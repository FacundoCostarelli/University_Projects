/**
 * @file    Ej1.c
 * @brief   [ESP] Ejercicio 1 - Final 30-04-2022. Estructuras lógicas y campos de bits.
 *          [ENG] Exercise 1 - Final 30-04-2022. Logic structures and bit fields.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

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
 * @brief [ESP] Unión de salida lógica (8 canales).
 *        [ENG] Logic output union (8 channels).
 */
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
    } output;
};

/**
 * @brief [ESP] Prototipos de funciones.
 *        [ENG] Function prototypes.
 */
char* toBinary(int n, int len);
void Impresion_union_logic_in(union logic_in *din);
void Impresion_union_logic_out(union logic_out *dout);
void process_data(union logic_in *din, union logic_out *dout);

/**
 * @brief [ESP] Función principal del Ejercicio 1.
 *        [ENG] Main function for Exercise 1.
 *
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main(void)
{
    union logic_in var1;
    union logic_out var2;
    char* binary = NULL;

    printf("El tamanio de unsigned short int data en logic_in es: %lu bytes\n", sizeof(unsigned short int));
    printf("El tamanio de unsigned char data en logic_out es: %lu bytes\n", sizeof(unsigned char));

    printf("Ingrese un dato de 16 bits (0 a 65535 inclusive): ");
    scanf("%hu", &var1.data);
    __fpurge(stdin);

    binary = toBinary( var1.data, 8 * sizeof(var1.data));

    printf("El dato de entrada ingresado fue: %u\n", var1.data);
    printf("Su representacion binaria es %s: \n", binary);

    /* [ESP] Muestra bits de entrada / [ENG] Shows input bits */
    Impresion_union_logic_in(&var1);

    /* [ESP] Procesa y genera la salida / [ENG] Processes and generates output */
    process_data(&var1, &var2);

    /* [ESP] Muestra bits de salida y dato final / [ENG] Shows output bits and final data */
    Impresion_union_logic_out(&var2);

    printf("El dato de salida obtenido luego del procesamiento fue: %d\n", var2.data);
    free(binary);

    return 0;
}

/**
 * @brief [ESP] Convierte a binario un número decimal.
 *        [ENG] Converts decimal number to binary.
 */
char* toBinary(int n, int len)
{
    char* binary = (char*)malloc(sizeof(char) * (len + 1));
    int k = 0;
    for (unsigned i = 1 << (len - 1); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}

/**
 * @brief [ESP] Imprime la particion de canales de entrada.
 *        [ENG] Prints input channels partition.
 */
void Impresion_union_logic_in(union logic_in *din)
{
    printf("La union logica de entrada queda particionada en:\n");
    printf("CH0  = %u\n", din->channel.ch0);  printf("CH1  = %u\n", din->channel.ch1);
    printf("CH2  = %u\n", din->channel.ch2);  printf("CH3  = %u\n", din->channel.ch3);
    printf("CH4  = %u\n", din->channel.ch4);  printf("CH5  = %u\n", din->channel.ch5);
    printf("CH6  = %u\n", din->channel.ch6);  printf("CH7  = %u\n", din->channel.ch7);
    printf("CH8  = %u\n", din->channel.ch8);  printf("CH9  = %u\n", din->channel.ch9);
    printf("CH10 = %u\n", din->channel.ch10); printf("CH11 = %u\n", din->channel.ch11);
    printf("CH12 = %u\n", din->channel.ch12); printf("CH13 = %u\n", din->channel.ch13);
    printf("CH14 = %u\n", din->channel.ch14); printf("CH15 = %u\n", din->channel.ch15);
}

/**
 * @brief [ESP] Imprime la particion de canales de salida.
 *        [ENG] Prints output channels partition.
 */
void Impresion_union_logic_out(union logic_out *dout)
{
    printf("La union logica de salida queda particionada en:\n");
    printf("OUT0 = %u\n", dout->output.out0); printf("OUT1 = %u\n", dout->output.out1);
    printf("OUT2 = %u\n", dout->output.out2); printf("OUT3 = %u\n", dout->output.out3);
    printf("OUT4 = %u\n", dout->output.out4); printf("OUT5 = %u\n", dout->output.out5);
    printf("OUT6 = %u\n", dout->output.out6); printf("OUT7 = %u\n", dout->output.out7);
}

/**
 * @brief [ESP] Procesa y transfiere bits de entrada a salida.
 *        [ENG] Processes and transfers input to output bits.
 */
void process_data(union logic_in *din, union logic_out *dout)
{
    /* out0 */
    dout->output.out0 = ((din->channel.ch0 == 1 && din->channel.ch1 == 1 && din->channel.ch2 == 1 && din->channel.ch3 == 1) || 
                         (din->channel.ch0 == 0 && din->channel.ch1 == 0 && din->channel.ch2 == 0 && din->channel.ch3 == 0)) ? 1 : 0;
    /* out1 */
    dout->output.out1 = ((din->channel.ch4 == 1 && din->channel.ch5 == 1 && din->channel.ch6 == 1 && din->channel.ch7 == 1) || 
                         (din->channel.ch4 == 0 && din->channel.ch5 == 0 && din->channel.ch6 == 0 && din->channel.ch7 == 0)) ? 1 : 0;
    /* out2 */
    dout->output.out2 = ((din->channel.ch8 == 1 && din->channel.ch9 == 1 && din->channel.ch10 == 1 && din->channel.ch11 == 1) || 
                         (din->channel.ch8 == 0 && din->channel.ch9 == 0 && din->channel.ch10 == 0 && din->channel.ch11 == 0)) ? 1 : 0;
    /* out3 */
    dout->output.out3 = ((din->channel.ch12 == 1 && din->channel.ch13 == 1 && din->channel.ch14 == 1 && din->channel.ch15 == 1) || 
                         (din->channel.ch12 == 0 && din->channel.ch13 == 0 && din->channel.ch14 == 0 && din->channel.ch15 == 0)) ? 1 : 0;
    /* out4 */
    dout->output.out4 = (din->channel.ch0 == 0 && din->channel.ch1 == 0 && din->channel.ch2 == 0 && din->channel.ch3 == 0) ? 1 : 0;
    /* out5 */
    dout->output.out5 = (din->channel.ch4 == 0 && din->channel.ch5 == 0 && din->channel.ch6 == 0 && din->channel.ch7 == 0) ? 1 : 0;
    /* out6 */
    dout->output.out6 = (din->channel.ch8 == 0 && din->channel.ch9 == 0 && din->channel.ch10 == 0 && din->channel.ch11 == 0) ? 1 : 0;
    /* out7 */
    dout->output.out7 = (din->channel.ch12 == 0 && din->channel.ch13 == 0 && din->channel.ch14 == 0 && din->channel.ch15 == 0) ? 1 : 0;
}
