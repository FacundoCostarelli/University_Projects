/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para operaciones matriciales dinámicas.
 *          [ENG] Usage example program for dynamic matrix operations.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Demuestra la creación, carga con datos predeterminados,
 *       visualización y liberación de matrices dinámicas de doubles.
 *
 * [ENG] Demonstrates creation, loading with predetermined data,
 *       display, and deallocation of dynamic double matrices.
 */

#include "matrix_ops.h"

int main(void)
{
    int filas = 3, columnas = 3;
    double **M = NULL;
    int i, j;

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 1: Crear una matriz dinámica 3×3
     * [ENG] Example 1: Create a 3×3 dynamic matrix
     * --------------------------------------------------------------- */
    printf("=== [ESP] Creando matriz 3x3 ===\n");
    printf("=== [ENG] Creating 3x3 matrix ===\n\n");

    M = crearmatrizcondatos(&M, filas, columnas);

    if (M == NULL)
    {
        printf("[ESP] Error creando la matriz.\n");
        printf("[ENG] Error creating matrix.\n");
        return -1;
    }

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 2: Cargar datos predeterminados (sin teclado)
     *       Llenamos la matriz con valores para demostración.
     * [ENG] Example 2: Load predetermined data (no keyboard input)
     *       Fill the matrix with values for demonstration.
     * --------------------------------------------------------------- */
    printf("[ESP] Cargando datos predeterminados...\n");
    printf("[ENG] Loading predetermined data...\n\n");

    double counter = 1.0;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            M[i][j] = counter;
            counter += 1.5;
        }
    }

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 3: Mostrar la matriz
     * [ENG] Example 3: Display the matrix
     * --------------------------------------------------------------- */
    printf("[ESP] Contenido de la matriz:\n");
    printf("[ENG] Matrix contents:\n\n");

    for (i = 0; i < filas; i++)
    {
        printf("  | ");
        for (j = 0; j < columnas; j++)
            printf("%6.1f ", M[i][j]);
        printf("|\n");
    }

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 4: Liberar la matriz
     * [ENG] Example 4: Free the matrix
     * --------------------------------------------------------------- */
    printf("\n[ESP] Liberando la matriz...\n");
    printf("[ENG] Freeing the matrix...\n");

    liberarmatriz(&M, filas);

    printf("[ESP] Matriz liberada exitosamente.\n");
    printf("[ENG] Matrix freed successfully.\n");

    return 0;
}
