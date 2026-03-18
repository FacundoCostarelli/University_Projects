1)Que es un sistema operativo?? Que tiene a su cargo??
2)Cual es la diferencia entre un header y una biblioteca?? Que contiene cada uno??
3)ver en el pdf
4)ver en el pdf

1) Un sistema operativo es una coleccion o grupo de programas donde todos estos se encargan de "administrar" los recursos de la computadora (recursos como: interfaz grafica,teclado, monitor, memoria, procesador, etc) Esto permite proveer a los diferentes usuarios logueados en el sistema, la posibilidad de usar todos los recursos de hardware y software de la computadora con la particularidad de NO tener que conocer detalladamente como son y como funcionan. Esto permite ademas, el uso seguro para el usuario y para el resto de usuarios.

2)"Una biblioteca o libreria de programas", es un archivo que contiene codigo, datos compilados y funcionales, donde estos programas del archivo seran incorporados a otros programas cuando se los necesite. Las librerias de codigos nos facilitan la reutilizacion de codigo para poder evitar tener que re-escribirlos cada ves que resolvemos una problematica o realizamos un proyecto, es decir, cuando los necesitamos nuevamente. Tambien nos permite mejorar el trabajo en equipo. Mas detalladamente, las librerias poseen: "a)Prototipos de las funciones los cuales son almacenados en archivo/s cabecera/s .h"
"b)Definicion de las funciones los cuales son almacenados en archivo/s fuentes.c  ... en caso de programar en Lenguage C
En adicion, existen al menos 3 tipos de librerias y estas son: 
- Estatica
- Compartida (shared)
- De carga dinamica( DL, por Dynamic Loaded)

Los archivos "header", es decir, los terminados en ".h" . Son archivos que poseen Prototipos de funciones, macros y variables globales. Estos seran utilizados junto a otros archivos header y demas, en un programa central fuente .c o se almacenaran en alguna libreria. En estos headers, no se encuentra la definicion o desarrollo de funciones, estas estaran en otros codigos fuentre .c por separado donde todo luego se compilara 
y se colocara en el archivo centrla fuente o en librerias adecuadamente.

3)La opcion correcta es: sizeof(int *) = sizeof(float *). EL tamanio de los punteros depende exclusivamente de la arquitectura del procesador, si es de 32 bits entonces los punteros tienen todos tamnio de 4bytes, si la arquitectura es de 64 bits, entonces los punteros tienen todos tamanio de 8bytes. 
4)
Voy a explicar instruccion por instruccion del siguiente codigo de enunciado y explicar que hace:

int main(void)
{
    int vec[4] = { 2, 1, 4, 3 }; //Creacion de un vector de datos "int" de tamanio de "4" elementos donde ademas se elijen y cargan en el array, los elementos escritos predeterminadamente entre llaves
    int *p;//declaracion de un puntero simple que apunta a algun lugar no inicializado
    p = vec;//el puntero "p" ahora se le asigna a almacenar, la direccion de cominezo del vector, es decir, la direccion del 1er elemento del vector. Ya que el nombre de un vector, es otro puntero que apunta al 1er elemento de dicho array
    printf("%d", *p);//se printea en pantalla de la consola shell el contenido de lo apuntado por "p", es decir, se printea el nro 2
    p = (int *)(p+2);//el puntero "p" ahora se le asigna la direccion de otro puntero que es "(int*)(p+2)", esta sera una direccion que apunta a un dato int y en particular dicho dato es el nro "4"
    printf("%d", *p);//se printea en pantalla de la consola shell el contenido de lo apuntado por "p", es decir, se printea el nro 4
    p = (int *)(p+2);//si bien estas 2 proximas instruciones se escriben igual que las 2 anteriores, aca sucede que el puntero "p" se le asigna la direccion que almacena otro puntero que es "(int*)(p+2)", esta sera una direccion que apunta a un dato int pero ahora....en particular....apunta a un dato que esta fuera del array, es decir, un dato de valor conocido como "basura"
    printf("%d", *p);))//se printea en pantalla de la consola shell el contenido de lo apuntado por "p", es decir, se printea el valor int "basura" aleatorio
    
    return 0;//se retorna un 0 a la consola shell para darlo al SO e indicar una finalizacion exitosa de la ejecucion del programa
}

//En particular en todos los printeos de pantalla, no hay saltos de nueva linea, entonces se printean todos los valores int mencionados de forma contigua uno despues del otro
