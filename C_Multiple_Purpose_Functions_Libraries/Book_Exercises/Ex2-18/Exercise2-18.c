/**
 * @file    Exercise2-18.c
 * @brief   [ESP] Ejercicio 2.18 del libro: Comparación de enteros.
 *          [ENG] Exercise 2.18 from the book: Integer comparison.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Func. principal. Compara 2 números e imprime el resultado.
 *        [ENG] Main func. Compares 2 numbers and prints the outcome.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Pide 2 números al usuario y los lee en a y b
       [ENG] Prompts the user for 2 numbers and reads them into a and b */
    int a, b;
    printf("Ingrese 2 numeros enteros siendo: a y b\n");
    scanf("%d%d", &a, &b);
    
    /* [ESP] Enunciados de decisión basados en las comparaciones
       [ENG] Decision statements based on comparisons */
    if( a > b )
        printf("El numero a=%d es el mayor de los 2\n", a);
    
    if( b > a )
        printf("El numero b=%d es el mayor de los 2\n", b);
    
    if( a == b )
        printf("Los numeros ingresados son iguales\n");
    
    return 0;
}
