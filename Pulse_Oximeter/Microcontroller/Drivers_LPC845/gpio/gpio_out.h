/*
 * gpio_out.h
 *
 *  Created on: 20 may. 2024
 *      Author: chor
 */

#ifndef GPIO_OUT_H_
#define GPIO_OUT_H_

#include "salida.h"
#include "../LPC845.h"

class gpio_out : public salida{

	private:
		uint8_t port;
		uint8_t pin;
		bool error;

	public:

		static const uint8_t iocon_index[2][32];

		static const uint8_t MODE_OD_OFF = 0;
		static const uint8_t MODE_OD_ON = 1;

		gpio_out( uint8_t _port , uint8_t _pin , uint8_t modo = MODE_OD_OFF );
		void setDir();
		void setMODE( uint8_t );
		void setValor( bool val);
		void toggleValor ( );

};

#endif /* GPIO_OUT_H_ */
