# Translated Text - Midterm_Info1_23_11_2022.pdf

National Technological University 
Buenos Aires Regional Faculty 
Department of Electronic Engineering
Computer Science I 
___-___-___ 
2nd Partial 
R1001
File
Surname and First Name
Note:
Theorists
1)
SOCKETs
a)
Mention
and
describe
the
functions
of the
language
c
that
if
they use
for 
realize a T CP server and client. 
b)
what
parameters
if
they have
that
define
for
establish
one 
T CP communication? Also clarify that they identify each one of them. 
2)
THREADs
a)
How
if
solve
the
multiple
access
to
one
variable
global
since 
several THREADs?
b)
Differentiate functions:
int pthread_detach(pthread_t thread);
int pthread_join(pthread_t thread, v oid **retv al);
c)
Describe a procedure to create a dynamic number of threads. 
d)
How would it be generated? 
Yo.
An own variable for each thread. 
ii.
A variable that all threads can access. 
iii.
one
variable
whose
value
initial
it depends
of the
order
of
creation
of the 
thread. 
3)
What does the following function do?
int fun(char *string)
{ 
int a=0;
if(*string) 
a=fun(string+1); 
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
Approval condition 60%.

National Technological University 
Buenos Aires Regional Faculty 
Department of Electronic Engineering
Computer Science I 
___-___-___ 
2nd Partial 
R1001
File
Surname and First Name
Note:
Practice:
1)
Perform a function that receives an integer where you have to:
a)
count
the
times
that
appears
the
pattern
of
bits
101
and
return
that 
value. 
b)
Yes
the
pattern
appears
a
number
PAIR
of
times,
exchange
part
high 
with
the
part
low
of the
number
original
(Ex:
12345678
pass
to
be 
567812349)
c)
Yes
the
pattern
appears
a
number
ODD
of
times,
exchange
the
0s
and 
1s (Ex: 101101 becomes 010010) 
2)
Perform
one
function
that
receive
a
char
*list[]
(last
element
in 
NULL)
and
it
returns
with
the
chains
ordered
alphabetically.
(it is
can 
use string.h).
3)
Perform
one
function
that
receive
a
pointer
to
one
list
with
structures
type 
products,
where
the
code
is
a
number
of
1
to
10.
The
function
has
that 
check
yes
there is
codes
that
if
they repeat,
and
in
the
case
of
find yourself
with
this 
you have to:
a)
Increase
the
number
of
products
in
the
first
node
of
the
list
that 
contain that code. 
b)
Delete from the list all nodes that contain a repeated code.
typedef struct node {
char name[10];
int qty;
char code;
struct node *sig;
}products;
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
Approval condition 60%.