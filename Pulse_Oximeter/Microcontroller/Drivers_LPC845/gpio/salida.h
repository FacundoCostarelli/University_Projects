/*
 * salida.h
 *
 *  Created on: 20 may. 2024
 *      Author: chor
 */

#ifndef SALIDA_H_
#define SALIDA_H_

class salida {

public:
	salida();
	virtual void setValor( bool ) = 0;
	virtual void toggleValor ( ) = 0;
};
#endif /* SALIDA_H_ */
