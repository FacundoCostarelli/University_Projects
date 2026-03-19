/**
 * @file    matrix_ops.h
 * @brief   [ESP] Biblioteca de operaciones matriciales con memoria dinámica.
 *          [ENG] Dynamic matrix operations library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Proporciona funciones para crear, cargar, mostrar, liberar, sumar
 *       y multiplicar matrices dinámicas de tipo double. Las matrices se
 *       manejan mediante punteros triples (double ***) para permitir
 *       almacenarlas en vectores dinámicos.
 *
 * [ENG] Provides functions to create, load, display, free, add, and
 *       multiply dynamic matrices of type double. Matrices are managed
 *       via triple pointers (double ***) to allow storing them in
 *       dynamic vectors.
 */

#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief [ESP] Crea dinámicamente una matriz de filas × columnas (double).
 *        [ENG] Dynamically creates a filas × columnas matrix (double).
 *
 * @param[in,out] P         [ESP] Puntero triple: la matriz se almacena en *P.
 *                          [ENG] Triple pointer: the matrix is stored in *P.
 * @param[in]     filas     [ESP] Cantidad de filas de la matriz.
 *                          [ENG] Number of rows in the matrix.
 * @param[in]     columnas  [ESP] Cantidad de columnas de la matriz.
 *                          [ENG] Number of columns in the matrix.
 * @return                  [ESP] Puntero doble a la matriz creada.
 *                          [ENG] Double pointer to the created matrix.
 *
 * @example
 *   double **M = NULL;
 *   M = crearmatrizcondatos(&M, 3, 3);
 */
double **crearmatrizcondatos(double ***P, int filas, int columnas);

/**
 * @brief [ESP] Carga una matriz con valores double ingresados por teclado.
 *        [ENG] Loads a matrix with double values entered from keyboard.
 *
 * @param[in,out] P         [ESP] Puntero triple a la matriz a cargar.
 *                          [ENG] Triple pointer to the matrix to load.
 * @param[in]     filas     [ESP] Cantidad de filas.
 *                          [ENG] Number of rows.
 * @param[in]     columnas  [ESP] Cantidad de columnas.
 *                          [ENG] Number of columns.
 * @return void
 */
void cargamatrizconnumerosdouble(double ***P, int filas, int columnas);

/**
 * @brief [ESP] Muestra por pantalla el contenido de una matriz.
 *        [ENG] Displays the contents of a matrix on screen.
 *
 * @param[in] P         [ESP] Puntero triple a la matriz. / [ENG] Triple pointer to the matrix.
 * @param[in] filas     [ESP] Cantidad de filas.            / [ENG] Number of rows.
 * @param[in] columnas  [ESP] Cantidad de columnas.         / [ENG] Number of columns.
 * @return void
 */
void mostrarmatriz(double ***P, int filas, int columnas);

/**
 * @brief [ESP] Libera la memoria dinámica de una matriz.
 *        [ENG] Frees the dynamic memory of a matrix.
 *
 * [ESP] Primero libera cada fila (array de columnas), luego el array de
 *       punteros a filas.
 * [ENG] First frees each row (column array), then the array of row pointers.
 *
 * @param[in,out] P      [ESP] Puntero triple a la matriz a liberar.
 *                       [ENG] Triple pointer to the matrix to free.
 * @param[in]     filas  [ESP] Cantidad de filas.
 *                       [ENG] Number of rows.
 * @return void
 */
void liberarmatriz(double ***P, int filas);

/**
 * @brief [ESP] Multiplica dos matrices y almacena el resultado.
 *        [ENG] Multiplies two matrices and stores the result.
 *
 * [ESP] Requisito: columnas1 == filas2. La matriz resultante tiene
 *       dimensiones filas1 × columnas2.
 * [ENG] Requirement: columnas1 == filas2. The resulting matrix has
 *       dimensions filas1 × columnas2.
 *
 * @param[out] P          [ESP] Puntero triple donde se almacena la resultante.
 *                        [ENG] Triple pointer where the result is stored.
 * @param[in]  P1         [ESP] Puntero triple a la 1ª matriz.
 *                        [ENG] Triple pointer to the 1st matrix.
 * @param[in]  P2         [ESP] Puntero triple a la 2ª matriz.
 *                        [ENG] Triple pointer to the 2nd matrix.
 * @param[in]  filas1     [ESP] Filas de la 1ª matriz. / [ENG] Rows of the 1st matrix.
 * @param[in]  columnas1  [ESP] Columnas de la 1ª matriz. / [ENG] Columns of 1st.
 * @param[in]  filas2     [ESP] Filas de la 2ª matriz. / [ENG] Rows of the 2nd matrix.
 * @param[in]  columnas2  [ESP] Columnas de la 2ª matriz. / [ENG] Columns of 2nd.
 * @param[out] PunteroaCantidadefilasmatricesresultantes
 *                        [ESP] Buffer para almacenar filas de la resultante.
 *                        [ENG] Buffer to store the row count of the result.
 * @return void
 */
void multiplicarmatrizes(double ***P, double ***P1, double ***P2,
                         int filas1, int columnas1, int filas2, int columnas2,
                         char *PunteroaCantidadefilasmatricesresultantes);

/**
 * @brief [ESP] Suma dos matrices y almacena el resultado.
 *        [ENG] Adds two matrices and stores the result.
 *
 * [ESP] Requisito: ambas matrices deben tener las mismas dimensiones.
 * [ENG] Requirement: both matrices must have the same dimensions.
 *
 * @param[out] P          [ESP] Puntero triple donde se almacena la resultante.
 *                        [ENG] Triple pointer where the result is stored.
 * @param[in]  P1         [ESP] Puntero triple a la 1ª matriz.
 *                        [ENG] Triple pointer to the 1st matrix.
 * @param[in]  P2         [ESP] Puntero triple a la 2ª matriz.
 *                        [ENG] Triple pointer to the 2nd matrix.
 * @param[in]  filas1     [ESP] Filas de la 1ª matriz. / [ENG] Rows of 1st.
 * @param[in]  columnas1  [ESP] Columnas de la 1ª matriz. / [ENG] Columns of 1st.
 * @param[in]  filas2     [ESP] Filas de la 2ª matriz. / [ENG] Rows of 2nd.
 * @param[in]  columnas2  [ESP] Columnas de la 2ª matriz. / [ENG] Columns of 2nd.
 * @param[out] PunteroaCantidadefilasmatricessumadas
 *                        [ESP] Buffer para almacenar filas de la resultante.
 *                        [ENG] Buffer to store the row count of the result.
 * @return void
 */
void sumarmatrices(double ***P, double ***P1, double ***P2,
                   int filas1, int columnas1, int filas2, int columnas2,
                   char *PunteroaCantidadefilasmatricessumadas);

#endif /* MATRIX_OPS_H */
