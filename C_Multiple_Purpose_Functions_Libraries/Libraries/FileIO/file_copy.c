/**
 * ==========================================================================
 * file_copy.c — Copy Source File Without Comment Lines
 * ==========================================================================
 * [ESP] Algoritmo que copia un archivo fuente .c eliminando las líneas
 *       de comentarios (// y /* ... *​/). Lee carácter a carácter y
 *       detecta las secuencias de comentarios para omitirlas.
 *
 * [ENG] Algorithm that copies a .c source file while removing comment
 *       lines (// and /* ... *​/). Reads character by character and
 *       detects comment sequences to skip them.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

/************************ALGORITMO PARA COPIAR UN ARHCIVO FUENTE.C SIN LAS LINEAS DE COMENTARIOS**************************/

/*

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

#define ERROR -1
#define EXITO 0


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
    
    //Apertura archivo IN y verificacion de error
    File_In = fopen(argv[1],"r");
    if(File_In == NULL)
    {
        printf("Error en apertura de archivo de entrada\n");
        return ERROR;
    }

    //Apertura archivo OUT y verificacion de error
    File_Out = fopen("copia.c","w");
    if(File_Out == NULL)
    {
        printf("Error en apertura de arhcivo de salida\n");
        return ERROR;
    }

//Lectura de caracteres de archivo IN siempre que sea != EOF
    ch = fgetc(File_In);
    while(ch != EOF)
    {
    	/******Algoritmo para saltaer caracteres de lineas de comentarios y las secuencias de comentarios como "//", "/*" y "*/" ******/
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
        /*Escritura de caracteres de codigo en el arhcivo OUT*/
        fputc(ch, File_Out);
        ch = fgetc(File_In);
    }
    
    printf("\nLa copia fue realiza exitosamente\n.");
    //Cierre de arhcivos
    fclose(File_In);
    fclose(File_Out);
    //getch();

   return 0;
}

*/

