# Original Text - 2ndCuatrimestreTheoryGeneral.pdf

2do Cuatrimestre 
➔ Parcial. 
➔ Formalicemos Funciones. 
➔ Formalicemos Tipos de Datos. 
➔ Formalicemos Sistemas de Numeración. 
1
Funciones 
➔ Metodología top-down 
◆ Dividir el problema en partes más chicas fáciles de resolver. 
➔ Construir a partir de lo ya hecho. 
➔ Independencia de códigos y datos. 
➔ Formar parte de distintos archivos fuentes y compilarse juntos. 
➔ Le damos “argumentos” y nos devuelve un “único” resultado, el resto es 
transparente a nuestro código. 
2
Deﬁnición Vs. Declaración. 
➔ Deﬁnición : es la función en sí, contendrá el código que ejecuta dicha 
función. Una sola vez. 
➔ Declaración : Le  informa al compilador el formato de la función. Cuando 
sea necesario 
◆ Obligatorio: cuando se llama a la función antes de deﬁnirla. 
◆ Obligatorio: cuando se llama a la función en un archivo distinto al de 
la deﬁnición. 
◆ Optativo: cuando la función es deﬁnida antes de su primer llamado. 
3
Deﬁnición 
●Tres componentes principales: 
a.Primera línea. 
b.Declaración de argumentos. 
c.Cuerpo 
No son todas obligatorias. 
4
Deﬁnición: primera línea 
➔ Contiene: 
a.Tipo del valor de retorno. 
b.Nombre de la función. 
c.Argumentos que recibe. 
tipo nombre (arg1, arg2,........., argn) 
➔ Los argumentos son pasados por valor (vía pila). Estos no son 
reconocidos fuera de la función. 
5
Deﬁnición: declaración de argumentos 
➔ Cada tipo de argumento que recibe debe coincidir con el tipo de dato que 
se le envía desde la llamada a la función 
➔ Puede ser omitido si se declaran los tipos junto con los argumentos en la 
primera línea 
a.tipo nombre(arg1, arg2,..........) 
tipo arg1 
tipo arg2 
b.tipo nombre(tipo arg1, tipo arg2,.........) 
6
Deﬁnición: cuerpo 
➔ Sentencia compuesta que deﬁne las acciones que debe realizar la función. 
➔ Está encerrada entre llaves { }. 
➔ Se utiliza la sentencia return para especiﬁcar el valor devuelto por la 
función. 
7
Declaración 
➔ La idea es darle al compilador la información del formato de la función. 
➔ Es necesario declarar una función cuando: 
◆ Se la llama antes de su deﬁnición 
◆ Se la llama desde códigos escritos en distintos archivos. 
➔ El formato de una declaración es: 
tipo-almacenamiento tipo-devuelto nombre (tipos-argumentos) 
8
TIPOS DE DATOS 
➔ Carácter: char 
➔ Enteros: int 
➔ Punto ﬂotante simple densidad: ﬂoat 
◆ 
➔ Punto ﬂotante doble densidad: double 
◆ 
9Signo (1) Exponente (8) Mantisa (23) 
Signo (1) Exponente (11) Mantisa (52) 
Punto Flotante: IEEE 754 
10

CALIFICADORES 
➔short 
➔long 
➔signed 
➔unsigned 
11
CONSTANTES 
➔ #deﬁne 
◆ #deﬁne ENTERO 1234 
◆ #deﬁne N_LONG  1234L 
◆ #deﬁne N_UNSIGNED 1234U 
◆ #deﬁne CARACTER  'A' 
◆ #deﬁne NVLIN  '\n' 
◆ #deﬁne N_HEXA 0x1234 
◆ #deﬁne N_OCTAL  01234 
◆ #deﬁne CADENA  “HOLA MUNDO\n” 
12
caracteres especiales 
13

