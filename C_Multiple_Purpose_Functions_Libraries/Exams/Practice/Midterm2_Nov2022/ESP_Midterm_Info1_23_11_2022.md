# Original Text - Midterm_Info1_23_11_2022.pdf

Universidad Tecnológica Nacional 
Facultad Regional  Buenos Aires 
Departamento de Ingeniería  Electrónica
Informática I 
___-___-___ 
2º Parcial 
R1001
Legajo
Apellido y Nombre
Nota:
Teóricos
1)
SOCKET s
a)
Mencionar
y
describir
las
funciones
del
lenguaje
C
que
se
utilizan
para 
realizar un servidor y un cliente T CP. 
b)
¿Qué
parámetros
se
tienen
que
definir
para
establecer
una 
comunicación T CP? Además aclare que identifican cada uno de ellos. 
2)
THREADs
a)
¿Cómo
se
soluciona
el
múltiple
acceso
a
una
variable
global
desde 
varios THREADs?
b)
Diferenciar las funciones:
int pthread_detach(pthread_t thread);
int pthread_join(pthread_t thread, v oid **retv al);
c)
Describir un procedimiento par a crear un número dinámico de threads. 
d)
¿ Cómo gener aría? 
i.
Una v ariable propia par a cada thread. 
ii.
Una v ariable a la que todos los thread puedan acceder . 
iii.
Una
variable
cuyo
valor
inicial
depende
del
orden
de
creación
del 
thread. 
3)
¿ Que hace la siguiente función ?
int fun(char *cadena)
{ 
int a=0;
if(*cadena) 
a=fun(cadena+1); 
return ++a; 
}
T1
T2
T3
P1
P2
P3
10%
10%
15%
15%
20%
30%
Condición de aprobación 60%.

Universidad Tecnológica Nacional 
Facultad Regional  Buenos Aires 
Departamento de Ingeniería  Electrónica
Informática I 
___-___-___ 
2º Parcial 
R1001
Legajo
Apellido y Nombre
Nota:
Práctica:
1)
Realizar una función que recibe un entero en el que tiene que:
a)
Contar
las
veces
que
aparece
el
patrón
de
bits
101
y
retornar
ese 
valor. 
b)
Si
el
patrón
aparece
un
número
PAR
de
veces,
intercambiar
parte
alta 
con
la
parte
baja
del
número
original
(Ej:
12345678
pasa
a
ser 
567812349)
c)
Si
el
patrón
aparece
un
número
IMPAR
de
veces,
intercambiar
los
0s
y 
1s (Ej: 101101 pasa a ser 010010) 
2)
Realizar
una
función
que
recibe
un
char
*listado[]
(último
elemento
en 
NULL)
y
lo
retorna
con
las
cadenas
ordenadas
alfabéticamente.
(se
puede 
usar string.h).
3)
Realizar
una
función
que
recibe
un
puntero
a
una
lista
con
estructur as
tipo 
productos,
donde
el
código
es
un
número
de
1
a
10.
La
función
tiene
que 
verificar
si
hay
códigos
que
se
repiten,
y
en
el
caso
de
encontr arse
con
esto 
tiene que:
a)
Incrementar
el
número
de
productos
en
el
primer
nodo
de
la
lista
que 
contenga ese código . 
b)
Borrar de la lista todos los nodos que contengan un código repetido .
typedef struct nodo {
char nombre[10];
int cant;
char codigo;
struct nodo *sig;
}productos;
T1
T2
T3
P1
P2
P3
10%
10%
15%
15%
20%
30%
Condición de aprobación 60%.

