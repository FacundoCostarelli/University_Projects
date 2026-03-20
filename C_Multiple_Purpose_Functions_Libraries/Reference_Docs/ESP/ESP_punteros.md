# Original Text - punteros.pdf

INFORMATICA I
Incremento de punteros
Ing.Juan Carlos Cuttitta
Universidad Tecnológica Nacional
Facultad Regional Buenos Aires
Departamento de Ingeniería Electrónica
21 de mayo de 2019
1 / 12
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXXiintPtr
0xB0290182PROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
1 / 12
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXXiintPtrcharPtr
0xB02901820xB029017AcPROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
2 / 12
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0x78
0x56
0x34
0x12iintPtrcharPtr
0xB02901820xB029017AcPROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
3 / 12
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0xXX
0x4E
0x78
0x56
0x34
0x12iintPtrcharPtr
0xB02901820xB029017Ac = ’N’PROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
4 / 12
0xXX
0xXX
0xXX
0xXX
0x82
0x01
0x29
0xB0
0x4E
0x78
0x56
0x34
0x12iintPtrcharPtr
0xB02901820xB029017Ac = ’N’PROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
5 / 12
0x7A
0x01
0x29
0xB0
0x82
0x01
0x29
0xB0
0x4E
0x78
0x56
0x34
0x12iintPtrcharPtr
0xB02901820xB029017Ac = ’N’PROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
6 / 12
0x7A
0x01
0x29
0xB0
0x82
0x01
0x29
0xB0
0x41
0x78
0x56
0x34
0x12iintPtrcharPtr
0xB02901820xB029017Ac = ’A’PROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
7 / 12
0x7A
0x01
0x29
0xB0
0x82
0x01
0x29
0xB0
0x41
0x14
0x00
0x00
0x00iintPtrcharPtr
0xB02901820xB029017Ac = ’A’PROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
8 / 12
0x7B
0x01
0x29
0xB0
0x82
0x01
0x29
0xB0
0x41
0x14
0x00
0x00
0x00iintPtrcharPtr
0xB02901820xB029017A
0xB029017Bc = ’A’PROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
9 / 12
0x7B
0x01
0x29
0xB0
0x86
0x01
0x29
0xB0
0x41
0x14
0x00
0x00
0x00iintPtrcharPtr
0xB02901820xB029017A
0xB029017B
0xB0290186c = ’A’PROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13 }
10 / 12
0x7B
0x01
0x29
0xB0
0x86
0x01
0x29
0xB0
0x41
0x41
0x14
0x00
0x00
0x00iintPtrcharPtr
0xB02901820xB029017A
0xB029017B
0xB0290186c = ’A’PROGRAMA FUENTEMEMORIA en
ARQUITECTURA x86 32-bits
1 void main ( )
2 {
3 i n ti n t P t r , i ;
4 charcharPtr , c ;
5 i = 0x12345678 ;
6 c = ’N ’ ;
7 i n t P t r = & i ;
8 charPtr = &c ;
9charPtr= ’A ’ ;
10i n t P t r = 20;
11 charPtr ++;
12 i n t P t r ++;
13charPtr= ’A ’ ;
14 }
11 / 12
Algunas reglas para recordar !!!
intA;
intp;
p= &A;
A= 7;
p= 7;intintint
int int
int intintintV[ ] =f10;20g;
intp;
p= &V[0];
V[1] = 7 ;
(p+ 1) = 7 ;int intint
int int
int intint
12 / 12
