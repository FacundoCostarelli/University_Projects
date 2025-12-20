#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<math.h>
#define TRUE 1

//Prototipo de funciones por enunciado que hay que usar
int funcion1(int i,int n,long double xi, long double xf, long double *x, long double *y);
int funcion2(int i,int n,long double xi, long double xf, long double *x, long double *y);
//Funciones creadas por mi resolver las problematicas y otros calculos
long double Sumatoria_f1( int i, long double x);
long double Sumatoria_f2( int i, long double x);
long double factorial( long double nrofactorial );

int main(void)
{
    int i, n = 0;
    long double xi = 0, xf = 0;
    char opcion;
    char aux;
    int cont_CASES_A = 0;//contador que cuenta la cantidad de veces que se ingresa al CASE A para usar malloc o realloc segun cant de veces de elegir CASE A
    int j;//iterador para printear tabla
    //Creo punteros simples para recorrer arrays dinamicos que contienen los valores x e y de la funcion
    long double *VectorPuntosf1X = NULL;
    long double *VectorPuntosf1Y = NULL;
    long double *VectorPuntosf2X = NULL;
    long double *VectorPuntosf2Y = NULL;
    //Creo un puntero simple temporal para trabajar con memoria dinamica y que almacena temporalmente lo que devuelve malloc y realloc y luego si no existe problemas, entonces se copia esto a cada puntero simple declarado en las lineas de arriba
    long double *PunteroTemporal = NULL;
    
    printf("Bienvenido al menu principal, elija por favor alguna de las opciones\n");
    printf("Escriba \"A\" para: Ingresar datos(n, xi, xf) donde n es la cant de pares de puntos a crear en un rango [xi,xf) , xi = x inicial, xf = x final\n");
    printf("Escriba \"B\" para: Llamar f1\n");
    printf("Escriba \"C\" para: Llamar f2\n");
    printf("Escriba \"D\" para: Salir \n");
    printf("Para salir tambien puede escribir el comando \"ctrl+d\" o \"-1\" \n");
    
    //Menu recursivo utilizando while + getchar +switchcase
    while ( ( opcion = getchar() ) != EOF )//El comando EOF suele ser ctrl+d o -1
    {
        switch(opcion)
        {
            case 'A': case 'a'://Ingreso de datos
            
                 cont_CASES_A++;//Se cuentan la cantidad de veces que se ingresa a este CASE A. Dicha cantidad permitira usar malloc o realloc en CASE B y C al momento de crear vectores dinamicos con memoria dinamica
                 
                 //Carga de datos por teclado
                 printf("Ingrese por favor la cantidad de pares de puntos \"n\" que desea crear con sus funciones:  ");
                 scanf("%i", &n);
                 __fpurge(stdin);
                 printf("Ingrese el valor inicial de entrada \"xi\":  ");
                 scanf("%Lf", &xi);
                 __fpurge(stdin);
                 printf("Ingrese el valor final de entrada \"xf\":  ");
                 scanf("%Lf", &xf);
                 __fpurge(stdin);
                
                printf("Ha finalizado la carga de sus datos correctamente\n.\n.\n.\n");
                 
                printf("Usted esta devuelta en el menu principal\n");
                printf("Escriba \"A\" para: Ingresar datos(n, xi, xf) donde n es la cant de datos, xi = x inicial, xf = x final\n");
                printf("Escriba \"B\" para: Llamar f1\n");
                printf("Escriba \"C\" para: Llamar f2\n");
                printf("Escriba \"D\" para: Salir \n");
                printf("Para salir tambien puede escribir el comando \"ctrl+d\" o \"-1\" \n");
    
                break;
            
            case 'B': case 'b'://Llamar f1
                
                //Proteccion contra eleccion de este case cuanndo el usuario quiere trabajar con la funcion cuando todavia no se ingresaron nunca datos necesarios para pasarlos a la funcion
                if( cont_CASES_A == 0 )
                {
                    printf("Todavia no puede acceder a este apartado hasta que elija al menos una vez, la opcion \"A\"\n");
                    printf("Usted esta devuelta en el menu principal\n");
                    printf("Escriba \"A\" para: Ingresar datos(n, xi, xf) donde n es la cant de datos, xi = x inicial, xf = x final\n");
                    printf("Escriba \"B\" para: Llamar f1\n");
                    printf("Escriba \"C\" para: Llamar f2\n");
                    printf("Escriba \"D\" para: Salir \n");
                    printf("Para salir tambien puede escribir el comando \"ctrl+d\" o \"-1\" \n");
                }
                else
                {
                    //Carga de datos por teclado
                    printf("Ingrese la cantidad de terminos de la sumatoria: ");
                    scanf("%i", &i);
                    __fpurge(stdin);
                    
                    //Algoritmo de solicitud de memoria dinamica, va con malloc si el CASE A solo se hace una vez. Si el usuario se arrepiente o mismo luego de trabajar con los 1eros datos ingresados, desea volver a ingresar nuevos datos, lo que implica acceder mas de una vez al CASE A, entonces se pide memoria dinamica con realloc en base a los nuevos datos ingresados en CASE A. En ambos casos, las cantidad o tamanio del bloque de memoria pedido, depende de "la cantida de pares de puntos x e y que el usario quiere tener en su tabla de valores, dicha cantidad es dada por n ".
                    if( cont_CASES_A == 1)
                    {
                        PunteroTemporal = (long double *)malloc( n * sizeof(long double ));
                        
                        if( PunteroTemporal == NULL )
                        {
                            printf("Hay un error con la asignacion de memoria dinamica\n");
                            return 0;
                        }
                        else
                        {
                            VectorPuntosf1X = PunteroTemporal; 
                        }
                        
                        PunteroTemporal = (long double *)malloc( n * sizeof(long double ));
                        
                        if( PunteroTemporal == NULL)
                        {
                            printf("Hay un error con la asignacion de memoria dinamica\n");
                            return 0;
                        }
                        else
                        {
                            VectorPuntosf1Y = PunteroTemporal;
                        }
                        
                    }
                    else
                    {
                        PunteroTemporal = (long double *)realloc( VectorPuntosf1X, n * sizeof(long double ));
                    
                        if( PunteroTemporal == NULL)
                        {
                            printf("Hay un error con la asignacion de memoria dinamica\n");
                            return 0;
                        }
                        else
                        {
                            VectorPuntosf1X = PunteroTemporal;
                        }
                            
                        PunteroTemporal = (long double *)realloc( VectorPuntosf1Y, n * sizeof(long double ));
                        
                        if( PunteroTemporal == NULL)
                        {
                            printf("Hay un error con la asignacion de memoria dinamica\n");
                            return 0;
                        }
                        else
                        {
                            VectorPuntosf1Y = PunteroTemporal;
                            
                        }
                    }
                    
                    //Algoritmo de printeo para chequear que las direcciones de comienzo de los vectores dinamicos creados en el main, hayan sido dadas por el SO a traves de malloc o realloc correctamente. Estas se enviaran a la funcion. Va en comentarios
                    printf("La direccion de comienzo de VectorPuntosf1X es %p\n", VectorPuntosf1X);
                    printf("La direccion de comienzo de VectorPuntosf1Y es %p\n", VectorPuntosf1Y);
                    
                    aux = funcion1( i, n, xi, xf, VectorPuntosf1X , VectorPuntosf1Y );
                    
                    if( aux == TRUE )
                    {
                        printf("Se llamo exitosamente a f1\n");
                        printf("Su tabla de valores queda como: \n");
                        for( j = 0; j < n; j++ )
                        {
                            printf("%Lf | %Lf \n", *(VectorPuntosf1X + j), *(VectorPuntosf1Y + j) );
                        }
                    }
                    else
                    {
                        printf("Ocurrio un error en el llamado a f1\n");
                        return 0;
                    }
                
                    printf("Usted esta devuelta en el menu principal\n");
                    printf("Escriba \"A\" para: Ingresar datos(n, xi, xf) donde n es la cant de datos, xi = x inicial, xf = x final\n");
                    printf("Escriba \"B\" para: Llamar f1\n");
                    printf("Escriba \"C\" para: Llamar f2\n");
                    printf("Escriba \"D\" para: Salir \n");
                    printf("Para salir tambien puede escribir el comando \"ctrl+d\" o \"-1\" \n");
                    
                }
                
               
                break;
            
            case 'C': case 'c'://Llamar f2
                
                //Proteccion contra eleccion de este case cuanndo el usuario quiere trabajar con la funcion cuando todavia no se ingresaron nunca datos necesarios para pasarlos a la funcion
                if( cont_CASES_A == 0 )
                {
                    printf("Todavia no puede acceder a este apartado hasta que elija al menos una vez, la opcion \"A\"\n");
                    printf("Usted esta devuelta en el menu principal\n");
                    printf("Escriba \"A\" para: Ingresar datos(n, xi, xf) donde n es la cant de datos, xi = x inicial, xf = x final\n");
                    printf("Escriba \"B\" para: Llamar f1\n");
                    printf("Escriba \"C\" para: Llamar f2\n");
                    printf("Escriba \"D\" para: Salir \n");
                    printf("Para salir tambien puede escribir el comando \"ctrl+d\" o \"-1\" \n");
                }
                else
                {
                    //Carga de datos por teclado
                    printf("Ingrese la cantidad de terminos de la sumatoria: ");
                    scanf("%i", &i);
                    __fpurge(stdin);
                    
                    //Algoritmo de solicitud de memoria dinamica, va con malloc si el CASE A solo se hace una vez. Si el usuario se arrepiente o mismo luego de trabajar con los 1eros datos ingresados, desea volver a ingresar nuevos datos, entonces se pide memoria dinamica con realloc en base a los nuevos datos ingresados en CASE A. En ambos casos, las cantidad o tamanio del bloque de memoria pedido, depende de "la cantida de pares de puntos x e y, dicha cantidad es dada por n ". 
                    if( cont_CASES_A == 1)
                    {
                        PunteroTemporal = (long double *)malloc( n * sizeof(long double ));
                        
                        if( PunteroTemporal == NULL )
                        {
                            printf("Hay un error con la asignacion de memoria dinamica\n");
                            return 0;
                        }
                        else
                        {
                            VectorPuntosf2X = PunteroTemporal; 
                        }
                        
                        PunteroTemporal = (long double *)malloc( n * sizeof(long double ));
                        
                        if( PunteroTemporal == NULL)
                        {
                            printf("Hay un error con la asignacion de memoria dinamica\n");
                            return 0;
                        }
                        else
                        {
                            VectorPuntosf2Y = PunteroTemporal;
                        }
                    }
                    else
                    {
                        PunteroTemporal = (long double *)realloc( VectorPuntosf2X, n * sizeof(long double ));
                    
                        if( PunteroTemporal == NULL)
                        {
                            printf("Hay un error con la asignacion de memoria dinamica\n");
                            return 0;
                        }
                        else
                        {
                            VectorPuntosf2X = PunteroTemporal;
                        }
                            
                        PunteroTemporal = (long double *)realloc( VectorPuntosf2Y, n * sizeof(long double ));
                        
                        if( PunteroTemporal == NULL)
                        {
                            printf("Hay un error con la asignacion de memoria dinamica\n");
                            return 0;
                        }
                        else
                        {
                            VectorPuntosf2Y = PunteroTemporal;
                        }
                    }
                    
                    //Algoritmo de printeo para chequear que las direcciones de comienzo de los vectores dinamicos creados en el main, hayan sido dadas por el SO a traves de malloc o realloc correctamente. Estas se enviaran a la funcion. Va en comentarios
                    printf("La direccion de comienzo de VectorPuntosf2X es %p\n", VectorPuntosf2X);
                    printf("La direccion de comienzo de VectorPuntosf2Y es %p\n", VectorPuntosf2Y);
                
                    aux = funcion2( i, n, xi, xf, VectorPuntosf2X , VectorPuntosf2Y );
                    
                    if( aux == TRUE )
                    {
                        printf("Se llamo exitosamente a f2\n");
                        printf("Su tabla de valores queda como: \n");
                        for( j = 0; j < n; j++ )
                        {
                            printf("%Lf | %Lf \n", *(VectorPuntosf2X + j), *(VectorPuntosf2Y + j) );
                        }
                    }
                    else
                    {
                        printf("Ocurrio un error en el llamado a f2\n");
                        return 0;
                    }
                
                    printf("Usted esta devuelta en el menu principal\n");
                    printf("Escriba \"A\" para: Ingresar datos(n, xi, xf) donde n es la cant de datos, xi = x inicial, xf = x final\n");
                    printf("Escriba \"B\" para: Llamar f1\n");
                    printf("Escriba \"C\" para: Llamar f2\n");
                    printf("Escriba \"D\" para: Salir \n");
                    printf("Para salir tambien puede escribir el comando \"ctrl+d\" o \"-1\" \n");
                    
                }
                
                break;
                                
            case 'D': case 'd'://Salir
                
                printf("Usted saldra del programa\n");
                //Libero la memoria dinamica luego de usarla
                free( VectorPuntosf1X );
                free( VectorPuntosf1Y );
                free( VectorPuntosf2X );
                free( VectorPuntosf2Y );
                
                return 0;
                
            case '\n' : case ' ': //ignora estas entradas de teclado
                   
                break;
                
            default: //Para todo el resto de caracteres tira un mensaje de error
                   
                printf("Se ingreso incorrectamente una letra o palabra\n");
                printf("Ingrese devuelta una de las opciones: ");
                    
                break;
                
        }
    }
}

