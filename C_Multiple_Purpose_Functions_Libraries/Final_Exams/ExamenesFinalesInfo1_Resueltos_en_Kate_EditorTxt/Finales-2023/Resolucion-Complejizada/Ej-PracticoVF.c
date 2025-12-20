#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>


typedef struct producto
{
    int codigo_Producto;
    char proveedor[20];
    int cantidad_stock;
}Producto_t;

typedef struct nodo
{
    Producto_t p;
    struct nodo *sig;

}Nodo_t;

int CargarProductos(const char *nombreArchivo, Producto_t ***listado);
void MostrarListado(Producto_t **listado);
int FiltrarProductos(Producto_t **listado, Nodo_t **listadoFiltrado, char *Proveedor);
int InsertarNodo_SL(const Producto_t *dato, Nodo_t **pINI, Nodo_t **pFIN);
void ExtraerNodo_SL(Nodo_t **pINI, Nodo_t **pFIN);
void MostrarNodos_SL(Nodo_t **pINI);
void LiberarNodos_SL(Nodo_t **pINI);


int main(int argc, char **argv)
{
    Producto_t **listado = NULL;
    Nodo_t *listadoFiltrado = NULL;
    int CantidadEstructurasLeidas;
    int Codigo_CargaDatosProveedor = 1;
    int i = 0;
    int check;
    size_t len;

    if(argc != 3)
    {
        printf("Cantidad incorrecta de argumentos. Reingrese siguiendo la referencia: <nombre_ejecutable.out> <nombre_archivo.bin> <nombre_proveedor>");
        return -1;

    }

    printf("Se llego a la linea 47\n");
    //Llamo a una funcion para crear y cargar dinamicamente un array de punteros a estructuras Producto_t * donde ademas voy a crear y cargar dinamicamente cada estructura apuntada con la informacion proveniente del archivo de entrada binario
    check = CargarProductos(argv[1], &listado);
    if(check == -1)
    {
        printf("Hubo un problema con la funcion CargarProducto\n");
        return -1;
    }
    else
    {
        CantidadEstructurasLeidas = check;
        printf("La cantidad de estructuras leidas son: %d\n", CantidadEstructurasLeidas);
    }

    i = CantidadEstructurasLeidas-2;
    //Llamo a una funcion para mostrar el contenido apuntado por punteros tipo Producto_t * que se encuentran en un array dinamico, en formato PILA;
    MostrarListado(listado);

    printf("Se llego a la linea 61\n");
        //Carga de informacion por teclado en cada una de las estructuras apuntadas por los punteros Producto_t * del array dinamico hasta que se ingrese algun codigo de finalizacion de carga
    while( i >= 0 )
    {
        printf("En base al archivo de entrada, entonces la informacion ACTUAL de la estrcutura #%d es:\n",i);
        printf("Codigo de producto: %d\n", (*((listado)+i))->codigo_Producto );
        printf("Nombre de proveedor: %s\n", ((*((listado)+i))->proveedor) );
        printf("Cantidad en stock: %d\n", ((*((listado)+i))->cantidad_stock) );
        printf("Desea realizar modificaciones en la estructura #%d mostrada recientemente???. \nEn caso de que SI, ingrese 1\nEn caso de que NO, ingrese 0\nOpcion: ",i);
        scanf("%d", &Codigo_CargaDatosProveedor);
        __fpurge(stdin);

        if(Codigo_CargaDatosProveedor == 1)
        {
            printf("Ingrese el codigo de producto: ");
            scanf("%d", &((*((listado)+i))->codigo_Producto) );
            __fpurge(stdin);

            printf("Ingrese el nombre del proveedor: ");
            if(fgets((*((listado)+i))->proveedor,20,stdin) != NULL)
            {
                len = strlen((*((listado)+i))->proveedor);
                if(len > 0 && (*((listado)+i))->proveedor[len-1] == '\n')
                    (*((listado)+i))->proveedor[len-1] =  '\0';
            }
            else
            {
                printf("Hubo un error con la lectura de fgets desde el teclado\n");
                return -1;
            }

            printf("Ingrese la cantidad en stock: ");
            scanf("%d", &((*((listado)+i))->cantidad_stock));
            __fpurge(stdin);
        }
        i--;
    }

    printf("La lista luego de la modificacion de datos queda como: \n");
    //Llamo a una funcion para mostrar el contenido apuntado por punteros tipo Producto_t * que se encuentran en un array dinamico, en formato PILA;
    MostrarListado(listado);

    printf("Se llego a la linea 106\n");
    //Llamo a una funcion para filtrar estructuras apuntadas por punteros Producto_t * donde dicho filtrado es en base a un nombre de un proveedor
    check = FiltrarProductos(listado, &listadoFiltrado, argv[2]);
    if(check == -1)
    {
        printf("Error con la funcion FiltrarProductos\n");
        return check;
    }
    else
        printf("La cantidad de productos filtrados segun el nombre del proveedor es: %d\n", check);




    return 0;
}


