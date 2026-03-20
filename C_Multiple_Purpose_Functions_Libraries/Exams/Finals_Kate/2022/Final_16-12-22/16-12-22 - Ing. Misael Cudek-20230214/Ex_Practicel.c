/**
 * @file    Ej-Practico.c
 * @brief   [ESP] Ejercicio Práctico - Final 16-12-2022. Estructuras de red con campos de bits.
 *          [ENG] Practical Exercise - Final 16-12-2022. Network structures with bit fields.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/**
 * @brief [ESP] Estructura de puerto con campos de bits.
 *        [ENG] Port structure with bit fields.
 */
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

/**
 * @brief [ESP] Estructura de paquete de red.
 *        [ENG] Network packet structure.
 */
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

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
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

    /* [ESP] Faltaría realizar un free() / [ENG] A free() is missing here */

    return 0;
}

/**
 * @brief [ESP] Rellena dinámicamente el puntero del array estático.
 *        [ENG] Dynamically fills the static array pointer.
 */
void Primer_Funcion(struct paquete **ptr)
{
    struct paquete *ptr_aux = NULL;
    ptr_aux = (struct paquete *)malloc(sizeof(struct paquete));
    if(ptr_aux == NULL)
    {
        printf("Error con ptrs a struct paquete array estatico\n");
        exit(-1);
    }
    else
        *ptr = ptr_aux;
}

/**
 * @brief [ESP] Genera direcciones MAC aleatorias y 1 bit en los puertos de entrada y de salida.
 *        [ENG] Generates random MAC addresses and 1 bit across input and output ports.
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
        
        ptr->MACori[i] = aux[Opcion];
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
        
        ptr->MACdes[i] = aux[Opcion];
    }

    /* [ESP] Puerto Entrada / [ENG] Input Port */
    for( i = 0; i < 8; i++ )
    {
        bit = (unsigned char)aleatorio_en_rango(0,1);
        if( bit == 1 ) break;
    }
    
    ptr->entrada.p0 = (i == 0) ? bit : 0;
    ptr->entrada.p1 = (i == 1) ? bit : 0;
    ptr->entrada.p2 = (i == 2) ? bit : 0;
    ptr->entrada.p3 = (i == 3) ? bit : 0;
    ptr->entrada.p4 = (i == 4) ? bit : 0;
    ptr->entrada.p5 = (i == 5) ? bit : 0;
    ptr->entrada.p6 = (i == 6) ? bit : 0;
    ptr->entrada.p7 = (i == 7) ? bit : 0;

    /* [ESP] Puerto Salida / [ENG] Output Port */
    for( i = 0; i < 8; i++ )
    {
        bit = (unsigned char)aleatorio_en_rango(0,1);
        if( bit == 1 ) break;
    }

    ptr->salida.p0 = (i == 0) ? bit : 0;
    ptr->salida.p1 = (i == 1) ? bit : 0;
    ptr->salida.p2 = (i == 2) ? bit : 0;
    ptr->salida.p3 = (i == 3) ? bit : 0;
    ptr->salida.p4 = (i == 4) ? bit : 0;
    ptr->salida.p5 = (i == 5) ? bit : 0;
    ptr->salida.p6 = (i == 6) ? bit : 0;
    ptr->salida.p7 = (i == 7) ? bit : 0;
}

int aleatorio_en_rango(int minimo, int maximo)
{
   return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

/**
 * @brief [ESP] Imprime información de red (MAC y puertos).
 *        [ENG] Prints network information (MAC and ports).
 */
void imprimir_info_switch(struct paquete *ptr)
{
    printf("%.6s ", ptr->MACdes);
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
}
