/**
 * @file    Exercise2-24.c
 * @brief   [ESP] Ejercicio 2.24 del libro: Determinar si un número es par o impar.
 *          [ENG] Exercise 2.24 from the book: Determine if a number is even or odd.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Pide un número e indica si es par o impar.
 *        [ENG] Prompts for a number and indicates if it's even or odd.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Variables para número y resto de la división
       [ENG] Variables for number and division remainder */
    int numero, resto;

    /* [ESP] Lee un número ingresado por el usuario
       [ENG] Reads a number entered by the user */
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    /* [ESP] Determina si es par o impar (resto de dividir por 2)
       [ENG] Determines if even or odd (remainder of dividing by 2) */
    resto = numero % 2;

    if (resto == 0)
        printf("El numero %d es par\n", numero);
    
    if (resto != 0)
        printf("El numero %d es inpar\n", numero);

    return 0;
}
