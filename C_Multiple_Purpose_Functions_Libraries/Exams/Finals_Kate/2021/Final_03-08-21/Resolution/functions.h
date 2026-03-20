/**
 * @file    funciones.h
 * @brief   [ESP] Cabecera para Examen Final 03-08-2021.
 *          [ENG] Header for Final Exam 03-08-2021.
 *
 * @author  Facundo Costarelli
 * @date    2021
 * @course  Informática 1 — UTNBA
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#define OK 0
#define ERROR 1
#define ERR_LEC -1
#define DECRYPT 8
#define DESPLAZ 8
#define UNBYTE 256

/**
 * @brief [ESP] Estructura que almacena info de los procesos hijos.
 *        [ENG] Structure that stores child processes info.
 */
struct hijos
{
	int pid; 			/* [ESP] Número de proceso hijo / [ENG] Child process ID */
	char * archivo; 	/* [ESP] Archivo procesado / [ENG] Processed file */
	int nro_arg;		/* [ESP] Posición en argumentos / [ENG] Argument position */
};

/**
 * @brief [ESP] Prototipos de las funciones.
 *        [ENG] Function prototypes.
 */
int convertir(int *, int, char *);
int nvo_nombre(char *, char *);
int lectura(char *, int **);
int f_hijo(char * );

#endif /* FUNCIONES_H */
