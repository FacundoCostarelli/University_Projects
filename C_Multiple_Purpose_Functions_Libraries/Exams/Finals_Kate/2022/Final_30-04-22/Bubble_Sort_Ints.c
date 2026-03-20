/**
 * @file    Funcion_Ordenamiento_Brubuja_ints.c
 * @brief   [ESP] Función aislada de ordenamiento Burbuja para enteros.
 *          [ENG] Isolated Bubble Sort function for integers.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

/* 
 * [ESP] Pseudo script, no ejecutable sin main().
 * [ENG] Pseudo script, not executable without main().
 */

#include <stdio.h>

/**
 * @brief [ESP] Estructura genérica del algoritmo Bubble Sort de muestra.
 *        [ENG] Sample Bubble Sort algorithm generic structure.
 */
void bubble_sort_sample()
{
    int i, aux;
    int numbersread = 0; /* Init variable to avoid warning */
    int swapped;
    int numbers[1000];

    do {
        swapped = 0;
        for(i = 0; i < numbersread - 1; i++) {
            if(numbers[i] > numbers[i + 1]) {
                swapped = 1;
                /* [ESP] Intercambio de variables / [ENG] Variable swap */
                aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
            }
        }
    } while(swapped);
    
    printf("The sorted values: ");
    for(i = 0; i < numbersread; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}
