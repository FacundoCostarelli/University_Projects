/*
 * gpio_out.cpp
 *
 *  Created on: 20 may. 2024
 *      Author: chor
 */

#include "gpio_out.h"

const uint8_t gpio_out::iocon_index[2][32] = {{17,11,6,5,4,3,16,15,14,13,8,7,2,1,18,10,9,0,30,29,28,27,26,25,24,23,22,21,20,50,51,35},{36,37,38,41,42,43,46,49,31,32,55,54,33,34,39,40,44,45,47,48,52,53,0,0,0,0,0,0,0,0,0,0}};

gpio_out::gpio_out( uint8_t _port , uint8_t _pin , uint8_t modo )
{
	port = _port;
	pin = _pin;
	error = false;

	if ( port > 1 || pin > 31 )
		error = true;

	if ( port == 0)
		//Habilito el CLK para el GPIO0:
		SYSCON->SYSAHBCLKCTRL0 |= 1 << SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT;
	if ( port == 1)
		//Habilito el CLK para el GPIO0:
		SYSCON->SYSAHBCLKCTRL0 |= 1 << SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT;

	setDir();
	setMODE ( modo );

}

void gpio_out::setDir()
{
	//Pongo en 1 el bit del registro para indicar que es una salida:
	GPIO->DIR[port] |= 1<<pin;
}

void gpio_out::setMODE( uint8_t modo )
{
	if ( !error )
	{
		//No hace falta borrar previamente porque es un solo bit:
		if (modo)
			IOCON->PIO[iocon_index[port][pin]] |= 1<<10;
		else
			IOCON->PIO[iocon_index[port][pin]] &= ~(1<<10);
	}
}

void gpio_out::setValor( bool val )
{
	if ( !error )
	{
		if ( !val )
			GPIO->PIN[port] &= ~(1<<pin);
		else
			GPIO->PIN[port] |= (1<<pin);
	}

}

void gpio_out::toggleValor(void)
{
	if ( !error )
		GPIO->PIN[port] ^= (1<<pin);
}
