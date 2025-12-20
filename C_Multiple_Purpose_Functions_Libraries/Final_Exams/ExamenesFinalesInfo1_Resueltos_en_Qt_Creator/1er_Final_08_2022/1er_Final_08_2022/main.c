#include "Funciones.h"

int main(int argc, char **argv)
{
    if( argc != 3)
    {
        printf("Error en argumentos ingresados. Reingresar segun: <nombre_ejecutable> <nombre_archivo_de_salida> <texto_a_encriptar>\n");
        return ERROR;
    }

    int i = 0;
    FILE *File_out = NULL;
    struct texto_encriptado *ptr = NULL;
    long tamanio_archivo = 0;
    char txt_aux[TXT_MAX_LEN];
    srand(time(NULL));

    //Abro arhcivo out
    File_out = fopen(argv[1],"wb");
    if( File_out == NULL )
    {
        printf("Error en apertura de archivo out\n");
        return ERROR;
    }

    //Pido memoria dinamica para la estructura
    ptr = (struct texto_encriptado *)malloc(sizeof(struct texto_encriptado));
    if(ptr == NULL)
    {
        printf("Error durante la asignacion de memoria dinamica para la struct texto_encriptado\n");
        return ERROR;
    }

    //Inicializo el campo array interno de la estructura con \0
    for( i = 0; i < TXT_MAX_LEN; i++ )
    {
        txt_aux[i] = '\0';
        ptr->txt[i] = '\0';
    }



    ptr->desplazamiento = encriptar_letras(argv[2], txt_aux);

    printf("Encriptacion de eltras da: %s\n",txt_aux);

    encriptar_numeros(txt_aux, ptr->txt);

    printf("Desplazamiento: %d\n",ptr->desplazamiento);
    printf("Encriptacion de letras y numeros: %s\n",ptr->txt);

    fseek(File_out,0,SEEK_END);
    tamanio_archivo = ftell(File_out);
    fseek(File_out,tamanio_archivo,SEEK_CUR);
    fwrite(ptr,sizeof(struct texto_encriptado),1,File_out);


    //Libero recursos
    fclose(File_out);
    free(ptr);

    printf("Se ejecuto el programa corretactmente\n");

    return 0;
}
