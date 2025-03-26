/*
 * gpio_in.h
 *
 *  Created on: 20 may. 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

/* ESP
 * @brief Aquí tenemos la declaración de la clase `gpio_in`, que hereda de la clase abstracta `entrada`.
 *        Esta clase maneja la configuración y lectura de un pin GPIO como entrada, permitiendo configurar el modo de resistencia pull-up/pull-down.
 *
 *      **Variables Privadas**
 *
 *      port:   Variable de tipo `uint8_t` que almacena el número de puerto GPIO.
 *      pin:    Variable de tipo `uint8_t` que almacena el número de pin GPIO.
 *      error:  Variable booleana que indica si ha ocurrido un error en la configuración o lectura del pin.
 *
 *      **Constantes Públicas Estáticas**
 *
 *      iocon_index[2][32]:  Matriz que mapea puertos y pines a índices de configuración IOCON.
 *      MODE_NONE:           Constante que representa el modo sin resistencia pull-up/pull-down.
 *      MODE_PULLDOWN:       Constante que representa el modo con resistencia pull-down.
 *      MODE_PULLUP:         Constante que representa el modo con resistencia pull-up.
 *      MODE_REPEAT:         Constante que representa el modo con resistencia repetida (no común en todos los microcontroladores).
 *
 *      **Métodos Públicos**
 *
 *      gpio_in(uint8_t _port, uint8_t _pin, uint8_t modo = MODE_PULLUP):
 *                   Constructor de la clase. Inicializa el pin GPIO como entrada con el modo especificado (por defecto, pull-up).
 *      void setDir():
 *                   Método que configura la dirección del pin como entrada.
 *      void setMODE(uint8_t):
 *                   Método que configura el modo de resistencia del pin (pull-up, pull-down, etc.).
 *      bool getValor() const:
 *                   Método que devuelve el valor actual del pin GPIO (true o false).
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the declaration of the `gpio_in` class, which inherits from the abstract class `entrada`.
 *        This class handles the configuration and reading of a GPIO pin as an input, allowing the configuration of pull-up/pull-down resistor modes.
 *
 *      **Private Variables**
 *
 *      port:   `uint8_t` variable that stores the GPIO port number.
 *      pin:    `uint8_t` variable that stores the GPIO pin number.
 *      error:  Boolean variable that indicates if an error has occurred during pin configuration or reading.
 *
 *      **Public Static Constants**
 *
 *      iocon_index[2][32]:  Matrix that maps ports and pins to IOCON configuration indices.
 *      MODE_NONE:           Constant representing the mode without pull-up/pull-down resistors.
 *      MODE_PULLDOWN:       Constant representing the mode with pull-down resistors.
 *      MODE_PULLUP:         Constant representing the mode with pull-up resistors.
 *      MODE_REPEAT:         Constant representing the mode with repeated resistors (not common in all microcontrollers).
 *
 *      **Public Methods**
 *
 *      gpio_in(uint8_t _port, uint8_t _pin, uint8_t modo = MODE_PULLUP):
 *                   Class constructor. Initializes the GPIO pin as an input with the specified mode (default is pull-up).
 *      void setDir():
 *                   Method that configures the pin direction as input.
 *      void setMODE(uint8_t):
 *                   Method that configures the pin resistor mode (pull-up, pull-down, etc.).
 *      bool getValor() const:
 *                   Method that returns the current value of the GPIO pin (true or false).
 *
 * @param None
 */

#ifndef GPIO_IN_H_
#define GPIO_IN_H_

#include "entrada.h"
#include "../LPC845.h"

class gpio_in : public entrada {

	private:
		uint8_t port;
		uint8_t pin;
		bool error;

	public:


		static const uint8_t iocon_index[2][32];

		static const uint8_t MODE_NONE = 0;
		static const uint8_t MODE_PULLDOWN = 1;
		static const uint8_t MODE_PULLUP = 2;
		static const uint8_t MODE_REPEAT = 3;


		gpio_in( uint8_t _port , uint8_t _pin , uint8_t modo = MODE_PULLUP );
		void setDir();
		void setMODE( uint8_t );
		bool getValor() const;

};

#endif /* GPIO_IN_H_ */
