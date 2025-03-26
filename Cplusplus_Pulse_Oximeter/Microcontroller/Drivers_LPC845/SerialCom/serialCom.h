/*
 * serialCom.h
 *
 *  Created on: September 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

/* ESP
 * @brief Aquí tenemos los includes y la declaración de la clase `serialCom`, que implementa la comunicación serie utilizando UART.
 *        Esta clase maneja buffers circulares para transmisión (TX) y recepción (RX), junto con la configuración del bitrate y pines UART.
 *
 *      **Variables**
 *
 *      bufTx:        Objeto de la clase `bufferCirc`, utilizado como buffer circular para los datos de transmisión (TX).
 *      bufRx:        Objeto de la clase `bufferCirc`, utilizado como buffer circular para los datos de recepción (RX).
 *      baudrate:     Variable de tipo `uint32_t` que almacena la velocidad de transmisión en bits por segundo (bitrate).
 *      n_uart:       Variable de tipo `uint8_t` que almacena el número del módulo UART configurado.
 *      dir_uart:     Puntero a `USART_Type`, utilizado para apuntar al registro del módulo UART configurado.
 *
 *      **Constantes**
 *
 *      cant_uarts:   Variable estática de tipo `uint8_t` que almacena la cantidad de instancias UART creadas.
 *
 *      **Métodos**
 *
 *      serialCom(uint32_t baudR = 9600, uint8_t pinTx = 25, uint8_t pinRx = 24):
 *                   Constructor de la clase. Inicializa una instancia UART con un bitrate especificado (por defecto, 9600 bps) y pines predeterminados (P0.25 para TX, P0.24 para RX).
 *
 *      uint32_t getBaudR():
 *                   Método para obtener la velocidad de transmisión configurada (bitrate).
 *
 *      void setBaudR(uint32_t):
 *                   Método para configurar la velocidad de transmisión (bitrate).
 *
 *      void Transmitir(uint8_t):
 *                   Método para transmitir un byte por el puerto UART configurado.
 *
 *      void Transmitir(uint8_t *, uint8_t):
 *                   Método para transmitir múltiples bytes (un array) por el puerto UART configurado.
 *
 *      void Transmitir_decimal(int32_t numero):
 *                   Método para transmitir un número decimal (int32_t) convertido a su representación ASCII por el puerto UART.
 *
 *      int16_t Recibir():
 *                   Método para recibir un byte desde el puerto UART configurado. Si no hay datos disponibles, devuelve un valor negativo.
 *
 *      **Funciones Amigas**
 *
 *      UART0_IRQHandler(void), UART1_IRQHandler(void), UART2_IRQHandler(void), UART3_IRQHandler(void):
 *                   Estas funciones son manejadoras de interrupción para los módulos UART. Son funciones amigas de la clase para permitir el acceso
 *                   directo a los métodos internos `setRxData` y `getTxData`.
 *
 *      **Funciones de Interrupción Externas**
 *
 *      UART0_IRQHandler(void), UART1_IRQHandler(void), UART2_IRQHandler(void), UART3_IRQHandler(void):
 *                   Declaración de las funciones manejadoras de interrupciones UART en un bloque `extern "C"` para asegurar compatibilidad con código C
 *                   al utilizar esta clase en entornos en C++.
 *
 * @param Ninguno
 */

/* ENG
 * @brief Here we have the includes and the declaration of the `serialCom` class, which implements serial communication using UART.
 *        This class manages circular buffers for transmission (TX) and reception (RX), along with UART bitrate and pin configuration.
 *
 *      **Variables**
 *
 *      bufTx:        Instance of the `bufferCirc` class, used as a circular buffer for transmission (TX) data.
 *      bufRx:        Instance of the `bufferCirc` class, used as a circular buffer for reception (RX) data.
 *      baudrate:     `uint32_t` variable that stores the transmission speed in bits per second (bitrate).
 *      n_uart:       `uint8_t` variable that stores the UART module number being configured.
 *      dir_uart:     Pointer to `USART_Type`, used to point to the configured UART module register.
 *
 *      **Constants**
 *
 *      cant_uarts:   Static `uint8_t` variable that stores the number of UART instances created.
 *
 *      **Methods**
 *
 *      serialCom(uint32_t baudR = 9600, uint8_t pinTx = 25, uint8_t pinRx = 24):
 *                   Class constructor. Initializes a UART instance with a specified bitrate (default is 9600 bps) and default pins (P0.25 for TX, P0.24 for RX).
 *
 *      uint32_t getBaudR():
 *                   Method to get the configured transmission speed (bitrate).
 *
 *      void setBaudR(uint32_t):
 *                   Method to set the transmission speed (bitrate).
 *
 *      void Transmitir(uint8_t):
 *                   Method to transmit a single byte through the configured UART port.
 *
 *      void Transmitir(uint8_t *, uint8_t):
 *                   Method to transmit multiple bytes (an array) through the configured UART port.
 *
 *      void Transmitir_decimal(int32_t numero):
 *                   Method to transmit a decimal number (int32_t) as its ASCII representation through the UART port.
 *
 *      int16_t Recibir():
 *                   Method to receive a single byte from the configured UART port. If no data is available, it returns a negative value.
 *
 *      **Friend Functions**
 *
 *      UART0_IRQHandler(void), UART1_IRQHandler(void), UART2_IRQHandler(void), UART3_IRQHandler(void):
 *                   These are interrupt handler functions for UART modules. They are friends of the class to allow direct access
 *                   to the internal methods `setRxData` and `getTxData`.
 *
 *      **External Interrupt Functions**
 *
 *      UART0_IRQHandler(void), UART1_IRQHandler(void), UART2_IRQHandler(void), UART3_IRQHandler(void):
 *                   Declaration of UART interrupt handler functions in an `extern "C"` block to ensure compatibility with C code
 *                   when using this class in C++ environments.
 *
 * @param None
 */

#ifndef SERIALCOM_H_
#define SERIALCOM_H_

#include "../LPC845.h"
#include "bufferCirc.h"

#if defined (__cplusplus)
extern "C" {

void UART0_IRQHandler (void);
void UART1_IRQHandler (void);
void UART2_IRQHandler (void);
void UART3_IRQHandler (void);

}
#endif

class serialCom {

	private:
		bufferCirc bufTx;
		bufferCirc bufRx;
		uint32_t baudrate;
		uint8_t n_uart;
		USART_Type * dir_uart;

	public:
		static uint8_t cant_uarts;
		serialCom( uint32_t baudR = 9600 , uint8_t pinTx = 25 , uint8_t pinRx = 24 );
		uint32_t getBaudR();
		void setBaudR ( uint32_t );

		void Transmitir ( uint8_t );
		void Transmitir ( uint8_t *, uint8_t );
		void Transmitir_decimal(int32_t numero);
		int16_t Recibir ();

		friend void UART0_IRQHandler (void);
		friend void UART1_IRQHandler (void);
		friend void UART2_IRQHandler (void);
		friend void UART3_IRQHandler (void);
};

#endif /* SERIALCOM_H_ */
