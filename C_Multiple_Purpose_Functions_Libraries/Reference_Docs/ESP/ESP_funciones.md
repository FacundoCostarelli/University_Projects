# Original Text - funciones.pdf

INFORMATICA I
Introducción a funciones en "C"
Ing.Juan Carlos Cuttitta
Universidad Tecnológica Nacional
Facultad Regional Buenos Aires
Departamento de Ingeniería Electrónica
27 de abril de 2020
Ing.Juan Carlos Cuttitta INFORMATICA I
Ejemplo de un programa que suma
Código en programa fuente
1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7 a = 6;
8 b = 9;
9 c = a + b ;
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12 a = 3;
13 b = 1;
14 c = a + b ;
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17 a = 12;
18 b = 4;
19 c = a + b ;
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7 a = 6;
8 b = 9;
9 c = a + b ;
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12 a = 3;
13 b = 1;
14 c = a + b ;
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17 a = 12;
18 b = 4;
19 c = a + b ;
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7 a = 6;
8 b = 9;
9 c = a + b ;
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12 a = 3;
13 b = 1;
14 c = a + b ;
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17 a = 12;
18 b = 4;
19 c = a + b ;
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7 a = 6;
8 b = 9;
9 c = a + b ;
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12 a = 3;
13 b = 1;
14 c = a + b ;
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17 a = 12;
18 b = 4;
19 c = a + b ;
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
c = a + b;1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
c = a + b;1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
c = a + b;1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
c = a + b;1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
c = a + b;1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
c = a + b;1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Tareas repetidas
Código en programa fuente
c = a + b;1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Funciones
Código en programa fuente
1int Mi_suma ( int x , int y )
2{
3int z;
4 z = x + y;
5 return z;
6{1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Funciones
Código en programa fuente
1int Mi_suma ( int x , int y )
2{
3int z;
4 z = x + y;
5 return z;
6{unico punto de entrada1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Funciones
Código en programa fuente
1int Mi_suma ( int x , int y )
2{
3int z;
4 z = x + y;
5 return z;
6{
unico punto de salida1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Funciones
Código en programa fuente
1int Mi_suma ( int x , int y )
2{
3int z;
4 z = x + y;
5 return z;
6{nombre de la funci on1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Funciones
Código en programa fuente
1int Mi_suma ( int x , int y )
2{
3int z;
4 z = x + y;
5 return z;
6{parametros o argumentos1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Funciones
Código en programa fuente
1int Mi_suma ( int x , int y )
2{
3int z;
4 z = x + y;
5 return z;
6{tipo de retorno1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Funciones
Código en programa fuente
1int Mi_suma ( int x , int y )
2{
3int z;
4 z = x + y;
5 return z;
6{tipo de retorno
la variable de retorno
tiene que ser del mismo tipo1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 i n t a , b , c ;
6
7
8
9
10 p r i n t f ( " El resultado es %d \ n " , c ) ;
11
12
13
14
15 p r i n t f ( " El resultado es %d \ n " , c ) ;
16
17
18
19
20 p r i n t f ( " El resultado es %d \ n " , c ) ;
21
22 r e t u r n ( 0 ) ;
23 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Ejemplo de un programa con una función
Código en programa fuente
PROTOTIPO
informa como tiene
que ser la funci on1 # include < s t d i o . h>
2
3 i n t Mi_suma ( i n t , i n t ) ;
4
5 i n t main ( void )
6 {
7 i n t a ;
8
9 a = Mi_suma ( 6 , 9 ) ;
10 p r i n t f ( " El resultado es %d \ n " ,a ) ;
11
12 a = Mi_suma ( 3 , 1 ) ;
13 p r i n t f ( " El resultado es %d \ n " ,a ) ;
14
15 a = Mi_suma ( 12 , 4 ) ;
16 p r i n t f ( " El resultado es %d \ n " ,a ) ;
17
18 r e t u r n ( 0 ) ;
19 }
20
21 i n t Mi_suma ( i n t x , i n t y )
22 {
23 i n t z ;
24 z = x + y ;
25 r e t u r n z ;
26 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Ejemplo de un programa con una función
Código en programa fuente
llama a la funci on1 # include < s t d i o . h>
2
3 i n t Mi_suma ( i n t , i n t ) ;
4
5 i n t main ( void )
6 {
7 i n t a ;
8
9 a = Mi_suma ( 6 , 9 ) ;
10 p r i n t f ( " El resultado es %d \ n " ,a ) ;
11
12 a = Mi_suma ( 3 , 1 ) ;
13 p r i n t f ( " El resultado es %d \ n " ,a ) ;
14
15 a = Mi_suma ( 12 , 4 ) ;
16 p r i n t f ( " El resultado es %d \ n " ,a ) ;
17
18 r e t u r n ( 0 ) ;
19 }
20
21 i n t Mi_suma ( i n t x , i n t y )
22 {
23 i n t z ;
24 z = x + y ;
25 r e t u r n z ;
26 }
Ing.Juan Carlos Cuttitta INFORMATICA I
Ejemplo de un programa con una función
Código en programa fuente
retorna de la funci on
y guarda el valorn de
z en a1 # include < s t d i o . h>
2
3 i n t Mi_suma ( i n t , i n t ) ;
4
5 i n t main ( void )
6 {
7 i n t a ;
8
9 a = Mi_suma ( 6 , 9 ) ;
10 p r i n t f ( " El resultado es %d \ n " ,a ) ;
11
12 a = Mi_suma ( 3 , 1 ) ;
13 p r i n t f ( " El resultado es %d \ n " ,a ) ;
14
15 a = Mi_suma ( 12 , 4 ) ;
16 p r i n t f ( " El resultado es %d \ n " ,a ) ;
17
18 r e t u r n ( 0 ) ;
19 }
20
21 i n t Mi_suma ( i n t x , i n t y )
22 {
23 i n t z ;
24 z = x + y ;
25 r e t u r n z ;
26 }
Ing.Juan Carlos Cuttitta INFORMATICA I
