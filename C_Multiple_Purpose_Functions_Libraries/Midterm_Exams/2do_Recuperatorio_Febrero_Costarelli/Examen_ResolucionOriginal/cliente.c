#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8010	/* El puerto donde se conectará, servidor */
#define BACKLOG 10	/* Tamaño de la cola de conexiones recibidas */




int	conectar (int, char **);

int	Open_conection (struct sockaddr_in *, int); /* Función que crea la conexión*/

int	Aceptar_pedidos (int);	/* Función que acepta una conexión entrante*/



int main(int argc, char **argv)
{
    int fd;
    char  dest[15];
    char nombre[20] = "Facundo";
    char apellido[20] = "Costarelli";
    //check;
    //struct sockaddr_in cliente_addr;
    if(argc != 3)
    {
        printf("Error. Ha ingresado mal los comandos. Re-ejecute de la siguiente forma: <ejecutable> <legajo> <dni>")
        return -1;
    }
    return 0;

    fd = conectar(PORT, dest);

    //Esta funcion recibe como parametro el fd del socket cliente, el legajo, el DNI, el nombre del alumno y el apellido. La funcion debe enviar la informacion del cliente al servidor
    enviar(fd, argv[1],argv[2],nombre,apellido);



    return 0;
}

 /*
    fd = socket(AF_INET,SOCK_STREAM,TCP);

           int bind(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen);

    check = bind(fd, (struct sockaddr *)&sin_addr)
    if( check == 0 )
        printf("Se dio nombre correctamente al socket cliente\n");
    else if( check == -1 )
    {
        printf("Error en la asignacion del nombre al socket cliente\n");
        return check;
    }

    fd = conectar
    */


int conectar (int port, char dest[])
{

	int	sockfd;
	struct hostent *he;	/* Se utiliza para convertir el nombre del host a su dirección IP */
	struct sockaddr_in their_addr;  /* dirección del server donde se conectará */

	/* Convertimos el nombre del host a su dirección IP */
	if ((he = gethostbyname ((const char *) dest)) == NULL)
	{
		herror("Error en Nombre de Host");
		exit(1);
	}

/* Creamos el socket */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("Error en creación de socket");
		exit(1);
	}

/* Establecemos their_addr con la direccion del server */
	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(port);
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(their_addr.sin_zero), 8);

/* Intentamos conectarnos con el servidor */
	if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
	{
		perror("Error tratando de conectar al server");
		exit(1);
	}
	return sockfd;
}


int Open_conection ( struct sockaddr_in * my_addr, int port)
{
	int	sockaux;	/*socket auxiliar*/
	int	aux; 		/*variable auxiliar*/

	/*Crea un socket y verifica si hubo algún error*/
	if ((sockaux = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		fprintf(stderr, "Error en función socket. Código de error %s\n", strerror(sockaux));
		return -1;
	}

/* Asignamos valores a la estructura my_addr */

	my_addr->sin_family = AF_INET;		/*familia de sockets INET para UNIX*/
	my_addr->sin_port = htons(port);	/*convierte el entero formato PC a
						entero formato network*/
	my_addr->sin_addr.s_addr = INADDR_ANY;	/* automaticamente usa la IP local */
	bzero(&(my_addr->sin_zero), 8);		/* rellena con ceros el resto de la
						 estructura */

	/* Con la estructura sockaddr_in completa, se declara en el Sistema que este proceso escuchará pedidos por la IP y el port definidos*/
	if ( (aux = bind (sockaux, (struct sockaddr *) my_addr, sizeof(struct sockaddr))) == -1)
	{
		fprintf(stderr, "Error en función bind. Código de error %s\n", strerror(aux));
		return -1;
	}
	/* Habilitamos el socket para recibir conexiones, con una cola de conexiones en espera que tendrá como máximo el tamaño especificado en BACKLOG*/
	if ((aux = listen (sockaux, BACKLOG)) == -1)
	{
		fprintf(stderr, "Error en función listen. Código de error %s\n", strerror(aux));
		return -1;
        }
	return sockaux;
}


int Aceptar_pedidos (int sockfd)
{
	int newfd; 	/* Por este socket duplicado del inicial se transaccionará*/
        struct sockaddr_in their_addr;  /* Contendra la direccion IP y número de puerto del cliente */
	unsigned int sin_size = sizeof(struct sockaddr_in);

	/*Se espera por conexiones ,*/
	if ((newfd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size)) == -1)
	{
		fprintf(stderr, "Error en función accept. Código de error %s\n", strerror(newfd));
		return -1;
	}
	else
	{
		printf  ("server:  conexión desde:  %s\n", inet_ntoa(their_addr.sin_addr));
		return newfd;
	}
}
