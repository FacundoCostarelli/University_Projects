/**
 * ==========================================================================
 * my_strings.c — Custom String Functions Library (Implementation)
 * ==========================================================================
 * [ESP] Implementación de funciones personalizadas de manejo de strings.
 *       Incluye funciones de copia, longitud, concatenación, comparación,
 *       memset, reversión, palíndromos, cambio de caso y ordenamiento.
 *
 * [ENG] Implementation of custom string manipulation functions.
 *       Includes copy, length, concatenation, comparison, memset,
 *       reversal, palindrome check, case conversion, and sorting.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#include"my_strings.h"

/**
 * [ESP] Función strcpy propia con la técnica de contadores.
 *       Copia el string Origen en Destino carácter a carácter usando un índice.
 * [ENG] Custom strcpy using counter technique.
 *       Copies the Origin string into Destination character by character using an index.
 */
char *Mi_StringCopyV1(char *Destino, const char *Origen)
{
    // [ESP] Verifico si Destino apunta a NULL (puntero inválido o memoria no alocada)
    // [ENG] Check if Destination points to NULL (invalid pointer or unallocated memory)
    if( Destino == NULL)
        return NULL;

    // [ESP] Algoritmo de copia con contador: por cada iteración, se copia un carácter
    //       hasta encontrar el carácter NULL ('\0')
    // [ENG] Counter-based copy algorithm: copies one character per iteration
    //       until the NULL character ('\0') is found
    int i = 0;
    while(Origen[i] != '\0')
    {
        Destino[i] = Origen[i]; // [ESP] Copiado de carácter / [ENG] Character copy
        i++;                     // [ESP] Contador / [ENG] Counter
    }

    // [ESP] Agrego el carácter '\0' en la última posición
    // [ENG] Append the '\0' character at the last position
    Destino[i] = '\0';

    // [ESP] Retorno el puntero al primer elemento del array Destino
    // [ENG] Return the pointer to the first element of the Destination array
    return Destino;

}

/**
 * [ESP] Función strcpy propia con aritmética de punteros.
 *       Copia el string Origen en Destino usando incremento de punteros.
 * [ENG] Custom strcpy using pointer arithmetic.
 *       Copies the Origin string into Destination using pointer increments.
 */
char *Mi_StringCopyV2(char *Destino, const char *Origen)
{
    // [ESP] Verifico si Destino apunta a NULL (puntero inválido o memoria no alocada)
    // [ENG] Check if Destination points to NULL (invalid pointer or unallocated memory)
    if( Destino == NULL)
        return NULL;

    // [ESP] Algoritmo de copia con aritmética de punteros
    // [ENG] Pointer arithmetic copy algorithm
    char *Destino_ptr_1er_elemento = Destino;
    while( *Origen != '\0' )
    {
        *Destino = *Origen; // [ESP] Copiado de carácter / [ENG] Character copy
        Destino++;          // [ESP] Avanzo al siguiente byte en Destino / [ENG] Move to next byte in Destination
        Origen++;           // [ESP] Avanzo al siguiente byte en Origen / [ENG] Move to next byte in Origin
    }

    // [ESP] Agrego el carácter '\0' al final
    // [ENG] Append the '\0' character at the end
    *Destino = '\0';

    // [ESP] Retorno el puntero al primer elemento del array Destino
    // [ENG] Return the pointer to the first element of the Destination array
    return Destino_ptr_1er_elemento;

}

/**
 * [ESP] Calcula el largo de un string sin contar el carácter '\0'.
 * [ENG] Calculates the length of a string excluding the '\0' character.
 */
int Mi_StringLength(char *String)
{
    // [ESP] Verifico si String apunta a NULL
    // [ENG] Check if String points to NULL
    if( String == NULL)
        return 0;

    // [ESP] Algoritmo que cuenta caracteres hasta llegar a '\0'
    //       El valor final del contador no incluye el carácter NULL
    // [ENG] Algorithm that counts characters until '\0' is reached
    //       The final counter value does not include the NULL character
    int i = 0;
    while(String[i] != '\0')
        i++;

    return i;

}

/**
 * [ESP] Concatena 2 strings con alocación de memoria dinámica.
 *       String1 se concatena con String2 (String2 queda a la derecha de String1).
 *       El orden de los parámetros determina el orden de la concatenación.
 *       NOTA: La memoria dinámica debe liberarse en el scope que llama a la función.
 * [ENG] Concatenates 2 strings using dynamic memory allocation.
 *       String1 is concatenated with String2 (String2 goes to the right of String1).
 *       The parameter order determines the concatenation order.
 *       NOTE: The dynamic memory must be freed in the calling scope.
 */
