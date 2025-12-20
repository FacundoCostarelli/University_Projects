#ifndef FUNCIONES_H
#define FUNCIONES_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#define ERROR -1
#define EXITO 0
#define TXT_MAX_LEN 100

struct texto_encriptado
{
    char txt[TXT_MAX_LEN];
    int desplazamiento;
};

int encriptar_letras(const char *src, char *dst);
int aleatorio_en_rango(int minimo, int maximo);
void encriptar_numeros(/*const*/ char *src, char *dst);
void revertir(char str[], int length);
char* IntToAnString(int num, char* str, int base);

#endif // FUNCIONES_H
