#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

#define EXITO 0
#define ERROR -1

typedef struct Paciente
{
    char nombre[30];
    int edad;
    char obra_social[30];


}Paciente;

typedef struct Nodo
{
    Paciente paciente;
    struct Nodo *siguiente;

}Nodo;

int encolar(Nodo **cola_pacientes, Paciente paciente);
int cargar_info_estructura_paciente(Paciente **ptr);
void imprimir_cola(Nodo **cola_pacientes);
void liberar_memoria_cola(Nodo **cola_pacientes);
int filtrar(Nodo *cola_pacientes, char **obras_sociales, int cantidad_obras_sociales, char *nombre_archivo);
void Menu(void);

int main(int argc, char **argv)
{
    /*
     * TODO ESTE BLOQUE FUNCIONA CORRECTAMENTE
     *
    int check, count = 0;
    Nodo *ptr_1erNodo = NULL;
    Paciente *ptr = NULL;
    char decision;
    char Matrix_Obras_Sociales[5][30] = {
                                        "OSDE",
                                        "Swiss Medical",
                                        "Galeno",
                                        "Andar",
                                        "Union Personal"
                                        };
    char nombre_archivo_salida[] = "TablaDePacientes.txt";


    do
    {
        do
        {
            printf("Desea cargar con informacion un nodo y encolar dicho nodo?. Presione \"S\"(SI) o \"N\"(NO): ");
            scanf("%c", &decision);
            __fpurge(stdin);

            if( decision != 'S' && decision != 'N' )
                printf("Ha ingresado mal la opcion. Vuelva a ingresar el caracter\n");

        }while( decision != 'S' && decision != 'N' );


        if( decision == 'S')
        {
            check = cargar_info_estructura_paciente(&ptr);

            if( check == ERROR )
            {
                printf("Hubo un error con la carga de informacion del nodo\n");
                return ERROR;
            }
            else if( check == EXITO )
                printf("Se pudo cargar correctamente con informacion un nodo\n");

            check = encolar(&ptr_1erNodo, *ptr);

            if( check == ERROR )
            {
                printf("Hubo un error con la creacion del nodo y con la asignacion de memoria dinamica para el nodo\n");
                return ERROR;
            }
            else if( check == EXITO )
                printf("Se pudo encolar exitosamente un nodo\n");
            count++;
        }
    }while( decision == 'S' );

    if( count == 0 )
    {
        printf("No se ha creado ningun nodo. Usted saldra del programa \n");
        return EXITO;
    }

    imprimir_cola(&ptr_1erNodo);

    check = filtrar(ptr_1erNodo, Matrix_Obras_Sociales, 5, nombre_archivo_salida);
    if( check == ERROR )
    {
        printf("Hubo un error con la apertura y/o escritura del archivo de txt de salida\n");
        return ERROR;
    }
    else if( check == EXITO )
        printf("Se pudo abrir y escribir correctamente el archivo de txt de salida\n");
    */




    if( argc <= 2)
    {
        printf("Faltan argumentos. Re-ejecute el programa tal que ingresa los argumentos como sigue: <nombre ejecutable.out> <nombre archivo.bin> <nombre obra social 1> .......<nombre obra social n>\n");
        return ERROR;
    }

    int check, count = 0;
    Nodo *ptr_1erNodo = NULL;
    Paciente *ptr = NULL;
    int opcion;
    char nombre_archivo[strlen(argv[1])+1];
    char formato[] = ".txt";

    memset(nombre_archivo, 0, sizeof(nombre_archivo));
    strncpy(nombre_archivo, argv[1], strlen(argv[1])-4);
    strcat(nombre_archivo, formato);
    printf("El nombre del archivo de salida queda como: %s\n", nombre_archivo);

    Menu();

    while( ( opcion = getc(stdin) ) != EOF )
    {
        __fpurge(stdin);
        switch(opcion)
        {
            case '1':

                check = cargar_info_estructura_paciente(&ptr);

                if( check == ERROR )
                {
                    printf("Hubo un error con la carga de informacion del nodo\n");
                    return ERROR;
                }
                else if( check == EXITO )
                    printf("Se pudo cargar correctamente con informacion un nodo\n");

                check = encolar(&ptr_1erNodo, *ptr);

                if( check == ERROR )
                {
                    printf("Hubo un error con la creacion del nodo y con la asignacion de memoria dinamica para el nodo\n");
                    return ERROR;
                }
                else if( check == EXITO )
                    printf("Se pudo encolar exitosamente un nodo\n");

                count++;

                if( count == 0 )
                {
                    printf("No se ha creado ningun nodo. Usted saldra del programa\n");
                    return EXITO;
                }

                Menu();

                break;

            case '2':

                if( count == 0 )
                    printf("No se ha creado ningun nodo previamente. No se imprimira ninguna COLA. Vuelva a ingresar una opcion\n");
                else
                    imprimir_cola(&ptr_1erNodo);

                Menu();

                break;

            case '3':

                if( count == 0 )
                    printf("No se ha creado ningun nodo previamente. No se escribira ningun archivo de texto con una tabla CSV\n");
                else
                {
                    check = filtrar(ptr_1erNodo, argv, argc-2, argv[1] );
                    if( check == ERROR )
                    {
                        printf("Hubo un error con la apertura y/o escritura del archivo de txt de salida\n");
                        return ERROR;
                    }
                    else if( check == EXITO )
                        printf("Se pudo abrir y escribir correctamente el archivo de txt de salida\n");
                }
                Menu();
                break;

            case '\n' : case ' ': //ignora estas entradas de teclado

                break;

            default:

                printf("Ha ingresado mal una opcion. Vuelva a intetarlo\n");
                Menu();
                break;
        }

    }

    liberar_memoria_cola(&ptr_1erNodo);

    printf("Ha finalizado el programa correctamente y se han liberado todos los recursos\n");

    return EXITO;
}

