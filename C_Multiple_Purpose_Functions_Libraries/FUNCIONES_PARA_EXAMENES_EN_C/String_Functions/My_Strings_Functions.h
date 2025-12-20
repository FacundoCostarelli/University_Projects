#ifndef MIS_FUNCIONES_STRINGS_H
#define MIS_FUNCIONES_STRINGS_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define ERROR -1
#define EXITO 1
//Funcion strcpy propia con la tecnica de contadores
char *Mi_StringCopyV1(char *Destino, const char *Origen);
//Funcion strcpy propia con aritmetica de punteros
char *Mi_StringCopyV2(char *Destino, const char *Origen);
//Funcion que calcula el largo de un string sin su caracter \0
int Mi_StringLength(char *String);
//Funcion que concatena 2 strings con allocacion de memoria dinamica. String1 es concatenado con String2
//Donde String2 se encuentra a la derecha de String1
char *Mi_StringConcatenate(char *String1, char *String2);
//Funcion que comoara 2 strings independientemente de si los caracteres estan en minuscula o mayuscula
int Mi_StringCaseCompare(const char *String1, const char *String2);
//Funcion que setea n bytes de un array con un valor entero indicado
//LIMITACION: Solo puede recibir valores de entre 0 a 255 inclusive
void *Mi_Stringmemset(void *ptr, unsigned char valor, size_t nro_de_bytes);
//Funcion que realiza una "inversion o reversion" del orden de los caracteres de un string
void Revertir_String(char *String, int length);
//Funcion que analisa si un string es palindromo o no sin importar mayusculas y minusculas
bool Analisis_Palindromo_String(char *String);
//Funcion que transforma todos los caracteres de un string a minusculas
void String_lowercase(char *String);
//Funcion que transforma todos los caracteres de un string a mayusculas
void String_uppercase(char *String);
//Funcion que ordena alfabeticamente un array de strings
void Ordenamiento_Array_De_Strings(char ArrayDeStrings[10][100], int Cantidad_De_Strings, int largoMaximoString);
#endif // MIS_FUNCIONES_STRINGS_H
