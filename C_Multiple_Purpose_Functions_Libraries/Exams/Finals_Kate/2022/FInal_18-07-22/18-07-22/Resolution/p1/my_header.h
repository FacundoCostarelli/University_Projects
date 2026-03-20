/**
 * @file    mi_header.h
 * @brief   [ESP] Cabecera para Problema 1 - Final 18-07-2022.
 *          [ENG] Header for Problem 1 - Final 18-07-2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#ifndef P1_HEADER_H
#define P1_HEADER_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define TERMINOS 10

/**
 * @brief [ESP] Prototipo de cálculo del coseno mediante Taylor.
 *        [ENG] Prototype of cosine calculation by Taylor series.
 */
int coseno(double **, double **, double, double, int);

#endif /* P1_HEADER_H */
