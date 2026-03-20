/**
 * @file    main2.c
 * @brief   [ESP] Resolución 2 - Final 22-12-2022. Cola dinámica con realocación de bloque.
 *          [ENG] Resolution 2 - Final 22-12-2022. Dynamic queue using block reallocation.
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

typedef struct
{
	st_data st;
	uint32_t dest;
} st_dest;

/**
 * @brief [ESP] Registro contenedor principal de la cola.
 *        [ENG] Main container struct for queue array.
 */
typedef struct
{
	st_dest *p;
	int cant;
	int size;
} st_queue;

#define DELTA_UP   2
#define DELTA_DOWN (DELTA_UP+1)

int pushMulti (st_queue * pb, const st_data *pdat, uint32_t dest)
{
    st_dest *px;
	if (!dest) return 0;
	
    /* insertamos al final - es más fácil */
	if ( pb->cant >= pb->size)	
	{
		px = (st_dest*) realloc (pb->p, (pb->size + DELTA_UP) * sizeof(st_dest));
		if (!px) return 0;
		pb->p = px;
		pb->size += DELTA_UP;
	}

    /* Hacemos la inserción */
	pb->p[pb->cant].st = *pdat;
	pb->p[pb->cant].dest = dest;
	pb->cant++;
    return 1;
}

void del_dest(uint32_t *dest, uint32_t borrar)
{
    uint32_t aux = *dest;
	*dest = 0;
	
	while(aux)
	{
		if (aux % 10 != borrar)
		{
			*dest *= 10;
			*dest += (aux % 10);
		}
		aux /= 10;
	}
}

int is_dest(uint32_t xdest, uint32_t dest)
{
	while(xdest)
	{
		if (xdest % 10 == dest) return 1;
		xdest /= 10;
	}
    return 0;
}

int buscar(st_queue * pb, uint32_t dest)
{
    int i;
	for (i = 0; i < pb->cant; i++)
		if (is_dest(pb->p[i].dest, dest))
			return i; /* posicion */
    return -1;
}

/**
 * @brief [ESP] Extraccion de la cola con realloc().
 *        [ENG] Deletion from queue using realloc().
 */
int popDest(st_queue * pb, st_data *pdat, uint32_t dest)
{
    int pos, i;
	
	if (pb->cant == 0) return 0;

	pos = buscar(pb, dest);
	if (pos < 0) return 0;

	*pdat = pb->p[pos].st;

	del_dest(&pb->p[pos].dest, dest);

	if (!pb->p[pos].dest)	
	{
		for (i = pos; i < pb->cant; i++)
			pb->p[i] = pb->p[i+1];
		pb->cant--;
		
        /* si se eliminaron muchos datos redimensionamiento DOWN */
		if ((pb->size - pb->cant) > DELTA_DOWN)
		{
			pb->p = (st_dest*) realloc(pb->p,(pb->cant+DELTA_UP)*sizeof(st_dest));
			pb->size = pb->cant + DELTA_UP;
		}
	}
    return 1;
}

/**
 * @brief [ESP] Función para liberar toda la cola y la memoria.
 *        [ENG] Memory freeing.
 */
void liberar(st_queue * pb)
{
	if (pb->p != NULL)
	{
		free (pb->p);
		pb->p = NULL;
		pb->cant = 0;
		pb->size = 0;
	}
}

void prt(const st_queue * pb)
{
	int i;
	printf ("-------------------------------\n");
	printf ("prt buff - size: %d | cant: %d\n", pb->size, pb->cant);
	for (i = 0; i < pb->cant; i++)
	{
		printf ("- %06d -> %4d | %4d | %s\n", pb->p[i].dest, pb->p[i].st.code, pb->p[i].st.cant, pb->p[i].st.desc);
	}
	printf ("-------------------------------\n");
}

#define INIT_QUEUE {NULL,0,0} 
	
/**
 * @brief [ESP] Función principal de la resolución 2.
 *        [ENG] Main function for second resolution.
 */
int main()
{
    st_queue buff = INIT_QUEUE;
    uint32_t xproc;
    st_data dd;
    int i;

    st_data vec[]={
        {111,111,"aaaaaaa"}, {222,222,"bbbbbbbbbb"}, {333,333,"cccccccccc"},
        {444,444,"dddddddd"}, {555,555,"eeeeeeeeeeeeee"}, {666,666,"fffffffffff"},
    };	
    uint32_t xdest[]={ 26, 46, 64321, 1, 456, 61 };	

	for (i=0; i < sizeof vec / sizeof *vec; i++)
	{
		if (!pushMulti(&buff, vec+i, xdest[i]))
			printf ("Error durante inserción\n");
		prt(&buff);
	}

	printf ("Comenzamos a extarer los datos...\n");
	printf ("- dest:");
    scanf ("%d",&xproc);

	while (xproc)
	{
		if (popDest(&buff, &dd, xproc))
			printf ("-> %4d | %4d | %s\n",dd.code,dd.cant,dd.desc);
		else
			printf ("Sin datos para el destino\n");

		prt(&buff);

		printf ("- dest:");
		scanf ("%d",&xproc);
	}
	printf ("Fin...\n\n");
	liberar(&buff);

    return 0;
}
