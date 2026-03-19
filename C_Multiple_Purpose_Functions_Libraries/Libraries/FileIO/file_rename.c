/**
 * @file    file_rename.c
 * @brief   [ESP] Modificación de nombres de archivo con inserción de sufijo.
 *          [ENG] Filename modification with suffix insertion.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "file_io.h"

/**
 * @brief [ESP] Modifica un nombre de archivo insertando "_decrypt" antes de la extensión.
 *        [ENG] Modifies a filename by inserting "_decrypt" before the extension.
 */
int ModificarNombreFileIn(char *Nombre_Archivo_In, char *Nombre_Archivo_Out)
{
    size_t i = 0, j = 0;
    char buffer_nombre[30];
    char buffer_extension[10];
    char buffer_frase[] = "_decrypt";
    int flag = 1;

    if (flag == 1)
    {
        /* [ESP] Inicializar los buffers con caracteres nulos
           [ENG] Initialize buffers with null characters */
        memset(buffer_nombre, '\0', sizeof(buffer_nombre));
        memset(buffer_extension, '\0', sizeof(buffer_extension));
        flag = EXITO;
    }
    else
        return ERROR;

    if (flag == EXITO)
    {
        /* [ESP] Extraer el nombre base: copiar caracteres hasta encontrar '.'
           [ENG] Extract the base name: copy characters until '.' is found */
        for (i = 0; Nombre_Archivo_In[i] != '.'; i++)
            buffer_nombre[i] = Nombre_Archivo_In[i];

        /* [ESP] Extraer la extensión (incluyendo el '.')
           [ENG] Extract the extension (including the '.') */
        for (j = 0; Nombre_Archivo_In[i] != '\0'; j++, i++)
            buffer_extension[j] = Nombre_Archivo_In[i];

        flag = EXITO;
    }
    else
        return ERROR;

    if (flag == EXITO)
    {
        /* [ESP] Construir el nombre de salida: nombre + frase + extensión
           [ENG] Build output name: name + phrase + extension */

        /* [ESP] Copiar nombre original
           [ENG] Copy original name */
        for (i = 0; i < strlen(buffer_nombre); i++)
            Nombre_Archivo_Out[i] = buffer_nombre[i];

        /* [ESP] Concatenar la frase ("_decrypt")
           [ENG] Concatenate the phrase ("_decrypt") */
        for (j = 0; j < strlen(buffer_frase); j++, i++)
            Nombre_Archivo_Out[i] = buffer_frase[j];

        /* [ESP] Concatenar la extensión original
           [ENG] Concatenate the original extension */
        for (j = 0; j < strlen(buffer_extension); j++, i++)
            Nombre_Archivo_Out[i] = buffer_extension[j];

        /* [ESP] Terminar el string con '\0'
           [ENG] Null-terminate the string */
        Nombre_Archivo_Out[i] = '\0';

        flag = EXITO;
    }
    else
        return ERROR;

    return (flag == EXITO) ? EXITO : ERROR;
}
