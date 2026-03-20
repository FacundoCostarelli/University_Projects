/**
 * @file    Exercise2_3.c
 * @brief   [ESP] Ejercicio 2.3 del libro: Ingreso de datos y varios printf.
 *          [ENG] Exercise 2.3 from the book: Data input and various printfs.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Función principal con distintas muestras de impresión en consola.
 *        [ENG] Main function with several console printing samples.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    int a;
    
    /* [ESP] Ingreso del número
       [ENG] Number input */
    printf("Ingrese un numero entero: ");
    scanf("%d",&a);
    
    printf("El numero ingresado es: %d \n",a);
    
    /* [ESP] Condición de variable
       [ENG] Variable condition */
	if( a != 7 )
		printf("La variable a no es igual a 7. \n");
		
    /* [ESP] Impresiones varias
       [ENG] Varied prints */
    printf("This is a C program. \n");
    printf("This is a C\nprogram. \n");
    printf("This\nis\na\nC\nprogram. \n");
    printf("This\tis\ta\tC\tprogram. \n");
    
    return 0;
}
