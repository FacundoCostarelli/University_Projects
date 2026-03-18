/**
 * ==========================================================================
 * sock_lib.h — TCP Socket Library (Header)
 * ==========================================================================
 * [ESP] Declaraciones para la biblioteca de sockets TCP.
 *       Incluye funciones para conectar a un servidor, abrir una conexión
 *       como servidor, y aceptar conexiones entrantes.
 *
 * [ENG] Declarations for the TCP socket library.
 *       Includes functions to connect to a server, open a connection
 *       as a server, and accept incoming connections.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

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



#define PORT 8010	/* El puerto donde se conectará, servidor */
#define BACKLOG 10	/* Tamaño de la cola de conexiones recibidas */

int	conectar (int, char *);

int	Open_conection (struct sockaddr_in *, int); /* Función que crea la conexión*/

int	Aceptar_pedidos (int);	/* Función que acepta una conexión entrante*/
