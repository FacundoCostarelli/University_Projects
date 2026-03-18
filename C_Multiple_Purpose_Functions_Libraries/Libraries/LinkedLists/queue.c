/**
 * ==========================================================================
 * queue.c — Simple Queue (FIFO) Implementation
 * ==========================================================================
 * [ESP] Implementación de una Cola Simple (FIFO: First In, First Out)
 *       usando una lista doblemente enlazada. Los nodos se insertan al
 *       principio y se extraen al final, respetando el orden secuencial.
 *       Incluye funciones de inserción, extracción, impresión y liberación.
 *
 * [ENG] Implementation of a Simple Queue (FIFO: First In, First Out)
 *       using a doubly linked list. Nodes are inserted at the beginning
 *       and extracted from the end, respecting sequential order.
 *       Includes insertion, extraction, display, and resource freeing functions.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

struct info
{
    char nombre[10];
    int edad;
};

struct nodo
{
    struct info *pdato;
    struct nodo *psig;
    struct nodo *pant;
};

void InsertarNodo_DL(struct nodo **pinicial, struct nodo **pfinal);
void MostrarLista_DL(struct nodo *pinicial);
void ExtraerNodo_DL(struct nodo **pinicial, struct nodo **pfinal);
void LiberarLista_DL(struct nodo **pinicial);

//DL = DoblementeEnlazada
//SL = SimplementeEnlazada
//Una cola es un agrupamiento de datos tal que el primero en entrar es el primero en salir, es decir, es del tipo FIFO(First In First Out). Los datos ingresan por el comienzo de la COLA y salen por el final de la misma respetando un orden secuencial. Se suele utilizar una Lista Doblemente Enlazada ya que se posee un puntero tanto al comienzo de la COLA como al final de la misma. Aunque se puede utilizar Lista Simplente Enlazada y arrays.
//Este codigo trabaja como una COLA SIMPLE, y en esta ocasion sucedera que:
//El enlazamiento de todos los nodos es AL PRINCIPIO
//La extraccion de datos se hace desde el FINAL.
//La lista utilizada sera una doblemente enlazada, pero debido a lo mencionado, sera entonces en realidad, una COLA SIMPLE
//ES IMPORTANTE DESTACAR que en caso de querer utilizar una Lista Simplemente Enlazada, habra que realizar el enlazamiento AL FINAL y la extraccion de datos AL PRINCIPIO. Aca tambien habran 2 punteros. Uno que apunte al comienzo de la cola y otro al princpio
int main()
{
    struct nodo *pINI = NULL;//La cola esta vacia
    struct nodo *pFIN = NULL;//La cola esta vacia
    int i, CantNodos;

    printf("Indique cuantos nodos desea crear: ");querer utilizar
    scanf("%d", &CantNodos);
    __fpurge(stdin);

    for( i = 0; i < CantNodos; i++ )
        InsertarNodo_DL(&pINI, &pFIN);

    printf("Se crearon y enlazaron correctamente %d nodos\nLa lista DOBLEMENTE ENLAZADA fue creada correctamente\n", CantNodos);
    //Muestro la lista creada y cargada
    MostrarLista_DL(pINI);
    //Extraigo algun nodo
    ExtraerNodo_DL(&pINI, &pFIN);

    printf("\n\nLa COLA SIMPLE queda como: \n");
    //Muestro la lista pero sin el nodo extraido
    MostrarLista_DL(pINI);
    //Libero los recursos
    LiberarLista_DL(&pINI);

    printf("El programa ha finalizado correctamente\n");
    return 0;
}


void InsertarNodo_DL(struct nodo **pinicial, struct nodo **pfinal)
{
    struct nodo *paux = NULL;

    //Pregunto si la lista esta vacia. En caso de estarlo creo el 1er nodo y lo inserto
    if((*pinicial) == NULL)
    {
        printf("La lista esta vacia. Se creara e insertara el 1er nodo de la COLA SIMPLE\n");
        *pinicial = (struct nodo *)malloc(sizeof(struct nodo));//Creo dinamicamente el 1er nodo de la COLA SIMPLE
        //Aca iria proteccion contra NULL de malloc
        *pfinal = *pinicial;//Como hay un 1er y unico nodo, entonces el puntero inicial y el puntero final de la lista apuntan al mismo nodo

        (*pinicial)->psig = NULL;//El puntero psig lo apunto a NULL
        (*pinicial)->pant = NULL;//El puntero pant lo apunto a NULL
        (*pinicial)->pdato = (struct info *)malloc(sizeof(struct info));//Creo la estructura dato de forma dinamica. Este dato estara ubicado dentro del nodo
        //Aca iria proteccion contra NULL de malloc

        //Cargo con informacion, proveniente del teclado, la estructura dato creada dinamicamente
        printf("Ingrese un nombre\n");
        scanf("%s",( (*pinicial)->pdato )->nombre);
        __fpurge(stdin);

        printf("Ingrese la edad\n");
        scanf("%d", &( ( (*pinicial)->pdato )->edad ) );
        __fpurge(stdin);

    }
    //Si la lista no esta vacia. Entonces creo el nuevo nodo y lo enlazo AL PRINCIPIO ya que en una COLA SIMPLE con una lista doblemente enlazada, simepre se hace de esta forma
    else
    {
        printf("La lista NO esta vacia. Se creara e insertara un nuevo nodo AL PRINCIPIO de la COLA SIMPLE\n");
        paux = (struct nodo *)malloc(sizeof(struct nodo));//Creo dinamicamente un nuevo nodo de la COLA SIMPLE
        //Aca iria proteccion contra NULL de malloc

        paux->psig = *pinicial;//Accedo al psig del nuevo nodo y hago que apunte al nodo inicial viejo de la lista
        paux->pant = NULL;//Accedo al pant del nuevo nodo y hago que apunte a NULL

        (*pinicial)->pant = paux;//Accedo al pant del nodo inicial viejo de la lista y hago que apunte al nuevo nodo

        *pinicial = paux;//El puntero al nodo inicial viejo de la lista apunta ahora al nuevo nodo de la lista el cual sera a su vez el inicial de la lista

        //El pfinal queda apuntando al nodo final de la lista hasta que dicho nodo se le extraiga informacion. Esta instruccion esta dada en el bloque if de mas arriba

        (*pinicial)->pdato = (struct info *)malloc(sizeof(struct info));//Creo dinamicamente la estructura dato. Esta se encuentra en el interior del nuevo nodo
        //Aca iria proteccion contra NULL de malloc
        //Cargo con informacion proveniente del teclado, la estructura dato creada dinamicamente
        printf("Ingrese un nombre\n");
        scanf("%s",( (*pinicial)->pdato )->nombre);
        __fpurge(stdin);

        printf("Ingrese la edad\n");
        scanf("%d", &( ( (*pinicial)->pdato )->edad ) );
        __fpurge(stdin);

    }

    return;
}



void ExtraerNodo_DL(struct nodo **pinicial, struct nodo **pfinal)
{
    struct nodo *paux = NULL;
    //Pregunto si la cola no esta vacia. De NO estar vacia, significa que hay un puntero inicial apuntando a un nodo inicial de la lista y ademas hay un  puntero final apuntando al ultimo nodo de la lista y dicho ultimo nodo NO es NULL
    if(*pinicial != NULL)
    {
        paux = *pfinal;//Guardo el puntero final al ultimo nodo, en otro puntero auxiliar
        *pfinal = (*pfinal)->pant;//Accedo al pant del ultimo nodo de la lista y hago que pfinal apunte a donde apunta pant. Es decir, pfinal apunta ahora al anteultimo nodo de la lista.
        (*pfinal)->psig = NULL;//Accedo al psig del anteultimo nodo apuntado por pfinal y hago que psig apunte a NULL

        printf("El nodo a extraer posee la siguiente informacion\n");
        printf("Nombre: %s\nEdad: %d\n", paux->pdato->nombre, paux->pdato->edad);

        //Libero los recursos del nodo extraido
        free(paux->pdato);
        free(paux);

        //Luego de hacer esto entonces pfinal apunta a un nodo que se convierte ahora en el ultimo nodo de la lista y no es mas el anteultimo

    }

    return;
}


void MostrarLista_DL(struct nodo *pinicial)
{
    struct nodo *paux = pinicial;

    //Se muestra la lista de forma directa
    while(paux != NULL)
    {
        printf("Nombre: %s\nEdad: %d\n", paux->pdato->nombre, paux->pdato->edad);
        paux = paux->psig;
    }


    return;
}

void LiberarLista_DL(struct nodo **pinicial)
{
    struct nodo *paux1 = *pinicial;
    struct nodo *paux2 = NULL;

    if(*pinicial == NULL)
    {
        printf("La lista esta vacia. No hay nada que liberar\n");
        exit(-1);
    }

    while(paux1 != NULL)
    {
        paux2 = paux1;
        paux1 = paux1->psig;
        free(paux2->pdato);
        free(paux2);
    }

    *pinicial = NULL;//Asigno NULL al puntero inicial de la lista para indicar que la lista ya esta vacia

    return;
}
