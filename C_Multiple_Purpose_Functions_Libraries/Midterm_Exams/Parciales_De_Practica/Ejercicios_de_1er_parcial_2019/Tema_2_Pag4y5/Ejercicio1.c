#include<stdio.h>
#include<stdio_ext.h>
//defino a traves de referencias simbolicas macro la long del vector, el valor de umbral

#define LONGITUD_ARRAY 15
#define VALOR_UMBRAL 0

//Este programa es lo mismo que el Ejercicio2 pero con la diferencia de que todo es "estatico". Es decir, el array tendra un tamanio pre-definido por el programador, ej, a traves de un #define. Esto hace que el "largo del array" este predefinido. Los elementos del array tambien seran pre-definidos (bien estatico). Luego, sucede lo mismo con el valor de umbral. Al momento de trabajar con la funcion ObtenerMayores, esta solo contara y mostrara el resultado, de la cantidad de valores que superan dicho umbral pre-fijado, no muestro cuales son los valores que superan dicho umbral, solo los cuento

//Declaro los prototipos de funciones
//Del enunciado el prototipo de la funcion es:
int ObtenerMayores( int *Array_de_datos, int Longitud_array, int Valor_umbral );

int main(void)
{
    //Declaro las variables que son: un puntero simple que recorre un vector estatico de datos int y la cantidad de valores que superan el umbral ;
    int Array_de_datos[LONGITUD_ARRAY] = { -10, -8, -7, -4, -3, -2, 0, 1, 2, 3, 20, 15, 23, 41, 10 };
    int Cantidad_de_valores_mayores_al_umbral;
    
    Cantidad_de_valores_mayores_al_umbral = ObtenerMayores( Array_de_datos, LONGITUD_ARRAY, VALOR_UMBRAL);
    
    printf("La cantidad de valores mayores al umbral es: %i\n", Cantidad_de_valores_mayores_al_umbral);
    
    return 0;
}

int ObtenerMayores( int *Array_de_datos, int Longitud_array, int Valor_umbral )
{
    //Declaro una variable de iteracion "i" y una variable de contador
    int i, cont = 0;
    
    //Uso ciclo de repeticion para comparar cada elemento del vector con el valor de umbral, en caso de superlo, se cuenta dicha "superacion". De no ser asi, no se cuenta. Tambien se printea en pantalla cuales son los valores que superan dicho umbral
    for( i = 0; i < (Longitud_array); i++ )
    {
        if( Array_de_datos[i] > Valor_umbral )
        {
            cont++;
        }   
    }
    
    //retorno al main la cantidad de valores que superar el umbral
    return cont;
}
