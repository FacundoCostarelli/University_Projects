# Translated Text - tabla.pdf

COMPUTING I
Practice with pointers
Ing.Juan Carlos Cuttitta
National Technological University
Buenos Aires Regional Faculty
Department of Electronic Engineering
June 24, 2020
1/12
Given the declaration of the following variables and their
memory representation
int a, b, *p, *q, **r, **s;
Complete the following table with the values that the
variables and what is noted by their contents in the columns
corresponding.
When it is not possible to indicate a value, indicate it with the sign ?
The letters , , , , and symbolize the directions of
memory in which the variables are located.
1/12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=&b
r=& p ; s=&q
**r = *q
*p = *q + **s
r = s ; q = p
*(& a) = *(& b)
b = a - **r + *p
*p = a
q=& b ; r =& p
*q=*q -**s+**(& p)
9
4
...




to
b
p
q
r
addresses of
memory only stores integers
only stores integers
2 / 12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=&q
**r = *q
*p = *q + **s
r = s ; q = p
*(& a) = *(& b)
b = a - **r + *p
*p = a
q=& b ; r =& p
*q=*q -**s+**(& p)
9
4


...




to
b
p
q
r
addresses of
memoryonly stores addresses
that point to an integer
3 / 12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4 9 4 9 4
**r = *q
*p = *q + **s
r = s ; q = p
*(& a) = *(& b)
b = a - **r + *p
*p = a
q=& b ; r =& p
*q=*q -**s+**(& p)
9
4




...




to
b
p
q
r
addresses of
memory
only stores addresses
that point in another direction
and that address points to an integer
4 / 12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4 9 4 9 4
**r = *q 4 4 4 4 4 4
*p = *q + **s
r = s ; q = p
*(& a) = *(& b)
b = a - **r + *p
*p = a
q=& b ; r =& p
*q=*q -**s+**(& p)
4
4




...




to
b
p
q
r
addresses of
variable memory
5 / 12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4 9 4 9 4
**r = *q 4 4 4 4 4 4
*p = *q + **s 8 4 8 4 8 4
r = s ; q = p
*(& a) = *(& b)
b = a - **r + *p
*p = a
q=& b ; r =& p
*q=*q -**s+**(& p)
8
4




...




to
b
p
q
r
addresses of
variable memory
6 / 12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4 9 4 9 4
**r = *q 4 4 4 4 4 4
*p = *q + **s 8 4 8 4 8 4
r = s ; q = p 8 4 8 8 8 8
*(& a) = *(& b)
b = a - **r + *p
*p = a
q=& b ; r =& p
*q=*q -**s+**(& p)
8
4




...




to
b
p
q
r
addresses of
variable memory
7 / 12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4 9 4 9 4
**r = *q 4 4 4 4 4 4
*p = *q + **s 8 4 8 4 8 4
r = s ; q = p 8 4 8 8 8 8
*(& a) = *(& b) 4 4 4 4 4 4
b = a - **r + *p
*p = a
q=& b ; r =& p
*q=*q -**s+**(& p)
4
4




...




to
b
p
q
r
addresses of
variable memory
8 / 12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4 9 4 9 4
**r = *q 4 4 4 4 4 4
*p = *q + **s 8 4 8 4 8 4
r = s ; q = p 8 4 8 8 8 8
*(& a) = *(& b) 4 4 4 4 4 4
b = a - **r + *p 4 4 4 4 4 4
*p = a
q=& b ; r =& p
*q=*q -**s+**(& p)
4
4




...




to
b
p
q
r
addresses of
variable memory
9 / 12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4 9 4 9 4
**r = *q 4 4 4 4 4 4
*p = *q + **s 8 4 8 4 8 4
r = s ; q = p 8 4 8 8 8 8
*(& a) = *(& b) 4 4 4 4 4 4
b = a - **r + *p 4 4 4 4 4 4
*p = a 4 4 4 4 4 4
q=& b ; r =& p
*q=*q -**s+**(& p)
4
4




...




to
b
p
q
r
addresses of
variable memory NOTHING CHANGES!!
10/12
Architectto X86-32 bits
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4 9 4 9 4
**r = *q 4 4 4 4 4 4
*p = *q + **s 8 4 8 4 8 4
r = s ; q = p 8 4 8 8 8 8
*(& a) = *(& b) 4 4 4 4 4 4
b = a - **r + *p 4 4 4 4 4 4
*p = a 4 4 4 4 4 4
q=& b ; r =& p 4 4 4 4 4 4
*q=*q -**s+**(& p)
4
4




...




to
b
p
q
r
addresses of
variable memory
11/12
X86-32 bit architecture
expression a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4 9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4 9 4 9 4
**r = *q 4 4 4 4 4 4
*p = *q + **s 8 4 8 4 8 4
r = s ; q = p 8 4 8 8 8 8
*(& a) = *(& b) 4 4 4 4 4 4
b = a - **r + *p 4 4 4 4 4 4
*p = a 4 4 4 4 4 4
q=& b ; r =& p 4 4 4 4 4 4
*q=*q -**s+**(& p) 4 4 4 4 4 4
4
4




...




to
b
p
q
r
addresses of
variable memory
12/12