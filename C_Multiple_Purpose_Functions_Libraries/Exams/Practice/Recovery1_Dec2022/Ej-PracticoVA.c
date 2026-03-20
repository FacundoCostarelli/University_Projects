/**
 * @file    Ej-PracticoVA.c
 * @brief   [ESP] Práctica Recuperatorio 1 Dic 2022 (Variante A): Fila de pacientes por obra social.
 *          [ENG] Recovery 1 Practice Dec 2022 (Variant A): Patients queue by health insurance.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

#define EXITO 0
#define ERROR -1

/**
 * @brief [ESP] Estructura de Paciente.
 *        [ENG] Patient structure.
 */
typedef struct Paciente
{
    char nombre[30];
    int edad;
    char obra_social[30];
} Paciente;

/**
 * @brief [ESP] Estructura Nodo de una cola enlazada.
 *        [ENG] Node structure of a linked queue.
 */
typedef struct Nodo
{
    Paciente paciente;
    struct Nodo *siguiente;
} Nodo;

/**
 * @brief [ESP] Encola un nuevo nodo paciente.
 *        [ENG] Enqueues a new patient node.
 */
int encolar(Nodo **cola_pacientes, Paciente paciente);

/**
 * @brief [ESP] Carga por teclado la información de un paciente.
 *        [ENG] Keyboard input for patient info.
 */
int cargar_info_estructura_paciente(Paciente **ptr);

/**
 * @brief [ESP] Imprime la cola de pacientes.
 *        [ENG] Prints the queue of patients.
 */
void imprimir_cola(Nodo **cola_pacientes);

/**
 * @brief [ESP] Libera la memoria alojada en la cola.
 *        [ENG] Frees queue allocated memory.
 */
void liberar_memoria_cola(Nodo **cola_pacientes);

/**
 * @brief [ESP] Filtra pacientes y genera un archivo CSV.
 *        [ENG] Filters patients and generates CSV file.
 */
int filtrar(Nodo *cola_pacientes, char **obras_sociales, int cantidad_obras_sociales, char *nombre_archivo);

/**
 * @brief [ESP] Muestra el menú de opciones.
 *        [ENG] Shows options menu.
 */
void Menu(void);

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main(int argc, char **argv)
{
    if( argc <= 2)
    {
        printf("Faltan argumentos. \nUso: <ejecutable> <archivo.bin/txt> <obrasocial1> ... <obrasocialN>\n");
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
    printf("Archivo de salida: %s\n", nombre_archivo);

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
                    printf("Error con la carga\n");
                    return ERROR;
                }
                
                check = encolar(&ptr_1erNodo, *ptr);
                if( check == ERROR )
                {
                    printf("Error memoria\n");
                    return ERROR;
                }
                count++;
                free(ptr); // [ESP] Liberar el puntero despues de copiar el valor / [ENG] Free pointer after copy value
                Menu();
                break;

            case '2':
                if( count == 0 )
                    printf("No hay pacientes\n");
                else
                    imprimir_cola(&ptr_1erNodo);
                Menu();
                break;

            case '3':
                if( count == 0 )
                    printf("No hay pacientes\n");
                else
                {
                    check = filtrar(ptr_1erNodo, argv, argc-2, argv[1] );
                    if( check == ERROR )
                        return ERROR;
                }
                Menu();
                break;

            case '\n' : case ' ': 
                break;

            default:
                printf("Error\n");
                Menu();
                break;
        }
    }

    liberar_memoria_cola(&ptr_1erNodo);
    printf("Programa finalizado.\n");
    return EXITO;
}

void Menu(void)
{
    printf("Menu principal:\n");
    printf("1. Agregar un nuevo paciente\n");
    printf("2. Imprimir todos los pacientes\n");
    printf("3. Generar archivo de texto CSV filtrados\n");
}

int encolar(Nodo ** cola_pacientes, Paciente paciente) 
{
    Nodo *Nuevo_Nodo = (Nodo *)malloc(sizeof(Nodo));
    Nodo *Nodo_actual = *cola_pacientes;

    if( Nuevo_Nodo == NULL ) return ERROR;

    Nuevo_Nodo->siguiente = NULL;
    Nuevo_Nodo->paciente = paciente;

    if( Nodo_actual == NULL )
    {
        *cola_pacientes = Nuevo_Nodo;
        return EXITO;
    }
    else
    {
        while( Nodo_actual->siguiente != NULL )
            Nodo_actual = Nodo_actual->siguiente;

        Nodo_actual->siguiente = Nuevo_Nodo;
        return EXITO;
    }
}

int cargar_info_estructura_paciente(Paciente **ptr)
{
    *ptr = (Paciente *)malloc(sizeof(Paciente));
    if( *ptr == NULL ) return ERROR;

    printf("Nombre: ");
    fgets((*ptr)->nombre,30,stdin);
    if ((strlen((*ptr)->nombre) > 0) && ((*ptr)->nombre[strlen((*ptr)->nombre) - 1] == '\n'))
        (*ptr)->nombre[strlen((*ptr)->nombre) - 1] = '\0';

    printf("Edad: ");
    scanf("%d", &(*ptr)->edad);
    __fpurge(stdin);

    printf("Obra social: ");
    fgets((*ptr)->obra_social,30,stdin);
    if ((strlen((*ptr)->obra_social) > 0) && ((*ptr)->obra_social[strlen((*ptr)->obra_social) - 1] == '\n'))
        (*ptr)->obra_social[strlen((*ptr)->obra_social) - 1] = '\0';

    return EXITO;
}

void imprimir_cola(Nodo **cola_pacientes)
{
    Nodo *Nodo_actual = *cola_pacientes;
    while( Nodo_actual != NULL )
    {
        printf("Nombre: %s\nEdad: %d\nObra: %s\n\n", Nodo_actual->paciente.nombre, Nodo_actual->paciente.edad, Nodo_actual->paciente.obra_social);
        Nodo_actual = Nodo_actual->siguiente;
    }
}

void liberar_memoria_cola(Nodo **cola_pacientes)
{
    Nodo *Nodo_actual = *cola_pacientes;
    Nodo *aux = *cola_pacientes;

    if (Nodo_actual == NULL) return;

    do
    {
        Nodo_actual = Nodo_actual->siguiente;
        free(aux);
        aux = Nodo_actual;
    } while( Nodo_actual != NULL );
}

int filtrar(Nodo *cola_pacientes, char **obras_sociales, int cantidad_obras_sociales, char *nombre_archivo)
{
    Nodo *Nodo_actual =  cola_pacientes;
    FILE *File_out = NULL;
    int i;

    File_out = fopen(nombre_archivo,"wt");
    if( File_out == NULL ) return ERROR;

    while( Nodo_actual != NULL )
    {
        for( i = 0; i < cantidad_obras_sociales; i ++ )
        {
            if( strcasecmp( Nodo_actual->paciente.obra_social, obras_sociales[i+2] ) == 0 )
            {
                fprintf(File_out,"%s,%d,%s\n", Nodo_actual->paciente.nombre, Nodo_actual->paciente.edad, Nodo_actual->paciente.obra_social);
            }
        }
        Nodo_actual = Nodo_actual->siguiente;
    }
    
    fclose(File_out);
    return EXITO;
}
