#include<stdio.h>



//Preguntas y Respuestas teoricas
1)
Según la siguientes declaraciones:
char cadena[10]="Info 1";//Es importante destacar que el array es de 10 elementos de tamanio aunque solo 6 de ellos estan ocupados por caracteres, el resto se rellena con null bytes osea \0
char *p=cadena;//Se carga la direccion de comienzo del 1er elemento del array en un puntero simple llamado *p
Indicar la salida de las siguientes líneas en una arquitectura de 64bits.

printf("%li\n",sizeof(cadena));//Esto printea un tamanio de 8bytes para la direccion de comienzo del 1er elemento del array cadena ya que el nombre de un array, esta asociado a un puntero que apunta a la direccion del 1er elemento del array.
printf("%li\n",strlen(cadena));//Si la libreria string.h esta incluida en el programa, entonces, printea la cantidad de elementos del array "cadena". En este caso 6, solo considera caracteres hasta el 1er \0  null byte que encuentre. Si la libreria no esta incluida, entonces hay error
printf("%li\n",sizeof(p));//Printea un tamanio de 8bytes ya que "p" tiene asignada la direccion de memoria del 1er elemento del array. Es decir lo mismo que en la linea 12
printf("%li\n",strlen(p));//Printea lo mismo que en la linea  13
printf("%li\n",sizeof(*p));//Printea el tamanio del contenido de lo apuntado por "p", como p es la direccion de memoria de comienzo del 1er elemento entonces, el contenido es el 1er caracter, el cual es "I". El tamanio de este contenido, es de 1 byte, ya que este contenido es un datol del tipo "char" y el tamanio siempre es de 1byte.

//Por otro lado, el tamanio de bytes ocupados por la memoria en cuanto a punteros, solo depende de la arquitectura de la computadora. Todos los tipos de punteros que apuntan a distintos tipos de datos, todos ellos pesan lo mismo en una arquitectura determinada. En 32 bits, el peso de todos los punteros es de bytes, en una de 64 bits, deberia ser de 8 bytes para todos ellos. 

2)
Diferencie una Unión de una Estructura. De un ejemplo de cada una,
indicando tamaño, declaración, definición, y formas de acceder a sus
miembros (con sus nombre y con un puntero a ellas)

Definicion teorica de estructura:

Una struct (estructura) es un tipo de dato de "definicion de usuario". Esto se encuentra dentro de C y podemos decir que nos permite agrupar distintas variables donde todas ellas son de distintos tipos de datos pero donde todas estan agrupadas bajo un solo nombre y en un solo bloque de memoria. Las estructuras se usan para representar "records", es decir, "grabaciones". Un "record" es un tipo de estructura de datos donde esta estructura de datos almacena un numero pre-fijado de elementos 
Para "definir" una estructura, se debe utilizar la palabra reservada "struct". Aqui struct nos define un nuevo tipo de dato. Este nuevo tipo de dato llamado struct tendra ahora uno o mas miembros/elementos dentro de el.

Tamanio de estructura: Cuando una variable es asociada al tipo de dato de struct, el compilador asigna memoria para cada miembro de la struct. El tamanio total de la estructura sera siempre igual o mayor a la suma total de los tamanios de cada uno de sus miembros
Memoria de estructura: Cada miembro dentro de la estructura se le es asignado un lugar unico de almacenamiento en la memoria
Alteracion de valores: La alteracion de un valor de un miembro de la estructura, no afecta al comportamiento y valores de los demas miembros
Acceso a los miembros: Cada miembro individual puede ser acedido de uno a la vez o mismo se puede acceder simultaneamente a varios miembros segun instruccion.
Inicializacion de miembrios: Varios miembros pueden ser inicializados a la vez. Esto a traves de realizar las operaciones adecuadas para cargar informacion alli. No se puede inicializar en el bloque de codigo de la declaracion de la estructura


Un ejemplo generico de declaracion puede ser el siguiente:
struct [nombre de la estructura]
   {
       declaracion del miembro;
       ...
       declaracion del miembro;
   };
   //Esta forma SI requiere declarar en el main una variable asociada al tipo de dato struct
   (O)

   struct [nombre de estructura]
   {
       declaracion del miembro;
       ...
       declaracion del miembro;
   }declaracion de variable asociada al tipo de dato "struct";
   //Esta forma NO requiere declarar en el main una variable asociada al tipo de dato struct
   
Un ejemplo particular junto a resto de codigo:
#include <stdio.h>
#include <stdio_ext.h>
/*
    Tambien se puede declarar una estructura fuera del main
    struct datos{
    char Nombre[20];
    int Legajo;
    }Persona;
    
*/
//Ejemplo aislado de estructura
typedef struct Datos{ //typedef hace que StructDatos sea un prototipo de la variable "struct Datos", se dice que a struct datos se le asocia otra etiqueta o identificacion mas comoda siendo esta StructDatos, o sea que por ser una etiqueta o identificador, no ocupa espacio en la memoria. Es por esto que hay que en el main hay que asociar esta nueva etiqueta a una variable ej de tipo puntero
    char Nombre[20];  
    char Apellido[20];
    int Legajo;
}StructDatos;


