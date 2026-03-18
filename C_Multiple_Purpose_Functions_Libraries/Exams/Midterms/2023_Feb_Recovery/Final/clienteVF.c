#include "sock-lib.h"
#include<stdio_ext.h>

//comando para compilar, linkear y obtener ejecutable del cliente: gcc -Wall cliente.c sock-lib.c -o cliente

typedef struct alumno_cliente
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
}Alumno_cliente;


int main(int argc, char **argv)
{
    int sock_cliente, check;
    char buffer_respuesta_servidor[25];
    char buffer_info_alumno_cliente[60];
    char mensaje_verificacion[9];
    Alumno_cliente var1;

    //Verificacion de error contra cantidad de argumentos de main insuficientes
    if(argc != 3)
    {
        printf("Error. Ha ingresado mal los comandos. Re-ejecute de la siguiente forma: <ejecutable> <legajo> <dni>\n");
        return -1;
    }


    //Carga de \0 en todo el array de buffer_examen para que luego de llenarlo con otros caracteres, el ultimo sea el \0
    memset(buffer_respuesta_servidor,0,sizeof(buffer_respuesta_servidor));

    //Carga con \0 todos los elementos del buffer_info_alumno_cliente para que luego de modificarlo al buffer_info_alumno_cliente, me quede el \0 al final de la cadena
    memset(buffer_info_alumno_cliente, 0, sizeof(buffer_info_alumno_cliente));

    //Cargo con \0 todos los elementos del array mensaje_verificacion para que luego de modificarlo, me quede el \0 al final de la cadena
    memset(mensaje_verificacion,0,sizeof(mensaje_verificacion));


    //fprintf(stderr,"Se llego a la linea 40\n");
    /*Carga de datos en la estructura Alumno_cliente*/

    //Carga del array legajo ,proveniente de la linea de comandos, como entero
    var1.legajo = atoi(argv[1]);

    //Carga del array DNI ,proveniente de la linea de comandos, como entero
    var1.DNI = atoi(argv[2]);

    fprintf(stderr,"Se llego a la linea 48\n");
    //Carga del nombre del alumno
    printf("Ingrese su nombre: ");
    fgets(var1.nombre, sizeof(var1.nombre), stdin);
    if( var1.nombre[strlen(var1.nombre)-1] == '\n')
        var1.nombre[strlen(var1.nombre)-1] = '\0';

    //Carga del apellido del alumno
    printf("Ingrese el apellido: ");
    fgets(var1.apellido, sizeof(var1.apellido), stdin);
    if( var1.apellido[strlen(var1.apellido)-1] == '\n')
        var1.apellido[strlen(var1.apellido)-1] = '\0';

    //Serializacion
    //Convierto la informacion en formato estructura a formato txt en un buffer
    sprintf(buffer_info_alumno_cliente, "{%d,%d,%s,%s}", var1.legajo, var1.DNI, var1.nombre, var1.apellido);
    fprintf(stderr,"Se envio la siguiente informacion al servidor\n");
    fprintf(stderr, "%s\n", buffer_info_alumno_cliente);

    //Creacion de socket cliente + nombramiento del socket + solicitud de conexion con el servidor
    sock_cliente = conectar(PORT,"localhost");

    //Envio de informacion guardada en estructura Alumno_cliente, en formato de string de caracteres luego de serializacion
    check = send(sock_cliente,buffer_info_alumno_cliente,strlen(buffer_info_alumno_cliente)+1,0);
    if(check == -1)
    {
        fprintf(stderr,"Error en el envio de informacion desde el cliente al servidor\n");
        return -1;
    }


    //Lectura de lo enviado por el servidor hacia el cliente. Este cliente actua en consecuencia.
    check = recv(sock_cliente,buffer_respuesta_servidor,sizeof(buffer_respuesta_servidor),0);
    if( check == -1)
    {
        fprintf(stderr,"Error en el recibo de informacion desde el servidor al cliente\n");
        return -1;
    }

    if(strcasecmp(buffer_respuesta_servidor,"ERROR_FALTA_ALUMNO") == 0)
    {
        fprintf(stderr,"%s\n.Su nombre y apellido no se encuentran en la lista de alumnos para rendir. Vuelva a intentarlo. Se cerrara la conexion\n",buffer_respuesta_servidor);
        close(sock_cliente);
    }
    else if(strcasecmp(buffer_respuesta_servidor,"ERROR_LEGAJO_Y-DNI") == 0)
    {
        fprintf(stderr,"Hay algo raro con el LEGAJO y DNI....espere un momento\n");
        sleep(10);//va 300
        //fprintf(stderr,"Se esperaron 10 segundos\n");
        fprintf(stderr,"%s\n.Se cerrara la conexion\n",buffer_respuesta_servidor);
        close(sock_cliente);
    }
    else if(strcasecmp(buffer_respuesta_servidor,"BANNED") == 0)
    {
        fprintf(stderr,"%s\n. Algunos de los datos del LEGAJO, DNI, NOMBRE, APELLIDO...no concuerdan en la lista. Usted esta BANNED. Se cerrara la conexion\n",buffer_respuesta_servidor);
        close(sock_cliente);
    }
    else
        fprintf(stderr,"El nombre del archivo examen recibido fue: %s\n", buffer_respuesta_servidor);

    //cerrar el socket
    close(sock_cliente);

    return 0;
}