CONSTANTES 
➔ enum 
◆ enum boolean {NO, SI };  / / NO=0 , SI =1. 
◆ enum meses {Enero =1 , Febrero , Marzo , A b r i l , Mayo , Junio , J u l i 
o , Agosto , Setiembre , Octubre , Noviembre , Diciembre };  / / Febrero 
=2 , Marzo= 3 , . . . 
◆ enum escapes {BELL = '\a' , TAB = '\t' , NVLIN = '\n'}; 
Crean un “tipo” de dato constante enum boolean, enum meses y enum escapes 
respectivamente. 
14
VARIABLES 
➔ Deﬁnición : es donde se le asigna un lugar en memoria. 
◆ ﬂoat a; 
◆ int b, c; //fuera de la función => externa 
◆ char texto[100]; 
➔ Declaración : Informa al compilador la naturaleza de la variable, no asigna 
memoria; no siempre necesario. 
◆ ﬂoat a; 
◆ extern int b, c; //múltiples archivos 
◆ char texto[ ]; 
15
VARIABLES 
➔ Inicialización : es darles un valor inicial en la deﬁnición, no es obligatorio. 
◆ ﬂoat a=3.14; 
◆ char texto[11]= “hola mundo”; //10+carácter nulo 
◆ char texto[]=”hola mundo” 
NOTA: son deﬁniciones, no declaraciones. 
16
Tipos de almacenamiento de variables 
➔ Tipos de datos 
◆ Char, int, ﬂoat y double. 
◆ Short, long, signed, unsigned 
➔ Tipos de almacenamiento 
◆ Según alcance 
● Automáticas (o locales) 
● Externas (o globales) 
◆ Según duración 
● Estáticas 
● Dinámicas 
◆ Según velocidad de acceso 
● Por registro 
● En memoria 
17
Almacenamiento automático (auto) 
➔ Se declaran dentro de la función y son locales a la misma. 
◆ Solo se pueden acceder desde la función 
◆ No es necesario usar la palabra auto  para deﬁnirlas 
18
Almacenamiento externo (extern) 
➔ Su ámbito se extiende desde el punto de deﬁnición hasta el resto del 
programa. 
◆ Mantienen su valor al entrar y salir de las funciones 
◆ Se deﬁne fuera de la función donde puede inicializarse también 
◆ Solo debe existir una deﬁnición de cada variable externa 
◆ Se deﬁnen como externas por su lugar fuera de las funciones por lo 
que no se usa extern para deﬁnirlas. 
◆ Se la declara usando extern. 
◆ No abusar 
19
Almacenamiento estático (static) 
➔ Aplicable tanto al almacenamiento local como global 
◆ Estática automática: Solo existen en el ámbito de la función pero 
mantienen su último valor. 
◆ Estáticas externas: Sólo serán reconocidas en el archivo donde se las 
deﬁnió. 
20
Almacenamiento en registros (register) 
➔ Le dice al compilador que en lo posible utilice un registro interno del 
procesador en lugar de la memoria para almacenar su valor. 
◆ Incrementa la velocidad de acceso 
◆ Usado cuando la variable tiene un alto grado de aparición en el 
código. 
◆ Solo para variables automáticas y parámetros formales de una 
función. 
21
Resumen 
● Las variables globales y funciones pueden ser deﬁnidas como estáticas 
● Pueden declararse variables o funciones externas al archivo de deﬁnición con “extern”. (1) 
● Las deﬁniciones o declaraciones locales pueden ser automáticas, estáticas, externas o 
registro. 
22

Aclaración 
➔ También existe la posibilidad de deﬁnir los tipo: 
◆ const : deﬁne una constante en memoria (puede optimizar su acceso 
estando en memoria de programa). 
◆ volatile : deﬁne una variable que puede ser modiﬁcada fuera del 
programa para obligar a la lectura de la memoria siempre que se la 
utilice. 
23
Representación BINARIA 
➔ Esta correspondencia entre señal DIGITAL y numeración BINARIA hacen a 
esta última una herramienta ideal para representar y analizar el 
comportamiento de las primeras. 
➔ La máquina usa niveles de tensión y el hombre los representa con 
números binarios. 
24
Sistema DECIMAL 
➔ El sistema decimal utiliza una BASE=10 
◆ Necesito 10 símbolos (0 1 2 3 4 5 6 7 8 9). 
◆ El valor del número viene dado por la suma de cada dígito 
multiplicado por su “peso”. 
Por ejemplo: 
25

