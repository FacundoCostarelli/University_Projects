# Translated Text - malloc.pdf

COMPUTING I
malloc and realloc
Ing.Juan Carlos Cuttitta
National Technological University
Buenos Aires Regional Faculty
Department of Electronic Engineering
June 27, 2020
1 / 33
Problem statement
Dynamically allocate memory to the vector
which contains the addresses of the
entered names and use memory
fair for each name.
The idea is that if I reserved space for a
vector that can store 256 bytes
but I enter a name that occupies 5
bytes, let's use the known resources
so that only the right spaces are used
of memory for those 5 bytes and not the 256
bytes for each name entered).
The program ends when a name
starts with the @ symbol
1 / 33
Example of malloc and realloc
1 i n t main ( void )
2 {
3 i n t i =0 , j =0;
4 char c, names [ 2 5 6 ];
5 char p ;
6 char adr ;
7
8 adr= ( char ) malloc ( s i z e o f ( char ) ) ;
9 c {
10 f g e t s ( names , 256 , st d i n ) ;
11 j = st r l e n ( names ) ;
12 p = (char) malloc (j s i z e o f (char)) ;
13 strcpy ( p , names ) ;
14 (adr + i) = p;
15 c = ( ( adr+ i ) ) ;
16 i f ( c != ’@’ ) {
17 adr = ( char ) r e a l l o c ( adr , ( i +2) s i z e o f ( char ) ) ;
18i++;
19 } else {
20 free (p);
21 (adr + i) = NULL;
22 }
23 } while ( c != ’@’ ) ;
24 f o r ( i =0 ; ( adr+ i ) != NULL ; i ++) {
25 p r i n t f ( " name %d : % s " , i , ( adr+ i ) ) ;
26 free ( ( adr+ i ) ) ;
27 }
28 free (adr);
29 r e t u r n 0;
30 }
2 / 33
malloc and realloc in X86-32-bit Architecture
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
adr char names [256]
3 / 33
malloc and realloc in X86-32-bit Architecture
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
adr char names [256]adr= (char **) malloc( sizeof (char *));
4 / 33
malloc and realloc in X86-32-bit Architecture
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
adr char names [256]fgets( names , 256 , stdin );
c a r l o s’n0’
5 / 33
malloc and realloc in X86-32-bit Architecture
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
adr char names [256]j = strlen( names );
c a r l o s’n0’
6 / 33
malloc and realloc in X86-32-bit Architecture
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
adr char names [256]p = (char *) malloc ( j * sizeof (char) );
pc a r l o s’n0’
7 / 33
malloc and realloc in X86-32-bit Architecture
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
adr char names [256]strcpy ( p , names );
0xD2DFF290
pc a r l o s’n0’
c a r l o s’n0’
8 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2DFF290char names [256]*( adr + i ) = p;
pc a r l o s’n0’
c a r l o s’n0’
9 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2DFF290char names [256]*( *(adr+i) ) contains the first character and how is != @
adr = (char **) realloc( adr , ( i+2 ) * sizeof (char *) )
pc a r l o s’n0’
c a r l o s’n0’
10 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2DFF290char names [256]i++;
pc a r l o s’n0’
c a r l o s’n0’
11 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2DFF290char names [256]fgets( names , 256 , stdin );
pp e d r o’n0’
c a r l o s’n0’
12 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2DFF290char names [256]j = strlen( names );
pp e d r o’n0’
c a r l o s’n0’
13 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2DFF290char names [256]p = (char *) malloc ( j * sizeof (char) );
pp e d r o’n0’
c a r l o s’n0’
14 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002C0char names [256]strcpy ( p , names);
pp e d r o’n0’
c a r l o s’n0’
p e d r o’n0’
15 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002C0char names [256]*(adr + i) = p;
pp e d r o’n0’
c a r l o s’n0’
p e d r o’n0’
16 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002C0char names [256]*( *(adr+i) ) contains the first character and how is != @
adr = (char **) realloc( adr , ( i+2 ) * sizeof (char *) )
pp e d r o’n0’
c a r l o s’n0’
p e d r o’n0’
17 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002C0char names [256]i++;
pp e d r o’n0’
c a r l o s’n0’
p e d r o’n0’
18 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002C0char names [256]fgets( names , 256 , stdin );
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
19 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002C0char names [256]j = strlen( names );
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
20 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002C0char names [256]p = (char *) malloc ( j * sizeof (char) );
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
21 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002E0char names [256]strcpy ( p , names );
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
22 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002E0char names [256]*(adr + i ) = p;
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
23 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002E0char names [256]*( *(adr+i) ) contains the first character and how is != @
adr = (char **) realloc( adr , ( i+2 ) * sizeof (char *) )
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
24 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002E0char names [256]i++
pj o s e’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
25 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002E0char names [256]fgets( names , 256 , stdin );
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
26 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002E0char names [256]j = strlen( names );
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
27 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002E0char names [256]p = (char *) malloc ( j * sizeof (char) );
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
28 / 33
malloc and realloc in X86-32-bit Architecture
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
......
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
0xD2E00300char names [256]strcpy ( p , names );
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
29 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E00300char names [256]*( adr + i ) = p;
p@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
30 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002E0char names [256]*( *(adr+i) ) contains the first character and it is @, we exit the loop
free(p);
@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
31 / 33
malloc and realloc in X86-32-bit Architecture
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
0xD2E002E0char names [256]*( adr + i ) = NULL;
@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
32 / 33
malloc and realloc in X86-32-bit Architecture
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
add names [256] Finally, print the names entered
and release the reserved memory blocks
@ c l a’n0’
c a r l o s’n0’
p e d r o’n0’
j o s e’n0’
@ c l a’n0’
33 / 33