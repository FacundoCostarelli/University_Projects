#ifndef FUNCIONES_H
#define FUNCIONES_H

/*
Alumno: Facundo Costarelli
DNI: 42724683
Legajo: 176.291-6
Cursada: R1002 con Mariano Gonzales 2022
*/


#include<stdio.h>
#include<stdlib.h>
#define ERROR -1
#define EXITO 0


struct datos
{
    int user_code;
    char user_name[15];
    float user_fee;
};

unsigned char paridad(char *s, int c);
int verif(char *f1, char *f2);

#endif // FUNCIONES_H
