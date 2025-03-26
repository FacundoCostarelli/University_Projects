/*
 * Timer.cpp
 *
 *  Created on: June 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

#include "Timer.h"

/* ESP
 * @brief Constructor de la clase Timer.
 *        Inicializa las variables necesarias para la configuración de un nuevo timer.
 *
 * @param _tiempo Tiempo en milisegundos que debe transcurrir antes de ejecutar la función _Handler.
 * @param _Handler Puntero a la función que se ejecutará luego de transcurrir el tiempo indicado.
 * @param _recargar Indica si el timer debe recargarse automáticamente después de ejecutar la función _Handler.
 *
 */

/* ENG
 * @brief Constructor of the Timer class.
 *        Initializes the necessary variables for configuring a new timer.
 *
 * @param _tiempo Time in milliseconds to elapse before executing the _Handler function.
 * @param _Handler Pointer to the function to be executed after the specified time has elapsed.
 * @param _recargar Indicates whether the timer should automatically reload after executing the _Handler function.
 *
 */

Timer::Timer ( uint32_t _tiempo , void (*_Handler) (void), bool _recargar)
{
	// ESP: Configuro los parámetros del nuevo timer.
	// ENG: Configure the new timer parameters.
	recarga = _tiempo;
	Handler = _Handler;
	recargar = _recargar;

	// ESP: El timer no se agrega automáticamente a la lista de timers (esto lo maneja PerifericoTemporizado).
	// ENG: The timer is not automatically added to the timers list (handled by PerifericoTemporizado).
}




/* ESP
 * @brief Destructor de la clase Timer.
 *        No realiza ninguna acción, ya que la gestión de recursos la maneja PerifericoTemporizado.
 */

/* ENG
 * @brief Destructor of the Timer class.
 *        Performs no actions, as resource management is handled by PerifericoTemporizado.
 */

Timer::~Timer()
{
	// ESP: No hace nada (porque lo maneja PerifericoTemporizado).
	// ENG: Does nothing (handled by PerifericoTemporizado).
}




/* ESP
 * @brief Inicia el timer configurado con un tiempo y un manejador válidos.
 *        Solo se inicia si el tiempo es diferente de cero y la función Handler no es nula.
 */

/* ENG
 * @brief Starts the timer configured with a valid time and handler.
 *        It starts only if the time is non-zero and the Handler function is not null.
 */

void Timer::start ()
{
	if ( recarga != 0 && Handler != nullptr )
		 // ESP: Asigno el valor de recarga al tiempo para comenzar el conteo.
		 // ENG: Assign the reload value to the time to start counting.
		tiempo = recarga;
}




/* ESP
 * @brief Detiene el timer estableciendo el tiempo a cero.
 */

/* ENG
 * @brief Stops the timer by setting the time to zero.
 */

void Timer::stop ()
{
	// ESP: Detengo el timer al asignar un valor de cero al tiempo restante.
	// ENG: Stop the timer by setting the remaining time to zero.
	tiempo = 0;
}




/* ESP
 * @brief Función que se ejecuta periódicamente en el Systick para calcular el tiempo transcurrido.
 *        Verifica si el tiempo ha llegado a cero, ejecuta el manejador y reinicia el timer si está configurado para recargarse.
 */

/* ENG
 * @brief Function executed periodically in the Systick to calculate elapsed time.
 *        Checks if the time has reached zero, executes the handler, and reloads the timer if configured to do so.
 */

void Timer::callback ( void )
{
	if ( tiempo != 0)
	{
		// ESP: Decremento el tiempo restante en cada llamada al callback.
		// ENG: Decrement the remaining time on each callback call.
		tiempo--;

		if ( !tiempo )
		{
			// ESP: Ejecuto la función manejadora cuando el tiempo llega a cero.
			// ENG: Execute the handler function when the time reaches zero.
			Handler();

			if (recargar)
				// ESP: Reinicio el timer asignando el valor de recarga.
				// ENG: Reload the timer by assigning the reload value.
				tiempo = recarga;
		}
	}
}
