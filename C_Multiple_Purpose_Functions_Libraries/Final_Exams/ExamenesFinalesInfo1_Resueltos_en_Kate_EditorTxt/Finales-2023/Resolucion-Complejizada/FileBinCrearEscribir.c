#include<stdio.h>

struct producto
{
    int codigo_Producto;
    char proveedor[20];
    int cantidad_stock;
};

int main(void)
{
    //Declaro un puntero a file del archivo binario de salida
    FILE *File_out = NULL;

    //Creo la informacion que contendra el archivo de salida a partir de crear varias variables struct producto y cargarlas con datos predeterminados
    struct producto var1 = { 1, "BAGLEY", 20};
    struct producto var2 = { 2, "TERRABUSI", 16};
    struct producto var3 = { 3, "CHOCOLINAS", 13};
    struct producto var4 = { 4, "DON_SATUR", 28};
    struct producto var5 = { 5, "9_DE_ORO", 8};
    struct producto var6 = { 6, "FORMITAS", 2};
    struct producto var7 = { 7, "BAGLEY", 34};
    struct producto var8 = { 8, "BAGLEY", 5};

    //Creo y abro el arhcivo de salida
    File_out = fopen("informacion.dat", "wb");
    //Proteccion contra NULL
    if(File_out == NULL)
    {
        printf("Hubo un error durante la apertura del arhcivo de salida binario\n");
        return -1;
    }

    //Escribo la informacion creada en el archivo de salida.
    //Por cada fwrite habria que escribir una proteccion
    fwrite(&var1, sizeof(struct producto), 1, File_out);
    fwrite(&var2, sizeof(struct producto), 1, File_out);
    fwrite(&var3, sizeof(struct producto), 1, File_out);
    fwrite(&var4, sizeof(struct producto), 1, File_out);
    fwrite(&var5, sizeof(struct producto), 1, File_out);
    fwrite(&var6, sizeof(struct producto), 1, File_out);
    fwrite(&var7, sizeof(struct producto), 1, File_out);
    fwrite(&var8, sizeof(struct producto), 1, File_out);

    //Cierro el archivo de salida
    fclose(File_out);

    return 0;
}
