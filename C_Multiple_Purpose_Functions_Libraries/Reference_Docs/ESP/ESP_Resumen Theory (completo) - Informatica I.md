# Original Text - Resumen Theory (completo) - Informatica I.pdf

Que es un sistema operativo?:  Un sistema operativo es una colecci ón de programas 
que se encargan de administrar los recursos del computador, proveyendo a los 
diferentes usuarios que pueden estar logueados al sistema la posibilidad de utilizar los  
recursos de hardware y software del mismo sin necesidad de conocer detalles sobre 
ellos y de manera segura para s í y para el resto.
API (Aplication Programming Interface):  serie de servicios o funciones que el 
Sistema Operativo ofrece al programador  y a trav és de  éstas acceder a los recursos de 
hardware del sistema. La implementaci ón de las API dentro del Sistema Operativo se 
conocen como System Calls.
Kernel: El conjunto de programas que constituyen el Sistema Operativo propiamente
dicho y la implementaci ón de las System Calls se denomina kernel (n úcleo). (NOTA 
wiki: Es el principal responsable de facilitar a los distintos programas acceso seguro  al 
harware de la computadora  o en forma b ásica, es el encargado de gestionar recursos. 
Tambi én se encarga de decidir qu é programa podr á hacer uso de un dispositivo de 
hardware y durante cu ánto tiempo).
Shell: Es  una interfaz de usuario. El Shell es un int érprete de comandos que se 
encarga de traducir los pedidos del usuario e invocando las System Calls apropiadas 
los lleva adelante. Esta interfaz se la conoce como modo consola.  EXTRA:  Cada vez 
que tipeamos un comando el shell lo asume como un ejecutable binario o como un
script. Un ejecutable binario es el resultado de la edici ón y compilaci ón y linkeo
de un programa determinado. Un script es un archivo de texto que contiene comandos 
binarios u otros scripts para ejecutar, y que adem ás puede incluir sentencias de control  
de flujo.
Device Drivers (Manejadores de Dispositivos):  Para acceder al Hardware, el 
sistema operativo posee una interfaz de muy bajo nivel llamada  Device Drivers. Estos 
componentes de software, son parte del kernel y su misi ón es acceder al hardware de 
sistema en forma directa. Las aplicaciones NO PUEDEN efectuar este acceso en los 
sistemas operativos modernos ya que se trata de entornos
multiusuario en los que la estabilidad del sistema y de las aplicaciones que se ejecutan  
dentro de  él debe estar garantizada.

