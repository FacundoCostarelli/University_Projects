/**
 * ==========================================================================
 * reverse_array.c — Integer Array Reversal Function
 * ==========================================================================
 * [ESP] Función que invierte el orden de los elementos de un array de enteros.
 *       Incluye un programa driver de prueba.
 *
 * [ENG] Function that reverses the order of elements in an integer array.
 *       Includes a test driver program.
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

void Revertir_Int_Array(int *Array, int length)
{
    int i = 0;
    int aux = 0;
    /*Algoritmo de reversion*/
    for( i = 0; i < (length/2); i++ )
    {
        /*Guardo en una variable aux el elemento del Array con index iterando en forma ascendente
          desde le inicio del array*/
        aux = Array[i];
        /*Guardo en la posicion i del Array, indexado en forma ascendente, el elemento del array
         *pero ahora indexando en forma descendente*/
        Array[i] = Array[length - i - 1];
        /*Guardo el elemento en aux en la posicion length-i-1 del array, indexado en forma descendente*/
        Array[length - i - 1] = aux;
    }
    return;
}

//Driver para funcion Revertir_Int_Array
int main()
{
    int array[] = {1,2,3,4};
    int largo = 4;

    Revertir_Int_Array(array,largo);

    for( int i = 0; i < largo; i++ )
    {
        printf("|%d| ",array[i]);
    }
    printf("\n");
    return 0;
}
