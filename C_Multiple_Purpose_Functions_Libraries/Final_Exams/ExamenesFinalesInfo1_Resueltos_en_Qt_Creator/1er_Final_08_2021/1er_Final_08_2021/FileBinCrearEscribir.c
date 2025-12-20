#include<stdio.h>


int main(void)
{
    //Declaro un puntero a file del archivo binario de salida
    FILE *File_out = NULL;
    
    int ArrayEnteros[10] = {5,8,236,3715,57292,-3274,-3612,38,9521,10};

    //Creo y abro el arhcivo de salida
    File_out = fopen("informacion.dat", "wb");
    //Proteccion contra NULL
    if(File_out == NULL)
    {
        printf("Hubo un error durante la apertura del arhcivo de salida binario\n");
        return -1;
    }

    fwrite(ArrayEnteros,sizeof(int),10,File_out);
    //Cierro el archivo de salida
    fclose(File_out);
    
    return 0;
}
