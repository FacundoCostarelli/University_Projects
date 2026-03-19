/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para lista simplemente enlazada (V1).
 *          [ENG] Usage example program for singly linked list (V1).
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Demuestra la creación, enlazamiento al final (COLA/FIFO),
 *       enlazamiento al inicio (PILA/LIFO), impresión y liberación
 *       de una lista simplemente enlazada con datos Producto_t.
 *
 * [ENG] Demonstrates creation, back linking (Queue/FIFO),
 *       front linking (Stack/LIFO), printing, and freeing
 *       of a singly linked list with Producto_t data.
 */

#include "lists.h"

int main(void)
{
    Nodo_t *head = NULL;
    Nodo_t *current = NULL;
    Nodo_t *nuevo = NULL;

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 1: Crear el primer nodo
     * [ENG] Example 1: Create the first node
     * --------------------------------------------------------------- */
    printf("=== [ESP] Creando primer nodo ===\n");
    printf("=== [ENG] Creating first node ===\n\n");

    Producto_t p1 = {101, "ProveedorA", 50};
    Allocalizar_Nuevo_Nodo(&nuevo);
    nuevo->data = p1;
    nuevo->sig = NULL;
    head = nuevo;
    current = nuevo;

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 2: Enlazar al final (COLA/FIFO)
     * [ENG] Example 2: Link at end (Queue/FIFO)
     * --------------------------------------------------------------- */
    printf("=== [ESP] Enlazando al final ===\n");
    printf("=== [ENG] Linking at end ===\n\n");

    Producto_t p2 = {202, "ProveedorB", 30};
    Enlazar_Al_Final_Y_Cargar_V1(&head, &current, p2, &nuevo);

    Producto_t p3 = {303, "ProveedorC", 75};
    Enlazar_Al_Final_Y_Cargar_V1(&head, &current, p3, &nuevo);

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 3: Enlazar al principio (PILA/LIFO)
     * [ENG] Example 3: Link at beginning (Stack/LIFO)
     * --------------------------------------------------------------- */
    printf("\n=== [ESP] Enlazando al principio ===\n");
    printf("=== [ENG] Linking at beginning ===\n\n");

    Producto_t p0 = {999, "ProveedorZ", 100};
    Enlazar_Al_Principio_Y_Cargar_V1(&head, &current, p0, &nuevo);

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 4: Imprimir todos los nodos
     * [ENG] Example 4: Print all nodes
     * --------------------------------------------------------------- */
    printf("\n=== [ESP] Lista completa ===\n");
    printf("=== [ENG] Full list ===\n\n");
    Imprimir_Campos_EstructuraInterna_NodoV1(&head);

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 5: Liberar memoria de toda la lista
     * [ENG] Example 5: Free memory of entire list
     * --------------------------------------------------------------- */
    printf("\n=== [ESP] Liberando memoria ===\n");
    printf("=== [ENG] Freeing memory ===\n\n");

    Nodo_t *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->sig;
        free(temp);
    }

    printf("[ESP] Lista liberada. %d nodos procesados.\n", 4);
    printf("[ENG] List freed. %d nodes processed.\n", 4);

    return 0;
}
