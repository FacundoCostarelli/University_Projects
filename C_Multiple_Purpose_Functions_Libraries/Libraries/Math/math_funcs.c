/**
 * @file    math_funcs.c
 * @brief   [ESP] Implementación de funciones matemáticas personalizadas.
 *          [ENG] Implementation of custom mathematical functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "math_funcs.h"

/**
 * @brief [ESP] Función de ejemplo #1: f(x) = x + 10.
 *        [ENG] Example function #1: f(x) = x + 10.
 */
float NomFun1(float x)
{
    return x + 10;
}

/**
 * @brief [ESP] Función de ejemplo #2: g(x) = x * 15.50.
 *        [ENG] Example function #2: g(x) = x * 15.50.
 */
float NomFun2(float x)
{
    return x * 15.50;
}

/**
 * @brief [ESP] Calcula la composición f(g(x)) y almacena resultados en un array 2D.
 *        [ENG] Computes composition f(g(x)) and stores results in a 2D array.
 */
float **ComposicionDeFunciones(float (*ptr_fun1)(float), float (*ptr_fun2)(float))
{
    /* [ESP] Variables para el rango y cantidad de puntos
       [ENG] Variables for range and number of points */
    float Xmin = 0, Xmax = 0, x = 0;
    int nro_de_puntos = 0;
    int i = 0;

    /* [ESP] Puntero doble para el array 2D dinámico (filas × 2 columnas)
       [ENG] Double pointer for the dynamic 2D array (rows × 2 columns) */
    float **Filas = NULL;

    /* [ESP] Solicitar datos de entrada al usuario
       [ENG] Request input data from the user */
    printf("[ESP] Ingrese valor de abscisa minima / [ENG] Enter minimum x value: ");
    scanf("%f", &Xmin);

    printf("[ESP] Ingrese valor de abscisa maxima / [ENG] Enter maximum x value: ");
    scanf("%f", &Xmax);

    printf("[ESP] Ingrese el nro de puntos / [ENG] Enter the number of points: ");
    scanf("%d", &nro_de_puntos);

    /* [ESP] Crear dinámicamente el array de punteros a filas.
             Se aloca nro_de_puntos + 1 para incluir el centinela NULL al final.
       [ENG] Dynamically create the array of row pointers.
             Allocate nro_de_puntos + 1 to include the NULL sentinel at the end. */
    Filas = (float **)malloc((nro_de_puntos + 1) * sizeof(float *));
    if (Filas == NULL)
    {
        printf("[ESP] Error: memoria insuficiente para filas.\n");
        printf("[ENG] Error: insufficient memory for rows.\n");
        exit(ERROR);
    }

    /* [ESP] El último elemento se marca como NULL (centinela de fin de array)
       [ENG] The last element is marked as NULL (end-of-array sentinel) */
    Filas[nro_de_puntos] = NULL;

    /* [ESP] Para cada fila, alocar un array de 2 columnas: [x, f(g(x))]
       [ENG] For each row, allocate a 2-column array: [x, f(g(x))] */
    for (i = 0; i < nro_de_puntos; i++)
    {
        Filas[i] = (float *)malloc(2 * sizeof(float));
        if (Filas[i] == NULL)
        {
            printf("[ESP] Error: memoria insuficiente para fila %d.\n", i);
            printf("[ENG] Error: insufficient memory for row %d.\n", i);
            exit(ERROR);
        }
    }

    /* [ESP] Calcular la composición f(g(x)) para cada punto en el rango [Xmin, Xmax].
             El paso (step) entre puntos es (Xmax - Xmin) / nro_de_puntos.
       [ENG] Compute the composition f(g(x)) for each point in range [Xmin, Xmax].
             The step between points is (Xmax - Xmin) / nro_de_puntos. */
    for (x = Xmin, i = 0; x <= Xmax; x += ((Xmax - Xmin) / nro_de_puntos), i++)
    {
        /* [ESP] Protección: no escribir más allá del último elemento válido
           [ENG] Guard: do not write past the last valid element */
        if (Filas[i] == NULL)
            break;

        Filas[i][0] = x;                       /* [ESP] Abscisa / [ENG] X value */
        Filas[i][1] = ptr_fun1(ptr_fun2(x));    /* [ESP] Ordenada: f(g(x)) / [ENG] Y value: f(g(x)) */
    }

    /* [ESP] Imprimir tabla de resultados
       [ENG] Print results table */
    printf("\n  X         |   Y = f(g(x))\n");
    printf("------------|---------------\n");
    for (i = 0; i < nro_de_puntos; i++)
    {
        printf("  %8.2f  |   %8.2f\n", Filas[i][0], Filas[i][1]);
    }

    /* [ESP] NOTA: El llamador debe liberar la memoria retornada.
       [ENG] NOTE: The caller must free the returned memory. */
    return Filas;
}
