/**
 * @file    Exercise2_5.c
 * @brief   [ESP] Ejercicio 2.5 del libro: Producto de tres enteros.
 *          [ENG] Exercise 2.5 from the book: Product of three integers.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Func. principal. Calcula y muestra el producto de 3 números.
 *        [ENG] Main func. Calculates and displays the product of 3 numbers.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Cálculo del producto de tres (3) enteros
       [ENG] Calculation of the product of three (3) integers */
    int x, y, z, result;
    
    /* [ESP] Recepción de los enteros
       [ENG] Receiving the integers */
    printf("Escriba un valor para cada entero X-Y-Z: ");
    scanf("%d%d%d", &x, &y, &z);
    
    result = x * y * z;
    
    printf("El resultado del producto es: %d\n", result);

    return 0;
}
