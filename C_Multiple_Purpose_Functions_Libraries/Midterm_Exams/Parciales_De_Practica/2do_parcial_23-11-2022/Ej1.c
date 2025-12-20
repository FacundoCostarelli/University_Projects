#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>


int Mi_Funcion(int numero, int *ptr);
char* toBinary(int n, int len);

int main(void)
{
    int numero, resultado;
    int len = 32;
    char* binary = NULL;
    int aux;

    printf("Ingrese un numero entero\n");
    scanf("%d", &numero);
    __fpurge(stdin);

    printf("El tamanio en bits de su numero entero es %ld\n", sizeof(int));


    binary = toBinary(numero, len);
    printf("La representacion binaria de %d es %s\n", numero, binary);
    free(binary);

    aux = Mi_Funcion(numero, &resultado);
    printf("La cantidad de veces que aparece el patron 101 en su numero ingresado es: %d\n", aux);
    printf("La operacion realizada a su numero %d segun el la cantidad de veces que se repitio el patron 101 dio como resultado %d\n", numero, resultado);
    binary = toBinary(resultado, len);
    printf("La representacion binaria del resultado %d es %s\n", resultado, binary);
    free(binary);


    return 0;
}

int Mi_Funcion(int numero, int *ptr)
{
    int patron = 0x00000005;
    int Mask = 0x00000007;
    int MaskA = 0x0000FFFF;
    int MaskB = 0xFFFF0000;
    int Low_word, High_word;
    int aux, i, count = 0;

    int len = 32;
    char* binary = NULL;

    for( i = 0; i < 32; i++ )
    {
        aux = numero & Mask;
        aux = aux >> i;
        binary = toBinary(aux, len);
        printf("La representacion binaria de aux %d es %s\n ", aux, binary);
        free(binary);
        if( aux == patron )
            count++;
        Mask = Mask << 1;
    }
    /*Par*/
    if( count % 2 == 0 )
    {
        printf("Count es %d y por lo tanto es par\n", count);
        Low_word = numero & MaskA;
        High_word = numero & MaskB;
        aux = (Low_word << 16) | ((High_word >> 16) & MaskA);
        binary = toBinary(aux, len);
        printf("La representacion binaria de aux %d es %s\n ", aux, binary);
        free(binary);
        *ptr = aux;
    }
    /*Impar*/
    else
    {
        printf("Count es %d y por lo tanto es impar\n", count);
        binary = toBinary(~numero, len);
        printf("La representacion binaria de ~numero %d es %s\n ", ~numero, binary);
        free(binary);
        *ptr = ~numero;
    }

    return count;
}


char* toBinary(int n, int len)
{
    char* binary = (char*)malloc(sizeof(char) * len);
    int k = 0;
    for (unsigned i = 1 << (len - 1); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}

/*
 * void displayBits( unsigned value )
{
   unsigned c, displayMask = 1 << 31;

   printf( "%7u = ", value );

   for ( c = 1; c <= 32; c++ ) {
      putchar( value & displayMask ? '1' : '0' );
      value <<= 1;

      if ( c % 8 == 0 )
         putchar( ' ' );
   }

   putchar( '\n' );
}
*/
