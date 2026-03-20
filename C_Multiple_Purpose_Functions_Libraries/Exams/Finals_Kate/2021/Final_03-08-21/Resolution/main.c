/**
 * @file    main.c
 * @brief   [ESP] Programa principal Examen Final 03-08-2021. Creador de procesos hijos.
 *          [ENG] Main program Final Exam 03-08-2021. Child processes creator.
 *
 * @author  Facundo Costarelli
 * @date    2021
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @param argc [ESP] Cantidad de argumentos / [ENG] Arguments quantity
 * @param argv [ESP] Vector de argumentos / [ENG] Arguments vector
 * @return 0   [ESP] Finalización correcta / [ENG] Correct termination
 */
int main (int argc, char **  argv)
{
	int i;
	int pid;
	struct hijos procesos[10];
	char * nombre_vec = NULL;

	/* [ESP] Validaciones iniciales / [ENG] Initial validations */
	if ((argc < 2) || (argc > 10))
	{
		printf("Debe especificar entre uno y diez nombres de archivo para procesar.\n");
	}
	else
	{
		/* [ESP] Creación de un proceso hijo por cada archivo / [ENG] Creation of child process per file */
		for (i = 1; i < argc; i++)
		{
			pid = fork();

			if (!pid)
			{
				/* [ESP] Código del hijo / [ENG] Child code */
				f_hijo(argv[i]);
				return 0;
			}
			else
			{
				/* [ESP] Código del padre / [ENG] Parent code */
				nombre_vec = (char *) malloc(strlen(argv[i])+1);
				if (!nombre_vec)
				{
					printf("No se pudo obtener memoria para guardar el nombre (archivo %d).\n", i);
					exit(1);
				}

				strcpy(nombre_vec, argv[i]);
				procesos[i].pid = pid;
				procesos[i].archivo = nombre_vec;
				procesos[i].nro_arg = i;
			}
		}

		/* [ESP] El padre espera a todos los hijos / [ENG] Parent waits for all children */
		for (i = 1; i < argc; i++)
		{
				wait(NULL);
		}

		/* [ESP] Liberación de recursos del padre / [ENG] Parent resources release */
		for (i = 1; i < argc; i++)
		{
				free(procesos[i].archivo);
		}
	}
	return 0;
}
