/**
 * @file    Funciones.c
 * @brief   [ESP] Archivo fuente de resolución de ejercicios. Final 08/2021.
 *          [ENG] Exercises resolution source file. Final 08/2021.
 *
 * @author  Facundo Costarelli
 * @date    2021
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/*
 * [ESP] EJERCICIO 1
 * Considerar que los enteros son de 4 bytes y los valores correspondientes al código ASCII son los 8
 * bits del segundo byte menos significativo, es decir los 16 bits de mayor peso no importan, los 8 bits
 * que siguen son el código ASCII y los 8 bits de menor peso no importan.
 * 
 * [ENG] EXERCISE 1
 * Consider 4-bytes integers where ASCII valid values belong to the 8 bits standing on the second least
 * significant byte. Meaning the uppermost 16 bits do not matter, the next 8 bits define the ASCII char,
 * and the lowest 8 bits do not matter.
 */

/**
 * @brief [ESP] Convierte arreglo de enteros a caracteres extrayendo su segundo byte (LSB).
 *        [ENG] Converts an int array to characters by extracting their second byte (LSB).
 *
 * @param IntArray   [ESP] Vector de enteros / [ENG] Integer array
 * @param Arraylargo [ESP] Largo del arreglo / [ENG] Array length
 * @param Frase      [ESP] Puntero doble a string destino / [ENG] Double pointer to target string
 * @return EXITO / ERROR
 */
int Convertir_IntArray_To_CharArray(int *IntArray, int Arraylargo, char **Frase)
{
    char *String = NULL;
    int Mascara = 0x000000FF;
    int i = 0;

    String = (char *)malloc((Arraylargo + 1) * sizeof(char));
    if(String == NULL) return ERROR;

    for( i = 0; i < Arraylargo; i++ )
        printf("IntArray[%d] = %d\n", i, IntArray[i]);

    /* [ESP] Aplico shift >> 8 BITS para llevar el segundo byte al LSB y luego mascara / [ENG] Shift and mask */
    for( i = 0; i < Arraylargo; i++ )
    {
        String[i] = (char)( (IntArray[i] >> _8BITS) & Mascara);
        printf("Caracter de string: %c\n", String[i]);
    }
    String[i] = '\0';

    printf("El String queda como: %s\n", String);
    *Frase = String;

    return EXITO;
}

/*
 * [ESP] EJERCICIO 2
 * Función que recibe un string (nombre de archivo), busca el último punto y devuelve un nombre
 * modificado añadiendo un sufijo "_decrypt".
 * 
 * [ENG] EXERCISE 2
 * Function receiving a file name, mapping its target extension and adding a suffix "_decrypt".
 */

/**
 * @brief [ESP] Modifica un nombre de archivo inyectando una frase antes de la extensión.
 *        [ENG] Modifies a filename appending a phrase before its extension.
 *
 * @return EXITO / ERROR
 */
int ModificarNombreFileIn(char *Nombre_Archivo_In, char *Nombre_Archivo_Out)
{
    size_t i = 0, j = 0;
    char buffer_nombre[30];
    char buffer_extension[10];
    char buffer_frase[] = "_decrypt";
    int flag = 1;

    if(flag == 1)
    {
        memset(buffer_nombre, '\0', sizeof(buffer_nombre));
        memset(buffer_extension, '\0', sizeof(buffer_extension));
        flag = EXITO;
    }
    else return ERROR;

    if(flag == EXITO )
    {
        for( i = 0; Nombre_Archivo_In[i] != '.'; i++ )
            buffer_nombre[i] = Nombre_Archivo_In[i];

        for( j = 0; Nombre_Archivo_In[i] != '\0'; j++, i++ )
            buffer_extension[j] = Nombre_Archivo_In[i];

        flag = EXITO;
    }
    else return ERROR;

    if( flag == EXITO )
    {
        for( i = 0; i < strlen(buffer_nombre); i++ )
            Nombre_Archivo_Out[i] = buffer_nombre[i];
            
        for( j = 0; j < strlen(buffer_frase); j++, i++ )
            Nombre_Archivo_Out[i] = buffer_frase[j];
            
        for( j = 0; j < strlen(buffer_extension); j++, i++ )
            Nombre_Archivo_Out[i] = buffer_extension[j];

        Nombre_Archivo_Out[i] = '\0';
        flag = EXITO;
    }
    else return ERROR;

    if( flag == EXITO) return EXITO;
    else return ERROR;
}

/*
 * [ESP] EJERCICIO 3
 * Lectura de tamaño desconocido de enteros de 4-bytes desde archivo binario hacia memoria dinámica.
 * 
 * [ENG] EXERCISE 3
 * Unbound parsing of 4-byte integers arriving from binary file injected into newly allocated memory.
 */

/**
 * @brief [ESP] Lee enteros de 4 bytes desde archivo binario a buffer en heap.
 *        [ENG] Reads 4 byte ints from a binary file into a dynamic buffer.
 *
 * @return int [ESP] Cantidad de enteros leídos / [ENG] Number of parsed integers
 */
int LecturaEnterosDe_4_BytesFileInBinario(char *Nombre_Archivo_In, int **Buffer_enteros)
{
    FILE *File_In = NULL;
    int CantidadEnteros_File_In = 0;
    long tamanio_archivo = 0;

    File_In = fopen(Nombre_Archivo_In, "r");
    if(File_In == NULL) return ERROR;

    fseek(File_In, 0, SEEK_END);
    tamanio_archivo = ftell(File_In);
    CantidadEnteros_File_In = ((int)tamanio_archivo) / ((int)sizeof(int));
    printf("La cantidad de enteros de 4 bytes es tipo: %d\n", CantidadEnteros_File_In);
    fseek(File_In, 0, SEEK_SET);

    (*Buffer_enteros) = (int *)malloc(CantidadEnteros_File_In * sizeof(int));
    if(*Buffer_enteros == NULL) return ERROR;

    if( fread(*Buffer_enteros, CantidadEnteros_File_In * sizeof(int), 1, File_In) < 1 )
        return ERROR;

    fclose(File_In);
    return CantidadEnteros_File_In;
}
