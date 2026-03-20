/**
 * @file    Ej4.c
 * @brief   [ESP] Ejercicio 4 - Final 30-04-2022. Flujo completo entrada/salida y procesado binario.
 *          [ENG] Exercise 4 - Final 30-04-2022. Complete I/O flow and binary processing.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>

/**
 * @brief [ESP] Constantes simbólicas para código de retorno.
 *        [ENG] Symbolic constants for return code.
 */
#define OK           0  /* funcion terminada correctamente */
#define EARGS       -1  /* error en la cantdad de argumentos */
#define EINFILE     -2  /* error al abrir el archivo de entrada */
#define EOUTFILE    -3  /* error al abrir el archivo de salida */

#define NCHANNELS   16

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


char* toBinary(int n, int len);
void Impresion_union_logic_in(union logic_in *din);
void Impresion_union_logic_out(union logic_out *dout);
void process_data(union logic_in *din, union logic_out *dout);
void compute_zeroes(union logic_in *din, int counts[]);
void print_stats( int counts[], int total);

/**
 * @brief [ESP] Función principal del Ejercicio 4.
 *        [ENG] Main function for Exercise 4.
 *
 * @param argc [ESP] Número de argumentos / [ENG] Number of arguments
 * @param argv [ESP] Array de argumentos (in/out_files) / [ENG] Arguments array (in/out_files)
 * @return int [ESP] Códigos de estado (OK, EARGS, EINFILE, EOUTFILE) / [ENG] Status codes
 */
int main(int argc, char *argv[]) 
{
    union logic_in var1;
    union logic_out var2;
    char* binary = NULL;
    FILE *f_in = NULL;
    FILE *f_out = NULL;
    int counts[NCHANNELS];
    int total_muestras_procesadas = 0;
    int porciones_bytes_leidos;
    int porciones_bytes_escritos;

    memset( counts, 0, NCHANNELS * sizeof(unsigned int));

    if( argc != 3 )
    {
        printf("Error al invocar %s\n", argv[0]);
        return(EARGS);
    }

    f_in = fopen(argv[1], "r");
    if( f_in == NULL )
    {
        printf("Error al abrir el archivo de entrada '%s'\n", argv[1]);
        return(EINFILE);
    }

    f_out = fopen(argv[2], "w");
    if( f_out == NULL )
    {
        printf("Error al abrir el archivo de salida '%s'\n", argv[2]);
        fclose(f_in);
        return(EOUTFILE);
    }
    
    var1.data = 0;

    /* [ESP] Procesa 10 muestras continuas / [ENG] Processes 10 consecutive samples */
    while(var1.data < 10)
    {
        do
        {
            porciones_bytes_leidos = fread(&(var1.data), sizeof(unsigned short int), 1, f_in);
        } while(porciones_bytes_leidos == 0);

        binary = toBinary( var1.data, 8 * sizeof(var1.data));

        printf("El dato de entrada ingresado fue: %u\n", var1.data);
        printf("Su representacion binaria es %s: \n", binary);

        Impresion_union_logic_in(&var1);
        process_data(&var1, &var2);
        Impresion_union_logic_out(&var2);

        printf("El dato de salida obtenido luego del procesamiento fue: %d\n", var2.data);
        compute_zeroes(&var1, counts);

        do
        {
            porciones_bytes_escritos = fwrite(&(var2.data), sizeof(unsigned char), 1, f_out);
        } while(porciones_bytes_escritos == 0);

        total_muestras_procesadas++;
        free(binary); /* [ESP] Liberación de array para binarios / [ENG] Free binary allocated array */
    }

    clearerr(f_in);
    print_stats( counts, total_muestras_procesadas);

    fclose(f_in);
    fclose(f_out);

    return OK;
}

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

void Impresion_union_logic_in(union logic_in *din)
{
    printf("CH0=%u CH1=%u CH2=%u CH3=%u\n",din->channel.ch0,din->channel.ch1,din->channel.ch2,din->channel.ch3);
    printf("CH4=%u CH5=%u CH6=%u CH7=%u\n",din->channel.ch4,din->channel.ch5,din->channel.ch6,din->channel.ch7);
    printf("CH8=%u CH9=%u CH10=%u CH11=%u\n",din->channel.ch8,din->channel.ch9,din->channel.ch10,din->channel.ch11);
    printf("CH12=%u CH13=%u CH14=%u CH15=%u\n",din->channel.ch12,din->channel.ch13,din->channel.ch14,din->channel.ch15);
}

