/**
 * @file    Ej_Practico_Vfinal.c
 * @brief   [ESP] 1er Parcial Info1 2022_Costarelli_Vfinal: Gráfica, sumatoria, archivo Octave.
 *          [ENG] 1st Midterm Info1 2022_Costarelli_Vfinal: Chart, sum, Octave file.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define pi 3.14159265 
#define kmax 30 
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
 * @brief [ESP] Calcula la función para la variable x y la almacena.
 *        [ENG] Computes function for x variable and stores it.
 */
int MiFuncion(punto *p1);

/**
 * @brief [ESP] Calcula el factorial (reutilizable).
 *        [ENG] Computes the factorial (reusable).
 */
long double factorial( long double nrofactorial );

/**
 * @brief [ESP] Halla el 1er máximo relativo.
 *        [ENG] Finds the 1st relative maximum.
 */
punto * Maximo( punto **p1, long double *VectorDinamicoValoresX, long double *VectorDinamicoValoresY );

/**
 * @brief [ESP] Halla el 1er mínimo relativo.
 *        [ENG] Finds the 1st relative minimum.
 */
punto * Minimo( punto **p1, long double *VectorDinamicoValoresX, long double *VectorDinamicoValoresY, int cant_puntos );

/**
 * @brief [ESP] Pide memoria dinámicamente y carga el archivo octave.
 *        [ENG] Requires dynamic memory and loads the octave file.
 */
char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );


