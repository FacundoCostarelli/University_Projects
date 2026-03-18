#include"Mis_Funciones_Strings.h"

//Funcion strcpy propia con la tecnica de contadores
char *Mi_StringCopyV1(char *Destino, const char *Origen)
{
    //Pregunto si Destino apunta a NULL.
    /*Si es verdadero siginifica que paso algo de las siguientes casos:
     *Se paso mal el puntero Destino o que
     *El puntero Destino esta apuntando erroneamente
     *No se allocalizo memoria dinamica correctamente con el puntero Destino
    */
    if( Destino == NULL)
        return NULL;

    /*Algoritmo que copia usando contador. Por cada cuenta, se copia un caracter.
    Esto hasta encontrar el caracter NULL*/
    int i = 0;
    while(Origen[i] != '\0')
    {
        Destino[i] = Origen[i];//copiado de caracter
        i++;//contador
    }

    //Agrego en la ultima posicion "i" obteneida de la iteracion, el caracter \0
    Destino[i] = '\0';

    //Devuelvo el puntero que apunta al 1er elemento del array Destino
    return Destino;

}

//Funcion strcpy propia con aritmetica de punteros
char *Mi_StringCopyV2(char *Destino, const char *Origen)
{
    //Pregunto si Destino apunta a NULL.
    /*Si es verdadero siginifica que paso algo de las siguientes casos:
     *Se paso mal el puntero Destino o que
     *El puntero Destino esta apuntando erroneamente
     *No se allocalizo memoria dinamica correctamente con el puntero Destino
    */
    if( Destino == NULL)
        return NULL;

    /*Algoritmo que copia usando aritmetica de punteros. Por cada cuenta, se copia un ccaracter
    Esto hasta encotnrar el caracter NULL*/
    char *Destino_ptr_1er_elemento = Destino;
    while( *Origen != '\0' )
    {
        *Destino = *Origen;//COpiado de caracter
        Destino++;//Incremento en una unidad el valor del puntero Destino, seria como "iterar"
        Origen++;//Incremento en una unidad el valor del puntero Origen, seria como "iterar"
    }

    //Agrego en la ultima posicion "i" obteneida de la iteracion, el caracter \0
    *Destino = '\0';

    //Devuelvo el puntero que apunta al 1er elemento del array Destino
    return Destino_ptr_1er_elemento;

}

//Funcion que calcula el largo de un string sin su caracter \0
int Mi_StringLength(char *String)
{
    //Pregunto si String apunta a NULL.
    /*Si es verdadero siginifica que paso algo de las siguientes casos:
     *Se paso mal el puntero String o que
     *El puntero String esta apuntando erroneamente
     *No se allocalizo memoria dinamica correctamente con el puntero String
    */
    if( String == NULL)
        return 0;

    /*Algoritmo que cuenta la cantidad de caracteres hasta llegar al caracter \0*/
    /*El valor del contador final no incluye el conteo del caracter Null */
    int i = 0;
    while(String[i] != '\0')
        i++;

    return i;

}

//Funcion que concatena 2 strings con allocacion de memoria dinamica. String1 es concatenado con String2
//Donde String2 se encuentra a la derecha de String1.
//Segun el orden en que se pasen los parametros, los origines quedaran en un sentido u otro
/*No importa el largo e\de String1 y el String2 porque para el String concatenado resultante
se allocaliza memoria dinamica y entonces habra espacio suficente para guardar la concatencacion*/
char *Mi_StringConcatenate(char *String1, char *String2)
{
    /*Calculo del largo del String 1*/
    int String1_length = Mi_StringLength(String1);
    /*Calculo del largo del String 2*/
    int String2_length = Mi_StringLength(String2);
    /*Largo total del String concatenado resultante.
     *Este es la suma de los largos de cada string y de un espacio mas para el caracter \0*/
    int Total_Length = String1_length + String2_length + 1;

    int i = 0;
    int j = 0;

    //Allocalizacion de memoria dinamica
    char *StringConcatenated = (char *)calloc(Total_Length,sizeof(char));
    if(StringConcatenated == NULL)
    {
        printf("Ocurrio un error con la memoria dinamica del String Concatenado\n");
        exit(ERROR);//ERROR vale -1
    }

    for( i = 0; i < String1_length; i++ )
        StringConcatenated[i] = String1[i];

    //La ultima iteracion de i deja la posicion lista para concatenar el String2 justo al lado del String1

    for( j = 0; j < String2_length; j++, i++ )
        StringConcatenated[i] = String2[j];

    //Agrego el caracter \0 al final del String Concatenado
    StringConcatenated[Total_Length-1] = '\0';
    //Como se trabaja con memoria dinamica. En el SCOPE que llama a la funcion, se debe liberar la memoria
    return StringConcatenated;
}

