#ifndef FUNCIONESSERVIDOR_H
#define FUNCIONESSERVIDOR_H

#define ERROR -1
#define EXITO 1
#define FALSE 0
#define TRUE 1
#define END 0
#define OK 1

#include"sock-lib.h"
#include<time.h>
#include<signal.h>
struct alumno
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
    int repartido;
    int banned;

};

typedef struct alumno_cliente
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
}Alumno_cliente;


//void sighandler(int signum);
int aleatorio_en_rango(int minimo, int maximo);

#endif // FUNCIONESSERVIDOR_H