File system: Un file system es un conjunto de pol íticas definidas para la organizaci ón 
de la informaci ón en archivos dentro de un medio de almacenamiento, de modo de 
permitir definir su ubicaci ón dentro de ese medio y posibilitar el acceso a los datos 
contenidos por  éstos de manera simple. El  file system manager  es una pieza de 
software de un sistema operativo que implementa las pol íticas definidas para el file 
system. JEEMPLOS de file system: discos duros, los CD's, DVD's. El file system 
manager es el responsable de organizar los sectores y pistas de "los discos, cd's...." en 
archivos, directorios, enlaces, etc, y mantener actualizada la base de datos de los 
sectores que corresponden a cada archivo, directorio, enlace, etc.
Procesos: Un proceso es (intentando ensayar una definici ón simplificada) una 
instancia de ejecuci ón de un programa, EXTRA:  Los procesos son programas que se ejecutan  
en un momento dado . como ejemplo el comando ls.  Pueden existir en un momento varias 
personas ejecutando ls en forma simult ánea. Cada instancia de ejecuci ón de ls es un 
proceso diferente. (con el comando ps se ven los ProcesoS). Cada vez que ejecutamos un  
ls para ver un directorio el sistema crea un proceso.
Archivos ".h":Estos archivos, contienen definiciones de funciones, macros y variables.
El compilado: El proceso de compilaci ón involucra cuatro etapas sucesivas: 
preprocesamiento, compilaci ón, ensamblado y enlazado. Para pasar de un programa 
fuente escrito por un humano a un archivo ejecutable es necesario realizar estas 
cuatro etapas en forma sucesiva.
1.Pre procesamiento:     En esta etapa se interpretan las directivas al 
preprocesador. Entre otras cosas, las variables inicializadas con  #define son 
sustitu ídas en el c ódigo por su valor en todos los lugares donde aparece su 
nombre. El preprocesado puede pedirse haciendo:  gcc ­E circulo.c > circulo.pp  y 
examinarlo haciendo:  more circulo.pp
2.Compilaci ón:       La compilaci ón transforma el c ódigo C en el lenguaje 
ensamblador propio del procesador de nuestra m áquina.
gcc ­S circulo.c realiza las dos primeras etapas creando el archivo circulo.s; 
examin ándolo con more circulo.s puede verse el programa en lenguaje 
ensamblador.
3.Ensamblado:    El ensamblado transforma el programa escrito en lenguaje 
ensamblador a c ódigo objeto, un archivo binario en lenguaje de m áquina 
ejecutable por el procesador.  gcc ­c circulo.c gcc ­c ­o circulo.o circulo.c gcc ­c 
circulo.c ­o circulo.o Cualquiera de estas lineas de codicos crea el archivo en 
código objeto circulo.o a partir de circulo.c (Realiza primero los 2 pasos 
anteriores). Puede verificarse el tipo de archivo usando el comando  $ file 
circulo.o  NOTA: En los programas extensos, donde se escriben muchos archivos  
fuente en c ódigo C, es muy frecuente compilar cada archivo fuente por separado,  
y luego enlazar todos los m ódulos objeto creados. Estas operaciones se 
automatizan coloc ándolas en un archivo llamado makefile, interpretable por el 
comando make, quien se ocupa de realizar las actualizaciones m ínimas 
necesarias toda vez que se modifica alguna porci ón de c ódigo en cualquiera de 
los archivos fuente.
4.Enlazado (linker):     Las funciones de C/C++ inclu ídas en nuestro c ódigo, tal 
como printf() en el ejemplo, se encuentran ya compiladas y ensambladas en 
bibliotecas existentes en el sistema. Es preciso incorporar de alg ún modo el 
código binario de estas funciones a nuestro ejecutable (los combina o linkea). En  
esto consiste la etapa de enlace, donde se re únen uno o m ás módulos en c ódigo 
objeto con el c ódigo existente en las bibliotecas.  $ gcc ­o circulo circulo.o  crea el 
ejecutable circulo a partir del objeto.
Libreria: Una librer ía de programas no es otra cosa que un archivo que contiene 
código y datos compilados y funcionales, que ser án incorporados a otros programas
cuando estos los requieran. Las librer ías de c ódigo facilitan la reutilizaci ón de c ódigo 
evitando tener que re escribirlos cada vez que los necesitamos y a su vez permiten el 
trabajo en equipo. una librer ía se compone de:
• Prototipos de las funciones ( archivo/s cabecera/s .h)
• Definici ón de las funciones ( archivos/s fuente .c )
Tipos de libreria:
1.Estatica:    Son simples colecciones de programas objeto agrupados en un  único 
archivo cuyo nombre t ípicamente finaliza en '.a'. Al compilar un programa que 
hace uso de c ódigo contenido en una librer ía est ática, en el momento de realizar 
la fase de enlace (link), se copia en nuestro programa el c ódigo objeto de la 
librer ía, es decir que no es necesario distribuir nuestro programa con la librer ía 
ya que  ésta se encuentra incrustada de nuestro nuevo programa. Para generar 
una librer ía est ática utilizamos el utilitario ar. Antes de ello obviamente 
debemos haber generado el programa objeto, compilando con la opci ón ­c. EJ:    
$ gcc ­c holalib.c     Creamos objeto en ese paso..... $ ar rcs libhola.a holalib.o 
Creamos la libreria.  Las librer ías en general llevan en su nombre el prefijo 
“lib”. Por lo tanto el nombre a los efectos del linker es lo que sigue a “lib” y 
precede a “.a”.
2.Compartida (shared):     Estas librer ías no se linkean al programa que llama a 
funciones empaquetadas en ellas, sino que se resuelven las referencias en el 
momento de arranque del programa en cuesti ón. Si en el momento de la carga 
de nuestro programa, las librer ías necesarias no est án ya cargadas en memoria, 
el dynamic loader efectuar á la carga simult ánea a memoria del programa en s í 
que va a componer el proceso disparado por el usuario, junto con las librer ías 
que necesita.
3.De carga dinamica (DL, por Dynamic Loaded):     Estas librer ías se cargan en 
momentos diferentes de la carga y ejecuci ón delprograma. Su principal utilidad 
es la implementaci ón de m ódulos, o plug­ins, ya que estos elementos de software  
se cargan cuando se invocan durante la ejecuci ón de un programa. Desde el 
punto de vista de su formato no tienen diferencias en Linux con respecto a como 
se construyen librer ías compartidas o programas objeto. Sin embargo hay 
diferencias en el c ódigo que se necesita escribir en la aplicaci ón para trabajar 
con estas librer ías. Es decir que el programador de la aplicaci ón debe incluir 
funciones espec íficas que hasta ahora en los modelos analizados no  se requieren. 
Básicamente necesitamos invocar cuatro funciones:
•dlopen ():    Carga una librer ía y la prepara para su uso.
•Dlerror ():    Retorna un string que describe el error generado por las 
demás funciones de manejo de librer ías din ámicas.
•Dlsym ():    Busca el valor de un s ímbolo presente en una librer ía ya 
abierta con dlopen ().
•dlclose ():    Cierra la librer ía abierta con dlopen().
Desarrollo de un programa:
Make: make es una herramienta que permite ejecutar una secuencia de procesos. 
Utiliza un script, llamada com únmente makefile. Es capaz de determinar 
autom áticamente cuales pasos de una secuencia deben repetirse debido al cambio en 
algunos de los archivos involucrados en la construcci ón de un objeto, o en una 
operaci ón, y cuales no han registrado cambios desde la  última vez de modo que no es 
necesario repetirlos.
Logica del make (seg ún desarrollo de un programa):   Cada programa objeto 
depende de su correspondiente programa fuente, y headers si los hubiere. Un 
ejecutable depender á de los programas objeto involucrados en su proyecto, mas las 
librer ías de uso en el mismo.

