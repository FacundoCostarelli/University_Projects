/**
 * @file    Funciones.c
 * @brief   [ESP] Archivo fuente de composición de funciones matemáticas. Final 06/2021.
 *          [ENG] Math functions composition source file. Final 06/2021.
 *
 * @author  Facundo Costarelli
 * @date    2021
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Funciones de ejemplo que forman la composición de funciones (Función 1).
 *        [ENG] Sample functions that make up the function composition (Function 1).
 */
float NomFun1(float x)
{
    return x + 10;
}

/**
 * @brief [ESP] Funciones de ejemplo que forman la composición de funciones (Función 2).
 *        [ENG] Sample functions that make up the function composition (Function 2).
 */
float NomFun2(float x)
{
    return x * 15.50;
}

/**
 * @brief [ESP] Item a) Calcula composición de funciones asignando un vector bidimensional al heap.
 *        [ENG] Item a) Calculates function composition allocating a 2D array on the heap.
 *
 * @param ptr_fun1 [ESP] Puntero a función 1 / [ENG] Pointer to function 1
 * @param ptr_fun2 [ESP] Puntero a función 2 / [ENG] Pointer to function 2
 * @return float** [ESP] Matriz 2D con resultados / [ENG] 2D matrix holding the results
 */
float ** ComposicionDeFunciones(float(*ptr_fun1)(float), float(*ptr_fun2)(float))
{
    float Xmin = 0, Xmax = 0, x = 0;
    int nro_de_puntos = 0;
    int i = 0;

    /* [ESP] Punteros para armar un array de 2D dinamico / [ENG] Double pointer for dynamic 2D array */
    float **Filas = NULL;

    printf("Ingrese valor de abscisa minima: ");
    scanf("%f", &Xmin);
    __fpurge(stdin);

    printf("Ingrese valor de abscisa maxima: ");
    scanf("%f", &Xmax);
    __fpurge(stdin);

    printf("Ingrese el nro de puntos obtener: ");
    scanf("%d", &nro_de_puntos);
    __fpurge(stdin);

    Filas = (float **)malloc( (nro_de_puntos + 1) * sizeof(float *) );
    if(Filas == NULL)
    {
        printf("Error durante la asignacion de memoria dinamica para el array de ptrs a FIlas\n");
        exit(ERROR);
    }

    Filas[nro_de_puntos] = NULL;

    for( i = 0; i < nro_de_puntos; i++ )
    {
        Filas[i] = (float *)malloc( 2 * sizeof(float) );
        if(Filas[i] == NULL)
        {
            printf("Error durante asignacion de memoria dinamica el array de 2 columnas en la fila %d\n", i);
            exit(ERROR);
        }
    }
    printf("Linea 65 ok\n");

    for(x = Xmin, i = 0; x <= Xmax; x += ((Xmax - Xmin) / nro_de_puntos), i++)
    {
        if( Filas[i] == NULL )
            break;
        else
        {
            Filas[i][0] = x;
            Filas[i][1] = ptr_fun1(ptr_fun2(x));
        }
    }

    printf("Linea 75 ok\n");
    printf("TABLA: X      |   Y\n");

    for( i = 0; i < nro_de_puntos; i++ )
    {
        printf("       %.2f   |   %.2f\n", Filas[i][0], Filas[i][1]);
    }

    return Filas;
}

/* 
 * Item b)
 * [ESP] Documentación sobre el uso de arreglos bi-dimensionales y liberación de memoria.
 * [ENG] Documentation about bi-dimensional array usage and memory release logic.
 *
 * Para llamarla hay que pasarle el nombre de 2 funciones a componerse y recibir lo devuelto en un puntero doble.
 * Para acceder a los datos habria que utilizar un ciclo for y usar el puntero doble con la sintaxis de un array de 2D,
 * Filas[indicefila][indicecolumna].
 * 
 * Para liberar:
 * //Libero las columnas
 * for( i = 0; Filas[i] != NULL; i++ ) free(Filas[i]);
 * //Libero las filas
 * free(Filas);
 */
