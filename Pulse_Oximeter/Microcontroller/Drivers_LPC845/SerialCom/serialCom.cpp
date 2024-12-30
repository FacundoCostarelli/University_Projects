/*
 * serialCom.cpp
 *
 *  Created on: 10 sep. 2023
 *      Author: chor
 */

#include "serialCom.h"

//Inicializacion variable static que cuenta la cantidad de objetos UART creados de acuerdo los modulos usados
uint8_t serialCom::cant_uarts = 0;
//Array de punteros a objetos serialCom. Debe tener una cantidad igual a la cantidad de modulos UART disponibles a usar
serialCom ** uarts = new serialCom*[4];


//Constructor
serialCom::serialCom( uint32_t baudR , uint8_t pinTx , uint8_t pinRx ):bufTx(255),bufRx(255)
{
	//Cargo el nro de cantidad de uart creadas hasta al momento previo a la construccion de una nueva uart
	n_uart = cant_uarts;
	//Almaceno la direccion del objeto UART tipo serialCom que estoy construyendo, en el array de punteros a objetos serialCom
	uarts[n_uart] = this;


	//Incremento en 1 la cantidad de uarts creadas, que es lo mismo que la cantidad de objetos serialCom creados
	cant_uarts++;
	//Guardo el bit rate
	baudrate = baudR;

	// HABILITO LA UART:
	uint8_t shift = 14 + n_uart;
	SYSCON->SYSAHBCLKCTRL0 |= (1 << shift);

	//Reseteo la UART:
	SYSCON->PRESETCTRL0 &= ~(1<<shift);
	SYSCON->PRESETCTRL0 |= (1<<shift);

	//Habilito el CLK a la SWM:
	SYSCON->SYSAHBCLKCTRL0 |= (1<<7);

	switch ( n_uart)
	{
		case 0:

			// CONFIGURO LA SWITCH MATRIX
			SWM0->PINASSIGN_DATA[0] &= ~(0x0000FFFF);
			SWM0->PINASSIGN_DATA[0] |= (pinTx << 0) | (pinRx << 8);
			//Seteo la direccion de la uart a configurar
			dir_uart = USART0;
			break;
		case 1:
			// CONFIGURO LA SWITCH MATRIX
			SWM0->PINASSIGN_DATA[1] &= ~(0x00FFFF00);
			SWM0->PINASSIGN_DATA[1] |= (pinTx << 8) | (pinRx << 16);
			//Seteo la direccion de la uart a configurar
			dir_uart = USART1;
			break;
		case 2:
			// CONFIGURO LA SWITCH MATRIX
			SWM0->PINASSIGN_DATA[2] &= ~(0xFFFF0000);
			SWM0->PINASSIGN_DATA[2] |= (pinTx << 16) | (pinRx << 24);
			//Seteo la direccion de la uart a configurar
			dir_uart = USART2;
			break;

		case 3:
			// CONFIGURO LA SWITCH MATRIX
			SWM0->PINASSIGN_DATA[11] &= ~(0xFF000000);
			SWM0->PINASSIGN_DATA[12] &= ~(0x000000FF);
			SWM0->PINASSIGN_DATA[11] |= (pinTx << 24);
			SWM0->PINASSIGN_DATA[12] |= pinRx;
			//Seteo la direccion de la uart a configurar
			dir_uart = USART3;
			break;
	}

	// CONFIGURACION GENERAL
	dir_uart->CFG = 	(0 << 0)		// 0=DISABLE 1=ENABLE
						| (1 << 2)		// 0=7BITS 1=8BITS 2=9BITS
						| (0 << 4)		// 0=NOPARITY 2=PAR 3=IMPAR
						| (0 << 6)		// 0=1BITSTOP 1=2BITSTOP
						| (0 << 9)		// 0=NOFLOWCONTROL 1=FLOWCONTROL
						| (0 << 11);	// 0=ASINCRONICA 1=SINCRONICA

	// CONFIGURACION INTERRUPCIONES
	dir_uart->INTENSET = (1 << 0);	//RX

	// CONFIGURACION DEL BAUDRATE
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

	//Habilito interrupcion USART0 en el NVIC
	shift = 3 + n_uart;
	ISER0 |= (1 << shift);

	// ENABLE LA UART
	dir_uart->CFG |= 1;
}

uint32_t serialCom::getBaudR()
{
	return baudrate;

}

