#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<ctype.h>
#define tamanio_VectorDeEnteros 26
//Funcion pedida por enunciado
void CuantasVeces( char ***P, int *VectorDeEnteros, int filas, int columnas );
//Funciones creadas por mi para resolver el resto de la problematica
char ** crearmatrizcondatos( char ***P, int filas, int columnas);
void cargamatriz( char ***P, int filas, int columnas );
void mostrarmatriz( char ***P, int filas, int columnas );
void liberarmatriz( char ***P, int filas );

int main(void)
{
    //Para el vector de enteros que contiene cantidad de repeticiones de caracteres de la matriz, se puede pedir memoria dinamica considerando un tamanio de alfabeto de 25 caracteres sin contar la "enie" y considerando todos los caracteres en minuscula. Lo mismo puede ser para todos caracteres en mayusculas.
    int filas, columnas;
    //para acceder a cada puntero doble, hay que apuntar a la direccion de cada variable puntero doble a traves de un puntero triple. Es triple porque apunta a direcciones de memoria de variables punteros dobles.
    char ***vectordepunterosdoblesdinamicos = NULL;
    //creo un array dinamico de datos int de filas que lo recorro con un puntero simple, esto para poder distinguir una matriz de otra(en caso de escalar el programa para mas matrices)esto al liberar la memoria usada, y otros usos
    int *PunteroaCantidadeFilas = NULL;
    //creo un array dinamico de datos int de columnas que lo recorro con un puntero simple, esto para poder distinguir una matriz de otra(en caso de escalar el programa para mas matrices)esto al liberar la memoria usada, y otros usos
    int *PunteroaCantidadeColumnas = NULL;
    //utilizo Punterotemporal para almacenar lo que devuelve malloc, analizar si es o no NULL y luego asignar lo que almacena Punterotemporal al puntero vectordepunterosdoblesdinamicos
    char ***Punterotemporal = NULL;
    int *Punterotemporal1 = NULL;//mismo uso que Punterotemporal
    //Creo un array dinamico de de enteros que lo recorro con un puntero simple
    int *VectorDeEnteros = NULL;
    
    int i, j; //iteradores para el "for"
    
    
    printf("Bienvenido, este programa le permite crear una matriz con caracteres, ingresar por teclado dichos caracteres y determinar cuales caracteres se repiten y cuantas veces\n.\n.\n.\n.\n");
    
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    __fpurge(stdin);
    printf("Ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);
    __fpurge(stdin);
    
    Punterotemporal = (char ***)malloc(sizeof(char **));//pido memoria dinamica con malloc para crear un vector de matrices que almacene 1 matriz.
                
    //proteccion contra NULL de malloc
    if( Punterotemporal == NULL )
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    else
    {
        vectordepunterosdoblesdinamicos = Punterotemporal;
        *(vectordepunterosdoblesdinamicos) = crearmatrizcondatos( vectordepunterosdoblesdinamicos, filas, columnas );//A esta funcion le paso la cant de filas, columnas, y la "cajita" de memoria donde se va a almacenar la matriz, dicha cajita tiene una direccion que se recorre con puntero triple
    }
    
    //pido memoria dinamica con malloc para crear un vector que almacena la cantidad de filas de la matriz mencionada
    Punterotemporal1 = (int *)malloc(sizeof(int));
                
    //proteccion contra NULL de malloc
    if( Punterotemporal1 == NULL )
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    else
    {
        PunteroaCantidadeFilas = Punterotemporal1;
        *(PunteroaCantidadeFilas) = filas;
    }
    
    //pido memoria dinamica con malloc para crear un vector que almacena la cantidad de columnas de la matriz mencionada
    Punterotemporal1 = (int *)malloc(sizeof(int));
    //proteccion contra NULL de malloc
    if( Punterotemporal1 == NULL )
    {
        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
        return 0;
    }
    else
    {
        PunteroaCantidadeColumnas = Punterotemporal1;
        *(PunteroaCantidadeColumnas) = columnas;
    }
    
    printf("Su matriz quedo dada como: \n");
    printf("| %i | Filas x | %i | Columnas \n", *(PunteroaCantidadeFilas), *(PunteroaCantidadeColumnas));
    
    Punterotemporal1 = (int *)malloc( tamanio_VectorDeEnteros * sizeof(int) );
    
    if( Punterotemporal1 == NULL )
    {
       printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias\n");
       return 0; 
    }
    else
    {
        VectorDeEnteros = Punterotemporal1;
    }
    
    //Llamo a una funcion, esta determina cuantas veces y cuales son los caracteres que se repiten en la matriz cargada por teclado
    CuantasVeces( vectordepunterosdoblesdinamicos, VectorDeEnteros, *(PunteroaCantidadeFilas), *(PunteroaCantidadeColumnas) );
    
    printf("Las distintas cantidades de repeticiones junto a dichos carecteres son\n");
    for( i = 0; i < tamanio_VectorDeEnteros; i++ )
    {
        printf("|%i|\b", *(VectorDeEnteros + i) );
    }
    printf("\n");
    for( i = 97; i <= 122; i++ )
    {
        printf("|%c|\b", i);
    }
    printf("\n");
    for( j = 65; j<= 90; j++ )
    {
        printf("|%c|\b", j);
    }
    printf("\n");
    //printf("Se va a liberar la memoria\n");
        
    //libero la memoria usada por las matrices a traves de una funcion
    liberarmatriz( vectordepunterosdoblesdinamicos, *(PunteroaCantidadeFilas) );
        
    //printf("Se libero la memoria de la matriz\n" );
    
    //libero el vector dinamico de matrices, es decir, punteros dobles que lo recorria con puntero triple
    free(vectordepunterosdoblesdinamicos);
    //libero el vector dinamico de cant de filas de matrices ingresadas, que lo recorria con un puntero simple
    free(PunteroaCantidadeFilas);
    //libero el vector dinamico de cant de columnas de matrices ingresadas, que lo recorria con un puntero simple
    free(PunteroaCantidadeColumnas);
    
    printf("Toda la memoria dinamica usada y solicitada, se ha liberado correctamente\n");
    printf("Gracias por utilizar este software\n");
    
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
    //char ***P es quien recibe las direcciones &M, &N, que estan dadas por malloc y realloc en el main
    //*P debera ser = M, N, etc osea las matrices/punteros dobles;
    *(P) = (char **)malloc( filas * sizeof(char **) );
    
    //cargo la matriz a traves de una funcion, envio la direccion donde se almacena cada matriz, es decir &M,&N, etc. Esto a traves de P ya que es puntero triple y contiene estas direcciones &M, &N, etc dadas por malloc y realloc
    cargamatriz( P, filas, columnas );
    //printeo la matriz  a traves de una funcion
    mostrarmatriz( P, filas, columnas );
    
    return *(P);
    
}


void cargamatriz( char ***P, int filas, int columnas )
{
    //este algoritmo carga con numeros char pero con su representacion de letras del abecedario
    int i, j;
    //cargo el vector de punteros simples, es decir, cada elemento sera un puntero simple que apunta a la direccion de comienzo de una fila, la longitud de la fila depende de la cantidad de columnas.
    for( i = 0; i < filas; i++ )
    {
        //a la izquierda son los punteros simples de filas y a la derecha lo que da malloc de direccion de comienzo de cada fila, el largo de las filas depende de cant de columnas 
        *((*P) + i) = (char *)malloc( columnas * sizeof(char *) ); 
    }
    printf("Por favor, ingrese los caracteres de la matriz considerando que se carga cada fila desde la primera hasta la ultima y de izquierda a derecha. Cuando finalize la carga de su fila, entonces comenzara la carga de la siguiente hasta no haber nada que cargar\n");
    
    //cargo la matriz a traves de cargar cada fila con sus respectivas columnas
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
    //mueestro la matriz a traves de mostrar cada dato de cada posicion fila-columna
    for( i = 0; i < filas; i++ )
    {
        for( j = 0; j < columnas; j++ )
        {
            //printf("| %c | \t", *(*((*P)+i)+j)  );
            printf("| %c |\t", (*(*((*P)+ i)+j)) );
        }
        printf("\n");
    }
}

void liberarmatriz( char ***P, int filas ) 
{
    /*
    printf("Direccion de la matriz a liberar en la funcion \"liberarmatriz\" es = %p\n", P);
    
    printf("La matriz a liberar es \"matriz\": %p\n", *P);
    printf("La cantidad de filas de esta matriz es: %d\n", filas);
    */
    
    int i;
    //libero cada fila con sus columnas de la matriz recibida
    for( i = 0; i < filas; i++ )
    {
        free((*((*P) + i)));
    }
    
    //printf("Se liberaron correctamente las columnas y  filas\n");
    
    //libero el vector de filas, osea libero el vector de punteros simples
    free((*P));
    
    //printf("Se libero la memoria correctamente\n");
    
}
