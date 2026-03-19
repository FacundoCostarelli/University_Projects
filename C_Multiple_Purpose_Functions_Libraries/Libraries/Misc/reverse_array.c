/**
 * @file    reverse_array.c
 * @brief   [ESP] Implementación de inversión de array de enteros.
 *          [ENG] Implementation of integer array reversal.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "misc_utils.h"

/**
 * @brief [ESP] Invierte el orden de los elementos de un array de enteros.
 *        [ENG] Reverses the order of elements in an integer array.
 */
void Revertir_Int_Array(int *Array, int length)
{
    int i = 0;
    int aux = 0;

    /* [ESP] Recorremos solo la primera mitad del array.
             En cada iteración intercambiamos el elemento en posición 'i'
             con el elemento en la posición espejada 'length - i - 1'.
       [ENG] We traverse only the first half of the array.
             In each iteration we swap the element at position 'i'
             with the element at mirrored position 'length - i - 1'. */
    for (i = 0; i < (length / 2); i++)
    {
        /* [ESP] Guardamos el valor actual en 'aux' (variable temporal)
           [ENG] Store the current value in 'aux' (temporary variable) */
        aux = Array[i];

        /* [ESP] Copiamos el elemento del extremo opuesto a la posición actual
           [ENG] Copy the element from the opposite end to the current position */
        Array[i] = Array[length - i - 1];

        /* [ESP] Colocamos el valor original (guardado en 'aux') en el extremo opuesto
           [ENG] Place the original value (saved in 'aux') at the opposite end */
        Array[length - i - 1] = aux;
    }

    return;
}
