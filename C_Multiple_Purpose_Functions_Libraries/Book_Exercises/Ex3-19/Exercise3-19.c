#include<stdio.h>

/*Programa que calcula el salario semanal de un vendedor en base a unas condiciones de enunciado*/

int main()
{
    /*Declaracion de variables*/
    
    float sales, salary = 0;
    /*Ingreso del primer dato*/
    printf("Enter sales in dollars ( -1 to end): ");
    scanf("%f", &sales);
    /*Comparacion para saber si la persona de entrada quiere cerrar o no el programa*/
    if ( sales != -1 )
    {   
        /*Ciclo de repeticion para ingreso de datos con flag*/

        while ( sales != -1 )
        {

            salary = 200 + 0.09 * sales;
            printf("The salary per week for these employee is: %.2f\n", salary);
            
            /*Comienzo de un nuevo ingreso de datos*/

            printf("Enter sales in dollars ( -1 to end): ");
            scanf("%f", &sales);
        }
        
        printf("The program has been shut down, thank you\n");
    
    
    }
    else 
        printf("The program has been shut down, thank you\n");
    
    return 0;
}
