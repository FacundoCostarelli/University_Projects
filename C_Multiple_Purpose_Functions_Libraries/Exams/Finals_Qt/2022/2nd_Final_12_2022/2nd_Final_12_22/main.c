/**
 * @file    main.c
 * @brief   [ESP] Archivo main (2do Final 12/2022). Evalúa simulación de red.
 *          [ENG] Main file (2nd Final 12/2022). Computes mocked network layout setup.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Función ejecución rutinas del simulador generador de MAC.
 *        [ENG] Main generator routine simulating MAC traffic blocks.
 */
int main(void)
{
    int check = 0;
    struct paquete * ArrPackages[CANTIDAD_PAQUETES];

    /* [ESP] Inicializo seed P-RNG / [ENG] Init pseudo-RNG Seed */
    srand(time(NULL));

    check = CargaArrayConPunteros_A_Paquetes(ArrPackages);
    if(check == EXITO)
        printf("Se ejecuto correctamente la funcion CargaArrayConPunteros_A_Paquetes\n");
    else
        printf("Hubo un problema con la funcion CargarArrayConPunteros_A_Paquetes\n");

    check = CargaDeMiembrosDeUnPaquete(ArrPackages);
    if( check == EXITO )
        printf("Se ejecuto correctamente la funcion CargaDeMiembrosDeUnPaquete\n");
    else
        printf("Hubo un problema con la funcion CargaDeMiembrosDeUnPaquete\n");

    ImprimirContenidoPaquete(ArrPackages);

    LiberarMemoriaDePaquetes(ArrPackages);

    return 0;
}
