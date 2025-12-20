#include"Mis_Funciones_Strings.h"
//Driver para testear mis funciones de manejo de strings

//Driver para funcion Mi_StringCopyV1 y la V2
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

/*
//Driver para funcion Mi_StringConcatenate
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
/*
//Driver para funcion Mi_memset
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

/*
//Driver para funcion Analisis_Palindromo_String
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

/*
//Driver para funciones String_lowercase y String_uppercase
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

/*
//Driver para funcion Ordenamiento_Array_De_Strings
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
