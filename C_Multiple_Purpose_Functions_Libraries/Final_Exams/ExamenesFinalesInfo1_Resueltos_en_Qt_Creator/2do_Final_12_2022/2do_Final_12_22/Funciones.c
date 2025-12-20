#include"Funciones.h"

int CargaArrayConPunteros_A_Paquetes(struct paquete **ArrPackages)
{
    int i = 0;
    /*
    *ArrPackages = (struct paquete **)malloc(CANTIDAD_PAQUETES * sizeof(struct paquete *));
    if(*ArrPackages == NULL)
    {
        printf("Error en la asignacion de memoria dinamica en el array de punteros a struct paquetes\n");
        return ERROR;
    }
    */
    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        ArrPackages[i] = (struct paquete *)malloc(CANTIDAD_PAQUETES * sizeof(struct paquete));
        if(ArrPackages[i] == NULL)
        {
            printf("Error en la asignacion de memoria dinamcia para cada puntero struct paquete * que se encuentra en el array de punteros\n");
            return ERROR;
        }
    }

    return EXITO;
}

int CargaDeMiembrosDeUnPaquete(struct paquete **ArrPackage)
{

    CargaMAC_origen(ArrPackage);
    CargarMAC_destino(ArrPackage);
    CargarPuerto_Entrada(ArrPackage);
    CargarPuerto_Salida(ArrPackage);

    return EXITO;
}

void CargaMAC_origen(struct paquete **ArrPackage)
{
    int i = 0;
    int j = 0;
    unsigned char select = 0;

    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        for( j = 0; j < 6; j++ )
        {
            select = aleatorio_en_rango('0','1');
            if( select == '0' )
                ArrPackage[i]->MACori[j] = aleatorio_en_rango('0','9');
            else if( select == '1' )
                ArrPackage[i]->MACori[j] = aleatorio_en_rango('A','Z');
        }
    }

    return;
}

void CargarMAC_destino(struct paquete **ArrPackage)
{
    int i = 0;
    int j = 0;
    unsigned char select = 0;

    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        for( j = 0; j < 6; j++ )
        {
            select = aleatorio_en_rango('0','1');
            if( select == '0' )
                ArrPackage[i]->MACdes[j] = aleatorio_en_rango('0','9');
            else if( select == '1' )
                ArrPackage[i]->MACdes[j] = aleatorio_en_rango('A','Z');
        }
    }

    return;
}

void CargarPuerto_Entrada(struct paquete **ArrPackage)
{
    int i = 0;
    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        ArrPackage[i]->entrada.p0 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->entrada.p1 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->entrada.p2 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->entrada.p3 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->entrada.p4 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->entrada.p5 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->entrada.p6 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->entrada.p7 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
    }

    return;
}

void CargarPuerto_Salida(struct paquete **ArrPackage)
{
    int i = 0;

    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        ArrPackage[i]->salida.p0 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->salida.p1 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->salida.p2 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->salida.p3 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->salida.p4 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->salida.p5 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->salida.p6 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
        ArrPackage[i]->salida.p7 = rand()%2;//aleatorio_en_rango((unsigned char)0,(unsigned char)1);
    }

    return;
}


// Devuelve un número aleatorio entre minimo y maximo, incluyendo a minimo y maximo.
//Se puede usar ints, char, unsigned char, etc. Solo hay que identificar el tipo de
//dato de cada parametro y el retorno segun lo que se quiera hacer. EJ: Todo es INT, o todo es
//unsigned char, o todo es char, etc.

unsigned char aleatorio_en_rango(unsigned char minimo, unsigned char maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void ImprimirContenidoPaquete(struct paquete **ArrPackages)
{
    int i = 0;

    printf("MAC_Destino MAC_Origen Puerto_Salida Puerto_Entrada\n");
    for( i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        //Impresion de MAC_Destino y MAC_Origen
        printf("%.6s      %.6s      ",ArrPackages[i]->MACdes,ArrPackages[i]->MACori);

        //Impresion de Puerto_Salida
        printf("%d",ArrPackages[i]->salida.p7);
        printf("%d",ArrPackages[i]->salida.p6);
        printf("%d",ArrPackages[i]->salida.p5);
        printf("%d",ArrPackages[i]->salida.p4);
        printf("%d",ArrPackages[i]->salida.p3);
        printf("%d",ArrPackages[i]->salida.p2);
        printf("%d",ArrPackages[i]->salida.p1);
        printf("%d      ",ArrPackages[i]->salida.p0);

        //Impresion de Puerto_Entrada
        printf("%d",ArrPackages[i]->entrada.p7);
        printf("%d",ArrPackages[i]->entrada.p6);
        printf("%d",ArrPackages[i]->entrada.p5);
        printf("%d",ArrPackages[i]->entrada.p4);
        printf("%d",ArrPackages[i]->entrada.p3);
        printf("%d",ArrPackages[i]->entrada.p2);
        printf("%d",ArrPackages[i]->entrada.p1);
        printf("%d",ArrPackages[i]->entrada.p0);

        printf("\n");
    }
}

void LiberarMemoriaDePaquetes(struct paquete **ArrPackages)
{
    int i = 0;

    for(i = 0; i < CANTIDAD_PAQUETES; i++ )
    {
        free(ArrPackages[i]);
        ArrPackages[i] = NULL;
    }
    return;
}




