/*
 * Timer.h
 *
 *  Created on: June 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

/* ESP
 * @brief Aquí tenemos los includes y la declaración de la clase `Timer`, que hereda de la clase `PerifericoTemporizado`.
 *        Esta clase maneja un temporizador configurable con la opción de recarga automática y un callback asociado.
 *
 *      **Variables**
 *
 *      tiempo:       Variable de tipo `uint32_t` que guarda el tiempo inicial del temporizador en unidades específicas (e.g., milisegundos).
 *      recarga:      Variable de tipo `uint32_t` que guarda el valor de recarga del temporizador si la opción de recarga automática está activada.
 *      recargar:     Variable booleana que indica si el temporizador debe recargarse automáticamente al finalizar el tiempo configurado.
 *      Handler:      Puntero a una función que se ejecutará como callback cuando el temporizador expire.
 *
 *      **Métodos**
 *
 *      Timer(uint32_t _tiempo, void (*_Handler)(void), bool _recargar = false):
 *                   Constructor de la clase. Inicializa el temporizador con un tiempo especificado, un callback y la opción de recarga automática.
 *
 *      ~Timer():     Destructor de la clase. Libera los recursos utilizados por el objeto.
 *
 *      void start(): Método que inicia el temporizador. Configura el tiempo inicial y habilita su funcionamiento.
 *
 *      void stop():  Método que detiene el temporizador. Deshabilita el temporizador y detiene la ejecución de su callback.
 *
 *      void callback(void):
 *                   Método asociado al evento del temporizador. Se llama automáticamente cuando el temporizador expira y ejecuta el `Handler` configurado.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the includes and the declaration of the `Timer` class, which inherits from the `PerifericoTemporizado` class.
 *        This class manages a configurable timer with an optional auto-reload feature and an associated callback.
 *
 *      **Variables**
 *
 *      tiempo:       `uint32_t` variable that stores the initial timer duration in specific units (e.g., milliseconds).
 *      recarga:      `uint32_t` variable that stores the reload value if the auto-reload feature is enabled.
 *      recargar:     Boolean variable that indicates whether the timer should automatically reload when the set time elapses.
 *      Handler:      Pointer to a function that will be executed as a callback when the timer expires.
 *
 *      **Methods**
 *
 *      Timer(uint32_t _tiempo, void (*_Handler)(void), bool _recargar = false):
 *                   Class constructor. Initializes the timer with a specified duration, a callback, and the auto-reload option.
 *
 *      ~Timer():     Class destructor. Releases the resources used by the object.
 *
 *      void start(): Method that starts the timer. Configures the initial duration and enables its operation.
 *
 *      void stop():  Method that stops the timer. Disables the timer and halts the execution of its callback.
 *
 *      void callback(void):
 *                   Method associated with the timer event. Automatically called when the timer expires and executes the configured `Handler`.
 *
 * @param None
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <LPC845.h>
#include <PerifericoTemporizado.h>

class Timer : public PerifericoTemporizado {

	private:
		uint32_t tiempo, recarga;
		bool recargar;
		void (*Handler) (void);

	public:
		Timer ( uint32_t _tiempo , void (*_Handler) (void) , bool _recargar = false );
		~Timer();
		void start ();
		void stop ();
		void callback ( void );
};

extern Timer **timers;

#endif /* TIMER_H_ */
