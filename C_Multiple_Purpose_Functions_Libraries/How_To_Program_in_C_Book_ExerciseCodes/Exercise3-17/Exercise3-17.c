#include<stdio.h>

int main()
{
    /* Declaracion de variables */

    float galones, millas, GalonesTotales = 0, MillasTotales = 0; 
    
    /* Se introducen las millas, galones y se calcula las millas por galon por tanque */

    printf("Introduzca la cantidad de millas hechas con un tanque ( -1 para terminar  ): ");
    scanf("%f", &millas);
            if ( millas != -1 )
            {
                printf("Introduzca la cantidad de galones hechas con un tanque: ");
                scanf("%f", &galones);
                printf(" La cantidad de millas por galon es: %.2f \n", millas / galones);

                /* Ciclo de repeticion para pedir millas, galones y calcular las millas por galon por cada tanque */

                while ( millas != -1 )
                {
                    /* Se calculan las millas totales y galones totales */
                    
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
                 /* Se muestran las millas totales y galones totales respecto de todos los tanques y al relacion de millas totales por galones totales */
                 
                printf(" Las millas totales son %.2f y los galones consumidos totales son %.2f \n Por otro lado, la cantidad de millas por galon respecto de todos los tanques es %.2f\n", MillasTotales, GalonesTotales, MillasTotales/GalonesTotales);
            }
            else 
            {
                printf("Se finalizara el programa, espere un momento....\n");
                printf("Listo, gracias por usar el servicio\n");
            }
    return 0;
}
