/**
 * @file    server_client.c
 * @brief   [ESP] Implementación de patrones TCP cliente-servidor portables.
 *          [ENG] Implementation of portable TCP client-server patterns.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Patrones generalizados extraídos del examen 2do Recuperatorio
 *       Feb 2023. Construidos sobre sock_lib.h para ser reutilizables.
 *
 * [ENG] Generalized patterns extracted from the 2nd Recuperatorio
 *       Feb 2023 exam. Built on top of sock_lib.h for reusability.
 */

#include "server_client.h"

/* ===========================================================================
 * [ESP] VARIABLE GLOBAL — ESTADO DEL SERVIDOR
 * [ENG] GLOBAL VARIABLE — SERVER STATE
 *
 * [ESP] 'volatile sig_atomic_t' garantiza que el handler de señal pueda
 *       modificarla de forma segura. Se inicializa en TRUE.
 * [ENG] 'volatile sig_atomic_t' ensures the signal handler can modify
 *       it safely. Initialized to TRUE.
 * =========================================================================== */
static volatile sig_atomic_t server_running = TRUE;

/* ===========================================================================
 * [ESP] HANDLER DE SEÑAL SIGALRM — TIMEOUT DEL SERVIDOR
 * [ENG] SIGALRM SIGNAL HANDLER — SERVER TIMEOUT
 * =========================================================================== */

/**
 * @brief [ESP] Handler interno: detiene el servidor al expirar el timer.
 *        [ENG] Internal handler: stops the server when the timer expires.
 */
static void timeout_handler(int signum)
{
    (void)signum; /* [ESP] evitar warning de variable no usada / [ENG] avoid unused variable warning */
    server_running = FALSE;
}

/* ===========================================================================
 * [ESP] FUNCIONES DE SERVIDOR
 * [ENG] SERVER FUNCTIONS
 * =========================================================================== */

/**
 * @brief [ESP] Inicializa un servidor TCP con timeout por señal SIGALRM.
 *        [ENG] Initializes a TCP server with SIGALRM signal timeout.
 */
int tcp_server_init(struct sockaddr_in *addr, int port, int timeout_secs)
{
    int sockfd;

    /* [ESP] Paso 1: Resetear la bandera de estado del servidor
       [ENG] Step 1: Reset the server state flag */
    server_running = TRUE;

    /* [ESP] Paso 2: Configurar el handler de señal SIGALRM.
             Cuando alarm() expire, timeout_handler() cambiará
             server_running a FALSE, deteniendo el loop de accept().
       [ENG] Step 2: Configure the SIGALRM signal handler.
             When alarm() expires, timeout_handler() will change
             server_running to FALSE, stopping the accept() loop. */
    if (timeout_secs > 0)
    {
        signal(SIGALRM, timeout_handler);
        alarm(timeout_secs);
    }

    /* [ESP] Paso 3: Crear socket, bind y listen usando sock_lib
       [ENG] Step 3: Create socket, bind, and listen using sock_lib */
    sockfd = Open_conection(addr, port);
    if (sockfd == -1)
    {
        fprintf(stderr, "[ESP] Error inicializando servidor en puerto %d.\n", port);
        fprintf(stderr, "[ENG] Error initializing server on port %d.\n", port);
        return ERROR;
    }

    printf("[ESP] Servidor iniciado en puerto %d", port);
    printf(" (timeout: %ds)\n", timeout_secs);
    printf("[ENG] Server started on port %d", port);
    printf(" (timeout: %ds)\n", timeout_secs);

    return sockfd;
}

/**
 * @brief [ESP] Verifica si el servidor sigue corriendo.
 *        [ENG] Checks if the server is still running.
 */
int is_server_running(void)
{
    return server_running;
}

/* ===========================================================================
 * [ESP] FUNCIONES DE CLIENTE
 * [ENG] CLIENT FUNCTIONS
 * =========================================================================== */

/**
 * @brief [ESP] Conecta a un servidor TCP, envía datos y recibe respuesta.
 *        [ENG] Connects to a TCP server, sends data, and receives response.
 */
