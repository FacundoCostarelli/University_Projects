#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

void compute_zeroes(union logic_in *din, int counts[]);

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

int main(void)
{
    union logic_in var1;
    int counts[sizeof(var1.channel)/sizeof(unsigned int)];
    memset( counts, 0, sizeof(var1.channel)/sizeof(unsigned int));




    return 0;
}

void compute_zeroes(union logic_in *din, int counts[])  //int counts[] es lo mismo que poner int *counts
{
    if( din->channel.ch0 == 0 )
        counts[0] += 1;
    if( din->channel.ch1 == 0 )
        counts[1] += 1;
    if( din->channel.ch2 == 0 )
        counts[2] += 1;
    if( din->channel.ch3 == 0 )
        counts[3] += 1;
    if( din->channel.ch4 == 0 )
        counts[4] += 1;
    if( din->channel.ch5 == 0 )
        counts[5] += 1;
    if( din->channel.ch6 == 0 )
        counts[6] += 1;
    if( din->channel.ch7 == 0 )
        counts[7] += 1;
    if( din->channel.ch8 == 0 )
        counts[8] += 1;
    if( din->channel.ch9 == 0 )
        counts[9] += 1;
    if( din->channel.ch10 == 0 )
        counts[10] += 1;
    if( din->channel.ch11 == 0 )
        counts[11] += 1;
    if( din->channel.ch12 == 0 )
        counts[12] += 1;
    if( din->channel.ch13 == 0 )
        counts[13] += 1;
    if( din->channel.ch14 == 0 )
        counts[14] += 1;
    if( din->channel.ch15 == 0 )
        counts[15] += 1;

    return;
}
