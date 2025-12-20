#include"Funciones.h"

void process_data(union logic_in *din, union logic_out *dout)
{
    if( (din->channel.ch0 == 1 && din->channel.ch1 == 1 && din->channel.ch2 == 1 && din->channel.ch3 == 1) || (din->channel.ch0 == 0 && din->channel.ch1 == 0 && din->channel.ch2 == 0 && din->channel.ch3 == 0) )
        dout->output.out0 = 1;
    else
        dout->output.out0 = 0;

    if( (din->channel.ch4 == 1 && din->channel.ch5 == 1 && din->channel.ch6 == 1 && din->channel.ch7 == 1 ) || (din->channel.ch4 == 0 && din->channel.ch5 == 0 && din->channel.ch6 == 0 && din->channel.ch7 == 0) )
        dout->output.out1 = 1;
    else
        dout->output.out1 = 0;

    if( (din->channel.ch8 == 1 && din->channel.ch9 == 1 && din->channel.ch10 == 1 && din->channel.ch11 == 1 ) || (din->channel.ch8 == 0 && din->channel.ch9 == 0 && din->channel.ch10 == 0 && din->channel.ch11 == 0) )
        dout->output.out2 = 1;
    else
        dout->output.out2 = 0;

    if( (din->channel.ch12 == 1 && din->channel.ch13 == 1 && din->channel.ch14 == 1 && din->channel.ch15 == 1) || (din->channel.ch12 == 0 && din->channel.ch13 == 0 && din->channel.ch14 == 0 && din->channel.ch15 == 0) )
        dout->output.out3 = 1;
    else
        dout->output.out3 = 0;

    if( din->channel.ch0 == 0 && din->channel.ch1 == 0 && din->channel.ch2 == 0 && din->channel.ch3 == 0 )
        dout->output.out4 = 1;
    else
        dout->output.out4 = 0;

    if(din->channel.ch4 == 0 && din->channel.ch5 == 0 && din->channel.ch6 == 0 && din->channel.ch7 == 0 )
        dout->output.out5 = 1;
    else
        dout->output.out5 = 0;

    if(din->channel.ch8 == 0 && din->channel.ch9 == 0 && din->channel.ch10 == 0 && din->channel.ch11 == 0)
        dout->output.out6 = 1;
    else
        dout->output.out6 = 0;

    if(din->channel.ch12 == 0 && din->channel.ch13 == 0 && din->channel.ch14 == 0 && din->channel.ch15 == 0)
        dout->output.out7 = 1;
    else
        dout->output.out7 = 0;

    return;
}

//Considero que ch15 es el canal asociado al bit MSB y que el ch0 es el asociado al bit LSB
//Recorro el vector considerando que el elemento count[0] es el entero correspondiente al ch0
//y que count[15] es el entero correspondiente al ch15
void compute_zeroes(union logic_in *d, int counts[])
{
    int i = 0;

    for( i = 0; i < CANTIDAD_ELEMENTOS_ARRAY_DATOS; i ++ )
    {
        if( GetBit(d->data,(char)i) == 0 )
            counts[i] = counts[i] + 1;
    }

    return;
}

void print_stats(int counts[], int total)
{
    int i = 0;

    for( i = 0; i < CANTIDAD_ELEMENTOS_ARRAY_DATOS; i++ )
    {
        /**Imprime porcentaje de CEROS**/
        //printf("Channel #%d   %.2f%%\n",i, ( (float)(counts[i] * 100) ) / ( (float)total ) );
        /**Imprime porcentaje de UNOS**/
        printf("Channel #%d   %.2f%%\n",i,( (float)( (total-counts[i]) * 100 ) / (float)total ) );

    }

    return;
}

unsigned int GetBit(unsigned short int dato, char bit)
{
    unsigned char resultado;
    unsigned short int mascara = 1;

    resultado = ( dato >> bit ) & mascara;

    return resultado;
}