Sistema BINARIO 
➔ El sistema binario utiliza una BASE=2 
◆ Necesito 2 símbolos (0 1). 
◆ El valor del número viene dado por la suma de cada dígito 
multiplicado por su “peso”. 
Por ejemplo: 
26

Sistema OCTAL 
➔ El sistema octal utiliza un BASE=8 
◆ Necesito 8 símbolos (0 1 2 3 4 5 6 7). 
◆ El valor del número viene dado por la suma de cada dígito 
multiplicado por su “peso”. 
Por ejemplo: 
27

Sistema HEXADECIMAL 
➔ El sistema hexadecimal utiliza un BASE=16 
◆ Necesito 8 símbolos (0 1 2 3 4 5 6 7 8 9 A B C D E F). 
◆ El valor del número viene dado por la suma de cada dígito 
multiplicado por su “peso”. 
Por ejemplo: 
28

Que quede claro 
➔ Un número lo podemos representar en cualquier base. 
➔ Al representarlo en distintas bases cambia su expresión simbólica pero no 
su magnitud. 
A5h=165d=245o=10100101b 
29
Métodos para CAMBIO de BASE 
Divisiones Sucesivas 
Se divide el número a convertir por la base a convertir, hasta que el cociente de 
un número menor que dicha base. El resultado se compone del último cociente 
y los restos tomados en sentido inverso a la sucesión de cocientes. 
30

Métodos para CAMBIO de BASE 
Divisiones Sucesivas 
Se divide el número a convertir por la base a convertir, hasta que el cociente de 
un número menor que dicha base. El resultado se compone del último cociente 
y los restos tomados en sentido inverso a la sucesión de cocientes. 
En el caso de los decimales se multiplica por la base y la parte entera es el 
dígito buscado. 
0,375x2= 0,75 => 0, 0
0,75x2= 1,5 => 0,0 1
0,5x2= 1 => 0,01 1
2,375d=10,011b 
31
Métodos para CAMBIO de BASE 
Restas sucesivas 
Consiste en tomar el número a convertir y buscar la potencia de 2 más grande 
que se le pueda restar, tomando el resultado de la resta como nuevo número 
para seguir el proceso, siempre que este no sea negativo. 
32

Conversiones Rápidas 
➔ Binario a Octal. 
➔ Binario a Hexadecimal. 
1100101110b=1456o=32Eh 
33

TABLA 
34

Representación Binaria en la PC 
➔ Las PCs, como otros dispositivos digitales, solo trabajan con dos niveles 
(0 y 1) 
➔ Problemas: 
◆ ¿Cómo representar números negativos? 
◆ ¿Cómo representar números con coma? 
◆ Estamos limitados en el ancho de los números que podemos manejar 
dentro de la PC. 
35
Sistema Binario: UNIDADES 
➔Bit [b]: acrónimo de Binary digit, (0 o 1). 
➔Nibble: Conjunto de 4 bits. 
➔Byte [B]: Conjunto de 8 bits. 
➔Word [w]: Conjunto de 16 bits. 
➔DoubleWord: Conjunto de 32 bits. 
➔QuadWord: Conjunto de 64 bits. 
36
Suma BINARIA 
➔ Mientras que la suma no supere el tamaño máximo soportado, la suma se 
efectúa sin problema. 
➔ Pero si supero el máximo número de dígitos que manejo tendré 
problemas. 
◆ Esto se llama CARRY  (ﬂag c) 
37

