#include "Funciones.h"

int main(int argc, char **argv)
{
    Producto_t *listado = NULL;
    int CantidadEstructurasLeidas = 0;

    Nodo_t *ptr1erElemento = NULL;
    int Productos_Filtrados = 0;
    if(argc != 3)
    {
        printf("Falta de argumentos, ingresar siguiendo <./nombre_ejecutable.out> <nombre_archivobinario> <nombre_proveedor_a_filtrar>");
        return -1;
    }

    CantidadEstructurasLeidas = CargarProductos(argv[1],&listado);

    if(CantidadEstructurasLeidas == ERROR)
    {
        printf("Hubu un error con la funcion Cargar Productos\n");
        return ERROR;
    }
    else
        printf("La cantidad de estructuras leidas son: %d\n", CantidadEstructurasLeidas);


    if ( CargaDeDatosDeProductosPorTeclado(&listado) == ERROR )
    {
        printf("Ocurrio un error con la carga de datos de productos por teclado\n");
        return ERROR;
    }

    Productos_Filtrados = FiltrarProductos(listado, &ptr1erElemento, argv[2]);
    if( Productos_Filtrados == ERROR )
    {
        printf("Ocurrio un error con el filtrado de productos por nombre de proveedor\n");
        return ERROR;
    }
    else
    {
        printf("La cantidad de productos filtrados son: %d\n", Productos_Filtrados);
        Imprimir_Campos_EstructuraInterna_Nodo(&ptr1erElemento);
    }



    Liberar_Lista_Simplemente_Enlazada(&ptr1erElemento);
    free(listado);

    printf("Se ejecuto el programa correctamente y se liberaron todos los recursos del heap\n");

    return 0;
}
