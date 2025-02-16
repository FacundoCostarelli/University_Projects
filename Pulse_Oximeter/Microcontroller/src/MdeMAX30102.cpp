/*
 * MdeMAX30102.cpp
 *
 *  Created on: October 2024
 *      Author: Facundo Costarelli
 *
 * ESP
 * @brief 	Según el protocolo I2C no hay encabezador. Solo bit de start, bit de escritura o lectura y bit de stop.
 * 			La maquina de estados responde al pseudocodigo de lectura en la datasheet del sensor MAX30102.
 * 			Los estados son FIRST_TRANSACTION y SECOND_TRANSACTION, se obtienen al estudiar la datasheet del módulo MAX30102.
 * 			El sensor se encuentra tomando muestras en todo momento. Esto lo hace una vez que fue configurado correctamente.
 * 			Este tiene hardware propio que realiza una conversión ADC y filtrado necesario. Las muestras se escriben y leen en buffer.
 * 			Cada muestra está compuesta por 6 bytes donde 3 bytes son los originados por la luz roja y los 3 bytes restantes son
 * 			originados por la luz infrarroja. Cada paquete de dato es de 6 bytes.
 *
 *
 * 			En FIRST_TRANSACTION se pregunta por los indices de los punteros de lectura y escritura de la memoria FIFO para saber
 * 			si ya hay muestras para leer o si hay espacio para escribir la FIFO con nuevas muestras tomadas. En tal caso, si hay
 * 			espacio, se guardan las nuevas muestras en la FIFO  y se verifica la condición de "wrap around".
 * 			Luego pasa al estado de SECOND_TRANSACTION.
 *
 * 			En SECOND_TRANSACTION se verifica si hay muestras disponibles para leer y de ser verdadero, se leen las muestras desde
 * 			la memoria FIFO. La lectura se hace ahora en cantidad de bytes y no de muestras. Recordar que cada muestra es de 6 bytes.
 * 			Se particiona la muestra en 2 partes de 3 bytes cada parte. Así queda una sub-muestra asociada a la onda de luz roja capturada
 * 			y otra para la onda de luz infrarroja capturada. Cada paqute de 3 bytes de cada luz, se guarda en un vector de int32_t (4bytes)
 * 			rellenando el byte restante con 0. Un vector es el asociado a valores dados por el led infrarrojo y el otro a valores
 * 			dados por el led rojo. Luego, se aplica un algoritmo de conversión de dichos bytes de los vectores a valores de SPO2 y Heart Rate.
 *			A posterior, se verifica si luego del algoritmo se obtuvieron valores válidos de SPO2 y Heart Rate; y en tal caso se cargan en vectores
 *			de datos de SPO2 y Heart Rate correspondientemente para así aplicar un segundo algoritmo de filtrado. Este filtrado consiste en obtener
 *			un resultado promedio ponderado de cada vector de datos de SPO2 y Hear Rate por separado. Esto permite mayor fidelidad en las mediciones
 *			realizadas y datos más congruentes con la realidad. Finalmente, se envía por medio de comunicación wifi cada dato de SPO2 y Heart Rate hacia
 *			una computadora tipo PC de escritorio o notebook que los recibe y los muestra en una iterfaz gráfica de QT.
 *
 */

