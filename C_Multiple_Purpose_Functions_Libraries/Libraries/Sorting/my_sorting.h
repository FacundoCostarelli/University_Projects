/**
 * @file    my_sorting.h
 * @brief   [ESP] Biblioteca de funciones de ordenamiento para enteros.
 *          [ENG] Integer sorting functions library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Implementa el algoritmo de ordenamiento burbuja optimizado con
 *       bandera de intercambio, en orden ascendente y descendente.
 *
 * [ENG] Implements the optimized bubble sort algorithm with a swap flag,
 *       in both ascending and descending order.
 */

#ifndef MY_SORTING_H
#define MY_SORTING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** @brief [ESP] Código de error / [ENG] Error code */
#define ERROR -1
/** @brief [ESP] Código de éxito / [ENG] Success code */
#define EXITO  0

/**
 * @brief [ESP] Ordena un array de enteros de mayor a menor (descendente).
 *        [ENG] Sorts an integer array from largest to smallest (descending).
 *
 * [ESP] Utiliza bubble sort optimizado con bandera 'Ocurrencia_De_Intercambio'.
 *       Si en una pasada no hay intercambios, el array ya está ordenado.
 *
 * [ENG] Uses optimized bubble sort with 'Ocurrencia_De_Intercambio' flag.
 *       If no swaps occur in a pass, the array is already sorted.
 *
 * @param[in,out] Array  [ESP] Puntero al array de enteros a ordenar.
 *                       [ENG] Pointer to the integer array to sort.
 * @param[in]     largo  [ESP] Cantidad de elementos en el array.
 *                       [ENG] Number of elements in the array.
 * @return void
 *
 * @example
 *   int arr[] = {1, 5, 3, 9, 2};
 *   Int_Ordenamiento_Burbuja_May_A_Men(arr, 5);
 *   // arr == {9, 5, 3, 2, 1}
 */
void Int_Ordenamiento_Burbuja_May_A_Men(int *Array, int largo);

/**
 * @brief [ESP] Ordena un array de enteros de menor a mayor (ascendente).
 *        [ENG] Sorts an integer array from smallest to largest (ascending).
 *
 * [ESP] Utiliza bubble sort optimizado con bandera 'Ocurrencia_De_Intercambio'.
 *       Si en una pasada no hay intercambios, el array ya está ordenado.
 *
 * [ENG] Uses optimized bubble sort with 'Ocurrencia_De_Intercambio' flag.
 *       If no swaps occur in a pass, the array is already sorted.
 *
 * @param[in,out] Array  [ESP] Puntero al array de enteros a ordenar.
 *                       [ENG] Pointer to the integer array to sort.
 * @param[in]     largo  [ESP] Cantidad de elementos en el array.
 *                       [ENG] Number of elements in the array.
 * @return void
 *
 * @example
 *   int arr[] = {5, 3, 1, 4, 2};
 *   Int_Ordenamiento_Burbuja_Men_A_May(arr, 5);
 *   // arr == {1, 2, 3, 4, 5}
 */
void Int_Ordenamiento_Burbuja_Men_A_May(int *Array, int largo);

#endif /* MY_SORTING_H */
