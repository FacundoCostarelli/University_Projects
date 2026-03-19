/**
 * @file    lists.h
 * @brief   [ESP] Biblioteca de estructuras y funciones para listas enlazadas.
 *          [ENG] Linked list data structures and functions library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Define estructuras de datos para nodos y productos, y declara
 *       funciones para listas simplemente enlazadas en dos versiones:
 *       V1 (dato embebido Producto_t) y V2 (dato genérico con void*).
 *       Incluye operaciones de alocación, enlazamiento al principio,
 *       al final, en el medio, impresión y liberación de memoria.
 *
 * [ENG] Defines data structures for nodes and products, and declares
 *       functions for singly linked lists in two versions:
 *       V1 (embedded Producto_t data) and V2 (generic void* data).
 *       Includes allocation, front linking, back linking, middle
 *       insertion, printing, and memory deallocation operations.
 *
 * [ESP] NOTA: V1 y V2 usan el mismo nombre de tipo (Nodo_t). En un
 *       proyecto real, se usaría un solo enfoque. Aquí se presentan
 *       ambos como referencia didáctica.
 *
 * [ENG] NOTE: V1 and V2 use the same type name (Nodo_t). In a real
 *       project, only one approach would be used. Both are presented
 *       here as a teaching reference.
 */

#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief [ESP] Estructura de producto con código, proveedor y stock.
 *        [ENG] Product structure with code, supplier, and stock.
 *
 * @param codigo_Producto  [ESP] Código único del producto. / [ENG] Unique product code.
 * @param proveedor        [ESP] Nombre del proveedor.     / [ENG] Supplier name.
 * @param cantidad_stock   [ESP] Cantidad en stock.        / [ENG] Stock quantity.
 */
typedef struct producto
{
    int codigo_Producto;
    char proveedor[20];
    int cantidad_stock;
} Producto_t;

/* ===========================================================================
 * [ESP] VERSIÓN 1: NODO CON DATO EMBEBIDO (Producto_t)
 *       Cada nodo contiene directamente una copia de Producto_t.
 * [ENG] VERSION 1: NODE WITH EMBEDDED DATA (Producto_t)
 *       Each node directly contains a copy of Producto_t.
 * =========================================================================== */

/**
 * @brief [ESP] Nodo V1 — dato embebido de tipo Producto_t.
 *        [ENG] Node V1 — embedded Producto_t data.
 *
 * @param data  [ESP] Datos del producto almacenados en el nodo.
 *              [ENG] Product data stored in the node.
 * @param sig   [ESP] Puntero al siguiente nodo (NULL si es el último).
 *              [ENG] Pointer to the next node (NULL if last).
 */
typedef struct nodo_v1
{
    Producto_t data;
    struct nodo_v1 *sig;
} Nodo_t;

/* ===========================================================================
 * [ESP] VERSIÓN 2 (referencia): NODO GENÉRICO CON void*
 *       Permite almacenar cualquier tipo de dato (requiere malloc + memcpy).
 *       Descomentar para usar en lugar de V1.
 * [ENG] VERSION 2 (reference): GENERIC NODE WITH void*
 *       Allows storing any data type (requires malloc + memcpy).
 *       Uncomment to use instead of V1.
 * ===========================================================================
 *
 * typedef struct nodo_v2
 * {
 *     void *data;                // [ESP] Puntero genérico / [ENG] Generic pointer
 *     struct nodo_v2 *sig;       // [ESP] Siguiente nodo / [ENG] Next node
 * } Nodo_t;
 */

/**
 * @brief [ESP] Asigna memoria dinámica para un nuevo nodo.
 *        [ENG] Allocates dynamic memory for a new node.
 *
 * @param[out] Nuevo_Nodo  [ESP] Puntero doble que recibirá la dirección del nodo alocado.
 *                         [ENG] Double pointer that will receive the address of the allocated node.
 * @return void
 *
 * @example
 *   Nodo_t *nodo = NULL;
 *   Allocalizar_Nuevo_Nodo(&nodo);
 */
void Allocalizar_Nuevo_Nodo(Nodo_t **Nuevo_Nodo);