int Mi_StringCaseCompare(const char *String1, const char *String2)
{
    /*Algoritmo 1
    const unsigned char *p1 = (const unsigned char *)String1;
    const unsigned char *p2 = (const unsigned char *)String2;
    int resultado = 0;

    if(p1 == p2)
        return 0;

    while((resultado = _tolower(*p1) - _tolower(*p2++)) == 0)
    {
        if(*p1++ == '\0')
            break;
    }

    return resultado;
    */

    //Algoritmo 2
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


//Funcion que setea n bytes de un array con un valor entero indicado
//LIMITACION: Solo puede recibir valores de entre 0 a 255 inclusive
void *Mi_Stringmemset(void *ptr, unsigned char valor, size_t nro_de_bytes)
{
    size_t i = 0;
    //Casteo del ptr para lograr usar aritmetica de punteros con offset de 1 byte
    unsigned char *ptr_cast = ptr;
    //Carga del array con el valor entero indicado
    for( i = 0; i < nro_de_bytes; i++ )
        ptr_cast[i] = valor;

    //Retorno del puntero original
    return ptr;

}

/*Funcion que realiza una "inversion o reversion" del orden de los caracteres de un string */
/*Recibe como 1er parametro un string a revertir*/
/*Recibe como 2do parametro un el largo del string considerando el caracter NULL*/

void Revertir_String(char *String, int length)
{
    int inicio = 0;
    int fin = length - 1;
    char aux = 0;
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
//Funcion que analisa si un string es palindromo o no sin importar mayusculas y minusculas
bool Analisis_Palindromo_String(char *String)
{
    int Punto_Medio = Mi_StringLength(String)/2;
    int largo = Mi_StringLength(String);
    int i= 0;
    char Buffer_Aux[largo+1];

    Mi_StringCopyV2(Buffer_Aux,String);
    //String_lowercase(String);
    String_uppercase(Buffer_Aux);

    for( i = 0; i < Punto_Medio; i++ )
    {
        if(Buffer_Aux[i] != Buffer_Aux[largo - i - 1])
            return false;
    }
    return true;
}

void String_lowercase(char *String)
{
    int length = Mi_StringLength(String);
    int i = 0;
    /*Recorro cada caracter del srting y guardo en cada posicion el caracter de esa posicion pero
      transformado a su equivalente en minuscula. Los que ya estan minuscula son re-guardados tal cual
     y los que son espacios blancos, se dejan tal cual como estan*/
    for( i = 0; i < length; i++ )
        String[i] = _tolower(String[i]);

    return;
}

void String_uppercase(char *String)
{
    int length = Mi_StringLength(String);
    int i = 0;

    /*Recorro cada caracter del srting y guardo en cada posicion el caracter de esa posicion pero
      transformado a su equivalente en mayuscula. Los que ya estan mayuscula son re-guardados tal cual
     y los que son espacios blancos, se dejan tal cual como estan*/
    for( i = 0; i < length; i++ )
        String[i] = _toupper(String[i]);
}

//Funcion que ordena alfabeticamente un array de strings
//Si el array 2D fue creado estaticamente, entonces el 1er argumento de la funcion debe ser char ArrayDeStrings[cantidad_de_strings][valor_entero_del_largo_maximo_de_strings]
//Si el arrat 2D fue creado dinamicamente, entonces el 1er argumento de la funcion debe ser char **ArrayDeStrings
void Ordenamiento_Array_De_Strings(char ArrayDeStrings[10][100], int Cantidad_De_Strings, int largoMaximoString)
{
    char aux[largoMaximoString];
    int i = 0;
    int j_min = 0;
    int j = 0;

    //Algoritmo de ordenamiento por Seleccion
    for( i = 0; i < (Cantidad_De_Strings-1); i++ )
    {
        j_min = i;
        for( j = i + 1; j < Cantidad_De_Strings; j++ )
        {
            //Si uso signo "<" se ordena alfabeticamente de menor a mayor
            //Si uso signo ">" se ordena alfabeticamente de mayor a menor
            if(Mi_StringCaseCompare(ArrayDeStrings[j],ArrayDeStrings[j_min]) < 0 )
            {
                j_min = j;
            }
        }

        if(j_min != i)
        {
            Mi_StringCopyV2(aux,ArrayDeStrings[i]);
            Mi_StringCopyV2(ArrayDeStrings[i],ArrayDeStrings[j_min]);
            Mi_StringCopyV2(ArrayDeStrings[j_min],aux);
        }
    }

    for(int i = 0; i < Cantidad_De_Strings; i++)
        printf("%s\n",ArrayDeStrings[i]);

    return;
}


