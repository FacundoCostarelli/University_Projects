/**
 * @file    bit_ops.h
 * @brief   [ESP] Biblioteca de operaciones a nivel de bits.
 *          [ENG] Bitwise operation utilities library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Proporciona funciones para manipular bits individuales de un dato
 *       entero sin signo: imprimir en binario, obtener, establecer e
 *       invertir bits específicos usando máscaras y operadores bitwise.
 *
 * [ENG] Provides functions to manipulate individual bits of an unsigned
 *       integer: print in binary, get, set, and toggle specific bits
 *       using masks and bitwise operators.
 */

#ifndef BIT_OPS_H
#define BIT_OPS_H

#include <stdio.h>

/** @brief [ESP] Estado de bit encendido / [ENG] Bit ON state */
#define ON  1
/** @brief [ESP] Estado de bit apagado / [ENG] Bit OFF state */
#define OFF 0

/**
 * @brief [ESP] Imprime la representación binaria y hexadecimal de un dato.
 *        [ENG] Prints the binary and hexadecimal representation of a value.
 *
 * @param[in] dato        [ESP] Valor entero sin signo a representar.
 *                        [ENG] Unsigned integer value to represent.
 * @param[in] nro_de_bit  [ESP] Cantidad de bits a imprimir (ej: 8, 16, 32).
 *                        [ENG] Number of bits to print (e.g., 8, 16, 32).
 * @return void
 *
 * @example
 *   PrintBits(0xA5, 8);
 *   // [ESP] Salida: b:10100101
 *   //               En hexadecimal: (0xA5)
 *   // [ENG] Output: b:10100101
 *   //               In hexadecimal: (0xA5)
 */
void PrintBits(unsigned int dato, char nro_de_bit);

/**
 * @brief [ESP] Obtiene el valor de un bit específico de un dato.
 *        [ENG] Gets the value of a specific bit from a value.
 *
 * @param[in] dato  [ESP] Valor entero sin signo del cual obtener el bit.
 *                  [ENG] Unsigned integer value to extract the bit from.
 * @param[in] bit   [ESP] Posición del bit a obtener (0 = LSB).
 *                  [ENG] Bit position to retrieve (0 = LSB).
 * @return          [ESP] 0 si el bit está apagado, 1 si está encendido.
 *                  [ENG] 0 if the bit is OFF, 1 if the bit is ON.
 *
 * @example
 *   unsigned char val = GetBit(0xA5, 5);
 *   // val == 1   (bit 5 of 0xA5 = 10100101 is 1)
 */
unsigned char GetBit(unsigned int dato, char bit);

/**
 * @brief [ESP] Establece un bit específico en ON (1) o OFF (0).
 *        [ENG] Sets a specific bit to ON (1) or OFF (0).
 *
 * @param[in] dato    [ESP] Valor original a modificar.
 *                    [ENG] Original value to modify.
 * @param[in] bit     [ESP] Posición del bit a modificar (0 = LSB).
 *                    [ENG] Bit position to modify (0 = LSB).
 * @param[in] estado  [ESP] Estado deseado: ON (1) o OFF (0).
 *                    [ENG] Desired state: ON (1) or OFF (0).
 * @return            [ESP] Nuevo valor con el bit modificado.
 *                    [ENG] New value with the modified bit.
 *
 * @example
 *   unsigned int result = SetBit(0x00, 3, ON);
 *   // result == 0x08  (bit 3 set to 1 → 00001000)
 *
 *   result = SetBit(0xFF, 0, OFF);
 *   // result == 0xFE  (bit 0 cleared → 11111110)
 */
unsigned int SetBit(unsigned int dato, char bit, char estado);

/**
 * @brief [ESP] Invierte (toggle) el valor de un bit específico.
 *        [ENG] Toggles (inverts) the value of a specific bit.
 *
 * @param[in] dato  [ESP] Valor original a modificar.
 *                  [ENG] Original value to modify.
 * @param[in] bit   [ESP] Posición del bit a invertir (0 = LSB).
 *                  [ENG] Bit position to toggle (0 = LSB).
 * @return          [ESP] Nuevo valor con el bit invertido.
 *                  [ENG] New value with the toggled bit.
 *
 * @example
 *   unsigned int result = SetToggle(0xA5, 0);
 *   // result == 0xA4  (bit 0 toggled: 10100101 → 10100100)
 */
unsigned int SetToggle(unsigned int dato, char bit);

#endif /* BIT_OPS_H */
