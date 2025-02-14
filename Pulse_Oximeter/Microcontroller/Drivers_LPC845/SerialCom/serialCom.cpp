/*
 * serialCom.cpp
 *
 *  Created on: September 2024
 *      Author: Jorge Escola & Mariana Prieto Canalejo
 */

#include "serialCom.h"

/* ESP
 * @brief Inicialización de la variable estática `cant_uarts` para contar los objetos `serialCom` creados.
 */

/* ENG
 * @brief Static variable initialization `cant_uarts` to count the created `serialCom` objects.
 */

uint8_t serialCom::cant_uarts = 0;

/* ESP
 * @brief Array de punteros a objetos `serialCom`. Este array se utiliza para manejar las diferentes UARTs disponibles.
 *        Se inicializa con espacio para 4 UARTs.
 */

/* ENG
 * @brief Array of pointers to `serialCom` objects. This array handles the available UARTs.
 *        Initialized with space for 4 UARTs.
 */

serialCom ** uarts = new serialCom*[4];




/* ESP
 * @brief Constructor de la clase `serialCom`.
 *        Configura una nueva UART, asigna su dirección y establece el baudrate, pines de transmisión y recepción.
 *
 * @param baudR Baudrate de la UART.
 * @param pinTx Pin asignado para transmisión.
 * @param pinRx Pin asignado para recepción.
 */

/* ENG
 * @brief Constructor for the `serialCom` class.
 *        Configures a new UART, assigns its address, and sets the baudrate, transmission, and reception pins.
 *
 * @param baudR UART baudrate.
 * @param pinTx Pin assigned for transmission.
 * @param pinRx Pin assigned for reception.
 */

serialCom::serialCom( uint32_t baudR , uint8_t pinTx , uint8_t pinRx ):bufTx(255),bufRx(255)
{
	// ESP: Cargar el número de UART creada antes de la construcción del objeto.
	// ENG: Load the number of UARTs created before constructing the object.
	n_uart = cant_uarts;

	// ESP: Almacenar la dirección del objeto en el array global de punteros `uarts`.
	// ENG: Store the object's address in the global pointer array `uarts`.
	uarts[n_uart] = this;

	 // ESP: Incrementar el contador global de UARTs.
	 // ENG: Increment the global UART counter.
	cant_uarts++;

	// ESP: Guardar el baudrate en la variable miembro.
	// ENG: Store the baudrate in the member variable.
	baudrate = baudR;

	// ESP: Habilitar el reloj de la UART correspondiente.
	// ENG: Enable the clock for the corresponding UART.
	uint8_t shift = 14 + n_uart;
	SYSCON->SYSAHBCLKCTRL0 |= (1 << shift);

	// ESP: Resetear la UART correspondiente.
	// ENG: Reset the corresponding UART.
	SYSCON->PRESETCTRL0 &= ~(1<<shift);
	SYSCON->PRESETCTRL0 |= (1<<shift);

	// ESP: Habilitar el reloj para la matriz de conmutación (Switch Matrix).
	// ENG: Enable the clock for the Switch Matrix.
	SYSCON->SYSAHBCLKCTRL0 |= (1<<7);

	// ESP: Configurar los pines de transmisión y recepción según la UART seleccionada.
	// ENG: Configure transmission and reception pins based on the selected UART.
	switch ( n_uart)
	{
		case 0:
			SWM0->PINASSIGN_DATA[0] &= ~(0x0000FFFF);
			SWM0->PINASSIGN_DATA[0] |= (pinTx << 0) | (pinRx << 8);
			dir_uart = USART0;//ESP: Dirección de la UART0. ENG: Direction of UART0.
			break;
		case 1:
			SWM0->PINASSIGN_DATA[1] &= ~(0x00FFFF00);
			SWM0->PINASSIGN_DATA[1] |= (pinTx << 8) | (pinRx << 16);
			dir_uart = USART1;//ESP: Dirección de la UART1. ENG: Direction of UART1.
			break;
		case 2:
			SWM0->PINASSIGN_DATA[2] &= ~(0xFFFF0000);
			SWM0->PINASSIGN_DATA[2] |= (pinTx << 16) | (pinRx << 24);
			dir_uart = USART2;//ESP: Dirección de la UART2. ENG: Direction of UART2.
			break;

		case 3:
			SWM0->PINASSIGN_DATA[11] &= ~(0xFF000000);
			SWM0->PINASSIGN_DATA[12] &= ~(0x000000FF);
			SWM0->PINASSIGN_DATA[11] |= (pinTx << 24);
			SWM0->PINASSIGN_DATA[12] |= pinRx;
			dir_uart = USART3;//ESP: Dirección de la UART3. ENG: Direction of UART3.
			break;
	}

	// ESP: Configuración general de la UART.
	// ENG: General UART configuration
	dir_uart->CFG = 	(0 << 0)		// 0=DISABLE 1=ENABLE
						| (1 << 2)		// 0=7BITS 1=8BITS 2=9BITS
						| (0 << 4)		// 0=NOPARITY 2=PAR 3=IMPAR
						| (0 << 6)		// 0=1BITSTOP 1=2BITSTOP
						| (0 << 9)		// 0=NOFLOWCONTROL 1=FLOWCONTROL
						| (0 << 11);	// 0=ASINCRONICA 1=SINCRONICA

	// ESP: Configurar interrupciones de recepción para la UART.
	// ENG: Configure reception interrupts for the UART.
	dir_uart->INTENSET = (1 << 0);

	// ESP: Configuración del baudrate.
	// ENG: Baudrate configuration.
	//CLK = FRO = 30MHz
	if ( n_uart == 0 )
		UART0CLKSEL = 0;
	else if ( n_uart == 1 )
		UART1CLKSEL = 0;
	else if ( n_uart == 2 )
		UART2CLKSEL = 0;
	else if ( n_uart == 3 )
		UART3CLKSEL = 0;

	dir_uart->BRG = (30000000 / (baudrate* 16));

	// ESP: Habilitar interrupciones en el NVIC para la UART seleccionada.
	// ENG: Enable NVIC interrupts for the selected UART.
	shift = 3 + n_uart;
	ISER0 |= (1 << shift);

	// ESP: Habilitar la UART.
	// ENG: Enable the UART.
	dir_uart->CFG |= 1;
}




