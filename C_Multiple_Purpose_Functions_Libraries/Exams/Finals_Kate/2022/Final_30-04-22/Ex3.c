/**
 * @file    Ej3.c
 * @brief   [ESP] Ejercicio 3 - Final 30-04-2022. Impresión de estadísticas por canal.
 *          [ENG] Exercise 3 - Final 30-04-2022. Printing statistics per channel.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include<stdio.h>

/**
 * @brief [ESP] Prototipo. Imprime porcentaje de 1's lógico en canales.
 *        [ENG] Prototype. Prints percentage of logical 1's per channel.
 */
void print_stats( int counts[], int total);

/**
 * @brief [ESP] Función principal del Ejercicio 3.
 *        [ENG] Main function for Exercise 3.
 *
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main(void)
{

    return 0;
}

/**
 * @brief [ESP] Convierte la cantidad de valores (en 0) en porcentajes de estado "1".
 *        [ENG] Converts zeroed-value amount into "1" states percentage.
 *
 * @param counts [ESP] Arreglo con la cuenta de '0's / [ENG] Array storing '0's count
 * @param total  [ESP] Total de iteraciones / [ENG] Total iterations
 */
void print_stats( int counts[], int total )
{
    /* [ESP] counts_aux guardará las ocurrencias de 1s (total - 0s) */
    /* [ENG] counts_aux will store 1s occurrences (total - 0s) */
    int counts_aux[16]; // Fixed calculation
    int i;

    for( i = 0; i < 16; i++ )
        counts_aux[i] = total - counts[i];

    printf("Channel #0\t%.2f%%\n", (float)(counts_aux[0] * 100) / total);
    printf("Channel #1\t%.2f%%\n", (float)(counts_aux[1] * 100) / total);
    printf("Channel #2\t%.2f%%\n", (float)(counts_aux[2] * 100) / total);
    printf("Channel #3\t%.2f%%\n", (float)(counts_aux[3] * 100) / total);
    printf("Channel #4\t%.2f%%\n", (float)(counts_aux[4] * 100) / total);
    printf("Channel #5\t%.2f%%\n", (float)(counts_aux[5] * 100) / total);
    printf("Channel #6\t%.2f%%\n", (float)(counts_aux[6] * 100) / total);
    printf("Channel #7\t%.2f%%\n", (float)(counts_aux[7] * 100) / total);
    printf("Channel #8\t%.2f%%\n", (float)(counts_aux[8] * 100) / total);
    printf("Channel #9\t%.2f%%\n", (float)(counts_aux[9] * 100) / total);
    printf("Channel #10\t%.2f%%\n", (float)(counts_aux[10] * 100) / total);
    printf("Channel #11\t%.2f%%\n", (float)(counts_aux[11] * 100) / total);
    printf("Channel #12\t%.2f%%\n", (float)(counts_aux[12] * 100) / total);
    printf("Channel #13\t%.2f%%\n", (float)(counts_aux[13] * 100) / total);
    printf("Channel #14\t%.2f%%\n", (float)(counts_aux[14] * 100) / total);
    printf("Channel #15\t%.2f%%\n", (float)(counts_aux[15] * 100) / total);

}
