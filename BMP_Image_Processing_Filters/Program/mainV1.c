/*
 * BMP_Image_Processing.c
 *
 * Created on: September 2022
 *     Author: Facundo Costarelli
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//ESP: Tamanio total maximo posible de cabezara bmp. 
//ENG: Maximum possible size of bmp header.
#define TamCabezera 54  
//ESP: Tamanio total maximo posible de colores.
//ENG: Maximum possible size of colors.  
#define TamTotalColores 1024
#define TRUE 1
#define BLANCO 255
#define NEGRO 0
#define UMBRAL 150

/*ESP
* @brief Proyecto creado en un único archivo main.c y un .h cuyo programa realiza un procesamiento de imagen BMP
*
* Este programa utiliza un codigo main.c como fuente principal donde se llama a las diversas funciones y se las utiliza. 
* Este fuente a su vez, posee declaraciones de punteros que se utilizan en las diversas funciones. 
* También dicho archivo fuente contiene las instrucciones de uso de:
* - Comandos por argumento de main
* - De la ejecución del archivo ejectuable
* - De la imagen .bmp a procesar

* En términos concretos, el programa realiza la lectura obligatoria del archivo de entrada bmp a traves de una funcion que lee el header, 
* tabla de colores(si existiese) y la data imagen. Ademas printea dicho header y tabla de colores(si existiese) en pantalla a traves 
* de otra funcion y finalmente y más importante es que posee un menu recursivo con diferentes opciones de procesamiento de imagenes donde
* todos estos procesamientos son realizados a traves del llamado de diversas funciones.
* El archivo .bmp de entrada puede ser del tipo:
* - 1)Blanco y negro,
* - 2)En escala de grises, osea en GrayshadeScale 
* - 3)Color RGB
* 
* En particular las diferentes opciones de procesamiento en funcionamiento son:
* - A)Copiar_imagen 
*   Aplicable para los tipos de imagenes 1),2),3) y para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits.
* 
* - B)Conversion_RGB_a_Grayscale 
*   Aplicable para los tipos de imagenes 3) mientras que para 2) y 1) tambien es posible pero es no recomendable 
*   porque se adquiere un resultado distinto al buscado. Es aplicable para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits. 
*   Posee un unico algoritmo de conversion de colores a grises llamado "The Weighted Method". 
*   Este metodo tambien llamado "Metodo de luminosidad" consiste en "pesar" el color rojo, verde y azul de acuerdo a sus longitudes de onda "landa". 
*   La formula es:
*   Grayscale = 0.299R + 0.587G + 0.114B
* 
* - C)Conversion_Grayscale_a_BlancoyNegro 
*   Aplicable para los tipos de imagenes 2) mientras que para 3) y 1) tambien es posile pero es no recomendable 
*   porque se adquiere un resultado distinto al buscado. Es aplicable para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits.
*   Posee un solo algoritmo de conversion de grises a blanco y negro llamado "binarizacion" que consiste en convertir el valor entero de cada byte a 0 o 1.
*   Se toma byte a byte de data de imagen tal que el valor entero propiamente dicho de ese byte valga 0 o 1 donde 0 equivale al negro binario y 
*   donde 1 equivale al blanco binario. Se usa ademas un valor entero de "Threshold" o tambien llamado "Umbral" tal que los valores enteros de bytes 
*   que superen dicho umbral se les asigne el valor de 1 y los valores que no superen el umbral se les asigne el valor de 0. En el codigo se usan 
*   3 macros, BLANCO para 1, NEGRO para 0 y UMBRAL para un valor entero definido por el programador ej: 150. Al cambiar este valor, cambia que 
*   tan oscuro se ve el negro y que tan claro se ve el blanco en la imagen blanco y negro de salida.

* - D)Rotacion_Imagen
*   Aplicable para los tipos de imagenes 1),2) y 3). Es aplicable para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits.
*   Posee un solo algoritmo de rotacion. La rotacion en un sentido u otro no es realizado en este programa a traves de la transformacion lineal 
*   sino a partir de asignar cada pixel del array "BufferCopiaLocalIn" de 2 dimensiones, en el array "BufferCopiaLocalOut" de 2 dimensiobes 
*   pero ubicando cada uno de ellos en las coordenadas "x e y" asociadas a los indexes "i e j" modificados matematicamente en los [] en el 
*   array BufferCopiaLocalOut de 2 dimensiones durante la asignacion. Dicho proceso de asignacion se ejecuta a traves de 2 ciclos for por cada 
*   case de rotacion debido a que los pixeles se encuentran ubicados en arreglos de 2 dimensiones.
* 
* - E)Deteccion de bordes lineal
*   Aplicable para los tipos de imagenes 1),2) y 3). Es aplicable para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits. 
*   Realiza la deteccion de bordes a partir de una mascara, es decir, un array de 2 dimensiones de 3x3 con valores pre-cargados. 
*   Dicho algoritmo utiliza 4 ciclos for: 
*   - El 1ero es para recorrer todas las filas.
*   - El 2do para recorrer todas las columnas. 
*   - El 3ero y el 4to que realizan cambio de valor en un pixel a otro valor y ademas se carga el nuevo valor del pixel en determinada 
*     posicion del buffer de salida de data imagen. Este algoritmo utiliza el operador de "gradientes" el cual computa las derivadas 
*     primeras en la imagen digital procesada.

* Todos estas operaciones de procesamiento de imagenes fueron testeadas con exito de forma exhaustiva para "tamanio de pixel 
* o profundidad de bit" de 24 bits osea cada pixel compuesto por 3bytes. El tamanio de pixel lo llamo en el codigo "Tampunto". 
*
* @attention 
* En las funciones Lectura_Imagen y Copia_Imagen se usan files descriptors y por ende POSIX system calls (open, read, write, close, etc). 
* En el resto de funciones se usan "streams" y por ende FILE pointers y las respectivas funciones para punteros a FILE(fopen, fread, fwrite, fclose, etc.)
* Estas son del standard C. La finalidad de esta mezcla fue usar distintas sintaxis y recursos para resolver diversos problemas asociados al manejo
* de archivos.

* 

*/

//ESP: Definicion de estructuras y uniones. 
//ENG: Definition of structures and unions.
#pragma pack(1)




/* ESP
 * @brief Estructura que define la cabecera de un archivo BMP.
 *        Contiene información sobre el tipo de archivo, tamaño, dimensiones, etc.
 */

/* ENG
 * @brief Structure that defines the header of a BMP file.
 *        Contains information about the file type, size, dimensions, etc.
 */