void Impresion_union_logic_out(union logic_out *dout)
{
    printf("OUT0=%u OUT1=%u OUT2=%u OUT3=%u\n",dout->output.out0,dout->output.out1,dout->output.out2,dout->output.out3);
    printf("OUT4=%u OUT5=%u OUT6=%u OUT7=%u\n",dout->output.out4,dout->output.out5,dout->output.out6,dout->output.out7);
}

void process_data(union logic_in *din, union logic_out *dout)
{
    dout->output.out0 = ((din->channel.ch0 == 1 && din->channel.ch1 == 1 && din->channel.ch2 == 1 && din->channel.ch3 == 1) || 
                         (din->channel.ch0 == 0 && din->channel.ch1 == 0 && din->channel.ch2 == 0 && din->channel.ch3 == 0)) ? 1 : 0;
    dout->output.out1 = ((din->channel.ch4 == 1 && din->channel.ch5 == 1 && din->channel.ch6 == 1 && din->channel.ch7 == 1) || 
                         (din->channel.ch4 == 0 && din->channel.ch5 == 0 && din->channel.ch6 == 0 && din->channel.ch7 == 0)) ? 1 : 0;
    dout->output.out2 = ((din->channel.ch8 == 1 && din->channel.ch9 == 1 && din->channel.ch10 == 1 && din->channel.ch11 == 1) || 
                         (din->channel.ch8 == 0 && din->channel.ch9 == 0 && din->channel.ch10 == 0 && din->channel.ch11 == 0)) ? 1 : 0;
    dout->output.out3 = ((din->channel.ch12 == 1 && din->channel.ch13 == 1 && din->channel.ch14 == 1 && din->channel.ch15 == 1) || 
                         (din->channel.ch12 == 0 && din->channel.ch13 == 0 && din->channel.ch14 == 0 && din->channel.ch15 == 0)) ? 1 : 0;

    dout->output.out4 = (din->channel.ch0 == 0 && din->channel.ch1 == 0 && din->channel.ch2 == 0 && din->channel.ch3 == 0) ? 1 : 0;
    dout->output.out5 = (din->channel.ch4 == 0 && din->channel.ch5 == 0 && din->channel.ch6 == 0 && din->channel.ch7 == 0) ? 1 : 0;
    dout->output.out6 = (din->channel.ch8 == 0 && din->channel.ch9 == 0 && din->channel.ch10 == 0 && din->channel.ch11 == 0) ? 1 : 0;
    dout->output.out7 = (din->channel.ch12 == 0 && din->channel.ch13 == 0 && din->channel.ch14 == 0 && din->channel.ch15 == 0) ? 1 : 0;
}

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

void print_stats( int counts[], int total) 
{
    float counts_unos[NCHANNELS];
    int i;
    for( i = 0; i < NCHANNELS; i++ )
        counts_unos[i] = total - counts[i];

    printf("Channel #0\t %.2f%% \n", (counts_unos[0] * 100) / total);
    printf("Channel #1\t %.2f%% \n", (counts_unos[1] * 100) / total);
    printf("Channel #2\t %.2f%% \n", (counts_unos[2] * 100) / total);
    printf("Channel #3\t %.2f%% \n", (counts_unos[3] * 100) / total);
    printf("Channel #4\t %.2f%% \n", (counts_unos[4] * 100) / total);
    printf("Channel #5\t %.2f%% \n", (counts_unos[5] * 100) / total);
    printf("Channel #6\t %.2f%% \n", (counts_unos[6] * 100) / total);
    printf("Channel #7\t %.2f%% \n", (counts_unos[7] * 100) / total);
    printf("Channel #8\t %.2f%% \n", (counts_unos[8] * 100) / total);
    printf("Channel #9\t %.2f%% \n", (counts_unos[9] * 100) / total);
    printf("Channel #10\t %.2f%% \n", (counts_unos[10] * 100) / total);
    printf("Channel #11\t %.2f%% \n", (counts_unos[11] * 100) / total);
    printf("Channel #12\t %.2f%% \n", (counts_unos[12] * 100) / total);
    printf("Channel #13\t %.2f%% \n", (counts_unos[13] * 100) / total);
    printf("Channel #14\t %.2f%% \n", (counts_unos[14] * 100) / total);
    printf("Channel #15\t %.2f%% \n", (counts_unos[15] * 100) / total);
}
