#include "Functions.h"

//EJERCICIO 2
//Asumo que los ultimos 4 bits del codigo del cliente se refieren a los 4 bits del nibble LSB
int obtenerBarrio(unsigned int codigoCliente, unsigned int *barriocliente)
{
    unsigned int Mask = 0x0000000F;
    unsigned int aux = 0;
    if( (aux = Mask & codigoCliente) < 0 )
        return ERROR;
    else
        *barriocliente = aux;

    //printf("Codigo de cliente: base 10 [%u], base 16 [0x%0X]\n",codigoCliente,codigoCliente);
    //printf("Barrio cliente: base 10 [%u], base 16 [0x%0X]\n", *barriocliente, *barriocliente);

    return EXITO;
}

//EJERCICIO 3
int crearListado(LISTAENERGIA **listadoClientesBarrio, FILE *idEnergia, unsigned int barrio)
{
    unsigned int barriocliente = 0;
    int CantidadEstructuras_FileIn = 0;
    long tamanio_archivo = 0;
    int i = 0;
    ENERGIA *Buffer_Read_in = NULL;

    //Posiciono el "file position indicator" al final del archivo de entrada
    fseek(idEnergia,0,SEEK_END);
    //Averiguo el tamanio del archivo
    tamanio_archivo = ftell(idEnergia);
    //Averiguo la cantidad de estructuras del archivo de entrada
    CantidadEstructuras_FileIn =  ( (int)tamanio_archivo ) / ( (int)sizeof(ENERGIA) );
    printf("La cantidad de estructuras tipo ENERGIA son: %d\n", CantidadEstructuras_FileIn);
    //Posiciono el "file position indicator" al comienzo del arhcivo de entrada
    fseek(idEnergia,0,SEEK_SET);

    //Pido memoria dinamica para almacenar la info del archivo in en memoria
    Buffer_Read_in = (ENERGIA *)malloc( CantidadEstructuras_FileIn * sizeof(ENERGIA));
    //Proteccion contra NULL de malloc
    if( Buffer_Read_in == NULL )
    {
        printf("Erropr en la asignacion de memoria dinamica para buffer de informacion read in\n");
        return ERROR;
    }

    for( i = 0; i < CantidadEstructuras_FileIn; i++ )
    {
        if( buscarRegistro(idEnergia,&Buffer_Read_in[i]) == EXITO )
            continue;
        else
            return ERROR;
    }

    /*
    //Leo del arhcivo de entrada las estructuras y las guardo en memoria
    if ( fread(Buffer_Read_in, CantidadEstructuras_FileIn * sizeof(ENERGIA), 1, idEnergia) < 1 )
    {
        printf("Hubo un error con la lectura en memoria de las estructuras de entrada\n");
        return ERROR;
    }
    */

    //Evaluo cada estructura con su informacion la cual se encuentra en el buffer en memoria heap
    for( i = 0; i < CantidadEstructuras_FileIn; i++ )
    {
        if( obtenerBarrio(Buffer_Read_in[i].codigoCliente,&barriocliente) == EXITO)
        {
            printf("El dato a comparar barriocliente[0x%0X] VS barrio indicado de filtrado[0x%0X]\n", barriocliente,barrio);
            //continue;
        }
        else
            return ERROR;
        //Habiendo logrado obtener exitosamente el dato a comparar, entonces comparo con lainformacion propuesta de filtro

        if( barriocliente == barrio )
        {
            //En caso de coincidir la informacion del cliente vs la de filtrado, entonces creo y armo una
            //Lista simplemente enlazada que puede ser tipo:
            // - COLA, es decir, con formato FIFO
            // - PILA, es decir, con formato LIFO
            //Esto depende del algoritmo de enlazamiento
            //Elijo formato PILA en este caso por gusto propio
            if( Lista_Simplemente_Enlazada_PILA( listadoClientesBarrio,Buffer_Read_in[i]) == EXITO )
                printf("Se creo crrectamente un nuevo nodo\n");
            else
            {
                printf("NO se creo correctamente un nodo;\n");
                return ERROR;
            }
        }

    }

    //Cierro arhcivo de entrada
    fclose(idEnergia);
    //Libero recursos de memoria dinamica usada
    free(Buffer_Read_in);

    return EXITO;
}

