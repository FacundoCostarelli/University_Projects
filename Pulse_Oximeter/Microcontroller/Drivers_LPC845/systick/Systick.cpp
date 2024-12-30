/*
 * Systick.cpp
 *
 *  Created on: 29 jul. 2024
 *      Author: chor
 */

#include <Systick.h>

void (*funcSystick) (void) = nullptr;

void SysTick_Handler (void)
{
	if ( funcSystick != nullptr )
		funcSystick();
}

void InstallSystick ( void ( *func ) (void) )
{
	funcSystick = func;
}