int CargarProductos(const char *nombreArchivo, Producto_t ***listado)
{
    int CantidadEstructuras_FileIn, i = 0, CantidadEstructurasLeidas;
    FILE *File_in = NULL;
    long tamanio_archivo;
    size_t CantItemsLeidos;

    File_in = fopen(nombreArchivo, "r");
    if(File_in == NULL)
    {
        printf("Error en apertura de archivo de entrada\n");
        return (-1);
    }

    fseek(File_in,0,SEEK_END);
    tamanio_archivo = ftell(File_in);
    CantidadEstructuras_FileIn = ( ( (int)tamanio_archivo ) / ( (int)sizeof(Producto_t) ) );
    printf("La cantidad de estructuras tipo Producto_t son: %d\n", CantidadEstructuras_FileIn);
    fseek(File_in,0,SEEK_SET);

    printf("Se llego a la linea 139\n");
    //Pregunto si la lista esta vacia. En caso de estarlo creo el array dinamico y lo cargo con un formato PILA, es decir, LIFO(Last in First Out)
    if(*listado == NULL)
    {
        printf("La lista esta vacia. Se crearan e insertaran los elementos siguiendo un formato PILA\n");
        *listado = (Producto_t **)malloc(sizeof(Producto_t *));
        //Proteccion contra null de malloc
        (*listado)[0] = (Producto_t *)malloc(sizeof(Producto_t));
        //Proteccion contra null de malloc
        fread((*listado)[i],sizeof(Producto_t),1,File_in);
        //Proteccion contra falta de items leidos

        for( i = 1; i < CantidadEstructuras_FileIn; i++ )
        {
            *listado = (Producto_t **)reallocarray(*listado, (i+1), sizeof(Producto_t *));
            printf("Se llego a la linea 147 \n");
            //Proteccion contra NULL de realloc
            if(*listado == NULL)
            {
                printf("Error en la asigancion de memoria dinamica para el array de punteros del tipo Producto_t * \n");
                return (-1);
            }
            (*listado)[i] = (Producto_t *)malloc(sizeof(Producto_t));
            //Proteccion contra NULL de malloc
            if((*listado)[i] == NULL)
            {
                printf("Error en la asignacion de memoria dinamica para las estructura del tipo Producto_t\n");
                return (-1);
            }
            CantItemsLeidos = fread((*listado)[i],sizeof(Producto_t),1,File_in);
            //Proteccion contra falta de lectura de items de informacion
            if(CantItemsLeidos < 1)
            {
                printf("Error en la cantidad de estructuras tipo Producto_t leidas desde el archivo de entrada\n");
                return (-1);
            }
        }
        printf("Se llego a la linea 168\n");
        //i++;
        *listado = (Producto_t **)reallocarray(*listado,(i+1), sizeof(Producto_t *));
        //Proteccion contra NULL de realloc
        if(*listado == NULL)
        {
            printf("Error en la asigancion de memoria dinamica para el array de punteros del tipo Producto_t * \n");
            return (-1);
        }
        (*listado)[i] = NULL;//Cargo un elemento mas adicional como NULL para poder saber cuando termina el array dinamico y calcular la cantidad de elementos que tiene en otras funciones

        printf("Se llego a la linea 186\n");
    }
    else
    {
        printf("La lista ya esta cargada. No hay nada que agregar\n");
        return (-1);
    }

    //Cierro el arhcivo de entrada
    fclose(File_in);

    printf("Se ejecuto correctamente la funcion CargarProductos\n");

    return (CantidadEstructurasLeidas = i+1);//Retorno la cantidad de estructuras leidas a partir de contar la cantidad de punteros Producto_t * cargados en el array incluyendo un ultimo puntero NULL

}



