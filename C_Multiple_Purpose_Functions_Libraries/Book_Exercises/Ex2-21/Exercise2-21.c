/**
 * @file    Exercise2-21.c
 * @brief   [ESP] Ejercicio 2.21 del libro: Impresión de formas geométricas.
 *          [ENG] Exercise 2.21 from the book: Printing geometric shapes.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Imprime por pantalla un cuadrado, óvalo, flecha y diamante.
 *        [ENG] Prints a square, oval, arrow, and diamond on the screen.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Se imprimen por pantalla cuadrado, óvalo, flecha y diamante
       [ENG] Square, oval, arrow, and diamond are printed to the screen */
    printf("*********      ***        *         *        \n");
    printf("*       *    *     *     ***       * *       \n");
    printf("*       *   *       *   *****     *   *      \n");
    printf("*       *   *       *     *      *     *     \n");
    printf("*       *   *       *     *     *       *    \n");
    printf("*       *   *       *     *      *     *     \n");
    printf("*       *   *       *     *       *   *      \n");
    printf("*       *    *     *      *        * *       \n");
    printf("*********      ***        *         *        \n");

    return 0;
}
