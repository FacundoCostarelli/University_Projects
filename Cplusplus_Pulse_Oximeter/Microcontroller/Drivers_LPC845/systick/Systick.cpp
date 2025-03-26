/*
 * Systick.cpp
 *
 *  Created on: July 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

#include <Systick.h>

/* ESP
 * @brief Puntero a función global que almacena la función de callback para el Systick.
 *        Se inicializa como nullptr para indicar que no hay función asignada.
 */

/* ENG
 * @brief Global function pointer that stores the callback function for the Systick.
 *        Initialized as nullptr to indicate no function is assigned.
 */

void (*funcSystick) (void) = nullptr;




/* ESP
 * @brief Interrupción del Systick.
 *        Se ejecuta automáticamente cada vez que se activa el Systick y verifica si hay una función asignada
 *        al puntero global `funcSystick`. Si existe, la ejecuta.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Systick interrupt handler.
 *        Automatically executed whenever the Systick is triggered. It checks if a function is assigned to
 *        the global pointer `funcSystick` and executes it if it exists.
 *
 * @param None
 */

void SysTick_Handler (void)
{
	if ( funcSystick != nullptr )
		// ESP: Llamo a la función de callback asignada al puntero `funcSystick`.
		// ENG: Call the callback function assigned to the `funcSystick` pointer.
		funcSystick();
}




/* ESP
 * @brief Instala la función de callback para el Systick.
 *        Permite asignar una función personalizada que será llamada en cada interrupción del Systick.
 *
 * @param func Puntero a la función que será llamada en cada interrupción del Systick.
 */

/* ENG
 * @brief Installs the callback function for the Systick.
 *        Allows assigning a custom function that will be called on every Systick interrupt.
 *
 * @param func Pointer to the function to be called on each Systick interrupt.
 */

void InstallSystick ( void ( *func ) (void) )
{
	// ESP: Asigno la función recibida al puntero global `funcSystick`.
	// ENG: Assign the received function to the global pointer `funcSystick`.
	funcSystick = func;
}