void Menu(void)
{
    printf("Menu principal:\n");
    printf("1. Agregar un nuevo paciente (desde stdin)\n");
    printf("2. Imprimir todos los pacientes y su informacion por la salida estandar (stdout)\n");
    printf("3. Generar un archivo de texto con los pacientes filtrados por obra social\n");
    printf("EOF. Finalizar programa\n");
    printf("Elija una opcion (1, 2 o 3): \n");
}

int encolar(Nodo ** cola_pacientes, Paciente paciente) //Como el enunciado no especifica si Nodo **cola_pacientes se asocia al 1er nodo o al ultimo nodo de la cola, puedo elegir y asumir cualquiera de las dos opciones. En particular elijo en este caso que Nodo **cola_pacientes se asocie al 1er elemento de la cola para tener una mejor abarcacion de casos
{
    Nodo *Nuevo_Nodo = NULL;
    //*cola_pacientes es como tener Nodo *ptrFirstElement en este caso, es decir, un puntero al 1er nodo de la lista
    Nodo *Nodo_actual = *cola_pacientes;

    //Creo un nuevo nodo dinamicamente
    Nuevo_Nodo = (Nodo *)malloc(sizeof(Nodo));

    //Verifico si se obtuvo correctamente el bloque de memoria dinamico solicitado al sistema
    if( Nuevo_Nodo == NULL )
        return ERROR;

    //Enlazo el nodo creado recientemente con ningun otro nodo
    Nuevo_Nodo->siguiente = NULL;

    //Cargo la informacion necesaria en el nodo creado recientemente
    Nuevo_Nodo->paciente = paciente;

    //Verifico si la COLA esta vacia y en tal caso encolo el 1er nodo. Sino, si la COLA ya posee 1 o mas nodos creados, enlazo el ultimo nodo de la COLA con el nuevo nodo creado recientemente
    if( Nodo_actual == NULL )
    {
        printf("La COLA esta vacia. Se va a encolar el 1er nodo en la COLA\n");
        *cola_pacientes = Nuevo_Nodo;
        Nodo_actual = Nuevo_Nodo;
        return EXITO;
    }
    else
    {
        //Recorro la lista en busqueda del ultimo nodo
        while( Nodo_actual->siguiente != NULL )
            Nodo_actual = Nodo_actual->siguiente;

        //Enlazo el ultimo nodo de la COLA con el nodo creado dinamicamente
        Nodo_actual->siguiente = Nuevo_Nodo;

        //Asocio el puntero Nodo_actual con el ultimo nodo agregado recientemente
        Nodo_actual = Nodo_actual->siguiente;

        return EXITO;
    }
}

int cargar_info_estructura_paciente(Paciente **ptr)
{
    *ptr = (Paciente *)malloc(sizeof(Paciente));

    if( *ptr == NULL )
        return ERROR;

    printf("Ingrese el nombre del paciente: ");

    /* Obtengo el nombre del paciente a traves del buffer de entrada con un limite maximo de caracteres como proteccion contra overflow */
    fgets((*ptr)->nombre,30,stdin);

    /* Elimino del array "nombre" el caracter de "\n" si es que se ingreso */
    if ((strlen((*ptr)->nombre) > 0) && ((*ptr)->nombre[strlen((*ptr)->nombre) - 1] == '\n'))
        (*ptr)->nombre[strlen((*ptr)->nombre) - 1] = '\0';

    /* Obtengo la edad del paciente*/
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &(*ptr)->edad);
    __fpurge(stdin);

    printf("Ingrese la obra social del paciente: ");

    /* Obtengo el nombre de la obra social a traves del buffer de entrada con un limite maximo de caracteres como proteccion contra overflow */
    fgets((*ptr)->obra_social,30,stdin);

     /* Elimino del array "obra_social" el caracter de "\n" si es que se ingreso */
    if ((strlen((*ptr)->obra_social) > 0) && ((*ptr)->obra_social[strlen((*ptr)->obra_social) - 1] == '\n'))
        (*ptr)->obra_social[strlen((*ptr)->obra_social) - 1] = '\0';

    return EXITO;
}

