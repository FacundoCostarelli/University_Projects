#include <stdio.h>


int main()
{
    /*Recibe 3 enteros, realiza calculos e imprime en pantalla*/
    
    int a, b, c;
    int suma, promedio, producto;
    printf("Ingrese 3 enteros: ");
    scanf("%d%d%d", &a, &b, &c);
    
    /*Calculos*/

    suma = a + b + c;
    promedio = suma / 3;
    producto = a * b * c;
    printf("La suma es %d\n", suma);
    printf("El promedio es %d\n", promedio);
    printf("El producto es %d\n", producto);
    
    /* Calcula y muestra en pantalla el entero mas chico */
    if( a < b )
    {
        
        if( a < c)
        printf("El entero mas chico es %d\n", a);
    
    }

    if( b < a )
    {
        
        if ( b < c )
        printf("El entero mas chico es %d\n", b);
        
    }
    
    if( c < a )
    {
        
        if ( c < b )
        printf("El entero mas chico es %d\n", c);
        
    }
    
    /* Calcula y muestra en pantalla el entero mas grande */
    
    if ( a > b )
    {
        
        if ( a > c )
        printf("El entero mas grande es %d\n", a);
        
    }
    
    if ( b > a )
    {
        
        if ( b > c )
        printf("El entero mas grande es %d\n", b);
    
    }
    
    if ( c > a )
    {
        
        if ( c > b )
        printf("El entero mas grande es %d\n", c);
    
    }
    
    
    return 0;
}
