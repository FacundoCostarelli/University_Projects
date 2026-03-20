/**
 * @file    Ej-PracticoVF.c
 * @brief   [ESP] Ejercicio práctico VF - Final 2023. Archivos y linked lists. (Complejizado).
 *          [ENG] Practical Exercise VF - Final 2023. Files and linked lists. (Complex).
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief [ESP] Estructura de producto.
 *        [ENG] Product structure.
 */
typedef struct producto
{
    int codigo_Producto;
    char proveedor[20];
    int cantidad_stock;
} Producto_t;

/**
 * @brief [ESP] Nodo para lista simple de Producto_t.
 *        [ENG] Node for simple list of Producto_t.
 */
typedef struct nodo
{
    Producto_t p;
    struct nodo *sig;
} Nodo_t;

/* [ESP] Prototipos de funciones / [ENG] Function prototypes */
int CargarProductos(const char *nombreArchivo, Producto_t ***listado);
void MostrarListado(Producto_t **listado);
int FiltrarProductos(Producto_t **listado, Nodo_t **listadoFiltrado, char *Proveedor);
int InsertarNodo_SL(const Producto_t *dato, Nodo_t **pINI, Nodo_t **pFIN);
void ExtraerNodo_SL(Nodo_t **pINI, Nodo_t **pFIN);
void MostrarNodos_SL(Nodo_t **pINI);
void LiberarNodos_SL(Nodo_t **pINI);

/**
 * @brief [ESP] Función principal (complejizada).
 *        [ENG] Main function (complex).
 */
int main(int argc, char **argv)
{
    Producto_t **listado = NULL;
    Nodo_t *listadoFiltrado = NULL;
    int CantidadEstructurasLeidas;
    int Codigo_CargaDatosProveedor = 1;
    int i = 0;
    int check;
    size_t len;

    if(argc != 3) {
        printf("Cantidad incorrecta de argumentos. Reingrese siguiendo la referencia: <nombre_ejecutable.out> <nombre_archivo.bin> <nombre_proveedor>");
        return -1;
    }

    check = CargarProductos(argv[1], &listado);
    if(check == -1) {
        printf("Hubo un problema con la funcion CargarProducto\n");
        return -1;
    } else {
        CantidadEstructurasLeidas = check;
        printf("La cantidad de estructuras leidas son: %d\n", CantidadEstructurasLeidas);
    }

    i = CantidadEstructurasLeidas - 2;
    MostrarListado(listado);
    
    while( i >= 0 )
    {
        printf("En base al archivo de entrada, entonces la informacion ACTUAL de la estrcutura #%d es:\n", i);
        printf("Codigo de producto: %d\n", (*((listado)+i))->codigo_Producto );
        printf("Nombre de proveedor: %s\n", ((*((listado)+i))->proveedor) );
        printf("Cantidad en stock: %d\n", ((*((listado)+i))->cantidad_stock) );
        printf("Desea realizar modificaciones en la estructura #%d mostrada recientemente???. \nEn caso de que SI, ingrese 1\nEn caso de que NO, ingrese 0\nOpcion: ", i);
        scanf("%d", &Codigo_CargaDatosProveedor);
        __fpurge(stdin);

        if(Codigo_CargaDatosProveedor == 1)
        {
            printf("Ingrese el codigo de producto: ");
            scanf("%d", &((*((listado)+i))->codigo_Producto) );
            __fpurge(stdin);

            printf("Ingrese el nombre del proveedor: ");
            if(fgets((*((listado)+i))->proveedor, 20, stdin) != NULL)
            {
                len = strlen((*((listado)+i))->proveedor);
                if(len > 0 && (*((listado)+i))->proveedor[len-1] == '\n')
                    (*((listado)+i))->proveedor[len-1] =  '\0';
            }
            else
            {
                printf("Hubo un error con la lectura de fgets desde el teclado\n");
                return -1;
            }

            printf("Ingrese la cantidad en stock: ");
            scanf("%d", &((*((listado)+i))->cantidad_stock));
            __fpurge(stdin);
        }
        i--;
    }

    printf("La lista luego de la modificacion de datos queda como: \n");
    MostrarListado(listado);

    check = FiltrarProductos(listado, &listadoFiltrado, argv[2]);
    if(check == -1) {
        printf("Error con la funcion FiltrarProductos\n");
        return check;
    } else {
        printf("La cantidad de productos filtrados segun el nombre del proveedor es: %d\n", check);
    }

    return 0;
}

/**
 * @brief [ESP] Carga listado de productos usando realloc.
 *        [ENG] Loads products list using realloc.
 */
