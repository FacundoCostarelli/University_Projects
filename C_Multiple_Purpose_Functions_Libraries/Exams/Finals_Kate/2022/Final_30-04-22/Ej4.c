#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>

// constantes simbolicas
#define OK           0  // funcion terminada correctamente
#define EARGS       -1  // error en la cantdad de argumentos
#define EINFILE     -2  // error al abrir el archivo de entrada
#define EOUTFILE    -3  // error al abrir el archivo de salida

#define NCHANNELS   16

// definicion de la union para la lectura de datos
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

// definicion de la union para la escritura de datos
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
void compute_zeroes(union logic_in *din, int counts[]);
void print_stats( int counts[], int total);

int main(int argc, char *argv[]) //char *argv[] es equivalente a escirbir char **argv
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

    while(var1.data < 10)
    {
        do
        {
            porciones_bytes_leidos = fread(&(var1.data), sizeof(unsigned short int), 1, f_in);
        }while(porciones_bytes_leidos == 0);

        binary = toBinary( var1.data, 8 * sizeof(var1.data));

        printf("El dato de entrada ingresado fue: %u\n", var1.data);
        printf("Su representacion binaria es %s: \n", binary);

        //Llamado a funcion que realiza la impresion de los bits de los canales de la union de entrada
        Impresion_union_logic_in(&var1);

        //Llamado a funcion que realiza el procesamiento de la data de entrada ubicada en la union de entrada y carga el dato de salida en la union de salida
        process_data(&var1, &var2);

        //Llamado a funcion que realiza la impresion de los bits de los canales de la union de salida
        Impresion_union_logic_out(&var2);

        printf("El dato de salida obtenido luego del procesamiento fue: %d\n",var2.data);

        //Llamado a funcion que computa que canales de entrada estan en cero logico
        compute_zeroes(&var1, counts);

        do
        {
            porciones_bytes_escritos = fwrite(&(var2.data), sizeof(unsigned char), 1, f_out);
        }while(porciones_bytes_escritos == 0);

        total_muestras_procesadas++;
    }

    clearerr(f_in);

    //Llamado a funcion que imprime en pantalla el porcentaje de unos logicos que hubo en cada canal de entrada en la union de entrada
    print_stats( counts, total_muestras_procesadas);

    fclose(f_in);
    fclose(f_out);

    return OK;
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

// funcion que procesa uu dato de entrada y arma el dato de salida
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

//funcion que computa que entradas estan en cero
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

// funcion que imprime en pantalla el porcentaje de unos en cada entrada
void print_stats( int counts[], int total) //Escribir int counts[] es lo mismo que escribir int *counts
{
    float counts_unos[NCHANNELS];
    int i;

    for( i = 0; i < NCHANNELS; i++ )
        counts_unos[i] = total - counts[i];

    printf("Channel #0\t %.2f%% ", (counts_unos[0] * 100) / total);
    printf("\nChannel #1\t %.2f%% ", (counts_unos[1] * 100) / total);
    printf("\nChannel #2\t %.2f%% ", (counts_unos[2] * 100) / total);
    printf("\nChannel #3\t %.2f%% ", (counts_unos[3] * 100) / total);
    printf("\nChannel #4\t %.2f%% ", (counts_unos[4] * 100) / total);
    printf("\nChannel #5\t %.2f%% ", (counts_unos[5] * 100) / total);
    printf("\nChannel #6\t %.2f%% ", (counts_unos[6] * 100) / total);
    printf("\nChannel #7\t %.2f%% ", (counts_unos[7] * 100) / total);
    printf("\nChannel #8\t %.2f%% ", (counts_unos[8] * 100) / total);
    printf("\nChannel #9\t %.2f%% ", (counts_unos[9] * 100) / total);
    printf("\nChannel #10\t %.2f%% ", (counts_unos[10] * 100) / total);
    printf("\nChannel #11\t %.2f%% ", (counts_unos[11] * 100) / total);
    printf("\nChannel #12\t %.2f%% ", (counts_unos[12] * 100) / total);
    printf("\nChannel #13\t %.2f%% ", (counts_unos[13] * 100) / total);
    printf("\nChannel #14\t %.2f%% ", (counts_unos[14] * 100) / total);
    printf("\nChannel #15\t %.2f%% ", (counts_unos[15] * 100) / total);
    printf("\n");
    return;
}

