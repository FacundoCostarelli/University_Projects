/**
 * @file    Funciones.c
 * @brief   [ESP] Archivo fuente gestor listas simplemente enlazadas (SLL) y ruteadas. 3er Final 12/2022.
 *          [ENG] Routed Singly Linked List (SLL) logic handlers code. 3rd Final 12/2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Crea e inserta de forma genérica un nodo. Inicializa cabecera si estaba vacía.
 *        [ENG] Initiates and injects a list node. Handles empty header setup when invoked.
 *
 * @note  [ESP] Asume llamadas directas desde main() y data_t reservado fuera / [ENG] Assumes generic calls and detached data struct handling.
 * @param ptr1erElemento  [ESP] Puntero a la cabeza de bloque / [ENG] List header pointer
 * @param ptrAux          [ESP] Puntero iterador-referencia  / [ENG] Auxiliar loop/anchor block
 * @param pdat            [ESP] Célula de datos referencial / [ENG] Ptr to generic data block entity
 * @param dest            [ESP] Valor código de destino rut. / [ENG] Destination routing binding  
 */
int init(Nodo_t **ptr1erElemento, Nodo_t **ptrAux, const data_t *pdat, uint32_t dest)
{
    Nodo_t *Nuevo_Nodo = NULL;

    /* [ESP] Si lista vacía, creo el primero / [ENG] If list empty, setup header node */
    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");

        if ( Allocalizar_Nuevo_Nodo(&Nuevo_Nodo) == ERROR )
            return ERROR;

        Nuevo_Nodo->data = *pdat;
        Nuevo_Nodo->dest = dest;
        Nuevo_Nodo->sig = NULL;

        *ptr1erElemento = Nuevo_Nodo;
        *ptrAux = Nuevo_Nodo;
    }
    else
    {
        if ( pushMulti(ptr1erElemento, ptrAux, &Nuevo_Nodo, pdat, dest) == ERROR )
            return ERROR;
    }

    return EXITO;
}

/**
 * @brief [ESP] Wrapper de Malloc para reservar espacio tipo size de Nodo.
 *        [ENG] Custom Malloc wrapper assigning explicit Node boundaries directly resolving heap space.
 */
int Allocalizar_Nuevo_Nodo(Nodo_t **Nuevo_Nodo)
{
    *Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
    if(*Nuevo_Nodo == NULL)
    {
        printf("Hubo un error con la creacion y asignacion de memoria dinamica para un nuevo nodo\n");
        return ERROR;
    }
    else
    {
        printf("Se creo exitosamente y dinamicamente un nuevo nodo\n");
    }

    return EXITO;
}

/**
 * @brief [ESP] Inserta nodo al final de la cola (push FIFO type).
 *        [ENG] Appends a trailing node into the collection applying strict FIFO Queue behaviour.
 */
int pushMulti(Nodo_t **ptr1erElemento, Nodo_t **ptrAux, Nodo_t **Nuevo_Nodo, const data_t *pdat, uint32_t dest)
{
    printf("Se creara, cargara y agregara un nuevo nodo al final de la lista\n");

    if( Allocalizar_Nuevo_Nodo(Nuevo_Nodo) == ERROR )
        return ERROR;

    /* [ESP] El iterador mantiene traza del último / [ENG] Assumes ptrAux acts as a trailing trace tracking the ultimate node */
    if ( (*ptr1erElemento)->sig == NULL )
    {
        (*ptr1erElemento)->sig = *Nuevo_Nodo;
        *ptrAux = *Nuevo_Nodo;
        (*Nuevo_Nodo)->sig = NULL;
        (*Nuevo_Nodo)->data = *pdat;
        (*Nuevo_Nodo)->dest = dest;
    }
    else
    {
        (*ptrAux)->sig = *Nuevo_Nodo;
        *ptrAux = *Nuevo_Nodo;
        (*Nuevo_Nodo)->sig = NULL;
        (*Nuevo_Nodo)->data = *pdat;
        (*Nuevo_Nodo)->dest = dest;
    }
    return EXITO;
}

/**
 * @brief [ESP] Iterador que escanea máscara cruzada para "popear" paquetes afines al destino.
 *        [ENG] Scans the linked collection looking upon masked matches aiming to extract bounds based on dest param.
 *
 * @return int [ESP] EXITO si extrajo / [ENG] Code asserting proper execution hits 
 */
int popDest(Nodo_t **ptr1erElemento, Nodo_t **ptrAux, data_t *pdat , uint32_t dest)
{
    *ptrAux = *ptr1erElemento;
    uint32_t mask4 = 0x000F;
    uint32_t mask3 = 0x00F0;
    uint32_t mask2 = 0x0F00;
    uint32_t mask1 = 0xF000;
    uint32_t dest1, dest2, dest3, dest4;
    int count_mensajes = 0;

    while( *ptrAux != NULL )
    {
        dest1 = mask1 & (*ptrAux)->dest;
        dest2 = mask2 & (*ptrAux)->dest;
        dest3 = mask3 & (*ptrAux)->dest;
        dest4 = mask4 & (*ptrAux)->dest;

        if( dest1 == dest || dest2 == dest || dest3 == dest || dest4 == dest )
        {
            count_mensajes++;
            *pdat = (*ptrAux)->data;
        }
        *ptrAux = (*ptrAux)->sig;
    }

    if( count_mensajes != 0 )
        return EXITO;
    else
        return ERROR;
}

/**
 * @brief [ESP] Colector de basura nativo iterando el árbol y vaciando el stack.
 *        [ENG] Main GC loop iterating nodes freeing tree bindings entirely wiping heap allocations.
 */
void Liberar_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(Nodo_t **ptr1erElemento)
{
    Nodo_t *Nodo_Actual = *ptr1erElemento;

    while(*ptr1erElemento != NULL)
    {
        *ptr1erElemento = Nodo_Actual->sig;
        free(Nodo_Actual);
        Nodo_Actual = *ptr1erElemento;
    }

    printf("La Lista Simplemente Enlazada ha sido finalizada y liberada en sus recursos correctamente\n");
}