/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(void)
{
    punto **p1 = NULL, **PunteroTemporal1 = NULL;
    punto *PunteroTemporal2 = NULL;
    long double *VectorDinamicoValoresX = NULL, *VectorDinamicoValoresY = NULL, *PunteroTemporal = NULL;
    char *buffer = NULL;
    long double Xmin, Xmax, x1;
    int cant_puntos, i, fd;
    
    /* [ESP] Pedido de Xmin,Xmax y la cantidad de puntos / [ENG] Request Xmin,Xmax and amount of points */
    printf("Ingrese el valor de Xmin(en grados): ");
    scanf("%Lf", &Xmin);
    __fpurge(stdin);
    Xmin = ( 2 * pi * Xmin ) / 360; 
    
    printf("Ingrese el valor de Xmax(en grados): ");
    scanf("%Lf", &Xmax);
    __fpurge(stdin);
    Xmax = ( 2 * pi * Xmax ) / 360; 
     
    printf("Ingrese la cantidad de puntos para usar en su grafico: ");
    scanf("%i", &cant_puntos);
    __fpurge(stdin);
    
    PunteroTemporal1 = (punto **)malloc( cant_estructuras * sizeof(punto *));
    if( PunteroTemporal1 == NULL) return 0;
    p1 = PunteroTemporal1;
    
    PunteroTemporal2 = (punto *)malloc( sizeof(punto));
    if( PunteroTemporal2 == NULL) return 0;
    *p1 = PunteroTemporal2;
    
    PunteroTemporal = (long double *)malloc( cant_puntos * sizeof(long double));
    if( PunteroTemporal == NULL) return 0;
    VectorDinamicoValoresX = PunteroTemporal;
    
    PunteroTemporal = (long double *)malloc( cant_puntos * sizeof(long double));
    if( PunteroTemporal == NULL) return 0;
    VectorDinamicoValoresY = PunteroTemporal;
    
    /* [ESP] Creacion tabla / [ENG] Table creation */
    for(i = 0, x1=Xmin; x1<=Xmax && i< cant_puntos; x1+= ((Xmax-Xmin)/cant_puntos), i++)
    {   
        (*p1)->x = x1;
        if( MiFuncion( *p1 ) == 0 )
        {
            VectorDinamicoValoresX[i] = (*p1)->x;
            VectorDinamicoValoresY[i] = (*p1)->y;
        }
        else return 0;
    }
    printf("\n");
    
    printf("Su tabla de valores queda como:\n");
    printf("X:\b ");
    for( i = 0; i < cant_puntos; i++ ) printf("|%Lf|\b", VectorDinamicoValoresX[i]);        
    printf("\n\nY:\b");
    for( i = 0; i < cant_puntos; i++ ) printf("|%Lf|\b", VectorDinamicoValoresY[i]);
    printf("|\n");
    
    *p1 = Maximo( p1, VectorDinamicoValoresX, VectorDinamicoValoresY );
    printf("El valor del Xcritico que produce el 1er maximo relativo es: %Lf\n", (*p1)->x);
    printf("El valor del 1er maximo relativo es: %Lf\n", (*p1)->y);
    
    *p1 = Minimo( p1, VectorDinamicoValoresX, VectorDinamicoValoresY, cant_puntos );
    if( (*p1)->x == 0 && (*p1)->y == 0 ) printf("No hay minimo en esta funcion\n");
    else
    {
        printf("El valor del Xcritico que produce el 1er minimo relativo es: %Lf\n", (*p1)->x);
        printf("El valor del 1er minimo relativo es: %Lf\n", (*p1)->y);
    }
    
    /* [ESP] Archivo Octave / [ENG] Octave file */
    buffer = Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( &buffer );
    fd=open(buffer, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    dprintf(fd,"hold on \n");
    dprintf(fd,"A=[");
    for( i = 0; i < cant_puntos; i++ )
    {
        dprintf(fd,"%6.3Lf, %6.3Lf", VectorDinamicoValoresX[i], VectorDinamicoValoresY[i]);
        if( i < cant_puntos -1 ) dprintf(fd,";");
    }
    dprintf(fd,"]\n");
    dprintf(fd, "plot(A(:,1),A(:,2),\"b\")\n");

    printf("Su archivo .m de octave ha sido creado correctamente.\n");

    free(*p1); free(p1);
    free(VectorDinamicoValoresX); free(VectorDinamicoValoresY);
    free(buffer);
    
    return 0;
}

int MiFuncion( punto *p1)
{
    int n, chek = 0;
    long double y1 = 0, k1 = -1;
    for( n = 1; n <= kmax; n++ )
    {   
        y1 = y1 + ( cosl( (p1->x) * (long double) n) / powl( (long double) n, (long double) 2  ) ) * k1;
        k1 *= 1;
    }
    p1->y = ( powl( (long double) pi, (long double) 2) / (long double) 3 ) + ( (long double) 4 * y1 );
    return chek;
}

punto * Maximo( punto **p1, long double *VectorDinamicoValoresX, long double *VectorDinamicoValoresY )
{
    int i;
    for( i = 0; VectorDinamicoValoresY[i] < VectorDinamicoValoresY[i+1]; i++)
    {
        if( VectorDinamicoValoresY[i+1] > VectorDinamicoValoresY[i] && VectorDinamicoValoresY[i+1] > VectorDinamicoValoresY[i+2])
        {
            (*p1)->x = VectorDinamicoValoresX[i+1];
            (*p1)->y = VectorDinamicoValoresY[i+1];
        }
    }
    return *p1;
}

punto * Minimo( punto **p1, long double *VectorDinamicoValoresX, long double *VectorDinamicoValoresY, int cant_puntos )
{
    int i, flag;
    for( i = 0, flag = 0; (VectorDinamicoValoresY[i] < VectorDinamicoValoresY[i+1] || flag == 0) && i < cant_puntos-1; i++)
    {
        if( VectorDinamicoValoresY[i+1] < VectorDinamicoValoresY[i] && VectorDinamicoValoresY[i+1] < VectorDinamicoValoresY[i+2] )
        {
            (*p1)->x = VectorDinamicoValoresX[i+1];
            (*p1)->y = VectorDinamicoValoresY[i+1];
            flag = 1;
        }
    }
    if( flag == 0 ) { (*p1)->x = 0; (*p1)->y = 0; }
    return *p1;
}

char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer )
{
    size_t capacidad = 0;
    ssize_t cantcaracteresleidos;
    
    printf("Ingrese nombre archivo octave (\".m\"): ");
    cantcaracteresleidos = getline( buffer, &capacidad, stdin ); 
    
    if( cantcaracteresleidos == -1 ) exit(-1);
    
    *(*(buffer)+(cantcaracteresleidos-1))= '\0';
    return *buffer;
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
