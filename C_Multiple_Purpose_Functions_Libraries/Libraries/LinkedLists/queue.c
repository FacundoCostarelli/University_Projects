/**
 * @file    queue.c
 * @brief   [ESP] Cola simple (FIFO) con lista doblemente enlazada.
 *          [ENG] Simple queue (FIFO) with doubly linked list.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Implementa una Cola Simple (FIFO: First In, First Out) usando una
 *       lista doblemente enlazada. Los nodos se insertan al principio y se
 *       extraen al final, respetando el orden secuencial. Incluye funciones
 *       de inserción, extracción, impresión y liberación de recursos.
 *
 * [ENG] Implements a Simple Queue (FIFO: First In, First Out) using a
 *       doubly linked list. Nodes are inserted at the beginning and
 *       extracted from the end, respecting sequential order. Includes
 *       insertion, extraction, display, and resource freeing functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief [ESP] Estructura de datos (nombre + edad).
 *        [ENG] Data structure (name + age).
 */
struct info
{
    char nombre[10]; /* [ESP] Nombre / [ENG] Name */
    int edad;        /* [ESP] Edad   / [ENG] Age  */
};

/**
 * @brief [ESP] Nodo de lista doblemente enlazada para la cola.
 *        [ENG] Doubly linked list node for the queue.
 */
struct nodo
{
    struct info *pdato; /* [ESP] Puntero a datos / [ENG] Pointer to data */
    struct nodo *psig;  /* [ESP] Siguiente nodo  / [ENG] Next node */
    struct nodo *pant;  /* [ESP] Nodo anterior   / [ENG] Previous node */
};

/* [ESP] Declaraciones / [ENG] Declarations */
void InsertarNodo_DL(struct nodo **pinicial, struct nodo **pfinal);
void MostrarLista_DL(struct nodo *pinicial);
void ExtraerNodo_DL(struct nodo **pinicial, struct nodo **pfinal);
void LiberarLista_DL(struct nodo **pinicial);

int main(void)
{
    struct nodo *pINI = NULL;
    struct nodo *pFIN = NULL;
    int i, CantNodos;

    printf("[ESP] Indique cuantos nodos crear: ");
    printf("[ENG] Enter how many nodes to create: ");
    scanf("%d", &CantNodos);

    /* [ESP] Crear y enlazar nodos
       [ENG] Create and link nodes */
    for (i = 0; i < CantNodos; i++)
        InsertarNodo_DL(&pINI, &pFIN);

    printf("\n[ESP] Cola creada con %d nodos.\n", CantNodos);
    printf("[ENG] Queue created with %d nodes.\n\n", CantNodos);

    MostrarLista_DL(pINI);

    /* [ESP] Extraer un nodo (FIFO: el primero que entró)
       [ENG] Extract a node (FIFO: the first one that entered) */
    ExtraerNodo_DL(&pINI, &pFIN);

    printf("\n[ESP] Cola despues de extraccion:\n");
    printf("[ENG] Queue after extraction:\n");
    MostrarLista_DL(pINI);

    LiberarLista_DL(&pINI);

    printf("[ESP] Programa finalizado.\n");
    printf("[ENG] Program finished.\n");
    return 0;
}

/**
 * @brief [ESP] Inserta un nuevo nodo al principio de la cola (FIFO).
 *        [ENG] Inserts a new node at the beginning of the queue (FIFO).
 *
 * [ESP] En una cola FIFO con lista doblemente enlazada:
 *       - Se inserta al PRINCIPIO (pINI)
 *       - Se extrae al FINAL (pFIN)
 * [ENG] In a FIFO queue with doubly linked list:
 *       - Insert at the BEGINNING (pINI)
 *       - Extract from the END (pFIN)
 */