typedef struct Cabezera
{
    char TipoArchivo[2]; //ESP: Vector que almacena los caracteres asociados al tipo de archivo. //ENG: Array that saves the characters representing the file type.
    int TamARchivo; //ESP: Entero que almacena el tamaño total del archivo en bytes. //ENG: Integer that stores the total file size in bytes.
    short int Reservado1; //ESP: Campo reservado, no utilizado. //ENG: Reserved field, not used.
    short int Reservado2; //ESP: Campo reservado, no utilizado. //ENG: Reserved field, not used.
    int InicioImagen; //ESP: Entero que indica el offset donde comienza la imagen. //ENG: Integer that indicates the offset where the image data begins.
    int TamTotalCabezera; //ESP: Entero que almacena el tamaño total de la cabecera. //ENG: Integer that stores the total size of the header.
    int Ancho; //ESP: Entero que almacena el ancho de la imagen en píxeles. //ENG: Integer that stores the width of the image in pixels.
    int Altura; //ESP: Entero que almacena la altura de la imagen en píxeles. //ENG: Integer that stores the height of the image in pixels.
    short int NumPlanos; //ESP: Entero corto que indica el número de planos de color. //ENG: Short integer that indicates the number of color planes.
    short int TamPunto; //ESP & ENG: Bits por píxel. //ENG: Bits per pixel.
    int Compresion; //ESP: Entero que indica el tipo de compresión utilizada. //ENG: Integer that indicates the type of compression used.
    int TamImg; //ESP: Entero que almacena el tamaño de la imagen en bytes. //ENG: Integer that stores the size of the image data in bytes.
    int ResoHorizontal; //ESP: Entero que almacena la resolución horizontal en píxeles por metro. //ENG: Integer that stores the horizontal resolution in pixels per meter.
    int ResoVertical; //ESP: Entero que almacena la resolución vertical en píxeles por metro. //ENG: Integer that stores the vertical resolution in pixels per meter.
    int TamTablaColores; //ESP: Entero que almacena el tamaño de la tabla de colores. //ENG: Integer that stores the size of the color table.
    int ContColores; //ESP: Entero que almacena el número de colores importantes usados. //ENG: Integer that stores the number of important colors used.
} DatosBMP; //ESP: DatosBMP es la nueva etiqueta asociada al tipo de dato "struct" cuyo nombre es "Cabezera". //ENG: DatosBMP is the new tag associated with the "struct" data type named "Cabezera".




/* ESP
 * @brief Unión que define la tabla de colores de un archivo BMP.
 *        Contiene la paleta de colores del archivo.
 */

/* ENG
 * @brief Union that defines the color table of a BMP file.
 *        Contains the color palette of the file.
 */

typedef union TablaColores
{
    unsigned char CantColoresPaleta[TamTotalColores];
}Paleta_de_colores;

#pragma pack(4)

//Declaracion de prototipos de funcion
void Lectura_Imagen( DatosBMP **p, Paleta_de_colores **p1, unsigned char **BufferDataImagen, 
char *NombreDeImagen, int *fd_in );
int Impresion_Info_HeaderBMP(DatosBMP *p);
void Escritura_Imagen_HeaderYTablaColores(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision);
void Copia_Imagen( DatosBMP **p, Paleta_de_colores **p1, unsigned char **BufferDataImagen, int *fd_out );
void Conversion_RGB_a_Grayscale(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision);
void Conversion_Grayscale_a_BlancoyNegro(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision);
void Rotacion_Imagen(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision);
void Deteccion_de_Bordes_lineal(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision, int Mascara[][3]);