Operaciones Básicas 
Sumar y restar dentro del conjunto de los ENTEROS nos trae un nuevo 
problema a la hora de hacerlo en una PC: 
➔ ¿Cómo representar números negativos? 
➔ Analizaremos distintos métodos: 
➔ Signo y Magnitud. 
➔ Complemento a 1. 
➔ Complemento a 2. 
➔ Binario Desplazado. 
38
Signo y Magnitud 
➔ Como ya mencionamos, dentro de la PC solo podemos representar 0s y 
1s.
➔ Signo y Magnitud utiliza el bit más signiﬁcativo (MSB) para representar el 
signo y el resto para el módulo. 
➔ Así, trabajando con 4 bits tenemos que: 
0010b equivale a 2. 
1010b equivale a -2. 
39
Signo y Magnitud 
Este método tiene algunos inconveniente: 
➔  Se consumen 2 valores para representar al cero. 
0000b=1000b (0=-0) 
➔  No se puede usar el mismo HARDWARE que suma números positivos 
para sumar números negativos. 
0010b+1001b=1011b (-3) 
2+(-1)=1 
40
Complemento a 1 (C1) 
➔ Para representar un número negativo se invierte cada bit por su 
complemento (1 en 0 y viceversa). 
0111b=7d y 1000b=-0111b=-7d 
➔ Continuamos teniendo el problema de ocupar dos números para 
representar al 0. 
0000b=0d y 1111b=-0000b=-0d 
➔ Al sumar dos números de distinto signo hay que sumar el acarreo del MSB 
para no tener errores. 
➔ Esto signiﬁca que si bien podremos usar el mismo hardware este tendrá 
que analizar de qué caso se trata. 
41
OPERACIÓN SUMA 
➔ Si ocurre un carry al ﬁnal de la adición/resta, sumarlo al resultado obtenido 
(end-around carry) 
◆ 0010b+0100b=0110b (2+4=6) 
◆ 0010b+1110b=10000b+1=1 (2+(-1)=1) 
◆ 0010b+1100b=1110b=-1 (2+(-3)=-1) 
◆ 1101b+1011b=11000b+1=-6 (-2+(-4)=-6) 
◆ 0110b+0110b=1100b=-3 (6+6=12 => fuera de escala) 
◆ 1001b+1001b=10010b+1=3 (-6-6=-12 => fuera de escala) 
¡¡¡ Cuidado con salirse de escala !!! 
42
NOTA 
Los protocolos de Internet IPv4, ICMP , UDP y TCP usan todos el mismo 
algoritmo de suma de veriﬁcación de 16 bits en complemento a uno. 
Aunque la mayoría de la computadoras carecen del hardware para manejar 
acarreo del último bit (end-around carry), la complejidad adicional es 
aceptada ya que es igualmente sensible a errores en todas las posiciones 
de bits. En UDP , una representación de todos ceros indica que la suma de 
veriﬁcación opcional ha sido omitida. La otra representación, todos unos, 
indica un valor 0 en la suma de veriﬁcación (las sumas de veriﬁcación son 
obligatorias para IPv4, TCP e ICMP; fueron omitidas en IPv6). 
43
Complemento a 2 (C2) 
➔ Para representar un número negativo se invierte cada bit por su 
complemento y se le suma 1 (C2=C1+1). 
0111b=7d 
0000b=0d 
1111b = -0000b+1= -1d 
1000b = -0111b+1= -8d 
➔ Se elimina la ambigüedad del cero. 
➔ No requiere ajuste al sumar 2 números de distinto signo. 
➔ Podremos usar el mismo hardware. 
44
OPERACIÓN SUMA 
➔ Si ocurre un carry al ﬁnal de la adición/resta, sumarlo al resultado obtenido 
(end-around carry) 
◆ 0010b+0100b=0110b (2+4=6) 
◆ 0010b+1111b=10001b=1 (2+(-1)=1) 
◆ 0010b+1101b=1111b=-1 (2+(-3)=-1) 
◆ 1110b+1100b=11010b=-6 (-2+(-4)=-6) 
◆ 0110b+0110b=1100b=-4 (6+6=12 => fuera de escala) 
◆ 1010b+1010b=10100b=4 (-6-6=-12 => fuera de escala) 
¡¡¡ Cuidado con salirse de escala !!! 
45
Binario Desplazado 
➔ Se suma al valor signado el valor absoluto de la mitad del rango menos 1. 
➔ El formato en exceso es habitual para la representación del exponente en 
números en punto ﬂotante 
➔ Ejemplos en 3bits: 
46

➔ 
47

