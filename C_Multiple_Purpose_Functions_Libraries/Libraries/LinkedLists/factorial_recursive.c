/**
 * ==========================================================================
 * factorial_recursive.c — Recursive Factorial Function
 * ==========================================================================
 * [ESP] Implementación de una función recursiva que calcula el factorial
 *       de un número entero. Ejemplo: factorial(4) = 4 * 3 * 2 * 1 = 24
 *
 * [ENG] Implementation of a recursive function that calculates the factorial
 *       of an integer. Example: factorial(4) = 4 * 3 * 2 * 1 = 24
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#include<stdio.h>

// [ESP] Declaración de la función factorial recursiva
// [ENG] Declaration of the recursive factorial function
int funcion(int n);


int main()
{
    printf("%d\n",funcion(4));

    return 0;
}

/**
 * [ESP] Calcula el factorial de n de forma recursiva.
 *       Caso base: n == 0 → retorna 1
 *       Caso recursivo: n * factorial(n-1)
 * [ENG] Recursively calculates the factorial of n.
 *       Base case: n == 0 → returns 1
 *       Recursive case: n * factorial(n-1)
 */
int funcion(int n)
{
    if(n==0)
    {
        return 1; // [ESP] Caso base / [ENG] Base case
    }
    else
    {
        return(n * funcion(n-1)); // [ESP] Llamada recursiva / [ENG] Recursive call
    }
}
