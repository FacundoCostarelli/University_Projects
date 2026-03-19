/**
 * @file    bin_read_int32.c
 * @brief   [ESP] Lectura de enteros de 32 bits desde archivo binario.
 *          [ENG] Reading 32-bit integers from a binary file.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "file_io.h"

/**
 * @brief [ESP] Lee enteros de 4 bytes desde un archivo binario.
 *        [ENG] Reads 4-byte integers from a binary file.
 */
int LecturaEnterosDe_4_BytesFileInBinario(char *Nombre_Archivo_In, int **Buffer_enteros)
{
    FILE *File_In = NULL;
    int CantidadEnteros_File_In = 0;
    long tamanio_archivo = 0;

    /* [ESP] Abrir el archivo binario en modo lectura
       [ENG] Open the binary file in read mode */
    File_In = fopen(Nombre_Archivo_In, "r");
    if (File_In == NULL)
        return ERROR;

    /* [ESP] Posicionar el indicador de posición al final del archivo
             para poder calcular su tamaño con ftell().
       [ENG] Position the file indicator at the end of the file
             so we can calculate its size with ftell(). */
    fseek(File_In, 0, SEEK_END);
    tamanio_archivo = ftell(File_In);

    /* [ESP] Calcular la cantidad de enteros: tamaño_archivo / sizeof(int)
       [ENG] Calculate number of integers: file_size / sizeof(int) */
    CantidadEnteros_File_In = ((int)tamanio_archivo) / ((int)sizeof(int));

    /* [ESP] Reposicionar al inicio para la lectura
       [ENG] Reposition to the beginning for reading */
    fseek(File_In, 0, SEEK_SET);

    /* [ESP] Alocar memoria dinámica para el buffer de enteros
       [ENG] Allocate dynamic memory for the integer buffer */
    (*Buffer_enteros) = (int *)malloc(CantidadEnteros_File_In * sizeof(int));
    if (*Buffer_enteros == NULL)
        return ERROR;

    /* [ESP] Leer todos los enteros del archivo al buffer de memoria
       [ENG] Read all integers from the file into the memory buffer */
    if (fread(*Buffer_enteros, CantidadEnteros_File_In * sizeof(int), 1, File_In) < 1)
        return ERROR;

    /* [ESP] Cerrar el archivo de entrada
       [ENG] Close the input file */
    fclose(File_In);

    /* [ESP] NOTA: La memoria debe liberarse con free() en el scope que llama.
       [ENG] NOTE: Memory must be freed with free() in the calling scope. */
    return CantidadEnteros_File_In;
}
