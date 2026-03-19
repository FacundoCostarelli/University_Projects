/**
 * @file    sock_lib.h
 * @brief   [ESP] Biblioteca de sockets TCP (declaraciones).
 *          [ENG] TCP socket library (declarations).
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Proporciona funciones para crear conexiones TCP tanto del lado
 *       del cliente como del servidor. Incluye resolución de nombres
 *       de host, creación de sockets, bind, listen y accept.
 *
 * [ENG] Provides functions to create TCP connections on both client
 *       and server sides. Includes host name resolution, socket
 *       creation, bind, listen, and accept.
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

/** @brief [ESP] Puerto por defecto del servidor / [ENG] Default server port */
#define PORT    8010

/** @brief [ESP] Tamaño de la cola de conexiones pendientes / [ENG] Pending connection queue size */
#define BACKLOG 10

/**
 * @brief [ESP] Conecta a un servidor TCP remoto (lado cliente).
 *        [ENG] Connects to a remote TCP server (client side).
 *
 * [ESP] Resuelve el nombre del host, crea un socket TCP, y establece
 *       la conexión con connect().
 *
 * [ENG] Resolves the host name, creates a TCP socket, and establishes
 *       the connection with connect().
 *
 * @param[in] port  [ESP] Puerto del servidor al que conectarse.
 *                  [ENG] Server port to connect to.
 * @param[in] dest  [ESP] Nombre o IP del host destino.
 *                  [ENG] Destination host name or IP.
 * @return          [ESP] Descriptor del socket creado (>= 0), o termina con exit(1) si falla.
 *                  [ENG] Created socket descriptor (>= 0), or terminates with exit(1) on failure.
 *
 * @example
 *   int sockfd = conectar(8010, "192.168.1.100");
 *   send(sockfd, "Hello", 5, 0);
 *   close(sockfd);
 */
int conectar(int port, char *dest);

/**
 * @brief [ESP] Abre una conexión como servidor TCP (bind + listen).
 *        [ENG] Opens a connection as a TCP server (bind + listen).
 *
 * [ESP] Crea un socket, lo asocia a un puerto con bind(), y habilita
 *       la escucha de conexiones con listen().
 *
 * [ENG] Creates a socket, binds it to a port with bind(), and enables
 *       connection listening with listen().
 *
 * @param[out] my_addr  [ESP] Estructura sockaddr_in que será completada.
 *                      [ENG] sockaddr_in structure that will be filled.
 * @param[in]  port     [ESP] Puerto en el que escuchar.
 *                      [ENG] Port to listen on.
 * @return              [ESP] Descriptor del socket servidor (>= 0), o -1 si falla.
 *                      [ENG] Server socket descriptor (>= 0), or -1 on failure.
 *
 * @example
 *   struct sockaddr_in addr;
 *   int sockfd = Open_conection(&addr, 8010);
 */
int Open_conection(struct sockaddr_in *my_addr, int port);

/**
 * @brief [ESP] Acepta una conexión entrante de un cliente.
 *        [ENG] Accepts an incoming connection from a client.
 *
 * [ESP] Bloquea hasta que un cliente se conecta. Retorna un nuevo
 *       descriptor de socket para la comunicación con el cliente.
 *
 * [ENG] Blocks until a client connects. Returns a new socket
 *       descriptor for communication with the client.
 *
 * @param[in] sockfd  [ESP] Descriptor del socket servidor (de Open_conection).
 *                    [ENG] Server socket descriptor (from Open_conection).
 * @return            [ESP] Descriptor del socket del cliente (>= 0), o -1 si falla.
 *                    [ENG] Client socket descriptor (>= 0), or -1 on failure.
 *
 * @example
 *   int client_fd = Aceptar_pedidos(sockfd);
 *   recv(client_fd, buffer, sizeof(buffer), 0);
 *   close(client_fd);
 */
int Aceptar_pedidos(int sockfd);

#endif /* SOCK_LIB_H */
