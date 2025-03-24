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

/**
* ESP:
* @brief Proyecto creado en un único archivo main.c y un .h cuyo programa realiza un procesamiento de imagen BMP.
*
*/

/**
* ENG:
* @brief Project created in a single file main.c and a .h whose program performs BMP image processing.
* 
*/


/**
* ESP:
* La directiva `#pragma pack(1)` se usa para cambiar la alineación predeterminada de estructuras, uniones y clases a 1 byte. Esto significa que el compilador
* empaquetará los miembros de estas estructuras de datos con una alineación de 1 byte, lo que puede
* reducir el tamaño de la estructura al eliminar los bytes de relleno. Sin embargo,
* también puede generar pérdidas de rendimiento en algunas arquitecturas debido a accesos a memoria desalineados.
*/

/**
 * ENG:
 * The `#pragma pack(1)` directive is used to change the default alignment of 
 * structures, unions, and classes to 1 byte. This means that the compiler will 
 * pack the members of these data structures with a 1-byte alignment, which can 
 * reduce the size of the structure by eliminating padding bytes. However, it 
 * may also lead to performance penalties on some architectures due to 
 * misaligned memory accesses.
 */

#pragma pack(1)




/**
 * ESP:
 * @brief Estructura que define la cabecera de un archivo BMP.
 *        Contiene información sobre el tipo de archivo, tamaño, dimensiones, etc.
 */

/** 
 * ENG:
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




/**
 * ESP:
 * @brief Unión que define la tabla de colores de un archivo BMP.
 *        Contiene la paleta de colores del archivo.
 */

/**
 * ENG:
 * @brief Union that defines the color table of a BMP file.
 *        Contains the color palette of the file.
 */

typedef union TablaColores
{
    unsigned char CantColoresPaleta[TamTotalColores];
}Paleta_de_colores;




/**
 * ESP:
 * La directiva `#pragma pack(4)` se usa para cambiar la alineación predeterminada de estructuras, uniones y clases a 4 bytes. Esto significa que el compilador
 * empaquetará los miembros de estas estructuras de datos con una alineación de 4 bytes, lo que puede
 * reducir el tamaño de la estructura al eliminar algunos bytes de relleno. Sin embargo,
 * también puede generar pérdidas de rendimiento en algunas arquitecturas debido a accesos a memoria desalineados.
 */

/**
 * ENG:
 * The `#pragma pack(4)` directive is used to change the default alignment of 
 * structures, unions, and classes to 4 bytes. This means that the compiler will 
 * pack the members of these data structures with a 4-byte alignment, which can 
 * reduce the size of the structure by eliminating some padding bytes. However, it 
 * may also lead to performance penalties on some architectures due to 
 * misaligned memory accesses.
 */

#pragma pack(4)

//ESP: Declaracion de prototipos de funcion.
//ENG: Declaration of function prototypes.
void Lectura_Imagen( DatosBMP **p, Paleta_de_colores **p1, unsigned char **BufferDataImagen, 
char *NombreDeImagen, int *fd_in );
int Impresion_Info_HeaderBMP(DatosBMP *p);
void Escritura_Imagen_HeaderYTablaColores(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision);
void Copia_Imagen( DatosBMP **p, Paleta_de_colores **p1, unsigned char **BufferDataImagen, int *fd_out );
void Conversion_RGB_a_Grayscale(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision);
void Conversion_Grayscale_a_BlancoyNegro(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision);
void Rotacion_Imagen(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision);
void Deteccion_de_Bordes_lineal(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision, int Mascara[][3]);




/**
 * ESP:
 * @brief Función principal que realiza el procesamiento de imágenes BMP.
 *        Lee un archivo BMP, imprime su información de encabezado, y ofrece un menú de opciones para procesar la imagen.
 *        Las opciones incluyen copiar la imagen, convertir a escala de grises, convertir a blanco y negro,
 *        rotar la imagen, y aplicar detección lineal de bordes.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Vector de cadenas que contiene los argumentos pasados al programa.
 * 
 * La función realiza las siguientes operaciones:
 * 1. Lee la imagen BMP y almacena la información del encabezado, la tabla de colores (si existe) y los datos de la imagen.
 * 2. Imprime la información del encabezado de la imagen BMP.
 * 3. Ofrece un menú de opciones para procesar la imagen:
 *    a. Copiar la imagen.
 *    b. Convertir la imagen a escala de grises.
 *    c. Convertir la imagen a blanco y negro.
 *    d. Rotar la imagen.
 *    e. Aplicar detección lineal de bordes.
 * 4. Procesa la imagen según la opción seleccionada.
 * 5. Libera la memoria dinámica utilizada.
 * 6. Cierra los archivos abiertos.
 */

/**
 * ENG:
 * @brief Main function that performs BMP image processing.
 *        Reads a BMP file, prints its header information, and offers a menu of options to process the image.
 *        The options include copying the image, converting to grayscale, converting to black and white,
 *        rotating the image, and performing linear edge detection.
 * 
 * @param argc Number of arguments passed to the program.
 * @param argv Array of strings containing the arguments passed to the program.
 * 
 * The function performs the following operations:
 * 1. Reads the BMP image and stores the header information, color table (if it exists), and image data.
 * 2. Prints the BMP image header information.
 * 3. Offers a menu of options to process the image:
 *    a. Copy the image.
 *    b. Convert the image to grayscale.
 *    c. Convert the image to black and white.
 *    d. Rotate the image.
 *    e. Perform linear edge detection.
 * 4. Processes the image according to the selected option.
 * 5. Frees the used dynamic memory.
 * 6. Closes the opened files.
 */