//Esta funcion recibe varios datos que permiten construir la tabla de valores x e y, para printear en pantalla. Esta tabla puede ser pensada en cambio como un vector de puntos x e y que se escribe en un futuro en un software como OCTAVE.
//n representa la cantidad de pares de puntos "x e y" 
//Lo que devuelve esto es ej: 1 entonces significa que se llamo correctamente y quiero volver al menu principal, sino que tire cartel de error
int funcion1(int i,int n,long double xi, long double xf, long double *x, long double *y)
{
    int j;
    //Algoritmo de printeo para chequear que las direcciones de comienzo de los vectores dinamicos creados en el main, hayan sido recibidas correctamente en esta funcion
    printf("La direccion de comienzo del puntero simple x es %p\n", x);
    printf("La direccion de comienzo del puntero simple y es %p\n", y);
                    
    //Cargo el 1er elemento(es decir, en posicion 0) de cada array de valores x e y
    *(x) = xi;
    *(y) = Sumatoria_f1( i, *(x) );
    printf("Las direcciones asociadas a la posicion 0 de cada vector son: %p, %p \n", x, y);
    printf("%Lf, %Lf\n", *(x), *(y) );
    //Algoritmo que carga los 2dos elementos(es decir, en posicion 1) en adelante, en los array de valores x e y
    for( j = 0; *(x+j) < xf && j < n - 1; j++ )
    {
        //Supongamos j = 1, entonces *(x+j+1) se carga el elemento de la posicion 2 del vector de valores x, previamente se lleno el de la pos 1 y 0, por su parte *(y+j+1) se carga el elemento de la posicion 2 del vector de valores y, previamente se lleno el de la pos 0 y 1. Luego j se incrementa y se compara si el valor de x actual cargado recientemente, el de la posocion 2, es decir: *(x+j) es < xf, con j = 2 ahora debido al incremento, esta comparacion con < xf es porque no queremos cargar valores > xf, es decir, valores fuera de rango ingresado por usuario. Ademas se compara que j < n - 1, esto significa que se va comparando la cant de elementos cargados(la cual incrementa luego de ejecutar todo el cuerpo del "for"). Si los elementos a cargar son "n", el 1ero se carga antes del "for", entonces quedan por cargar con el ciclo "for", una cantidad de elementos n - 1. Puede pasar que el ultimo elemento sea < xf y no = o > xf, en general sucedera que el ultimo elemento es < xf pero por ser el ultimo elemento hay que finalizar la carga de elementos. Este problema de que no se puede cargar el ultimo elemento dado como xf, se debe a la formula asociada a "intervalos constantes entre valores x". Dicha formula es (xf-xi)\n, esto hace que entre cada valor de x haya esta "distancia", y que por ende esta distancia exista entre el anteultimo elemento y el ultimo. Esto da como resultado que el ultimo elemento en general < xf. 
        //En resumen, Si se cumplen las condiciones del for, se continua cargando datos. Esto se repite sucesivamente
        
        *(x+j+1) = *(x+j) + ((xf-xi)/n);
        *(y+j+1) = Sumatoria_f1( i, *(x+j+1) );//los datos "y" de la funcion los obtengo con otra funcion
        printf("Las direcciones asociadas a la posicion %i de cada vector son: %p, %p\n", j+1, x+j+1, y+j+1);
        printf("%Lf, %Lf\n", *(x+j+1), *(y+j+1) );
        
    }
    
    //Algoritmo de printeo de las direcciones de cada elementos con los elementos de cada vector de valores c e y. Esto para chequear que el proceso de carga haya sido exitoso. Va con comentarios.
    for( j = 0; j < n; j++ )
    {
        printf("%p \t", x+j);
        printf("%Lf, ", *(x + j) );
    }
    printf("\n");
    for( j = 0; j < n; j++ )
    {
        printf("%p \t", y+j);
        printf("%Lf, ", *(y + j) );
    }
    
    return TRUE;
}

