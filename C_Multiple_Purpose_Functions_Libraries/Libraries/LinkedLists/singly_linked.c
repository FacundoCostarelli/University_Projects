/**
 * @file    singly_linked.c
 * @brief   [ESP] Implementación de operaciones para listas simplemente enlazadas.
 *          [ENG] Implementation of singly linked list operations.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Incluye dos versiones:
 *       V1: Nodo con estructura Producto_t embebida — enlazar al inicio,
 *           al final, en el medio, borrar nodo, e imprimir.
 *       V2: Nodo genérico con void* — crear, cargar, enlazar e imprimir
 *           con copia byte a byte para datos de cualquier tipo.
 *
 * [ENG] Includes two versions:
 *       V1: Node with embedded Producto_t struct — link at beginning,
 *           end, middle, delete node, and print.
 *       V2: Generic node with void* — create, load, link, and print
 *           with byte-by-byte copy for any data type.
 */

#include "lists.h"

/* ===========================================================================
 * [ESP] FUNCIONES COMPARTIDAS V1/V2
 * [ENG] SHARED FUNCTIONS V1/V2
 * =========================================================================== */

/**
 * @brief [ESP] Asigna memoria dinámica para un nuevo nodo.
 *        [ENG] Allocates dynamic memory for a new node.
 */
void Allocalizar_Nuevo_Nodo(Nodo_t **Nuevo_Nodo)
{
    /* [ESP] malloc crea un bloque de memoria del tamaño de un Nodo_t.
             Si falla (retorna NULL), terminamos el programa.
       [ENG] malloc creates a memory block of Nodo_t size.
             If it fails (returns NULL), we terminate the program. */
    *Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
    if (*Nuevo_Nodo == NULL)
    {
        printf("[ESP] Error en malloc para nuevo nodo.\n");
        printf("[ENG] malloc error for new node.\n");
        exit(-1);
    }

    return;
}

/* ===========================================================================
 * [ESP] VERSIÓN 1: NODO CON DATO EMBEBIDO (Producto_t)
 * [ENG] VERSION 1: NODE WITH EMBEDDED DATA (Producto_t)
 * =========================================================================== */

/**
 * @brief [ESP] Wrapper V1: crea, carga y enlaza un nodo con menú interactivo.
 *        [ENG] Wrapper V1: creates, loads, and links a node with interactive menu.
 */
void Lista_Simplemente_Enlazada_V1(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, Producto_t data)
{
    Nodo_t *Nuevo_Nodo = NULL;
    int PosNodoIzq;
    int PosNodoDer;
    int decision;

    /* [ESP] Si la lista está vacía, crear el primer nodo
       [ENG] If the list is empty, create the first node */
    if (*ptr1erElemento == NULL)
    {
        printf("[ESP] Lista vacia. Creando 1er nodo.\n");
        printf("[ENG] Empty list. Creating 1st node.\n");

        Allocalizar_Nuevo_Nodo(&Nuevo_Nodo);

        /* [ESP] Cargar datos y marcar como último nodo (sig = NULL)
           [ENG] Load data and mark as last node (sig = NULL) */
        Nuevo_Nodo->data = data;
        Nuevo_Nodo->sig = NULL;

        /* [ESP] Actualizar punteros: inicio de lista y nodo actual
           [ENG] Update pointers: list head and current node */
        *Nodo_Actual = Nuevo_Nodo;
        *ptr1erElemento = Nuevo_Nodo;
    }
    else
    {
        /* [ESP] Si la lista no está vacía, elegir método de enlazamiento
           [ENG] If the list is not empty, choose linking method */
        do
        {
            printf("[ESP] Opciones: 1)Final 2)Principio 3)Medio\n");
            printf("[ENG] Options: 1)End 2)Beginning 3)Middle\n");
            scanf("%d", &decision);
        } while (decision < 1 || decision > 3);

        switch (decision)
        {
        case 1:
            Enlazar_Al_Final_Y_Cargar_V1(ptr1erElemento, Nodo_Actual, data, &Nuevo_Nodo);
            break;
        case 2:
            Enlazar_Al_Principio_Y_Cargar_V1(ptr1erElemento, Nodo_Actual, data, &Nuevo_Nodo);
            break;
        case 3:
            printf("[ESP] Ingrese posición del nodo izquierdo (desde 0): ");
            printf("[ENG] Enter left node position (from 0): ");
            scanf("%d", &PosNodoIzq);
            PosNodoDer = PosNodoIzq + 1;
            Enlazar_En_El_Medio_Y_Cargar_V1(ptr1erElemento, Nodo_Actual, data, &Nuevo_Nodo, PosNodoIzq, PosNodoDer);
            break;
        default:
            break;
        }
    }

    return;
}

