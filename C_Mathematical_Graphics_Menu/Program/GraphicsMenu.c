/*ESP
 * @brief Proyecto creado en un único archivo main.c cuyo programa grafica diferentes funciones matemáticas.
 * 
 * Este programa permite al usuario elegir entre diferentes tipos de funciones matemáticas siendo
 * estas: Rectas, Cuadráticas, Polinomios, Hiperbolas, Módulos, Logarítmos Naturales con Series de Taylor
 * Seno, Coseno y Tangente, estos 3 con Series de Maclaurin.
 * Es posible calcular multiples puntos, definir los coeficientes y cantidad de términos por entrada de comandos
 * de main. Luego se generan archivos de salida con los datos y comandos necesarios para grafica en Octave.
 * Dicho gráfico abarca diversas funciones en una misma ventana particionada como matriz de hasta 
 * 9 subventanas o lugares.
 * 
 * @attention  
 * 
 * Es posible graficar una recta tangente derivada en un punto "a" interior del dominio
 * de una funcion original seleccionada previamente. Sin embargo, actualmente esto último solo está 
 * disponible para la función Cuadratica. Por lo que se le pide al usuario que en todos los demas casos, 
 * elija la opcion "N"(NO) a la pregunta de graficar recta tg derivada.
 * Además, no siempre sucede pero puede pasar que si el octave al abrir multiples ventanas, no grafica 
 * inmediatamente la Cuadratica con su recta tg, entonces debmos dar algunos cliks con el mouse como 
 * tratando de "arrastrar" esos clicks en dicha ventana, luego aparece correctamente el grafico. 
 * Sino, otra forma de solucionar esto es clikear el boton de "save and run" multiples veces con la ventana 
 * minimizada, hasta que en el cuadro de la cuadratica, aparezca con su recta tg en "a".
 * Mas abajo se presenta un algoritmo fallido de proteccion contra cant de caracteres excedidios
 * en el nombre del archivo de salida. En cualquier caso si se excede, la computadora arroja "invalid encoding" 
 * en el nombre del archivo creado y permite continuar la ejecucion del programa de forma normal
 * pero ya teniendo un error de base en la creacion del archivo .m por lo cual, lo ejecutado no 
 * se podrá leer ni graficar.
 * El grafico de la tang, su forma depende de: 
 *  - Si comienza la gráfica en -89 a 89 grados. 
 *  - La cantidad de términos donde una cantidad muy grande pasados de los 30, arroja "nan" 
 *    en algunos valores del vector de puntos. 
 *  - La cantidad de puntos que en general con un 10<=n<=20 deberia funcionar sin problema 
 *    y con una cant de puntos de entre 10 a 20. 
 */

/*ENG
 * @brief Project created in a single main.c file whose program graphs different mathematical functions.
 * 
 * This program allows the user to choose between different types of mathematical functions such as:
 * Straight lines, Quadratics, Polynomials, Hyperbolas, Modules, Natural Logarithms with Taylor Series
 * Sine, Cosine, and Tangent, these 3 with Maclaurin Series.
 * It is possible to calculate multiple points, define the coefficients and number of terms by inputting commands
 * from main. Output files are then generated with the data and commands necessary for graphics in Octave.
 * This graph covers various functions in the same window partitioned as a matrix of up to 
 * 9 sub-windows or places.
 * 
 * @attention  
 * 
 * It is possible to graph a tangent line derived at a point "a" within the domain
 * of a previously selected original function. However, currently, this is only 
 * available for the Quadratic function. Therefore, the user is asked to choose the option "N"(NO) 
 * for the question of graphing the derived tangent line in all other cases.
 * Additionally, it does not always happen, but it may occur that if Octave opens multiple windows, 
 * it does not immediately graph the Quadratic with its tangent line, then we must give some clicks with the mouse 
 * as if trying to "drag" those clicks in that window, then the graph appears correctly. 
 * Otherwise, another way to solve this is to click the "save and run" button multiple times with the window 
 * minimized until the Quadratic graph appears with its tangent line in "a".
 * Below is a failed algorithm for protection against exceeding the character limit
 * in the output file name. In any case, if it exceeds, the computer throws "invalid encoding" 
 * in the created file name and allows the program to continue executing normally
 * but already having a base error in the creation of the .m file, so what is executed cannot 
 * be read or graphed.
 * The graph of the tangent depends on: 
 *  - If the graph starts from -89 to 89 degrees. 
 *  - The number of terms where a very large number exceeding 30, throws "nan" 
 *    in some values of the point vector. 
 *  - The number of points that generally with a 10<=n<=20 should work without problems 
 *    and with a number of points between 10 to 20 it should be also fine. 
 */


#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio_ext.h> //ESP: Solo para Linux Enviroment. ENG: Only for Linux Enviroment.
#include <math.h>



//ESP: Definición del tamaño máximo del nombre del archivo de salida con formato ".m"
//ENG: Defines the maximum size for the output file name with format ".m".
#define largo 50 


// ESP: Funcion que calcula el largo del vector "nombre" cargado por el usuario.
// ENG: Function that calculates the length of the "nombre" array loaded by the user. 
// int LongitudFinalDeNombre( char arreglo[], int i );

//ESP: Funcion que calcula el largo de cualquier vector.
//ENG: Function that calculates the length of any array. 
//int LongitudDelArreglo ( char arreglo[largo] );

// Declaración de funciones
/*ESP 
 * @brief Declara las funciones utilizadas en el programa.
 */

/*ENG
 * @brief Declares the functions used in the program.
 */
void DatosRecta( float *m, float *b, float *Xm, float *XM, float *puntos );
void VectorpuntosRecta( int *fd, char *M, int *cantvectores, float m, float b, float Xm, float XM, float puntos );
float Recta( float m, float x, float b );
void VectorPuntosyDatosRectaDadaPor2Puntos( int *fd, char *M, int *cantvectores );

void DatosCuadratica( float *coef1, float *coef2, float *coef3, float *Xmin, float *Xmax, float *puntos1 );
void VectorpuntoCuadratica( int *fd, char *M, int *cantvectores, float coef1, float coef2, float coef3, float Xmin, float Xmax, float puntos1 );
float Cuadratica( float coef1, float coef2, float coef3, float x1 );
void VectorDatosyPuntosRectaTangenteEnUnPuntoDeCuadratica( int *fd, char *M, float *Xmin, float *Xmax, float coef1, float coef2, float coef3 );
float RectaTgDerivada( float xrtg, float a, float pendiente_en_a, float imagen_en_a );

void DatosPolinomio( float Coeficientes[], int n );
void VectorPuntosPolinomio( float *VectorCoefPolinomio, int n, int *fd, char *M, int *cantvectores );
float Polinomio( float *VectorCoefPolinomio, float xp, int n );

void VectorPuntosyDatosHiperbola( int *fd, char *M, int *cantvectores );
float Hiperbola( float xh, float a, float b, float c, float d );

void VectorPuntosyDatosModulo( int *fd, char*M, int *cantvectores );
float Modulo( float xmod, float a, float b, float c );

void VectorPuntosyDatosSerieTaylorLn( int *fd, char *M, int *cantvectores, int nmax );
float SerieTaylorLn( int  nmax, float xln );

void VectorPuntosyDatosSerieMaclaurinSen( int *fd, char *M, int *cantvectores, int nmax );
float SerieMaclaurinSen( int nmax, float xsen );

//ESP: Funcion compartida por la serie de Maclaurin de Sen(x) y Cos(x).
//ENG: Function shared by the Maclaurin Series of Sen(x) and Cos(x).
float factorial( int nrofactorial );

void VectorPuntosyDatosSerieMaclaurinCos( int *fd, char *M, int *cantvectores, int nmax );
float SerieMaclaurinCos( int nmax, float xcos);

void VectorPuntosyDatosSerieMaclaurinTang( int *fd, char *M, int *cantvectores, int nmax );
float SerieMaclaurinTang ( int nmax, float xtang );


/*ESP 
 * @brief Función principal que ejecuta el programa de generación de gráficos. 
 * Permite al usuario seleccionar diferentes tipos de gráficos matemáticos 
 * y generar archivos compatibles con Octave.
 * 
 * @param Ninguno.
 * @return Retorna 0 al finalizar correctamente la ejecución del programa.
 */

/*ENG 
 * @brief Main function that executes the graph generation program.
 * Allows the user to select different types of mathematical graphs and 
 * generate Octave-compatible files.
 * 
 * @param None.
 * @return Returns 0 upon successful program execution.
 */

