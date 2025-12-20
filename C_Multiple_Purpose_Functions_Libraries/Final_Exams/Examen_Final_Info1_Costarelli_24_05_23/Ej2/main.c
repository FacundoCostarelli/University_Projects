#include"Funciones.h"

int main()
{
    char *String = NULL;
    int i = 0, j = 0;
     ssize_t caracteres_leidos = 0;
    char *buffer_aux_pila = NULL;
    printf("Ingrese una instruccion de entrada para el simulador de parser: ");
    caracteres_leidos = getline(&String,0,stdin);
    if( String[caracteres_leidos-1] == '\n')
            String[caracteres_leidos-1] = '\0';

    //Pido memoria dinamica
    buffer_aux_pila = (char *)malloc(caracteres_leidos * sizeof(char) );
    if(buffer_aux_pila == NULL)
    {
            printf("Error con la asignacion de memoria dinamica para la pila\n");
            return ERROR;
    }
    /*Primer parte del algoritmo*/
    for( i = 0, j = 0; i < caracteres_leidos; i++,j++ )
    {
        if(String[i] == '(' || String[i] ==')' )
        {
            buffer_aux_pila[j] = String[i];
        }

    }
    /*Faltaria comparar si hay misma cantidad de ( y de ) y si estan en el orden correcto*/


    //Libero memoria usada
    free(buffer_aux_pila);
    free(String);
    return 0;
}
