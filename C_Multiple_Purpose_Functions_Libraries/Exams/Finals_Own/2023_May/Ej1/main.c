/**
 * @file    main.c
 * @brief   [ESP] Programa principal Ejercicio 1.
 *          [ENG] Main program Exercise 1.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("Faltan argumentos. Uso: <nombre_ejecutable> <archivo.bin> <archivo.txt>\n");
        return ERROR;
    }

    int cantidad_errores = 0;
    
    /* [ESP] Llamada a verificación / [ENG] Verification call */
    cantidad_errores = verif(argv[1], argv[2]);
    printf("La cantidad de errores son %d\n", cantidad_errores);

    return 0;
}
