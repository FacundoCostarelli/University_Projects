/**
 * @file    Funciones.c
 * @brief   [ESP] Funciones para Ejercicio 1 (Paridad y Verificación).
 *          [ENG] Functions for Exercise 1 (Parity and Verification).
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

unsigned char paridad(char *s, int c)
{
    int i = 0;
    unsigned char bytedeparidad = s[0];

    for( i = 1; i < c; i++ )
    {
        bytedeparidad = bytedeparidad ^ s[i];
    }

    return bytedeparidad;
}

int verif(char *f1, char *f2)
{
    FILE *File_in1 = NULL;
    FILE *File_in2 = NULL;
    int CantidadEstructuras_FileIn1 = 0;
    int Cantidadbytes_FileIn2 = 0;
    long tamanio_archivo1 = 0;
    long tamanio_archivo2 = 0;
    int i = 0;
    struct datos *Buffer_Read_in1 = NULL;
    unsigned char *buffer_Read_in_bytesdeparidad = NULL;
    unsigned char bytedeparidad = 0;
    int cantidad_errores = 0;

    /* [ESP] Archivo de entrada 1 / [ENG] Input file 1 */
    File_in1 = fopen(f1, "r");
    if( File_in1 == NULL )
    {
        printf("Ocurrio un erorr en la apertura del archivo de entrada\n");
        return ERROR;
    }

    fseek(File_in1, 0, SEEK_END);
    tamanio_archivo1 = ftell(File_in1);
    CantidadEstructuras_FileIn1 = ((int)tamanio_archivo1) / ((int)sizeof(struct datos));
    printf("Cantidad de estructuras struct datos: %d\n", CantidadEstructuras_FileIn1);
    fseek(File_in1, 0, SEEK_SET);

    /* [ESP] Memoria dinámica 1 / [ENG] Dynamic memory 1 */
    Buffer_Read_in1 = (struct datos *)malloc(CantidadEstructuras_FileIn1 * sizeof(struct datos));
    if( Buffer_Read_in1 == NULL ) return ERROR;

    if ( fread(Buffer_Read_in1, CantidadEstructuras_FileIn1 * sizeof(struct datos), 1, File_in1) < 1 )
    {
        printf("Error con la lectura de estructuras\n");
        return ERROR;
    }

    /* [ESP] Archivo de entrada 2 / [ENG] Input file 2 */
    File_in2 = fopen(f2, "r");
    if( File_in2 == NULL ) return ERROR;

    fseek(File_in2, 0, SEEK_END);
    tamanio_archivo2 = ftell(File_in2);
    Cantidadbytes_FileIn2 = ((int)tamanio_archivo2) / ((int)sizeof(char));
    printf("Cantidad de bytes de paridad: %d\n", Cantidadbytes_FileIn2);
    fseek(File_in2, 0, SEEK_SET);

    /* [ESP] Memoria dinámica 2 / [ENG] Dynamic memory 2 */
    buffer_Read_in_bytesdeparidad = (unsigned char *)malloc( Cantidadbytes_FileIn2 * sizeof(unsigned char));
    if( buffer_Read_in_bytesdeparidad == NULL ) return ERROR;

    if ( fread(buffer_Read_in_bytesdeparidad, Cantidadbytes_FileIn2 * sizeof(unsigned char), 1, File_in2) < 1 )
    {
        printf("Error con la lectura de paridad\n");
        return ERROR;
    }

    /* [ESP] Verificación de bytes / [ENG] Bytes verification */
    for( i = 0; i < CantidadEstructuras_FileIn1; i++ )
    {
        bytedeparidad = paridad((char *)&Buffer_Read_in1[i], sizeof(Buffer_Read_in1[i]));
        if( buffer_Read_in_bytesdeparidad[i] != bytedeparidad)
            cantidad_errores++;
    }

    /* [ESP] Liberar memoria y archivos / [ENG] Free memory and files */
    free(Buffer_Read_in1);
    free(buffer_Read_in_bytesdeparidad);
    fclose(File_in1);
    fclose(File_in2);

    return cantidad_errores;
}
