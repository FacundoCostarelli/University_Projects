//Asumo que string de entrada viene con todas MASYUSCULAS
//Asumo que string de salida tiene espacio suficiente para almacenar la nueva encriptacion
//Recibo un *src que apunta a la direccion de comienzo de un array de chars de origen
//Recibo un *dst que apunta a la direccion de comienzo de un array de chars de destino

/*Funcion que encripta strings de letras MAYUSCULAS sin modificar los strings numericos intermedios. Escribe dicha encriptacion en un   array de salida que puede ser auxiliar o no. La encriptacion se basa en un desplazamiento alfabetico aleatorio para cada caracter*/  
/*Recibe un string de entrada "char *src" y un string de salida "char *dst"*/
/*Esta funcion devuelve el valor de desplazamiento alfabetico*/
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

/*Funcion que encripta strings de numeros convirtiendo estos de formato string a int decimal, convierte ese int decimal a int octal y finalmente lo convierte a formato string. Esta concatena las encriptaciones numericas con los arrays alfabeticos intermededios, en un array char de salida "dst" que puede ser o no de salida */  
/*La encriptacion se basa en reemplazar cada digito del valor octal con un simbolo dado por la tabla en el switchcase. Ademas dicha encreptacion se escribe entre simbolos inicial y final "#" */
//Recibe un array de entrada "char *src" y un array de salida "char *dst"
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

           //Cuento la cantidad de digitos que hay hasta el proximo dato no digito y dejo el iterador preparado para el proximo dato no
           //digito
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

