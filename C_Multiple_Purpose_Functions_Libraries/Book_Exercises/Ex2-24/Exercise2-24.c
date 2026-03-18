#include <stdio.h>

int main()
{

    /*Lee un numero y determina si es par o inpar*/

    int numero, resto;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    resto = numero % 2;

    if (resto == 0)
        printf("El numero %d es par\n", numero);
    
    if (resto != 0)
        printf("El numero %d es inpar\n", numero);

    return 0;

}
