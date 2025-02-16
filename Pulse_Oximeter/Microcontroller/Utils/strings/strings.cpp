/*
 * Cadena.cpp
 *
 *  Created on: 29 nov 2024
 *      Author: Facundo Costarelli
 */

#include <strings.h>




/* ESP
 * @brief Convierte un número entero en una cadena de caracteres.
 *        El número se convierte a su representación en ASCII y se almacena en la cadena proporcionada.
 *
 * @param numero Número entero a convertir.
 * @param cadena Puntero a la cadena donde se almacenará el resultado.
 */
/* ENG
 * @brief Converts an integer to a string.
 *        The number is converted to its ASCII representation and stored in the provided string.
 *
 * @param numero Integer number to convert.
 * @param cadena Pointer to the string where the result will be stored.
 */

void Cadenas::enteroACadena(uint8_t numero, uint8_t* cadena) {
	 uint8_t i = 0;

	 // ESP: Convertimos el número a cadena en orden inverso.
	 // ENG: Convert the number to a string in reverse order.
	do {
		// ESP: Convertimos el dígito a su equivalente ASCII y lo almacenamos.
		// ENG: Convert the digit to its ASCII equivalent and store it.
		cadena[i++] = (numero % 10) + '0'; // Convertimos el dígito a ASCII

		// ESP: Dividimos el número por 10 para procesar el siguiente dígito.
		// ENG: Divide the number by 10 to process the next digit.
		numero /= 10;
	} while (numero > 0);

	// ESP: Invertimos el resultado para obtener el orden correcto.
	// ENG: Reverse the result to get the correct order.
	for (uint8_t j = 0; j < i / 2; j++) {
		uint8_t temp = cadena[j];
		cadena[j] = cadena[i - j - 1];
		cadena[i - j - 1] = temp;
	}

	// ESP: Añadimos el terminador nulo al final de la cadena.
	// ENG: Add the null terminator at the end of the string.
	cadena[i] = '\0';
 }




/* ESP
 * @brief Concatena una cadena de origen al final de una cadena de destino.
 *        La cadena de origen se añade al final de la cadena de destino.
 *
 * @param destino Puntero a la cadena de destino.
 * @param origen Puntero a la cadena de origen.
 */
/* ENG
 * @brief Concatenates a source string to the end of a destination string.
 *        The source string is appended to the end of the destination string.
 *
 * @param destino Pointer to the destination string.
 * @param origen Pointer to the source string.
 */

 void Cadenas::concatenarCadena(uint8_t* destino, const uint8_t* origen) {
     uint16_t i = 0;
     uint16_t j = longitudCadena(destino);

     // ESP: Recorro la cadena de origen hasta encontrar el terminador nulo.
     // ENG: Iterate through the source string until the null terminator is found.
     while (origen[i] != '\0') {

    	 // ESP: Copio cada carácter de la cadena de origen al final de la cadena de destino.
    	 // ENG: Copy each character from the source string to the end of the destination string.
    	 destino[j] = origen[i];
         i++;
         j++;
     }

     // ESP: Añado el terminador nulo al final de la cadena resultante.
     // ENG: Add the null terminator at the end of the resulting string.
     destino[j] = '\0';
 }




 /* ESP
  * @brief Copia una cadena de origen a una cadena de destino.
  *        La cadena de origen se copia completamente en la cadena de destino.
  *
  * @param destino Puntero a la cadena de destino.
  * @param origen Puntero a la cadena de origen.
  */
 /* ENG
  * @brief Copies a source string to a destination string.
  *        The source string is completely copied into the destination string.
  *
  * @param destino Pointer to the destination string.
  * @param origen Pointer to the source string.
  */

 void Cadenas::copiarCadena(uint8_t* destino, const uint8_t* origen) {
     uint16_t i = 0;

     // ESP: Recorro la cadena de origen hasta encontrar el terminador nulo.
     // ENG: Iterate through the source string until the null terminator is found.
     while (origen[i] != '\0') {

    	 // ESP: Copio cada carácter de la cadena de origen a la cadena de destino.
    	 // ENG: Copy each character from the source string to the destination string.
    	 destino[i] = origen[i];
         i++;
     }

     // ESP: Añado el terminador nulo al final de la cadena de destino.
     // ENG: Add the null terminator at the end of the destination string.
     destino[i] = '\0';
 }




 /* ESP
  * @brief Calcula la longitud de una cadena.
  *        La longitud se determina contando los caracteres hasta el terminador nulo.
  *
  * @param cadena Puntero a la cadena cuya longitud se desea calcular.
  * @return Longitud de la cadena (número de caracteres).
  */
 /* ENG
  * @brief Calculates the length of a string.
  *        The length is determined by counting characters until the null terminator is found.
  *
  * @param cadena Pointer to the string whose length is to be calculated.
  * @return Length of the string (number of characters).
  */

uint8_t Cadenas::longitudCadena(const uint8_t* cadena) {
	uint8_t longitud = 0;

	// ESP: Recorro la cadena hasta encontrar el terminador nulo.
	// ENG: Iterate through the string until the null terminator is found.
	while (cadena[longitud] != '\0') { longitud++; }

	// ESP: Retorno la longitud de la cadena.
	// ENG: Return the length of the string.
	return longitud;
}
