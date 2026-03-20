#ifndef FUNCIONES_H
#define FUNCIONES_H

#include<stdio.h>
#include<stdlib.h>
#define ERROR 1
#define EXITO 0

typedef struct consumo
{
    char nombreyapellido[80];
    unsigned int codigoCliente;
    float kws;
}ENERGIA;

typedef struct listado
{
    ENERGIA cliente;
    struct listado *siguiente;
}LISTAENERGIA;

//EJERCICIO 2
//Asumo que los ultimos 4 bits del codigo del cliente se refieren a los 4 bits del nibble LSB
int obtenerBarrio(unsigned int codigoCliente, unsigned int *barriocliente);
//EJERCICIO 3
int crearListado(LISTAENERGIA **listadoClientesBarrio, FILE *idEnergia, unsigned int barrio);
//FUNCION ADICIONAL PARA EJERCICO 3
int Lista_Simplemente_Enlazada_PILA(LISTAENERGIA **ptr1erElemento,ENERGIA data);
//FUNCION ADICIONAL PARA EJERCICIO 3
int Allocalizar_Nuevo_Nodo( LISTAENERGIA **Nuevo_Nodo);
//FUNCION ADICIONAL PARA EJERCICIO 3
int Enlazar_Al_Principio_Y_Cargar(LISTAENERGIA **ptr1erElemento,ENERGIA data,LISTAENERGIA **Nuevo_Nodo);
//FUNCION ADICIONAL EJERCICIO 3
void Liberar_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(LISTAENERGIA **ptr1erElemento);
//Funcion que imprime la informacion de cada nodo de una lista simplemente enlazada siempre y cuando cada nodo tenga una variable del tipo "struct" con sus respectivos campos
void Imprimir_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(LISTAENERGIA **ptr1erElemento);
//EJERCICIO 4
int buscarRegistro(FILE *idEnergia,ENERGIA *cliente);
#endif // FUNCIONES_H