int main(void)
{
    //Ejemplo aislado de estructura
    struct datos{
    char Nombre[20];
    int Legajo;
    }Persona;//Aca "Persona" es la variable asociada a struc datos, entonces esta ocupa memoria y la uso directo sin hacer ninguna otra declaracion

StructDatos *Alumnos[30];//Cuando escrbis *Alumnos[30] te estas refieriendo a un array de punteros simples que apuntan a distintas StructDatos. Si escribieras solamentes Alumnos[30],                           estarias escrbiendo un vector de estructuras, por ejemplo un vector de 30 elementos donde cada elemento es una estructura.

//Cargo struc datos
printf("Ingrese Nombre: ");
scanf("%s",Persona.Nombre); 
__fpurge(stdin);
printf("Ingrese legajo: ");
scanf("%d",&Persona.Legajo);
__fpurge(stdin);

//Cargo las struc Datos de la sig forma.
for(i=0;i<n;i++)
{
       printf("Ingrese nombre: ");
       scanf("%s",(*Alumnos[i]).Nombre); 
       __fpurge(stdin);
       printf("Ingrese legajo: ");
       scanf("%d",&Alumnos[i]->Legajo);//el operador -> me reemplaza tener que escribir todo el rato (*variable).
       __fpurge(stdin);
}

printf("\tNombre: %s\n",Persona.Nombre);
printf("\tLegajo: %d\n",Persona.Legajo);

for(i=0;i<30;i++)
{
    printf("Datos:\n");
    printf("\tNombre: %s\n",Alumnos[i]->Nombre);
    printf("\tLegajo: %d\n",Alumnos[i]->Legajo);
}

return 0;
}

Podemos ver al menos 3 formas de acceder a los miembros de una estructura. Esta es
a) Persona.Nombre, genericamente es [variable asociada al tipo de dato struct].[miembro de la struct]
b) *Alumnos[i].Nombre, genericamente es [contenido de lo apuntado por un puntero simple, ubicado en un array de punteros simples, que apunta a una struct].[miembro de la struct]
c) Alumnos[i]->Nombre, genericamente [puntero simple, ubicado en un array de punteros, que apunta a una struct]->[miembro de la struct]
donde el operador -> nos reemplza el * y nos indica que apunta a Nombre, es decir que: "*Alumnos[i]." = "Alumnos[i]->"


*
*
*
Una union es un tipo de dato de "definicion de usuario". Esto se encuentra dentro de C y podemos decir que nos permite agrupar distintas variables donde todas ellas son de distintos tipos de datos pero donde todas estan agrupadas bajo un solo nombre y en un solo bloque de memoria. Esto se suele usar para el trabajo de estructuras de datos del tipo "record" ya que tiene un numero pre-fijado de miembros o elementos. Para definir una "union" se utiliza la palabra clave union. Esto nos permite tener un nuevo tipo de dato con uno o mas miembros dentro de el. Hasta aca tiene las mismas caracteristicas que un struct.
En cuanto a las cualidades distintas de una estructura, podemos mencionar que SOLO UN MIEMBRO puede contener un valor en cualquier momento dado durante el programa y su ejecucion. Las uniones proveen un uso eficiente del mismo bloque de memoria para multiples propositos.

Tamanio de la union: Cuando una variable es asociada a una union, el compilador asigna bloque de memoria
considerando el tamanio mas grande posible a ocupar, entonces, el tamanio de memoria usado por la union sera el tamanio que ocupa su miembro mas grande de todos.
Memoria de la union: La memoria asignada o "allocated" es compartida por todos los miembros individuales de la union.
Alteracion de valores: El alterar el valor que contiene uno de los miembros, alterara los valores asignados y que pueden tomar los demas miembros.
Accesos a los miembros: Solo uno de los miembros puede ser accedido en un instante dado, sera el 1ero de ellos, el resto no se puede acceder en ese momento
Inicializacion de miembros: Solo el 1er elemento puede ser inicializado. Esto a traves de realizar las operaciones adecuadas para cargar informacion alli. No se puede inicializar en el bloque de codigo de la declaracion de la estructura

Un ejemplo generico de declaracion puede ser el siguiente:
union [nombre de la union]
    {
       declaracion del miembro;
       ...
       declaracion del miembro;
    };
   //Esta forma SI requiere declarar en el main una variable asociada al tipo de dato struct
    (OR) 

union [nombre de la union]
    {
       declaracion del miembro;
       ...
       declaracion del miembro;
    }declaracion de variable asociada al tipo de dato "union";
//Esta forma NO requiere declarar en el main una variable asociada al tipo de dato struct
    
Un ejemplo particular de declaracion con codigo restante:

#include <stdio.h>
#include <string.h>
    
// declaracion de union. Esta se podria declarar incluso dentro del main
  
union union_example
{
    int integer;
    float decimal;
    char name[20];
};
    
