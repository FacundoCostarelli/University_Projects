# Translated Text - 1st_Midterm_modelo_2022.pdf

Practice (on PC)
1) For the defined prototype perform the functions
•int function1(int i,int n,long double xi, long double xf, long double *x, long double *y)
a)Make a function that calculates n values of y for a range of values from x to
constant intervals knowing that: ∑
i=0k
(−1)ix2i+1
(2i+1)!
b)Make a function that calculates n values of y for a range of values from x to
constant intervals knowing that: ∑
i=0k
(−1)ix2i
(2i)! 
then perform the main, as an argument it is given k. A menu is presented with the options:
•Enter data (n; xi, xf)
•Call f1.
•Call f2.
•Do f1(f2).
•Do f2(f1)
•Exit.
2) Make a function that receives a pointer to an array of characters and
vector of integers, in each integer you will put the number of times it appears
each letter of the alphabet (without ñ and without distinguishing uppercase from lowercase).  In the
character array. Make the main that calls said function and prints the
result.
Theory (without using a PC)
1) According to the following statements:
char string[10]="Info 1";
char *p=string;
Indicate the output of the following lines on a 64-bit architecture.
     printf("%li\n",sizeof(string));
     printf("%li\n",strlen(string));
     printf("%li\n",sizeof(p));
     printf("%li\n",strlen(p));
     printf("%li\n",sizeof(*p));
2) Differentiate a Union from a Structure. Give an example of each, indicating size, declaration, definition, and ways to access its members (with their names and with a pointer to them.