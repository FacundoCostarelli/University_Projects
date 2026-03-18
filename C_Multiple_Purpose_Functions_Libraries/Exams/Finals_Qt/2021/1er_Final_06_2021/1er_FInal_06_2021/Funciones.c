#include "Funciones.h"


/*Funciones de ejemplo que forman la composicion de funciones*/
float NomFun1(float x)
{
    return x + 10;
}

float NomFun2(float x)
{
    return x * 15.50;
}


//Item a)
float ** ComposicionDeFunciones(float(*ptr_fun1)(float),float(*ptr_fun2)(float))
{
    //Variables de enunciado
    float Xmin = 0,Xmax = 0, x = 0;
    int nro_de_puntos = 0;

    //Otras variables
    int i = 0;

    //Punteros para armar un array de 2D dinamico
    float **Filas = NULL;
    //float *Columnas = NULL;

    //Pido los datos de Xmin, Xmax y nro_de_puntos
    printf("Ingrese valor de abscisa minima: ");
    scanf("%f",&Xmin);
    __fpurge(stdin);

    printf("Ingrese valor de abscisa maxima: ");
    scanf("%f", &Xmax);
    __fpurge(stdin);

    printf("Ingrese el nro de puntos obtener: ");
    scanf("%d",&nro_de_puntos);
    __fpurge(stdin);

    //Creo dinamicamente un array de 2 dimensiones. El nro de filas depende del nro de puntos
    //EL nro de columnas son 2. Una para las absicas y otra para las ordenadas

    Filas = (float **)malloc( (nro_de_puntos+1) * sizeof(float *));
    if(Filas == NULL)
    {
        printf("Error durante la asignacion de memoria dinamica para el array de ptrs a FIlas\n");
        exit(ERROR);
    }

    //Cargo el ultimo elemento el array de punteros a filas con NULL para marcar el final del array
    Filas[nro_de_puntos] = NULL;

    for( i = 0; i < nro_de_puntos; i++ )
    {
        Filas[i] = (float *)malloc( 2 * sizeof(float) );
        if(Filas[i] == NULL)
        {
            printf("Erro durante asignacion de memoria dinamica el array de 2 columnas en la fila %d\n",i);
            exit(ERROR);
        }
    }
    printf("Linea 65 ok\n");
    for(x=Xmin,i = 0; x<=Xmax; x+= ((Xmax-Xmin)/nro_de_puntos) , i++)
    {
        if( Filas[i] == NULL )
            break;
        else
        {
            Filas[i][0] = x;
            Filas[i][1] = ptr_fun1(ptr_fun2(x));
        }
    }

    printf("Linea 75 ok\n");

    printf("TABLA: X      |   Y\n");
    //Imprimo la matriz para ver como queda cargada
    for( i = 0; i < nro_de_puntos; i++ )
    {
        printf("       %.2f   |   %.2f\n",Filas[i][0],Filas[i][1]);
    }

    //Una vez retornado el array 2D dinamico habria que realizar un free para las filas y columnas
    //para liberar la memoria. Esto en otro scope.
    return Filas;
}

//Item b)
/*Para llamarla hay que paserle el nombre de 2 funciones a componerse y recibir lo devuelto en un puntero doble*/
/*Para acceder a los datos habria que utilizar un ciclo for y usar le puntero doble con la sintaxis de un array
de 2D ya que buscamos acceder a cada fila y luego a cada columna de esa fila. Esto es Filas[indicefila][indicecolumna]
Esto es para poder imprimir los datos, leerlos, reescribir, etc*/
/*FInalmente hay que liberar la memoria dinamica. Para ello primero liberar la memoria de las columnas y luego la
memoria del array de punteros a filas. Hay que saber cual es la ultima fila y para buscarla el ultimo
elemento de punteros a filas deberia ser NULL. Estos es:

//Libero las columnas
i = 0;
for( i = 0; Filas[i] != NULL; i++ )
    free(Filas[i]);

//Libero las filas
free(Filas);
*/
