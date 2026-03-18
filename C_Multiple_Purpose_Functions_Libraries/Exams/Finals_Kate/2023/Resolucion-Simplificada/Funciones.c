#include"Funciones.h"

//Funcion que abre un archivo de entrada, carga los datos en un buffer dinamico y:
//retorna -1 en caso de error o la cantidad de estructuras leidas
int CargarProductos(const char *nombreArchivo, Producto_t **listado)
{
    int CantidadEstructuras_FileIn,CantidadEstructurasLeidas;

    FILE *File_in = NULL;
    long tamanio_archivo;


    //Abro el archivo de entrada
    File_in = fopen(nombreArchivo,"r");
    if(File_in == NULL)
    {
        printf("Error en la apertura del archivo de entrada\n");
        return -1;
    }

    //Posiciono el "file position indicator" al final del archivo
    fseek(File_in,0,SEEK_END);
    //Averiguo el tamanio del archivo
    tamanio_archivo = ftell(File_in);
    //Averiguo la cantidad de estructuras del archivo de entrada
    CantidadEstructuras_FileIn = ( ( (int)tamanio_archivo ) / ( (int)sizeof(Producto_t) ) );
    printf("La cantidad de estructuras tipo Producto_t son: %d\n", CantidadEstructuras_FileIn);
    fseek(File_in,0,SEEK_SET);

    //Armo el ARRAY DINAMICO DE STRUCTS
    CantidadEstructurasLeidas = Lista_En_Formato_Pila_Como_ARRAYDINAMICO_DE_STRUCTS(CantidadEstructuras_FileIn,File_in,listado);
    //Cierro el archivo de entrada
    fclose(File_in);
    //Muestro en pantalla el contenido del ARRAY DINAMICO DE STRUCTS
    Mostrar_PILA_ARRAY_DINAMICO_DE_STRUCTS(CantidadEstructurasLeidas,listado);


    return CantidadEstructurasLeidas;
}

//Funcion que crea una lista simplemente enlazada en formato PILA, esto es LIFO(Last IN,First Out)
//Esta funcion crea un ARRAY DINAMICO de STRUCTS y no de punteros a structs
//Retorna -1 en caso de error o retorna la cantidad de estructuras leidas en caso de exito

int Lista_En_Formato_Pila_Como_ARRAYDINAMICO_DE_STRUCTS(int CantidadEstructuras_FileIn,FILE *File_in,Producto_t **listado)
{
    size_t CantItemsLeidos;
    int i;

    //Pregunto si la lista esta vacia.
    //En caso de estarlo creo el array dinamico y lo cargo con un formato PILA
    //Es decir, LIFO(Last in First Out)

    if(*listado == NULL)
    {
        printf("La lista esta vacia. Se crearan e insertaran los elementos siguiendo un formato PILA\n");

        //Pido memoria para crear un ARRAY DINAMICO DE STRUCTS segun la Cantidad de estructuras leidas del archivo de entrada
        *listado = (Producto_t *)malloc((CantidadEstructuras_FileIn+1) * sizeof(Producto_t ));
        //Proteccion contra null de malloc
        if(*listado == NULL)
        {
            printf("Hubo un problema con la asignacion de memoria dinamica para el 1er elemento del ARRAY DE STRUCTS\n");
            return ERROR;
        }

        for( i = 0; i < CantidadEstructuras_FileIn; i++ )
        {
            //Leo del archivo de entrada, los elementos, es decir, guardo en memoria heap las estructuras provenientes del archivo de entrada.
            CantItemsLeidos = fread((*listado)+i,sizeof(Producto_t),1,File_in);
            //Proteccion contra falta de items leidos
            if(CantItemsLeidos < 1)
            {
                printf("Error en la lectura de estructuras del ARRAY DINAMICO DE STRUCTS\n");
                return ERROR;
            }
        }

        (*listado)[i].codigo_Producto = 0;
        strcpy( (*listado)[i].proveedor, ULTIMOPRODUCTO );
        (*listado)[i].cantidad_stock = 0;
        return CantidadEstructuras_FileIn;

    }
    //En caso de NO ESTAR VACIA la lista, entonces retorno -1 y un mensaje en pantalla
    else
    {
        printf("La lista ya esta cargada. No hay nada que agregar\n");
        return ERROR;
    }
}

