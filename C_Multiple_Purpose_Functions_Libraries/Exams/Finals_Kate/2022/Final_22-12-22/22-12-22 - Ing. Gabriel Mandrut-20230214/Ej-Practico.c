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

typedef struct{
    int code, cant;
    char desc[30];
}st_data;
typedef unsigned int uint32_t;

typedef struct lista
{
	st_data st;
	uint32_t  dest;
	struct lista *sig;
} st_list;



int main()
{




    return ;
}

/*

  int init (st_lista **cola_mensajes, st_data data)
  {
  }
  Esta funcion no la desarrollo ni la hago ya que las condiciones para que la cola de mensajes este lista para su uso son:
  -Creacion de un nuevo nodo dinamico
  -Carga de informacion en el nuevo nodo
  -Enlazamiento del nodo a la lista siguiendo el formato FIFO
  -Obtencion de la lista construida tipo COLA con formato FIFO
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

st_list *Buscar_Nodo(st_list *ptr1erElemento, st_list **ptr_auxiliar, int *count_Final_Lista, uint32_t dest)
{
    st_list *Nodo_Actual = ptr1erElemento;

    //Recorro la lista desde el principio hasta el ultimo nodo, en busqueda del que tenga el valor "dest". Si encuentro un nodo que cumpla, entonces lo retorno y termina el recorrido de la lista.
    while( Nodo_Actual != NULL )
    {
        if( Nodo_Actual->dest & dest == dest )
            return Nodo_Actual;

        *ptr_auxiliar = Nodo_Actual;
        Nodo_Actual = Nodo_Actual->sig;
        if( Nodo_Actual = NULL )//Si llega al final de la lista sin retornar nodos que posean el valor de dest. Entonces pongo en 1 el count
            *count_Final_Lista = 1;
    }

    return NULL;//Si recorro toda la lista desde el principio hasta llegar al final y no encuentro ningun nodo mas con el dest indicado o mismo la lista esta vacia, entonces retorno NULL
}

int pushMulti ( st_list **ptr1erElemento , const st_data *pdata , uint32_t dest)
{
    st_list *Nodo_Actual = *ptr1erElemento;

    //Chequeo que dest sea 0. Si lo es, significa que no hay un destino para enviar el mensaje, entonces retorno 0(error)
    if(dest == 0)
        return 0;

    //Chequeo si la lista esta vacia. En tal caso creo el 1er elemento de la misma y lo enlazo a NULL.
    if(*ptr1erElemento == NULL)
    {
        *ptr1erElemento = Crear_Y_Cargar_Nodo(*ptdata, dest);
         Nodo_Actual = *ptr1erElemento;
    }

    //Creo un nuevo nodo y lo enlazo al 1er nodo de la lista, es decir, al comienzo de la lista. Queda asi el nuevo nodo como 1er nodo de la lista
    Nodo_Actual = Crear_Y_Cargar_Nodo(*ptdata, dest);
    Nodo_Actual->sig = *ptr1erElemento;
    //El puntero al 1er nodo ahora apunta al nuevo nodo creado
    *ptr1erElemento = Nodo_Actual;

    return 1;
}

int popDest( st_list **ptr1erElemento, st_data *bufferdata , uint32_t dest)
{
    st_list *Nodo_Actual = *ptr1erElemento;
    st_list *ptr_auxiliar = *ptr1erElemento;
    st_list *Nodo_Retornado = NULL;
    int count_Final_Lista = 0;

    while( count_Final_Lista = 0 )
    {
        Nodo_Retornado = Buscar_Nodo(*ptr1erElemento,&ptr_auxiliar,&count_Final_Lista,dest);//Obtengo un nodo retornado segun el valor de dest
        if(Nodo_Retornado == NULL)
        {
            printf("No se encontro ningun nodo mas con el valor dest solicitado o no se encontro ningun nodo en total con el valor de dest o la cola de mensajes esta vacia en mensajes o se llego al final \n");
            return 0;
        }
        bufferdata[count_Nodos_No_Null] = Nodo_Retornado->st;
        count_Nodos_No_Null++;
        ptr_auxiliar->sig = Nodo_Retornado->sig;
        Nodo_Retornado->sig = NULL;
        free(Nodo_Retornado);
    }

    return 1;
}


