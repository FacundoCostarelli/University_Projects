/**
 * @file    Ejercicio2.c
 * @brief   [ESP] Ejercicio 2 Tema 1 (2022): Frecuencia de letras en matriz.
 *          [ENG] Exercise 2 Theme 1 (2022): Letter frequency in matrix.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<ctype.h>

#define tamanio_VectorDeEnteros 26

/**
 * @brief [ESP] Verifica cuántas veces se repiten letras (A-Z) en la matriz.
 *        [ENG] Checks how many times letters (A-Z) repeat in the matrix.
 */
void CuantasVeces( char ***P, int *VectorDeEnteros, int filas, int columnas );

/**
 * @brief [ESP] Solicita memoria dinámica y carga la matriz.
 *        [ENG] Allocates dynamic memory and loads the matrix.
 */
char ** crearmatrizcondatos( char ***P, int filas, int columnas);

/**
 * @brief [ESP] Lee línea a línea la matriz desde teclado.
 *        [ENG] Reads matrix line by line from keyboard.
 */
void cargamatriz( char ***P, int filas, int columnas );

/**
 * @brief [ESP] Muestra el contenido de la matriz 2D.
 *        [ENG] Shows the content of the 2D matrix.
 */
void mostrarmatriz( char ***P, int filas, int columnas );

/**
 * @brief [ESP] Libera la memoria de la matriz 2D.
 *        [ENG] Frees 2D matrix memory.
 */
void liberarmatriz( char ***P, int filas );

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(void)
{
    int filas, columnas;
    char ***vectordepunterosdoblesdinamicos = NULL;
    int *PunteroaCantidadeFilas = NULL;
    int *PunteroaCantidadeColumnas = NULL;
    char ***Punterotemporal = NULL;
    int *Punterotemporal1 = NULL;
    int *VectorDeEnteros = NULL;
    
    int i, j; 
    
    printf("Bienvenido, este programa permite crear una matriz con caracteres, ingresar por teclado dichos caracteres y determinar cuales caracteres se repiten y cuantas veces\n");
    
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    __fpurge(stdin);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);
    __fpurge(stdin);
    
    Punterotemporal = (char ***)malloc(sizeof(char **));
    if( Punterotemporal == NULL ) { return 0; }
    else
    {
        vectordepunterosdoblesdinamicos = Punterotemporal;
        *(vectordepunterosdoblesdinamicos) = crearmatrizcondatos( vectordepunterosdoblesdinamicos, filas, columnas );
    }
    
    Punterotemporal1 = (int *)malloc(sizeof(int));
    if( Punterotemporal1 == NULL ) { return 0; }
    else
    {
        PunteroaCantidadeFilas = Punterotemporal1;
        *(PunteroaCantidadeFilas) = filas;
    }
    
    Punterotemporal1 = (int *)malloc(sizeof(int));
    if( Punterotemporal1 == NULL ) { return 0; }
    else
    {
        PunteroaCantidadeColumnas = Punterotemporal1;
        *(PunteroaCantidadeColumnas) = columnas;
    }
    
    printf("Su matriz quedo dada como: \n");
    printf("| %i | Filas x | %i | Columnas \n", *(PunteroaCantidadeFilas), *(PunteroaCantidadeColumnas));
    
    Punterotemporal1 = (int *)calloc( tamanio_VectorDeEnteros, sizeof(int) );
    if( Punterotemporal1 == NULL ) { return 0; }
    else
    {
        VectorDeEnteros = Punterotemporal1;
    }
    
    CuantasVeces( vectordepunterosdoblesdinamicos, VectorDeEnteros, *(PunteroaCantidadeFilas), *(PunteroaCantidadeColumnas) );
    
    printf("Las distintas cantidades de repeticiones junto a dichos carecteres son\n");
    for( i = 0; i < tamanio_VectorDeEnteros; i++ )  printf("|%i|\b", *(VectorDeEnteros + i) );
    printf("\n");
    for( i = 97; i <= 122; i++ ) printf("|%c|\b", i);
    printf("\n");
    for( j = 65; j<= 90; j++ )   printf("|%c|\b", j);
    printf("\n");
        
    liberarmatriz( vectordepunterosdoblesdinamicos, *(PunteroaCantidadeFilas) );
    free(vectordepunterosdoblesdinamicos);
    free(PunteroaCantidadeFilas);
    free(PunteroaCantidadeColumnas);
    free(VectorDeEnteros);
    
    printf("Toda la memoria dinamica usada ha sido liberada correctamente\n");
    return 0;   
}

void CuantasVeces( char ***P, int *VectorDeEnteros, int filas, int columnas )
{
    int i, j, k, n, aux;
    for( i = 0; i < filas; i++ )
    {
        for( j = 0; j < columnas; j++ )
        {
            aux = tolower( (int)(*(*((*P)+ i)+j)) );
            for( n = 0, k = 97; k <= 122; k++ )
            {
                if( aux == k )
                {
                    (*(VectorDeEnteros + n))++;
                }
                n++;
            }
        }
    }
}

char ** crearmatrizcondatos( char ***P, int filas, int columnas)
{
    *(P) = (char **)malloc( filas * sizeof(char *) );
    cargamatriz( P, filas, columnas );
    mostrarmatriz( P, filas, columnas );
    return *(P);
}

void cargamatriz( char ***P, int filas, int columnas )
{
    int i, j;
    for( i = 0; i < filas; i++ )
    {
        *((*P) + i) = (char *)malloc( columnas * sizeof(char) ); 
    }
    printf("Por favor, ingrese los caracteres de la matriz elemento por elemento:\n");
    
    for( i = 0; i < filas; i++ )
    {
        for( j = 0; j < columnas; j++ )
        {
            printf("[%i][%i] =  ",i,j);
            scanf("%c", *((*P)+ i)+j);
            __fpurge(stdin);
        }
    }
}

void mostrarmatriz( char ***P, int filas, int columnas )
{
    int i, j;
    for( i = 0; i < filas; i++ )
    {
        for( j = 0; j < columnas; j++ )
        {
            printf("| %c |\t", (*(*((*P)+ i)+j)) );
        }
        printf("\n");
    }
}

void liberarmatriz( char ***P, int filas ) 
{
    int i;
    for( i = 0; i < filas; i++ )
    {
        free((*((*P) + i)));
    }
    free((*P));
}
