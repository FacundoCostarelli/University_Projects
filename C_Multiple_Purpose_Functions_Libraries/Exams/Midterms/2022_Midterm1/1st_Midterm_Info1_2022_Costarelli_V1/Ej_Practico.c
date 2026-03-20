/**
 * @file    Ej_Practico.c
 * @brief   [ESP] 1er Parcial Info1 2022_Costarelli_V1: Gráfica y serie de Maclaurin (Versión 1).
 *          [ENG] 1st Midterm Info1 2022_Costarelli_V1: Chart and Maclaurin series (Version 1).
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<math.h>

/* [ESP] Utilizamos una estructura auxiliar creada dinamicamente a la cual se le cambian los valores
         de x e y, luego se asignan a 2 vectores dinamicos. 
   [ENG] We use an auxiliary structure dynamically created where x and y values are modified,
         then assigned to 2 dynamic vectors. */

#define pi 3.1416 
#define kmax 20 
#define nmax 20 
#define cant_estructuras 1 

/**
 * @brief [ESP] Estructura que almacena un punto (x, y).
 *        [ENG] Structure that stores a point (x, y).
 */
typedef struct elemento
{
    long double x;
    long double y;
} punto;

/**
 * @brief [ESP] Calcula la función para el valor de x en la estructura y lo carga.
 *        [ENG] Computes function for the x value in the structure and loads it.
 */
int MiFuncion(punto *p1);

/**
 * @brief [ESP] Función que calcula el coseno mediante la serie de Maclaurin.
 *        [ENG] Function that computes the cosine using the Maclaurin series.
 */
long double SerieMaclaurinCos( long double xcos );

/**
 * @brief [ESP] Función que calcula el factorial de un número.
 *        [ENG] Function that calculates the factorial of a number.
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
    punto **p1 = NULL;
    punto **PunteroTemporal1 = NULL;
    punto *PunteroTemporal2 = NULL;
    long double *VectorDinamicoValoresX = NULL;
    long double *VectorDinamicoValoresY = NULL;
    long double *PunteroTemporal = NULL;
    long double Xmin, Xmax;
    int cant_puntos;
    long double x1;
    int i;
    
    printf("Ingrese el valor de Xmin: ");
    scanf("%Lf", &Xmin);
    __fpurge(stdin);
    
    printf("Ingrese el valor de Xmax: ");
    scanf("%Lf", &Xmax);
    __fpurge(stdin);
    
    printf("Ingrese la cantidad de puntos para usar en su grafico: ");
    scanf("%i", &cant_puntos);
    __fpurge(stdin);
    
    PunteroTemporal1 = (punto **)malloc( cant_estructuras * sizeof(punto *));
    if( PunteroTemporal1 == NULL)
    {
        printf("Ha ocurrido un error con la asignacion de memoria\n");
        return 0;
    }
    p1 = PunteroTemporal1;
    
    PunteroTemporal2 = (punto *)malloc( sizeof(punto));
    if( PunteroTemporal2 == NULL)
    {
        printf("Ha ocurrido un error con la asignacion de memoria\n");
        return 0;
    }
    *p1 = PunteroTemporal2;
    
    PunteroTemporal = (long double *)malloc( cant_puntos * sizeof(long double));
    if( PunteroTemporal == NULL) return 0;
    VectorDinamicoValoresX = PunteroTemporal;
    
    PunteroTemporal = (long double *)malloc( cant_puntos * sizeof(long double));
    if( PunteroTemporal == NULL) return 0;
    VectorDinamicoValoresY = PunteroTemporal;
    
    for(i = 0, x1=Xmin; x1<=Xmax || i< cant_puntos; x1+= ((Xmax-Xmin)/cant_puntos), i++)
    {   
        (*p1)->x = x1;
        if( MiFuncion( *p1 ) == 0 )
        {
            printf("|%Lf|\b", (*p1)->y);
            VectorDinamicoValoresX[i] = (*p1)->x;
            VectorDinamicoValoresY[i] = (*p1)->y;
        }
        else
        {
            printf("Hubo un error con MiFuncion\n");
            return 0;
        }
    }
    printf("\n");
    
    /* [ESP] Imprimir tabla / [ENG] Print table */
    for( i = 0; i < cant_puntos; i++ ) printf("|%Lf|\b", VectorDinamicoValoresX[i]);        
    printf("\n");
    for( i = 0; i < cant_puntos; i++ ) printf("|%Lf|\b", VectorDinamicoValoresY[i]);
    
    free(*p1);
    free(p1);
    free(VectorDinamicoValoresX);
    free(VectorDinamicoValoresY);
    
    return 0;
}

int MiFuncion( punto *p1)
{
    int n;
    int chek = 0;
    long double y1 = 0, k1 = -1;
    for( n = 1; n <= kmax; n++ )
    {   
        y1 = y1 +  ( SerieMaclaurinCos( (p1->x) * (long double) n ) / powl( (long double) n, (long double) 2  ) ) * k1;
        k1 *= 1;
    }
    p1->y = ( powl( (long double) pi, (long double) 2) / (long double) 3 ) + ( (long double) 4 * y1 );
    return chek;
}

long double SerieMaclaurinCos( long double xcos )
{
    int n;
    long double nrofactorial;
    long double cos = 0, k = 1;
    for( n = 0; n < nmax; n++ )
    {
        nrofactorial = 2 * (long double)n;
        cos +=  ( ( powl( xcos, nrofactorial ) / factorial( nrofactorial ) )* k );
        k *= -1;
    }
    return cos;
}

long double factorial( long double nrofactorial ) 
{
    long double factorial = 1, ninicial;
    for( ninicial = 1; ninicial <= nrofactorial; ninicial++ )
    {
        factorial *= ninicial;
    }
    return factorial;
}
