/**
 * @file    FileBinCrearEscribir.c
 * @brief   [ESP] Script para mockear archivo binario.
 *          [ENG] Script creating dummy binary file for assertions.
 *
 * @author  Facundo Costarelli
 * @date    2021
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Main function that dumps a static array into a binary file.
 *        [ENG] Main function creating test data and writing to disk.
 */
int main(void)
{
    FILE *File_out = NULL;
    int ArrayEnteros[10] = {5, 8, 236, 3715, 57292, -3274, -3612, 38, 9521, 10};

    File_out = fopen("informacion.dat", "wb");
    if(File_out == NULL)
    {
        printf("Hubo un error durante la apertura del archivo de salida binario\n");
        return -1;
    }

    fwrite(ArrayEnteros, sizeof(int), 10, File_out);
    fclose(File_out);
    
    return 0;
}
