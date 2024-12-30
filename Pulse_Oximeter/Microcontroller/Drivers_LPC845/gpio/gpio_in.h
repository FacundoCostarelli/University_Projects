/*
 * gpio_in.h
 *
 *  Created on: 20 may. 2024
 *      Author: chor
 */

#ifndef GPIO_IN_H_
#define GPIO_IN_H_

#include "entrada.h"
#include "../LPC845.h"

class gpio_in : public entrada {

	private:
		uint8_t port;
		uint8_t pin;
		bool error;

	public:

		static const uint8_t iocon_index[2][32];

		static const uint8_t MODE_NONE = 0;
		static const uint8_t MODE_PULLDOWN = 1;
		static const uint8_t MODE_PULLUP = 2;
		static const uint8_t MODE_REPEAT = 3;

		gpio_in( uint8_t _port , uint8_t _pin , uint8_t modo = MODE_PULLUP );
		void setDir();
		void setMODE( uint8_t );
		bool getValor() const;

};

#endif /* GPIO_IN_H_ */
