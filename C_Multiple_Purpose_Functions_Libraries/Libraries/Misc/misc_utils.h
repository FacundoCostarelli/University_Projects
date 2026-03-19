/**
 * @file    misc_utils.h
 * @brief   [ESP] Biblioteca de funciones utilitarias misceláneas.
 *          [ENG] Miscellaneous utility functions library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Colección de funciones utilitarias de propósito general:
 *       generación de números aleatorios, inversión de arrays y
 *       ordenamiento burbuja para enteros.
 *
 * [ENG] Collection of general-purpose utility functions:
 *       random number generation, array reversal, and
 *       bubble sort for integers.
 */

#ifndef MISC_UTILS_H
#define MISC_UTILS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief [ESP] Genera un número aleatorio entero dentro de un rango inclusivo.
 *        [ENG] Generates a random integer within an inclusive range.
 *
 * @param[in] minimo  [ESP] Valor mínimo del rango (incluido).
 *                    [ENG] Minimum range value (inclusive).
 * @param[in] maximo  [ESP] Valor máximo del rango (incluido).
 *                    [ENG] Maximum range value (inclusive).
 * @return            [ESP] Número aleatorio entre minimo y maximo.
 *                    [ENG] Random number between minimo and maximo.
 *
 * @example
 *   int r = aleatorio_en_rango_int(1, 100);
 *   // r ∈ [1, 100]
 */
int aleatorio_en_rango_int(int minimo, int maximo);

/**
 * @brief [ESP] Genera un número aleatorio unsigned char dentro de un rango.
 *        [ENG] Generates a random unsigned char within a range.
 *
 * @param[in] minimo  [ESP] Valor mínimo del rango (incluido).
 *                    [ENG] Minimum range value (inclusive).
 * @param[in] maximo  [ESP] Valor máximo del rango (incluido).
 *                    [ENG] Maximum range value (inclusive).
 * @return            [ESP] Unsigned char aleatorio entre minimo y maximo.
 *                    [ENG] Random unsigned char between minimo and maximo.
 *
 * @example
 *   unsigned char c = aleatorio_en_rango_uchar(0, 255);
 */
unsigned char aleatorio_en_rango_uchar(unsigned char minimo, unsigned char maximo);

/**
 * @brief [ESP] Invierte el orden de los elementos de un array de enteros in-place.
 *        [ENG] Reverses the order of elements in an integer array in-place.
 *
 * [ESP] Utiliza el algoritmo de intercambio desde los extremos hacia el centro.
 *       Solo recorre la mitad del array para realizar la inversión completa.
 *
 * [ENG] Uses the swap algorithm from both ends towards the center.
 *       Only traverses half the array to perform the complete reversal.
 *
 * @param[in,out] Array   [ESP] Puntero al array de enteros a invertir.
 *                        [ENG] Pointer to the integer array to reverse.
 * @param[in]     length  [ESP] Cantidad de elementos en el array.
 *                        [ENG] Number of elements in the array.
 * @return void
 *
 * @example
 *   int arr[] = {1, 2, 3, 4, 5};
 *   Revertir_Int_Array(arr, 5);
 *   // arr == {5, 4, 3, 2, 1}
 */
void Revertir_Int_Array(int *Array, int length);

/**
 * @brief [ESP] Ordena un array de enteros de menor a mayor (burbuja optimizado).
 *        [ENG] Sorts an integer array from smallest to largest (optimized bubble).
 *
 * [ESP] Implementa el algoritmo de ordenamiento burbuja con una bandera de
 *       optimización que detiene el ciclo si no hubo intercambios.
 *
 * [ENG] Implements the bubble sort algorithm with an optimization flag
 *       that stops the loop if no swaps occurred.
 *
 * @param[in,out] array          [ESP] Puntero al array de enteros a ordenar.
 *                               [ENG] Pointer to the integer array to sort.
 * @param[in]     cant_elementos [ESP] Cantidad de elementos en el array.
 *                               [ENG] Number of elements in the array.
 * @return void
 *
 * @example
 *   int arr[] = {5, 3, 1, 4, 2};
 *   Ordenamiento_Burbuja_Menor_A_Mayor(arr, 5);
 *   // arr == {1, 2, 3, 4, 5}
 */
void Ordenamiento_Burbuja_Menor_A_Mayor(int *array, int cant_elementos);

#endif /* MISC_UTILS_H */
