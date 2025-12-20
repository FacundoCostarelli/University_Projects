#include <stdio.h>

/* EL programa calcula si una persona puede realizar una compra o no con la tarjeta de credito
a partir de saber una serie de datos iniciales, es decir, determina si excede o no el limite
de la tarjeta de credito*/

int main() 
{
    int account_number;
    float beginning_balance, total_charges, total_credits, credit_limit, final_balance = 0;

    /* Declaro e inicializo las variables a usar*/

    printf("Enter  account number (-1 to end data input) : ");
    scanf("%d", &account_number);
    
    if ( account_number != -1 )
    {
        while ( account_number != -1 )
        {
            /* Ingreso los datos de input necesarios */
            printf("Enter beginning balance: ");
            scanf("%f", &beginning_balance);
            printf("Enter total charges: ");
            scanf("%f", &total_charges);
            printf("Enter total credits: ");
            scanf("%f", &total_credits);
            printf("Enter credit limit: ");
            scanf("%f", &credit_limit);
            
            /*Calculo el balance final*/
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
