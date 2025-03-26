/*
 * bufferCirc.cpp
 *
 *  Created on: October 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

#include "bufferCirc.h"

/* ESP
 * @brief Constructor de la clase bufferCirc.
 *        Inicializa las variables necesarias y asigna memoria dinámica para el buffer circular.
 *
 * @param cant_bytes Cantidad de bytes que puede almacenar el buffer.
 */

/* ENG
 * @brief Constructor of the bufferCirc class.
 *        Initializes necessary variables and allocates dynamic memory for the circular buffer.
 *
 * @param cant_bytes Number of bytes the buffer can store.
 */

bufferCirc::bufferCirc ( uint8_t cant_bytes )
{
	// ESP: Establezco el tamaño del buffer circular.
	// ENG: Set the size of the circular buffer.
	tam = cant_bytes;

	// ESP: Inicializo los índices de entrada y salida en cero.
	// ENG: Initialize the input and output indices to zero.
	in = 0;
	out = 0;

	// ESP: Marco el buffer como no lleno inicialmente.
	// ENG: Mark the buffer as not full initially.
	lleno = false;

	// ESP: Asigno memoria dinámica para el buffer con el tamaño especificado.
	// ENG: Allocate dynamic memory for the buffer with the specified size.
	buffer = new uint8_t [tam];
}




/* ESP
 * @brief Guarda un dato en el buffer circular si hay espacio disponible.
 *
 * @param dato Valor a almacenar en el buffer.
 */

/* ENG
 * @brief Stores a data value in the circular buffer if space is available.
 *
 * @param dato Value to store in the buffer.
 */

void bufferCirc::push ( uint8_t dato )
{
	if ( ! lleno )
	{
		// ESP: Almaceno el dato en la posición de entrada del buffer.
		// ENG: Store the data in the buffer's input position.
		buffer[in] = dato;

		// ESP: Incremento el índice de entrada y aplico el módulo para mantenerlo dentro del tamaño del buffer.
		// ENG: Increment the input index and apply modulo to keep it within the buffer size.
		in++;
		in%= tam;

		// ESP: Si el índice de entrada alcanza al de salida, el buffer está lleno.
		// ENG: If the input index reaches the output index, the buffer is full.
		if ( in == out )
			lleno = true;
	}
}




/* ESP
 * @brief Extrae un dato del buffer circular y lo devuelve.
 *        Si el buffer está vacío, devuelve un valor de error.
 *
 * @return El dato extraído o el valor NO_DATA si el buffer está vacío.
 */

/* ENG
 * @brief Removes a data value from the circular buffer and returns it.
 *        If the buffer is empty, it returns an error value.
 *
 * @return The extracted data or the NO_DATA value if the buffer is empty.
 */

int16_t bufferCirc::pop ( void )
{
	int16_t retorno = NO_DATA;

	if ( (in != out) || lleno )
	{
		// ESP: Extraigo el dato de la posición de salida del buffer.
		// ENG: Extract the data from the buffer's output position.
		retorno = buffer[out];

		// ESP: Incremento el índice de salida y aplico el módulo para mantenerlo dentro del tamaño del buffer.
		// ENG: Increment the output index and apply modulo to keep it within the buffer size.
		out++;
		out %= tam;
	}

	// ESP: Después de extraer un dato, marco el buffer como no lleno.
	// ENG: After extracting data, mark the buffer as not full.
	lleno = false;

	return retorno;
}




/* ESP
 * @brief Verifica si hay espacio disponible en el buffer circular.
 *
 * @return true si hay espacio, false si el buffer está lleno.
 */

/* ENG
 * @brief Checks if there is available space in the circular buffer.
 *
 * @return true if there is space, false if the buffer is full.
 */

bool bufferCirc::hayLugar()
{
	// ESP: Retorno true si el buffer no está lleno.
	// ENG: Return true if the buffer is not full.
	return !lleno;
}
