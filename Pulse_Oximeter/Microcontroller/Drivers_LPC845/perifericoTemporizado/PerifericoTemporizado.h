/*
 * PerifericoTemporizado.h
 *
 *  Created on: July 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

/*  ESP
 * @brief Aquí tenemos los includes y la declaración de la clase abstracta `PerifericoTemporizado`, la cual sirve como base para implementar
 *        periféricos temporizados. Esta clase proporciona una estructura común para gestionar periféricos que requieren operaciones periódicas.
 *
 *      **Variables Estáticas**
 *
 *      cant_pt:     Variable estática de tipo `uint8_t` que almacena la cantidad de instancias de periféricos temporizados creadas.
 *
 *      **Métodos Públicos**
 *
 *      PerifericoTemporizado():
 *                   Constructor de la clase. Inicializa una instancia de periférico temporizado.
 *
 *      ~PerifericoTemporizado():
 *                   Destructor de la clase. Libera los recursos asociados a la instancia.
 *
 *      virtual void callback(void) = 0:
 *                   Método puramente virtual que debe ser implementado en las clases derivadas. Representa la operación que se ejecutará
 *                   de forma periódica en el periférico.
 *
 *      **Extern Variables**
 *
 *      perifericosTemp:
 *                   Puntero a un array de punteros de objetos `PerifericoTemporizado`. Permite almacenar y gestionar múltiples periféricos temporizados.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the includes and the declaration of the abstract class `PerifericoTemporizado`, which serves as a base to implement
 *        timed peripherals. This class provides a common structure for managing peripherals that require periodic operations.
 *
 *      **Static Variables**
 *
 *      cant_pt:     Static `uint8_t` variable that stores the count of created timed peripheral instances.
 *
 *      **Public Methods**
 *
 *      PerifericoTemporizado():
 *                   Class constructor. Initializes a timed peripheral instance.
 *
 *      ~PerifericoTemporizado():
 *                   Class destructor. Releases resources associated with the instance.
 *
 *      virtual void callback(void) = 0:
 *                   Pure virtual method that must be implemented in derived classes. Represents the operation to be executed
 *                   periodically in the peripheral.
 *
 *      **Extern Variables**
 *
 *      perifericosTemp:
 *                   Pointer to an array of `PerifericoTemporizado` object pointers. Allows storing and managing multiple timed peripherals.
 *
 * @param None
 */

#ifndef PERIFERICOTEMPORIZADO_H_
#define PERIFERICOTEMPORIZADO_H_

#include <LPC845.h>

class PerifericoTemporizado
{
public:
	PerifericoTemporizado();
	~PerifericoTemporizado();

	virtual void callback ( void ) = 0;
	static uint8_t cant_pt;
};

extern PerifericoTemporizado **perifericosTemp;


#endif /* PERIFERICOTEMPORIZADO_H_ */
