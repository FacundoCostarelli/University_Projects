#define _POSIX_C_SOURCE 200809L//norma necesaria para usar getline()
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//prototipo de funcion que calcula la cantidad de veces que se repiten los distintos caracteres en una frase por enunciado es la siguiente
//CUIDADO: Una frase puede ser de una o mas palabras
int CuantasVeces( const char *, int *);

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );

int Evaluacion_y_printeo_de_caracteres_repetidos( size_t tamanio_buffer, const char *buffer, int *vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter, int *vector_dinamico_almacen_de_los_caracteres_repetidos );

int Evaluacion_mayor_cant_de_repeticiones( int k, 
int *vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter, int *vector_dinamico_almacen_de_los_caracteres_repetidos );


int main()
{   
    //declaro un puntero simple que recorre un vector dinamico de caracteres(que podran formar una palabra o mas palabras) que se carga por teclado y se va realocalizando a medida que se ingresan caracteres. Esto de acuerdo a la construccion interna de la funcion getline()
    char *buffer = NULL;
    //creo un vector dinamico que almacena la cantidad de repeticiones de los caracteres
    int *vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter = NULL;
    int Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres = 0;
    
    printf("Bienvenido, este programa determina cuantas veces se repiten los caracteres de una frase, que puede ser de una o mas palabras, ingresada por teclado. Con esta informacion usted podra crear el grafico del histograma con algun otro software como OCTAVE, EXCEL, etc\n");
    
    //Ingreso por teclado y guardo el texto en un vector de caracteres "buffer", a traves de una funcion
    buffer = Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( &buffer );
    
    //La funcion CuantasVeces me devuelve la cantidad de repeticiones del caracter mas repetido. 
    Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres = CuantasVeces( buffer, vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter );
    
    printf("El mayor nro de repeticiones de uno o mas caracteres fue: %i\n", Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres );
    
    //libero la memoria usada por el buffer que almacena el texto ingresado por teclado
    free(buffer);
    
    return 0;
}

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer )
{
    size_t capacidad = 0;//size_t y ssize_t es lo mismo que escribir unsigned int. Es decir, es un tipo de dato entero sin signo, usualmente lo devuelve sizeof pero tambien se puede declarar asi nomas. Al ponerle 0, permito que getline() use malloc y realloc desde el 1er instante. De lo contrario, si pongo un valor ej 30. Pide memoria para 30 caracteres y luego si me paso, realocaliza.
    ssize_t cantcaracteresleidos;//declaro una variable que guarda la cantidad de caracteres leidos por teclado
    
    printf("Ingrese por favor la palabra que desea evaluar: ");
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

int CuantasVeces( const char *buffer, int *vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter)
{
    int Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres = 0, k;
    size_t tamanio_buffer;
    int *vector_dinamico_almacen_de_los_caracteres_repetidos = NULL;
    
    //Busco medir el largo del texto ingresado para iterar en toda la frase en la busqueda de caracteres ascii que se repitan
    tamanio_buffer = strlen( buffer );//esta funcion cuenta incluyendo el \n si hubiera pero sin \0
    
    //Este printf debe mostrar tanto sin el caracter \n ni el \0. El caracter \n ya lo saque antes
    printf("El tamanio del texto ingresado sin contar el \" barra 0 \" ni \" barra n \" es de %li caracteres\n", tamanio_buffer);
    
    //pido memoria dinamica para un vector, recorrido con puntero simple, que almacena distintas cantidades de repeticiones de caracteres
    vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter = (int *)malloc( tamanio_buffer * sizeof(int *));
    
    //proteccion contra NULL de malloc
    if( vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter == NULL )
    {
        printf("Hay un error con la asignacion de memoria dinamica\n");
        exit(-1);
    }
    
    //pido memoria dinamica para un vector, recorrido con un puntero simple, que almacena los valores o codigos int asccii de los caracteres repetedios 
    vector_dinamico_almacen_de_los_caracteres_repetidos = (int *)malloc( tamanio_buffer * sizeof(int *));
    
    //proteccion contra NULL de malloc
    if( vector_dinamico_almacen_de_los_caracteres_repetidos == NULL )
    {
        printf("Hay un error con la asignacion de memoria dinamica\n");
        exit(-1);
    }
    
    k = Evaluacion_y_printeo_de_caracteres_repetidos( tamanio_buffer, buffer, vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter, vector_dinamico_almacen_de_los_caracteres_repetidos );
   
    Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres = Evaluacion_mayor_cant_de_repeticiones( k, vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter, vector_dinamico_almacen_de_los_caracteres_repetidos );
    
    //libero la memoria usada por los 2 vectores dinamicos creados en esta funcion 
    free(vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter);
    free(vector_dinamico_almacen_de_los_caracteres_repetidos);
    
    return Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres;
}

//Esta funcion evalua cuantas veces y cuales son los caracteres que se repiten. Ademas lo muestra en pantalla. Esta funcion, devuelve la " cantidad de elementos+1 " del vector_dinamico_almacen_de_los_caracteres_repetidos.
int Evaluacion_y_printeo_de_caracteres_repetidos( size_t tamanio_buffer, const char *buffer, int *vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter, int *vector_dinamico_almacen_de_los_caracteres_repetidos )
{
    int i, j, k = 0, cont_de_repeteciones;
    
    //algoritmo de dos iteraciones for. El 1er for, busca iterar entre distintos codigos asccii de caracteres El 2do for busca, detenerse en cada codigo asccii del 1er for y a partir de alli, buscar posicion por posicion en el texto ingresado, si dicho codigo asccii ocurre o no en cada una de las posiciones de caracteres del texto ingresado. Dentro de este 2do for hay un "if", esto es para que si dicho cosigo asccii sucede en la posicion de algun caracter del texto, entonces, cuenta 1 repeticion. Voy entre 32 y 250 porque se evalua la tabla de asccii "imprimible y la extendida"
    for( j = 32; j <= 250; j++ )
    {
        for( i = 0, cont_de_repeteciones = 0; i < tamanio_buffer; i++ )
        {
            if( buffer[i] == j )
                cont_de_repeteciones++;
        }
        //Al final de evaluar dicho codigo asccii, en toda la frase o texto ingresado, se busca evaluar si hubo o no efectivamente repeticiones. Si las hubo, en un vector dinamico se almacena esa cantidad de repeticiones por cada codigo asccii, caso contrario, no almacena cantidades nulas. Ademas, en otro vector dinamico, se busca almacenar los codigos int asccii que sufrieron ocurrencias o repetenciones en la frase de estudio, para uso posterior
        if( cont_de_repeteciones >= 1 )
        {
            vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter[k] = cont_de_repeteciones;
            vector_dinamico_almacen_de_los_caracteres_repetidos[k] = j;
            printf("El caracter %c se repitio %i veces\n", j, cont_de_repeteciones);
            k++;
        }
    }
    
    return k;
}

//Esta funcion evalua cual es la mayor cantidad de repeticiones de un caracter
int Evaluacion_mayor_cant_de_repeticiones( int k, 
int *vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter, int *vector_dinamico_almacen_de_los_caracteres_repetidos )
{
    int i, auxiliar = 0;
    
    //Dentro del vector que almacena repeticiones de caracteres, busco encontrar el valor numerico mas grande de repeticiones. Uso como hipotesis que el valor mas grande es el del 1er elemento del vector y luego con un ciclo for comparo ese auxiliar con cada valor del vector. De ser mas grande ese valor que el auxiliar, entonces auxiliar toma ese valor. Caso contrario, el for continua con la iteracion
    auxiliar = vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter[0];
    for( i = 1; i < k; i++)
    {
        if( vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter[i] > auxiliar )
            auxiliar = vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter[i];
    }
    
    //Busco mostrar en pantalla cual o cuales caracteres son los que tuvieron la mayor cantidad de repeticiones. Ciclo for itera para comparar con un if, si el valor de auxiliar (este fue hallado como mayor en el bloque de codigo anterior) coicide o no con cada valor numerico de repeticiones. De coincidir, se muestra en pantalla el caracter asociado al codigo asccii guardado en el vector de codigos asccii. Dicha posicion de codigo asccii estara asociada a la posicion de la cantidad de repeticiones que coincide con el valor de auxiliar 
    printf("El/los caracteres de mayor repeticion es/fueron: ");
    for( i = 0; i < k; i++ )
    {
        if( auxiliar == vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter[i] )
        {
            printf("%c  ", vector_dinamico_almacen_de_los_caracteres_repetidos[i]);
        }
    }
    printf("\n");
    
    return auxiliar;
}
