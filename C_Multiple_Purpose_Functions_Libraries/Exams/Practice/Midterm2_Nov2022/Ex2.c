/**
 * @file    Ej2.c
 * @brief   [ESP] Ejercicio 2 2do Parcial Nov 2022: Ordenamiento burbuja de cadenas dinámicas.
 *          [ENG] Exercise 2 2nd Midterm Nov 2022: Bubble sort of dynamic strings.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>

#define LONGITUD_CADENAS 100

/**
 * @brief [ESP] Solicita memoria dinámica y carga la línea de texto ingresada.
 *        [ENG] Requests dynamic memory and loads the entered line of text.
 */
char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );

/**
 * @brief [ESP] Ordena un listado de cadenas mediante el algoritmo burbuja.
 *        [ENG] Sorts an array of strings using bubble sort algorithm.
 */
char **Ordenamiento_Burbuja_Strings( char **listado );

/**
 * @brief [ESP] Crea y redimensiona dinámicamente un array de punteros a strings.
 *        [ENG] Dynamically creates and expands an array of pointers to strings.
 */
int Creacion_Lista_Strings(char ***ptrA);

/**
 * @brief [ESP] Imprime la lista de cadenas actual.
 *        [ENG] Prints the current list of strings.
 */
void Impresion_Lista_Strings(int count, char **ptrA);

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(void)
{
    char **ptrA = NULL;
    int i, count;

    printf("Bienvenido, este programa ordena alfabeticamente listas de palabras. Estos pueden ser nombres, apellidos, etc.\n Usted debera ingresar al menos una palabra para armar su listado\n");

    /* [ESP] Creación de listado de strings / [ENG] Creation of string list */
    count = Creacion_Lista_Strings(&ptrA);

    /* [ESP] Impresión antes de ordenar / [ENG] Printing before sorting */
    Impresion_Lista_Strings(count, ptrA);

    /* [ESP] Ordenamiento burbuja / [ENG] Bubble sort */
    ptrA = Ordenamiento_Burbuja_Strings(ptrA);

    /* [ESP] Impresión después de ordenar / [ENG] Printing after sorting */
    Impresion_Lista_Strings(count, ptrA);

    /* [ESP] Liberación de memoria / [ENG] Memory freeing */
    for( i = 0; i < count; i++ )
        free(ptrA[i]);
    free(ptrA);

    return 0;
}

int Creacion_Lista_Strings(char ***ptrA)
{
    char **ptrA_aux = NULL;
    size_t count = 1;
    char decision;

    do
    {
        /* [ESP] Array de punteros / [ENG] Pointers array */
        ptrA_aux = (char **)reallocarray(*ptrA, count, sizeof(char *));
        if( ptrA_aux == NULL )
        {
            printf("Ha ocurrido un error con la asignacion de memoria dinamica\n");
            return(-1);
        }
        *ptrA = ptrA_aux;

        /* [ESP] Carga de cadena / [ENG] Loading string */
        *(*(ptrA) + count-1) = Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( *(ptrA) + count-1 );

        do
        {
            printf("Desea ingresar otro nombre? Presione: SI(S) o NO(N): ");
            scanf("%c", &decision);
            __fpurge(stdin);

            if( decision != 'S' && decision != 'N')
                printf("Caracter invalido. Ingrese correcta.\n");
        } while( decision != 'S' && decision != 'N');

        if( decision == 'S')
            count++;
        else
        {
            count++;
            ptrA_aux = (char **)reallocarray( *ptrA, count, sizeof(char *));
            if( ptrA_aux == NULL )
            {
                printf("Ha ocurrido un error con la asignacion de memoria dinamica\n");
                return(-1);
            }
            *ptrA = ptrA_aux;
            *(*(ptrA) + count-1) = NULL;
        }
    } while( decision == 'S');

    return count;
}

char **Ordenamiento_Burbuja_Strings(char **listado)
{
    char temp[LONGITUD_CADENAS];
    int swapped;
    int i;

    do
    {
        swapped = 0;
        for(i = 0; listado[i+1] != NULL; i++)
        {
            if(strcmp(listado[i], listado[i+1]) > 0)
            {
                swapped = 1;
                strcpy(temp, listado[i]);
                strcpy(listado[i], listado[i+1]);
                strcpy(listado[i+1], temp);
            }
        }
    } while(swapped == 1);

    return listado;
}

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer )
{
    size_t capacidad = LONGITUD_CADENAS;
    ssize_t cantcaracteresleidos;

    printf("Ingrese por favor la palabra deseada a cargar en la lista: ");
    cantcaracteresleidos = getline( buffer, &capacidad, stdin );

    if( cantcaracteresleidos == -1 )
    {
        printf("Hay un error con la lectura del texto ingresado");
        exit(-1);
    }
    else
    {
        printf("Caracteres leidos: %li\n", cantcaracteresleidos);
        printf("Texto ingresado: %s\n", *buffer);
    }
    
    *(*(buffer)+(cantcaracteresleidos-1))= '\0';

    return *buffer;
}

void Impresion_Lista_Strings(int count, char **ptrA)
{
    int i;
    printf("La lista ordenada de la siguiente manera: \n");
    for( i = 0; i < count-1; i++ )
        printf("- %s -\n", ptrA[i]);
}
