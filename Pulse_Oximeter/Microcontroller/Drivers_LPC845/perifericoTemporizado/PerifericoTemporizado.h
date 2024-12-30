/*
 * PerifericoTemporizado.h
 *
 *  Created on: 29 jul. 2024
 *      Author: chor
 */

#ifndef PERIFERICOTEMPORIZADO_H_
#define PERIFERICOTEMPORIZADO_H_

#include <LPC845.h>

class PerifericoTemporizado {

public:
	PerifericoTemporizado();
	~PerifericoTemporizado();

	virtual void callback ( void ) = 0;
	static uint8_t cant_pt;
};

extern PerifericoTemporizado **perifericosTemp;


#endif /* PERIFERICOTEMPORIZADO_H_ */
