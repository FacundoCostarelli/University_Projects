# Translated Text - puntoflotante.pdf

COMPUTING I
Representation of real numbers IEEE (754)
Ing.Juan Carlos Cuttitta
National Technological University
Buenos Aires Regional Faculty
Department of Electronic Engineering
May 7, 2019
Ing.Juan Carlos Cuttitta COMPUTER I
Review of scientiﬁc notation!!!!
R=cbe
Rrepresents all the numbers included in the
interval (-1 to +1).
c is the coefficient and is formed by a real number with
a single whole digit followed by a comma and several digits
fractional.
b is the basis of the numbering system
16 in hexadecimal
10 in decimal
8 in the octal
2 in binary
e is the integer exponent which raises the base to a
power.
Ing.Juan Carlos Cuttitta COMPUTER I
Review of scientiﬁc notation!!!!
The coefficient has a certain number of digits
signiﬁcant and this quantity indicates the precision of the number
represented. The more digit, the higher the precision.
Example with Euler number:
2;71 100lowest precision
2;718281 100higher precisionc be
Ing.Juan Carlos Cuttitta COMPUTER I
Review of scientiﬁc notation!!!!
By multiplying the coefficient (c) by the base (b) raised to a
integer power (e), what we are doing is displacing
the comma of the coefficient (c) as many positions as indicated by the
exponent (e). The comma moves to the right if the
exponent is positive and to the left if it is negative.
Examples:
Scientific notation Representation of n R
3;14159 10 20.0314159
3;14159 10 10.314159
3;14159 1003.14159
3;14159 10131.4159
3;14159 102314.159
Ing.Juan Carlos Cuttitta COMPUTER I
IEEE standard for floating point (IEEE 754)
The floating point allows us to represent a limited quantity
of digits of an R
A number R cannot be represented with complete precision
but as an approximation.
The precision will depend on the number of digits
meanings that the comma representation has
floating.
approximate real value sign
mantiza =1, fraction in binarybaseexponent
v=s m 2e
Ing.Juan Carlos Cuttitta COMPUTER I
IEEE standard for floating point (IEEE 754)
Since 1 m < 2y in order to normalize the representation
binary, only the binary fraction is placed in the blanket and
implicitly assumes the 1 that is located to the left of the
comma.
As can be seen in the figure, we need to obtain the
sign, fraction and exponent; where the latter is
represents in shifted binary.
31 30 2322 02( 127+ exp)
8bits 1bit 23bitsSign Exponent fraction
Ing.Juan Carlos Cuttitta COMPUTER I
IEEE standard for floating point (IEEE 754)
Practical example with the number -37,625
We convert the integer part to binary as seen in the
following table (in our example it is 37).
division result remainder
37 2 18 1
18 2 9 0
9 2 4 1
4 2 2 0
2 2 1 0
1 2 0 1
(37) 10= (100101) 2
Ing.Juan Carlos Cuttitta COMPUTER I
IEEE standard for floating point (IEEE 754)
Then we convert the decimal part to binary as seen in the
following table (in our example it is 0.625).
multiplication result whole part
0;625 2 1.25 1
0;25 2 0.5 0
0;5 2 1 1
In this way the representation of the
number in binary format.
( 37;625) 10= ( 100101 ;101) 2
Ing.Juan Carlos Cuttitta COMPUTER I
IEEE standard for floating point (IEEE 754)
The result is represented in scientiﬁc notation.
1;00101101 25
To obtain the value of the exponent, exp is cleared from the
following equality.
2(127+ exp)=25
127 + exp = 5
exp = 5 + 127
exp = 132
(132) 10= (10000100) 2
Ing.Juan Carlos Cuttitta COMPUTER I
IEEE standard for floating point (IEEE 754)
11000010000101101000000000000000sign
exp fraction complete with zeros0
1positive
negative
( 37;625) 10= 1;00101101 25
The approximate precision range for 32 normalized bits is
binary decimal
2 126a21271;18 10 38a3;4 1038
Ing.Juan Carlos Cuttitta COMPUTER I
scanf function for float data type
0x13
0x27
0x01
0x200x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46X86 32-bit architecture
addresses of
memoryVariable layout
dataFloat in memory
Code in source program
The memory can initially
contain any value !!!Reserve a space of
memory type ﬂoatdataFloat
1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 f l o a t dataFloat ;
6. . . . . .
7. . . . . .
8 r e t u r n ( 0 ) ;
9 }
Ing.Juan Carlos Cuttitta COMPUTER I
scanf function for float data type
0x13
0x27
0x01
0x200x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layouthim
dataFloat in memory
Code in source program
Print on screen a
legend for userdataFloat1 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 f l o a t dataFloat ;
6
7 // Data entry
8 p r i n t f ( "Enter value: " ) ;
9. . . . . .
10. . . . . .
11 r e t u r n ( 0 ) ;
12 }
Ing.Juan Carlos Cuttitta COMPUTER I
scanf function for float data type
0x13
0x27
0x01
0x200x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Code in source program
Indicates the type of data that
keyboard takedataFloat1 # include < s t d i o . h>
2
3 i n t main ( void )
4 {
5 f l o a t dataFloat ;
6
7 // Data entry
8 p r i n t f ( "Enter value: " ) ;
9 scanf ( " % f " , &dataFloat ) ;
10. . . . . .
11. . . . . .
12 r e t u r n ( 0 ) ;
13 }
Ing.Juan Carlos Cuttitta COMPUTER I
scanf function for float data type
0x13
0x27
0x01
0x200x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Code in source program
Indicates the memory address
where the data will be savedFloat1 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 f l o a t dataFloat ;
6
7 // Data entry
8 p r i n t f ( "Enter value: " ) ;
9 scanf ( " % f " , &dataFloat ) ;
10. . . . . .
11. . . . . .
12 r e t u r n ( 0 ) ;
13 }
Ing.Juan Carlos Cuttitta COMPUTER I
scanf function for float data type
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Code in source program
The data entered was
the number 37;625datoFloat1 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 f l o a t dataFloat ;
6
7 // Data entry
8 p r i n t f ( "Enter value: " ) ;
9 scanf ( " % f " , &dataFloat ) ;
10. . . . . .
11. . . . . .
12 r e t u r n ( 0 ) ;
13 }
Ing.Juan Carlos Cuttitta COMPUTER I
printf function for float data type
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Code in source program
Enter value: -37,625
float size: 4
dataFloat1 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 f l o a t dataFloat ;
6
7 // Data entry
8 p r i n t f ( "Enter value: " ) ;
9 scanf ( " % f " , &dataFloat ) ;
10 // Data printing
11 p r i n t f ( " f l o a t size : \ t %d \ r \ n " , ( i n t ) s i z e o f ( datoFloat ) ) ;
12. . . . . .
13 r e t u r n ( 0 ) ;
14 }
Ing.Juan Carlos Cuttitta COMPUTER I
printf function for float data type
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Code in source program
Enter value: -37,625
float size: 4
the real data: -37.625000
dataFloat1 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 f l o a t dataFloat ;
6
7 // Data entry
8 p r i n t f ( "Enter value: " ) ;
9 scanf ( " % f " , &dataFloat ) ;
10 // Data printing
11 p r i n t f ( " f l o a t size : \ t %d \ r \ n " , ( i n t ) s i z e o f ( datoFloat ) ) ;
12 p r i n t f ( " the data in real: \t % f \ r \ n " , dataFloat ) ;
13. . . . . .
14 r e t u r n ( 0 ) ;
15 }
Ing.Juan Carlos Cuttitta COMPUTER I
printf function for float data type
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Code in source program
Enter value: -37,625
float size: 4
the real data: -37.625000
the real data: -37.62
dataFloat1 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 f l o a t dataFloat ;
6
7 // Data entry
8 p r i n t f ( "Enter value: " ) ;
9 scanf ( " % f " , &dataFloat ) ;
10 // Data printing
11 p r i n t f ( " f l o a t size : \ t %d \ r \ n " , ( i n t ) s i z e o f ( datoFloat ) ) ;
12 p r i n t f ( " the data in real: \t % f \ r \ n " , dataFloat ) ;
13 p r i n t f ( " the data in real: \ t % 0.2 f \ r \ n " , dataFloat ) ;
14. . . . . .
15 r e t u r n ( 0 ) ;
16 }
Ing.Juan Carlos Cuttitta COMPUTER I
printf function for float data type
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E450x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Code in source program
Enter value: -37,625
float size: 4
the real data: -37.625000
the real data: -37.62
memory address: 0x7FFE6E41
dataFloat1 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 f l o a t dataFloat ;
6 // Data entry
7 p r i n t f ( "Enter value: " ) ;
8 scanf ( " % f " , &dataFloat ) ;
9 // Data printing
10 p r i n t f ( " f l o a t size : \ t %d \ r \ n " , ( i n t ) s i z e o f ( datoFloat ) ) ;
11 p r i n t f ( " the data in real: \t % f \ r \ n " , dataFloat ) ;
12 p r i n t f ( " the data in real: \ t % 0.2 f \ r \ n " , dataFloat ) ;
13 p r i n t f ( " memory address : \t %p \ r \ n " , &datoFloat ) ;
14 r e t u r n ( 0 ) ;
15 }
Ing.Juan Carlos Cuttitta COMPUTER I
Verification of float data stored in memory
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Enter value: -37,625
the data in ﬂoat: -37.625000
memory address: 0x7FFE6E41
content of p is : 0x7FFE6E41
the data in *p is: 0x00
the data in *(p+1) is: 0x80
the data in *(p+2) is: 0x16
the data in *(p+3) is: 0xC21 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 unsigned char p ;
6 f l o a t dataFloat ;
7 p=( unsigned char )&dataFloat ;
8 // Data entry
9 p r i n t f ( "Enter value: " ) ;
10 scanf ( " % f " , &dataFloat ) ;
11 // Data printing
12 p r i n t f ( " the data in f l o a t : \ t % f \ r \ n " , dataFloat ) ;
13 p r i n t f ( " memory address : \ t %p \ r \ n " ,& datoFloat ) ;
14 p r i n t f ( " content of p is: \ t %p \ r \ n " ,& dataFloat ) ;
15 p r i n t f ( " the data in p is: \ t %#x \ r \ n " , p ) ;
16 p r i n t f ( " the data in (p+1) : \ t %#x \ r \ n " , (p+1) ) ;
17 p r i n t f ( " the data in (p+2) : \ t %#x \ r \ n " , (p+2) ) ;
18 p r i n t f ( " the data in (p+3) : \ t %#x \ r \ n " , (p+3) ) ;
19 r e t u r n ( 0 ) ;
20 }
Ing.Juan Carlos Cuttitta COMPUTER I
Verification of float data stored in memory
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Enter value: -37,625
the data in ﬂoat: -37.625000
memory address: 0x7FFE6E41
content of p is : 0x7FFE6E41
the data in *p is: 0x00
the data in *(p+1) is: 0x80
the data in *(p+2) is: 0x16
the data in *(p+3) is: 0xC21 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 unsigned char p ;
6 f l o a t dataFloat ;
7 p=( unsigned char )&dataFloat ;
8 // Data entry
9 p r i n t f ( "Enter value: " ) ;
10 scanf ( " % f " , &dataFloat ) ;
11 // Data printing
12 p r i n t f ( " the data in f l o a t : \ t % f \ r \ n " , dataFloat ) ;
13 p r i n t f ( " memory address : \ t %p \ r \ n " ,& datoFloat ) ;
14 p r i n t f ( " content of p is: \ t %p \ r \ n " ,& dataFloat ) ;
15 p r i n t f ( " the data in p is: \ t %#x \ r \ n " , p ) ;
16 p r i n t f ( " the data in (p+1) : \ t %#x \ r \ n " , (p+1) ) ;
17 p r i n t f ( " the data in (p+2) : \ t %#x \ r \ n " , (p+2) ) ;
18 p r i n t f ( " the data in (p+3) : \ t %#x \ r \ n " , (p+3) ) ;
19 r e t u r n ( 0 ) ;
20 }
Ing.Juan Carlos Cuttitta COMPUTER I
Verification of float data stored in memory
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Enter value: -37,625
the data in ﬂoat: -37.625000
memory address: 0x7FFE6E41
content of p is : 0x7FFE6E41
the data in *p is: 0x00
the data in *(p+1) is: 0x80
the data in *(p+2) is: 0x16
the data in *(p+3) is: 0xC21 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 unsigned char p ;
6 f l o a t dataFloat ;
7 p=( unsigned char )&dataFloat ;
8 // Data entry
9 p r i n t f ( "Enter value: " ) ;
10 scanf ( " % f " , &dataFloat ) ;
11 // Data printing
12 p r i n t f ( " the data in f l o a t : \ t % f \ r \ n " , dataFloat ) ;
13 p r i n t f ( " memory address : \ t %p \ r \ n " ,& datoFloat ) ;
14 p r i n t f ( " content of p is: \ t %p \ r \ n " ,& dataFloat ) ;
15 p r i n t f ( " the data in p is: \ t %#x \ r \ n " , p ) ;
16 p r i n t f (" the datain (p+1) : \ t %#x \ r \ n " , (p+1) ) ;
17 p r i n t f ( " the data in (p+2) : \ t %#x \ r \ n " , (p+2) ) ;
18 p r i n t f ( " the data in (p+3) : \ t %#x \ r \ n " , (p+3) ) ;
19 r e t u r n ( 0 ) ;
20 }
Ing.Juan Carlos Cuttitta COMPUTER I
Verification of float data stored in memory
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Enter value: -37,625
the data in ﬂoat: -37.625000
memory address: 0x7FFE6E41
content of p is : 0x7FFE6E41
the data in *p is: 0x00
the data in *(p+1) is: 0x80
the data in *(p+2) is: 0x16
the data in *(p+3) is: 0xC21 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 unsigned char p ;
6 f l o a t dataFloat ;
7 p=( unsigned char )&dataFloat ;
8 // Data entry
9 p r i n t f ( "Enter value: " ) ;
10 scanf ( " % f " , &dataFloat ) ;
11 // Data printing
12 p r i n t f ( " the data in f l o a t : \ t % f \ r \ n " , dataFloat ) ;
13 p r i n t f ( " memory address : \ t %p \ r \ n " ,& datoFloat ) ;
14 p r i n t f ( " content of p is: \ t %p \ r \ n " ,& dataFloat ) ;
15 p r i n t f ( " the data in p is: \ t %#x \ r \ n " , p ) ;
16 p r i n t f ( " the data in (p+1) : \ t %#x \ r \ n " , (p+1) ) ;
17 p r i n t f ( " the data in (p+2) : \ t %#x \ r \ n " , (p+2) ) ;
18 p r i n t f ( " the data in (p+3) : \ t %#x \ r \ n " , (p+3) ) ;
19 r e t u r n ( 0 ) ;
20 }
Ing.Juan Carlos Cuttitta COMPUTER I
Verification of float data stored in memory
0x00
0x80
0x16
0xC20x7FFE6E41
0x7FFE6E42
0x7FFE6E43
0x7FFE6E44
0x7FFE6E45
0x7FFE6E46
addresses of
memoryVariable layout
dataFloat in memory
Enter value: -37,625
the data in ﬂoat: -37.625000
memory address: 0x7FFE6E41
content of p is : 0x7FFE6E41
the data in *p is: 0x00
the data in *(p+1) is: 0x80
the data in *(p+2) is: 0x16
the data in *(p+3) is: 0xC21 # include < st d i o . h>
2
3 i n t main ( void )
4 {
5 unsigned char p ;
6 f l o a t dataFloat ;
7 p=( unsigned char )&dataFloat ;
8 // Data entry
9 p r i n t f ( "Enter value: " ) ;
10 scanf ( " % f " , &dataFloat ) ;
11 // Data printing
12 p r i n t f ( " the data in f l o a t : \ t % f \ r \ n " , dataFloat ) ;
13 p r i n t f ( " memory address : \ t %p \ r \ n " ,& datoFloat ) ;
14 p r i n t f ( " content of p is: \ t %p \ r \ n " ,& dataFloat ) ;
15 p r i n t f ( " the data in p is: \ t %#x \ r \ n " , p ) ;
16 p r i n t f ( " the data in (p+1) : \ t %#x \ r \ n " , (p+1) ) ;
17 p r i n t f ( " the data in (p+2) : \ t %#x \ r \ n " , (p+2) ) ;
18 p r i n t f ( " the data in (p+3) : \ t %#x \ r \ n " , (p+3) ) ;
19 r e t u r n ( 0 ) ;
20 }
Ing.Juan Carlos Cuttitta COMPUTER I