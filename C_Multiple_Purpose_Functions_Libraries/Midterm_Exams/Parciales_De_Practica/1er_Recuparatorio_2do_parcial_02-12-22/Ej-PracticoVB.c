#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

#define ERROR -1
#define EXITO 0

typedef struct paciente
{
    char nombre[30];
    int edad;
    char obra_social[30];


}Paciente;

int arreglar(Paciente **pacientes, int *cantidad_pacientes,Paciente paciente);
int filtrar(Paciente *pacientes, int cantidad_pacientes, char **obras_sociales, int cantidad_obras_sociales, char *nombre_archivo);
int cargar_info_estructura_paciente(Paciente *ptr);
void Imprimir_array(Paciente *pacientes, int cantidad_pacientes);
void Menu(void);
int Menu_Recursivo( int argc, char **argv, char *nombre_archivo);


int main( int argc, char **argv )
{
    if( argc <= 2)
    {
        printf("Faltan argumentos. Re-ejecute el programa tal que ingresa los argumentos como sigue: <nombre ejecutable.out> <nombre archivo.bin> <nombre obra social 1> .......<nombre obra social n>\n");
        return ERROR;
    }
    char nombre_archivo[strlen(argv[1])+1];
    char formato[] = ".txt";
    memset(nombre_archivo, 0, sizeof(nombre_archivo));
    strncpy(nombre_archivo, argv[1], strlen(argv[1])-4);
    strcat(nombre_archivo, formato);
    printf("El nombre del archivo de salida queda como: %s\n", nombre_archivo);
    int checkFinal;
    checkFinal = Menu_Recursivo(argc,argv,nombre_archivo);
    if(checkFinal == ERROR)
        return ERROR;
    else
    {
        printf("Se ha liberado la memoria dimaica y los recursos correctamente\n");
        return EXITO;
    }
}



int arreglar(Paciente **pacientes, int *cantidad_pacientes,Paciente paciente)
{
    //Pido memoria dinamica para realocalizar un array dinamico de estructuras tipo[] "Paciente". Se iran agregando de a 1 elemento a la vez en la COLA segun las veces que se llame a la funcion "arreglar"
    *pacientes = (Paciente *)reallocarray(*pacientes, *cantidad_pacientes, sizeof(paciente));
    //Verifico si hay error o no segun lo devuelto por "reallocarray". Si reallocarray devuelve NULL, salgo del programa. Sino asigno a *pacientes la direccion de comienzo del bloque de memoria de estructras realocalizado. Lo que sera en realidad un array dinamico de estructuras
    if( *pacientes == NULL )
    {
        printf("Hubo un error en la funcion arreglar. No se pudo agregar un elemento a la COLA O ARRAY DINAMICO\n");
        return ERROR;
    }
    //printf("Se llego a la linea 95\n");
    //Le asigno al ultimo elemento del array creado, una estructura del tipo "Paciente" con los datos ya pre-cargados
    (*pacientes)[(*cantidad_pacientes)-1] = paciente;

    return EXITO;
}

int filtrar(Paciente *pacientes, int cantidad_pacientes, char **obras_sociales, int cantidad_obras_sociales, char *nombre_archivo)
{
    //Declaracion de variables
    int i, j, count = 0;
    FILE *File_out = NULL;
    //Abro un archivo de salida con permisos de escritura y verifico error
    File_out = fopen(nombre_archivo, "w");
    if( File_out == NULL )
        return ERROR;
    //Recorro un array dinamico de estructuras del tipo "Paciente" con un 1er for.
    for( i = 0; i < cantidad_pacientes; i++ )
    {
        //Para cada elemento del array osea para cada estructura recorro con un 2do for, el listado de strings asociados a obras sociales ingresadas por teclado.
        for( j = 0; j < cantidad_obras_sociales; j++ )
        {
            //Realizo una comparacion entre el string almacenado en campo "nombre" de la estructura respecto al string correspondiente de la lista de strings ingresada por teclado. En caso de que ambos strings coincidan, entonces "se filtra" la estructura del paciente asociada y se imprimen los datos de la misma en un archivo de salida .txt. Ademas por aca filtracion lograda, se aumenta un contador
            if( strcasecmp(pacientes[i].obra_social, obras_sociales[j+2]) == 0 )
            {
                fprintf(File_out,"%s,%d,%s\n", pacientes[i].nombre, pacientes[i].edad, pacientes[i].obra_social);
                count++;
            }
        }
    }

    return count;
}


int cargar_info_estructura_paciente(Paciente *ptr)
{
    printf("Ingrese el nombre del paciente: ");
    /* Obtengo el nombre del paciente a traves del buffer de entrada con un limite maximo de caracteres como proteccion contra overflow */
    fgets(ptr->nombre,30,stdin);
    /* Elimino del array "nombre" el caracter de "\n" si es que se ingreso */
    if ((strlen(ptr->nombre) > 0) && (ptr->nombre[strlen(ptr->nombre) - 1] == '\n'))
        ptr->nombre[strlen(ptr->nombre) - 1] = '\0';

    /* Obtengo la edad del paciente*/
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &ptr->edad);
    __fpurge(stdin);

    printf("Ingrese la obra social del paciente: ");
    /* Obtengo el nombre de la obra social a traves del buffer de entrada con un limite maximo de caracteres como proteccion contra overflow */
    fgets(ptr->obra_social,30,stdin);
    /* Elimino del array "obra_social" el caracter de "\n" si es que se ingreso */
    if ((strlen(ptr->obra_social) > 0) && (ptr->obra_social[strlen(ptr->obra_social) - 1] == '\n'))
        ptr->obra_social[strlen(ptr->obra_social) - 1] = '\0';

    return EXITO;
}

void Imprimir_array(Paciente *pacientes, int cantidad_pacientes)
{
    int i;
    for(i = 0; i < cantidad_pacientes; i ++)
    {
        printf("Nombre del paciente: %s\n", pacientes[i].nombre);
        printf("Edad del paciente: %d\n", pacientes[i].edad);
        printf("Obra social: %s\n", pacientes[i].obra_social);
    }
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

int Menu_Recursivo(int argc, char **argv, char *nombre_archivo)
{
    int check = 0, opcion, count = 0, cant_pacientes_filtrados = 0;
    Paciente *ptrArrayDin = NULL;
    Paciente var1;
    Menu();
    while( (opcion = getc(stdin)) != EOF )
    {
        __fpurge(stdin);
        switch(opcion)
        {
            case '1':
                check = cargar_info_estructura_paciente(&var1);
                if( check != EXITO)
                {
                    printf("Hubo un error con la carga de info del paciente. Usted saldra del programa\n");
                    return ERROR;
                }
                count++;
                printf("count vale %d\n", count);
                check = arreglar(&ptrArrayDin, &count,var1);
                if( check == ERROR ) return ERROR;
                break;
            case '2':
                Imprimir_array(ptrArrayDin, count);
                break;
            case '3':
                cant_pacientes_filtrados = filtrar(ptrArrayDin, count, argv, argc-2,nombre_archivo);
                printf("Se escribieron en un .txt y filtraron %d pacientes\n", cant_pacientes_filtrados);
                break;
            case '\n': case ' ':
                break;
            default:
                printf("Ha ingresado mal una opcion. Vuelva a intetarlo\n");
                break;
        }
         Menu();
    }
    free(ptrArrayDin);
    return EXITO;
}
