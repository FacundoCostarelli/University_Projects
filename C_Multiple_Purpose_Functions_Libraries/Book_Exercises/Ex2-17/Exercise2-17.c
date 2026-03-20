/**
 * @file    Exercise2-17.c
 * @brief   [ESP] Ejercicio 2.17 del libro: Impresión de números 1 a 4.
 *          [ENG] Exercise 2.17 from the book: Printing numbers 1 to 4.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Función principal. Imprime 1 a 4 de tres formas distintas.
 *        [ENG] Main function. Prints 1 to 4 in three different ways.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Imprime por pantalla los números 1 a 4 de tres (3) formas distintas
       [ENG] Prints numbers 1 to 4 on screen in three (3) different ways */    
    int a=1, b=2, c=3, d=4;

    /* [ESP] 1era forma usando un solo literal de cadena
       [ENG] 1st way using a single string literal */
    printf("1 2 3 4\n");
    
    /* [ESP] 2da forma usando especificadores de formato y variables
       [ENG] 2nd way using format specifiers and variables */
    printf("%d %d %d %d\n", a, b, c, d);
    
    /* [ESP] 3era forma usando múltiples sentencias printf
       [ENG] 3rd way using multiple printf statements */
    printf("1 ");
    printf("2 ");
    printf("3 ");
    printf("4\n");

    return 0;
}
