#include <stdio.h>

int main()
{
    /*Pide 2 numeros a usuario y imprime en pantalla mensajes comparativos segun caso*/

    int a, b;

    printf("Ingrese 2 numeros enteros siendo: a y b\n");
    scanf("%d%d", &a, &b);
    
    /*Enunciados de decision*/

    if( a > b )
        printf("El numero a=%d es el mayor de los 2\n", a);
    if( b > a )
        printf("El numero b=%d es el mayor de los 2\n", b);
    if( a == b )
        printf("Los numeros ingresados son iguales\n");
    
    return 0;

}
