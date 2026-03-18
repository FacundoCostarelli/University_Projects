/**
 * ==========================================================================
 * main.c — Test Driver for Sorting Functions
 * ==========================================================================
 * [ESP] Programa de prueba para las funciones de ordenamiento burbuja.
 *       Prueba tanto el orden descendente como el ascendente.
 *
 * [ENG] Test driver for bubble sort functions.
 *       Tests both descending and ascending order.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#include "my_sorting.h"

// [ESP] Driver para Int_Ordenamiento_Burbuja (descendente y ascendente)
// [ENG] Driver for Int_Ordenamiento_Burbuja (descending and ascending)
int main()
{
    int Array[] = {1,3,7,9,0,2,4,5,8,6};
    printf("Hello World!\n");
    Int_Ordenamiento_Burbuja_May_A_Men(Array,10);
    Int_Ordenamiento_Burbuja_Men_A_May(Array,10);
    return 0;
}
