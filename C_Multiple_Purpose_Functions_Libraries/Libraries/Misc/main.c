/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para las funciones utilitarias misceláneas.
 *          [ENG] Usage example program for miscellaneous utility functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "misc_utils.h"
#include <time.h>

int main(void)
{
    int i;

    /* [ESP] Inicializar semilla aleatoria
       [ENG] Initialize random seed */
    srand((unsigned int)time(NULL));

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 1: aleatorio_en_rango_int
     * [ENG] Example 1: aleatorio_en_rango_int
     * --------------------------------------------------------------- */
    printf("=== aleatorio_en_rango_int ===\n\n");
    printf("[ESP] 10 numeros aleatorios entre 1 y 50:\n");
    printf("[ENG] 10 random numbers between 1 and 50:\n  ");
    for (i = 0; i < 10; i++)
        printf("%d ", aleatorio_en_rango_int(1, 50));
    printf("\n\n");

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 2: aleatorio_en_rango_uchar
     * [ENG] Example 2: aleatorio_en_rango_uchar
     * --------------------------------------------------------------- */
    printf("=== aleatorio_en_rango_uchar ===\n\n");
    printf("[ESP] 5 chars aleatorios entre 65 ('A') y 90 ('Z'):\n");
    printf("[ENG] 5 random chars between 65 ('A') and 90 ('Z'):\n  ");
    for (i = 0; i < 5; i++)
    {
        unsigned char c = aleatorio_en_rango_uchar(65, 90);
        printf("%c(%d) ", c, c);
    }
    printf("\n\n");

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 3: Random bit (referencia directa)
     * [ENG] Example 3: Random bit (direct reference)
     * --------------------------------------------------------------- */
    printf("=== Random bit ===\n\n");
    printf("[ESP] 10 bits aleatorios: ");
    printf("[ENG] 10 random bits: ");
    for (i = 0; i < 10; i++)
        printf("%d", rand() % 2);
    printf("\n\n");

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 4: Revertir_Int_Array
     * [ENG] Example 4: Revertir_Int_Array
     * --------------------------------------------------------------- */
    printf("=== Revertir_Int_Array ===\n\n");

    int arr[] = {1, 2, 3, 4, 5};
    int len = 5;

    printf("[ESP] Array original:  ");
    printf("[ENG] Original array:  ");
    for (i = 0; i < len; i++)
        printf("|%d| ", arr[i]);
    printf("\n");

    Revertir_Int_Array(arr, len);

    printf("[ESP] Array invertido: ");
    printf("[ENG] Reversed array:  ");
    for (i = 0; i < len; i++)
        printf("|%d| ", arr[i]);
    printf("\n\n");

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 5: Ordenamiento_Burbuja_Menor_A_Mayor
     * [ENG] Example 5: Ordenamiento_Burbuja_Menor_A_Mayor
     * --------------------------------------------------------------- */
    printf("=== Ordenamiento_Burbuja_Menor_A_Mayor ===\n\n");

    int unsorted[] = {42, 7, 99, 3, 15};
    int n = 5;

    printf("[ESP] Array desordenado: ");
    printf("[ENG] Unsorted array:    ");
    for (i = 0; i < n; i++)
        printf("%d ", unsorted[i]);
    printf("\n");

    Ordenamiento_Burbuja_Menor_A_Mayor(unsorted, n);

    printf("[ESP] Array ordenado:    ");
    printf("[ENG] Sorted array:      ");
    for (i = 0; i < n; i++)
        printf("%d ", unsorted[i]);
    printf("\n");

    return 0;
}