/* ESP
 * @brief Obtiene el baudrate actual de la UART.
 *
 * @return El baudrate configurado.
 */

/* ENG
 * @brief Gets the current UART baudrate.
 *
 * @return The configured baudrate.
 */

uint32_t serialCom::getBaudR()
{
	return baudrate;

}




/* ESP
 * @brief Configura un nuevo baudrate para la UART.
 *
 * @param br Nuevo baudrate a configurar.
 */

/* ENG
 * @brief Sets a new baudrate for the UART.
 *
 * @param br New baudrate to configure.
 */

void serialCom::setBaudR ( uint32_t br)
{
	baudrate = br;

	// ESP: Reconfigurar el baudrate en el registro de configuración.
	// ENG: Reconfigure the baudrate in the configuration register.
	dir_uart->BRG = (30000000 / (baudrate* 16));
}




/* ESP
 * @brief Transmite un dato individual usando el buffer circular y la UART.
 *
 * @param dato Dato a transmitir.
 */

/* ENG
 * @brief Transmits a single data value using the circular buffer and UART.
 *
 * @param dato Data to transmit.
 */

void serialCom::Transmitir( uint8_t dato )
{
	// ESP: Agregar el dato al buffer circular.
	// ENG: Data is added into the circular buffer.
	bufTx.push(dato);

	// ESP: Habilitar interrupción de transmisión.
	// ENG: Enable of transmission interruption.
	dir_uart->INTENSET |= 1<<2;
}




/* ESP
 * @brief Transmite múltiples datos desde un buffer usando el buffer circular.
 *
 * @param buf Buffer con los datos a transmitir.
 * @param cant Cantidad de datos a transmitir.
 */

/* ENG
 * @brief Transmits multiple data values from a buffer using the circular buffer.
 *
 * @param buf Buffer containing data to transmit.
 * @param cant Number of data values to transmit.
 */

void serialCom::Transmitir ( uint8_t *buf , uint8_t cant )
{
	uint8_t i = 0;
	if(cant == 0){
		while(buf[i]){
			bufTx.push((uint8_t)buf[i]);
			i++;
		}
	} else {
		for ( int i = 0 ; i < cant ; i++ )
			bufTx.push(buf[i]);
	}

	dir_uart->INTENSET |= 1<<2;
}




/* ESP
 * @brief Recibe un dato del buffer circular de recepción.
 *
 * @return El dato recibido o un valor de error si no hay datos disponibles.
 */

/* ENG
 * @brief Receives a data value from the reception circular buffer.
 *
 * @return The received data or an error value if no data is available.
 */