/**
 * @brief [ESP] Enlaza un nuevo nodo al final de la lista (COLA/FIFO).
 *        [ENG] Links a new node at the end of the list (Queue/FIFO).
 */
void Enlazar_Al_Final_Y_Cargar_V1(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, Producto_t data, Nodo_t **Nuevo_Nodo)
{
    /* [ESP] Iniciar desde el primer nodo
       [ENG] Start from the first node */
    *Nodo_Actual = *ptr1erElemento;

    Allocalizar_Nuevo_Nodo(Nuevo_Nodo);

    /* [ESP] Recorrer la lista hasta encontrar el último nodo (sig == NULL)
       [ENG] Traverse the list until the last node is found (sig == NULL) */
    while ((*Nodo_Actual)->sig != NULL)
        (*Nodo_Actual) = (*Nodo_Actual)->sig;

    /* [ESP] Enlazar el nuevo nodo al final
       [ENG] Link the new node at the end */
    (*Nodo_Actual)->sig = *Nuevo_Nodo;

    /* [ESP] Cargar datos en el nuevo nodo y marcar como último
       [ENG] Load data into the new node and mark as last */
    (*Nuevo_Nodo)->data = data;
    (*Nuevo_Nodo)->sig = NULL;

    /* [ESP] Actualizar nodo actual
       [ENG] Update current node */
    *Nodo_Actual = *Nuevo_Nodo;

    return;
}

/**
 * @brief [ESP] Enlaza un nuevo nodo al principio de la lista (PILA/LIFO).
 *        [ENG] Links a new node at the beginning of the list (Stack/LIFO).
 */
void Enlazar_Al_Principio_Y_Cargar_V1(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, Producto_t data, Nodo_t **Nuevo_Nodo)
{
    *Nodo_Actual = *ptr1erElemento;

    Allocalizar_Nuevo_Nodo(Nuevo_Nodo);

    /* [ESP] El nuevo nodo apunta al nodo que antes era el primero.
             No necesitamos recorrer la lista.
       [ENG] The new node points to what was previously the first node.
             No need to traverse the list. */
    (*Nuevo_Nodo)->sig = *Nodo_Actual;
    (*Nuevo_Nodo)->data = data;

    /* [ESP] Actualizar punteros
       [ENG] Update pointers */
    *Nodo_Actual = *Nuevo_Nodo;
    *ptr1erElemento = *Nuevo_Nodo;

    return;
}

/**
 * @brief [ESP] Enlaza un nuevo nodo en el medio de la lista.
 *        [ENG] Links a new node in the middle of the list.
 */
void Enlazar_En_El_Medio_Y_Cargar_V1(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, Producto_t data, Nodo_t **Nuevo_Nodo, int PosNodoIzq, int PosNodoDer)
{
    *Nodo_Actual = *ptr1erElemento;

    /* [ESP] Punteros auxiliares para ubicar los nodos laterales
       [ENG] Auxiliary pointers to locate the neighboring nodes */
    Nodo_t *Nodo_Aux1 = *ptr1erElemento;
    Nodo_t *Nodo_Aux2 = *ptr1erElemento;
    int i;

    Allocalizar_Nuevo_Nodo(Nuevo_Nodo);

    /* [ESP] Recorrer hasta la posición del nodo izquierdo
       [ENG] Traverse to the left node position */
    if (PosNodoIzq != 0)
    {
        for (i = 1; i < PosNodoIzq; i++)
            Nodo_Aux1 = Nodo_Aux1->sig;
    }

    /* [ESP] Recorrer hasta la posición del nodo derecho
       [ENG] Traverse to the right node position */
    for (i = 0; i < PosNodoDer; i++)
        Nodo_Aux2 = Nodo_Aux2->sig;

    /* [ESP] Insertar el nuevo nodo entre los nodos izquierdo y derecho:
             NodoIzq → NuevoNodo → NodoDer
       [ENG] Insert the new node between the left and right nodes:
             LeftNode → NewNode → RightNode */
    Nodo_Aux1->sig = *Nuevo_Nodo;
    (*Nuevo_Nodo)->sig = Nodo_Aux2;

    (*Nuevo_Nodo)->data = data;
    *Nodo_Actual = *Nuevo_Nodo;

    return;
}

