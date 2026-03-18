/**
 * ==========================================================================
 * bubble_sort.c — Generic Bubble Sort (void* Version)
 * ==========================================================================
 * [ESP] Implementación de ordenamiento burbuja ascendente usando void*.
 *       Incluye driver de prueba que solicita 5 valores por teclado.
 *
 * [ENG] Ascending bubble sort implementation using void*.
 *       Includes test driver that prompts for 5 keyboard values.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#include <stdio.h>


void Ordenamiento_Burbuja_Menor_A_Mayor(void *array, int cant_elementos);
int main(void) {
        int numbers[5];
        int i;

        /* ask the user to enter 5 values */
        for(i = 0; i < 5; i++) {
                printf("\nEnter value #%i\n",i + 1);
                scanf("%d",&numbers[i]);
        }

        Ordenamiento_Burbuja_Menor_A_Mayor(numbers,5);


        /* print results */
        printf("\nSorted array: ");
        for(i = 0; i < 5; i++)
                printf("%d ",numbers[i]);
        printf("\n");
        return 0;
}

void Ordenamiento_Burbuja_Menor_A_Mayor(void *array, int cant_elementos)
{
    int aux, intercambiado;
    /* sort them */
        do {
                intercambiado = 0;
                for(i = 0; i < cant_elementos; i++) {
                        if(array[i] > array[i + 1]) {
                            intercambiado = 1;
                            aux = array[i];
                            array[i] = array[i + 1];
                            array[i + 1] = aux;
                         }
                }
        } while(intercambiado);
}
