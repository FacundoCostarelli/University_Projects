/**
 * @file    signals.h
 * @brief   [ESP] Biblioteca de referencia para manejo de señales POSIX.
 *          [ENG] Reference library for POSIX signal handling.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Proporciona patrones de referencia para:
 *       - Manejo simple con signal() + alarm() (SIGALRM)
 *       - Manejo complejo con sigaction() + select() (SIGUSR1)
 *       Estos archivos son código de referencia para Linux/POSIX.
 *
 * [ENG] Provides reference patterns for:
 *       - Simple handling with signal() + alarm() (SIGALRM)
 *       - Complex handling with sigaction() + select() (SIGUSR1)
 *       These files are reference code for Linux/POSIX.
 */

#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>

/**
 * @brief [ESP] Handler de señal genérico que cambia una bandera.
 *        [ENG] Generic signal handler that changes a flag.
 *
 * @param[in] signum  [ESP] Número de señal recibida.
 *                    [ENG] Received signal number.
 * @return void
 */
void signal_handler(int signum);

#endif /* SIGNALS_H */
