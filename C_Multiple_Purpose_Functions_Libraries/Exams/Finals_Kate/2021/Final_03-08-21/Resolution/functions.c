/**
 * @file    funciones.c
 * @brief   [ESP] Funciones para el Examen Final 03-08-2021.
 *          [ENG] Functions for Final Exam 03-08-2021.
 *
 * @author  Facundo Costarelli
 * @date    2021
 * @course  Informática 1 — UTNBA
 */

#include "functions.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief [ESP] Convierte un buffer de enteros a un string (ASCII).
 *        [ENG] Converts a buffer of integers into a string (ASCII).
 *
 * @param listado [ESP] Array de enteros / [ENG] Array of integers
 * @param largo   [ESP] Longitud del array / [ENG] Length of array
 * @param frase   [ESP] String resultante / [ENG] Resulting string
 * @return OK     [ESP] Si ejecución exitosa / [ENG] If successful execution
 */
int convertir (int * listado, int largo, char * frase)
{
	int i, codigo = OK;
	int aux_i;
	char aux;

	for (i=0; i < largo; i++)
	{
		aux_i = *(listado+i);
		/* [ESP] aux_i = aux_i >> DESPLAZ; / [ENG] aux_i = aux_i >> DESPLAZ; */
		aux_i = aux_i / UNBYTE;
		aux = (char) aux_i;
		*(frase+i) = aux;
	}
	*(frase+largo) = '\0';

	return codigo;
}

/**
 * @brief [ESP] Devuelve el nombre original añadiendo "_decrypt" antes de la extensión.
 *        [ENG] Returns the original name appending "_decrypt" before the extension.
 *
 * @param origen  [ESP] Nombre original / [ENG] Original name
 * @param destino [ESP] Nombre nuevo / [ENG] New name
 * @return OK     [ESP] Si ejecución exitosa / [ENG] If successful execution
 */
int nvo_nombre (char * origen, char * destino)
{
	int i, codigo = OK;
	char agregar[] = "_decrypt";

	i = strlen(origen);

	while((*(origen+i) != '.') && (i >= 0))
	{
		i--;
	}

	if (i < 0)
	{
		strcpy(destino,origen);
		strcat(destino, agregar);
	}
	else
	{
		strncpy(destino, origen, i);
		*(destino+i+1) = '\0';
		strcat(destino, agregar);
		strcat(destino, (origen+i));
	}

	return codigo;
}

/**
 * @brief [ESP] Lee archivo binario y guarda enteros en un buffer de memoria dinámica.
 *        [ENG] Reads binary file and stores integers in dynamic memory buffer.
 *
 * @param archivo [ESP] Nombre del archivo / [ENG] File name
 * @param buffer  [ESP] Doble puntero al buffer / [ENG] Double pointer to buffer
 * @return int    [ESP] Cantidad de elementos leídos / [ENG] Amount of read elements
 */
int lectura (char * archivo, int ** buffer)
{
	FILE * lectura;
	int i = 0, aux;
	int * aux_p;

	(*buffer) = (int *) malloc (sizeof(int));
	if (!(*buffer))
	{
		return ERR_LEC;
	}

	lectura = fopen(archivo, "r");
	if (!lectura)
	{
		return ERR_LEC;
	}

	do
	{
		fread(&aux, sizeof(int), 1, lectura);
		if (!feof(lectura))
		{
			aux_p = (int *) realloc (*buffer, sizeof(int)*(i+1));
			if (aux_p)
			{
				(*buffer) = aux_p;
				*((*buffer)+i) = aux;
				i++;
			}
			else
			{
				free(*buffer);
				return ERR_LEC;
			}
		}
	} while (!feof(lectura));

	return i;
}

/**
 * @brief [ESP] Función para procesos hijos que procesan los archivos.
 *        [ENG] Function for child processes that process the files.
 *
 * @param archivo [ESP] Archivo a procesar / [ENG] File to process
 * @return 0      [ESP] Terminación correcta / [ENG] Correct termination
 */
int f_hijo (char * archivo)
{
	int largo, sigo;
	int * numeros;
	char * frase = NULL;
	FILE * destino = NULL;
	char * nombre_dest = NULL;

	largo = lectura (archivo, &numeros);

	if (largo < 0)
	{
		printf("No se pudo generar el vector de números (archivo %s).\n", archivo);
		exit(1);
	}

	nombre_dest = (char *) malloc (strlen(archivo)+DECRYPT+1);
	if (!nombre_dest)
	{
		printf("No se pudo obtener memoria para generar el nombre (archivo %s).\n", archivo);
		exit(1);
	}

	sigo = nvo_nombre (archivo, nombre_dest);
	if (sigo == ERROR)
	{
		printf("Error en la función de generación del nombre (archivo %s).\n", archivo);
		exit(1);
	}

	frase = (char *) malloc (largo+1);
	if (!frase)
	{
		printf("No se pudo obtener memoria para guardar la frase (archivo %s).\n", archivo);
		exit(1);
	}

	sigo = convertir (numeros, largo, frase);
	if (sigo == ERROR)
	{
		printf("Error en la función de conversión de la frase (archivo %s).\n", archivo);
		exit(1);
	}

	destino = fopen(nombre_dest,"w");
	if (!destino)
	{
		printf("No se pudo abrir el archivo para grabar la frase (archivo %s).\n", archivo);
		exit(1);
	}
	fprintf(destino,"%s", frase);

	sleep(10);

	free(frase);
	free(numeros);
	free(nombre_dest);
	fclose(destino);

	return 0;
}
