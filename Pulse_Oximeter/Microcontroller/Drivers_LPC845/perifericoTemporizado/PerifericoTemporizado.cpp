/*
 * PerifericoTemporizado.cpp
 *
 *  Created on: July 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

#include "PerifericoTemporizado.h"


/* ESP
 * @brief Variable estática que lleva la cuenta de cuántos periféricos temporizados se han creado.
 */

/* ENG
 * @brief Static variable tracking how many timed peripherals have been created.
 */

uint8_t PerifericoTemporizado::cant_pt = 0;




/* ESP
 * @brief Puntero global que apunta a una lista dinámica de objetos `PerifericoTemporizado`.
 *        Almacena referencias a todos los periféricos temporizados creados.
 */

/* ENG
 * @brief Global pointer to a dynamic list of `PerifericoTemporizado` objects.
 *        Stores references to all created timed peripherals.
 */

PerifericoTemporizado **perifericosTemp = nullptr;




/* ESP
 * @brief Constructor de la clase `PerifericoTemporizado`.
 *        Agrega el nuevo objeto a una lista dinámica de periféricos temporizados.
 */

/* ENG
 * @brief Constructor for the `PerifericoTemporizado` class.
 *        Adds the new object to a dynamic list of timed peripherals.
 */

PerifericoTemporizado::PerifericoTemporizado()
{
	// ESP: Crea una nueva lista dinámica que incluye el nuevo periférico.
	// ENG: Creates a new dynamic list including the new peripheral.
	PerifericoTemporizado **aux = new PerifericoTemporizado*[cant_pt+1];

	// ESP: Copia los elementos de la lista actual al nuevo vector.
	// ENG: Copies elements from the current list to the new vector.
	for ( int i = 0 ; i < cant_pt ; i++ )
		aux[i] = perifericosTemp[i];

	// ESP: Agrega el nuevo periférico al final de la lista.
	// ENG: Adds the new peripheral to the end of the list.
	aux[cant_pt] = this;
	cant_pt++; // ESP: Incrementa el contador de periféricos. ENG: Increments the peripheral counter.

	// ESP: Libera la memoria de la lista anterior y actualiza el puntero global.
	// ENG: Frees the memory of the old list and updates the global pointer.
	delete[] perifericosTemp;
	perifericosTemp = aux;
}




/* ESP
 * @brief Destructor de la clase `PerifericoTemporizado`.
 *        Elimina el objeto de la lista dinámica de periféricos temporizados.
 */

/* ENG
 * @brief Destructor for the `PerifericoTemporizado` class.
 *        Removes the object from the dynamic list of timed peripherals.
 */

PerifericoTemporizado::~PerifericoTemporizado()
{
	int posicion;

	// ESP: Encuentra la posición del objeto actual "this" en la lista.
	// ENG: Finds the position of the current object "this" in the list.
	for ( posicion = 0 ; posicion < cant_pt ; posicion++ )
		if ( perifericosTemp[posicion] == this )
			break;

	// ESP: Crea una nueva lista dinámica excluyendo el objeto actual "this".
	// ENG: Creates a new dynamic list excluding the current object.
	PerifericoTemporizado **aux = new PerifericoTemporizado*[cant_pt-1];
	for ( int i = 0 ; i < posicion; i++ )
		aux[i] = perifericosTemp[i];
	for ( int i = posicion + 1 ; i < cant_pt ; i++ )
		aux[i-1] = perifericosTemp[i];

	// ESP: Libera la memoria de la lista anterior y actualiza el puntero global.
	// ENG: Frees the memory of the old list and updates the global pointer.
	delete[] perifericosTemp;
	cant_pt--;

	perifericosTemp = aux;

}