int16_t serialCom::Recibir ()
{
	return bufRx.pop();
}




/* ESP
 * @brief Transmite un número decimal como una cadena de caracteres ASCII.
 *
 * @param numero Número a transmitir.
 */

/* ENG
 * @brief Transmits a decimal number as an ASCII character string.
 *
 * @param numero Number to transmit.
 */

void serialCom::Transmitir_decimal(int32_t numero){
	// ESP: Calculo la cantidad de digitos del numero a descomponer.
	// ENG: I calculate the number of digits of the number to be decomposed.
	uint8_t cant_digitos = 0;
	if(numero == 0){
		cant_digitos = 1;
	} else {
		int32_t numero_aux = numero;

		while (numero_aux > 0) {
			numero_aux /= 10;
			cant_digitos++;
		}
	}

	// ESP: Paso de numero a array de numeros. Array para almacenar cada dígito del número (máximo 3 posiciones para un uint8_t)
	// ENG: Passage from number to array of numbers. Array to store each digit of the number (maximum 3 positions for a uint8_t)
	uint8_t digitos_numero[cant_digitos];

	// ESP: Indice de iteración para convertir un numero en digitos almacenados en un array.
	// ENG: Iteration index to convert a number into digits stored in an array.
	int indice = cant_digitos-1;
    do {
    	// ESP: Extrae el último dígito y lo guarda.
    	// ENG: Extracts the last digit and saves it.
	    digitos_numero[indice--] = numero % 10;

	    // ESP: Elimina el último dígito del número.
	    // ENG: Remove the last digit of the number.
	    numero /= 10;

    } while (numero > 0 && indice >= 0);

    // ESP: Casteo digito por digito a ASCII.
    // ENG: Digit-by-digit casting to ASCII.
    for(uint8_t i = 0; i< cant_digitos; i++){
    	digitos_numero[i] = digitos_numero[i] + '0';
    }

  // ESP: Transmito por puerto serie el array de digitos.
  // ENG: I transmit the digit array via serial port.
  Transmitir(digitos_numero, cant_digitos);

}




/* ESP
 * @brief Manejador de interrupción para la UART0.
 *        Gestiona recepción, transmisión y manejo de errores.
 */

/* ENG
 * @brief Interrupt handler for UART0.
 *        Manages reception, transmission, and error handling.
 */

void UART0_IRQHandler (void)
{
	// ESP: Obtengo el estado de la UART0.
	// ENG: Get the status of UART0.
	uint32_t stat = USART0->STAT;
	int16_t dato;

	// ESP: Caso de recepción de datos.
	// ENG: Case for data reception.
	if(stat & (1 << 0))
	{
		// ESP: Leo el dato recibido.
		// ENG: Read the received data.
		uint8_t valor_rx = (uint8_t)USART0->RXDAT;

		// ESP: Almaceno el dato en el buffer circular de recepción.
		// ENG: Store the data in the reception circular buffer.
		uarts[0]->bufRx.push(valor_rx);
	}

	// ESP: Caso de transmisión de datos.
	// ENG: Case for data transmission.
	if(stat & (1 << 2))
	{
		// ESP: Extraigo el siguiente dato a transmitir del buffer circular.
		// ENG: Extract the next data to transmit from the circular buffer.
		dato = uarts[0]->bufTx.pop();

		// ESP: Transmito el dato si está disponible.
		// ENG: Transmit the data if available.
		if ( dato != (bufferCirc::NO_DATA) )
			USART0->TXDAT = dato;
		else
			// ESP: Deshabilito la interrupción si no hay más datos.
			// ENG: Disable the interrupt if no more data is available.
			USART0->INTENCLR |= 1<<2;
	}

	// ESP: Caso de errores (pendiente de implementar).
	// ENG: Case for errors (pending implementation).
	else
	{

	}
}




/* ESP
 * @brief Manejador de interrupción para la UART1.
 *        Gestiona recepción, transmisión y manejo de errores.
 */

/* ENG
 * @brief Interrupt handler for UART1.
 *        Manages reception, transmission, and error handling.
 */

