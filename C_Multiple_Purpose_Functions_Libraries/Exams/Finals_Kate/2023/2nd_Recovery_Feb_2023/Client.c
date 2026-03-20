/**
 * @file    Cliente.c
 * @brief   [ESP] Archivo fuente del cliente (Sockets TCP). 2do Recup 2023.
 *          [ENG] Client source file (TCP Sockets). 2nd Makeup exam 2023.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "Functions_Server_Client.h"

/**
 * @brief [ESP] Función principal del cliente TCP.
 *        [ENG] Main function for the TCP client.
 *
 * @param argc [ESP] Número de argumentos / [ENG] Number of arguments
 * @param argv [ESP] Vector de parámetros / [ENG] Parameters vector (legajo, DNI)
 * @return EXITO [ESP] Ejecución satisfactoria. / [ENG] Satisfactory execution.
 */
int main(int argc, char **argv)
{
    if( argc != 3 )
    {
        printf("Cantidad de comandos insuficiente, re-ejecute ingredsando <nombre_ejectuable.out> <legajo> <DNI>\n");
        return ERROR;
    }

    char msg_respuesta_server[30];
    int sock_cliente = 0;
    Alumno_cliente var1;
    char buffer_info_alumno_cliente[60];
    char *Nombre = NULL;
    char *Apellido = NULL;
    size_t stdin_length = 0;
    ssize_t string_largo = 0;

    memset(buffer_info_alumno_cliente, 0, sizeof(buffer_info_alumno_cliente));

    /* [ESP] Ingreso de data adicional del alumno / [ENG] Input for additional student data */
    printf("Ingrese su nombre: ");
    string_largo = getline(&Nombre, &stdin_length, stdin);
    Nombre[string_largo-1] = '\0';

    printf("Ingrese su apellido: ");
    string_largo = getline(&Apellido, &stdin_length, stdin);
    Apellido[string_largo-1] = '\0';

    strcpy(var1.nombre, Nombre);
    strcpy(var1.apellido, Apellido);
    var1.legajo = atoi(argv[1]);
    var1.DNI = atoi(argv[2]);

    /* [ESP] Convierto a formato txt / [ENG] Converts to txt format */
    sprintf(buffer_info_alumno_cliente, "{%d,%d,%s,%s}", var1.legajo, var1.DNI, var1.nombre, var1.apellido);

    /* [ESP] Creacion y solicitud conexion / [ENG] Request creation and connection */
    sock_cliente = conectar(PORT, "localhost");

    send(sock_cliente, buffer_info_alumno_cliente, sizeof(buffer_info_alumno_cliente) + 1, 0);
    fprintf(stderr, "Se envio la siguiente informacion al servidor\n");
    fprintf(stderr, "%s\n", buffer_info_alumno_cliente);

    recv(sock_cliente, msg_respuesta_server, sizeof(msg_respuesta_server), 0);
    fprintf(stderr, "El servidor dice %s\n", msg_respuesta_server);

    close(sock_cliente);
    free(Nombre);
    free(Apellido);
    printf("Se ejecuto correctamente todo y se liberaron los recuros\n");
    return EXITO;
}
