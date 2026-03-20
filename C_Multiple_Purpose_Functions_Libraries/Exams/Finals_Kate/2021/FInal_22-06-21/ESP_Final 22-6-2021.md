# Original Text - Final 22-6-2021.pdf

 
 
 
 
 
 
 
 
 
 
 
 
 
 
Teoría  
 
 1. Teniendo en cuenta que un Keep alive es un mecanismo de comunicación que informa a un 
proceso (P) el normal funcionamiento de un segundo proceso (H) y así, en el caso de que el 
proceso H se detenga por un tiempo mayor al esperado el proceso P lo mate para luego ejecutar 
nuevamente un poseso H y considerando que nuestro proceso P solo estará pendiente de esto se 
pide:  
 a) Proponer que mecanismos de comunicación utilizaría  
 b) Proponer una secuencia del mecanismo (puede apoyarse en un diagrama)  
 c) Que funciones de C est arían involucradas si o si en el proceso P.  
 2. Se pide:  
 a) Completar la siguiente cuenta de números positivos realizada en hexadecimal:   
 
 b) Si se trabaja con números signados usando complemento a 2, indicar que número decimal 
representa el 8A29h en:  
 Un sistema d e 16bits:  
 Un sistema de 32bits:  
 3. Diferencias y relación entre:  
 a) Archivo fuente, objeto, binario.  
 b) Programa, proceso  
 c) En socket: Proceso, puerto e IP  
 
 
 
 1. Se tiene un conjunto de funciones escritas en C con el siguiente prototipo:  
float NomFun(float x);  
Cada una de estas funciones toma el valor de x, le aplica una función matemática y retorna el 
valor de ordenada correspondiente.  
Se pide:  
 a) Realizar una función realice la composición de dos funciones matemáticas, para ello se le 
22-6-2021  
pasarán dos punteros a funciones (tipo NomFun) que según el orden corresponderá a la 
función compuesta pedida. Al ingresar a la función se pedirá se solicitarán los v alores de 
Xmin, Xmax y número de puntos a calcular. La función retorna un array de dos 
dimensiones donde en la primera columna están los valores de abscisa y en la segunda los 
de ordenadas correspondientes  según se obtengan de la función compuesta.  
 b) Definir el prototipo de la función pedida en el punto a. Luego realice una breve descripción 
de su uso (como hay que pasar los argumentos y como acceder a los datos que genera desde 
el código que la llama)  
 
 2. Escribir un código que recibe por argumentos del main el nombre de un archivo fuente escrito 
en lenguaje c, nuestro programa tiene generar una copia del archivo fuente ingresado pero sin 
los comentarios en sus líneas.  
