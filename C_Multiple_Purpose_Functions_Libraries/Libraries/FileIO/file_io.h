/**
 * @file    file_io.h
 * @brief   [ESP] Biblioteca de funciones de entrada/salida de archivos.
 *          [ENG] File input/output functions library.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 *
 * [ESP] Colección de funciones para operaciones con archivos:
 *       lectura/escritura binaria de estructuras y enteros de 32 bits,
 *       copia de archivos fuente sin líneas de comentarios,
 *       y modificación de nombres de archivo con sufijos.
 *
 * [ENG] Collection of functions for file operations:
 *       binary reading/writing of structs and 32-bit integers,
 *       copying source files without comment lines,
 *       and filename modification with suffixes.
 */

#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @brief [ESP] Código de error / [ENG] Error code */
#define ERROR -1
/** @brief [ESP] Código de éxito / [ENG] Success code */
#define EXITO  0

/**
 * @brief [ESP] Lee enteros de 4 bytes desde un archivo binario y los
 *              almacena en un buffer dinámico.
 *        [ENG] Reads 4-byte integers from a binary file and stores
 *              them in a dynamic buffer.
 *
 * [ESP] Calcula la cantidad de enteros a partir del tamaño del archivo,
 *       aloca memoria dinámica y lee todos los datos. El llamador debe
 *       liberar la memoria con free().
 *
 * [ENG] Calculates the number of integers from the file size, allocates
 *       dynamic memory, and reads all data. The caller must free the
 *       memory with free().
 *
 * @param[in]  Nombre_Archivo_In  [ESP] Nombre (ruta) del archivo binario.
 *                                [ENG] Name (path) of the binary file.
 * @param[out] Buffer_enteros     [ESP] Puntero doble donde se almacenará
 *                                      la dirección del buffer alocado.
 *                                [ENG] Double pointer where the address
 *                                      of the allocated buffer will be stored.
 * @return     [ESP] Cantidad de enteros leídos (>= 0), o ERROR (-1) si falla.
 *             [ENG] Number of integers read (>= 0), or ERROR (-1) on failure.
 *
 * @example
 *   int *buffer = NULL;
 *   int count = LecturaEnterosDe_4_BytesFileInBinario("data.bin", &buffer);
 *   if (count > 0) {
 *       for (int i = 0; i < count; i++) printf("%d ", buffer[i]);
 *       free(buffer);
 *   }
 */
int LecturaEnterosDe_4_BytesFileInBinario(char *Nombre_Archivo_In, int **Buffer_enteros);

/**
 * @brief [ESP] Modifica un nombre de archivo insertando un sufijo antes de la extensión.
 *        [ENG] Modifies a filename by inserting a suffix before the extension.
 *
 * [ESP] Ejemplo: "texto.txt" → "texto_decrypt.txt"
 * [ENG] Example: "texto.txt" → "texto_decrypt.txt"
 *
 * @param[in]  Nombre_Archivo_In   [ESP] Nombre original del archivo.
 *                                 [ENG] Original filename.
 * @param[out] Nombre_Archivo_Out  [ESP] Buffer de salida con el nombre modificado.
 *                                       Debe tener espacio suficiente.
 *                                 [ENG] Output buffer for the modified name.
 *                                       Must have enough space.
 * @return     [ESP] EXITO (0) si se realizó correctamente, ERROR (-1) si falla.
 *             [ENG] EXITO (0) on success, ERROR (-1) on failure.
 *
 * @example
 *   char new_name[100];
 *   ModificarNombreFileIn("report.pdf", new_name);
 *   // new_name == "report_decrypt.pdf"
 */
int ModificarNombreFileIn(char *Nombre_Archivo_In, char *Nombre_Archivo_Out);

#endif /* FILE_IO_H */