FLAGs aritmeticos 
➔ Z = Zero ﬂag: El resultado es cero. 
➔ N = Negative ﬂag: El resultado es negativo. 
➔ V = Overﬂow ﬂag: El resultado supera el número de bits que puede manejar 
la ALU. 
➔ P = Parity ﬂag: Paridad del número de 1 en los datos. 
➔ C = Carry ﬂag: Acarreo de la operación realizada. 
48
Representar REALES 
➔ Por ahora solo vimos como representar un pequeño subconjunto de los 
enteros. 
➔ La codiﬁcación en PUNTO FLOTANTE permite trabajar (en un mismo tipo 
de dato) con magnitudes muy grandes y muy pequeñas. 
➔ Pero el precio a pagar: a mayor rango menor será la precisión y viceversa. 
49
RANGO y PRECISIÓN 
➔ Se divide el número de bits en tres: 
◆ Signo 
◆ Mantisa (determina el número de dígitos que podemos representar: precisión) 
◆ Exponente (determina el rango de números que podemos representar) 
➔ Tener el número de dígitos ﬁjos me limita los números que puedo 
representar. 
➔ Por ejemplo, con 4 dígitos decimales tendremos: 
◆ Rango: 
● 0000 a 9999 
● 0.000 a 9.999 
◆ Precisión: 
● Del 1000 paso al 1001 (no puedo representar el 1000.1) 
● Del 1.001 paso al 1.002 (no puedo representar el 1.0015) 
➔ 50
Representación Binaria de Números Reales 
➔ En general tenemos dos formatos: 
◆ Punto Fijo. 
◆ Punto Flotante. 
51
Punto Fijo con Signo 
➔ Se representan mediante una expresion del tipo: 
(an an−1 . . . a0 .a−1 a−2 . . . a−m )b = (−1)s ∗ (an ∗ 2n + · · · +a0 ∗ 20 + a−1 ∗ 2−1 + a−2 ∗ 2−2 + · · · + a−m ∗ 2−m )
◆ s es el signo: 0 positivo y 1 negativo. 
◆ La distancia entre dos números consecutivos es 2-m. 
◆ Ejemplo: -101.011b=(-1)¹[1x2²+0x2¹+1x2 ⁰+0x2 ⁻¹+1x2 ⁻²+1x2 ⁻³] 
Deja de ser un rango continuo de números para transformarse en un rango 
discreto. Por ejemplo, incrementos de 0.001b=0.125d 
52
Punto Flotante: Notación Cientíﬁca 
Sistema Decimal 
➔ Permite representar números reales. 
➔ Su formato es: 
a: coeﬁciente 
b: exponente 
➔ Ejemplo: 
➔ Para uniﬁcar la representación se utiliza la Notación Cientíﬁca 
Normalizada: 
53

Punto Flotante: Representación 
➔ Se representan con los pares ordenados (m,e): 
m: mantisa; representa a un número fraccionario. 
b: base; toma el valor del sistema de numeración. 
e: exponente; un número entero. 
54

Punto Flotante: Formato IEEE 754 
➔ IEEE: Institute of Electrical and Electronic Engineers 
◆ Asociación técnico-profesional mundial dedicada a la estandarización. 
➔ IEEE 754 
◆ Estándar para aritmética en coma ﬂotante. 
◆ Ampliamente utilizado. 
◆ Deﬁne representación, operaciones y valores especiales. 
◆ Formatos: 
● 16bits (Half precision) 
● 32bits (Single precision) 
● 64bits (Double precision) 
● 80bits (Double Extended Precision) 
● 128bits (Quadruple precision) 
➔ 
55
Punto Flotante: FORMATOS 
56

Punto Flotante: RANGOS 
57

Representación de caracteres 
➔ No solo necesitaremos representar números. 
➔ Para representar letras y símbolos se utilizan distintos tipos de 
codiﬁcaciones. 
➔ Su representación será, sin duda, binaria; pero tendrá que estar codiﬁcada 
por algún estándar. 
◆ ASCII 
◆ ISO 8859-1 
◆ Unicode 
◆ UTF
58
ASCII 
➔ American Standard Code for Information Interchange. 
➔ Creado en 1963 por el Comité Estadounidense de estándares ASA (ANSI 
desde 1969) 
➔ Deﬁne 95 caracteres imprimibles, numerados del 32 al 126 (del 0 al 31 y el 
127 son caracteres no imprimibles). 
➔ Basado en el alfabeto LATINO. 
➔ Utiliza 7 bits para representar los caracteres (1111111b=127). 
➔ ASCII extendido: utiliza los 8bits 
59
Tabla ASCII ESTANDAR 
60

Tabla ASCII EXTENDIDA 
➔ 
61