int main( int argc, char *argv[] )
{
    //ESP: Creacion de un puntero "p" para almacenar la direccion asignada por la funcion "Lectura_Imagen" 
    //a traves de malloc, asociada dicha direccion al bloque de memoria asignado para la estructura de DatosBMP y sus 
    //miembros donde todos ellos son asociados a las distintas secciones del Header del archivo BMP.
    //ENG: Creation of a pointer "p" to store the address obtained by the function "Lectura_Imagen"
    //through malloc, associated that address to the memory block assigned to the structure DatosBMP and its
    //members where all of them are associated with the different sections of the BMP file Header.
    DatosBMP *p = NULL;
    
    //ESP: Creacion de un puntero "p1" para almacenar la direccion asignada por la funcion "Lectura_Imagen" 
    //a traves de malloc, asociada dicha direccion al bloque de memoria asignado para la union Paleta_de_Colores 
    //y sus miembors donde todos ellos son asociados a la tabla de colores del archivo BMP.
    //ENG: Creation of a pointer "p1" to store the address obtained by the function "Lectura_Imagen"
    //through malloc, associated that address to the memory block assigned to the union Paleta_de_Colores
    //and its members where all of them are associated with the color table of the BMP file.
    Paleta_de_colores *p1 = NULL;
    
    //ESP: Creacion de un puntero "BufferDataImagen" para almacenar la direccion asignada por la funcion "Lectura_Imagen" 
    //a traves de malloc, asociada dicha direccion al bloque de memoria asignado para la data de la imagen, 
    //es decir, la informacion exclusivamente de la imagen y no la del header o tabla de colores, etc.
    //ENG: Creation of a pointer "BufferDataImagen" to store the address obtained by the function "Lectura_Imagen"
    //through malloc, associated that address to the memory block assigned to the image data,
    //that is, the information exclusively of the image and not the header or color table, etc.
    unsigned char *BufferDataImagen = NULL;
    
    //ESP: Declaro una variable de file descripto que guardara un numero int asociado al "ARCHIVO DE ENTRADA" 
    //que se abre con OPEN para luego leerlo y procesarlo. 
    //ENG: Declaration of a file descriptor variable that will store an int number associated with the "INPUT FILE"
    //that is opened with OPEN to then read it and process it.
	int fd_in;
    
    //ESP: Declaro una variable de file descripto que guardara un numero int asociado al "ARCHIVO DE SALIDA" que se abre 
    //con OPEN para luego escribirlo y procesarlo.
    //ENG: Declaration of a file descriptor variable that will store an int number associated with the "OUTPUT FILE"
    //that is opened with OPEN to then write it and process it.
    int fd_out;
    
    //ESP: Declaro una variable puntero simple a FILE que almacena la direccion de comienzo de un "ARCHIVO DE ENTRADA" 
    //que se abre con fopen para luego leerlo y procesarlo.
    //ENG: Declaration of a simple pointer variable to FILE that stores the start address of an "INPUT FILE"
    //that is opened with fopen to then read it and process it.
    FILE *ptr_in = NULL;

    //ESP: Declaro una variable puntero simple a FILE que almacena la direccion de comienzo de un "ARCHIVO DE SALIDA"
    //que se abre con fopen para luego escribirlo y procesarlo.
    //ENG: Declaration of a simple pointer variable to FILE that stores the start address of an "OUTPUT FILE"
    //that is opened with fopen to then write it and process it.
    FILE *ptr_out = NULL;
    
    //ESP: Declaro una variable auxiliar para recibir lo que devuelve la funcion Impresion_Info_HeaderBMP().
    //ENG: Declaration of an auxiliary variable to receive what the function Impresion_Info_HeaderBMP() returns.
    int aux;
    
    //ESP: Proteccion contra cantidad insuficiente de argumentos de main.
    //ENG: Protection against insufficient number of main arguments.
	if(argc<2)
    {
        printf("falta imagen\n");
        return(0);
    }
    
    //ESP: Llamado a la funcion que lee de un archivo de entrada ".bmp", la informacion respectiva del header y tabla de colores si existiese, y la data de la imagen.
    //ENG: Call to the function that reads from an input file ".bmp", the respective header and color table information if it exists, and the image data.
    Lectura_Imagen( &p, &p1, &BufferDataImagen, argv[1], &fd_in );
   
   
    //ESP: Llamado a la funcion que imprime en pantalla la informacion del header.
    //ENG: Call to the function that prints the header information on the screen.
    aux = Impresion_Info_HeaderBMP(p);
    
    //ESP: Proteccion contra lo devuelto por la funcion Impresion_Info_HeaderBMP() + impresion de la informacion de la tabla de colores.
    //ENG: Protection against what is returned by the Impresion_Info_HeaderBMP() function + printing of the color table information.
    if( aux == TRUE )
    {
        printf(".\n.\n.\nSe imprimio correctamente la informacion del header del archivo BMP\n");
        
        if( p->TamPunto <=8 )
            printf("CantColoresPaleta: %.0f\n", powf( 2, (float)(p->TamPunto) ) * 4 );
        
        printf("Usted saltara ahora a la siguiente seccion del programa\n.\n.\n.\n");
       
    }
    else
    {   
        printf("Hubo algun error con la impresion del header\n");
        return 0;
    }
    
    //ESP: Una vez leido correctamente toda la informacion del header y de la tabla de colores(si existiese) entonces creo un menu recursivo con diferentes opciones para procesar la imagen ingresada.
    //ENG: Once all the header and color table information (if it exists) has been read correctly, I create a recursive menu with different options to process the entered image.
    int decision;
    int decisiondeteccion;

    //ESP: Declaro mascaras de 3x3 para usar en deteccion de bordes lineal.
    //ENG: Declare 3x3 masks to use in linear edge detection.
    int MascaraVertical[3][3] = {{-1,2,-1},
                                {-1,2,-1},
                                {-1,2,-1}
                                };
    int MascaraHorizontal[3][3] = {{-1,-1,-1},
                                   { 2,2,2},
                                   {-1,-1,-1}
                                  };
    int MascaraDiagonalIzq[3][3] = {{2,-1,-1},
                                    {-1,2,-1},
                                    {-1,-1,2}
                                   };
    int MascaraDiagonalDer[3][3] = {{-1,-1,2},
                                    {-1,2,-1},
                                    {2,-1,-1}
                                   };
    
    printf("Elija entre las siguientes operaciones de procesamiento de imagen\n");
    printf("\"A\"- Copiar imagen\n\"B\"- Conversion imagen RGB a Greyshade Scale\n\"C\"- Conversion Grayscale a BlancoyNegro\n\"D\"- Rotacion imagen\n\"E\"- Deteccion de bordes lineal\n");
    printf(" Si desea terminar de ingresar opciones de procesamiento de imagen, ingrese el caracter EOF (ctrl+d) al comienzo de un nuevo pedido de opcion de procesamiento: ");
    
    //ESP: EOF es con ctrl+d, armo un menu recursivo con while y switchcase.
    //ENG: EOF is with ctrl+d, I build a recursive menu with while and switchcase.
    while ( ( decision = getchar() ) != EOF ) 
    {
        switch(decision)
        {
            case 'A': case 'a':
            
                Copia_Imagen( &p, &p1, &BufferDataImagen, &fd_out );
                
                printf("Ha finalizado el procesamiento de imagen de la opcion \"A\". Ingrese otra opcion o el comando \"EOF\" para terminar: ");
                
                break;
                
            case 'B': case 'b':
                
                Conversion_RGB_a_Grayscale( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision );
                
                printf("Ha finalizado el procesamiento de imagen de la opcion \"B\". Ingrese otra opcion o el comando \"EOF\" para terminar: ");
                
                break;
                
            case 'C': case 'c':
                
                Conversion_Grayscale_a_BlancoyNegro( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision );
                
                printf("Ha finalizado el procesamiento de imagen de la opcion \"C\". Ingrese otra opcion o el comando \"EOF\" para terminar: ");
                 
                 break;
            
            case 'D': case 'd':
                
                Rotacion_Imagen( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision );
                
                printf("Ha finalizado el procesamiento de imagen de la opcion \"D\". Ingrese otra opcion o el comando \"EOF\" para terminar: ");
                
                break;
                
            case 'E': case 'e':
                
                do{
                    printf("Elija una de las siguientes detecciones lineales\n\"1\"- Vertical\n\"2\"- Horizontal\n\"3\"- Diagonal Izquierda\n\"4\"- Diagonal Derecha\n");
                    scanf("%d", &decisiondeteccion);
                    __fpurge(stdin);
                    
                    if( decisiondeteccion == 1 )
                        Deteccion_de_Bordes_lineal( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision, MascaraVertical);
                    else if( decisiondeteccion == 2 )
                            Deteccion_de_Bordes_lineal( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision, MascaraHorizontal);
                    else if( decisiondeteccion == 3 )
                            Deteccion_de_Bordes_lineal( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision, MascaraDiagonalIzq);
                    else if( decisiondeteccion == 4 )
                            Deteccion_de_Bordes_lineal( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision, MascaraDiagonalDer);
                    else if( decisiondeteccion != 1 && decisiondeteccion != 2 && decisiondeteccion != 3 && decisiondeteccion != 4 )
                        printf("Se ingreso incorrectamente una opcion\n");
                        
                }while( decisiondeteccion != 1 && decisiondeteccion != 2 && decisiondeteccion != 3 && decisiondeteccion != 4);
                
                printf("Ha finalizado el procesamiento de imagen de la opcion \"E\". Ingrese otra opcion o el comando \"EOF\" para terminar: ");
        
                break;
                 
            case '\n' : case ' ': //ESP: Ignora estas entradas de teclado. ENG: Ignore these keyboard inputs.
                   
                break;
                
            default: //ESP: Para todo el resto de caracteres tira un mensaje de error. ENG: For all other characters it throws an error message.
                   
                printf("Se ingreso incorrectamente una opcion\n");
                printf("Ingrese devuelta una de las opciones: ");
                    
                break;
        }
    }
    
    //ESP: Cierro files descriptos trabajdos en las funciones Lectura_Imagen y Copia_Imagen.
    //ENG: I close file descriptors worked on in the Lectura_Imagen and Copia_Imagen functions.
    close(fd_in);
    close(fd_out);
    
    //ESP: Libero memoria dinamica usada por las estructuras de DatosBMP y Paleta_de_colores(si existise).
    //ENG: I free dynamic memory used by the DatosBMP and Paleta_de_colores structures (if it exists).
    free(p);

    if( p->TamPunto <=8 )
        free(p1);
    
    //ESP: Libero memoria dinamica de buffer asociada a la data de imagen.
    //ENG: I free dynamic memory buffer associated with the image data.
    free(BufferDataImagen);
    
    return 0;
}




