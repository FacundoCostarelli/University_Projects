/**
 * @file    Ejercicio2.c
 * @brief   [ESP] Ejercicio 2 Tema 2: Conteo de valores mayores a un umbral dinámico.
 *          [ENG] Exercise 2 Theme 2: Count of values greater than a dynamic threshold.
 *
 * @author  Facundo Costarelli
 * @date    2019
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

/**
 * @brief [ESP] Solicita memoria dinámica y lee datos hasta ingresar EOF.
 *        [ENG] Requests dynamic memory and reads data until EOF is entered.
 */
void Solicitud_de_memoria_y_carga_de_datos( int **ptr_a_Array_de_datos );

/**
 * @brief [ESP] Calcula la longitud de un array dinámico observando el fin de lectura.
 *        [ENG] Computes the length of a dynamic array observing read end.
 */
int Mi_string_length( int *Array_de_datos );

/**
 * @brief [ESP] Verifica cantidad de valores mayores al umbral ingresado.
 *        [ENG] Checks amount of values greater than inputted threshold.
 */
int ObtenerMayores( int *Array_de_datos, int Longitud_array, int Valor_umbral );

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    int *Array_de_datos = NULL;
    int Longitud_array, Valor_umbral;
    int Cantidad_de_valores_mayores_al_umbral;
    
    printf("Bievenido, este programa permite cargar un grupo de datos enteros y determinar cuales de ellos superan un determinado valor de umbral. Dicho valor debe ser ingresado por usted\n");
    
    Solicitud_de_memoria_y_carga_de_datos( &Array_de_datos );
    Longitud_array = Mi_string_length( Array_de_datos );
    
    printf("Una vez cargado todos los datos, por favor, ingrese el valor de umbral: ");
    scanf("%i", &Valor_umbral);
    __fpurge(stdin);
    
    Cantidad_de_valores_mayores_al_umbral = ObtenerMayores( Array_de_datos, Longitud_array, Valor_umbral );
    
    free( Array_de_datos );
    
    printf("La cantidad de valores que superan el umbral, es: %i\n", Cantidad_de_valores_mayores_al_umbral);
    printf("Gracias por usar este programa\n");
    
    return 0;
}

void Solicitud_de_memoria_y_carga_de_datos( int **ptr_a_Array_de_datos )
{
    int i = 0;
    
    *(ptr_a_Array_de_datos) = (int *)malloc(sizeof(int));
    if( *(ptr_a_Array_de_datos) == NULL )
    {
        printf("Hay un error con la asignacion de memoria\n");
        exit(-1);
    }
    
    printf("Ingrese un dato por favor. Si no desea ingresar mas, ingrese -1 (o EOF)\n");
    
    do
    {
        scanf("%i", (*(ptr_a_Array_de_datos) + i) );
        __fpurge(stdin);
        i++;
        
        if( *( *(ptr_a_Array_de_datos) + (i-1) ) != EOF )
        {
            *(ptr_a_Array_de_datos) = (int *)realloc( *(ptr_a_Array_de_datos) , (i+1) * sizeof(int));
            if( *(ptr_a_Array_de_datos) == NULL )
            {
                printf("Hay un error con la asignacion de memoria\n");
                exit(-1);
            }
        }
    } while( *( (*(ptr_a_Array_de_datos) + (i-1) ) ) != EOF );
}

int Mi_string_length( int *Array_de_datos )
{
    int i = 0;
    
    /* [ESP] Cuento cantidad de elementos hasta encontrar el EOF
       [ENG] Counts elements until finding EOF */
    while( Array_de_datos[i] != EOF )
    {
        i++;
    }
    
    return i;
}

int ObtenerMayores( int *Array_de_datos, int Longitud_array, int Valor_umbral )
{
    int i, cont = 0;
    
    for( i = 0; i < Longitud_array; i++ )
    {
        if( Array_de_datos[i] > Valor_umbral )
        {
            printf("El valor ingresado %i supera al valor de umbral que es %i\n", Array_de_datos[i], Valor_umbral);
            cont++;
        }   
    }
    
    return cont;
}
