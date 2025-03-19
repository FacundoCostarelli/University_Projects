#include<stdio.h>
#include<stdlib.h>
#include <stdio_ext.h>

double ** crearmatrizcondatos( double ***P, int filas, int columnas);
//void cargamatriz( char ***P, int filas, int columnas );
void cargamatrizconnumerosdouble( double ***P, int filas, int columnas );
void mostrarmatriz( double ***P, int filas, int columnas );
void liberarmatriz( double ***P, int filas );
void multiplicarmatrizes( double ***P, double ***P1, double ***P2, int filas1, int columnas1, int filas2, int columnas2, char *PunteroaCantidadefilasmatricesresultantes );
void sumarmatrices( double ***P, double ***P1, double ***P2, int filas1, int columnas1, int filas2, int columnas2, char *PunteroaCantidadefilasmatricessumadas );

//Este programa permite crear matrices dinamicamente ,con datos predeterminadas; y guardarlas en un vector dinamico que se lo recorre con puntero triple. Las matrices seran punteros dobles tal que apuntan y permiten recorrer un array dinamico que almacena las filas. Estas filas a su vez son punteros simples tal que apuntan y permiten recorrer un array dinamico que almacena los datos guardados de cada posicion de la matriz

//Este programa permite ademas, por un lado: a) realizar la multiplicacion de las 2 primeras matrices ingresadas y mostrar dicha matriz resultante y b) realizar la suma de las 2 primeras matrices ingresadas y mostrar dicha matriz. ES IMPORTANTE DESTACAR que se realizo todo con datos char, se puede escalar el programa para soportar datos int, float, etc. Se hizo asi primero ya que la idea era cargar valores que puedan utilizarse con su representacion de letras del alfabeto

//Como se podra ver, la carga de la matriz, el printeo de la misma, la liberacion de cierta memoria dinamica utilizada, la suma de matrices, la multiplicacion de matrices, todo se hace a traves de funciones. 

//En particular en el main, se pide memoria dinamica con malloc y realloc segun el caso, aunque tambien se utiliza memoria estatica cuando es requerido. Tambien se realiza la liberacion de cierta memoria dinamica utilizada.

