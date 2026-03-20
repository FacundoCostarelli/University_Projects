/**
 * @file    Exercise3-18.c
 * @brief   [ESP] Ejercicio 3.18 del libro: Verificación de límite de crédito.
 *          [ENG] Exercise 3.18 from the book: Credit limit verification.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>

/**
 * @brief [ESP] Func. principal. Calcula si el cliente excede su límite de tarjeta.
 *        [ENG] Main func. Checks if the client exceeds their credit card limit.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main() 
{
    /* [ESP] El programa determina, a partir de datos iniciales, si un cliente
             excede o no el límite de crédito en su tarjeta
       [ENG] The program determines, based on initial data, if a client
             exceeds their credit card limit or not */
    int account_number;
    float beginning_balance, total_charges, total_credits, credit_limit, final_balance = 0;

    /* [ESP] Declaro e inicializo las variables a usar
       [ENG] Declare and initialize the variables to use */
    printf("Enter  account number (-1 to end data input) : ");
    scanf("%d", &account_number);
    
    if ( account_number != -1 )
    {
        while ( account_number != -1 )
        {
            /* [ESP] Ingreso los datos de input necesarios
               [ENG] Input the necessary input data */
            printf("Enter beginning balance: ");
            scanf("%f", &beginning_balance);
            printf("Enter total charges: ");
            scanf("%f", &total_charges);
            printf("Enter total credits: ");
            scanf("%f", &total_credits);
            printf("Enter credit limit: ");
            scanf("%f", &credit_limit);
            
            /* [ESP] Calculo el balance final
               [ENG] Calculate the final balance */
            final_balance = beginning_balance + total_credits;

            if ( final_balance > credit_limit )
            {
                printf("Account number: %d\n", account_number);
                printf("Credit Limit: %.2f\n", credit_limit);
                printf("Total charges: %.2f\n", total_charges);
                printf("Final Balance: %.2f\n", final_balance);
                printf("Credit Limit Exceeded\n");
            }
            
            printf("Enter  account number (-1 to end data input) : ");
            scanf("%d", &account_number);
        }

        printf("The program has been shut down, thank you \n");
    }
    else 
        printf("The program has been shut down, thank you\n");

    return 0;
}
