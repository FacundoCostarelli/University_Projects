/**
 * @file    Exercise3-17.c
 * @brief   [ESP] Ejercicio 3.17 del libro: Cálculo de millas por galón.
 *          [ENG] Exercise 3.17 from the book: Miles per gallon calculation.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>

/**
 * @brief [ESP] Func. principal. Calcula MPGs por tanque y totales.
 *        [ENG] Main func. Calculates MPGs per tank and total MPGs.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    /* [ESP] Declaración de variables
       [ENG] Variable declaration */
    float galones, millas, GalonesTotales = 0, MillasTotales = 0; 
    
    /* [ESP] Se introducen las millas, galones y se calcula las millas por galón por tanque
       [ENG] Inputs miles, gallons, and calculates miles per gallon per tank */
    printf("Introduzca la cantidad de millas hechas con un tanque ( -1 para terminar  ): ");
    scanf("%f", &millas);
    
    if ( millas != -1 )
    {
        printf("Introduzca la cantidad de galones hechas con un tanque: ");
        scanf("%f", &galones);
        printf(" La cantidad de millas por galon es: %.2f \n", millas / galones);

        /* [ESP] Ciclo de repetición para pedir millas, galones y calcular las millas por galón por cada tanque
           [ENG] Loop for prompting miles, gallons, and calculating MPGs for each tank */
        while ( millas != -1 )
        {
            /* [ESP] Se calculan las millas totales y galones totales
               [ENG] Calculate total miles and total gallons */
            MillasTotales += millas;
            GalonesTotales += galones;

            printf("Introduzca la cantidad de millas hechas con un tanque o ( -1 para terminar ): ");
            scanf("%f", &millas);
            
            if ( millas != -1 )
            {
                printf("Introduzca la cantidad de galones hechas con un tanque: ");
                scanf("%f", &galones);
                printf(" La cantidad de millas por galon es: %.2f \n", millas / galones);
            }
        }
        
        /* [ESP] Se muestran las millas totales y galones totales de todos los tanques y la relación general.
           [ENG] Total miles and gallons from all tanks are displayed, along with the overall ratio. */
        printf(" Las millas totales son %.2f y los galones consumidos totales son %.2f \n Por otro lado, la cantidad de millas por galon respecto de todos los tanques es %.2f\n", MillasTotales, GalonesTotales, MillasTotales/GalonesTotales);
    }
    else 
    {
        printf("Se finalizara el programa, espere un momento....\n");
        printf("Listo, gracias por usar el servicio\n");
    }
    
    return 0;
}
