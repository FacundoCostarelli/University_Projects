#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define ERROR 0
#define EXITO 1

#define DEST_01 0x0001
#define DEST_02 0x0002
#define DEST_03 0x0003
#define DEST_04 0x0004
#define DEST_05 0x0005
#define DEST_06 0x0006
#define DEST_07 0x0007

typedef unsigned int uint32_t;

typedef struct dato
{
    uint32_t informacion1;
    uint32_t informacion2;
    uint32_t masinformacion;
    /*
     *
     *
     *
     */
}data_t;

typedef struct nodo
{
    data_t data;
    uint32_t dest;
    struct nodo *sig;
}Nodo_t;

int init(Nodo_t **ptr1erElemento,Nodo_t **ptrAux,const data_t *pdat, uint32_t dest);
int Allocalizar_Nuevo_Nodo( Nodo_t **Nuevo_Nodo);
int pushMulti(Nodo_t **ptr1erElemento,Nodo_t **ptrAux,Nodo_t **Nuevo_Nodo,const data_t *pdat,uint32_t dest);
int popDest(Nodo_t **ptr1erElemento,Nodo_t **ptrAux, data_t *pdat , uint32_t dest);
void Liberar_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(Nodo_t **ptr1erElemento);


#endif // FUNCIONES_H
