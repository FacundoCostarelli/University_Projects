#include<stdio.h>

/*This program calculates the interest charge of a selected loan*/
int main()
{
    /*Declaration of variables*/

    float interest, principal, rate;
    int days;
    
    /*First data input with flag value as an option*/

    printf("Enter loan principal ( -1 to end ): ");
    scanf("%f", &principal);
    
    /*Evaluation of variable principal to determinate if it has flag value or not and what to do in any case*/

    if ( principal != -1 )
    {
        /*Cicle process to input more data*/

        while ( principal != -1 )
        {
            printf("Enter interest anual rate: ");
            scanf("%f", &rate);
            printf("Enter term or amount of days for the loan: ");
            scanf("%d", &days);
            
            /*Calculate of the total interest charge of the loan*/
 
            interest = principal * rate * days / 365;

            printf("The interest charge for the loan selected is: %.2f\n", interest);

            /*Input of first new data with flag value as an option to end the program*/
 
            printf("Enter loan principal ( -1 to end ): ");
            scanf("%f", &principal);

        }

        printf("The program has been shut down, thank you\n");

    }
    else
        printf("The program has been shut down, thank you\n");

    return 0;

}
