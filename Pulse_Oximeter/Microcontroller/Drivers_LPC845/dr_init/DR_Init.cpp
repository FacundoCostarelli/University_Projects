/*
 * DR_Init.c
 *
 *  Created on: 8 ago. 2021
 *      Author: Jorge Escola
 */

#include "DR_Init.h"

// ESP: Declaro un puntero a función para configurar la frecuencia del FRO.
// ENG: Declare a function pointer to set the FRO frequency.
void (*fro_set_frec) (int ) = FRO_SET_FRECUENCY_FUNC;




/* ESP
 * @brief Inicializa el PLL y configura el reloj del sistema.
 *        Configura el FRO, el PLL y el Systick para interrumpir cada 1 ms.
 */
/* ENG
 * @brief Initializes the PLL and configures the system clock.
 *        Configures the FRO, PLL, and Systick to interrupt every 1 ms.
 */

void InicializarPLL(void)
{
	// ESP: Configuro la frecuencia del FRO a 30 MHz llamando a la función de ROM.
	// ENG: Set the FRO frequency to 30 MHz by calling the ROM function.
	fro_set_frec(30000);

	// ESP: Selecciono la salida del FRO como el reloj principal del sistema.
	// ENG: Select the FRO output as the main system clock.
	SYSCON->FROOSCCTRL |= 1<<17;

	// ESP: Refresco el registro para habilitar el reloj de 30 MHz.
	// ENG: Refresh the register to enable the 30 MHz clock.
	SYSCON->FRODIRECTCLKUEN &= ~1;
	SYSCON->FRODIRECTCLKUEN |= 1;


	// ESP: Configuro el FRO como la fuente de reloj del PLL.
	// ENG: Set the FRO as the clock source for the PLL.
	SYSCON->MAINCLKPLLSEL = 0;

	// ESP: Refresco el registro para habilitar el cambio de fuente de reloj del PLL.
	// ENG: Refresh the register to enable the PLL clock source change.
	SYSCON->MAINCLKPLLUEN &= ~1;
	SYSCON->MAINCLKPLLUEN |= 1;

	// ESP: Configuro el FRO como la fuente de reloj del PLL.
	// ENG: Set the FRO as the clock source for the PLL.
	SYSCON->SYSPLLCLKSEL = 0;

	// ESP: Refresco el registro para habilitar el cambio de fuente de reloj del PLL.
	// ENG: Refresh the register to enable the PLL clock source change.
	SYSCON->SYSPLLCLKUEN &= ~1;
	SYSCON->SYSPLLCLKUEN |= 1;

	// ESP: Configuro el divisor del reloj del sistema a 1 (sin división).
	// ENG: Set the system clock divider to 1 (no division).
	SYSCON->SYSAHBCLKDIV = 1;

	// ESP: Configuro el Systick para que interrumpa cada 1 ms.
	// ENG: Configure the Systick to interrupt every 1 ms.
	SYSTICK->CSR=6;				// ESP: Habilito la interrupción del Systick y selecciono el FRO como fuente. ENG: Enable Systick interrupt and select FRO as the source.
	SYSTICK->RVR=30000-1;		// ESP: Configuro el Systick para interrumpir cada 1 ms (30000 ticks a 30 MHz), va el -1 porque tarda 1 tick mas en hacer un reload. ENG: Configure Systick to interrupt every 1 ms (30000 ticks at 30 MHz), -1 goes because it takes 1 more tick to do a reload.
	SYSTICK->CVR=SYSTICK->RVR;	// ESP: Aseguro que la primera interrupción dure lo mismo que las siguientes. ENG: Ensure the first interrupt lasts the same as the others.
	SYSTICK->CSR |= 1;			// ESP: Habilito el Systick. ENG: Enable the Systick.

	// ESP: Asigno la función de recorrido de periféricos temporizados al Systick.
	// ENG: Assign the timed peripherals traversal function to the Systick.
	InstallSystick(recorridoPTs);
}




/* ESP
 * @brief Recorre todos los periféricos temporizados y ejecuta su callback.
 *        Esta función se llama periódicamente desde el Systick.
 */
/* ENG
 * @brief Iterates through all timed peripherals and executes their callback.
 *        This function is called periodically from the Systick.
 */

void recorridoPTs (void)
{
	// ESP: Recorro todos los periféricos temporizados registrados.
	// ENG: Iterate through all registered timed peripherals.
	for (int i = 0 ; i < PerifericoTemporizado::cant_pt ; i++)
	{
		// ESP: Ejecuto el callback del periférico temporizado actual.
		// ENG: Execute the callback of the current timed peripheral.
		perifericosTemp[i]->callback();
	}
}
