#include <stdio.h>


int main()
{
    /* Pide 2 enteros y realiza calculos */
    int a, b;
    
    printf("Ingrese 2 numeros enteros siendo: a y b\n");
    scanf("%d%d", &a, &b);

    /*calculos*/
    
    printf("La suma a + b es: %d\n", a + b);
    printf("La resta a - b es: %d\n", a - b);
    printf("El producto a * b es: %d\n", a * b);
    printf("El cociente a / b es: %d\n", a / b);
    printf("El modulo a porcentaje b es: %d\n", a % b);

    return 0;
    
}
