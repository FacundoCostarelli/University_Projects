#ifndef FUNCIONES_H
#define FUNCIONES_H

#include<stdio.h>
#include<stdlib.h>

#define ERROR -1
/*********/
//Iria el valor de las macros correspondientes del examen. Cargo -1 para poder compilar
#define EARGS -1
#define EINFILE -1
#define EOUTFILE -1
/***************/

#define EXITO 0
#define CANTIDAD_ELEMENTOS_ARRAY_DATOS 16
union logic_in
{
    unsigned short int data;
    struct
    {
        unsigned int ch0 :1;
        unsigned int ch1 :1;
        unsigned int ch2 :1;
        unsigned int ch3 :1;
        unsigned int ch4 :1;
        unsigned int ch5 :1;
        unsigned int ch6 :1;
        unsigned int ch7 :1;
        unsigned int ch8 :1;
        unsigned int ch9 :1;
        unsigned int ch10 :1;
        unsigned int ch11 :1;
        unsigned int ch12 :1;
        unsigned int ch13 :1;
        unsigned int ch14 :1;
        unsigned int ch15 :1;
    }channel;
};

union logic_out
{
    unsigned char data;
    struct
    {
        unsigned int out0 :1;
        unsigned int out1 :1;
        unsigned int out2 :1;
        unsigned int out3 :1;
        unsigned int out4 :1;
        unsigned int out5 :1;
        unsigned int out6 :1;
        unsigned int out7 :1;
    }output;
};

void process_data(union logic_in *din, union logic_out *dout);
void compute_zeroes(union logic_in *d, int counts[]);
void print_stats(int counts[], int total);
unsigned int GetBit(unsigned short int dato, char bit);

#endif // FUNCIONES_H