void InsertarNodo_DL(struct nodo **pinicial, struct nodo **pfinal)
{
    struct nodo *paux = NULL;

    if ((*pinicial) == NULL)
    {
        /* [ESP] Lista vacía: crear primer nodo
           [ENG] Empty list: create first node */
        *pinicial = (struct nodo *)malloc(sizeof(struct nodo));
        *pfinal = *pinicial;

        (*pinicial)->psig = NULL;
        (*pinicial)->pant = NULL;

        /* [ESP] Alocar estructura de datos interna
           [ENG] Allocate internal data structure */
        (*pinicial)->pdato = (struct info *)malloc(sizeof(struct info));

        printf("[ESP] Nombre / [ENG] Name: ");
        scanf("%s", ((*pinicial)->pdato)->nombre);
        printf("[ESP] Edad / [ENG] Age: ");
        scanf("%d", &(((*pinicial)->pdato)->edad));
    }
    else
    {
        /* [ESP] Lista no vacía: crear nodo y enlazar al principio.
                 El nuevo nodo apunta al nodo que antes era el inicial.
           [ENG] Non-empty list: create node and link at the beginning.
                 The new node points to what was previously the initial node. */
        paux = (struct nodo *)malloc(sizeof(struct nodo));

        paux->psig = *pinicial;
        paux->pant = NULL;
        (*pinicial)->pant = paux;
        *pinicial = paux;

        /* [ESP] pFIN sigue apuntando al último nodo de la cola
           [ENG] pFIN keeps pointing to the last node of the queue */

        (*pinicial)->pdato = (struct info *)malloc(sizeof(struct info));

        printf("[ESP] Nombre / [ENG] Name: ");
        scanf("%s", ((*pinicial)->pdato)->nombre);
        printf("[ESP] Edad / [ENG] Age: ");
        scanf("%d", &(((*pinicial)->pdato)->edad));
    }

    return;
}

/**
 * @brief [ESP] Extrae el nodo del final de la cola (FIFO: el primero que entró).
 *        [ENG] Extracts the node from the end of the queue (FIFO: first one in).
 */
void ExtraerNodo_DL(struct nodo **pinicial, struct nodo **pfinal)
{
    struct nodo *paux = NULL;

    if (*pinicial != NULL)
    {
        /* [ESP] Guardar referencia al último nodo para poder liberarlo
           [ENG] Save reference to the last node to be able to free it */
        paux = *pfinal;
        *pfinal = (*pfinal)->pant;
        (*pfinal)->psig = NULL;

        printf("[ESP] Nodo extraido: %s, %d\n",
               paux->pdato->nombre, paux->pdato->edad);
        printf("[ENG] Extracted node: %s, %d\n",
               paux->pdato->nombre, paux->pdato->edad);

        free(paux->pdato);
        free(paux);
    }

    return;
}

/**
 * @brief [ESP] Muestra todos los nodos de la cola.
 *        [ENG] Displays all nodes in the queue.
 */
void MostrarLista_DL(struct nodo *pinicial)
{
    struct nodo *paux = pinicial;

    while (paux != NULL)
    {
        printf("  [ESP/ENG] Nombre/Name: %s | Edad/Age: %d\n",
               paux->pdato->nombre, paux->pdato->edad);
        paux = paux->psig;
    }

    return;
}

/**
 * @brief [ESP] Libera toda la memoria dinámica de la cola.
 *        [ENG] Frees all dynamic memory from the queue.
 */
void LiberarLista_DL(struct nodo **pinicial)
{
    struct nodo *paux1 = *pinicial;
    struct nodo *paux2 = NULL;

    if (*pinicial == NULL)
    {
        printf("[ESP] Cola vacia.\n[ENG] Empty queue.\n");
        return;
    }

    /* [ESP] Recorrer liberando cada nodo y su estructura de datos
       [ENG] Traverse freeing each node and its data structure */
    while (paux1 != NULL)
    {
        paux2 = paux1;
        paux1 = paux1->psig;
        free(paux2->pdato);
        free(paux2);
    }

    *pinicial = NULL;
    return;
}
