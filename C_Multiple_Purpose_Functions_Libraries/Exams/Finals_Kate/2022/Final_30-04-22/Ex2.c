/**
 * @file    Ej2.c
 * @brief   [ESP] Ejercicio 2 - Final 30-04-2022. Cómputo de ceros en canales.
 *          [ENG] Exercise 2 - Final 30-04-2022. Channels zeroes computation.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief [ESP] Unión de entrada lógica (16 canales).
 *        [ENG] Logic input union (16 channels).
 */
union logic_in
{
    unsigned short int data;
    struct
    {
        unsigned int ch0  :1;
        unsigned int ch1  :1;
        unsigned int ch2  :1;
        unsigned int ch3  :1;
        unsigned int ch4  :1;
        unsigned int ch5  :1;
        unsigned int ch6  :1;
        unsigned int ch7  :1;
        unsigned int ch8  :1;
        unsigned int ch9  :1;
        unsigned int ch10 :1;
        unsigned int ch11 :1;
        unsigned int ch12 :1;
        unsigned int ch13 :1;
        unsigned int ch14 :1;
        unsigned int ch15 :1;
    } channel;
};

/**
 * @brief [ESP] Prototipo para contar los bits en 0 de los canales.
 *        [ENG] Prototype to count 0-bits inside channels.
 */
void compute_zeroes(union logic_in *din, int counts[]);

/**
 * @brief [ESP] Función principal del Ejercicio 2.
 *        [ENG] Main function for Exercise 2.
 *
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main(void)
{
    union logic_in var1;
    int counts[sizeof(var1.channel)/sizeof(unsigned int)];
    
    memset(counts, 0, sizeof(var1.channel)/sizeof(unsigned int));

    return 0;
}

/**
 * @brief [ESP] Computa si hay canal en 0 para cada uno sumando a counts.
 *        [ENG] Computes if a channel is in 0 for each of them adding to counts.
 *
 * @param din    [ESP] Referencia a la union de entrada / [ENG] Input union reference
 * @param counts [ESP] Arreglo acumulador / [ENG] Accumulator array
 */
void compute_zeroes(union logic_in *din, int counts[]) 
{
    if( din->channel.ch0 == 0 ) counts[0] += 1;
    if( din->channel.ch1 == 0 ) counts[1] += 1;
    if( din->channel.ch2 == 0 ) counts[2] += 1;
    if( din->channel.ch3 == 0 ) counts[3] += 1;
    if( din->channel.ch4 == 0 ) counts[4] += 1;
    if( din->channel.ch5 == 0 ) counts[5] += 1;
    if( din->channel.ch6 == 0 ) counts[6] += 1;
    if( din->channel.ch7 == 0 ) counts[7] += 1;
    if( din->channel.ch8 == 0 ) counts[8] += 1;
    if( din->channel.ch9 == 0 ) counts[9] += 1;
    if( din->channel.ch10 == 0 ) counts[10] += 1;
    if( din->channel.ch11 == 0 ) counts[11] += 1;
    if( din->channel.ch12 == 0 ) counts[12] += 1;
    if( din->channel.ch13 == 0 ) counts[13] += 1;
    if( din->channel.ch14 == 0 ) counts[14] += 1;
    if( din->channel.ch15 == 0 ) counts[15] += 1;
}
