#include <stdio.h>


int main ()
{

    /* Recibe el valor de radio por teclado, realiza calculos e imprime en pantalla*/
    
    float pi, radio;
    pi = 3.14159;
    
    printf("Ingrese un valor de radio de una cirunferencia en alguna unidad metrica: ");
    scanf("%f", &radio);
    
    printf("El diametro es: %f\n", 2 * radio);
    printf("El perimetro es: %f\n", 2 * pi * radio);
    printf("El area es %f\n", pi * radio * radio);
    
    return 0;
    
} 
