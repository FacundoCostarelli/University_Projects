/*
 * PinInt.h
 *
 *  Created on: 5 jun. 2023
 *      Author: chor
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

class PinInt {

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
