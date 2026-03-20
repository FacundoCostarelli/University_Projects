/**
 * @file    P1.c
 * @brief   [ESP] Archivo fuente de prueba de polinomio de Taylor para Coseno.
 *          [ENG] Source code testing Taylor polynomial series for Cosine.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "my_header.h"

/**
 * @brief [ESP] Main para prueba iterativa del cálculo de Coseno con Taylor.
 *        [ENG] Main function to test Cosine approximation with Taylor iterative cycles.
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
      
    verificar = coseno(&abscisas, &ordenadas, Xmin, Xmax, p);
    
    for(cont = 0; cont < verificar; cont++)
    {
		printf("%6.3lf,%6.3lf", abscisas[cont], ordenadas[cont]);
		if(cont < (verificar - 1))
			printf(";");
	}
	
	free(abscisas);
	free(ordenadas);
    
	return(0);
}

/**
 * @brief [ESP] Calcula aproximación del coseno sobre un rango de abscisas usando sumatorias de Taylor.
 *        [ENG] Approximates cosine values across an abscissas range using Taylor accumulations.
 *
 * @param x  [ESP] Array dinámico para X / [ENG] Dynamic x-coordinates array
 * @param y  [ESP] Array dinámico para Y / [ENG] Dynamic y-coordinates array
 * @param Xm [ESP] Rango mínimo / [ENG] Local minimum range
 * @param XM [ESP] Rango máximo / [ENG] Local maximum range
 * @param p  [ESP] Cantidad de puntos / [ENG] Point iterations quantity
 * @return int [ESP] Total de puntos procesados / [ENG] Processed points size
 */
int coseno(double **x, double **y, double Xm, double XM, int p)
{
	double resultado = 0, factorial = 1, binomio = 1;
	int cont, i, j, k = 1;
	double a, *abs, *ord;
	
	a = Xm;
	
    /* [ESP] Validación de bordes / [ENG] Boundary constraints */
	if(p < 2) return(-1);		// Minimo 2 puntos
	if(Xm >= XM) return(-2);    // El minimo es mayor al maximo
	if(x == NULL) return(-3);   // No me pasaron una direccion valida
	
	*x = (double *)malloc(p * sizeof(double));
	if(!(*x)) return(-5);		// Error de malloc
	
    *y = (double *)malloc(p * sizeof(double));
	if(!(*y)) return(-5);		// Error de malloc

	abs = *x;
	ord = *y;		
	
	for(cont = 0; cont < p; cont++)
	{
		abs[cont] = a;
		a += (XM - Xm) / (p - 1); // Incremento delta x / delta increment

        /* [ESP] Términos de sumatoria de Taylor / [ENG] Taylor summation scopes */
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
