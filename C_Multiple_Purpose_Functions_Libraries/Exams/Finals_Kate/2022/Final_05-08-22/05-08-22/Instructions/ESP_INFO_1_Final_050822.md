# Original Text - INFO_1_Final_050822.pdf

  Informática I  
05 de Agosto de 2022  
Final  
Apellido y Nombres  Legajo # de Hojas  Profesor  
    
 
Página 1 de 4 
Normas Generales  
Lea detenidamente cada pregunta y consulte las dudas de que pudieran surgir.  La correcta interpretación del 
enunciado forma parte de la evaluación. 
En caso de realizar el examen en papel, numere las hojas entregadas. Complete en la primera hoja la cantidad total de 
hojas entregadas. Debe identificarse cada hoja con: Nombre, Apellido, Legajo.  
Por favor entregar esta hoja junto al resto de las hojas realizadas.  
 
Sección teórica (Tiempo 15 minutos)  
1) Defina brevemente que es una librería y como se relaciona con los archivos de cabecera. 
 
2)  
a) Justifique las diferencias de las siguientes declaraciones e inicializaciones: 
 
char *str = "Hola Mundo"; 
char str[100] = "Hola Mundo"; 
 
b) ¿Es correcto? Justifique. 
 
#include <string.h> 
 
int main(void) 
{ 
    char *str = "Hola Mundo"; 
    strcpy(str, "Hola"); 
    return 0; 
} 
 
c) Dado los siguientes arrays, completar la tabla adjunta: 
 
int x[5] 1 2 10 11 12 
 20     
     
int y[5] 0 22 1 15 8 
 40     
     
int z[5] 3 6 -1 14 198 
 60      
 
 
 
 
  Informática I  
05 de Agosto de 2022  
Final  
Apellido y Nombres  Legajo # de Hojas  Profesor  
    
 
Página 2 de 4 
Sabiendo que el array x inicia en la posición de memoria 20, el y en la 40 y z en la 60. 
 
 
Referencia dirección Valor 
y[3]     
y[6]     
y[-2]     
x[12]     
 
 
Sección Practica (Tiempo 90 minutos)  
Usted trabaja en el departamento de criptografía de la UTN-FRBA. Debido a un ataque, se le 
solicita volver a generar los algoritmos de encriptación de “texto” utilizando las siguientes 
funciones que deberá desarrollar: 
 
1) Función para encriptar caracteres A-Z 
 
int encriptar_leras ( const char *src , char * dst); 
 
El algoritmo de encriptación se basa en "desplazar" cada una de las letras del string de origen (src) 
recibido como primer argumento de la función, un valor entero. 
Este valor entero, el valor del "desplazamiento alfabético" lo deberá definir la propia función 
(encriptar_letras) de manera aleatoria por cada llamada a la misma. 
Este desplazamiento aleatorio podrá tomar valores entre 1 y 25. 
En el caso que el nuevo valor "encriptado"(desplazado) sobrepase la 'Z', se deberá continuar con la 
'A'. 
Los números y espacios deben permanecer invariables (no se modifican) 
La función debe retornar la cantidad de posiciones que se han desplazado los caracteres.  
Asuma que en dst se recibió un puntero a un string de tamaño suficiente para almacenar el texto 
encriptado. 
Asuma que el string de entrada se encuentra completamente en mayúsculas. 
 
Ejemplo:  
“HOLA 54”. Si el numero aleatorio fue 3, debería quedar “KROD 54”. 
 
Para generar números aleatorios puede utilizar las funciones srand y random: 
#include <stdio.h> 
 
void srand (unsigned int seed ); 
int rand (void); 
 
  Informática I  
05 de Agosto de 2022  
Final  
Apellido y Nombres  Legajo # de Hojas  Profesor  
    
 
Página 3 de 4 
/* 
Recuerde que la función rand devuelve números de una secuencia pseudo aleatoria entre 0 y 
RAND_MAX, y que debe llamar a srand adecuadamente al principio del programa para cambiar 
dicha secuencia cada vez que se ejecuta el programa 
*/ 
 
2)  
void encriptar_numeros ( const char *src , char *dst); 
 
Para encriptar los números del string el procedimiento será el siguiente: se debe convertir el 
número en octal, para luego reemplazar cada uno de sus dígitos por los siguientes caracteres. 
Adicionalmente, se debe agregar el carácter # tanto al comienzo como al final del número 
encriptado.  
 
EJ: “305” (461 en octal) “#@+%#” 
 
0 $ 
1 % 
2 & 
3 * 
4 @ 
5 ! 
6 + 
7 = 
 
3) Con el objetivo de utilizar las funciones antes implementadas, desarrollar un programa que 
realice lo siguiente: 
 
a) Reciba los siguientes argumentos desde la línea de comandos: 
 primer argumento: nombre de un archivo (“path” a un archivo) 
 segundo argumento:    texto a encriptar 
Los dos argumentos son mandatorios, en caso de no recibir alguno de ellos, finalizar el programa e 
indicar lo sucedido con un mensaje de error. 
 
b) Encriptar el texto recibido desde la línea de comandos y almacenarlo en una estructura. 
 
struct st_texto_encriptado  
{ 
 char txt[TXT_MAX_LEN]; 
int desplazamiento; 
}; 
  Informática I  
05 de Agosto de 2022  
Final  
Apellido y Nombres  Legajo # de Hojas  Profesor  
    
 
Página 4 de 4 
 
Donde el campo “txt” es el texto encriptado y “desplazamiento” es justamente el generado 
automáticamente por la función “encriptar_letras”  
 
c) Finalmente guardar la estructura en el archivo recibido desde la línea de comando como 
primer argumento. Cada vez que se ejecute el programa, la estructura se deberá almacenar al 
final del archivo. 
 
 
Nota: en caso de no poder resolver alguna función o módulo, prototipe una función que le 
permita avanzar, describa su uso y asuma que es función de librería para poder continuar. 
