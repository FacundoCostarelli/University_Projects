/**
 * @file    ProgramaDePruebaParaCopiar.c
 * @brief   [ESP] Archivo para ser escaneado por el extractor de comentarios.
 *          [ENG] File waiting to be scanned by comment-remover script.
 *
 * @author  Facundo Costarelli
 * @date    2021
 * @course  Informática 1 — UTNBA
 */

/*Programa de prueba*/

/**
 * @brief [ESP] Función principal de prueba con comentarios intactos.
 *        [ENG] Test main function carrying some comments intact.
 */
int main(void)
{ 
   int a = 1, b = 2;	
   int sum;

   // Imprimo un mensaje
   printf("Este es un programa de prueba\n");

   // Sumo 2 valores
   sum = a + b;

   /* Imprimo un resultado */
   printf("El resultado es sum: %d\n", sum);
   
   return 0;
}
