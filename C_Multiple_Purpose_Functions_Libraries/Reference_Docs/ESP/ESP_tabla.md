# Original Text - tabla.pdf

INFORMATICA I
Practica con punteros
Ing.Juan Carlos Cuttitta
Universidad Tecnológica Nacional
Facultad Regional Buenos Aires
Departamento de Ingeniería Electrónica
24 de junio de 2020
1 / 12
Dada la declaración de las siguientes variables y su
representación en memoria
int a , b , *p , *q , **r , **s;
Complete la siguiente tabla con los valores que tomarán las
variables y lo apuntado por sus contenidos en las columnas
correspondientes.
Cuando no sea posible indicar un valor, señalelo con el signo ?
Las letras,,,,ysimbolizan las direcciones de
memoria en las que se encuentran ubicadas las variables.
1 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b
r=& p ; s=& q
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
a
b
p
q
r
sdirecciones de
memoriasolo almacena enteros
solo almacena enteros
2 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q
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
a
b
p
q
r
sdirecciones de
memoriasolo almacena direcciones
que apuntan a un entero
3 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4   9 4     9 4
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
a
b
p
q
r
sdirecciones de
memoria
solo almacena direcciones
que apuntan a otra dirección
y esa dirección apunta a un entero
4 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4   9 4     9 4
**r = *q 4 4   4 4     4 4
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
a
b
p
q
r
sdirecciones de
memoria variables
5 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4   9 4     9 4
**r = *q 4 4   4 4     4 4
*p = *q + **s 8 4   8 4     8 4
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
a
b
p
q
r
sdirecciones de
memoria variables
6 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4   9 4     9 4
**r = *q 4 4   4 4     4 4
*p = *q + **s 8 4   8 4     8 4
r = s ; q = p 8 4   8 8     8 8
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
a
b
p
q
r
sdirecciones de
memoria variables
7 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4   9 4     9 4
**r = *q 4 4   4 4     4 4
*p = *q + **s 8 4   8 4     8 4
r = s ; q = p 8 4   8 8     8 8
*(& a) = *(& b) 4 4   4 4     4 4
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
a
b
p
q
r
sdirecciones de
memoria variables
8 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4   9 4     9 4
**r = *q 4 4   4 4     4 4
*p = *q + **s 8 4   8 4     8 4
r = s ; q = p 8 4   8 8     8 8
*(& a) = *(& b) 4 4   4 4     4 4
b = a - **r + *p 4 4   4 4     4 4
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
a
b
p
q
r
sdirecciones de
memoria variables
9 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4   9 4     9 4
**r = *q 4 4   4 4     4 4
*p = *q + **s 8 4   8 4     8 4
r = s ; q = p 8 4   8 8     8 8
*(& a) = *(& b) 4 4   4 4     4 4
b = a - **r + *p 4 4   4 4     4 4
*p = a 4 4   4 4     4 4
q=& b ; r =& p
*q=*q -**s+**(& p)
4
4




...




a
b
p
q
r
sdirecciones de
memoria variablesNADA CAMBIA !!
10 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4   9 4     9 4
**r = *q 4 4   4 4     4 4
*p = *q + **s 8 4   8 4     8 4
r = s ; q = p 8 4   8 8     8 8
*(& a) = *(& b) 4 4   4 4     4 4
b = a - **r + *p 4 4   4 4     4 4
*p = a 4 4   4 4     4 4
q=& b ; r =& p 4 4   4 4     4 4
*q=*q -**s+**(& p)
4
4




...




a
b
p
q
r
sdirecciones de
memoria variables
11 / 12
Arquitectura X86-32 bits
expresión a b p q *p *q r s *r *s **r **s
a=9 ; b=4 9 4 ? ? ? ? ? ? ? ? ? ?
p=& a ; q=& b 9 4   9 4 ? ? ? ? ? ?
r=& p ; s=& q 9 4   9 4     9 4
**r = *q 4 4   4 4     4 4
*p = *q + **s 8 4   8 4     8 4
r = s ; q = p 8 4   8 8     8 8
*(& a) = *(& b) 4 4   4 4     4 4
b = a - **r + *p 4 4   4 4     4 4
*p = a 4 4   4 4     4 4
q=& b ; r =& p 4 4   4 4     4 4
*q=*q -**s+**(& p) 4 4   4 4     4 4
4
4




...




a
b
p
q
r
sdirecciones de
memoria variables
12 / 12
