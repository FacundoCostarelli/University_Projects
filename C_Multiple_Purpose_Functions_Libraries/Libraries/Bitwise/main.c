/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para las funciones de bit_ops.
 *          [ENG] Usage example program for bit_ops functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Este archivo demuestra el uso de PrintBits, GetBit, SetBit y
 *       SetToggle con ejemplos prácticos comentados.
 *
 * [ENG] This file demonstrates the usage of PrintBits, GetBit, SetBit,
 *       and SetToggle with practical commented examples.
 */

#include "bit_ops.h"

int main(void)
{
    unsigned int valor = 0xA5;  /* 10100101 in binary */

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 1: Imprimir representación binaria y hexadecimal
     * [ENG] Example 1: Print binary and hexadecimal representation
     * --------------------------------------------------------------- */
    printf("=== PrintBits ===\n");
    printf("[ESP] Imprimiendo 0xA5 en 8 bits:\n");
    printf("[ENG] Printing 0xA5 in 8 bits:\n");
    PrintBits(valor, 8);
    printf("\n");

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 2: Obtener bits individuales
     * [ENG] Example 2: Get individual bits
     * --------------------------------------------------------------- */
    printf("=== GetBit ===\n");
    printf("[ESP] Bit 0 de 0xA5: %d  (esperado: 1)\n", GetBit(valor, 0));
    printf("[ENG] Bit 0 of 0xA5: %d  (expected: 1)\n", GetBit(valor, 0));
    printf("[ESP] Bit 1 de 0xA5: %d  (esperado: 0)\n", GetBit(valor, 1));
    printf("[ENG] Bit 1 of 0xA5: %d  (expected: 0)\n", GetBit(valor, 1));
    printf("[ESP] Bit 5 de 0xA5: %d  (esperado: 1)\n", GetBit(valor, 5));
    printf("[ENG] Bit 5 of 0xA5: %d  (expected: 1)\n", GetBit(valor, 5));
    printf("\n");

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 3: Establecer bits en ON y OFF
     * [ENG] Example 3: Set bits to ON and OFF
     * --------------------------------------------------------------- */
    printf("=== SetBit ===\n");
    unsigned int resultado;

    /* [ESP] Encender bit 1 de 0xA5 (10100101 → 10100111 = 0xA7)
       [ENG] Turn ON bit 1 of 0xA5 (10100101 → 10100111 = 0xA7) */
    resultado = SetBit(valor, 1, ON);
    printf("[ESP] SetBit(0xA5, 1, ON) = 0x%02X  (esperado: 0xA7)\n", resultado);
    printf("[ENG] SetBit(0xA5, 1, ON) = 0x%02X  (expected: 0xA7)\n", resultado);

    /* [ESP] Apagar bit 0 de 0xA5 (10100101 → 10100100 = 0xA4)
       [ENG] Turn OFF bit 0 of 0xA5 (10100101 → 10100100 = 0xA4) */
    resultado = SetBit(valor, 0, OFF);
    printf("[ESP] SetBit(0xA5, 0, OFF) = 0x%02X  (esperado: 0xA4)\n", resultado);
    printf("[ENG] SetBit(0xA5, 0, OFF) = 0x%02X  (expected: 0xA4)\n", resultado);
    printf("\n");

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 4: Invertir (toggle) bits
     * [ENG] Example 4: Toggle bits
     * --------------------------------------------------------------- */
    printf("=== SetToggle ===\n");

    /* [ESP] Toggle bit 0 de 0xA5 (10100101 → 10100100 = 0xA4)
       [ENG] Toggle bit 0 of 0xA5 (10100101 → 10100100 = 0xA4) */
    resultado = SetToggle(valor, 0);
    printf("[ESP] SetToggle(0xA5, 0) = 0x%02X  (esperado: 0xA4)\n", resultado);
    printf("[ENG] SetToggle(0xA5, 0) = 0x%02X  (expected: 0xA4)\n", resultado);

    /* [ESP] Toggle bit 1 de 0xA5 (10100101 → 10100111 = 0xA7)
       [ENG] Toggle bit 1 of 0xA5 (10100101 → 10100111 = 0xA7) */
    resultado = SetToggle(valor, 1);
    printf("[ESP] SetToggle(0xA5, 1) = 0x%02X  (esperado: 0xA7)\n", resultado);
    printf("[ENG] SetToggle(0xA5, 1) = 0x%02X  (expected: 0xA7)\n", resultado);

    return 0;
}
