#include<stdio.h>

int main(void)
{
    int vec[4] = { 2, 1, 4, 3 }; //Creacion de un vector de datos "int" de tamanio de "4" elementos donde ademas se elijen y cargan en el array, los elementos escritos predeterminadamente entre llaves
    int *p;//declaracion de un puntero simple que apunta a algun lugar no inicializado
    p = vec;//el puntero "p" ahora se le asigna a almacenar, la direccion de cominezo del vector, es decir, la direccion del 1er elemento del vector. Ya que el nombre de un vector, es otro puntero que apunta al 1er elemento de dicho array
    printf("%d\n", *p);//se printea en pantalla de la consola shell el contenido de lo apuntado por "p", es decir, se printea el nro 2
    p = (int *)(p+2);//el puntero "p" ahora se le asigna la direccion de otro puntero que es "(int*)(p+2)", esta sera una direccion que apunta a un dato int y en particular dicho dato es el nro "4"
    printf("%d\n", *p);//se printea en pantalla de la consola shell el contenido de lo apuntado por "p", es decir, se printea el nro 4
    p = (int *)(p+2);//si bien estas 2 proximas instruciones se escriben igual que las 2 anteriores, aca sucede que el puntero "p" se le asigna la direccion que almacena otro puntero que es "(int*)(p+2)", esta sera una direccion que apunta a un dato int pero ahora....en particular....apunta a un dato que esta fuera del array, es decir, un dato de valor conocido como "basura"
    printf("%d\n", *p);//se printea en pantalla de la consola shell el contenido de lo apuntado por "p", es decir, se printea el valor int "basura" aleatorio
    
    return 0;
}
