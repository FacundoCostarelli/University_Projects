/**
 * @file    Funciones-Server-Cliente.c
 * @brief   [ESP] Archivo fuente de funciones para cliente y servidor. 2do Recup 2023.
 *          [ENG] Client and server common logic source file. 2nd Makeup exam 2023.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "Functions_Server_Client.h"

/**
 * @brief [ESP] Devuelve un número aleatorio enter minimo y máximo, incluyendo límites.
 *        [ENG] Returns a pseudo-random number within minimum and maximum, including limits.
 *
 * @param minimo [ESP] Valor minimo / [ENG] Minimum value
 * @param maximo [ESP] Valor maximo / [ENG] Maximum value
 * @return int   [ESP] Entero pseudo-aleatorio / [ENG] Pseudo-random integer
 */
int aleatorio_en_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
