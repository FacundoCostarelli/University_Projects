/**
 * @file    Exercise3-20.c
 * @brief   [ESP] Ejercicio 3.20 del libro: Cálculo de intereses de un préstamo.
 *          [ENG] Exercise 3.20 from the book: Interest charge calculation on a loan.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>

/**
 * @brief [ESP] Func. principal. Calcula cargos de intereses basado en diferentes tasas.
 *        [ENG] Main func. Computes interest charges based on different rates.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Declaración de variables
       [ENG] Declaration of variables */
    float interest, principal, rate;
    int days;
    
    /* [ESP] Primer ingreso de datos con valor centinela como opción
       [ENG] First data input with sentinel (flag) value as an option */
    printf("Enter loan principal ( -1 to end ): ");
    scanf("%f", &principal);
    
    /* [ESP] Evalúa si la variable principal activó el cierre del programa
       [ENG] Evaluation of principal variable to check if shutting down */
    if ( principal != -1 )
    {
        /* [ESP] Ciclo del proceso para mayores ingresos de datos
           [ENG] Cyclic process for further data input */
        while ( principal != -1 )
        {
            printf("Enter interest anual rate: ");
            scanf("%f", &rate);
            printf("Enter term or amount of days for the loan: ");
            scanf("%d", &days);
            
            /* [ESP] Cálculo del interés a pagar por el préstamo
               [ENG] Calculate the total interest charge of the loan */
            interest = principal * rate * days / 365;

            printf("The interest charge for the loan selected is: %.2f\n", interest);

            /* [ESP] Pide nuevo número o -1 para cerrar
               [ENG] Input of new data with flag value to end program */
            printf("Enter loan principal ( -1 to end ): ");
            scanf("%f", &principal);
        }

        printf("The program has been shut down, thank you\n");
    }
    else
        printf("The program has been shut down, thank you\n");

    return 0;
}
