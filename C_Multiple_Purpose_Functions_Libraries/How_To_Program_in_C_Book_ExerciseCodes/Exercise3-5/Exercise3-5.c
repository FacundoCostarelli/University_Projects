#include <stdio.h>

int main ()
{
    /* Calcula la suma de resultados de "sum" con cada entero x del 1 al 10 */
    int sum = 0, x = 1;
    
    
    while ( x < 11 )
    {
        sum = sum + x;
        x++;
        printf("El resultado de sum es: %d\n", sum);
    }
/* 
0+1=1
1+2=3
3+3=6
6+4=10
10+5=15
15+6=21
21+7=28
28+8=36
36+9=45
45+10=55
calculos que se realizan a lo largo de la repeticion del while*/

    printf("El resultado final de sum es: %d\n", sum);

    return 0;
}

