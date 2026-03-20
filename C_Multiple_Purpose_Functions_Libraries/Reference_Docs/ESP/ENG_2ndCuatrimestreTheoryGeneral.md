# Translated Text - 2ndCuatrimestreTheoryGeneral.pdf

2nd Semester 
➔ Partial. 
➔ Let's formalize Functions. 
➔ Let's formalize Data Types. 
➔ Let's formalize Numbering Systems. 
1
Features 
➔ Top-down methodology 
◆ Divide the problem into smaller parts that are easy to solve. 
➔ Build from what has already been done. 
➔ Independence of codes and data. 
➔ Be part of different source files and be compiled together. 
➔ We give it “arguments” and it returns a “single” result, the rest is 
transparent to our code. 
2
Deﬁnition Vs. Declaration. 
➔ Deﬁnition: it is the function itself, it will contain the code that executes said 
function. Just once. 
➔ Declaration : Tells the compiler the format of the function. When 
be necessary 
◆ Mandatory: when the function is called before deﬁning it. 
◆ Required: When the function is called in a file other than the one in 
the deﬁnition. 
◆ Optional: when the function is deﬁned before its first call. 
3
Definition 
●Three main components: 
a.First line. 
b.Declaration of arguments. 
c.Body 
They are not all mandatory. 
4
Definition: first line 
➔ Contains: 
a.Type of the return value. 
b.Function name. 
c.Arguments you receive. 
type name (arg1, arg2,........., argn) 
➔ Arguments are passed by value (via stack). These are not 
recognized outside the function. 
5
Deﬁnition: declaration of arguments 
➔ Each type of argument you receive must match the type of data you receive. 
is sent from the function call 
➔ It can be omitted if the types are declared along with the arguments in the 
first line 
a.type name(arg1, arg2,..........) 
type arg1 
type arg2 
b.type name(type arg1, type arg2,.........) 
6
Definition: body 
➔ Composite statement that defines the actions that the function must perform. 
➔ It is enclosed in braces { }. 
➔ The return statement is used to specify the value returned by the 
function. 
7
Declaration 
➔ The idea is to give the compiler information about the format of the function. 
➔ It is necessary to declare a function when: 
◆ It is called before its deﬁnition 
◆ It is called from codes written in different files. 
➔ The format of a declaration is: 
storage-type return-type name (argument-types) 
8
DATA TYPES 
➔ Character: char 
➔ Integers: int 
➔ Simple floating point density: ﬂoat 
◆ 
➔ Double density floating point: double 
◆ 
9Sign (1) Exponent (8) Mantissa (23) 
Sign (1) Exponent (11) Mantissa (52) 
Floating Point: IEEE 754 
10

QUALIFIERS 
➔short 
➔long 
➔signed 
➔unsigned 
11
CONSTANTS 
➔ #define 
◆ #define INTEGER 1234 
◆ #define N_LONG 1234L 
◆ #define N_UNSIGNED 1234U 
◆ #define CHARACTER 'A' 
◆ #define NVLIN '\n' 
◆ #define N_HEXA 0x1234 
◆ #define N_OCTAL 01234 
◆ #define STRING “HELLO WORLD\n” 
12
special characters 
13

