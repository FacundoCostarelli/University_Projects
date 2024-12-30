/*
 * serialCom.h
 *
 *  Created on: 10 sep. 2023
 *      Author: chor
 */

#ifndef SERIALCOM_H_
#define SERIALCOM_H_

#include "../LPC845.h"
#include "bufferCirc.h"

//Funciones de interrupcion de UART
#if defined (__cplusplus)
extern "C" {

void UART0_IRQHandler (void);
void UART1_IRQHandler (void);
void UART2_IRQHandler (void);
void UART3_IRQHandler (void);

}
#endif

//La class serialCom utiliza "composicion" de objetos de class bufferCirc
class serialCom {

	//Buffer Circular para TX
	bufferCirc bufTx;
	//Buffer Circula para RX
	bufferCirc bufRx;

	//Variable para almacenar la velocidad de transmision de bits. Es equivalente a bitrate
	uint32_t baudrate;
	//Variable que almacena el nro de modulo uart que se está configurando
	uint8_t n_uart;

	//Uso este puntero para apuntar a la uart que voy a configurar:
	USART_Type * dir_uart;

public:
	//Uso esta variable para ir creando una nueva uart por cada instancia, podría pasar el nro de uart al constructor
	static uint8_t cant_uarts;

	//Por defecto el pin para transmision es el P025 y el de recepcion P0.24:
	serialCom( uint32_t baudR = 9600 , uint8_t pinTx = 25 , uint8_t pinRx = 24 );

	//Leer y configurar la velocidad de comunicacion:
	uint32_t getBaudR();
	void setBaudR ( uint32_t );

	//Transmitir o recibir un byte por el puerto
	void Transmitir ( uint8_t );
	void Transmitir ( uint8_t *, uint8_t );
	void Transmitir_decimal(int32_t numero);
	int16_t Recibir ();

	//Son funciones amigas para poder acceder a los metodos setRxData y getTxData
	friend void UART0_IRQHandler (void);
	friend void UART1_IRQHandler (void);
	friend void UART2_IRQHandler (void);
	friend void UART3_IRQHandler (void);

};

#endif /* SERIALCOM_H_ */
