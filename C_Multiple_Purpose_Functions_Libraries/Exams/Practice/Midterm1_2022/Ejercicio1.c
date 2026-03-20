/**
 * @file    Ejercicio1.c
 * @brief   [ESP] Ejercicio 1 Tema 1 (2022): Cálculo de sumatorias y tabla de valores.
 *          [ENG] Exercise 1 Theme 1 (2022): Summation calculations and values table.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1

/**
 * @brief [ESP] Calcula tabla para función 1 (seno serie Taylor).
 *        [ENG] Computes table for function 1 (sine Taylor series).
 */
int funcion1(int i,int n,long double xi, long double xf, long double *x, long double *y);

/**
 * @brief [ESP] Calcula tabla para función 2 (coseno serie Taylor).
 *        [ENG] Computes table for function 2 (cosine Taylor series).
 */
int funcion2(int i,int n,long double xi, long double xf, long double *x, long double *y);

/**
 * @brief [ESP] Evalúa la sumatoria de f1.
 *        [ENG] Evaluates f1 summation.
 */
long double Sumatoria_f1( int i, long double x);

/**
 * @brief [ESP] Evalúa la sumatoria de f2.
 *        [ENG] Evaluates f2 summation.
 */
long double Sumatoria_f2( int i, long double x);

/**
 * @brief [ESP] Calcula el factorial de un número dado.
 *        [ENG] Calculates factorial of a given number.
 */
long double factorial( long double nrofactorial );

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(void)
{
    int i, n = 0;
    long double xi = 0, xf = 0;
    char opcion;
    char aux;
    int cont_CASES_A = 0;
    int j;
    
    long double *VectorPuntosf1X = NULL;
    long double *VectorPuntosf1Y = NULL;
    long double *VectorPuntosf2X = NULL;
    long double *VectorPuntosf2Y = NULL;
    long double *PunteroTemporal = NULL;
    
    printf("Bienvenido al menu principal, elija por favor alguna de las opciones\n");
    printf("Escriba \"A\" para: Ingresar datos(n, xi, xf)\n");
    printf("Escriba \"B\" para: Llamar f1\n");
    printf("Escriba \"C\" para: Llamar f2\n");
    printf("Escriba \"D\" para: Salir \n");
    
    while ( ( opcion = getchar() ) != EOF )
    {
        switch(opcion)
        {
            case 'A': case 'a':
                 cont_CASES_A++;
                 printf("Ingrese por favor la cantidad de pares de puntos \"n\":  ");
                 scanf("%i", &n);
                 __fpurge(stdin);
                 printf("Ingrese el valor inicial de entrada \"xi\":  ");
                 scanf("%Lf", &xi);
                 __fpurge(stdin);
                 printf("Ingrese el valor final de entrada \"xf\":  ");
                 scanf("%Lf", &xf);
                 __fpurge(stdin);
                 printf("Ha finalizado la carga de sus datos correctamente\n\n");
                 break;
            
            case 'B': case 'b':
                if( cont_CASES_A == 0 )
                {
                    printf("Elija opcion A primero\n");
                }
                else
                {
                    printf("Ingrese la cantidad de terminos de la sumatoria: ");
                    scanf("%i", &i);
                    __fpurge(stdin);
                    
                    if( cont_CASES_A == 1)
                    {
                        VectorPuntosf1X = (long double *)malloc( n * sizeof(long double ));
                        VectorPuntosf1Y = (long double *)malloc( n * sizeof(long double ));
                    }
                    else
                    {
                        VectorPuntosf1X = (long double *)realloc( VectorPuntosf1X, n * sizeof(long double ));
                        VectorPuntosf1Y = (long double *)realloc( VectorPuntosf1Y, n * sizeof(long double ));
                    }
                    
                    aux = funcion1( i, n, xi, xf, VectorPuntosf1X , VectorPuntosf1Y );
                    
                    if( aux == TRUE )
                    {
                        printf("Se llamo exitosamente a f1\n");
                        for( j = 0; j < n; j++ )  printf("%Lf | %Lf \n", *(VectorPuntosf1X + j), *(VectorPuntosf1Y + j) );
                    }
                }
                break;
            
            case 'C': case 'c':
                if( cont_CASES_A == 0 )
                {
                    printf("Elija opcion A primero\n");
                }
                else
                {
                    printf("Ingrese la cantidad de terminos de la sumatoria: ");
                    scanf("%i", &i);
                    __fpurge(stdin);
                    
                    if( cont_CASES_A == 1)
                    {
                        VectorPuntosf2X = (long double *)malloc( n * sizeof(long double ));
                        VectorPuntosf2Y = (long double *)malloc( n * sizeof(long double ));
                    }
                    else
                    {
                        VectorPuntosf2X = (long double *)realloc( VectorPuntosf2X, n * sizeof(long double ));
                        VectorPuntosf2Y = (long double *)realloc( VectorPuntosf2Y, n * sizeof(long double ));
                    }
                
                    aux = funcion2( i, n, xi, xf, VectorPuntosf2X , VectorPuntosf2Y );
                    
                    if( aux == TRUE )
                    {
                        printf("Se llamo exitosamente a f2\n");
                        for( j = 0; j < n; j++ )  printf("%Lf | %Lf \n", *(VectorPuntosf2X + j), *(VectorPuntosf2Y + j) );
                    }
                }
                break;
                                
            case 'D': case 'd':
                printf("Usted saldra del programa\n");
                free( VectorPuntosf1X );
                free( VectorPuntosf1Y );
                free( VectorPuntosf2X );
                free( VectorPuntosf2Y );
                return 0;
                
            case '\n' : case ' ': 
                break;
                
            default:
                printf("Opcion invalida\n");
                break;
        }
    }
}

