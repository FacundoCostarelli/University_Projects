#include<stdio.h>

int main()\
{
    /*Calculate of the product of three(3) integers*/

    int x, y, z, result;
    
    printf("Escriba un valor para cada entero X-Y-Z: ");
    scanf("%d%d%d", &x, &y, &z);
    result= x * y * z;
    printf("El resultado del producto es: %d\n", result);

    return 0;

}
