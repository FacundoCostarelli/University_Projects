/**
 * @file    FileBinCrearEscribir.c
 * @brief   [ESP] Script para mockear/crear el archivo binario para la prueba. Final 2023.
 *          [ENG] Script used to create the binary file containing products test data. Final 2023.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>

/**
 * @brief [ESP] Estructura simple de producto.
 *        [ENG] Product basic structure.
 */
struct producto
{
    int codigo_Producto;
    char proveedor[20];
    int cantidad_stock;
};

/**
 * @brief [ESP] Función principal crea datos y graba en disco.
 *        [ENG] Main function creating fake test data and saving to disk.
 */
int main(void)
{
    FILE *File_out = NULL;

    struct producto var1 = { 1, "BAGLEY", 20};
    struct producto var2 = { 2, "TERRABUSI", 16};
    struct producto var3 = { 3, "CHOCOLINAS", 13};
    struct producto var4 = { 4, "DON_SATUR", 28};
    struct producto var5 = { 5, "9_DE_ORO", 8};
    struct producto var6 = { 6, "FORMITAS", 2};
    struct producto var7 = { 7, "BAGLEY", 34};
    struct producto var8 = { 8, "BAGLEY", 5};

    File_out = fopen("informacion.dat", "wb");
    
    if(File_out == NULL)
    {
        printf("Hubo un error durante la apertura del arhcivo de salida binario\n");
        return -1;
    }

    fwrite(&var1, sizeof(struct producto), 1, File_out);
    fwrite(&var2, sizeof(struct producto), 1, File_out);
    fwrite(&var3, sizeof(struct producto), 1, File_out);
    fwrite(&var4, sizeof(struct producto), 1, File_out);
    fwrite(&var5, sizeof(struct producto), 1, File_out);
    fwrite(&var6, sizeof(struct producto), 1, File_out);
    fwrite(&var7, sizeof(struct producto), 1, File_out);
    fwrite(&var8, sizeof(struct producto), 1, File_out);

    fclose(File_out);

    return 0;
}
