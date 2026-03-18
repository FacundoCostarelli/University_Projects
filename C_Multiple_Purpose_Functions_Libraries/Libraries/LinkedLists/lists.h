/**
 * ==========================================================================
 * lists.h — Linked List Data Structures & Function Declarations (Header)
 * ==========================================================================
 * [ESP] Definición de estructuras de datos y declaraciones de funciones
 *       para listas simplemente enlazadas. Incluye dos versiones:
 *       V1: Nodo con estructura de datos embebida (Producto_t)
 *       V2: Nodo genérico con puntero void* para datos de cualquier tipo
 *
 * [ENG] Data structure definitions and function declarations for
 *       singly linked lists. Includes two versions:
 *       V1: Node with embedded data structure (Producto_t)
 *       V2: Generic node with void* pointer for any data type
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

// [ESP] Estructura que representa un producto con código, proveedor y stock
// [ENG] Structure representing a product with code, supplier, and stock
typedef struct producto
{
    int codigo_Producto;
    char proveedor[20];
    int cantidad_stock;
}Producto_t;

// [ESP] Estructura V1: Nodo con dato embebido del tipo Producto_t
// [ENG] Structure V1: Node with embedded Producto_t data
typedef struct nodo
{
    Producto_t data;
    Nodo_t *sig;
}Nodo_t;

// [ESP] Estructura V2: Nodo genérico con puntero void* para cualquier tipo de dato
// [ENG] Structure V2: Generic node with void* pointer for any data type
typedef struct nodo
{
    void *data;
    Nodo_t *sig;
}Nodo_t;


// [ESP] Funciones para Lista Simplemente Enlazada V1 (dato embebido)
// [ENG] Functions for Singly Linked List V1 (embedded data)
void Lista_Simplemente_Enlazada_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data);
void Enlazar_Al_Final_Y_Cargar_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data,Nodo_t **Nuevo_Nodo);
void Enlazar_Al_Principio_Y_Cargar_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data,Nodo_t **Nuevo_Nodo);
void Enlazar_En_El_Medio_Y_Cargar_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data,Nodo_t **Nuevo_Nodo,int PosNodoIzq, int PosNodoDer);
void Imprimir_Campos_EstructuraInterna_NodoV1(Nodo_t **ptr1erElemento);
void BorrarNodo(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,//parametros de filtrado para borrar)

// [ESP] Funciones para Lista Simplemente Enlazada V2 (dato genérico con void*)
// [ENG] Functions for Singly Linked List V2 (generic data with void*)
void Crear_Cargar_Enlazar_Nodo_V2(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,void *nueva_data, size_t tam_data);
void Imprimir_Campos_EstructuraInterna_NodoV2(Nodo_t **ptr1erElemento);

// [ESP] Función compartida por V1 y V2: asigna memoria dinámica para un nuevo nodo
// [ENG] Shared function for V1 and V2: allocates dynamic memory for a new node
void Allocalizar_Nuevo_Nodo(Nodo_t **Nuevo_Nodo);
