/**
 * @file    Exercise3-8.c
 * @brief   [ESP] Ejercicio 3.8 del libro: Potenciación con bucle while.
 *          [ENG] Exercise 3.8 from the book: Exponentiation using while loop.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Func. principal. Calcula x elevado a la y.
 *        [ENG] Main func. Calculates x raised to the power of y.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main ()
{
    /* [ESP] Variables para la base(x), exponente(y) y resultado(power)
       [ENG] Variables for base(x), exponent(y) and result(power) */
    int x, y;
    int power = 1, i = 1;
    
    /* [ESP] Introduce y lee base y exponente
       [ENG] Prompts and reads base and exponent */
    printf("Introduzca la base entera x: \n");
    scanf("%d", &x);
    printf("Introduzca el exponente entero y: \n");
    scanf("%d", &y);
    
    /* [ESP] Multiplica iterativamente hasta alcanzar el exponente
       [ENG] Multiplies iteratively until reaching the exponent */
    while ( i <= y )
    {
        power *= x;
        i++;
    }
    
    printf("El resultado de la x elevado a la y es: %d \n", power);

    return 0;
}
