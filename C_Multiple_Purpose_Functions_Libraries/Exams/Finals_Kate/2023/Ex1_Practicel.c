/**
 * @file    Ej1-Practico.c
 * @brief   [ESP] Ejercicio práctico 1 - Final 2023. Listas y estructuras.
 *          [ENG] Practical Exercise 1 - Final 2023. Lists and structures.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

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
 * @brief [ESP] Estructura de nodo simple para producto.
 *        [ENG] Simple node structure for a product.
 */
typedef struct nodo
{
    Producto_t data;
    struct nodo *sig;
} Nodo_t;

/**
 * @brief [ESP] Estructura auxiliar de producto.
 *        [ENG] Product auxiliary structure.
 */
typedef struct producto_auxiliar
{
    int codigo_Producto;
    char proveedor[20];
    int cantidad_stock;
} Producto_t_aux;

/* [ESP] Prototipos de funciones / [ENG] Function prototypes */
int Cargar_Productos(const char *nombreArchivo, Producto_t **listado);
void Crear_Cargar_Enlazar_Nodo_V1(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, Producto_t data);
void Imprimir_Campos_EstructuraInterna_NodoV1(Nodo_t **ptr1erElemento);
void Crear_Cargar_Enlazar_Nodo_V2(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, void *nueva_data, size_t tam_data);
void Imprimir_Campos_EstructuraInterna_NodoV2(Nodo_t **ptr1erElemento);
int FiltrarProductos(const Producto_t *listado, Nodo_t **listadoFiltrado, char *proveedor);

/**
 * @brief [ESP] Función principal del programa.
 *        [ENG] Main function of the program.
 * 
 * @param argc [ESP] Número de argumentos / [ENG] Number of arguments
 * @param argv [ESP] Array de argumentos / [ENG] Arguments array
 * @return 0 [ESP] Ejecución exitosa / [ENG] Successful execution
 */
int main(int argc, char **argv)
{
    int check;
    FILE *File_out = NULL;
    Producto_t *listado = NULL;
    Nodo_t *ptr1erElemento = NULL;
    Nodo_t *Nodo_Actual = NULL;
    
    /* [ESP] Verificacion contra cantidad insuficiente de argumentos / [ENG] Argument verification */
    if(argc < 3)
    {
        printf("Faltan comandos. Re-ingrese como: <nombre_ejecutable.out> <nombre_archivo.dat/.bin> <nombre_proveedor_a_filtrar>\n");
        return (-1);
    }
    
    /* [ESP] Apertura de arhcivo de salida y verificacion de error / [ENG] Output file opening and error verification */
    File_out = fopen("listafiltrada.bin", "wb");
    if(File_out == NULL)
    {
        printf("Error en la apertura del archivo de salida\n");
        return (-1);
    }

    check = Cargar_Productos(argv[1], &listado);
    if(check == -1)
    {
        printf("Hubo un problema con la funcion Cargar_Productos\n");
        return (check);
    }
    else
        printf("La cantidad de estructuras leidas del archivo de entrada fueron: %d\n", check);

    /* 
    check = FiltrarProductos(listado, &listadoFiltrado, argv[2]);
    if(check == -1)
    {
        printf("Hubo un problema con la funcion FiltrarProductos()\n");
        return (check);
    }
    else
        printf("La cantidad de productos del proveedor es: %d\n", check);
    */

    if (File_out) fclose(File_out);

    return 0;
}


/**
 * @brief [ESP] Carga productos desde un archivo hacia memoria dinámica.
 *        [ENG] Loads products from file into dynamic memory.
 * 
 * @param nombreArchivo [ESP] Nombre del archivo de entrada / [ENG] Input file name
 * @param listado [ESP] Doble puntero a array dinámico / [ENG] Double pointer to dynamic array
 * @return int [ESP] Cantidad de estructuras / [ENG] Structures amount
 */