char *Mi_StringConcatenate(char *String1, char *String2)
{
    // [ESP] Calculo del largo de cada string
    // [ENG] Calculate the length of each string
    int String1_length = Mi_StringLength(String1);
    int String2_length = Mi_StringLength(String2);

    // [ESP] Largo total = largo string1 + largo string2 + 1 (para '\0')
    // [ENG] Total length = length of string1 + length of string2 + 1 (for '\0')
    int Total_Length = String1_length + String2_length + 1;

    int i = 0;
    int j = 0;

    // [ESP] Alocación de memoria dinámica para el string concatenado
    // [ENG] Dynamic memory allocation for the concatenated string
    char *StringConcatenated = (char *)calloc(Total_Length,sizeof(char));
    if(StringConcatenated == NULL)
    {
        printf("Ocurrio un error con la memoria dinamica del String Concatenado\n");
        exit(ERROR); // ERROR = -1
    }

    // [ESP] Copio String1 al inicio del string concatenado
    // [ENG] Copy String1 to the beginning of the concatenated string
    for( i = 0; i < String1_length; i++ )
        StringConcatenated[i] = String1[i];

    // [ESP] La última iteración de i deja la posición lista para concatenar String2
    // [ENG] The last iteration of i leaves the position ready to concatenate String2
    for( j = 0; j < String2_length; j++, i++ )
        StringConcatenated[i] = String2[j];

    // [ESP] Agrego '\0' al final del string concatenado
    // [ENG] Append '\0' at the end of the concatenated string
    StringConcatenated[Total_Length-1] = '\0';

    return StringConcatenated;
}

/**
 * [ESP] Compara 2 strings sin importar mayúsculas o minúsculas.
 *       Retorna 0 si son iguales, un valor negativo si String1 < String2,
 *       o un valor positivo si String1 > String2.
 * [ENG] Case-insensitive comparison of 2 strings.
 *       Returns 0 if equal, a negative value if String1 < String2,
 *       or a positive value if String1 > String2.
 */
int Mi_StringCaseCompare(const char *String1, const char *String2)
{
    // [ESP] Algoritmo: convierte cada carácter a minúscula antes de comparar
    // [ENG] Algorithm: converts each character to lowercase before comparing
    int ca = 0;
    int cb = 0;

    do
    {
        ca = * (unsigned char *)String1;
        cb = * (unsigned char *)String2;
        ca = _tolower(_toupper(ca));
        cb = _tolower(_toupper(cb));
        String1++;
        String2++;
    }while( ca == cb && ca != '\0' );
    return ca - cb;

}


/**
 * [ESP] Setea n bytes de un array con un valor entero indicado (similar a memset).
 *       LIMITACIÓN: Solo acepta valores de 0 a 255 inclusive.
 * [ENG] Sets n bytes of an array to a specified integer value (similar to memset).
 *       LIMITATION: Only accepts values between 0 and 255 inclusive.
 */
void *Mi_Stringmemset(void *ptr, unsigned char valor, size_t nro_de_bytes)
{
    size_t i = 0;
    // [ESP] Casteo del puntero para usar aritmética de punteros con offset de 1 byte
    // [ENG] Pointer cast to enable pointer arithmetic with 1-byte offset
    unsigned char *ptr_cast = ptr;

    // [ESP] Carga del array con el valor indicado
    // [ENG] Fill the array with the specified value
    for( i = 0; i < nro_de_bytes; i++ )
        ptr_cast[i] = valor;

    // [ESP] Retorno del puntero original
    // [ENG] Return the original pointer
    return ptr;

}

/**
 * [ESP] Invierte el orden de los caracteres de un string.
 *       Recibe el string y su largo (incluyendo '\0').
 * [ENG] Reverses the order of characters in a string.
 *       Receives the string and its length (including '\0').
 */
void Revertir_String(char *String, int length)
{
    int inicio = 0;
    int fin = length - 1;
    char aux = 0;

    // [ESP] Intercambio de caracteres desde los extremos hacia el centro
    // [ENG] Swap characters from both ends towards the center
    while (inicio < fin)
    {
        aux = String[inicio];
        String[inicio] = String[fin];
        String[fin] = aux;
        fin--;
        inicio++;
    }

    return;
}

