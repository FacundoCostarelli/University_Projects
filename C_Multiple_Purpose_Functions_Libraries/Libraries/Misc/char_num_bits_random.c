/**
 * ==========================================================================
 * char_num_bits_random.c — Random Number & Bit Generators
 * ==========================================================================
 * [ESP] Funciones para generar números aleatorios dentro de un rango:
 *       - Versión para int
 *       - Versión para unsigned char
 *       - Generación de bits aleatorios (0 o 1)
 *
 * [ENG] Functions to generate random numbers within a range:
 *       - Version for int
 *       - Version for unsigned char
 *       - Random bit generation (0 or 1)
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

// [ESP] Devuelve un número aleatorio entre minimo y maximo, incluyendo a minimo y maximo.
// [ENG] Returns a random number between min and max, inclusive.
//Se puede usar ints, char, unsigned char, etc. Solo hay que identificar el tipo de
//dato de cada parametro y el retorno segun lo que se quiera hacer. EJ: Todo es INT, o todo es
//unsigned char, o todo es char, etc.

//Para generar nros aleatorios tipo int
int aleatorio_en_rango(int minimo, int maximo)
{
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
//Para generar nros aleatorios tipo unsigned char
unsigned char aleatorio_en_rango(unsigned char minimo, unsigned char maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

//Para generar bits aleatorios entre 0 y 1 simplemente usar
randbit = rand()%2;
