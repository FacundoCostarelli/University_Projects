#include<stdio.h>

/* This program calculates the salary per week of a worker according to forms of payment of the company */
int main()
{   
    /*Declaration of variables*/
    int hours, counter = 0;
    float hourlyrate;
    /*First data input*/
    printf("Enter amount of hours worked ( -1 to end ): ");
    scanf("%d", &hours);
        
    /*Cicly for data input with flag value as a posibility*/
        
    while ( hours != -1 )
    {
        printf("Enter hourly rate of the worker: ");
        scanf("%f", &hourlyrate);
        counter = counter + 1;
            
        /*Evaluation of amount of hours worked, so that can be calculated the salary depending on normal time or normal time extrahours*/
            
        if ( hours <= 40 )
            printf("The salary is : %.2f \n", hours * hourlyrate);
        else 
            printf("The salary is : %.2f \n", hours * hourlyrate + hourlyrate / 2);
            
        printf("Enter amount of hours worked ( -1 to end ): ");
        scanf("%d", &hours);
    }
    
    if( counter != 0 )
        printf("The amount of total salaries calculated were: %d\n", counter); 
    else
        printf("There wasnt data entered to analyse, the program has been shut down\n");


    return 0;
}
