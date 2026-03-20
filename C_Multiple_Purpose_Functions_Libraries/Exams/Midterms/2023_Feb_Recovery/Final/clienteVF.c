/**
 * @file    clienteVF.c
 * @brief   [ESP] Cliente del 2do Parcial Recuperatorio Feb 2023 (Versión Final).
 *          [ENG] Client of the 2nd Midterm Recovery Feb 2023 (Final Version).
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "sock-lib.h"
#include<stdio_ext.h>

/* [ESP] Comando para compilar: gcc -Wall clienteVF.c sock-lib.c -o clienteVF 
   [ENG] Compile command: gcc -Wall clienteVF.c sock-lib.c -o clienteVF */

/**
 * @brief [ESP] Estructura que almacena los datos del alumno en el cliente.
 *        [ENG] Structure that stores the student data in the client.
 */
typedef struct alumno_cliente
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
} Alumno_cliente;

/**
 * @brief [ESP] Función principal del cliente.
 *        [ENG] Main function of the client.
 *
 * @param argc [ESP] Cantidad de argumentos / [ENG] Number of arguments
 * @param argv [ESP] Vector de argumentos / [ENG] Arguments vector
 * @return 0 [ESP] Si la ejecución cruzó correcta. / [ENG] If execution passes correctly.
 */
int main(int argc, char **argv)
{
    int sock_cliente, check;
    char buffer_respuesta_servidor[25];
    char buffer_info_alumno_cliente[60];
    char mensaje_verificacion[9];
    Alumno_cliente var1;

    /* [ESP] Verificacion de cantidad de argumentos / [ENG] Verification of arguments amount */
    if(argc != 3)
    {
        printf("Error. Uso: <ejecutable> <legajo> <dni>\n");
        return -1;
    }

    memset(buffer_respuesta_servidor, 0, sizeof(buffer_respuesta_servidor));
    memset(buffer_info_alumno_cliente, 0, sizeof(buffer_info_alumno_cliente));
    memset(mensaje_verificacion, 0, sizeof(mensaje_verificacion));

    /* [ESP] Carga de datos / [ENG] Data loading */
    var1.legajo = atoi(argv[1]);
    var1.DNI = atoi(argv[2]);

    fprintf(stderr,"Carga de datos de alumno\n");
    printf("Ingrese su nombre: ");
    fgets(var1.nombre, sizeof(var1.nombre), stdin);
    if( var1.nombre[strlen(var1.nombre)-1] == '\n')
        var1.nombre[strlen(var1.nombre)-1] = '\0';

    printf("Ingrese el apellido: ");
    fgets(var1.apellido, sizeof(var1.apellido), stdin);
    if( var1.apellido[strlen(var1.apellido)-1] == '\n')
        var1.apellido[strlen(var1.apellido)-1] = '\0';

    /* [ESP] Serializacion / [ENG] Serialization */
    sprintf(buffer_info_alumno_cliente, "{%d,%d,%s,%s}", var1.legajo, var1.DNI, var1.nombre, var1.apellido);
    fprintf(stderr, "Se envio la siguiente informacion al servidor:\n%s\n", buffer_info_alumno_cliente);

    /* [ESP] Creacion y conexion de socket cliente / [ENG] Creation and connection of client socket */
    sock_cliente = conectar(PORT, "localhost");

    /* [ESP] Envio de informacion / [ENG] Sending information */
    check = send(sock_cliente, buffer_info_alumno_cliente, strlen(buffer_info_alumno_cliente)+1, 0);
    if(check == -1)
    {
        fprintf(stderr,"Error enviando informacion\n");
        return -1;
    }

    /* [ESP] Recepcion de respuesta del servidor / [ENG] Reception of server response */
    check = recv(sock_cliente, buffer_respuesta_servidor, sizeof(buffer_respuesta_servidor), 0);
    if( check == -1)
    {
        fprintf(stderr,"Error en recepcion\n");
        return -1;
    }

    /* [ESP] Procesamiento de respuesta / [ENG] Response processing */
    if(strcasecmp(buffer_respuesta_servidor,"ERROR_FALTA_ALUMNO") == 0)
    {
        fprintf(stderr, "%s\nSu nombre y apellido no se encuentran en la lista. Vuelva a intentarlo.\n", buffer_respuesta_servidor);
    }
    else if(strcasecmp(buffer_respuesta_servidor,"ERROR_LEGAJO_Y-DNI") == 0)
    {
        fprintf(stderr, "Hay algo raro con el LEGAJO y DNI....espere un momento\n");
        sleep(10);
        fprintf(stderr, "%s\nSe cerrara la conexion\n", buffer_respuesta_servidor);
    }
    else if(strcasecmp(buffer_respuesta_servidor,"BANNED") == 0)
    {
        fprintf(stderr, "%s\nUsted esta BANNED. Se cerrara la conexion\n", buffer_respuesta_servidor);
    }
    else
    {
        fprintf(stderr, "El nombre del archivo examen recibido fue: %s\n", buffer_respuesta_servidor);
    }

    /* [ESP] Cerrar el socket / [ENG] Close the socket */
    close(sock_cliente);

    return 0;
}
