/*
 * Systick.h
 *
 *  Created on: July 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

/* ESP
 * @brief Aquí tenemos los includes y la declaración de las funciones relacionadas con el controlador SysTick, el cual permite implementar temporizadores
 *        basados en interrupciones periódicas.
 *
 *      **Variables**
 *
 *      funcSystick:  Puntero a función que se ejecutará como callback cuando ocurra la interrupción del SysTick.
 *
 *      **Funciones**
 *
 *      void InstallSystick(void (*)(void)):
 *                   Función que asocia un callback a la interrupción del SysTick. Permite definir la lógica que se ejecutará de manera periódica.
 *
 *      void SysTick_Handler(void):
 *                   Función manejadora de la interrupción del SysTick. Es llamada automáticamente cuando ocurre la interrupción y ejecuta el callback configurado.
 *                   Nota: Está protegida con un bloque `extern "C"` para asegurar compatibilidad con código en C si se utiliza desde un entorno en C++.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the includes and the declaration of functions related to the SysTick controller, which allows the implementation of timers
 *        based on periodic interrupts.
 *
 *      **Variables**
 *
 *      funcSystick:  Pointer to a function that will be executed as a callback when the SysTick interrupt occurs.
 *
 *      **Functions**
 *
 *      void InstallSystick(void (*)(void)):
 *                   Function that associates a callback with the SysTick interrupt. It defines the logic that will be executed periodically.
 *
 *      void SysTick_Handler(void):
 *                   SysTick interrupt handler function. Automatically called when the interrupt occurs and executes the configured callback.
 *                   Note: It is wrapped in an `extern "C"` block to ensure compatibility with C code if used in a C++ environment.
 *
 * @param None
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <LPC845.h>

extern void (*funcSystick) (void);

void InstallSystick ( void (*) (void) );

#if defined (__cplusplus)
extern "C" {

void SysTick_Handler (void);
}
#endif

#endif /* SYSTICK_H_ */
