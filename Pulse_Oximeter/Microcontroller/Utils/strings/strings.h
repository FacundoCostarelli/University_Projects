/*
 * Cadenas.h
 *
 *  Created on: 29 nov 2024
 *      Author: Facun
 */

#ifndef DRIVERS_LPC845_CADENAS_H_
#define DRIVERS_LPC845_CADENAS_H_

#include "LPC845.h"

class Cadenas{

	public:
		static void enteroACadena(uint8_t numero, uint8_t* cadena);
		static void concatenarCadena(uint8_t* destino, const uint8_t* origen);
		static void copiarCadena(uint8_t* destino, const uint8_t* origen) ;
		static uint8_t longitudCadena(const uint8_t* cadena);

};



#endif /* DRIVERS_LPC845_CADENAS_H_ */