/* ENG
 *@brief    According to the I2C protocol there is no header. Only start bit, write or read bit and stop bit.
 *			The state machine responds to the pseudocode read in the MAX30102 sensor datasheet.
 *			The states are FIRST_TRANSACTION and SECOND_TRANSACTION, they are obtained by studying the datasheet of the MAX30102 module.
 *			The sensor is taking samples at all times. It does this once it has been configured correctly.
 *			This has its own hardware that performs ADC conversion and necessary filtering. Samples are written and read in buffer.
 *			Each sample is made up of 6 bytes where 3 bytes are those caused by the red light and the remaining 3 bytes are
 *			caused by infrared light. Each data packet is 6 bytes.
 *
 *
 *			In FIRST_TRANSACTION, the indexes of the read and write pointers of the FIFO memory are asked to know
 * 			if there are already samples to be read or if there is space to write to FIFO memory with new samples taken.
 * 			In this case, if there is space, the new samples are saved in the FIFO and the "wrap around" condition is verified.
 * 			Then it goes to the SECOND_TRANSACTION state.
 *
 *			SECOND_TRANSACTION checks if there are samples available to read and if true, the samples are read from FIFO memory.
 *			The reading is now done in number of bytes and not samples. Remember that each sample is 6 bytes.
 * 			The sample is partitioned into 2 parts of 3 bytes each part. This leaves a sub-sample associated with the captured red light wave,
 * 			and another for the captured infrared light wave. Each 3-byte package of each light is saved in a vector of int32_t (4bytes)
 * 			filling the remaining byte with 0. One vector is the one associated with values ​​given by the infrared LED and the other with values
 * 			given by the red led. Then, an algorithm is applied to convert said bytes of the vectors to SPO2 and Heart Rate values.
 * 			Next, it is verified if valid SPO2 and Heart Rate values ​​were obtained after the algorithm; and in this case they are loaded into vectors
 * 			SPO2 and Heart Rate data correspondingly in order to apply a second filtering algorithm. This filtering consists of obtaining
 * 			a weighted average result of each separate SPO2 and Hear Rate data vector. This allows for greater fidelity in measurements.
 * 			carried out and data more consistent with reality. Finally, each SPO2 and Heart Rate data is sent via Wi-Fi communication to the
 * 			a desktop or notebook PC type computer that receives them and displays them in a QT graphical interface.
 *
 */




#include "MdeMAX30102.h"

/* ESP
 * @brief Constructor de la clase Max30102StateMachine, se inicializan variables y objetos
 * 		  como: sensor, wifi, indice_spo2 e indice_hr.
 * @param module_wifi puntero al objeto de la clase del modulo wifi
 *
 */

/* ENG
 * @brief Constructor of the Max30102StateMachine class, variables and objects are initialized
 * 		  such as: sensor, wifi, spo2_index and hr_index.
 *
 * @param module_wifi pointer to the wifi module class object
 *
 */

 Max30102StateMachine::Max30102StateMachine(ESP8266 *module_wifi):
 	 sensor(I2C0, mode_t::master, SLAVE_ADDR_MAX30102){
	 wifi= module_wifi;
	 indice_spo2 = 0;
	 indice_hr=0;
 }




/* ESP
 * @brief Maquina de estados para solicitar muestras medidas del sensor MAX30102, leer datos de las muestras, filtrar datos y
 * 		  transmitir la información por medio de WI-FI con el módulo ESP8266.
 *
 * @param Ninguno
 *
 */

/* ENG
 * @brief State machine to request measured samples from the MAX30102 sensor, read data from the samples, filter data and
 * 		  transmit the information via WI-FI with the ESP8266 module.
 *
 * @param Ninguno
 *
 */

