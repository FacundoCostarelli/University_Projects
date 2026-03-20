/**
 * @file    func_plogic.h
 * @brief   [ESP] Cabecera de funciones lógicas. (Resolución). Final 30-04-2022.
 *          [ENG] Logical functions header. (Resolution). Final 30-04-2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#ifndef FUNC_PLOGIC_H
#define FUNC_PLOGIC_H

/* [ESP] Constantes simbolicas / [ENG] Symbolic constants */
#define OK           0  /* funcion terminada correctamente */
#define EARGS       -1  /* error en la cantdad de argumentos */
#define EINFILE     -2  /* error al abrir el archivo de entrada */
#define EOUTFILE    -3  /* error al abrir el archivo de salida */

#define NCHANNELS   16

/**
 * @brief [ESP] Definicion de la union para la lectura de datos.
 *        [ENG] Union definition for data reading.
 */
union logic_in {
    unsigned short int data;
    struct {
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
 * @brief [ESP] Definicion de la union para la escritura de datos.
 *        [ENG] Union definition for data writing.
 */
union logic_out {
    unsigned char data;
    struct {
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

/* [ESP] Prototipos de las funciones auxiliares / [ENG] Prototypes for aux functions */
void process_data(union logic_in *din, union logic_out *dout);
void compute_zeroes(union logic_in *d, int counts[]);
void print_stats(int counts[], int total);

#endif /* FUNC_PLOGIC_H */
