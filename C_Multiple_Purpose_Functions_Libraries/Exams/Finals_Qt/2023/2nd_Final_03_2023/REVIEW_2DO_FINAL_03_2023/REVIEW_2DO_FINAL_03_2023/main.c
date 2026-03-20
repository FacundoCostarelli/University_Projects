#include "Functions.h"

int main(int argc, char **argv)
{
    if( argc != 2 )
    {
        printf("Faltan argumentos. Re-ingresar segun <nombre_ejecutable> <nombre_archivo_in>\n");
        return ERROR;
    }
    FILE *File_in = NULL;
    LISTAENERGIA *ptr_1erElemento = NULL;

    //Abro el archivo de entrada
    File_in = fopen(argv[1],"r");
    if( File_in == NULL )
    {
        printf("Ocurrio un erorr en la apertura del archivo de entrada\n");
        return ERROR;
    }

    if( crearListado(&ptr_1erElemento,File_in,14) == ERROR )
    {
        printf("Ocurrio un errro con la funcion crealistado\n");
        return ERROR;
    }

    Imprimir_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(&ptr_1erElemento);
    Liberar_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(&ptr_1erElemento);

    printf("El programa se ejecuto correctamente\n");
    return 0;
}
