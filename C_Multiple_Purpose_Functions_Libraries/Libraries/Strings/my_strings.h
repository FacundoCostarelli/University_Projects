/**
 * @file    my_strings.h
 * @brief   [ESP] Biblioteca de funciones personalizadas de manejo de strings.
 *          [ENG] Custom string manipulation functions library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Funciones que replican y extienden las operaciones estándar de strings
 *       en C: copia, longitud, concatenación, comparación sin importar caso,
 *       memset, reversión, detección de palíndromos, conversión de caso y
 *       ordenamiento alfabético de arrays de strings.
 *
 * [ENG] Functions that replicate and extend standard C string operations:
 *       copy, length, concatenation, case-insensitive comparison, memset,
 *       reversal, palindrome detection, case conversion, and alphabetical
 *       sorting of string arrays.
 */

#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/** @brief [ESP] Código de error / [ENG] Error code */
#define ERROR -1
/** @brief [ESP] Código de éxito / [ENG] Success code */
#define EXITO  1

/**
 * @brief [ESP] Copia un string usando la técnica de contadores (índices).
 *        [ENG] Copies a string using the counter (index) technique.
 *
 * @param[out] Destino  [ESP] Buffer destino donde se copiará el string.
 *                      [ENG] Destination buffer where the string will be copied.
 * @param[in]  Origen   [ESP] String fuente a copiar.
 *                      [ENG] Source string to copy.
 * @return              [ESP] Puntero al buffer destino, o NULL si Destino es NULL.
 *                      [ENG] Pointer to destination buffer, or NULL if Destino is NULL.
 *
 * @example
 *   char dest[50];
 *   Mi_StringCopyV1(dest, "Hello World");
 *   // dest == "Hello World"
 */
char *Mi_StringCopyV1(char *Destino, const char *Origen);

/**
 * @brief [ESP] Copia un string usando aritmética de punteros.
 *        [ENG] Copies a string using pointer arithmetic.
 *
 * @param[out] Destino  [ESP] Buffer destino donde se copiará el string.
 *                      [ENG] Destination buffer where the string will be copied.
 * @param[in]  Origen   [ESP] String fuente a copiar.
 *                      [ENG] Source string to copy.
 * @return              [ESP] Puntero al buffer destino, o NULL si Destino es NULL.
 *                      [ENG] Pointer to destination buffer, or NULL if Destino is NULL.
 *
 * @example
 *   char dest[50];
 *   Mi_StringCopyV2(dest, "Pointer copy");
 *   // dest == "Pointer copy"
 */
char *Mi_StringCopyV2(char *Destino, const char *Origen);

/**
 * @brief [ESP] Calcula el largo de un string sin contar el carácter '\0'.
 *        [ENG] Calculates the length of a string excluding the '\0' character.
 *
 * @param[in] String  [ESP] String cuya longitud se desea obtener.
 *                    [ENG] String whose length is to be obtained.
 * @return            [ESP] Largo del string (0 si String es NULL).
 *                    [ENG] Length of the string (0 if String is NULL).
 *
 * @example
 *   int len = Mi_StringLength("HOLA");
 *   // len == 4
 */
int Mi_StringLength(char *String);

/**
 * @brief [ESP] Concatena 2 strings con alocación de memoria dinámica.
 *        [ENG] Concatenates 2 strings using dynamic memory allocation.
 *
 * [ESP] El llamador debe liberar la memoria retornada con free().
 * [ENG] The caller must free the returned memory with free().
 *
 * @param[in] String1  [ESP] Primer string (queda a la izquierda).
 *                     [ENG] First string (goes on the left).
 * @param[in] String2  [ESP] Segundo string (queda a la derecha).
 *                     [ENG] Second string (goes on the right).
 * @return             [ESP] Puntero al nuevo string concatenado (memoria dinámica).
 *                     [ENG] Pointer to the new concatenated string (dynamic memory).
 *
 * @example
 *   char *result = Mi_StringConcatenate("Hello ", "World");
 *   printf("%s\n", result);  // "Hello World"
 *   free(result);
 */
char *Mi_StringConcatenate(char *String1, char *String2);

/**
 * @brief [ESP] Compara 2 strings sin importar mayúsculas o minúsculas.
 *        [ENG] Case-insensitive comparison of 2 strings.
 *
 * @param[in] String1  [ESP] Primer string a comparar.
 *                     [ENG] First string to compare.
 * @param[in] String2  [ESP] Segundo string a comparar.
 *                     [ENG] Second string to compare.
 * @return             [ESP] 0 si iguales, <0 si String1 < String2, >0 si String1 > String2.
 *                     [ENG] 0 if equal, <0 if String1 < String2, >0 if String1 > String2.
 *
 * @example
 *   int cmp = Mi_StringCaseCompare("Hello", "HELLO");
 *   // cmp == 0 (equal)
 */
