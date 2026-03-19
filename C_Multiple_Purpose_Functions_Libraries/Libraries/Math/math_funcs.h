/**
 * @file    math_funcs.h
 * @brief   [ESP] Biblioteca de funciones matemáticas personalizadas (sin math.h).
 *          [ENG] Custom mathematical functions library (without math.h).
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Proporciona una función de composición de funciones f(g(x)) que
 *       calcula y almacena los pares (x, y) en un array 2D dinámico.
 *       Utiliza punteros a función para generalizar la composición.
 *
 * [ENG] Provides a function composition f(g(x)) that calculates and stores
 *       (x, y) pairs in a dynamic 2D array. Uses function pointers to
 *       generalize the composition.
 */

#ifndef MATH_FUNCS_H
#define MATH_FUNCS_H

#include <stdio.h>
#include <stdlib.h>

/** @brief [ESP] Código de error / [ENG] Error code */
#define ERROR -1
/** @brief [ESP] Código de éxito / [ENG] Success code */
#define EXITO  0

/**
 * @brief [ESP] Calcula la composición de dos funciones f(g(x)) y almacena
 *              los pares (x, y) en un array 2D dinámico.
 *        [ENG] Computes the composition of two functions f(g(x)) and stores
 *              the (x, y) pairs in a dynamic 2D array.
 *
 * @param[in] ptr_fun1  [ESP] Puntero a la función exterior f().
 *                      [ENG] Pointer to the outer function f().
 * @param[in] ptr_fun2  [ESP] Puntero a la función interior g().
 *                      [ENG] Pointer to the inner function g().
 * @return              [ESP] Puntero doble a un array 2D dinámico [N+1][2]:
 *                            - Columna 0: valores de x (abscisas)
 *                            - Columna 1: valores de f(g(x)) (ordenadas)
 *                            - Última fila: NULL (sentinela de fin)
 *                            El llamador debe liberar la memoria con free().
 *                      [ENG] Double pointer to a dynamic 2D array [N+1][2]:
 *                            - Column 0: x values (abscissas)
 *                            - Column 1: f(g(x)) values (ordinates)
 *                            - Last row: NULL (end sentinel)
 *                            The caller must free the memory with free().
 *
 * @example
 *   float f(float x) { return x + 10; }
 *   float g(float x) { return x * 2;  }
 *   // [ESP] Calcula f(g(x)) = (x * 2) + 10
 *   // [ENG] Computes f(g(x)) = (x * 2) + 10
 *   float **tabla = ComposicionDeFunciones(f, g);
 *   // [ESP] Liberar memoria después de usar:
 *   // [ENG] Free memory after use:
 *   // for (int i = 0; tabla[i] != NULL; i++) free(tabla[i]);
 *   // free(tabla);
 */
float **ComposicionDeFunciones(float (*ptr_fun1)(float), float (*ptr_fun2)(float));

/**
 * @brief [ESP] Función de ejemplo #1 para composición: f(x) = x + 10.
 *        [ENG] Example function #1 for composition: f(x) = x + 10.
 *
 * @param[in] x  [ESP] Valor de entrada. / [ENG] Input value.
 * @return       [ESP] x + 10. / [ENG] x + 10.
 */
float NomFun1(float x);

/**
 * @brief [ESP] Función de ejemplo #2 para composición: g(x) = x * 15.50.
 *        [ENG] Example function #2 for composition: g(x) = x * 15.50.
 *
 * @param[in] x  [ESP] Valor de entrada. / [ENG] Input value.
 * @return       [ESP] x * 15.50. / [ENG] x * 15.50.
 */
float NomFun2(float x);

#endif /* MATH_FUNCS_H */
