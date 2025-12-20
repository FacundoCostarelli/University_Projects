#ifndef FUNCIONES_H
#define FUNCIONES_H

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

#define ERROR -1
#define EXITO 0

float ** ComposicionDeFunciones(float(*ptr_fun1)(float),float(*ptr_fun2)(float));
float NomFun1(float x);
float NomFun2(float x);
#endif // FUNCIONES_H
