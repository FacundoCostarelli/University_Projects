/**
 * @file    mi_header.h
 * @brief   [ESP] Cabecera para el ejercicio de Coseno.
 *          [ENG] Main header scoping Cosine exercise.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#ifndef MI_HEADER_H
#define MI_HEADER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <stdlib.h>

/**
 * @brief [ESP] Número de términos para la serie de Taylor.
 *        [ENG] Taylor polynomial upper limit terms span.
 */
#define TERMINOS 10

/* [ESP] Prototipos de funciones / [ENG] Function prototypes */
int coseno(double **, double **, double, double, int);

#endif /* MI_HEADER_H */
