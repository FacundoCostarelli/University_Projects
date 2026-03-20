/**
 * @file    Funciones.h
 * @brief   [ESP] Cabecera de funciones para encriptación. Final 08/2022.
 *          [ENG] Header for string encryption tools. Final 08/2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief [ESP] Constantes de error y macros de logitudes de texto.
 *        [ENG] Error constants and string lengths macros.
 */
#define ERROR -1
#define EXITO 0
#define TXT_MAX_LEN 100

/**
 * @brief [ESP] Estructura que almacena un texto encriptado y su desplazamiento asociado.
 *        [ENG] Structure that packs the encrypted text along with its cypher shifting.
 */
struct texto_encriptado
{
    char txt[TXT_MAX_LEN];
    int desplazamiento;
};

/* [ESP] Prototipos de funciones / [ENG] Function prototypes */
int encriptar_letras(const char *src, char *dst);
int aleatorio_en_rango(int minimo, int maximo);
void encriptar_numeros(char *src, char *dst);
void revertir(char str[], int length);
char* IntToAnString(int num, char* str, int base);

#endif /* FUNCIONES_H */
