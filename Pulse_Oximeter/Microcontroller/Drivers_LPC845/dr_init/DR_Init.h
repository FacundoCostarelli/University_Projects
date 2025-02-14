/*
 * DR_Init.h
 *
 *  Created on: 8 ago. 2021
 *      Author: Jorge Escola
 */

/* ESP
 * @brief Este archivo contiene las declaraciones necesarias para inicializar el sistema y configurar el PLL (Phase-Locked Loop).
 *        También incluye funciones para gestionar periféricos temporizados.
 *
 *      **Definiciones**
 *
 *      FRO_SET_FRECUENCY_FUNC:
 *                          Puntero a una función ubicada en una dirección específica de memoria (0x0F0026F5U) que se utiliza para
 *                          configurar la frecuencia del oscilador de frecuencia de referencia (FRO).
 *
 *      **Funciones**
 *
 *      InicializarPLL(void):
 *                          Función para inicializar y configurar el PLL, que permite generar una frecuencia de reloj estable
 *                          para el sistema.
 *
 *      recorridoPTs(void):  Función para realizar un recorrido y gestión de los periféricos temporizados (PTs) en el sistema.
 *
 * @param Ninguno
 */

/* ENG
 * @brief This file contains the necessary declarations to initialize the system and configure the PLL (Phase-Locked Loop).
 *        It also includes functions to manage timed peripherals.
 *
 *      **Definitions**
 *
 *      FRO_SET_FRECUENCY_FUNC:
 *                          Pointer to a function located at a specific memory address (0x0F0026F5U) used to configure the
 *                          frequency of the Frequency Reference Oscillator (FRO).
 *
 *      **Functions**
 *
 *      InicializarPLL(void):
 *                          Function to initialize and configure the PLL, which generates a stable clock frequency for the system.
 *
 *      recorridoPTs(void):  Function to perform a scan and management of the timed peripherals (PTs) in the system.
 *
 * @param None
 */

#ifndef DR_INIT_H_
#define DR_INIT_H_

#include <LPC845.h>

// ESP: Incluye las librerías necesarias para el manejo del sistema y periféricos.
// ENG: Includes the necessary libraries for managing the system and peripherals.
#include <systick/Systick.h>
#include <PerifericoTemporizado.h>

// ESP: Definición de la función para configurar la frecuencia del FRO.
// ENG: Definition of the function to configure the FRO frequency.
#define FRO_SET_FRECUENCY_FUNC (void (*)(int))(0x0F0026F5U)

// ESP: Declaración de funciones.
// ENG: Function declaration.
void InicializarPLL (void);  // ESP: Función para inicializar el PLL. ENG: Function to initialize the PLL.
void recorridoPTs (void);    // ESP: Función para gestionar periféricos temporizados. ENG: Function to manage timed peripherals.



#endif /* DR_INIT_H_ */
