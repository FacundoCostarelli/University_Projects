/*
 * Timer.cpp
 *
 *  Created on: 11 jun. 2023
 *      Author: chor
 */

#include "Timer.h"

/*
 * @brief constructor de la clase Timer
 * 		  Inicializa variables a usar
 * @param _tiempo tiempo en ms a ejecutar la funcion _handler
 * @param _handler funcion a ejecutar luego de _tiempo indicado
 * @param _recargar indica si hay que recargar el timer luego de ejecutar la funcion handler o no
 * */
Timer::Timer ( uint32_t _tiempo , void (*_Handler) (void), bool _recargar)
{
	//Configuro el nuevo timer:
	recarga = _tiempo;
	Handler = _Handler;
	recargar = _recargar;

	//NO lo agrego a la lista de timers (porque lo hace PerifericoTemporizado):
}

Timer::~Timer()
{
	//No hace nada (porque lo hace PerifericoTemporizado)
}

/*
 * @brief inicia el timer
 * */
void Timer::start ()
{
	if ( recarga != 0 && Handler != nullptr )
		tiempo = recarga;
}

/*
 * @brief frena el timer
 * */
void Timer::stop ()
{
	tiempo = 0;
}

/*
 * @brief funcion que se ejecuta en el systick para el calculo del tiempo transcurrido
 * */
void Timer::callback ( void )
{
	if ( tiempo != 0)
	{
		tiempo--;
		if ( !tiempo )
		{
			Handler();
			if (recargar)
				tiempo = recarga;
		}
	}
}
