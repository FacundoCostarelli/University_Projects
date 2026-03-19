/**
 * @file    char_num_bits_random.c
 * @brief   [ESP] Implementación de generadores de números aleatorios.
 *          [ENG] Implementation of random number generators.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Nota: En C no se puede sobrecargar funciones (a diferencia de C++).
 *       Por eso se usan nombres distintos para cada tipo de dato.
 *
 * [ENG] Note: C does not support function overloading (unlike C++).
 *       That's why different names are used for each data type.
 */

#include "misc_utils.h"

/**
 * @brief [ESP] Genera un número aleatorio entero dentro de un rango.
 *        [ENG] Generates a random integer within a range.
 */
int aleatorio_en_rango_int(int minimo, int maximo)
{
    /* [ESP] Fórmula: minimo + rand() / (RAND_MAX / rango + 1)
             Evita el sesgo modular (modulo bias) que ocurre con rand() % N.
       [ENG] Formula: minimo + rand() / (RAND_MAX / range + 1)
             Avoids modulo bias that occurs with rand() % N. */
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

/**
 * @brief [ESP] Genera un número aleatorio unsigned char dentro de un rango.
 *        [ENG] Generates a random unsigned char within a range.
 */
unsigned char aleatorio_en_rango_uchar(unsigned char minimo, unsigned char maximo)
{
    /* [ESP] Misma fórmula, pero casteada a unsigned char (0–255).
       [ENG] Same formula, but cast to unsigned char (0–255). */
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

/* [ESP] Para generar bits aleatorios (0 o 1), simplemente usar:
         int randbit = rand() % 2;
   [ENG] To generate random bits (0 or 1), simply use:
         int randbit = rand() % 2; */
