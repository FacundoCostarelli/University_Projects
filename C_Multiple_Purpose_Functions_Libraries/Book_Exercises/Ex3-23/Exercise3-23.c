/**
 * @file    Exercise3-23.c
 * @brief   [ESP] Ejercicio 3.23 del libro: Bucle simple hasta 10.
 *          [ENG] Exercise 3.23 from the book: Simple loop up to 10.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>

/**
 * @brief [ESP] Func. principal. Imprime números del 1 al 10 en la misma línea.
 *        [ENG] Main func. Prints numbers from 1 to 10 on the same line.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Inicia contador en 1
       [ENG] Starts counter at 1 */
    int counter = 1;
    
    /* [ESP] Repite mientras el contador sea menor o igual a 10
       [ENG] Repeats while the counter is less than or equal to 10 */
    while ( counter <= 10 )
    {
        printf("%d   ", counter);
        counter += 1;
    }
    
    printf("\n");
    return 0;
}
