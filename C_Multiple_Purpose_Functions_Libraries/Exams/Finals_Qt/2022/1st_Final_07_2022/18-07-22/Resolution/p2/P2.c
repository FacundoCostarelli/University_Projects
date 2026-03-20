/**
 * @file    P2.c
 * @brief   [ESP] Archivo fuente contando incidencias alfabéticas.
 *          [ENG] Source code measuring alphabetic incidence inside an input file.
 *
 * @author  Facundo Costarelli
 * @date    2022
 * @course  Informática 1 — UTNBA
 */

#include "my_header.h"

/**
 * @brief [ESP] Verifica incidencias alfabéticas guardando conteos a memoria contigua local.
 *        [ENG] Scans file payload storing alphabetic char frequencies.
 */
int main(int argc, char *argv[])
{
	int a, fd, listado['z' - 'a' + 1], i;
	
    /* [ESP] Chequea argumento para abrir FD seguro / [ENG] Checks mapped file descriptor index constraints */
    if (argc < 2) {
        printf("Error: Ingrese un archivo como argumento\n");
        return 1;
    }

	fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0) {
        printf("Error al abrir archivo\n");
        return 1;
    }
    
	for(i = 0; i < ('z' - 'a' + 1); i++)
		listado[i] = 0;

	a = contador(fd, listado);
	if(a < 0)
	{
		printf("error: %d\n", a);
		return 0;
	}
	
	for(i = 0; i < ('z' - 'a' + 1); i++)
		printf("%c:%i veces\n", 'a' + i, listado[i]);			
	
    close(fd);
    return 0;
}

/**
 * @brief [ESP] Itera los bytes del archivo leyendo una celda contigua midiendo offsets para charactéres lícitos.
 *        [ENG] Iterates the file bytes testing each read step parsing bounds over lower & upper char offsets.
 *
 * @param archivo [ESP] Descriptor de archivo / [ENG] OS level file descriptor unit
 * @param vector  [ESP] Vector acumulador / [ENG] Accumulator vector tracking occurrences
 * @return int [ESP] Código de validación / [ENG] Feedback return code
 */
int contador(int archivo, int *vector)
{
	int cont;
	char letra;
	
	if(!vector) return -1;
	if(archivo < 0) return -2;	
	
	do
	{
		cont = read(archivo, &letra, 1);
		if(cont > 0)
		{
			if(letra >= 'a' && letra <= 'z')
			{
				vector[letra - 'a']++;
			}
			if(letra >= 'A' && letra <= 'Z')
            {
				vector[letra - 'A']++;
            }
		}
	} while(cont > 0);	

	return 0;
}
