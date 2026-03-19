/**
 * @file    bubble_sort.c
 * @brief   [ESP] Implementación de ordenamiento burbuja para enteros.
 *          [ENG] Implementation of bubble sort for integers.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "misc_utils.h"

/**
 * @brief [ESP] Ordena un array de enteros de menor a mayor (burbuja optimizado).
 *        [ENG] Sorts an integer array from smallest to largest (optimized bubble).
 */
void Ordenamiento_Burbuja_Menor_A_Mayor(int *array, int cant_elementos)
{
    int aux, intercambiado, i;

    /* [ESP] Ciclo externo: repetimos mientras haya al menos un intercambio.
             La bandera 'intercambiado' optimiza el algoritmo: si en una
             pasada completa no hubo intercambios, el array ya está ordenado.
       [ENG] Outer loop: repeat while there is at least one swap.
             The 'intercambiado' flag optimizes the algorithm: if no swaps
             occurred in a complete pass, the array is already sorted. */
    do
    {
        intercambiado = 0;

        /* [ESP] Ciclo interno: comparamos elementos adyacentes.
                 Usamos cant_elementos - 1 para no salir del array.
           [ENG] Inner loop: compare adjacent elements.
                 We use cant_elementos - 1 to stay within array bounds. */
        for (i = 0; i < cant_elementos - 1; i++)
        {
            /* [ESP] Si el elemento actual es mayor que el siguiente,
                     los intercambiamos (swap) usando 'aux' como temporal.
               [ENG] If the current element is greater than the next,
                     we swap them using 'aux' as a temporary variable. */
            if (array[i] > array[i + 1])
            {
                intercambiado = 1;
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
            }
        }
    } while (intercambiado);
}