//Funcion que muestra en pantalla el contenido del ARRAY DINAMICO DE STRUCTS tipo PILA con todos sus campos
void Mostrar_PILA_ARRAY_DINAMICO_DE_STRUCTS(int CantidadEstructurasLeidas,Producto_t **listado)
{
    int i;

    for(i = CantidadEstructurasLeidas-1; i >= 0; i--)
    {
        printf("Codigo Producto: %d\n", (*listado)[i].codigo_Producto);
        printf("Proveedor: %s\n",(*listado)[i].proveedor);
        printf("Cantidad de Stock: %d\n", (*listado)[i].cantidad_stock);
    }

    return;
}



//Funcion que recibe un ARRAY DINAMICO DE STRUCTS, filtra los elementos segun nombre de proveedor
//Y arma una lista simplemente enlazada tipo COLA con dichos elementos
//Retorna -1 en caso de error, 0 en caso de no haber productos del proveedor a filtrar, cantidad de productos del proveedor buscado

int FiltrarProductos(const Producto_t *listado, Nodo_t **listadoFiltrado, char *proveedor)
{
    int i = 0;
    int Estructuras_ARRAY_DINAMICO_COUNTER = 0;
    int Productos_Filtrados_Counter = 0;

    for( i = 0; strcasecmp(listado[i].proveedor,ULTIMOPRODUCTO) != 0 ; i++ )
        Estructuras_ARRAY_DINAMICO_COUNTER++;

    printf("En funcion FiltraProductos Estructuras_ARRAY_DINAMICO_COUNTER = %d\n", Estructuras_ARRAY_DINAMICO_COUNTER);

    for( i = Estructuras_ARRAY_DINAMICO_COUNTER-1; i >= 0; i-- )
    {
        if( strcasecmp(proveedor, listado[i].proveedor) == 0 )
        {
            if( Lista_Simplemente_Enlazada(listadoFiltrado,listado[i]) == ERROR )
                return ERROR;


            Productos_Filtrados_Counter++;
        }
    }

    return Productos_Filtrados_Counter;
}



//Funcion generica que crea,cargar y enlaza un nodo donde alguno de los campos internos es una variable asociada a una estructura y NO un puntero a estructura, Esta funcion esta pensada para poder utilizar un nodo cuya "struct" es presentada de la siguiente manera
/*
    typedef struct nodo
    {
        Producto_t data;
        Nodo_t *sig;
    }Nodo_t;
 */