int Cargar_Productos(const char *nombreArchivo, Producto_t **listado)
{
    FILE *File_in = NULL;
    long tamanio_archivo;
    int cant_estructuras, i;
    int porciones_bytes_leidos;
    
    /* [ESP] Apertura archivo de entrada / [ENG] Open input file */
    File_in = fopen(nombreArchivo,"rb");
    if(File_in == NULL)
    {
        printf("Error en apertura de archivo de entrada\n");
        return(-1);
    }

    fseek(File_in, 0, SEEK_END);
    tamanio_archivo = ftell(File_in);
    fseek(File_in, 0, SEEK_SET);

    cant_estructuras = tamanio_archivo / sizeof(Producto_t);

    *listado = (Producto_t *)malloc(sizeof(Producto_t) * cant_estructuras);
    if(*listado == NULL)
    {
        printf("Error en apertura de archivo de entrada\n"); // typo in original code left intact
        return(-1);
    }
    for( i = 0; i < cant_estructuras; i ++ )
    {
        porciones_bytes_leidos = fread((*listado) + i, sizeof(Producto_t), 1, File_in);
        if(porciones_bytes_leidos < 1)
        {
            printf("Hubo un error con la lectura de estructuras tipo Producto_t desde el arhcivo de entrada hacia la memoria\n");
            return (-1);
        }
    }

    if (File_in) fclose(File_in);
    return cant_estructuras;
}

/**
 * @brief [ESP] Filtra productos en un listado y crea nueva cola.
 *        [ENG] Filters products on a list and creates a queue.
 */
int FiltrarProductos(const Producto_t *listado, Nodo_t **listadoFiltrado, char *proveedor)
{
    int cant_productos = 0;
    return cant_productos;
}

/**
 * @brief [ESP] Crea y enlaza nodo pasando la estuctura V1. 
 *        [ENG] Creates and links a node passing V1 struct.
 */
void Crear_Cargar_Enlazar_Nodo_V1(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, Producto_t data)
{
    Nodo_t *Nuevo_Nodo = NULL;

    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");
        Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
        if(Nuevo_Nodo == NULL)
        {
            printf("Hubo un error con la creacion y asignacion de memoria dinamica para el 1er nodo\n");
            exit(-1);
        }
        Nuevo_Nodo->data = data;
        Nuevo_Nodo->sig = NULL;

        *Nodo_Actual = Nuevo_Nodo;
        *ptr1erElemento = Nuevo_Nodo;
    }
    else {
        printf("Se creara, cargara y agregara un nuevo nodo a la lista\n");
        Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
        if(Nuevo_Nodo == NULL)
        {
            printf("Hubo un error con la creacion y asignacion de memoria dinamica para un nuevo nodo\n");
            exit(-1);
        }
        Nuevo_Nodo->data = data;
        Nuevo_Nodo->sig = *ptr1erElemento;
        *Nodo_Actual = Nuevo_Nodo;
        *ptr1erElemento = Nuevo_Nodo;
    }
    return;
}

/**
 * @brief [ESP] Crea y enlaza nodo pasando puntero genérico V2. 
 *        [ENG] Creates and links a node passing generic void* V2.
 */
void Crear_Cargar_Enlazar_Nodo_V2(Nodo_t **ptr1erElemento, Nodo_t **Nodo_Actual, void *nueva_data, size_t tam_data)
{
    /* [ESP] Incompleto/Deshabilitado visualmente, requiere cast adecuaciones en C std y un struct Node que no incluya Producto_t / [ENG] Disabled and requires further refactoring */
    return;
}

void Imprimir_Campos_EstructuraInterna_NodoV1(Nodo_t **ptr1erElemento)
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

void Imprimir_Campos_EstructuraInterna_NodoV2(Nodo_t **ptr1erElemento)
{
    /* [ESP] V2 pointer no usa Producto_t si usamos void data. Se deja de igual manera / [ENG] V2 unused. Leaves it same */
    return;
}
