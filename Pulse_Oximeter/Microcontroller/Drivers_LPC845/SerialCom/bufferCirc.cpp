/*
 * bufferCirc.cpp
 *
 *  Created on: 2 oct. 2023
 *      Author: chor
 */

#include "bufferCirc.h"

/*
 * @brief constructor de la clase bufferCirc
 * 		  inicializa las variables a usar
 * */
bufferCirc::bufferCirc ( uint8_t cant_bytes )
{
	tam = cant_bytes;
	in = 0;
	out = 0;
	lleno = false;
	buffer = new uint8_t [tam];

}

/*
 * @brief guarda un dato en el buffer circular
 * @param dato valor a almacenar
 * */
void bufferCirc::push ( uint8_t dato )
{
	if ( ! lleno )
	{
		buffer[in] = dato;
		in++;
		in%= tam;

		if ( in == out )
			lleno = true;
	}
}

/*
 * @brief saca un dato en el buffer circular y lo devuelve
 * */
int16_t bufferCirc::pop ( void )
{
	int16_t retorno = NO_DATA;

	if ( (in != out) || lleno )
	{
		retorno = buffer[out];
		out++;
		out %= tam;
	}

	lleno = false;

	return retorno;
}

/*
 * @brief Indica si hay lugar para guardar en el buffer circular o no
 * */
bool bufferCirc::hayLugar()
{
	return !lleno;
}
