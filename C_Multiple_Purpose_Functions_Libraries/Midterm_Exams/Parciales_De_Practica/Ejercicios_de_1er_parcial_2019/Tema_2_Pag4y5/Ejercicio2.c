#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

//Este programa es lo mismo que el Ejercicio1, pero la diferencia es que hay mas "dinamica". Es decir, se usa memoria dinamica en la carga de datos y una variable simbolica macro que es FIN a traves de un define...pero....en este yo uso la macro EOF la cual ya de por si tiene asginado el valor -1 o ctrl+d. Este EOF no hay que declaralo con define. Ademas se le pide al usuario que ingrese el valor de umbral(mas dinamico) y se pide usar la funcion ObtenerMayores...por mi parte...en dicha funcion...no solo la cantidad de valores que superan el umbral sino que muestro cuales son(mas dinamico).

//Declaro los prototipos de funciones
void Solicitud_de_memoria_y_carga_de_datos( int **ptr_a_Array_de_datos );
int Mi_string_length( int *Array_de_datos );
//Del enunciado el prototipo de la funcion es:
int ObtenerMayores( int *Array_de_datos, int Longitud_array, int Valor_umbral );

int main()
{
    //Declaro las variables que son: un puntero simple que recorre un vector dinamico de datos int, la long del vector, el valor de umbral y la cantidad de valores que superan el umbral ;
    int *Array_de_datos = NULL;
    int Longitud_array, Valor_umbral;
    int Cantidad_de_valores_mayores_al_umbral;
    
    printf("Bievenido, este programa permite cargar un grupo de datos enteros y determinar cuales de ellos superan un determinado valor de umbral. Dicho valor debe ser ingresado por usted\n");
    
    //Solicito memoria dinamica y contruyo el vector de datos a traves de duna funcion
    Solicitud_de_memoria_y_carga_de_datos( &Array_de_datos );
    //Calculo el largo del array a traves de una funcion de biblioteca standr de C
    Longitud_array = Mi_string_length( Array_de_datos );
    
    printf("Una vez cargado todos los datos, por favor, ingrese el valor de umbral donde este puede ser uno de los datos ingresados u otro: ");
    scanf("%i", &Valor_umbral);
    __fpurge(stdin);
    
    //Obtengo los valores mayores al umbral ingresado, a traves de una funcion
    Cantidad_de_valores_mayores_al_umbral = ObtenerMayores( Array_de_datos, Longitud_array, Valor_umbral );
    
    free( Array_de_datos );
    
    printf("La cantidad de valores que superan el umbral, es: %i\n", Cantidad_de_valores_mayores_al_umbral);
    printf("Gracias por usar este programa\n");
    
    return 0;
}

void Solicitud_de_memoria_y_carga_de_datos( int **ptr_a_Array_de_datos )
{
    //Declaro una variabli "i" de cont o iterador
    int i = 0;
    
    //Pido memoria dinamica para un vector de datos int que lo recorro con un puntero simple
    *(ptr_a_Array_de_datos) = (int *)malloc(sizeof(int *));
    
    //Proteccion contra NULL de malloc
    if( *(ptr_a_Array_de_datos) == NULL )
    {
        printf("Hay un error con la asignacion de memoria\n");
        exit(-1);
    }
    
    printf("Ingrese un dato por favor. Si no desea ingresar mas, ingrese el comando End of File tipicamente Ctrl+d o -1\n");
    
    //Carga de datos en el array con estructura DO-while
    do
    {
        scanf("%i", (*(ptr_a_Array_de_datos) + i) );
        __fpurge(stdin);
        i++;
        //Si se ingresa -1 = EOF no se pide mas memoria al SO
        if( *( *(ptr_a_Array_de_datos) + (i-1) ) != EOF )
        {
            *(ptr_a_Array_de_datos) = (int *)realloc( *(ptr_a_Array_de_datos) , (i+1) * sizeof(int *));
            //Proteccion contra NULL de realloc
            if( *(ptr_a_Array_de_datos) == NULL )
            {
                printf("Hay un error con la asignacion de memoria\n");
                exit(-1);
            }
        }
        //Si se ingresa -1 = EOF no se solicita mas la carga de datos
    }while( *( (*(ptr_a_Array_de_datos) + (i-1) ) ) != EOF );
    
}

int Mi_string_length( int *Array_de_datos )
{
    //Declaro variable de iteracion
    int i = 0;
    
    //Cuento la cantidad de elmentos en el array hasta encontrar el \0
    while( Array_de_datos[i] != '\0' )
    {
        i++;
    }
    
    //retorno al main dicha cantidad de elementos
    return i;
}

int ObtenerMayores( int *Array_de_datos, int Longitud_array, int Valor_umbral )
{
    //Declaro una variable de iteracion "i" y una variable de contador
    int i, cont = 0;
    
    //Uso ciclo de repeticion para comparar cada elemento del vector con el valor de umbral, en caso de superlo, se cuenta dicha "superacion". De no ser asi, no se cuenta. Tambien se printea en pantalla cuales son los valores que superan dicho umbral
    for( i = 0; i < (Longitud_array - 1); i++ )
    {
        if( Array_de_datos[i] > Valor_umbral )
        {
            printf("El valor ingresado %i supera al valor de umbral que es %i\n", Array_de_datos[i], Valor_umbral);
            cont++;
        }   
    }
    
    //retorno al main la cantidad de valores que superar el umbral
    return cont;
}

