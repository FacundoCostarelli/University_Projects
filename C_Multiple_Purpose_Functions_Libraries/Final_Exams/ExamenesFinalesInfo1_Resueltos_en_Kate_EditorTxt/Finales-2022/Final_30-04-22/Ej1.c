#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

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


char* toBinary(int n, int len);
void Impresion_union_logic_in(union logic_in *din);
void Impresion_union_logic_out(union logic_out *dout);
void process_data(union logic_in *din, union logic_out *dout);

int main(void)
{
    union logic_in var1;
    union logic_out var2;
    char* binary = NULL;

    printf("El tamanio de unsigned short int data en logic_in es: %lu bytes\n", sizeof(unsigned short int));
    printf("El tamanio de unsigned char data en logic_out es: %lu bytes\n", sizeof(unsigned char));


        printf("Ingrese un dato de entrada de 16 bits con la particularidad de que debe estar entre 0 a 65535 inclusive: ");
        scanf("%hu", &var1.data);
        __fpurge(stdin);

    binary = toBinary( var1.data, 8 * sizeof(var1.data));

    printf("El dato de entrada ingresado fue: %u\n", var1.data);
    printf("Su representacion binaria es %s: \n", binary);

    //Llamado a funcion que realiza la impresion de los bits de los canales de la union
    Impresion_union_logic_in(&var1);

    //Llamado a funcion que realiza el procesamiento de la data de entrada
    process_data(&var1, &var2);

    //Llamado a funcion que realiza el procesamiento de la data de salida
    Impresion_union_logic_out(&var2);

    printf("El dato de salida obtenido luego del procesamiento fue: %d\n",var2.data);

    return 0;
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

void Impresion_union_logic_in(union logic_in *din)
{
    printf("La union logica de entrada queda particionada en los siguientes canales son sus repsectivos bits\n");
    printf("CH0  = %u\n", din->channel.ch0);
    printf("CH1  = %u\n", din->channel.ch1);
    printf("CH2  = %u\n", din->channel.ch2);
    printf("CH3  = %u\n", din->channel.ch3);
    printf("CH4  = %u\n", din->channel.ch4);
    printf("CH5  = %u\n", din->channel.ch5);
    printf("CH6  = %u\n", din->channel.ch6);
    printf("CH7  = %u\n", din->channel.ch7);
    printf("CH8  = %u\n", din->channel.ch8);
    printf("CH9  = %u\n", din->channel.ch9);
    printf("CH10 = %u\n", din->channel.ch10);
    printf("CH11 = %u\n", din->channel.ch11);
    printf("CH12 = %u\n", din->channel.ch12);
    printf("CH13 = %u\n", din->channel.ch13);
    printf("CH14 = %u\n", din->channel.ch14);
    printf("CH15 = %u\n", din->channel.ch15);

    return;
}

void Impresion_union_logic_out(union logic_out *dout)
{
    printf("La union logica de salida queda particionada en los siguientes canales con sus repsectivos bits\n");
    printf("OUT0 = %u\n", dout->output.out0);
    printf("OUT1 = %u\n", dout->output.out1);
    printf("OUT2 = %u\n", dout->output.out2);
    printf("OUT3 = %u\n", dout->output.out3);
    printf("OUT4 = %u\n", dout->output.out4);
    printf("OUT5 = %u\n", dout->output.out5);
    printf("OUT6 = %u\n", dout->output.out6);
    printf("OUT7 = %u\n", dout->output.out7);

    return;
}

void process_data(union logic_in *din, union logic_out *dout)
{
    //Carga de valor de out0
    if( (din->channel.ch0 == 1 && din->channel.ch1 == 1 && din->channel.ch2 == 1 && din->channel.ch3 == 1)  ||  (din->channel.ch0 == 0 && din->channel.ch1 == 0 && din->channel.ch2 == 0 && din->channel.ch3 == 0) )
        dout->output.out0 = 1;
    else
        dout->output.out0 = 0;

    //Carga de valor de out1
    if( (din->channel.ch4 == 1 && din->channel.ch5 == 1 && din->channel.ch6 == 1 && din->channel.ch7 == 1)  ||  (din->channel.ch4 == 0 && din->channel.ch5 == 0 && din->channel.ch6 == 0 && din->channel.ch7 == 0) )
        dout->output.out1 = 1;
    else
        dout->output.out1 = 0;

    //Carga de valor de out2
    if( (din->channel.ch8 == 1 && din->channel.ch9 == 1 && din->channel.ch10 == 1 && din->channel.ch11 == 1)  ||  (din->channel.ch8 == 0 && din->channel.ch9 ==0 && din->channel.ch10 == 0 && din->channel.ch11 == 0) )
        dout->output.out2 = 1;
    else
        dout->output.out2 = 0;

    //Carga de valor de out3
    if( (din->channel.ch12 == 1 && din->channel.ch13 == 1 && din->channel.ch14 == 1 && din->channel.ch15 == 1)  ||  (din->channel.ch12 == 0 && din->channel.ch13 == 0 && din->channel.ch14 == 0 && din->channel.ch15 == 0) )
        dout->output.out3 = 1;
    else
        dout->output.out3 = 0;

    //Carga de valor de out4
    if(din->channel.ch0 == 0 && din->channel.ch1 == 0 && din->channel.ch2 == 0 && din->channel.ch3 == 0)
        dout->output.out4 = 1;
    else
        dout->output.out4 = 0;

    //Carga de valor de out5
    if(din->channel.ch4 == 0 && din->channel.ch5 == 0 && din->channel.ch6 == 0 && din->channel.ch7 == 0)
        dout->output.out5 = 1;
    else
        dout->output.out5 = 0;

    //Carga de valor out6
    if(din->channel.ch8 == 0 && din->channel.ch9 ==0 && din->channel.ch10 == 0 && din->channel.ch11 == 0)
        dout->output.out6 = 1;
    else
        dout->output.out6 = 0;

    //Carga de valor out7
    if(din->channel.ch12 == 0 && din->channel.ch13 == 0 && din->channel.ch14 == 0 && din->channel.ch15 == 0)
        dout->output.out7 = 1;
    else
        dout->output.out7 = 0;

    return;
}

