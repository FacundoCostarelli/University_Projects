/**
 * ==========================================================================
 * bin_read_int32.c — Binary File Reader for 32-bit Integers
 * ==========================================================================
 * [ESP] Función que lee un archivo binario de enteros de 4 bytes cuyo
 *       largo es desconocido. Calcula la cantidad de enteros a partir
 *       del tamaño del archivo, aloca un buffer dinámico y devuelve
 *       los datos por referencia.
 *
 * [ENG] Function that reads a binary file of 4-byte integers whose
 *       length is unknown. Calculates the number of integers from the
 *       file size, allocates a dynamic buffer, and returns the data
 *       by reference.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

/*****Función que recibe el nombre de un archivo. El archivo es del tipo binario y
contiene una sucesión de números enteros de 4 bytes. No se conoce previamente su longitud.
La función lee el archivo número por número y guarda los valores en un buffer dinamico de
enteros que es devuelto por referencia.
*****/
/****Primer parámetro es el nombre del archivo, y el segundo es el lugar para guardar la
dirección de memoria donde comienza el buffer. Retorna un número mayor o igual a cero asociada con la
cantidad de elemento del vector o ERRROR (constante simbólica que deberá definir como -1)si no lo
pudo generar
****/

int LecturaEnterosDe_4_BytesFileInBinario(char *Nombre_Archivo_In, int **Buffer_enteros)
{
    FILE *File_In = NULL;
    int CantidadEnteros_File_In= 0;
    long tamanio_archivo = 0;

    //Apertura de archivo de entrada
    File_In = fopen(Nombre_Archivo_In,"r");
    if(File_In == NULL)
    {
        //printf("Error en apertura de archivo File_In\n");
        return ERROR;
    }

    //Posiciono el "file position indicator" al final del archivo de entrada
    fseek(File_In,0,SEEK_END);
    //Averiguo el tamanio del archivo
    tamanio_archivo = ftell(File_In);
    //Averiguo la cantidad de estructuras del archivo de entrada
    CantidadEnteros_File_In =  ( (int)tamanio_archivo ) / ( (int)sizeof(int)) ;
    printf("La cantidad de enteros de 4 bytes es tipo: %d\n", CantidadEnteros_File_In);
    //Posiciono el "file position indicator" al comienzo del arhcivo de entrada
    fseek(File_In,0,SEEK_SET);

    //Pido memoria dinamica para almacenar la info del archivo in en memoria
    (*Buffer_enteros) = (int *)malloc(CantidadEnteros_File_In * sizeof(int));
    if(*Buffer_enteros == NULL)
    {
        //printf("Error durante la asignacion de memoria dinamica para el Buffer de enteros\n");
        return ERROR;
    }

    if( fread(*Buffer_enteros,CantidadEnteros_File_In * sizeof(int),1,File_In) < 1 )
    {
        //printf("Error con la lectura de los enteros provenientes del arhcivo de entrada\n");
        return ERROR;
    }


    fclose(File_In);

    return CantidadEnteros_File_In;
}
/****FALTARIA LIBERAR LA MEMORIA EN EL SCOPE MAIN U OTRO SCOPE CON FREE()**/
