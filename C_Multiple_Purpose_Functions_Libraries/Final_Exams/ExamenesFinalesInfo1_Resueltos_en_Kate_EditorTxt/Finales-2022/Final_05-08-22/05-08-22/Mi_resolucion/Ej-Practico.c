#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#include<time.h>

#define TXT_MAX_LEN 20
struct st_texto_encriptado
{
char txt[TXT_MAX_LEN];
int desplazamiento;
};

int encriptar(const char *src , char * dst);
int encriptar_letras(const char *src , char *dst);
void encriptar_numeros ( const char *src , char *dst);
int aleatorio_en_rango(int minimo, int maximo);

int main(int argc, char**argv)
{
    struct st_texto_encriptado var1;
    FILE *File_out = NULL;
    if( argc != 3 )
    {
        printf("Erro, no se ingresaron todos los argumentos necesarios. Por favor ingrese segun: <ejectuable> <nombre_archivo_de_salida.txt> <texto a encriptar>\n");
        return -1;
    }
    srand(time(NULL));

    /*
    //char letras_encriptadas[TXT_MAX_LEN];
    char numeros_a_encriptar[] = "305";
    char numeros_encriptados[sizeof(numeros_a_encriptar)];

    //memset(letras_encriptadas, 0, sizeof(letras_encriptadas));
    memset(numeros_encriptados,0,sizeof(numeros_encriptados));
    */
    //memset(var1.txt, 0, sizeof(var1.txt));
    printf("EL txt ingresado a encriptar fue %s y tiene %ld caracteres\n", argv[2], strlen(argv[2]));
    var1.desplazamiento = encriptar(argv[2], var1.txt);
    printf("El texto ingresado queda encriptado como %s\n", var1.txt);

    File_out = fopen(argv[1], "at");
    if(File_out == NULL)
    {
        printf("Error al abrir archivo de salida\n");
        return -1;
    }

    fprintf(File_out,"%s\n", var1.txt);

    fclose(File_out);

    return 0;
}

int encriptar(const char *src , char * dst)
{
    char auxiliar[TXT_MAX_LEN];
    char array_final[TXT_MAX_LEN];
    int codigo;
    memset(array_final,0,sizeof(array_final));
    codigo = encriptar_letras(src,auxiliar);
    encriptar_numeros(auxiliar,array_final);
    strcpy(dst,array_final);

    return codigo;
}

int encriptar_letras(const char *src , char * dst)
{
    //Alternativa a la funcion aleatroio_en_rango()..."rand()%(INTERVALO+1)+MINIMO"
    //Declaro e inicializo variables
    int minimo = 1, maximo = 25;
    int nro_desplazamiento_alfabetico = aleatorio_en_rango(minimo,maximo);
    //Declaro variables para usar en loop for
    int k;
    //Muestro el nro_desplazamiento_alfabetico generado por rand() a traves de la funcion aleatorio_en_rango con su algoritmo matematico
    printf("El numero de nro_desplazamiento_alfabetico es %d\n", nro_desplazamiento_alfabetico);

    //Doble loop for. El 1ero es para recorrer cada caracter del string de entrada. El 2do es para verificar que cada caracter este entre 'A' y 'Z', ambos incluidos(Esto con una 1er sentencia if en la linea 30),. Es decir, que los caracteres del string de entrada no sean espacios ni numeros. Aquellos caracteres que cumplan con lo mencionado, seran entonces "desplazados" segun el nro_desplazamiento_alfabetico, en caso contrario no se modifican. Ademas hay una 2da verificacion con un 2do if en la linea 33. Aca por cada desplazamiento realizado en el caracter, se comprueba si el caracter desplazado sobrepasa al 'Z'. En tal caso se procede segun el enunciado del problema. Cabe mencionar, que cada caracter desplazado a partir de el calculo matematico desarrollado, en realidad se carga como una copia en cada posicion del array "dst" a medida que se va recorriendo el array "src".
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

    //retorno la cantidad de posiciomnes desplazadas
    return nro_desplazamiento_alfabetico;
}

void encriptar_numeros( const char *src , char *dst)//Asumo que el valor numerico expresado en caracters a traves de src, es un valor decimal
{
    int valor_decimal, count = 1;
    char *Fin_Cadena_Numerica = NULL;
    //Un valor octal int puede ser representado con hasta 10 digitos en el peor de los casos en un array de caracteres
    char array_aux[13];//10 digitos  + 2 elementos mas para '#' + 1 elemento para '\0'
    int k = 0, i;
    //Inicializo el array_aux con todos valores \0
    memset(array_aux,0,sizeof(array_aux));
    //Asigno el caracter '#' al comienzo del array auxilar
    array_aux[k] = '#';

    for(i = 0; i < strlen(src); i++)
    {
        if(count == 1)
        {
            if(  (src[i] >= 'A' && src[i] <= 'Z') || src[i] == ' '  )
            {
                if(dst[i] != '\0')
                    dst[i+2] = src[i];
                else
                    dst[i] = src[i];
            }
            else
            {
                //Convierto el valor numerico decimal de entrada en formato de caracteres en src a un valor entero decimal
                valor_decimal = (int)strtol(&src[i], &Fin_Cadena_Numerica, 10);
                if(valor_decimal == 0) printf("No hay digitos en formato string para convertir\n");
                //Convierto el valor numerico int decimal a octal en formato de caracteres pasandolo a un array auxiliar
                sprintf(array_aux+1, "%o", valor_decimal);
                printf("El valor decimal convertido a octal y expresado en un string es %s\n", array_aux+1);
                printf("El valor decimal expresado a octal es: %o\n",valor_decimal);
                //Evaluo cada cifra octal y re-asigno en el espacio que ocupan en el array_aux, los caracteres correspondientes segun la tabla del enunciado
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
                //Asigno el caracter '#' al final de "dst"
                array_aux[k] = '#';
                printf("El array numerico octal encriptado queda como %s\n", array_aux);
                count = strlen(array_aux) - 2;
                //Copio el contenido que hay en array_aux en el array destino
                strcpy(&dst[i],array_aux);
            }
        }
        else
        {
            printf("El valor de i es: %d\n", i);
            count--;
        }

    }
}

// Devuelve un número aleatorio entre minimo y maximo, incluyendo a minimo y maximo
int aleatorio_en_rango(int minimo, int maximo)
{
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
