# Translated Text - mallocmatriz.pdf

COMPUTING I
Dynamic matrix with malloc
Ing.Juan Carlos Cuttitta
National Technological University
Buenos Aires Regional Faculty
Department of Electronic Engineering
June 23, 2020
1/35
Problem statement
Example to assemble a matrix (N x N) in
dynamic form using malloc.
In this example the matrix will be (2 x 3)
remaining as follows:
11 12 13
21 22 23
1/35
NxN matrix with malloc on X86-32-bit Architecture
0
0
0
0
0xXXXXXXXX
...
...
...
...0xFFE07600i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
2 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
0
2
3
0xXXXXXXXX
...
...
...
...0xFFE07600i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
3 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
0
2
3
0x5E1D4A80
...
...
...
...0x5E1D4A80
0x5E1D4A84i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
4 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
...
...
...0x5E1D4A80 mtz[0]
0x5E1D4A84
0x5E1D4AA0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
5 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
6 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
7 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
8 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
9 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0...
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
10 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
11 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
1
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
12 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
1
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
13 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
1
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
14 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
2
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
15 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
2
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
16 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
2
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
17 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
3
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
18 / 35
NxN matrix with malloc on X86-32-bit Architecture
0
3
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
Does not meet the condition
and exits the loop for1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
19 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
3
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
20 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
3
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
21 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
22 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
23 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
0
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0] 0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
24/35
NxN matrix with malloc on X86-32-bit Architecture
1
1
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0] 0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
25 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
1
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0] 0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
26 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
1
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
22
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0]
mtz[1][1]0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
27 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
2
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
22
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0]
mtz[1][1]0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
28 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
2
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
22
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0]
mtz[1][1]0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free(mtz)
31 r e t u r n ( 0 ) ;
32 }
29 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
2
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
22
23
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0]
mtz[1][1]
mtz[1][2]0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
30/35
NxN matrix with malloc on X86-32-bit Architecture
1
3
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
22
23
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0]
mtz[1][1]
mtz[1][2]0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
31 / 35
NxN matrix with malloc on X86-32-bit Architecture
1
3
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
22
23
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0]
mtz[1][1]
mtz[1][2]0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
Does not meet the condition
and exits the loop for1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
32 / 35
NxN matrix with malloc on X86-32-bit Architecture
2
3
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
22
23
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0]
mtz[1][1]
mtz[1][2]0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ("\ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
33 / 35
NxN matrix with malloc on X86-32-bit Architecture
2
3
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
22
23
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0]
mtz[1][1]
mtz[1][2]0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)
Does not meet the condition and
exits the for loop of i1 #include < st d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
34/35
NxN matrix with malloc on X86-32-bit Architecture
2
3
2
3
0x5E1D4A80
...
0x5E1D4AA0
0x5E1D4AC0
...
11
12
13
...
21
22
23
...0x5E1D4A80 mtz[0]
mtz[1] 0x5E1D4A84
0x5E1D4AA0 mtz[0][0]
mtz[0][1]
mtz[0][2]
mtz[1][0]
mtz[1][1]
mtz[1][2]0x5E1D4AC0i
j
file
row
mtzexample for matrix (2x3)

11 12 13
21 22 23 1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
35 / 35
NxN matrix with malloc on X86-32-bit Architecture
2
3
2
3
0xXXXXXXXX
...
...
11
12
13
...
21
22
23
...i
j
file
row
mtzexample for matrix (2x3)
I release all memory
requested with malloc1 #include < s t d i o . h>
2 # include < st d l i b . h>
3
4 i n t main ( void )
5 {
6 i n t f i l e =0 ,row=0 , i =0 , j =0;
7 i n t mtz ;
8
9 p r i n t f ( " enter rows and columns \n " ) ;
10 scanf ( " %d %d " ,& f i l e , & row ) ;
11 mtz =( in t ) malloc ( f i l e s i z e o f ( in t ) ) ;
12 f o r ( i =0 ; i < f i l e ; i ++) {
13 mtz [ i ] = ( i n t ) malloc ( row s i z e o f ( i n t ) ) ;
14 }
15 f o r ( i =0 ; i < f i l e ; i ++) {
16 f o r ( j =0 ; j < row ; j ++) {
17 p r i n t f ( " f i l e %d rows %d \ n " , i , j ) ;
18 scanf ( " %d " ,&mtz [ i ] [ j ] ) ;
19 }
20 }
21 p r i n t f ( " \ n " ) ;
22 f o r ( i =0 ; i < f i l e ; i ++) {
23 f o r ( j =0 ; j < row ; j ++) {
24 p r i n t f ( " %d \ t " , mtz [ i ] [ j ] ) ;
25 }
26 }
27 f o r ( i =0 ; i < f i l e ; i ++) {
28 free ( mtz [ i ] ) ;
29 }
30 free (mtz);
31 r e t u r n ( 0 ) ;
32 }
36/35