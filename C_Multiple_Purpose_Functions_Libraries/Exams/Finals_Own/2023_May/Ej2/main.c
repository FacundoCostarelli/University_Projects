/**
 * @file    main.c
 * @brief   [ESP] Programa principal Ejercicio 2: Simulador de parser con pila básica.
 *          [ENG] Main program Exercise 2: Parser simulator with basic stack.
 *
 * @author  Facundo Costarelli
 * @date    2023
 * @course  Informática 1 — UTNBA
 */

#include "Functions.h"

/**
 * @brief [ESP] Función principal.
 *        [ENG] Main function.
 *
 * @return 0 [ESP] Si la ejecución es correcta. / [ENG] If execution is correct.
 */
int main()
{
    char *String = NULL;
    int i = 0, j = 0;
    ssize_t caracteres_leidos = 0;
    char *buffer_aux_pila = NULL;
    
    printf("Ingrese instruccion para el simulador de parser: ");
    caracteres_leidos = getline(&String, 0, stdin);
    
    if( String[caracteres_leidos-1] == '\n')
            String[caracteres_leidos-1] = '\0';

    /* [ESP] Memoria dinámica / [ENG] Dynamic memory */
    buffer_aux_pila = (char *)malloc(caracteres_leidos * sizeof(char) );
    if(buffer_aux_pila == NULL)
    {
            printf("Error asignacion pila\n");
            return ERROR;
    }
    
    /* [ESP] Guardar solo paréntesis en la pila / [ENG] Store only parenthesis in stack */
    for( i = 0, j = 0; i < caracteres_leidos; i++, j++ )
    {
        if(String[i] == '(' || String[i] ==')' )
        {
            buffer_aux_pila[j] = String[i];
        }
    }
    
    /* [ESP] TODO: Comparar si hay misma cantidad y orden correcto 
       [ENG] TODO: Compare if there are same amount and correct order */

    /* [ESP] Liberación memoria / [ENG] Memory release */
    free(buffer_aux_pila);
    free(String);
    
    return 0;
}
