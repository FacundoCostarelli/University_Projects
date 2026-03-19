/**
 * @file    bit_ops.c
 * @brief   [ESP] Implementación de funciones de operaciones a nivel de bits.
 *          [ENG] Implementation of bitwise operation functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "bit_ops.h"

/**
 * @brief [ESP] Imprime la representación binaria y hexadecimal de un dato.
 *        [ENG] Prints the binary and hexadecimal representation of a value.
 */
void PrintBits(unsigned int dato, char nro_de_bit)
{
    /* [ESP] Ajustamos el índice: si tenemos 8 bits, el más alto es bit 7
       [ENG] Adjust index: if we have 8 bits, the highest is bit 7 */
    nro_de_bit--;

    /* [ESP] Imprimimos cada bit desde el MSB hasta el LSB
       [ENG] Print each bit from MSB down to LSB */
    printf("b:");
    for ( ; nro_de_bit >= 0; nro_de_bit--)
        printf("%d", GetBit(dato, nro_de_bit));

    /* [ESP] Imprimimos el valor en formato hexadecimal
       [ENG] Print the value in hexadecimal format */
    printf("\nEn hexadecimal / In hexadecimal: (0x%02X) \n", dato);

    return;
}

/**
 * @brief [ESP] Obtiene el valor de un bit específico de un dato.
 *        [ENG] Gets the value of a specific bit from a value.
 */
unsigned char GetBit(unsigned int dato, char bit)
{
    unsigned char resultado, mascara = 1;

    /* [ESP] Desplazamos el dato 'bit' posiciones a la derecha y aplicamos
             AND con la máscara (0x01) para aislar el bit deseado.
       [ENG] Shift the value 'bit' positions to the right and apply
             AND with the mask (0x01) to isolate the desired bit. */
    resultado = (dato >> bit) & mascara;

    return resultado;
}

/**
 * @brief [ESP] Establece un bit específico en ON (1) o OFF (0).
 *        [ENG] Sets a specific bit to ON (1) or OFF (0).
 */
unsigned int SetBit(unsigned int dato, char bit, char estado)
{
    unsigned int resultado, mascara = 1;

    /* [ESP] Desplazamos la máscara a la posición del bit deseado
       [ENG] Shift the mask to the desired bit position */
    mascara = mascara << bit;

    if (estado == OFF)
    {
        /* [ESP] Para apagar un bit: invertimos la máscara (~) y aplicamos AND.
                 Esto pone en 0 únicamente el bit seleccionado.
           [ENG] To turn a bit OFF: invert the mask (~) and apply AND.
                 This clears only the selected bit. */
        mascara = ~mascara;
        resultado = dato & mascara;
    }
    else
    {
        /* [ESP] Para encender un bit: aplicamos OR con la máscara.
                 Esto pone en 1 únicamente el bit seleccionado.
           [ENG] To turn a bit ON: apply OR with the mask.
                 This sets only the selected bit. */
        resultado = dato | mascara;
    }

    return resultado;
}

/**
 * @brief [ESP] Invierte (toggle) el valor de un bit específico.
 *        [ENG] Toggles (inverts) the value of a specific bit.
 */
unsigned int SetToggle(unsigned int dato, char bit)
{
    unsigned int resultado, mascara = 1;

    /* [ESP] Desplazamos la máscara a la posición del bit deseado
             y aplicamos XOR. El XOR invierte: 0→1 o 1→0.
       [ENG] Shift the mask to the desired bit position
             and apply XOR. XOR inverts: 0→1 or 1→0. */
    mascara = mascara << bit;
    resultado = dato ^ mascara;

    return resultado;
}