int tcp_client_send(int port, char *host, void *send_buffer, size_t send_size,
                    void *recv_buffer, size_t recv_size)
{
    int sockfd;

    /* [ESP] Paso 1: Conectar al servidor
       [ENG] Step 1: Connect to the server */
    sockfd = conectar(port, host);

    /* [ESP] Paso 2: Enviar datos al servidor
       [ENG] Step 2: Send data to the server */
    if (send(sockfd, send_buffer, send_size, 0) == -1)
    {
        perror("[ESP] Error en send / [ENG] send error");
        close(sockfd);
        return ERROR;
    }

    /* [ESP] Paso 3: Recibir respuesta del servidor (si se proporcionó buffer)
       [ENG] Step 3: Receive response from server (if buffer provided) */
    if (recv_buffer != NULL && recv_size > 0)
    {
        if (recv(sockfd, recv_buffer, recv_size, 0) == -1)
        {
            perror("[ESP] Error en recv / [ENG] recv error");
            close(sockfd);
            return ERROR;
        }
    }

    /* [ESP] Paso 4: Cerrar conexión
       [ENG] Step 4: Close connection */
    close(sockfd);

    return EXITO;
}

/* ===========================================================================
 * [ESP] FUNCIONES DE ARCHIVOS BINARIOS — ESTRUCTURAS GENÉRICAS
 * [ENG] BINARY FILE FUNCTIONS — GENERIC STRUCTS
 * =========================================================================== */

/**
 * @brief [ESP] Lee estructuras de tamaño fijo desde un archivo binario.
 *        [ENG] Reads fixed-size structs from a binary file.
 */
int read_structs_from_binfile(char *filename, size_t struct_size, void **buffer)
{
    FILE *f = NULL;
    long file_size = 0;
    int count = 0;

    /* [ESP] Abrir archivo en modo lectura binaria
       [ENG] Open file in binary read mode */
    f = fopen(filename, "rb");
    if (f == NULL)
    {
        fprintf(stderr, "[ESP] Error abriendo '%s'.\n", filename);
        fprintf(stderr, "[ENG] Error opening '%s'.\n", filename);
        return ERROR;
    }

    /* [ESP] Calcular tamaño del archivo y cantidad de estructuras:
             fseek al final → ftell → dividir por struct_size
       [ENG] Calculate file size and struct count:
             fseek to end → ftell → divide by struct_size */
    fseek(f, 0, SEEK_END);
    file_size = ftell(f);
    count = (int)(file_size / (long)struct_size);
    fseek(f, 0, SEEK_SET);

    if (count <= 0)
    {
        fclose(f);
        return 0;
    }

    /* [ESP] Alocar memoria dinámica para todas las estructuras
       [ENG] Allocate dynamic memory for all structs */
    *buffer = malloc(count * struct_size);
    if (*buffer == NULL)
    {
        fprintf(stderr, "[ESP] Error en malloc.\n[ENG] malloc error.\n");
        fclose(f);
        return ERROR;
    }

    /* [ESP] Leer todas las estructuras a memoria
       [ENG] Read all structs into memory */
    if (fread(*buffer, struct_size, count, f) < (size_t)count)
    {
        fprintf(stderr, "[ESP] Error en fread.\n[ENG] fread error.\n");
        free(*buffer);
        *buffer = NULL;
        fclose(f);
        return ERROR;
    }

    fclose(f);

    /* [ESP] NOTA: El llamador debe liberar *buffer con free()
       [ENG] NOTE: The caller must free *buffer with free() */
    return count;
}

/**
 * @brief [ESP] Escribe un array de estructuras a un archivo binario.
 *        [ENG] Writes an array of structs to a binary file.
 */
int write_structs_to_binfile(char *filename, void *data, size_t struct_size, int count)
{
    FILE *f = NULL;

    /* [ESP] Abrir/crear archivo en modo escritura binaria
       [ENG] Open/create file in binary write mode */
    f = fopen(filename, "wb");
    if (f == NULL)
    {
        fprintf(stderr, "[ESP] Error abriendo '%s'.\n", filename);
        fprintf(stderr, "[ENG] Error opening '%s'.\n", filename);
        return ERROR;
    }

    /* [ESP] Escribir todas las estructuras al archivo
       [ENG] Write all structs to the file */
    if ((int)fwrite(data, struct_size, count, f) < count)
    {
        fprintf(stderr, "[ESP] Error en fwrite.\n[ENG] fwrite error.\n");
        fclose(f);
        return ERROR;
    }

    fclose(f);

    printf("[ESP] %d estructuras escritas en '%s'.\n", count, filename);
    printf("[ENG] %d structs written to '%s'.\n", count, filename);

    return EXITO;
}