int main()
{
    int filas, columnas;
    //char **M, char **N;//punteros dobles que poseen la direccion de comienzo del vector de punteros simples
    char decision;
    int cont = 0, cont1 = 0;
    double ***vectordepunterosdoblesdinamicos;
    //para acceder a cada puntero doble, hay que apuntar a la direccion de cada variable puntero doble a traves de un puntero triple. Es triple porque apunta a direcciones de memoria de variables punteros dobles.
    double ***Punterotemporal;//utilizo Punterotemporal para almacenar lo que devuelve realloc, analizar si es o no NULL y luego asignar lo que almacena Punterotemporal al puntero vectordepunterosdoblesdinamicos
    char *PunteroaCantidadeFilas;//creo un array dinamico de datos int de filas que lo recorro con un puntero simple, esto para poder distinguir una matriz de otra al liberar la memoria usada, y otros usos
    char *Punterotemporal1;//mismo uso que Punterotemporal pero para PunteroaCantidadeFilas
    char *PunteroaCantidadeColumnas;//creo un array dinamico de datos int de columnas que lo recorro con un puntero simple, esto para poder distinguir una matriz de otra al liberar la memoria usada, y otros usos
    char *Punterotemporal2;//mismo uso que Punterotemporal pero para PunteroaCantidadeColumnas
    //creo un array dinamico que almacena 2 matrices las cuales se operaran entre si con suma, resta o multiplicacion segun caseo
    double ***vectordepunterosdoblesdinamicosparaoperacionesmatriciales;
    //creo un array dinamico que alamcena las matrices resultantes de las respectivas operaciones matriciales
    double ***vectordepunterosdoblesdinamicosmatricesresultantes;
    //creo un array dinamico que almacena la cantidad de filas de las matrices resultantes de las respectivas operaciones
    char *PunteroaCantidadefilasmatricesresultantes;
    //creo un array dinamico que almacena la cantidad de columnas de las matrices resultantes de las respectivas operaciones
    char *PunteroaCantidadecolumnasmatricesresultantes;
    //creo 2 variables que almacenan el "nro de orden de matriz"(es deciri, 1ero,2do,3ero,etc) de acuerdo al vector que almacena matrices
    int matrizseleccionada1 = 0;
    int matrizseleccionada2 = 0;
    //creo una variable que almacena la opcion a,b o c de las matrices con las cuales se va a operar
    char decisionoperacionmatriz;
    //cre un contador que cuenta la cantidad de matrices resultantes
    int contmatrizesresultantes = 0;
    
    //En un futuro Habria que crear una vector dinamico de 2 matrizes de para sumas, restas y multiplicaciones, para que el usuario de todas las matrices ingresadas, elija(ingresando por teclado 2 posiciones una en I y otra en J, del vector que almacena matrices ingresadas) cuales 2 quiere utilizar para operaciones, estas 2 habria que cargarlas en este vector de operaciones. EN Dicho vector luego de cada calculo, habria que liberarlo de las matrices cargadas, para poder usar el mismo espacio devuelta. Cada resultado habria que guardarlo en otro vector dinamico, ej de matrices resultantes para poder almacenar esa info importante. Tambien para poder realizar las operaciones mencionadas con estas matrices resultantes entre si o entre las ingresadas y resultantes. En ambos casos habria que crear vectores dinamicos que almacenen las filas y columnas de las matrices resultantes
    
    //Luego de crear la 1er matriz, el usuario podria equivocarse y querer operar con solo una matriz, hay que poner algun algoritmo por cada case que detecte que solo se creo 1 matriz y que tire algun mensaje de error y de ahi lo mande al menu generico devuelta tal que vea nuevamente todas las opciones y vaya a ingresar una 2da matriz.
    //Inmediatamente Luego de tratar de operar con las 2 primeras matrices, puede pasar que hayan errores por no respetar las reglas matematicas de operacion tal que haya que salir del programa para re ingresar matrices o puede pasar que se cree 1 o mas matrices resultantes. En tal caso, al finalizar cada uno de los cases, se puede pedir al usuario si quiere re-operar devuelta donde se puede hacer que elija 2 de entre las matrices ingresadas y resultantes, para operar o mismo enviar con un goto a la seccion de creacion de matrices para agregar otras nuevas y nuevamente ejecutar los cases de operaciones
    
    //En si mismo solo se necesitan 3 vectores dinamicos. El 1ero sera el de matrices creadas por teclado, este se libera recien al finalizar todo el programa.El 2do es para operar con las matrices elijidas, este se libera luego de cada operacion para poder re-utilizarlo en otra operacion. El 3ero es el de matrices resultantes de operaciones, este se libera recien al finalizar todo el programa.
    
    printf("**** Bienvenido al siguiente programa en cual va a poder realizar distintas operaciones matriciales elegiendo cualquiera de las siguientes opciones ****\n\n");
    printf("**** Para finalizar el programa y su menu, usted puede ingresar el comando EOF = End of File cuando lo desee, pero siempre en la seccion del menu ****\n\n"); 
    printf("Opcion \"1\": crear una matriz\nOpcion \"2\": sumar las dos primeras matrices ingresadas\nOpcion \"3\": restar las dos primeras matrices ingresadas\nOpcion \"4\": multiplicar las 2 primeras matrices ingresadas\nOpcion \"5\": cambiar la 1er martiz ingresada por la resultante de alguna de las operaciones anteriores\nOpcion \"6\": salida alternativa del programa\n "); 
    
    
    //EOF es con ctrl+d, armo un menu recursivo con while y switchcase
    while( ( decision = getchar() ) != EOF )
    {
        switch(decision)
        {
            case 1://Creacion de matrices dinamicas A, B, C, D, etc 
                
                printf("Ingrese la cantidad de filas: ");
                scanf("%d", &filas);
                __fpurge(stdin);
                printf("Ingrese la cantidad de columnas: ");
                scanf("%d", &columnas);
                __fpurge(stdin);
                
                cont1 = cont1 + 1;
                
                if( cont1 == 1 )
                {
                    vectordepunterosdoblesdinamicos = ( double ***)malloc(sizeof(double ***));//pido memoria dinamica con malloc para crear un vector de matrices que almacene 1 matriz, esta sera la 1era de varias o la unica segun el caso
                    
                    //proteccion contra NULL de malloc
                    if( vectordepunterosdoblesdinamicos == NULL )
                    {
                        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias");
                        return 0;
                    }
                    else
                    {
                        *(vectordepunterosdoblesdinamicos) = crearmatrizcondatos( vectordepunterosdoblesdinamicos, filas, columnas );
                    }
                    //pido memoria dinamica con malloc para crear un vector que almacena la cantidad de filas de la matriz mencionada
                    PunteroaCantidadeFilas = (char *)malloc(sizeof(char *));
                    
                    //proteccion contra NULL de malloc
                    if( PunteroaCantidadeFilas == NULL )
                    {
                        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias");
                        return 0;
                    }
                    else
                    {
                        *(PunteroaCantidadeFilas) = filas;
                    }
                    //pido memoria dinamica con malloc para crear un vector que almacena la cantidad de columnas de la matriz mencionada
                    PunteroaCantidadeColumnas = (char *)malloc(sizeof(char *));
                    //proteccion contra NULL de malloc
                    if( PunteroaCantidadeColumnas == NULL )
                    {
                        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias");
                        return 0;
                    }
                    else
                    {
                        *(PunteroaCantidadeColumnas) = columnas;
                    }
                }
                
                if( cont1 > 1 )
                {
                // printf("Matriz de la posicion [0] antes de realloc es = %p\n", *(vectordepunterosdoblesdinamicos));
                    
                    
                    //pido memoria dinamica con realloc para redimensionar el vector de matrices que almacena ahora mas de 1 matriz
                    Punterotemporal = (double ***)realloc( vectordepunterosdoblesdinamicos, (double)cont1 * sizeof(double ***));
                    
                    //proteccion contra NULL de realloc
                    if( Punterotemporal == NULL )
                    {
                        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias");
                        return 0;
                    }
                    else
                    {
                        vectordepunterosdoblesdinamicos = Punterotemporal;
                    }
                    
                    
                    /*
                    printf("Matriz de la posicion [0] despues de realloc es = %p\n", *(vectordepunterosdoblesdinamicos + 0));
                    printf("Direccion de la matriz [0] es = %p\n", vectordepunterosdoblesdinamicos );
                    printf("Antes de crear una nueva matriz \n");
                    printf("Matriz de la posicion[%d] = %p\n", (cont1-1),*(vectordepunterosdoblesdinamicos + (cont1 - 1)));
                    printf("Direccion de la matriz[%d] es = %p\n", (cont1-1), vectordepunterosdoblesdinamicos + (cont1 - 1) );
                    */
                    
                    
                    //Creo y asigno cada nueva matriz a una posicion de memoria del vector de matrices
                    *(vectordepunterosdoblesdinamicos + (cont1-1) ) = crearmatrizcondatos( vectordepunterosdoblesdinamicos + (cont1-1), filas, columnas );
                    
                    
                    /*
                    printf("Despues de crear una nueva matriz\n");
                    printf("Matriz de la posicion [0] es = %p\n", *(vectordepunterosdoblesdinamicos + 0));
                    printf("Direccion de la matriz [0] es = %p\n", vectordepunterosdoblesdinamicos );
                    printf("Matriz de la posicion[%d] = %p\n", (cont1-1), *(vectordepunterosdoblesdinamicos + (cont1 - 1)));
                    printf("Direccion de la matriz[%d] es = %p\n", (cont1-1), vectordepunterosdoblesdinamicos + (cont1 - 1) );
                    */
                    
                    
                    //pido memoria dinamica con realloc para redimensionar el vector de cantidad de filas que almacena ahora mas de una cantidad de filas ya que hay mas de 1 matriz donde cada una tiene su cantidad propia de filas
                    Punterotemporal1 = (char *)realloc( PunteroaCantidadeFilas, (char)cont1 * sizeof(char *) );
                    
                    //Proteccion contra NULL de realloc
                    if( Punterotemporal1 == NULL )
                    {
                        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias");
                        return 0;
                    }
                    else
                    {
                        PunteroaCantidadeFilas = Punterotemporal1;
                    }
                    
                    //Asigno cada nueva cantidad de filas de cada nueva matriz, a una posicion de memoria del vector de cantidad de filas
                    *(PunteroaCantidadeFilas + (cont1 - 1)) = filas;
                    
                    //pido memoria dinamica con realloc para redimensionar el vector de cantidad de columnas que almacena ahora mas de una cantidad de columnas ya que hay mas de 1 matriz donde cada una tiene su cantidad propia de columnas
                    Punterotemporal2 = (char *)realloc( PunteroaCantidadeColumnas, (char)cont1 * sizeof(char *) );
                    
                    //Proteccion contra NULL de realloc
                    if( Punterotemporal2 == NULL )
                    {
                        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias");
                        return 0;
                    }
                    else
                    {
                        PunteroaCantidadeColumnas = Punterotemporal2;
                    }
                    //Asigno cada nueva cantidad de columnas de cada nueva matriz, a una posicion de memoria del vector de cantidad de columnas
                    *(PunteroaCantidadeColumnas + (cont1 - 1)) = columnas; 
                    
                }   
        
                
                break;
                
            case 2://Sumatoria de las 2 primeras matrices ingresadas
                
                if( cont1 == 1 )
                {
                    printf("No puede operar solo con una matriz cargada. Debe minimamente ingresar una 2da matriz. Por favor, ingrese la opcion 1 nuevamente: ");
                }
                else
                {
                   
                    printf("Cuales matrices va a operar?\n");
                    printf("a) Matrices ingresadas\n");
                    printf("b) Matrices resultantes\n");
                    printf("c) Matrices ingresadas con resultantes\n");
                    printf("Su opcion es: ");
                    scanf("%c", &decisionoperacionmatriz);
                    __fpurge(stdin);
                    
                    //EOF es con ctrl+d, armo un menu recursivo con while y switchcase
                    while( ( decisionoperacionmatriz = getchar() ) != EOF )
                    {
                        switch(decisionoperacionmatriz)
                        {
                            case 'a':
                                
                                if( contmatrizesresultantes == 0 )
                                {
                                    printf("Recordando el orden creciente desde la posicion 0 inclusive, de las matrices existentes, elija cuales 2 de ellas va a sumar:\n");
                                    scanf("%i", &matrizseleccionada1);
                                    __fpurge(stdin);
                                    scanf("%i", &matrizseleccionada2);
                                    __fpurge(stdin);
                                    
                                    //creo un vector dinamico de matrices resultantes(EN PRINCIPIO CON UNA SOLA MATRIZ RESUlTANTE), luego se puede realocalizar para agregar mas matrices resultantes 
                                    vectordepunterosdoblesdinamicosmatricesresultantes = (double ***)malloc(sizeof(double ***));
                                    
                                    //proteccion contra NULL de malloc
                                    if( vectordepunterosdoblesdinamicosmatricesresultantes == NULL )
                                    {
                                        printf("Ha ocurrido un error con la asignacion de memoria, tomar medidas necesarias");
                                        return 0;
                                    }
                                    else
                                    {
                                        //creo array dinamico que almacena la cantidad de filas de las matrices resultantes , dicho vector se carga a traves de la funcion sumarmatrices
                                        PunteroaCantidadefilasmatricesresultantes = (char *)malloc(sizeof(char *));
                                        
                                        //proteccion contra NULL de malloc
                                        if( PunteroaCantidadefilasmatricesresultantes == NULL )
                                        {
                                            printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias");
                                            return 0;
                                        }
                                        else
                                        {
                                            //Chequeo que la suma matricial sea posible siguiendo la regla de que A y B deben ser pertenecientes a R^mxn donde A + B = C(mxn) donde m de A y m de B deben ser iguales asi como tambien n de A y n de B deben ser iguales
                                            Etiqueta1:
                                            if( *(PunteroaCantidadeFilas + matrizseleccionada1) != *(PunteroaCantidadeFilas + matrizseleccionada2)   ||  *(PunteroaCantidadeColumnas + matrizseleccionada1) != *(PunteroaCantidadeColumnas + matrizseleccionada2) )
                                            {
                                                do
                                                {
                                                    printf("Esta suma matricial no se puede hacer. Si desea continuar en el programa ingrese \"S\", si desea re-elegir otras matrices o cambiar el orden de lugar para operar, ingrese \"R\".  Recuerde seguir la regla \"A(mxn) + B(mxn) = C(mxn) con mA = mB y nA = nB\"\n");
                                                    scanf("%c", &decisionoperacionmatriz);
                                                    __fpurge(stdin);
                                                
                                                    if( decisionoperacionmatriz == 'S' )
                                                        continue;
                                                    if( decisionoperacionmatriz == 'R' )
                                                    {
                                                        printf("Recordando el orden creciente desde la posicion 0 inclusive, de las matrices existentes, elija cuales 2 de ellas va a sumar:\n");
                                                        scanf("%i", &matrizseleccionada1);
                                                        __fpurge(stdin);
                                                        scanf("%i", &matrizseleccionada2);
                                                        __fpurge(stdin);
                                                        goto Etiqueta1;
                                                    }
                                                }while( decisionoperacionmatriz != 'S' && decisionoperacionmatriz != 'R' );
                                            }
                                            else
                                            {
                                                //realizo la suma de matrices a traves de una funcion, para ello le paso por referencia: la direccion o "cajita" correspondiente del vector dinamico que almacenara la matriz resultante, las direcciones o "cajitas" del vector dinamico que almacena las matrices existentes elegidas. Le paso ademas las cantidad de filas y columnas de las 2 matrices elegidas.
                                                sumarmatrices( vectordepunterosdoblesdinamicosmatricesresultantes + contmatrizesresultantes, vectordepunterosdoblesdinamicos + matrizseleccionada1, vectordepunterosdoblesdinamicos + matrizseleccionada2, *(PunteroaCantidadeFilas + matrizseleccionada1), *(PunteroaCantidadeColumnas + matrizseleccionada1), *(PunteroaCantidadeFilas + matrizseleccionada2), *(PunteroaCantidadeColumnas + matrizseleccionada2), PunteroaCantidadefilasmatricesresultantes + contmatrizesresultantes);
                                                
                                                //Muestro  la cantidad de filas de la matriz resultante de sumar
                                                printf("La cantidad de filas de esta matriz resultante de sumar es: \n");
                                                printf("| %i | ", *(PunteroaCantidadefilasmatricesresultantes+ contmatrizesresultantes) );
                                                printf("\n");
                                                
                                                contmatrizesresultantes++;
                                            }
                                        }
                                    }
                                }
                                 
                                break;
                                
                            case 'b':
                                
                                if( contmatrizesresultantes == 0 )
                                {
                                    printf("Todavia no se creo ninguna matriz resultante, por lo que esta opcion aun no esta disponible\n");
                                }
                                else
                                {
                                    printf("Recordando el orden creciente de las matrices existentes, elija cuales 2 de ellas va a sumar:\n");
                                    scanf("%i", &matrizseleccionada1);
                                    __fpurge(stdin);
                                    scanf("%i", &matrizseleccionada2);
                                    __fpurge(stdin);
                                }
                                
                                break;
                                
                            case 'c':
                                
                                if( contmatrizesresultantes == 0 )
                                {
                                    printf("Todavia no se creo ninguna matriz resultante, por lo que esta opcion aun no esta disponible\n");
                                }
                                else
                                {
                                    printf("Recordando el orden creciente de las matrices existentes, elija cuales 2 de ellas va a sumar:\n");
                                    scanf("%i", &matrizseleccionada1);
                                    __fpurge(stdin);
                                    scanf("%i", &matrizseleccionada2);
                                    __fpurge(stdin);
                                }
                                //aca va else
                                
                                break;
                                
                            case '\n' : case ' ': //ignora estas entradas de teclado
                    
                                break;
                    
                            default: //Para todo el resto de caracteres tira un mensaje de error
                    
                                printf("Se ingreso alguna letra o palabra, lo cual es incorrecto\n");
                                printf("Ingrese devuetla una de las opciones usando los caracteres propuestos: ");
                        
                                break;
                        }
                        
                    }
                    
                    
                   
                    
                    
                    
                }
                break
                
            case 3://Resta de las 2 primeras matrices ingresadas
                
                if( cont1 == 1 )
                {
                    printf("No puede operar solo con una matriz cargada. Debe minimamente ingresar una 2da matriz. Por favor, ingrese la opcion 1 nuevamente: ");
                    
                }
                //aca va else
                
                break;
                
            case 4://Multiplicacion de las 2 primeras matrices ingresadas
                
                if( cont1 == 1 )
                {
                    printf("No puede operar solo con una matriz cargada. Debe minimamente ingresar una 2da matriz. Por favor, ingrese la opcion 1 nuevamente: ");
                    
                }
                else
                {
                    //creo un vector dinamico de matrices resultantes de multiplicar matrices(EN PRINCIPIO CON UNA SOLA MATRIZ RESUlTANTE, luego se puede realocalizar para agregar mas matrices resultantes y se puede hacer algoritmo para que usario elija cuales quiere multiplicar)
                    vectordepunterosdoblesdinamicosmatricesmultiplicadas = (double ***)malloc(sizeof(double ***));
                        
                    //proteccion contra NULL de malloc
                    if( vectordepunterosdoblesdinamicosmatricesmultiplicadas == NULL )
                    {
                        printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias");
                        return 0;
                    }
                    else
                    {
                        //creo array dinamico que almacena la cantidad de filas de las matrices resultantes de multipliaciones, dicho vector se carga a traves de la funcion multiplicarmatrizes
                        PunteroaCantidadefilasmatricesresultantes = (char *)malloc(sizeof(char *));
                            
                        //proteccion contra NULL de malloc
                        if( PunteroaCantidadefilasmatricesresultantes == NULL )
                        {
                            printf("Ha ocurrido un error con la asignacion de memoria, tomar medias necesarias");
                            return 0;
                        }
                        else
                        {
                            //Chequeo que el producto matricial sea posible siguiendo la regla A(mxn) . B(nxp) = C(mxp) donde n de A y n de B deben ser iguales
                            if( *(PunteroaCantidadeColumnas + 0) != *(PunteroaCantidadeFilas + 1) )
                            {
                            printf("Hay un producto matricial que no se puede hacer, continue con la ejecucion  del programa y al final re-ejecute y re-ingrese eligiendo otras matrices y/o el orden, con que se van a multiplicar siguiendo la regla \"A(mxn) . B(nxp) = C(mxp) con nA = nB \" \n");
                            //Aca en un futuro habria que hacer un goto al lugar del programa en que se piden las 2 matrices para operar 
                            }
                            else
                            {
                                //realizo multiplicacion de matrices a traves de una funcion, para ello le paso por referencia: la direccion o "cajita" correspondiente del vector dinamico que almacenara la matriz resultante, la direcciones o "cajitas" del vector dinamico que almacena las 2 primeras matrices ingresadas. Le paso ademas las cantidad de filas y columnas de la 1era y 2da matriz ingresada. Y tambien la cajita o direccion que almacena la cantidad de filas de la matriz resultante
                                multiplicarmatrizes( vectordepunterosdoblesdinamicosmatricesmultiplicadas, vectordepunterosdoblesdinamicos, vectordepunterosdoblesdinamicos + 1, *(PunteroaCantidadeFilas), *(PunteroaCantidadeColumnas), *(PunteroaCantidadeFilas + 1), *(PunteroaCantidadeColumnas + 1), PunteroaCantidadefilasmatricesresultantes );
                                    
                                //Muestro el vector dinamico que contiene la cantidad de filas de la matriz resultante de multiplicar
                                printf("El vector de cantidad de filas de matrices resultantes de multiplicaciones es: \n");
                                printf("| %i | ", *(PunteroaCantidadefilasmatricesresultantes) );
                                printf("\n");
                            
                                //libero la memoria dinamica utilizada por la matriz resultante de la multiplicacion
                                liberarmatriz( vectordepunterosdoblesdinamicosmatricesmultiplicadas, *(PunteroaCantidadefilasmatricesresultantes) );
                            }
                                //libero la memoria dinamica usada por el vector de cant de filas de matrices reultantes de multiplicaciones que lo recorria con puntero simple
                                free(PunteroaCantidadefilasmatricesresultantes);
                                //libero la memoria dinamica usada por el vector de matrices resultantes de multiplicaciones que lo recorria con un puntero triple
                                free(vectordepunterosdoblesdinamicosmatricesmultiplicadas);
                        }
                    }
            
                }
                break;
                
            case 5://Cambiar la primera matrix ingresada A por la C resultante de alguna de las operaciones anteriores
                printf("Esta funcion aun no esta disponible");
                if( cont1 == 1 )
                {
                    printf("No puede operar solo con una matriz cargada. Debe minimamente ingresar una 2da matriz. Por favor, ingrese la opcion 1 nuevamente: ");
                    
                }
                //aca va else
                break;
                
            case 6://caso alternativo al EOF como salida del programa
                
                printf("Usted va salir del programa");
                
                return 0;
                
                break;
                
            case '\n' : case ' ': //ignora estas entradas de teclado
                   
                break;
                
            default: //Para todo el resto de caracteres tira un mensaje de error
                   
                printf("Se ingreso alguna letra o palabra, lo cual es incorrecto\n");
                printf("Ingrese devuetla una de las opciones usando los numeros propuestos: ");
                    
                break;
        }
    }
        
//Coloco una etiqueta de salto para la instruccion "goto", esta en particular es para saltear la re-pregunta de la estructura del Do-while luego de que no se pueden multiplicar 2 matrices por no cumplirse la regla apropieda  "Etiqueta1:"

//Coloco una etiqueta de salto para goto, esta en particular es para saltear la estructura del Do-while luego de que no se pueden multiplicar 2 matrices por no cumplirse la regla apropieda "Etiqueta2:"


    //Muestro el vector dinamico que contiene la cantidad de filas de las matrices ingresadas con numeros ingresados por teclado 
    printf("El vector de cantidad de filas de matrices ingresadas es: \n");
    for(cont = 0; cont < cont1; cont++ )
    {
        printf("| %i | \t", *(PunteroaCantidadeFilas + cont));
    }
    printf("\n");
    
    //Muestro el vector dinamico que contiene la cantidad de columnas de las matrices ingresadas con numeros ingresados por teclado
    printf("El vector de cantidad de columnas de matrices ingresadas es: \n");
    for(cont = 0; cont < cont1; cont++ )
    {
        printf("| %i | \t", *(PunteroaCantidadeColumnas + cont));
    }
    printf("\n");
    
   
    //Busco liberar con estructura de repeticion, la memoria dinamica ocupada por cada matriz ingresada con numeros predeterminados a traves de liberar las columnas, filas y la matriz en si misma, todo esto utilizando una funcion denominada "liberarmatriz"
    for( cont = 0; cont < cont1; cont++ )
    {
        //printf("Cont antes de liberar una matriz = %d\n",cont);
        //printf("Se va a liberar la memoria\n");
        
        //libero la memoria usada por las matrices a traves de una funcion
        liberarmatriz( vectordepunterosdoblesdinamicos + cont, *(PunteroaCantidadeFilas + cont) );
        
        //printf("Se libero la memoria de la matriz %d\n", cont );
        //printf("Cont despues de liberar una matriz = %d\n", cont);
        
    }
    
    //libero el vector dinamico de matrices, es decir, punteros dobles que lo recorria con puntero triple
    free(vectordepunterosdoblesdinamicos);
    //libero el vector dinamico de cant de filas de matrices ingresadas, que lo recorria con un puntero simple
    free(PunteroaCantidadeFilas);
    //libero el vector dinamico de cant de columnas de matrices ingresadas, que lo recorria con un puntero simple
    free(PunteroaCantidadeColumnas);
    
    for( cont = 0; cont < contmatrizesresultantes, cont++ )
    {
        
        //printf("Cont antes de liberar una matriz = %d\n",cont);
        //printf("Se va a liberar la memoria\n");
        
        //libero la memoria dinamica utilizada por las matrizes resultantes 
        liberarmatriz( vectordepunterosdoblesdinamicosmatricesresultantes + cont, *(PunteroaCantidadefilasmatricesresultantes + cont) );
                                                
        //printf("Se libero la memoria de la matriz %d\n", cont );
        //printf("Cont despues de liberar una matriz = %d\n", cont);
        
    }
    
    //libero la memoria dinamica usada por el vector de matrices resultantes que lo recorria con un puntero triple
    free(vectordepunterosdoblesdinamicosmatricesresultantes);
    //libero la memoria dinamica usada por el vector de cant de filas de matrices resultantes que lo recorria con puntero simple
    free(PunteroaCantidadefilasmatricesresultantes);
    
    
    
    printf("Toda la memoria dinamica usada y solicitada, se ha liberado correctamente\n");
    printf("Gracias por utilizar este software\n");
    return 0;
}




