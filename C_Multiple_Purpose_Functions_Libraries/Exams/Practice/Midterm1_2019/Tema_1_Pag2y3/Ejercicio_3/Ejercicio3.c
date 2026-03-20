/**
 * @file    Ejercicio3.c
 * @brief   [ESP] Ejercicio 3 Tema 1: Determinación de palíndromos.
 *          [ENG] Exercise 3 Theme 1: Palindrome determination.
 *
 * @author  Facundo Costarelli
 * @date    2019
 * @course  Informática 1 — UTNBA
 */

#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define FALSE 0
#define TRUE 1

/**
 * @brief [ESP] Pide texto por teclado y solicita memoria dinámica usando getline.
 *        [ENG] Prompts for text and requests dynamic memory using getline.
 */
char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );

/**
 * @brief [ESP] Evalúa si el texto ingresado es un palíndromo iterando inversamente.
 *        [ENG] Evaluates if input text is a palindrome by reverse iteration.
 */
int es_palindromo( const char* );

/**
 * @brief [ESP] Copia un array de char de origen a destino en sentido opuesto.
 *        [ENG] Copies a char array from source to destination in reverse order.
 */
char * strcpy_sentido_opuesto( char *dest, const char *src, size_t tamanio_buffer );

/**
 * @brief [ESP] Compara dos strings char a char convirtiéndolos a minúsculas.
 *        [ENG] Compares two strings char by char lowercasing them.
 */
int strcicmpL(char const *a, char const *b, size_t tamanio_buffer);

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Puntero para vector dinámico de caracteres y variable de decisión
       [ENG] Pointer for dynamic char vector and decision variable */
    char *buffer = NULL;
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
    size_t capacidad = 0;
    ssize_t cantcaracteresleidos;
    
    printf("Ingrese por favor la palabra que desea evaluar: ");
    cantcaracteresleidos = getline( buffer, &capacidad, stdin ); 
    
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
    
    /* [ESP] Elimino el caracter de nueva línea
       [ENG] Remove the newline character */
    *(*(buffer)+(cantcaracteresleidos-1))= '\0';
    
    return *buffer;
}

int es_palindromo( const char *buffer )
{
    size_t tamanio_buffer;
    
    /* [ESP] Mido el largo (strlen no cuenta el \0)
       [ENG] Measure the length (strlen doesn't count the \0) */
    tamanio_buffer = strlen( buffer );
    printf("El tamanio del texto ingresado sin contar el \" barra 0 \" ni \" barra n \" es de %li caracteres\n", tamanio_buffer);
    
    /* [ESP] Vector auxiliar dinámico
       [ENG] Dynamic auxiliary vector */
    char *vector_auxiliar = NULL;
    vector_auxiliar = (char *)malloc(tamanio_buffer * sizeof(char));
    
    /* [ESP] Copia en sentido opuesto
       [ENG] Copy in reverse order */
    vector_auxiliar = strcpy_sentido_opuesto( vector_auxiliar, buffer, tamanio_buffer );
    printf("El vector_auxiliar quedo cargado con: %s\n", vector_auxiliar);
    printf("El texto original quedo como: %s\n", buffer);
    
    /* [ESP] Comparación final (minúsculas)
       [ENG] Final comparison (lowercased) */
    int result = FALSE;
    if( strcicmpL( buffer, vector_auxiliar, tamanio_buffer ) == 0 )
    {
        result = TRUE;
    }
    
    free(vector_auxiliar);
    return result;
}

char * strcpy_sentido_opuesto( char *dest, const char *src, size_t tamanio_buffer )
{
    short int i, j;

    for (i = tamanio_buffer - 1, j = 0; i >= 0 && src[j] != '\0'; i--, j++)
    {
        dest[j] = src[i];
    }
    dest[j] = '\0'; /* Fixing out of bounds logic from original */

    return dest;
}

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
