/**
 * ==========================================================================
 * signals_example.c — Signal Handling with select() and Timers
 * ==========================================================================
 * [ESP] Ejemplo de manejo de señales POSIX con select().
 *       Usa SIGUSR1 para salir de un loop principal, combinando
 *       monitoreo de teclado (stdin) con un temporizador de 5 segundos.
 *       Demuestra el uso de sigaction, fd_set, y struct timeval.
 *
 * [ENG] Example of POSIX signal handling with select().
 *       Uses SIGUSR1 to exit a main loop, combining keyboard monitoring
 *       (stdin) with a 5-second timer. Demonstrates usage of sigaction,
 *       fd_set, and struct timeval.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

volatile sig_atomic_t flag = 0;

void signal_handler(int signum) {
    flag = 1;
}

int main() {
    int resultado,maxfd;
    fd_set readfds; //para guardar los fd que lee select.

    struct timeval timeout; //estructura para el timer de select.
    struct sigaction sa;    //estructura para manejar la señal.

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;    //con esto no se quedo en select.

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error al configurar el manejador de señales");
        exit(1);
    }


    maxfd = STDIN_FILENO + 1;  //select pide que se le de el maximo fd+1, por lo tanto en caso de usar el fd del socket hay que hacer new_fd+1.

    while (!flag) {
        // Configurar el conjunto de descriptores de archivo para select.
        FD_ZERO(&readfds); //borrar la lista de fds.
        FD_SET(STDIN_FILENO, &readfds); //ingresar la lista de fd al set.

        // Configurar el temporizador para la salida de select cada 5 segundos.
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        // Esperar hasta que se oprima una tecla o el temporizador expire.
        resultado = select(maxfd, &readfds, NULL, NULL, &timeout); //escucho si se modifica algun fd de la lista o si se termian el timer.
        if (resultado == -1) {
            perror("Error en select");
            break;
        } else if (resultado == 0) {
            // El temporizador expiró, imprimir mensaje y regresar a select.
            printf("Han pasado 5 segundos.\n");
            continue;
        }

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            // Se oprimió una tecla, leerla y procesarla.
            char c;
            read(STDIN_FILENO, &c, 1);
            printf("Se oprimió la tecla: %c\n", c);
        }
    }

    printf("Se recibió la señal SIGUSR1, terminando el programa.\n");

    return 0;
}

