/**
 * @file    file_copy.c
 * @brief   [ESP] Copia un archivo fuente .c eliminando líneas de comentarios.
 *          [ENG] Copies a .c source file while removing comment lines.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Código de referencia que demuestra cómo copiar un archivo fuente
 *       carácter a carácter, detectando y omitiendo las secuencias de
 *       comentarios // y /* ... *​/.
 *
 * [ENG] Reference code demonstrating how to copy a source file character
 *       by character, detecting and skipping comment sequences
 *       // and /* ... *​/.
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define EXITO  0

/**
 * @brief [ESP] Programa que copia un archivo .c sin sus comentarios.
 *        [ENG] Program that copies a .c file without its comments.
 *
 * [ESP] Uso: ./ejecutable archivo_entrada.c
 *       La salida se escribe en "copia.c"
 * [ENG] Usage: ./executable input_file.c
 *       Output is written to "copia.c"
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("[ESP] Uso: <ejecutable> <archivo_entrada.c>\n");
        printf("[ENG] Usage: <executable> <input_file.c>\n");
        return ERROR;
    }

    FILE *File_In = NULL;
    FILE *File_Out = NULL;
    char ch = '\0';

    /* [ESP] Abrir archivo de entrada en modo lectura
       [ENG] Open input file in read mode */
    File_In = fopen(argv[1], "r");
    if (File_In == NULL)
    {
        printf("[ESP] Error en apertura de archivo de entrada.\n");
        printf("[ENG] Error opening input file.\n");
        return ERROR;
    }

    /* [ESP] Abrir/crear archivo de salida en modo escritura
       [ENG] Open/create output file in write mode */
    File_Out = fopen("copia.c", "w");
    if (File_Out == NULL)
    {
        printf("[ESP] Error en apertura de archivo de salida.\n");
        printf("[ENG] Error opening output file.\n");
        fclose(File_In);
        return ERROR;
    }

    /* [ESP] Lectura carácter a carácter, omitiendo secuencias de comentarios
       [ENG] Character-by-character reading, skipping comment sequences */
    ch = fgetc(File_In);
    while (ch != EOF)
    {
        if (ch == '/')
        {
            ch = fgetc(File_In);

            if (ch == '*')
            {
                /* [ESP] Comentario de bloque: avanzar hasta encontrar '*​/'
                   [ENG] Block comment: advance until '*​/' is found */
                for ( ; (ch = fgetc(File_In)) != '*'; );
                ch = fgetc(File_In); /* [ESP] Saltar '/' / [ENG] Skip '/' */
                ch = fgetc(File_In); /* [ESP] Siguiente carácter válido / [ENG] Next valid char */
            }
            else if (ch == '/')
            {
                /* [ESP] Comentario de línea: avanzar hasta '\n'
                   [ENG] Line comment: advance until '\n' */
                for ( ; (ch = fgetc(File_In)) != '\n'; );
            }
        }

        /* [ESP] Escribir carácter no-comentario en el archivo de salida
           [ENG] Write non-comment character to the output file */
        fputc(ch, File_Out);
        ch = fgetc(File_In);
    }

    printf("[ESP] Copia realizada exitosamente.\n");
    printf("[ENG] Copy completed successfully.\n");

    fclose(File_In);
    fclose(File_Out);

    return EXITO;
}
