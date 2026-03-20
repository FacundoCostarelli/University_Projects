/**
 * @file    sock-lib.h
 * @brief   [ESP] Cabecera de librería de sockets simplificada.
 *          [ENG] Header of simplified sockets library.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#ifndef SOCK_LIB_H
#define SOCK_LIB_H

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

#define PORT 8010	/* [ESP] Puerto del servidor / [ENG] Server port */
#define BACKLOG 10	/* [ESP] Cola de conexiones / [ENG] Connections queue size */

/**
 * @brief [ESP] Conecta un cliente a un puerto y destino dados.
 *        [ENG] Connects a client to a given port and destination.
 */
int conectar(int, char *);

/**
 * @brief [ESP] Crea y abre la conexión del servidor.
 *        [ENG] Creates and opens the server connection.
 */
int Open_conection(struct sockaddr_in *, int);

/**
 * @brief [ESP] Acepta una conexión entrante en el servidor.
 *        [ENG] Accepts an incoming connection on the server.
 */
int Aceptar_pedidos(int);

#endif /* SOCK_LIB_H */