CONSTANTS 
➔ enum 
◆ enum boolean {NO, YES };  // NO=0, YES =1. 
◆ enum months {January =1, February, March, April, May, June, July 
or, August, September, October, November, December };  // February 
=2, March= 3, . . . 
◆ enum escapes {BELL = '\a' , TAB = '\t' , NVLIN = '\n'}; 
They create a constant data “type” enum boolean, enum months and enum escapes 
respectively. 
14
VARIABLES 
➔ Deﬁnition: it is where a place in memory is assigned. 
◆ ﬂoat a; 
◆ int b, c; //outside the function => external 
◆ char text[100]; 
➔ Declaration: Informs the compiler of the nature of the variable, it does not assign 
memory; not always necessary. 
◆ ﬂoat a; 
◆ extern int b, c; //multiple files 
◆ char text[ ]; 
15
VARIABLES 
➔ Initialization: it is giving them an initial value in the deﬁnition, it is not mandatory. 
◆ ﬂoat a=3.14; 
◆ char text[11]= “hello world”; //10+null character 
◆ char text[]=”hello world” 
NOTE: These are deﬁnitions, not statements. 
16
Variable storage types 
➔ Data types 
◆ Char, int, ﬂoat and double. 
◆ Short, long, signed, unsigned 
➔ Types of storage 
◆ According to scope 
● Automatic (or local) 
● External (or global) 
◆ According to duration 
● Static 
● Dynamics 
◆ Depending on access speed 
● By registration 
● In memory 
17
Automatic storage (auto) 
➔ They are declared within the function and are local to it. 
◆ Can only be accessed from the function 
◆ It is not necessary to use the word car to define them 
18
External storage (extern) 
➔ Its scope extends from the point of deﬁnition to the rest of the 
program. 
◆ They maintain their value when entering and exiting functions 
◆ It is deﬁned outside the function where it can also be initialized 
◆ AloneThere must be a deﬁnition of each external variable 
◆ They are deﬁned as external due to their place outside the functions, so 
that extern is not used to deﬁne them. 
◆ It is declared using extern. 
◆ Do not abuse 
19
Static storage 
➔ Applicable to both local and global storage 
◆ Automatic static: They only exist in the function scope but 
They maintain their last value. 
◆ External statics: They will only be recognized in the file where they are 
defined. 
20
Storage in registers (register) 
➔ Tells the compiler to use an internal registry if possible. 
processor instead of memory to store its value. 
◆ Increase access speed 
◆ Used when the variable has a high degree of appearance in the 
code. 
◆ Only for automatic variables and formal parameters of a 
function. 
21
Summary 
● Global variables and functions can be defined as static 
● Variables or functions external to the deﬁnition file can be declared with “extern”. (1) 
● Local deﬁnitions or declarations can be automatic, static, external, or 
registration. 
22

Clarification 
➔ There is also the possibility of defining the types: 
◆ const : defines a constant in memory (you can optimize its access 
being in program memory). 
◆ volatile: defines a variable that can be modified outside the 
program to force the memory to be read whenever it is 
use. 
23
BINARY Representation 
➔ This correspondence between DIGITAL signal and BINARY numbering makes 
the latter an ideal tool to represent and analyze the 
behavior of the former. 
➔ The machine uses tension levels and the man represents them with 
binary numbers. 
24
DECIMAL system 
➔ The decimal system uses a BASE=10 
◆ I need 10 symbols (0 1 2 3 4 5 6 7 8 9). 
◆ The value of the number is given by the sum of each digit 
multiplied by its “weight”. 
For example: 
25

BINARY system 
➔ The binary system uses a BASE=2 
◆ I need 2 symbols (0 1). 
◆ The value of the number is given by the sum of each digit 
multiplied by its “weight”. 
For example: 
26

OCTAL system 
➔ The octal system uses a BASE=8 
◆ I need 8 symbols (0 1 2 3 4 5 6 7). 
◆ The value of the number is given by the sum of each digit 
multiplied by its “weight”. 
For example: 
27

HEXADECIMAL system 
➔ The hexadecimal system uses BASE=16 
◆ I need 8 symbols (0 1 2 3 4 5 6 7 8 9 A B C D E F). 
◆ The value of the number is given by the sum of each digit 
multiplied by its “weight”. 
For example: 
28

Let it be clear 
➔ We can represent a number in any base. 
➔ When representing it in different bases its symbolic expression changes but not 
its magnitude. 
A5h=165d=245o=10100101b 
29
Methods for CHANGE OF BASE 
Successive Divisions 
The number to be converted is divided by the base to be converted, until the quotient of 
a number less than said base. The result is made up of the last quotient 
and the remainders taken in the opposite direction to the sequence of quotients. 
30

Methods for CHANGE OF BASE 
Successive Divisions 
The number to be converted is divided by the base to be converted, until the quotient of 
a number less than said base. The result is made up of the last quotient 
and the remainders taken in the opposite direction to the sequence of quotients. 
In the case of decimals, it is multiplied by the base and the integer part is the 
searched digit. 
0.375x2= 0.75 => 0, 0
0.75x2= 1.5 => 0.0 1
0.5x2= 1 => 0.01 1
2,375d=10,011b 
31
Methods for CHANGE OF BASE 
Successive subtractions 
It consists of taking the number to convert and finding the largest power of 2 
that can be subtracted, taking the result of the subtraction as the new number 
to continue the process, as long as it is not negative. 
32

Quick Conversions 
➔ Binary to Octal. 
➔ Binary to Hexadecimal. 
1100101110b=1456o=32Eh 
33

TABLE 
34

