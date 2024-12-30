/*
 * PinInt.cpp
 *
 *  Created on: 5 jun. 2023
 *      Author: chor
 */

#include "PinInt.h"

void (*PinInt::handlers[8]) (void) = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};

uint8_t PinInt::cant_ints = 0;

void PININT0_IRQHandler (void)
{
	INT_EXT->IST |= 1;
	if ( PinInt::handlers[0] != nullptr )
		PinInt::handlers[0]();
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

PinInt::PinInt( uint8_t port , uint8_t pin , void (*handler) (void) , uint8_t asc_on , uint8_t desc_on , uint8_t alto_on , uint8_t bajo_on )
{
	if ( cant_ints > 7 )
		cant_ints = 0;

	fuente = cant_ints;
	cant_ints++;

	//Pongo la función de interrupción en el vector:
	handlers[fuente] = handler;

	//Habilito el clk del perisferico PIN INTERRUPT
	SYSCON->SYSAHBCLKCTRL0 |= 1 << 28;

	//Fuente de interrupcion indicada por int_src
	//Tengo que poner el nro de pin que generará la interrupción:
	//P0.0 a P0.31 se los indica con los números 0 a 31
	//P1.0 a P1.31 se los indica con los números 32 a 63
	SYSCON->PINTSEL[ fuente ] = port*32 + pin;

	//Deshabilito las interrupciones hasta que el usuario las configure:
	set_flanco(asc_on,desc_on);
	set_nivel(alto_on,bajo_on);

}

PinInt::~PinInt()
{
	//Deshabilito la interrupción en el NVIC:
	ICER0 |= (0x01 << (24 + fuente));

	//Deshabilito flanco y nivel de esta fuente de interrupcion:
	set_flanco(0,0);
	set_nivel(0,0);

	handlers[fuente] = nullptr;
}

void PinInt::set_flanco (uint8_t asc_on , uint8_t desc_on )
{
	//Si quiero habilitar alguno de los flancos lo selecciono en el registro ISEL:
	if ( asc_on || desc_on )
		INT_EXT->ISEL &= ~(1<<fuente);

	//Si el flanco ascendente está habilitado lo reflejo en el registro IENR:
	if ( asc_on )
		INT_EXT->IENR |= 1<<fuente;

	//Si el flanco descendente está habilitado lo reflejo en el registro IENF:
	if ( desc_on )
		INT_EXT->IENF |= 1<<fuente;

	//Por las dudas limpio el flag de estado:
	INT_EXT->IST |= 1<<fuente;

	//Habilito NVIC
	if ( asc_on || desc_on)
		ISER0 |= (1 << (24 + fuente));
}

void PinInt::set_nivel ( uint8_t alto_on , uint8_t bajo_on )
{
	//Si quiero configurar alguno de los niveles lo selecciono en el registro ISEL:
	if ( alto_on || bajo_on)
		INT_EXT->ISEL |= 1<<fuente;

	//Si se habilita la interrupcion por nivel alto:
	if ( alto_on )
	{
		INT_EXT->IENR &= ~(1<<fuente);
		INT_EXT->IENF |= 1<<fuente;
	}

	//Si se habilita la interrupcion por nivel bajo:
	if ( bajo_on)
	{
		INT_EXT->IENR &= ~(1<<fuente);
		INT_EXT->IENF &= ~(1<<fuente);
	}

	//Por las dudas limpio el flag de estado:
	INT_EXT->IST |= 1<<fuente;

	//Habilito NVIC
	if ( alto_on || bajo_on)
		ISER0 |= (0x01 << (24 + fuente));
}
