/*
 * salida.h
 *
 *  Created on: 20 may. 2024
 *      Author: Jorge Escola
 */

/* ESP
 * @brief Aquí tenemos la declaración de la clase abstracta `salida`, que define una interfaz para controlar una salida digital.
 *        Esta clase es una clase base pura, lo que significa que no se puede instanciar directamente y debe ser heredada por clases derivadas.
 *
 *      **Métodos Públicos**
 *
 *      salida():                Constructor de la clase. Inicializa la instancia de la clase.
 *      virtual ~salida():        Destructor virtual de la clase. Permite la liberación adecuada de recursos en clases derivadas.
 *      virtual void setValor(bool) = 0:
 *                               Método virtual puro que debe ser implementado por las clases derivadas. Establece el valor de la salida (true para alto, false para bajo).
 *      virtual void toggleValor() = 0:
 *                               Método virtual puro que debe ser implementado por las clases derivadas. Invierte el valor actual de la salida.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the declaration of the abstract class `salida`, which defines an interface for controlling a digital output.
 *        This class is a pure base class, meaning it cannot be instantiated directly and must be inherited by derived classes.
 *
 *      **Public Methods**
 *
 *      salida():                Class constructor. Initializes the class instance.
 *      virtual ~salida():       Virtual destructor of the class. Ensures proper resource cleanup in derived classes.
 *      virtual void setValor(bool) = 0:
 *                               Pure virtual method that must be implemented by derived classes. Sets the value of the output (true for high, false for low).
 *      virtual void toggleValor() = 0:
 *                               Pure virtual method that must be implemented by derived classes. Toggles the current value of the output.
 *
 * @param None
 */

#ifndef SALIDA_H_
#define SALIDA_H_

class salida {

public:
	salida();
	virtual void setValor( bool ) = 0;
	virtual void toggleValor ( ) = 0;
};
#endif /* SALIDA_H_ */
