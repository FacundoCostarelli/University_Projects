/**
 * @file    servidor.c
 * @brief   [ESP] Servidor del 2do Parcial Recuperatorio Feb 2023 (Versión Original).
 *          [ENG] Server of the 2nd Midterm Recovery Feb 2023 (Original Version).
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 8010	/* [ESP] Puerto del servidor / [ENG] Server port */
#define BACKLOG 10	/* [ESP] Cola de conexiones / [ENG] Connections queue size */
#define FALSE 0
#define TRUE 1

/**
 * @brief [ESP] Estructura que almacena los datos del alumno en el servidor.
 *        [ENG] Structure that stores the student data in the server.
 */
struct alumno
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
    int repartido;
    int banned;
};

/**
 * @brief [ESP] Conecta con el servidor.
 *        [ENG] Connects to the server.
 */
int conectar(int, char **);

/**
 * @brief [ESP] Crea la conexión y el socket.
 *        [ENG] Creates connection and socket.
 */
int Open_conection(struct sockaddr_in *, int);

/**
 * @brief [ESP] Acepta la conexión.
 *        [ENG] Accepts the connection.
 */
int Aceptar_pedidos(int);

/**
 * @brief [ESP] Devuelve un numero aleatorio entre rango determinado.
 *        [ENG] Returns a random number between determined range.
 */
int aleatorio_en_rango(int minimo, int maximo);


/**
 * @brief [ESP] Función principal del servidor original.
 *        [ENG] Main function of original server.
 *
 * @return 0 [ESP] Si la ejecución cruzó correcta. / [ENG] If execution passes correctly.
 */
int main()
{
    /*
    int fd, fd_new, legajo, DNI, nro_examen;
    char nombre[20];
    char apellido[20];
    // int repartido;
    // int banned;
    char nombre_examen[10];
    int i;
    int cant_structs_alumnos;
    long tamanio_archivo;
    */
    FILE *File_in = NULL;
    char *nombre_archivo = "alumnos.dat";

    // memset(nombre_examen,0,sizeof(nombre_examen));
    // strcpy(nombre_examen,"TX.tar.gz");

    srand(time(NULL));

    File_in = fopen(nombre_archivo, "r");
    if(File_in == NULL)
    {
        printf("Error en la apertura del archivo de entrada\n");
        return -1;
    }

    /* [ESP] Código incompleto en original / [ENG] Incomplete code in original */

    /*
    tamanio_archivo = ftell(File_in);
    cant_structs_alumnos = tamanio_archivo/sizeof(struct alumno);
    struct alumno array[cant_structs_alumnos];

    for( i = 0; i < cant_structs_alumnos; i++ )
    {
        fread(&array[i], sizeof(struct alumno), 1, File_in);
        array[i].repartido = FALSE;
        array[i].banned = FALSE;
    }

    fd = Open_conection(&my_addr,PORT);
    fd_new = Aceptar_pedidos(fd);

    recibir(fd_new, &legajo,&DNI,nombre,apellido);
    ...
    */

    return 0;
}

int aleatorio_en_rango(int minimo, int maximo)
{
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

int conectar (int port, char dest[])
{
	int	sockfd;
	struct hostent *he;	
	struct sockaddr_in their_addr;  

	if ((he = gethostbyname ((const char *) dest)) == NULL)
	{
		herror("Error en Nombre de Host");
		exit(1);
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error en creacion de socket");
		exit(1);
	}

	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(port);
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

	if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Error tratando de conectar al server");
		exit(1);
	}
	return sockfd;
}

int Open_conection ( struct sockaddr_in * my_addr, int port)
{
	int	sockaux;	
	int	aux; 		

	if ((sockaux = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "Error en funcion socket. Codigo de error %s\n", strerror(sockaux));
		return -1;
	}

	my_addr->sin_family = AF_INET;		
	my_addr->sin_port = htons(port);	
	my_addr->sin_addr.s_addr = INADDR_ANY;	
	bzero(&(my_addr->sin_zero), 8);		

	if ( (aux = bind (sockaux, (struct sockaddr *) my_addr, sizeof(struct sockaddr))) == -1)
	{
		fprintf(stderr, "Error en funcion bind. Codigo de error %s\n", strerror(aux));
		return -1;
	}
	
	if ((aux = listen (sockaux, BACKLOG)) == -1)
	{
		fprintf(stderr, "Error en funcion listen. Codigo de error %s\n", strerror(aux));
		return -1;
    }
	return sockaux;
}

int Aceptar_pedidos (int sockfd)
{
	int newfd; 	
    struct sockaddr_in their_addr;  
	unsigned int sin_size = sizeof(struct sockaddr_in);

	if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
	{
		fprintf(stderr, "Error en funcion accept. Codigo de error %s\n", strerror(newfd));
		return -1;
	}
	else
	{
		printf ("server: conexion desde: %s\n", inet_ntoa(their_addr.sin_addr));
		return newfd;
	}
}
