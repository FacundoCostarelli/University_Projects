/**
 * @file    main.c
 * @brief   [ESP] Archivo main (Final 06/2021). Incluye ejercicios varios comentados.
 *          [ENG] Main file (Final 06/2021). Includes various commented exercises.
 *
 * @author  Facundo Costarelli
 * @date    2021
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Función principal que prueba la composición de funciones (Ejercicio 1).
 *        [ENG] Main execution block testing function composition (Exercise 1).
 */
int main(void)
{
    float **Filas = NULL;
    int i = 0;
    Filas = ComposicionDeFunciones(NomFun1, NomFun2);

    /* [ESP] Libero las columnas / [ENG] Free columns */
    for( i = 0; Filas[i] != NULL; i++ )
        free(Filas[i]);

    /* [ESP] Libero las filas / [ENG] Free rows */
    free(Filas);

    printf("Se ejecuto correctamente el programa\n");
    return 0;
}

/*
 * [ESP] Segundo programa principal (Ejercicio 2). Remueve comentarios de un archivo de C.
 * [ENG] Alternate main program (Exercise 2). Comments stripping script logically disabled.
 *
int main(int argc, char** argv)
{
    if( argc != 2 ) {
        printf("Falta de argumentos. Re-ingresar segun <nombre_ejecutable> <nombre_archivo_in.c> \n");
        return ERROR;
    }

    FILE *File_In = NULL;
    FILE *File_Out = NULL;
    char ch = '\0';
    File_In = fopen(argv[1], "r");
    if(File_In == NULL) {
        printf("Error en apertura de archivo de entrada\n");
        return ERROR;
    }

    File_Out = fopen("copia.c", "w");
    if(File_Out == NULL) {
        printf("Error en apertura de archivo de salida\n");
        return ERROR;
    }

    ch = fgetc(File_In);
    while(ch != EOF) {
        if(ch == '/') {
            ch = fgetc(File_In);
            if( ch == '*' ) {
                for( ; ( (ch = fgetc(File_In)) != '*' ); );
                ch = fgetc(File_In);
                ch = fgetc(File_In);
            } else if( ch == '/') {
                for( ; ( ch = fgetc(File_In) ) != '\n'; );
            }
        }
        fputc(ch, File_Out);
        ch = fgetc(File_In);
    }
    printf("\nLa copia fue realiza exitosamente.\n");
    fclose(File_In);
    fclose(File_Out);
    return 0;
}
*/
