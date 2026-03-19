#include"Funciones-Server-Cliente.h"

//variable global del tipo  volatil
volatile sig_atomic_t flag = TRUE;

//FUncion handler de signals
void misenal(int a)
{
    printf("a = %d\n",a);
    flag = FALSE;
    //alarm(5);
    
}



int main(int argc, char **argv)
{
    printf("%d\n", EINTR);
    signal(SIGALRM,misenal);
    alarm(30);
    
    
    //Proteccion contra ingreso insuficiente de argumentos
    if( argc!= 2 )
    {
        printf("Reingrese los comandos <nombre_ejecutable.out> <nombre_archivo_IN.dat>\n");
        return ERROR;
    }

    int sock_servidor = 0, sock_new = 0;
    struct sockaddr_in info_server_in;
    int connection_status = OK;
    char nombre_examen[10] = "TX.tar.gz";
    char buffer_info_alumno_servidor[60];
    //char buffer_info_alumno_archivoIn[60];
    char msg_err_Leg_Y_DNI[] = "ERROR_LEGAJO_Y-DNI";
    char msg_err_Nom_Y_APE[] = "ERROR_NOMBRE_Y/O_APELLIDO";
    char msg_Banned[] = "BANNED";

    int validacion = FALSE;
    int nro_examen = 0;
    char c = 'X';
    Alumno_cliente var1;

    //Cargo el array buffer_info_alumno_servidor con todos \0 para dejar el caracter NULL al final del string cargado
    memset(buffer_info_alumno_servidor,0,sizeof(buffer_info_alumno_servidor));
    //Cargo el array buffer_info_alumno_archivoIn con todos \0 para dejar el caracter NULL al final del string cargado
    //memset(buffer_info_alumno_archivoIn,0,sizeof(buffer_info_alumno_archivoIn));

    //Inicializo la seed para generar numeros pseudo-aleatorios
    srand(time(NULL));

    /*******************ALGORITMO DE APERTURA DE ARCHIVO Y LECTURA DE DATA EN MEMORIA*********************/
    FILE *File_in = NULL;
    int CantidadEstructuras_FileIn = 0;
    long tamanio_archivo = 0;
    int i = 0;
    struct alumno *Buffer_Read_in = NULL;

    //Abro el archivo de entrada
    File_in = fopen(argv[1],"r");
    if( File_in == NULL )
    {
        printf("Ocurrio un error en la apertura del archivo de entrada\n");
        return ERROR;
    }

    //Posiciono el "file position indicator" al final del archivo de entrada
    fseek(File_in,0,SEEK_END);
    //Averiguo el tamanio del archivo
    tamanio_archivo = ftell(File_in);
    //Averiguo la cantidad de estructuras del archivo de entrada
    CantidadEstructuras_FileIn =  ( (int)tamanio_archivo ) / ( (int)sizeof(struct alumno) );
    printf("La cantidad de estructuras tipo struct alumno son: %d\n", CantidadEstructuras_FileIn);
    //Posiciono el "file position indicator" al comienzo del arhcivo de entrada
    fseek(File_in,0,SEEK_SET);

    //Pido memoria dinamica para almacenar la info del archivo in en memoria
    Buffer_Read_in = (struct alumno *)malloc( CantidadEstructuras_FileIn * sizeof(struct alumno));
    //Proteccion contra NULL de malloc
    if( Buffer_Read_in == NULL )
    {
        printf("Erropr en la asignacion de memoria dinamica para buffer de informacion read in\n");
        return ERROR;
    }

    //Leo del arhcivo de entrada las estructuras y las guardo en memoria
    if ( fread(Buffer_Read_in, CantidadEstructuras_FileIn * sizeof(struct alumno), 1, File_in) < 1 )
    {
        printf("Hubo un error con la lectura en memoria de las estructuras de entrada\n");
        return ERROR;
    }
    //Cierro el archivo de entrada
    fclose(File_in);
    /**********FIN DE ALGORITMO DE APERTURA DE ARCHIVO Y LECTURA EN MEMORIA**********/

    //Inicializacion de banned y repartido en FALSE
    for( i = 0; i < CantidadEstructuras_FileIn; i++ )
    {
        Buffer_Read_in[i].banned = FALSE;
        Buffer_Read_in[i].repartido = FALSE;
    }

    //Funcion que crea el socket servidor, nombramiento del socket servidor, seteo de socket servidor en modo LISTEN para recibimiento de solicitudes de conexion de clientes en cola
    sock_servidor = Open_conection(&info_server_in,PORT);
    if( sock_servidor == ERROR )
    {
        fprintf(stderr,"Ocurrio un error con la apertura de conexion del server\n");
        return ERROR;
    }




 while( connection_status == OK && flag == TRUE)
{
        if( flag == FALSE )
        {
            close(sock_servidor);
        }
        else
        {
            //Llamada a funcion bloqueante y aceptacion de solicitudes de conexion de clientes
            sock_new = Aceptar_pedidos(sock_servidor);
            if( sock_new == ERROR )
            {
                fprintf(stderr,"Hubo un problema para aceptar pedidos de conexion, se cerrara el server\n");
                connection_status = END;
                printf("SE TERMINO EL PROCESO \n");
            }
        }

        /*SE PUEDE INGRESAR POR TECLADO ALGUN COMANDO COMO CTRL+D PARA CERRAR ABRUPTAMENTE EL SERVER*/

        if(connection_status == OK)
        {
            //Lectura en memoria de lo enviado por el cliente al servidor
            recv(sock_new,buffer_info_alumno_servidor,sizeof(buffer_info_alumno_servidor),0);
            //Aca iria checkeo de error de recv

            fprintf(stderr,"Se recibio en el servidor la siguiente informacion\n");
            //Printeo lo leido por el servidor respecto a lo enviado por el cliente
            fprintf(stderr,"%s\n",buffer_info_alumno_servidor);

            //Deserializacion
            //Convierto la informacion de la estructura en formato txt en un buffer a formato de estructura con sus respectivos campos "parcializando la informacion"
            sscanf(buffer_info_alumno_servidor,"{%d,%d,%[^,],%[^}]}", &var1.legajo, &var1.DNI, var1.nombre, var1.apellido);


            /*SUPONGO QUE 2 O MAS PERSONAS NO TIENEN MISMO NOMBRE Y APELLIDO, DIFIEREN EN UNO DE ELLOS*/
            /*HABRIA QUE IMPLEMENTAR ESTE CASO EN UN FUTURO*/

            //Recorro todo el buffer buscando el nombre y apellido del alumno-cliente
            for( i = 0; i < CantidadEstructuras_FileIn; i++ )
            {
                //Validacion de nombre y apellido de alumno-cliente vs datos-server
                if( ( strcasecmp(var1.nombre,Buffer_Read_in[i].nombre)  == 0 ) && ( strcasecmp(var1.apellido,Buffer_Read_in[i].apellido) == 0 ) )
                {
                    validacion = OK;
                    break;
                }
                else
                    validacion = FALSE;
            }

            if( validacion == FALSE )
            {
                send(sock_new,msg_err_Nom_Y_APE,sizeof(msg_err_Nom_Y_APE) + 1,0);
                //Aca iria proteccion contra error de send
                //Cierro conexion
                close(sock_new);
            }
            else
            {
                //Validacion de legajo y dni de alumno-cliente vs datos-server
                if( (var1.DNI == Buffer_Read_in[i].DNI) && (var1.legajo == Buffer_Read_in[i].legajo) )
                {
                    //Validacion de banned en FALSE de struct alumno-server
                    if( Buffer_Read_in[i].banned == FALSE )
                    {
                        nro_examen = aleatorio_en_rango(1,4);
                        c = nro_examen + '0';
                        nombre_examen[1] = c;
                        send(sock_new,nombre_examen,sizeof(nombre_examen) + 1, 0);
                        //Aca iria proteccion contra error de send
                        //Cierro conexion
                        close(sock_new);
                        Buffer_Read_in[i].repartido++;
                    }
                    else
                    {
                        send(sock_new,msg_Banned,sizeof(msg_Banned) + 1, 0);
                        //Aca iria proteccion contra error de send
                        //Cierro conexion
                        close(sock_new);
                    }
                }
                else
                {
                    send(sock_new,msg_err_Leg_Y_DNI,sizeof(msg_err_Leg_Y_DNI) + 1, 0);
                    //Aca iria proteccion contra error de send
                    //Cierro conexion
                    close(sock_new);

                    //Coloco banned en la struct alumno-server
                    Buffer_Read_in[i].banned = TRUE;
                }
            }
        }
    }


    printf("Time-out.Se va a cerrar el servidor.\n");
    //Libero los recursos del buffer dinamico de estructuras provenientes del archivo de entrada
    free(Buffer_Read_in);
    printf("Se ejecuto correctamente todo y se liberaron los recursos");
    return EXITO;
}