void UART1_IRQHandler (void)
{
	// ESP: Obtengo el estado de la UART1.
	// ENG: Get the status of UART1.
	uint32_t stat = USART1->STAT;
	int16_t dato;

	// ESP: Caso de recepción de datos.
	// ENG: Case for data reception.
	if(stat & (1 << 0))
	{
		// ESP: Leo el dato recibido.
		// ENG: Read the received data.
		uint8_t valor_rx = (uint8_t)USART1->RXDAT;

		// ESP: Almaceno el dato en el buffer circular de recepción.
		// ENG: Store the data in the reception circular buffer.
		uarts[1]->bufRx.push(valor_rx);
	}

	// ESP: Caso de transmisión de datos.
	// ENG: Case for data transmission.
	if(stat & (1 << 2))
	{
		// ESP: Extraigo el siguiente dato a transmitir del buffer circular.
		// ENG: Extract the next data to transmit from the circular buffer.
		dato = uarts[1]->bufTx.pop();

		// ESP: Transmito el dato si está disponible.
		// ENG: Transmit the data if available.
		if ( dato != (bufferCirc::NO_DATA) )
			USART1->TXDAT = dato;
		else
			// ESP: Deshabilito la interrupción si no hay más datos.
			// ENG: Disable the interrupt if no more data is available.
			USART1->INTENCLR |= 1<<2;
	}

	// ESP: Caso de errores (pendiente de implementar).
	// ENG: Case for errors (pending implementation).
	else
	{

	}

}




/* ESP
 * @brief Manejador de interrupción para la UART2.
 *        Gestiona recepción, transmisión y manejo de errores.
 */

/* ENG
 * @brief Interrupt handler for UART2.
 *        Manages reception, transmission, and error handling.
 */

void UART2_IRQHandler (void)
{
	// ESP: Obtengo el estado de la UART2.
	// ENG: Get the status of UART2.
	uint32_t stat = USART2->STAT;
	int16_t dato;

	// ESP: Caso de recepción de datos.
	// ENG: Case for data reception.
	if(stat & (1 << 0))
	{
		// ESP: Leo el dato recibido.
		// ENG: Read the received data.
		uint8_t valor_rx = (uint8_t)USART2->RXDAT;

		// ESP: Almaceno el dato en el buffer circular de recepción.
		// ENG: Store the data in the reception circular buffer.
		uarts[2]->bufRx.push(valor_rx);
	}

	// ESP: Caso de transmisión de datos.
	// ENG: Case for data transmission.
	if(stat & (1 << 2))
	{
		// ESP: Extraigo el siguiente dato a transmitir del buffer circular.
		// ENG: Extract the next data to transmit from the circular buffer.
		dato = uarts[2]->bufTx.pop();

		// ESP: Transmito el dato si está disponible.
		// ENG: Transmit the data if available.
		if ( dato != (bufferCirc::NO_DATA) )
			USART2->TXDAT = dato;
		else
			// ESP: Deshabilito la interrupción si no hay más datos.
			// ENG: Disable the interrupt if no more data is available.
			USART2->INTENCLR |= 1<<2;
	}

	// ESP: Caso de errores (pendiente de implementar).
	// ENG: Case for errors (pending implementation).
	else
	{

	}

}

void UART3_IRQHandler (void)
{
	// ESP: Obtengo el estado de la UART3.
	// ENG: Get the status of UART3.
	uint32_t stat = USART3->STAT;
	int16_t dato;

	// ESP: Caso de recepción de datos.
	// ENG: Case for data reception.
	if(stat & (1 << 0))
	{
		// ESP: Leo el dato recibido.
		// ENG: Read the received data.
		uint8_t valor_rx = (uint8_t)USART3->RXDAT;

		// ESP: Almaceno el dato en el buffer circular de recepción.
		// ENG: Store the data in the reception circular buffer.
		uarts[3]->bufRx.push(valor_rx);
	}

	// ESP: Caso de transmisión de datos.
	// ENG: Case for data transmission.
	if(stat & (1 << 2))
	{
		// ESP: Extraigo el siguiente dato a transmitir del buffer circular.
		// ENG: Extract the next data to transmit from the circular buffer.
		dato = uarts[3]->bufTx.pop();

		// ESP: Transmito el dato si está disponible.
		// ENG: Transmit the data if available.
		if ( dato != (bufferCirc::NO_DATA) )
			USART3->TXDAT = dato;
		else
			// ESP: Deshabilito la interrupción si no hay más datos.
			// ENG: Disable the interrupt if no more data is available.
			USART3->INTENCLR |= 1<<2;
	}

	// ESP: Caso de errores (pendiente de implementar).
	// ENG: Case for errors (pending implementation).
	else
	{

	}

}

