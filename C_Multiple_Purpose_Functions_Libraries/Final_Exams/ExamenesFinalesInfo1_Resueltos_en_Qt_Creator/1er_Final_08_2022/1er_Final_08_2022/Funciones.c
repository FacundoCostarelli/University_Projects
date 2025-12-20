#include "Funciones.h"

//Asumo que string de entrada viene con todas MASYUSCULAS
//Asumo que string de salida tiene espacio suficiente para almacenar la nueva encriptacion
//Recibo un *src que apunta a la direccion de comienzo de un array de chars de origen
//Recibo un *dst que apunta a la direccion de comienzo de un array de chars de destino

int encriptar_letras(const char *src, char *dst)
{
    int desplazamiento_alfabetico = aleatorio_en_rango(1,25);
    //int desplazamiento_restante_hasta_Z = 0;
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
                //desplazamiento_restante_hasta_Z = 'Z' - src[i];
                //desplazamiento_adicional = desplazamiento_alfabetico - desplazamiento_restante_hasta_Z;

                dst[i] = 'A' + (desplazamiento_adicional-1);
            }
            else
                dst[i] = src[i] + desplazamiento_alfabetico;
        }
    }

    return desplazamiento_alfabetico;
}

//Para generar nros aleatorios tipo int
int aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

//Funciona para todos los casos excepto aquellos en los que hay digito-letra-digioto-letra o letra-digito-letra-digito
//Sucede que para los 2 casos menicinados, solo encripta algunos de los caracteres de esa secuencia especial
void encriptar_numeros(/*const*/ char *src, char *dst)
{
    size_t i = 0, j = 0, k = 0;
    char buffer_aux[TXT_MAX_LEN];//buffer auxiliar que almacena un valor entero octal en formato de string de chars
    int valor_decimal_IN = 0;
    char *Fin_Cadena_Numerica = NULL;

    //Inicializo aux con un valor cualquiera
    //char aux = 'A';



    //Algoritmo de encriptado. Recorro cada caracter de src y pregunto si esta entre 0 y 9
    //En tal caso lo convierto a octal y voy escribiendo en dst el caracter de encriptacion asociado
    //a cada digito del valor octal  los # al principio y fin del encriptado.
    for( i = 0; i < strlen(src); i++ )
    {

        if( (src[i] >= '0' && src[i] <= '9') ) // || (aux >= '0' && aux <= '9')
        {
            //Limpio buffer_aux con todos 0
            for( k = 0; k < TXT_MAX_LEN; k++ )
            {
                buffer_aux[k] = '\0';
            }


            //Metodo 1
            //Convierto el valor numerico decimal de entrada en formato de caracteres en src a un valor entero decimal
            valor_decimal_IN = (int)strtol(&src[i], &Fin_Cadena_Numerica, 10);
            if(valor_decimal_IN == 0) printf("No hay digitos en formato string para convertir\n");

            //Convierto el valor numerico int decimal a octal en formato de caracteres pasandolo a un array auxiliar
            sprintf(buffer_aux, "%o", valor_decimal_IN);
            printf("El valor entero a numero octal con sprintf queda como %s\n",buffer_aux);


           //Metodo 2
           //Convierto el valor numerico decimal de entrada en formato emtero una cadena de caracteres asociada
           //IntToAnString(valor_decimal_IN, buffer_aux, 8);
           //printf("El valor entero a numero octal con IntToAnString queda como %s\n",buffer_aux);

           j = i;
           dst[j] = '#';
           j++;

           for( k = 0; k < strlen(buffer_aux); k++ )
           {
               //aux = atoi(&buffer_aux[i]);
               //switch ( aux )
               switch( buffer_aux[k] )
               {
               case '0':
                   dst[j] = '$';
                   j++;
                   break;
               case '1':
                   dst[j] = '%';
                   j++;
                   break;
               case '2':
                   dst[j] = '&';
                   j++;
                   break;
               case '3':
                   dst[j] = '*';
                   j++;
                   break;
               case '4':
                   dst[j] = '@';
                   j++;
                   break;
               case '5':
                   dst[j] = '!';
                   j++;
                   break;
               case '6':
                   dst[j] = '+';
                   j++;
                   break;
               case '7':
                   dst[j] = '=';
                   j++;
                   break;
               default:
                   break;
               }
           }
           dst[j] =  '#';
           //j++;
           printf("Valor de j %lu\n",j);


           printf("Encriptacion en funcion encriptar_numeros %s\n",dst);

           //Cuento la cantidad de digitos que hay hasta el proximo dato no digito y dejo el iterador preparado para el proximo dato no digito
           for( ; src[i] >= '0' && src[i] <= '9'; i++);

           i++;



        }
        else
        {
           if(dst[i-1] == '#')
           {

               //Limpio buffer auxliar todos 0
               for( k = 0; k < TXT_MAX_LEN; k++ )
               {
                   buffer_aux[k] = '\0';
               }

               j = i - 2;
              // printf("Caracter de inicio de cadena a concatenar %c\n",src[j]);
               for(k = 0 ; src[j] >= 'A' && src[j] <= 'Z'; k++,j++)
                    buffer_aux[k] = src[j];

               //printf("buffer aux con solo letras: %s\n",buffer_aux);
               strcat(dst,buffer_aux);

           }
           else
               dst[i] = src[i];
        }





    }

    return;
}

// C program to implement itoa()
//#include <stdbool.h>
//#include <stdio.h>


// A utility function to reverse a string
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



// Implementation of IntToAnString()
char* IntToAnString(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    // Handle 0 explicitly, otherwise empty string is printed for 0
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled
    // only with base 10. Otherwise numbers are
    // considered unsigned.
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    revertir(str, i);

    return str;
}

/*
//FUncion que conviete numeros a octal
int Convertir_a_octal( char numero )
{
    printf("Esta funcion convierte un caracter a un valor octal entero\n");
    return
}
*/
