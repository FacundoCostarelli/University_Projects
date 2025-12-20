#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>
#define LONGITUD_CADENAS 100
char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );
char **Ordenamiento_Burbuja_Strings( char **listado );
int Creacion_Lista_Strings(char ***ptrA);
void Impresion_Lista_Strings(int count, char **ptrA);
int main(void)
{
    char **ptrA = NULL;
    int i, count;
    printf("Bienvenido, este programa ordena alfabeticamente listas de palabras. Estos pueden ser nombres, apellidos, etc. Usted debera ingresar al menos una palabra para armar su listado\n");

    /*Llamado a funcion que crea dinamicamente un listado de strings de caracteres*/
    count = Creacion_Lista_Strings(&ptrA);

    /*Llamado a funcion que imprime la lista de strings antes de ordenarlos*/
    Impresion_Lista_Strings(count, ptrA);

    /*Llamado a funcion que ordena los strings de caracteres de la lista*/
    ptrA = Ordenamiento_Burbuja_Strings(ptrA);

    /*Llamado a funcion que imprime la lista de strings luego de ordenarlos*/
    Impresion_Lista_Strings(count, ptrA);

    /*Liberacion de memoria de las cadenas de caracteres*/
    for( i = 0; i < count; i++ )
        free(ptrA[i]);
    /*Liberacion de mememoria del array de punteros a cadenas de caracteres*/
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
        /*Creacion dinamica de array de punteros a cadenas de caracteres, es decir, el listado*/
        ptrA_aux = (char **)reallocarray(*ptrA, count, sizeof(char *));
        if( ptrA_aux == NULL )
        {
            printf("Ha ocurrido un error con la asignacion de memoria dinamica en linea 19\n");
            return(-1);
        }
        *ptrA = ptrA_aux;

        /*Creacion dinamica de cadenas de caracteres*/
        *(*(ptrA) + count-1) = Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( *(ptrA) + count-1 );

        do
        {
            printf("Desea ingresar otro nombre?\n Presione:SI(S) o NO(N): ");
            scanf("%c", &decision);
            __fpurge(stdin);

            if( decision != 'S' && decision != 'N')
                printf("Caracter invalido. Ingrese el caracter solicitado de forma correcta\n");

        }while( decision != 'S' && decision != 'N');

        if( decision == 'S')
            count++;
        /*Solicitud de memoria y carga del ultimo elemento puntero siendo este NULL en el array de punteros a cadenas*/
        else
        {
            count++;
            ptrA_aux = (char **)reallocarray( *ptrA, count, sizeof(char *));
            if( ptrA_aux == NULL )
            {
                printf("Ha ocurrido un error con la asignacion de memoria dinamica en linea 19\n");
                return(-1);
            }
            *ptrA = ptrA_aux;
            printf("count = %ld\n", count);
            *(*(ptrA) + count-1) = NULL;
        }
    }while( decision == 'S');

    return count;
}

char **Ordenamiento_Burbuja_Strings(char **listado) //char *listado[] es lo mismo que hacer char **listado
{
    char temp[LONGITUD_CADENAS];
    int swapped;
    int i;

    /*Algoritmo de ordenamiento burbuja de strings de caracteres*/
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
    }while(swapped == 1);

    return listado;
}

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer )
{
    size_t capacidad = LONGITUD_CADENAS;//size_t y ssize_t es lo mismo que escribir unsigned int. Es decir, es un tipo de dato entero sin signo, usualmente lo devuelve sizeof pero tambien se puede declarar asi nomas. Al ponerle 0, permito que getline() use malloc y realloc desde el 1er instante. De lo contrario, si pongo un valor ej 30. Pide memoria con malloc para 30 caracteres y luego si me paso, realocaliza con realloc
    ssize_t cantcaracteresleidos;//declaro una variable que guarda la cantidad de caracteres leidos por teclado

    printf("Ingrese por favor la palabra deseada a cargar en la lista: ");
    cantcaracteresleidos = getline( buffer, &capacidad, stdin );
    // Hay que tener en cuenta este prototipo para pasar bien los parametros a getline
    //ssize_t getline(char **lineptr, size_t *n, FILE *stream);


    if( cantcaracteresleidos == -1 )
    {
        printf("Hay un error con la lectura del texto ingresado");
        exit(-1);
    }
    else
    {
        printf("La cantidad de caracteres leidos teniendo en cuenta el caracter \" barra n \"fueron: %li\n", cantcaracteresleidos);
        printf("El texto ingresado fue: %s\n", *buffer);
    }
    //Elimino el caracter de nueva linea en el texto ingresado por teclado y lo reemplazo por el caracter \0
    *(*(buffer)+(cantcaracteresleidos-1))= '\0';

    return *buffer;
}

void Impresion_Lista_Strings(int count, char **ptrA)
{
    int i;

    printf("La lista actualmente se encuentra ordenada de la siguiente manera: \n");

    for( i = 0; i < count-1; i++ )
        printf("- %s -\n", ptrA[i]);
}
