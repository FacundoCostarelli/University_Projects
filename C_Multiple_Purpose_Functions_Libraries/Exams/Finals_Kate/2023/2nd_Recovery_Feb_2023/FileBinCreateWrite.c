#include<stdio.h>

struct alumno
{
    int legajo;
    int DNI;
    char nombre[20];
    char apellido[20];
    int repartido;
    int banned;
};

int main(void)
{
    //Declaro un puntero a file del archivo binario de salida
    FILE *File_out = NULL;

    //Creo la informacion que contendra el archivo de salida a partir de crear varias variables struct producto y cargarlas con datos predeterminados
    struct alumno var1 = { 1762916, 42724683, "Facundo", "Costarelli", 0, 0};
    struct alumno var2 = { 2317920, 40502045, "Juan", "Costarelli", 0, 0};
    struct alumno var3 = { 1567345, 41356278, "Federico", "Lacroze", 0, 0};
    struct alumno var4 = { 1742663, 43485823, "Mariano", "Gonzales", 0, 0};
    struct alumno var5 = { 1345483, 42448256, "Emilia", "Benitez", 0, 0};
    struct alumno var6 = { 1807421, 44532567, "Marcelo", "Trujillo", 0, 0};
    struct alumno var7 = { 1190452, 45028384, "Lautaro","Martinez", 0, 0};
    struct alumno var8 = { 1734023, 39867546, "Federico", "Boa", 0, 0};

    //Creo y abro el arhcivo de salida
    File_out = fopen("alumnos.dat", "wb");
    //Proteccion contra NULL
    if(File_out == NULL)
    {
        printf("Hubo un error durante la apertura del arhcivo de salida binario\n");
        return -1;
    }

    //Escribo la informacion creada en el archivo de salida.
    //Por cada fwrite habria que escribir una proteccion
    fwrite(&var1, sizeof(struct alumno), 1, File_out);
    fwrite(&var2, sizeof(struct alumno), 1, File_out);
    fwrite(&var3, sizeof(struct alumno), 1, File_out);
    fwrite(&var4, sizeof(struct alumno), 1, File_out);
    fwrite(&var5, sizeof(struct alumno), 1, File_out);
    fwrite(&var6, sizeof(struct alumno), 1, File_out);
    fwrite(&var7, sizeof(struct alumno), 1, File_out);
    fwrite(&var8, sizeof(struct alumno), 1, File_out);

    //Cierro el archivo de salida
    fclose(File_out);
    
    return 0;
}
