/**
 * @file    Ej-PracticoVB.c
 * @brief   [ESP] Práctica Recuperatorio 1 Dic 2022 (Variante B): Array dinámico de pacientes.
 *          [ENG] Recovery 1 Practice Dec 2022 (Variant B): Dynamic array of patients.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

#define ERROR -1
#define EXITO 0

/**
 * @brief [ESP] Estructura de Paciente.
 *        [ENG] Patient structure.
 */
typedef struct paciente
{
    char nombre[30];
    int edad;
    char obra_social[30];
} Paciente;

/**
 * @brief [ESP] Agranda el array dinámico.
 *        [ENG] Extends the dynamic array.
 */
int arreglar(Paciente **pacientes, int *cantidad_pacientes,Paciente paciente);

/**
 * @brief [ESP] Filtra e imprime en un archivo CSV.
 *        [ENG] Filters and prints in a CSV file.
 */
int filtrar(Paciente *pacientes, int cantidad_pacientes, char **obras_sociales, int cantidad_obras_sociales, char *nombre_archivo);

/**
 * @brief [ESP] Solicita info de teclado.
 *        [ENG] Request info by keyboard.
 */
int cargar_info_estructura_paciente(Paciente *ptr);

/**
 * @brief [ESP] Imprime arreglo en pantalla.
 *        [ENG] Prints array on screen.
 */
void Imprimir_array(Paciente *pacientes, int cantidad_pacientes);

/**
 * @brief [ESP] Despliega el menu principal.
 *        [ENG] Deploys the main menu.
 */
void Menu(void);

/**
 * @brief [ESP] Ciclo de menu recursivo.
 *        [ENG] Recursive menu loop.
 */
int Menu_Recursivo( int argc, char **argv, char *nombre_archivo);

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main( int argc, char **argv )
{
    if( argc <= 2)
    {
        printf("Faltan argumentos. \nUso: <ejecutable> <archivo> <obra1> ... <obraN>\n");
        return ERROR;
    }
    
    char nombre_archivo[strlen(argv[1])+1];
    char formato[] = ".txt";
    memset(nombre_archivo, 0, sizeof(nombre_archivo));
    strncpy(nombre_archivo, argv[1], strlen(argv[1])-4);
    strcat(nombre_archivo, formato);
    
    printf("Archivo salida: %s\n", nombre_archivo);
    
    int checkFinal;
    checkFinal = Menu_Recursivo(argc,argv,nombre_archivo);
    if(checkFinal == ERROR)
        return ERROR;
    else
    {
        printf("Finalizado con exito.\n");
        return EXITO;
    }
}

int arreglar(Paciente **pacientes, int *cantidad_pacientes,Paciente paciente)
{
    /* [ESP] Realocamos memoria. / [ENG] We reallocate memory. */
    *pacientes = (Paciente *)reallocarray(*pacientes, *cantidad_pacientes, sizeof(paciente));
    if( *pacientes == NULL )
        return ERROR;

    (*pacientes)[(*cantidad_pacientes)-1] = paciente;
    return EXITO;
}

int filtrar(Paciente *pacientes, int cantidad_pacientes, char **obras_sociales, int cantidad_obras_sociales, char *nombre_archivo)
{
    int i, j, count = 0;
    FILE *File_out = NULL;
    
    File_out = fopen(nombre_archivo, "w");
    if( File_out == NULL ) return ERROR;
    
    for( i = 0; i < cantidad_pacientes; i++ )
    {
        for( j = 0; j < cantidad_obras_sociales; j++ )
        {
            if( strcasecmp(pacientes[i].obra_social, obras_sociales[j+2]) == 0 )
            {
                fprintf(File_out,"%s,%d,%s\n", pacientes[i].nombre, pacientes[i].edad, pacientes[i].obra_social);
                count++;
            }
        }
    }
    fclose(File_out);
    return count;
}

int cargar_info_estructura_paciente(Paciente *ptr)
{
    printf("Ingrese nombre: ");
    fgets(ptr->nombre,30,stdin);
    if ((strlen(ptr->nombre) > 0) && (ptr->nombre[strlen(ptr->nombre) - 1] == '\n'))
        ptr->nombre[strlen(ptr->nombre) - 1] = '\0';

    printf("Ingrese edad: ");
    scanf("%d", &ptr->edad);
    __fpurge(stdin);

    printf("Ingrese obra social: ");
    fgets(ptr->obra_social,30,stdin);
    if ((strlen(ptr->obra_social) > 0) && (ptr->obra_social[strlen(ptr->obra_social) - 1] == '\n'))
        ptr->obra_social[strlen(ptr->obra_social) - 1] = '\0';

    return EXITO;
}

void Imprimir_array(Paciente *pacientes, int cantidad_pacientes)
{
    int i;
    for(i = 0; i < cantidad_pacientes; i ++)
    {
        printf("Nombre: %s, Edad: %d, Obra Social: %s\n", pacientes[i].nombre, pacientes[i].edad, pacientes[i].obra_social);
    }
}

void Menu(void)
{
    printf("1. Agregar un nuevo paciente\n");
    printf("2. Imprimir todos los pacientes\n");
    printf("3. Archivo filtrados\n");
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
                if( check != EXITO) return ERROR;
                count++;
                check = arreglar(&ptrArrayDin, &count,var1);
                if( check == ERROR ) return ERROR;
                break;
            case '2':
                Imprimir_array(ptrArrayDin, count);
                break;
            case '3':
                cant_pacientes_filtrados = filtrar(ptrArrayDin, count, argv, argc-2,nombre_archivo);
                printf("Filtrados %d pacientes\n", cant_pacientes_filtrados);
                break;
            case '\n': case ' ':
                break;
            default:
                break;
        }
        Menu();
    }
    free(ptrArrayDin);
    return EXITO;
}