double ** crearmatrizcondatos( double ***P, int filas, int columnas)
{
    //char ***P es quien recibe las direcciones &M, &N, que estan dadas por malloc y realloc en el main
    //*P debera ser = M, N, etc osea las matrices/punteros dobles;
    *(P) = (double **)malloc( (double)filas * sizeof(double **) );
    
    //cargo la matriz a traves de una funcion, envio la direccion donde se almacena cada matriz, es decir &M,&N, etc. Esto a traves de P ya que es puntero triple y contiene estas direcciones &M, &N, etc dadas por malloc y realloc
    cargamatrizconnumerosdouble( P, filas, columnas );
    //printeo la matriz  a traves de una funcion
    mostrarmatriz( P, filas, columnas );
    
    return *(P);
    
}

void mostrarmatriz( double ***P, int filas, int columnas )
{
    int i, j;
    //muestro la matriz a traves de mostrar cada dato de cada posicion fila-columna
    for( i = 0; i < filas; i++ )
    {
        for( j = 0; j < columnas; j++ )
        {
            //printf("| %c | \t", *(*((*P)+i)+j)  );
            printf("| %lf |\t", (*(*((*P)+ i)+j)) );
        }
        printf("\n");
    }
}

void cargamatrizconnumerosdouble( double ***P, int filas, int columnas )
{
    //este algoritmo carga con numeros del tipo dato double 
    int i, j;
    double numero = 1;
    //cargo el vector de punteros simples, es decir, cada elemento sera un puntero simple que apunta a la direccion de comienzo de una fila, la longitud de la fila depende de la cantidad de columnas.
    for( i = 0; i < filas; i++ )
    {
        /*a la izquierda son los punteros simples de filas y a la derecha lo que da malloc de direccion de comienzo de cada fila, el largo de las filas depende de cant de columnas */
        *((*P) + i) = (double *)malloc( (double)columnas * sizeof(double *) ); 
    }
    //cargo la matriz a traves de cargar cada fila con sus respectivas columnas
    for( i = 0; i < filas; i++ )
    {
        for( j = 0; j < columnas; j++ )
        {
            *(*((*P)+ i)+j) = numero;
            numero++;
        }
    }
}

