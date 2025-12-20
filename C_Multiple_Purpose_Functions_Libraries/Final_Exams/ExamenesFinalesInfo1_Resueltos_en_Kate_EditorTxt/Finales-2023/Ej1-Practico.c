
typedef struct producto
{
    int codigo_Producto
    char proveedor[20];
    int cantidad_stock;


}Producto_t;

//probar typedef Producto_t Producto_t

typedef struct nodo
{
    //Producto_t p;
    //Utilizo otro nombre de variable para el tipo de dato Producto_t, siendo mas comodo "data"
    Producto_t data;
    //struct nodo *sig;
    //Utilizo la keyword Nodo_t para el tipo de dato struct nodo
    Nodo_t *sig;

}Nodo_t;


typedef struct producto_auxiliar
{
    int codigo_Producto
    char proveedor[20];
    int cantidad_stock;
}Producto_t_aux;

//probar typedef Nodo_t Nodo_t
int Cargar_Productos(const char *nombreArchivo, Producto_t **listado);
void Crear_Cargar_Enlazar_Nodo_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data);
void Imprimir_Campos_EstructuraInterna_NodoV1(Nodo_t **ptr1erElemento);
void Crear_Cargar_Enlazar_Nodo_V2(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,void *nueva_data, size_t tam_data);
void Imprimir_Campos_EstructuraInterna_NodoV2(Nodo_t **ptr1erElemento);

int main(int argc, char **argv)
{
    //Declaracion de variables e inicializacion de algunas de ellas
    int check, valor_codigo;
    FILE File_out = NULL;
    Producto_t_aux var;
    Producto_t *listado = NULL;
    Nodo_t *listadoFiltrado = NULL;//equivalente a Nodo_t *ptr1erElemento = NULL;
    Nodo_t *Nodo_Actual = NULL;
    //Verificacion contra cantidad insuficiente de argumentos
    if(argc < 3)
    {
        printf("Faltan comandos. Re-ingrese como: <nombre_ejecutable.out> <nombre_archivo.dat/.bin> <nombre_proveedor_a_filtrar>\n");
        return (-1);
    }
   /* //Carga de datos restantes por teclado pedidos por enunciado
    printf("Ingrese los datos restantes del producto proveniente del proveedor ingresado\n");
    printf("Codigo producto: ");
    scanf("%d",&var.codigo_Producto);
    __fpurge(stdin);
    printf("Cantidad stock: ");
    scanf("%d",&var.cantidad_stock);
    __fpurge(stdin);
    ........
    ........
    ........
    valor_codigo = 0;
    */


    //Apertura de arhcivo de salida y verificacion de error
    File_out =fopen("listafiltrada.bin","wb");
    if(File_out == NULL)
    {
        printf("Error en la apertura del archivo de salida\n");
        return (-1);
    }

    check = Cargar_Productos(argv[1],&ptr1erElemento,&Nodo_Actual);
    if(check == -1)
    {
        printf("Hubo un problema con la funcion Cargar_Productos\n");
        return (check);
    }
    else
        printf("La cantidad de estructuras leidas del archivo de entrada fueron: %d\n",check);

    check = FiltrarProductos();
    if(check == -1)
    {
        printf("Hubo un problema con la funcion FiltrarProductos()\n");
        return (check);
    }
    else
        printf("La cantidad de productos del proveedor es: %d\n", check);


    return 0;
}


/*
 Corregir el punto 1, es mas facil de lo que parece

 */


//Funcion pedida por enunciad. "const char *nombreArchivo" lo considero como un puntero al 1er elemento de un string de caracteres. "Producto_t **listado" lo considero como un puntero a puntero que apunta a la direccion de comienzo de un array dinamico de estructuras tipo "Producto_t"
int Cargar_Productos(const char *nombreArchivo, Producto_t **listado)
{
    //Declaracion de variables e inicializacion de algunas de ellas


    FILE *File_in = NULL;
    long tamanio_archivo;
    int cant_estructuras, i;
    int porciones_bytes_leidos;
    //Apertura archivo de entrada y verificacion de error
    File_in = fopen(nombreArchivo,"rb");
    if(File_in == NULL)
    {
        printf("Error en apertura de archivo de entrada\n");
        return(-1);
    }

    //Obtencion del tamanio del archivo a partir de reubicar el offset de lectura
    fseek(File_in,0,SEEK_END);
    tamanio_archivo = ftell(File_in);
    fseek(File_in,0,SEEK_SET);
    //Obtencion de la cantidad de estructuras
    cant_estructuras = tamanio_archivo / sizeof(Producto_t);

    //Creacion de array dinamico de estructuras tipo "Producto_t", verificacion de error de malloc y carga de estructuras en el array
    *listado = (Producto_t *)malloc(sizeof(Producto_t) * cant_estructuras);
    if(*listado == NULL)
    {
        printf("Error en apertura de archivo de entrada\n");
        return(-1);
    }
    for( i = 0; i < cant_estructuras; i ++ )
    {
        porciones_bytes_leidos = fread((*listado) + i,sizeof(Producto_t),1,File_in);
        if(porciones_bytes_leidos < 1)
        {
            printf("Hubo un error con la lectura de estructuras tipo Producto_t desde el arhcivo de entrada hacia la memoria\n");
            return (-1);
        }
    }

    //VER DE SACAR ESTA PARTE DEL CODIGO
    for( i = 0; i < cant_estructuras; i ++ )
        Crear_Cargar_Enlazar_Nodo_V1(ptr1erElemento,Nodo_Actual,(*listado)[i]);

    return cant_estructuras;
}