/* ESP
 * @brief Lee una imagen de un archivo BMP en memoria, incluyendo el encabezado, la tabla de colores (si existe) y los datos de la imagen.
 *        Esta función utiliza llamadas al sistema POSIX y descriptores de archivos.
 * 
 * @param p Puntero a un puntero a una estructura DatosBMP donde se almacenará la información del encabezado.
 * @param p1 Puntero a un puntero a una estructura Paleta_de_colores donde se almacenará la tabla de colores (si existe).
 * @param BufferDataImagen Puntero a un puntero a un array de unsigned char donde se almacenarán los datos de la imagen.
 * @param NombreDeImagen Puntero a un array de char que contiene el nombre del archivo BMP a leer.
 * @param fd_in Puntero a un descriptor de archivo entero para el archivo de entrada.
 */

/* ENG
 * @brief Reads an image from a BMP file into memory, including the header, color table (if it exists), and image data.
 *        This function uses POSIX system calls and file descriptors.
 * 
 * @param p Pointer to a pointer to a DatosBMP structure where the header information will be stored.
 * @param p1 Pointer to a pointer to a Paleta_de_colores structure where the color table will be stored (if it exists).
 * @param BufferDataImagen Pointer to a pointer to an unsigned char array where the image data will be stored.
 * @param NombreDeImagen Pointer to a char array containing the name of the BMP file to be read.
 * @param fd_in Pointer to an integer file descriptor for the input file.
 */

void Lectura_Imagen( DatosBMP **p, Paleta_de_colores **p1, unsigned char **BufferDataImagen, char *NombreDeImagen, int *fd_in )
{
    //ESP: Declaracion de punteros simples temporales para almacenar lo devuelto por malloc.
    //ENG: Declaration of simple temporary pointers to store what malloc returns.
    DatosBMP *PunteroTemporal = NULL;
    Paleta_de_colores *PunteroTemporal1 = NULL;
    unsigned char *PunteroTemporal2= NULL;
    
    //ESP: Declaro una variable que recibe lo que devuelve la funcion read().
    //ENG: Declare a variable that receives what the read() function returns.
    ssize_t bytesleidos;
    
    //ESP: Pido memoria dinamica para la estructura la cual almacenara la informacion del header del archivo BMP.
    //ENG: I request dynamic memory for the structure that will store the BMP file header information.
    PunteroTemporal = (DatosBMP *)malloc(sizeof(DatosBMP));
    
    //ESP: Proteccion contra NULL de malloc.
    //ENG: Protection against NULL from malloc.
    if( PunteroTemporal == NULL )
    {
        printf("Hay un error con la asignacion de memoria dinamica para la estructura asociada al header\n");
        exit(-1);
    }
    
    //ESP: Asignacion a "p" (del main), la direccion de comienzo del bloque de memoria dado por malloc para la estructura.
    //ENG: Assignment to "p" (from main), the start address of the memory block given by malloc for the structure.
    *p = PunteroTemporal;

    //ESP: Apertura del archivo de entrada bmp con funcion OPEN.
    //ENG: Opening of the input bmp file with OPEN.
	*fd_in=open(NombreDeImagen,O_RDONLY);
    
    //ESP: Proteccion contra apertura fallida del archivo.
    //ENG: Protection against failed file opening.
    if(*fd_in < 0)
    {
        printf("Error en apertura de archivo en funcion \"Lectura_Imagen\"\n");
        exit(-1);
    }

    //ESP: Este ciclo do-while esta para proteger de lectura fallida del reader, en caso de que el reader leea menos bytes de lo esperado por ejemplo.
    //ENG: This do-while loop is to protect against failed reader reading, in case the reader reads fewer bytes than expected for example.
    do{
        //ESP: Lectura del archivo bmp con funcion READ. Por proceso de lectura, la maquina copia todo el header del archivo y lo almacena en el espacio 
        //de memoria asignado a la estructura. Luego se accedera a este espacio a traves de los distintos miembros de la estructura para acceder de a 
        //grupos de bytes de acuerdo a las secciones del header.
        //ENG: Reading of the bmp file with the READ function. By reading process, the machine copies the entire header of the file and stores it in the space
        //of memory assigned to the structure. Then this space will be accessed through the different members of the structure to access groups of bytes according 
        //to the sections of the header.
        bytesleidos = read(*fd_in,*p,TamCabezera);
        printf("Cantidad de bytes leidos de cabezera: %ld\n", bytesleidos);
        
    }while(bytesleidos < TamCabezera);
    
    
    //ESP: Chequeo el valor de TamPunto, es decir, el bitdepth ya que me permite saber si hay o no tabla de colores. En caso de ser TRUE esta condicion, 
    //leo la informacion de la tabla de colores en un bloque de memoria dinamico.
    //ENG: I check the value of TamPunto, that is, the bitdepth since it allows me to know if there is a color table or not. In case this condition is TRUE,
    //I read the color table information into a dynamic memory block.
    if( (*p)->TamPunto <= 8)
    {
        //ESP: Pido memoria dinamica para la union la cual almacenara la informacion de la tabla de colores del archivo BMP.
        //ENG: I request dynamic memory for the union that will store the color table information of the BMP file.
        PunteroTemporal1 = (Paleta_de_colores *)malloc(sizeof(Paleta_de_colores));
        
        //ESP: Proteccion contra NULL de malloc.
        //ENG: Protection against NULL from malloc.
        if( PunteroTemporal1 == NULL )
        {
            printf("Hay un error con la asignacion de memoria dinamica para la union asociada a la tabla de colores\n");
            exit(-1);
        }
    
        //ESP: Asignacion a "p1" (del main), la direccion de comienzo del bloque de memoria dado por malloc para la union.
        //ENG: Assignment to "p1" (from main), the start address of the memory block given by malloc for the union.
        *p1 = PunteroTemporal1;
        
        //ESP: Este ciclo do-while esta para proteger de lectura fallida del reader, en caso de que el reader leea menos bytes de lo esperado por ejemplo.
        //ENG: This do-while loop is to protect against failed reader reading, in case the reader reads fewer bytes than expected for example.
        do{
            //ESP: Lectura del archivo bmp con funcion READ.
            //ENG: Reading of the bmp file with the READ function.
            bytesleidos = read(*fd_in,*p1,TamTotalColores);
            printf("Cantidad de bytes leidos de la tabla de colores: %ld\n", bytesleidos);
        }while(bytesleidos < TamTotalColores);
        
    }
    
    //ESP: Pido memoria dinamica para que durante otro proceso de lectura, entonces poder almacenar el resto de informacion del archivo que no son los 54 bytes 
    //del header ya que estos estan alamcenados en la estructura. El resto de informacion puede ser la imagen mas otras cosas.
    //La cantidad de memoria a pedir dependera del tamanio total del archivo menos el tamanio del header.
    //ENG: I request dynamic memory so that during another reading process, I can then store the rest of the file information that is not the 54 bytes
    //of the header since these are stored in the structure. The rest of the information can be the image plus other things.
    //The amount of memory to request will depend on the total size of the file minus the size of the header.
    PunteroTemporal2 = (unsigned char *)malloc( ( (*p)->TamARchivo - TamCabezera ) * sizeof(unsigned char) );
    
    //ESP: Proteccion contra NULL de malloc.
    //ENG: Protection against NULL from malloc.
    if( PunteroTemporal2 == NULL )
    {
        printf("Hay un error con la asignacion de memoria dinamica para el buffer de memoria asociado a la data de la imagen \n");
        exit(-1);
    }
    
    //ESP: Asignacion a "BufferDataImagen" (del main), la direccion de comienzo del bloque de memoria dado por malloc para la data de la imagen.
    //ENG: Assignment to "BufferDataImagen" (from main), the start address of the memory block given by malloc for the image data.
    *BufferDataImagen = PunteroTemporal2;

    //ESP: Realizo otro proceso de lectura pero ahora del resto del archivo donde la lectura de la maquina en este caso, consiste en copiar el resto del archivo 
    //y escribirlo en memoria. En este caso ese resto de archivo se copiara en memoria asignada dinamicamente, es decir, en BufferDataImagen.
    //ENG: I perform another reading process but now of the rest of the file where the machine reading in this case, consists of copying the rest of the file
    //and write it to memory. In this case that rest of the file will be copied to memory assigned dynamically, that is, to BufferDataImagen.
    do{
       bytesleidos = read(*fd_in,*BufferDataImagen,(*p)->TamImg);
       printf("Cantidad de bytes leidos de la DATA Imagen: %ld\n", bytesleidos);
    }while(bytesleidos < (*p)->TamImg);
    
    printf("Se llamo exitosamente a la funcion \"Lectura_Imagen\"\n.\n.\n.\n");
}