void multiplicarmatrizes( double ***P, double ***P1, double ***P2, int filas1, int columnas1, int filas2, int columnas2, char *PunteroaCantidadefilasmatricesresultantes )
{
    int i, j, n, k;
    
    int filasmatrizresultante, columnasmatrizresultante;
  
        filasmatrizresultante = filas1;
        columnasmatrizresultante = columnas2;
        n = columnas1;
        //cargo el vector dinamico de cant de filas de la matriz resultante de multiplicar
        *(PunteroaCantidadefilasmatricesresultantes) = filasmatrizresultante;
        //creo la matriz resultante primero cargandola con datos de numeros char y mostrandola para verificar que se crea adecuadamente
       printf("Su matriz resultante se creo en primera instancia correctamente, para ello se cargo con numeros predeterminados: \n");
       *(P) = crearmatrizcondatos( P, filasmatrizresultante, columnasmatrizresultante);
       printf("\n");
       //Cargo a la matriz creada ahora con la nueva informacion siguiendo la siguiente regla o cuenta: A.B = C perteneciente a R^mxp tal que csub: ij = Sumatoria(desde k=1 a n) de "asub: ik . bsub: kj" con A perteneciente a R^mxn y B perteneciente a R^nxp
       for( i = 0; i < filasmatrizresultante; i++ )
       {
        
           for( j = 0; j < columnasmatrizresultante; j++ )
           {
                (*(*((*P) + i) +j )) = 0;
                
               for( k = 0; k < n; k++ )
               {
                    (*(*((*P) + i) + j)) = ((*(*((*P1) + i) + k)) * (*(*((*P2) + k) + j))) + (*(*((*P) + i) + j));
                   // printf(" |%i| \t", (int)(*(*((*P) + i) + j))  );
               }
           }
       }
    //muestro la matriz resultante de la multiplicacion a traves de una funcion
    printf("Su matriz resultante luego de los calculos correspondientes es: \n");
    mostrarmatriz( P, filasmatrizresultante, columnasmatrizresultante );
    
}

