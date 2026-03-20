/**
 * @file    Funciones-Server-Cliente.h
 * @brief   [ESP] Cabecera de funciones para cliente y servidor. 2do Recup 2023.
 *          [ENG] Client and server common logic header. 2nd Makeup exam 2023.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#ifndef FUNCIONESSERVIDOR_H
#define FUNCIONESSERVIDOR_H

#define ERROR -1
#define EXITO 1
#define FALSE 0
#define TRUE 1
#define END 0
#define OK 1

#include "sock-lib.h"
#include <time.h>
#include <signal.h>

/**
 * @brief [ESP] Estructura alumno usada en el servidor.
 *        [ENG] Student structure used on server.
 */
struct alumno
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
    int repartido;
    int banned;
};

/**
 * @brief [ESP] Estructura alumno enviada por cliente.
 *        [ENG] Student structure sended by client.
 */
typedef struct alumno_cliente
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
} Alumno_cliente;

/* [ESP] Prototipos de funciones / [ENG] Function prototypes */
int aleatorio_en_rango(int minimo, int maximo);

#endif /* FUNCIONESSERVIDOR_H */
