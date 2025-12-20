#include"Funciones-Server-Cliente.h"


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


    //Cargo el array buffer_info_alumno_servidor con todos \0 para dejar el caracter NULL al final del string cargado
    memset(buffer_info_alumno_cliente,0,sizeof(buffer_info_alumno_cliente));

    //Ingreso de data adicional del alumno
    printf("Ingrese su nombre: ");
    string_largo = getline(&Nombre,&stdin_length,stdin);
    Nombre[string_largo-1] = '\0';//Elimino el caracter \n en la ultima pos del string

    printf("Ingrese su apellido: ");
    string_largo = getline(&Apellido,&stdin_length,stdin);
    Apellido[string_largo-1] = '\0';//Elimino el caracter \n en la ultima pos del string

    //Cargo la estructura que se va a enviar
    strcpy(var1.nombre,Nombre);
    strcpy(var1.apellido,Apellido);
    var1.legajo = atoi(argv[1]);
    var1.DNI = atoi(argv[2]);

    //Serializacion
    //Convierto la informacion en formato estructura a formato txt en un buffer
    sprintf(buffer_info_alumno_cliente, "{%d,%d,%s,%s}", var1.legajo, var1.DNI, var1.nombre, var1.apellido);

    //Creacion de socket cliente + nombramiento del socket + solicitud de conexion con el servidor
    sock_cliente = conectar(PORT,"localhost");
    //Aca iria proteccion contra error de conectar

    //Envio de data hacia el server
    send(sock_cliente,buffer_info_alumno_cliente,sizeof(buffer_info_alumno_cliente) + 1,0);
    //Aca iria proteccion contrar error de send
    fprintf(stderr,"Se envio la siguiente informacion al servidor\n");
    fprintf(stderr, "%s\n", buffer_info_alumno_cliente);
    //Recepcion de data del server
    recv(sock_cliente,msg_respuesta_server,sizeof(msg_respuesta_server),0);
    fprintf(stderr,"El servidor dice %s\n",msg_respuesta_server);

    close(sock_cliente);

    free(Nombre);
    free(Apellido);
    printf("Se ejecuto correctamente todo y se liberaron los recuros");
    return EXITO;
}
