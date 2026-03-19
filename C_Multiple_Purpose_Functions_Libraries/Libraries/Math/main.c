/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para las funciones de math_funcs.
 *          [ENG] Usage example program for math_funcs functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Demuestra el uso de ComposicionDeFunciones con las funciones
 *       de ejemplo NomFun1 y NomFun2, incluyendo la liberación de memoria.
 *
 * [ENG] Demonstrates usage of ComposicionDeFunciones with example
 *       functions NomFun1 and NomFun2, including memory deallocation.
 */

#include "math_funcs.h"

int main(void)
{
    int i;

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo: Composición f(g(x)) donde f(x)=x+10, g(x)=x*15.50
     *       Resultado: f(g(x)) = (x * 15.50) + 10
     * [ENG] Example: Composition f(g(x)) where f(x)=x+10, g(x)=x*15.50
     *       Result: f(g(x)) = (x * 15.50) + 10
     * --------------------------------------------------------------- */
    printf("=== ComposicionDeFunciones ===\n");
    printf("[ESP] Composicion: f(g(x)) = (x * 15.50) + 10\n");
    printf("[ENG] Composition: f(g(x)) = (x * 15.50) + 10\n\n");

    /* [ESP] Llamamos a la función; el usuario ingresará Xmin, Xmax y nro_de_puntos
       [ENG] Call the function; the user will enter Xmin, Xmax, and nro_de_puntos */
    float **tabla = ComposicionDeFunciones(NomFun1, NomFun2);

    /* ---------------------------------------------------------------
     * [ESP] Liberación de memoria dinámica
     *       1) Liberar cada fila (array de 2 columnas)
     *       2) Liberar el array de punteros a filas
     * [ENG] Dynamic memory deallocation
     *       1) Free each row (2-column array)
     *       2) Free the array of row pointers
     * --------------------------------------------------------------- */
    printf("\n[ESP] Liberando memoria dinamica...\n");
    printf("[ENG] Freeing dynamic memory...\n");

    for (i = 0; tabla[i] != NULL; i++)
        free(tabla[i]);

    free(tabla);

    printf("[ESP] Memoria liberada exitosamente.\n");
    printf("[ENG] Memory freed successfully.\n");

    return EXITO;
}