/**
 * @brief [ESP] Crea un nodo, enlaza al final (COLA/FIFO) y carga datos V1.
 *        [ENG] Creates a node, links at the end (Queue/FIFO) and loads V1 data.
 *
 * @param[in,out] ptr1erElemento  [ESP] Puntero doble al primer nodo de la lista.
 *                                [ENG] Double pointer to the first node of the list.
 * @param[in,out] Nodo_Actual     [ESP] Puntero doble al último nodo actual.
 *                                [ENG] Double pointer to the current last node.
 * @param[in]     data            [ESP] Datos del producto a cargar.
 *                                [ENG] Product data to load.
 * @param[out]    Nuevo_Nodo      [ESP] Puntero doble al nodo recién creado.
 *                                [ENG] Double pointer to the newly created node.
 * @return void
 *
 * @example
 *   Nodo_t *head = NULL, *current = NULL, *nuevo = NULL;
 *   Producto_t p = {1, "ProvA", 50};
 *   Enlazar_Al_Final_Y_Cargar_V1(&head, &current, p, &nuevo);
 */
void Enlazar_Al_Final_Y_Cargar_V1(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, Producto_t data, Nodo_t **Nuevo_Nodo);

/**
 * @brief [ESP] Crea un nodo, enlaza al principio (PILA/LIFO) y carga datos V1.
 *        [ENG] Creates a node, links at the beginning (Stack/LIFO) and loads V1 data.
 *
 * @param[in,out] ptr1erElemento  [ESP] Puntero doble al primer nodo.
 *                                [ENG] Double pointer to the first node.
 * @param[in,out] Nodo_Actual     [ESP] Puntero doble al nodo actual.
 *                                [ENG] Double pointer to the current node.
 * @param[in]     data            [ESP] Datos del producto a cargar.
 *                                [ENG] Product data to load.
 * @param[out]    Nuevo_Nodo      [ESP] Puntero doble al nodo recién creado.
 *                                [ENG] Double pointer to the newly created node.
 * @return void
 */
void Enlazar_Al_Principio_Y_Cargar_V1(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, Producto_t data, Nodo_t **Nuevo_Nodo);

/**
 * @brief [ESP] Imprime todos los campos internos de cada nodo (V1).
 *        [ENG] Prints all internal fields of each node (V1).
 *
 * @param[in] ptr1erElemento  [ESP] Puntero doble al primer nodo.
 *                            [ENG] Double pointer to the first node.
 * @return void
 */
void Imprimir_Campos_EstructuraInterna_NodoV1(Nodo_t **ptr1erElemento);

/**
 * @brief [ESP] Wrapper: crea, carga y enlaza un nodo V1 al final (COLA).
 *        [ENG] Wrapper: creates, loads and links a V1 node at the end (Queue).
 *
 * @param[in,out] ptr1erElemento  [ESP] Puntero doble al primer nodo.
 *                                [ENG] Double pointer to the first node.
 * @param[in,out] Nodo_Actual     [ESP] Puntero doble al nodo actual.
 *                                [ENG] Double pointer to the current node.
 * @param[in]     data            [ESP] Datos del producto.
 *                                [ENG] Product data.
 * @return void
 */
void Lista_Simplemente_Enlazada_V1(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, Producto_t data);

/**
 * @brief [ESP] Wrapper V2: crea, carga y enlaza un nodo genérico (void*).
 *        [ENG] Wrapper V2: creates, loads and links a generic node (void*).
 *
 * @param[in,out] ptr1erElemento  [ESP] Puntero doble al primer nodo.
 *                                [ENG] Double pointer to the first node.
 * @param[in,out] Nodo_Actual     [ESP] Puntero doble al nodo actual.
 *                                [ENG] Double pointer to the current node.
 * @param[in]     nueva_data      [ESP] Puntero void* a los datos a copiar.
 *                                [ENG] void* pointer to the data to copy.
 * @param[in]     tam_data        [ESP] Tamaño en bytes de los datos.
 *                                [ENG] Size in bytes of the data.
 * @return void
 */
void Crear_Cargar_Enlazar_Nodo_V2(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, void *nueva_data, size_t tam_data);

#endif /* LISTS_H */
