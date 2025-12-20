#include<stdio.h>

typedef /*<struct data>*/
{
	/*ESTO ES UN EJEMPLO*/
    char nombreyapellido[80];
    unsigned int codigoCliente;
    float kws;
}/*<NOMBRE_ESTRUCTURA>*/;

int main(void)
{
    //Declaro un puntero a file del archivo binario de salida
    FILE *File_out = NULL;

    //Creo la informacion que contendra el archivo de salida a partir de crear varias variables struct producto y cargarlas con datos predeterminados
    /*<struct data>*/ var1 = { "Facundo Costarelli", 30, 90};
    /*<struct data>*/ var2 = { "Juan Costarelli", 20, 150.5};
    /*<struct data>*/ var3 = { "Silvia Bruno", 30, 180.9};
    /*<struct data>*/ var4 = { "Jorge Costarelli", 15, 135};
    /*<struct data>*/ var5 = { "Mariano Gonzales", 40, 200.50};
    /*<struct data>*/ var6 = { "Marcelo Trujillo", 100, 3000.500};
    /*<struct data>*/ var7 = { "Misael Cudeck", 80, 2000.435};
    /*<struct data>*/ var8 = { "Federico Boa", 30, 1500.536};

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
    fwrite(&var1, sizeof(/*<struct data>*/), 1, File_out);
    fwrite(&var2, sizeof(/*<struct data>*/), 1, File_out);
    fwrite(&var3, sizeof(/*<struct data>*/), 1, File_out);
    fwrite(&var4, sizeof(/*<struct data>*/), 1, File_out);
    fwrite(&var5, sizeof(/*<struct data>*/), 1, File_out);
    fwrite(&var6, sizeof(/*<struct data>*/), 1, File_out);
    fwrite(&var7, sizeof(/*<struct data>*/), 1, File_out);
    fwrite(&var8, sizeof(/*<struct data>*/), 1, File_out);

    //Cierro el archivo de salida
    fclose(File_out);
    
    return 0;
}
