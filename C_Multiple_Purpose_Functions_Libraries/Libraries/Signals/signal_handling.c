/**
 * @file    signal_handling.c
 * @brief   [ESP] Algoritmos de referencia para manejo de señales POSIX.
 *          [ENG] Reference algorithms for POSIX signal handling.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Contiene dos patrones de referencia:
 *       1. Simple: signal() + alarm() para salir por temporizador
 *       2. Complejo: sigaction() + select() para salir por teclado o señal
 *
 * [ENG] Contains two reference patterns:
 *       1. Simple: signal() + alarm() to exit by timer
 *       2. Complex: sigaction() + select() to exit by keyboard or signal
 */

/* ===========================================================================
 * [ESP] PATRÓN 1 — SIMPLE: SALIR POR TEMPORIZADOR CON SIGALRM
 * [ENG] PATTERN 1 — SIMPLE: EXIT BY TIMER WITH SIGALRM
 *
 * [ESP] La función signal() asocia una señal con un handler.
 *       La función alarm() le dice al SO que genere SIGALRM después
 *       de N segundos. El handler cambia una variable global volátil
 *       para que el loop principal termine.
 *
 * [ENG] The signal() function associates a signal with a handler.
 *       The alarm() function tells the OS to generate SIGALRM after
 *       N seconds. The handler changes a volatile global variable
 *       so the main loop exits.
 * =========================================================================== */

#define TEMPORIZADOR 30     /* [ESP] Segundos / [ENG] Seconds */
#define TRUE  1
#define FALSE 0

/* [ESP] Variable global volátil: solo se modifica en el handler.
         'volatile' impide que el compilador la optimice.
         'sig_atomic_t' garantiza escritura atómica.
   [ENG] Volatile global variable: only modified in the handler.
         'volatile' prevents compiler optimization.
         'sig_atomic_t' guarantees atomic write. */
volatile sig_atomic_t flag = TRUE;

/* [ESP] Función handler — se ejecuta cuando llega la señal
   [ENG] Handler function — executes when the signal arrives */
void misenal(int a)
{
    printf("a = %d\n", a);
    flag = FALSE;
    /* alarm(5); */  /* [ESP] Descomentar para repetir / [ENG] Uncomment to repeat */
}

/* [ESP] Código a incluir en main():
   [ENG] Code to include in main():

    signal(SIGALRM, misenal);       // [ESP] Asociar SIGALRM con handler
    alarm(TEMPORIZADOR);            // [ENG] Start timer

    while (flag == TRUE)
    {
        // [ESP] Código principal del loop
        // [ENG] Main loop code
        if (flag == FALSE)
        {
            // [ESP] Código de limpieza (cerrar conexiones, etc.)
            // [ENG] Cleanup code (close connections, etc.)
        }
    }
    // [ESP] Liberar memoria y recursos
    // [ENG] Free memory and resources
*/

/* ===========================================================================
 * [ESP] PATRÓN 2 — COMPLEJO: SALIR POR TECLADO O SEÑAL CON select()
 * [ENG] PATTERN 2 — COMPLEX: EXIT BY KEYBOARD OR SIGNAL WITH select()
 *
 * [ESP] Usa sigaction() (más robusto que signal()) + select() para
 *       monitorear simultáneamente el teclado y un temporizador.
 *       select() bloquea hasta que hay actividad en stdin o el timer expira.
 *
 * [ENG] Uses sigaction() (more robust than signal()) + select() to
 *       simultaneously monitor the keyboard and a timer.
 *       select() blocks until there is activity on stdin or the timer expires.
 * =========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

volatile sig_atomic_t flag2 = 0;

void signal_handler(int signum)
{
    flag2 = 1;
}

int main(void)
{
    int resultado, maxfd;

    /* [ESP] fd_set: conjunto de descriptores de archivo para select()
       [ENG] fd_set: file descriptor set for select() */
    fd_set readfds;

    /* [ESP] Configurar temporizador para select()
       [ENG] Configure timer for select() */
    struct timeval timeout;

    /* [ESP] Configurar el handler con sigaction() (más seguro que signal())
       [ENG] Configure the handler with sigaction() (safer than signal()) */
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("[ESP] Error configurando handler / [ENG] Error configuring handler");
        exit(1);
    }

    /* [ESP] maxfd: select() requiere el fd más alto + 1
       [ENG] maxfd: select() requires the highest fd + 1 */
    maxfd = STDIN_FILENO + 1;

    while (!flag2)
    {
        /* [ESP] Reiniciar el conjunto de descriptores en cada iteración
           [ENG] Reset the file descriptor set on each iteration */
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);

        /* [ESP] Temporizador: 5 segundos
           [ENG] Timer: 5 seconds */
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        /* [ESP] select() bloquea hasta:
                 - Hay datos en algún fd del set, O
                 - El temporizador expira, O
                 - Llega una señal
           [ENG] select() blocks until:
                 - There is data on an fd in the set, OR
                 - The timer expires, OR
                 - A signal arrives */
        resultado = select(maxfd, &readfds, NULL, NULL, &timeout);

        if (resultado == -1)
        {
            perror("[ESP] Error en select / [ENG] Error in select");
            break;
        }
        else if (resultado == 0)
        {
            /* [ESP] Temporizador expiró sin actividad
               [ENG] Timer expired without activity */
            printf("[ESP] Han pasado 5 segundos.\n");
            printf("[ENG] 5 seconds have passed.\n");
            continue;
        }

        /* [ESP] Verificar si hay datos disponibles en stdin
           [ENG] Check if data is available on stdin */
        if (FD_ISSET(STDIN_FILENO, &readfds))
        {
            char c;
            read(STDIN_FILENO, &c, 1);
            printf("[ESP] Tecla presionada: %c\n", c);
            printf("[ENG] Key pressed: %c\n", c);
        }
    }

    printf("[ESP] Se recibio SIGUSR1, terminando programa.\n");
    printf("[ENG] Received SIGUSR1, exiting program.\n");

    return 0;
}
