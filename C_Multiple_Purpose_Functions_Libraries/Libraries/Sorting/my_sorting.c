/**
 * ==========================================================================
 * my_sorting.c — Custom Sorting Functions Library (Implementation)
 * ==========================================================================
 * [ESP] Implementación del algoritmo de ordenamiento burbuja optimizado
 *       para arrays de enteros. Incluye versiones ascendente y descendente.
 *       Usa una bandera de intercambio para evitar iteraciones innecesarias
 *       cuando el array ya está ordenado.
 *
 * [ENG] Implementation of an optimized Bubble Sort algorithm for integer
 *       arrays. Includes ascending and descending versions.
 *       Uses a swap flag to avoid unnecessary iterations when the array
 *       is already sorted.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#include"my_sorting.h"

/**
 * [ESP] Ordenamiento burbuja de mayor a menor (descendente).
 *       Recibe un puntero al array de enteros y su largo.
 *       Optimización: usa una bandera para detenerse cuando no hay más intercambios.
 * [ENG] Bubble sort from largest to smallest (descending order).
 *       Receives a pointer to the integer array and its length.
 *       Optimization: uses a flag to stop when no more swaps occur.
 */
void Int_Ordenamiento_Burbuja_May_A_Men(int *Array, int largo)
{
    int i = 0;
    int j = 0;
    int aux = 0;

    // [ESP] Supongo inicialmente que el array está completamente ordenado
    // [ENG] Initially assume the array is fully sorted
    bool Ocurrencia_De_Intercambio = false;

    do
    {
        // [ESP] Asumo que todos los elementos están ordenados después del último pase.
        //       Si ocurre un intercambio, la bandera se activa.
        //       Esto evita recorrer el array innecesariamente cuando ya está ordenado.
        // [ENG] Assume all elements are sorted after the last pass.
        //       If a swap occurs, the flag is set.
        //       This avoids unnecessary traversals when the array is already sorted.
        Ocurrencia_De_Intercambio = false;

        // [ESP] Itero comparando pares adyacentes. Cada pase "burbujea"
        //       el valor más pequeño al final, por eso se reduce el rango con (largo-1-i).
        // [ENG] Iterate comparing adjacent pairs. Each pass "bubbles"
        //       the smallest value to the end, hence the range is reduced by (largo-1-i).
        for(j = 0; j < (largo-1-i); j++)
        {
            // [ESP] Si el valor actual es menor que el siguiente, intercambio (orden descendente)
            // [ENG] If current value is less than the next, swap (descending order)
            if(Array[j] < Array[j+1])
            {
                aux = Array[j];         // [ESP] Guardo valor actual / [ENG] Store current value
                Array[j] = Array[j+1];  // [ESP] Copio el siguiente / [ENG] Copy next value
                Array[j+1] = aux;       // [ESP] Restauro desde aux / [ENG] Restore from aux
                Ocurrencia_De_Intercambio = true;
            }
        }
        i++;
    }while(Ocurrencia_De_Intercambio == true);

    // [ESP] Impresión del resultado ordenado
    // [ENG] Print the sorted result
    for( i = 0; i < largo; i ++ )
    {
        printf("Array [%d] = %d ",i,Array[i]);
    }
    printf("\n");
    return;
}

/**
 * [ESP] Ordenamiento burbuja de menor a mayor (ascendente).
 *       Misma lógica que la versión descendente pero con la comparación invertida.
 * [ENG] Bubble sort from smallest to largest (ascending order).
 *       Same logic as the descending version but with the comparison inverted.
 */
void Int_Ordenamiento_Burbuja_Men_A_May(int *Array, int largo)
{
    int i = 0;
    int j = 0;
    int aux = 0;

    // [ESP] Bandera de intercambio: si no ocurren swaps, el array ya está ordenado
    // [ENG] Swap flag: if no swaps occur, the array is already sorted
    bool Ocurrencia_De_Intercambio = false;

    do
    {
        Ocurrencia_De_Intercambio = false;

        for(j = 0; j < (largo-1-i); j++)
        {
            // [ESP] Si el valor actual es mayor que el siguiente, intercambio (orden ascendente)
            // [ENG] If current value is greater than the next, swap (ascending order)
            if(Array[j] > Array[j+1])
            {
                 aux = Array[j];
                 Array[j] = Array[j+1];
                 Array[j+1] = aux;
                 Ocurrencia_De_Intercambio = true;
            }
        }
        i++;
    }while(Ocurrencia_De_Intercambio == true);

    // [ESP] Impresión del resultado ordenado
    // [ENG] Print the sorted result
    for( i = 0; i < largo; i ++ )
    {
        printf("Array [%d] = %d ",i,Array[i]);
    }
    printf("\n");

    return;
}
