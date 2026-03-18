#include "sock-lib.h"
#include <time.h>
#include<stdio_ext.h>
#define FALSE 0
#define TRUE  1

//Declaracion de una estructura del tipo "struct alumno" segun enunciado
typedef struct alumno
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
    int repartido;
    int banned;
}Alumno;

typedef struct alumno_cliente
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
}Alumno_cliente;


int aleatorio_en_rango(int minimo, int maximo);


int main()
{
    //Declaracion y definicion de variables con inicializacion de algunas tales como: nombre_archivo, File_in y ptr
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


    //Cargo el array buffer_info_alumno_servidor con todos \0 para dejar el caracter NULL al final del string cargado
    memset(buffer_info_alumno_servidor,0,sizeof(buffer_info_alumno_servidor));
    //Cargo el array buffer_info_alumno_archivoIn con todos \0 para dejar el caracter NULL al final del string cargado
    memset(buffer_info_alumno_archivoIn,0,sizeof(buffer_info_alumno_archivoIn));

    //Inicializo la seed para generar numeros pseudo-aleatorios
    srand(time(NULL));

    //Apertura de archivo
    File_in = fopen(nombre_archivo,"rt");
    //Verificacion de error contra apertura de archivo
    if(File_in == NULL)
    {
        fprintf(stderr,"Error en la apertura del archivo de entrada\n");
        return -1;
    }

    //Posicion el file stream en EOF
    fseek(File_in,0,SEEK_END);
    //Obtencion del tamanio del archivo
    tamanio_archivo = ftell(File_in);
    //Posicion el file stream en el princpio del archivo
    fseek(File_in,0,SEEK_SET);

    fprintf(stderr,"tamanio_archivo: %lu\n",tamanio_archivo);

    while((fgets(buffer_info_alumno_archivoIn,sizeof(buffer_info_alumno_archivoIn),File_in)) != NULL)
    {
        array = (Alumno *)reallocarray(array,cant_structs_alumnos,sizeof(Alumno));
        if(array == NULL)
        {
            fprintf(stderr,"Error durante la asignacion de memoria dinamica para las estructuras de alumnos\n");
            return -2;
        }
        sscanf(buffer_info_alumno_archivoIn,"{%[^,],%[^,],%d,%d}",array[i].nombre,array[i].apellido,&array[i].legajo,&array[i].DNI);
        fprintf(stderr,"La estructura #%d queda cargada como:\n",i);
        fprintf(stderr,"Legajo: %d\n",array[i].legajo);
        fprintf(stderr,"DNI: %d\n",array[i].DNI);
        fprintf(stderr,"Nombre: %s\n",array[i].nombre);
        fprintf(stderr,"Apellido: %s\n",array[i].apellido);
        //Inicializacion de los campos "repartido" y "banned" con una macro FALSE. Esto por cada estructura tipo "struct alumno" cargada en el array dinamico
        array[i].repartido = FALSE;
        array[i].banned = FALSE;
        fprintf(stderr,"Repartido: %d\n",array[i].repartido);
        fprintf(stderr,"banned: %d\n",array[i].banned);
        i++;
        cant_structs_alumnos++;
    }

    fprintf(stderr,"Cantidad de estructuras tipo Alumno: %d\n",cant_structs_alumnos-1);

    fprintf(stderr,"Se creo correctamente el array dinamico de estructuras del archivo .txt de entrada\n");

    //Creacion de socket servidor, nombramiento del socket servidor, seteo de socket servidor en modo LISTEN y recibimiento de solicitudes de conexion de clientes en cola
    sock_servidor = Open_conection(&info_server_in,PORT);

    while(decision != -1)
    {
        //Llamada a funcion bloqueante y aceptacion de solicitudes de conexion de clientes
        sock_new = Aceptar_pedidos(sock_servidor);

        //Lectura en memoria de lo enviado por el cliente al servidor
        check = recv(sock_new,buffer_info_alumno_servidor,sizeof(buffer_info_alumno_servidor),0);
        if(check == -1)
        {
            fprintf(stderr,"Error en el recibo de informacion desde el cliente al servidor\n");
            return -1;
        }

        fprintf(stderr,"Se recibio en el servidor la siguiente informacion\n");
        //Printeo lo leido por el servidor respecto a lo enviado por el cliente
        fprintf(stderr,"%s\n",buffer_info_alumno_servidor);

        //Deserializacion
        //Convierto la informacion de la estructura en formato txt de un buffer a formato de estructura con sus respectivos campos "parcializando la informacion"
        sscanf(buffer_info_alumno_servidor,"{%d,%d,%[^,],%[^}]}", &var1.legajo, &var1.DNI, var1.nombre, var1.apellido);


        for( count_estructuras_recorridas = 0,i = 0; i < cant_structs_alumnos-1; i++ )
        {
            if( strcasecmp(array[i].nombre, var1.nombre) == 0 && strcasecmp(array[i].apellido,var1.apellido) == 0 )
            {
                if(array[i].legajo == var1.legajo && array[i].DNI == var1.DNI)
                {
                    if(array[i].banned == FALSE)
                    {
                        fprintf(stderr,"Se verificaron los datos del alumno correctamente\n");
                        nro_examen = aleatorio_en_rango(1,4);
                        c = nro_examen + '0';
                        nombre_examen[1] = c;
                        array[i].repartido += 1;
                        //Esta funcion recibe el sock_new del socket asociado de comunicacion con el cliente y el string con el nombre_examen. Esta informacion debe ser enviada desde el servidor al cliente
                        check = send(sock_new,nombre_examen,strlen(nombre_examen)+1,0);
                        if(check == -1)
                        {
                             fprintf(stderr,"Error en el envio de informacion desde el servidor al cliente\n");
                             return -1;
                        }
                        //count_estructuras_recorridas = 0;
                        //break;

                    }
                    else
                    {
                        fprintf(stderr,"Se verificaron erroneamente los datos del alumno. El alumno esta BANNED. Se cerrara la conexion servidor-cliente\n");
                        check = send(sock_new,msg_Banned,strlen(msg_Banned)+1,0);
                        if(check == -1)
                        {
                        fprintf(stderr,"Error en el envio de informacion desde el servidor al cliente\n");
                        return -1;
                        }
                        close(sock_new);
                    }
                }
                else
                {
                    fprintf(stderr,"Se verificaron erroneamente los datos del LEGAJO y DNI del alumno. Se cerrara la conexion servidor-cliente\n");
                    array[i].banned = TRUE;
                    check = send(sock_new,msg_err_Leg_Y_DNI,strlen(msg_err_Leg_Y_DNI)+1,0);
                    if(check == -1)
                    {
                        fprintf(stderr,"Error en el envio de informacion desde el servidor al cliente\n");
                        return -1;
                    }
                    close(sock_new);
                    //break;
                }
            }
            else
                count_estructuras_recorridas++;
        }

        if(count_estructuras_recorridas == cant_structs_alumnos-1)
        {
            fprintf(stderr,"No se encontro al alumno en la lista de alumnos para rendir examen\n");
            check = send(sock_new,msg_err_Nom_Y_APE,strlen(msg_err_Nom_Y_APE)+1,0);
            if(check == -1)
            {
                fprintf(stderr,"Error en el envio de informacion desde el servidor al cliente\n");
                return -1;
            }
            count_estructuras_recorridas = 0;
            close(sock_new);
        }

        fprintf(stderr,"Desea cerrar el servidor?. Ingrese -1 si lo desea sino otro numero\n");
        scanf("%d",&decision);
        __fpurge(stdin);
    }
    fprintf(stderr,"Se cerrara el servidor\n.\n.\n.\n");
    close(sock_servidor);
    free(array);
    fprintf(stderr,"Se liberaron correctamente los recursos\n");
    return 0;
}

// Devuelve un número aleatorio entre minimo y maximo, incluyendo a minimo y maximo
int aleatorio_en_rango(int minimo, int maximo)
{
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

