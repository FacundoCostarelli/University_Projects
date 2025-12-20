#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#define CANTMAXCARACTERES 32

typedef struct nodo
{
    char nombre[CANTMAXCARACTERES];
    int cant;
    char codigo;
    struct nodo *sig;


}productos;

void Creacion_ListaSimplementeEnlazada(productos **ptrFirstElement, int *Cantidad_Nodos);
void CargaDeDatos_ListaSimplementeEnlazada( productos **ptrFirstElement, int *Cantidad_Nodos);
void Impresion_ListaSimplementeEnlazada(productos **ptrFirstElement); //int *Cantidad_Nodos);
void Mi_Funcion(productos **ptrFirstElement); //int *Cantidad_Nodos);


int main(void)
{
    productos *ptrFirstElement = NULL;
    int Cantidad_Nodos;
    //int i;
    printf("Bienvenido. Este programa le permite la creacion de una lista simplemente enlazada de estructuras de datos de forma dinamica y la carga de datos de la misma. Ademas realiza algunas operaciones en base los codigos ingresados y repetidos siendo: \n-Incrementa el numero de productos en el primer nodo de lista con un determinado codigo a partir de los codigos repetidos del mismo valor en los diferentes nodon\n-Borra de la lista todos los nodos que tienen un codigo repetido\n\n");

    /*Llamado a funcion que crea una lista simplemente enlazada*/
    Creacion_ListaSimplementeEnlazada(&ptrFirstElement, &Cantidad_Nodos);

    /*Llamado a funcion que carga informacion en las estructuras de datos que conforman la lista simplemente enlazada*/
    CargaDeDatos_ListaSimplementeEnlazada(&ptrFirstElement, &Cantidad_Nodos);

    printf("La lista queda creada y cargada de la siguiente manera: ");

    /*Llamado a funcion que imprime la lista simplemente enlazada*/
    Impresion_ListaSimplementeEnlazada(&ptrFirstElement); //&Cantidad_Nodos);

    /*Llamado a funcion que realiza las operatorias pertinentes a lo pedido por el ejercicio*/
    Mi_Funcion(&ptrFirstElement); //&Cantidad_Nodos);

    printf("La lista luego de realizar las operaciones pertinentes queda de la siguiente manera: ");

    /*Llamado a funcion que imprime la lista simplemente enlazada*/
    Impresion_ListaSimplementeEnlazada(&ptrFirstElement); //&Cantidad_Nodos);

    /*Liberacion de memoria dinamica utilizada para la lista*/
    free(ptrFirstElement);

    printf("Se ha liberado la memoria correctamente\n");
    return 0;
}

void Creacion_ListaSimplementeEnlazada(productos **ptrFirstElement, int *Cantidad_Nodos)
{
    productos *ptr_aux = NULL;
    productos *current = NULL;
    size_t count = 1;
    char decision;
    int i;

    /*Creacion de array dinamico de estructuras para formar una one-way linked list*/
    do
    {
        printf("Se creo la estructura #%lu\n", count);
        ptr_aux = (productos *)reallocarray(*ptrFirstElement, count, sizeof(productos));
        if( ptr_aux == NULL )
        {
            printf("Ha ocurrido un error con la asignacion de memoria dinamica para el array de estructuras\n");
            exit(-1);
        }
        *ptrFirstElement = ptr_aux;

        do
        {
            printf("Desea crear otra estructura de datos?\n Presione:SI(S) o NO(N): ");
            scanf("%c", &decision);
            __fpurge(stdin);

            if( decision != 'S' && decision != 'N')
                printf("Caracter invalido. Ingrese el caracter solicitado de forma correcta\n");

        }while( decision != 'S' && decision != 'N');

        if( decision == 'S')
            count++;
        else
            *Cantidad_Nodos = count;

    }while( decision == 'S' );

    /*Seteo al puntero actual tal que apunta a la 1er estructura*/
    current =  *ptrFirstElement;

    /*Creacion y tejimiento de la lista. El puntero actual apunta a la 1er estructura, alli guarda en el campo next(sig) la direccion de memoria de la 2da estructura y luego el puntero actual apunta a esta 2da estructura. El puntero actual apunta ahora a la 2da estructura y carga en el campo next(sig) la direccion de memoria de la 3er estructura y luego el puntero actual apunta a esta 3er estructura. Esto se repite asi sucesivamente*/
	for( i = 1; i < count; i++ )
	{
	    current->sig = ptr_aux+i;
	    current = current->sig;
	}

	/*El campo next(sig) de la ultima estructura se le asigna NULL*/
	current->sig = NULL;

    printf("Se ha creado correctamente una lista simplemente enlazada con una cantidad de nodos = %lu\n", count);

    return;
}

