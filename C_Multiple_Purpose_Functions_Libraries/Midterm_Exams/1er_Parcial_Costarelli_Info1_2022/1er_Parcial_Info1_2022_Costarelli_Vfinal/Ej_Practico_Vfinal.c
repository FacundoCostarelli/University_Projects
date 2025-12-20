#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


//En mi solucion Yo utilizo una estrctura auxiliar creada dinamicamente a la cual se le van cambiando los valores de x e y donde luego de esto, lo asigno cada coordenada del par de puntos, a 2 vectores dinamicos correspondientemente. Es decir, el vector de estructuras, es de uno solo. Para el calculo de la sumatoria, al momento de utilizar coseno, hay 2 formas, una con el cosl() de math.h o con la que hice yo(abajo de todo comentada), la del math.h funciona seguro. La que hice yo tiene algunos problemas segun la cantidad de terminos para la sumatoria de la formula de SerieMaclaurinCos y ademas tambien para algunos valores ingresados en radianes de X. En esta version final del codigo, yo utilizo el cosl() de math.h.


//Es importante destacar que los valores ingresados de Xmin y Xmax, el usuario los ingresa en grados y luego se hace una conversion a radianes para poder usar cosl() y el resto de las operaciones con radianes. Algo que me habia olvidado de hacer en la 1er entrega. En la 1era version, ingresaba los valores y ej: al poner Xmin = 1 y Xmax = 10 entonces, el programa trabajaba con un rango de radianes entre 1 y 10, lo cual no tiene sentido porque hay muy pocos valores sueltos por cada vuelta de circunferencia trigonometrica. Si ingreso 0 y 360 ahora, me los pasa a radianes y tengo mas valores por vuelta de circunferencia trigonometrica

//Los maximos y minimos que muestrom son relativos a partir de considerar la definicion matematica correspondiente de AM1 de extremos relativos. Otra forma de verlo, es pensar como que en un maximo o minimo, hay un cambio de "curva", es decir, para un maximo viene subiendo la curva y luego en un determinado valor comienza a bajar. Para el caso del minimo, la curva viene bajando y luego para un determinado valor comienza a subir.

#define pi 3.14159265 //cte global para usar en las funciones 
#define kmax 30 //cte global para usar como cant de terminos en la formula de sumatoria de MiFuncion
//#define nmax 30 //cte global para usar como cantidad de terminos en sumatoria de la formula del coseno
#define cant_estructuras 1 //cte global para definir el tamanio de un array dinamico de punteros a estructuras
typedef struct elemento
{
    long double x;
    long double y;
    
    
}punto;

//Funcion dada por enunciado, cuando recibe la estructura tipo punto, dentro de ella ya debe estar el valor de x pero asi mismo debe cargar el valor de y
int MiFuncion(punto *p1);
//Funcion que calcula el coseno de un numero
//long double SerieMaclaurinCos( long double xcos );
//Funcion que calcula el factorial de un numero
long double factorial( long double nrofactorial );
//Funcion dada por enunciado que haya el 1er maximo relativo
punto * Maximo( punto **p1, long double *VectorDinamicoValoresX, long double *VectorDinamicoValoresY );
//Funcion dada por enunciado que haya el 1er minimo relativo
punto * Minimo( punto **p1, long double *VectorDinamicoValoresX, long double *VectorDinamicoValoresY, int cant_puntos );
//Funcion que toma un texto ingresado por teclado y lo guarda en memoria dinamica para su uso independientemente del largo del texto ingresado
char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer );

