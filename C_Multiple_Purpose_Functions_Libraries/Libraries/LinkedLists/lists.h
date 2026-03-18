#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>




typedef struct producto
{
    int codigo_Producto;
    char proveedor[20];
    int cantidad_stock;
}Producto_t;

//Estructura V1
typedef struct nodo
{
    Producto_t data;
    Nodo_t *sig;
}Nodo_t;

//Estructura V2
typedef struct nodo
{
    void *data;
    Nodo_t *sig;
}Nodo_t;


//Funciones para una Lista Simplemente Enlazada V1
void Lista_Simplemente_Enlazada_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data);
void Enlazar_Al_Final_Y_Cargar_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data,Nodo_t **Nuevo_Nodo);
void Enlazar_Al_Principio_Y_Cargar_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data,Nodo_t **Nuevo_Nodo);
void Enlazar_En_El_Medio_Y_Cargar_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data,Nodo_t **Nuevo_Nodo,int PosNodoIzq, int PosNodoDer);
void Imprimir_Campos_EstructuraInterna_NodoV1(Nodo_t **ptr1erElemento);
void BorrarNodo(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,//parametros de filtrado para borrar)


//Funciones para una Lista Simplemente Enlazada V2
void Crear_Cargar_Enlazar_Nodo_V2(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,void *nueva_data, size_t tam_data);
void Imprimir_Campos_EstructuraInterna_NodoV2(Nodo_t **ptr1erElemento);

//Funcion compartida por las funciones anteriores tanto V1 como V2
void Allocalizar_Nuevo_Nodo(Nodo_t **Nuevo_Nodo);