void MostrarListado(Producto_t **listado)
{
    int i = 0;

    while(listado[i] != NULL)
    {
        printf("Estructura #%d posee la info: \n", i);
        printf("Codigo Producto: %d\n", (listado[i])->codigo_Producto);
        printf("Nombre Proveedor: %s\n", (listado[i])->proveedor);
        printf("Cantidad de stock: %d\n", (listado[i])->cantidad_stock );
        i++;
    }

    return;
}



//ES IMPORTANTE DESTACAR que al usar una Lista Simplemente Enlazada, habra que realizar el enlazamiento AL FINAL y la extraccion de datos AL PRINCIPIO para que sea facil y practico. Aca tambien habran 2 punteros. Uno que apunte al comienzo de la cola y otro al final
//En la funcion FiltrarProductos, asumo que recibo un puntero doble, es decir, un puntero a un array de punteros simples del tipo Producto_t *, esto seria entonces "const Producto_t **listado", luego recibo como parametro un puntero doble que apunta a un puntero simple que apunta al inicio de una COLA con lista simplemente enlazada. Finalmente recibo un puntero a un string de caracteres asociado al nombre de proveedor
int FiltrarProductos(Producto_t **listado, Nodo_t **listadoFiltrado, char *Proveedor)//Primer parametro antes era const Producto_t *listado
{
    Nodo_t *pINI = *listadoFiltrado;
    Nodo_t *pFIN = NULL;
    //Producto_t **BasePila = NULL;
    //Producto_t **TopePila = NULL;
    int check;
    int CantidadProductosProveedor = 0;
    int i = 0;
    printf("Se llego a la libea 238\n");
    //Apunto un puntero a la BASE de la PILA
    //BasePila = listado;
    //Recorro el listado de punteros en busqueda del ultimo elemento que es NULL
    while(listado[i] != NULL)
            i++;

    printf("El valor de i luego de recorrer la lista en FiltrarProductos es: %d\n", i);
    //Luego de encontrar el ultimo puntero y saber la cantidad de elementos del listado a traves de "i", entonces apunto un puntero al TOP de la PILA
    //TopePila = listado+i;

    //Trato al listado de punteros a estructuras tipo Producto_t*, como una PILA. Entonces evaluo secuncialmente desde el TOPE hasta la BASE cada elemento, utilizo la informacioon de dicho elemento convenientemente y libero la memoria dinamica ocupada luego de utilizar dicho elemento
    while( i > 0 )
    {
        if(strcasecmp( (listado[i-1])->proveedor, Proveedor ) == 0 )
        {
            printf("Se llego a la linea 256\n");
            check = InsertarNodo_SL(listado[i-1], &pINI, &pFIN);
            if(check == -1)
            {
                printf("Surgio un error en el filtrado de productos\n");
                return check;
            }
            CantidadProductosProveedor++;
        }

        printf("Se llego a la linea 266\n");
        //Luego de evaluar cada elemento de la PILA, manteniendo una forma secuencial, desde el TOPE hasta la BASE. Entonces, voy liberando la memoria dinamica apuntada por cada elemento evaluado y hago que dicho puntero apunte a NULL
        free(listado[i-1]);
        listado[i-1] = NULL;

        //Decremento el iterador
        i--;
    }
    printf("Se llego a la linea 274\n");
    printf("La COLA SIMPLE SL queda como: \n");
    //Llamo a una funcion para mostrar como queda la COLA autoreferenciada con sus nodos, esto luego del filtrado
    MostrarNodos_SL(&pINI);
    //Llamo a una funcion para liberar la memoria dinamica ocupada por la COLA autoreferenciada
    LiberarNodos_SL(&pINI);

    printf("Se llego a la linea 280\n");
    return CantidadProductosProveedor;
}

