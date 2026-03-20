/**
 * @file    mi_header.h
 * @brief   [ESP] Cabecera para lectura de caracteres desde fichero con FDs.
 *          [ENG] Main header bounding File Descriptor readings logic prototypes.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#ifndef MI_HEADER_H
#define MI_HEADER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* [ESP] Prototipos de funciones / [ENG] Function prototypes */
int contador(int, int *);

#endif /* MI_HEADER_H */
