#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct port
{
unsigned char p0:1;
unsigned char p1:1;
unsigned char p2:1;
unsigned char p3:1;
unsigned char p4:1;
unsigned char p5:1;
unsigned char p6:1;
unsigned char p7:1;
};

struct paquete
{
unsigned char MACori[6];
unsigned char MACdes[6];
struct port entrada;
struct port salida;
};

void Primer_Funcion(struct paquete **ptr);
void Segunda_Funcion(struct paquete *ptr);
void imprimir_info_switch(struct paquete *ptr);
int aleatorio_en_rango(int minimo, int maximo);


int main()
{
    struct paquete *Array_estatico_de_ptrs_paquetes[10];
    int i;
    srand(time(NULL));

    printf("Se imprimira la informacion pedida con el siguiente formato: \nMAC_Destino MAC_Origen Puerto_Salida Puerto_Entrada\n\n\n");
    for( i = 0; i < 10; i++ )
    {
        Primer_Funcion(&Array_estatico_de_ptrs_paquetes[i]);
        Segunda_Funcion(Array_estatico_de_ptrs_paquetes[i]);
        imprimir_info_switch(Array_estatico_de_ptrs_paquetes[i]);
        printf("\n");
    }

    return 0;
}

/*
1)Realizar una función que rellene dinámicamente un array estático, de punteros a struct
paquete de 10 posiciones. La estructura interna de struct paquete se detalla debajo,
notar que cada struct paquete, contiene 2 struct port que se utilizan como campo de
bits.(el array debe ser creado en el main). Con esta función simulamos la existencia de
10 paquetes.
*/

void Primer_Funcion(struct paquete **ptr)
{
    struct paquete *ptr_aux = NULL;
    ptr_aux = (struct paquete *)malloc(sizeof(struct paquete));
    if(ptr_aux == NULL)
    {
        printf("Hubo un error con la carga de punteros a struct paquete en el array estatico\n");
        exit(-1);
    }
    else
        *ptr = ptr_aux;
    return;
}

/*
2)Realizar una función que rellene aleatoriamente los array de char llamados MACori y
MACdes que forman parte de la estructura, y rellene los struct port entrada y salida.
(En estos últimos sólo 1bit de cada struct port entrada y struct por salida puede valer
‘1’). Con este ítem se busca lograr tener una dirección mac de origen y una dirección
mac de destino aleatoria, junto con un puerto de origen aleatorio (por donde el
paquete simulado entro), y un puerto de salida aleatorio(por donde el paquete
simulado debería salir)
*/
void Segunda_Funcion(struct paquete *ptr)
{
    int i;

    char aux[4];
    char Numero, CarMin, CarMay;
    int Opcion;
    unsigned char bit;
    aux[3] = '\0';
    for( i = 0; i < 6; i++ )
    {
        Numero = (char)aleatorio_en_rango('0','9');
        aux[0] = Numero;
        CarMin = (char)aleatorio_en_rango('A', 'Z');
        aux[1] = CarMin;
        CarMay = (char)aleatorio_en_rango('a', 'z');
        aux[2] = CarMay;
        Opcion = aleatorio_en_rango(0,2);
        switch(Opcion)
        {
            case 0:
                ptr->MACori[i] = aux[Opcion];
                break;
            case 1:
                ptr->MACori[i] = aux[Opcion];
                break;
            case 2:
                ptr->MACori[i] = aux[Opcion];
                break;
            default:
                break;
        }
    }
    for( i = 0; i < 6; i++ )
    {
        Numero = (char)aleatorio_en_rango('0','9');
        aux[0] = Numero;
        CarMin = (char)aleatorio_en_rango('A', 'Z');
        aux[1] = CarMin;
        CarMay = (char)aleatorio_en_rango('a', 'z');
        aux[2] = CarMay;
        Opcion = aleatorio_en_rango(0,2);
        switch(Opcion)
        {
            case 0:
                ptr->MACdes[i] = aux[Opcion];
                break;
            case 1:
                ptr->MACdes[i] = aux[Opcion];
                break;
            case 2:
                ptr->MACdes[i] = aux[Opcion];
                break;
            default:
                break;
        }
    }

    for( i = 0; i < 8; i++ )
    {
        bit = (unsigned char)aleatorio_en_rango(0,1);
        if( bit == 1 )
            break;
    }

    if( i == 0 ) ptr->entrada.p0 = bit;
    else ptr->entrada.p0 = 0;
    if( i == 1 ) ptr->entrada.p1 = bit;
    else ptr->entrada.p1 = 0;
    if( i == 2 ) ptr->entrada.p2 = bit;
    else ptr->entrada.p2 = 0;
    if( i == 3 ) ptr->entrada.p3 = bit;
    else ptr->entrada.p3 = 0;
    if( i == 4 ) ptr->entrada.p4 = bit;
    else ptr->entrada.p4 = 0;
    if( i == 5 ) ptr->entrada.p5 = bit;
    else ptr->entrada.p5 = 0;
    if( i == 6 ) ptr->entrada.p6 = bit;
    else ptr->entrada.p6 = 0;
    if( i == 7 ) ptr->entrada.p7 = bit;
    else ptr->entrada.p7 = 0;


    for( i = 0; i < 8; i++ )
    {
        bit = (unsigned char)aleatorio_en_rango(0,1);
        if( bit == 1 )
            break;
    }

    if( i == 0 ) ptr->salida.p0 = bit;
    else ptr->salida.p0 = 0;
    if( i == 1 ) ptr->salida.p1 = bit;
    else ptr->salida.p1 = 0;
    if( i == 2 ) ptr->salida.p2 = bit;
    else ptr->salida.p2 = 0;
    if( i == 3 ) ptr->salida.p3 = bit;
    else ptr->salida.p3 = 0;
    if( i == 4 ) ptr->salida.p4 = bit;
    else ptr->salida.p4 = 0;
    if( i == 5 ) ptr->salida.p5 = bit;
    else ptr->salida.p5 = 0;
    if( i == 6 ) ptr->salida.p6 = bit;
    else ptr->salida.p6 = 0;
    if( i == 7 ) ptr->salida.p7 = bit;
    else ptr->salida.p7 = 0;

}

