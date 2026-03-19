/**
 * @file    itostr_strtol.h
 * @brief   [ESP] Biblioteca de conversión entre enteros y cadenas de caracteres.
 *          [ENG] Integer ↔ String conversion library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Proporciona funciones para convertir enteros a strings en distintas
 *       bases numéricas (2, 8, 10, 16) y una función auxiliar para invertir
 *       el orden de caracteres de un string. Incluye también documentación
 *       de referencia sobre el uso de strtol() y sprintf() de la biblioteca
 *       estándar de C.
 *
 * [ENG] Provides functions to convert integers to strings in different
 *       numeric bases (2, 8, 10, 16) and a helper function to reverse
 *       the character order of a string. Also includes reference
 *       documentation on using strtol() and sprintf() from the C
 *       standard library.
 */

#ifndef ITOSTR_STRTOL_H
#define ITOSTR_STRTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief [ESP] Convierte un entero a formato string en la base especificada.
 *        [ENG] Converts an integer to string format in the specified base.
 *
 * @param[in]  num   [ESP] Valor entero a convertir.
 *                   [ENG] Integer value to convert.
 * @param[out] str   [ESP] Buffer de salida donde se almacena el string resultante.
 *                         Debe tener espacio suficiente (mínimo 33 bytes para base 2).
 *                   [ENG] Output buffer where the resulting string is stored.
 *                         Must have enough space (minimum 33 bytes for base 2).
 * @param[in]  base  [ESP] Base numérica de la conversión: 2, 8, 10 o 16.
 *                         - Base 10: soporta números negativos (agrega '-').
 *                         - Bases 2, 8, 16: trata el número como unsigned.
 *                   [ENG] Numeric base for conversion: 2, 8, 10, or 16.
 *                         - Base 10: supports negative numbers (adds '-').
 *                         - Bases 2, 8, 16: treats the number as unsigned.
 * @return           [ESP] Puntero al buffer str con el resultado.
 *                   [ENG] Pointer to the str buffer with the result.
 *
 * @example
 *   char buffer[33];
 *   IntToAnString(255, buffer, 16);   // buffer == "ff"
 *   IntToAnString(255, buffer, 2);    // buffer == "11111111"
 *   IntToAnString(-42, buffer, 10);   // buffer == "-42"
 *   IntToAnString(255, buffer, 8);    // buffer == "377"
 */
char *IntToAnString(int num, char *str, int base);

/**
 * @brief [ESP] Invierte el orden de los caracteres de un string in-place.
 *        [ENG] Reverses the character order of a string in-place.
 *
 * @param[in,out] str     [ESP] String cuyos caracteres se van a invertir.
 *                        [ENG] String whose characters will be reversed.
 * @param[in]     length  [ESP] Largo del string (sin contar el '\0').
 *                        [ENG] Length of the string (not counting '\0').
 * @return void
 *
 * @example
 *   char text[] = "ABCDE";
 *   revertir(text, 5);
 *   // text == "EDCBA"
 */
void revertir(char str[], int length);

#endif /* ITOSTR_STRTOL_H */
