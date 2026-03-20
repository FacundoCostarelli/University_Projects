/**
 * @file    Ej1.c
 * @brief   [ESP] Ejercicio 1 - Final 18-07-2022. Serie de Maclaurin para coseno (Múltiples matrices).
 *          [ENG] Exercise 1 - Final 18-07-2022. Maclaurin series for cosine (Multiple matrices).
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<math.h>

#define CANTMATRIXES 2
#define FILAS 10
#define COLUMNAS 10
#define PI 3.141592
#define NMAXPUNTOS 100

/**
 * @brief [ESP] Funciones prototipo.
 *        [ENG] Prototype functions.
 */
double SerieMaclaurinCos( int nmax, double xcos );
double factorial( int nrofactorial );
int FunCos( double array_matrices[][FILAS][COLUMNAS], double Xmin, double Xmax);

/**
 * @brief [ESP] Función principal del Ejercicio 1.
 *        [ENG] Main function for Exercise 1.
 *
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main(void)
{
    double Xmin, Xmax;
    int nro_puntos, i, j, k;
    double array_matrices[CANTMATRIXES][FILAS][COLUMNAS];

    printf("Ingrese el Xmin en grados: ");
    scanf("%lf", &Xmin);
    __fpurge(stdin);

    /* [ESP] Convierto grados a radianes / [ENG] Convert degrees to radians */
    Xmin = Xmin * ((2.0 * PI) / 360.0); 

    printf("Ingrese el Xmax en grados: ");
    scanf("%lf", &Xmax);
    __fpurge(stdin);

    /* [ESP] Convierto grados a radianes / [ENG] Convert degrees to radians */
    Xmax = Xmax * ((2.0 * PI) / 360.0); 

    nro_puntos = FunCos(array_matrices, Xmin, Xmax);

    printf("La cantidad de puntos obtenidos fueron %d\n", nro_puntos);

    /* [ESP] Imprimir matrices / [ENG] Print matrices */
    for( k = 0; k < CANTMATRIXES; k++ )
    {
        if( k == 0 )
            printf("La matrizX con los valores de las abcisas cargadas queda como:\n");
        if( k == 1 )
            printf("La matrizY con los valores de las ordenadas cargadas queda como:\n");
            
        for( i = 0; i < FILAS; i++ )
        {
            for( j = 0; j < COLUMNAS; j++ )
            {
                printf("|%lf|  ", array_matrices[k][i][j]);
            }
            printf("\n");
        }
        printf("\n\n\n");
    }

    return 0;
}

/**
 * @brief [ESP] Genera puntos X,Y basándose en serie de Maclaurin y carga el array_matrices.
 *        [ENG] Generates X,Y points based on Maclaurin series and loads the array_matrices.
 *
 * @param array_matrices [ESP] Arreglo 3D que almacena matrices. / [ENG] 3D array storing matrices.
 * @param Xmin           [ESP] Valor X min. / [ENG] Min X value.
 * @param Xmax           [ESP] Valor X max. / [ENG] Max X value.
 * @return int           [ESP] Nro de puntos calculados / [ENG] No. of calculated points
 */
int FunCos( double array_matrices[][FILAS][COLUMNAS], double Xmin, double Xmax)
{
    double xcos, nro_puntos;
    int i, j, k, n;
    double ValoresX[NMAXPUNTOS];
    double ValoresY[NMAXPUNTOS];

    memset(ValoresX, 0, sizeof(double) * NMAXPUNTOS);
    memset(ValoresY, 0, sizeof(double) * NMAXPUNTOS);

    printf("Ingrese el numero de terminos de la serie de Maclaurin para aproximar la funcion Coseno: ");
    scanf("%d", &k);
    __fpurge(stdin);

    do
    {
        printf("Ingrese el numero de puntos a graficar entre 0 y 100 inclusive: ");
        scanf("%lf", &nro_puntos);
        __fpurge(stdin);

        if(nro_puntos <= 0 || nro_puntos > NMAXPUNTOS)
            printf("Error, ha ingresado mal el nro de puntos. Vuelva a intentarlo\n");

    } while(nro_puntos <= 0 || nro_puntos > NMAXPUNTOS);

    for( n = 0, xcos = Xmin; xcos <= Xmax; xcos += ((Xmax-Xmin)/nro_puntos ))
    {
        if( n < 100 )
        {   
            ValoresX[n] = xcos;
            ValoresY[n] = SerieMaclaurinCos(k, xcos);
            n++;
        }
    }

    /* [ESP] Carga de las matrices 3D / [ENG] Loading of 3D matrices */
    for( k = 0, n = 0; n < CANTMATRIXES; n++ )
    {
        for( i = 0; i < FILAS; i++ )
        {
            for( j = 0; j < COLUMNAS; j++ )
            {
                if( n == 0 )
                    array_matrices[n][i][j] =  ValoresX[k];

                if( n == 1 )
                    array_matrices[n][i][j] =  ValoresY[k];

                k++;
            }
        }
        k = 0;
    }
    return (int)nro_puntos;
}

/**
 * @brief [ESP] Calcula la Serie de Maclaurin para el Coseno de x.
 *        [ENG] Computes Maclaurin Series for the Cosine of x.
 *
 * @param nmax [ESP] Cantidad n de términos / [ENG] Number of n terms
 * @param xcos [ESP] Valor de x (en radianes) / [ENG] x value (in radians)
 * @return double [ESP] Coseno aproximado / [ENG] Approximate cosine
 */
double SerieMaclaurinCos( int nmax, double xcos )
{
    int n, nrofactorial;
    double cos = 0.0, k = 1.0;
    
    for( n = 0; n < nmax; n++ )
    {
        nrofactorial = 2 * n;
        cos +=  ( ( pow( xcos, (double) nrofactorial ) / factorial( nrofactorial ) )* k );
        k *= -1.0;
    }
    return cos;
}

/**
 * @brief [ESP] Calcula el factorial de un número. Reutilizable.
 *        [ENG] Computes factorial of a number. Reusable.
 *
 * @param nrofactorial [ESP] Número a calcularle el factorial / [ENG] Number to calulate factorial from
 * @return double      [ESP] Valor factorial resultanto / [ENG] Result factorial value
 */
double factorial( int nrofactorial )
{
    double factorial = 1.0, ninicial;
    for( ninicial = 1.0; ninicial <= (double) nrofactorial; ninicial++ )
    {
        factorial *= ninicial;
    }
    return factorial;
}
