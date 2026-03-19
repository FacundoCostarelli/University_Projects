/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para las funciones de string_encrypt.
 *          [ENG] Usage example program for string_encrypt functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "string_encrypt.h"
#include <time.h>

int main(void)
{
    /* [ESP] Inicializar semilla aleatoria para que los resultados varíen
       [ENG] Initialize random seed so results vary between executions */
    srand((unsigned int)time(NULL));

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 1: encriptar_letras — Cifrado César aleatorio
     * [ENG] Example 1: encriptar_letras — Random Caesar cipher
     * --------------------------------------------------------------- */
    printf("=== encriptar_letras ===\n\n");

    char original[] = "HOLA MUNDO";
    char encriptado[TXT_MAX_LEN];

    printf("[ESP] Texto original: %s\n", original);
    printf("[ENG] Original text: %s\n", original);

    int shift = encriptar_letras(original, encriptado);

    printf("[ESP] Texto encriptado: %s\n", encriptado);
    printf("[ENG] Encrypted text:   %s\n", encriptado);
    printf("[ESP] Desplazamiento aplicado: %d\n", shift);
    printf("[ENG] Applied shift: %d\n\n", shift);

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 2: aleatorio_en_rango
     * [ENG] Example 2: aleatorio_en_rango
     * --------------------------------------------------------------- */
    printf("=== aleatorio_en_rango ===\n\n");

    printf("[ESP] 5 numeros aleatorios entre 1 y 100:\n");
    printf("[ENG] 5 random numbers between 1 and 100:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("  %d", aleatorio_en_rango(1, 100));
    }
    printf("\n\n");

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 3: encriptar_numeros — Sustitución octal
     * [ENG] Example 3: encriptar_numeros — Octal substitution
     * --------------------------------------------------------------- */
    printf("=== encriptar_numeros ===\n\n");

    printf("[ESP] Tabla de sustitución (dígito octal → símbolo):\n");
    printf("[ENG] Substitution table (octal digit → symbol):\n");
    printf("  0→$  1→%%  2→&  3→*  4→@  5→!  6→+  7→=\n\n");

    char texto_mixto[] = "ABC123";
    char resultado[TXT_MAX_LEN];
    memset(resultado, '\0', TXT_MAX_LEN);

    printf("[ESP] Texto original: %s\n", texto_mixto);
    printf("[ENG] Original text: %s\n", texto_mixto);

    /* [ESP] Primero copiamos el texto original al resultado
       [ENG] First copy the original text to the result */
    strcpy(resultado, texto_mixto);
    encriptar_numeros(texto_mixto, resultado);

    printf("[ESP] Texto con numeros encriptados: %s\n", resultado);
    printf("[ENG] Text with encrypted numbers:   %s\n", resultado);
    printf("[ESP] (123 decimal → 173 octal → #%%=*#)\n");
    printf("[ENG] (123 decimal → 173 octal → #%%=*#)\n");

    return 0;
}
