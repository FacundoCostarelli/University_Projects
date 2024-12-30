/*
 * bufferCirc.h
 *
 *  Created on: 2 oct. 2023
 *      Author: chor
 */

#ifndef BUFFERCIRC_H_
#define BUFFERCIRC_H_

#include "../LPC845.h"

class bufferCirc {

	uint8_t *buffer;
	uint8_t tam;

	uint8_t in,out;
	bool lleno;

public:

	const static int16_t NO_DATA = -1;

	bufferCirc ( uint8_t cant_bytes = 30 );

	void push ( uint8_t );
	int16_t pop ( );

	bool hayLugar();
};

#endif /* BUFFERCIRC_H_ */
