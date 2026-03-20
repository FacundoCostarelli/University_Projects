/**
 * @file    main.c
 * @brief   [ESP] Resolución 1 - Final 22-12-2022. Lista Enlazada Simple con Bitwise.
 *          [ENG] Resolution 1 - Final 22-12-2022. Singly Linked List with Bitwise.
 *
 * @author  Ing. Gabriel Mandrut
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/**
 * @brief [ESP] Estructura de datos almacenada.
 *        [ENG] Stored data structure.
 */
typedef struct{
    int code, cant;
    char desc[30];
} st_data;

typedef unsigned int uint32_t;

#define DEST_01		0x0001
#define DEST_02		0x0002
#define DEST_03		0x0004
#define DEST_04		0x0008
#define DEST_05		0x0010
#define DEST_06		0x0020

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
 * @brief [ESP] Asigna un nuevo nodo e inicializa los parámetros.
 *        [ENG] Allocates a new node and initializes parameters.
 */
st_list * nodo(const st_data *pdat, uint32_t dest)
{
    st_list *q;

	q = (st_list *) malloc(sizeof (st_list));
	if (q)
	{
		q->sig = NULL;
		q->dest = dest;
		q->st = *pdat;
	}
    return q;	
}

/**
 * @brief [ESP] Inserta nodo al final.
 *        [ENG] Inserts node at tail.
 */
int pushMulti(st_list ** pp, const st_data *pdat, uint32_t dest)
{
    st_list *q, *r;

	if (!dest) return 0;
	
	q = nodo(pdat, dest);
	if (!q) return 0;	

	if ( !(*pp) )	/* lista vacia / empty list */
	{
		q->sig = *pp;
		*pp = q;
		return 1;
	}

    /* Buscamos el final de la lista */
	for (r = *pp; r->sig; r = r->sig);
	r->sig = q;

    return 1;
}

st_list * buscar (st_list * p, int code)
{
	while (p)
	{
		if (code <= p->st.code)
		{
			if (p->st.code == code) return p;
			break;
		}
		p = p->sig;
	}
    return NULL;
}

/**
 * @brief [ESP] Extrae elementos según el destino con bitwise AND.
 *        [ENG] Conditioned extraction based on destination using bitwise AND.
 */
int popDest(st_list ** pp, st_data *pdat, uint32_t dest)
{
    st_list *q, *r;

	if (*pp == NULL) return 0;	

	if ((*pp)->dest & dest)
	{
		*pdat = (*pp)->st;	

		(*pp)->dest &= ~dest;	/* se retira el destino del bitwise */

		if (!(*pp)->dest)	
		{					
			q = *pp;	
			*pp = (*pp)->sig;	
			free(q); 
		}
		return 1;
	}

	for (r = *pp; r->sig && !(r->sig->dest & dest); r = r->sig);
	
	if (r->sig == NULL)	return 0;	

	*pdat = r->sig->st;	

	r->sig->dest &= ~dest; 

	if (!r->sig->dest)	
	{					
		q = r->sig;		
		r->sig = q->sig;	
		free(q); 
	}
    return 1;
}

/**
 * @brief [ESP] Libera toda la lista.
 *        [ENG] Frees entire list.
 */
void liberar(st_list ** pp)
{
    st_list * q = *pp;
    st_list * r;	
	while (q)
	{
		r = q;
		q = q->sig;
		free(r);
	}
	*pp = NULL;
}

/**
 * @brief [ESP] Funcion de print por terminal (DEBUGGING).
 *        [ENG] Terminal print function (DEBUGGING).
 */
void prt(const st_list * p)
{
	printf ("-------------------------------\n");
	printf ("prt lista\n");
	while (p)
	{
		printf ("- %04X -> %4d | %4d | %s\n", p->dest, p->st.code, p->st.cant, p->st.desc);
		p = p->sig;
	}
	printf ("-------------------------------\n");
}

int main ()
{
    st_list * p = NULL;
    uint32_t xproc;
    st_data dd;
    int i;

    st_data vec[]={
        {111,111,"aaaaaaa"}, {222,222,"bbbbbbbbbb"}, {333,333,"cccccccccc"},
        {444,444,"dddddddd"}, {555,555,"eeeeeeeeeeeeee"}, {666,666,"fffffffffff"},
    };	
    uint32_t xdest[]={ 	
        DEST_02|DEST_06, DEST_04|DEST_06, 
        DEST_01|DEST_02|DEST_03|DEST_04|DEST_06, 
        DEST_01, DEST_04|DEST_05|DEST_06, DEST_01|DEST_06 
    };	

	for (i=0; i < sizeof vec / sizeof *vec; i++)
	{
		if (!pushMulti(&p, vec+i, xdest[i]))
			printf ("Error durante inserción\n");
		prt(p);	/* DEBUG */
	}

	printf ("Comenzamos a extarer los datos...\n");
	printf ("- dest:");
    scanf ("%x",&xproc);

	while (xproc)
	{
		if (popDest(&p ,&dd,xproc))
			printf ("-> %4d | %4d | %s\n",dd.code,dd.cant,dd.desc);
		else
			printf ("Sin datos para el destino\n");

		prt(p);	/* DEBUG */

		printf ("- dest:");
		scanf ("%x",&xproc);
	}
	printf ("Fin...\n\n");
	liberar (&p);	

    return 0;
}
