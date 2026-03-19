/**
 * @file    string_encrypt.h
 * @brief   [ESP] Biblioteca de encriptación de strings.
 *          [ENG] String encryption library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Proporciona funciones para encriptar strings con dos métodos:
 *       cifrado César aleatorio para letras y sustitución simbólica
 *       basada en conversión octal para números.
 *
 * [ENG] Provides functions to encrypt strings with two methods:
 *       random Caesar cipher for letters and symbolic substitution
 *       based on octal conversion for numbers.
 */

#ifndef STRING_ENCRYPT_H
#define STRING_ENCRYPT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @brief [ESP] Largo máximo de texto / [ENG] Maximum text length */
#define TXT_MAX_LEN 256

/**
 * @brief [ESP] Encripta letras mayúsculas con un desplazamiento César aleatorio.
 *        [ENG] Encrypts uppercase letters with a random Caesar shift.
 *
 * [ESP] Recorre el string fuente carácter a carácter. Las letras mayúsculas
 *       se desplazan una cantidad aleatoria de posiciones (1–25). Los espacios,
 *       dígitos y '#' se copian sin modificar.
 *
 * [ENG] Iterates through the source string character by character. Uppercase
 *       letters are shifted by a random amount (1–25). Spaces, digits, and
 *       '#' are copied unmodified.
 *
 * @param[in]  src  [ESP] String fuente en MAYÚSCULAS a encriptar.
 *                  [ENG] Source UPPERCASE string to encrypt.
 * @param[out] dst  [ESP] Buffer de salida con el resultado encriptado.
 *                        Debe tener al menos strlen(src) + 1 bytes.
 *                  [ENG] Output buffer for the encrypted result.
 *                        Must have at least strlen(src) + 1 bytes.
 * @return          [ESP] Valor del desplazamiento alfabético aplicado (1–25).
 *                  [ENG] The alphabetic shift value applied (1–25).
 *
 * @example
 *   char resultado[100];
 *   int shift = encriptar_letras("HOLA MUNDO", resultado);
 *   printf("Shift: %d, Encrypted: %s\n", shift, resultado);
 */
int encriptar_letras(const char *src, char *dst);

/**
 * @brief [ESP] Encripta dígitos numéricos sustituyéndolos por símbolos.
 *        [ENG] Encrypts numeric digits by substituting them with symbols.
 *
 * [ESP] Convierte cada grupo de dígitos decimales a su representación octal
 *       y reemplaza cada dígito octal con un símbolo, encerrado entre '#':
 *       0→$, 1→%, 2→&, 3→*, 4→@, 5→!, 6→+, 7→=
 *
 * [ENG] Converts each group of decimal digits to octal representation
 *       and replaces each octal digit with a symbol, enclosed in '#':
 *       0→$, 1→%, 2→&, 3→*, 4→@, 5→!, 6→+, 7→=
 *
 * @param[in]  src  [ESP] String fuente con letras y/o números.
 *                  [ENG] Source string with letters and/or numbers.
 * @param[out] dst  [ESP] Buffer de salida con los números encriptados.
 *                        Debe tener espacio suficiente para la expansión.
 *                  [ENG] Output buffer with encrypted numbers.
 *                        Must have enough space for the expansion.
 * @return void
 *
 * @example
 *   char resultado[256];
 *   encriptar_numeros("ABC123DEF", resultado);
 *   // [ESP] Los dígitos "123" → octal "173" → "#%=*#"
 *   // [ENG] Digits "123" → octal "173" → "#%=*#"
 */
void encriptar_numeros(char *src, char *dst);

/**
 * @brief [ESP] Genera un número aleatorio entero dentro de un rango inclusivo.
 *        [ENG] Generates a random integer within an inclusive range.
 *
 * @param[in] minimo  [ESP] Valor mínimo del rango (incluido).
 *                    [ENG] Minimum range value (inclusive).
 * @param[in] maximo  [ESP] Valor máximo del rango (incluido).
 *                    [ENG] Maximum range value (inclusive).
 * @return            [ESP] Número aleatorio entre minimo y maximo.
 *                    [ENG] Random number between minimo and maximo.
 *
 * @example
 *   int r = aleatorio_en_rango(1, 25);
 *   // r ∈ [1, 25]
 */
int aleatorio_en_rango(int minimo, int maximo);

#endif /* STRING_ENCRYPT_H */
