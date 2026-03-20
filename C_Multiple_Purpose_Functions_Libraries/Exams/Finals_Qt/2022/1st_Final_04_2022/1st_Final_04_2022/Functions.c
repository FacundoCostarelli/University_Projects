/**
 * @file    Funciones.c
 * @brief   [ESP] Archivo fuente de resolución de cálculos lógicos. Final 04/2022.
 *          [ENG] Logical computations resolution source file. Final 04/2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Procesa las compuertas lógicas sobre los canales de entrada para mutar bits de salida.
 *        [ENG] Processes logic gates across input channels assigning values to output bits.
 *
 * @param din  [ESP] Puntero a la unión de entrada  / [ENG] Pointer to the input union
 * @param dout [ESP] Puntero a la unión de salida / [ENG] Pointer to the output union
 */
void process_data(union logic_in *din, union logic_out *dout)
{
    if( (din->channel.ch0 == 1 && din->channel.ch1 == 1 && din->channel.ch2 == 1 && din->channel.ch3 == 1) || 
        (din->channel.ch0 == 0 && din->channel.ch1 == 0 && din->channel.ch2 == 0 && din->channel.ch3 == 0) )
        dout->output.out0 = 1;
    else
        dout->output.out0 = 0;

    if( (din->channel.ch4 == 1 && din->channel.ch5 == 1 && din->channel.ch6 == 1 && din->channel.ch7 == 1 ) || 
        (din->channel.ch4 == 0 && din->channel.ch5 == 0 && din->channel.ch6 == 0 && din->channel.ch7 == 0) )
        dout->output.out1 = 1;
    else
        dout->output.out1 = 0;

    if( (din->channel.ch8 == 1 && din->channel.ch9 == 1 && din->channel.ch10 == 1 && din->channel.ch11 == 1 ) || 
        (din->channel.ch8 == 0 && din->channel.ch9 == 0 && din->channel.ch10 == 0 && din->channel.ch11 == 0) )
        dout->output.out2 = 1;
    else
        dout->output.out2 = 0;

    if( (din->channel.ch12 == 1 && din->channel.ch13 == 1 && din->channel.ch14 == 1 && din->channel.ch15 == 1) || 
        (din->channel.ch12 == 0 && din->channel.ch13 == 0 && din->channel.ch14 == 0 && din->channel.ch15 == 0) )
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
}

/**
 * @brief [ESP] Cuenta cantidad de bits '0' por cada canal, incrementando su celda correspondiente.
 *        [ENG] Counts amount of '0' bits sequentially per channel, upgrading its integer cell counterpart.
 *
 * @param d      [ESP] Puntero a vector de union_in / [ENG] Pointer to logic_in array
 * @param counts [ESP] Arreglo acumulador / [ENG] Acummulator array  
 */
void compute_zeroes(union logic_in *d, int counts[])
{
    int i = 0;
    
    /* 
     * [ESP] Considero que ch15 es el canal MSB y ch0 el LSB. count[0] es para ch0, count[15] para ch15
     * [ENG] Considering ch15 as MSB channel and ch0 as LSB. count associates to each bit position
     */
    for( i = 0; i < CANTIDAD_ELEMENTOS_ARRAY_DATOS; i ++ )
    {
        if( GetBit(d->data, (char)i) == 0 )
            counts[i] = counts[i] + 1;
    }
}

/**
 * @brief [ESP] Imprime estadísticas basadas en los contadores.
 *        [ENG] Print out stats given the accumulators vector over total loops.
 */
void print_stats(int counts[], int total)
{
    int i = 0;

    for( i = 0; i < CANTIDAD_ELEMENTOS_ARRAY_DATOS; i++ )
    {
        /* [ESP] Imprime porcentaje de UNOS / [ENG] Prints ONES ratio */
        printf("Channel #%d   %.2f%%\n", i, ((float)((total - counts[i]) * 100) / (float)total));
    }
}

/**
 * @brief [ESP] Extrae el bit específico con una máscara directa y shift paramétrico.
 *        [ENG] Extracts the target bit implementing a right-shift given pos-index.
 */
unsigned int GetBit(unsigned short int dato, char bit)
{
    unsigned char resultado;
    unsigned short int mascara = 1;

    resultado = (dato >> bit) & mascara;
    return resultado;
}
