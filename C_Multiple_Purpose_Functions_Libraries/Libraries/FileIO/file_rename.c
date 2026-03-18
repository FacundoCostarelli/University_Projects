/**
 * ==========================================================================
 * file_rename.c — Filename Modifier with Suffix Insertion
 * ==========================================================================
 * [ESP] Función que recibe un nombre de archivo, busca el último punto
 *       a la derecha y devuelve un nuevo nombre con una frase adicional
 *       (ej: "_decrypt") insertada antes de la extensión original.
 *       Ejemplo: "texto.txt" → "texto_decrypt.txt"
 *
 * [ENG] Function that receives a filename, finds the last dot on the right,
 *       and returns a new name with an additional phrase (e.g., "_decrypt")
 *       inserted before the original extension.
 *       Example: "texto.txt" → "texto_decrypt.txt"
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

// [ESP] Ejemplo: Recibe "texto.txt" y retorna "texto_decrypt.txt"
// [ENG] Example: Receives "texto.txt" and returns "texto_decrypt.txt"
// [ESP] Si el nombre no contiene punto, la frase se agrega al final.
// [ENG] If the name has no dot, the phrase is appended at the end.
// [ESP] buffer_frase contiene en este ejemplo "_decrypt"
// [ENG] buffer_frase contains "_decrypt" in this example
int ModificarNombreFileIn(char *Nombre_Archivo_In, char *Nombre_Archivo_Out)
{
    size_t i = 0, j = 0;
    char buffer_nombre[30];
    char buffer_extension[10];
    char buffer_frase[] = "_decrypt";
    //int largo_extension = 0;
    int flag = 1;

    if(flag == 1)
    {
        // [ESP] Inicializo los buffers con todos 0
        // [ENG] Initialize buffers with all zeros
        memset(buffer_nombre,'\0',sizeof(buffer_nombre));
        memset(buffer_extension,'\0',sizeof(buffer_extension));
        //memset(buffer_frase,'\0',sizeof(buffer_frase));
        flag = EXITO;
    }
    else
        return ERROR;

    if(flag == EXITO )
    {
        // [ESP] Guardo el nombre del archivo In en un buffer hasta encontrar el "."
        // [ENG] Store the input filename in a buffer until the "." is found
        for( i = 0; Nombre_Archivo_In[i] != '.'; i++ )
            buffer_nombre[i] = Nombre_Archivo_In[i];


       //printf("largo de la extension %lu\n",strlen(Nombre_Archivo_In+i));

        // [ESP] Guardo la extensión en un buffer
        // [ENG] Store the extension in a buffer
        for( j = 0; Nombre_Archivo_In[i] != '\0'; j++, i++ )
            buffer_extension[j] = Nombre_Archivo_In[i];

        //printf("La extension es: %s\n",buffer_extension);

        flag = EXITO;
    }
    else
        return ERROR;

    if( flag == EXITO )
    {
        // [ESP] Guardo en el array de salida el nuevo nombre completo
        // [ENG] Store the complete new name in the output array

        // [ESP] Guardo nombre original en array de salida
        // [ENG] Store original name in output array
        for( i = 0; i < strlen(buffer_nombre); i++ )
            Nombre_Archivo_Out[i] = buffer_nombre[i];
        // [ESP] Guardo frase concatenándola en array de salida
        // [ENG] Concatenate phrase into output array
        for( j = 0; j < strlen(buffer_frase); j++, i++ )
            Nombre_Archivo_Out[i] = buffer_frase[j];
        // [ESP] Guardo extensión original concatenándola en array de salida
        // [ENG] Concatenate original extension into output array
        for( j = 0; j < strlen(buffer_extension); j++,i++ )
            Nombre_Archivo_Out[i] = buffer_extension[j];

        // [ESP] Guardo el carácter null como último elemento para indicar fin de cadena
        // [ENG] Append null character as last element to indicate end of string
        Nombre_Archivo_Out[i] = '\0';

        flag = EXITO;
    }
    else
        return ERROR;

    if( flag == EXITO)
    {
        //printf("El archivo de salida tiene el nuevo nombre que es: %s\n",Nombre_Archivo_Out);
        return EXITO;
    }
    else
        return ERROR;

}