void imprimir_cola(Nodo **cola_pacientes)
{
    Nodo *Nodo_actual = *cola_pacientes;

    /*Recorro la COLA y voy imprimiendo la informacion de cada nodo*/
    while( Nodo_actual != NULL )
    {
        printf("Nombre de paciente: %s\n", Nodo_actual->paciente.nombre);
        printf("Edad de paciente: %d\n", Nodo_actual->paciente.edad);
        printf("Nombre de obra social: %s\n", Nodo_actual->paciente.obra_social);
        printf("\n\n");
        Nodo_actual = Nodo_actual->siguiente;
    }

        return;
}

void liberar_memoria_cola(Nodo **cola_pacientes)
{
    Nodo *Nodo_actual = *cola_pacientes;
    Nodo *aux = *cola_pacientes;

    do
    {
        Nodo_actual = Nodo_actual->siguiente;
        free(aux);
        aux = Nodo_actual;
    }while( Nodo_actual != NULL );

    return;
}



int filtrar(Nodo *cola_pacientes, char **obras_sociales, int cantidad_obras_sociales, char *nombre_archivo)//Asumo en este caso que Nodo *cola_pacientes es un puntero al 1er nodo de la COLA. Ademas, char **obras_sociales es equivalente a char obras_sociales[][30] donde 30 es el numero de columnas de la matrix de cadenas char en este caso pensado mas arriba. Por otro lado, int cantidad_obras_sociales esta asociado a la cantidad de filas de la matrix de cadenas char. Finalmente char *nombre_archivo esta asociado con el nombre del archivo de salida pensado mas arriba en un array de char
{

    Nodo *Nodo_actual =  cola_pacientes;
    FILE *File_out = NULL;
    int i;
    // char coma = ',';
    //char nuevalinea = '\n';

    //Abro un archivo de salida con permisos de escritura y chequeo error
    File_out = fopen(nombre_archivo,"wt");
    if( File_out == NULL )
        return ERROR;
    else
        printf("Se creo correctamente el archivo de salida\n");

    //Recorro cada nodo de la COLA desde el comienzo de la misma
    while( Nodo_actual != NULL )
    {
        //printf("Se llego a la linea 242\n");
        //Verifico por cada nodo si el campo cargado "Nodo_actual->paciente.obra_social" es igual o no a alguno de los strings cadena asociados a las diferentes obras sociales de referencia. Para ello recorro con un for todos los strings de obras sociales y comparo con el campo mencionado
        for( i = 0; i < cantidad_obras_sociales; i ++ )
        {
            //printf("Se llego a la linea 245\n");
            //En caso de que el campo cargado "Nodo_actual->paciente.obra_social" sea igual a alguno de los strings cadena asociados a las obras sociales de referencia , entonces escribo en un archivo de texto con formato CSV, los datos del paciente ubicados en el nodo que satisface esta condicion mencionada.
            if( strcasecmp( Nodo_actual->paciente.obra_social, obras_sociales[i] ) == 0 )
            {
                //printf("Se llego a la linea 248\n");
                /*Este 1er bloque funciona bien
                fwrite(Nodo_actual->paciente.nombre, strlen(Nodo_actual->paciente.nombre), 1, File_out);
                fwrite(&coma, sizeof(coma), 1, File_out);
                fprintf(File_out, "%d", Nodo_actual->paciente.edad);
                fwrite(&coma, sizeof(coma), 1, File_out);
                fwrite(Nodo_actual->paciente.obra_social, strlen(Nodo_actual->paciente.obra_social), 1, File_out);
                fwrite(&nuevalinea, sizeof(nuevalinea), 1, File_out);
                */
                //Este 2do bloque funciona bien tambien y es equivalente al 1er bloque
                fprintf(File_out,"%s,%d,%s\n", Nodo_actual->paciente.nombre, Nodo_actual->paciente.edad, Nodo_actual->paciente.obra_social);
            }
            //printf("Se llego a la linea 256\n");
        }
        Nodo_actual = Nodo_actual->siguiente;
    }

    return EXITO;
}