Tenemos tres grupos claramente diferenciados por los colores de las flechas. A la hora 
de armar un makefile necesitamos tener claro el mapa de dependencias.
Una vez armado y en funcionamiento el makefile, si modificamos el archivo b.c, no
importa el motivo, make detectar á la actualizaci ón pero en lugar de repetir todas las 
compilaciones y linkeos, solo recompilar á al archivo b.c, lo cual modificar á el objeto b.o, 
y por lo tanto deber á relinkear la aplicaci ón para llegar a la versi ón de executable que 
contenga los cambios hechos en b.c. Lo interesante es que no toc ó el resto. Es decir lo 
que no cambia se deja tal como est á. Ejemplo Make anterior:
Lo que vemos al inicio de la l ínea como un nombre terminado con ':' se denomina regla.
Si no le especificamos nada y solo tipeamos make a secas, make asumir á que la regla a 
ejecutar es solo la de la primer l ínea con esta caracter ística. En nuestro primer 
ejemplo executable.
Si la regla a continuaci ón del car ácter ':' tiene dependencias,  éstas deber án 
corresponder dentro del makefile a otras reglas que se escriban a continuaci ón de la 
regla dependiente. En nuestro caso excecutable es dependiente de a.o y b.o.
Por lo tanto debe necesariamente existir una regla para a.o y otra para b.o escritas 
luego de la regla dependiente. Estas l íneas est án a continuaci ón con sus respectivas 
dependencias.
Finalmente hemos escrito una regla que permita limpiar todos los archivos generados 
a partir de los fuentes. Esto puede resultar  útil para hacer una recompilaci ón general. 
Se ejecuta haciendo: “$ make clean” Pasando por alto las demas reglas y ejecutando 

