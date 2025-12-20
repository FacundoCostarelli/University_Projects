#include<stdio.h>
#include<stdio_ext.h>
#include<math.h>


//Calculo de la esperanza de un conjunto de valores y del devio estandar de dicho conjunto. Seria respecto de una muestra con los respectivos datos tomadas por el estadista
//Como utilizo la libreria math.h , hay que linkear ademas -lm. Entonces una forma valida de utilizar al ejecutar el comando de compilacion es ej: gcc -c Ejercicio1.c -o Ejercicio1.o -Wall -lm, es decir, a continuacion del -Wall 

float calcular_esperanza( int vector[], unsigned int largo );
float calcular_desvio_estandar( int vector[], unsigned int largo);
//donde int vector[] es lo mismo que poner lo siguiente: int *vector(puntero llamado "vector" que apunta a la direccion de comienzo del vector) donde este recibe &vector[0] = vector, es decir la direccion de comienzo del 1er elemento. Ademas *(vector + 0) = vector[0]. Este vector contendra los datos observados de la muestra
//unsigned int largo, es una variable int sin singo que esta asociada al largo del vector y por ende al largo de la muestra, es decir, es el tamanio muestral N. 

float esperanza_muestral = 0; //declaro una variable global para poder usarla en todas las funciones requeridas. Donde esperanza_muestral es "mu" de las formulas propuestas por enunciado

int main()
{
    unsigned int N;
    unsigned int i;
    float desvio_muestral;
    
    printf("Bienvenido, con este programa podra calcular la esperanza y desvio de una muestra de una poblacion\n");
    printf("Ingrese por favor la cantidad muestral o el numero muestral poblacional \"N\": ");
    scanf("%i", &N);
    __fpurge(stdin);
    
    int vector[N];
    
    //printf("La direccion de comienzo del vector creado es: %p\n", vector);
    
    printf("Ingrese por favor cada uno de los datos obtenidos de la muestra recordando usted que es lo que esta estudiando con ellos\n");
    for( i = 0; i < N; i++ )
    {
        scanf("%i", &vector[i]);//otra forma es scanf("%i", (vector + i)); 
        __fpurge(stdin);
    }
    
    printf("Usted a cargado los siguientes datos en el array: \n");
    for( i = 0; i < N; i++ )
    {
        printf("|%i|\t", vector[i] );
    }
    printf("\n");
    
    esperanza_muestral = calcular_esperanza( vector, N );
    desvio_muestral = calcular_desvio_estandar( vector, N );

    
    printf("La esperanza muestral calculada es: %.2f\n", esperanza_muestral);
    printf("El desvio_muestral calculado es: %.2f\n", desvio_muestral);
    printf("Gracias por usar el programa\n");
    
    return 0;
}


float calcular_esperanza( int vector[], unsigned int largo )
{
    float esperanza_muestral_dentro_de_la_funcion = 0;
    int sumatoria_de_datos = 0;
    unsigned int i;
    
    //printf("En la funcion calcular_esperanza, la direccion recibida de comienzo del vector es: %p\n", vector);
    
    //calculo la sumatoria con estructura de repeticion for
    for( i = 0; i < largo; i++ )
    {
        sumatoria_de_datos = sumatoria_de_datos + vector[i];
    }
    
    //printf("En la funcion calcular_esperanza, la sumatoria_de_datos es: %i\n", sumatoria_de_datos);
    
    //hallo la esperanza muestral de acuerdo a la formula brindada por enunciado
    esperanza_muestral_dentro_de_la_funcion = ( (float)sumatoria_de_datos ) / ( (float)largo );
    //si saco el cast de sumatoria_de_datos, al realizar la division entre int e int, el valor que me da es un float pero con decimales faltantes, es decir, un int con decimales 0. Ademas si hago (1/largo) * ( (float)sumatoria_de_datos ); sucede un problema con la operacion ya que multiplica un float por un cociente de ints y devuelve 0.00, es decir, algo mal. El porblema esta en querer operar con int * float, todo tiene que ser del mismo tipo, en este caso float * float. Lo mismo para el cociente, por eso esta casteado tanto sumatoria_de_datos como largo, ambos para poder hacer float / float = float
    
   // printf("La esperanza_muestral a retornar es: %.2f\n", esperanza_muestral_dentro_de_la_funcion);
    
    return esperanza_muestral_dentro_de_la_funcion;
}

float calcular_desvio_estandar( int vector[], unsigned int largo )
{
    float desvio_muestral;
    float sumatoria_de_datos = 0;
    unsigned int i;
    
    //printf("En la funcion calcular_desvio_estandar, la direccion recibida de comienzo del vector es: %p\n", vector);
    
    //calculo la sumatoria con estructura de repeticion for
    for( i = 0; i < largo; i++ )
    {
        sumatoria_de_datos = sumatoria_de_datos + powf( ( (float)vector[i] ) - esperanza_muestral, (float)2 );
    }
    
    //printf("En la funcion calcular_desvio_estandar, la sumatoria_de_datos es: %f\n", sumatoria_de_datos);
    
    //hallo el desvio muestral de acuerdo a al formula brindada por enunciado
    desvio_muestral = sqrtf( sumatoria_de_datos / (float)largo );
    
    //printf("El desvio_muestral a retornar es: %.2f\n", desvio_muestral);
    
    return desvio_muestral;
}