int FiltrarProductos(const Producto_t *listado, Nodo_t **listadoFiltrado, char *proveedor)
{
    int cant_productos = 0;



    return cant_productos
}


//Funcion generica que crea,cargar y enlaza un nodo donde alguno de los campos internos es una variable asociada a una estructura y NO un puntero a estructura, Esta funcion esta pensada para poder utilizar un nodo cuya "struct" es presentada de la siguiente manera
/*
    typedef struct nodo
    {
        Producto_t data;
        Nodo_t *sig;
    }Nodo_t;
 */
void Crear_Cargar_Enlazar_Nodo_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data)
{
    Nodo_t *Nuevo_Nodo = NULL;

    //Verifico si la lista esta vacia y en tal caso creo, cargo y agrego el 1er nodo de la lista
    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");
        //Allocacion de memoria dinamica para un nuevo nodo
        Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
        //Verificacion de error contra NULL de malloc
        if(Nuevo_Nodo == NULL)
        {
            printf("Hubo un error con la creacion y asignacion de memoria dinamica para el 1er nodo\n");
            exit(-1);
        }
        //Cargar nodo
        Nuevo_Nodo->data = data;
        //Enlazamiento
        Nuevo_Nodo->sig = NULL;

        //Retorno, por referencia, del puntero al nuevo nodo creado
        *Nodo_Actual = Nuevo_Nodo;
        *ptr1erElemento = Nuevo_Nodo;
    }

    //Si la lista no esta vacia, entonces creo un nuevo nodo, lo cargo y lo enlazo a la lista actual
    printf("Se creara, cargara y agregara un nuevo nodo a la lista\n");
    //Allocacion de memoria dinamica para un nuevo nodo
    Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
    if(Nuevo_Nodo == NULL)
    {
        printf("Hubo un error con la creacion y asignacion de memoria dinamica para un nuevo nodo\n");
        exit(-1);
    }
    //Cargar nodo
    Nuevo_Nodo->data = data;
    //Enlazamiento
    Nuevo_Nodo->sig = *ptr1erElemento;
    //Retorno, por referencia, del puntero al nuevo nodo creado
    *Nodo_Actual = Nuevo_Nodo;
    *ptr1erElemento = Nuevo_Nodo;

    return;
}

//Funcion generica que crea un nodo donde alguno de los campos internos es un puntero a otra estructura
//Esta funcion esta pensada para poder utilizar un nodo cuya "struct" es presentada de la siguiente manera
/*
    typedef struct nodo
    {
        void *data;
        Nodo_t *sig;
    }Nodo_t;
 */
