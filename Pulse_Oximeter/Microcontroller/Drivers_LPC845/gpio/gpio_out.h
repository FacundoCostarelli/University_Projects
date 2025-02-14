/*
 * gpio_out.h
 *
 *  Created on: 20 may. 2024
 *      Author: Jorge Escola
 */

/* ESP
 * @brief Aquí tenemos la declaración de la clase `gpio_out`, que hereda de la clase abstracta `salida`.
 *        Esta clase maneja la configuración y control de un pin GPIO como salida, permitiendo configurar el modo de drenador abierto (open-drain) y establecer su valor.
 *
 *      **Variables Privadas**
 *
 *      port:   Variable de tipo `uint8_t` que almacena el número de puerto GPIO.
 *      pin:    Variable de tipo `uint8_t` que almacena el número de pin GPIO.
 *      error:  Variable booleana que indica si ha ocurrido un error en la configuración o escritura del pin.
 *
 *      **Constantes Públicas Estáticas**
 *
 *      iocon_index[2][32]:  Matriz que mapea puertos y pines a índices de configuración IOCON.
 *      MODE_OD_OFF:         Constante que representa el modo de drenador abierto desactivado (push-pull).
 *      MODE_OD_ON:          Constante que representa el modo de drenador abierto activado.
 *
 *      **Métodos Públicos**
 *
 *      gpio_out(uint8_t _port, uint8_t _pin, uint8_t modo = MODE_OD_OFF):
 *                   Constructor de la clase. Inicializa el pin GPIO como salida con el modo especificado (por defecto, drenador abierto desactivado).
 *      void setDir():
 *                   Método que configura la dirección del pin como salida.
 *      void setMODE(uint8_t):
 *                   Método que configura el modo de drenador abierto del pin.
 *      void setValor(bool val):
 *                   Método que establece el valor del pin GPIO (true para alto, false para bajo).
 *      void toggleValor():
 *                   Método que invierte el valor actual del pin GPIO.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the declaration of the `gpio_out` class, which inherits from the abstract class `salida`.
 *        This class handles the configuration and control of a GPIO pin as an output, allowing the configuration of open-drain mode and setting its value.
 *
 *      **Private Variables**
 *
 *      port:   `uint8_t` variable that stores the GPIO port number.
 *      pin:    `uint8_t` variable that stores the GPIO pin number.
 *      error:  Boolean variable that indicates if an error has occurred during pin configuration or writing.
 *
 *      **Public Static Constants**
 *
 *      iocon_index[2][32]:  Matrix that maps ports and pins to IOCON configuration indices.
 *      MODE_OD_OFF:         Constant representing the open-drain mode disabled (push-pull).
 *      MODE_OD_ON:          Constant representing the open-drain mode enabled.
 *
 *      **Public Methods**
 *
 *      gpio_out(uint8_t _port, uint8_t _pin, uint8_t modo = MODE_OD_OFF):
 *                   Class constructor. Initializes the GPIO pin as an output with the specified mode (default is open-drain disabled).
 *      void setDir():
 *                   Method that configures the pin direction as output.
 *      void setMODE(uint8_t):
 *                   Method that configures the open-drain mode of the pin.
 *      void setValor(bool val):
 *                   Method that sets the value of the GPIO pin (true for high, false for low).
 *      void toggleValor():
 *                   Method that toggles the current value of the GPIO pin.
 *
 * @param None
 */

#ifndef GPIO_OUT_H_
#define GPIO_OUT_H_

#include "salida.h"
#include "../LPC845.h"

class gpio_out : public salida{

	private:
		uint8_t port;
		uint8_t pin;
		bool error;

	public:

		static const uint8_t iocon_index[2][32];

		static const uint8_t MODE_OD_OFF = 0;
		static const uint8_t MODE_OD_ON = 1;

		gpio_out( uint8_t _port , uint8_t _pin , uint8_t modo = MODE_OD_OFF );
		void setDir();
		void setMODE( uint8_t );
		void setValor( bool val);
		void toggleValor ( );

};

#endif /* GPIO_OUT_H_ */
