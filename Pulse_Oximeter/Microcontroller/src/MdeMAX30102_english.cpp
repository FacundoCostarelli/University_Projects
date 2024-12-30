/*
 * MdeMAX30102.cpp
 *
 *  Created on: 8 oct. 2024
 *      Author: Facundo Costarelli & Ezequiel Lagatche
 *      Additional information:
 *      Segun el protocolo I2C no hay encabezador. Solo bit de start, bit de escritura o lectura y bit de stop
 *		La maquina de estados responde al pseudocodigo de lectura en la datasheet del sensor MAX30102
 */

#include "MdeMAX30102.h"

/*
 * @brief Constructor de la clase Max30102StateMachine
 * 		  Inicializa variables
 * @param module_wifi puntero al objeto de la clase del modulo wifi
 * */
 Max30102StateMachine::Max30102StateMachine(ESP8266 *module_wifi):
 	 sensor(I2C0, mode_t::master, SLAVE_ADDR_MAX30102){
	 wifi= module_wifi;
	 index_spo2 = 0;
	 index_hr = 0;
 }
/*
 * @brief maquina de estados para leer los datos del sensor max30102
 * */
void Max30102StateMachine::Mde_MAX30102()
{
	static transactions state = FIRST_TRANSACTION;
	uint8_t index_FIFO_WR_PTR = 0;  // Para establecer el numero de muestras
	uint8_t index_FIFO_RD_PTR = 0;
	static int32_t NUM_AVAILABLE_SAMPLES = 0;//int16_t y no uint8_t para hacer restas

	switch(state)
	{

		case FIRST_TRANSACTION:

			// El START, STOP y REPEATED_START lo hace por si mismo el  modulo I2C del LPC
			sensor.getFifoReadAndWrite(&index_FIFO_WR_PTR, &index_FIFO_RD_PTR);

			if (index_FIFO_WR_PTR != index_FIFO_RD_PTR)
			{
				NUM_AVAILABLE_SAMPLES = index_FIFO_WR_PTR - index_FIFO_RD_PTR;

				if (NUM_AVAILABLE_SAMPLES < 0) NUM_AVAILABLE_SAMPLES += 32; // Wrap around condition
			}

			state = SECOND_TRANSACTION;

			break;

		case SECOND_TRANSACTION:
		 // The central processor evaluates the number of samples to be read from the FIFO
		if (NUM_AVAILABLE_SAMPLES > 0)
		{

			int32_t bytesLeftToRead = NUM_AVAILABLE_SAMPLES * 6;// 3 bytes per led (ir and red). 6 bytes in total per package

			sensor.readFifoData(&bytesLeftToRead);

 			if(bytesLeftToRead == 0 && !sensor.continue_reading()){
				// si leyó datos
 				sensor.reset_samples_counter();

				  int32_t spo2;
				  int8_t spo2_valid;
				  int32_t heart_rate;
				  int8_t hr_valid;

				  uint32_t* irValues = sensor.getArrayIRValues();
				  uint32_t* rValues = sensor.getArrayRValues();


				  sensor.maxim_heart_rate_and_oxygen_saturation(
						  irValues,
						  SAMPLES_SIZE,
						  rValues,
						  &spo2,
						  &spo2_valid,
						  &heart_rate,
						  &hr_valid
				  );


				  if(hr_valid){

					  values_hr[index_hr] = heart_rate;
					  index_hr++;
					  if(index_hr == SAMPLE_VAL){

						  wifi->send(0);
						  wifi->send(average_values(values_hr));
						  index_hr = 0;
					  }

				  }

				  if(spo2_valid ){

					  values_spo2[index_spo2] = spo2;
					  index_spo2++;
					  if(index_spo2 == SAMPLE_VAL){
						  wifi->send(1);
						  wifi->send(average_values(values_spo2));
						  index_spo2=0;
					  }

				  }


					sensor.resetFifoWrite();
			  }

			}
			state = FIRST_TRANSACTION;
			break;
	}

}

/*
 * @brief realiza un promedio de un array de enteros
 * @param valores array de enteros a promediar
 * */
int32_t Max30102StateMachine::average_values(int32_t values[]){
	int32_t average = 0;
	for(uint8_t i = 0; i < SAMPLE_VAL; i++){
		average += values[i];
	}

	return average / SAMPLE_VAL;

}




