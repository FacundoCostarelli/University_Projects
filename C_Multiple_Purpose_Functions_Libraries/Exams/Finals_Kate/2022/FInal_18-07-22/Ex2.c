/**
 * @file    Ej2.c
 * @brief   [ESP] Ejercicio 2 - Final 18-07-2022. Frecuencia de caracteres a partir de un archivo.
 *          [ENG] Exercise 2 - Final 18-07-2022. Character frequency from a file.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

/**
 * @brief [ESP] Función que cuenta ocurrencias de caracteres en un archivo de texto.
 *        [ENG] Function that counts character occurrences in a text file.
 */
int *Mi_Funcion(int **array, FILE *ptr, long int tamanio_file);

/**
 * @brief [ESP] Función principal del Ejercicio 2.
 *        [ENG] Main function for Exercise 2.
 *
 * @param argc [ESP] Argumentos pasados (Se espera ejecutable y path relativo al archivo texto).
 *             [ENG] Passed arguments (Executable and relative text file path expected).
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main( int argc, char *argv[])
{
    FILE *ptr = NULL;
    int *array = NULL;
    int i, Cant_Caracteres = 26;
    long int tamanio_file;

    if( argc != 2 )
    {
        printf("Error. Ingrese: <ejecutable> <nombre_archivo_in.txt>\n");
        return -1;
    }

    /* [ESP] Apertura archivo / [ENG] File opening */
    ptr = fopen(argv[1], "r");
    if( ptr == NULL )
    {
        printf("Error al abrir el archivo de texto de entrada\n");
        return -1;
    }

    fseek(ptr, 0L, SEEK_END);
    tamanio_file = ftell(ptr);
    fseek(ptr, 0L, SEEK_SET);

    /* [ESP] Llamada a funcion de conteo / [ENG] Conteo function call */
    array = Mi_Funcion(&array, ptr, tamanio_file);

    /* [ESP] Imprimir resultados de la funcion conteo / [ENG] Print frequency array */
    for( i = 0; i < Cant_Caracteres; i++ )
        printf("|%d| ", *(array + i));
    printf("\n");

    /* [ESP] Cierre de archivos y liberacion de array devueltos por la funcion / [ENG] Free memories and files*/
    fclose(ptr);
    free(array);

    printf("Se cerro correctamente el archivo y se libero memoria dinamica\n");
    return 0;
}

/**
 * @brief [ESP] Analiza el archivo para contar la frecuencia de cada letra (ignora mayús/minús).
 *        [ENG] Parses the file to count frequency of each letter (ignores case).
 *
 * @param array        [ESP] Array dinámico para almacenar conteos / [ENG] Dynamic array for storing counts
 * @param ptr          [ESP] FILE Puntero al archivo / [ENG] FILE pointer to the file
 * @param tamanio_file [ESP] Tamaño del archivo / [ENG] File size
 * @return int*        [ESP] Puntero al array / [ENG] Pointer to the array
 */
int *Mi_Funcion(int **array, FILE *ptr, long int tamanio_file)
{
    int *ptr_aux = NULL;
    int Cant_Caracteres = 26;
    int i, j;
    char codgio_caracter;
    char CarMay, CarMin;

    ptr_aux = (int *)malloc(sizeof(int) * Cant_Caracteres);
    if( ptr_aux == NULL )
    {
        printf("Error asignacion dinamica\n");
        exit(-1);
    }
    else
    {
        *array = ptr_aux;
        for( i = 0; i < Cant_Caracteres; i++ )
           *( (*array) + i ) = 0;
    }

    for( j = 0; j < tamanio_file-1; j++ )
    {
        if ( ( codgio_caracter = fgetc(ptr) ) == EOF )
        {
            printf("Error EOF inesperado\n");
            exit(-1);
        }
        else
        {
            for( i = 0, CarMay = 'A', CarMin = 'a'; CarMay <= 'Z' && CarMin <= 'z' ;  )
            {
                if(codgio_caracter == CarMay || codgio_caracter == CarMin)
                {
                    *( (*array) + i ) += 1;
                    break;
                }
                i++;
                CarMay++;
                CarMin++;
            }
        }
    }

    /* [ESP] Imprime la cabecera en el vector / [ENG] Prints headers for the array */
    printf("El vector cargado queda como: \n");
    
    for( CarMay = 'A'; CarMay <= 'Z'; CarMay++ )
        printf("|%c| ", CarMay);
    printf("\n");

    for( CarMin = 'a'; CarMin <= 'z'; CarMin++ )
        printf("|%c| ", CarMin);
    printf("\n");

    return *array;
}
