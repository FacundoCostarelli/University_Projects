/*
 * gpio_out.cpp
 *
 *  Created on: 20 may. 2024
 *      Author: Jorge Escola
 */

#include "gpio_out.h"

/* ESP
 * @brief Matriz de índices IOCON para los pines de los puertos GPIO0 y GPIO1.
 *        Esta matriz permite mapear los pines físicos a sus respectivos registros IOCON.
 */

/* ENG
 * @brief IOCON index matrix for GPIO0 and GPIO1 pins.
 *        This matrix maps physical pins to their respective IOCON registers.
 */
const uint8_t gpio_out::iocon_index[2][32] = {{17,11,6,5,4,3,16,15,14,13,8,7,2,1,18,10,9,0,30,29,28,27,26,25,24,23,22,21,20,50,51,35},{36,37,38,41,42,43,46,49,31,32,55,54,33,34,39,40,44,45,47,48,52,53,0,0,0,0,0,0,0,0,0,0}};




/* ESP
 * @brief Constructor de la clase gpio_out.
 *        Inicializa una instancia de la clase gpio_out con el puerto, pin y modo especificados.
 *
 * @param _port Puerto GPIO (0 o 1).
 * @param _pin  Pin GPIO (0 a 31).
 * @param modo  Modo de configuración del pin.
 */

/* ENG
 * @brief Constructor of the gpio_out class.
 *        Initializes an instance of the gpio_out class with the specified port, pin, and mode.
 *
 * @param _port GPIO port (0 or 1).
 * @param _pin  GPIO pin (0 to 31).
 * @param mode  Pin configuration mode.
 */

gpio_out::gpio_out( uint8_t _port , uint8_t _pin , uint8_t modo )
{
	// ESP: Asigna el puerto y pin proporcionados a las variables miembro.
	// ENG: Assigns the provided port and pin to the member variables.
	port = _port;
	pin = _pin;

	// ESP: Inicializa la bandera de error como falsa.
	// ENG: Initializes the error flag as false.
	error = false;

	// ESP: Verifica si el puerto o pin están fuera de rango.
	// ENG: Checks if the port or pin are out of range.
	if ( port > 1 || pin > 31 )
		error = true;

	// ESP: Habilita el reloj para el puerto GPIO correspondiente.
	// ENG: Enables the clock for the corresponding GPIO port.
	if ( port == 0)
		// ESP: Habilita el CLK para el GPIO0.
		// ENG: Enables the CLK for GPIO0.
		SYSCON->SYSAHBCLKCTRL0 |= 1 << SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT;
	if ( port == 1)
		// ESP: Habilita el CLK para el GPIO1.
        // ENG: Enables the CLK for GPIO1.
		SYSCON->SYSAHBCLKCTRL0 |= 1 << SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT;

	// ESP: Configura la dirección del pin como salida.
	// ENG: Configures the pin direction as output.
	setDir();

    // ESP: Configura el modo del pin.
    // ENG: Configures the pin mode.
	setMODE ( modo );

}




/* ESP
 * @brief Configura la dirección del pin como salida.
 */

/* ENG
 * @brief Configures the pin direction as output.
 */

void gpio_out::setDir()
{
	// ESP: Pone en 1 el bit correspondiente en el registro DIR para indicar que es una salida.
	// ENG: Sets the corresponding bit in the DIR register to 1 to indicate it is an output
	GPIO->DIR[port] |= 1<<pin;
}




/* ESP
 * @brief Configura el modo del pin.
 * @param modo Modo de configuración del pin.
 */

/* ENG
 * @brief Configures the pin mode.
 * @param mode Pin configuration mode.
 */

void gpio_out::setMODE( uint8_t modo )
{
	if ( !error )
	{
		// ESP: No es necesario borrar previamente porque solo se modifica un bit.
		// ENG: No need to clear beforehand because only one bit is modified.
		if (modo)
			// ESP: Configura el bit 10 del registro IOCON para el modo especificado.
			// ENG: Sets bit 10 of the IOCON register for the specified mode
			IOCON->PIO[iocon_index[port][pin]] |= 1<<10;
		else
			// ESP: Limpia el bit 10 del registro IOCON.
			// ENG: Clears bit 10 of the IOCON register.
			IOCON->PIO[iocon_index[port][pin]] &= ~(1<<10);
	}
}




/* ESP
 * @brief Establece el valor del pin (alto o bajo).
 * @param val Valor a establecer (true para alto, false para bajo).
 */

/* ENG
 * @brief Sets the pin value (high or low).
 * @param val Value to set (true for high, false for low).
 */

void gpio_out::setValor( bool val )
{
	if ( !error )
	{
		if ( !val )
			// ESP: Pone el pin en bajo (limpia el bit correspondiente en el registro PIN).
			// ENG: Sets the pin low (clears the corresponding bit in the PIN register)
			GPIO->PIN[port] &= ~(1<<pin);
		else
			// ESP: Pone el pin en alto (establece el bit correspondiente en el registro PIN).
			// ENG: Sets the pin high (sets the corresponding bit in the PIN register).
			GPIO->PIN[port] |= (1<<pin);
	}

}




/* ESP
 * @brief Cambia el valor del pin (toggle).
 */

/* ENG
 * @brief Toggles the pin value.
 */

void gpio_out::toggleValor(void)
{
	if ( !error )
		// ESP: Cambia el estado del pin usando una operación XOR.
		// ENG: Toggles the pin state using an XOR operation.
		GPIO->PIN[port] ^= (1<<pin);
}
