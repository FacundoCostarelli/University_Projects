/**
 * @file    Funciones.c
 * @brief   [ESP] Archivo fuente de resolución de encriptación Cesar. Final 08/2022.
 *          [ENG] Cesar encryption computations resolution source file. Final 08/2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Encripta una cadena alfabética usando un desplazamiento (Shift) aleatorio.
 *        [ENG] Encrypts an alphabetical string applying a pseudo-random shift.
 *
 * @note  [ESP] Asume cadena de entrada en MAYÚSCULAS y buffer reservado / [ENG] Assumes UPPERCASE incoming string and allocated buffer
 * @param src [ESP] Cadena alfabética de origen / [ENG] Source alphabetical string 
 * @param dst [ESP] Búfer de caracteres destino / [ENG] Destination characters buffer 
 * @return int [ESP] Valor de desplazamiento aplicado / [ENG] Cypher applied shift value
 */
int encriptar_letras(const char *src, char *dst)
{
    int desplazamiento_alfabetico = aleatorio_en_rango(1, 25);
    int desplazamiento_adicional = 0;
    size_t i = 0;

    for( i = 0; i < strlen(src); i++ )
    {
        if(src[i] == ' ' || ( (src[i] >= '0' && src[i] <= '9') || src[i] == '#' ))
        {
            dst[i] = src[i];
        }
        else
        {
            if(src[i] + desplazamiento_alfabetico > 'Z')
            {
                desplazamiento_adicional = (src[i] + desplazamiento_alfabetico) - 'Z';
                dst[i] = 'A' + (desplazamiento_adicional - 1);
            }
            else
            {
                dst[i] = src[i] + desplazamiento_alfabetico;
            }
        }
    }
    dst[i] = '\0';
    return desplazamiento_alfabetico;
}

/**
 * @brief [ESP] Generador de un número int pseudo-aleatorio en un rango cerrado.
 *        [ENG] Pseudo-random integer generator wrapper setting limits.
 */
int aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

/**
 * @brief [ESP] Encripta secuencias numéricas a símbolos después de convertirlas a octal.
 *        [ENG] Encrypts numeric sequences into symbols after casting them as octal strings.
 *
 * @note  [ESP] Funciona excepto para algunos bordes (letra-digito-letra-digito) / [ENG] Might fail on complex letter-digit-letter alternations
 */
void encriptar_numeros(char *src, char *dst)
{
    size_t i = 0, j = 0, k = 0;
    char buffer_aux[TXT_MAX_LEN];
    int valor_decimal_IN = 0;
    char *Fin_Cadena_Numerica = NULL;
    dst[0] = '\0';

    for( i = 0; i < strlen(src); i++ )
    {
        if( (src[i] >= '0' && src[i] <= '9') )
        {
            for( k = 0; k < TXT_MAX_LEN; k++ )
                buffer_aux[k] = '\0';

            /* [ESP] Convierte valor en sub-cadena a entero / [ENG] Transform sub-str char block to integer */
            valor_decimal_IN = (int)strtol(&src[i], &Fin_Cadena_Numerica, 10);
            if(valor_decimal_IN == 0) printf("No hay digitos en formato string para convertir\n");

            /* [ESP] Convierte int decimal a formato char octal / [ENG] Cast decimal int to char octal formatting */
            sprintf(buffer_aux, "%o", valor_decimal_IN);
            printf("El valor entero a numero octal con sprintf queda como %s\n", buffer_aux);

            j = strlen(dst);
            dst[j] = '#';
            j++;

            for( k = 0; k < strlen(buffer_aux); k++ )
            {
                switch( buffer_aux[k] )
                {
                case '0': dst[j] = '$'; j++; break;
                case '1': dst[j] = '%'; j++; break;
                case '2': dst[j] = '&'; j++; break;
                case '3': dst[j] = '*'; j++; break;
                case '4': dst[j] = '@'; j++; break;
                case '5': dst[j] = '!'; j++; break;
                case '6': dst[j] = '+'; j++; break;
                case '7': dst[j] = '='; j++; break;
                default: break;
                }
            }
            dst[j] =  '#';
            dst[j+1] = '\0';
            printf("Valor de j %lu\n", j);
            printf("Encriptacion en funcion encriptar_numeros %s\n", dst);

            for( ; src[i] >= '0' && src[i] <= '9'; i++);

            if (src[i] == '\0') break;
            i--; 
        }
        else
        {
           size_t len_dst = strlen(dst);
           if(len_dst > 0 && dst[len_dst-1] == '#')
           {
               for( k = 0; k < TXT_MAX_LEN; k++ )
                   buffer_aux[k] = '\0';

               size_t p = i;
               for(k = 0 ; src[p] >= 'A' && src[p] <= 'Z'; k++, p++)
                    buffer_aux[k] = src[p];

               strcat(dst, buffer_aux);
               i = p - 1; 
           }
           else
           {
               len_dst = strlen(dst);
               dst[len_dst] = src[i];
               dst[len_dst+1] = '\0';
           }
        }
    }
}

/**
 * @brief [ESP] Invierte el contenido de una cadena.
 *        [ENG] Reverses the char-string payload natively.
 */
void revertir(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

/**
 * @brief [ESP] Función para escribir enteros a formato string basado en una base radical dada (ej: octal, hex).
 *        [ENG] Converts integers into strings bound to specific bases natively.
 */
char* IntToAnString(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';
    revertir(str, i);

    return str;
}