// Devuelve un número aleatorio entre minimo y maximo, incluyendo a minimo y maximo
int aleatorio_en_rango(int minimo, int maximo)
{
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}


/*
3)Realizar una función que imprima en la terminal según el siguiente título.
a) MAC_Destino MAC_Origen Puerto_Salida Puerto_Entrada.
*/

void imprimir_info_switch(struct paquete *ptr)
{
    //MAC_Destino
    printf("%.6s ", ptr->MACdes);
    //MAC_Origen
    printf("%.6s ", ptr->MACori);

    if(ptr->salida.p0 == 1) printf("P0 ");
    if(ptr->salida.p1 == 1) printf("P1 ");
    if(ptr->salida.p2 == 1) printf("P2 ");
    if(ptr->salida.p3 == 1) printf("P3 ");
    if(ptr->salida.p4 == 1) printf("P4 ");
    if(ptr->salida.p5 == 1) printf("P5 ");
    if(ptr->salida.p6 == 1) printf("P6 ");
    if(ptr->salida.p7 == 1) printf("P7 ");

    if(ptr->entrada.p0 == 1) printf("P0 ");
    if(ptr->entrada.p1 == 1) printf("P1 ");
    if(ptr->entrada.p2 == 1) printf("P2 ");
    if(ptr->entrada.p3 == 1) printf("P3 ");
    if(ptr->entrada.p4 == 1) printf("P4 ");
    if(ptr->entrada.p5 == 1) printf("P5 ");
    if(ptr->entrada.p6 == 1) printf("P6 ");
    if(ptr->entrada.p7 == 1) printf("P7 ");
    /*
    printf("Puerto_Salida: \n");
    printf("p0 = %d\n", ptr->salida.p0);
    printf("p1 = %d\n", ptr->salida.p1);
    printf("p2 = %d\n", ptr->salida.p2);
    printf("p3 = %d\n", ptr->salida.p3);
    printf("p4 = %d\n", ptr->salida.p4);
    printf("p5 = %d\n", ptr->salida.p5);
    printf("p6 = %d\n", ptr->salida.p6);
    printf("p7 = %d\n", ptr->salida.p7);

    printf("Puerto_Entrada: \n");
    printf("p0 = %d\n", ptr->entrada.p0);
    printf("p1 = %d\n", ptr->entrada.p1);
    printf("p2 = %d\n", ptr->entrada.p2);
    printf("p3 = %d\n", ptr->entrada.p3);
    printf("p4 = %d\n", ptr->entrada.p4);
    printf("p5 = %d\n", ptr->entrada.p5);
    printf("p6 = %d\n", ptr->entrada.p6);
    printf("p7 = %d\n", ptr->entrada.p7);
    */
}
