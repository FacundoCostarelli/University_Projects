/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para la biblioteca servidor-cliente TCP.
 *          [ENG] Usage example program for the TCP server-client library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Demuestra los patrones portables de la biblioteca:
 *       1. Escritura de estructuras a archivo binario
 *       2. Lectura de estructuras desde archivo binario
 *       3. Referencia de uso para servidor y cliente TCP
 *
 * [ENG] Demonstrates the portable library patterns:
 *       1. Writing structs to a binary file
 *       2. Reading structs from a binary file
 *       3. Reference usage for TCP server and client
 *
 * [ESP] NOTA: Las funciones TCP (tcp_server_init, tcp_client_send)
 *       requieren Linux/POSIX para compilar. Las funciones de archivo
 *       binario son portables.
 *
 * [ENG] NOTE: TCP functions (tcp_server_init, tcp_client_send) require
 *       Linux/POSIX to compile. Binary file functions are portable.
 */

#include "server_client.h"

/* [ESP] Estructura de ejemplo para demostración
   [ENG] Example struct for demonstration */
typedef struct
{
    int id;
    char nombre[20];
    float valor;
} Registro_t;

int main(void)
{
    int i;

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 1: Escribir estructuras a un archivo binario
     * [ENG] Example 1: Write structs to a binary file
     * --------------------------------------------------------------- */
    printf("=== write_structs_to_binfile ===\n\n");

    Registro_t datos[] = {
        {1, "Producto A", 99.50},
        {2, "Producto B", 150.75},
        {3, "Producto C", 200.00},
        {4, "Producto D", 50.25}
    };
    int n = 4;

    int result = write_structs_to_binfile("test_registros.dat",
                                          datos, sizeof(Registro_t), n);
    if (result == ERROR)
    {
        printf("[ESP] Error escribiendo archivo.\n");
        printf("[ENG] Error writing file.\n");
        return ERROR;
    }

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 2: Leer estructuras desde el archivo binario
     * [ENG] Example 2: Read structs from the binary file
     * --------------------------------------------------------------- */
    printf("\n=== read_structs_from_binfile ===\n\n");

    Registro_t *leidos = NULL;
    int count = read_structs_from_binfile("test_registros.dat",
                                          sizeof(Registro_t), (void **)&leidos);

    if (count > 0 && leidos != NULL)
    {
        printf("[ESP] Se leyeron %d registros:\n", count);
        printf("[ENG] Read %d records:\n\n", count);

        for (i = 0; i < count; i++)
        {
            printf("  [%d] ID: %d | Nombre/Name: %-12s | Valor/Value: %.2f\n",
                   i, leidos[i].id, leidos[i].nombre, leidos[i].valor);
        }

        /* [ESP] Liberar memoria dinámica alocada por read_structs_from_binfile
           [ENG] Free dynamic memory allocated by read_structs_from_binfile */
        free(leidos);
    }

    /* [ESP] Limpiar archivo de prueba
       [ENG] Clean up test file */
    remove("test_registros.dat");

    /* ---------------------------------------------------------------
     * [ESP] Referencia: Patrón de servidor TCP
     * [ENG] Reference: TCP server pattern
     *
     *   struct sockaddr_in addr;
     *   int sockfd = tcp_server_init(&addr, PORT, 60);
     *
     *   while (is_server_running())
     *   {
     *       int client = Aceptar_pedidos(sockfd);
     *       if (client == -1) break;
     *
     *       char buffer[64];
     *       recv(client, buffer, sizeof(buffer), 0);
     *       // ... procesar / process ...
     *       send(client, "OK", 3, 0);
     *       close(client);
     *   }
     *
     *   close(sockfd);
     * --------------------------------------------------------------- */

    /* ---------------------------------------------------------------
     * [ESP] Referencia: Patrón de cliente TCP
     * [ENG] Reference: TCP client pattern
     *
     *   char response[64];
     *   tcp_client_send(PORT, "localhost", "Hello", 6,
     *                   response, sizeof(response));
     *   printf("Server says: %s\n", response);
     * --------------------------------------------------------------- */

    printf("\n[ESP] Ejemplo completado exitosamente.\n");
    printf("[ENG] Example completed successfully.\n");

    return 0;
}
