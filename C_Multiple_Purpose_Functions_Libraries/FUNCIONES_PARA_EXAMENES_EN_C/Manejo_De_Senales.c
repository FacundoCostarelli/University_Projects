/***************ALGORITMO SIMPLE PARA EL MANEJO DE SENALES PARA SALIR DE UN LOOP INFINITO POR TEMPORIZADOR*****************/
#define TEMPORIZADOR 30 //30 o cualquier otro valor, esto es en segundos
#define TRUE 1
#define FALSE 0
//variable global del tipo  volatil
volatile sig_atomic_t flag = TRUE;

//Funcion handler
void misenal(int a)
{
    printf("a = %d\n",a);
    flag = FALSE
    //alarm(5);//Puede descomentarse para recibir una SIGALRM repetidas veces
    
}

//Esto va en el main al principio
//printf("%d\n", EINTR);	
    signal(SIGALRM,misenal);
    alarm(TEMPORIZADOR);
    
    /*BLOQUE DE CODIGO QUE HACE ALGO**/
    
//LOOP infinito     
while( flag == TRUE)
{
        if( flag == FALSE )
        {
            /*BLOQUE DE CODIGO QUE HACE ALGO, EJ: cerrar conexion desde servidor, etc*/
        }
        
        /*BLOQUE DE CODIGO QUE HACE ALGO*/
}

/*****BLOQUE DE CODIGO DE LIMPIEZA DE MEMORIA***/
    
    
//SIGALRM es una signal.
//La funcion signal() recibe el nro de senal como 1er parametro y como 2do parametro recibe un puntero a funcion. Asi le dice al SO que ejecute una determinada funcion "handler" apuntada por el puntero que recibio 2do parametro. De esta manera, se atienda a la signal o interrupcion
//Una vez dentro de la funcion hanlder, se busca cambiar el valor de una variable global volatil y ademas ejecutar la funcion alarm() que recibe como parametro un int asociado a una cantidad en segundos. alarm() le dice al SO que genere una senal, a traves de generar el valor int que ya se encuentra definido por la macro SIGALRM. Esta senal sera generada una vez que finalize el temporizador y sera repetido su disparo tantas veces como sea necesario hasta que con algun bloque de codigo, se deje de ejecutar alarm(). Tambien se puede ejecutar alarm() en el main solamente pero esto lo hara una unica vez 


/***********ALGORITMO COMPLEJO DE MANEJO DE SENALES PARA SALIR DE UN LOOP INFINITO POR TECLADO O POR TEMPORIZADOR************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

volatile sig_atomic_t flag = 0;

void signal_handler(int signum) {
    flag = 1;
}

int main() {
    int resultado,maxfd;
    fd_set readfds; //para guardar los fd que lee select.

    struct timeval timeout; //estructura para el timer de select.
    struct sigaction sa;    //estructura para manejar la señal.

    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;    //con esto no se quedo en select.

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error al configurar el manejador de señales");
        exit(1);
    }


    maxfd = STDIN_FILENO + 1;  //select pide que se le de el maximo fd+1, por lo tanto en caso de usar el fd del socket hay que hacer new_fd+1.

    while (!flag) {
        // Configurar el conjunto de descriptores de archivo para select.
        FD_ZERO(&readfds); //borrar la lista de fds.
        FD_SET(STDIN_FILENO, &readfds); //ingresar la lista de fd al set.

        // Configurar el temporizador para la salida de select cada 5 segundos.
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        // Esperar hasta que se oprima una tecla o el temporizador expire.
        resultado = select(maxfd, &readfds, NULL, NULL, &timeout); //escucho si se modifica algun fd de la lista o si se termian el timer.
        if (resultado == -1) {
            perror("Error en select");
            break;
        } else if (resultado == 0) {
            // El temporizador expiró, imprimir mensaje y regresar a select.
            printf("Han pasado 5 segundos.\n");
            continue;
        }

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            // Se oprimió una tecla, leerla y procesarla.
            char c;
            read(STDIN_FILENO, &c, 1);
            printf("Se oprimió la tecla: %c\n", c);
        }
    }

    printf("Se recibió la señal SIGUSR1, terminando el programa.\n");

    return 0;
}

