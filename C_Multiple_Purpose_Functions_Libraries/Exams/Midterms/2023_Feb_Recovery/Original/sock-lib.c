/**
 * @file    sock-lib.c
 * @brief   [ESP] Librería de sockets simplificada para clientes y servidores.
 *          [ENG] Simplified sockets library for clients and servers.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "sock-lib.h"

int conectar(int port, char dest[])
{
	int sockfd;
	struct hostent *he;	/* [ESP] Convierte host a IP / [ENG] Converts host to IP */
	struct sockaddr_in their_addr;  /* [ESP] Direccion del servidor / [ENG] Server address */

	if ((he = gethostbyname((const char *) dest)) == NULL)
	{
		herror("Error en Nombre de Host");
		exit(1);
	}
 
	/* [ESP] Creamos el socket / [ENG] We create the socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error en creación de socket");
		exit(1);
	}

	/* [ESP] Direccion del servidor / [ENG] Server address setup */
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(port);
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

	/* [ESP] Intentamos conectar / [ENG] Attempt to connect */
	if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Error tratando de conectar al server");
		exit(1);
	}
	return sockfd;
}

int Open_conection(struct sockaddr_in *my_addr, int port)
{
	int sockaux;	
	int aux; 		

	/* [ESP] Crea socket y verifica error / [ENG] Creates socket and verifies error */
	if ((sockaux = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
	{
		fprintf(stderr, "Error en función socket. Código de error %s\n", strerror(sockaux));
		return -1;
	}

	/* [ESP] Valores de my_addr / [ENG] my_addr assignments */
	my_addr->sin_family = AF_INET;
	my_addr->sin_port = htons(port);	
	my_addr->sin_addr.s_addr = INADDR_ANY;	
	bzero(&(my_addr->sin_zero), 8);		

	/* [ESP] Vinculamos IP y port / [ENG] Bind IP and port */
	if ((aux = bind(sockaux, (struct sockaddr *) my_addr, sizeof(struct sockaddr))) == -1)
	{
		fprintf(stderr, "Error en función bind. Código de error %s\n", strerror(aux));
		return -1;
	}
	
    /* [ESP] Escucha conexiones / [ENG] Listen to connections */
	if ((aux = listen(sockaux, BACKLOG)) == -1)
	{
		fprintf(stderr, "Error en función listen. Código de error %s\n", strerror(aux));
		return -1;
    }
	return sockaux;
}

int Aceptar_pedidos(int sockfd)
{
	int newfd; 	
    struct sockaddr_in their_addr;  
	unsigned int sin_size = sizeof(struct sockaddr_in);

	/* [ESP] Acepta conexion entrante / [ENG] Accepts incoming connection */
	if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
	{
		fprintf(stderr, "Error en función accept. Código de error %s\n", strerror(newfd));
		return -1;
	}
	else
	{
		printf("server: conexión desde: %s\n", inet_ntoa(their_addr.sin_addr));
		return newfd;
	}
}
