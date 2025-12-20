#include"Funciones.h"

//EJERCICIO 1
/*
  Considerar que los enteros son de 4 bytes y los valores correspondientes al código ASCII son los 8
  bits del segundo byte menos significativo, es decir los 16 bits de mayor peso no importan, los 8 bits
  que siguen son el código ASCII y los 8 bits de menor peso no importan.
*/

/*
 * Cada entero con su segundo byte, estara asociado a un caracter
*/
int Convertir_IntArray_To_CharArray(int *IntArray, int Arraylargo, char **Frase)
{
    char *String = NULL;
    int Mascara = 0x000000FF;
    int i = 0;


    //Pido memoria dinamica para el string
    String = (char *)malloc( (Arraylargo + 1) * sizeof(char));
    if(String == NULL)
    {
        //printf("Error en la asignacion de memoria dinamica para el string\n");
        return ERROR;
    }

    for( i = 0; i < Arraylargo; i++ )
    {
        printf("IntArray[%d] = %d\n",i,IntArray[i]);
    }

    //Cargo en el string cada caracter asociado al 2do byte LSB de cada entero a partir de aplicar una mascara
    for( i = 0; i < Arraylargo; i++ )
    {
        String[i] = (char)( (IntArray[i] >> _8BITS) & Mascara);
        printf("Caracter de string: %c\n",String[i]);
    }
    //Cargo el caracter Null para saber donde termina la cadena
    String[i] = '\0';

    //Imprimo en pantalla provisoriamente el string para ver como queda
    printf("El String queda como: %s\n",String);

    //Retorno por referencia el string
    *Frase = String;

    return EXITO;
}

//Ejercicio 2

/***Función que reciba un string correspondiente a un nombre de archivo, busca el
último punto a la derecha y devuelve un string que corresponda al nombre original, agregada alguna frase ej
“_decrypt” y la extensión original.***/
//Ejemplo: Recibe el nombre "texto.txt" y debe retornar "texto_decrypt.txt"
//Si el nombre no contiene punto, la frase se agregará al final y quedará sin punto.
//El buffer_frase contiene en este ejemplo a _decrypt
int ModificarNombreFileIn(char *Nombre_Archivo_In, char *Nombre_Archivo_Out)
{
    size_t i = 0, j = 0;
    char buffer_nombre[30];
    char buffer_extension[10];
    char buffer_frase[] = "_decrypt";
    //int largo_extension = 0;
    int flag = 1;

    if(flag == 1)
    {
        //Inicializo los buffers con todos 0
        memset(buffer_nombre,'\0',sizeof(buffer_nombre));
        memset(buffer_extension,'\0',sizeof(buffer_extension));
        //memset(buffer_frase,'\0',sizeof(buffer_frase));
        flag = EXITO;
    }
    else
        return ERROR;

    if(flag == EXITO )
    {
        //Guardo el nombre del archivo In en un buffer hasta encontrar el "." en el nombre
        for( i = 0; Nombre_Archivo_In[i] != '.'; i++ )
            buffer_nombre[i] = Nombre_Archivo_In[i];


       //printf("largo de la extension %lu\n",strlen(Nombre_Archivo_In+i));

        //Guardo la extension en un buffer
        for( j = 0; Nombre_Archivo_In[i] != '\0'; j++, i++ )
            buffer_extension[j] = Nombre_Archivo_In[i];

        //printf("La extension es: %s\n",buffer_extension);

        flag = EXITO;
    }
    else
        return ERROR;

    if( flag == EXITO )
    {
        //Guardo en el array de salida el nuevo nombre con la nueva frase adicional y la extension original

        //Guardo nombre original en array de salida
        for( i = 0; i < strlen(buffer_nombre); i++ )
            Nombre_Archivo_Out[i] = buffer_nombre[i];
        //Guardo frase concatenandola en array de salida
        for( j = 0; j < strlen(buffer_frase); j++, i++ )
            Nombre_Archivo_Out[i] = buffer_frase[j];
        //Guardo extension original concatenandola en array de salida
        for( j = 0; j < strlen(buffer_extension); j++,i++ )
            Nombre_Archivo_Out[i] = buffer_extension[j];

        //Guardo el caracter null como ultimo elemento para indicar fin de cadena
        Nombre_Archivo_Out[i] = '\0';

        flag = EXITO;
    }
    else
        return ERROR;

    if( flag == EXITO)
    {
        //printf("El archivo de salida tiene el nuevo nombre que es: %s\n",Nombre_Archivo_Out);
        return EXITO;
    }
    else
        return ERROR;

}

//Ejercicio 3

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
