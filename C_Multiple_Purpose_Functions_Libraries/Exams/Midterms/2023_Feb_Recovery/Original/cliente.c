/**
 * @file    cliente.c
 * @brief   [ESP] Cliente del 2do Parcial Recuperatorio Feb 2023 (Versión Original).
 *          [ENG] Client of the 2nd Midterm Recovery Feb 2023 (Original Version).
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8010	/* [ESP] Puerto del servidor / [ENG] Server port */
#define BACKLOG 10	/* [ESP] Cola de conexiones / [ENG] Connections queue size */


/**
 * @brief [ESP] Conecta con el servidor.
 *        [ENG] Connects to the server.
 */
int	conectar (int, char **);

/**
 * @brief [ESP] Función que crea la conexión.
 *        [ENG] Function that creates connection.
 */
int	Open_conection (struct sockaddr_in *, int);

/**
 * @brief [ESP] Función que acepta conexión entrante.
 *        [ENG] Function that accepts incoming connection.
 */
int	Aceptar_pedidos (int);


/**
 * @brief [ESP] Función principal del cliente original.
 *        [ENG] Main function of original client.
 *
 * @return 0 [ESP] Si la ejecución cruzó correcta. / [ENG] If execution passes correctly.
 */
int main(int argc, char **argv)
{
    // int fd;
    // char dest[15];
    // char nombre[20] = "Facundo";
    // char apellido[20] = "Costarelli";
    
    if(argc != 3)
    {
        printf("Error. Uso: <ejecutable> <legajo> <dni>\n");
        return -1;
    }
    
    return 0;

    /* [ESP] Conexión y envío (código comentado en el original) 
       [ENG] Connection and sending (commented code in the original) */
       
    // fd = conectar(PORT, dest);
    // enviar(fd, argv[1], argv[2], nombre, apellido);

    // return 0;
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
		printf("server: conexion desde: %s\n", inet_ntoa(their_addr.sin_addr));
		return newfd;
	}
}
