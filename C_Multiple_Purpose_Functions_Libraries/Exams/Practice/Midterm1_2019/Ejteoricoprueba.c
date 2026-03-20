/**
 * @file    Ejteoricoprueba.c
 * @brief   [ESP] Prueba de concepto con punteros a arreglos.
 *          [ENG] Proof of concept with pointers to arrays.
 *
 * @author  Facundo Costarelli
 * @date    2019
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>

/**
 * @brief [ESP] Función principal. Muestra operaciones con punteros.
 *        [ENG] Main function. Demonstrates pointer operations.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(void)
{
    /* [ESP] Creación de un vector de datos "int" de tamaño "4" con elementos predeterminados.
       [ENG] Creation of an "int" data vector of size "4" with default elements. */
    int vec[4] = { 2, 1, 4, 3 }; 
    
    /* [ESP] Declaración de un puntero simple sin inicializar.
       [ENG] Declaration of an uninitialized simple pointer. */
    int *p;
    
    /* [ESP] El puntero "p" almacena la dirección del 1er elemento del vector.
       [ENG] Pointer "p" stores the address of the 1st element of the vector. */
    p = vec;
    
    /* [ESP] Se imprime el contenido apuntado por "p" (el nro 2).
       [ENG] Prints the content pointed to by "p" (number 2). */
    printf("%d\n", *p);
    
    /* [ESP] Se le asigna a "p" la dirección desplazada en 2 posiciones ints. Apunta al nro 4.
       [ENG] "p" is assigned the address shifted by 2 int positions. Points to number 4. */
    p = (int *)(p + 2);
    printf("%d\n", *p);
    
    /* [ESP] Se desplaza "p" otras 2 posiciones. Ahora apunta fuera del array (basura).
       [ENG] "p" is shifted another 2 positions. Now points outside the array (garbage). */
    p = (int *)(p + 2);
    
    /* [ESP] Se imprime el valor int aleatorio (basura).
       [ENG] Prints the random int value (garbage). */
    printf("%d\n", *p);
    
    return 0;
}
