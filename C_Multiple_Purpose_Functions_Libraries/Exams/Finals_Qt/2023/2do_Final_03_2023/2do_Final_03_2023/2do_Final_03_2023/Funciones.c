#include "Funciones.h"

int obtenerBariio(unsigned int codigoCliente, unsigned int *barrioCliente)
{
    unsigned int mascara = 0x0000000F;
    printf("El codigo del cliente es %u\n", codigoCliente);
    if( (*barrioCliente = codigoCliente & mascara) >= 0 )
    {
        printf("El barrio del cliente en decimal es %u\n", *barrioCliente);
        printf("El barrio del cliente en bits es: \n");
        PrintBits(*barrioCliente, 8 * sizeof(unsigned int));
        return EXITO;
    }
    printf("No se pudo obtener el barrio del cliente\n");
    return ERROR;
}

int crearListado(LISTAENERGIA **listadoClientesBarrio,LISTAENERGIA **ptrAux, FILE *idEnergia, unsigned int barrio)
{
    unsigned int barrioCLiente = 0;
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

    //Leo del arhcivo de entrada las estructuras y las guardo en memoria
    if ( fread(Buffer_Read_in, CantidadEstructuras_FileIn * sizeof(ENERGIA), 1, idEnergia) < 1 )
    {
        printf("Hubo un error con la lectura en memoria de las estructuras de entrada\n");
        return ERROR;
    }

    //Evaluo cada estructura con su informacion la cual se encuentra en el buffer en memoria heap
    for( i = 0; i < CantidadEstructuras_FileIn; i++ )
    {
        printf("El codigo del cliente es%u\n", Buffer_Read_in[i].codigoCliente);
        //Obtengo el barrio de cada estructura asociada a cada cliente y actuo en consecuencia
        if( obtenerBariio(Buffer_Read_in[i].codigoCliente,&barrioCLiente) == EXITO )
        {
            //Habiendo logrado obtener exitosamente el barrio del cliente, entonces comparo con el barrio
            //propuesto de filtro
            if( barrioCLiente == barrio )
            {
                //En caso de coincidir los barrios del cliente vs el barrio de filtro, entonces creo y armo una
                //Lista simplemente enlazada tipo COLA, es decir, con formato FIFO
                if ( Lista_Simplemente_Enlazada_COLA(listadoClientesBarrio,ptrAux,Buffer_Read_in[i]) == EXITO )
                    printf("Se creo crrectamente un nuevo nodo\n");
                else
                {
                    printf("NO se creo correctamente un nodo;\n");
                    return ERROR;
                }
            }
        }
        else
        {
            printf("Hubo un problema con la obtencion del barrio del cliente\n");
            return ERROR;
        }
    }
    //Libero los recursos del buffer dinamico de estructuras provenientes del archivo de entrada
    free(Buffer_Read_in);

    return EXITO;
}

/*
int buscarRegistro(id *idEnergia, ENERGIA *cliente)
{
    return EXITO;
}
*/

//Funcion generica que crea,cargar y enlaza un nodo donde alguno de los campos internos es una variable asociada a una estructura y NO un puntero a estructura, Esta funcion esta pensada para poder utilizar un nodo cuya "struct" es presentada de la siguiente manera
/*
    typedef struct nodo
    {
        Producto_t data;
        Nodo_t *sig;
    }Nodo_t;
 */

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
        Nuevo_Nodo->sig = NULL;

        //Retorno, por referencia, del puntero al nuevo nodo creado
        *ptr1erElemento = Nuevo_Nodo;
    }
    else
    {
        //Si la lista no esta vacia, entonces creo un nuevo nodo, lo cargo y lo enlazo a la lista actual
        if ( Enlazar_Al_Principio_Y_Cargar(ptr1erElemento,data,&Nuevo_Nodo) == ERROR )
            return ERROR;
    }

    return EXITO;
}

int Lista_Simplemente_Enlazada_COLA(LISTAENERGIA **ptr1erElemento,LISTAENERGIA **ptrAux,ENERGIA data)
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
        Nuevo_Nodo->sig = NULL;

        //Retorno, por referencia, del puntero al nuevo nodo creado
        *ptr1erElemento = Nuevo_Nodo;
        //Hago que un puntero auxiliar comienze apuntando al nodo nuevo creado por 1era vez
        *ptrAux = Nuevo_Nodo;

    }
    else
    {
        if ( Enlazar_Al_Final_Y_Cargar(ptr1erElemento,ptrAux,data,&Nuevo_Nodo) == ERROR )
            return ERROR;
    }

    return EXITO;
}

