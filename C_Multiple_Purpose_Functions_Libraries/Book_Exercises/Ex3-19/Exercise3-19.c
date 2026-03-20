/**
 * @file    Exercise3-19.c
 * @brief   [ESP] Ejercicio 3.19 del libro: Cálculo de salario semanal de ventas.
 *          [ENG] Exercise 3.19 from the book: Weekly sales salary calculation.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>

/**
 * @brief [ESP] Func. principal. Calcula salario usando ventas brutas.
 *        [ENG] Main func. Computes salary based on gross sales.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Declaración de variables
       [ENG] Variable declaration */
    float sales, salary = 0;
    
    /* [ESP] Ingreso del primer dato
       [ENG] First data input */
    printf("Enter sales in dollars ( -1 to end): ");
    scanf("%f", &sales);
    
    /* [ESP] Comparación para saber si el usuario quiere cerrar o continuar
       [ENG] Comparison to check if the user wants to close or continue */
    if ( sales != -1 )
    {   
        /* [ESP] Ciclo de repetición usando valor centinela (flag)
           [ENG] Repetition loop using a sentinel (flag) value */
        while ( sales != -1 )
        {
            salary = 200 + 0.09 * sales;
            printf("The salary per week for these employee is: %.2f\n", salary);
            
            /* [ESP] Comienzo de un nuevo ingreso de datos
               [ENG] Beginning of a new data input */
            printf("Enter sales in dollars ( -1 to end): ");
            scanf("%f", &sales);
        }
        
        printf("The program has been shut down, thank you\n");
    }
    else 
        printf("The program has been shut down, thank you\n");
    
    return 0;
}