void serialCom::setBaudR ( uint32_t br)
{
	baudrate = br;
	//Reconfiguro Baudrate
	dir_uart->BRG = (30000000 / (baudrate* 16));
}


void serialCom::Transmitir( uint8_t dato )
{
	//Agrego el dato al buffer circular:
	bufTx.push(dato);

	//Transmito el dato por interrupción
	dir_uart->INTENSET |= 1<<2;
}

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
			//Agrego el dato al buffer circular:
			bufTx.push(buf[i]);
	}

	//Transmito el dato por interrupción
	dir_uart->INTENSET |= 1<<2;
}


int16_t serialCom::Recibir ()
{
	return bufRx.pop();
}



void serialCom::Transmitir_decimal(int32_t numero){
	//calculo la cantidad de digitos del numero
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

	//paso de numero a array de numeros
	uint8_t digitos_numero[cant_digitos]; // Array para almacenar cada dígito del número (máximo 3 posiciones para un uint8_t)

	int indice = cant_digitos-1;       // Comienza desde el inicio
    do {
	    digitos_numero[indice--] = numero % 10; // Extrae el último dígito y lo guarda
	    numero /= 10;                      // Elimina el último dígito del número
    } while (numero > 0 && indice >= 0);

    // casteo digito por digito a ASCII
    for(uint8_t i = 0; i< cant_digitos; i++){ //Convierto cada digito en ascii
    	digitos_numero[i] = digitos_numero[i] + '0';
    }

  Transmitir(digitos_numero, cant_digitos);

}


//Funciones de interrupcion:
void UART0_IRQHandler (void)
{
	uint32_t stat = USART0->STAT;
	int16_t dato;

    // CASO RECEPCION
	if(stat & (1 << 0))
	{
		uint8_t valor_rx = (uint8_t)USART0->RXDAT;
		uarts[0]->bufRx.push(valor_rx);//pusheo cada byte recibido en el buffer
	}

	//CASO TRANSMISION
	if(stat & (1 << 2))
	{
		dato = uarts[0]->bufTx.pop();

		if ( dato != (bufferCirc::NO_DATA) )
			USART0->TXDAT = dato;
		else
			USART0->INTENCLR |= 1<<2; // Desactiva la interrupción si no hay más datos
	}

	//CASO ERRORES
	else
	{

	}
}

void UART1_IRQHandler (void)
{
	uint32_t stat = USART1->STAT;
	int16_t dato;

    // CASO RECEPCION
	if(stat & (1 << 0))
	{
		uint8_t valor_rx = (uint8_t)USART1->RXDAT;
		uarts[1]->bufRx.push(valor_rx);
	}

	//CASO TRANSMISION
	if(stat & (1 << 2))
	{
		dato = uarts[1]->bufTx.pop();
		if ( dato != (bufferCirc::NO_DATA) )
			USART1->TXDAT = dato;
		else
			USART1->INTENCLR |= 1<<2;
	}

	//CASO ERRORES
	else
	{

	}

}

void UART2_IRQHandler (void)
{
	uint32_t stat = USART2->STAT;
	int16_t dato;

    // CASO RECEPCION
	if(stat & (1 << 0))
	{
		uint8_t valor_rx = (uint8_t)USART2->RXDAT;
		uarts[2]->bufRx.push(valor_rx);
	}

	//CASO TRANSMISION
	if(stat & (1 << 2))
	{
		dato = uarts[2]->bufTx.pop();
		if ( dato != (bufferCirc::NO_DATA) )
			USART2->TXDAT = dato;
		else
			USART2->INTENCLR |= 1<<2;
	}

	//CASO ERRORES
	else
	{

	}

}

void UART3_IRQHandler (void)
{
	uint32_t stat = USART3->STAT;
	int16_t dato;

    // CASO RECEPCION
	if(stat & (1 << 0))
	{
		uint8_t valor_rx = (uint8_t)USART3->RXDAT;
		uarts[3]->bufRx.push(valor_rx);
	}

	//CASO TRANSMISION
	if(stat & (1 << 2))
	{
		dato = uarts[3]->bufTx.pop();
		if ( dato != (bufferCirc::NO_DATA) )
			USART3->TXDAT = dato;
		else
			USART3->INTENCLR |= 1<<2;
	}

	//CASO ERRORES
	else
	{

	}

}

