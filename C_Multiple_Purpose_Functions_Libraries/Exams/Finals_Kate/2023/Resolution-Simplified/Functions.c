/**
 * @file    Funciones.c
 * @brief   [ESP] Archivo fuente de funciones. (Resolución Simplificada). Final 2023.
 *          [ENG] Main logic source file. (Simplified resolution). Final 2023.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Abre un archivo, carga los datos en un buffer dinamico
 *        [ENG] Opens a file, loads the data into a dynamic buffer
 *
 * @param nombreArchivo [ESP] Cadena al archivo / [ENG] Path to file string
 * @param listado [ESP] Doble puntero a array en heap / [ENG] Dynamic double ptr array
 */
int CargarProductos(const char *nombreArchivo, Producto_t **listado)
{
    int CantidadEstructuras_FileIn, CantidadEstructurasLeidas;
    FILE *File_in = NULL;
    long tamanio_archivo;

    File_in = fopen(nombreArchivo, "r");
    if(File_in == NULL)
    {
        printf("Error en la apertura del archivo de entrada\n");
        return -1;
    }

    fseek(File_in, 0, SEEK_END);
    tamanio_archivo = ftell(File_in);
    
    CantidadEstructuras_FileIn = (((int)tamanio_archivo) / ((int)sizeof(Producto_t)));
    printf("La cantidad de estructuras tipo Producto_t son: %d\n", CantidadEstructuras_FileIn);
    
    fseek(File_in, 0, SEEK_SET);

    CantidadEstructurasLeidas = Lista_En_Formato_Pila_Como_ARRAYDINAMICO_DE_STRUCTS(CantidadEstructuras_FileIn, File_in, listado);
    fclose(File_in);
    Mostrar_PILA_ARRAY_DINAMICO_DE_STRUCTS(CantidadEstructurasLeidas, listado);

    return CantidadEstructurasLeidas;
}

/**
 * @brief [ESP] Crea array dinámica LIFO para volcar las locaciones
 *        [ENG] Generates LIFO dynamic array passing elements from binary
 */
