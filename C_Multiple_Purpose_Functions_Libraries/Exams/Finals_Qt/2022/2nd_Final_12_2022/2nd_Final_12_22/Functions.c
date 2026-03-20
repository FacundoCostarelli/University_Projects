/**
 * @file    Funciones.c
 * @brief   [ESP] Archivo fuente de resolución simulación de ruteo/switcheo. Final 12/2022.
 *          [ENG] Network routing/switching simulation resolution source code. Final 12/2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Carga el arreglo de paquetes dimensionados dinámicamente.
 *        [ENG] Loads dynamically allocated arrays of mocked packages.
 */
int CargaArrayConPunteros_A_Paquetes(struct paquete **ArrPackages)
{
    int i = 0;
    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        ArrPackages[i] = (struct paquete *)malloc(CANTIDAD_PAQUETES * sizeof(struct paquete));
        if(ArrPackages[i] == NULL)
        {
            printf("Error en la asignacion de memoria dinamcia para cada puntero struct paquete * que se encuentra en el array de punteros\n");
            return ERROR;
        }
    }
    return EXITO;
}

/**
 * @brief [ESP] Función ensambladora de carga para MACs y Puertos para rellenar los paquetes.
 *        [ENG] Setup wrapper allocating MAC domains and bound ports for incoming packages.
 */
int CargaDeMiembrosDeUnPaquete(struct paquete **ArrPackage)
{
    CargaMAC_origen(ArrPackage);
    CargarMAC_destino(ArrPackage);
    CargarPuerto_Entrada(ArrPackage);
    CargarPuerto_Salida(ArrPackage);

    return EXITO;
}

/**
 * @brief [ESP] Escribe valores pseudo-aleatorios (letras/números) simulando direcciones MAC de origen.
 *        [ENG] Writes pseudo-randomized (chars/numbers) payload simulating source MAC addresses.
 */
void CargaMAC_origen(struct paquete **ArrPackage)
{
    int i = 0;
    int j = 0;
    unsigned char select = 0;

    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        for( j = 0; j < 6; j++ )
        {
            select = aleatorio_en_rango('0', '1');
            if( select == '0' )
                ArrPackage[i]->MACori[j] = aleatorio_en_rango('0', '9');
            else if( select == '1' )
                ArrPackage[i]->MACori[j] = aleatorio_en_rango('A', 'Z');
        }
    }
}

/**
 * @brief [ESP] Escribe valores pseudo-aleatorios (letras/números) simulando direcciones MAC de destino.
 *        [ENG] Writes pseudo-randomized (chars/numbers) payload simulating destination MAC addresses.
 */
void CargarMAC_destino(struct paquete **ArrPackage)
{
    int i = 0;
    int j = 0;
    unsigned char select = 0;

    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        for( j = 0; j < 6; j++ )
        {
            select = aleatorio_en_rango('0', '1');
            if( select == '0' )
                ArrPackage[i]->MACdes[j] = aleatorio_en_rango('0', '9');
            else if( select == '1' )
                ArrPackage[i]->MACdes[j] = aleatorio_en_rango('A', 'Z');
        }
    }
}

/**
 * @brief [ESP] Inicializa aleatoriamente bitfields de entrada (canal de recepción).
 *        [ENG] Flips pseudo-randomizing logic over reception (incoming) bitfields.
 */
void CargarPuerto_Entrada(struct paquete **ArrPackage)
{
    int i = 0;
    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        ArrPackage[i]->entrada.p0 = rand() % 2;
        ArrPackage[i]->entrada.p1 = rand() % 2;
        ArrPackage[i]->entrada.p2 = rand() % 2;
        ArrPackage[i]->entrada.p3 = rand() % 2;
        ArrPackage[i]->entrada.p4 = rand() % 2;
        ArrPackage[i]->entrada.p5 = rand() % 2;
        ArrPackage[i]->entrada.p6 = rand() % 2;
        ArrPackage[i]->entrada.p7 = rand() % 2;
    }
}

/**
 * @brief [ESP] Inicializa aleatoriamente bitfields de salida.
 *        [ENG] Radomly flips binary values mapped to output bits.
 */
void CargarPuerto_Salida(struct paquete **ArrPackage)
{
    int i = 0;

    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        ArrPackage[i]->salida.p0 = rand() % 2;
        ArrPackage[i]->salida.p1 = rand() % 2;
        ArrPackage[i]->salida.p2 = rand() % 2;
        ArrPackage[i]->salida.p3 = rand() % 2;
        ArrPackage[i]->salida.p4 = rand() % 2;
        ArrPackage[i]->salida.p5 = rand() % 2;
        ArrPackage[i]->salida.p6 = rand() % 2;
        ArrPackage[i]->salida.p7 = rand() % 2;
    }
}

/**
 * @brief [ESP] Devuelve un número aleatorio entre un mínimo y un máximo paramétricos asumiendo bytes genéricos.
 *        [ENG] Native wrapper yielding a random byte within scoped ranges.
 */
unsigned char aleatorio_en_rango(unsigned char minimo, unsigned char maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

/**
 * @brief [ESP] Imprime en tabla formato CLI el contenido total del Buffer de Red.
 *        [ENG] Print payload in CLI formatted tables handling the package buffer array.
 */
void ImprimirContenidoPaquete(struct paquete **ArrPackages)
{
    int i = 0;

    printf("MAC_Destino MAC_Origen Puerto_Salida Puerto_Entrada\n");
    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        /* [ESP] MAC_Destino y MAC_Origen / [ENG] Dest and Src MAC */
        printf("%.6s      %.6s      ", ArrPackages[i]->MACdes, ArrPackages[i]->MACori);

        /* [ESP] Puerto_Salida / [ENG] Out Port */
        printf("%d%d%d%d%d%d%d%d      ",
               ArrPackages[i]->salida.p7, ArrPackages[i]->salida.p6,
               ArrPackages[i]->salida.p5, ArrPackages[i]->salida.p4,
               ArrPackages[i]->salida.p3, ArrPackages[i]->salida.p2,
               ArrPackages[i]->salida.p1, ArrPackages[i]->salida.p0);

        /* [ESP] Puerto_Entrada / [ENG] In Port */
        printf("%d%d%d%d%d%d%d%d",
               ArrPackages[i]->entrada.p7, ArrPackages[i]->entrada.p6,
               ArrPackages[i]->entrada.p5, ArrPackages[i]->entrada.p4,
               ArrPackages[i]->entrada.p3, ArrPackages[i]->entrada.p2,
               ArrPackages[i]->entrada.p1, ArrPackages[i]->entrada.p0);

        printf("\n");
    }
}

/**
 * @brief [ESP] Procedimiento colector de basura dinámico. Limpieza lineal.
 *        [ENG] Native linear dynamic GC cleaner block freeing packages memory space.
 */
void LiberarMemoriaDePaquetes(struct paquete **ArrPackages)
{
    int i = 0;

    for(i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        free(ArrPackages[i]);
        ArrPackages[i] = NULL;
    }
}
