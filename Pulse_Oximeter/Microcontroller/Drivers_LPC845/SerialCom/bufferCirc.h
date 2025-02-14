/*
 * bufferCirc.h
 *
 *  Created on: October 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

/* ESP
 * @brief Aquí tenemos los includes y la declaración de la clase `bufferCirc`, la cual implementa un buffer circular para el almacenamiento y manejo
 *        de datos de manera eficiente. Este buffer permite insertar y extraer datos con un control básico de sobreescritura y disponibilidad.
 *
 *      **Variables**
 *
 *      buffer:       Puntero de tipo `uint8_t` que almacena la dirección del área de memoria utilizada como buffer.
 *      tam:          Variable de tipo `uint8_t` que guarda el tamaño máximo del buffer en bytes.
 *      in:           Variable de tipo `uint8_t` que actúa como índice para la posición de escritura en el buffer.
 *      out:          Variable de tipo `uint8_t` que actúa como índice para la posición de lectura en el buffer.
 *      lleno:        Variable booleana que indica si el buffer está lleno, evitando sobreescrituras no controladas.
 *
 *      **Constantes**
 *
 *      NO_DATA:      Constante de tipo `int16_t` con valor -1, que indica que no hay datos disponibles para leer en el buffer.
 *
 *      **Métodos**
 *
 *      bufferCirc(uint8_t cant_bytes = 30):
 *                   Constructor de la clase. Inicializa el buffer con un tamaño especificado (por defecto, 30 bytes).
 *
 *      void push(uint8_t):
 *                   Método que inserta un nuevo dato en el buffer. Si el buffer está lleno, no se realiza la operación.
 *
 *      int16_t pop():
 *                   Método que extrae el dato más antiguo almacenado en el buffer. Si el buffer está vacío, devuelve `NO_DATA`.
 *
 *      bool hayLugar():
 *                   Método que verifica si hay espacio disponible en el buffer para insertar nuevos datos.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the includes and the declaration of the `bufferCirc` class, which implements a circular buffer for efficient data storage
 *        and handling. This buffer allows inserting and extracting data with basic control over overwriting and availability.
 *
 *      **Variables**
 *
 *      buffer:       `uint8_t` pointer that stores the address of the memory area used as the buffer.
 *      tam:          `uint8_t` variable that stores the maximum size of the buffer in bytes.
 *      in:           `uint8_t` variable that acts as an index for the write position in the buffer.
 *      out:          `uint8_t` variable that acts as an index for the read position in the buffer.
 *      lleno:        Boolean variable that indicates whether the buffer is full, preventing uncontrolled overwrites.
 *
 *      **Constants**
 *
 *      NO_DATA:      `int16_t` constant with a value of -1, indicating that no data is available to read from the buffer.
 *
 *      **Methods**
 *
 *      bufferCirc(uint8_t cant_bytes = 30):
 *                   Class constructor. Initializes the buffer with a specified size (default is 30 bytes).
 *
 *      void push(uint8_t):
 *                   Method that inserts a new data byte into the buffer. If the buffer is full, the operation is not performed.
 *
 *      int16_t pop():
 *                   Method that extracts the oldest data byte stored in the buffer. If the buffer is empty, it returns `NO_DATA`.
 *
 *      bool hayLugar():
 *                   Method that checks if there is space available in the buffer to insert new data.
 *
 * @param None
 */

#ifndef BUFFERCIRC_H_
#define BUFFERCIRC_H_

#include "../LPC845.h"

class bufferCirc {

	private:
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