/* ESP
 * @brief Escribe el encabezado y la tabla de colores (si existe) en un archivo de salida y abre un archivo BMP de entrada, reposicionando el offset.
 *        Esto a traves de punteros a FILE y uso de "streams".
 * 
 * Esta función abre un archivo BMP de entrada y reposiciona el offset al inicio de los datos de la imagen. Luego abre un archivo BMP de salida
 * con un nombre basado en la opción de menú seleccionada en la función principal. La función verifica la apertura exitosa de los archivos de 
 * entrada y salida. Copia el encabezado y la tabla de colores (si existe) del archivo de entrada al archivo de salida.
 * 
 * @param p Puntero a una estructura DatosBMP que contiene la información del archivo BMP.
 * @param p1 Puntero a una estructura Paleta_de_colores que contiene la información de la tabla de colores.
 * @param ptr_in Puntero al flujo del archivo de entrada.
 * @param ptr_out Puntero al flujo del archivo de salida.
 * @param NombreDeImagen Nombre del archivo BMP de entrada.
 * @param decision Opción de menú seleccionada en la función principal para determinar el nombre del archivo de salida.
 */

/* ENG
 * @brief Writes the header and color table (if it exists) to an output file and opens an input BMP file, repositioning the offset.
 * 
 * This function opens an input BMP file and repositions the offset to the start of the image data. It then opens an output BMP file
 * with a name based on the menu option selected in the main function. The function checks for successful opening of the input and 
 * output files. It copies the header and color table (if it exists) from the input file to the output file.
 * 
 * @param p Pointer to a DatosBMP structure containing BMP file information.
 * @param p1 Pointer to a Paleta_de_colores structure containing color table information.
 * @param ptr_in Pointer to the input file stream.
 * @param ptr_out Pointer to the output file stream.
 * @param NombreDeImagen Name of the input BMP file.
 * @param decision Menu option selected in the main function to determine the output file name.
 */

void Escritura_Imagen_HeaderYTablaColores(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
    //ESP: Apertura del archivo de entrada bmp con funcion "fopen".
    //ENG: Opening of the input bmp file with the "fopen" function.
    *ptr_in = fopen(NombreDeImagen, "rb");

    //ESP: Reposicionamiento del offset del archivo de entrada. En principio al abrir el archivo, dicho offset esta ubicado en el byte 0 y a traves de "fseek" 
    //lo re-ubico en el nro de byte asociado al valor de InicioImagen almacenado dicho byte en la struct DatosBMP. 
    //Esto lo hago porque en algunas funciones como "Conversion_RGB_a_Grayscale" se requiere trabajar con puntero a FILE de archivo de entrada para manipular 
    //bytes de data de imagen y bytes de padding. Por lo que es necesario posicionar el offset del "stream" en la posicion adecuado dentro del bloque de informacion del archivo de entrada.
    //ENG: Repositioning of the input file offset. Initially when opening the file, this offset is located at byte 0 and through "fseek"
    //I relocate it in the byte number associated with the value of InicioImagen stored in that byte in the DatosBMP structure.
    //I do this because in some functions like "Conversion_RGB_a_Grayscale" it is required to work with a pointer to the FILE of the input file to manipulate
    //image data bytes and padding bytes. So it is necessary to position the "stream" offset at the appropriate position within the input file information block.
    fseek(*ptr_in,(*p)->InicioImagen, SEEK_CUR );
        
    //ESP: Algoritmo de apertura de achivo de salida bmp con funcion "fopen", con distintos nombres segun opcion de menu ingresada en main.
    //ENG: Algorithm for opening the output bmp file with the "fopen" function, with different names depending on the menu option entered in main.
    if( *decision == 'B' )
        *ptr_out = fopen("copia_RGB_a_Grayscale.bmp", "wb");
    else if( *decision == 'C' )
        *ptr_out = fopen("copia_Grayscale_a_BlancoyNegro.bmp", "wb");
    else if ( *decision == 'D' )
        *ptr_out = fopen("copia_Rotacion.bmp", "wb");
    else if ( *decision == 'E' )
        *ptr_out = fopen("copia_Deteccion_de_Bordes_lineal.bmp", "wb");
    
    //ESP: Chequeo de correcta apertura de archivos de entrada y salida.
    //ENG: Check of correct opening of input and output files.
    if (!ptr_in || !ptr_out)
    {
        printf("Error en apertura de archivos de salida y entrada en funcion \"Conversion_RGB_a_Grayscale\".\n");
        exit(-1);
    }
    
    //ESP: Copiado de cabecera usando la funcion "fwrite" para realizar el copiado de todos los bytes del header almacenados en la struct DatosBMP. 
    //Estos bytes ahora copiados se escriben en el archivo de salida.
    //ENG: Copying of the header using the "fwrite" function to copy all the bytes of the header stored in the DatosBMP structure.
    //These bytes now copied are written to the output file.
    fwrite(*p,sizeof(unsigned char),TamCabezera,*ptr_out);
    
    //ESP: Copiado de tabla de colores(si existiese) usando la funcion "fwrite". Los bytes se encuentran en la struct Paleta_de_colores y estos bytes ahora 
    //copiados se escriben en el archivo de salida y a continuacion de los bytes del header.
    //ENG: Copying of the color table (if it exists) using the "fwrite" function. The bytes are in the Paleta_de_colores structure and these bytes now copied
    //are written to the output file and after the header bytes.
    if( (*p)->TamPunto <= 8 )
        fwrite(*p1,sizeof(unsigned char),TamTotalColores,*ptr_out);
    
    printf("Se llamo exitosamente a la funcion \"Escritura_Imagen_HeaderYTablaColores\"\n.\n.\n.\n");
}

