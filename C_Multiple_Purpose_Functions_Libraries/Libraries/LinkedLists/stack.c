/**
 * @file    stack.c
 * @brief   [ESP] Pila (LIFO/FILO) con lista simplemente enlazada.
 *          [ENG] Stack (LIFO/FILO) with singly linked list.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Implementa una Pila (LIFO: Last In, First Out) usando una lista
 *       simplemente enlazada. Los nodos se insertan (push) y se extraen
 *       (pop) desde el principio de la lista. Incluye funciones de push,
 *       pop, impresión y liberación de recursos.
 *
 * [ENG] Implements a Stack (LIFO: Last In, First Out) using a singly
 *       linked list. Nodes are pushed and popped from the beginning of
 *       the list. Includes push, pop, display, and resource freeing
 *       functions.
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
 * @brief [ESP] Nodo de lista simplemente enlazada para la pila.
 *        [ENG] Singly linked list node for the stack.
 */
struct nodo
{
    struct info *pdato; /* [ESP] Puntero a datos / [ENG] Pointer to data */
    struct nodo *psig;  /* [ESP] Siguiente nodo  / [ENG] Next node */
};

/* [ESP] Declaraciones / [ENG] Declarations */
void PushNodo(struct nodo **pinicial);
void PopNodo(struct nodo **pinicial);
void MostrarLista(struct nodo *pinicial);
void LiberarLista(struct nodo **pinicial);

int main(void)
{
    struct nodo *pINI = NULL;
    int i, CantNodos;

    printf("[ESP] Cantidad de nodos a crear: ");
    printf("[ENG] Number of nodes to create: ");
    scanf("%d", &CantNodos);

    /* [ESP] Push: crear nodos y apilarlos
       [ENG] Push: create nodes and stack them */
    for (i = 0; i < CantNodos; i++)
        PushNodo(&pINI);

    printf("\n[ESP] Pila con %d nodos:\n", CantNodos);
    printf("[ENG] Stack with %d nodes:\n", CantNodos);
    MostrarLista(pINI);

    /* [ESP] Pop: extraer un nodo (el último que entró)
       [ENG] Pop: extract a node (the last one pushed) */
    PopNodo(&pINI);
    printf("\n[ESP] Pila despues de 1 pop:\n");
    printf("[ENG] Stack after 1 pop:\n");
    MostrarLista(pINI);

    LiberarLista(&pINI);

    printf("[ESP] Programa finalizado. Recursos liberados.\n");
    printf("[ENG] Program finished. Resources freed.\n");
    return 0;
}

/**
 * @brief [ESP] Push: inserta un nuevo nodo al principio de la pila.
 *        [ENG] Push: inserts a new node at the top of the stack.
 *
 * [ESP] En una pila LIFO con lista simplemente enlazada:
 *       - Push (insertar) se hace al PRINCIPIO
 *       - Pop (extraer) se hace al PRINCIPIO
 * [ENG] In a LIFO stack with singly linked list:
 *       - Push (insert) is done at the BEGINNING
 *       - Pop (extract) is done at the BEGINNING
 */
void PushNodo(struct nodo **pinicial)
{
    struct nodo *paux = NULL;

    if ((*pinicial) == NULL)
    {
        /* [ESP] Pila vacía: crear primer nodo
           [ENG] Empty stack: create first node */
        *pinicial = (struct nodo *)malloc(sizeof(struct nodo));
        (*pinicial)->psig = NULL;
        (*pinicial)->pdato = (struct info *)malloc(sizeof(struct info));

        printf("[ESP] Nombre / [ENG] Name: ");
        scanf("%s", ((*pinicial)->pdato)->nombre);
        printf("[ESP] Edad / [ENG] Age: ");
        scanf("%d", &(((*pinicial)->pdato)->edad));
    }
    else
    {
        /* [ESP] Pila no vacía: crear nodo y enlazar al principio.
                 El nuevo nodo apunta al nodo que antes era el tope.
           [ENG] Non-empty stack: create node and link at the beginning.
                 The new node points to what was previously the top. */
        paux = (struct nodo *)malloc(sizeof(struct nodo));
        paux->psig = *pinicial;
        *pinicial = paux;

        (*pinicial)->pdato = (struct info *)malloc(sizeof(struct info));

        printf("[ESP] Nombre / [ENG] Name: ");
        scanf("%s", ((*pinicial)->pdato)->nombre);
        printf("[ESP] Edad / [ENG] Age: ");
        scanf("%d", &(((*pinicial)->pdato)->edad));
    }

    return;
}

/**
 * @brief [ESP] Pop: extrae el nodo del tope de la pila (LIFO).
 *        [ENG] Pop: extracts the node from the top of the stack (LIFO).
 */
void PopNodo(struct nodo **pinicial)
{
    struct nodo *paux = NULL;

    if ((*pinicial) == NULL)
    {
        printf("[ESP] Pila vacia. Nada que extraer.\n");
        printf("[ENG] Empty stack. Nothing to extract.\n");
    }
    else
    {
        /* [ESP] Guardar referencia al tope, avanzar pinicial, y liberar
           [ENG] Save reference to top, advance pinicial, and free */
        paux = *pinicial;
        printf("[ESP] Extraido: %s, %d\n",
               ((*pinicial)->pdato)->nombre, ((*pinicial)->pdato)->edad);
        printf("[ENG] Extracted: %s, %d\n",
               ((*pinicial)->pdato)->nombre, ((*pinicial)->pdato)->edad);

        *pinicial = (*pinicial)->psig;

        free(paux->pdato);
        free(paux);
    }

    return;
}

/**
 * @brief [ESP] Muestra todos los nodos de la pila (tope → base).
 *        [ENG] Displays all stack nodes (top → bottom).
 */
void MostrarLista(struct nodo *pinicial)
{
    struct nodo *paux = pinicial;

    if (pinicial == NULL)
    {
        printf("[ESP] Pila vacia.\n[ENG] Empty stack.\n");
    }
    else
    {
        while (paux != NULL)
        {
            printf("  [ESP/ENG] Nombre/Name: %s | Edad/Age: %d\n",
                   (paux->pdato)->nombre, (paux->pdato)->edad);
            paux = paux->psig;
        }
    }

    return;
}

/**
 * @brief [ESP] Libera toda la memoria dinámica de la pila.
 *        [ENG] Frees all dynamic memory from the stack.
 */
void LiberarLista(struct nodo **pinicial)
{
    struct nodo *pactual = *pinicial;
    struct nodo *psiguiente = NULL;

    /* [ESP] Recorrer liberando cada nodo y su estructura de datos
       [ENG] Traverse freeing each node and its data structure */
    while (pactual != NULL)
    {
        psiguiente = pactual->psig;
        free(pactual->pdato);
        free(pactual);
        pactual = psiguiente;
    }

    *pinicial = NULL;
    return;
}
