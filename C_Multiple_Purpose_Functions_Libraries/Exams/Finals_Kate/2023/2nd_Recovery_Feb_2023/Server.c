/**
 * @file    Servidor.c
 * @brief   [ESP] Archivo fuente del servidor (Sockets TCP). 2do Recup 2023.
 *          [ENG] Server source file (TCP Sockets). 2nd Makeup exam 2023.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "Functions_Server_Client.h"

/* [ESP] variable global del tipo volatil / [ENG] volatile type global variable */
volatile sig_atomic_t flag = TRUE;

/**
 * @brief [ESP] FUncion handler de signals.
 *        [ENG] Signals handler function.
 */
void misenal(int a)
{
    printf("a = %d\n", a);
    flag = FALSE;
}

/**
 * @brief [ESP] Función principal del servidor TCP TCP.
 *        [ENG] Main function for the TCP server.
 */
int main(int argc, char **argv)
{
    int sock_servidor = 0, sock_new = 0;
    struct sockaddr_in info_server_in;
    int connection_status = OK;
    char nombre_examen[10] = "TX.tar.gz";
    char buffer_info_alumno_servidor[60];
    char msg_err_Leg_Y_DNI[] = "ERROR_LEGAJO_Y-DNI";
    char msg_err_Nom_Y_APE[] = "ERROR_NOMBRE_Y/O_APELLIDO";
    char msg_Banned[] = "BANNED";
    int validacion = FALSE;
    int nro_examen = 0;
    char c = 'X';
    Alumno_cliente var1;
    FILE *File_in = NULL;
    int CantidadEstructuras_FileIn = 0;
    long tamanio_archivo = 0;
    int i = 0;
    struct alumno *Buffer_Read_in = NULL;

    printf("%d\n", EINTR);
    signal(SIGALRM, misenal);
    alarm(30);

    /* [ESP] Proteccion contra ingreso / [ENG] Protection for missing inputs */
    if( argc!= 2 )
    {
        printf("Reingrese los comandos <nombre_ejecutable.out> <nombre_archivo_IN.dat>\n");
        return ERROR;
    }

    memset(buffer_info_alumno_servidor, 0, sizeof(buffer_info_alumno_servidor));
    srand(time(NULL));

    /* [ESP] Apertura de archivo de alumnos inscriptos / [ENG] Unregistered students file read */
    File_in = fopen(argv[1], "r");
    if( File_in == NULL ) return ERROR;

    fseek(File_in, 0, SEEK_END);
    tamanio_archivo = ftell(File_in);
    CantidadEstructuras_FileIn = ((int)tamanio_archivo) / ((int)sizeof(struct alumno));
    printf("La cantidad de estructuras tipo struct alumno son: %d\n", CantidadEstructuras_FileIn);
    fseek(File_in, 0, SEEK_SET);

    Buffer_Read_in = (struct alumno *)malloc( CantidadEstructuras_FileIn * sizeof(struct alumno));
    if( Buffer_Read_in == NULL ) return ERROR;

    if ( fread(Buffer_Read_in, CantidadEstructuras_FileIn * sizeof(struct alumno), 1, File_in) < 1 )
        return ERROR;
    fclose(File_in);

    for( i = 0; i < CantidadEstructuras_FileIn; i++ )
    {
        Buffer_Read_in[i].banned = FALSE;
        Buffer_Read_in[i].repartido = FALSE;
    }

    sock_servidor = Open_conection(&info_server_in, PORT);
    if( sock_servidor == ERROR ) return ERROR;

    while( connection_status == OK && flag == TRUE)
    {
        if( flag == FALSE )
        {
            close(sock_servidor);
        }
        else
        {
            sock_new = Aceptar_pedidos(sock_servidor);
            if( sock_new == ERROR )
            {
                fprintf(stderr, "Hubo un problema para aceptar pedidos de conexion, se cerrara el server\n");
                connection_status = END;
                printf("SE TERMINO EL PROCESO \n");
            }
        }

        if(connection_status == OK)
        {
            recv(sock_new, buffer_info_alumno_servidor, sizeof(buffer_info_alumno_servidor), 0);
            fprintf(stderr, "Se recibio en el servidor la siguiente informacion\n");
            fprintf(stderr, "%s\n", buffer_info_alumno_servidor);

            sscanf(buffer_info_alumno_servidor, "{%d,%d,%[^,],%[^}]}", &var1.legajo, &var1.DNI, var1.nombre, var1.apellido);

            for( i = 0; i < CantidadEstructuras_FileIn; i++ )
            {
                if( (strcasecmp(var1.nombre, Buffer_Read_in[i].nombre) == 0) && (strcasecmp(var1.apellido, Buffer_Read_in[i].apellido) == 0) )
                {
                    validacion = OK;
                    break;
                }
                else
                    validacion = FALSE;
            }

            if( validacion == FALSE )
            {
                send(sock_new, msg_err_Nom_Y_APE, sizeof(msg_err_Nom_Y_APE) + 1, 0);
                close(sock_new);
            }
            else
            {
                if( (var1.DNI == Buffer_Read_in[i].DNI) && (var1.legajo == Buffer_Read_in[i].legajo) )
                {
                    if( Buffer_Read_in[i].banned == FALSE )
                    {
                        nro_examen = aleatorio_en_rango(1, 4);
                        c = nro_examen + '0';
                        nombre_examen[1] = c;
                        send(sock_new, nombre_examen, sizeof(nombre_examen) + 1, 0);
                        close(sock_new);
                        Buffer_Read_in[i].repartido++;
                    }
                    else
                    {
                        send(sock_new, msg_Banned, sizeof(msg_Banned) + 1, 0);
                        close(sock_new);
                    }
                }
                else
                {
                    send(sock_new, msg_err_Leg_Y_DNI, sizeof(msg_err_Leg_Y_DNI) + 1, 0);
                    close(sock_new);
                    Buffer_Read_in[i].banned = TRUE;
                }
            }
        }
    }

    printf("Time-out.Se va a cerrar el servidor.\n");
    free(Buffer_Read_in);
    printf("Se ejecuto correctamente todo y se liberaron los recursos\n");
    return EXITO;
}
