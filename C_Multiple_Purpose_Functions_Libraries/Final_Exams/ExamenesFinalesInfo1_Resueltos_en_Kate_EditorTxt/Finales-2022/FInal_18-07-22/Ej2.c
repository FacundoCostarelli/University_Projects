#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>


int *Mi_Funcion(int **array, FILE *ptr, long int tamanio_file);

int main( int argc, char *argv[])
{
    FILE *ptr = NULL;
    int *array = NULL;
    int i, Cant_Caracteres = 26;
    long int tamanio_file;

    if( argc != 2 )
    {
        printf("Error. Ingrese solamente 2 nombres de archivos. <ejecutable> <nombre_archivo_in.txt>\n");
        return -1;
    }

    ptr = fopen(argv[1], "r");
    if( ptr == NULL )
    {
        printf("Error al abrir el archivo de texto de entrada\n");
        return -1;
    }

    fseek(ptr, 0L, SEEK_END);

    tamanio_file = ftell(ptr);

    fseek(ptr, 0L, SEEK_SET);

    array = Mi_Funcion(&array, ptr, tamanio_file);

    for( i = 0; i < Cant_Caracteres; i++ )
        printf("|%d| ", *(array + i));
    printf("\n");

    fclose(ptr);
    free(array);

    printf("Se cerro correctamente el archivo y se libero memoria dinamica\n");

    return 0;
}

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
        printf("Error con la asignacion de memoria dinamica para el vector que cuenta caracteres repetidos\n");
        exit(-1);
    }
    else
    {
        *array = ptr_aux;

        for( i = 0; i < Cant_Caracteres; i++ )
           *( (*array) + i ) = 0;
            //*array[i] = 0;
    }

    for( j = 0; j < tamanio_file-1; j++ )
    {
        if ( ( codgio_caracter = fgetc(ptr) ) == EOF )
        {
            printf("Error al leer un caracter del archivo.\nEl current file position esta ya ubicado justo despues del ultimo caracter en el archivo o sucede otro problema\n");
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
                    //*array[i] += 1;
                }
                i++;
                CarMay++;
                CarMin++;
            }
        }

    }


    printf("El vector cargado queda como: \n");
    /*
    for( i = 0; i < Cant_Caracteres; i++ )
        printf("|%d| ", *( (*array) + i ) );

    printf("\n");
    */
    for( CarMay = 'A'; CarMay <= 'Z'; CarMay++ )
        printf("|%c| ", CarMay);

    printf("\n");

    for( CarMin = 'a'; CarMin <= 'z'; CarMin++ )
        printf("|%c| ", CarMin);

    printf("\n");


    return *array;

}
