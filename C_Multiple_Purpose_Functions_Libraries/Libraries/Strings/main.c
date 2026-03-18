/**
 * ==========================================================================
 * main.c — Test Drivers for Custom String Functions
 * ==========================================================================
 * [ESP] Programa de prueba (driver) para verificar el funcionamiento de
 *       las funciones de manejo de strings definidas en my_strings.h.
 *       Cada bloque main() prueba una función distinta.
 *       Descomentar el bloque deseado para ejecutar la prueba.
 *
 * [ENG] Test driver program to verify the behavior of the string
 *       manipulation functions defined in my_strings.h.
 *       Each main() block tests a different function.
 *       Uncomment the desired block to run that test.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

#include"my_strings.h"

/* -----------------------------------------------------------------------
 * [ESP] Driver para Mi_StringCopyV1 y Mi_StringCopyV2
 * [ENG] Driver for Mi_StringCopyV1 and Mi_StringCopyV2
 * ----------------------------------------------------------------------- */
/*
int main()
{
    char src[] = "copy this";
    char dest[100] ;

    char *dest_ptr = Mi_StringCopyV2(dest,src);

    printf("    src:  %s\n", src);
    printf("    dest: %s\n",dest);
    printf("dest_ptr: %s\n",dest_ptr);

    printf("    dest: %p\n", dest);
    printf("dest_ptr: %p\n",dest_ptr);

    return 0;
}
*/

/* -----------------------------------------------------------------------
 * [ESP] Driver para Mi_StringConcatenate
 * [ENG] Driver for Mi_StringConcatenate
 * ----------------------------------------------------------------------- */
/*
int main()
{
    char s1[] = "abc";
    char s2[] = "wxyz";

    char *StringConcatenated = Mi_StringConcatenate(s1,s2);

    printf("El string concatenado es: %s\n",StringConcatenated);

    free(StringConcatenated);

    return 0;
}
*/

/* -----------------------------------------------------------------------
 * [ESP] Driver para Mi_Stringmemset
 * [ENG] Driver for Mi_Stringmemset
 * ----------------------------------------------------------------------- */
/*
int main()
{
    char Arr1[10];
    char Arr2[10];

    Mi_Stringmemset(Arr1,'\0',10);
    for( int i = 0; i < 10; i++ )
    {
        printf("%d\n",Arr1[i]);
    }
    Mi_Stringmemset(Arr2,5,10);

    for( int i = 0; i < 10; i++ )
    {

        printf("%d\n",Arr2[i]);
    }

    return 0;
}
*/

/* -----------------------------------------------------------------------
 * [ESP] Driver para Analisis_Palindromo_String
 * [ENG] Driver for Analisis_Palindromo_String (Palindrome Check)
 * ----------------------------------------------------------------------- */
/*
int main()
{
    //char string1[] = "not a palindromo";
    //char string2[] = "abccba";
    char string3[] = "aBcDCbA";

    if( Analisis_Palindromo_String(string3) == true )
        printf("%s\n- Es palindroma\n",string3);
    else
        printf("%s\n-No es palindroma\n", string3);

    return 0;
}
*/

/* -----------------------------------------------------------------------
 * [ESP] Driver para String_lowercase y String_uppercase
 * [ENG] Driver for String_lowercase and String_uppercase
 * ----------------------------------------------------------------------- */
/*
int main()
{
    char String[] = "HolA Como ESTaS HoY";

    String_lowercase(String);
    printf("En minusculas: %s\n",String);
    String_uppercase(String);
    printf("En mayusculas %s\n", String);

    return 0;
}
*/

/* -----------------------------------------------------------------------
 * [ESP] Driver para Ordenamiento_Array_De_Strings
 * [ENG] Driver for Ordenamiento_Array_De_Strings (String Array Sorting)
 * ----------------------------------------------------------------------- */
/*
int main()
{
    char Strings[10][100] =
    {
        "demonstration",
        "apple",
        "joyful",
        "friends",
        "battle",
        "incredible",
        "example",
        "great",
        "happy",
        "city",
    };


    Ordenamiento_Array_De_Strings(Strings,10,100);

    return 0;
}
*/
