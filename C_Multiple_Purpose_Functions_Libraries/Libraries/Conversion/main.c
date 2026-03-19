/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para las funciones de itostr_strtol.
 *          [ENG] Usage example program for itostr_strtol functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "itostr_strtol.h"
#include <string.h>

int main(void)
{
    char buffer[33];

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 1: IntToAnString — Conversión a distintas bases
     * [ENG] Example 1: IntToAnString — Conversion to different bases
     * --------------------------------------------------------------- */
    printf("=== IntToAnString ===\n\n");

    /* [ESP] Convertir 255 a base 10, 16, 8 y 2
       [ENG] Convert 255 to base 10, 16, 8, and 2 */
    IntToAnString(255, buffer, 10);
    printf("[ESP] 255 en base 10: %s   (esperado: 255)\n", buffer);
    printf("[ENG] 255 in base 10: %s   (expected: 255)\n\n", buffer);

    IntToAnString(255, buffer, 16);
    printf("[ESP] 255 en base 16: %s    (esperado: ff)\n", buffer);
    printf("[ENG] 255 in base 16: %s    (expected: ff)\n\n", buffer);

    IntToAnString(255, buffer, 8);
    printf("[ESP] 255 en base  8: %s   (esperado: 377)\n", buffer);
    printf("[ENG] 255 in base  8: %s   (expected: 377)\n\n", buffer);

    IntToAnString(255, buffer, 2);
    printf("[ESP] 255 en base  2: %s  (esperado: 11111111)\n", buffer);
    printf("[ENG] 255 in base  2: %s  (expected: 11111111)\n\n", buffer);

    /* [ESP] Convertir número negativo en base 10
       [ENG] Convert negative number in base 10 */
    IntToAnString(-42, buffer, 10);
    printf("[ESP] -42 en base 10: %s   (esperado: -42)\n", buffer);
    printf("[ENG] -42 in base 10: %s   (expected: -42)\n\n", buffer);

    /* [ESP] Convertir cero
       [ENG] Convert zero */
    IntToAnString(0, buffer, 10);
    printf("[ESP]   0 en base 10: %s     (esperado: 0)\n", buffer);
    printf("[ENG]   0 in base 10: %s     (expected: 0)\n\n", buffer);

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 2: revertir — Invertir un string
     * [ENG] Example 2: revertir — Reverse a string
     * --------------------------------------------------------------- */
    printf("=== revertir ===\n\n");

    char texto[] = "ABCDE";
    printf("[ESP] Original: %s\n", texto);
    printf("[ENG] Original: %s\n", texto);

    revertir(texto, (int)strlen(texto));
    printf("[ESP] Invertido: %s  (esperado: EDCBA)\n", texto);
    printf("[ENG] Reversed:  %s  (expected: EDCBA)\n\n", texto);

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 3: strtol — Referencia de uso (stdlib.h)
     * [ENG] Example 3: strtol — Usage reference (stdlib.h)
     * --------------------------------------------------------------- */
    printf("=== strtol (stdlib.h reference) ===\n\n");

    char *endptr;
    int valor;

    /* [ESP] Convertir string "123" a entero en base 10
       [ENG] Convert string "123" to integer in base 10 */
    valor = (int)strtol("123", &endptr, 10);
    printf("[ESP] strtol(\"123\", base 10) = %d  (esperado: 123)\n", valor);
    printf("[ENG] strtol(\"123\", base 10) = %d  (expected: 123)\n\n", valor);

    /* [ESP] Convertir string "FF" a entero en base 16
       [ENG] Convert string "FF" to integer in base 16 */
    valor = (int)strtol("FF", &endptr, 16);
    printf("[ESP] strtol(\"FF\", base 16) = %d  (esperado: 255)\n", valor);
    printf("[ENG] strtol(\"FF\", base 16) = %d  (expected: 255)\n\n", valor);

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 4: sprintf — Referencia de uso (stdio.h)
     * [ENG] Example 4: sprintf — Usage reference (stdio.h)
     * --------------------------------------------------------------- */
    printf("=== sprintf (stdio.h reference) ===\n\n");

    /* [ESP] Convertir 255 a string octal con sprintf
       [ENG] Convert 255 to octal string with sprintf */
    sprintf(buffer, "%o", 255);
    printf("[ESP] sprintf(255, octal) = \"%s\"  (esperado: 377)\n", buffer);
    printf("[ENG] sprintf(255, octal) = \"%s\"  (expected: 377)\n\n", buffer);

    /* [ESP] Convertir 255 a string hexadecimal con sprintf
       [ENG] Convert 255 to hexadecimal string with sprintf */
    sprintf(buffer, "%x", 255);
    printf("[ESP] sprintf(255, hex) = \"%s\"  (esperado: ff)\n", buffer);
    printf("[ENG] sprintf(255, hex) = \"%s\"  (expected: ff)\n", buffer);

    return 0;
}
