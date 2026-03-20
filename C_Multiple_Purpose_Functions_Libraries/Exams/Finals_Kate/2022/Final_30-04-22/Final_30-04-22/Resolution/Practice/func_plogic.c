/**
 * @file    func_plogic.c
 * @brief   [ESP] Archivo fuente de funciones lógicas. (Resolución). Final 30-04-2022.
 *          [ENG] Logical functions source file. (Resolution). Final 30-04-2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>
#include "func_plogic.h"

/**
 * @brief [ESP] Procesa un dato de entrada y arma el dato de salida completo.
 *        [ENG] Processes an input data and builds the complete output data.
 */
void process_data(union logic_in *din, union logic_out *dout)
{
    dout->data = 0;

    /* [ESP] usando comparacion entre bits / [ENG] using bit comparison */
    dout->output.out0 = (din->channel.ch0 == din->channel.ch1) && (din->channel.ch0 == din->channel.ch2) && (din->channel.ch0 == din->channel.ch3);
    dout->output.out1 = (din->channel.ch4 == din->channel.ch5) && (din->channel.ch4 == din->channel.ch6) && (din->channel.ch4 == din->channel.ch7);
    dout->output.out2 = (din->channel.ch8 == din->channel.ch9) && (din->channel.ch8 == din->channel.ch10) && (din->channel.ch8 == din->channel.ch11);
    dout->output.out3 = (din->channel.ch12 == din->channel.ch13) && (din->channel.ch12 == din->channel.ch14) && (din->channel.ch12 == din->channel.ch15);
    
    dout->output.out4 =  !(din->channel.ch0 | din->channel.ch1 | din->channel.ch2 | din->channel.ch3);
    dout->output.out5 =  !(din->channel.ch4 | din->channel.ch5 | din->channel.ch6 | din->channel.ch7);
    dout->output.out6 =  !(din->channel.ch8 | din->channel.ch9 | din->channel.ch10 | din->channel.ch11);
    dout->output.out7 =  !(din->channel.ch12 | din->channel.ch13 | din->channel.ch14 | din->channel.ch15);

    /* 
     [ESP] usando una mascara / [ENG] using a mask
     unsigned int m = 0x00f;
     dout->output.out0 = (din->data & m) == m || (din->data & m) == 0; 
     dout->output.out4 = (din->data & m) == 0;
     m <<= 4;
     dout->output.out1 = (din->data & m) == m || (din->data & m) == 0; 
     dout->output.out5 = (din->data & m) == 0;
     m <<= 4;
     dout->output.out2 = (din->data & m) == m || (din->data & m) == 0; 
     dout->output.out6 = (din->data & m) == 0;
     m <<= 4;
     dout->output.out3 = (din->data & m) == m || (din->data & m) == 0; 
     dout->output.out7 = (din->data & m) == 0;
    */
}

/**
 * @brief [ESP] Computa qué entradas están en uno.
 *        [ENG] Computes which inputs are in one.
 */
void compute_zeroes(union logic_in *d, int counts[])
{
    /* [ESP] usando los bit del campo channel de la union / [ENG] using union channel bits */
    if (!d->channel.ch0) counts[0]++;
    if (!d->channel.ch1) counts[1]++;
    if (!d->channel.ch2) counts[2]++;
    if (!d->channel.ch3) counts[3]++;
    if (!d->channel.ch4) counts[4]++;
    if (!d->channel.ch5) counts[5]++;
    if (!d->channel.ch6) counts[6]++;
    if (!d->channel.ch7) counts[7]++;
    if (!d->channel.ch8) counts[8]++;
    if (!d->channel.ch9) counts[9]++;
    if (!d->channel.ch10) counts[10]++;
    if (!d->channel.ch11) counts[11]++;
    if (!d->channel.ch12) counts[12]++;
    if (!d->channel.ch13) counts[13]++;
    if (!d->channel.ch14) counts[14]++;
    if (!d->channel.ch15) counts[15]++;
    
    /* 
     [ESP] usando el campo data de la union / [ENG] using union data field
     int i;
     for (i=0; i<NCHANNELS; i++) {
         if (!((d->data >> i) & 1)) {
             counts[i]++;
         }
     }
    */
}

/**
 * @brief [ESP] Imprime en pantalla el porcentaje de unos en cada entrada.
 *        [ENG] Prints the percentage of ones in each input on screen.
 */
void print_stats(int counts[], int total)
{
    int n;
    for(n = 0; n < NCHANNELS; n++)
        printf("Channel #%d\t%.2f%%\n", n, ((float)(total - counts[n]) / total) * 100.0);
}
