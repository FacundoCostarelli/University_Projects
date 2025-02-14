/*
 * MdeMAX30102.h
 *
 *  Created on: October 2024
 *      Author: Facundo Costarelli & Ezequiel Lagatche
 */

/* ESP
 * @brief Aquí tenemos los includes y la declaración de la class que maneja la máquina de estados de la aplicación del sistema.
 *
 *		**Variables**
 *
 * 		transactions: 	enum que guarda los estados de la máquina de estados.
 * 		MUESTRA_VAL: 	etiqueta macro que guarda la cantidad de muestras a procesar.
 * 		sensor: 		objeto de class MAX30102 asociado al módulo de hardware correspondiente.
 * 		wifi: 			puntero a objeto de class ESP8266 asociado al módulo de hardware correspondiente.
 * 		valores_hr: 	vector tipo int32_t de tamanio MUESTRA_VAL. Almacena las muestras de "heart rate" procesadas por el sensor MAX30102.
 * 		valores_spo2: 	vector tipo int32_t de tamanio MUESTRA_VAL. Almacena las muestras de "spo2" procesadas por el sensor MAX30102.
 * 		indice_hr: 		variable asociada al indice que recorre el vector valores_hr.
 * 		indice_spo2: 	variable asociada al indice que recorre el vector valores_spo2.
 *
 *		**Métodos**
 *
 *		Max30102StateMachine(ESP8266 *module_wifi): 	método asociado con el constructor de la clase.
 *
 *		void Mde_MAX30102(void);						método asociado con la máquina de estados. Es la función de aplicación principal del sistema.
 *
 *		int32_t promediar_valores(int32_t valores[]);   método que realiza un promedio ponderado de los vectores valores_hr y valores_spo2.
 *
 * @param Ninguno
 *
 */

/* ENG
 * @brief Here we have the includes and the declaration of the class that manages the state machine of the system application.
 *
 *		**Variables**
 *
 * 		transactions: 	enum that saves the states of the state machine.
 * 		SAMPLE_VAL: 	macro label that stores the number of samples to process.
 * 		sensor: 		MAX30102 class object associated with the corresponding hardware module.
 * 		*wifi: 			pointer to ESP8266 class object associated with the corresponding hardware module.
 * 		hr_values: 		vector type int32_t of size SAMPLE_VAL. Stores the heart rate samples processed by the MAX30102 sensor.
 * 		spo2_values: 	vector type int32_t of size SAMPLE_VAL. Stores the "spo2" samples processed by the MAX30102 sensor.
 * 		hr_index: 		variable associated with the index that runs through the hr_values ​​vector.
 * 		spo2_index: 	variable associated with the index that runs through the spo2_values ​​vector.
 *
 *		**Methods**
 *
 *		Max30102StateMachine(ESP8266 *module_wifi):		method associated with the class constructor.
 *
 *		void Mde_MAX30102(void):						method associated with the state machine. It is the main application function of the system.
 *
 *	 	int32_t promediar_valores(int32_t valores[]): 	method that performs a weighted average of the vectors hr_values ​​and spo2_values.
 *
 * @param None
 *
 */


#ifndef MDEMAX30102_H_
#define MDEMAX30102_H_

#include <dr_init/DR_Init.h>
#include <ESP8266.h>
#include <LPC845.h>
#include <pinInt/PinInt.h>
#include <Timer.h>
#include <gpio/gpio_out.h>
#include <gpio/gpio_in.h>
#include <I2C/I2C.h>
#include <MAX30102.h>
#include <serialCom.h>

enum transactions{FIRST_TRANSACTION,SECOND_TRANSACTION};

#define MUESTRA_VAL 60

 class Max30102StateMachine {
 private:
	MAX30102 sensor;
	ESP8266 *wifi;
	int32_t valores_hr[MUESTRA_VAL];
	int32_t valores_spo2[MUESTRA_VAL];
	uint8_t indice_spo2;
	uint8_t indice_hr;

 public:
	Max30102StateMachine(ESP8266 *module_wifi);
	void Mde_MAX30102(void);
	int32_t promediar_valores(int32_t valores[]);
};


#endif /* MDEMAX30102_H_ */
