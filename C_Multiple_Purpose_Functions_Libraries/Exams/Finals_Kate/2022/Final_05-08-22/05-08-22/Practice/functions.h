/**
 * @file    funciones.h
 * @brief   [ESP] Cabecera de Funciones. Práctica Final 05-08-2022.
 *          [ENG] Header of Functions. Practice Final 05-08-2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#ifndef P_0508_FUNCIONES_H
#define P_0508_FUNCIONES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 200

/**
 * @brief [ESP] Estructura auxiliar de encriptado.
 *        [ENG] Aux struct for encription.
 */
typedef struct encriptado
{
	char txt[MAX];
	int desplazamiento;
} encriptado_t;

/**
 * @brief [ESP] Prototipos de las funciones de encriptación.
 *        [ENG] Prototypes for the encryption functions.
 */
void desencriptar_texto (const char * src, char * dst, int desplazamiento);
int aleatorio (int base, int rango);
int desplazar_letras (const char * src, char * dst);
void encriptar_numeros (const char * src, char * dst);
void octal (int numero, char * str);
void string_reverse (char * str);
int encriptar (const char * src, char * dst);

#endif /* P_0508_FUNCIONES_H */
