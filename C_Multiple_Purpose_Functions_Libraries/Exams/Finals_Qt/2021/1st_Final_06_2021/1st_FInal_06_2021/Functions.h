/**
 * @file    Funciones.h
 * @brief   [ESP] Cabecera de funciones. Final 06/2021.
 *          [ENG] Function prototypes header for Final 06/2021.
 *
 * @author  Facundo Costarelli
 * @date    2021
 * @course  Informática 1 — UTNBA
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

/**
 * @brief [ESP] Constantes de error y éxito.
 *        [ENG] Error and success constants.
 */
#define ERROR -1
#define EXITO 0

/* [ESP] Prototipos de funciones / [ENG] Function prototypes */
float ** ComposicionDeFunciones(float(*ptr_fun1)(float), float(*ptr_fun2)(float));
float NomFun1(float x);
float NomFun2(float x);

#endif /* FUNCIONES_H */