solo la regla clean. El formato general de cada regla es:
dependiente: dependencia
comando para generar el dependiente a partir de la dependencia.
Las l íneas que contienen comandos empiezan con un tabulador. De otro modo no 
funciona.
Variables en 
make: Se colocan 
al principio del 
codigo, igualando la  
constante varaible  
al comando a 
reemplazar, y se 
accede al valor 
poniendo $
(VARIABLE). 
Unidades 
basicas:  
•BIT[b]: Menor unidad de informaci ón, puede valer 0 o 1.
•BYTE[B]: Conjunto de 8 bits.

El modelo de Von Newmann:  Propone:
•Memoria: Los datos y programas se almacenan en una misma memoria de 
lectura­escritura.
◦Los contenidos de esta memoria se direccionan indicando su posici ón sin 
importar su tipo.
•Ejecuci ón:    Procesamiento secuencial de instrucciones (salvo que se indique lo 
contrario).
•Informaci ón:    Todo esto usando Datos binarios.
En la versi ón actual de las arquitecturas de las computadoras con programa 
almacenado cumplen m ínimamente con las siguientes caracter ísticas:
•Tres sistemas de harware  (interconectados por Buses):
◦Unidad de Procesamiento Central (CPU).
◦Un sistema de memoria principal.
◦Un sistema de entrada y salida (I/O).
•Capacidad para realizar el procesamiento secuencialmente.
•Un único camino (f ísico o l ógico) entre memoria y CPU  (cuello de botella de la 
arquitectura Von Newmann).
 Unidad de Procesamiento Central (CPU):  su misi ón consiste en coordinar y 
controlar o realizar todas Las operaciones del sistema. Sus partes principales son las 
siguientes:
•Unidad de control: implementa la maquina de estados.
•Unidad Aritm ético L ógica (ALU).
•La Memoria Central (MC) o  Registros (peque ña área de memoria y el contador 

de programa).
Sistema de memoria principal:   Almacena datos y programas.
Sistema de entrada y salida:   Comunicaci ón con el mundo exterior.
La unidad de procesamiento central el sistema de memoria principal y el sistema de 
entrada y salida est án conectados entre si por un sistema de interconexiones (buses).
Un t ípico ciclo completo seria:
1)La unidad de control recupera la “siguiente” instrucci ón de programa de la 
memoria principal (utilizando el contador de programa: IP)
2)La instrucci ón se decodifica.
3)Se toman de memoria los operandos a continuaci ón de la instrucci ón y se 
colocan en los registros.
4)La ALU realiza la operaci ón pedida y se coloca el resultado en los registros o en 
memoria.
VER IMAGEN A CONTINUACION.
 Un procesador es una maquina secuencial que esta en un ciclo infinito como el de la 
figura:
Sistema decimal:  
•Necesita 10 s ímbolos: (0 1 2 3 4 5 6 7 8 9).

