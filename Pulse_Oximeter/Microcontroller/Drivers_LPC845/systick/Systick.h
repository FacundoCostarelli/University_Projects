/*
 * Systick.h
 *
 *  Created on: 29 jul. 2024
 *      Author: chor
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <LPC845.h>

extern void (*funcSystick) (void);

void InstallSystick ( void (*) (void) );

#if defined (__cplusplus)
extern "C" {

void SysTick_Handler (void);
}
#endif

#endif /* SYSTICK_H_ */
