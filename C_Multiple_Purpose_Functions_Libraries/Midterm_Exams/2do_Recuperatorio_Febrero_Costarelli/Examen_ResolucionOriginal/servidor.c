#include <stdio.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>
#include<string.h>
#include<time.h>
#define PORT 8010	/* El puerto donde se conectará, servidor */
#define BACKLOG 10	/* Tamaño de la cola de conexiones recibidas */

struct alumno
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
    int repartido;
    int banned;
};


int	conectar (int, char **);

int	Open_conection (struct sockaddr_in *, int); /* Función que crea la conexión*/

int	Aceptar_pedidos (int);	/* Función que acepta una conexión entrante*/

int aleatorio_en_rango(int minimo, int maximo);

int main()
{
    int fd, fd_new, legajo, DNI, nro_examen;
    char nombre[20];
    char apellido[20];
    int repartido;
    int banned;
    char nombre_examen[10];
    int i;
    int cant_structs_alumnos;
    long tamanio_archivo;
    FILE *File_in = NULL;
    char nombre_archivo = "alumnos.dat";

    memset(nombre_examen,0,sizeof(nombre_examen));
    strcpy(nombre_examen,"TX.tar.gz");

    srand(time(NULL));

    File_in = fopen(nombre_archivo, "r");
    if(File_in == NULL)
    {
        printf("Error en la apertura del archivo de entrada\n");
        return -1;
    }

    tamanio_archivo = ftell(File_in);
    cant_structs_alumnos = tamanio_archivo/sizeof(struct alumno);
    struct alumno array[cant_structs_alumnos];

    for( i = 0; i < cant_structs_alumnos; i++ )
    {
        fread(&array[i], sizeof(struct alumno), 1, File_in);
        array[i].repartido = FALSE;
        array[i].banned = FALSE;
    }

    fd = Open_conection(my_addr,PORT);

    fd_new = Aceptar_pedidos(fd);

    //Esta funcion se le pasa como parametro el fd_new del socket asociado de comunicacion con el cliente, un puntero a legajo, un puntero a dni y los strings nombre y apellido. Todo esto debera ser cargado en memoria con la informacion proveniente del cliente.
    recibir(fd_new, &legajo,&DNI,nombre,apellido);

    for( i = 0; i < cant_structs_alumnos; i++ )
    {
        if( strcasecmp(array[i].nombre, nombre) == 0 && strcasecmp(array[i].apellido, apellido) == 0 )
        {
            if(array[i].legajo == legajo && array[i].DNI == DNI)
            {
                if(array[i].banned == FALSE)
                {
                    nro_examen = aleatorio_en_rango(1,4);
                    nombre_examen[1] = nro_examen;
                    array[i].repartido += 1;
                    //Esta funcion recibe el fd_new del socket asociado de comunicacion con el cliente y el string con el nombre_examen. Esta informacion debe ser enviada desde el servidor al cliente
                    enviar(fd_new,nombre_examen);
                }
                else
                    close(fd_new);
            }
            else
            {
                array[i].banned = TRUE;
                close(fd_new);
            }
        }
        else
            close(fd_new);



    }


    return 0;
}

// Devuelve un número aleatorio entre minimo y maximo, incluyendo a minimo y maximo
int aleatorio_en_rango(int minimo, int maximo)
{
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int conectar (int port, char dest[])
{

	int	sockfd;
	struct hostent *he;	/* Se utiliza para convertir el nombre del host a su dirección IP */
	struct sockaddr_in their_addr;  /* dirección del server donde se conectará */

	/* Convertimos el nombre del host a su dirección IP */
	if ((he = gethostbyname ((const char *) dest)) == NULL)
	{
		herror("Error en Nombre de Host");
		exit(1);
	}

/* Creamos el socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error en creación de socket");
		exit(1);
	}

/* Establecemos their_addr con la direccion del server */
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(port);
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

/* Intentamos conectarnos con el servidor */
	if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Error tratando de conectar al server");
		exit(1);
	}
	return sockfd;
}


int Open_conection ( struct sockaddr_in * my_addr, int port)
{
	int	sockaux;	/*socket auxiliar*/
	int	aux; 		/*variable auxiliar*/

	/*Crea un socket y verifica si hubo algún error*/
	if ((sockaux = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "Error en función socket. Código de error %s\n", strerror(sockaux));
		return -1;
	}

/* Asignamos valores a la estructura my_addr */

	my_addr->sin_family = AF_INET;		/*familia de sockets INET para UNIX*/
	my_addr->sin_port = htons(port);	/*convierte el entero formato PC a
						entero formato network*/
	my_addr->sin_addr.s_addr = INADDR_ANY;	/* automaticamente usa la IP local */
	bzero(&(my_addr->sin_zero), 8);		/* rellena con ceros el resto de la
						 estructura */

	/* Con la estructura sockaddr_in completa, se declara en el Sistema que este proceso escuchará pedidos por la IP y el port definidos*/
	if ( (aux = bind (sockaux, (struct sockaddr *) my_addr, sizeof(struct sockaddr))) == -1)
	{
		fprintf(stderr, "Error en función bind. Código de error %s\n", strerror(aux));
		return -1;
	}
	/* Habilitamos el socket para recibir conexiones, con una cola de conexiones en espera que tendrá como máximo el tamaño especificado en BACKLOG*/
	if ((aux = listen (sockaux, BACKLOG)) == -1)
	{
		fprintf(stderr, "Error en función listen. Código de error %s\n", strerror(aux));
		return -1;
        }
	return sockaux;
}


int Aceptar_pedidos (int sockfd)
{
	int newfd; 	/* Por este socket duplicado del inicial se transaccionará*/
        struct sockaddr_in their_addr;  /* Contendra la direccion IP y número de puerto del cliente */
	unsigned int sin_size = sizeof(struct sockaddr_in);

	/*Se espera por conexiones ,*/
	if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
	{
		fprintf(stderr, "Error en función accept. Código de error %s\n", strerror(newfd));
		return -1;
	}
	else
	{
		printf  ("server:  conexión desde:  %s\n", inet_ntoa(their_addr.sin_addr));
		return newfd;
	}
}
