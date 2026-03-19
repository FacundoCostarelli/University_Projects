/**
 * @file    doubly_linked.c
 * @brief   [ESP] Lista doblemente enlazada con inserción ordenada por DNI.
 *          [ENG] Doubly linked list with sorted insertion by DNI.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Programa standalone que implementa una lista doblemente enlazada
 *       donde los nodos se insertan manteniendo un orden descendente por DNI.
 *       Incluye: inserción ordenada, recorrido directo e inverso, y
 *       liberación de recursos.
 *
 * [ENG] Standalone program implementing a doubly linked list where nodes
 *       are inserted maintaining descending order by DNI.
 *       Includes: sorted insertion, forward and reverse traversal, and
 *       resource deallocation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief [ESP] Estructura de datos interna del nodo (persona).
 *        [ENG] Internal data structure of the node (person).
 */
struct info
{
    int dni;        /* [ESP] Documento de identidad / [ENG] ID number */
    char sexo;      /* [ESP] Sexo ('M' o 'F')      / [ENG] Gender ('M' or 'F') */
    char *nombre;   /* [ESP] Nombre (string)        / [ENG] Name (string) */
};

/**
 * @brief [ESP] Nodo de lista doblemente enlazada.
 *        [ENG] Doubly linked list node.
 */
struct nodo
{
    struct nodo *psig;  /* [ESP] Puntero al siguiente nodo / [ENG] Pointer to next node */
    struct nodo *pant;  /* [ESP] Puntero al nodo anterior  / [ENG] Pointer to previous node */
    struct info *Info;  /* [ESP] Puntero a datos internos  / [ENG] Pointer to internal data */
};

/* [ESP] Declaraciones de funciones / [ENG] Function declarations */
void InsertarNodo(struct nodo **Pini, struct info *dato);
void MostrarLista(struct nodo *ini);
struct info *GenerarNodo(int gdni, char gsexo, char *gnombre);
void LiberarRecursos(struct nodo *ini);

int main(void)
{
    srandom(time(NULL));
    struct nodo *pinicio = NULL;
    struct info *aux = NULL;
    struct nodo *pfree = NULL;
    int i;

    /* [ESP] Crear 5 nodos con DNI aleatorio y nombre por defecto
       [ENG] Create 5 nodes with random DNI and default name */
    for (i = 0; i < 5; i++)
    {
        aux = GenerarNodo(random() % 100, 'M', NULL);
        InsertarNodo(&pinicio, aux);
    }

    printf("[ESP] Lista doblemente enlazada creada.\n");
    printf("[ENG] Doubly linked list created.\n");

    pfree = pinicio;
    MostrarLista(pinicio);
    LiberarRecursos(pfree);

    return 0;
}

/**
 * @brief [ESP] Inserta un nodo en la lista manteniendo orden descendente por DNI.
 *        [ENG] Inserts a node maintaining descending order by DNI.
 *
 * [ESP] Tres casos posibles:
 *       1. Lista vacía → crear primer nodo
 *       2. DNI mayor que todos → insertar al principio
 *       3. Otro → insertar en el medio o al final
 *
 * [ENG] Three possible cases:
 *       1. Empty list → create first node
 *       2. DNI greater than all → insert at beginning
 *       3. Other → insert in the middle or at the end
 */