void Max30102StateMachine::Mde_MAX30102()
{
	static transactions state = FIRST_TRANSACTION;
	uint8_t indice_FIFO_WR_PTR = 0; // ESP: Inicializo el índice de escritura FIFO. ENG: Initialize FIFO write pointer index.
	uint8_t indice_FIFO_RD_PTR = 0; // ESP: Inicializo el índice de lectura FIFO. ENG: Initialize FIFO read pointer index.
	static int32_t NUM_AVAILABLE_SAMPLES = 0; // ESP: Inicializo el número de muestras disponibles. ENG: Initialize the number of available samples.

	switch(state)
	{

		case FIRST_TRANSACTION:

			// ESP: El START, STOP y REPEATED_START lo gestiona automáticamente el módulo I2C del LPC.
			// ENG: START, STOP, and REPEATED_START are handled automatically by the LPC I2C module.
			sensor.getFifoReadAndWrite(&indice_FIFO_WR_PTR, &indice_FIFO_RD_PTR);

			if (indice_FIFO_WR_PTR != indice_FIFO_RD_PTR)
			{
				// ESP: Calculo el número de muestras disponibles en el FIFO.
				// ENG: Calculate the number of available samples in the FIFO.
				NUM_AVAILABLE_SAMPLES = indice_FIFO_WR_PTR - indice_FIFO_RD_PTR;

				if (NUM_AVAILABLE_SAMPLES < 0) NUM_AVAILABLE_SAMPLES += 32; // ESP: Ajusto el desbordamiento. ENG: Handle wrap-around condition.
			}

			state = SECOND_TRANSACTION;// ESP: Cambio al siguiente estado. ENG: Transition to the next state.

			break;

		case SECOND_TRANSACTION:
			// ESP: El procesador central evalúa cuántas muestras se deben leer del FIFO.
			// ENG: The central processor evaluates how many samples need to be read from the FIFO.
			if (NUM_AVAILABLE_SAMPLES > 0)
			{
				// ESP: Calculo bytes restantes. 6 bytes por paquete (2 LEDs).
				// ENG: Calculate remaining bytes. 6 bytes per package (2 LEDs).
				int32_t bytesLeftToRead = NUM_AVAILABLE_SAMPLES * 6;
				sensor.readFifoData(&bytesLeftToRead);

				if(bytesLeftToRead == 0 && !sensor.continue_reading()){
					// ESP: Si todos los datos fueron leídos correctamente aplico un reset y se crean nuevas variables para guardar data de spo2 y hr.
					// ENG: If all data was successfully read, a reset is applied and new variables are created to save spo2 and hr data.
					sensor.reset_samples_counter();

					  int32_t spo2; // ESP: Variable para SpO2. ENG: Variable for SpO2.
					  int8_t spo2_valid; // ESP: Indicador de validez de SpO2. ENG: Validity flag for SpO2.
					  int32_t heart_rate; // ESP: Variable para frecuencia cardíaca. ENG: Variable for heart rate.
					  int8_t hr_valid; // ESP: Indicador de validez de frecuencia cardíaca. ENG: Validity flag for heart rate.

					  // ESP: Obtengo arrays de valores IR y R.
					  // ENG: Retrieve arrays of IR and R values.
					  uint32_t* irValues = sensor.getArrayIRValues();
					  uint32_t* rValues = sensor.getArrayRValues();


					  // ESP: Calculo frecuencia cardíaca y saturación de oxígeno.
					  // ENG: Calculate heart rate and oxygen saturation.
					  sensor.maxim_heart_rate_and_oxygen_saturation(
							  irValues,
							  SAMPLES_SIZE,
							  rValues,
							  &spo2,
							  &spo2_valid,
							  &heart_rate,
							  &hr_valid
					  );

					  // ESP: Verifico si la frecuencia cardíaca es válida.
					  // ENG: Check if heart rate is valid.
					  if(hr_valid)
					  {
						  valores_hr[indice_hr] = heart_rate;// ESP: Almaceno valor de frecuencia cardíaca.// ENG: Store heart rate value.
						  indice_hr++;
						  if(indice_hr == MUESTRA_VAL)
						  {
							  // ESP: Envío promedio de valores de frecuencia cardíaca por WiFi.
							  // ENG: Send averaged heart rate values via WiFi.
							  wifi->send(0);
							  wifi->send(promediar_valores(valores_hr));
							  indice_hr = 0;
						  }

					  }

					  // ESP: Verifico si SpO2 es válido.
					  // ENG: Check if SpO2 is valid.
					  if(spo2_valid )
					  {
						  valores_spo2[indice_spo2] = spo2; // ESP: Almaceno valor de SpO2.// ENG: Store SpO2 value.
						  indice_spo2++;
						  if(indice_spo2 == MUESTRA_VAL)
						  {
							  // ESP: Envío promedio de valores de SpO2 por WiFi.
							  // ENG: Send averaged SpO2 values via WiFi.
							  wifi->send(1);
							  wifi->send(promediar_valores(valores_spo2));
							  indice_spo2=0;
						  }

					  }


						sensor.resetFifoWrite(); // ESP: Reinicio el puntero de escritura FIFO. // ENG: Reset FIFO write pointer.
				  }

				}
				state = FIRST_TRANSACTION; // ESP: Regreso al primer estado.// ENG: Return to the first state.
				break;
		}

}




/* ESP
 * @brief Obtiene un valor promedio ponderado respecto de un array de enteros.
 *
 * @param Array de enteros a promediar.
 *
 */

/* ENG
 * @brief Averages an array of integers and it returns the average value.
 *
 *  @param Array of integers to average.
 *
 */

int32_t Max30102StateMachine::promediar_valores(int32_t valores[]){
	int32_t promedio = 0;
	for(uint8_t i = 0; i < MUESTRA_VAL; i++){
		promedio += valores[i];
	}

	return promedio / MUESTRA_VAL;

}




