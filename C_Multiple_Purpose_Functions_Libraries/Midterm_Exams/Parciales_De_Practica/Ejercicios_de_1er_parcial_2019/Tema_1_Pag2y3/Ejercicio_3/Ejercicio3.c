#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define FALSE 0
#define TRUE 1
//Este ejercicio consiste en crear una funcion que recibe una cadena de caracteres y determina si es capicua dicha palabra, retornando palabras clave como TRUE o FALSE. La funcion no debe dar importancia a las mayusculas y minusculas. Ej: Ana, AnA, ANA, aNa, etc. Todas estas palabras son capicua o mejor dicho palindromos donde no importan las mayusculas o minusculas, la lectura en un sentido u otro es la misma.
//Lo que hago es 1ero cualquier palabra recibida convertirla toda a minuscula o mayuscula. Luego comparar el 1er caracter con el ultimo, el 2do caracter con el ante ultimo y asi, si en todos los casos de comparacion son iguales pero en 1 solo caracter(el del centro de la palabra) este no tiene con pareja para comparar o mismo al comparar este caracter sucede que se compara con si mismo siendo igual. Entonces la pabara es palindroma. Habra que asegurar el string de caracteres sin \n ni \0, es decir, quitarselos si los posee. Y recorrer el string en un sentido y simultaneamente en otro.

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );
int es_palindromo( const char* );
//prototipo de uso obligatorio por enunciado. Por otro lado, const char* es un puntero el cual puede modificarse las direcciones a las que apunte PERO NO se puede modificar el contenido de lo apuntado por el puntero. Es decir, mantiene constante el contenido. De intentar modificar ese contenido , habra mensajes de error dados por el compilador.
char * strcpy_sentido_opuesto( char *dest, const char *src, size_t tamanio_buffer );
int strcicmpL(char const *a, char const *b, size_t tamanio_buffer);





