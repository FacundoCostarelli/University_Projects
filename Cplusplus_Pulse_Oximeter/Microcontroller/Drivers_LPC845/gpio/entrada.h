/*
 * entrada.h
 *
 *  Created on: 20 may. 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

/* ESP
 * @brief Aquí tenemos la declaración de la clase abstracta `entrada`, que define una interfaz para obtener un valor booleano.
 *        Esta clase es una clase base pura, lo que significa que no se puede instanciar directamente y debe ser heredada por clases derivadas.
 *
 *      **Métodos Públicos**
 *
 *      entrada():                Constructor de la clase. Inicializa la instancia de la clase.
 *      virtual ~entrada():        Destructor virtual de la clase. Permite la liberación adecuada de recursos en clases derivadas.
 *      virtual bool getValor() const = 0:
 *                                 Método virtual puro que debe ser implementado por las clases derivadas. Devuelve un valor booleano que representa el estado de la entrada.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the declaration of the abstract class `entrada`, which defines an interface for obtaining a boolean value.
 *        This class is a pure base class, meaning it cannot be instantiated directly and must be inherited by derived classes.
 *
 *      **Public Methods**
 *
 *      entrada():                Class constructor. Initializes the class instance.
 *      virtual ~entrada():       Virtual destructor of the class. Ensures proper resource cleanup in derived classes.
 *      virtual bool getValor() const = 0:
 *                                 Pure virtual method that must be implemented by derived classes. Returns a boolean value representing the state of the input.
 *
 * @param None
 */

#ifndef ENTRADA_H_
#define ENTRADA_H_

class entrada {

public:

	entrada();
	virtual bool getValor() const = 0;

};

#endif /* ENTRADA_H_ */