int main(void)
{
    //ESP: Declaro variables para gestionar archivos y gráficos.
    //ENG: Declare variables to manage files and graphs.
    int fd, cont, grafico, cantvectores = 0;

    //ESP: Variables para configurar subplots  según el comando subplot(filas, columnas, cuadro).
    //ENG: Variables for subplot configuration following the command as subplot(filas, columnas, cuadro). 
    int filas, columnas, cuadro;

    //ESP: Variable auxiliar para el manejo de casos en el switch.
    //ENG: Auxiliary variable for switch-case handling.
    int aux;

    //ESP: Contador de afirmaciones para rectas tangentes.
    //ENG: Counter for tangent line affirmations.
    int cantafirmaciones = 0;

    //ESP: Variable para seleccionar entre las opciones de rectas.
    //ENG: Variable to choose between line options.
    int recta;
    
    //ESP: Variables para la creación de gráficos y nombres de archivos.
    //ENG: Variables for graph creation and file names.
    char decision, M = 'A';

    //ESP: Vector para el nombre del archivo. 
    //ENG: Vector for file name.
    char nombre[largo];

    //ESP: Variables de apoyo para ciclos for y while.
    //ENG: Support variables to be used in for and while loops.
    int i;

    //ESP: Vector de caracteres para cargar las decisiones de hacer o no rectas derivadas a un punto.
    //Los caracteres deben ser S(si) y N(no)
    //ENG: Array to save characters related to the decision of doing or not the derivatives of lines to a point.
    //This characters must be S(yes) and N(no).
    char decisionrectaderivada[9];

    //ESP: Contador de deciones tomadas para guardar las N(no) y S(si) a medida que se ingresan por teclado.
    //ENG: Counter of decisiones made so to save N(ni) and S(si) as they are entered by keyboard.
    int contdecision = 0;

    //ESP: Variables de función cuadrática.
    //ENG: Quadratic function variables. 
    float coef1, coef2, coef3; 

    //ESP: Variables de función recta. 
    //ENG: Line function variables.
    float m, b;

    //ESP: Variables compartidas y reutilizables de las funciones recta y cuadratica.
    //ENG: Shared and reusable variables from the line and quadratic functions.
    float Xmin, Xmax, puntos;

    //ESP: Vector de coeficientes para la función polinomica de grado a elección.
    //ENG: Array of coefficients for the polynomial function of degree of choice.
    float Coeficientes[10];

    //ESP: Variable reutilizable asociada al grado de polinomio y de cantidad de terminos que se necesitan para formar las funciones:
    //ln(x) por Serie de Taylor, sen(x) por Serie de Maclaurin, cos(x) por Serie de Maclaurin, tang(x) por Serie de Maclaurin.
    //ENG: Reusable variable related to the degree of the polynomial and the quantity of terms necessary to make the functions:
    //ln(x) by Taylor Series, sen(x) by Maclaurin Series, cos(x) by Maclaurin Series, tang(x) by Maclaurin Series.
    int n;

    //ESP: Cadena de formato para el comando plot en Octave
    //ENG: Format string for the plot command in Octave
    char cadena[]="plot(%c(:,1),%c(:,2),\"b\")\n";
    
    //ESP: Cadena de formato para el comando subplot en Octave
    //ENG: Format string for the subplot command in Octave
    char cadena1[]="subplot(%i,%i,%i)\n";

    //ESP: Cadena de formato para el comando hold on en Octave.
    //ENG: Format string for the hold on command in Octave.
    char cadena2[]="hold on\n";

    //ESP: Printeo una decision de ingreso o no al menu de graficos.
    //ENG: Print a decision to enter or not the graph menu.
    printf("Desea crear un grafico, presione \"S\" (SI) o \"N\" (NO): ");
    scanf("%c", &decision);
    __fpurge(stdin);
    
    if( decision == 'S' )
    { 
        //ESP: Limpio con "0" la basura del vector de caracteres nombre para evitar conflictos.
        //ENG: Clear the garbage in the character array 'nombre' with "0" to avoid conflicts.
        memset(nombre, 0, 50); 

        //ESP: Limpio con "0" la basura del vector de decisionrectaderivada para evitar conflictos.
        //ENG: Clear the garbage in the array 'decisionrectaderivada' with "0" to avoid conflicts.
        memset(decisionrectaderivada, 0, 9); 
        
        //ESP: Solicito al usuario que ingrese el nombre del archivo.
        //ENG: Prompt the user to enter the file name.
        printf("Ingrese el nombre que desea para el archivo de hasta maximo 50 caracteres, presione \"enter\" para terminar: ");
        nombre[0] = '.';
        nombre[1] = '/';
        for( i = 2, cont = 2; cont <= largo-2 && nombre[cont-1] != '\n' ; cont++ )
        {
            scanf("%c", &nombre[cont]);
            i++;
            /* 
            //ESP: Algoritmo fallido de proteccion contra cant de caracteres excedidios en el nombre del archivo
            //ENG: Failed algorithm for protection against exceeding the character limit in the file name
            if( nombre[50] == '\n' || ( nombre[50] != '\n' && nombre[50] != 0 ) )
            {
                printf("\n Error, debe reingresar el nombre: ");
                i = 2;
                cont = 2;
                memset(nombre, 0, 50);
                nombre[0] = '.';
                nombre[1] = '/';
            }
            */
        }
        
        //ESP: Cargo al final del nombre del archivo la extension dada como ".m"
        //ENG: Load the file name with the extension known as ".m"
        nombre[cont-1] = '.';
        nombre[cont] = 'm';
            
        //ESP: Defino el archivo de octave con los permisos.
        //ENG: Define the octave file with the permissions.
        fd=open(nombre, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        dprintf(fd, "hold on \n");

        //ESP: Solicito al usuario que elija entre las opciones de gráficos.
        //ENG: Prompt the user to choose between graph options.
        printf("Elija entre las opciones: recta \"R\", cuadratica \"C\", polinomio \"P\", Hiperbola \"H\", Modulo \"M\" Logaritmo Neperiano siendo ln( 1 + x ) \"L\", Seno de x con Sen(x) siendo \"S\", Coseno de x con Cos(x) siendo \"O\", Tangente de x con Tang(x) siendo \"T\" \n");
        printf("El maximo de graficos que puede ingresar en total es de 9 en la misma pantalla\n");
        printf("En caso de superar dicha cantidad, se graficara solo hasta el noveno grafico ingresado\n");
        printf(" Si desea terminar de ingresar graficos, ingrese el caracter EOF (ctrl+d) al comienzo de un nuevo pedido de opcion de grafico: ");
      
        //ESP: Ingreso de opciones de graficos por teclado.
        //ENG: Input of graph options by keyboard.
        while ( ( grafico = getchar() ) != EOF && cantvectores < 9) //ESP: EOF se ejecuta con ctrl+d,
        {
            //ESP: Armo un menu recursivo con while, switchcase y limito a una cantidad maxima de 9 vectores de graficos ya que el subplot tiene limitado una matriz de maximo 9 posiciones.
            //ENG: Build a recursive menu with while, switchcase and limit to a maximum of 9 graph vectors since the subplot is limited to a matrix of maximum 9 positions.
            switch (grafico)
            {

                //ESP: Recta tipo a) r(x) = m.x+b o b) r(x) dada por P1(xo1,yo1) y P2(xo2,yo2).
                //ENG: Line type a) r(x) = m.x+b or b) r(x) given by P1(xo1,yo1) and P2(xo2,yo2).
                case 'R': case 'r': 
                    
                    //ESP: Limpio el buffer de entrada.
                    //ENG: Clear the input buffer.
                    __fpurge(stdin);

                    //ESP: Protección contra carácter de opción mal ingresado.
                    //ENG: Protection against incorrectly entered option character.
                    do
                    {
                        //ESP: Solicito al usuario que ingrese el tipo de recta y limpio el buffer de entrada.
                        //ENG: Prompt the user to enter the type of line and clear the input buffer.
                        printf("Ingrese \"1\" para r(x)=m.x+b o \"2\" para r(x) dada por 2 puntos: ");
                        scanf("%i", &recta);
                        __fpurge(stdin);

                    }while( recta != 1 && recta != 2 );
                
                    if ( recta == 1 )
                    {
                        //ESP: Pido datos para la recta a través de una función.
                        //ENG: Request data for the line through a function.
                        DatosRecta( &m, &b, &Xmin, &Xmax, &puntos );

                        //ESP: Armo el vector de puntos de la recta a través de una función.
                        //ENG: Build the vector of points for the line through a function.
                        VectorpuntosRecta( &fd, &M, &cantvectores, m, b, Xmin, Xmax, puntos );
                        
                        do
                        {
                            //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                            //ENG: Ask the user if they want to get the tangent line at a point and clear the input buffer.
                            printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                            scanf("%c", &decision);
                            __fpurge(stdin);

                        }while( decision != 'S' && decision != 'N' );
                        
                        //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                        //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                        decisionrectaderivada[contdecision] = decision;
                        contdecision++;
                    }
                    
                    if ( recta == 2 )
                    {
                        //ESP: Armo el vector de puntos de la recta a través de una función.
                        //ENG: Build the vector of points for the line through a function.
                        VectorPuntosyDatosRectaDadaPor2Puntos( &fd, &M, &cantvectores );
                        
                        do
                        {
                            //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                            //ENG: Ask the user if they want to get the tangent line at a point and clear the input buffer.
                            printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                            scanf("%c", &decision);
                            __fpurge(stdin);

                        }while( decision != 'S' && decision != 'N' );
                        
                        //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                        //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                        decisionrectaderivada[contdecision] = decision;
                        contdecision++;
                    }
                    
                    //ESP: Solicito al usuario si desea ingresar otra recta o terminar.
                    //ENG: Ask the user if they want to enter another line or finish.
                    printf("Si desea ingresar otra recta presione \"R\", si desea ingresar otro grafico presione otra opcion: ");
                    
                    break;
                
                //ESP: Cuadratica tipo c(x) =  a.x^2+b.x+c .
                //ENG: Quadratic type c(x) =  a.x^2+b.x+c . 
                case 'C': case 'c': 
                    
                    //ESP: Los datos de una cuadrática los pido con una función.
                    //ENG: Request the data for a quadratic function through a function.
                    DatosCuadratica( &coef1, &coef2, &coef3, &Xmin, &Xmax, &puntos );
                    
                    //ESP: Armo el vector de puntos x e y de la cuadrática con una función.
                    //ENG: Build the vector of x and y points for the quadratic function through a function.
                    VectorpuntoCuadratica( &fd, &M ,&cantvectores, coef1, coef2, coef3, Xmin, Xmax, puntos );
                
                    do
                    {
                        //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                        //ENG: Ask the user if they want to get the tangent line at a point and clear the input buffer.
                        printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                        scanf("%c", &decision);
                        __fpurge(stdin);
                        
                    }while( decision != 'S' && decision != 'N' );
                    
                    //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                    //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                    decisionrectaderivada[contdecision] = decision;
                    contdecision++;
                    
                    if( decision == 'S' )
                    {
                        //ESP: Armo el vector de puntos y datos de la recta tangente en un punto de la cuadrática.
                        //ENG: Build the vector of points and data for the tangent line at a point of the quadratic function.
                        VectorDatosyPuntosRectaTangenteEnUnPuntoDeCuadratica( &fd, &M, &Xmin, &Xmax, coef1, coef2, coef3 );
                        cantafirmaciones++;
                    }
                    
                    //ESP: Solicito al usuario si desea ingresar otra cuadrática o terminar.
                    //ENG: Ask the user if they want to enter another quadratic function or finish.
                    printf("Si desea ingresar otra cuadratica presione \"C\", si desea ingresar otro grafico o terminar, presione otra de las opciones mencionadas: ");
                    
                    break;
                    
                //ESP: Polinimo de grado 0<= n <= 10  p(x) = asub n . x^n + asub n-1 . x^n-1 +...+ asub 1 . x + a0 . 
                //ENG: Polynomial of degree 0<= n <= 10  p(x) = asub n . x^n + asub n-1 . x^n-1 +...+ asub 1 . x + a0 . 
                case 'P' : case 'p' : 
                    
                    //ESP: Pido el grado del polinomio y limpio el buffer de entrada.
                    //ENG: Request the degree of the polynomial and clean the input buffer.
                    printf("Ingrese el grado del polinomio con 0<= n <= 10 como posibles valores: ");
                    scanf("%i", &n);
                    __fpurge(stdin);
                    
                    //ESP: Los datos del polinomio los pido primero con un vector que se carga con los coeficientes según el grado n.
                    //ENG: Request the polynomial data first with a vector that is loaded with the coefficients according to the degree n.
                    DatosPolinomio( Coeficientes, n );
                    
                    //ESP: Los datos restantes del polinomio los pido por teclado con una función, resuelvo la función y armo el vector de puntos x e y del polinomio.
                    //ENG: Request the remaining polynomial data through a function, solve the function and build the vector of x and y points for the polynomial.
                    VectorPuntosPolinomio( Coeficientes, n, &fd, &M, &cantvectores );
                    
                    do
                    {
                        //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                        //ENG: Ask the user if they want to get the tangent line at a point and clean the input buffer.
                        printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                        scanf("%c", &decision);
                        __fpurge(stdin);

                    }while( decision != 'S' && decision != 'N' );
                    
                    //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                    //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                    decisionrectaderivada[contdecision] = decision;
                    contdecision++;
                    
                    //ESP: Solicito al usuario si desea ingresar otro polinomio o terminar.
                    //ENG: Ask the user if they want to enter another polynomial or finish.
                    printf("Si desea ingresar otro polinomio presione \"P\", si desea ingresar otro grafico o terminar, presione otra de las opciones mencionadas: ");
                    
                    break;

                //ESP: Hiperbola tipo h(x) = (a.x+b) / (c.x+d)
                //ENG: Hyperbola type h(x) = (a.x+b) / (c.x+d)  
                case 'H' : case 'h' : 
                    
                    //ESP: Pido los datos y armo el vector de puntos x e y de la hiperbola h(x) con una función.
                    //ENG: Request the data and build the vector of x and y points for the hyperbola h(x) with a function.
                    VectorPuntosyDatosHiperbola( &fd, &M, &cantvectores );
                    
                    do
                    {
                        //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                        //ENG: Ask the user if they want to get the tangent line at a point and clean the input buffer.
                        printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                        scanf("%c", &decision);
                        __fpurge(stdin);

                    }while( decision != 'S' && decision != 'N' );
                    
                    //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                    //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                    decisionrectaderivada[contdecision] = decision;
                    contdecision++;
                    
                    //ESP: Solicito al usuario si desea ingresar otra hiperbola o terminar.
                    //ENG: Ask the user if they want to enter another hyperbola or finish.
                    printf("Si desea ingresar otra hiperbola presione \"H\", si desea ingresar otro grafico o terminar, presione otra de las opciones mencionadas: ");
                    
                    break;

                //ESP: Modulo tipo m(x) = a.|x+b|+c
                //ENG: Modulo tipo m(x) = a.|x+b|+c  
                case 'M' : case 'm' : 
                    
                    //ESP: Pido los datos y armo el vector de puntos x e y del modulo m(x) con una función.
                    //ENG: Request the data and build the vector of x and y points for the modulus m(x) with a function.
                    VectorPuntosyDatosModulo( &fd, &M, &cantvectores );
                    
                    do
                    {
                        //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                        //ENG: Ask the user if they want to get the tangent line at a point and clean the input buffer.
                        printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                        scanf("%c", &decision);
                        __fpurge(stdin);

                    }while( decision != 'S' && decision != 'N' );
                    
                    //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                    //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                    decisionrectaderivada[contdecision] = decision;
                    contdecision++;
                    
                    //ESP: Solicito al usuario si desea ingresar otro modulo o terminar.
                    //ENG: Ask the user if they want to enter another modulus or finish.
                    printf("Si desea ingresar otro Modulo presione \"M\", si desea ingresar otro grafico o terminar, presione otra de las opciones mencionadas: ");
                    
                    break;
                
                //ESP: Logaritmo natural ln(x) con Serie de Taylor.
                //ENG: Natural logarithm ln(x) with Taylor Series.
                case 'L' : case 'l' : 
                    
                    //ESP: Pido la cantidad maxima de terminos por teclado y limpio el buffer de entrada.
                    //ENG: Request the maximum number of terms by keyboard and clean the input buffer.
                    printf("Ingrese la cantidad de terminos con los que desea formar la Serie De Taylor para formar el ln(1+z) con x=1+z, siendo n>=1: ");
                    scanf("%i", &n);
                    __fpurge(stdin);
                    
                    //ESP: Pido los datos y armo el vector de puntos x e y de la Serie de Taylor de ln(x) con una función.
                    //ENG: Request the data and build the vector of x and y points for the Taylor Series of ln(x) with a function.
                    VectorPuntosyDatosSerieTaylorLn( &fd, &M, &cantvectores, n );
                    
                    do
                    {
                        //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                        //ENG: Ask the user if they want to get the tangent line at a point and clean the input buffer.
                        printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                        scanf("%c", &decision);
                        __fpurge(stdin);

                    }while( decision != 'S' && decision != 'N' );
                    
                    //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                    //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                    decisionrectaderivada[contdecision] = decision;
                    contdecision++;
                    
                    //ESP: Solicito al usuario si desea ingresar otro logaritmo o terminar.
                    //ENG: Ask the user if they want to enter another logarithm or finish.
                    printf("Si desea ingresar otro logaritmo con distinta cantidad de terminos presione \"L\", si desea ingresar otro grafico o terminar, presione otra de las opciones mencionadas: ");
                    
                    break;
                
                //ESP: Seno de x con Serie de Maclaurin.
                //ENG: Sine of x with Maclaurin Series.
                case 'S' : case 's' : 
                    
                    //ESP: Pido la cantidad maxima de terminos por teclado y limpio el buffer de entrada.
                    //ENG: Request the maximum number of terms by keyboard and clean the input buffer.
                    printf("Ingrese la cantidad de terminos con los que desea formar la Serie De Maclaurin para formar Sen(x), siendo n >= 0: ");
                    scanf("%i", &n);
                    __fpurge(stdin);
                    
                    //ESP: Pido los datos y armo el vector de puntos x e y de la Serie de Maclaurin de Sen(x) con una función.
                    //ENG: Request the data and build the vector of x and y points for the Maclaurin Series of Sen(x) with a function.
                    VectorPuntosyDatosSerieMaclaurinSen( &fd, &M, &cantvectores, n );
                    
                    do
                    {
                        //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                        //ENG: Ask the user if they want to get the tangent line at a point and clean the input buffer.
                        printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                        scanf("%c", &decision);
                        __fpurge(stdin);

                    }while( decision != 'S' && decision != 'N' );
                    
                    //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                    //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                    decisionrectaderivada[contdecision] = decision;
                    contdecision++;
                    
                    //ESP: Solicito al usuario si desea ingresar otro Sen(x) o terminar.
                    //ENG: Ask the user if they want to enter another Sen(x) or finish.
                    printf("Si desea ingresar otro Sen(x) con distinta cantidad de terminos presione \"S\", si desea ingresar otro grafico o terminar, presione otra de las opciones mencionadas: ");
                    
                    break;

                //ESP: Coseno de x con Serie de Maclaurin.
                //ENG: Cosine of x with Maclaurin Series.
                case 'O' : case 'o' : 
                    
                    //ESP: Pido la cantidad maxima de terminos por teclado y limpio el buffer de entrada.
                    //ENG: Request the maximum number of terms by keyboard and clean the input buffer.
                    printf("Ingrese la cantidad de terminos con los que desea formar la Serie De Maclaurin para formar Cos(x), siendo n >= 0: ");
                    scanf("%i", &n);
                    __fpurge(stdin);
                    
                    //ESP: Pido los datos y armo el vector de puntos x e y de la Serie de Maclaurin de Cos(x) con una función.
                    //ENG: Request the data and build the vector of x and y points for the Maclaurin Series of Cos(x) with a function.
                    VectorPuntosyDatosSerieMaclaurinCos( &fd, &M, &cantvectores, n );
                    
                    do
                    {
                        //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                        //ENG: Ask the user if they want to get the tangent line at a point and clean the input buffer.
                        printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                        scanf("%c", &decision);
                        __fpurge(stdin);

                    }while( decision != 'S' && decision != 'N' );
                    
                    //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                    //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                    decisionrectaderivada[contdecision] = decision;
                    contdecision++;
                    
                    //ESP: Solicito al usuario si desea ingresar otro Cos(x) o terminar.
                    //ENG: Ask the user if they want to enter another Cos(x) or finish.
                    printf("Si desea ingresar otro Cos(x) con distinta cantidad de terminos presione \"O\", si desea ingresar otro grafico o terminar, presione otra de las opciones mencionadas: ");
                    
                    break;

                //ESP: Caso función tangente de x con Serie de Maclaurin.
                //ENG: Case of tangent function of x with Maclaurin Series.    
                case 'T' : case 't' :  
                    
                    //ESP: Pido la cantidad de termininos por teclado y limpio el buffer de entrada.
                    //ENG: Request the number of terms by keyboard and clean the input buffer.
                    printf("Ingrese la cantidad de terminos con los que desea formar la Serie De Maclaurin para formar Tang(x), siendo n >= 0: ");
                    scanf("%i", &n);
                    __fpurge(stdin);
                    
                    //ESP: Pido los datos y armo el vector de puntos x e y de la Serie de Maclaurin de Tang(x) con una función.
                    //ENG: Request the data and build the vector of x and y points for the Maclaurin Series of Tang(x) with a function.
                    VectorPuntosyDatosSerieMaclaurinTang( &fd, &M, &cantvectores, n );
                    
                    do
                    {
                        //ESP: Solicito al usuario si desea obtener la recta tangente en un punto y limpio el buffer de entrada.
                        //ENG: Ask the user if they want to get the tangent line at a point and clean the input buffer.
                        printf("Si desea obtener la recta tangente en un punto \"a\" interior del dominio, oprima \"S\" (SI) o \"N\" (NO): ");
                        scanf("%c", &decision);
                        __fpurge(stdin);

                    }while( decision != 'S' && decision != 'N' );
                    
                    //ESP: Almaceno la decisión asociada con el caracter ´S´ o ´N´ en el vector decisionrectaderivada.	
                    //ENG: Store the decision associated with the character ´S´ or ´N´ in the decisionrectaderivada vector.
                    decisionrectaderivada[contdecision] = decision;
                    contdecision++;
                
                    //ESP: Solicito al usuario si desea ingresar otra Tang(x) o terminar.
                    //ENG: Ask the user if they want to enter another Tang(x) or finish.
                    printf("Si desea ingresar otra Tang(x) con distinta cantidad de terminos presione \"T\", si desea ingresar otro grafico o terminar, presione otra de las opciones mencionadas: ");
                    
                    break;
                    
                //ESP: Ignoro estas entradas de teclado. 
                //ENG: Ignore these keyboard inputs.
                case '\n' : case ' ': 
                
                    break;
                
                //ESP: Caso por defecto para caracteres incorrectos.
                //ENG: Default case for incorrect characters.
                default: 
                
                    //ESP: Mensaje de error para caracteres incorrectos.
                    //ENG: Error message for incorrect characters.
                    printf("Se ingreso incorrectamente una letra o palabra\n");
                    printf("Ingrese devuetla una de las opciones: ");
                    
                    break;
            }
        
        }
        
   //ESP: Evaluo distinos casos de cant de vectores para graficar de acuerdo al subplot .
   //ENG: Evaluate different cases of vector quantity to graph according to the subplot.
   if ( cantvectores == 1 || cantvectores == 9 )
   {
        switch(cantvectores)
        {
            //ESP: Caso de un unico grafico.  
            //ENG: Case of a single graph.
            case 1 :
           
                //ESP: Creo un comando plot para graficar una unica funcion.
                //ENG: Create a plot command to graph a single function.
                M = 'A';
                dprintf(fd, cadena, M, M);
                if( decision == 'S' )
                {   M += 1;
                    dprintf(fd, cadena, M, M);
                    dprintf(fd, cadena2, M, M);// Linea agregada el 18-3-2025
                }
                
                break;
            
            //ESP: Caso de nueve graficos.
            //ENG: Case of nine graphs.
            case 9 :
            
                //ESP: Creo los comandos "subplot" de matriz 2 x nrocolumnas y "plot" uno detras del otro para graficar en una sola pantalla matriziada, varios graficos.
                //ENG: Create the "subplot" commands of matrix 2 x nrocolumns and "plot" one after the other to graph in a single matrixed screen, several graphs.
                for( M = 'A', cont = 0, filas = 3, columnas = 3, cuadro = 1, contdecision = 0; cont < cantvectores ; cont++, M++, cuadro++, contdecision++)
                {
                    dprintf(fd, cadena1, filas, columnas, cuadro);
                    dprintf(fd, cadena, M, M);
                    dprintf(fd, cadena2, M, M);// Linea agregada el 18-3-2025
                    if( decisionrectaderivada[contdecision] == 'S' )
                    {
                        M += 1;
                        dprintf(fd, cadena, M, M);
                        dprintf(fd, cadena2, M, M);// Linea agregada el 18-3-2025
                    }
                }
                
                break;
        }
   }
   else
   {
        //ESP: Evaluo si la cantidad de graficos es par o impar.
        //ENG: Evaluate if the number of graphs is even or odd.
        aux = cantvectores%2;

        //ESP: Evaluo los casos de cantidad de graficos para graficar de acuerdo al subplot.
        //ENG: Evaluate the cases of the number of graphs to graph according to the subplot.
        switch(aux)
        {
            //ESP: Caso de cantidad impar de graficos.
            //ENG: Case of an odd number of graphs.
            case 1 :
                
                //ESP: Algoritmo de graficacion para cant impar de graficos.
                //ENG: Graphing algorithm for odd number of graphs. 
                cantvectores++;
                columnas = cantvectores / 2;

                //ESP: Creo los enunciados "subplot" de matriz 2 x nrocolumnas y "plot" uno detras del otro para graficar en una sola pantalla matriziada, varios graficos.
                //ENG: Create the "subplot" commands of matrix 2 x nrocolumns and "plot" one after the other to graph in a single matrixed screen, several graphs.
                for( M = 'A', cont = 1, filas = 2, cuadro = 1, contdecision = 0 ; cont < cantvectores ; cont++, cuadro++, M++, contdecision++ )
                {
                    dprintf(fd, cadena1, filas, columnas, cuadro);
                    dprintf(fd, cadena, M, M);
                    dprintf(fd, cadena2, M, M);// Linea agregada el 18-3-2025
                    if( decisionrectaderivada[contdecision] == 'S' )
                    {
                        M += 1;
                        dprintf(fd, cadena, M, M);
                        dprintf(fd, cadena2, M, M);// Linea agregada el 18-3-2025
                    }
                }
                    
                break;
            
            //ESP: Caso de cantidad par de graficos.
            //ENG: Case of an even number of graphs.
            case 0 :
                
                //ESP: Algoritmo de graficacion para cantidad pares de graficos.
                //ENG: Graphing algorithm for even number of graphs.
                columnas = cantvectores / 2;

                //ESP: Creo los enunciados "subplot" de matriz 2 x nrocolumnas y "plot" uno detras del otro para graficar en una sola pantalla matriziada, varios graficos.
                //ENG: Create the "subplot" commands of matrix 2 x nrocolumns and "plot" one after the other to graph in a single matrixed screen, several graphs.
                for( M = 'A', cont = 0, filas = 2, cuadro = 1, contdecision = 0; cont < cantvectores ; cont++, cuadro++, M++, contdecision++)
                {
                    dprintf(fd, cadena1, filas, columnas, cuadro);
                    dprintf(fd, cadena, M, M);
                    dprintf(fd, cadena2, M, M);// Linea agregada el 18-3-2025
                    if( decisionrectaderivada[contdecision] == 'S' )
                    {
                        M += 1;
                        dprintf(fd, cadena, M, M);
                        dprintf(fd, cadena2, M, M);// Linea agregada el 18-3-2025
                    }
                }
                
                break;
           
        }   
   }
   
   printf("\nLa cantidad de rectas tangentes derivadas a graficar son: %i\n", cantafirmaciones);
   
   close(fd);
   
   }
   
   return(0);
   
}




/* ESP
 * @brief Calcula la longitud de un arreglo de caracteres.
 *
 * @param arreglo El arreglo de caracteres cuya longitud se va a calcular.
 * @return La longitud del arreglo.
 */
/* ENG
 * @brief Calculates the length of a character array.
 *
 * @param arreglo The character array whose length is to be calculated.
 * @return The length of the array.
 */
/*
int LongitudDelArreglo ( char arreglo[] )
{
    int Longitud; 
    char TamanioDelArreglo, TamanioDelPrimerElemento;
    int cont;
    for( TamanioDelArreglo = 0, cont = 0; TamanioDelArreglo < largo; cont++)
    {
        TamanioDelArreglo += sizeof(arreglo[cont]);
    }
    TamanioDelPrimerElemento = sizeof(arreglo[0]);
    
    return Longitud = TamanioDelArreglo / TamanioDelPrimerElemento;
}
*/




/* ESP
 * @brief Calcula la longitud final del nombre de un archivo.
 *
 * @param arreglo El arreglo de caracteres que contiene el nombre del archivo.
 * @param i La longitud máxima del nombre del archivo.
 * @return La longitud final del nombre del archivo.
 */
/* ENG
 * @brief Calculates the final length of a file name.
 *
 * @param arreglo The character array containing the file name.
 * @param i The maximum length of the file name.
 * @return The final length of the file name.
 */
/*
int LongitudFinalDeNombre( char arreglo[], int i )
{
    int Longitud;
    char TamanioDelArreglo, TamanioDelPrimerElemento;
    int cont;
    for( TamanioDelArreglo = 0, cont = 0; TamanioDelArreglo < i; cont++)
    {
        TamanioDelArreglo += sizeof(arreglo[cont]);
    }
    TamanioDelPrimerElemento = sizeof(arreglo[0]);
    
    return Longitud = TamanioDelArreglo / TamanioDelPrimerElemento;
}
*/




/* ESP
 * @brief Solicita los datos necesarios para construir una recta.
 *
 * @param m Puntero a la pendiente de la recta.
 * @param b Puntero a la ordenada al origen de la recta.
 * @param Xm Puntero a la coordenada x inicial de la recta.
 * @param XM Puntero a la coordenada x final de la recta.
 * @param puntos Puntero a la cantidad de puntos de la recta.
 */
/* ENG
 * @brief Requests the necessary data to construct a line.
 *
 * @param m Pointer to the slope of the line.
 * @param b Pointer to the y-intercept of the line.
 * @param Xm Pointer to the initial x-coordinate of the line.
 * @param XM Pointer to the final x-coordinate of the line.
 * @param puntos Pointer to the number of points of the line.
 */
void DatosRecta( float *m, float *b, float *Xm, float *XM, float *puntos )
{
    //ESP: Pido los datos para armar una recta.
    //ENG: Request the data to build a line. 
    printf("ingrese pendiente de la recta: ");
    scanf("%f", m);
    __fpurge(stdin);
    printf("ingrese la ordenada al origen: ");
    scanf("%f", b);  
    __fpurge(stdin);
    printf("ingrese x inicial de la recta: ");
    scanf("%f", Xm);
    __fpurge(stdin);
    printf("ingrese x final de la recta: ");
    scanf("%f", XM);
    __fpurge(stdin);
    printf("ingrese la cantidad de puntos: ");
    scanf("%f", puntos);
    __fpurge(stdin);
}




/* ESP
 * @brief Genera el vector de puntos para una recta y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 * @param m Pendiente de la recta.
 * @param b Ordenada al origen de la recta.
 * @param Xm Coordenada x inicial de la recta.
 * @param XM Coordenada x final de la recta.
 * @param puntos Cantidad de puntos de la recta.
 */
/* ENG
 * @brief Generates the vector of points for a line and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 * @param m Slope of the line.
 * @param b Y-intercept of the line.
 * @param Xm Initial x-coordinate of the line.
 * @param XM Final x-coordinate of the line.
 * @param puntos Number of points of the line.
 */
void VectorpuntosRecta( int *fd, char *M, int *cantvectores, float m, float b, float Xm, float XM, float puntos )
{
    float x;
    //ESP: Printeo en un archivo de octave, el vector que contiene las coordenadas x e y para formar una recta.
    //ENG: Print in an octave file, the vector containing the x and y coordinates to form a line.
    dprintf(*fd,"%c=[",*M);
    
    for(x=Xm; x<=XM; x+= ((XM-Xm)/puntos))
    {
        //ESP: Los datos "y" de la recta los obtengo con una funcion.
        //ENG: The "y" data of the line is obtained with a function.
        dprintf(*fd, "%6.3f, %6.3f", x, Recta( m, x, b )); 
        if(x+((XM-Xm)/puntos) <= XM)
        dprintf(*fd,";");
    }

    dprintf(*fd,"]\n");
    
    //ESP:Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores.
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors.
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Calcula la ordenada (y) de una recta.
 *
 * @param m Pendiente de la recta.
 * @param x Coordenada x.
 * @param b Ordenada al origen de la recta.
 * @return La ordenada (y) de la recta.
 */
/* ENG
 * @brief Calculates the y-coordinate of a line.
 *
 * @param m Slope of the line.
 * @param x X-coordinate.
 * @param b Y-intercept of the line.
 * @return The y-coordinate of the line.
 */
float Recta ( float m, float x, float b )
{
    //ESP: Obtengo la coordenada "y" de la recta.
    //ENG: I get the "y" coordinate of the line.
    float y = m*x+b; 
    
    return y;
}




/* ESP
 * @brief Genera el vector de puntos para una recta dada por dos puntos y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 */
/* ENG
 * @brief Generates the vector of points for a line given by two points and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 */
void VectorPuntosyDatosRectaDadaPor2Puntos( int *fd, char *M, int *cantvectores )
{
    float xo1, xo2, yo1, yo2;
    
    //ESP: Pido las coordenadas de los puntos para armar la recta.
    //ENG: Request the coordinates of the points to build the line.
    printf("Ingrese la coordenada xo1 de P1: ");
    scanf("%f", &xo1);
    __fpurge(stdin);
    printf("Ingrese la coordenada yo1 de P1: ");
    scanf("%f", &yo1);
    __fpurge(stdin);
    printf("Ingrese la coordenada xo2 de P2: ");
    scanf("%f", &xo2);
    __fpurge(stdin);
    printf("Ingrese la coordenada yo2 de P2: ");
    scanf("%f", &yo2);
    __fpurge(stdin);
    
    //ESP: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar una recta.
    //ENG: Print in an octave file, the vector containing the x and y coordinates to form a line.
    dprintf(*fd,"%c=[",*M);

    //ESP: Los datos "y" de la recta los obtengo con una funcion.
    //ENG: The "y" data of the line is obtained with a function.
    dprintf(*fd,"%6.3f, %6.3f", xo1, yo1); 
    dprintf(*fd,";");
    dprintf(*fd,"%6.3f, %6.3f", xo2, yo2);
    dprintf(*fd,"]\n");
    
    //ESP: Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores.
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors.
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Solicita los datos necesarios para construir una función cuadrática.
 *
 * @param coef1 Puntero al primer coeficiente de la función cuadrática.
 * @param coef2 Puntero al segundo coeficiente de la función cuadrática.
 * @param coef3 Puntero al tercer coeficiente de la función cuadrática.
 * @param Xmin Puntero a la coordenada x inicial de la función cuadrática.
 * @param Xmax Puntero a la coordenada x final de la función cuadrática.
 * @param puntos1 Puntero a la cantidad de puntos de la función cuadrática.
 */
/* ENG
 * @brief Requests the necessary data to construct a quadratic function.
 *
 * @param coef1 Pointer to the first coefficient of the quadratic function.
 * @param coef2 Pointer to the second coefficient of the quadratic function.
 * @param coef3 Pointer to the third coefficient of the quadratic function.
 * @param Xmin Pointer to the initial x-coordinate of the quadratic function.
 * @param Xmax Pointer to the final x-coordinate of the quadratic function.
 * @param puntos1 Pointer to the number of points of the quadratic function.
 */
void DatosCuadratica( float *coef1, float *coef2, float *coef3, float *Xmin, float *Xmax, float *puntos1 )
{
    //ESP: Pido los datos para armar una cuadratica. 
    //ENG: Request the data to build a quadratic function.
    printf("ingrese el 1er coef \"a\": ");
    scanf("%f", coef1);
    __fpurge(stdin);
    printf("ingrese el 2do coef \"b\": ");
    scanf("%f", coef2);
    __fpurge(stdin);
    printf("ingrese el 3er coef \"c\": ");
    scanf("%f", coef3);
    __fpurge(stdin);
    printf("ingrese la x inicial de la cuadratica: ");
    scanf("%f", Xmin);
    __fpurge(stdin);
    printf("ingrese la x final de la cuadratica: ");
    scanf("%f", Xmax);
    __fpurge(stdin);
    printf("ingrese la cantidad de puntos: ");
    scanf("%f", puntos1);
    __fpurge(stdin);
}




/* ESP
 * @brief Genera el vector de puntos para una función cuadrática y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 * @param coef1 Primer coeficiente de la función cuadrática.
 * @param coef2 Segundo coeficiente de la función cuadrática.
 * @param coef3 Tercer coeficiente de la función cuadrática.
 * @param Xmin Coordenada x inicial de la función cuadrática.
 * @param Xmax Coordenada x final de la función cuadrática.
 * @param puntos1 Cantidad de puntos de la función cuadrática.
 */
/* ENG
 * @brief Generates the vector of points for a quadratic function and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 * @param coef1 First coefficient of the quadratic function.
 * @param coef2 Second coefficient of the quadratic function.
 * @param coef3 Third coefficient of the quadratic function.
 * @param Xmin Initial x-coordinate of the quadratic function.
 * @param Xmax Final x-coordinate of the quadratic function.
 * @param puntos1 Number of points of the quadratic function.
 */
void VectorpuntoCuadratica( int *fd, char *M, int *cantvectores, float coef1, float coef2, float coef3, float Xmin, float Xmax, float puntos1 )
{
    float x1;

    //ESP: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar una cuadratica.
    //ENG: Print in an octave file the vector containing the x and y coordinates to form a quadratic function.
    dprintf(*fd,"%c=[",*M);

    for(x1=Xmin; x1<=Xmax; x1+= ((Xmax-Xmin)/puntos1))
    {
        //ESP: Los datos "y" de la cuadratica los obtengo con una funcion.
        //ENG: The "y" data of the quadratic function is obtained with a function.
        dprintf(*fd,"%6.3f, %6.3f", x1, Cuadratica( coef1, coef2, coef3,  x1 ) );
        if(x1+((Xmax-Xmin)/puntos1 ) <= Xmax)
        dprintf(*fd, ";");
                
    }

    dprintf(*fd,"]\n");
    
    //ESP: Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores.
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors.
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Calcula la ordenada (y) de una función cuadrática.
 *
 * @param coef1 Primer coeficiente de la función cuadrática.
 * @param coef2 Segundo coeficiente de la función cuadrática.
 * @param coef3 Tercer coeficiente de la función cuadrática.
 * @param x1 Coordenada x.
 * @return La ordenada (y) de la función cuadrática.
 */
/* ENG
 * @brief Calculates the y-coordinate of a quadratic function.
 *
 * @param coef1 First coefficient of the quadratic function.
 * @param coef2 Second coefficient of the quadratic function.
 * @param coef3 Third coefficient of the quadratic function.
 * @param x1 X-coordinate.
 * @return The y-coordinate of the quadratic function.
 */
float Cuadratica( float coef1, float coef2, float coef3, float x1 )
{
    //ESP: Obtengo la coordenada "y" de la cuadratica.
    //ENG: I get the "y" coordinate of the quadratic function.
    float cuadratica = (coef1*x1*x1)+(coef2*x1)+coef3; 
    
    return cuadratica;
}




/* ESP
 * @brief Genera el vector de puntos para la recta tangente en un punto de una función cuadrática y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param Xmin Puntero a la coordenada x inicial de la función cuadrática.
 * @param Xmax Puntero a la coordenada x final de la función cuadrática.
 * @param coef1 Primer coeficiente de la función cuadrática.
 * @param coef2 Segundo coeficiente de la función cuadrática.
 * @param coef3 Tercer coeficiente de la función cuadrática.
 */
/* ENG
 * @brief Generates the vector of points for the tangent line at a point of a quadratic function and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param Xmin Pointer to the initial x-coordinate of the quadratic function.
 * @param Xmax Pointer to the final x-coordinate of the quadratic function.
 * @param coef1 First coefficient of the quadratic function.
 * @param coef2 Second coefficient of the quadratic function.
 * @param coef3 Third coefficient of the quadratic function.
 */
void VectorDatosyPuntosRectaTangenteEnUnPuntoDeCuadratica( int *fd, char *M, float *Xmin, float *Xmax, float coef1, float coef2, float coef3 )
{
    float a, xrtg, Xminrtg, Xmaxrtg;
    float pendiente_en_a, imagen_en_a;
    int puntosrtg;
    
    do
    {
        //ESP: Solicito el valor de entrada "a" donde se quiere hallar la recta tangente.
        //ENG: Request the input value "a" where the tangent line is to be found.
        printf("Ingrese el valor de entrada \"a\" donde quiere hallar la recta tangente, considere dicho punto interior del dominio original [%.3f,%.3f] de la funcion usado previamente: ", *Xmin, *Xmax );
        scanf("%f",&a);
        __fpurge(stdin);

    }while( a < *Xmin || a > *Xmax );
    
    printf("ingrese la x inicial de la recta tangente en \"a\": ");
    scanf("%f", &Xminrtg);
    __fpurge(stdin);
    printf("ingrese la x final de la recta tangente en \"a\": ");
    scanf("%f", &Xmaxrtg);
    __fpurge(stdin);
    printf("ingrese la cantidad de puntos: ");
    scanf("%i", &puntosrtg);
    __fpurge(stdin);
    
    //ESP: Obtengo la "c'(a)" osea la pendiente de la recta en "a".
    //ENG: I get the "c'(a)" which is the slope of the line at "a".
    pendiente_en_a = 2*coef1*a+coef2; 

    //ESP: Obtengo la "c(a)" osea la imagen en el punto de tangencia
    //ENG: I get the "c(a)" which is the image at the point of tangency
    imagen_en_a = (coef1*a*a)+(coef2*a)+coef3;

    //ESP: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar la recta tangente en "a" de la cuadratica
    //ENG: Print in an octave file the vector containing the x and y coordinates to form the tangent line at "a" of the quadratic function
    dprintf(*fd,"%c=[",*M);
    
    for(xrtg=Xminrtg; xrtg<=Xmaxrtg; xrtg+= ((Xmaxrtg-Xminrtg)/puntosrtg))
    {
        dprintf(*fd, "%6.3f, %6.3f", xrtg, RectaTgDerivada( xrtg, a, pendiente_en_a, imagen_en_a )); //ESP: Los datos "y" de la recta tangente derivada los obtengo con una funcion
        //ENG: The "y" data of the derived tangent line is obtained with a function
        if(xrtg+((Xmaxrtg-Xminrtg)/puntosrtg) <= Xmaxrtg)
        dprintf(*fd,";");
    }

    dprintf(*fd,"]\n");
    
    //ESP: Sumo 1 al entero asociado al char de la variable M
    //ENG: Add 1 to the integer associated with the char of the variable M
    (*M)++;
}




/* ESP
 * @brief Calcula la ordenada (y) de la recta tangente derivada en un punto de una función cuadrática.
 *
 * @param xrtg Coordenada x de la recta tangente.
 * @param a Punto de tangencia.
 * @param pendiente_en_a Pendiente de la recta en el punto de tangencia.
 * @param imagen_en_a Imagen en el punto de tangencia.
 * @return La ordenada (y) de la recta tangente derivada.
 */
/* ENG
 * @brief Calculates the y-coordinate of the derived tangent line at a point of a quadratic function.
 *
 * @param xrtg X-coordinate of the tangent line.
 * @param a Point of tangency.
 * @param pendiente_en_a Slope of the line at the point of tangency.
 * @param imagen_en_a Image at the point of tangency.
 * @return The y-coordinate of the derived tangent line.
 */
float RectaTgDerivada( float xrtg, float a, float pendiente_en_a, float imagen_en_a )
{
    float recta;

    return  recta = pendiente_en_a * ( xrtg - a ) + imagen_en_a; 
}




/* ESP
 * @brief Solicita los datos necesarios para construir un polinomio.
 *
 * @param Coeficientes Vector de coeficientes del polinomio.
 * @param n Grado del polinomio.
 */
/* ENG
 * @brief Requests the necessary data to construct a polynomial.
 *
 * @param Coeficientes Array of polynomial coefficients.
 * @param n Degree of the polynomial.
 */
void DatosPolinomio( float Coeficientes[], int n )
{
    int cont;
    
    //ESP: Estructura de proteccion contra grado de polinomio mal ingresado por teclado.
    //ENG: Protection structure against polynomial degree incorrectly entered by keyboard.
    if ( n > 10 || n < 0  ) 
    {
        do
        {   
            printf("Ingrese un numero valido de n grado: ");
            scanf("%i", &n);
            __fpurge(stdin);
        }
        while ( n > 10 || n < 0 );
    }
    
    //ESP: Pido datos de los coeficientes del polinomio y los guardo en un vector.
    //ENG: I ask for data of the coefficients of the polynomial and save them in a vector.
    printf("De acuerdo al n = %d indicando el grado y la cantidad de coeficientes %d, ingrese los valores de los coeficientes de forma secuencial: \n", n, n+1);
    
    for( cont=0; cont <= n; cont++ )
    {
        scanf("%f", &Coeficientes[cont]);
    }
    
    //ESP: Mensaje de seguridad para saber si el vector fue cargado o no.
    //ENG: Security message to know if the vector was loaded or not.
    printf("El vector de coeficientes fue cargado\n");
}




/* ESP
 * @brief Genera el vector de puntos para un polinomio y lo guarda en un archivo.
 *
 * @param Coeficientes Vector de coeficientes del polinomio.
 * @param n Grado del polinomio.
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 */
/* ENG
 * @brief Generates the vector of points for a polynomial and saves it to a file.
 *
 * @param Coeficientes Array of polynomial coefficients.
 * @param n Degree of the polynomial.
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 */
void VectorPuntosPolinomio( float *Coeficientes, int n, int *fd, char *M, int *cantvectores  )
{
    float Xmaxp, Xminp, puntosp;
    float xp;
       
    //ESP: Pido los datos restantes para armar el polinomio.
    //ENG: I ask for the remaining data to build the polynomial.
    printf("Ingrese el x inicial del polinomoio: ");
    scanf("%f", &Xminp);
    __fpurge(stdin);
    printf("Ingrese el x final del polinomoio: ");
    scanf("%f", &Xmaxp);
    __fpurge(stdin);
    printf("Ingrese la cantidad de puntos: ");
    scanf("%f", &puntosp);
    __fpurge(stdin);
       
    //ESp: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar el polinomio.
    //ENG: Print in an octave file the vector containing the x and y coordinates to form the polynomial.
    dprintf(*fd,"%c=[",*M);
    
    for(xp=Xminp; xp<=Xmaxp; xp+= ((Xmaxp-Xminp)/puntosp))
    {
        //ESP: Los datos "y" del polinomio los obtengo con una funcion.
        //ENG: The "y" data of the polynomial is obtained with a function.
        dprintf(*fd, "%6.3f, %6.3f", xp, Polinomio( Coeficientes, xp, n ) ); 
        if(xp+((Xmaxp-Xminp)/puntosp) <= Xmaxp)
        dprintf(*fd,";");
    }

    dprintf(*fd,"]\n");
       
    //ESP: Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores.
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors.
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Calcula la ordenada (y) de un polinomio.
 *
 * @param Coeficientes Vector de coeficientes del polinomio.
 * @param xp Coordenada x.
 * @param n Grado del polinomio.
 * @return La ordenada (y) del polinomio.
 */
/* ENG
 * @brief Calculates the y-coordinate of a polynomial.
 *
 * @param Coeficientes Array of polynomial coefficients.
 * @param xp X-coordinate.
 * @param n Degree of the polynomial.
 * @return The y-coordinate of the polynomial.
 */
float Polinomio( float *Coeficientes, float xp, int n )
{
    float Polinomio = 0;
    int cont;

    for ( cont = 0; cont <= n; cont++)
    {
        //ESP: Obtengo la coordenada "y" del polinomio.
        //ENG: I get the "y" coordinate of the polynomial.
        Polinomio +=  ( (powf(xp,(float) n) ) * ( Coeficientes[cont] ) );
    }
    
    return Polinomio;
}




/* ESP
 * @brief Genera el vector de puntos para una hiperbola y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 */
/* ENG
 * @brief Generates the vector of points for a hyperbola and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 */
void VectorPuntosyDatosHiperbola( int *fd, char *M, int *cantvectores )
{
    float xh, Xminh, Xmaxh;
    float a, b, c, d;
    int puntosh;
    
    //ESP: Pido los datos para armar la hiperbola.
    //ENG: Request the data to build the hyperbola.
    printf("Ingrese el coeficiente \"a\": ");
    scanf("%f", &a);
    __fpurge(stdin);
    printf("Ingrese el coeficiente \"b\": ");
    scanf("%f", &b);
    __fpurge(stdin);
    printf("Ingrese el coeficiente \"c\": ");
    scanf("%f", &c);
    __fpurge(stdin);
    printf("Ingrese el coeficiente \"d\": ");
    scanf("%f", &d);
    __fpurge(stdin);
    printf("Ingrese el x inicial de la hiperbola: ");
    scanf("%f", &Xminh);
    __fpurge(stdin);
    printf("Ingrese el x final de la hiperbola: ");
    scanf("%f", &Xmaxh);
    __fpurge(stdin);
    printf("Ingrese la cantidad de puntos: ");
    scanf("%i", &puntosh);
    __fpurge(stdin);
    
    //ESP: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar la hiperbola.
    //ENG: Print in an octave file the vector containing the x and y coordinates to form the hyperbola.
    dprintf(*fd,"%c=[",*M);
    
    for(xh=Xminh; xh<=Xmaxh; xh+= ((Xmaxh-Xminh)/puntosh))
    {
        //ESP: Obtengo la coordenada "y" de la hiperbola con una funcion.
        //ENG: I get the "y" coordinate of the hyperbola with a function.
        dprintf(*fd, "%6.3f, %6.3f", xh, Hiperbola( xh, a, b, c, d ) ); 
        if(xh+((Xmaxh-Xminh)/puntosh) <= Xmaxh)
        dprintf(*fd,";");
    }

    dprintf(*fd,"]\n");
       
    //ESP: Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores.
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors.
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Calcula la ordenada (y) de una hiperbola.
 *
 * @param xh Coordenada x.
 * @param a Coeficiente a de la hiperbola.
 * @param b Coeficiente b de la hiperbola.
 * @param c Coeficiente c de la hiperbola.
 * @param d Coeficiente d de la hiperbola.
 * @return La ordenada (y) de la hiperbola.
 */
/* ENG
 * @brief Calculates the y-coordinate of a hyperbola.
 *
 * @param xh X-coordinate.
 * @param a Coefficient a of the hyperbola.
 * @param b Coefficient b of the hyperbola.
 * @param c Coefficient c of the hyperbola.
 * @param d Coefficient d of the hyperbola.
 * @return The y-coordinate of the hyperbola.
 */
float Hiperbola( float xh, float a, float b, float c, float d )
{
    float divisor = c*xh+d;
    float hiperbola;
    
    if( divisor != 0 )
    {
        //ESP: Obtengo la coordenada "y" de la hiperbola.
        //ENG: I get the "y" coordinate of the hyperbola.
        hiperbola = (a*xh+b) / (c*xh+d);
    }
    else
    {
        printf("En uno de los valores de x, sucedio que: divisor = c.x+d vale 0 y no se puede obtener el valor \"y\" ya que no se puede dividir por 0, entonces se retorna y = 0");
        
        hiperbola = 0;
    }
    
    return hiperbola;
}




/* ESP
 * @brief Genera el vector de puntos para un módulo y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 */
/* ENG
 * @brief Generates the vector of points for a modulus and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 */
void VectorPuntosyDatosModulo( int *fd, char*M, int *cantvectores )
{
    float xmod, Xminmod, Xmaxmod;
    float a, b, c;
    int puntosmod;
    
    //ESP: Pido los datos para armar el módulo.
    //ENG: Request the data to build the modulus.
    printf("Ingrese el coeficiente \"a\": ");
    scanf("%f", &a);
    __fpurge(stdin);
    printf("Ingrese el coeficiente \"b\": ");
    scanf("%f", &b);
    __fpurge(stdin);
    printf("Ingrese el coeficiente \"c\": ");
    scanf("%f", &c);
    __fpurge(stdin);
    printf("Ingrese el x inicial del módulo: ");
    scanf("%f", &Xminmod);
    __fpurge(stdin);
    printf("Ingrese el x final del módulo: ");
    scanf("%f", &Xmaxmod);
    __fpurge(stdin);
    printf("Ingrese la cantidad de puntos: ");
    scanf("%i", &puntosmod);
    __fpurge(stdin);
    
    //ESP: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar el módulo.
    //ENG: Print in an octave file the vector containing the x and y coordinates to form the modulus.
    dprintf(*fd,"%c=[",*M);
    
    for(xmod=Xminmod; xmod<=Xmaxmod; xmod+= ((Xmaxmod-Xminmod)/puntosmod))
    {
        //ESP: Los datos "y" del módulo los obtengo con una función.
        //ENG: The "y" data of the modulus is obtained with a function.
        dprintf(*fd, "%6.3f, %6.3f", xmod, Modulo( xmod, a, b, c ) ); 
        if(xmod+((Xmaxmod-Xminmod)/puntosmod) <= Xmaxmod)
        dprintf(*fd,";");
    }

    dprintf(*fd,"]\n");
       
    //ESP: Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores.
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors.
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Calcula la ordenada (y) de un módulo.
 *
 * @param xmod Coordenada x.
 * @param a Coeficiente a del módulo.
 * @param b Coeficiente b del módulo.
 * @param c Coeficiente c del módulo.
 * @return La ordenada (y) del módulo.
 */
/* ENG
 * @brief Calculates the y-coordinate of a modulus.
 *
 * @param xmod X-coordinate.
 * @param a Coefficient a of the modulus.
 * @param b Coefficient b of the modulus.
 * @param c Coefficient c of the modulus.
 * @return The y-coordinate of the modulus.
 */
float Modulo( float xmod, float a, float b, float c )
{
    float modulo;
                                    
    if ( xmod >= -b )
        //ESP: Obtengo los datos "y" de la rama 1.
        //ENG: I get the "y" data of branch 1.
        modulo = a*(xmod+b)+c; 
    if ( xmod < -b )
        //ESP: Obtengo los datos "y" de la rama 2.
        //ENG: I get the "y" data of branch 2.
        modulo = a*(-1*(xmod+b))+c; 
    
    return modulo;
}




/* ESP
 * @brief Genera el vector de puntos para la Serie de Taylor de ln(x) y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 * @param nmax Número máximo de términos de la serie.
 */
/* ENG
 * @brief Generates the vector of points for the Taylor Series of ln(x) and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 * @param nmax Maximum number of terms in the series.
 */
void VectorPuntosyDatosSerieTaylorLn( int *fd, char *M, int *cantvectores, int nmax )
{
    float xln, Xminln, Xmaxln;
    int puntosln;
      
    //ESP: Protección contra cantidad de términos menores a 1.
    //ENG: Protection against number of terms less than 1.
    while ( nmax < 1 ) 
    {
        printf("Ha ingresado mal el número de términos, ingrese de nuevo considerando n >= 1: ");
        scanf("%i", &nmax);
        __fpurge(stdin);
    }
      
    //ESP: Pido los datos para armar la Serie de Taylor de ln.
    //ENG: Request the data to build the Taylor Series of ln.
      
    //ESP: Protección contra valor x inicial ingresado fuera de rango.
    //ENG: Protection against initial x value entered out of range.
    do
    {
        printf("Ingrese el valor inicial x siendo el rango posible 0 < x inicial < 2: ");
        scanf("%f", &Xminln);
        __fpurge(stdin);
    }while( Xminln <= 0 || Xminln >= 2 );
    
    //ESP: Protección contra valor x final ingresado fuera de rango.
    //ENG: Protection against final x value entered out of range.
    do
    {
        printf("Ingrese el valor final x siendo el rango posible 0 < x final < 2 con además x final > x inicial: ");
        scanf("%f", &Xmaxln);
        __fpurge(stdin);
    }while( Xmaxln <= 0 || Xmaxln > 2 || Xmaxln <= Xminln );
    
    printf("Ingrese la cantidad de puntos: ");
    scanf("%i", &puntosln);
    __fpurge(stdin);
    
    //ESP: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar la Serie de Taylor de ln(x).
    //ENG: Print in an octave file the vector containing the x and y coordinates to form the Taylor Series of ln(x).
    dprintf(*fd,"%c=[",*M);
    
    for(xln=Xminln; xln<=Xmaxln; xln+= ((Xmaxln-Xminln)/puntosln))
    {
        dprintf(*fd, "%6.3f, %6.3f", xln, SerieTaylorLn( nmax, xln) ); //ESP: Los datos "y" de la Serie de Taylor de ln(x) los obtengo con una función.
        //ENG: The "y" data of the Taylor Series of ln(x) is obtained with a function.
        if(xln+((Xmaxln-Xminln)/puntosln) <= Xmaxln)
        dprintf(*fd,";");
    }

    dprintf(*fd,"]\n");
       
    //ESP: Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores.
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors.
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Calcula la ordenada (y) de la Serie de Taylor de ln(x).
 *
 * @param nmax Número máximo de términos de la serie.
 * @param xln Coordenada x.
 * @return La ordenada (y) de la Serie de Taylor de ln(x).
 */
/* ENG
 * @brief Calculates the y-coordinate of the Taylor Series of ln(x).
 *
 * @param nmax Maximum number of terms in the series.
 * @param xln X-coordinate.
 * @return The y-coordinate of the Taylor Series of ln(x).
 */
float SerieTaylorLn( int  nmax, float xln )
{
    float ln = 0;
    int n, k = 1;
    
    for ( n = 1; n <= nmax; n++ )
    {
        //ESP: Obtengo los datos "y" de la Serie de Taylor de ln(x).
        //ENG: I get the "y" data of the Taylor Series of ln(x).
        ln += ( powf(xln - 1, (float) n) / n ) * k;
        k = k * (-1); 
    }
    
    return ln;
}




/* ESP
 * @brief Genera el vector de puntos para la Serie de Maclaurin de Sen(x) y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 * @param nmax Número máximo de términos de la serie.
 */
/* ENG
 * @brief Generates the vector of points for the Maclaurin Series of Sen(x) and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 * @param nmax Maximum number of terms in the series.
 */
void VectorPuntosyDatosSerieMaclaurinSen( int *fd, char *M, int *cantvectores, int nmax )
{
    float xsen, Xminsen, Xmaxsen;
    int puntosen;
    
    //ESP: Protección contra cantidad de términos ingresados fuera del rango de la Serie de Maclaurin de Sen(x).
    //ENG: Protection against number of terms entered out of range for the Maclaurin Series of Sen(x).
    while ( nmax < 0 ) 
    {
        printf("Ha ingresado mal el número de términos, ingrese de nuevo considerando n >= 0: ");
        scanf("%i", &nmax);
        __fpurge(stdin);
    }
    
    //ESP: Pido los datos para formar la Serie de Maclaurin de Sen(x).
    //ENG: Request the data to form the Maclaurin Series of Sen(x).

    //ESP: Pido el valor inicial de X.
    //ENG: I ask for the initial value of X.
    printf("Ingrese el valor x inicial en grados: ");
    scanf("%f", &Xminsen);
    __fpurge(stdin);
    
    //ESP: Convierto los grados ingresados a radianes.
    //ENG: Convert the entered degrees to radians.
    Xminsen = ( 2 * 3.14159265 * Xminsen ) / 360; 
    
    //ESP: Pido el valor final de X.
    //ENG: I ask for the final value of X.
    printf("Ingrese el valor x final en grados: ");
    scanf("%f", &Xmaxsen);
    __fpurge(stdin);
    
    //ESP: Convierto los grados ingresados a radianes.
    //ENG: Convert the entered degrees to radians.
    Xmaxsen = ( 2 * 3.14159265 * Xmaxsen ) / 360; 
    
    //ESP: Pido la cantidad de puntos.
    //ENG: I ask for the number of points
    printf("Ingrese la cantidad de puntos: ");
    scanf("%i", &puntosen);
    __fpurge(stdin);
    
    //ESP: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar la Serie de Maclaurin de Sen(x).
    //ENG: Print in an octave file the vector containing the x and y coordinates to form the Maclaurin Series of Sen(x).
    dprintf(*fd,"%c=[",*M);
    
    for(xsen=Xminsen; xsen<=Xmaxsen; xsen+= ((Xmaxsen-Xminsen)/puntosen))
    {
        //ESP: Los datos "y" de la Serie de Maclaurin de Sen(x) los obtengo con una función.
        //ENG: The "y" data of the Maclaurin Series of Sen(x) is obtained with a function.
        dprintf(*fd, "%6.3f, %6.3f", xsen, SerieMaclaurinSen( nmax, xsen) ); 
        if(xsen+((Xmaxsen-Xminsen)/puntosen) <= Xmaxsen)
        dprintf(*fd,";");
    }

    dprintf(*fd,"]\n");
       
    //ESP: Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores.
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors.
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Calcula la Serie de Maclaurin para Sen(x).
 *
 * @param nmax Número máximo de términos de la serie.
 * @param xsen Valor de x en radianes.
 * @return El valor de Sen(x) calculado usando la Serie de Maclaurin.
 */
/* ENG
 * @brief Calculates the Maclaurin Series for Sin(x).
 *
 * @param nmax Maximum number of terms in the series.
 * @param xsen Value of x in radians.
 * @return The value of Sin(x) calculated using the Maclaurin Series.
 */
float SerieMaclaurinSen( int nmax, float xsen )
{
    int n, nrofactorial;
    float sen = 0, k = 1;

    for( n = 0; n < nmax; n++ )
    {
        nrofactorial = 2*n+1;
        //ESP: Obtengo la "y" de la Serie de Maclaurin de Sen(x).
        //ENG: Get the "y" value of the Maclaurin Series for Sin(x).
        sen +=  ( ( powf( xsen, (float) nrofactorial ) / factorial( nrofactorial ) )* k ); 
        k *= -1;
    }

    return sen;
}




/* ESP
 * @brief Calcula el factorial de un número.
 *
 * @param nrofactorial Número del cual se calculará el factorial.
 * @return El factorial del número dado.
 */
/* ENG
 * @brief Calculates the factorial of a number.
 *
 * @param nrofactorial Number for which the factorial will be calculated.
 * @return The factorial of the given number.
 */
float factorial( int nrofactorial ) 
{
    float factorial = 1, ninicial;

    for( ninicial = 1; ninicial <= (float) nrofactorial; ninicial++ )
    {
        //ESP: Calculo el factorial de 2*n+1 de la Serie de Maclaurin de Sen(x) y el factorial de 2*n de la Serie de Maclaurin de Cos(x).
        //ENG: Calculate the factorial of 2*n+1 for the Maclaurin Series of Sin(x) and the factorial of 2*n for the Maclaurin Series of Cos(x).
        factorial *= ninicial; 
    }

    return factorial;
}




/* ESP
 * @brief Genera el vector de puntos para la Serie de Maclaurin de Cos(x) y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 * @param nmax Número máximo de términos de la serie.
 */
/* ENG
 * @brief Generates the vector of points for the Maclaurin Series of Cos(x) and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 * @param nmax Maximum number of terms in the series.
 */
void VectorPuntosyDatosSerieMaclaurinCos( int *fd, char *M, int *cantvectores, int nmax )
{
    float xcos, Xmincos, Xmaxcos;
    int puntoscos;
    
    //ESP: Protección contra cantidad de términos ingresados fuera del rango de la Serie de Maclaurin de Cos(x).
    //ENG: Protection against number of terms entered out of range for the Maclaurin Series of Cos(x).
    while ( nmax < 0 ) 
    {
        printf("Ha ingresado mal el número de términos, ingrese de nuevo considerando n >= 0: ");
        scanf("%i", &nmax);
        __fpurge(stdin);
    }
    
    //ESP: Pido los datos para formar la Serie de Maclaurin de Cos(x).
    //ENG: Request the data to form the Maclaurin Series of Cos(x).

    //ESP: Pido el valor inicial de X.
    //ENG: I ask for the initial value of X.
    printf("Ingrese el valor x inicial en grados: ");
    scanf("%f", &Xmincos);
    __fpurge(stdin);
    
    //ESP: Convierto los grados ingresados a radianes.
    //ENG: Convert the entered degrees to radians.
    Xmincos = ( 2 * 3.14159265 * Xmincos ) / 360; 
    
    //ESP: Pido el valor final de X.
    //ENG: I ask for the final value of X.
    printf("Ingrese el valor x final en grados: ");
    scanf("%f", &Xmaxcos);
    __fpurge(stdin);
    
    //ESP: Convierto los grados ingresados a radianes.
    //ENG: Convert the entered degrees to radians.
    Xmaxcos = ( 2 * 3.14159265 * Xmaxcos ) / 360; 
    
    //ESP: Pido la cantidad de puntos.
    //ENG: I ask for the number of points.
    printf("Ingrese la cantidad de puntos: ");
    scanf("%i", &puntoscos);
    __fpurge(stdin);
    
    //ESP: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar la Serie de Maclaurin de Cos(x).
    //ENG: Print in an octave file the vector containing the x and y coordinates to form the Maclaurin Series of Cos(x).
    dprintf(*fd,"%c=[",*M);
    
    for(xcos=Xmincos; xcos<=Xmaxcos; xcos+= ((Xmaxcos-Xmincos)/puntoscos))
    {
        //ESP: Los datos "y" de la Serie de Maclaurin de Cos(x) los obtengo con una función.
        //ENG: The "y" data of the Maclaurin Series of Cos(x) is obtained with a function.
        dprintf(*fd, "%6.3f, %6.3f", xcos, SerieMaclaurinCos( nmax, xcos) ); 
        if(xcos+((Xmaxcos-Xmincos)/puntoscos) <= Xmaxcos)
        dprintf(*fd,";");
    }

    dprintf(*fd,"]\n");
       
    //ESP: Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores.
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors.
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Calcula la Serie de Maclaurin para Cos(x).
 *
 * @param nmax Número máximo de términos de la serie.
 * @param xcos Valor de x en radianes.
 * @return El valor de Cos(x) calculado usando la Serie de Maclaurin.
 */
/* ENG
 * @brief Calculates the Maclaurin Series for Cos(x).
 *
 * @param nmax Maximum number of terms in the series.
 * @param xcos Value of x in radians.
 * @return The value of Cos(x) calculated using the Maclaurin Series.
 */
float SerieMaclaurinCos( int nmax, float xcos)
{
    int n, nrofactorial;
    float cos = 0, k = 1;

    for( n = 0; n < nmax; n++ )
    {
        nrofactorial = 2*n;
        //ESP: Obtengo la "y" de la Serie de Maclaurin de Cos(x).
        //ENG: Get the "y" value of the Maclaurin Series for Cos(x).
        cos +=  ( ( powf( xcos, (float) nrofactorial ) / factorial( nrofactorial ) )* k ); 
        k *= -1;
    }

    return cos;
}




/* ESP
 * @brief Genera el vector de puntos para la Serie de Maclaurin de Tang(x) y lo guarda en un archivo.
 *
 * @param fd Puntero al descriptor de archivo.
 * @param M Puntero al carácter que representa el vector.
 * @param cantvectores Puntero a la cantidad de vectores.
 * @param nmax Número máximo de términos de la serie.
 */
/* ENG
 * @brief Generates the vector of points for the Maclaurin Series of Tan(x) and saves it to a file.
 *
 * @param fd Pointer to the file descriptor.
 * @param M Pointer to the character representing the vector.
 * @param cantvectores Pointer to the number of vectors.
 * @param nmax Maximum number of terms in the series.
 */
void VectorPuntosyDatosSerieMaclaurinTang( int *fd, char *M, int *cantvectores, int nmax )
{
    float xtang, Xmintang, Xmaxtang;
    int puntostang;
 
    //ESP: Protección contra cantidad de términos ingresados fuera del rango de la Serie de Taylor de Tang(x).
    //ENG: Protection against number of terms entered out of range for the Taylor Series of Tan(x).
    while ( nmax < 0 ) 
    {
        printf("Ha ingresado mal el número de términos, ingrese de nuevo considerando n >= 0: ");
        scanf("%i", &nmax);
        __fpurge(stdin);
    }
    
    //ESP: Pido los datos para formar la Serie de Maclaurin de Tang(x).
    //ENG: Request the data to form the Maclaurin Series of Tan(x).
    
    //ESP: Protección contra valor x inicial ingresado fuera de rango.
    //ENG: Protection against initial x value entered out of range.
    do
    {
        printf("Ingrese el valor x inicial en grados siendo el rango posible -90 < x inicial < +90: ");
        scanf("%f", &Xmintang);
        __fpurge(stdin);

    }while( Xmintang <= -90 || Xmintang >= +90 );
    
    //ESP: Convierto los grados ingresados a radianes.
    //ENG: Convert the entered degrees to radians.
    Xmintang = ( 2 * 3.14159265 * Xmintang ) / 360; 
    
    //ESP: Protección contra valor x final ingresado fuera de rango.
    //ENG: Protection against final x value entered out of range.
    do
    {
        printf("Ingrese el valor x final en grados siendo el rango posible -90 < x final <= 90 con además x final > x inicial: ");
        scanf("%f", &Xmaxtang);
        __fpurge(stdin);

    }while( Xmaxtang <= -90 || Xmaxtang >= +90 || Xmaxtang <= Xmintang );
    
    Xmaxtang = ( 2 * 3.14159265 * Xmaxtang ) / 360; //ESP: Convierto los grados ingresados a radianes
    //ENG: Convert the entered degrees to radians
    
    printf("Ingrese la cantidad de puntos: ");
    scanf("%i", &puntostang);
    __fpurge(stdin);
    
    //ESP: Printeo en un archivo de octave el vector que contiene las coordenadas x e y para formar la Serie de Taylor de Tang(x)
    //ENG: Print in an octave file the vector containing the x and y coordinates to form the Taylor Series of Tan(x)
    dprintf(*fd,"%c=[",*M);
    
    for(xtang=Xmintang; xtang<=Xmaxtang; xtang+= ((Xmaxtang-Xmintang)/puntostang))
    {
        dprintf(*fd, "%6.3f, %6.3f", xtang, SerieMaclaurinTang( nmax, xtang) ); //ESP: Los datos "y" de la Serie de Maclaurin de Tang(x) los obtengo con una función
        //ENG: The "y" data of the Maclaurin Series of Tan(x) is obtained with a function
        if(xtang+((Xmaxtang-Xmintang)/puntostang) <= Xmaxtang)
        dprintf(*fd,";");
    }
    dprintf(*fd,"]\n");
       
    //ESP: Sumo 1 al entero asociado al char de la variable M, y sumo 1 a la cantidad de vectores
    //ENG: Add 1 to the integer associated with the char of the variable M, and add 1 to the number of vectors
    (*M)++;
    (*cantvectores)++;
}




/* ESP
 * @brief Calcula la Serie de Maclaurin para Tang(x).
 *
 * @param nmax Número máximo de términos de la serie.
 * @param xtang Valor de x en radianes.
 * @return El valor de Tang(x) calculado usando la Serie de Maclaurin.
 */
/* ENG
 * @brief Calculates the Maclaurin Series for Tan(x).
 *
 * @param nmax Maximum number of terms in the series.
 * @param xtang Value of x in radians.
 * @return The value of Tan(x) calculated using the Maclaurin Series.
 */
float SerieMaclaurinTang ( int nmax, float xtang )
{
    float xsen = xtang;
    float xcos = xtang;
    float tang = 0;
    tang += ( SerieMaclaurinSen( nmax, xsen )  /  SerieMaclaurinCos( nmax, xcos) );
    return tang;
}
