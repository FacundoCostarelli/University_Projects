/**
 * @file    Ejercicio1.c
 * @brief   [ESP] Ejercicio 1 Tema 1: Cálculo de esperanza y desvío de una muestra.
 *          [ENG] Exercise 1 Theme 1: Calculation of expected value and standard dev of a sample.
 *
 * @author  Facundo Costarelli
 * @date    2019
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<math.h>

/**
 * @brief [ESP] Calcula la esperanza muestral.
 *        [ENG] Calculates sample expected value (mean).
 */
float calcular_esperanza( int vector[], unsigned int largo );

/**
 * @brief [ESP] Calcula el desvío estándar de la muestra.
 *        [ENG] Calculates sample standard deviation.
 */
float calcular_desvio_estandar( int vector[], unsigned int largo);

/* [ESP] Variable global: esperanza muestral
   [ENG] Global variable: sample expected value */
float esperanza_muestral = 0; 

/**
 * @brief [ESP] Func. principal. Lee N datos de la muestra, calcula esperanza y desvío.
 *        [ENG] Main func. Reads N sample data items, calculates expected value and standard dev.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
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
    
    printf("Ingrese por favor cada uno de los datos obtenidos de la muestra\n");
    for( i = 0; i < N; i++ )
    {
        scanf("%i", &vector[i]);
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
    
    /* [ESP] Cálculo de sumatoria con ciclo for
       [ENG] Calculation of sum using for loop */
    for( i = 0; i < largo; i++ )
    {
        sumatoria_de_datos = sumatoria_de_datos + vector[i];
    }
    
    /* [ESP] Halla esperanza muestral (promedio). Se hace cast a float
       [ENG] Finds expected sample value (average). Cast to float applied */
    esperanza_muestral_dentro_de_la_funcion = ( (float)sumatoria_de_datos ) / ( (float)largo );
    
    return esperanza_muestral_dentro_de_la_funcion;
}

float calcular_desvio_estandar( int vector[], unsigned int largo )
{
    float desvio_muestral;
    float sumatoria_de_datos = 0;
    unsigned int i;
    
    /* [ESP] Cálculo de la sumatoria resolviendo los cuadrados
       [ENG] Calculation of the sum resolving the squares */
    for( i = 0; i < largo; i++ )
    {
        sumatoria_de_datos = sumatoria_de_datos + powf( ( (float)vector[i] ) - esperanza_muestral, (float)2 );
    }
    
    /* [ESP] Raíz cuadrada para obtener el desvío según la fórmula
       [ENG] Square root to obtain the deviation according to the formula */
    desvio_muestral = sqrtf( sumatoria_de_datos / (float)largo );
    
    return desvio_muestral;
}
