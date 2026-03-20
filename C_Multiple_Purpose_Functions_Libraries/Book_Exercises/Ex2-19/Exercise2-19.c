/**
 * @file    Exercise2-19.c
 * @brief   [ESP] Ejercicio 2.19 del libro: Suma, promedio, producto, menor y mayor.
 *          [ENG] Exercise 2.19 from the book: Sum, average, product, smallest, largest.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Pide 3 enteros, realiza varios cálculos y encuentra max/min.
 *        [ENG] Prompts for 3 integers, executes math and finds max/min.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    int a, b, c;
    int suma, promedio, producto;
    
    /* [ESP] Recibe 3 enteros por teclado
       [ENG] Receives 3 integers via keyboard */
    printf("Ingrese 3 enteros: ");
    scanf("%d%d%d", &a, &b, &c);
    
    /* [ESP] Cálculos
       [ENG] Calculations */
    suma = a + b + c;
    promedio = suma / 3;
    producto = a * b * c;
    
    printf("La suma es %d\n", suma);
    printf("El promedio es %d\n", promedio);
    printf("El producto es %d\n", producto);
    
    /* [ESP] Calcula y muestra en pantalla el entero más chico
       [ENG] Calculates and prints the smallest integer */
    if( a < b ) {
        if( a < c )
            printf("El entero mas chico es %d\n", a);
    }
    if( b < a ) {
        if( b < c )
            printf("El entero mas chico es %d\n", b);
    }
    if( c < a ) {
        if( c < b )
            printf("El entero mas chico es %d\n", c);
    }
    
    /* [ESP] Calcula y muestra en pantalla el entero más grande
       [ENG] Calculates and prints the largest integer */
    if ( a > b ) {
        if ( a > c )
            printf("El entero mas grande es %d\n", a);
    }
    if ( b > a ) {
        if ( b > c )
            printf("El entero mas grande es %d\n", b);
    }
    if ( c > a ) {
        if ( c > b )
            printf("El entero mas grande es %d\n", c);
    }
    
    return 0;
}
