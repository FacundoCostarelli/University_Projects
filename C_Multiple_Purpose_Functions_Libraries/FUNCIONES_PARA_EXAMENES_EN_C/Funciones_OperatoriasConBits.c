
#include<stdio.h>
#define ON 1
#define OFF 0
void PrintBits( unsigned int dato, char nro_de_bit )
{
    nro_de_bit--;

    printf("b:");
    for( ; nro_de_bit >= 0; nro_de_bit-- )
        printf("%d", GetBit(dato, nro_de_bit));

    printf("\nEn hexadecima: (0x%02X) \n", dato);

    return;
}

unsigned char GetBit(unsigned int dato, char bit)
{
    unsigned char resultado, mascara = 1;

    resultado = ( dato >> bit ) & mascara;

    return resultado;
}

unsigned int SetBit( unsigned int dato, char bit, char estado )
{
    unsigned int resultado, mascara = 1;

    mascara = mascara << bit;

    if( estado == OFF)
    {
        mascara = ~mascara;
        resultado = dato & mascara;
    }
    else
        resultado = dato | mascara;

    return resultado;
}

unsigned int SetToggle( unsigned int dato, char bit )
{
    unsigned int resultado, mascara = 1;

    mascara = mascara << bit;
    resultado = dato ^ mascara;

    return resultado;
}
