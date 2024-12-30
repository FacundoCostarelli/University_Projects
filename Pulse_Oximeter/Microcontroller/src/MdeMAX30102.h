/*
 * MdeMAX30102.h
 *
 *  Created on: 8 oct. 2024
 *      Author: Facun
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