int main(void)
{
    //declaro un puntero doble que recorre un vector dinamico de punteros simples que apuntan a estructuras del tipo "punto"
    punto **p1 = NULL;
    //declaro un puntero doble temporal para utilizar con malloc y prevenir errores de NULL de malloc
    punto **PunteroTemporal1 = NULL;
    //declaro un puntero simple temporal para utilizar con malloc y prevenir errores de NULL de malloc
    punto *PunteroTemporal2 = NULL;
    //declaro dos punteros simples que apuntan a arrays dinamicos de valores "x e y" del tipo long double. Dichos arrays se recorren con estos punteros simples
    long double *VectorDinamicoValoresX = NULL;
    long double *VectorDinamicoValoresY = NULL;
    //declaro un puntero simple temporal para utilizar con malloc y prevenir errores de NULL de malloc
    long double *PunteroTemporal = NULL;
    //declaro un puntero simple que recorre un vector dinamico de caracteres que se carga por teclado y se va realocalizando a medida que se ingresan caracteres. Esto de acuerdo a la construccion de la funcion getline()
    char *buffer = NULL;
    //declaro las variables que almacenan el extremo inferior y superior del rango de valores de "x" que quiere el usuario para poder graficar y para poder hallar el 1er maximo y minimo relativos
    long double Xmin, Xmax;
    //declaro una variable que se asocia a la cantidad de pares de puntos que desea tener el usuario en su table de puntos y mismo para graficar en octave
    int cant_puntos;
    //declaro una variable auxiliar que toma los valores de "x" del rango mencionado anteriormente
    long double x1;
    //declaro un iterador de for
    int i;
    //declaro una variable de "file descript" para poder imprimir en un archivo .m
    int fd;
    
    
    //Pedido de Xmin,Xmax y la cantidad de puntos, por teclado
    printf("Ingrese el valor de Xmin(en grados): ");
    scanf("%Lf", &Xmin);
    __fpurge(stdin);
    
    Xmin = ( 2 * pi * Xmin ) / 360; //Convierto los grados ingresados a radianes
    
    printf("Ingrese el valor de Xmax(en grados): ");
    scanf("%Lf", &Xmax);
    __fpurge(stdin);
    
    Xmax = ( 2 * pi * Xmax ) / 360; //Convierto los grados ingresados a radianes
     
    printf("Ingrese la cantidad de puntos para usar en su grafico: ");
    scanf("%i", &cant_puntos);
    __fpurge(stdin);
    
    //Pido memoria dinamica para un array de punteros simples que apuntan estructuras tipo "punto", este vector lo recorro con puntero doble. Este array en mi caso contendra un solo puntero simple porque solo habra una estructura a la que se apunte
    PunteroTemporal1 = (punto **)malloc( cant_estructuras * sizeof(punto *));
    
    //Proteccion contra NULL de malloc
    if( PunteroTemporal1 == NULL)
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    
    //Asigno la direccion almacenada en PunteroTemporal1 al vector dinamico correspondiente
    p1 = PunteroTemporal1;
    
    //Pido memoria dinamica para un array de estructuras del tipo "punto". Dicho vector lo recorro con un puntero simple. Este array tendra una sola estructura => un solo puntero simple que apunta a ella
    PunteroTemporal2 = (punto *)malloc( sizeof(punto));
    
    //Proteccion contra NULL de malloc
    if( PunteroTemporal2 == NULL)
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    
    //Asigno la direccion almacenada en PunteroTemporal2 al vector dinamico correspondiente
    *p1 = PunteroTemporal2;
    //p2 = *p1;
    //Pido memoria dinamica para crear un array de valores del tipo "long double", este array almacenara los distintos valores de X. Este array se recorre con un puntero simple
    PunteroTemporal = (long double *)malloc( cant_puntos * sizeof(long double));
    
    //Proteccion contra NULL de malloc
    if( PunteroTemporal == NULL)
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    
    //Asigno la direccion almacenada en PunteroTemporal al vector dinamico correspondiente
    VectorDinamicoValoresX = PunteroTemporal;
    
    //Pido memoria dinamica para crear un array de valores del tipo "long double", este array almacenara los distintos valores de Y. Este array se recorre con un puntero simple
    PunteroTemporal = (long double *)malloc( cant_puntos * sizeof(long double));
    
    //Proteccion contra NULL de malloc
    if( PunteroTemporal == NULL)
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    
    //Asigno la direccion almacenada en PunteroTemporal al vector dinamico correspondiente
    VectorDinamicoValoresY = PunteroTemporal;
    
    //Algoritmo de creacion de tabla de valores X e Y
    for(i = 0, x1=Xmin; x1<=Xmax && i< cant_puntos; x1+= ((Xmax-Xmin)/cant_puntos), i++)
    {   
        //En cada iteracion cargo un valor de "x" en la estructura, luego cargo el valor de "y" asociado a esta "x" a traves de MiFuncion, luego cargo los valores de "x e y" de la estructura, en los arrays dinamicos correspondientes. La estructura funciona como una "struct" auxiliar, la cual se le van modificando sus valores y luego de cada modificacion, se pasa una copia de los mismos a los array dinamicos de valores X e Y.
        
        (*p1)->x = x1;
        if( MiFuncion( *p1 ) == 0 )
        {
            //printf("|%Lf|\b", (*p1)->y);
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
    printf("Su tabla de valores queda como:\n");
    printf("X:\b ");
    for( i = 0; i < cant_puntos; i++ )
    {
        printf("|%Lf|\b", VectorDinamicoValoresX[i]);        
    }
    printf("\n");
    printf("\n");
    printf("Y:\b");
    for( i = 0; i < cant_puntos; i++ )
    {
        printf("|%Lf|\b", VectorDinamicoValoresY[i]);
    }
    printf("|\n");
    
    //Hallo el 1er maximo relativo a traves de una funcion
    *p1 = Maximo( p1, VectorDinamicoValoresX, VectorDinamicoValoresY );
    
    //Printeo en pantalla el Xcritico que produce el 1er maximo relativo y el valor de dicho maximo de la funcion
    printf("El valor del Xcritico que produce el 1er maximo relativo es: %Lf\n", (*p1)->x);
    printf("El valor del 1er maximo relativo es: %Lf\n", (*p1)->y);
    
    //Hallo el 1er minimo relativo a traves de una funcion
    *p1 = Minimo( p1, VectorDinamicoValoresX, VectorDinamicoValoresY, cant_puntos );
    //Proteccion contra falta de minimo, en caso de no haber minimo, entonces en la estructura se carga (0,0). Por la forma matematica de la funcion dada por enunciado, seguro no hay extremos en ese punto.
    if( (*p1)->x == 0 && (*p1)->y == 0 )
    {
        printf("No hay minimo en esta funcion\n");
    }
    else
    {
        //Printeo en pantalla el Xcritico que produce el 1er minimo relativo y el valor de dicho minimo de la funcion    
        printf("El valor del Xcritico que produce el 1er minimo relativo es: %Lf\n", (*p1)->x);
        printf("El valor del 1er minimo relativo es: %Lf\n", (*p1)->y);
    }
    
    //Pedido de ingreso de nombre de archivo de octave para graficar la funcion dada
    buffer = Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( &buffer );
    
    //Defino el archivo de octave con los permisos y voy printeando las instrucciones necesarias en este archivo para graficar
    fd=open(buffer, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    dprintf(fd,"hold on \n");
    dprintf(fd,"A=[");
    for( i = 0; i < cant_puntos; i++ )
    {
        dprintf(fd,"%6.3Lf, %6.3Lf", VectorDinamicoValoresX[i], VectorDinamicoValoresY[i]);
        if( i < cant_puntos -1 )
        {
            dprintf(fd,";");
        }
    }
    dprintf(fd,"]\n");
    dprintf(fd, "plot(A(:,1),A(:,2),\"b\")\n");

    printf("Su archivo .m de octave ha sido creado correctamente. Puede abrir el programa y ejecutarlo alli\n\n\nGracias por usar este software\n");
    //Liberacion de memoria dinamica usada por arrays dinamicos
    free(*p1);
    free(p1);
    free(VectorDinamicoValoresX);
    free(VectorDinamicoValoresY);
    free(buffer);
    
    return 0;
}

//Funcion que halla el valor "y" para el valor "x" de la estructura, tambien lo carga alli
int MiFuncion( punto *p1)
{
    int n;
    int chek = 0;
    long double y1 = 0, k1 = -1;
    for( n = 1; n <= kmax; n++ )
    {   
        //y1 = y1 +  ( SerieMaclaurinCos( (p1->x) * (long double) n ) / powl( (long double) n, (long double) 2  ) ) * k1;
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
    int i;
    int flag;
    for( i = 0, flag = 0; (VectorDinamicoValoresY[i] < VectorDinamicoValoresY[i+1] || flag == 0) && i < cant_puntos-1; i++)
    {
        if( VectorDinamicoValoresY[i+1] < VectorDinamicoValoresY[i] && VectorDinamicoValoresY[i+1] < VectorDinamicoValoresY[i+2] )
        {
            (*p1)->x = VectorDinamicoValoresX[i+1];
            (*p1)->y = VectorDinamicoValoresY[i+1];
            flag = 1;
        }
    }
    if( flag == 0 )
    {
        (*p1)->x = 0;
        (*p1)->y = 0;
    }
    
    return *p1;
}

//Funcion que permite tomar un texto ingresado por teclado y guardarlo en un array de caracteres. El texto tomado puede tener cualquier longitud de acuerdo a lo que escribe el usuario, la memoria ocupada sera dada dinamicamente y limitada por el tamanio del string ingresado
char * Ingreso_de_texto_por_teclado_y_solicitud_de_memoria_para_el_mismo( char **buffer )
{
    size_t capacidad = 0;//size_t y ssize_t es lo mismo que escribir unsigned int. Es decir, es un tipo de dato entero sin signo, usualmente lo devuelve sizeof pero tambien se puede declarar asi nomas. Al ponerle 0, permito que getline() use malloc y realloc desde el 1er instante. De lo contrario, si pongo un valor ej 30. Pide memoria para 30 caracteres y luego si me paso, realocaliza con realloc
    ssize_t cantcaracteresleidos;//declaro una variable que guarda la cantidad de caracteres leidos por teclado
    
    printf("Ingrese por favor, el nombre de su archivo ejecutable de octave. Este debe comenzar con \"./\" y terminar con \".m\": ");
    cantcaracteresleidos = getline( buffer, &capacidad, stdin ); 
    // Hay que tener en cuenta este prototipo para pasar bien los parametros a getline
    //ssize_t getline(char **lineptr, size_t *n, FILE *stream);

    
    if( cantcaracteresleidos == -1 )
    {
        printf("Hay un error con la lectura del texto ingresado");
        exit(-1);
    }
    else
    {
        printf("La cantidad de caracteres leidos antes de eliminar el caracter \" barra n \", el cual fue ingresado al presionar \"enter\",fueron: %li\n", cantcaracteresleidos);
        
    }
    //Elimino el caracter de nueva linea en el texto ingresado por teclado
    *(*(buffer)+(cantcaracteresleidos-1))= '\0';
    printf("El texto ingresado con el caracter \"barra n\" eliminado, fue: %s\n", *buffer);
    
    return *buffer;
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

//Funcion que calcula el coseno pedido 
/*
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
*/
