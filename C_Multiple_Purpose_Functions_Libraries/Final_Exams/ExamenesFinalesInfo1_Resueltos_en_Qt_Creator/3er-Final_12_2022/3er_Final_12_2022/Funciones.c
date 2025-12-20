#include"Funciones.h"

//Funcion generica que crea,cargar y enlaza un nodo donde alguno de los campos internos es una variable asociada a una estructura
//y NO un puntero a estructura. Esta funcion esta pensada para poder utilizar
//un nodo cuya "struct" es presentada de la siguiente manera





  //Asumo que todas las funciones son invocadas desde el main y no dentro de otro scope de otra funcion diferente
int init(Nodo_t **ptr1erElemento,Nodo_t **ptrAux,const data_t *pdat, uint32_t dest)//Asumo que data_t viene de un buffer de memoria dinamica en el main
{
    Nodo_t *Nuevo_Nodo = NULL;

    //Verifico si la lista esta vacia y en tal caso creo, cargo y agrego el 1er nodo de la lista
    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");

        //Llamo a funcion que crea dinamicamente un nuevo nodo
        if ( Allocalizar_Nuevo_Nodo(&Nuevo_Nodo) == ERROR )
            return ERROR;

        //Cargo 1er nodo
        Nuevo_Nodo->data = *pdat;
        Nuevo_Nodo->dest = dest;
        //Enlazamiento del 1er nodo
        Nuevo_Nodo->sig = NULL;

        //Retorno, por referencia, del puntero al nuevo nodo creado
        *ptr1erElemento = Nuevo_Nodo;
        //Hago que un puntero auxiliar comienze apuntando al nodo nuevo creado por 1era vez
        *ptrAux = Nuevo_Nodo;

    }
    else
    {

        if ( pushMulti(ptr1erElemento,ptrAux,&Nuevo_Nodo,pdat,dest) == ERROR )
            return ERROR;
    }

    return EXITO;
}

//Funcion que allocaliza dinamicamente un nuevo nodo.
//Retorna ERROR en caso de error y EXITO en caso de exito
int Allocalizar_Nuevo_Nodo( Nodo_t **Nuevo_Nodo)
{
    //Allocacion de memoria dinamica para un nuevo nodo y verificacion de error de malloc
    *Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
    if(*Nuevo_Nodo == NULL)
    {
        printf("Hubo un error con la creacion y asignacion de memoria dinamica para un nuevo nodo\n");
        return ERROR;
    }
    else
        printf("Se creo exitosamente y dinamicamente un nuevo nodo\n");

    return EXITO;
}

//Funcion que elaza al final y carga el nodo.
//ESTO ES FORMATO COLA para una LISTA_SL
int pushMulti(Nodo_t **ptr1erElemento,Nodo_t **ptrAux,Nodo_t **Nuevo_Nodo,const data_t *pdat,uint32_t dest)
{

    printf("Se creara, cargara y agregara un nuevo nodo al final de la lista\n");

    //Llamo a funcion que crea dinamicamente un nuevo nodo
    if( Allocalizar_Nuevo_Nodo(Nuevo_Nodo) == ERROR )
        return ERROR;

    //No busco ultimo nodo del final de lista ya que solo necesito el nodo inicial de la lista
    //Enlazo nodo al final de la lista

    //Pregunto si el puntero sig del 1er nodo apunta a NULL. En tal caso enlazo al final respecto del 1er nodo y cargo el nuevo nodo
    if ( (*ptr1erElemento)->sig == NULL )
    {
        (*ptr1erElemento)->sig = *Nuevo_Nodo;
        *ptrAux = *Nuevo_Nodo;
        (*Nuevo_Nodo)->sig = NULL;
        //Cargo el nuevo nodo
        (*Nuevo_Nodo)->data = *pdat;
        (*Nuevo_Nodo)->dest = dest;
    }
    //Si el puntero sig del 1er nodo NO apunta a NULL, significa que ya tenemos al menos 2 nodos o mas. En tal caso enlazo al final desde el ultimo nodo
    else
    {
        (*ptrAux)->sig = *Nuevo_Nodo;
        *ptrAux = *Nuevo_Nodo;
        (*Nuevo_Nodo)->sig = NULL;
        //Cargo el nuevo nodo
        (*Nuevo_Nodo)->data = *pdat;
        (*Nuevo_Nodo)->dest = dest;
    }
    return EXITO;
}

int popDest(Nodo_t **ptr1erElemento,Nodo_t **ptrAux, data_t *pdat , uint32_t dest)
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

    return;
}

