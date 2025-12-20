#include"Funciones.h"

/*Ejercicio1*/

int main()
{
    //float x = 10;
    float **Filas = NULL;
    int i = 0;
    Filas = ComposicionDeFunciones(NomFun1,NomFun2);

    //Libero las columnas

    for( i = 0; Filas[i] != NULL; i++ )
        free(Filas[i]);

    //Libero las filas
    free(Filas);

    printf("Se ejecuto correctamente el programa\n");
    return 0;
}


/*
//Ejercicio 2
int main(int argc, char** argv)
{
    if( argc != 2 )
    {
        printf("Falta de argumentos.Re-ingresar segun <nombre_ejecutable> <nombre_archivo_in.c> \n");
        return ERROR;
    }

    FILE *File_In = NULL;
    FILE *File_Out = NULL;
    char ch = '\0';
    File_In = fopen(argv[1],"r");
    if(File_In == NULL)
    {
        printf("Error en apertura de archivo de entrada\n");
        return ERROR;
    }

    File_Out = fopen("copia.c","w");
    if(File_Out == NULL)
    {
        printf("Error en apertura de arhcivo de salida\n");
        return ERROR;
    }


    ch = fgetc(File_In);
    while(ch != EOF)
    {
        if(ch == '/')
        {
            ch = fgetc(File_In);
            if( ch == '*' )
            {
                for( ; ( (ch = fgetc(File_In)) != '*' ); );

                //Guarda la ultima / de la secuencia (*)asterisco / de final de comentario
                ch = fgetc(File_In);
                //Guarda el proximo caracter que NO es comentario
                ch = fgetc(File_In);

            }
            else if( ch == '/')
            {
                for( ; ( ch = fgetc(File_In) ) != '\n'; );
            }
        }
        fputc(ch, File_Out);
        ch = fgetc(File_In);
    }
    printf("\nLa copia fue realiza exitosamente\n.");
    fclose(File_In);
    fclose(File_Out);
    //getch();

   return 0;
}

*/