int CargarProductos(const char *nombreArchivo, Producto_t ***listado)
{
    int CantidadEstructuras_FileIn, i = 0, CantidadEstructurasLeidas;
    FILE *File_in = NULL;
    long tamanio_archivo;
    size_t CantItemsLeidos;

    File_in = fopen(nombreArchivo, "r");
    if(File_in == NULL) return (-1);

    fseek(File_in, 0, SEEK_END);
    tamanio_archivo = ftell(File_in);
    CantidadEstructuras_FileIn = ((int)tamanio_archivo) / ((int)sizeof(Producto_t));
    fseek(File_in, 0, SEEK_SET);

    if(*listado == NULL)
    {
        *listado = (Producto_t **)malloc(sizeof(Producto_t *));
        (*listado)[0] = (Producto_t *)malloc(sizeof(Producto_t));
        fread((*listado)[i], sizeof(Producto_t), 1, File_in);

        for( i = 1; i < CantidadEstructuras_FileIn; i++ )
        {
            *listado = (Producto_t **)reallocarray(*listado, (i+1), sizeof(Producto_t *));
            if(*listado == NULL) return (-1);

            (*listado)[i] = (Producto_t *)malloc(sizeof(Producto_t));
            if((*listado)[i] == NULL) return (-1);

            CantItemsLeidos = fread((*listado)[i], sizeof(Producto_t), 1, File_in);
            if(CantItemsLeidos < 1) return (-1);
        }
        *listado = (Producto_t **)reallocarray(*listado, (i+1), sizeof(Producto_t *));
        if(*listado == NULL) return (-1);
        (*listado)[i] = NULL;
    }
    else
    {
        return (-1);
    }

    fclose(File_in);
    CantidadEstructurasLeidas = i + 1;
    return CantidadEstructurasLeidas;
}

/**
 * @brief [ESP] Muestra el listado entero de memoria.
 *        [ENG] Displays the whole memory list.
 */
void MostrarListado(Producto_t **listado)
{
    int i = 0;
    while(listado[i] != NULL)
    {
        printf("Estructura #%d posee la info: \n", i);
        printf("Codigo Producto: %d\n", (listado[i])->codigo_Producto);
        printf("Nombre Proveedor: %s\n", (listado[i])->proveedor);
        printf("Cantidad de stock: %d\n", (listado[i])->cantidad_stock );
        i++;
    }
}

/**
 * @brief [ESP] Filtra productos usando memoria tipo pila a una SL cola.
 *        [ENG] Filters products from stack array to SL queue handling memory.
 */
int FiltrarProductos(Producto_t **listado, Nodo_t **listadoFiltrado, char *Proveedor)
{
    Nodo_t *pINI = *listadoFiltrado;
    Nodo_t *pFIN = NULL;
    int check;
    int CantidadProductosProveedor = 0;
    int i = 0;

    while(listado[i] != NULL) i++;

    while( i > 0 )
    {
        if(strcasecmp( (listado[i-1])->proveedor, Proveedor ) == 0 )
        {
            check = InsertarNodo_SL(listado[i-1], &pINI, &pFIN);
            if(check == -1) return check;
            CantidadProductosProveedor++;
        }
        free(listado[i-1]);
        listado[i-1] = NULL;
        i--;
    }
    MostrarNodos_SL(&pINI);
    LiberarNodos_SL(&pINI);

    return CantidadProductosProveedor;
}

/**
 * @brief [ESP] Inserta nodo en una cola Lista Simplemente Enlazada SL.
 *        [ENG] Inserts node in a Simple Linked List queue SL.
 */
int InsertarNodo_SL(const Producto_t *dato, Nodo_t **pINI, Nodo_t **pFIN)
{
    Nodo_t *paux = NULL;
    Nodo_t *paux2 = NULL;
    if(*pINI == NULL)
    {
        *pINI = (Nodo_t *)malloc(sizeof(Nodo_t));
        if(*pINI == NULL) return -1;
        *pFIN = *pINI;
        (*pINI)->sig = NULL;
        (*pINI)->p = *dato;
    }
    else
    {
        paux = (Nodo_t *)malloc(sizeof(Nodo_t));
        if(paux == NULL) return -1;
        paux2 = *pINI;
        while(paux2->sig != NULL)
            paux2 = paux2->sig;
        paux2->sig = paux;
        paux->sig = NULL;
        paux->p = *dato;
        *pFIN = paux;
    }
    return 0;
}

/**
 * @brief [ESP] Extrae el primer nodo (FIFO). 
 *        [ENG] Extracts first node (FIFO).
 */
void ExtraerNodo_SL(Nodo_t **pINI, Nodo_t **pFIN)
{
    Nodo_t *paux = NULL;
    if(*pINI != NULL)
    {
        paux = *pINI;
        *pINI = (*pINI)->sig;
        paux->sig = NULL;

        printf("Codigo Producto: %d\n", paux->p.codigo_Producto);
        printf("Nombre Proveedor: %s\n", paux->p.proveedor);
        printf("Cantidad de stock: %d\n", paux->p.cantidad_stock);

        free(paux);
    }
}

/**
 * @brief [ESP] Muestra nodos. 
 *        [ENG] Shows nodes.
 */
void MostrarNodos_SL(Nodo_t **pINI)
{
    Nodo_t *paux = *pINI;
    int i = 0;
    while(paux != NULL)
    {
        printf("La informacion del nodo #%d:\n", i);
        printf("Codigo Producto: %d\n", paux->p.codigo_Producto);
        printf("Nombre Proveedor: %s\n", paux->p.proveedor);
        printf("Cantidad de stock: %d\n", paux->p.cantidad_stock);
        i++;
        paux = paux->sig;
    }
}

/**
 * @brief [ESP] Libera los nodos restantes. 
 *        [ENG] Free remaining nodes.
 */
void LiberarNodos_SL(Nodo_t **pINI)
{
    Nodo_t *paux = *pINI;
    while(paux != NULL)
    {
        *pINI = (*pINI)->sig;
        free(paux);
        paux = *pINI;
    }
}