int main()
{
    char *buffer = NULL;//declaro un puntero simple que recorre un vector dinamico de caracteres que se carga por teclado y se va realocalizando a medida que se ingresan caracteres. Esto de acuerdo a la construccion de la funcion getline()
    char decision = 0;
    
    printf("Bienvenido, este programa determina si una palabra ingresada por teclado, es o no \"palindromo\"\n");
    
    buffer = Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( &buffer );
    
    decision = es_palindromo( buffer );
    
    if( decision == TRUE )
    {
        printf("Su palabra ingresada es palindroma\n");
    }
    else
    {
        printf("Su palabra ingresada NO es palindroma\n");
    }
    
    printf("Gracias por usar este programa. Si desea evaluar otra palabra, ejecute devuelta el programa\n");
    
    free(buffer);
    return 0;
}

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer )
{
    size_t capacidad = 0;//size_t y ssize_t es lo mismo que escribir unsigned int. Es decir, es un tipo de dato entero sin signo, usualmente lo devuelve sizeof pero tambien se puede declarar asi nomas. Al ponerle 0, permito que getline() use malloc y realloc desde el 1er instante. De lo contrario, si pongo un valor ej 30. Pide memoria para 30 caracteres y luego si me paso, realocaliza con realloc
    ssize_t cantcaracteresleidos;//declaro una variable que guarda la cantidad de caracteres leidos por teclado
    
    printf("Ingrese por favor la palabra que desea evaluar: ");
    cantcaracteresleidos = getline( buffer, &capacidad, stdin ); 
    // Hay que tener en cuenta este prototipo para pasar bien los parametros a getline
    //ssize_t getline(char **lineptr, size_t *n, FILE *stream);

    
    if( cantcaracteresleidos == -1 )
    {
        printf("Hay un error con la lectura del texto ingresado");
        exit(-1);
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
int es_palindromo( const char *buffer )
{
    size_t tamanio_buffer;
    //short int i;
    
    //Busco medir el largo del texto ingresado para crear un 2do vector de este tamanio
    tamanio_buffer = strlen( buffer );//esta funcion cuenta incluyendo el \n si hubiera pero sin \0
    
    //Este printf debe mostrar tanto sin el caracter \n ni el \0. El caracter \n ya lo saque antes
    printf("El tamanio del texto ingresado sin contar el \" barra 0 \" ni \" barra n \" es de %li caracteres\n", tamanio_buffer);
    
    //creo el vector auxiliar de acuerdo al tamanio del buffer para luego pasarle una copia en sentido opuesto del texto del buffer
    char *vector_auxiliar = NULL;
    vector_auxiliar = (char *)malloc(tamanio_buffer * sizeof(char *));
    
    /*
    //Busco convertir todo el texto del buffer a minusculas o mayusculas para usarlo mas adelante en copiado y comparacion(esto se puede armar con funcion void)
    for( i = 0; i < tamanio_buffer; i++ )
    {
        (buffer[i]) = tolower( (int)*(buffer+i) );
    }
    
    printf("El texto ingresado convertido a minusculas queda como: %s\n", buffer);
    
    for( i = 0; i < tamanio_buffer; i++ )
    {
        (buffer+i) = toupper( (int)*(buffer+i) );
    }
    
    printf("El texto ingresado convertido a mayusculas queda como: %s\n", buffer);
    
    */
    
    //realizo un copiado en sentido opuesto, de los caracteres del buffer a un vector auxiliar. Recordamos que el buffer es el que contiene el texto ingresado por teclado
    vector_auxiliar = strcpy_sentido_opuesto( vector_auxiliar, buffer, tamanio_buffer );
    printf("El vector_auxiliar quedo cargado con: %s\n", vector_auxiliar);
    printf("El texto original quedo como: %s\n", buffer);
    
    //realizo una comparacion entre ambos strings para ver si son o no iguales. De serlo retorno TRUE y lo utilizo en el main. De no serlo, retorno FALSE y lo utilizo en el main. Ambos casos para mostrar distinos mensajes en pantalla
    if( strcicmpL( buffer, vector_auxiliar, tamanio_buffer ) == 0 )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
    free(vector_auxiliar);
}

char * strcpy_sentido_opuesto( char *dest, const char *src, size_t tamanio_buffer )
{
    short int i,j;

    for (i = tamanio_buffer - 1, j = 0; i >= 0 && src[j] != '\0'; i--, j++)
    {
        dest[j] = src[i];
    }
        dest[j+1] = '\0';

    return dest;
}

//Convierte los caracteres a minusucula y los compara uno a uno
int strcicmpL( char const *a, char const *b, size_t tamanio_buffer )
{
    short int i, d, cont_caracteres_iguales = 0, cont_caracteres_distintos = 0;
    for( i = 0; i < tamanio_buffer; i++ )
    {
        d = tolower(*(a+i)) - tolower(*(b+i));
        if(d == 0) 
        {
            cont_caracteres_iguales++;
        }
        else 
        {
            cont_caracteres_distintos++;
        }
    }  
    
    if( cont_caracteres_iguales == tamanio_buffer)
    {
        printf("La cantidad de caracteres coincidentes deberia ser igual al tamanio_buffer, esto es: %i\n", cont_caracteres_iguales);
        return 0;
    }
    else
    {
        printf("La cantidad de caracteres NO coincidentes son: %i\n", cont_caracteres_distintos);
        printf("La cantidad de algunos caracteres coincidentes sin embargo, fueron: %i\n", cont_caracteres_iguales);
        return -1;
    }
}
/*
Funciona igual que strcicmpL, nada mas que hace conversiones de los caracteres a mayusculas
int strcicmpU( char const *a, char const *b, size_t tamanio_buffer )
{
    short int i, d, cont_caracteres_iguales = 0, cont_caracteres_distintos = 0;
    for( i = 0; i < tamanio_buffer; i++ )
    {
        d = toupper(*(a+i)) - toupper(*(b+i));
        if(d == 0) 
        {
            cont_caracteres_iguales++;
        }
        else 
        {
            cont_caracteres_distintos++;
        }
    }  
    
    if( cont_caracteres_iguales == tamanio_buffer)
    {
        printf("La cantidad de caracteres coincidentes deberia ser igual al tamanio_buffer, esto es: %i\n", cont_caracteres_iguales);
        return 0;
    }
    else
    {
        printf("La cantidad de caracteres NO coincidentes son: %i\n", cont_caracteres_distintos);
        printf("La cantidad de algunos caracteres coincidentes sin embargo, fueron: %i\n", cont_caracteres_iguales);
        return -1;
    }
}
*/