/**
 * @brief [ESP] Imprime todos los campos de cada nodo (V1: dato embebido).
 *        [ENG] Prints all fields of each node (V1: embedded data).
 */
void Imprimir_Campos_EstructuraInterna_NodoV1(Nodo_t **ptr1erElemento)
{
    Nodo_t *Nodo_Actual = *ptr1erElemento;

    /* [ESP] Recorrer la lista e imprimir cada nodo
       [ENG] Traverse the list and print each node */
    while (Nodo_Actual != NULL)
    {
        printf("[ESP/ENG] Codigo/Code: %d | Proveedor/Supplier: %s | Stock: %d\n",
               Nodo_Actual->data.codigo_Producto,
               Nodo_Actual->data.proveedor,
               Nodo_Actual->data.cantidad_stock);
        Nodo_Actual = Nodo_Actual->sig;
    }

    return;
}

/* ===========================================================================
 * [ESP] VERSIÓN 2: NODO GENÉRICO CON void*
 * [ENG] VERSION 2: GENERIC NODE WITH void*
 *
 * [ESP] NOTA: Esta sección es código de referencia/plantilla.
 *       Requiere la definición V2 de Nodo_t (con void* data) para compilar.
 *       Ver lists.h para desactivar V1 y activar V2.
 *
 * [ENG] NOTE: This section is reference/template code.
 *       Requires the V2 definition of Nodo_t (with void* data) to compile.
 *       See lists.h to deactivate V1 and activate V2.
 * =========================================================================== */

/*
void Crear_Cargar_Enlazar_Nodo_V2(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, void *nueva_data, size_t tam_data)
{
    Nodo_t *Nuevo_Nodo = NULL;
    int i;

    if (*ptr1erElemento == NULL)
    {
        Allocalizar_Nuevo_Nodo(&Nuevo_Nodo);

        // [ESP] Alocar memoria para la estructura interna del nodo
        // [ENG] Allocate memory for the node's internal data structure
        Nuevo_Nodo->data = (void *)malloc(tam_data);
        if (Nuevo_Nodo->data == NULL)
        {
            printf("[ESP] Error en malloc para datos.\n");
            printf("[ENG] malloc error for data.\n");
            exit(-1);
        }

        // [ESP] Copia byte a byte: asumimos que char ocupa 1 byte.
        //       Copiamos tam_data bytes desde nueva_data hacia Nuevo_Nodo->data.
        // [ENG] Byte-by-byte copy: assume char is 1 byte.
        //       Copy tam_data bytes from nueva_data to Nuevo_Nodo->data.
        for (i = 0; i < (int)tam_data; i++)
            *((char *)(Nuevo_Nodo->data) + i) = *((char *)(nueva_data) + i);

        Nuevo_Nodo->sig = NULL;
        *Nodo_Actual = Nuevo_Nodo;
        *ptr1erElemento = Nuevo_Nodo;
        return;
    }

    // [ESP] Lista no vacía: crear nuevo nodo y enlazar al principio
    // [ENG] Non-empty list: create new node and link at the beginning
    Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
    if (Nuevo_Nodo == NULL)
    {
        printf("[ESP] Error en malloc.\n[ENG] malloc error.\n");
        exit(-1);
    }

    Nuevo_Nodo->data = (void *)malloc(tam_data);
    if (Nuevo_Nodo->data == NULL)
    {
        printf("[ESP] Error en malloc para datos.\n[ENG] malloc error for data.\n");
        exit(-1);
    }

    for (i = 0; i < (int)tam_data; i++)
        *((char *)(Nuevo_Nodo->data) + i) = *((char *)(nueva_data) + i);

    // [ESP] Enlazar al principio (LIFO/Stack)
    // [ENG] Link at the beginning (LIFO/Stack)
    Nuevo_Nodo->sig = *ptr1erElemento;
    *Nodo_Actual = Nuevo_Nodo;
    *ptr1erElemento = Nuevo_Nodo;

    return;
}
*/
