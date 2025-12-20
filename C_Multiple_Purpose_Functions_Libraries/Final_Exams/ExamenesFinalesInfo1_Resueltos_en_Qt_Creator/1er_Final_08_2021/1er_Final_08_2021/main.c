#include"Funciones.h"

/*
//Main para ejercicio 1
int main()
{
    int v[4]={147456,227328,221184,198656};
    char *String = NULL;
    int check = 0;

    check = Convertir_IntArray_To_CharArray( v, 4, &String);
    if( check == EXITO )
    {
        printf("La funcion Convertir_IntArray_To_CharArray se ejecuto correctamente\n");
        printf("El string queda como: %s\n",String);
    }
    else
        printf("Ocurrio un error con la funcion Convertir_IntArray_To_CharArray\n");

    free(String);


    return 0;
}
*/


//Main para ejercicio 2
/*
int main()
{
    char Nombre_Archivo_In[] = "texto.txt";
    char Nombre_Archivo_Out[50];
    int check = 0;
    memset(Nombre_Archivo_Out,'\0',sizeof(Nombre_Archivo_Out));

    check = ModificarNombreFileIn(Nombre_Archivo_In, Nombre_Archivo_Out);
    if(check == EXITO)
    {
        printf("Se ejecuto correctamente la funcion ModificarNombreFIleIn\n");
        printf("El nombre de salida queda como:%s\n",Nombre_Archivo_Out);
    }
    else
        printf("Ocurrio un error con la funcion ModificarNombreFileIn\n");


    return 0;
}
*/

//Main para ejercicio 3
int main(int argc, char **argv)
{
    if( argc != 2)
    {
        printf("Argumentos insuficientes. Re-ingrese segun <nombre_ejecutable> <nombre_archivo_in.dat> \n");
        return ERROR;
    }

    int *ArrayEnteros = NULL;
    int check = 0;
    int tamanio_ArrayEnteros = 0;
    int i = 0;
    check = LecturaEnterosDe_4_BytesFileInBinario(argv[1],&ArrayEnteros);
    if( check == ERROR )
    {
        printf("Ocurrio un error con la funcion LecturaEnterosDe4BytesFileInBinario\n");
        return ERROR;
    }
    else
        tamanio_ArrayEnteros = check;

    for( i = 0; i < tamanio_ArrayEnteros; i++ )
        printf("|%d| ",ArrayEnteros[i]);

    free(ArrayEnteros);
    printf("El programa se ejecuto exitosamente y se liberaron los recursos\n");
    return 0;
}
