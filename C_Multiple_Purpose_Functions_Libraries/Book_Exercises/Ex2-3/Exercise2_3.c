#include <stdio.h>

int main()
{
    int a;
    printf("Ingrese un numero entero: ");
    scanf("%d",&a);
    printf("El numero ingresado es: %d \n",a);
	if( a != 7 )
		printf("La variable a no es igual a 7. \n");
    printf("This is a C program. \n");
    printf("This is a C\nprogram. \n");
    printf("This\nis\na\nC\nprogram. \n");
    printf("This\tis\ta\tC\tprogram. \n");
    return 0;
}
