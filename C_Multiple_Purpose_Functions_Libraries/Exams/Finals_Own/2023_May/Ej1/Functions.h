/**
 * @file    Funciones.h
 * @brief   [ESP] Cabecera para Ejercicio 1.
 *          [ENG] Header for Exercise 1.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define EXITO 0

/**
 * @brief [ESP] Estructura de datos del usuario.
 *        [ENG] User data structure.
 */
struct datos
{
    int user_code;
    char user_name[15];
    float user_fee;
};

/**
 * @brief [ESP] Calcula el byte de paridad usando XOR.
 *        [ENG] Computes parity byte using XOR.
 */
unsigned char paridad(char *s, int c);

/**
 * @brief [ESP] Verifica errores comparando estructuras con bytes de paridad.
 *        [ENG] Verifies errors comparing structures with parity bytes.
 */
int verif(char *f1, char *f2);

#endif /* FUNCIONES_H */
