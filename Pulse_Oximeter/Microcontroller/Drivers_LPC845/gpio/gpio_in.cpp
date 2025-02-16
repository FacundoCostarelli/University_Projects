/*
 * gpio_in.cpp
 *
 *  Created on: 20 may. 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

#include "gpio_in.h"




/* ESP
 * @brief Matriz de índices IOCON para los pines de los puertos GPIO0 y GPIO1.
 *        Esta matriz permite mapear los pines físicos a sus respectivos registros IOCON.
 */

/* ENG
 * @brief IOCON index matrix for GPIO0 and GPIO1 pins.
 *        This matrix maps physical pins to their respective IOCON registers.
 */

const uint8_t gpio_in::iocon_index[2][32] = {{17,11,6,5,4,3,16,15,14,13,8,7,2,1,18,10,9,0,30,29,28,27,26,25,24,23,22,21,20,50,51,35},{36,37,38,41,42,43,46,49,31,32,55,54,33,34,39,40,44,45,47,48,52,53,0,0,0,0,0,0,0,0,0,0}};




/* ESP
 * @brief Constructor de la clase gpio_in.
 *        Inicializa una instancia de la clase gpio_in con el puerto, pin y modo especificados.
 *
 * @param _port Puerto GPIO (0 o 1).
 * @param _pin  Pin GPIO (0 a 31).
 * @param modo  Modo de configuración del pin.
 */

/* ENG
 * @brief Constructor of the gpio_in class.
 *        Initializes an instance of the gpio_in class with the specified port, pin, and mode.
 *
 * @param _port GPIO port (0 or 1).
 * @param _pin  GPIO pin (0 to 31).
 * @param mode  Pin configuration mode.
 */

gpio_in::gpio_in( uint8_t _port , uint8_t _pin , uint8_t modo )
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
		// ENG: Enables the CLK for GPIO1
		SYSCON->SYSAHBCLKCTRL0 |= 1 << SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT;

	// ESP: Configura la dirección del pin como entrada.
	// ENG: Configures the pin direction as input.
	setDir();

	// ESP: Configura el modo del pin.
	// ENG: Configures the pin mode.
	setMODE ( modo );
}




/* ESP
 * @brief Configura la dirección del pin como entrada.
 */

/* ENG
 * @brief Configures the pin direction as input.
 */

void gpio_in::setDir()
{
	if ( !error )
		// ESP: Configura el pin como entrada (limpia el bit correspondiente en el registro DIR).
		// ENG: Configures the pin as input (clears the corresponding bit in the DIR register)
		GPIO->DIR[port] &= ~(1<<pin);
}




/* ESP
 * @brief Configura el modo del pin.
 * @param modo Modo de configuración del pin.
 */

/* ENG
 * @brief Configures the pin mode.
 * @param mode Pin configuration mode.
 */

void gpio_in::setMODE( uint8_t modo )
{
	if ( !error )
	{
		// ESP: Obtiene el índice IOCON correspondiente al puerto y pin.
		// ENG: Gets the IOCON index corresponding to the port and pin.
		uint8_t indice = iocon_index[port][pin];

		// ESP: Limpia los bits 3 y 4 del registro IOCON.
		// ENG: Clears bits 3 and 4 of the IOCON register.
		IOCON->PIO[ indice ] &= ~(3<<3);

		// ESP: Configura el modo del pin en los bits 3 y 4 del registro IOCON.
		// ENG: Configures the pin mode in bits 3 and 4 of the IOCON register.
		IOCON->PIO[ indice ] |= modo << 3;
	}
}




/* ESP
 * @brief Obtiene el valor actual del pin.
 * @return true si el pin está en alto, false si está en bajo.
 */

/* ENG
 * @brief Gets the current value of the pin.
 * @return true if the pin is high, false if it is low.
 */

bool gpio_in::getValor() const
{
	// ESP: Lee el valor del pin y devuelve true si está en alto (1), false si está en bajo (0).
	// ENG: Reads the pin value and returns true if it is high (1), false if it is low (0).
	return (((GPIO->PIN[port]>>pin)&0x01) == 1);
}
