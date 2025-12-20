#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<math.h>

#define CANTMATRIXES 2
#define FILAS 10
#define COLUMNAS 10
#define PI 3.142
#define NMAXPUNTOS 100


double SerieMaclaurinCos( int nmax, double xcos );
double factorial( int nrofactorial );
int FunCos( double array_matrices[][FILAS][COLUMNAS], double Xmin, double Xmax);



int main(void)
{
    double Xmin, Xmax;
    int nro_puntos, i ,j, k;
    double array_matrices[CANTMATRIXES][FILAS][COLUMNAS];

    printf("Ingrese el Xmin en grados: ");
    scanf("%lf", &Xmin);
    __fpurge(stdin);

    Xmin = Xmin * ((2.0 * PI) / 360.0); //Convierto los grados ingresados a radianes

    printf("Ingrese el Xmax en grados: ");
    scanf("%lf", &Xmax);
    __fpurge(stdin);

    Xmax = Xmax * ((2.0 * PI) / 360.0); //Convierto los grados ingresados a radianes

    nro_puntos = FunCos(array_matrices, Xmin, Xmax);

    printf("La cantidad de puntos obtenidos fueron %d\n", nro_puntos);

    for( k = 0; k < CANTMATRIXES; k++ )
    {
        if( k == 0 )
            printf("La matrizX con los valores de las absicias cargadas queda como:\n");
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

//Funcion que pide el enunciado. Dicha funcion genera los puntos (x,y). A su vez llama a otra funcion para obtener cada valor de "Y" en base a la formula propuesta por enunciado
//reemplazo "double ***puntos" con la sintaxis "double array_matrices[CANTMATRIXES][FILAS][COLUMNAS]"
int FunCos( double array_matrices[][FILAS][COLUMNAS], double Xmin, double Xmax)
{
    double xcos, nro_puntos;
    int i,j,k,n;

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

    }while(nro_puntos <= 0 || nro_puntos > NMAXPUNTOS);

    for( n = 0, xcos=Xmin; xcos<=Xmax; xcos+= ((Xmax-Xmin)/nro_puntos ))
    {
        if( n < 100 )
        {   ValoresX[n] = xcos;
            ValoresY[n] = SerieMaclaurinCos(k, xcos); //los datos "y" de la Serie de Maclaurin de Cos(x) los obtengo con una funcion
            n++;
        //if(xcos+((Xmaxcos-Xmincos)/puntoscos) <= Xmaxcos)
        }

    }
    /*
    printf("Los vectores de valores X e Y luego de la carga de valores quedan como: \n");

    for( n = 0; n < NMAXPUNTOS; n++ )
        printf("|%lf| ", ValoresX[n]);

    printf("\n");
    */

    for( k = 0,  n = 0; n < CANTMATRIXES; n++ )
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
    return nro_puntos;
}

//Esta funcion anda perfectamente y es transportable
double SerieMaclaurinCos( int nmax, double xcos )
{

    int n, nrofactorial;
    double cos = 0.0, k = 1.0;
    for( n = 0; n < nmax; n++ )
    {
        nrofactorial = 2*n;
        cos +=  ( ( pow( xcos, (double) nrofactorial ) / factorial( nrofactorial ) )* k );//obtengo la "y" de la Serie de Maclaurin de Cos(x)
        k *= -1.0;
    }
    //printf("En la serie de Maclaurin de Cos tenemos que cada Y = %lf\n", cos);
    return cos;

}

double factorial( int nrofactorial )
{

    double factorial = 1.0, ninicial;

    for( ninicial = 1.0; ninicial <= (double) nrofactorial; ninicial++ )
    {
        factorial *= ninicial;//calculo el factorial de 2*n+1 de la formula original de la Serie de Maclaurin de Sen(x) y el factorial de 2*n de la formula original de la Serie de Maclaurin de Cos(x), por lo que esta funcion propia factorial es reutilizable
    }

    return factorial;

}