int Lista_Simplemente_Enlazada(Nodo_t **ptr1erElemento,Producto_t data)
{
    Nodo_t *Nuevo_Nodo = NULL;

    //Verifico si la lista esta vacia y en tal caso creo, cargo y agrego el 1er nodo de la lista
    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");

        //Llamo a funcion que crea dinamicamente un nuevo nodo
        if ( Allocalizar_Nuevo_Nodo(&Nuevo_Nodo) == ERROR )
            return ERROR;

        //Cargar 1er nodo
        Nuevo_Nodo->data = data;
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

//Funcion que allocaliza dinamicamente un nuevo nodo.
//Retorna -1 en caso de error y 0 en caso de exito
int Allocalizar_Nuevo_Nodo(Nodo_t **Nuevo_Nodo)
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

//Funcion que elaza al principio y carga el nodo.
//ESTO ES FORMATO COLA SIMPLE o COLA SIMPLEMENTE ENLAZADA
int Enlazar_Al_Principio_Y_Cargar(Nodo_t **ptr1erElemento,Producto_t data,Nodo_t **Nuevo_Nodo)
{
    printf("Se creara, cargara y agregara un nuevo nodo al principio de la lista\n");

    //Llamo a funcion que crea dinamicamente un nuevo nodo
    if( Allocalizar_Nuevo_Nodo(Nuevo_Nodo) == ERROR )
        return ERROR;

    //No busco ultimo nodo del final de lista ya que solo necesito el nodo inicial de la lista

    //Enlazo nodo al princpio de la lista
    (*Nuevo_Nodo)->sig = *ptr1erElemento;
    //Cargo el nuevo nodo
    (*Nuevo_Nodo)->data = data;
    //Retorno, por referencia, del puntero al nuevo nodo creado
    *ptr1erElemento= *Nuevo_Nodo;

    return EXITO;
}

void Liberar_Lista_Simplemente_Enlazada(Nodo_t **ptr1erElemento)
{
    Nodo_t *Nodo_Actual = *ptr1erElemento;

    while(*ptr1erElemento != NULL)
    {
        *ptr1erElemento = Nodo_Actual->sig;
        free(Nodo_Actual);
        Nodo_Actual = *ptr1erElemento;
    }

    return;
}

//Funcion que imprime la informacion de cada nodo de una lista simplemente enlazada siempre y cuando cada nodo tenga una variable del tipo "struct" con sus respectivos campos
void Imprimir_Campos_EstructuraInterna_Nodo(Nodo_t **ptr1erElemento)
{
    Nodo_t *Nodo_Actual = *ptr1erElemento;
    //Se imprime comenzando por el PRINCIPIO de la COLA hasta el FINAL de la misma.
    //Deberia ser al reves pero se necesita una COLA DOBLEMENTE ENLAZADA
    while(Nodo_Actual != NULL)
    {
        printf("Codigo producto: %d\n", Nodo_Actual->data.codigo_Producto);
        printf("Proveedor: %s\n", Nodo_Actual->data.proveedor);
        printf("Cantidad stock: %d\n", Nodo_Actual->data.cantidad_stock);
        Nodo_Actual = Nodo_Actual->sig;
    }

    return;
}

int CargaDeDatosDeProductosPorTeclado(Producto_t **listadoprecargado)
{
    int i = 0, codigo_de_finalizacion = 0;
    int Counter_EstructutasPreCargadas = 0;
    int Counter_NuevasEstructuras = 0;
    //Cuento la cantidad de elementos pre-cargados en el ARRAY DINAMICO DE STRUCTS tipo PILA
    for( i = 0; strcasecmp((*listadoprecargado)[i].proveedor,ULTIMOPRODUCTO) != 0 ; i++ )
        Counter_EstructutasPreCargadas++;

    Counter_NuevasEstructuras = Counter_EstructutasPreCargadas;
    printf("En funcion CargaDeDatosDeProductosPorTeclado => Counter_EstructutasPreCargadas = %d\n", Counter_EstructutasPreCargadas);
    printf("Usted va a cargar en memoria mas productos por teclado adicionandolos a los que vienen del archivo de entrada\n");

    do
    {
        printf("Desea cargar un producto?\nIngrese un numero cualquiera (SI)\nIngrese 0 (NO)\n");
        scanf("%d",&codigo_de_finalizacion);
        __fpurge(stdin);

        if( codigo_de_finalizacion != 0 )
        {
            //Pedido de memoria dinamica para re-alocalizar el ARRAY DINAMICO DE STRUCTS tipo PILA
            *listadoprecargado = (Producto_t *)reallocarray(*listadoprecargado, Counter_NuevasEstructuras + 1, sizeof(Producto_t));
            if(*listadoprecargado == NULL)
            {
                printf("Ocurrio un error en la asignacion de memoria dinamica para ampliar la lista-pre-cargada de productos\n");
                return ERROR;
            }

            //Carga de datos en el nuevo elemento allocalizado dentro del ARRAY DINAMICO DE STRUCTS tipo PILA
            printf("Ingrese el codigo del producto: ");
            scanf("%d", &(*listadoprecargado)[Counter_NuevasEstructuras].codigo_Producto);
            __fpurge(stdin);
            printf("Ingrese el nombre del proveedor: ");
            scanf("%s", (*listadoprecargado)[Counter_NuevasEstructuras].proveedor);
            __fpurge(stdin);
            printf("Ingrese la cantidad en stock: ");
            scanf("%d", &(*listadoprecargado)[Counter_NuevasEstructuras].cantidad_stock);
            __fpurge(stdin);

            Counter_NuevasEstructuras++;
        }

    }while( codigo_de_finalizacion != 0 );

    //Pido memoria para un elemento mas del array que es una estructura tipo Producto_t vacia
    *listadoprecargado = (Producto_t *)reallocarray(*listadoprecargado, Counter_NuevasEstructuras + 1, sizeof(Producto_t));
    if(*listadoprecargado == NULL)
    {
        printf("Ocurrio un error en la asignacion de memoria dinamica para ampliar la lista-pre-cargada de productos\n");
        return ERROR;
    }

    //Carga de datos en el ULTIMO elemento vacio allocalizado dentro del ARRAY DINAMICO DE STRUCTS tipo PILA
    (*listadoprecargado)[Counter_NuevasEstructuras].codigo_Producto = 0;
    strcpy( (*listadoprecargado)[Counter_NuevasEstructuras].proveedor, ULTIMOPRODUCTO);
    (*listadoprecargado)[Counter_NuevasEstructuras].cantidad_stock = 0;

    //Imprimo en pantalla el ARRAY DINAMICO DE STRUCTS RE-ALOCALIZADO tipo PILA con datos ingresados por teclado
    Mostrar_PILA_ARRAY_DINAMICO_DE_STRUCTS(Counter_NuevasEstructuras,listadoprecargado);
    printf("Se llego a la linea 297\n");

    return EXITO;
}
