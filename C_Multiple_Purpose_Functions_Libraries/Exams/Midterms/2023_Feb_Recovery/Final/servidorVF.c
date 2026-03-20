/**
 * @file    servidorVF.c
 * @brief   [ESP] Servidor del 2do Parcial Recuperatorio Feb 2023 (Versión Final).
 *          [ENG] Server of the 2nd Midterm Recovery Feb 2023 (Final Version).
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "sock-lib.h"
#include <time.h>
#include <stdio_ext.h>

#define FALSE 0
#define TRUE  1

/**
 * @brief [ESP] Estructura que almacena los datos del alumno en el servidor.
 *        [ENG] Structure that stores the student data in the server.
 */
typedef struct alumno
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
    int repartido;
    int banned;
} Alumno;

/**
 * @brief [ESP] Estructura del alumno usada como auxiliar.
 *        [ENG] Student structure used as auxiliary.
 */
typedef struct alumno_cliente
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
} Alumno_cliente;

/**
 * @brief [ESP] Retorna un número aleatorio en un rango dado.
 *        [ENG] Returns a random number in a given range.
 */
int aleatorio_en_rango(int minimo, int maximo);


/**
 * @brief [ESP] Función principal del servidor.
 *        [ENG] Main function of the server.
 *
 * @return 0 [ESP] Si la ejecución cruzó correcta. / [ENG] If execution passes correctly.
 */
int main()
{
    int sock_servidor, sock_new, check;
    int cant_structs_alumnos = 1, i = 0;
    int count_estructuras_recorridas = 0;
    int decision = 0;
    int nro_examen;
    char c;
    char nombre_examen[10] = "TX.tar.gz";
    char nombre_archivo[12] = "alumnos.txt";
    char buffer_info_alumno_servidor[60];
    char buffer_info_alumno_archivoIn[60];
    char msg_err_Leg_Y_DNI[] = "ERROR_LEGAJO_Y-DNI";
    char msg_err_Nom_Y_APE[] = "ERROR_FALTA_ALUMNO";
    char msg_Banned[] = "BANNED";
    long tamanio_archivo;
    FILE *File_in = NULL;
    Alumno *array = NULL;
    struct sockaddr_in info_server_in;
    Alumno_cliente var1;

    memset(buffer_info_alumno_servidor, 0, sizeof(buffer_info_alumno_servidor));
    memset(buffer_info_alumno_archivoIn, 0, sizeof(buffer_info_alumno_archivoIn));

    srand(time(NULL));

    /* [ESP] Apertura de archivo / [ENG] File opening */
    File_in = fopen(nombre_archivo, "rt");
    if(File_in == NULL)
    {
        fprintf(stderr,"Error en la apertura del archivo de entrada\n");
        return -1;
    }

    fseek(File_in, 0, SEEK_END);
    tamanio_archivo = ftell(File_in);
    fseek(File_in, 0, SEEK_SET);

    fprintf(stderr, "tamanio_archivo: %lu\n", tamanio_archivo);

    /* [ESP] Lectura del archivo de alumnos / [ENG] Reading students file */
    while((fgets(buffer_info_alumno_archivoIn, sizeof(buffer_info_alumno_archivoIn), File_in)) != NULL)
    {
        array = (Alumno *)reallocarray(array, cant_structs_alumnos, sizeof(Alumno));
        if(array == NULL) return -2;
        
        sscanf(buffer_info_alumno_archivoIn, "{%[^,],%[^,],%d,%d}", array[i].nombre, array[i].apellido, &array[i].legajo, &array[i].DNI);
        array[i].repartido = FALSE;
        array[i].banned = FALSE;
        i++;
        cant_structs_alumnos++;
    }

    fprintf(stderr,"Cantidad de estudiantes cargados: %d\n", cant_structs_alumnos-1);

    /* [ESP] Inicialización del servidor / [ENG] Server initialization */
    sock_servidor = Open_conection(&info_server_in, PORT);

    while(decision != -1)
    {
        sock_new = Aceptar_pedidos(sock_servidor);

        check = recv(sock_new, buffer_info_alumno_servidor, sizeof(buffer_info_alumno_servidor), 0);
        if(check == -1) return -1;

        fprintf(stderr, "Servidor recibio: %s\n", buffer_info_alumno_servidor);

        /* [ESP] Deserializacion / [ENG] Deserialization */
        sscanf(buffer_info_alumno_servidor,"{%d,%d,%[^,],%[^}]}", &var1.legajo, &var1.DNI, var1.nombre, var1.apellido);

        /* [ESP] Verificación de los datos / [ENG] Data verification */
        for( count_estructuras_recorridas = 0, i = 0; i < cant_structs_alumnos-1; i++ )
        {
            if( strcasecmp(array[i].nombre, var1.nombre) == 0 && strcasecmp(array[i].apellido, var1.apellido) == 0 )
            {
                if(array[i].legajo == var1.legajo && array[i].DNI == var1.DNI)
                {
                    if(array[i].banned == FALSE)
                    {
                        fprintf(stderr, "Datos validados OK.\n");
                        nro_examen = aleatorio_en_rango(1,4);
                        c = nro_examen + '0';
                        nombre_examen[1] = c;
                        array[i].repartido += 1;
                        
                        check = send(sock_new, nombre_examen, strlen(nombre_examen)+1, 0);
                        if(check == -1) return -1;
                    }
                    else
                    {
                        fprintf(stderr, "Alumno BANNED.\n");
                        send(sock_new, msg_Banned, strlen(msg_Banned)+1, 0);
                        close(sock_new);
                    }
                }
                else
                {
                    fprintf(stderr, "LEGAJO y DNI invalidos.\n");
                    array[i].banned = TRUE;
                    send(sock_new, msg_err_Leg_Y_DNI, strlen(msg_err_Leg_Y_DNI)+1, 0);
                    close(sock_new);
                }
                break;
            }
            else
            {
                count_estructuras_recorridas++;
            }
        }

        if(count_estructuras_recorridas == cant_structs_alumnos-1)
        {
            fprintf(stderr, "Alumno NO encontrado.\n");
            send(sock_new, msg_err_Nom_Y_APE, strlen(msg_err_Nom_Y_APE)+1, 0);
            close(sock_new);
        }

        fprintf(stderr,"Desea cerrar el servidor? (-1 para si, otro para no): ");
        scanf("%d", &decision);
        __fpurge(stdin);
    }
    
    close(sock_servidor);
    free(array);
    fprintf(stderr, "Recursos liberados.\n");
    return 0;
}

int aleatorio_en_rango(int minimo, int maximo)
{
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
