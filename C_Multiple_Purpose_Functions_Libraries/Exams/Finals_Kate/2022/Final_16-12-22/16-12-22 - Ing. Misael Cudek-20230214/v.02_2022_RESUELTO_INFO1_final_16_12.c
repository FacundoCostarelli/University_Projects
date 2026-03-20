/**
 * @file    v.02_2022_RESUELTO_INFO1_final_16_12.c
 * @brief   [ESP] Resolución del Profesor - Final 16-12-2022. Estructuras de red con campos de bits.
 *          [ENG] Professor's Resolution - Final 16-12-2022. Network structures with bit fields.
 *
 * @author  Ing. Misael Cudek 
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 

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

void rellenarArray(struct paquete **);
void cargarArray(struct paquete **);
void mostrarArray(struct paquete **);
void liberar(struct paquete **);
void printMAC(char *);
void printPuerto(struct port);

#define TAM 10

/**
 * @brief [ESP] Función principal del resuelto del profesor.
 *        [ENG] Main function for professor's resolution.
 *
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main()
{
    struct paquete * array[TAM];

    rellenarArray(array);
    cargarArray(array);
    mostrarArray(array);
    liberar(array);
    
    return 0;
}

/**
 * @brief [ESP] Asigna memoria dinámica.
 *        [ENG] Allocates dynamic memory.
 */
void rellenarArray(struct paquete ** p)
{
    for(int i = 0; i < TAM; i++)
    {
        p[i] = (struct paquete *)malloc(sizeof(struct paquete));
        if(p[i] == NULL)
        {
           printf("Error de malloc\n");
           exit(1); 
        }
    }
}

/**
 * @brief [ESP] Carga estructuras pseudo-aleatoriamente.
 *        [ENG] Loads structures pseudo-randomly.
 */
void cargarArray(struct paquete ** p)
{
    srand(time(NULL));
    for(int i = 0; i < TAM; i++)
    {
        p[i]->entrada.p0=0; p[i]->entrada.p1=0; p[i]->entrada.p2=0; p[i]->entrada.p3=0;
        p[i]->entrada.p4=0; p[i]->entrada.p5=0; p[i]->entrada.p6=0; p[i]->entrada.p7=0;

        p[i]->salida.p0=0; p[i]->salida.p1=0; p[i]->salida.p2=0; p[i]->salida.p3=0;
        p[i]->salida.p4=0; p[i]->salida.p5=0; p[i]->salida.p6=0; p[i]->salida.p7=0;

        switch(rand()%8)
        {
            case 0: p[i]->entrada.p0=1; break;
            case 1: p[i]->entrada.p1=1; break;
            case 2: p[i]->entrada.p2=1; break;
            case 3: p[i]->entrada.p3=1; break;
            case 4: p[i]->entrada.p4=1; break;
            case 5: p[i]->entrada.p5=1; break;
            case 6: p[i]->entrada.p6=1; break;
            case 7: p[i]->entrada.p7=1; break;
        }

        switch(rand()%8)
        {
            case 0: p[i]->salida.p0=1; break;
            case 1: p[i]->salida.p1=1; break;
            case 2: p[i]->salida.p2=1; break;
            case 3: p[i]->salida.p3=1; break;
            case 4: p[i]->salida.p4=1; break;
            case 5: p[i]->salida.p5=1; break;
            case 6: p[i]->salida.p6=1; break;
            case 7: p[i]->salida.p7=1; break;
        }

        for(int j=0; j < 6; j++)
        {
            p[i]->MACori[j] = (unsigned char)(rand()%256);
            p[i]->MACdes[j] = (unsigned char)(rand()%256);
        }
    }
}

/**
 * @brief [ESP] Muestra la lista de paquetes simulados.
 *        [ENG] Displays list of simulated packets.
 */
void mostrarArray(struct paquete ** p)
{
    printf("MAC destino\t\tMAC origen\t\tPuerto destino\tPuerto origen\n");
    for(int i = 0; i < TAM; i++)
    {
        printMAC(p[i]->MACdes);  printf("\t");
        printMAC(p[i]->MACori);  printf("\t");
        printPuerto(p[i]->entrada);  printf("\t\t");
        printPuerto(p[i]->salida);   printf("\n");
    }
}

void printMAC(char * mac)
{
    for(int i = 0; i < 6; i++)
    {
        printf("%02x", (unsigned char)mac[i]);
        if(i != 5) printf(":");
    }
}

void printPuerto(struct port p)
{
    printf("%c", p.p0 ? '1':'0');
    printf("%c", p.p1 ? '1':'0');
    printf("%c", p.p2 ? '1':'0');
    printf("%c", p.p3 ? '1':'0');
    printf("%c", p.p4 ? '1':'0');
    printf("%c", p.p5 ? '1':'0');
    printf("%c", p.p6 ? '1':'0');
    printf("%c", p.p7 ? '1':'0');
}

void liberar(struct paquete ** p)
{
    for(int i = 0; i < TAM; i++)
    {
        free(p[i]);
        p[i]=NULL;
    }
}
