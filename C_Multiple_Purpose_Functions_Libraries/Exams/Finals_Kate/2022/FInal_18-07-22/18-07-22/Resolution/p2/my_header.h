/**
 * @file    mi_header.h
 * @brief   [ESP] Cabecera para Problema 2 - Final 18-07-2022.
 *          [ENG] Header for Problem 2 - Final 18-07-2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#ifndef P2_HEADER_H
#define P2_HEADER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief [ESP] Prototipo de conteo de letras.
 *        [ENG] Letters count prototype.
 */
int contador(int, int *);

#endif /* P2_HEADER_H */
