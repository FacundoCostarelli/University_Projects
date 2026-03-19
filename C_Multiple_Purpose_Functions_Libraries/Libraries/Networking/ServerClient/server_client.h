/**
 * @file    server_client.h
 * @brief   [ESP] Biblioteca portable de patrones TCP cliente-servidor.
 *          [ENG] Portable TCP client-server patterns library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Funciones de alto nivel construidas sobre sock_lib.h para
 *       implementar patrones comunes en aplicaciones cliente-servidor:
 *       - Inicialización de servidor con timeout por señales
 *       - Loop de aceptación de conexiones
 *       - Conexión de cliente con envío de datos
 *       - Serialización/deserialización de estructuras a texto
 *       - Lectura de estructuras desde archivos binarios
 *
 * [ENG] High-level functions built on top of sock_lib.h for
 *       implementing common client-server application patterns:
 *       - Server initialization with signal-based timeout
 *       - Connection acceptance loop
 *       - Client connection with data sending
 *       - Struct serialization/deserialization to/from text
 *       - Reading structs from binary files
 *
 * [ESP] NOTA: Estas funciones solo compilan en Linux/POSIX.
 * [ENG] NOTE: These functions only compile on Linux/POSIX.
 */

#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H

#include "../sock_lib.h"
#include <signal.h>
#include <time.h>
#include <string.h>

/** @brief [ESP] Temporizador por defecto (segundos) / [ENG] Default timer (seconds) */
#define DEFAULT_TIMEOUT 30

/** @brief [ESP] Código de error / [ENG] Error code */
#ifndef ERROR
#define ERROR -1
#endif

/** @brief [ESP] Código de éxito / [ENG] Success code */
#ifndef EXITO
#define EXITO 0
#endif

#ifndef TRUE
#define TRUE  1
#define FALSE 0
#endif

/**
 * @brief [ESP] Inicializa un servidor TCP con timeout por señal SIGALRM.
 *        [ENG] Initializes a TCP server with SIGALRM signal timeout.
 *
 * [ESP] Crea el socket servidor, configura el handler de SIGALRM y
 *       programa la alarma. Cuando el temporizador expira, la bandera
 *       global server_running se pone en 0 para detener el loop.
 *
 * [ENG] Creates the server socket, sets up the SIGALRM handler, and
 *       schedules the alarm. When the timer expires, the global flag
 *       server_running is set to 0 to stop the loop.
 *
 * @param[out] addr           [ESP] Estructura sockaddr_in a completar.
 *                            [ENG] sockaddr_in structure to fill.
 * @param[in]  port           [ESP] Puerto donde escuchar.
 *                            [ENG] Port to listen on.
 * @param[in]  timeout_secs   [ESP] Segundos antes del timeout (0 = sin timeout).
 *                            [ENG] Seconds before timeout (0 = no timeout).
 * @return                    [ESP] Descriptor del socket servidor, o ERROR.
 *                            [ENG] Server socket descriptor, or ERROR.
 *
 * @example
 *   struct sockaddr_in addr;
 *   int sockfd = tcp_server_init(&addr, 8010, 60);
 */
int tcp_server_init(struct sockaddr_in *addr, int port, int timeout_secs);

/**
 * @brief [ESP] Conecta a un servidor TCP y envía un buffer de datos.
 *        [ENG] Connects to a TCP server and sends a data buffer.
 *
 * @param[in] port            [ESP] Puerto del servidor.
 *                            [ENG] Server port.
 * @param[in] host            [ESP] IP o nombre del host.
 *                            [ENG] IP or host name.
 * @param[in] send_buffer     [ESP] Datos a enviar.
 *                            [ENG] Data to send.
 * @param[in] send_size       [ESP] Tamaño de los datos en bytes.
 *                            [ENG] Size of the data in bytes.
 * @param[out] recv_buffer    [ESP] Buffer para la respuesta del servidor.
 *                            [ENG] Buffer for the server response.
 * @param[in] recv_size       [ESP] Tamaño máximo de la respuesta.
 *                            [ENG] Maximum response size.
 * @return                    [ESP] EXITO o ERROR.
 *                            [ENG] EXITO or ERROR.
 *
 * @example
 *   char response[64];
 *   tcp_client_send(8010, "localhost", "Hello", 6, response, sizeof(response));
 */
int tcp_client_send(int port, char *host, void *send_buffer, size_t send_size,
                    void *recv_buffer, size_t recv_size);

/**
 * @brief [ESP] Lee estructuras de tamaño fijo desde un archivo binario.
 *        [ENG] Reads fixed-size structs from a binary file.
 *
 * [ESP] Calcula la cantidad de estructuras a partir del tamaño del archivo,
 *       aloca memoria dinámica y lee todos los datos. El llamador debe
 *       liberar la memoria con free().
 *
 * [ENG] Calculates the number of structs from the file size, allocates
 *       dynamic memory, and reads all data. The caller must free the
 *       memory with free().
 *
 * @param[in]  filename       [ESP] Nombre del archivo binario.
 *                            [ENG] Name of the binary file.
 * @param[in]  struct_size    [ESP] Tamaño de cada estructura en bytes.
 *                            [ENG] Size of each struct in bytes.
 * @param[out] buffer         [ESP] Puntero doble void* que recibe la dirección
 *                                  del buffer alocado.
 *                            [ENG] void** double pointer that receives the
 *                                  address of the allocated buffer.
 * @return                    [ESP] Cantidad de estructuras leídas, o ERROR.
 *                            [ENG] Number of structs read, or ERROR.
 *
 * @example
 *   struct alumno *data = NULL;
 *   int n = read_structs_from_binfile("alumnos.dat", sizeof(struct alumno), (void**)&data);
 *   if (n > 0) { ... free(data); }
 */
int read_structs_from_binfile(char *filename, size_t struct_size, void **buffer);

/**
 * @brief [ESP] Escribe un array de estructuras a un archivo binario.
 *        [ENG] Writes an array of structs to a binary file.
 *
 * @param[in] filename        [ESP] Nombre del archivo de salida.
 *                            [ENG] Name of the output file.
 * @param[in] data            [ESP] Puntero a los datos a escribir.
 *                            [ENG] Pointer to the data to write.
 * @param[in] struct_size     [ESP] Tamaño de cada estructura en bytes.
 *                            [ENG] Size of each struct in bytes.
 * @param[in] count           [ESP] Cantidad de estructuras a escribir.
 *                            [ENG] Number of structs to write.
 * @return                    [ESP] EXITO o ERROR.
 *                            [ENG] EXITO or ERROR.
 *
 * @example
 *   struct alumno arr[3] = { ... };
 *   write_structs_to_binfile("output.dat", arr, sizeof(struct alumno), 3);
 */
int write_structs_to_binfile(char *filename, void *data, size_t struct_size, int count);

/**
 * @brief [ESP] Verifica si el servidor sigue corriendo (para uso en loop).
 *        [ENG] Checks if the server is still running (for use in loop).
 *
 * @return [ESP] 1 si el servidor sigue corriendo, 0 si expiró el timeout.
 *         [ENG] 1 if the server is still running, 0 if timeout expired.
 */
int is_server_running(void);

#endif /* SERVER_CLIENT_H */