//Esta funcion realiza el algoritmo de sumatoria dado en ejericico 1 de enunciado, lo que devuelve es el valor "y" obtenido de trabajar con la expresion matemaitca mencionada y aca en este caso, el algoritmo.
long double Sumatoria_f1( int i, long double x)
{
    //i es inicilamente la cantidad de terminos de la sumatoria contando desde i = 1. Ej sumatoria desde i = 1 hasta i = 3. Tenemos una operatoria con i = 1, otra con i = 2 y finalmente una con i = 3. Al sumar todas las operatorias, osea, al hacer la sumatoria, entonces se suman 3 operatorias.
    //Sin embargo, en el enunciado de este ejercicio, la sumatoria tiene sub indice i = 0 , es decir, que la 1er operatoria no se da para i = 1, sino antes, y si queremos mantener la misma cantidad de terminos de sumatoria o misma cantidad de operatorias sumadas, es decir 3, debemos terminar tambien una unidad de indice antes. Por lo que el supraindice valdra i = 2. Luego, por cuestiones matematicas y de codeo, llamaremos subindice a i, tomando el valor incial de 0 y que ira iterando en el ciclo for, donde el supraindice sera k = i -1 por lo explicado anteriormente, tomando por ej k = 2 si seguimos el ej mencionado
    int k = i - 1;
    int nro_de_terminos = ( k - 0 ) + 1;//formula matematica para hallar la cantidad de terminos en una sumatoria sabiendo lso valores del subindice y supraindice
    long double y, nrofactorial;//declaro "y" a retornar y una variable que toma el valor de la formula de nro a aplicar factorial
    
    //ciclo for que calcula la sumatoria de enunciado
    for( i = 0, y = 0; i < nro_de_terminos; i++ )
    {
        nrofactorial = 2 * (long double) i + 1;
        y = y + ( ( powl( (long double) (-1), (long double) i ) )   *  ( ( powl( x , nrofactorial ) ) /  ( factorial( nrofactorial ) ) ) );
        printf("%Lf\n", y);
    }
    
    return y;
}

