/*
 * Cadena.cpp
 *
 *  Created on: 29 nov 2024
 *      Author: Facun
 */

#include <strings.h>

void Cadenas::enteroACadena(uint8_t numero, uint8_t* cadena) {
	 uint8_t i = 0;

	// Convertimos el número a cadena en orden inverso
	do {
		cadena[i++] = (numero % 10) + '0'; // Convertimos el dígito a ASCII
		numero /= 10;
	} while (numero > 0);

	// Invertimos el resultado para obtener el orden correcto
	for (uint8_t j = 0; j < i / 2; j++) {
		uint8_t temp = cadena[j];
		cadena[j] = cadena[i - j - 1];
		cadena[i - j - 1] = temp;
	}

	// Añadimos el terminador nulo al final
	cadena[i] = '\0';
 }

 void Cadenas::concatenarCadena(uint8_t* destino, const uint8_t* origen) {
     uint16_t i = 0;
     uint16_t j = longitudCadena(destino);
     while (origen[i] != '\0') {
         destino[j] = origen[i];
         i++;
         j++;
     }
     destino[j] = '\0';
 }

 //no se usa pero esta por si se quiere usar
 void Cadenas::copiarCadena(uint8_t* destino, const uint8_t* origen) {
     uint16_t i = 0;
     while (origen[i] != '\0') {
         destino[i] = origen[i];
         i++;
     }
     destino[i] = '\0';
 }
uint8_t Cadenas::longitudCadena(const uint8_t* cadena) {
	uint8_t longitud = 0;
	while (cadena[longitud] != '\0') { longitud++; }
	return longitud;
}
