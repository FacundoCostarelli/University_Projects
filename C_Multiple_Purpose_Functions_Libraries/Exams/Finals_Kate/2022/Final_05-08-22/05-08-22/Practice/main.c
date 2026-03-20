/**
 * @file    main.c
 * @brief   [ESP] Archivo main. Práctica Final 05-08-2022.
 *          [ENG] Main file. Practice Final 05-08-2022.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "functions.h"

/**
 * @brief [ESP] Función principal de encriptación práctica.
 *        [ENG] Main function for practical encryption.
 *
 * @return 0 [ESP] Ejecución exitosa. / [ENG] Successful execution.
 */
int main (int argc, char**argv)
{
    int fd;
    encriptado_t aux;
    
    if (argc < 3)
    {
		printf("uso: ./%s <path> <texto_a_encriptar>", argv[0]);
		exit(0);
    }
    
    srand (getpid());
    
    fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0666);
    
    if (fd < 0)
    {
        printf ("error abriendo %s\n", argv[1]);
        exit (0);
    }
       
    aux.desplazamiento = encriptar (argv[2], aux.txt);
    write (fd, &aux, sizeof(aux));
    
    printf ("se encripto el msj %s con el codigo %d\n", aux.txt, aux.desplazamiento);
	
    return 0;
}
