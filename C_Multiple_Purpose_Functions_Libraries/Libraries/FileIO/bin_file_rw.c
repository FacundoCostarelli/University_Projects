/**
 * @file    bin_file_rw.c
 * @brief   [ESP] Plantilla de escritura de archivos binarios con estructuras.
 *          [ENG] Binary file write template with structs.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Código de referencia que demuestra cómo crear un archivo binario
 *       y escribir múltiples registros de estructuras usando fwrite().
 *       Las secciones marcadas con <NOMBRE_ESTRUCTURA> son placeholders
 *       que deben reemplazarse por el tipo de estructura real.
 *
 * [ENG] Reference code demonstrating how to create a binary file and
 *       write multiple struct records using fwrite(). Sections marked
 *       with <NOMBRE_ESTRUCTURA> are placeholders that must be replaced
 *       with the actual struct type.
 */

#include <stdio.h>

/* [ESP] Definición de estructura de ejemplo — reemplazar por la real
   [ENG] Example struct definition — replace with the actual one */
typedef struct
{
    char nombreyapellido[80];   /* [ESP] Nombre y apellido / [ENG] Full name */
    unsigned int codigoCliente; /* [ESP] Código de cliente / [ENG] Client code */
    float kws;                  /* [ESP] Kilowatts consumidos / [ENG] Kilowatts consumed */
} ClienteEjemplo;

/**
 * @brief [ESP] Programa ejemplo: crea un archivo binario con datos de clientes.
 *        [ENG] Example program: creates a binary file with client data.
 */
int main(void)
{
    FILE *File_out = NULL;

    /* [ESP] Crear datos de ejemplo con estructuras inicializadas
       [ENG] Create sample data with initialized structs */
    ClienteEjemplo var1 = {"Facundo Costarelli", 30, 90.0};
    ClienteEjemplo var2 = {"Juan Costarelli", 20, 150.5};
    ClienteEjemplo var3 = {"Silvia Bruno", 30, 180.9};
    ClienteEjemplo var4 = {"Jorge Costarelli", 15, 135.0};
    ClienteEjemplo var5 = {"Mariano Gonzales", 40, 200.50};
    ClienteEjemplo var6 = {"Marcelo Trujillo", 100, 3000.500};
    ClienteEjemplo var7 = {"Misael Cudeck", 80, 2000.435};
    ClienteEjemplo var8 = {"Federico Boa", 30, 1500.536};

    /* [ESP] Abrir el archivo en modo escritura binaria ("wb")
       [ENG] Open the file in binary write mode ("wb") */
    File_out = fopen("informacion.dat", "wb");
    if (File_out == NULL)
    {
        printf("[ESP] Error en apertura de archivo binario de salida.\n");
        printf("[ENG] Error opening binary output file.\n");
        return -1;
    }

    /* [ESP] Escribir cada estructura al archivo binario con fwrite().
             fwrite(ptr, tamaño, cantidad, archivo)
       [ENG] Write each struct to the binary file with fwrite().
             fwrite(ptr, size, count, file) */
    fwrite(&var1, sizeof(ClienteEjemplo), 1, File_out);
    fwrite(&var2, sizeof(ClienteEjemplo), 1, File_out);
    fwrite(&var3, sizeof(ClienteEjemplo), 1, File_out);
    fwrite(&var4, sizeof(ClienteEjemplo), 1, File_out);
    fwrite(&var5, sizeof(ClienteEjemplo), 1, File_out);
    fwrite(&var6, sizeof(ClienteEjemplo), 1, File_out);
    fwrite(&var7, sizeof(ClienteEjemplo), 1, File_out);
    fwrite(&var8, sizeof(ClienteEjemplo), 1, File_out);

    /* [ESP] Cerrar el archivo
       [ENG] Close the file */
    fclose(File_out);

    printf("[ESP] Archivo binario creado exitosamente.\n");
    printf("[ENG] Binary file created successfully.\n");

    return 0;
}
