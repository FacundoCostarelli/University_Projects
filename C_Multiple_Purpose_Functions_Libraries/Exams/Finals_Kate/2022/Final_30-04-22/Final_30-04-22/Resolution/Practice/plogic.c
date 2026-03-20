/**
 * @file    plogic.c
 * @brief   [ESP] Archivo principal main. (Resolución). Final 30-04-2022.
 *          [ENG] Main core file. (Resolution). Final 30-04-2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>
#include "func_plogic.h"

/**
 * @brief [ESP] Función principal del programa.
 *        [ENG] Main function of program.
 *
 * @param ac [ESP] Cantidad de argumentos / [ENG] Number of arguments
 * @param av [ESP] Argumentos pasados (infile outfile) / [ENG] Passed arguments
 * @return OK [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main(int ac, char **av) 
{
    FILE *fpi, *fpo;
    union logic_in data_in;
    union logic_out data_out;
    int total_count = 0;
    int input_count[NCHANNELS] = {0};

    /* [ESP] Verificacion de la cantidad de argumentos / [ENG] Argument verification */
    if (ac != 3) {
        printf("Error al invocar %s\n", av[0]);
        return EARGS;
    }
    
    /* [ESP] Abro el archivo de entrada de datos / [ENG] Open input data file */
    if ((fpi = fopen(av[1], "r")) == NULL) {
        printf("Error al abrir el archivo de entrada '%s'\n", av[1]);
        return EINFILE;
    }
    
    /* [ESP] Abro el archivo de salida de datos / [ENG] Open output data file */
    if ((fpo = fopen(av[2], "w")) == NULL) {
        fclose(fpi);
        printf("Error al abrir el archivo de salida '%s'\n", av[2]);
        return EOUTFILE;
    }

    while(1) {
        /* [ESP] Leo un dato del archivo de entrada / [ENG] Read a data from input file */
        fread(&(data_in.data), sizeof(data_in.data), 1, fpi);
        if(feof(fpi)) break;
        
        /* [ESP] Proceso el dato / [ENG] Process the data */
        process_data(&data_in, &data_out);

        /* [ESP] Computo los unos / [ENG] Compute the ones */
        compute_zeroes(&data_in, input_count);

        /* [ESP] Incremento el contador total / [ENG] Increment total counter */
        total_count++;

        /* [ESP] Escribo el dato procesado / [ENG] Write processed data */
        fwrite(&(data_out.data), sizeof(data_out.data), 1, fpo);
    }
    
    /* [ESP] Imprimo los porcentajes / [ENG] Print percentages */
    print_stats(input_count, total_count);

    /* [ESP] Cierro los archivos / [ENG] Close the files */
    fclose(fpi);
    fclose(fpo);
    
    return OK;
}
