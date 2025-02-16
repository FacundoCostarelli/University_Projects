/*
 * PinInt.h
 *
 *  Created on: June 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */


/* PININT
 * @brief Aquí tenemos los includes y la declaración de la clase `PinInt`, que implementa interrupciones configurables en los pines del microcontrolador LPC845.
 *        La clase permite configurar interrupciones basadas en flancos o niveles para eventos específicos.
 *
 *      **Variables**
 *
 *      fuente:      Variable privada de tipo `uint8_t` que almacena la fuente del pin asociado a la interrupción.
 *
 *      **Variables Estáticas**
 *
 *      cant_ints:   Variable estática que mantiene un conteo de las interrupciones creadas.
 *      handlers[8]: Array estático de punteros a funciones, que almacena los callbacks asociados a cada interrupción.
 *
 *      **Constantes**
 *
 *      MODE_FLANCO: Constante de tipo `uint8_t` que define el modo de interrupción por flanco.
 *      MODE_NIVEL:  Constante de tipo `uint8_t` que define el modo de interrupción por nivel.
 *
 *      **Métodos Públicos**
 *
 *      PinInt(uint8_t port, uint8_t pin, void (*handler)(void), uint8_t asc_on = 0, uint8_t desc_on = 0, uint8_t alto_on = 0, uint8_t bajo_on = 0):
 *                   Constructor de la clase. Configura una interrupción en un pin específico con opciones para flancos ascendentes, descendentes,
 *                   nivel alto o nivel bajo.
 *
 *      ~PinInt():
 *                   Destructor de la clase. Libera los recursos asociados a la interrupción configurada.
 *
 *      void set_flanco(uint8_t asc_on, uint8_t desc_on):
 *                   Método para configurar interrupciones basadas en flancos ascendentes o descendentes.
 *
 *      void set_nivel(uint8_t alto_on, uint8_t bajo_on):
 *                   Método para configurar interrupciones basadas en niveles altos o bajos.
 *
 *      **Funciones de Interrupción Externas**
 *
 *      PININT0_IRQHandler(void) ... PININT7_IRQHandler(void):
 *                   Declaraciones de funciones manejadoras de interrupciones para los pines `PININT0` a `PININT7`.
 *                   Estas funciones están protegidas con un bloque `extern "C"` para garantizar compatibilidad con código en C.
 *
 * @param Ninguno
 */

/* PININT
 * @brief Here we have the includes and the declaration of the `PinInt` class, which implements configurable interrupts on the LPC845 microcontroller pins.
 *        The class allows configuration of interrupts based on edges or levels for specific events.
 *
 *      **Variables**
 *
 *      fuente:      Private `uint8_t` variable that stores the source pin associated with the interrupt.
 *
 *      **Static Variables**
 *
 *      cant_ints:   Static variable that keeps a count of the created interrupts.
 *      handlers[8]: Static array of function pointers, storing the callbacks associated with each interrupt.
 *
 *      **Constants**
 *
 *      MODE_FLANCO: `uint8_t` constant that defines the edge-triggered interrupt mode.
 *      MODE_NIVEL:  `uint8_t` constant that defines the level-triggered interrupt mode.
 *
 *      **Public Methods**
 *
 *      PinInt(uint8_t port, uint8_t pin, void (*handler)(void), uint8_t asc_on = 0, uint8_t desc_on = 0, uint8_t alto_on = 0, uint8_t bajo_on = 0):
 *                   Class constructor. Configures an interrupt on a specific pin with options for rising edges, falling edges,
 *                   high level, or low level.
 *
 *      ~PinInt():
 *                   Class destructor. Releases resources associated with the configured interrupt.
 *
 *      void set_flanco(uint8_t asc_on, uint8_t desc_on):
 *                   Method to configure interrupts based on rising or falling edges.
 *
 *      void set_nivel(uint8_t alto_on, uint8_t bajo_on):
 *                   Method to configure interrupts based on high or low levels.
 *
 *      **External Interrupt Functions**
 *
 *      PININT0_IRQHandler(void) ... PININT7_IRQHandler(void):
 *                   Declarations of interrupt handler functions for pins `PININT0` to `PININT7`.
 *                   These functions are wrapped in an `extern "C"` block to ensure compatibility with C code.
 *
 * @param None
 */

#ifndef PININT_H_
#define PININT_H_

#if defined (__cplusplus)
extern "C" {

void PININT0_IRQHandler (void);
void PININT1_IRQHandler (void);
void PININT2_IRQHandler (void);
void PININT3_IRQHandler (void);
void PININT4_IRQHandler (void);
void PININT5_IRQHandler (void);
void PININT6_IRQHandler (void);
void PININT7_IRQHandler (void);
}
#endif

#include "LPC845.h"

class PinInt
{
	private:
		uint8_t fuente;

	public:
		static uint8_t cant_ints;
		static void (*handlers[8]) (void);

		static const uint8_t MODE_FLANCO = 0;
		static const uint8_t MODE_NIVEL = 1;

		PinInt( uint8_t port , uint8_t pin , void (*handler) (void) , uint8_t asc_on = 0 , uint8_t desc_on = 0 , uint8_t alto_on = 0, uint8_t bajo_on = 0);
		~PinInt();

		void set_flanco(uint8_t asc_on , uint8_t desc_on);
		void set_nivel(uint8_t alto_on , uint8_t bajo_on);

};


#endif /* PININT_H_ */
