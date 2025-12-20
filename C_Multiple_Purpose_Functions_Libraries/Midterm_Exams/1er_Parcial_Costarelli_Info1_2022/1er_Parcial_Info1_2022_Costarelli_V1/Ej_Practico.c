#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<math.h>
//Yo utilizo una estrctura auxiliar creada dinamicamente a la cual se le van cambiando los valores de x e y donde luego de esto, lo asigno cada par de puntos a 2 vectores dinamicos correspondientemente. Es decir, el vector de estructuras, es de uno solo.
#define pi 3.1416 //cte global para usar en las funciones 
#define kmax 20 //cte global para usar como cant de terminos en la formula de sumatoria de MiFuncion
#define nmax 20 //cte global para usar como cantidad de terminos en sumatoria de la formula del coseno
#define cant_estructuras 1 //cte global para definir el tamanio de un array dinamico de punteros a estructuras
typedef struct elemento
{
    long double x;
    long double y;
    
    
}punto;

//Esta funcion cuando recibe la estructura tipo punto, dentro de ella ya debe estar el valor de x pero asi mismo debe cargar el valor de y
int MiFuncion(punto *p1);
//Funcion que calcula el coseno de un numero
long double SerieMaclaurinCos( long double xcos );
//Funcion que calcula el factorial de un numero
long double factorial( long double nrofactorial );

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
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    
    p1 = PunteroTemporal1;
    
    PunteroTemporal2 = (punto *)malloc( sizeof(punto));
    
    if( PunteroTemporal2 == NULL)
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    
    *p1 = PunteroTemporal2;
    
    //Proteccion contra NULL de malloc
    PunteroTemporal = (long double *)malloc( cant_puntos * sizeof(long double));
    
    if( PunteroTemporal == NULL)
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    //Asigno la direccion almacenada en PunteroTemporal al vector dinamico correspondiente
    VectorDinamicoValoresX = PunteroTemporal;
    
    //Proteccion contra NULL de malloc
    PunteroTemporal = (long double *)malloc( cant_puntos * sizeof(long double));
    if( PunteroTemporal == NULL)
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    //Asigno la direccion almacenada en PunteroTemporal al vector dinamico correspondiente
    VectorDinamicoValoresY = PunteroTemporal;
    
    for(i = 0, x1=Xmin; x1<=Xmax || i< cant_puntos; x1+= ((Xmax-Xmin)/cant_puntos), i++)
    {   
        //En cada iteracion cargo cada valor de x en la estructura, luego cargo el valor de y a traves de MiFuncion, luego cargo los valores de x e y de la estructura, en los arrays dinamicos correspondientes
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
    //Printeo en pantalla la tabla de valores de datos x e y
    for( i = 0; i < cant_puntos; i++ )
    {
        printf("|%Lf|\b", VectorDinamicoValoresX[i]);        
    }
    printf("\n");
    for( i = 0; i < cant_puntos; i++ )
    {
        printf("|%Lf|\b", VectorDinamicoValoresY[i]);
    }
    
    free(*p1);
    free(p1);
    //Liberacion de memoria dinamica usada por arrays dinamicos
    free(VectorDinamicoValoresX);
    free(VectorDinamicoValoresY);
    
    
    return 0;
}
//Funcion que halla el valor y para el valor x de la estructura, tambien lo carga alli
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
//Funcion que calcula el coseno pedido 
long double SerieMaclaurinCos( long double xcos )
{
    
    int n;
    long double nrofactorial;
    long double cos = 0, k = 1;
    for( n = 0; n < nmax; n++ )
    {
        nrofactorial = 2 * (long double)n;
        cos +=  ( ( powl( xcos, nrofactorial ) / factorial( nrofactorial ) )* k );//obtengo la "y" de la Serie de Maclaurin de Cos(x)
        k *= -1;
    }
    
    return cos;
}
//Funcion que calcula el factorial de un numero
long double factorial( long double nrofactorial ) 
{
    
    long double factorial = 1, ninicial;
    
    for( ninicial = 1; ninicial <= nrofactorial; ninicial++ )
    {
        factorial *= ninicial;//calculo el factorial de 2*i+1 de la formula original de la sumatoria de f1 y lo mismo para el factorial de 2*i de la sumatoria de f2. Esta funcion propia factorial es reutilizable, ya que proviene de otro codigo. En caso de 0! entonces el cuerpo del "for" no se ejecuta ya que no se cumple la condicion y entonces se retorna factorial = 1
    }
    
    return factorial;
}