//Funcion que copia escribiendo en un archivo de salida el header, la tabla de colores(si existiese) y la data de la imagen. Esto a traves de POSIX system calls y file descriptos
void Copia_Imagen( DatosBMP **p, Paleta_de_colores **p1, unsigned char **BufferDataImagen, int *fd_out )
{
    //Apertura del archivo de salida bmp con funcion OPEN 
    *fd_out = open("copia.bmp", O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    //Copiado de cabecera usando la funcion WRITE para realizar el copiado de todos los bytes del header almacenados en la struct DatosBMP. Estos bytes ahora copiados se escriben en el archivo de salida
    write(*fd_out,*p,TamCabezera);
    
    //Copiado de tabla de colores(si existiese) usando la funcion WRITE. Los bytes se encuentran en la struct Paleta_de_colores y estos bytes ahora copiados se escriben en el archivo de salida y a continuacion de los bytes del header
    if( (*p)->TamPunto <= 8 )
        write(*fd_out,*p1,TamTotalColores);
    
    //Copiado de la data de la imagen usando la funcion WRITE. Estos bytes se encuentran en un buffer de memoria dinamico temporal y estos bytes ahora copiados se escriben en el archivo de salida y a continuacion de la tabla de colores(si existiese) sino a continuacion de la informacion del header 
    write(*fd_out,*BufferDataImagen,( (*p)->TamARchivo ) - TamCabezera);
    
    printf("Se llamo exitosamente a la funcion \"Copia_Imagen\"\n.\n.\n.\n");
}

//Funcion que converite una imagen bmp en colores de mezcla RGB a una imagen bmp en colores de escala de grises. Esto a traves de punteros a FILE y uso de "streams" y del algoritmo de "Weighted Method",es decir, "Metodo de luminosidad" 
void Conversion_RGB_a_Grayscale(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
    //Declaro 3 variables de iteracion para ciclo for
    int y, x;
    
    //Llamo a funcion que escribe el header y tabla de colores en la imagen de salida y que usa archivo de entrada y cambia posicion de offset. Todo con streams y punteros a FILE
    Escritura_Imagen_HeaderYTablaColores(p, p1, ptr_in, ptr_out, NombreDeImagen, decision);
   
    //Declaro variables "stride=paso" y de "padding=relleno" y asigno sus valores en base a formulas para tamanio de pixel de 24 bits
    int stride = ((*p)->Ancho * 3 + 3) & ~3;
    int padding = stride - (*p)->Ancho * 3;
    printf("stride: %d\n", stride);
    printf("padding: %d\n", padding);
    
    //Algoritmo que transforma cada pixel de color mezclado de RGB a un pixel de color de GrayshadeScale y que realiza proceso de "padding", es decir, relleno de bytes asociados al color negro al final de cada fila de bytes completada con informacion asociada a GrayshadeScale. Para esto, se considera que cada pixel de color sera de 24 bit, entonces, tendra 3 bytes y donde cada byte esta asociado a un pequenio pixel de un color distinto RGB siendo 1er byte equivalente a "pixel rojo", 2do byte equivalente a "pixel verde", 3er byte equivalente a "pixel azul". Por lo que 3 pixeles pequenios de 8 bits cada uno, forman un pixel de color completo mezclado RGB de 24 bits. 
    //Cada byte de 1 pixel de data de imagen, es tomado del archivo de entrada y almacenado en principio en un array "pixel" donde cada elemento entonces sera un byte asociado a un color RGB. Luego a cada elemento del vector, es decir, a cada byte de cada color RGB lo multiplico por una constante siendo para el rojo el 0.3, para el verde el 0.59 y para el azul el 0.11. Luego sumo los resultados de dicha multiplicacion almacenandolos en una variable del tipo unsigned char llamada "gris". Despues, a traves de memset, se re-llena el array "pixel" por completo con todos bytes(3 en total) asociados sus valores al valor del byte "gris" el cual fue obtenido en la linea anterior. Como siguiente paso, se cargan esos bytes del array "pixel" ahora en el archivo de salida. Todos estos pasos se repiten para cada pixel de cada columna de la fila de estudio del archivo de entrada. Al finalizar la carga de cada fila en el archivo de salida y justo antes de comenzar la carga de la siguiente fila, se realiza entonces, un proceso de padding, es decir, un proceso de rellenado de nuevos pixeles todos con mismo valor constante. Dicho proceso se realiza a traves de leer del archivo de entrada, 1 item de data de imagen de tamanio igual al valor entero de padding y a partir de esto alamcenar dicho item de data, en el array "pixel" para luego tomar lo que hay en ese array y almacenarlo en el archivo de salida justo a continuacion de la fila cargada. Todo este procesidimiento se hace 1 vez por cada fila cargada para poder evitar recortes en la imagen y que al momento de aplicar filtros con mascaras se asegure que los valores de la mascara se "superpongan" todos en contacto con los distintos pixeles produciendo las modificaciones pertinentes y que por ende evitar asi que haya zonas de imagen donde los valores de las mascaras se superponen con la nada lo cual genera problemas.
   
    unsigned char pixel[3];
    for ( y = 0; y < (*p)->Altura; ++y)
    {
        for ( x = 0; x < (*p)->Ancho; ++x)
        {
            fread(pixel, 3, 1, *ptr_in);
            unsigned char gris = pixel[0] * 0.3 + pixel[1] * 0.58 + pixel[2] * 0.11;
            memset(pixel, gris, sizeof(pixel));
            fwrite(pixel, 3, 1, *ptr_out);
        }
        fread(pixel, padding, 1, *ptr_in);
        fwrite(pixel, padding, 1, *ptr_out);
    }
    
    //Cierro archivo de entrada y salida
    fclose(*ptr_in);
    fclose(*ptr_out);
    
    printf("Se llamo exitosamente a la funcion \"Conversion_RGB_a_Grayscale\"\n.\n.\n.\n");
}

//Funcion que convierte una imagen bmp en colores de escala de grises a una imagen bmp en blanco y negro. Esto a traves de punteros a FILE y uso de "streams" y del algoritmo de "binarizacion"
void Conversion_Grayscale_a_BlancoyNegro(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
    //Declaro puntero simple que apuntara a la direccion de comienzo de un buffer local de memoria dinamico de datos unsigned char dado por malloc
    unsigned char *BufferCopiaLocal = NULL;
    //Declaro puntero simple temporal que recibe lo devuelto por malloc
    unsigned char *PunteroTemporalLocal = NULL;
    //Declaro variable iterador de para ciclo for
    int i;
    
    //Llamo a funcion que escribe el header y tabla de colores en la imagen de salida y que usa archivo de entrada y cambia posicion de offset. Todo con streams y punteros a FILE
    Escritura_Imagen_HeaderYTablaColores(p, p1, ptr_in, ptr_out, NombreDeImagen, decision);
    
    //Pedido de memoria dinamico con malloc para almacenar la data imagen dinamicamente 
    PunteroTemporalLocal = (unsigned char*)malloc( ( (*p)->TamARchivo - TamCabezera ) * sizeof(unsigned char));
    
    //Proteccion contra NULL de malloc
    if( PunteroTemporalLocal == NULL )
    {
        printf("Hay un error con la asignacion de memoria dinamica para el buffer de memoria asociado a la data de la imagen \n");
        exit(-1);
    }
    
    //Asignacion a puntero simple "BufferCopiaLocal" de la direccion de comienzo del bloque de memeoria dinamico de data de imagen
    BufferCopiaLocal = PunteroTemporalLocal;
    
    //Lectura en memoria de la data imagen del archivo de entrada hacia el bloque de memoria dinamico apuntado por el puntero simple "BufferCopiaLocal"
    fread(BufferCopiaLocal,sizeof(unsigned char),(*p)->TamImg,*ptr_in);
    
    //Algoritmo de "binarizacion" de pixeles en Grayshadescale. A traves de ciclo for, se evalua el valor entero de cada pixel, si el valor supera el valor de umbral entonces se le asigna el valor entero de 1 asociado al blanco. Caso contrario se le asigna el valor de entero 0 asociado al negro. Cada modificacion de valor de pixel se hace sobre pixeles almacenados en el bloque de memoria apuntado por BufferCopiaLocal. Luego, una vez modificado este bloque de memoria dinamico local, se escribe toda esta informacion en el archivo de salida con la funcion "frwite".
    for( i = 0; i < (*p)->TamImg; i++ )
    {
        BufferCopiaLocal[i] = (BufferCopiaLocal[i]>UMBRAL)?BLANCO : NEGRO;
    }
    
    //Escritura en archivo de salida de la data imagen modificada en el bloque de memoria apuntado por BufferCopiaLocalIn. 
    fwrite(BufferCopiaLocal,sizeof(unsigned char),(*p)->TamImg,*ptr_out);
    
    //Cierro archivo de entrada y salida  
    fclose(*ptr_in);
    fclose(*ptr_out);
    
    //Liberacion de memoria dinamica usada por la data imagen 
    free(BufferCopiaLocal);
    
    printf("Se llamo exitosamente a la funcion \"Conversion_Grayscale_o_RGB_a_BlancoyNegro\"\n.\n.\n.\n");
}

void Rotacion_Imagen(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
    //Declaracion de array estatico de 2 dimensiones siendo AnchoXAlto, que almacena la data imagen del archivo de entrada
    unsigned char BufferCopiaLocalIn[(*p)->Ancho][(*p)->Altura];
    //Declaracion de array estatico de 2 dimensiones sinedo AnchoxAlto, que almacena la data imagen rotada para ser escrita en archivo de salida
    unsigned char BufferCopiaLocalOut[(*p)->Ancho][(*p)->Altura];
    //Declaracion de variables de iteracion para for
    int i,j;
    //Declaracion de variable que almacena valor de opcion para switchcase
    int decisionrotacion;
    
    //Llamo a funcion que escribe el header y tabla de colores en la imagen de salida y que usa archivo de entrada y cambia posicion de offset. Todo con streams y punteros a FILE
    Escritura_Imagen_HeaderYTablaColores(p, p1, ptr_in, ptr_out, NombreDeImagen, decision);
    
    //Lectura en memoria de la data imagen del archivo de entrada hacia el bloque de memoria estatico de 2 dimensiones BufferCopiaLocalIn
    fread(BufferCopiaLocalIn,sizeof(unsigned char),(*p)->TamImg,*ptr_in);
    
    //Pedido de opcion para menu
    printf("Elija el sentido de rotacion siendo:\n\"1\" 90° a izquierda\n\"2\" 90° a derecha\n\"3\" 180° a inversion\n");
    scanf("%i",&decisionrotacion);
    __fpurge(stdin);
    
    //Menu no recursivo de opciones de rotacion de imagen. La rotacion en un sentido u otro no lo hago a traves de transformacion lineal sino a partir de asignar cada pixel del array BufferCopiaLocalIn de 2D en el array BufferCopiaLocalOut de 2D pero ubicando cada uno de ellos en las coordenadas x e y asociadas a los indexes "i e j" modificados matematicamente en array BufferCopiaLocalOut de 2D durante la asignacion. Dicho proceso de asignacion se ejecuta a traves de 2 ciclos for por cada case de rotacion debido a que los pixeles se encuentran ubicados en arreglos de 2D 

    //Es importante destacar que la rotacion solo funciona para imagenes cuya dimension en alto y ancho es la misma. Ej para la imagen de lena 512 x 512 funciona pero para la imagen de goldhill de 720x576 entonces no funciona y asi fuese de 576x720 tampoco funcionara
    switch(decisionrotacion)
    {
        case 1:  //Rotacion 90° a izquierda en imagen de salida. Si armo una matrix de 2D se puede ver que las filas de pixeles rotan en realidad hacia la derecha pero en la imagen de salida el efecto visual es de rotacion a la izquierda. Esto tiene que ver con el margen de referencia que se tome de la imagen original. En este caso, el margen de referencia a tomar seria el margen izquierdo de la imagen original, siguiendo la rotacion a derecha a nivel imagen, vemos que el margen izquierdo pasa a ser el margen inferior en la imagen de salida indicando que hubo una rotacion de 90 grados a derecha respecto de esta referencia. Sin embargo, a nivel matricial, el margen derecho de la matriz rota a izquierda 90 pasando a ser margen inferior en la matriz.
            
            for( i = 0; i < (*p)->Ancho; i++)
            {
                for( j = 0; j < (*p)->Altura; j++)
                {
                    BufferCopiaLocalOut[j][(*p)->Altura-1-i] = BufferCopiaLocalIn[i][j];
                }
            }
            
            break;
            
        case 2:  //Rotacion 90° a derecha + efecto espejo en imagen de salida. Si armo una matrix de 2D se puede ver que las filas de pixeles rotan en realidad hacia la izquierda pero en la imagen de salida el efecto visual es de rotacion a la derecha. Esto tiene que ver con el margen de referencia que se tome de la imagen original. En este caso, el margen de referencia a tomar seria el margen derecho de la imagen original, siguiendo la rotacion a izquierda con espejado a nivel imagen, vemos que el margen derecho pasa a ser el margen superior de la imagen de salida indicando que hubo una rotacion de 90 grados a derecha con espejado respecto de esta referencia. Sin embargo, a nivel matricial, el margen derecho de la matriz rota a derecha 90 y se espeja pasando a ser margen inferior en la matriz
            
            for( i = 0; i < (*p)->Ancho; i++)
            {
                for( j = 0; j < (*p)->Altura; j++)
                {
                    BufferCopiaLocalOut[j][i] = BufferCopiaLocalIn[i][j];
                }
            }
            
            break;
            
        case 3: //Rotacion 180° a inversion. Si armo una matriz de 2D se puede ver que las filas superiores pasan a ocupar los lugares de las filas inferiores y viceversa pero sin modificar la ubicaciones de las filas intermedias. En la imagen de salida se produce un efecto de inversion a 180 grados. Se puede pensar que en este caso a nivel imagen y a nivel matricial se respeta la misma logica en cuanto a la referencia a tomar, siendo por ejemplo en este caso el margen superior de la imagen y a nivel martricial tambien. Vemos que este margen superior pasa a ser el margen inferior y viceversa. Pero el centro de la imagen y de la matriz se mantiene sin modificaciones
        
            for( i = 0; i < (*p)->Ancho; i++)
            {
                for( j = 0; j < (*p)->Altura; j++)
                {
                    BufferCopiaLocalOut[(*p)->Ancho-1-i][j] = BufferCopiaLocalIn[i][j];
                }
            }
            
            break;
            
        case '\n' : case ' ': //ignora estas entradas de teclado
                   
            break;
                
        default: //Para todo el resto de caracteres tira un mensaje de error
                   
                printf("Se ingreso incorrectamente una opcion de rotacion\n");
                printf("Ingrese devuelta una de las opciones: ");
                    
            break;
    }
    
    //Escritura en archivo de salida de la data imagen modificada en el bloque de memoria BufferCopiaLocalOut de 2D.
    fwrite(BufferCopiaLocalOut,sizeof(unsigned char),(*p)->TamImg,*ptr_out);
    
    //Cierro archivo de entrada y salida
    fclose(*ptr_in);
    fclose(*ptr_out);
    
     printf("Se llamo exitosamente a la funcion \"Rotacion_Imagen\"\n.\n.\n.\n");
}

//Funcion que realiza la deteccion de bordes de una imagen bmp de entrada a partir del uso de mascaras como matrizes de 2D de 3x3
void Deteccion_de_Bordes_lineal(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision, int Mascara[][3])
{
    //Declaracion de array estatico de 1 dimension de TamImg, que almacena la data imagen del archivo de entrada
    unsigned char BufferCopiaLocalIn[(*p)->TamImg];
    //Declaracion de array estatico de 1 dimension de TamImg, que almacena la data imagen modificada para ser escrita en archivo de salida
    unsigned char BufferCopiaLocalOut[(*p)->TamImg];
    //Declaracion de variables de iteracion para ciclo for
    int x,y,i,j,sum;
    
    //Llamo a funcion que escribe el header y tabla de colores en la imagen de salida y que usa archivo de entrada y cambia posicion de offset. Todo con streams y punteros a FILE
    Escritura_Imagen_HeaderYTablaColores(p, p1, ptr_in, ptr_out, NombreDeImagen, decision);
    
    //Lectura en memoria de la data imagen del archivo de entrada hacia el bloque de memoria estatico de 1 dimensiones BufferCopiaLocalIn
    fread(BufferCopiaLocalIn,sizeof(unsigned char),(*p)->TamImg,*ptr_in);
    
    //Algoritmo que realiza la deteccion de bordes a partir de una mascara y operaciones de multiplicacion, donde esta mascara es un array de 2D de 3x3 con valores pre-cargados. Se busca evaluar que sucede con un "vecindario" de pixeles de 3x3 respecto a un pixel central. Dicho algoritmo utiliza 4 ciclos for. El 1ero y el 2do es para recorrer todas las filas y las columnas en busqueda de un pixel central siendo que la posicion de dicho pixel central de un vecindario este dado por "BufferCopiaLocalOut+x+(long)y * ((*p)->Ancho)". Luego el 3ero y el 4to que realizan una sumatoria de resultados dados por las operaciones de la linea 593 tal que se obtiene un valor resultante de todas las operacoiones de todos los pixeles de un "neighborhood" respecto al pixel central estudiado. Dicho valor resultante del vecindario se evalua al finalizar el 3er y 4to for, en la evaluacion se determina si el pixel central asumira el valor de "encendido o blanco(255)" o el valor de "apagado o negro(0)". Repitiendo esto sucesivamente para todos los pixeles de una imagen, se podra tener entonces los "bordes" o delineados bien marcados en la imagen de salida. Cabe aclarar que la imagen de estudio debe estar en escala de grises obligatoriamente.

    for(y = 1; y < (*p)->Altura-1; y++)
    {
        for(x = 1; x < (*p)->Ancho-1; x++)
        {
            sum = 0;
            for(i = -1; i <= 1; i++)
            {
                for(j = -1; j <= 1; j++)
                {
                    sum = sum + *(BufferCopiaLocalIn+x+i+(long)(y+j) * ((*p)->Ancho) ) * Mascara[i+1][j+1];
                }
            }
            if(sum > 255) sum = 255;
            if(sum < 0) sum = 0;
            *(BufferCopiaLocalOut+x+(long)y * ((*p)->Ancho)) = sum;
        }
    }
    
    //Escritura en archivo de salida de la data imagen modificada en el bloque de memoria BufferCopiaLocalOut de 2D.
    fwrite(BufferCopiaLocalOut,sizeof(unsigned char),(*p)->TamImg,*ptr_out);
    
    
    //Cierro archivo de entrada y salida
    fclose(*ptr_in);
    fclose(*ptr_out);
    
    printf("Se llamo exitosamente a la funcion \"Deteccion_de_Bordes_lineal\"\n.\n.\n.\n");
}

//Funcion que imprime en pantalla la informacion del header a traves del uso de estructura y sus miembros
int Impresion_Info_HeaderBMP(DatosBMP *p)
{
    printf("Tipo de Archivo: %c%c\n",p->TipoArchivo[0],p->TipoArchivo[1]);
	printf("Tamaño de archivo: %d\n",p->TamARchivo);
	printf("Reservado1:%d\n",p->Reservado1);
	printf("Reservado2:%d\n",p->Reservado2);
	printf("Inicio de la Imagen:%d\n",p->InicioImagen);
	printf("Tamaño Total de la Cabecera:%d\n",p->TamTotalCabezera);
	printf("Ancho de la Imagen:%d\n",p->Ancho);
	printf("Altura de la Imagen:%d\n",p->Altura);
	printf("Numero de Planos:%d\n",p->NumPlanos);
	printf("Tamaño del Punto:%d\n",p->TamPunto);
	printf("Compresión:%d\n",p->Compresion);
	printf("Tamaño de la Imagen:%d\n",p->TamImg);
	printf("Resolución Horizontal:%d\n",p->ResoHorizontal);
	printf("Resolución Vertical:%d\n",p->ResoVertical);
	printf("Tamaño Tabla de Colores:%d\n",p->TamTablaColores);
	printf("Contador de Colores:%d\n",p->ContColores);
    
    return TRUE;
}
    
