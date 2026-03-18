/**
 * ==========================================================================
 * my_sorting.h — Custom Sorting Functions Library (Header)
 * ==========================================================================
 * [ESP] Declaraciones de funciones de ordenamiento para arrays de enteros.
 *       Implementa el algoritmo de ordenamiento burbuja (Bubble Sort)
 *       en orden ascendente y descendente.
 *
 * [ENG] Declarations for integer array sorting functions.
 *       Implements the Bubble Sort algorithm in both
 *       ascending and descending order.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#ifndef MIS_ORDENAMIENTOFUNCIONES_H
#define MIS_ORDENAMIENTOFUNCIONES_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ERROR -1
#define EXITO 0

// [ESP] Ordenamiento burbuja de mayor a menor (descendente)
// [ENG] Bubble sort from largest to smallest (descending)
void Int_Ordenamiento_Burbuja_May_A_Men(int *Array, int largo);

// [ESP] Ordenamiento burbuja de menor a mayor (ascendente)
// [ENG] Bubble sort from smallest to largest (ascending)
void Int_Ordenamiento_Burbuja_Men_A_May(int *Array, int largo);

#endif // MIS_ORDENAMIENTOFUNCIONES_H