int main( int argc, char *argv[])
{
    //ESP: Creacion de puntero "p" para almacenar direccion de estructura DatosBMP.
    //ENG: Create pointer "p" to store address of DatosBMP structure.
    DatosBMP *p = NULL;
    
    //ESP: Creacion de puntero "p1" para almacenar la direccion de la tabla de colores.
    //ENG: Create pointer "p1" to store the address of the color table.
    Paleta_de_colores *p1 = NULL;
    
    //ESP: Puntero para almacenar la data de la imagen.
    //ENG: Pointer to store the image data.
    unsigned char *BufferDataImagen = NULL;
    
    //ESP: Variable descriptor de archivo para el archivo de entrada.
    //ENG: File descriptor variable for the input file.
    int fd_in;
    
    //ESP: Variable descriptor de archivo para el archivo de salida.
    //ENG: File descriptor variable for the output file.
    int fd_out;
    
    //ESP: Puntero a FILE para abrir y leer un archivo de entrada.
    //ENG: FILE pointer to open and read an input file.
    FILE *ptr_in = NULL;

    //ESP: Declaro puntero a FILE para archivo de salida.
    //ENG: Declare FILE pointer for output file.
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
            case 'A': case 'a': //ESP: Copiar imagen. ENG: Copy image.
            
                Copia_Imagen( &p, &p1, &BufferDataImagen, &fd_out );
                
                printf("Ha finalizado el procesamiento de imagen de la opcion \"A\". Ingrese otra opcion o el comando \"EOF\" para terminar: ");
                
                break;
                
            case 'B': case 'b': //ESP: Conversion imagen RGB a Greyshade Scale. ENG: Conversion image RGB to Greyshade Scale.
                
                Conversion_RGB_a_Grayscale( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision );
                
                printf("Ha finalizado el procesamiento de imagen de la opcion \"B\". Ingrese otra opcion o el comando \"EOF\" para terminar: ");
                
                break;
                
            case 'C': case 'c': //ESP: Conversion Grayscale a BlancoyNegro. ENG: Conversion Grayscale to BlackandWhite.
                
                Conversion_Grayscale_a_BlancoyNegro( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision );
                
                printf("Ha finalizado el procesamiento de imagen de la opcion \"C\". Ingrese otra opcion o el comando \"EOF\" para terminar: ");
                 
                 break;
            
            case 'D': case 'd': //ESP: Rotacion imagen. ENG: Image rotation.
                
                Rotacion_Imagen( &p, &p1, &ptr_in, &ptr_out, argv[1], &decision );
                
                printf("Ha finalizado el procesamiento de imagen de la opcion \"D\". Ingrese otra opcion o el comando \"EOF\" para terminar: ");
                
                break;
                
            case 'E': case 'e': //ESP: Deteccion de bordes lineal. ENG: Linear edge detection.
                
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




/** 
 * ESP
 * @brief Lee una imagen de un archivo BMP en memoria, incluyendo el encabezado, la tabla de colores (si existe) y los datos de la imagen.
 *        Esta función utiliza llamadas al sistema POSIX y descriptores de archivos.
 * 
 * @param p Puntero a un puntero a una estructura DatosBMP donde se almacenará la información del encabezado.
 * @param p1 Puntero a un puntero a una estructura Paleta_de_colores donde se almacenará la tabla de colores (si existe).
 * @param BufferDataImagen Puntero a un puntero a un array de unsigned char donde se almacenarán los datos de la imagen.
 * @param NombreDeImagen Puntero a un array de char que contiene el nombre del archivo BMP a leer.
 * @param fd_in Puntero a un descriptor de archivo entero para el archivo de entrada.
 *
 * La función realiza las siguientes operaciones:
 * 1. Solicita memoria dinámica para almacenar el encabezado y la tabla de colores (si existe).
 * 2. Abre el archivo BMP de entrada utilizando la llamada al sistema open().
 * 3. Lee el encabezado del archivo BMP y lo almacena en la estructura DatosBMP.
 * 4. Si la imagen tiene una tabla de colores (profundidad de color <= 8), lee la tabla de colores y la almacena en la estructura Paleta_de_colores.
 * 5. Solicita memoria dinámica para almacenar los datos de la imagen.
 * 6. Lee los datos de la imagen del archivo BMP y los almacena en el buffer de datos de la imagen.
 * 7. Imprime mensajes indicando la cantidad de bytes leídos en cada paso.
 * 8. Imprime un mensaje indicando que la función se ejecutó exitosamente.
 */

/** 
 * ENG
 * @brief Reads an image from a BMP file into memory, including the header, color table (if it exists), and image data.
 *        This function uses POSIX system calls and file descriptors.
 * 
 * @param p Pointer to a pointer to a DatosBMP structure where the header information will be stored.
 * @param p1 Pointer to a pointer to a Paleta_de_colores structure where the color table will be stored (if it exists).
 * @param BufferDataImagen Pointer to a pointer to an unsigned char array where the image data will be stored.
 * @param NombreDeImagen Pointer to a char array containing the name of the BMP file to be read.
 * @param fd_in Pointer to an integer file descriptor for the input file.
 *
 * The function performs the following operations:
 * 1. Allocates dynamic memory to store the header and color table (if it exists).
 * 2. Opens the input BMP file using the open() system call.
 * 3. Reads the BMP file header and stores it in the DatosBMP structure.
 * 4. If the image has a color table (color depth <= 8), reads the color table and stores it in the Paleta_de_colores structure.
 * 5. Allocates dynamic memory to store the image data.
 * 6. Reads the image data from the BMP file and stores it in the image data buffer.
 * 7. Prints messages indicating the number of bytes read at each step.
 * 8. Prints a message indicating that the function was successfully called.
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
        //ESP: Lectura del archivo bmp con READ, copiando el header al espacio de memoria asignado a la estructura.
        //ENG: Reading the bmp file with READ, copying the header to the memory space assigned to the structure.
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
    
    //ESP: Pido memoria dinamica para almacenar el resto del archivo que no es el header.
    //ENG: Allocate dynamic memory to store the rest of the file excluding the header.
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

    //ESP: Leo el resto del archivo y lo copio en memoria dinámica asignada a BufferDataImagen.
    //ENG: Read the rest of the file and copy it to dynamically allocated memory in BufferDataImagen.
    do{
       bytesleidos = read(*fd_in,*BufferDataImagen,(*p)->TamImg);
       printf("Cantidad de bytes leidos de la DATA Imagen: %ld\n", bytesleidos);
    }while(bytesleidos < (*p)->TamImg);
    
    printf("Se llamo exitosamente a la funcion \"Lectura_Imagen\"\n.\n.\n.\n");
}




/** 
 * ESP
 * @brief Escribe el encabezado y la tabla de colores (si existe) en un archivo de salida y abre un archivo BMP de entrada, reposicionando el offset.
 *        Esto a traves de punteros a FILE y uso de "streams".
 *
 * @param p Puntero a una estructura DatosBMP que contiene la información del archivo BMP.
 * @param p1 Puntero a una estructura Paleta_de_colores que contiene la información de la tabla de colores.
 * @param ptr_in Puntero al flujo del archivo de entrada.
 * @param ptr_out Puntero al flujo del archivo de salida.
 * @param NombreDeImagen Nombre del archivo BMP de entrada.
 * @param decision Opción de menú seleccionada en la función principal para determinar el nombre del archivo de salida.
 *
 * La función realiza las siguientes operaciones:
 * 1. Abre el archivo BMP de entrada y reposiciona el offset al inicio de los datos de la imagen.
 * 2. Abre un archivo BMP de salida con un nombre basado en la opción de menú seleccionada en la función principal.
 * 3. Verifica la apertura exitosa de los archivos de entrada y salida.
 * 4. Copia el encabezado y la tabla de colores (si existe) del archivo de entrada al archivo de salida.
 * 5. Imprime un mensaje indicando que la función se ejecutó exitosamente.
 */

/** 
 * ENG
 * @brief Writes the header and color table (if it exists) to an output file and opens an input BMP file, repositioning the offset.
 *        This is done through FILE pointers and streams.
 *
 * @param p Pointer to a DatosBMP structure containing BMP file information.
 * @param p1 Pointer to a Paleta_de_colores structure containing color table information.
 * @param ptr_in Pointer to the input file stream.
 * @param ptr_out Pointer to the output file stream.
 * @param NombreDeImagen Name of the input BMP file.
 * @param decision Menu option selected in the main function to determine the output file name.
 *
 * The function performs the following operations:
 * 1. Opens the input BMP file and repositions the offset to the start of the image data.
 * 2. Opens an output BMP file with a name based on the menu option selected in the main function.
 * 3. Checks for successful opening of the input and output files.
 * 4. Copies the header and color table (if it exists) from the input file to the output file.
 * 5. Prints a message indicating that the function was successfully called.
 */

void Escritura_Imagen_HeaderYTablaColores(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
    //ESP: Apertura del archivo de entrada bmp con funcion "fopen".
    //ENG: Opening of the input bmp file with the "fopen" function.
    *ptr_in = fopen(NombreDeImagen, "rb");

    //ESP: Reposiciona el offset del archivo de entrada al InicioImagen en DatosBMP con "fseek" para manipular datos de imagen y padding.
    //ENG: Repositions the input file offset to InicioImagen in DatosBMP using "fseek" to manipulate image data and padding.
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
    
    //ESP: Copiado del header de la estructura DatosBMP al archivo de salida usando "fwrite".
    //ENG: Copy the header from the DatosBMP structure to the output file using "fwrite".
    fwrite(*p,sizeof(unsigned char),TamCabezera,*ptr_out);
    
    //ESP: Copia la tabla de colores (si existe) al archivo de salida usando "fwrite".
    //ENG: Copies the color table (if it exists) to the output file using "fwrite".
    if( (*p)->TamPunto <= 8 )
        fwrite(*p1,sizeof(unsigned char),TamTotalColores,*ptr_out);
    
    printf("Se llamo exitosamente a la funcion \"Escritura_Imagen_HeaderYTablaColores\"\n.\n.\n.\n");
}




/**
 * ESP
 * @brief Funcion que copia escribiendo en un archivo de salida el header, la tabla de colores (si existiese) y la data de la imagen.
 *        Esto se realiza a traves de llamadas al sistema POSIX y descriptores de archivos.
 *
 * @param p Puntero a un puntero de la estructura DatosBMP que contiene la cabecera de la imagen.
 * @param p1 Puntero a un puntero de la estructura Paleta_de_colores que contiene la tabla de colores (si existiese).
 * @param BufferDataImagen Puntero a un buffer que contiene los datos de la imagen.
 * @param fd_out Puntero a un descriptor de archivo donde se escribirá la copia de la imagen.
 *
 * La función realiza las siguientes operaciones:
 * 1. Abre el archivo de salida "copia.bmp" con permisos de lectura y escritura.
 * 2. Copia la cabecera de la imagen al archivo de salida.
 * 3. Si la imagen tiene una tabla de colores (profundidad de color <= 8), la copia al archivo de salida.
 * 4. Copia los datos de la imagen al archivo de salida.
 * 5. Imprime un mensaje indicando que la función se ejecutó exitosamente.
 */

/**
 * ENG
 * @brief Function that copies the header, color table (if it exists), and image data to an output file.
 *        This is done through POSIX system calls and file descriptors.
 *
 * @param p Pointer to a pointer of the DatosBMP structure containing the image header.
 * @param p1 Pointer to a pointer of the Paleta_de_colores structure containing the color table (if it exists).
 * @param BufferDataImagen Pointer to a buffer containing the image data.
 * @param fd_out Pointer to a file descriptor where the image copy will be written.
 *
 * The function performs the following operations:
 * 1. Opens the output file "copia.bmp" with read and write permissions.
 * 2. Copies the image header to the output file.
 * 3. If the image has a color table (color depth <= 8), copies it to the output file.
 * 4. Copies the image data to the output file.
 * 5. Prints a message indicating that the function was successfully called.
 */

void Copia_Imagen( DatosBMP **p, Paleta_de_colores **p1, unsigned char **BufferDataImagen, int *fd_out )
{
    //EPS: Apertura del archivo de salida bmp con funcion OPEN.
    //ENG: Opening of the output bmp file with the OPEN function. 
    *fd_out = open("copia.bmp", O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);

    //ESP: Copia la cabecera del archivo BMP al archivo de salida.
    //ENG: Copies the BMP file header to the output file.
    write(*fd_out,*p,TamCabezera);
    
    //ESP: Copia la tabla de colores (si existe) al archivo de salida.
    //ENG: Copies the color table (if it exists) to the output file.
    if( (*p)->TamPunto <= 8 )
        write(*fd_out,*p1,TamTotalColores);
    
    //ESP: Copia la data de la imagen desde el buffer temporal al archivo de salida.
    //ENG: Copies the image data from the temporary buffer to the output file.
    write(*fd_out,*BufferDataImagen,( (*p)->TamARchivo ) - TamCabezera);
    
    printf("Se llamo exitosamente a la funcion \"Copia_Imagen\"\n.\n.\n.\n");
}




/** 
 * ESP
 * @brief Funcion que convierte una imagen bmp en colores de mezcla RGB a una imagen bmp en colores de escala de grises.
 *        Esto se realiza a traves de punteros a FILE y uso de "streams" y del algoritmo de "Weighted Method", es decir, "Metodo de luminosidad".
 *
 * @param p Puntero a un puntero de la estructura DatosBMP que contiene la cabecera de la imagen.
 * @param p1 Puntero a un puntero de la estructura Paleta_de_colores que contiene la tabla de colores (si existiese).
 * @param ptr_in Puntero a un puntero de archivo de entrada.
 * @param ptr_out Puntero a un puntero de archivo de salida.
 * @param NombreDeImagen Puntero a un string que contiene el nombre de la imagen.
 * @param decision Puntero a un entero que indica alguna decision (no especificada en el codigo).
 *
 * La función realiza las siguientes operaciones:
 * 1. Llama a una función que escribe el header y la tabla de colores en la imagen de salida.
 * 2. Calcula el stride y el padding para el tamaño de pixel de 24 bits.
 * 3. Transforma cada pixel de color mezclado de RGB a un pixel de color de escala de grises usando el "Weighted Method".
 * 4. Realiza el proceso de padding al final de cada fila de bytes.
 * 5. Cierra los archivos de entrada y salida.
 * 6. Imprime un mensaje indicando que la función se ejecutó exitosamente.
 */

/** 
 * ENG
 * @brief Function that converts a bmp image from RGB mixed colors to a bmp image in grayscale colors.
 *        This is done through FILE pointers and streams using the "Weighted Method" algorithm, also known as "Luminosity Method".
 *
 * @param p Pointer to a pointer of the DatosBMP structure containing the image header.
 * @param p1 Pointer to a pointer of the Paleta_de_colores structure containing the color table (if it exists).
 * @param ptr_in Pointer to a pointer of the input file.
 * @param ptr_out Pointer to a pointer of the output file.
 * @param NombreDeImagen Pointer to a string containing the image name.
 * @param decision Pointer to an integer indicating some decision (not specified in the code).
 *
 * The function performs the following operations:
 * 1. Calls a function that writes the header and color table to the output image.
 * 2. Calculates the stride and padding for the 24-bit pixel size.
 * 3. Transforms each mixed RGB color pixel to a grayscale color pixel using the "Weighted Method".
 * 4. Performs the padding process at the end of each row of bytes.
 * 5. Closes the input and output files.
 * 6. Prints a message indicating that the function was successfully called.
 */

void Conversion_RGB_a_Grayscale(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
    //ESP: Declaro 3 variables de iteracion para ciclo for.
    //ENG: Declare 3 iteration variables for the for loop.
    int y, x;
    
    //ESP: Llama a función que escribe el header y tabla de colores en la imagen de salida usando streams y punteros a FILE.
    //ENG: Calls a function that writes the header and color table to the output image using streams and FILE pointers.
    Escritura_Imagen_HeaderYTablaColores(p, p1, ptr_in, ptr_out, NombreDeImagen, decision);
   
    //ESP: Declaro variables "stride=paso" y de "padding=relleno" y asigno sus valores en base a formulas para tamanio de pixel de 24 bits.
    //ENG: I declare "stride" and "padding" variables and assign their values based on formulas for 24-bit pixel size.
    int stride = ((*p)->Ancho * 3 + 3) & ~3;
    int padding = stride - (*p)->Ancho * 3;
    printf("stride: %d\n", stride);
    printf("padding: %d\n", padding);
    
    //ESP: Algoritmo que convierte cada pixel RGB a escala de grises y realiza el relleno de bytes al final de cada fila.
    //ENG: Algorithm that converts each RGB pixel to grayscale and performs byte padding at the end of each row.
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
    
    //ESP: Cierro archivo de entrada y salida.
    //ENG: I close the input and output files.
    fclose(*ptr_in);
    fclose(*ptr_out);
    
    printf("Se llamo exitosamente a la funcion \"Conversion_RGB_a_Grayscale\"\n.\n.\n.\n");
}




/** 
 * ESP
 * @brief Funcion que convierte una imagen bmp en colores de escala de grises a una imagen bmp en blanco y negro.
 *        Esto se realiza a traves de punteros a FILE y uso de "streams" y del algoritmo de "binarizacion".
 *
 * @param p Puntero a un puntero de la estructura DatosBMP que contiene la cabecera de la imagen.
 * @param p1 Puntero a un puntero de la estructura Paleta_de_colores que contiene la tabla de colores (si existiese).
 * @param ptr_in Puntero a un puntero de archivo de entrada.
 * @param ptr_out Puntero a un puntero de archivo de salida.
 * @param NombreDeImagen Puntero a un string que contiene el nombre de la imagen.
 * @param decision Puntero a un entero que indica alguna decision (no especificada en el codigo).
 *
 * La función realiza las siguientes operaciones:
 * 1. Llama a una función que escribe el header y la tabla de colores en la imagen de salida.
 * 2. Reserva memoria dinámica para almacenar los datos de la imagen.
 * 3. Lee los datos de la imagen del archivo de entrada en un buffer de memoria.
 * 4. Aplica el algoritmo de binarización para convertir los pixeles de escala de grises a blanco y negro.
 * 5. Escribe los datos modificados de la imagen en el archivo de salida.
 * 6. Cierra los archivos de entrada y salida.
 * 7. Libera la memoria dinámica utilizada.
 * 8. Imprime un mensaje indicando que la función se ejecutó exitosamente.
 */

/** 
 * ENG
 * @brief Function that converts a bmp image from grayscale colors to a bmp image in black and white.
 *        This is done through FILE pointers and streams using the "binarization" algorithm.
 *
 * @param p Pointer to a pointer of the DatosBMP structure containing the image header.
 * @param p1 Pointer to a pointer of the Paleta_de_colores structure containing the color table (if it exists).
 * @param ptr_in Pointer to a pointer of the input file.
 * @param ptr_out Pointer to a pointer of the output file.
 * @param NombreDeImagen Pointer to a string containing the image name.
 * @param decision Pointer to an integer indicating some decision (not specified in the code).
 *
 * The function performs the following operations:
 * 1. Calls a function that writes the header and color table to the output image.
 * 2. Allocates dynamic memory to store the image data.
 * 3. Reads the image data from the input file into a memory buffer.
 * 4. Applies the binarization algorithm to convert grayscale pixels to black and white.
 * 5. Writes the modified image data to the output file.
 * 6. Closes the input and output files.
 * 7. Frees the used dynamic memory.
 * 8. Prints a message indicating that the function was successfully called.
 */

void Conversion_Grayscale_a_BlancoyNegro(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
    //ESP: Declaro puntero simple para un buffer local de memoria dinámica de datos unsigned char.
    //ENG: Declare a simple pointer for a local dynamic memory buffer of unsigned char data.
    unsigned char *BufferCopiaLocal = NULL;

    //ESP: Declaro puntero temporal que recibe lo devuelto por malloc.
    //ENG: Declare a temporary pointer that receives what malloc returns.
    unsigned char *PunteroTemporalLocal = NULL;
    
    //ESP: Declaro variable iterador de para ciclo for.
    //ENG: Declare iterator variable for for loop.
    int i;
    
    //ESP: Escribe el header y la tabla de colores en la imagen de salida usando el archivo de entrada y cambia la posición del offset.
    //ENG: Writes the header and color table to the output image using the input file and changes the offset position.
    Escritura_Imagen_HeaderYTablaColores(p, p1, ptr_in, ptr_out, NombreDeImagen, decision);
    
    //ESP: Pedido de memoria dinamico con malloc para almacenar la data imagen dinamicamente. 
    //ENG: Request for dynamic memory with malloc to store the image data dynamically.
    PunteroTemporalLocal = (unsigned char*)malloc( ( (*p)->TamARchivo - TamCabezera ) * sizeof(unsigned char));
    
    //ESP: Proteccion contra NULL de malloc.
    //ENG: Protection against NULL from malloc.
    if( PunteroTemporalLocal == NULL )
    {
        printf("Hay un error con la asignacion de memoria dinamica para el buffer de memoria asociado a la data de la imagen \n");
        exit(-1);
    }
    
    //ESP: Asignacion a puntero simple "BufferCopiaLocal" de la direccion de comienzo del bloque de memeoria dinamico de data de imagen.
    //ENG: Assignment to simple pointer "BufferCopiaLocal" of the start address of the dynamic memory block of image data.
    BufferCopiaLocal = PunteroTemporalLocal;
    
    //ESP: Lectura en memoria de la data imagen del archivo de entrada hacia el bloque de memoria dinamico apuntado por el puntero simple "BufferCopiaLocal".
    //ENG: Reading in memory of the image data from the input file to the dynamic memory block pointed to by the simple pointer "BufferCopiaLocal".
    fread(BufferCopiaLocal,sizeof(unsigned char),(*p)->TamImg,*ptr_in);
    
    //ESP: Algoritmo de binarización que convierte cada pixel de escala de grises a blanco o negro según un umbral.
    //ENG: Binarization algorithm that converts each grayscale pixel to black or white based on a threshold.
    for( i = 0; i < (*p)->TamImg; i++ )
    {
        BufferCopiaLocal[i] = (BufferCopiaLocal[i]>UMBRAL)?BLANCO : NEGRO;
    }
    
    //ESP: Escritura en archivo de salida de la data imagen modificada en el bloque de memoria apuntado por BufferCopiaLocalIn.
    //ENG: Writing to the output file the modified image data in the memory block pointed to by BufferCopiaLocalIn.      
    fwrite(BufferCopiaLocal,sizeof(unsigned char),(*p)->TamImg,*ptr_out);
    
    //ESP: Cierro archivo de entrada y salida.
    //ENG: I close the input and output file.  
    fclose(*ptr_in);
    fclose(*ptr_out);
    
    //ESP: Liberacion de memoria dinamica usada por la data imagen.
    //ENG: Freeing dynamic memory used by the image data. 
    free(BufferCopiaLocal);
    
    printf("Se llamo exitosamente a la funcion \"Conversion_Grayscale_o_RGB_a_BlancoyNegro\"\n.\n.\n.\n");
}




/** 
 * ESP
 * @brief Funcion que rota una imagen bmp en colores de escala de grises en diferentes angulos.
 *        Esto se realiza a traves de punteros a FILE y uso de "streams".
 *
 * @param p Puntero a un puntero de la estructura DatosBMP que contiene la cabecera de la imagen.
 * @param p1 Puntero a un puntero de la estructura Paleta_de_colores que contiene la tabla de colores (si existiese).
 * @param ptr_in Puntero a un puntero de archivo de entrada.
 * @param ptr_out Puntero a un puntero de archivo de salida.
 * @param NombreDeImagen Puntero a un string que contiene el nombre de la imagen.
 * @param decision Puntero a un entero que indica alguna decision (no especificada en el codigo).
 *
 * La función realiza las siguientes operaciones:
 * 1. Llama a una función que escribe el header y la tabla de colores en la imagen de salida.
 * 2. Lee los datos de la imagen del archivo de entrada en un buffer de memoria.
 * 3. Solicita al usuario la opción de rotación deseada.
 * 4. Aplica la rotación seleccionada a los datos de la imagen.
 * 5. Escribe los datos modificados de la imagen en el archivo de salida.
 * 6. Cierra los archivos de entrada y salida.
 * 7. Imprime un mensaje indicando que la función se ejecutó exitosamente.
 */

/** 
 * ENG
 * @brief Function that rotates a bmp image in grayscale colors at different angles.
 *        This is done through FILE pointers and streams.
 *
 * @param p Pointer to a pointer of the DatosBMP structure containing the image header.
 * @param p1 Pointer to a pointer of the Paleta_de_colores structure containing the color table (if it exists).
 * @param ptr_in Pointer to a pointer of the input file.
 * @param ptr_out Pointer to a pointer of the output file.
 * @param NombreDeImagen Pointer to a string containing the image name.
 * @param decision Pointer to an integer indicating some decision (not specified in the code).
 *
 * The function performs the following operations:
 * 1. Calls a function that writes the header and color table to the output image.
 * 2. Reads the image data from the input file into a memory buffer.
 * 3. Prompts the user for the desired rotation option.
 * 4. Applies the selected rotation to the image data.
 * 5. Writes the modified image data to the output file.
 * 6. Closes the input and output files.
 * 7. Prints a message indicating that the function was successfully called.
 */

void Rotacion_Imagen(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
    //ESP: Declaracion de array estatico de 2 dimensiones siendo AnchoXAlto, que almacena la data imagen del archivo de entrada.
    //ENG: Declaration of a static array of 2 dimensions being WidthXHeight, which stores the image data from the input file.
    unsigned char BufferCopiaLocalIn[(*p)->Ancho][(*p)->Altura];
    
    //ESP: Declaracion de array estatico de 2 dimensiones sinedo AnchoxAlto, que almacena la data imagen rotada para ser escrita en archivo de salida.
    //ENG: Declaration of a static array of 2 dimensions being WidthxHeight, which stores the rotated image data to be written to the output file.
    unsigned char BufferCopiaLocalOut[(*p)->Ancho][(*p)->Altura];
    
    //ESP: Declaracion de variables de iteracion para for.
    //ENG: Declaration of iteration variables for for.
    int i,j;
    //ESP: Declaracion de variable que almacena valor de opcion para switchcase.
    //ENG: Declaration of variable that stores option value for switchcase.
    int decisionrotacion;
    
    //ESP: Llamo a funcion que escribe el header y tabla de colores en la imagen de salida y que usa archivo de entrada y cambia posicion de offset. 
    //Todo con streams y punteros a FILE.
    //ENG: I call a function that writes the header and color table to the output image and that uses the input file and changes the offset position.
    //All with streams and FILE pointers.
    Escritura_Imagen_HeaderYTablaColores(p, p1, ptr_in, ptr_out, NombreDeImagen, decision);
    
    //ESP: Lectura en memoria de la data imagen del archivo de entrada hacia el bloque de memoria estatico de 2 dimensiones BufferCopiaLocalIn.
    //ENG: Reading in memory of the image data from the input file to the static 2-dimensional memory block BufferCopiaLocalIn.
    fread(BufferCopiaLocalIn,sizeof(unsigned char),(*p)->TamImg,*ptr_in);
    
    //ESP: Pedido de opcion para menu.
    //ENG: Request for option for menu.
    printf("Elija el sentido de rotacion siendo:\n\"1\" 90° a izquierda\n\"2\" 90° a derecha\n\"3\" 180° a inversion\n");
    scanf("%i",&decisionrotacion);
    __fpurge(stdin);
    
    //ESP: Menu no recursivo de opciones de rotacion de imagen. La rotacion en un sentido u otro no lo hago a traves de transformacion lineal 
    //sino a partir de asignar cada pixel del array BufferCopiaLocalIn de 2D en el array BufferCopiaLocalOut de 2D pero ubicando cada uno de ellos
    //en las coordenadas x e y asociadas a los indexes "i e j" modificados matematicamente en array BufferCopiaLocalOut de 2D durante la asignacion.
    //Dicho proceso de asignacion se ejecuta a traves de 2 ciclos for por cada case de rotacion debido a que los pixeles se encuentran ubicados en arreglos de 2D.
    //ENG: Non-recursive menu of image rotation options. The rotation in one direction or another is not done through linear transformation
    //but by assigning each pixel of the 2D array BufferCopiaLocalIn to the 2D array BufferCopiaLocalOut but placing each of them
    //in the x and y coordinates associated with the "i and j" indexes modified mathematically in the 2D BufferCopiaLocalOut array during the assignment.
    //This assignment process is executed through 2 for loops for each rotation case because the pixels are located in 2D arrays.


    //ESP: Es importante destacar que la rotacion solo funciona para imagenes cuya dimension en alto y ancho es la misma.
    //Ej para la imagen de lena 512 x 512 funciona pero para la imagen de goldhill de 720x576 entonces no funciona y asi fuese de 576x720 tampoco funcionara.
    //ENG: It is important to note that the rotation only works for images whose height and width dimension are the same.
    //Eg for the 512 x 512 lena image it works but for the 720x576 goldhill image it does not work and even if it were 576x720 it will not work either.
    switch(decisionrotacion)
    {
        //ESP: Rotacion 90° a izquierda en imagen de salida. Si armo una matrix de 2D se puede ver que las filas de pixeles rotan en realidad hacia la derecha 
        //pero en la imagen de salida el efecto visual es de rotacion a la izquierda. Esto tiene que ver con el margen de referencia que se tome de la imagen original. 
        //En este caso, el margen de referencia a tomar seria el margen izquierdo de la imagen original, siguiendo la rotacion a derecha a nivel imagen, vemos que el margen 
        //izquierdo pasa a ser el margen inferior en la imagen de salida indicando que hubo una rotacion de 90 grados a derecha respecto de esta referencia. Sin embargo, 
        //a nivel matricial, el margen derecho de la matriz rota a izquierda 90 pasando a ser margen inferior en la matriz.
        //ENG: 90° rotation to the left in the output image. If I build a 2D matrix I can see that the rows of pixels actually rotate to the right
        //but in the output image the visual effect is of rotation to the left. This has to do with the reference margin that is taken from the original image.
        //In this case, the reference margin to be taken would be the left margin of the original image, following the rotation to the right at the image level,
        //we see that the left margin becomes the lower margin in the output image indicating that there was a 90 degree rotation to the right with respect to this reference.
        //However, at the matrix level, the right margin of the matrix rotates to the left 90 becoming the lower margin in the matrix.
        case 1:  
            
            for( i = 0; i < (*p)->Ancho; i++)
            {
                for( j = 0; j < (*p)->Altura; j++)
                {
                    BufferCopiaLocalOut[j][(*p)->Altura-1-i] = BufferCopiaLocalIn[i][j];
                }
            }
            
            break;
        //ESP: Rotacion 90° a derecha + efecto espejo en imagen de salida. Si armo una matrix de 2D se puede ver que las filas de pixeles rotan en realidad hacia la izquierda 
        //pero en la imagen de salida el efecto visual es de rotacion a la derecha. Esto tiene que ver con el margen de referencia que se tome de la imagen original. 
        //En este caso, el margen de referencia a tomar seria el margen derecho de la imagen original, siguiendo la rotacion a izquierda con espejado a nivel imagen, 
        //vemos que el margen derecho pasa a ser el margen superior de la imagen de salida indicando que hubo una rotacion de 90 grados a derecha con espejado respecto de esta referencia. 
        //Sin embargo, a nivel matricial, el margen derecho de la matriz rota a derecha 90 y se espeja pasando a ser margen inferior en la matriz.
        //ENG: 90° rotation to the right + mirror effect in the output image. If I build a 2D matrix I can see that the rows of pixels actually rotate to the left
        //but in the output image the visual effect is of rotation to the right. This has to do with the reference margin that is taken from the original image.
        //In this case, the reference margin to be taken would be the right margin of the original image, following the rotation to the left with mirroring at the image level,
        //we see that the right margin becomes the upper margin of the output image indicating that there was a 90 degree rotation to the right with mirroring with respect to this reference.
        //However, at the matrix level, the right margin of the matrix rotates to the right 90 and is mirrored becoming the lower margin in the matrix.
        case 2:  
            
            for( i = 0; i < (*p)->Ancho; i++)
            {
                for( j = 0; j < (*p)->Altura; j++)
                {
                    BufferCopiaLocalOut[j][i] = BufferCopiaLocalIn[i][j];
                }
            }
            
            break;
        
        //Rotacion 180° a inversion. Si armo una matriz de 2D se puede ver que las filas superiores pasan a ocupar los lugares de las filas inferiores y viceversa pero sin modificar 
        //la ubicaciones de las filas intermedias. En la imagen de salida se produce un efecto de inversion a 180 grados. Se puede pensar que en este caso a nivel imagen y a nivel 
        //matricial se respeta la misma logica en cuanto a la referencia a tomar, siendo por ejemplo en este caso el margen superior de la imagen y a nivel martricial tambien. 
        //Vemos que este margen superior pasa a ser el margen inferior y viceversa. Pero el centro de la imagen y de la matriz se mantiene sin modificaciones.
        case 3: 
        
            for( i = 0; i < (*p)->Ancho; i++)
            {
                for( j = 0; j < (*p)->Altura; j++)
                {
                    BufferCopiaLocalOut[(*p)->Ancho-1-i][j] = BufferCopiaLocalIn[i][j];
                }
            }
            
            break;
            
        case '\n' : case ' ': //ESP: Ignora estas entradas de teclado. ENG: Ignore these keyboard inputs.
                   
            break;
                
        default: //ESP: Para todo el resto de caracteres tira un mensaje de error. ENG: For all other characters throw an error message.
                   
                printf("Se ingreso incorrectamente una opcion de rotacion\n");
                printf("Ingrese devuelta una de las opciones: ");
                    
            break;
    }
    
    //ESP: Escritura en archivo de salida de la data imagen modificada en el bloque de memoria BufferCopiaLocalOut de 2D.
    //ENG: Writing to the output file the modified image data in the 2D BufferCopiaLocalOut memory block.
    fwrite(BufferCopiaLocalOut,sizeof(unsigned char),(*p)->TamImg,*ptr_out);
    
    //ESP: Cierro archivo de entrada y salida.
    //ENG: I close the input and output file.
    fclose(*ptr_in);
    fclose(*ptr_out);
    
     printf("Se llamo exitosamente a la funcion \"Rotacion_Imagen\"\n.\n.\n.\n");
}




/** 
 * ESP
 * @brief Funcion que realiza la deteccion de bordes de una imagen bmp de entrada a partir del uso de mascaras como matrices de 2D de 3x3.
 *
 * @param p Puntero a un puntero de la estructura DatosBMP que contiene la cabecera de la imagen.
 * @param p1 Puntero a un puntero de la estructura Paleta_de_colores que contiene la tabla de colores (si existiese).
 * @param ptr_in Puntero a un puntero de archivo de entrada.
 * @param ptr_out Puntero a un puntero de archivo de salida.
 * @param NombreDeImagen Puntero a un string que contiene el nombre de la imagen.
 * @param decision Puntero a un entero que indica alguna decision (no especificada en el codigo).
 * @param Mascara Array bidimensional de enteros de 3x3 que contiene la mascara utilizada para la deteccion de bordes.
 *
 * La función realiza las siguientes operaciones:
 * 1. Llama a una función que escribe el header y la tabla de colores en la imagen de salida.
 * 2. Lee los datos de la imagen del archivo de entrada en un buffer de memoria.
 * 3. Aplica la deteccion de bordes utilizando una mascara de 3x3.
 * 4. Escribe los datos modificados de la imagen en el archivo de salida.
 * 5. Cierra los archivos de entrada y salida.
 * 6. Imprime un mensaje indicando que la función se ejecutó exitosamente.
 */

/** 
 * ENG
 * @brief Function that performs edge detection on an input bmp image using 3x3 masks as 2D matrices.
 *
 * @param p Pointer to a pointer of the DatosBMP structure containing the image header.
 * @param p1 Pointer to a pointer of the Paleta_de_colores structure containing the color table (if it exists).
 * @param ptr_in Pointer to a pointer of the input file.
 * @param ptr_out Pointer to a pointer of the output file.
 * @param NombreDeImagen Pointer to a string containing the image name.
 * @param decision Pointer to an integer indicating some decision (not specified in the code).
 * @param Mascara Two-dimensional array of integers 3x3 containing the mask used for edge detection.
 *
 * The function performs the following operations:
 * 1. Calls a function that writes the header and color table to the output image.
 * 2. Reads the image data from the input file into a memory buffer.
 * 3. Applies edge detection using a 3x3 mask.
 * 4. Writes the modified image data to the output file.
 * 5. Closes the input and output files.
 * 6. Prints a message indicating that the function was successfully called.
 */

void Deteccion_de_Bordes_lineal(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision, int Mascara[][3])
{
    //ESP: Declaracion de array estatico de 1 dimension de TamImg, que almacena la data imagen del archivo de entrada.
    //ENG: Declaration of a static array of 1 dimension of TamImg, which stores the image data from the input file.
    unsigned char BufferCopiaLocalIn[(*p)->TamImg];

    //ESP: Declaracion de array estatico de 1 dimension de TamImg, que almacena la data imagen modificada para ser escrita en archivo de salida.
    //ENG: Declaration of a static array of 1 dimension of TamImg, which stores the modified image data to be written to the output file.
    unsigned char BufferCopiaLocalOut[(*p)->TamImg];
    
    //ESP: Declaracion de variables de iteracion para ciclo for.
    //ENG: Declaration of iteration variables for for.
    int x,y,i,j,sum;
    
    //ESP: Llamo a funcion que escribe el header y tabla de colores en la imagen de salida y que usa archivo de entrada y cambia posicion de offset. 
    //Todo con streams y punteros a FILE.
    //ENG: I call a function that writes the header and color table to the output image and that uses the input file and changes the offset position.
    //All with streams and FILE pointers.
    Escritura_Imagen_HeaderYTablaColores(p, p1, ptr_in, ptr_out, NombreDeImagen, decision);
    
    //ESP: Lectura en memoria de la data imagen del archivo de entrada hacia el bloque de memoria estatico de 1 dimensiones BufferCopiaLocalIn.
    //ENG: Reading in memory of the image data from the input file to the static 1-dimensional memory block BufferCopiaLocalIn.
    fread(BufferCopiaLocalIn,sizeof(unsigned char),(*p)->TamImg,*ptr_in);
    
    //ESP: Algoritmo que realiza la deteccion de bordes a partir de una mascara y operaciones de multiplicacion, donde esta mascara es un array de 2D de 3x3 
    //con valores pre-cargados. Se busca evaluar que sucede con un "vecindario" de pixeles de 3x3 respecto a un pixel central. Dicho algoritmo utiliza 4 ciclos for. 
    //El 1ero y el 2do es para recorrer todas las filas y las columnas en busqueda de un pixel central siendo que la posicion de dicho pixel central de un vecindario 
    //este dado por "BufferCopiaLocalOut+x+(long)y * ((*p)->Ancho)". Luego el 3ero y el 4to que realizan una sumatoria de resultados dados por las operaciones de la linea 593 
    //tal que se obtiene un valor resultante de todas las operacoiones de todos los pixeles de un "neighborhood" respecto al pixel central estudiado. 
    //Dicho valor resultante del vecindario se evalua al finalizar el 3er y 4to for, en la evaluacion se determina si el pixel central asumira el valor de "encendido o blanco(255)" 
    //o el valor de "apagado o negro(0)". Repitiendo esto sucesivamente para todos los pixeles de una imagen, se podra tener entonces los "bordes" o delineados bien marcados en la imagen de salida. 
    //Cabe aclarar que la imagen de estudio debe estar en escala de grises obligatoriamente.
    //ENG: Algorithm that performs edge detection from a mask and multiplication operations, where this mask is a 3x3 2D array
    //with pre-loaded values. The goal is to evaluate what happens to a 3x3 pixel "neighborhood" with respect to a central pixel. This algorithm uses 4 for loops.
    //The 1st and 2nd loops are to traverse all rows and columns in search of a central pixel, with the position of said central pixel in a neighborhood
    //being given by "BufferCopiaLocalOut+x+(long)y * ((*p)->Width)". Then the 3rd and 4th loops perform a summation of the results given by the operations on line 593
    //such that a resulting value is obtained from all the operations on all the pixels in a "neighborhood" with respect to the central pixel being studied.
    //This resulting neighborhood value is evaluated at the end of the 3rd and 4th for loops. This evaluation determines whether the center pixel will assume the value "on or white(255)"
    //or the value "off or black(0)". By repeating this successively for all the pixels in an image, the "edges" or outlines can then be clearly defined in the output image.
    //It should be noted that the study image must be in grayscale. 

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
    
    //ESP: Escritura en archivo de salida de la data imagen modificada en el bloque de memoria BufferCopiaLocalOut de 2D.
    //ENG: Writing to the output file the modified image data in the 2D BufferCopiaLocalOut memory block.
    fwrite(BufferCopiaLocalOut,sizeof(unsigned char),(*p)->TamImg,*ptr_out);
    
    //ESP: Cierro archivo de entrada y salida.
    //ENG: I close the input and output file.
    fclose(*ptr_in);
    fclose(*ptr_out);
    
    printf("Se llamo exitosamente a la funcion \"Deteccion_de_Bordes_lineal\"\n.\n.\n.\n");
}




/** 
 * ESP
 * @brief Funcion que imprime en pantalla la informacion del header a traves del uso de estructura y sus miembros.
 *
 * @param p Puntero a la estructura DatosBMP que contiene la cabecera de la imagen.
 *
 * La función realiza las siguientes operaciones:
 * 1. Imprime el tipo de archivo.
 * 2. Imprime el tamaño del archivo.
 * 3. Imprime los campos reservados.
 * 4. Imprime el inicio de la imagen.
 * 5. Imprime el tamaño total de la cabecera.
 * 6. Imprime el ancho y la altura de la imagen.
 * 7. Imprime el número de planos.
 * 8. Imprime el tamaño del punto.
 * 9. Imprime la compresión.
 * 10. Imprime el tamaño de la imagen.
 * 11. Imprime la resolución horizontal y vertical.
 * 12. Imprime el tamaño de la tabla de colores.
 * 13. Imprime el contador de colores.
 *
 * @return TRUE si la función se ejecutó exitosamente.
 */

/** 
 * ENG
 * @brief Function that prints the header information on the screen through the use of structure and its members.
 *
 * @param p Pointer to the DatosBMP structure containing the image header.
 *
 * The function performs the following operations:
 * 1. Prints the file type.
 * 2. Prints the file size.
 * 3. Prints the reserved fields.
 * 4. Prints the image start.
 * 5. Prints the total header size.
 * 6. Prints the image width and height.
 * 7. Prints the number of planes.
 * 8. Prints the point size.
 * 9. Prints the compression.
 * 10. Prints the image size.
 * 11. Prints the horizontal and vertical resolution.
 * 12. Prints the color table size.
 * 13. Prints the color counter.
 *
 * @return TRUE if the function was successfully called.
 */

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