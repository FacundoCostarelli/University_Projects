/**
 * @file    signals_example.c
 * @brief   [ESP] Ejemplo compilable de manejo de señales con select().
 *          [ENG] Compilable example of signal handling with select().
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Programa standalone que combina monitoreo de teclado (stdin)
 *       con un temporizador de 5 segundos usando select(). Se sale
 *       del loop al recibir SIGUSR1.
 *
 * [ENG] Standalone program that combines keyboard monitoring (stdin)
 *       with a 5-second timer using select(). Exits the loop when
 *       SIGUSR1 is received.
 */

#include "signals.h"
#include <termios.h>

volatile sig_atomic_t exit_flag = 0;

void signal_handler(int signum)
{
    exit_flag = 1;
}

int main(void)
{
    int resultado, maxfd;
    fd_set readfds;
    struct timeval timeout;
    struct sigaction sa;

    /* [ESP] Configurar handler para SIGUSR1 usando sigaction()
       [ENG] Configure SIGUSR1 handler using sigaction() */
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("[ESP] Error en sigaction / [ENG] sigaction error");
        exit(1);
    }

    maxfd = STDIN_FILENO + 1;

    printf("[ESP] Esperando entrada de teclado o SIGUSR1...\n");
    printf("[ENG] Waiting for keyboard input or SIGUSR1...\n");
    printf("[ESP] Enviar SIGUSR1 con: kill -USR1 %d\n", getpid());
    printf("[ENG] Send SIGUSR1 with: kill -USR1 %d\n\n", getpid());

    while (!exit_flag)
    {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);

        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        resultado = select(maxfd, &readfds, NULL, NULL, &timeout);

        if (resultado == -1)
        {
            perror("[ESP] Error en select / [ENG] select error");
            break;
        }
        else if (resultado == 0)
        {
            printf("[ESP] 5 segundos sin actividad.\n");
            printf("[ENG] 5 seconds without activity.\n");
            continue;
        }

        if (FD_ISSET(STDIN_FILENO, &readfds))
        {
            char c;
            read(STDIN_FILENO, &c, 1);
            printf("[ESP] Tecla: %c\n", c);
            printf("[ENG] Key:   %c\n", c);
        }
    }

    printf("\n[ESP] SIGUSR1 recibida, saliendo.\n");
    printf("[ENG] SIGUSR1 received, exiting.\n");

    return 0;
}