int Mi_StringCaseCompare(const char *String1, const char *String2);

/**
 * @brief [ESP] Setea n bytes de un array con un valor (similar a memset).
 *        [ENG] Sets n bytes of an array to a value (similar to memset).
 *
 * @param[out] ptr           [ESP] Puntero al bloque de memoria a llenar.
 *                           [ENG] Pointer to the memory block to fill.
 * @param[in]  valor         [ESP] Valor con el cual llenar (0–255).
 *                           [ENG] Value to fill with (0–255).
 * @param[in]  nro_de_bytes  [ESP] Cantidad de bytes a setear.
 *                           [ENG] Number of bytes to set.
 * @return                   [ESP] Puntero al bloque de memoria original.
 *                           [ENG] Pointer to the original memory block.
 *
 * @example
 *   char buffer[10];
 *   Mi_Stringmemset(buffer, 0, 10);
 *   // buffer filled with zeros
 */
void *Mi_Stringmemset(void *ptr, unsigned char valor, size_t nro_de_bytes);

/**
 * @brief [ESP] Invierte el orden de los caracteres de un string.
 *        [ENG] Reverses the order of characters in a string.
 *
 * @param[in,out] String  [ESP] String cuyos caracteres se invertirán.
 *                        [ENG] String whose characters will be reversed.
 * @param[in]     length  [ESP] Largo del string (sin contar '\0').
 *                        [ENG] Length of the string (not counting '\0').
 * @return void
 *
 * @example
 *   char text[] = "ABCDE";
 *   Revertir_String(text, 5);
 *   // text == "EDCBA"
 */
void Revertir_String(char *String, int length);

/**
 * @brief [ESP] Analiza si un string es palíndromo (sin importar mayúsculas).
 *        [ENG] Checks whether a string is a palindrome (case-insensitive).
 *
 * @param[in] String  [ESP] String a analizar.
 *                    [ENG] String to analyze.
 * @return            [ESP] true si es palíndromo, false si no lo es.
 *                    [ENG] true if palindrome, false otherwise.
 *
 * @example
 *   bool result = Analisis_Palindromo_String("Ana");
 *   // result == true
 */
bool Analisis_Palindromo_String(char *String);

/**
 * @brief [ESP] Convierte todos los caracteres de un string a minúsculas.
 *        [ENG] Converts all characters in a string to lowercase.
 *
 * @param[in,out] String  [ESP] String a convertir (se modifica in-place).
 *                        [ENG] String to convert (modified in-place).
 * @return void
 *
 * @example
 *   char text[] = "HELLO";
 *   String_lowercase(text);
 *   // text == "hello"
 */
void String_lowercase(char *String);

/**
 * @brief [ESP] Convierte todos los caracteres de un string a mayúsculas.
 *        [ENG] Converts all characters in a string to uppercase.
 *
 * @param[in,out] String  [ESP] String a convertir (se modifica in-place).
 *                        [ENG] String to convert (modified in-place).
 * @return void
 *
 * @example
 *   char text[] = "hello";
 *   String_uppercase(text);
 *   // text == "HELLO"
 */
void String_uppercase(char *String);

/**
 * @brief [ESP] Ordena alfabéticamente un array de strings (selection sort).
 *        [ENG] Sorts a string array alphabetically (selection sort).
 *
 * @param[in,out] ArrayDeStrings      [ESP] Array 2D de strings a ordenar.
 *                                    [ENG] 2D string array to sort.
 * @param[in]     Cantidad_De_Strings [ESP] Cantidad de strings en el array.
 *                                    [ENG] Number of strings in the array.
 * @param[in]     largoMaximoString   [ESP] Largo máximo de cada string.
 *                                    [ENG] Maximum length of each string.
 * @return void
 *
 * @example
 *   char names[3][100] = {"Charlie", "Alice", "Bob"};
 *   Ordenamiento_Array_De_Strings(names, 3, 100);
 *   // names: {"Alice", "Bob", "Charlie"}
 */
void Ordenamiento_Array_De_Strings(char ArrayDeStrings[10][100], int Cantidad_De_Strings, int largoMaximoString);

#endif /* MY_STRINGS_H */