//Funcion que allocaliza dinamicamente un nuevo nodo.
//Retorna -1 en caso de error y 0 en caso de exito
int Allocalizar_Nuevo_Nodo(LISTAENERGIA **Nuevo_Nodo)
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
    (*Nuevo_Nodo)->sig = *ptr1erElemento;
    //Cargo el nuevo nodo
    (*Nuevo_Nodo)->cliente = data;
    //Retorno, por referencia, del puntero al nuevo nodo creado
    *ptr1erElemento= *Nuevo_Nodo;

    return EXITO;
}

//Funcion que elaza al final y carga el nodo.
//ESTO ES FORMATO COLA para una LISTA_SL
int Enlazar_Al_Final_Y_Cargar(LISTAENERGIA **ptr1erElemento,LISTAENERGIA **ptrAux,ENERGIA data,LISTAENERGIA**Nuevo_Nodo)
{

    printf("Se creara, cargara y agregara un nuevo nodo al final de la lista\n");

    //Llamo a funcion que crea dinamicamente un nuevo nodo
    if( Allocalizar_Nuevo_Nodo(Nuevo_Nodo) == ERROR )
        return ERROR;

    //No busco ultimo nodo del final de lista ya que solo necesito el nodo inicial de la lista
    printf("Se llego a la linea 189\n");

    //Enlazo nodo al final de la lista


    //Pregunto si el puntero sig del 1er nodo apunta a NULL. En tal caso enlazo al final respecto del 1er nodo y cargo el nuevo nodo
    if ( (*ptr1erElemento)->sig == NULL )
    {
        (*ptr1erElemento)->sig = *Nuevo_Nodo;
        *ptrAux = *Nuevo_Nodo;
        (*Nuevo_Nodo)->sig = NULL;
        //Cargo el nuevo nodo
        (*Nuevo_Nodo)->cliente = data;
    }
    //Si el puntero sig del 1er nodo NO apunta a NULL, significa que ya tenemos al menos 2 nodos. En tal caso enlazo al final desde el ultimo nodo
    else
    {
        (*ptrAux)->sig = *Nuevo_Nodo;
        *ptrAux = *Nuevo_Nodo;
        (*Nuevo_Nodo)->sig = NULL;
        //Cargo el nuevo nodo
        (*Nuevo_Nodo)->cliente = data;
    }
    return EXITO;
}

void Liberar_Lista_Simplemente_Enlazada_PILA_O_COLA(LISTAENERGIA **ptr1erElemento)
{
    LISTAENERGIA *Nodo_Actual = *ptr1erElemento;

    while(*ptr1erElemento != NULL)
    {
        *ptr1erElemento = Nodo_Actual->sig;
        free(Nodo_Actual);
        Nodo_Actual = *ptr1erElemento;
    }

    return;
}

//Funcion que imprime la informacion de cada nodo de una lista simplemente enlazada siempre y cuando cada nodo tenga una variable del tipo "struct" con sus respectivos campos
void Imprimir_Lista_Simplemente_Enlazada_PILA_O_COLA(LISTAENERGIA **ptr1erElemento)
{
    LISTAENERGIA *Nodo_Actual = *ptr1erElemento;
    //Se imprime comenzando por el PRINCIPIO de la COLA hasta el FINAL de la misma.
    //Deberia ser al reves pero se necesita una COLA DOBLEMENTE ENLAZADA
    while(Nodo_Actual != NULL)
    {
        printf("Nombre y apellido del cliente: %s\n", Nodo_Actual->cliente.nombreyapellido);
        printf("Codigo del cliente: %ud\n", Nodo_Actual->cliente.codigoCliente);
        printf("Consumo en kws: %.2f\n", Nodo_Actual->cliente.kws);
        Nodo_Actual = Nodo_Actual->sig;
    }

    return;
}




void PrintBits( unsigned int dato, char nro_de_bit )
{
    nro_de_bit--;

    printf("b:");
    for( ; nro_de_bit >= 0; nro_de_bit-- )
        printf("%d", GetBit(dato, nro_de_bit));

    printf("\nEn hexadecima: (0x%02X) \n", dato);

    return;
}

unsigned char GetBit(unsigned int dato, char bit)
{
    unsigned char resultado, mascara = 1;

    resultado = ( dato >> bit ) & mascara;

    return resultado;
}

unsigned int SetBit( unsigned int dato, char bit, char estado )
{
    unsigned int resultado, mascara = 1;

    mascara = mascara << bit;

    if( estado == OFF)
    {
        mascara = ~mascara;
        resultado = dato & mascara;
    }
    else
        resultado = dato | mascara;

    return resultado;
}

unsigned int SetToggle( unsigned int dato, char bit )
{
    unsigned int resultado, mascara = 1;

    mascara = mascara << bit;
    resultado = dato ^ mascara;

    return resultado;
}

