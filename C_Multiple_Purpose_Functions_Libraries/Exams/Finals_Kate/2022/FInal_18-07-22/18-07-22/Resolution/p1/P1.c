/**
 * @file    P1.c
 * @brief   [ESP] Resolución del Problema 1 - Final 18-07-2022 (Cálculo de coseno).
 *          [ENG] Resolution of Problem 1 - Final 18-07-2022 (Cosine calculation).
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "my_header.h"

/**
 * @brief [ESP] Función principal del cálculo de coseno.
 *        [ENG] Main function for cosine calculation.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(void)
{
	int cont, verificar, p;
	double *abscisas = NULL, *ordenadas = NULL, Xmin, Xmax;
	
    printf("Ingrese X minima\n");
    scanf("%lf", &Xmin);
    __fpurge(stdin);
    
    printf("Ingrese X maxima\n");
    scanf("%lf", &Xmax);
    __fpurge(stdin);

	printf("Ingrese cantidad de puntos\n");
    scanf("%i", &p);
    __fpurge(stdin);
      
    /* [ESP] Calculo del coseno / [ENG] Cosine calculation */
    verificar = coseno(&abscisas, &ordenadas, Xmin, Xmax, p);
    
    for(cont = 0; cont < verificar; cont++)
    {
		printf("%6.3lf,%6.3lf", abscisas[cont], ordenadas[cont]);
		if(cont < (verificar-1))
			printf(";");
	}
	
	/* [ESP] Liberacion de memoria / [ENG] Memory release */
	free(abscisas);
	free(ordenadas);
    
	return(0);
}

/**
 * @brief [ESP] Calcula la serie de Taylor para la función coseno sobre el rango estipulado.
 *        [ENG] Computes Taylor series for cosine function over stipulated range.
 *
 * @param x  [ESP] Array de abscisas / [ENG] Abscissa array
 * @param y  [ESP] Array de ordenadas / [ENG] Ordinate array
 * @param Xm [ESP] Valor de X minimo / [ENG] X minimum value
 * @param XM [ESP] Valor de X maximo / [ENG] X maximum value
 * @param p  [ESP] Cantidad de puntos / [ENG] Points amount
 * @return int [ESP] Códigos de error u ok / [ENG] Error or ok codes
 */
int coseno(double **x, double **y, double Xm, double XM, int p)
{
	double resultado = 0, factorial = 1, binomio = 1;
	int cont, i, j, k = 1;
	double a, *abs, *ord;
	
	a = Xm;
	
	/* [ESP] Verificaciones de parametro / [ENG] Parameter verifications */
	if(p < 2) return(-1);		/* minimo 2 puntos */
	if(Xm >= XM) return(-2);		/* el minimo es mayor al maximo */
	if(x == NULL) return(-3);		/* no me pasaron una direccion valida */
	
    /* [ESP] Asignacion de memoria dinamica / [ENG] Dynamic memory allocation */
	*x = (double *)malloc(p * sizeof(double)); 
	if(!(*x)) return(-5);		/* error de malloc */
		
	*y = (double *)malloc(p * sizeof(double)); 
	if(!(*y)) return(-5);		/* error de malloc */
		
	abs = *x;		/* para simplificar el uso de punteros / to simplify pointer usage */
	ord = *y;		
	
	for(cont = 0; cont < p; cont++)
	{
		abs[cont] = a;
		a += (XM - Xm)/(p - 1);		/* mas delta x */
		
		for(i = 0; i <= TERMINOS; i++)
		{
			for(j = 0; j < (2 * i); j++)
				binomio *= (abs[cont]);
				
			for(j = 0; j < (2 * i); j++)
				factorial *= j + 1;
				
			resultado += (k * (binomio / factorial));
			binomio = 1;
			factorial = 1;
			k *= -1;
		}
		
		ord[cont] = resultado;
		resultado = 0;
		k = 1;
    }
	return p;
}
