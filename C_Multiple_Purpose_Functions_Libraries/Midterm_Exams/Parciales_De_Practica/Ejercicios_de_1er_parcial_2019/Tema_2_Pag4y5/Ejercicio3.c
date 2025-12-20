#define _POSIX_C_SOURCE 200809L//norma necesaria para usar getline()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

//Declaro las funciones a usar
//El prototipo de la funcion dada por enunciado es
int CuantasVeces( char *buffer, char Caracter_de_estudio, int *Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter );

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );
int Evaluacion_de_caracterestudiado_vs_caracteresstring_y_printeo_de_posiciones_de_repeticion( int tamanio_buffer, char Caracter_de_estudio, char *buffer, int *Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter);

int main(void)
{
    //declaro un puntero simple que recorre un vector dinamico de caracteres(que podran formar una palabra o mas palabras) que se carga por teclado y se va realocalizando a medida que se ingresan caracteres. Esto de acuerdo a la construccion interna de la funcion getline()
    char *buffer = NULL;
    //declaro una variable que almacena la cantidad de repeticiones de un caracter ingresado por el usuario evaluando una frase ingresada.
    int Cantidad_de_repeticiones_de_caracter_ingresado = 0;
    //declaro una variable que almacena el caracter de estudio de repeticiones en una frase ingresada
    char Caracter_de_estudio;
    //declaro un array dinamico que lo recorro con un puntero simple. Dicho array posee como elementos las posiciones en la frase donde se repite el caracter de estudio
    int *Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter = NULL;
    
    printf("Bienvenido, este programa determina cuantas veces se repite un caracter determinado ingresado por el usuario en una frase ingresada, que puede ser de una o mas palabras. Dicha frase se ingresa por teclado. Ademas permite detectar en que posiciones de la frase, ocurren las repeticiones de dicho caracter.\n");
    
    //Ingreso por teclado y guardo el texto en un vector de caracteres "buffer", a traves de una funcion
    buffer = Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( &buffer );
    
    //ingreso por teclado el caracter de estudio a evaluar sus ocurrencias en una frase
    printf("Ingrese por favor el caracter a evaluar sus ocurrencias en su frase ingresada: ");
    scanf("%c", &Caracter_de_estudio);
    __fpurge(stdin);
    
    //La funcion CuantasVeces me devuelve la cantidad de repeticiones del caracter ingresado al evaluar una frase ingresada. 
    Cantidad_de_repeticiones_de_caracter_ingresado = CuantasVeces( buffer, Caracter_de_estudio, Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter );
    
    printf("La cantidad de veces que se repite el caracter de estudio en su frase ingresada, es: %i\n", Cantidad_de_repeticiones_de_caracter_ingresado );
    
    //libero la memoria usada por el buffer que almacena el texto ingresado por teclado
    free(buffer);
    
    return 0;
}

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer )
{
    size_t capacidad = 0;//size_t y ssize_t es lo mismo que escribir unsigned int. Es decir, es un tipo de dato entero sin signo, usualmente lo devuelve sizeof pero tambien se puede declarar asi nomas. Al ponerle 0, permito que getline() use malloc y realloc desde el 1er instante. De lo contrario, si pongo un valor ej 30. Pide memoria para 30 caracteres y luego si me paso, realocaliza.
    ssize_t cantcaracteresleidos;//declaro una variable que guarda la cantidad de caracteres leidos por teclado
    
    printf("Ingrese por favor la frase que desea evaluar: ");
    cantcaracteresleidos = getline( buffer, &capacidad, stdin ); 
    // Hay que tener en cuenta este prototipo para armar pasar bien los argumentos a getline
    //ssize_t getline(char **lineptr, size_t *n, FILE *stream);

    if( cantcaracteresleidos == -1 )
    {
        printf("Hay un error con la lectura del texto ingresado");
    }
    else
    {
        printf("La cantidad de caracteres leidos teniendo en cuenta el caracter \" barra n \"fueron: %li\n", cantcaracteresleidos);
        printf("El texto ingresado fue: %s\n", *buffer);
    }
    //Elimino el caracter de nueva linea en el texto ingresado por teclado
    *(*(buffer)+(cantcaracteresleidos-1))= '\0';
    
    return *buffer;
}

int CuantasVeces( char *buffer, char Caracter_de_estudio, int *Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter )
{
    int cont_de_repeticiones = 0; 
    //declaro una variable que almacena el tamanio o cantidad de caracter del texto ingresado
    size_t tamanio_buffer;
    
    //Busco medir el largo del texto ingresado para iterar en toda la frase en la busqueda de caracteres ascii que se repitan
    tamanio_buffer = strlen( buffer );//esta funcion cuenta incluyendo el \n si hubiera pero sin \0
    
    //Este printf debe mostrar tanto sin el caracter \n ni el \0. El caracter \n ya lo saque antes
    printf("El tamanio del texto ingresado sin contar el \" barra 0 \" ni \" barra n \" es de %li caracteres\n", tamanio_buffer);
    
    //pido memoria dinamica para un vector, recorrido con puntero simple, que almacena distintas posiciones de repeticiones del caracter de estudio
    Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter = (int *)malloc( tamanio_buffer * sizeof(int *));
    
    //proteccion contra NULL de malloc
    if( Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter == NULL )
    {
        printf("Hay un error con la asignacion de memoria dinamica\n");
        exit(-1);
    }
    
    cont_de_repeticiones = Evaluacion_de_caracterestudiado_vs_caracteresstring_y_printeo_de_posiciones_de_repeticion( tamanio_buffer, Caracter_de_estudio, buffer, Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter);
   
    //Libero la memoria dinamica usada por el array de pociones de caracter repetido
    free( Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter );
    
    //retorno la cantidad de repeticiones del caracter de estudio
    return cont_de_repeticiones;
}

int Evaluacion_de_caracterestudiado_vs_caracteresstring_y_printeo_de_posiciones_de_repeticion( int tamanio_buffer, char Caracter_de_estudio, char *buffer, int *Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter)
{
    //declaro 2 variables"i" e "j" que son iteradores
    int i, j;
    //declaro variable de contador de repeticiones 
    int cont_de_repeticiones = 0;
    //Algoritmo de comparacion de cada caracter de la frase con el caracter de estudio, si son iguales, el contador se incrementa, el vector dinamico de posiciones se carga con la posicion de la repeticion del caracter de estudio y se incrementa el indice de dicho vector. De no cumplirse la condicion del "if" entonces continua con la iteracion el for
    for( i = 0, j = 0; i < tamanio_buffer; i++ )
    {
        if( buffer[i] == Caracter_de_estudio )
        {
            cont_de_repeticiones++;
            Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter[j] = i;
            j++;
        }
    }
    
    //Algoritmo de printeo de las pociones de repeticion del caracter de estudio en la frase ingresada
    printf("Las posiciones, contando desde posinicial 0, en la frase donde se repite el caracter de estudio, son: \n");
    for( i = 0; i < j; i++ )
    {
        printf("%i ", Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter[i] ); 
    }
    printf("\n");
    
    //retorno la cantidad de repeticiones del caracter de estudio
    return cont_de_repeticiones;
}