//Esta funcion recibe varios datos que permiten construir la tabla de valores x e y, para printear en pantalla. Esta tabla puede ser pensada en cambio como un vector de puntos x e y que se escribe en un futuro en un software como OCTAVE.
//n representa la cantidad de pares de puntos "x e y" 
//Lo que devuelve esto es ej: 1 entonces significa que se llamo correctamente y quiero volver al menu principal, sino que tire cartel de error
int funcion2(int i,int n,long double xi, long double xf, long double *x, long double *y)
{
    int j;
    //Algoritmo de printeo para chequear que las direcciones de comienzo de los vectores dinamicos creados en el main, hayan sido recibidas correctamente en esta funcion
    printf("La direccion de comienzo del puntero simple x es %p\n", x);
    printf("La direccion de comienzo del puntero simple y es %p\n", y);
                    
    //Cargo el 1er elemento(es decir, en posicion 0) de cada array de valores x e y
    *(x) = xi;
    *(y) = Sumatoria_f2( i, *(x) );
    printf("Las direcciones asociadas a la posicion 0 de cada vector son: %p, %p \n", x, y);
    printf("%Lf, %Lf\n", *(x), *(y) );
    //Algoritmo que carga los 2dos elementos(es decir, en posicion 1) en adelante, en los array de valores x e y
    for( j = 0; *(x+j) < xf && j < n - 1; j++ )
    {
        //Supongamos j = 1, entonces *(x+j+1) se carga el elemento de la posicion 2 del vector de valores x, previamente se lleno el de la pos 1 y 0, por su parte *(y+j+1) se carga el elemento de la posicion 2 del vector de valores y, previamente se lleno el de la pos 0 y 1. Luego j se incrementa y se compara si el valor de x actual cargado recientemente, el de la posocion 2, es decir: *(x+j) es < xf, con j = 2 ahora debido al incremento, esta comparacion con < xf es porque no queremos cargar valores > xf, es decir, valores fuera de rango ingresado por usuario. Ademas se compara que j < n - 1, esto significa que se va comparando la cant de elementos cargados(la cual incrementa luego de ejecutar todo el cuerpo del "for"). Si los elementos a cargar son "n", el 1ero se carga antes del "for", entonces quedan por cargar con el ciclo "for", una cantidad de elementos n - 1. Puede pasar que el ultimo elemento sea < xf y no = o > xf, en general sucedera que el ultimo elemento es < xf pero por ser el ultimo elemento hay que finalizar la carga de elementos. Este problema de que no se puede cargar el ultimo elemento dado como xf, se debe a la formula asociada a "intervalos constantes entre valores x". Dicha formula es (xf-xi)\n, esto hace que entre cada valor de x haya esta "distancia", y que por ende esta distancia exista entre el anteultimo elemento y el ultimo. Esto da como resultado que el ultimo elemento en general < xf. 
        //En resumen, Si se cumplen las condiciones del for, se continua cargando datos. Esto se repite sucesivamente
        
        *(x+j+1) = *(x+j) + ((xf-xi)/n);
        *(y+j+1) = Sumatoria_f2( i, *(x+j+1) );//los datos "y" de la funcion los obtengo con otra funcion
        printf("Las direcciones asociadas a la posicion %i de cada vector son: %p, %p\n", j+1, x+j+1, y+j+1);
        printf("%Lf, %Lf\n", *(x+j+1), *(y+j+1) );
        
    }
    
    //Algoritmo de printeo de las direcciones de cada elementos con los elementos de cada vector de valores c e y. Esto para chequear que el proceso de carga haya sido exitoso. Va con comentarios.
    for( j = 0; j < n; j++ )
    {
        printf("%p \t", x+j);
        printf("%Lf, ", *(x + j) );
    }
    printf("\n");
    for( j = 0; j < n; j++ )
    {
        printf("%p \t", y+j);
        printf("%Lf, ", *(y + j) );
    }
    
    return TRUE;
}

