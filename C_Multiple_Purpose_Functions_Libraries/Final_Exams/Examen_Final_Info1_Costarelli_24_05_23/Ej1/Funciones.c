/*
Alumno: Facundo Costarelli
DNI: 42724683
Legajo: 176.291-6
Cursada: R1002 con Mariano Gonzales 2022
*/

#include"Funciones.h"

//Ejercicio1 item a)
unsigned char paridad(char *s, int c)
{
    int i = 0;
    unsigned char bytedeparidad = s[0];

    for( i = 1; i < c; i++ )
    {
        bytedeparidad = bytedeparidad ^ s[i];
    }

    return bytedeparidad;
}

//Ejercicio1 item b)

int verif(char *f1, char *f2)
{
    FILE *File_in1 = NULL;
    FILE *File_in2 = NULL;
    int CantidadEstructuras_FileIn1 = 0;
    int Cantidadbytes_FileIn2 = 0;
    long tamanio_archivo1 = 0;
    long tamanio_archivo2 = 0;
    int i = 0;
    struct datos *Buffer_Read_in1 = NULL;
    unsigned char *buffer_Read_in_bytesdeparidad = NULL;
    unsigned char bytedeparidad = 0;
    int cantidad_errores = 0;

    //Abro el archivo de entrada
    File_in1 = fopen(f1,"r");
    if( File_in1 == NULL )
    {
        printf("Ocurrio un erorr en la apertura del archivo de entrada\n");
        return ERROR;
    }

    //Posiciono el "file position indicator" al final del archivo de entrada 1
    fseek(File_in1,0,SEEK_END);
    //Averiguo el tamanio del archivo 1
    tamanio_archivo1 = ftell(File_in1);
    //Averiguo la cantidad de estructuras del archivo de entrada 1
    CantidadEstructuras_FileIn1 =  ( (int)tamanio_archivo1 ) / ( (int)sizeof(struct datos) );
    printf("La cantidad de estructuras tipo struct datos son: %d\n", CantidadEstructuras_FileIn1);
    //Posiciono el "file position indicator" al comienzo del arhcivo de entrada 1
    fseek(File_in1,0,SEEK_SET);

    //Pido memoria dinamica para almacenar la info del archivo in 1 en memoria
    Buffer_Read_in1 = (struct datos *)malloc( CantidadEstructuras_FileIn1 * sizeof(struct datos));
    //Proteccion contra NULL de malloc
    if( Buffer_Read_in1 == NULL )
    {
        printf("Erropr en la asignacion de memoria dinamica para buffer de informacion read in\n");
        return ERROR;
    }

    //Leo del arhcivo de entrada 1 las estructuras y las guardo en memoria
    if ( fread(Buffer_Read_in1, CantidadEstructuras_FileIn1 * sizeof(struct datos), 1, File_in1) < 1 )
    {
        printf("Hubo un error con la lectura en memoria de las estructuras de entrada\n");
        return ERROR;
    }


    //Abro el archivo de entrada 2
    File_in2 = fopen(f2,"r");
    if( File_in2 == NULL )
    {
        printf("Ocurrio un erorr en la apertura del archivo de entrada 2\n");
        return ERROR;
    }

    //Posiciono el "file position indicator" al final del archivo de entrada 2
    fseek(File_in2,0,SEEK_END);
    //Averiguo el tamanio del archivo 2
    tamanio_archivo2 = ftell(File_in2);
    //Averiguo la cantidad de estructuras del archivo de entrada 2
    Cantidadbytes_FileIn2 =  ( (int)tamanio_archivo2 ) / ( (int)sizeof(char) );
    printf("La cantidad de bytes de paridad tipo char son: %d\n", Cantidadbytes_FileIn2);
    //Posiciono el "file position indicator" al comienzo del arhcivo de entrada 2
    fseek(File_in2,0,SEEK_SET);

    //Pido memoria dinamica para almacenar la info del archivo in 1 en memoria
   buffer_Read_in_bytesdeparidad = (unsigned char *)malloc( Cantidadbytes_FileIn2 * sizeof(unsigned char));
    //Proteccion contra NULL de malloc
    if( buffer_Read_in_bytesdeparidad == NULL )
    {
        printf("Erropr en la asignacion de memoria dinamica para buffer de informacion read in\n");
        return ERROR;
    }

    //Leo del arhcivo de entrada 1 las estructuras y las guardo en memoria
    if ( fread(buffer_Read_in_bytesdeparidad, Cantidadbytes_FileIn2 * sizeof(unsigned char), 1, File_in2) < 1 )
    {
        printf("Hubo un error con la lectura en memoria de las estructuras de entrada\n");
        return ERROR;
    }


    /*Algoritmo de verificacion de bytes del arhcivo de verificacion vs los bytes de paridad del archivo binario*/
    for( i = 0; i < CantidadEstructuras_FileIn1; i++ )
    {

        bytedeparidad = paridad((char *)&Buffer_Read_in1[i], sizeof(Buffer_Read_in1[i]));
        if( buffer_Read_in_bytesdeparidad[i] != bytedeparidad)
            cantidad_errores++;
    }


    //Libero los recursos del buffer dinamico de estructuras provenientes del archivo de entrada 1
    free(Buffer_Read_in1);
    //Libreo los recursos del buffer que contiene los bytes del txt de entrada
    free(buffer_Read_in_bytesdeparidad);
    //Cierro el archivo de entrada 1 y 2
    fclose(File_in1);
    fclose(File_in2);

    return cantidad_errores;

}
