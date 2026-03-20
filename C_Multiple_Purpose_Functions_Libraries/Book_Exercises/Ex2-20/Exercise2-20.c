/**
 * @file    Exercise2-20.c
 * @brief   [ESP] Ejercicio 2.20 del libro: Diámetro, perímetro y área de un círculo.
 *          [ENG] Exercise 2.20 from the book: Diameter, perimeter and area of a circle.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Pide el radio e imprime diámetro, perímetro y área.
 *        [ENG] Prompts for the radius and prints diameter, perimeter and area.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main ()
{
    float pi, radio;
    pi = 3.14159;
    
    /* [ESP] Recibe el valor de radio por teclado
       [ENG] Receives the radius value via keyboard */
    printf("Ingrese un valor de radio de una cirunferencia en alguna unidad metrica: ");
    scanf("%f", &radio);
    
    /* [ESP] Realiza cálculos e imprime en pantalla
       [ENG] Executes calculations and prints to screen */
    printf("El diametro es: %f\n", 2 * radio);
    printf("El perimetro es: %f\n", 2 * pi * radio);
    printf("El area es %f\n", pi * radio * radio);
    
    return 0;
} 