Binary Representation on PC 
➔ PCs, like other digital devices, only work with two levels 
(0 and 1) 
➔ Problems: 
◆ How to represent negative numbers? 
◆ How to represent numbers with a comma? 
◆ We are limited in the width of the numbers we can handle 
inside the PC. 
35
Binary System: UNITS 
➔Bit [b]: acronym for Binary digit, (0 or 1). 
➔Nibble: Set of 4 bits. 
➔Byte [B]: Set of 8 bits. 
➔Word [w]: Set of 16 bits. 
➔DoubleWord: 32-bit set. 
➔QuadWord: 64-bit set. 
36
BINARY sum 
➔ As long as the sum does not exceed the maximum supported size, the sum sand 
performs without problem. 
➔ But if I exceed the maximum number of digits that I handle, I will have 
problems. 
◆ This is called CARRY (ﬂag c) 
37

Basic Operations 
Adding and subtracting within the set of INTEGERS brings us a new 
Problem when doing it on a PC: 
➔ How to represent negative numbers? 
➔ We will analyze different methods: 
➔ Sign and Magnitude. 
➔ 1's complement. 
➔ 2's complement. 
➔ Shifted Binary. 
38
Sign and Magnitude 
➔ As we already mentioned, within the PC we can only represent 0s and 
1s.
➔ Sign and Magnitude uses the most significant bit (MSB) to represent the 
sign and the rest for the module. 
➔ Thus, working with 4 bits we have to: 
0010b equals 2. 
1010b equals -2. 
39
Sign and Magnitude 
This method has some drawbacks: 
➔ 2 values are consumed to represent zero. 
0000b=1000b (0=-0) 
➔ You cannot use the same HARDWARE that adds positive numbers 
to add negative numbers. 
0010b+1001b=1011b (-3) 
2+(-1)=1 
40
1's complement (C1) 
➔ To represent a negative number, each bit is inverted for its 
complement (1 in 0 and vice versa). 
0111b=7d and 1000b=-0111b=-7d 
➔ We continue to have the problem of occupying two numbers to 
represent 0. 
0000b=0d and 1111b=-0000b=-0d 
➔ When adding two numbers with different signs, you must add the carry of the MSB 
to avoid errors. 
➔ This means that although we can use the same hardware, it will have 
We have to analyze what case it is. 
41
SUM OPERATION 
➔ If a carry occurs at the end of the addition/subtraction, add it to the result obtained 
(end-around carry) 
◆ 0010b+0100b=0110b (2+4=6) 
◆ 0010b+1110b=10000b+1=1 (2+(-1)=1) 
◆ 0010b+1100b=1110b=-1 (2+(-3)=-1) 
◆ 1101b+1011b=11000b+1=-6 (-2+(-4)=-6) 
◆ 0110b+0110b=1100b=-3 (6+6=12 => out of scale) 
◆ 1001b+1001b=10010b+1=3 (-6-6=-12 => out of scale) 
Be careful not to go off scale!!! 
42
NOTE 
The Internet protocols IPv4, ICMP, UDP and TCP all use the same 
16-bit one's complement checksum algorithm. 
Although most computers lack the hardware to handle 
end-around carry, the additional complexity is 
accepted since it is equally sensitive to errors in all positions 
of bits. In UDP, an all-zero representation indicates that the sum of 
optional verification has been skipped. The other representation, all of them, 
indicates a value of 0 in the checksum (checksums are 
mandatory for IPv4, TCP and ICMP; were omitted in IPv6). 
43
2's complement (C2) 
➔ To represent a negative number, each bit is inverted for its 
complement and 1 is added (C2=C1+1). 
0111b=7d 
0000b=0d 
1111b = -0000b+1= -1d 
1000b = -0111b+1= -8d 
➔ The ambiguity of zero is eliminated. 
➔ No adjustment required when adding 2 numbers with different signs. 
➔ We can use the same hardware. 
44
SUM OPERATION 
➔ If a carry occurs at the end of the addition/subtraction, add it to the result obtained 
(end-around carry) 
◆ 0010b+0100b=0110b (2+4=6) 
◆ 0010b+1111b=10001b=1 (2+(-1)=1) 
◆ 0010b+1101b=1111b=-1 (2+(-3)=-1) 
◆ 1110b+1100b=11010b=-6 (-2+(-4)=-6) 
◆ 0110b+0110b=1100b=-4 (6+6=12 => out of scale) 
◆ 1010b+1010b=10100b=4 (-6-6=-12 => out of scale) 
Be careful not to go off scale!!! 
45
Shifted Binary 
➔ The absolute value of half the range minus 1 is added to the signed value. 
➔ The excess format is common for the representation of the exponent in 
floating point numbers 
➔ Examples in 3bits: 
46

