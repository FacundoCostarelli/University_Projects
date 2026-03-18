#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include<errno.h>

typedef struct{
    int code, cant;
    char desc[30];
}st_data;
typedef unsigned int uint32_t;

#define DEST_01		0x0001
#define DEST_02		0x0002
#define DEST_03		0x0004
#define DEST_04		0x0008
#define DEST_05		0x0010
#define DEST_06		0x0020
/// etcetera


//===================================================================
//-------------------- Resolución del examen ------------------------
//
//===================================================================


typedef struct lista
{
	st_data st;
	uint32_t  dest;
	struct lista *sig;
} st_list;





st_list * nodo (const st_data *pdat,uint32_t  dest)
{
st_list *q;

	q=(st_list *) malloc ( sizeof (st_list) );
	if (q)
	{
		q->sig=NULL;
		q->dest=dest;
		q->st=*pdat;
	}
	
return q;	
}


int pushMulti  (st_list ** pp, const st_data *pdat,uint32_t dest)
{
st_list *q,*r;

	if (!dest)	// se requiere definir un destino
		return 0;
	
	q=nodo(pdat,dest);
	if (!q)
		return 0;	// condición de error

/*	insertamos al final lo cual simplifica el proceso de extracción */

	if ( !(*pp)   )	// si la lista esta vacia
	{
		q->sig=*pp;
		*pp=q;
		return 1;
	}

/*	Buscamos el final de la lista para hacer la insercion */

	for (r=*pp; r->sig ;r=r->sig);// va el punto y coma
	r->sig=q;

return 1;

}


st_list * buscar (st_list * p, int code)
{
	while (p)
	{
		if (code <= p->st.code)
		{
			if (p->st.code==code)
				return p;
			break;
		}
		p=p->sig;
	}

return NULL;
}

// Extraccion condicionada
int popDest  (st_list ** pp,st_data *pdat,uint32_t  dest)
{
st_list *q,*r;

	if (*pp==NULL)	//lista vacia
		return 0;

	// Analizamos el primero de la lista	
	if ((*pp)->dest & dest)
	{
	/// corresponde a ese distino
		*pdat=(*pp)->st;	// recuperamos el dato

		(*pp)->dest &= ~dest;	// se retira el destino del bitwise

		if (!(*pp)->dest)	// ya se envio a todos los destinos
		{					// entonces se libera el recurso
			q=*pp;	// elemento a extrae
			*pp=(*pp)->sig;	// nuevo inicio de la lista
			free (q); //liberamos el nodo 
		}

		return 1;
	}

	// analizamos si se encuentra en el resto de la lista
	for (r=*pp; r->sig && !(r->sig->dest & dest); r=r->sig);

	
	if (r->sig==NULL)	// no se encontro el destino buscado
		return 0;	

	//--- destino encontrado, devolvemos el dato.
	*pdat=r->sig->st;	// recuperamos el dato

	r->sig->dest &= ~dest; // se retira el destino del bitwise

	if (!r->sig->dest)	// ya se envio a todos los destinos
	{					// entonces se libera el recurso
		q=r->sig;		// elemento a extraer
		r->sig=q->sig;	// nuevo inicio de la lista
		free (q); //liberamos el nodo 
	}

return 1;
}

// liberación de todos los nodos que conforman la lista
// no estaba pedido en el enunciado, pero correspoindería
void liberar (st_list ** pp)
{
st_list * q=*pp;
st_list * r;	
	while (q)
	{
		r=q;
		q=q->sig;
		free (r);
	}

	*pp=NULL;
}



//===================================================================
//---------- código auxiliar para probar el código ------------------
//
//===================================================================

// permite visualizar como se van acomodando los datos
void prt (const st_list * p)
{
	printf ("-------------------------------\n");
	printf ("prt lista\n");
	while (p)
	{
		printf ("- %04X -> %4d | %4d | %s\n",p->dest,p->st.code,p->st.cant,p->st.desc);
		p=p->sig;
	}
	printf ("-------------------------------\n");

	
}

int main ()
{
st_list * p=NULL;
uint32_t xproc;
st_data dd;
int i;

st_data vec[]={{111,111,"aaaaaaa"},
			   {222,222,"bbbbbbbbbb"},
			   {333,333,"cccccccccc"},
			   {444,444,"dddddddd"},
			   {555,555,"eeeeeeeeeeeeee"},
			   {666,666,"fffffffffff"},
			};	
uint32_t xdest[]={ 	DEST_02|DEST_06,
	 				DEST_04|DEST_06, 
	 				DEST_01|DEST_02|DEST_03|DEST_04|DEST_06, 
	 				DEST_01, 
	 				DEST_04|DEST_05|DEST_06, 
	 				DEST_01|DEST_06 };	
	
	for (i=0;i<sizeof vec/sizeof *vec;i++)
	{
		
		if (!pushMulti  (&p,vec+i,xdest[i]))
		{
			printf ("Error durante inserción\n");
		}
		prt ( p);	// a modo de debug
	}

	printf ("Comenzamos a extarer los datos...\n");

	printf ("- dest:");
		scanf ("%x",&xproc);

	while (xproc )
	{
		if (popDest (&p ,&dd,xproc))
			printf ("-> %4d | %4d | %s\n",dd.code,dd.cant,dd.desc);
		else
			printf ("Sin datos para el destino\n");

		prt ( p);	// a modo de debug

		
		printf ("- dest:");
		scanf ("%x",&xproc);
	}
	printf ("Fin...\n\n");

	liberar (&p);	

	
return 0;
}