void Crear_Cargar_Enlazar_Nodo_V2(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,void *nueva_data, size_t tam_data)
{
    Nodo_t *Nuevo_Nodo = NULL;
    int i;
    //Verifico si la lista esta vacia y en tal caso creo, cargo y agrego el 1er nodo de la lista
    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");
        //Allocacion de memoria dinamica para un nuevo nodo
        Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
        //Verificacion de error contra NULL de malloc
        if(Nuevo_Nodo == NULL)
        {
            printf("Hubo un error con la creacion y asignacion de memoria dinamica para el 1er nodo\n");
            exit(-1);
        }

        //Alocalizar memoria dinamica para una estructura interna del nodo y Cargar nodo
        Nuevo_Nodo->data = malloc(tam_data);
        if(Nuevo_Nodo->data == NULL)
        {
            printf("Hubo un problema con la asignacion de memoria dinamica para la estructura interna del nuevo nodo\n");
            exit(-1);
        }
        // Opcion 1
        // Copiado del contenido de lo apuntado por "void *nueva_data" hacia el bloque de memoria dinamico creado para la estructura interna del nodo.
        // Assunmo que char pesa 1 byte y que copia de a 1 byte a la vez
        for( i = 0; i < tam_data; i++ )
            *(char *)(Nuevo_Nodo->data + i) = *(char *)(nueva_data + i);

        // Opcion 2
        // Copiado del contenido de lo apuntado por "void *data" hacia el bloque de memoria dinamico creado para la estructura interna del nodo.
        // *(Nuevo_Nodo->data) = *nueva_data;

        //Enlazamiento
        Nuevo_Nodo->sig = NULL;

        //Retorno, por referencia, del puntero al nuevo nodo creado
        *Nodo_Actual = Nuevo_Nodo;
        *ptr1erElemento = Nuevo_Nodo;
    }

    //Si la lista no esta vacia, entonces creo un nuevo nodo, lo cargo y lo enlazo a la lista actual
    printf("Se creara, cargara y agregara un nuevo nodo a la lista\n");
    //Allocacion de memoria dinamica para un nuevo nodo
    Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
    if(Nuevo_Nodo == NULL)
    {
        printf("Hubo un error con la creacion y asignacion de memoria dinamica para un nuevo nodo\n");
        exit(-1);
    }

    // Opcion 1
    // Copiado del contenido de lo apuntado por "void *nueva_data" hacia el bloque de memoria dinamico creado para la estructura interna del nodo.
    // Assunmo que char pesa 1 byte y que copia de a 1 byte a la vez
    for( i = 0; i < tam_data; i++ )
        *(char *)(Nuevo_Nodo->data + i) = *(char *)(nueva_data + i);

    // Opcion 2
    // Copiado del contenido de lo apuntado por "void *data" hacia el bloque de memoria dinamico creado para la estructura interna del nodo.
    // *(Nuevo_Nodo->data) = *nueva_data;

    //Enlazamiento
    Nuevo_Nodo->sig = *ptr1erElemento;
    //Retorno, por referencia, del puntero al nuevo nodo creado
    *Nodo_Actual = Nuevo_Nodo;
    *ptr1erElemento = Nuevo_Nodo;

    return;
}

//Funcion que imprime la informacion de cada nodo de una lista simplemente enlazada siempre y cuando cada nodo tenga una variable del tipo "struct" con sus respectivos campos
void Imprimir_Campos_EstructuraInterna_NodoV1(Nodo_t **ptr1erElemento)
{
    Nodo_t *Nodo_Actual = *ptr1erElemento;

    while(Nodo_Actual != NULL)
    {
        printf("Codigo producto: %d\n", Nodo_Actual->data.codigo_Producto);
        printf("Proveedor: %s\n", Nodo_Actual->data.proveedor);
        printf("Cantidad stock: %d\n", Nodo_Actual->data.cantidad_stock);
        Nodo_Actual = Nodo_Actual->sig;
    }

    return;
}

//Funcion que imprime la informacion de cada nodo de una lista simplemente enlazada siempre y cuando cada nodo tenga un puntero a una "struct" con dicha estructura cargada con respectivos campos
void Imprimir_Campos_EstructuraInterna_NodoV2(Nodo_t **ptr1erElemento)
{
    Nodo_t Nodo_Actual = *ptr1erElemento;

    while(Nodo_Actual != NULL)
    {
        printf("Codigo producto: %d\n", Nodo_Actual->data->codigo_Producto);
        printf("Proveedor: %s\n", Nodo_Actual->data->proveedor);
        printf("Cantidad stock: %d\n", Nodo_Actual->data->cantidad_stock);
        Nodo_Actual = Nodo_Actual->sig;
    }

    return;
}

/*

//Funcion que recorre todos los nodos de una lista simplemente enlazada e imprime el contenido o data de cada uno. "fptr" es usado para acceder a otra funcion que imprime la informacion de los campos de una estructura interna de un nodo
void ImprimirLista(Nodo_t *Nodo_Actual, void (*fptr)(void *))
{
    while(Nodo_Actual != NULL)
    {
        (*fptr)(Nodo_Actual->data);
        Nodo_Actual = Nodo_Actual->sig;
    }
}

void Imprimir_Campos_EstructuraInterna_Nodo(void *ptr)
{
    printf("Codigo producto: %d\n", *(int *)ptr);
    printf("Proveedor: %s\n", (char *)ptr)
}




// Function to print an integer
void printInt(void *n)
{
   printf(" %d", *(int *)n);
}

// Function to print nodes in a given linked list. fpitr is used
   to access the function to be used for printing current node data.
   Note that different data types need different specifier in printf()
void printList(struct Node *node, void (*fptr)(void *))
{
    while (node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}



//Funcion generica que crea un nodo donde alguno de los campos internos es un puntero a otra estructura
void push(struct Node** head_ref, void *new_data, size_t data_size)
{
    // Allocate memory for node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data  = malloc(data_size);
    new_node->next = (*head_ref);

    // Copy contents of new_data to newly allocated memory.
    // Assumption: char takes 1 byte.
    int i;
    for (i=0; i<data_size; i++)
        *(char *)(new_node->data + i) = *(char *)(new_data + i);

    // Change head pointer as new node is added at the beginning
    (*head_ref)    = new_node
}

*/
