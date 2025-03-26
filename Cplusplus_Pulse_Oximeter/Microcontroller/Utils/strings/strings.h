/*
 * Cadenas.h
 *
 *  Created on: 29 nov 2024
 *      Author: Facundo Costarelli
 */

/* ESP
 * @brief Este archivo define la clase `Cadenas`, que proporciona métodos estáticos para manipular cadenas de caracteres.
 *        Incluye funciones para convertir enteros a cadenas, concatenar cadenas, copiar cadenas y calcular la longitud de una cadena.
 *
 *      **Clase Cadenas**
 *
 *      **Métodos Públicos Estáticos**
 *
 *      enteroACadena(uint8_t numero, uint8_t* cadena):
 *                          Convierte un número entero de 8 bits en una cadena de caracteres.
 *                          - `numero`: El número entero que se convertirá.
 *                          - `cadena`: Puntero al arreglo de caracteres donde se almacenará la cadena resultante.
 *
 *      concatenarCadena(uint8_t* destino, const uint8_t* origen):
 *                          Concatena la cadena `origen` al final de la cadena `destino`.
 *                          - `destino`: Puntero a la cadena de destino donde se concatenará la cadena origen.
 *                          - `origen`: Puntero a la cadena que se concatenará.
 *
 *      copiarCadena(uint8_t* destino, const uint8_t* origen):
 *                          Copia la cadena `origen` en la cadena `destino`.
 *                          - `destino`: Puntero a la cadena de destino donde se copiará la cadena origen.
 *                          - `origen`: Puntero a la cadena que se copiará.
 *
 *      longitudCadena(const uint8_t* cadena):
 *                          Calcula la longitud de una cadena de caracteres.
 *                          - `cadena`: Puntero a la cadena de la cual se calculará la longitud.
 *                          - Retorna: La longitud de la cadena (número de caracteres).
 *
 * @param Ninguno
 */

/* ENG
 * @brief This file defines the `Cadenas` class, which provides static methods for manipulating character strings.
 *        It includes functions to convert integers to strings, concatenate strings, copy strings, and calculate the length of a string.
 *
 *      **Class Cadenas**
 *
 *      **Public Static Methods**
 *
 *      enteroACadena(uint8_t numero, uint8_t* cadena):
 *                          Converts an 8-bit integer into a character string.
 *                          - `numero`: The integer to be converted.
 *                          - `cadena`: Pointer to the character array where the resulting string will be stored.
 *
 *      concatenarCadena(uint8_t* destino, const uint8_t* origen):
 *                          Concatenates the `origen` string to the end of the `destino` string.
 *                          - `destino`: Pointer to the destination string where the `origen` string will be concatenated.
 *                          - `origen`: Pointer to the string to be concatenated.
 *
 *      copiarCadena(uint8_t* destino, const uint8_t* origen):
 *                          Copies the `origen` string into the `destino` string.
 *                          - `destino`: Pointer to the destination string where the `origen` string will be copied.
 *                          - `origen`: Pointer to the string to be copied.
 *
 *      longitudCadena(const uint8_t* cadena):
 *                          Calculates the length of a character string.
 *                          - `cadena`: Pointer to the string whose length will be calculated.
 *                          - Returns: The length of the string (number of characters).
 *
 * @param None
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