int Lista_En_Formato_Pila_Como_ARRAYDINAMICO_DE_STRUCTS(int CantidadEstructuras_FileIn, FILE *File_in, Producto_t **listado)
{
    size_t CantItemsLeidos;
    int i;

    if(*listado == NULL)
    {
        printf("La lista esta vacia. Se crearan e insertaran los elementos siguiendo un formato PILA\n");

        *listado = (Producto_t *)malloc((CantidadEstructuras_FileIn + 1) * sizeof(Producto_t));
        if(*listado == NULL)
        {
            printf("Hubo un problema con la asignacion de memoria dinamica para el 1er elemento del ARRAY DE STRUCTS\n");
            return ERROR;
        }

        for( i = 0; i < CantidadEstructuras_FileIn; i++ )
        {
            CantItemsLeidos = fread((*listado) + i, sizeof(Producto_t), 1, File_in);
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
    else
    {
        printf("La lista ya esta cargada. No hay nada que agregar\n");
        return ERROR;
    }
}

/**
 * @brief [ESP] Mostrar la pila 
 *        [ENG] Print the LIFO stack
 */
void Mostrar_PILA_ARRAY_DINAMICO_DE_STRUCTS(int CantidadEstructurasLeidas, Producto_t **listado)
{
    int i;
    for(i = CantidadEstructurasLeidas - 1; i >= 0; i--)
    {
        printf("Codigo Producto: %d\n", (*listado)[i].codigo_Producto);
        printf("Proveedor: %s\n",(*listado)[i].proveedor);
        printf("Cantidad de Stock: %d\n", (*listado)[i].cantidad_stock);
    }
}

/**
 * @brief [ESP] Filtra según proveedor comparando el array y guardando en SL.
 *        [ENG] Filter through dynamic array matching supplier and populating SL.
 */
int FiltrarProductos(const Producto_t *listado, Nodo_t **listadoFiltrado, char *proveedor)
{
    int i = 0;
    int Estructuras_ARRAY_DINAMICO_COUNTER = 0;
    int Productos_Filtrados_Counter = 0;

    for( i = 0; strcasecmp(listado[i].proveedor, ULTIMOPRODUCTO) != 0 ; i++ )
        Estructuras_ARRAY_DINAMICO_COUNTER++;

    printf("En funcion FiltraProductos Estructuras_ARRAY_DINAMICO_COUNTER = %d\n", Estructuras_ARRAY_DINAMICO_COUNTER);

    for( i = Estructuras_ARRAY_DINAMICO_COUNTER - 1; i >= 0; i-- )
    {
        if( strcasecmp(proveedor, listado[i].proveedor) == 0 )
        {
            if( Lista_Simplemente_Enlazada(listadoFiltrado, listado[i]) == ERROR )
                return ERROR;

            Productos_Filtrados_Counter++;
        }
    }

    return Productos_Filtrados_Counter;
}

/**
 * @brief [ESP] Carga producto y encola en Linked List Single.
 *        [ENG] Linked List Enqueue execution.
 */
int Lista_Simplemente_Enlazada(Nodo_t **ptr1erElemento, Producto_t data)
{
    Nodo_t *Nuevo_Nodo = NULL;

    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");

        if (Allocalizar_Nuevo_Nodo(&Nuevo_Nodo) == ERROR)
            return ERROR;

        Nuevo_Nodo->data = data;
        Nuevo_Nodo->sig = NULL;

        *ptr1erElemento = Nuevo_Nodo;
    }
    else
    {
        if (Enlazar_Al_Principio_Y_Cargar(ptr1erElemento, data, &Nuevo_Nodo) == ERROR)
            return ERROR;
    }

    return EXITO;
}

/**
 * @brief [ESP] Asignación de memoria.
 *        [ENG] Handle mallocs node.
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
        printf("Se creo exitosamente y dinamicamente un nuevo nodo\n");

    return EXITO;
}

/**
 * @brief [ESP] Enzar elementos al principio de the COLA
 *        [ENG] Linking element to queue start.
 */
int Enlazar_Al_Principio_Y_Cargar(Nodo_t **ptr1erElemento, Producto_t data, Nodo_t **Nuevo_Nodo)
{
    printf("Se creara, cargara y agregara un nuevo nodo al principio de la lista\n");

    if( Allocalizar_Nuevo_Nodo(Nuevo_Nodo) == ERROR )
        return ERROR;

    (*Nuevo_Nodo)->sig = *ptr1erElemento;
    (*Nuevo_Nodo)->data = data;
    *ptr1erElemento = *Nuevo_Nodo;

    return EXITO;
}

/**
 * @brief [ESP] Release simple list.
 *        [ENG] Libera nodos.
 */
void Liberar_Lista_Simplemente_Enlazada(Nodo_t **ptr1erElemento)
{
    Nodo_t *Nodo_Actual = *ptr1erElemento;

    while(*ptr1erElemento != NULL)
    {
        *ptr1erElemento = Nodo_Actual->sig;
        free(Nodo_Actual);
        Nodo_Actual = *ptr1erElemento;
    }
}

/**
 * @brief [ESP] Iterate and visualizer fields of each Node
 *        [ENG] Print out list details.
 */
void Imprimir_Campos_EstructuraInterna_Nodo(Nodo_t **ptr1erElemento)
{
    Nodo_t *Nodo_Actual = *ptr1erElemento;
    while(Nodo_Actual != NULL)
    {
        printf("Codigo producto: %d\n", Nodo_Actual->data.codigo_Producto);
        printf("Proveedor: %s\n", Nodo_Actual->data.proveedor);
        printf("Cantidad stock: %d\n", Nodo_Actual->data.cantidad_stock);
        Nodo_Actual = Nodo_Actual->sig;
    }
}

/**
 * @brief [ESP] Pide imput por cmdline usando variables de C estándar
 *        [ENG] Handles stdin scanning for allocating data entries dynamically
 */
int CargaDeDatosDeProductosPorTeclado(Producto_t **listadoprecargado)
{
    int i = 0, codigo_de_finalizacion = 0;
    int Counter_EstructutasPreCargadas = 0;
    int Counter_NuevasEstructuras = 0;
    
    for( i = 0; strcasecmp((*listadoprecargado)[i].proveedor, ULTIMOPRODUCTO) != 0 ; i++ )
        Counter_EstructutasPreCargadas++;

    Counter_NuevasEstructuras = Counter_EstructutasPreCargadas;
    printf("En funcion CargaDeDatosDeProductosPorTeclado => Counter_EstructutasPreCargadas = %d\n", Counter_EstructutasPreCargadas);
    printf("Usted va a cargar en memoria mas productos por teclado adicionandolos a los que vienen del archivo de entrada\n");

    do
    {
        printf("Desea cargar un producto?\nIngrese un numero cualquiera (SI)\nIngrese 0 (NO)\n");
        scanf("%d", &codigo_de_finalizacion);
        __fpurge(stdin);

        if( codigo_de_finalizacion != 0 )
        {
            *listadoprecargado = (Producto_t *)reallocarray(*listadoprecargado, Counter_NuevasEstructuras + 1, sizeof(Producto_t));
            if(*listadoprecargado == NULL)
            {
                printf("Ocurrio un error en la asignacion de memoria dinamica para ampliar la lista-pre-cargada de productos\n");
                return ERROR;
            }

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

    } while( codigo_de_finalizacion != 0 );

    *listadoprecargado = (Producto_t *)reallocarray(*listadoprecargado, Counter_NuevasEstructuras + 1, sizeof(Producto_t));
    if(*listadoprecargado == NULL)
    {
        printf("Ocurrio un error en la asignacion de memoria dinamica para ampliar la lista-pre-cargada de productos\n");
        return ERROR;
    }

    (*listadoprecargado)[Counter_NuevasEstructuras].codigo_Producto = 0;
    strcpy( (*listadoprecargado)[Counter_NuevasEstructuras].proveedor, ULTIMOPRODUCTO);
    (*listadoprecargado)[Counter_NuevasEstructuras].cantidad_stock = 0;

    Mostrar_PILA_ARRAY_DINAMICO_DE_STRUCTS(Counter_NuevasEstructuras, listadoprecargado);
    printf("Se llego a la linea 297\n");

    return EXITO;
}
