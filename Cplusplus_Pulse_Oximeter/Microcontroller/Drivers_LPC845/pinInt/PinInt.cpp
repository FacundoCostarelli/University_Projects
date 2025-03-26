/*
 * PinInt.cpp
 *
 *  Created on: June 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

#include "PinInt.h"

/* ESP
 * @brief Array de punteros a funciones que manejan las interrupciones externas asociadas a cada fuente.
 *        Inicialmente, todos los punteros están en nullptr.
 */

/* ENG
 * @brief Array of function pointers handling external interrupts associated with each source.
 *        Initially, all pointers are set to nullptr.
 */

void (*PinInt::handlers[8]) (void) = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};




/* ESP
 * @brief Contador estático que lleva la cuenta de cuántas fuentes de interrupción se han creado.
 */

/* ENG
 * @brief Static counter tracking how many interrupt sources have been created.
 */

uint8_t PinInt::cant_ints = 0;




/* ESP
 * @brief Manejadores de interrupción para cada fuente (0-7).
 *        Limpian el flag correspondiente y llaman a la función asociada si está configurada.
 */

/* ENG
 * @brief Interrupt handlers for each source (0-7).
 *        Clears the corresponding flag and calls the associated function if configured.
 */

void PININT0_IRQHandler (void)
{
	INT_EXT->IST |= 1; // ESP: Limpia el flag de la interrupción. ENG: Clears the interrupt flag.
	if ( PinInt::handlers[0] != nullptr )
		PinInt::handlers[0](); // ESP: Llama al manejador si está configurado. ENG: Calls the handler if configured.
}

void PININT1_IRQHandler ( void )
{
	INT_EXT->IST |= 2;
	if ( PinInt::handlers[1] != nullptr )
		PinInt::handlers[1]();

}

void PININT2_IRQHandler ( void )
{
	INT_EXT->IST |= 4;
	if ( PinInt::handlers[2] != nullptr )
		PinInt::handlers[2]();

}

void PININT3_IRQHandler ( void )
{
	INT_EXT->IST |= 8;
	if ( PinInt::handlers[3] != nullptr )
		PinInt::handlers[3]();

}

void PININT4_IRQHandler ( void )
{
	INT_EXT->IST |= 0x10;
	if ( PinInt::handlers[4] != nullptr )
		PinInt::handlers[4]();

}

void PININT5_IRQHandler ( void )
{
	INT_EXT->IST |= 0x20;
	if ( PinInt::handlers[5] != nullptr )
		PinInt::handlers[5]();

}

void PININT6_IRQHandler ( void )
{
	INT_EXT->IST |= 0x40;
	if ( PinInt::handlers[6] != nullptr )
		PinInt::handlers[6]();

}

void PININT7_IRQHandler ( void )
{
	INT_EXT->IST |= 0x80;
	if ( PinInt::handlers[7] != nullptr )
		PinInt::handlers[7]();

}




/* ESP
 * @brief Constructor de la clase PinInt.
 *        Configura la interrupción asociada a un pin y un puerto específicos, asignando un manejador.
 *        Configura las opciones de flanco y nivel de la interrupción.
 *
 * @param port Puerto asociado al pin.
 * @param pin Pin que genera la interrupción.
 * @param handler Función manejadora de la interrupción.
 * @param asc_on Habilita la interrupción por flanco ascendente.
 * @param desc_on Habilita la interrupción por flanco descendente.
 * @param alto_on Habilita la interrupción por nivel alto.
 * @param bajo_on Habilita la interrupción por nivel bajo.
 */

/* ENG
 * @brief Constructor for the PinInt class.
 *        Configures the interrupt associated with a specific pin and port, assigning a handler.
 *        Sets up edge and level options for the interrupt.
 *
 * @param port Port associated with the pin.
 * @param pin Pin generating the interrupt.
 * @param handler Function handling the interrupt.
 * @param asc_on Enables interrupt on rising edge.
 * @param desc_on Enables interrupt on falling edge.
 * @param alto_on Enables interrupt on high level.
 * @param bajo_on Enables interrupt on low level.
 */

