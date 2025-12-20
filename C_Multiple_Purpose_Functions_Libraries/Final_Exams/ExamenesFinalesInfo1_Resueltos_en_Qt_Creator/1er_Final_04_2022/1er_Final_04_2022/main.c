#include"Funciones.h"

int main(int argc, char**argv)
{
    if( argc != 3)
    {
        printf("Cantidad insuficiente de argumentos, reingresar segun <nomnre_ejecutable> <arch_entrada> <arch_salida>\n");
        return EARGS;
    }

    FILE *File_in = NULL;
    int CantidadUniones_FileIn = 0;
    long tamanio_archivo = 0;
    int i = 0;
    union logic_in *Buffer_Read_in = NULL;

    FILE *File_out = NULL;
    int CantidadUniones_FileOut = 0; //Sera igual a la cantidad de uniones de salida ya que por cada entrada hay una salida
    union logic_out *Buffer_Read_out = NULL;

    //Array de encuniado para contar cantidad de bits 0 en canales IN
    int counts[CANTIDAD_ELEMENTOS_ARRAY_DATOS];
    //Inicializo el array con todos 0
    for( i = 0; i < CANTIDAD_ELEMENTOS_ARRAY_DATOS; i++ )
        counts[i] = 0;


    //Abro el archivo de entrada
    File_in = fopen(argv[1],"r");
    if( File_in == NULL )
    {
        printf("Ocurrio un erorr en la apertura del archivo de entrada\n");
        return EINFILE;
    }

    //Posiciono el "file position indicator" al final del archivo de entrada
    fseek(File_in,0,SEEK_END);
    //Averiguo el tamanio del archivo
    tamanio_archivo = ftell(File_in);
    //Averiguo la cantidad de estructuras del archivo de entrada
    CantidadUniones_FileIn =  ( (int)tamanio_archivo ) / ( (int)sizeof(union logic_in) );
    printf("La cantidad de estructuras tipo union logic_in son: %d\n", CantidadUniones_FileIn);
    //Posiciono el "file position indicator" al comienzo del arhcivo de entrada
    fseek(File_in,0,SEEK_SET);

    //Pido memoria dinamica para almacenar la info del archivo in en memoria
    Buffer_Read_in = (union logic_in *)malloc( CantidadUniones_FileIn * sizeof(union logic_in));
    //Proteccion contra NULL de malloc
    if( Buffer_Read_in == NULL )
    {
        printf("Erropr en la asignacion de memoria dinamica para buffer de informacion read in\n");
        return ERROR;
    }

    //Leo del arhcivo de entrada las estructuras y las guardo en memoria
    if ( fread(Buffer_Read_in, CantidadUniones_FileIn * sizeof(union logic_in), 1, File_in) < 1 )
    {
        printf("Hubo un error con la lectura en memoria de las estructuras de entrada\n");
        return ERROR;
    }

    //Cierro el archivo de entrada
    fclose(File_in);

    CantidadUniones_FileOut = CantidadUniones_FileIn;

    //Abro el archivo de salida
    File_out = fopen(argv[2],"wb");
    if( File_out == NULL )
    {
        printf("Ocurrio un erorr en la apertura del archivo de salida\n");
        return EOUTFILE;
    }

    //Pido memoria dinamica para almacenar la info de los datos procesados en memoria
    Buffer_Read_out = (union logic_out *)malloc( CantidadUniones_FileOut * sizeof(union logic_out));
    //Proteccion contra NULL de malloc
    if( Buffer_Read_out == NULL )
    {
        printf("Erropr en la asignacion de memoria dinamica para buffer de informacion read out\n");
        return ERROR;
    }



    /**llamada a funciones */
    for( i = 0; i < CantidadUniones_FileOut; i++ )
    {
        process_data(&Buffer_Read_in[i], &Buffer_Read_out[i]);

        compute_zeroes(&Buffer_Read_in[i], counts);
    }

    print_stats(counts, CantidadUniones_FileIn);

    fwrite(Buffer_Read_out,sizeof(union logic_out), 1, File_out);

    //Cierro el archivo de salida
    fclose(File_out);
    //Libero los recursos del buffer dinamico de estructuras provenientes del archivo de entrada y de salida
    free(Buffer_Read_in);
    free(Buffer_Read_out);

    printf("Se ejecuto correctamente el programa\n");
    return 0;
}
