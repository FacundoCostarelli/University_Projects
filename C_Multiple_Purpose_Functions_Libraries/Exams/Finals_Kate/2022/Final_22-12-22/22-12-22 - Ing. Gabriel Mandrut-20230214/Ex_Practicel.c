/**
 * @file    Ej-Practico.c
 * @brief   [ESP] Ejercicio Práctico incompleto - Final 22-12-2022. Lista Enlazada Simple con Bitwise.
 *          [ENG] Incomplete Practical Exercise - Final 22-12-2022. Singly Linked List with Bitwise.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include<errno.h>

#define DEST_01		0x0001
#define DEST_02		0x0002
#define DEST_03		0x0004
#define DEST_04		0x0008
#define DEST_05		0x0010
#define DEST_06		0x0020

/**
 * @brief [ESP] Estructura de datos almacenada.
 *        [ENG] Stored data structure.
 */
typedef struct{
    int code, cant;
    char desc[30];
} st_data;

typedef unsigned int uint32_t;

/**
 * @brief [ESP] Nodo de la lista.
 *        [ENG] List node.
 */
typedef struct lista
{
	st_data st;
	uint32_t  dest;
	struct lista *sig;
} st_list;

/**
 * @brief [ESP] Crea y carga un nuevo nodo de la cola.
 *        [ENG] Creates and loads new queue node.
 */
st_list *Crear_Y_Cargar_Nodo( st_data data, uint32_t dest)
{
    st_list *ptr = NULL;

    ptr = (st_list *)malloc(sizeof(st_list));
    if(ptr == NULL)
    {
        printf("Error durante la creacion de un nodo\n");
        exit(-1);
    }
    ptr->st = data;
    ptr->dest = dest;
    ptr->sig = NULL;

    return ptr;
}

/**
 * @brief [ESP] Busca el nodo y lo remueve en cola.
 *        [ENG] Finds node and removes it from queue.
 */
st_list *Buscar_Nodo(st_list *ptr1erElemento, st_list **ptr_auxiliar, int *count_Final_Lista, uint32_t dest)
{
    st_list *Nodo_Actual = ptr1erElemento;

    while( Nodo_Actual != NULL )
    {
        if( (Nodo_Actual->dest & dest) == dest )
            return Nodo_Actual;

        *ptr_auxiliar = Nodo_Actual;
        Nodo_Actual = Nodo_Actual->sig;
    }
    
    *count_Final_Lista = 1;

    return NULL;
}

/**
 * @brief [ESP] Múltiples adiciones a la lista. Incompleto.
 *        [ENG] Multiple additions to list. Incomplete.
 */
int pushMulti( st_list **ptr1erElemento , const st_data *pdata , uint32_t dest)
{
    st_list *Nodo_Actual = *ptr1erElemento;

    if(dest == 0) return 0;

    if(*ptr1erElemento == NULL)
    {
        *ptr1erElemento = Crear_Y_Cargar_Nodo(*pdata, dest);
         Nodo_Actual = *ptr1erElemento;
         return 1;
    }

    Nodo_Actual = Crear_Y_Cargar_Nodo(*pdata, dest);
    Nodo_Actual->sig = *ptr1erElemento;
    *ptr1erElemento = Nodo_Actual;

    return 1;
}

/**
 * @brief [ESP] Busca nodo y remueve el de un determinado destino. Incompleto.
 *        [ENG] Validates output destination via Bitwise matching. Incomplete. 
 */
int popDest( st_list **ptr1erElemento, st_data *bufferdata , uint32_t dest)
{
    /* [ESP] Incompleto / [ENG] Incomplete */
    return 1;
}

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main()
{
    return 0;
}
