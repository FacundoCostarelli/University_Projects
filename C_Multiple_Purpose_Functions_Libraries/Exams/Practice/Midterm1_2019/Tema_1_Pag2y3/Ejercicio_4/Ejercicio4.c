/**
 * @file    Ejercicio4.c
 * @brief   [ESP] Ejercicio 4 Tema 1: Conteo de mayor repetición de un caracter.
 *          [ENG] Exercise 4 Theme 1: Counting the most repeated character.
 *
 * @author  Facundo Costarelli
 * @date    2019
 * @course  Informática 1 — UTNBA
 */

#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief [ESP] Devuelve la cantidad de repeticiones de la letra más frecuente.
 *        [ENG] Returns the repetition count of the most frequent letter.
 */
int CuantasVeces( const char *, int *);

/**
 * @brief [ESP] Pide memoria dinámica con getline para almacenar texto.
 *        [ENG] Requests dynamic memory with getline to store text.
 */
char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );

/**
 * @brief [ESP] Evalúa cada caracter ASCII y cuenta sus repeticiones en el texto.
 *        [ENG] Evaluates each ASCII char and counts its repetitions in the text.
 */
int Evaluacion_y_printeo_de_caracteres_repetidos( size_t tamanio_buffer, const char *buffer, int *vec_repeticiones, int *vec_codigos );

/**
 * @brief [ESP] Retorna el valor máximo de repeticiones e imprime el caracter asociado.
 *        [ENG] Returns the maximum repetition value and prints the associated char.
 */
int Evaluacion_mayor_cant_de_repeticiones( int k, int *vec_repeticiones, int *vec_codigos );

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{   
    char *buffer = NULL;
    int *vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter = NULL;
    int Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres = 0;
    
    printf("Bienvenido, este programa determina cuantas veces se repiten los caracteres de una frase...\n");
    
    buffer = Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( &buffer );
    
    Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres = CuantasVeces( buffer, vector_dinamico_almacen_de_cantidad_de_repeticiones_de_un_caracter );
    
    printf("El mayor nro de repeticiones de uno o mas caracteres fue: %i\n", Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres );
    
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
    }
    else
    {
        printf("La cantidad de caracteres leidos fueron: %li\n", cantcaracteresleidos);
        printf("El texto ingresado fue: %s\n", *buffer);
    }
    
    /* [ESP] Remueve \n
       [ENG] Removes \n */
    *(*(buffer)+(cantcaracteresleidos-1))= '\0';
    
    return *buffer;
}

int CuantasVeces( const char *buffer, int *vec_rep)
{
    int Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres = 0, k;
    size_t tamanio_buffer;
    int *vec_codigos = NULL;
    
    tamanio_buffer = strlen( buffer );
    printf("El tamanio del texto es de %li caracteres\n", tamanio_buffer);
    
    vec_rep = (int *)malloc( tamanio_buffer * sizeof(int));
    if( vec_rep == NULL ) { printf("Error malloc\n"); exit(-1); }
    
    vec_codigos = (int *)malloc( tamanio_buffer * sizeof(int));
    if( vec_codigos == NULL ) { printf("Error malloc\n"); exit(-1); }
    
    k = Evaluacion_y_printeo_de_caracteres_repetidos( tamanio_buffer, buffer, vec_rep, vec_codigos );
    
    Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres = Evaluacion_mayor_cant_de_repeticiones( k, vec_rep, vec_codigos );
    
    free(vec_rep);
    free(vec_codigos);
    
    return Mayor_nro_de_repeticiones_de_uno_o_mas_caracteres;
}

int Evaluacion_y_printeo_de_caracteres_repetidos( size_t tamanio_buffer, const char *buffer, int *vec_rep, int *vec_codigos )
{
    int i, j, k = 0, cont_de_repeteciones;
    
    /* [ESP] Analiza toda la tabla ASCII de 32 a 250
       [ENG] Analyzes the entire ASCII table from 32 to 250 */
    for( j = 32; j <= 250; j++ )
    {
        for( i = 0, cont_de_repeteciones = 0; i < tamanio_buffer; i++ )
        {
            if( buffer[i] == j )
                cont_de_repeteciones++;
        }
        
        if( cont_de_repeteciones >= 1 )
        {
            vec_rep[k] = cont_de_repeteciones;
            vec_codigos[k] = j;
            printf("El caracter %c se repitio %i veces\n", j, cont_de_repeteciones);
            k++;
        }
    }
    
    return k;
}

int Evaluacion_mayor_cant_de_repeticiones( int k, int *vec_rep, int *vec_codigos )
{
    int i, auxiliar = 0;
    
    if (k == 0) return 0;
    
    /* [ESP] Encuentra el máximo contando elementos iterativamente
       [ENG] Finds the maximum counting elements iteratively */
    auxiliar = vec_rep[0];
    for( i = 1; i < k; i++)
    {
        if( vec_rep[i] > auxiliar )
            auxiliar = vec_rep[i];
    }
    
    printf("El/los caracteres de mayor repeticion es/fueron: ");
    for( i = 0; i < k; i++ )
    {
        if( auxiliar == vec_rep[i] )
        {
            printf("%c  ", vec_codigos[i]);
        }
    }
    printf("\n");
    
    return auxiliar;
}
