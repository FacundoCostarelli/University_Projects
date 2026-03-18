#ifndef FUNCIONES_H
#define FUNCIONES_H

#define ON 1
#define OFF 0
#define ERROR 1
#define EXITO 0
#include <stdio.h>
#include <stdio_ext.h>
#include<stdlib.h>

//Esta estructura corresponde a la informacion de un nodo que pertenece a una lista dinamica enlazada
typedef struct consumo
{
    char nombreyapellido[80];
    unsigned int codigoCliente;
    float kws;
}ENERGIA;

//Esta estructura corresponde a la de un "nodo" de una lista dinamica enlazada
typedef struct listado
{
    ENERGIA cliente;
    struct listado *sig;//Cambio "siguiente" por "sig" para mayor comodidad
}LISTAENERGIA;


int obtenerBariio(unsigned int codigoCliente, unsigned int *barrioCliente);
int crearListado(LISTAENERGIA **listadoClientesBarrio, LISTAENERGIA **ptrAux, FILE *idEnergia, unsigned int barrio);
int Lista_Simplemente_Enlazada_PILA(LISTAENERGIA **ptr1erElemento,ENERGIA data);
int Lista_Simplemente_Enlazada_COLA(LISTAENERGIA **ptr1erElemento,LISTAENERGIA **ptrAux,ENERGIA data);
int Allocalizar_Nuevo_Nodo(LISTAENERGIA **Nuevo_Nodo);
int Enlazar_Al_Principio_Y_Cargar(LISTAENERGIA **ptr1erElemento,ENERGIA data,LISTAENERGIA **Nuevo_Nodo);
int Enlazar_Al_Final_Y_Cargar(LISTAENERGIA **ptr1erElemento,LISTAENERGIA **ptrAux,ENERGIA data,LISTAENERGIA**Nuevo_Nodo);
void Liberar_Lista_Simplemente_Enlazada_PILA_O_COLA(LISTAENERGIA **ptr1erElemento);
void Imprimir_Lista_Simplemente_Enlazada_PILA_O_COLA(LISTAENERGIA **ptr1erElemento);
void PrintBits( unsigned int dato, char nro_de_bit );
unsigned char GetBit(unsigned int dato, char bit);
unsigned int SetBit( unsigned int dato, char bit, char estado );
unsigned int SetToggle( unsigned int dato, char bit );


#endif // FUNCIONES_H