//FUNCION ADICIONAL PARA EJERCICO 3
//Funcion que crea una Lista Simplemtente Enlazada tipo PILA. Devuelve ERROR en caso de alguna falla o EXITO
int Lista_Simplemente_Enlazada_PILA(LISTAENERGIA **ptr1erElemento,ENERGIA data)
{
    LISTAENERGIA *Nuevo_Nodo = NULL;

    //Verifico si la lista esta vacia y en tal caso creo, cargo y agrego el 1er nodo de la lista
    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");

        //Llamo a funcion que crea dinamicamente un nuevo nodo
        if ( Allocalizar_Nuevo_Nodo(&Nuevo_Nodo) == ERROR )
            return ERROR;

        //Cargar 1er nodo
        Nuevo_Nodo->cliente = data;
        //Enlazamiento del 1er nodo
        Nuevo_Nodo->siguiente= NULL;

        //Retorno, por referencia, del puntero al nuevo nodo creado
        *ptr1erElemento = Nuevo_Nodo;
    }
    else
    {
        //Si la lista no esta vacia, entonces creo un nuevo nodo, lo cargo y lo enlazo a la lista actual
        //Por ser pila es con enlazamiento al principio

        /*ENLAZAMIENTO AL PRINCIPIO(PILA)*/
        if( Enlazar_Al_Principio_Y_Cargar(ptr1erElemento,data,&Nuevo_Nodo) == ERROR )
            return ERROR;
    }

    return EXITO;
}
//FUNCION ADICIONAL PARA EJERCICIO 3
//Funcion que allocaliza dinamicamente un nuevo nodo.
//Retorna ERROR en caso de error y EXITO en caso de exito
int Allocalizar_Nuevo_Nodo( LISTAENERGIA **Nuevo_Nodo)
{
    //Allocacion de memoria dinamica para un nuevo nodo y verificacion de error de malloc
    *Nuevo_Nodo = (LISTAENERGIA *)malloc(sizeof(LISTAENERGIA));
    if(*Nuevo_Nodo == NULL)
    {
        printf("Hubo un error con la creacion y asignacion de memoria dinamica para un nuevo nodo\n");
        return ERROR;
    }
    else
        printf("Se creo exitosamente y dinamicamente un nuevo nodo\n");

    return EXITO;
}

//FUNCION ADICIONAL PARA EJERCICIO 3
//Funcion que elaza al principio y carga el nodo.
//ESTO ES FORMATO PILA para una LISTA_SL
int Enlazar_Al_Principio_Y_Cargar(LISTAENERGIA **ptr1erElemento,ENERGIA data,LISTAENERGIA **Nuevo_Nodo)
{
    printf("Se creara, cargara y agregara un nuevo nodo al principio de la lista\n");

    //Llamo a funcion que crea dinamicamente un nuevo nodo
    if( Allocalizar_Nuevo_Nodo(Nuevo_Nodo) == ERROR )
        return ERROR;

    //No busco ultimo nodo del final de lista ya que solo necesito el nodo inicial de la lista

    //Enlazo nodo al princpio de la lista
    (*Nuevo_Nodo)->siguiente = *ptr1erElemento;
    //Cargo el nuevo nodo
    (*Nuevo_Nodo)->cliente = data;
    //Retorno, por referencia, del puntero al nuevo nodo creado
    *ptr1erElemento= *Nuevo_Nodo;

    return EXITO;
}

//FUNCION ADICIONAL EJERCICIO 3
void Liberar_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(LISTAENERGIA **ptr1erElemento)
{
    LISTAENERGIA *Nodo_Actual = *ptr1erElemento;

    while(*ptr1erElemento != NULL)
    {
        *ptr1erElemento = Nodo_Actual->siguiente;
        free(Nodo_Actual);
        Nodo_Actual = *ptr1erElemento;
    }

    return;
}

//Funcion que imprime la informacion de cada nodo de una lista simplemente enlazada siempre y cuando cada nodo tenga una variable del tipo "struct" con sus respectivos campos
void Imprimir_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(LISTAENERGIA **ptr1erElemento)
{
    LISTAENERGIA *Nodo_Actual = *ptr1erElemento;
    //Se imprime comenzando por el PRINCIPIO de la COLA hasta el FINAL de la misma.
    //Deberia ser al reves pero se necesita una COLA DOBLEMENTE ENLAZADA
    while(Nodo_Actual != NULL)
    {
        printf("nomnreyapellido: %s\n", Nodo_Actual->cliente.nombreyapellido);
        printf("codigoCliente 2: %u\n", Nodo_Actual->cliente.codigoCliente);
        printf("kws: %.2f\n", Nodo_Actual->cliente.kws);
        Nodo_Actual = Nodo_Actual->siguiente;
    }

    return;
}



//EJERCICIO 4
int buscarRegistro(FILE *idEnergia,ENERGIA *cliente)
{
    if( fread((ENERGIA *)cliente,sizeof(ENERGIA),1,idEnergia) < 1 )
    {
        printf("Error en la lectura de una unidad de registro tipo ENERGIA\n");
        return ERROR;
    }

    return EXITO;
}

