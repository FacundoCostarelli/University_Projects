/**
 * @file    main.c
 * @brief   [ESP] Programa de ejemplo para funciones de E/S de archivos.
 *          [ENG] Usage example program for file I/O functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "file_io.h"
#include <string.h>

int main(void)
{
    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 1: ModificarNombreFileIn
     *       Inserta "_decrypt" antes de la extensión del archivo.
     * [ENG] Example 1: ModificarNombreFileIn
     *       Inserts "_decrypt" before the file extension.
     * --------------------------------------------------------------- */
    printf("=== ModificarNombreFileIn ===\n\n");

    char nombre_original[] = "datos.bin";
    char nombre_modificado[100];

    int result = ModificarNombreFileIn(nombre_original, nombre_modificado);

    if (result == EXITO)
    {
        printf("[ESP] Original:   %s\n", nombre_original);
        printf("[ENG] Original:   %s\n", nombre_original);
        printf("[ESP] Modificado: %s\n", nombre_modificado);
        printf("[ENG] Modified:   %s\n", nombre_modificado);
    }
    else
    {
        printf("[ESP] Error al modificar el nombre.\n");
        printf("[ENG] Error modifying the name.\n");
    }

    /* ---------------------------------------------------------------
     * [ESP] Ejemplo 2: LecturaEnterosDe_4_BytesFileInBinario
     *       Lee enteros de 4 bytes desde un archivo binario.
     *       NOTA: Para que este ejemplo funcione, se necesita un
     *       archivo binario con enteros. Se creará uno de prueba.
     * [ENG] Example 2: LecturaEnterosDe_4_BytesFileInBinario
     *       Reads 4-byte integers from a binary file.
     *       NOTE: For this example to work, a binary file with
     *       integers is needed. A test file will be created.
     * --------------------------------------------------------------- */
    printf("\n=== LecturaEnterosDe_4_BytesFileInBinario ===\n\n");

    /* [ESP] Crear archivo binario de prueba con 5 enteros
       [ENG] Create test binary file with 5 integers */
    FILE *f = fopen("test_integers.bin", "wb");
    if (f != NULL)
    {
        int test_data[] = {10, 20, 30, 40, 50};
        fwrite(test_data, sizeof(int), 5, f);
        fclose(f);

        printf("[ESP] Archivo de prueba creado: test_integers.bin\n");
        printf("[ENG] Test file created: test_integers.bin\n");

        /* [ESP] Leer los enteros del archivo binario
           [ENG] Read the integers from the binary file */
        int *buffer = NULL;
        int count = LecturaEnterosDe_4_BytesFileInBinario("test_integers.bin", &buffer);

        if (count > 0 && buffer != NULL)
        {
            printf("[ESP] Se leyeron %d enteros:\n", count);
            printf("[ENG] Read %d integers:\n", count);
            for (int i = 0; i < count; i++)
                printf("  [%d] = %d\n", i, buffer[i]);

            /* [ESP] Liberar la memoria alocada por la función
               [ENG] Free the memory allocated by the function */
            free(buffer);
        }
        else
        {
            printf("[ESP] Error leyendo el archivo.\n");
            printf("[ENG] Error reading the file.\n");
        }

        /* [ESP] Limpiar archivo de prueba
           [ENG] Clean up test file */
        remove("test_integers.bin");
    }

    return 0;
}
