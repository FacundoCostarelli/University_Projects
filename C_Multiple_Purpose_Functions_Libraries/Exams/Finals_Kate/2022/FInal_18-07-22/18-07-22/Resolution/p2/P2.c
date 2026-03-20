/**
 * @file    P2.c
 * @brief   [ESP] Resolución del Problema 2 - Final 18-07-2022 (Contador caracteres).
 *          [ENG] Resolution of Problem 2 - Final 18-07-2022 (Character counter).
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "my_header.h"

/**
 * @brief [ESP] Función principal del contador de caracteres.
 *        [ENG] Main function for the character counter.
 *
 * @param argc [ESP] Cantidad de argumentos / [ENG] Number of arguments
 * @param argv [ESP] Vector de argumentos / [ENG] Argument vector
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(int argc, char *argv[])
{
	int a, fd, listado['z'-'a'+1], i;
	
	/* [ESP] Abrimos el archivo pasado por argumento / [ENG] Open file passed as argument */
	fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	
	for(i = 0; i < 'z'-'a'; i++)
		listado[i] = 0;
		
	/* [ESP] Invocación de la función contador / [ENG] Invocation of counter function */
	a = contador(fd, listado);
	if(a < 0)
	{
		printf("error: %d\n", a);
		return 0;
	}
	
	/* [ESP] Imprimir los resultados / [ENG] Print results */
	for(i = 0; i < 'z'-'a'; i++)
		printf("%c:%i veces\n", 'a'+i, listado[i]);			
		
	return 0 ;
}

/**
 * @brief [ESP] Cuenta cuántas iteraciones de cada carácter hay en un archivo.
 *        [ENG] Counts how many iterations of each character are in a file.
 *
 * @param archivo [ESP] File descriptor del archivo / [ENG] File descriptor
 * @param vector  [ESP] Vector que almacena las ocurrencias / [ENG] Vector storing occurrences
 * @return int    [ESP] Códigos de error / [ENG] Error codes
 */
int contador(int archivo, int *vector)
{
	int cont;
	char letra;
	
	if(!vector) return -1;
	if(!archivo) return -2;	
	
	do
	{
		cont = read(archivo, &letra, 1);
		if(cont)
		{
			/* [ESP] Cuenta minúsculas / [ENG] Counts lowercase */
			if(letra >= 'a' && letra <= 'z')
			{
				vector[letra-'a']++;
			}
			/* [ESP] Cuenta mayúsculas (y las mapea al mismo lugar) / [ENG] Counts uppercase */
			if(letra >= 'A' && letra <= 'Z')
			{
				vector[letra-'A']++;
			}
		}
	} while(cont);	
	
	return(0);
}
