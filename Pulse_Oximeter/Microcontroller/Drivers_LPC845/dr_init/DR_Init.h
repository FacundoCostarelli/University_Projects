/*
 * DR_Init.h
 *
 *  Created on: 8 ago. 2021
 *      Author: chor
 */

#ifndef DR_INIT_H_
#define DR_INIT_H_

#include <LPC845.h>

#include <systick/Systick.h>
#include <PerifericoTemporizado.h>

#define FRO_SET_FRECUENCY_FUNC (void (*)(int))(0x0F0026F5U)

void InicializarPLL (void);
void recorridoPTs (void);



#endif /* DR_INIT_H_ */