int funcion1(int i,int n,long double xi, long double xf, long double *x, long double *y)
{
    int j;
    *(x) = xi;
    *(y) = Sumatoria_f1( i, *(x) );
    
    for( j = 0; *(x+j) < xf && j < n - 1; j++ )
    {
        *(x+j+1) = *(x+j) + ((xf-xi)/n);
        *(y+j+1) = Sumatoria_f1( i, *(x+j+1) );
    }
    
    return TRUE;
}

long double Sumatoria_f1( int i, long double x)
{
    int k = i - 1;
    int nro_de_terminos = ( k - 0 ) + 1;
    long double y = 0, nrofactorial;
    int c;
    
    for( c = 0; c < nro_de_terminos; c++ )
    {
        nrofactorial = 2 * (long double) c + 1;
        y += (powl(-1.0, (long double) c)) * (powl(x, nrofactorial) / factorial(nrofactorial));
    }
    
    return y;
}

int funcion2(int i,int n,long double xi, long double xf, long double *x, long double *y)
{
    int j;
    *(x) = xi;
    *(y) = Sumatoria_f2( i, *(x) );
    
    for( j = 0; *(x+j) < xf && j < n - 1; j++ )
    {
        *(x+j+1) = *(x+j) + ((xf-xi)/n);
        *(y+j+1) = Sumatoria_f2( i, *(x+j+1) );
    }
    
    return TRUE;
}

long double Sumatoria_f2( int i, long double x)
{
    int k = i - 1;
    int nro_de_terminos = ( k - 0 ) + 1;
    long double y = 0, nrofactorial;
    int c;
    
    for( c = 0; c < nro_de_terminos; c++ )
    {
        nrofactorial = 2 * (long double) c;
        y += (powl(-1.0, (long double) c)) * (powl(x, nrofactorial) / factorial(nrofactorial));
    }
    
    return y;    
}

long double factorial( long double nrofactorial ) 
{
    long double fact = 1, ninicial;
    for( ninicial = 1; ninicial <= nrofactorial; ninicial++ )
    {
        fact *= ninicial;
    }
    return fact;
}
