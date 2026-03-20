#include "Functions.h"

int main(int argc, char **argv)
{
    FILE *File_in = NULL;
    LISTAENERGIA *listadoClientesBarrio = NULL;
    LISTAENERGIA *ptrAuxlistadoClientesBarrio = NULL;
    unsigned int barrio_a_filtrar = 0;
    if( argc != 2 )
    {
        printf("Ingrese bien los comandos <nombreEjecutable.out> <nombre_archivo.bin/dat> \n");
        return ERROR;
    }

    printf("Ingrese el nro de barrio a filtrar: ");
    scanf("%ud", &barrio_a_filtrar);
    __fpurge(stdin);

    //Abro el archivo de entrada
    File_in = fopen(argv[1],"r");
    if( File_in == NULL )
    {
        printf("Ocurrio un erorr en la apertura del archivo de entrada\n");
        return ERROR;
    }

    if( crearListado(&listadoClientesBarrio, &ptrAuxlistadoClientesBarrio ,File_in, barrio_a_filtrar) == EXITO)
    {
        printf("Se ejecuto correctamente la funcion crearListado\n");
        Imprimir_Lista_Simplemente_Enlazada_PILA_O_COLA(&listadoClientesBarrio);
    }
    else
    {
        printf("Ocurrio un error con la funcion crearListado\n");
        return ERROR;
    }
    /*
    if ( crearListado(&listadoClientesBarrio, File_in, barrio_a_filtrar) == EXITO )
    {
        printf("Se ejecuto correctamente la funcion crearListado\n");
        Imprimir_Campos_EstructuraInterna_Nodo(&listadoClientesBarrio);
    }
    else
    {
        printf("Ocurrio un error con la funcion crearListado\n");
        return ERROR;
    }
*/

    fclose(File_in);
    Liberar_Lista_Simplemente_Enlazada_PILA_O_COLA(&listadoClientesBarrio);

    printf("Se ejecuto el programa y liberaron todos los recursos correctamente\n");

    return 0;
}
