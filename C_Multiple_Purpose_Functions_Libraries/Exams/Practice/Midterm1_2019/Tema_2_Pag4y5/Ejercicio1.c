/**
 * @file    Ejercicio1.c
 * @brief   [ESP] Ejercicio 1 Tema 2: Conteo de valores superiores a un umbral estático.
 *          [ENG] Exercise 1 Theme 2: Count of values above a static threshold.
 *
 * @author  Facundo Costarelli
 * @date    2019
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>

/* [ESP] Defino macros para longitud y umbral
   [ENG] Define macros for length and threshold */
#define LONGITUD_ARRAY 15
#define VALOR_UMBRAL 0

/**
 * @brief [ESP] Verifica cantidad de valores mayores al umbral en un array.
 *        [ENG] Checks amount of values greater than threshold in an array.
 *
 * @param Array_de_datos [ESP] Vector de datos ints / [ENG] Array of ints
 * @param Longitud_array [ESP] Tamaño del arreglo / [ENG] Size of array
 * @param Valor_umbral   [ESP] Límite de control / [ENG] Control limit
 * @return [ESP] Cantidad que supera umbral / [ENG] Count that exceeds threshold
 */
int ObtenerMayores( int *Array_de_datos, int Longitud_array, int Valor_umbral );

/**
 * @brief [ESP] Func. principal. Cuenta y muestra la cant de valores mayores al umbral.
 *        [ENG] Main func. Counts and displays the amount of values above threshold.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(void)
{
    /* [ESP] Vector estático de datos int y contador
       [ENG] Static vector of int data and counter */
    int Array_de_datos[LONGITUD_ARRAY] = { -10, -8, -7, -4, -3, -2, 0, 1, 2, 3, 20, 15, 23, 41, 10 };
    int Cantidad_de_valores_mayores_al_umbral;
    
    Cantidad_de_valores_mayores_al_umbral = ObtenerMayores( Array_de_datos, LONGITUD_ARRAY, VALOR_UMBRAL);
    
    printf("La cantidad de valores mayores al umbral es: %i\n", Cantidad_de_valores_mayores_al_umbral);
    
    return 0;
}

int ObtenerMayores( int *Array_de_datos, int Longitud_array, int Valor_umbral )
{
    /* [ESP] Declaro variable de iteración y contador
       [ENG] Declare iteration variable and counter */
    int i, cont = 0;
    
    /* [ESP] Compara ciclo a ciclo contra umbral. Suma a cont si supera.
       [ENG] Compares cycle by cycle against threshold. Adds to cont if exceeds. */
    for( i = 0; i < (Longitud_array); i++ )
    {
        if( Array_de_datos[i] > Valor_umbral )
        {
            cont++;
        }   
    }
    
    /* [ESP] Retorno la cantidad de valores
       [ENG] Return the amount of values */
    return cont;
}