/**
 * [ESP] Analiza si un string es palíndromo (sin importar mayúsculas/minúsculas).
 *       Retorna true si es palíndromo, false en caso contrario.
 * [ENG] Checks whether a string is a palindrome (case-insensitive).
 *       Returns true if palindrome, false otherwise.
 */
bool Analisis_Palindromo_String(char *String)
{
    int Punto_Medio = Mi_StringLength(String)/2;
    int largo = Mi_StringLength(String);
    int i= 0;
    char Buffer_Aux[largo+1];

    // [ESP] Copio el string a un buffer auxiliar y lo convierto a mayúsculas
    // [ENG] Copy the string to an auxiliary buffer and convert to uppercase
    Mi_StringCopyV2(Buffer_Aux,String);
    String_uppercase(Buffer_Aux);

    // [ESP] Comparo caracteres desde los extremos hacia el centro
    // [ENG] Compare characters from both ends towards the center
    for( i = 0; i < Punto_Medio; i++ )
    {
        if(Buffer_Aux[i] != Buffer_Aux[largo - i - 1])
            return false;
    }
    return true;
}

/**
 * [ESP] Convierte todos los caracteres de un string a minúsculas.
 * [ENG] Converts all characters in a string to lowercase.
 */
void String_lowercase(char *String)
{
    int length = Mi_StringLength(String);
    int i = 0;

    // [ESP] Recorro cada carácter y lo transformo a minúscula.
    //       Los espacios en blanco se dejan tal cual.
    // [ENG] Iterate through each character and convert to lowercase.
    //       Whitespace characters are left unchanged.
    for( i = 0; i < length; i++ )
        String[i] = _tolower(String[i]);

    return;
}

/**
 * [ESP] Convierte todos los caracteres de un string a mayúsculas.
 * [ENG] Converts all characters in a string to uppercase.
 */
void String_uppercase(char *String)
{
    int length = Mi_StringLength(String);
    int i = 0;

    // [ESP] Recorro cada carácter y lo transformo a mayúscula.
    //       Los espacios en blanco se dejan tal cual.
    // [ENG] Iterate through each character and convert to uppercase.
    //       Whitespace characters are left unchanged.
    for( i = 0; i < length; i++ )
        String[i] = _toupper(String[i]);
}

/**
 * [ESP] Ordena alfabéticamente un array de strings usando el algoritmo de selección.
 *       Si el array 2D fue creado estáticamente, el 1er argumento debe ser
 *       char ArrayDeStrings[cantidad][largo_maximo].
 *       Si fue creado dinámicamente, usar char **ArrayDeStrings.
 * [ENG] Sorts a string array alphabetically using selection sort algorithm.
 *       If the 2D array was created statically, the 1st argument must be
 *       char ArrayDeStrings[count][max_length].
 *       If dynamically created, use char **ArrayDeStrings.
 */
void Ordenamiento_Array_De_Strings(char ArrayDeStrings[10][100], int Cantidad_De_Strings, int largoMaximoString)
{
    char aux[largoMaximoString];
    int i = 0;
    int j_min = 0;
    int j = 0;

    // [ESP] Algoritmo de ordenamiento por selección
    // [ENG] Selection sort algorithm
    for( i = 0; i < (Cantidad_De_Strings-1); i++ )
    {
        j_min = i;
        for( j = i + 1; j < Cantidad_De_Strings; j++ )
        {
            // [ESP] Si uso "<" se ordena de menor a mayor; si uso ">" de mayor a menor
            // [ENG] Using "<" sorts ascending; using ">" sorts descending
            if(Mi_StringCaseCompare(ArrayDeStrings[j],ArrayDeStrings[j_min]) < 0 )
            {
                j_min = j;
            }
        }

        // [ESP] Intercambio de posiciones usando un buffer auxiliar
        // [ENG] Swap positions using an auxiliary buffer
        if(j_min != i)
        {
            Mi_StringCopyV2(aux,ArrayDeStrings[i]);
            Mi_StringCopyV2(ArrayDeStrings[i],ArrayDeStrings[j_min]);
            Mi_StringCopyV2(ArrayDeStrings[j_min],aux);
        }
    }

    // [ESP] Impresión del resultado ordenado
    // [ENG] Print the sorted result
    for(int i = 0; i < Cantidad_De_Strings; i++)
        printf("%s\n",ArrayDeStrings[i]);

    return;
}