int main()
{
    // creating variable for union
    // and initializing values
    union union_example u={18,38,"geeksforgeeks"};
    //Solo se va a printear 18, el resto de informacion tendra problemas ya que solo se puede inicializar el 1er elemento
    printf("\nunion data:\n integer: %d\n"
                "decimal: %.2f\n name: %s\n",
                u.integer, u.decimal, u.name);
    //Deberia mostrarse el tamanio de todo el vector ya que el el mimebro mas pesado en memoria
    printf("sizeof union : %d\n", sizeof(u));
    
    printf("\n Accessing all members modified at a time:");
    //La ultima modificacion es la que se mostrara correctamente. El alterar integer, provoca que se altere ls valores que toman el resto de las variables. Al modificar de una en una, entonces se va alterando todo. En este caso, la ultima modificacion sera tenida en cuenta, ya que esta modifica al resto pero permitiendose a si misma printearse en pantalla sin problemas, el resto mostrara informacion erronea, producto de modificar el ultimo miembro y querer acceder a cada miembro simultaneamente en el printf.
    u.integer = 183;
    u.decimal = 90;
    strcpy(u.name, "geeksforgeeks");
      
    printf("\nunion data:\n integer: %d\n "
                "decimal: %.2f\n name: %s\n",
            u.integer, u.decimal, u.name);
      
    printf("\n Accessing one member at time:");
    //Aca se deberia mostrar todo correctamente, ya que al modificar cada valor individualemente de un miembro, un instante despues y solo en dicho instante, se printea en pantalla esta modificaion. El resto no se printea simultaneamente ni se modifica. Este proceso repetido para cada miembro permite modificar y printear exitosamente
    printf("\n union data:");
    u.integer = 240;
    printf("\ninteger: %d", u.integer);
      
    u.decimal = 120;
    printf("\ndecimal: %f", u.decimal);
      
    strcpy(u.name, "C programming");
    printf("\nname: %s\n", u.name);
    
    //difference four
    //Aca se modifica solo un miembro y se intenta acceder a todos los miembros simultaneamente en el printf. Como lo que se modifico es el miembro integer, entonces se altera la informacion en los demas miembros tal que en un printeo se muestre informacion incorrecta. Luego por querer accedeer a todos los mimebros durante la misma instruccion entonces, se muestra informacion erronea para todos excepto el 1er miembro. Ya que C solo accedera al 1er miembro y no al resto.
    printf("\nAltering a member value:\n");
    u.integer = 1218;
    printf("union data:\n integer: %d\n"
           " decimal: %.2f\n name: %s\n",
            u.integer, u.decimal, u.name);
    return 0;
}
    
    
// C program to illustrate differences
// between structure and Union
 
#include <stdio.h>
#include <string.h>
  
// declaring structure
struct struct_example
{
    int integer;
    float decimal;
    char name[20];
    
    
};
  
// declaring union
  
union union_example
{
    int integer;
    float decimal;
    char name[20];
};
  
void main()
{
    // creating variable for structure
    // and initializing values difference
    // six
    struct struct_example s={18,38,"geeksforgeeks"};
  
    // creating variable for union
    // and initializing values
    union union_example u={18,38,"geeksforgeeks"};
  
          
    printf("structure data:\n integer: %d\n"
                "decimal: %.2f\n name: %s\n",
                s.integer, s.decimal, s.name);
    printf("\nunion data:\n integer: %d\n"
                 "decimal: %.2f\n name: %s\n",
                u.integer, u.decimal, u.name);
  
  
    // difference two and three
    printf("\nsizeof structure : %d\n", sizeof(s));
    printf("sizeof union : %d\n", sizeof(u));
      
    // difference five
    printf("\n Accessing all members at a time:");
    s.integer = 183;
    s.decimal = 90;
    strcpy(s.name, "geeksforgeeks");
      
    printf("structure data:\n integer: %d\n "
                "decimal: %.2f\n name: %s\n",
            s.integer, s.decimal, s.name);
      
    u.integer = 183;
    u.decimal = 90;
    strcpy(u.name, "geeksforgeeks");
      
    printf("\nunion data:\n integer: %d\n "
                "decimal: %.2f\n name: %s\n",
            u.integer, u.decimal, u.name);
      
    printf("\n Accessing one member at time:");
      
    printf("\nstructure data:");
    s.integer = 240;
    printf("\ninteger: %d", s.integer);
      
    s.decimal = 120;
    printf("\ndecimal: %f", s.decimal);
      
    strcpy(s.name, "C programming");
    printf("\nname: %s\n", s.name);
      
    printf("\n union data:");
    u.integer = 240;
    printf("\ninteger: %d", u.integer);
      
    u.decimal = 120;
    printf("\ndecimal: %f", u.decimal);
      
    strcpy(u.name, "C programming");
    printf("\nname: %s\n", u.name);
      
    //difference four
    printf("\nAltering a member value:\n");
    s.integer = 1218;
    printf("structure data:\n integer: %d\n "
                " decimal: %.2f\n name: %s\n",
                s.integer, s.decimal, s.name);
      
    u.integer = 1218;
    printf("union data:\n integer: %d\n"
           " decimal: %.2f\n name: %s\n",
            u.integer, u.decimal, u.name);
}