• El valor del n úmero viene dado por la suma de cada d ígito multiplicado por su 
“peso”.
◦Por ejemplo: 123,4=1⋅102+2⋅101+3⋅100+4⋅10−1
Sistema binario:   
•Necesito 2 s ímbolos: (0 1).
•El valor del n úmero viene dado por la suma de cada d ígito multiplicado por su 
“peso”.
◦Por ejemplo: 101102=1⋅24+0⋅23+1⋅22+1⋅21+0⋅20=16+0+4+2+0=2210
Sistema octal:  
•Necesito 8 s ímbolos (0 1 2 3 4 5 6 7).
•El valor del n úmero viene dado por la suma de cada d ígito multiplicado por su 
“peso”.
◦Por ejemplo: 3778=3⋅82+7⋅81+7⋅80=192+56+7=255-->(255=4⋅82−1)
Sistema hexadecimal:   
•Necesito 8 s ímbolos (0 1 2 3 4 5 6 7 8 9 A B C D E F).
•El valor del n úmero viene dado por la suma de cada d ígito multiplicado por su 
“peso”.
◦Por ejemplo: ABC8=10⋅162+11⋅161+12⋅160=2560+176+12=274810
PASAJES:
4410=1001002:
Se divide el n úmero a convertir por la base a convertir, hasta que el cociente de un 
número menor que dicha base. El resultado se compone del  último cociente y los restos  
tomados en sentido inverso a la sucesi ón de cocientes.
En el caso de los decimales se multiplica por la base y la parte entera es el d ígito 
buscado.
0,375x2=0,75 => 0,0
0,75x2=1,5 => 0,01
0,5x2=1 => 0,011                  2,37510=10,0112
Binario a octal:  
Binario a hexa:  

Si supero el numero maximo de digitos que manejo al sumar tendre problemas, a esto 
se lo llama “carry”: 
•Carry    Flag (CF) (Bit 0)­ Acarreo. Indica con 1 un desborde no signado. Ej: bytes  
255 + 1 (el resultado no est á en el rango 0...255).
•Overflow    Flag (OF) (Bit 11)­ Desborde. Indica con 1 un desborde signado. Ej: 
bytes 100 + 50 (resultado no esta en rango de ­128...127).
Sumar y restar dentro del conjunto de los ENTEROS nos trae un nuevo problema a la
hora de hacerlo en una PC: ¿C ómo representar n úmeros negativos? Para esto 
analizamos 4 puntos:
•Signo y Magnitud

•Complemento a 1
•Complemento a 2
•Binario Desplazado
Signo y magnitud:   utiliza el bit mas significativo (MSB) para representar el signo y 
el resto para el modulo. As í, trabajando con 4 bits tenemos que:
•00102 equivale a 2.
•10102 equivale a ­2.
Inconvenientes de este metodo: 
•Se consumen 2 valores para representar al cero  0000b=1000b (0=­0)
•No se puede usar el mismo HARDWARE que suma n úmeros positivos para 
sumar n úmeros negativos. 2+(­1)=1       0010b+1001b=1011b (­3)
•Para realizar una suma primero determinar si los dos n úmeros tienen el mismo 
signo.
◦ Mismo signo:sumar parte significativa
◦ Distinto signo: restar el mayor del menor y asignar el signo del mayor.
Complemento a 1:  Para representar un n úmero negativo se invierte cada bit por su 
complemento (1 en 0 y viceversa).
01112=710Complemento a 1:  1000b = ­0111b = ­7d (Mismo problema con el “0”).
Si ocurre un carry al final de la adici ón/resta, sumarlo al resultado obtenido (end­
around carry) 
ej:
El resultado esta en complemento a uno, por lo que si la respuesta dio negativa se 
invierten los bits. Al sumar mismos signos, si me dio como respuesta un signo opuesto 
entocnes me fui de escala (los ultimos 2 casos).
Complemento a dos:  Para representar un n úmero negativo se invierte cada bit por su  
complemento y se le suma 1 (C2=C1+1).
0111b=7d
 0000b=0d
ahora al ser negativo se hace el complemento (teniendo en cuenta C2 = C1 + 1)
1111b=­0000b+1=­1d
1000b=­0111b+1=­8d
No requiere ajuste al sumar 2 n úmeros de distinto signo. (el carry no se suma, tener 

en cuenta nuevamente la suma de signos que de lo que correspponda como en caso 
anterior).
Binario desplazado:  Se suma al valor signado el valor absoluto de la mitad del rango  
menos 1. (El valor que quiero representar le sumo: la mitad del valor absoluto signado,  
este valor absoluto es 2 (por binario) elevado a la cantidad de bits a representar, y a 
este valor le resto 1). El resultado de la cuenta es el valor (que tengo que pasar a 
binario) que representa el numero en binario desplazado. Ej:
Punto flotante:  Representa cualquier numero real.

