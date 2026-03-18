/***Función que reciba un string correspondiente a un nombre de archivo, busca el
último punto a la derecha y devuelve un string que corresponda al nombre original, agregada alguna frase ej
“_decrypt” y la extensión original.***/
//Ejemplo: Recibe el nombre "texto.txt" y debe retornar "texto_decrypt.txt"
//Si el nombre no contiene punto, la frase se agregará al final y quedará sin punto.
//El buffer_frase contiene en este ejemplo a _decrypt
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
        //Inicializo los buffers con todos 0
        memset(buffer_nombre,'\0',sizeof(buffer_nombre));
        memset(buffer_extension,'\0',sizeof(buffer_extension));
        //memset(buffer_frase,'\0',sizeof(buffer_frase));
        flag = EXITO;
    }
    else
        return ERROR;

    if(flag == EXITO )
    {
        //Guardo el nombre del archivo In en un buffer hasta encontrar el "." en el nombre
        for( i = 0; Nombre_Archivo_In[i] != '.'; i++ )
            buffer_nombre[i] = Nombre_Archivo_In[i];


       //printf("largo de la extension %lu\n",strlen(Nombre_Archivo_In+i));

        //Guardo la extension en un buffer
        for( j = 0; Nombre_Archivo_In[i] != '\0'; j++, i++ )
            buffer_extension[j] = Nombre_Archivo_In[i];

        //printf("La extension es: %s\n",buffer_extension);

        flag = EXITO;
    }
    else
        return ERROR;

    if( flag == EXITO )
    {
        //Guardo en el array de salida el nuevo nombre con la nueva frase adicional y la extension original

        //Guardo nombre original en array de salida
        for( i = 0; i < strlen(buffer_nombre); i++ )
            Nombre_Archivo_Out[i] = buffer_nombre[i];
        //Guardo frase concatenandola en array de salida
        for( j = 0; j < strlen(buffer_frase); j++, i++ )
            Nombre_Archivo_Out[i] = buffer_frase[j];
        //Guardo extension original concatenandola en array de salida
        for( j = 0; j < strlen(buffer_extension); j++,i++ )
            Nombre_Archivo_Out[i] = buffer_extension[j];

        //Guardo el caracter null como ultimo elemento para indicar fin de cadena
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
