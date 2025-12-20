#include"Funciones.h"

int main()
{
    int check = 0;
    struct paquete * ArrPackages[CANTIDAD_PAQUETES];

    //Inicializo la seed para generar numeros pseudo-aleatorios
    srand(time(NULL));

    check = CargaArrayConPunteros_A_Paquetes(ArrPackages);
    if(check == EXITO)
        printf("Se ejecuto correctamente la funcion CargarArrayConPunteros_A_Paquetes\n");
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