PinInt::PinInt( uint8_t port , uint8_t pin , void (*handler) (void) , uint8_t asc_on , uint8_t desc_on , uint8_t alto_on , uint8_t bajo_on )
{
	if ( cant_ints > 7 )
		cant_ints = 0; // ESP: Limita las interrupciones a un máximo de 8. ENG: Limits interrupts to a maximum of 8.

	fuente = cant_ints; // ESP: Asigna una fuente de interrupción. ENG: Assigns an interrupt source.
	cant_ints++;

	// ESP: Pongo la función de interrupción en el vector de punteros a funciones de interrupción.
	// La posición es dada por la "fuente" de interrupción que va del 0 al 7. La "fuente" es el indice.
	// ENG: I put the interrupt function in the vector of pointers to interrupt functions.
	// The position is given by the interrupt "source" which goes from 0 to 7. The "source" is the index.
	handlers[fuente] = handler;

	// ESP: Habilita el reloj para las interrupciones externas a partir del clock del periferico PIN INTERRUPT.
	// ENG: Enables the clock for external interrupts based on the PIN INTERRUPT peripheral clock
	SYSCON->SYSAHBCLKCTRL0 |= 1 << 28;



	// ESP: Configura el pin asociado a la fuente. La fuente de interrupcion indicada por int_src. Tengo que poner el nro de pin
	// que generará la interrupción:
	// P0.0 a P0.31 se los indica con los números 0 a 31
	// P1.0 a P1.31 se los indica con los números 32 a 63

	// ENG: Configures the pin associated with the source. The interrupt source indicated by int_src. I have to set the pin number
	// that will generate the interruption:
	// P0.0 to P0.31 are indicated by the numbers 0 to 31
	// P1.0 to P1.31 are indicated by the numbers 32 to 63
	SYSCON->PINTSEL[ fuente ] = port*32 + pin;


	// ESP: Deshabilita las interrupciones y configura los flancos y niveles según lo que eligió el usuario.
	// ENG: Disables interrupts and configures edges and levels according to the users choice.
	set_flanco(asc_on,desc_on);
	set_nivel(alto_on,bajo_on);

}




/* ESP
 * @brief Destructor de la clase PinInt.
 *        Deshabilita la interrupción asociada y elimina el manejador.
 */

/* ENG
 * @brief Destructor for the PinInt class.
 *        Disables the associated interrupt and removes the handler.
 */

PinInt::~PinInt()
{
	ICER0 |= (0x01 << (24 + fuente)); 	// ESP: Deshabilita la interrupción en el NVIC. ENG: Disables the interrupt in the NVIC.
	set_flanco(0,0);					// ESP: Deshabilita los flancos. ENG: Disables edges.
	set_nivel(0,0);						// ESP: Deshabilita los niveles. ENG: Disables levels.
	handlers[fuente] = nullptr; 		// ESP: Elimina el manejador asociado. ENG: Removes the associated handler.
}




/* ESP
 * @brief Configura las interrupciones por flanco ascendente y descendente.
 *
 * @param asc_on Habilita flanco ascendente.
 * @param desc_on Habilita flanco descendente.
 */

/* ENG
 * @brief Configures interrupts for rising and falling edges.
 *
 * @param asc_on Enables rising edge.
 * @param desc_on Enables falling edge.
 */

void PinInt::set_flanco (uint8_t asc_on , uint8_t desc_on )
{
	if ( asc_on || desc_on )
		INT_EXT->ISEL &= ~(1<<fuente); 	// ESP: Selecciona modo de flanco. ENG: Selects edge mode.

	if ( asc_on )
		INT_EXT->IENR |= 1<<fuente; 	// ESP: Habilita flanco ascendente en registro IENR. ENG: Enables rising edge using IENR register.

	if ( desc_on )
		INT_EXT->IENF |= 1<<fuente; 	// ESP: Habilita flanco descendente en registro IENF. ENG: Enables falling edge using IENF register.

	INT_EXT->IST |= 1<<fuente; 			// ESP: Limpia el flag de estado. ENG: Clears the status flag.

	if ( asc_on || desc_on)
		ISER0 |= (1 << (24 + fuente)); 	// ESP: Habilita la interrupción en el NVIC. ENG: Enables the interrupt in the NVIC.
}




/* ESP
 * @brief Configura las interrupciones por nivel alto y bajo.
 *
 * @param alto_on Habilita nivel alto.
 * @param bajo_on Habilita nivel bajo.
 */

/* ENG
 * @brief Configures interrupts for high and low levels.
 *
 * @param alto_on Enables high level.
 * @param bajo_on Enables low level.
 */

void PinInt::set_nivel ( uint8_t alto_on , uint8_t bajo_on )
{
	if ( alto_on || bajo_on)
		INT_EXT->ISEL |= 1<<fuente; // ESP: Selecciona modo de nivel en registro ISEL. ENG: Selects level mode in ISEL register.

	// ESP: Si se habilita la interrupcion por nivel alto.
	// ENG: If it is enabled the interruption by high level.
	if ( alto_on )
	{
		INT_EXT->IENR &= ~(1<<fuente); 	// ESP: Deshabilita flanco ascendente. ENG: Disables rising edge.
		INT_EXT->IENF |= 1<<fuente;		// ESP: Habilita nivel alto. ENG: Enables high level.
	}

	//ENG: If it is enabled the interruption by low level.
	//ESP: Si se habilita la interrupcion por nivel bajo.
	if ( bajo_on)
	{
		INT_EXT->IENR &= ~(1<<fuente);	// ESP: Deshabilita flanco ascendente. ENG: Disables rising edge.
		INT_EXT->IENF &= ~(1<<fuente);	// ESP: Habilita nivel bajo. ENG: Enables low level.
	}

	INT_EXT->IST |= 1<<fuente; // ESP: Limpia el flag de estado. ENG: Clears the status flag.

	if ( alto_on || bajo_on)
		ISER0 |= (0x01 << (24 + fuente)); // ESP: Habilita la interrupción en el NVIC. ENG: Enables the interrupt in the NVIC.
}
