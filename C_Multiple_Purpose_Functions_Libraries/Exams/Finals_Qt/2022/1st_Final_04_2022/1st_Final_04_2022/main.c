/**
 * @file    main.c
 * @brief   [ESP] Archivo main (Final 04/2022). Evalúa lotes en I/O.
 *          [ENG] Main file (Final 04/2022). Evaluates I/O logic data batches.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Función principal con IO binaria e interacción lógica de uniones con bitfields.
 *        [ENG] Main sequence applying IO buffering and bitfields union tracking logic computations.
 */
int main(int argc, char**argv)
{
    if( argc != 3)
    {
        printf("Cantidad insuficiente de argumentos, reingresar segun <nombre_ejecutable> <arch_entrada> <arch_salida>\n");
        return EARGS;
    }

    FILE *File_in = NULL;
    int CantidadUniones_FileIn = 0;
    long tamanio_archivo = 0;
    int i = 0;
    union logic_in *Buffer_Read_in = NULL;

    FILE *File_out = NULL;
    int CantidadUniones_FileOut = 0; 
    union logic_out *Buffer_Read_out = NULL;

    int counts[CANTIDAD_ELEMENTOS_ARRAY_DATOS];
    
    for( i = 0; i < CANTIDAD_ELEMENTOS_ARRAY_DATOS; i++ )
        counts[i] = 0;

    File_in = fopen(argv[1], "r");
    if( File_in == NULL ) return EINFILE;

    fseek(File_in, 0, SEEK_END);
    tamanio_archivo = ftell(File_in);
    CantidadUniones_FileIn = ((int)tamanio_archivo) / ((int)sizeof(union logic_in));
    printf("La cantidad de estructuras tipo union logic_in son: %d\n", CantidadUniones_FileIn);
    fseek(File_in, 0, SEEK_SET);

    Buffer_Read_in = (union logic_in *)malloc(CantidadUniones_FileIn * sizeof(union logic_in));
    if( Buffer_Read_in == NULL ) return ERROR;

    if ( fread(Buffer_Read_in, CantidadUniones_FileIn * sizeof(union logic_in), 1, File_in) < 1 )
        return ERROR;

    fclose(File_in);

    CantidadUniones_FileOut = CantidadUniones_FileIn;

    File_out = fopen(argv[2], "wb");
    if( File_out == NULL ) return EOUTFILE;

    Buffer_Read_out = (union logic_out *)malloc(CantidadUniones_FileOut * sizeof(union logic_out));
    if( Buffer_Read_out == NULL ) return ERROR;

    /** [ESP] Llamada a funciones procesadoras / [ENG] Processing routine call back */
    for( i = 0; i < CantidadUniones_FileOut; i++ )
    {
        process_data(&Buffer_Read_in[i], &Buffer_Read_out[i]);
        compute_zeroes(&Buffer_Read_in[i], counts);
    }

    print_stats(counts, CantidadUniones_FileIn);

    fwrite(Buffer_Read_out, sizeof(union logic_out), 1 /*CantidadUniones_FileOut*/, File_out);

    fclose(File_out);
    free(Buffer_Read_in);
    free(Buffer_Read_out);

    printf("Se ejecuto correctamente el programa\n");
    return EXITO;
}
