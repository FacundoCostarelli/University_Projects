/**
 * @file    Exercise3-5.c
 * @brief   [ESP] Ejercicio 3.5 del libro: Suma de una secuencia de enteros.
 *          [ENG] Exercise 3.5 from the book: Sum of a sequence of integers.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Func. principal. Imprime suma incremental de 1 a 10.
 *        [ENG] Main func. Prints the incremental sum from 1 to 10.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main ()
{
    /* [ESP] Calcula la suma progresiva con cada entero x del 1 al 10
       [ENG] Calculates the progressive sum with each integer x from 1 to 10 */
    int sum = 0, x = 1;
    
    while ( x < 11 )
    {
        sum = sum + x;
        x++;
        printf("El resultado de sum es: %d\n", sum);
    }

    /* [ESP] Imprime la suma final al concluir el ciclo
       [ENG] Prints the final sum after loop concludes */
    printf("El resultado final de sum es: %d\n", sum);

    return 0;
}
