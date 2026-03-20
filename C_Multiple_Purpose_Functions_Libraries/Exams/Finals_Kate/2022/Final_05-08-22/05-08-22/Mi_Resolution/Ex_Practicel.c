/**
 * @file    Ej-Practico.c
 * @brief   [ESP] Ejercicio Práctico - Final 05-08-2022. Encriptación (Mi resolución).
 *          [ENG] Practical Exercise - Final 05-08-2022. Encryption (My resolution).
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<time.h>

#define TXT_MAX_LEN 20

/**
 * @brief [ESP] Estructura para el texto encriptado.
 *        [ENG] Structure for encrypted text.
 */
struct st_texto_encriptado
{
    char txt[TXT_MAX_LEN];
    int desplazamiento;
};

/**
 * @brief [ESP] Funciones de encriptación y aleatoriedad.
 *        [ENG] Encryption and randomness functions.
 */
int encriptar(const char *src , char * dst);
int encriptar_letras(const char *src , char *dst);
void encriptar_numeros ( const char *src , char *dst);
int aleatorio_en_rango(int minimo, int maximo);

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main(int argc, char**argv)
{
    struct st_texto_encriptado var1;
    FILE *File_out = NULL;
    
    if( argc != 3 )
    {
        printf("Uso: <ejectuable> <nombre_archivo_de_salida.txt> <texto a encriptar>\n");
        return -1;
    }
    
    srand(time(NULL));

    /* [ESP] Llamada a encriptado general / [ENG] General encryption call */
    printf("El txt ingresado a encriptar fue %s y tiene %ld caracteres\n", argv[2], strlen(argv[2]));
    var1.desplazamiento = encriptar(argv[2], var1.txt);
    printf("El texto ingresado queda encriptado como %s\n", var1.txt);

    /* [ESP] Apertura de archivo y guardado del encriptado / [ENG] File open and save encryption */
    File_out = fopen(argv[1], "at");
    if(File_out == NULL) return -1;

    fprintf(File_out, "%s\n", var1.txt);
    fclose(File_out);

    return 0;
}

/**
 * @brief [ESP] Proceso general de encriptar letras y numeros.
 *        [ENG] General process of encrypting letters and numbers.
 */
int encriptar(const char *src , char * dst)
{
    char auxiliar[TXT_MAX_LEN];
    char array_final[TXT_MAX_LEN];
    int codigo;
    
    memset(array_final, 0, sizeof(array_final));
    codigo = encriptar_letras(src, auxiliar);
    encriptar_numeros(auxiliar, array_final);
    strcpy(dst, array_final);

    return codigo;
}

/**
 * @brief [ESP] Cifrado de letras tipo Caesar usando un número aleatorio a modo de desplazamiento.
 *        [ENG] Caesar-like cipher for letters using a random number for shifted positions.
 */
int encriptar_letras(const char *src , char * dst)
{
    int minimo = 1, maximo = 25;
    int nro_desplazamiento_alfabetico = aleatorio_en_rango(minimo, maximo);
    int k;
    
    printf("El numero de nro_desplazamiento_alfabetico es %d\n", nro_desplazamiento_alfabetico);

    for( k = 0; k < strlen(src); k++ )
    {
            if( src[k] >= 'A' && src[k] <= 'Z' )
            {
                dst[k] = src[k] + nro_desplazamiento_alfabetico;
                if( dst[k] > 'Z')
                    dst[k] = 'A' + (dst[k]-'Z'-1);
            }
            else
                dst[k] = src[k];
    }
    dst[k] = '\0';

    return nro_desplazamiento_alfabetico;
}

/**
 * @brief [ESP] Encriptación de digitos numéricos del string, transformándolos a octal y con símbolos prefijados.
 *        [ENG] Encryption of numeric digits on string, transformed to octal with prefixed symbols.
 */
void encriptar_numeros(const char *src, char *dst)
{
    int valor_decimal, count = 1;
    char *Fin_Cadena_Numerica = NULL;
    char array_aux[13]; 
    int k = 0, i;
    
    memset(array_aux, 0, sizeof(array_aux));
    array_aux[k] = '#';

    for(i = 0; i < strlen(src); i++)
    {
        if(count == 1)
        {
            if( (src[i] >= 'A' && src[i] <= 'Z') || src[i] == ' ' )
            {
                if(dst[i] != '\0')
                    dst[i+2] = src[i];
                else
                    dst[i] = src[i];
            }
            else
            {
                valor_decimal = (int)strtol(&src[i], &Fin_Cadena_Numerica, 10);
                if(valor_decimal == 0) printf("No hay digitos para convertir\n");
                
                sprintf(array_aux+1, "%o", valor_decimal);
                
                for( k = 1; k < strlen(array_aux); k++)
                {
                    if(array_aux[k] == '0') array_aux[k] = '$';
                    if(array_aux[k] == '1') array_aux[k] = '%';
                    if(array_aux[k] == '2') array_aux[k] = '&';
                    if(array_aux[k] == '3') array_aux[k] = '*';
                    if(array_aux[k] == '4') array_aux[k] = '@';
                    if(array_aux[k] == '5') array_aux[k] = '!';
                    if(array_aux[k] == '6') array_aux[k] = '+';
                    if(array_aux[k] == '7') array_aux[k] = '=';
                }
                
                array_aux[k] = '#';
                count = strlen(array_aux) - 2;
                strcpy(&dst[i], array_aux);
            }
        }
        else
        {
            count--;
        }
    }
}

/**
 * @brief [ESP] Obtiene un valor aleatorio entre mínimo y máximo incluido. 
 *        [ENG] Gets random value between min and max included.
 */
int aleatorio_en_rango(int minimo, int maximo)
{
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
