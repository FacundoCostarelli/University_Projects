/**
 * ==========================================================================
 * itostr_strtol.c — Integer ↔ String Conversion Functions
 * ==========================================================================
 * [ESP] Funciones y algoritmos para conversión entre enteros y strings:
 *       - Uso de strtol() para convertir cadenas numéricas a enteros
 *       - Uso de sprintf() para convertir enteros a cadenas en otra base
 *       - IntToAnString: convierte un entero a formato string en base
 *         2, 8, 10 o 16
 *       - revertir: invierte el orden de caracteres de un string
 *
 * [ENG] Functions and algorithms for integer ↔ string conversion:
 *       - Using strtol() to convert numeric strings to integers
 *       - Using sprintf() to convert integers to strings in another base
 *       - IntToAnString: converts an integer to string format in base
 *         2, 8, 10, or 16
 *       - revertir: reverses the character order of a string
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */


/*PRIMERA PARTE-PRIMERA PARTE-PRIMERA PARTE-PRIMERA PARTE-PRIMERA PARTE-PRIMERA PARTE-PRIMERA PARTE-*/

/*Convierto el valor numerico entero de entrada en formato de caracteres proveniente de un array src a un valor entero en alguna base eelgida*/
/*Para lograr esto utilizo la funcion de biblioteca "strtol" casteada su retorno a int (aunque podria usarse con long) */
/*Prototipo: long int strtol(const char *nptr, char **endptr, int base);

Hay que incluir el siguiente header
       
#include <stdlib.h>

-Recibe como 1er parametro un array del cual va a evaluar si hay o no digitos en formato caracter
-Recibe como 2do parametro un puntero a puntero el cual apunta a la direccion de memoria de un caracter no digito
-Recibe como 3er parametro un valor entero asociado a la base de conversion. Puedo ser cualquier base multiplo de 2 siendo un rango de entre 2 a 36.  Se puede pasar como valor especial 0 que equivale a distantas bases segun como viene el array de digitos
/***VER MANUAL***/
*/
/*La funcion evalua un array de digitos en formato caracter hasta encontrar un caracter que no sea un digito. Evalua dicho grupo de digitos y lo convierte a un valor entero o long segun caso en la base elegida. Guarda ademas en el contenido de lo apuntado por endptr(osea *endptr), la direccion del caracter no digito encontrado al final de la cadena*/
/*Si no hubiese dugitos en lo absoluto, guarda en el contenido de lo apuntado por endptr(osea *endptr), la direccion del 1er caracter*/
/*La funcion strtol devuelve el valor int o long(segun caso) en la base elegida. Este esta asociado a la cadena de digitos evaluada*/
/*VER MANUAL PARA MAS INFORMACION*/

Ejemplo de aplicacion: 
//Convierto una cadena de digitos en una base supuesta decimal a un entero en base decimal
valor_decimal_IN = (int)strtol(&src[i], &Fin_Cadena_Numerica, 10);
if(valor_decimal_IN == 0) printf("No hay digitos en formato string para convertir\n");

/*SEGUNDA PARTE-SEGUNDA PARTE-SEGUNDA PARTE-SEGUNDA PARTE-SEGUNDA PARTE-SEGUNDA PARTE-SEGUNDA PARTE-SEGUNDA PARTE*/

/*Convierto un valor entero supuesto en alguna base en una cadena de digitos en una base elegida*/
/*Para lograr esto utilizo la funcion de  biblioteca sprintf*/
/*Prototipo: int sprintf(char *str, const char *format, ...);

Hay que incluir el siguiente header
       
#include <stdio.h>


-Recibe como 1er parametro un buffer donde guardar la cadena de digitos creada
-Recibe como 2do parametro un array de formato con el cual se indica la base en la que se quiere la conversion
-Recibe como 3er parametro un valor entero en alguna base dada que se va a procesar para obtener la cadena de digitos asociada
*/
/*La funcion converite algun entero en alguna base supuesta en una cadena de digitos en alguna base elegida y lo guarda en un buffer de caracteres*/
/*La funcion devuelve algun tipo de macro asociada a algun error o exito*/

Ejemplo de aplicacion:
//Convierto el valor numerico int decimal a octal en formato de caracteres pasandolo a un array auxiliar
sprintf(buffer_aux, "%o", valor_decimal_IN);
printf("El valor entero a numero octal con sprintf queda como %s\n",buffer_aux);	     


/********FIN ALGORITMO*********/

/*******ALGORITMO PARA CONVERTIR UN VALOR ENTERO EN FORMATO STRING EN ALGUNA BASE COMO: 2,8,10,16******/
/* Headers para invocar con ls funcion IntToAnString
#include <stdbool.h>
#include <stdio.h>
 */

/*Esta funcion conviernte un entero a formato string en alguna de las siguientes bases: 
-Base 2
-Base 8
-Base 10
-Base 16
*/
/*Recibe como 1er parametro un entero que es el nro a cinvertir*/
/*Recibe como 2do parametro un puntero a char a un buffer donde guardar la conversion*/
/*Recibe como 3er parametro un entero que es la base de conversion del 1er parametro*/

/*Devuelve un puntero a char a un buffer donde guardar la conversion*/
char* IntToAnString(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
 
    /* Caso en que num es 0 explicitamente, carga el string con elemento numerico 0 y con \0 */
    /* Otra alternativa es imprimir un string vacio cuando num = 0 */
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    /*Caso en que num es negativo y la base es 10. Conveierte a positivo el signo de num para procesarlo*/
    /*Para las bases 2, 8 y 16 = > num es considerado unsigned*/
    
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }
 
    /*Procesamiento individual de digitos*/
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
 
    /*Caso en que el numero procesado era previamente negativo respecto del procesamiento y la base era 10, entonces se agrega el caracter 	de "signo -" a la cadena de caracteres asociada al num
     */    
    if (isNegative)
        str[i++] = '-';
 
    /*Se  carga el caracter NULL al final de la cadena resultante del procesamiento*/
    str[i] = '\0'; 
 
    // Se revierte el orden de los caracteres del string resultante del procesamiento
    revertir(str, i);
 
    return str;
}

/*Funcion que realiza una "inversion o reversion" del orden de los caracteres de un string */
/*Recibe como 1er parametro un string a revertir*/
/*Recibe como 2do parametro un el largo del string considerando el caracter NULL*/

void revertir(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
     {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

/********FIN ALGORITMO*********/
