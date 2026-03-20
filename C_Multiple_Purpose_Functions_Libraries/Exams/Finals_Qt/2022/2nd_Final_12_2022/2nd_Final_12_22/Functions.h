/**
 * @file    Funciones.h
 * @brief   [ESP] Cabecera para estructuras y funciones lógicas de ruteo en red. Final 12/2022.
 *          [ENG] Header for networking routing logic structs and functions. Final 12/2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief [ESP] Constantes de error y cantidad en paquetes simulados.
 *        [ENG] Error constants and mocked packets threshold.
 */
#define EXITO 0
#define ERROR -1
#define CANTIDAD_PAQUETES 10

/**
 * @brief [ESP] Estructura de puerto bit a bit.
 *        [ENG] Bit-by-bit port states structure.
 */
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

/**
 * @brief [ESP] Representación de un paquete de red y puertos de flujo.
 *        [ENG] Representation of a network packet along with flow ports.
 */
struct paquete
{
    unsigned char MACori[6];
    unsigned char MACdes[6];
    struct port entrada;
    struct port salida;
};

/* [ESP] Prototipos de funciones / [ENG] Function prototypes */
int CargaArrayConPunteros_A_Paquetes(struct paquete **ArrPackages);
int CargaDeMiembrosDeUnPaquete(struct paquete **ArrPackage);
void CargaMAC_origen(struct paquete **ArrPackage);
void CargarMAC_destino(struct paquete **ArrPackage);
void CargarPuerto_Entrada(struct paquete **ArrPackage);
void CargarPuerto_Salida(struct paquete **ArrPackage);
void ImprimirContenidoPaquete(struct paquete **ArrPackages);
void LiberarMemoriaDePaquetes(struct paquete **ArrPackages);
unsigned char aleatorio_en_rango(unsigned char minimo, unsigned char maximo);

#endif /* FUNCIONES_H */
