#include"Funciones-Server-Cliente.h"

// Devuelve un número aleatorio entre minimo y maximo, incluyendo a minimo y maximo
int aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}