➔ 
47

Arithmetic FLAGs 
➔ Z = Zero ﬂag: The result is zero. 
➔ N = Negative ﬂag: The result is negative. 
➔ V = Overﬂow ﬂag: The result exceeds the number of bits it can handle 
the ALU. 
➔ P = Parity ﬂag: Parity of the number of 1s in the data. 
➔ C = Carry ﬂag: Carry of the operation carried out. 
48
Represent REAL 
➔ For now we only saw how to represent a small subset of the 
whole. 
➔ FLOATING POINT coding allows you to work (in the same type 
of data) with very large and very small magnitudes. 
➔ But the price to pay: the greater the range, the lower the precision and vice versa. 
49
RANGE and PRECISION 
➔ The number of bits is divided into three: 
◆ Sign 
◆ Mantissa (determines the number of digits we can represent: precision) 
◆ Exponent (determines the range of numbers we can represent) 
➔ Having the number of fixed digits limits the numbers I can 
represent. 
➔ For example, with 4 decimal digits we will have: 
◆ Range: 
● 0000 to 9999 
● 0.000 to 9.999 
◆ Pricesion: 
● From 1000 I go to 1001 (I cannot represent 1000.1) 
● From 1.001 I go to 1.002 (I cannot represent 1.0015) 
➔ 50
Binary Representation of Real Numbers 
➔ In general we have two formats: 
◆ Fixed Point. 
◆ Floating Point. 
51
Fixed Point with Sign 
➔ They are represented by an expression of the type: 
(an an−1 . . . a0 .a−1 a−2 . . . a−m )b = (−1)s ∗ (an ∗ 2n + · · · +a0 ∗ 20 + a−1 ∗ 2−1 + a−2 ∗ 2−2 + · · · + a−m ∗ 2−m )
◆ s is the sign: 0 positive and 1 negative. 
◆ The distance between two consecutive numbers is 2-m. 
◆ Example: -101.011b=(-1)¹[1x2²+0x2¹+1x2 ⁰+0x2 ⁻¹+1x2 ⁻²+1x2 ⁻³] 
It stops being a continuous range of numbers and becomes a range 
discreet For example, increments of 0.001b=0.125d 
52
Floating Point: Scientific Notation 
Decimal System 
➔ Allows you to represent real numbers. 
➔ Its format is: 
a: coefficient 
b: exponent 
➔ Example: 
➔ To unify the representation, Scientific Notation is used 
Normalized: 
53

Floating Point: Representation 
➔ They are represented with ordered pairs (m,e): 
m: mantissa; represents a fractional number. 
b: base; takes the value from the numbering system. 
e: exponent; an integer. 
54

Floating Point: IEEE 754 Format 
➔ IEEE: Institute of Electrical and Electronic Engineers 
◆ World technical-professional association dedicated to standardization. 
➔ IEEE 754 
◆ Standard for floating point arithmetic. 
◆ Widely used. 
◆ Defines representation, operations and special values. 
◆ Formats: 
● 16bits (Half precision) 
● 32bits (Single precision) 
● 64bits (Double precision) 
● 80bits (Double Extended Precision) 
● 128bits (Quadruple precision) 
➔ 
55
Floating Point: FORMATS 
56

Floating Point: RANKS 
57

Character representation 
➔ We will not only need to represent numbers. 
➔ Different types of symbols are used to represent letters and symbols. 
encodings. 
➔ Its representation will, without a doubt, be binary; but it will have to be encoded 
by some standard. 
◆ ASCII 
◆ ISO 8859-1 
◆ Unicode 
◆UTF
58
ASCII 
➔ American Standard Code for Information Interchange. 
➔ Created in 1963 by the American Standards Committee ASA (ANSI 
since 1969) 
➔ Defines 95 printable characters, numbered from 32 to 126 (0 to 31 and the 
127 are non-printable characters). 
➔ Based on the LATIN alphabet. 
➔ It uses 7 bits to represent the characters (1111111b=127). 
➔ Extended ASCII: uses 8 bits 
59
STANDARD ASCII table 
60

EXTENDED ASCII Table 
➔ 
61