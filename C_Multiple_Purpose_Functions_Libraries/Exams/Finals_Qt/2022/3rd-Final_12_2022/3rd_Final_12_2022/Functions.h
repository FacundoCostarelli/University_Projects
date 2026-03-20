/**
 * @file    Funciones.h
 * @brief   [ESP] Cabecera para gestor de listas enlazadas enrutadas. 3er Final 12/2022.
 *          [ENG] Main header for linked-list data router management. 3rd Final 12/2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

/**
 * @brief [ESP] Constantes de error, éxito y máscaras de destino.
 *        [ENG] Error, success and destination masking constants.
 */
#define ERROR 0
#define EXITO 1

#define DEST_01 0x0001
#define DEST_02 0x0002
#define DEST_03 0x0003
#define DEST_04 0x0004
#define DEST_05 0x0005
#define DEST_06 0x0006
#define DEST_07 0x0007

typedef unsigned int uint32_t;

/**
 * @brief [ESP] Estructura genérica contenedora de capas de información (Data node).
 *        [ENG] Inner node generic structure defining generic data scopes.
 */
typedef struct dato
{
    uint32_t informacion1;
    uint32_t informacion2;
    uint32_t masinformacion;
} data_t;

/**
 * @brief [ESP] Elemento de lista enlazada (Singly linked list node) agregando sub-dato y destino.
 *        [ENG] Singly linked list element aggregating the sub-data field alongside routing dest bounds.
 */
typedef struct nodo
{
    data_t data;
    uint32_t dest;
    struct nodo *sig;
} Nodo_t;

/* [ESP] Prototipos de funciones / [ENG] Function prototypes */
int init(Nodo_t **ptr1erElemento, Nodo_t **ptrAux, const data_t *pdat, uint32_t dest);
int Allocalizar_Nuevo_Nodo(Nodo_t **Nuevo_Nodo);
int pushMulti(Nodo_t **ptr1erElemento, Nodo_t **ptrAux, Nodo_t **Nuevo_Nodo, const data_t *pdat, uint32_t dest);
int popDest(Nodo_t **ptr1erElemento, Nodo_t **ptrAux, data_t *pdat, uint32_t dest);
void Liberar_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(Nodo_t **ptr1erElemento);

#endif /* FUNCIONES_H */
