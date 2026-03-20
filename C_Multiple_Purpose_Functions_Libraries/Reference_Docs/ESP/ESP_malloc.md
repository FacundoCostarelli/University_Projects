# Original Text - malloc.pdf

INFORMATICA I
malloc y realloc
Ing.Juan Carlos Cuttitta
Universidad Tecnológica Nacional
Facultad Regional Buenos Aires
Departamento de Ingeniería Electrónica
27 de junio de 2020
1 / 33
Enunciado del problema
Asignar memoria dinamicamente al vector
que contiene las direcciones de los
nombres ingresados y utilizar la memoria
justa para cada nombre.
La idea es que si reservé espacio para un
vector que pueda almacenar 256 bytes
pero ingreso un nombre que ocupa 5
bytes, utilicemos los recursos conocidos
para que sólo se usen los espacios justos
de memoria para esos 5 bytes y no los 256
bytes para cada nombre ingresado).
Termina el programa cuando un nombre
comienza con el simbolo @
1 / 33
Ejemplo de malloc y realloc
1 i n t main ( void )
2 {
3 i n t i =0 , j =0;
4 char c , nombres [ 2 5 6 ] ;
5 charp ;
6 charadr ;
7
8 adr= ( char ) malloc ( s i z e o f ( char ) ) ;
9 do {
10 f g e t s ( nombres , 256 , s t d i n ) ;
11 j = s t r l e n ( nombres ) ;
12 p = ( char ) malloc ( js i z e o f ( char ) ) ;
13 strcpy ( p , nombres ) ;
14( adr + i ) = p ;
15 c = (( adr+ i ) ) ;
16 i f ( c != ’@’ ) {
17 adr = ( char ) r e a l l o c ( adr , ( i +2) s i z e o f ( char) ) ;
18 i ++;
19 } else {
20 free ( p ) ;
21 ( adr + i ) = NULL;
22 }
23 } while ( c != ’@’ ) ;
24 f o r ( i =0 ; ( adr+ i ) != NULL ; i ++) {
25 p r i n t f ( " nombre %d : % s " , i , ( adr+ i ) ) ;
26 free ( ( adr+ i ) ) ;
27 }
28 free ( adr ) ;
29 r e t u r n 0;
30 }
2 / 33
malloc y realloc en Arquitectura X86-32 bits
0
0
0xXXXXXXXX
0xXXXXXXXX
...
...
...
...
...
...0xFFE07600i
j
p
adr char nombres [256]
3 / 33
malloc y realloc en Arquitectura X86-32 bits
0
0
0xXXXXXXXX
0xD2DFE260
...
0xXXXXXXXX
...
...
...
...
...0xD2DFE260i
j
p
adr char nombres [256]adr= (char **) malloc( sizeof (char *));
4 / 33
malloc y realloc en Arquitectura X86-32 bits
0
0
0xXXXXXXXX
0xD2DFE260
...
0xXXXXXXXX
...
...
...
...
...0xD2DFE260i
j
p
adr char nombres [256]fgets( nombres , 256 , stdin );
c a r l o s’n0’
5 / 33
malloc y realloc en Arquitectura X86-32 bits
0
7
0xXXXXXXXX
0xD2DFE260
...
0xXXXXXXXX
...
...
...
...
...0xD2DFE260i
j
p
adr char nombres [256]j = strlen( nombres );
c a r l o s’n0’
6 / 33
malloc y realloc en Arquitectura X86-32 bits
0
7
0xD2DFF290
0xD2DFE260
...
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFF290i
j
p
adr char nombres [256]p = (char *) malloc ( j * sizeof (char) );
pc a r l o s’n0’
7 / 33
malloc y realloc en Arquitectura X86-32 bits
0
7
0xD2DFF290
0xD2DFE260
...
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFF290i
j
p
adr char nombres [256]strcpy ( p , nombres );
0xD2DFF290
pc a r l o s’n0’
c a r l o s’n0’
8 / 33
malloc y realloc en Arquitectura X86-32 bits
0
7
0xD2DFF290
0xD2DFE260
...
0xD2DFF290
...
...
...
...
...0xD2DFE260
0xD2DFF290i
j
p
adr
0xD2DFF290char nombres [256]*( adr + i ) = p;
pc a r l o s’n0’
c a r l o s’n0’
9 / 33
malloc y realloc en Arquitectura X86-32 bits
0
7
0xD2DFF290
0xD2DFE260
...
0xD2DFF290
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFF290i
j
p
adr
0xD2DFF290char nombres [256]*( *(adr+i) ) contiene al primer caracter y como es != @
adr = (char **) realloc( adr , ( i+2 ) * sizeof (char *) )
pc a r l o s’n0’
c a r l o s’n0’
10 / 33
malloc y realloc en Arquitectura X86-32 bits
1
7
0xD2DFF290
0xD2DFE260
...
0xD2DFF290
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFF290i
j
p
adr
0xD2DFF290char nombres [256]i++;
pc a r l o s’n0’
c a r l o s’n0’
11 / 33
malloc y realloc en Arquitectura X86-32 bits
1
7
0xD2DFF290
0xD2DFE260
...
0xD2DFF290
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFF290i
j
p
adr
0xD2DFF290char nombres [256]fgets( nombres , 256 , stdin );
pp e d r o’n0’
c a r l o s’n0’
12 / 33
malloc y realloc en Arquitectura X86-32 bits
1
6
0xD2DFF290
0xD2DFE260
...
0xD2DFF290
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFF290i
j
p
adr
0xD2DFF290char nombres [256]j = strlen( nombres );
pp e d r o’n0’
c a r l o s’n0’
13 / 33
malloc y realloc en Arquitectura X86-32 bits
1
6
0xD2E002C0
0xD2DFE260
...
0xD2DFF290
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFF290
0xD2E002C0i
j
p
adr
0xD2DFF290char nombres [256]p = (char *) malloc ( j * sizeof (char) );
pp e d r o’n0’
c a r l o s’n0’
14 / 33
malloc y realloc en Arquitectura X86-32 bits
1
6
0xD2E002C0
0xD2DFE260
...
0xD2DFF290
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFF290
0xD2E002C0i
j
p
adr
0xD2DFF290
0xD2E002C0char nombres [256]strcpy ( p , nombres);
pp e d r o’n0’
c a r l o s’n0’
p e d r o’n0’
15 / 33
malloc y realloc en Arquitectura X86-32 bits
1
6
0xD2E002C0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFF290
0xD2E002C0i
j
p
adr
0xD2DFF290
0xD2E002C0char nombres [256]*(adr + i) = p;
pp e d r o’n0’
c a r l o s’n0’
p e d r o’n0’
16 / 33
malloc y realloc en Arquitectura X86-32 bits
1
6
0xD2E002C0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFF290
0xD2E002C0i
j
p
adr
0xD2DFF290
0xD2E002C0char nombres [256]*( *(adr+i) ) contiene al primer caracter y como es != @
adr = (char **) realloc( adr , ( i+2 ) * sizeof (char *) )
pp e d r o’n0’
c a r l o s’n0’
p e d r o’n0’
17 / 33
malloc y realloc en Arquitectura X86-32 bits
2
6
0xD2E002C0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFF290
0xD2E002C0i
j
p
adr
0xD2DFF290
0xD2E002C0char nombres [256]i++;
pp e d r o’n0’
c a r l o s’n0’
p e d r o’n0’
18 / 33
malloc y realloc en Arquitectura X86-32 bits
2
6
0xD2E002C0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFF290
0xD2E002C0i
j
p
adr
0xD2DFF290
0xD2E002C0char nombres [256]fgets( nombres , 256 , stdin );
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
19 / 33
malloc y realloc en Arquitectura X86-32 bits
2
5
0xD2E002C0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFF290
0xD2E002C0i
j
p
adr
0xD2DFF290
0xD2E002C0char nombres [256]j = strlen( nombres );
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
20 / 33
malloc y realloc en Arquitectura X86-32 bits
2
5
0xD2E002E0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adr
0xD2DFF290
0xD2E002C0char nombres [256]p = (char *) malloc ( j * sizeof (char) );
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
21 / 33
malloc y realloc en Arquitectura X86-32 bits
2
5
0xD2E002E0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0char nombres [256]strcpy ( p , nombres );
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
22 / 33
malloc y realloc en Arquitectura X86-32 bits
2
5
0xD2E002E0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0char nombres [256]*(adr + i ) = p;
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
23 / 33
malloc y realloc en Arquitectura X86-32 bits
2
5
0xD2E002E0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0char nombres [256]*( *(adr+i) ) contiene al primer caracter y como es != @
adr = (char **) realloc( adr , ( i+2 ) * sizeof (char *) )
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
24 / 33
malloc y realloc en Arquitectura X86-32 bits
3
5
0xD2E002E0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0char nombres [256]i++
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
25 / 33
malloc y realloc en Arquitectura X86-32 bits
3
5
0xD2E002E0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0char nombres [256]fgets( nombres , 256 , stdin );
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
26 / 33
malloc y realloc en Arquitectura X86-32 bits
3
5
0xD2E002E0
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0char nombres [256]j = strlen( nombres );
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
27 / 33
malloc y realloc en Arquitectura X86-32 bits
3
5
0xD2E00300
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xD2E00300i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0char nombres [256]p = (char *) malloc ( j * sizeof (char) );
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
28 / 33
malloc y realloc en Arquitectura X86-32 bits
3
5
0xD2E00300
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xXXXXXXXX
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xD2E00300i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xD2E00300char nombres [256]strcpy ( p , nombres );
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
29 / 33
malloc y realloc en Arquitectura X86-32 bits
3
5
0xD2E00300
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xD2E00300
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xD2E00300i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xD2E00300char nombres [256]*( adr + i ) = p;
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
30 / 33
malloc y realloc en Arquitectura X86-32 bits
3
5
0xD2E00300
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
0xD2E00300
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0char nombres [256]*( *(adr+i) ) contiene al primer caracter y es @, salimos del loop
free( p );
@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
31 / 33
malloc y realloc en Arquitectura X86-32 bits
3
5
0xD2E00300
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
NULL
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adr
0xD2DFF290
0xD2E002C0
0xD2E002E0char nombres [256]*( adr + i ) = NULL;
@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
32 / 33
malloc y realloc en Arquitectura X86-32 bits
3
5
0xD2E00300
0xD2DFE260
...
0xD2DFF290
0xD2E002C0
0xD2E002E0
NULL
...
...
...
...
...0xD2DFE260
0xD2DFE264
0xD2DFE268
0xD2DFE26C
0xD2DFF290
0xD2E002C0
0xD2E002E0i
j
p
adrchar nombres [256]Por último imprimme los nombres ingresados
y libera los bloque de memoria reservado
@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
33 / 33
