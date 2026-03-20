/**
 * @file    Exercise3-21.c
 * @brief   [ESP] Ejercicio 3.21 del libro: Cálculo de sueldo por hora.
 *          [ENG] Exercise 3.21 from the book: Hourly wage computation.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>

/**
 * @brief [ESP] Func. principal. Calcula sueldo con bonos por horas extras.
 *        [ENG] Main func. Computes wage with overtime bonus.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{   
    /* [ESP] Declaración de variables
       [ENG] Declaration of variables */
    int hours, counter = 0;
    float hourlyrate;
    
    /* [ESP] Primer ingreso de datos
       [ENG] First data input */
    printf("Enter amount of hours worked ( -1 to end ): ");
    scanf("%d", &hours);
        
    /* [ESP] Ciclo de ingreso con valor centinela como posibilidad
       [ENG] Loop for data input with flag value as possibility */
    while ( hours != -1 )
    {
        printf("Enter hourly rate of the worker: ");
        scanf("%f", &hourlyrate);
        counter = counter + 1;
            
        /* [ESP] Si son menos o 40hrs, es normal. Sino, recargo por hora extra.
           [ENG] If <= 40hrs it's normal rate. Else, overtime half-rate bonus. */
        if ( hours <= 40 )
            printf("The salary is : %.2f \n", hours * hourlyrate);
        else 
            printf("The salary is : %.2f \n", hours * hourlyrate + hourlyrate / 2);
            
        printf("Enter amount of hours worked ( -1 to end ): ");
        scanf("%d", &hours);
    }
    
    /* [ESP] Imprime la cantidad final de cálculos realizados
       [ENG] Prints final calculation count */
    if( counter != 0 )
        printf("The amount of total salaries calculated were: %d\n", counter); 
    else
        printf("There wasnt data entered to analyse, the program has been shut down\n");

    return 0;
}
