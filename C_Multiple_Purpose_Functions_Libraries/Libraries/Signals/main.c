/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para manejo de señales POSIX.
 *          [ENG] Usage example program for POSIX signal handling.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Demuestra dos patrones de señales:
 *       1. signal() + alarm() + SIGALRM — temporizador simple
 *       2. Referencia a sigaction() + select() (ver signal_handling.c)
 *
 * [ENG] Demonstrates two signal patterns:
 *       1. signal() + alarm() + SIGALRM — simple timer
 *       2. Reference to sigaction() + select() (see signal_handling.c)
 *
 * [ESP] NOTA: Este programa solo compila en Linux/POSIX.
 * [ENG] NOTE: This program only compiles on Linux/POSIX.
 */

#include "signals.h"
#include <unistd.h>

/* [ESP] Variable global volátil modificada por el handler.
         'volatile sig_atomic_t' garantiza escritura atómica segura.
   [ENG] Volatile global variable modified by the handler.
         'volatile sig_atomic_t' guarantees safe atomic writes. */
volatile sig_atomic_t alarm_triggered = 0;

/**
 * @brief [ESP] Handler de SIGALRM — cambia la bandera cuando el timer expira.
 *        [ENG] SIGALRM handler — changes the flag when the timer expires.
 */
void signal_handler(int signum)
{
    printf("\n[ESP] Senal recibida: %d (SIGALRM)\n", signum);
    printf("[ENG] Signal received: %d (SIGALRM)\n", signum);
    alarm_triggered = 1;
}

int main(void)
{
    int counter = 0;

    printf("=== [ESP] Ejemplo: signal() + alarm() ===\n");
    printf("=== [ENG] Example: signal() + alarm() ===\n\n");

    /* [ESP] Paso 1: Asociar SIGALRM con nuestro handler.
             Cuando se dispare la alarma, se ejecutará signal_handler().
       [ENG] Step 1: Associate SIGALRM with our handler.
             When the alarm fires, signal_handler() will execute. */
    signal(SIGALRM, signal_handler);

    /* [ESP] Paso 2: Programar la alarma para que se dispare en 3 segundos.
             alarm() le dice al SO que envíe SIGALRM después de N segundos.
       [ENG] Step 2: Schedule the alarm to fire in 3 seconds.
             alarm() tells the OS to send SIGALRM after N seconds. */
    printf("[ESP] Alarma programada: 3 segundos.\n");
    printf("[ENG] Alarm set: 3 seconds.\n\n");
    alarm(3);

    /* [ESP] Paso 3: Loop principal que corre hasta que el handler cambie
             la bandera. Esto simula un servidor o proceso que trabaja
             hasta que llega una señal de timeout.
       [ENG] Step 3: Main loop that runs until the handler changes the
             flag. This simulates a server or process working until a
             timeout signal arrives. */
    printf("[ESP] Trabajando en el loop principal...\n");
    printf("[ENG] Working in main loop...\n");

    while (!alarm_triggered)
    {
        printf("  [ESP] Iteracion %d...\n", counter);
        printf("  [ENG] Iteration %d...\n", counter);
        counter++;
        sleep(1);  /* [ESP] Esperar 1 segundo / [ENG] Wait 1 second */
    }

    /* [ESP] Paso 4: Después de la señal — limpieza y salida.
       [ENG] Step 4: After the signal — cleanup and exit. */
    printf("\n[ESP] Loop terminado despues de %d iteraciones.\n", counter);
    printf("[ENG] Loop ended after %d iterations.\n", counter);
    printf("[ESP] Aqui iria la liberacion de recursos (close, free, etc).\n");
    printf("[ENG] Resource cleanup would go here (close, free, etc).\n");

    return 0;
}
