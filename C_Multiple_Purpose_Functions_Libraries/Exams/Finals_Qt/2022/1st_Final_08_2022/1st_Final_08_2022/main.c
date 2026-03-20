/**
 * @file    main.c
 * @brief   [ESP] Archivo main (Final 08/2022). Genera uniones con texto y sus desplazamientos de encriptación y escribe a disco.
 *          [ENG] Main file (Final 08/2022). Creates struct elements packaging texts and their encryption shift values into a binary file.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Función de ejecución principal (criptografía César y octales simulados).
 *        [ENG] Main execution logic handling César encoding schemas bounded locally.
 */
int main(int argc, char **argv)
{
    if( argc != 3)
    {
        printf("Error en argumentos ingresados. Reingresar segun: <nombre_ejecutable> <nombre_archivo_de_salida> <texto_a_encriptar>\n");
        return ERROR;
    }

    int i = 0;
    FILE *File_out = NULL;
    struct texto_encriptado *ptr = NULL;
    long tamanio_archivo = 0;
    char txt_aux[TXT_MAX_LEN];
    srand(time(NULL));

    File_out = fopen(argv[1], "wb");
    if( File_out == NULL )
    {
        printf("Error en apertura de archivo out\n");
        return ERROR;
    }

    ptr = (struct texto_encriptado *)malloc(sizeof(struct texto_encriptado));
    if(ptr == NULL)
    {
        printf("Error durante la asignacion de memoria dinamica para la struct texto_encriptado\n");
        return ERROR;
    }

    /* [ESP] Inicializo todos los arreglos / [ENG] Initialize all native arrays to clean bytes */
    for( i = 0; i < TXT_MAX_LEN; i++ )
    {
        txt_aux[i] = '\0';
        ptr->txt[i] = '\0';
    }

    /* [ESP] Encriptar letras devolviendo el step / [ENG] Encrypt letters matching a randomized cypher shifting */
    ptr->desplazamiento = encriptar_letras(argv[2], txt_aux);
    printf("Encriptacion de letras da: %s\n", txt_aux);

    /* [ESP] Encriptar números intermedios / [ENG] Cypher intermediate number chunks */
    encriptar_numeros(txt_aux, ptr->txt);

    printf("Desplazamiento: %d\n", ptr->desplazamiento);
    printf("Encriptacion de letras y numeros: %s\n", ptr->txt);

    /* [ESP] Acumular data guardada en archivo bin / [ENG] Append logical data inside out binary scope */
    fseek(File_out, 0, SEEK_END);
    tamanio_archivo = ftell(File_out);
    fseek(File_out, tamanio_archivo, SEEK_CUR);
    fwrite(ptr, sizeof(struct texto_encriptado), 1, File_out);

    fclose(File_out);
    free(ptr);

    printf("Se ejecuto el programa correctamente\n");
    return EXITO;
}
