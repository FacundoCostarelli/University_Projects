/**
 * @file    sock_lib.c
 * @brief   [ESP] Implementación de funciones de red TCP.
 *          [ENG] Implementation of TCP networking functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "sock_lib.h"

/**
 * @brief [ESP] Conecta a un servidor TCP remoto (lado cliente).
 *        [ENG] Connects to a remote TCP server (client side).
 */
int conectar(int port, char dest[])
{
    int sockfd;
    struct hostent *he;
    struct sockaddr_in their_addr;

    /* [ESP] Convertir nombre de host a dirección IP con gethostbyname().
             Retorna una estructura hostent con la info del host.
       [ENG] Convert host name to IP address with gethostbyname().
             Returns a hostent struct with host info. */
    if ((he = gethostbyname((const char *)dest)) == NULL)
    {
        herror("[ESP] Error en nombre de host / [ENG] Host name error");
        exit(1);
    }

    /* [ESP] Crear socket TCP (AF_INET = IPv4, SOCK_STREAM = TCP)
       [ENG] Create TCP socket (AF_INET = IPv4, SOCK_STREAM = TCP) */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("[ESP] Error creando socket / [ENG] Socket creation error");
        exit(1);
    }

    /* [ESP] Configurar la estructura sockaddr_in con la dirección del servidor:
             - sin_family: familia de direcciones (AF_INET para IPv4)
             - sin_port: puerto en formato network byte order (htons)
             - sin_addr: dirección IP del servidor
       [ENG] Configure the sockaddr_in structure with the server address:
             - sin_family: address family (AF_INET for IPv4)
             - sin_port: port in network byte order (htons)
             - sin_addr: server IP address */
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(port);
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    bzero(&(their_addr.sin_zero), 8);

    /* [ESP] Intentar conectar al servidor con connect()
       [ENG] Attempt to connect to the server with connect() */
    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("[ESP] Error conectando al servidor / [ENG] Server connection error");
        exit(1);
    }

    return sockfd;
}

/**
 * @brief [ESP] Abre una conexión como servidor TCP (bind + listen).
 *        [ENG] Opens a connection as a TCP server (bind + listen).
 */
int Open_conection(struct sockaddr_in *my_addr, int port)
{
    int sockaux;
    int aux;

    /* [ESP] Crear socket TCP
       [ENG] Create TCP socket */
    if ((sockaux = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        fprintf(stderr, "[ESP] Error en socket: %s\n[ENG] Socket error: %s\n", strerror(errno), strerror(errno));
        return -1;
    }

    /* [ESP] Configurar la estructura sockaddr_in para el servidor:
             - INADDR_ANY: escuchar en todas las interfaces de red
             - htons(): convertir puerto a formato network byte order
       [ENG] Configure the sockaddr_in structure for the server:
             - INADDR_ANY: listen on all network interfaces
             - htons(): convert port to network byte order */
    my_addr->sin_family = AF_INET;
    my_addr->sin_port = htons(port);
    my_addr->sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr->sin_zero), 8);

    /* [ESP] Asociar el socket al puerto con bind().
             Esto le dice al SO que este proceso escuchará en este puerto.
       [ENG] Bind the socket to the port with bind().
             This tells the OS that this process will listen on this port. */
    if ((aux = bind(sockaux, (struct sockaddr *)my_addr, sizeof(struct sockaddr))) == -1)
    {
        fprintf(stderr, "[ESP] Error en bind: %s\n[ENG] Bind error: %s\n", strerror(errno), strerror(errno));
        return -1;
    }

    /* [ESP] Habilitar escucha con listen(). BACKLOG define el tamaño
             máximo de la cola de conexiones pendientes.
       [ENG] Enable listening with listen(). BACKLOG defines the maximum
             size of the pending connection queue. */
    if ((aux = listen(sockaux, BACKLOG)) == -1)
    {
        fprintf(stderr, "[ESP] Error en listen: %s\n[ENG] Listen error: %s\n", strerror(errno), strerror(errno));
        return -1;
    }

    return sockaux;
}

/**
 * @brief [ESP] Acepta una conexión entrante de un cliente.
 *        [ENG] Accepts an incoming connection from a client.
 */
int Aceptar_pedidos(int sockfd)
{
    int newfd;
    struct sockaddr_in their_addr;
    unsigned int sin_size = sizeof(struct sockaddr_in);

    /* [ESP] accept() bloquea hasta que llega una conexión de un cliente.
             Retorna un nuevo descriptor de socket para comunicarse con ese cliente.
             El socket original (sockfd) sigue escuchando nuevas conexiones.
       [ENG] accept() blocks until a client connection arrives.
             Returns a new socket descriptor for communicating with that client.
             The original socket (sockfd) continues listening for new connections. */
    if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
    {
        fprintf(stderr, "[ESP] Error en accept: %s\n[ENG] Accept error: %s\n", strerror(errno), strerror(errno));
        return -1;
    }
    else
    {
        /* [ESP] Imprimir la IP del cliente conectado
           [ENG] Print the connected client's IP address */
        printf("[ESP] Conexión desde: %s\n", inet_ntoa(their_addr.sin_addr));
        printf("[ENG] Connection from: %s\n", inet_ntoa(their_addr.sin_addr));
        return newfd;
    }
}