//Esta funcion realiza el algoritmo de sumatoria dado en ejericico 1 de enunciado, lo que devuelve es el valor "y" obtenido de trabajar con la expresion matemaitca mencionada y aca en este caso, el algoritmo.
long double Sumatoria_f2( int i, long double x)
{
    //i es inicilamente la cantidad de terminos de la sumatoria contando desde i = 1. Ej sumatoria desde i = 1 hasta i = 3. Tenemos una operatoria con i = 1, otra con i = 2 y finalmente una con i = 3. Al sumar todas las operatorias, osea, al hacer la sumatoria, entonces se suman 3 operatorias.
    //Sin embargo, en el enunciado de este ejercicio, la sumatoria tiene sub indice i = 0 , es decir, que la 1er operatoria no se da para i = 1, sino antes, y si queremos mantener la misma cantidad de terminos de sumatoria o misma cantidad de operatorias sumadas, es decir 3, debemos terminar tambien una unidad de indice antes. Por lo que el supraindice valdra i = 2. Luego, por cuestiones matematicas y de codeo, llamaremos subindice a i, tomando el valor incial de 0 y que ira iterando en el ciclo for, donde el supraindice sera k = i -1 por lo explicado anteriormente, tomando por ej k = 2 si seguimos el ej mencionado
    int k = i - 1;
    int nro_de_terminos = ( k - 0 ) + 1;//formula matematica para hallar la cantidad de terminos en una sumatoria sabiendo lso valores del subindice y supraindice
    long double y, nrofactorial;//declaro "y" a retornar y una variable que toma el valor de la formula de nro a aplicar factorial
    
    //ciclo for que calcula la sumatoria de enunciado
    for( i = 0, y = 0; i < nro_de_terminos; i++ )
    {
        nrofactorial = 2 * (long double) i;
        y = y + ( ( powl( (long double) (-1), (long double) i ) )   *  ( ( powl( x , nrofactorial ) ) /  ( factorial( nrofactorial ) ) ) );
        printf("%Lf\n", y);
    }
    
    return y;    
}

//Funcion portable que calcula el factorial de un numero, cualquier numero que se le pase por copia, lo recibe, lo trabaja con el algoritmo de abajo y devuelve dicho numero trabajdo, es decir, devuelve el resultado de la operacion factorial. El algoritmo es sencillo, consiste en armar el factorial de un numero ej 5 de la sig forma: 1.1 + 1.1 . 2+ 1.1.2 . 3+ 1.1.2.3 . 4+ 1.1.2.3.4 . 5. El resultado final sera lo dado por 1.1.2.3.4.5
long double factorial( long double nrofactorial ) 
{
    
    long double factorial = 1, ninicial;
    
    for( ninicial = 1; ninicial <= nrofactorial; ninicial++ )
    {
        factorial *= ninicial;//calculo el factorial de 2*i+1 de la formula original de la sumatoria de f1 y lo mismo para el factorial de 2*i de la sumatoria de f2. Esta funcion propia factorial es reutilizable, ya que proviene de otro codigo. En caso de 0! entonces el cuerpo del "for" no se ejecuta ya que no se cumple la condicion y entonces se retorna factorial = 1
    }
    
    return factorial;
}
