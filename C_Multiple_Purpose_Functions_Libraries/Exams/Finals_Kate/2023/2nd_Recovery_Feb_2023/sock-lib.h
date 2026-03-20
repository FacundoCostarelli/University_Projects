/**
 * @file    sock-lib.h
 * @brief   [ESP] Cabecera auxiliar de sockets. 2do Recup 2023.
 *          [ENG] Socket helper header. 2nd Makeup exam 2023.
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

#define PORT 8010	/* El puerto donde se conectará, servidor */
#define BACKLOG 10	/* Tamaño de la cola de conexiones recibidas */

/* [ESP] Prototipos de funciones de Sockets / [ENG] Socket function prototypes */
int conectar(int, char *);
int Open_conection(struct sockaddr_in *, int); 
int Aceptar_pedidos(int);

#endif /* SOCK_LIB_H */
