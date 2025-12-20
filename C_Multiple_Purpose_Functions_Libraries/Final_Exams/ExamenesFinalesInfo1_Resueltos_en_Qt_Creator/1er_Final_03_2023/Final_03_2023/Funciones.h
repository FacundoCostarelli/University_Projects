#ifndef FUNCIONES_H
#define FUNCIONES_H

#include"stdio.h"
#include"stdio_ext.h"
#include<stdlib.h>
#include<string.h>
#define ERROR -1
#define EXITO 0
#define ULTIMOPRODUCTO "N/A"
typedef struct producto
{
    int codigo_Producto;
    char proveedor[20];
    int cantidad_stock;
}Producto_t;

typedef struct nodo
{
    Producto_t data;
    struct nodo *sig;
}Nodo_t;

int CargarProductos(const char *nombreArchivo, Producto_t **listado);
int Lista_En_Formato_Pila_Como_ARRAYDINAMICO_DE_STRUCTS(int CantidadEstructuras_FileIn,FILE *File_in,Producto_t **listado);
void Mostrar_PILA_ARRAY_DINAMICO_DE_STRUCTS(int CantidadEstructurasLeidas,Producto_t **listado);

int FiltrarProductos(const Producto_t *listado, Nodo_t **listadoFiltrado, char *proveedor);
int Lista_Simplemente_Enlazada(Nodo_t **ptr1erElemento,Producto_t data);
int Allocalizar_Nuevo_Nodo(Nodo_t **Nuevo_Nodo);
int Enlazar_Al_Principio_Y_Cargar(Nodo_t **ptr1erElemento,Producto_t data,Nodo_t **Nuevo_Nodo);
void Liberar_Lista_Simplemente_Enlazada(Nodo_t **ptr1erElemento);
void Imprimir_Campos_EstructuraInterna_Nodo(Nodo_t **ptr1erElemento);

int CargaDeDatosDeProductosPorTeclado(Producto_t **listadoprecargado);

#endif // FUNCIONES_H
