/**
 * @file    Ej3.c
 * @brief   [ESP] Ejercicio 3 2do Parcial Nov 2022: Lista simplemente enlazada de productos.
 *          [ENG] Exercise 3 2nd Midterm Nov 2022: Singly linked list of products.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

#define CANTMAXCARACTERES 32

/**
 * @brief [ESP] Estructura que almacena datos de los productos.
 *        [ENG] Structure that stores products data.
 */
typedef struct nodo
{
    char nombre[CANTMAXCARACTERES];
    int cant;
    char codigo;
    struct nodo *sig;
} productos;

/**
 * @brief [ESP] Crea dinámicamente una lista vinculada sencilla de productos.
 *        [ENG] Dynamically creates a single linked list of products.
 */
void Creacion_ListaSimplementeEnlazada(productos **ptrFirstElement, int *Cantidad_Nodos);

/**
 * @brief [ESP] Carga los datos por teclado en cada nodo.
 *        [ENG] Loads keyboard data into each node.
 */
void CargaDeDatos_ListaSimplementeEnlazada( productos **ptrFirstElement, int *Cantidad_Nodos);

/**
 * @brief [ESP] Imprime la lista de productos por pantalla.
 *        [ENG] Prints the product list on screen.
 */
void Impresion_ListaSimplementeEnlazada(productos **ptrFirstElement);

/**
 * @brief [ESP] Agrupa nodos repetidos del mismo código y elimina repeticiones en la lista.
 *        [ENG] Groups repeated nodes of the same code and removes repetitions in list.
 */
void Mi_Funcion(productos **ptrFirstElement);


/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(void)
{
    productos *ptrFirstElement = NULL;
    int Cantidad_Nodos;
    
    printf("Bienvenido. Este programa le permite la creacion de una lista simplemente enlazada de estructuras...\n");

    /* [ESP] Creacion lista / [ENG] List creation */
    Creacion_ListaSimplementeEnlazada(&ptrFirstElement, &Cantidad_Nodos);

    /* [ESP] Carga de datos / [ENG] Data load */
    CargaDeDatos_ListaSimplementeEnlazada(&ptrFirstElement, &Cantidad_Nodos);

    printf("La lista queda creada y cargada de la siguiente manera: \n");
    Impresion_ListaSimplementeEnlazada(&ptrFirstElement);

    /* [ESP] Funcion reagrupamiento / [ENG] Regrouping function */
    Mi_Funcion(&ptrFirstElement);

    printf("La lista luego de realizar las operaciones pertinentes queda de la siguiente manera: \n");
    Impresion_ListaSimplementeEnlazada(&ptrFirstElement);

    /* [ESP] Liberación de memoria dinamica / [ENG] Free dynamic memory */
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
            printf("Desea crear otra estructura de datos? Presione: SI(S) o NO(N): ");
            scanf("%c", &decision);
            __fpurge(stdin);

            if( decision != 'S' && decision != 'N')
                printf("Caracter invalido. Ingrese el caracter solicitado de forma correcta\n");

        } while( decision != 'S' && decision != 'N');

        if( decision == 'S')
            count++;
        else
            *Cantidad_Nodos = count;

    } while( decision == 'S' );

    current =  *ptrFirstElement;

	for( i = 1; i < count; i++ )
	{
	    current->sig = ptr_aux+i;
	    current = current->sig;
	}

	current->sig = NULL;
    printf("Se ha creado correctamente una lista simplemente enlazada con una cantidad de nodos = %lu\n", count);
}

void  CargaDeDatos_ListaSimplementeEnlazada( productos **ptrFirstElement, int *Cantidad_Nodos)
{
    productos *current = NULL;
    int count, i;

    current =  *ptrFirstElement;
    count = *Cantidad_Nodos;
    
	for( i = 0; i < count; i++ )
	{
        printf("Usted va a cargar ahora la estructura de datos #%d\n", i+1);
        printf("Ingrese el nombre del producto (max %d caracteres): ", CANTMAXCARACTERES);
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

        } while((current->codigo) < 1 && (current->codigo) > 10);

	    current = current->sig;
	}
}

void Impresion_ListaSimplementeEnlazada(productos **ptrFirstElement)
{
    productos *current = NULL;
    int i;

    current =  *ptrFirstElement;

    for( i = 0; current != NULL; i++ )
    {
        printf("La estructura #%d contiene los datos:\n", i+1);
        printf("Nombre: %s\n", current->nombre);
        printf("Cant: %d\n", current->cant);
        printf("Codigo: %d\n", current->codigo);

        current = current->sig;
    }
}

void Mi_Funcion(productos **ptrFirstElement)
{
    productos *current = NULL;
    productos *aux = NULL;
    int count_aux = 0, j;
    productos *array[10];

    memset(array, 0, sizeof(array));

    current =  *ptrFirstElement;
    aux = *ptrFirstElement;

    for( j = 1; j <= 10; j++ )
    {
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

    for( j = 1; j <= 10; j++ )
    {
        for( ; current != NULL;  )
        {
            if( current->codigo == j && count_aux == 0 && current != array[j-1])
            {
                array[j-1]->cant += current->cant;
                count_aux++;
                if( count_aux == 1 )
                {
                    aux->sig = current->sig;
                    current->sig = NULL;
                }
            }
            aux = current;
            current = current->sig;
        }
        count_aux = 0;
        current = *ptrFirstElement;
    }
}