int InsertarNodo_SL(const Producto_t *dato, Nodo_t **pINI, Nodo_t **pFIN)
{
    Nodo_t *paux = NULL;
    Nodo_t *paux2 = NULL;
    //Pregunto si la lista esta vacia. En caso de estarlo creo el 1er nodo y lo inserto
    if(*pINI == NULL)
    {
        printf("La lista esta vacia. Se creara e insertara el 1er nodo de la COLA SIMPLE\n");
        *pINI = (Nodo_t *)malloc(sizeof(Nodo_t));//Creo dinamicamente el 1er nodo de la COLA SIMPLE
        //Proteccion contra NULL de malloc
        if(*pINI == NULL)
        {
            printf("Error durante la asignacion de memoria dinamica para un nodo\n");
            return -1;
        }
        *pFIN = *pINI;//Como hay un 1er y unico nodo, entonces el puntero inicial y el puntero final de la lista apuntan al mismo nodo
        (*pINI)->sig = NULL;//El puntero sig lo apunto a NULL
        (*pINI)->p = *dato;//Cargo el dato en el nodo
    }
    //Si la lista no esta vacia. Entonces creo el nuevo nodo y lo enlazo AL FINAL ya que en una COLA SIMPLE usando una Lista Simplemente Enlazada, se puede deducir que es la manera mas practica y sencilla
    else
    {
        printf("La lista NO esta vacia. Se creara e insertara un nuevo nodo AL FINAL de la COLA SIMPLE\n");
        paux = (Nodo_t *)malloc(sizeof(Nodo_t));//Creo dinamicamente un nuevo nodo de la COLA SIMPLE
        //Proteccion contra NULL de malloc
        if(paux == NULL)
        {
            printf("Error durante la asignacion de memoria dinamica para un nodo\n");
            return -1;
        }
        paux2 = *pINI;//Apunto paux2 al comienzo de la lista
        //Recorro la lista en busqueda del ultimo nodo. Este nodo sera aquel donde el puntero "sig" apunte a NULL
        while(paux2->sig != NULL)
            paux2 = paux2->sig;

        paux2->sig = paux;//Enlazo el nuevo nodo AL FINAL de la lista
        paux->sig = NULL;//Apunto el puntero "sig" del nuevo nodo a NULL
        paux->p = *dato;//Cargo el dato en el nodo
        *pFIN = paux;//Apunto el puntero "*pFIN" al ultimo nodo de la lista
    }

    return 0;
}

void ExtraerNodo_SL(Nodo_t **pINI, Nodo_t **pFIN)
{
    Nodo_t *paux = NULL;

    //Pregunto si la cola no esta vacia. De NO estar vacia, significa que hay un puntero inicial apuntando a un nodo inicial de la lista y ademas hay un  puntero final apuntando al ultimo nodo de la lista y dicho ultimo nodo NO es NULL
    //Realizo la extraccion y eliminacion de un nodo AL PRINCIPIO de la cola siguiendo el modelo FIFO
    if(*pINI != NULL)
    {
        paux = *pINI;//Guardo en un puntero auxiliar, una copia del puntero al nodo inicial de la lista
        *pINI = (*pINI)->sig;//Reasigno el puntero al nodo inicial a un nuevo nodo inicial siguiente de la lista
        paux->sig = NULL;//Apunto el puntero "sig" a NULL. Esto dentro del nodo a extraer

        printf("La informacion del nodo a extraer es:\n ");
        printf("Codigo Producto: %d\n", paux->p.codigo_Producto);
        printf("Nombre Proveedor: %s\n", paux->p.proveedor);
        printf("Cantidad de stock: %d\n", paux->p.cantidad_stock);

        free(paux);//Libero la memoria dinamica del nodo cuya informacion fue extraida o printeada en pantalla

    }
    //En caso de estar vacia la lista tomo accion
    else
        printf("La lista esta vacia y no hay ningun nodo para extraer. Continuara la ejecucion del programa\n");


    return;
}

void MostrarNodos_SL(Nodo_t **pINI)
{
    Nodo_t *paux = *pINI;
    int i = 0;

    while(paux != NULL)
    {
        printf("La informacion del nodo #%d:\n", i);
        printf("Codigo Producto: %d\n", paux->p.codigo_Producto);
        printf("Nombre Proveedor: %s\n", paux->p.proveedor);
        printf("Cantidad de stock: %d\n", paux->p.cantidad_stock);
        i++;
        paux = paux->sig;
    }
    return;
}


void LiberarNodos_SL(Nodo_t **pINI)
{
    Nodo_t *paux = *pINI;


    while(paux != NULL)
    {
        *pINI = (*pINI)->sig;
        free(paux);
        paux = *pINI;
    }
    printf("Se han liberado correctamente todos los recursos\n");

    return;
}
