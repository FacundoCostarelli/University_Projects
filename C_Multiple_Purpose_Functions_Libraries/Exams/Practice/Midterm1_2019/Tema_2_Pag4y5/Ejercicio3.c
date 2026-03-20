/**
 * @file    Ejercicio3.c
 * @brief   [ESP] Ejercicio 3 Tema 2: Frecuencia de un caracter en frase.
 *          [ENG] Exercise 3 Theme 2: Frequency of a character in a phrase.
 *
 * @author  Facundo Costarelli
 * @date    2019
 * @course  Informática 1 — UTNBA
 */

#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

/**
 * @brief [ESP] Cantidad de ocurrencias y reserva de memoria.
 *        [ENG] Ocurrence count and memory allocation.
 */
int CuantasVeces( char *buffer, char Caracter_de_estudio, int *Vector_dinamico );

/**
 * @brief [ESP] Obtiene texto del teclado con memoria dinámica.
 *        [ENG] Gets keyboard text with dynamic memory.
 */
char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );

/**
 * @brief [ESP] Evalúa cada posición de la frase para coincidencia y guarla.
 *        [ENG] Evaluates phrase positions for matches and stores them.
 */
int Evaluacion_de_caracterestudiado_vs_caracteresstring_y_printeo_de_posiciones_de_repeticion( int tamanio_buffer, char Caracter_de_estudio, char *buffer, int *Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter);

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(void)
{
    char *buffer = NULL;
    int Cantidad_de_repeticiones_de_caracter_ingresado = 0;
    char Caracter_de_estudio;
    int *Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter = NULL;
    
    printf("Bienvenido, este programa determina cuantas veces se repite un caracter...");
    
    buffer = Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( &buffer );
    
    printf("Ingrese por favor el caracter a evaluar: ");
    scanf("%c", &Caracter_de_estudio);
    __fpurge(stdin);
    
    Cantidad_de_repeticiones_de_caracter_ingresado = CuantasVeces( buffer, Caracter_de_estudio, Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter );
    
    printf("La cantidad de veces que se repite el caracter es: %i\n", Cantidad_de_repeticiones_de_caracter_ingresado );
    
    free(buffer);
    return 0;
}

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer )
{
    size_t capacidad = 0;
    ssize_t cantcaracteresleidos;
    
    printf("\nIngrese por favor la frase que desea evaluar: ");
    cantcaracteresleidos = getline( buffer, &capacidad, stdin ); 

    if( cantcaracteresleidos == -1 )
    {
        printf("Hay un error con la lectura del texto ingresado");
    }
    else
    {
        printf("Caracteres leidos: %li\n", cantcaracteresleidos);
        printf("El texto ingresado fue: %s\n", *buffer);
    }
    *(*(buffer)+(cantcaracteresleidos-1))= '\0';
    
    return *buffer;
}

int CuantasVeces( char *buffer, char Caracter_de_estudio, int *Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter )
{
    int cont_de_repeticiones = 0; 
    size_t tamanio_buffer;
    
    tamanio_buffer = strlen( buffer );
    printf("El tamanio del texto es de %li caracteres\n", tamanio_buffer);
    
    Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter = (int *)malloc( tamanio_buffer * sizeof(int));
    if( Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter == NULL )
    {
        printf("Hay un error con la asignacion de memoria dinamica\n");
        exit(-1);
    }
    
    cont_de_repeticiones = Evaluacion_de_caracterestudiado_vs_caracteresstring_y_printeo_de_posiciones_de_repeticion( tamanio_buffer, Caracter_de_estudio, buffer, Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter);
   
    free( Vector_dinamico_de_posiciones_de_ocurrencias_del_caracter );
    
    return cont_de_repeticiones;
}

int Evaluacion_de_caracterestudiado_vs_caracteresstring_y_printeo_de_posiciones_de_repeticion( int tamanio_buffer, char Caracter_de_estudio, char *buffer, int *vec_pos )
{
    int i, j;
    int cont_de_repeticiones = 0;
    
    for( i = 0, j = 0; i < tamanio_buffer; i++ )
    {
        if( buffer[i] == Caracter_de_estudio )
        {
            cont_de_repeticiones++;
            vec_pos[j] = i;
            j++;
        }
    }
    
    printf("Las posiciones (base 0) donde se repite el caracter son: \n");
    for( i = 0; i < j; i++ )
    {
        printf("%i ", vec_pos[i] ); 
    }
    printf("\n");
    
    return cont_de_repeticiones;
}
