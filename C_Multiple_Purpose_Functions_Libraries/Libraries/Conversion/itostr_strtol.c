/**
 * @file    itostr_strtol.c
 * @brief   [ESP] Implementación de funciones de conversión entero ↔ string.
 *          [ENG] Implementation of integer ↔ string conversion functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Nota de referencia: para la conversión inversa (string → entero),
 *       se puede utilizar la función estándar strtol():
 *         int valor = (int)strtol("123", &endptr, 10);
 *       Y para entero → string en bases estándar, sprintf():
 *         sprintf(buffer, "%o", 255);  // "377" (octal)
 *
 * [ENG] Reference note: for the reverse conversion (string → integer),
 *       the standard function strtol() can be used:
 *         int value = (int)strtol("123", &endptr, 10);
 *       And for integer → string in standard bases, sprintf():
 *         sprintf(buffer, "%o", 255);  // "377" (octal)
 */

#include "itostr_strtol.h"

/**
 * @brief [ESP] Invierte el orden de los caracteres de un string in-place.
 *        [ENG] Reverses the character order of a string in-place.
 */
void revertir(char str[], int length)
{
    int start = 0;
    int end = length - 1;

    /* [ESP] Intercambiamos caracteres desde los extremos hacia el centro.
             Usamos una variable temporal 'temp' para el swap.
       [ENG] Swap characters from both ends towards the center.
             We use a temporary variable 'temp' for the swap. */
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

/**
 * @brief [ESP] Convierte un entero a formato string en la base especificada.
 *        [ENG] Converts an integer to string format in the specified base.
 */
char *IntToAnString(int num, char *str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* [ESP] Caso especial: si num es 0, el string resultante es simplemente "0".
       [ENG] Special case: if num is 0, the resulting string is simply "0". */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    /* [ESP] Si num es negativo y la base es 10, guardamos el signo.
             Para bases 2, 8 y 16, num se trata como unsigned.
       [ENG] If num is negative and the base is 10, we save the sign.
             For bases 2, 8, and 16, num is treated as unsigned. */
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    /* [ESP] Extraemos los dígitos uno por uno mediante módulo (%) y división.
             Los dígitos se almacenan en orden inverso (LSB primero).
             Para bases > 10 (ej: hexadecimal), los restos > 9 se convierten
             a letras minúsculas ('a' = 10, 'b' = 11, ..., 'f' = 15).
       [ENG] Extract digits one by one using modulus (%) and division.
             Digits are stored in reverse order (LSB first).
             For bases > 10 (e.g., hexadecimal), remainders > 9 are converted
             to lowercase letters ('a' = 10, 'b' = 11, ..., 'f' = 15). */
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    /* [ESP] Si el número era negativo (base 10), agregamos el carácter '-'.
       [ENG] If the number was negative (base 10), we add the '-' character. */
    if (isNegative)
        str[i++] = '-';

    /* [ESP] Terminamos el string con el carácter nulo.
       [ENG] Terminate the string with the null character. */
    str[i] = '\0';

    /* [ESP] Invertimos el string porque los dígitos fueron almacenados al revés.
       [ENG] Reverse the string because digits were stored in reverse order. */
    revertir(str, i);

    return str;
}
