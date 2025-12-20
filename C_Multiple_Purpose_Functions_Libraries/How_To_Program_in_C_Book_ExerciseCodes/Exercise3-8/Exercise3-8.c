#include <stdio.h>

int main ()
{
    int x, y;
    int power=1, i=1;
    
    printf("Introduzca la base entera x: \n");
    scanf("%d", &x);
    printf("Introduzca el exponente entero y: \n");
    scanf("%d", &y);
    
    while ( i <= y )
        {

            power *= x;
            i++;

        }
    printf("El resultado de la x elevado a la y es: %d \n", power);


    return 0;
}