void sumarmatrices( double ***P, double ***P1, double ***P2, int filas1, int columnas1, int filas2, int columnas2, char *PunteroaCantidadefilasmatricessumadas )
{
     int i, j;
    
    int filasmatrizresultante, columnasmatrizresultante;
  
        filasmatrizresultante = filas1;
        columnasmatrizresultante = columnas2;
        //cargo el vector dinamico de cant de filas de la matriz resultante de sumar
        *(PunteroaCantidadefilasmatricessumadas) = filasmatrizresultante;
        //creo la matriz resultante primero cargandola con datos de numeros char y mostrandola para verificar que se crea adecuadamente
       printf("Su matriz resultante se creo en primera instancia correctamente, para ello se cargo con numeros predeterminados: \n");
       *(P) = crearmatrizcondatos( P, filasmatrizresultante, columnasmatrizresultante);
       printf("\n");
       //Cargo a la matriz creada ahora con la nueva informacion siguiendo la siguiente regla o cuenta: A+B = C perteneciente a R^mxn tal que csub: ij = asub: ij + bsub: ij para todo i,j con A y B pertenecientes a R^mxn
       for( i = 0; i < filasmatrizresultante; i++ )
       {
        
           for( j = 0; j < columnasmatrizresultante; j++ )
           {
                (*(*((*P) + i) + j)) = ((*(*((*P1) + i) + j)) + (*(*((*P2) + i) + j)));
                // printf(" |%i| \t", (*(*((*P) + i) + j))  );
           }
       }
    //muestro la matriz resultante de la suma a traves de una funcion
    printf("Su matriz resultante luego de los calculos correspondientes es: \n");
    mostrarmatriz( P, filasmatrizresultante, columnasmatrizresultante );

}

void liberarmatriz( double ***P, int filas ) 
{
    /*
    printf("Direccion de la matriz a liberar en la funcion \"liberarmatriz\" es = %p\n", P);
    
    printf("La matriz a liberar es \"matriz\": %p\n", *P);
    printf("La cantidad de filas de esta matriz es: %d\n", filas);
    */
    
    int i;
    //libero cada fila con sus columnas de la matriz recibida
    for( i = 0; i < filas; i++ )
    {
        free((*((*P) + i)));
    }
    
    //printf("Se liberaron correctamente las columnas y  filas\n");
    
    //libero el vector de filas, osea libero el vector de punteros simples
    free((*P));
    
    //printf("Se libero la memoria correctamente\n");
    
}
