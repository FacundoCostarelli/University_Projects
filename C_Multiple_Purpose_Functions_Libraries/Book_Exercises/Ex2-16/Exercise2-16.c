/**
 * @file    Exercise2-16.c
 * @brief   [ESP] Ejercicio 2.16 del libro: Operaciones aritméticas básicas.
 *          [ENG] Exercise 2.16 from the book: Basic arithmetic operations.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Función principal. Pide 2 enteros e imprime varios cálculos.
 *        [ENG] Main function. Prompts for 2 integers and prints several calculations.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Variables para almacenar los números ingresados
       [ENG] Variables to store the entered numbers */
    int a, b;
    
    /* [ESP] Pide 2 números enteros siendo: a y b
       [ENG] Prompts for 2 integers, being: a and b */
    printf("Ingrese 2 numeros enteros siendo: a y b\n");
    scanf("%d%d", &a, &b);

    /* [ESP] Cálculos e impresión de resultados
       [ENG] Calculations and result printing */
    printf("La suma a + b es: %d\n", a + b);
    printf("La resta a - b es: %d\n", a - b);
    printf("El producto a * b es: %d\n", a * b);
    printf("El cociente a / b es: %d\n", a / b);
    printf("El modulo a porcentaje b es: %d\n", a % b);

    return 0;
}