void InsertarNodo(struct nodo **Pini, struct info *dato)
{
    struct nodo *aux = *Pini;
    struct nodo *aux2 = *Pini;

    /* [ESP] Caso 1: Lista vacía — crear primer nodo
       [ENG] Case 1: Empty list — create first node */
    if (*Pini == NULL)
    {
        (*Pini) = (struct nodo *)malloc(sizeof(struct nodo));
        (*Pini)->psig = NULL;
        (*Pini)->pant = NULL;
        (*Pini)->Info = dato;
    }
    else
    {
        /* [ESP] Recorrer la lista buscando la posición correcta.
                 Avanzamos mientras aux no sea NULL y el DNI del nodo actual
                 sea mayor que el DNI del dato a insertar.
           [ENG] Traverse the list looking for the correct position.
                 Advance while aux is not NULL and the current node's DNI
                 is greater than the DNI of the data to insert. */
        while ((aux != NULL) && (aux->Info->dni > dato->dni))
        {
            aux2 = aux;     /* [ESP] aux2 queda un paso atrás / [ENG] aux2 stays one step behind */
            aux = aux->psig; /* [ESP] aux avanza / [ENG] aux advances */
        }

        /* [ESP] Caso 2: Insertar al principio (el nuevo DNI es el mayor)
           [ENG] Case 2: Insert at beginning (new DNI is the largest) */
        if (aux == *Pini)
        {
            (*Pini)->pant = (struct nodo *)malloc(sizeof(struct nodo));
            ((*Pini)->pant)->psig = (*Pini);
            ((*Pini)->pant)->pant = NULL;
            (*Pini) = (*Pini)->pant;
            (*Pini)->Info = dato;
        }
        else
        {
            /* [ESP] Caso 3a: Insertar al final (aux == NULL)
               [ENG] Case 3a: Insert at end (aux == NULL) */
            if (aux == NULL)
            {
                aux2->psig = (struct nodo *)malloc(sizeof(struct nodo));
                (aux2->psig)->psig = NULL;
                (aux2->psig)->pant = aux2;
                (aux2->psig)->Info = dato;
                aux2 = aux2->psig;
            }
            /* [ESP] Caso 3b: Insertar en el medio (entre aux2 y aux)
               [ENG] Case 3b: Insert in the middle (between aux2 and aux) */
            else
            {
                aux2->psig = (struct nodo *)malloc(sizeof(struct nodo));
                aux->pant = aux2->psig;
                (aux2->psig)->psig = aux;
                (aux2->psig)->pant = aux2;
                (aux2->psig)->Info = dato;
            }
        }
    }

    return;
}

/**
 * @brief [ESP] Muestra la lista en sentido directo e inverso.
 *        [ENG] Displays the list in forward and reverse order.
 */
void MostrarLista(struct nodo *ini)
{
    struct nodo *aux;

    /* [ESP] Recorrido directo (inicio → final)
       [ENG] Forward traversal (beginning → end) */
    printf("\n[ESP] Recorrido directo / [ENG] Forward traversal:\n");
    while (ini != NULL)
    {
        printf("  DNI: %d | Sexo/Gender: %c | Nombre/Name: %s\n",
               ini->Info->dni, ini->Info->sexo, ini->Info->nombre);
        aux = ini;
        ini = ini->psig;
    }

    /* [ESP] Recorrido inverso (final → inicio), partiendo desde 'aux'
             que quedó apuntando al último nodo válido.
       [ENG] Reverse traversal (end → beginning), starting from 'aux'
             which is pointing to the last valid node. */
    printf("\n[ESP] Recorrido inverso / [ENG] Reverse traversal:\n");
    while (aux != NULL)
    {
        printf("  DNI: %d | Sexo/Gender: %c | Nombre/Name: %s\n",
               aux->Info->dni, aux->Info->sexo, aux->Info->nombre);
        aux = aux->pant;
    }

    return;
}

/**
 * @brief [ESP] Genera una estructura info con datos de prueba.
 *        [ENG] Generates an info struct with test data.
 */
struct info *GenerarNodo(int gdni, char gsexo, char *gnombre)
{
    struct info *datoaux = (struct info *)malloc(sizeof(struct info));
    datoaux->dni = gdni;
    datoaux->sexo = gsexo;
    datoaux->nombre = "No definido";
    return datoaux;
}

/**
 * @brief [ESP] Libera toda la memoria dinámica de la lista.
 *        [ENG] Frees all dynamic memory from the list.
 */
void LiberarRecursos(struct nodo *ini)
{
    struct nodo *aux;

    /* [ESP] Recorremos nodo por nodo, liberando primero los datos y luego el nodo
       [ENG] Traverse node by node, freeing data first, then the node */
    while (ini != NULL)
    {
        aux = ini;
        ini = ini->psig;
        free(aux->Info);
        free(aux);
    }

    printf("[ESP] Recursos liberados.\n");
    printf("[ENG] Resources freed.\n");
    return;
}