Ejemplos
•Ejemplo wikipedia:   
Codifiquemos el número decimal -118,625 usando el sistema de la IEEE 754.
Necesitamos obtener el signo, el exponente y la fracción.
Dado que es un número negativo, el bit de signo es "1".
Primero, escribimos el número (sin signo) usando notación binaria. Mira el sistema de numeración binario  
para ver cómo hacer esto. El resultado es 1110110,101.
Ahora, movamos la coma decimal a la izquierda, dejando sólo un 1 a su izquierda.
1110110,101=1,110110101·26 Esto es un número en coma flotante normalizado.
El significante es la parte a la derecha de la coma decimal, rellenada con ceros a la derecha hasta que 
obtengamos todos los 23 bits. Es decir 11011010100000000000000.
El exponente es 6, pero necesitamos convertirlo a binario y desplazarlo (de forma que el exponente más 
negativo es 0, y todos los exponentes son solamente números binarios no negativos). Para el formato IEEE 

754 de 32 bits, el desplazamiento es 127, así es que 6 + 127 = 133. En binario, esto se escribe como 
10000101.
Poniendo todo junto:
  1     8               23             <-- tamaño en bits
 +-+--------+-----------------------+
 |S|  Exp   |     Significante      |
 |1|10000101|11011010100000000000000|
 +-+--------+-----------------------+
 31 30    23 22                    0   <-- índice del bit (0 a la derecha)
    desplazado +127
•Ejemplo utenianos:   
Expresar en Base 10 los siguientes números dados en forma de Punto Flotante Precisión Simple.
Y te da el siguiente numero: 35C1F .
Coma flotante de Simple Precision, son 4 bytes.
Por lo que el numero en realidad es 35C1F000
35C1F000 convertido a binario:
00110101110000011111000000000000
Y ahora dividimos en: 1 bit de signo, 8 de exponente, 23 de mantisa
0|01101011|10000011111000000000000
Signo: 0 -> +1
Exponente: 01101011 -> 107 -> le restamos el exceso -> 107 - 127 = -20 -> como son potencias  
de 2 nos quedamos con -> 2^-20
Mantisa: 10000011111000000000000 -> 2^-1+2^-7+2^-8+2^-9+2^-10+2^-11 = 
0.515136719 -> Se le suma 1 -> 1.515136719
Multiplicamos todo:
+1 * 2^-20 * 1.515136719 = 1.44494697 E -6
Expresar en punto flotante simple precisión los números siguientes expresados en base 10.
Y nos da este numero: 165,625.
T enemos 165,625
Buscamos su signo: +1 -> 0
Transformamos el numero sin el signo a binario
165,625 -> 10100101,101
Exponente:
Desplazamos la coma hasta dejar solo un 1 a la izquierda
1,0100101101 -> 7 lugares -> Mantisa: 0100101101
Exponente: 7 -> Desplazado en 127 -> 127+7 = 134 -> En binario: 10000110
Armamos el numero
0|10000110|0100101101 -> completamos con ceros hasta los 4 bytes
01000011001001011010000000000000 -> En hexa: 4325A000 -> 4325A
#define NOMBRE valor
enum: tipo de dato o variable similar a #define. Esta se realiza por conteo.
enum boolean {NO, SI }; / / NO=0 , SI =1.
enum meses {Enero =1 , Febrero , Marzo , Abril , Mayo , Junio , Julio , Agosto , Setiembre , 
Octubre , Noviembre , Diciembre }; / / Febrero =2 , Marzo= 3 , . . .
enum escapes {BELL = '\a' , TAB = '\t' , NVLIN = '\n'};
if inline: a = (i<0) ? 0 : 100;
