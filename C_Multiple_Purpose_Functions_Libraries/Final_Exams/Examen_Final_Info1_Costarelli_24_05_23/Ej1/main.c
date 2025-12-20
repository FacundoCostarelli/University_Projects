/*
Alumno: Facundo Costarelli
DNI: 42724683
Legajo: 176.291-6
Cursada: R1002 con Mariano Gonzales 2022
*/


#include"Funciones.h"

int main(int argc, char **argv)
{

    if(argc != 3)
    {
        printf("Faltan argumentos. Re-ingrese <nombre_ejecutable> <nombre_archivo.bin> <nombre_archivo.txt>\n");
        return ERROR;
    }

    int cantidad_errores = 0;
    cantidad_errores = verif(argv[1], argv[2]);
    printf("La cantidad de errores son %d\n", cantidad_errores);


    return 0;
}
