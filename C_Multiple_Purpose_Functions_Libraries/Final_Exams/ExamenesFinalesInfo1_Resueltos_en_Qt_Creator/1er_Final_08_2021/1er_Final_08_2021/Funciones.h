#ifndef FUNCIONES_H
#define FUNCIONES_H

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

#define ERROR -1
#define EXITO 0
#define _8BITS 8
#define _16BITS 16
#define _24BITS 24
#define _32BITS 32
#define _1BYTE 256
#define _2BYTE 65536
#define _3BYTE 16777216
#define _4BYTE 4294967300
int Convertir_IntArray_To_CharArray(int *IntArray, int Arraylargo, char **Frase);
int ModificarNombreFileIn(char *Nombre_Archivo_In, char *Nombre_Archivo_Out);
int LecturaEnterosDe_4_BytesFileInBinario(char *Nombre_Archivo_In, int **Buffer_enteros);

#endif // FUNCIONES_H