void  CargaDeDatos_ListaSimplementeEnlazada( productos **ptrFirstElement, int *Cantidad_Nodos)
{
    productos *current = NULL;
    int count, i;

    /*Seteo al puntero actual tal que apunta a la 1er estructura*/
    current =  *ptrFirstElement;
    //printf("%p\n", current);
    /*Asignacion del numero de la cantidad de nodos de la variable "Cantidad_Nodos" hacia la variable "count" para uso de forma local y simplificada*/
    count = *Cantidad_Nodos;
	/*Carga de datos cada uno de los campos de las estructuras a partir de recorrer toda la lista*/
	for( i = 0; i < count; i++ )
	{
        printf("Usted va a cargar ahora la estructura de datos #%d\n", i+1);
        printf("Ingrese el nombre del producto con un nro maximo de %d caracteres y sin espacios blancos ya que se recortara el nombre. En tal caso puede usar el caracter \"_\": ", CANTMAXCARACTERES);
        scanf("%s", current->nombre);
        __fpurge(stdin);

        printf("Ingrese la cantidad de productos de este tipo: ");
        scanf("%d", &(current->cant));
        __fpurge(stdin);

        do
        {
            printf("Ingrese el valor del codigo siendo este entre 1 y 10: ");
            scanf("%hhd", &(current->codigo));
            __fpurge(stdin);

            if((current->codigo) < 1 && (current->codigo) > 10)
                printf("Ha ingresado mal su codigo. Vuelva a intentarlo\n");

        }while((current->codigo) < 1 && (current->codigo) > 10);


	    current = current->sig;
        //printf("%p\n", current);

	}

    return;
}

void Impresion_ListaSimplementeEnlazada(productos **ptrFirstElement) //int *Cantidad_Nodos)
{
    productos *current = NULL;
    //int count
    int i;

     /*Seteo al puntero actual tal que apunta a la 1er estructura*/
    current =  *ptrFirstElement;

    /*Asignacion del numero de la cantidad de nodos de la variable "Cantidad_Nodos" hacia la variable "count" para uso de forma local y simplificada*/
   // count = *Cantidad_Nodos;

    for( i = 0; current != NULL; i++ )
    {
        printf("La estructura #%d contiene los datos:\n", i+1);
        printf("Nombre: %s\n", current->nombre);
        printf("Cant: %d\n", current->cant);
        printf("Codigo: %d\n", current->codigo);

        current = current->sig;
    }


    return;
}

void Mi_Funcion(productos **ptrFirstElement) //int *Cantidad_Nodos)
{
    productos *current = NULL;
    productos *aux = NULL;
    //int count;
    //int i;
    int count_aux = 0, j;
    productos *array[10];

    /*Seteo con NULL todos los elementos del array de punteros a estructuras "productos"*/
    memset(array, 0, sizeof(array));

     /*Seteo al puntero actual tal que apunta a la 1er estructura*/
    current =  *ptrFirstElement;
    aux = *ptrFirstElement;
    /*Asignacion del numero de la cantidad de nodos de la variable "Cantidad_Nodos" hacia la variable "count" para uso de forma local y simplificada*/
    //count = *Cantidad_Nodos;

    /*Busqueda de 1eras estructuras que contienen el codigo 1, 2, 3 etc hasta llegar a 10. Se almacenan los punteros a estas estructuras en un array de punteros a estructuras tipo productos*/
    for( j = 1; j <= 10; j++ )
    {
        //for( i = 0; i < count; i++ )
        for( ; current != NULL ; )
        {
            if( current->codigo == j && count_aux == 0 )
            {
                array[j-1] = current;
                count_aux++;
                break;
            }
            else
                current = current->sig;
        }
        count_aux = 0;
        current = *ptrFirstElement;
    }

    /*
    printf("El array de punteros a estructuras tipo productos quedo cargado con: \n");
    for( i = 0; i < 10; i++ )
        printf("%p\n", array[i]);
    */

    /*Incremento del numero de productos en el primer nodo de lista con un determinado codigo a partir de los codigos repetidos del mismo valor en los diferentes nodos. Borrado de la lista de todos los nodos que tienen un codigo repetido*/

    for( j = 1; j <= 10; j++ )
    {
        for( ; current != NULL;  )
        {
                //printf("El puntero aux vale %p\n", aux);
                //printf("El puntero current vale %p\n", current);
            if( current->codigo == j && count_aux == 0 && current != array[j-1])
            {
                array[j-1]->cant += current->cant;
                count_aux++;
                if( count_aux == 1 )
                {
                    //printf("El puntero aux vale %p\n", aux);
                    //printf("El puntero current vale %p\n", current);
                    aux->sig = current->sig;
                    current->sig = NULL;
                    //printf("EL puntero aux->sig vale %p\n", aux->sig);
                    //printf("El puntero current->sig vale %p\n", current->sig);
                    //printf("Se llego a la linea 237 y el puntero current vale %p\n", current);

                    //free(current);

                    //printf("Se llego a la linea 239\n");
                }

            }

            aux = current;
            current = current->sig;

        }
        count_aux = 0;
        current = *ptrFirstElement;
    }


    return;
}
