#ifndef FUNCIONES_H
#define FUNCIONES_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define EXITO 0
#define ERROR -1
#define CANTIDAD_PAQUETES 10
struct port
{
    unsigned char p0:1;
    unsigned char p1:1;
    unsigned char p2:1;
    unsigned char p3:1;
    unsigned char p4:1;
    unsigned char p5:1;
    unsigned char p6:1;
    unsigned char p7:1;
};

struct paquete
{
    unsigned char MACori[6];
    unsigned char MACdes[6];
    struct port entrada;
    struct port salida;
};

int CargaArrayConPunteros_A_Paquetes(struct paquete **ArrPackages);
int CargaDeMiembrosDeUnPaquete(struct paquete **ArrPackage);
void CargaMAC_origen(struct paquete **ArrPackage);
void CargarMAC_destino(struct paquete **ArrPackage);
void CargarPuerto_Entrada(struct paquete **ArrPackage);
void CargarPuerto_Salida(struct paquete **ArrPackage);
void ImprimirContenidoPaquete(struct paquete **ArrPackages);
void LiberarMemoriaDePaquetes(struct paquete **ArrPackages);

unsigned char aleatorio_en_rango(unsigned char minimo, unsigned char maximo);

#endif // FUNCIONES_H
