/**
 * ==========================================================================
 * my_strings.h — Custom String Functions Library (Header)
 * ==========================================================================
 * [ESP] Declaraciones de funciones personalizadas de manejo de strings.
 *       Incluye funciones de copia, longitud, concatenación, comparación,
 *       memset, reversión, palíndromos, cambio de caso y ordenamiento.
 *
 * [ENG] Declarations for custom string manipulation functions.
 *       Includes copy, length, concatenation, comparison, memset,
 *       reversal, palindrome check, case conversion, and sorting.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#ifndef MIS_FUNCIONES_STRINGS_H
#define MIS_FUNCIONES_STRINGS_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define ERROR -1
#define EXITO 1

// [ESP] Función strcpy propia con la técnica de contadores
// [ENG] Custom strcpy using counter technique
char *Mi_StringCopyV1(char *Destino, const char *Origen);

// [ESP] Función strcpy propia con aritmética de punteros
// [ENG] Custom strcpy using pointer arithmetic
char *Mi_StringCopyV2(char *Destino, const char *Origen);

// [ESP] Función que calcula el largo de un string sin su carácter \0
// [ENG] Function that calculates the length of a string excluding the \0 character
int Mi_StringLength(char *String);

// [ESP] Función que concatena 2 strings con alocación de memoria dinámica.
//       String1 es concatenado con String2 (String2 queda a la derecha de String1).
// [ENG] Concatenates 2 strings using dynamic memory allocation.
//       String1 is concatenated with String2 (String2 goes to the right of String1).
char *Mi_StringConcatenate(char *String1, char *String2);

// [ESP] Función que compara 2 strings independientemente de mayúsculas o minúsculas
// [ENG] Case-insensitive string comparison function
int Mi_StringCaseCompare(const char *String1, const char *String2);

// [ESP] Función que setea n bytes de un array con un valor entero indicado.
//       LIMITACIÓN: Solo puede recibir valores de entre 0 a 255 inclusive.
// [ENG] Sets n bytes of an array to a specified integer value.
//       LIMITATION: Only accepts values between 0 and 255 inclusive.
void *Mi_Stringmemset(void *ptr, unsigned char valor, size_t nro_de_bytes);

// [ESP] Función que invierte/revierte el orden de los caracteres de un string
// [ENG] Reverses the order of characters in a string
void Revertir_String(char *String, int length);

// [ESP] Función que analiza si un string es palíndromo (sin importar mayúsculas/minúsculas)
// [ENG] Checks whether a string is a palindrome (case-insensitive)
bool Analisis_Palindromo_String(char *String);

// [ESP] Función que transforma todos los caracteres de un string a minúsculas
// [ENG] Converts all characters in a string to lowercase
void String_lowercase(char *String);

// [ESP] Función que transforma todos los caracteres de un string a mayúsculas
// [ENG] Converts all characters in a string to uppercase
void String_uppercase(char *String);

// [ESP] Función que ordena alfabéticamente un array de strings
// [ENG] Sorts a string array in alphabetical order
void Ordenamiento_Array_De_Strings(char ArrayDeStrings[10][100], int Cantidad_De_Strings, int largoMaximoString);

#endif // MIS_FUNCIONES_STRINGS_H
