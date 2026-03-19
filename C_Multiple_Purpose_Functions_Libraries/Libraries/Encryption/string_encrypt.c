/**
 * @file    string_encrypt.c
 * @brief   [ESP] Implementación de funciones de encriptación de strings.
 *          [ENG] Implementation of string encryption functions.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "string_encrypt.h"

/**
 * @brief [ESP] Genera un número aleatorio entero dentro de un rango inclusivo.
 *        [ENG] Generates a random integer within an inclusive range.
 */
int aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

/**
 * @brief [ESP] Encripta letras mayúsculas con un desplazamiento César aleatorio.
 *        [ENG] Encrypts uppercase letters with a random Caesar shift.
 */
int encriptar_letras(const char *src, char *dst)
{
    /* [ESP] Generar un desplazamiento aleatorio entre 1 y 25 posiciones
       [ENG] Generate a random shift between 1 and 25 positions */
    int desplazamiento_alfabetico = aleatorio_en_rango(1, 25);
    int desplazamiento_adicional = 0;
    size_t i = 0;

    for (i = 0; i < strlen(src); i++)
    {
        /* [ESP] Si el carácter es un espacio, dígito o '#', se copia sin cambios
           [ENG] If the character is a space, digit, or '#', copy it unchanged */
        if (src[i] == ' ' || (src[i] >= '0' && src[i] <= '9') || src[i] == '#')
        {
            dst[i] = src[i];
        }
        else
        {
            /* [ESP] Si el desplazamiento supera 'Z', hacemos wrap-around a 'A'.
                     Ej: 'Y' + 3 = 'Y'(89) + 3 = 92 > 'Z'(90), excedente = 2 → 'B'
               [ENG] If the shift exceeds 'Z', we wrap around to 'A'.
                     E.g.: 'Y' + 3 = 'Y'(89) + 3 = 92 > 'Z'(90), excess = 2 → 'B' */
            if (src[i] + desplazamiento_alfabetico > 'Z')
            {
                desplazamiento_adicional = (src[i] + desplazamiento_alfabetico) - 'Z';
                dst[i] = 'A' + (desplazamiento_adicional - 1);
            }
            else
            {
                /* [ESP] Desplazamiento directo sin overflow
                   [ENG] Direct shift without overflow */
                dst[i] = src[i] + desplazamiento_alfabetico;
            }
        }
    }

    /* [ESP] Terminamos el string destino con '\0'
       [ENG] Null-terminate the destination string */
    dst[i] = '\0';

    return desplazamiento_alfabetico;
}

/**
 * @brief [ESP] Encripta dígitos numéricos sustituyéndolos por símbolos.
 *        [ENG] Encrypts numeric digits by substituting them with symbols.
 *
 * [ESP] Tabla de sustitución (dígito octal → símbolo):
 *       0→$  1→%  2→&  3→*  4→@  5→!  6→+  7→=
 * [ENG] Substitution table (octal digit → symbol):
 *       0→$  1→%  2→&  3→*  4→@  5→!  6→+  7→=
 */
void encriptar_numeros(char *src, char *dst)
{
    size_t i = 0, j = 0, k = 0;

    /* [ESP] Buffer auxiliar para almacenar el valor octal como string
       [ENG] Auxiliary buffer to store the octal value as a string */
    char buffer_aux[TXT_MAX_LEN];
    int valor_decimal_IN = 0;
    char *Fin_Cadena_Numerica = NULL;

    for (i = 0; i < strlen(src); i++)
    {
        /* [ESP] Detectamos si el carácter actual es un dígito (0–9)
           [ENG] Detect if the current character is a digit (0–9) */
        if (src[i] >= '0' && src[i] <= '9')
        {
            /* [ESP] Limpiar buffer auxiliar
               [ENG] Clear auxiliary buffer */
            for (k = 0; k < TXT_MAX_LEN; k++)
                buffer_aux[k] = '\0';

            /* [ESP] Convertir la secuencia de dígitos a entero decimal con strtol().
                     &src[i] apunta al primer dígito de la secuencia.
                     Fin_Cadena_Numerica recibirá la dirección del primer no-dígito.
               [ENG] Convert the digit sequence to decimal integer with strtol().
                     &src[i] points to the first digit of the sequence.
                     Fin_Cadena_Numerica will receive the address of the first non-digit. */
            valor_decimal_IN = (int)strtol(&src[i], &Fin_Cadena_Numerica, 10);

            /* [ESP] Convertir el entero decimal a string octal con sprintf()
               [ENG] Convert the decimal integer to octal string with sprintf() */
            sprintf(buffer_aux, "%o", valor_decimal_IN);

            /* [ESP] Escribir '#' como delimitador de inicio de sección encriptada
               [ENG] Write '#' as the opening delimiter of the encrypted section */
            j = i;
            dst[j] = '#';
            j++;

            /* [ESP] Sustituir cada dígito octal por su símbolo correspondiente.
                     La tabla de sustitución define un carácter único para cada dígito.
               [ENG] Substitute each octal digit with its corresponding symbol.
                     The substitution table defines a unique character for each digit. */
            for (k = 0; k < strlen(buffer_aux); k++)
            {
                switch (buffer_aux[k])
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

            /* [ESP] Escribir '#' como delimitador de fin de sección encriptada
               [ENG] Write '#' as the closing delimiter of the encrypted section */
            dst[j] = '#';

            /* [ESP] Avanzar el índice 'i' para saltar los dígitos ya procesados.
                     Buscamos el próximo carácter que no sea dígito.
               [ENG] Advance index 'i' to skip already processed digits.
                     We look for the next non-digit character. */
            for ( ; src[i] >= '0' && src[i] <= '9'; i++);
            i++;
        }
        else
        {
            /* [ESP] Para caracteres no-dígito: copiar directamente al destino.
                     Se maneja el caso especial cuando el carácter anterior era '#'.
               [ENG] For non-digit characters: copy directly to destination.
                     Special case is handled when the previous character was '#'. */
            if (i > 0 && dst[i - 1] == '#')
            {
                for (k = 0; k < TXT_MAX_LEN; k++)
                    buffer_aux[k] = '\0';

                j = i - 2;
                for (k = 0; src[j] >= 'A' && src[j] <= 'Z'; k++, j++)
                    buffer_aux[k] = src[j];

                strcat(dst, buffer_aux);
            }
            else
            {
                dst[i] = src[i];
            }
        }
    }

    return;
}
