//Funcion generica que crea,cargar y enlaza un nodo donde alguno de los campos internos es una variable asociada a una estructura y NO un puntero a estructura, Esta funcion esta pensada para poder utilizar un nodo cuya "struct" es presentada de la siguiente manera
/*
    typedef struct nodo
    {
        Producto_t data;
        Nodo_t *sig;
    }Nodo_t;
 */
void Lista_Simplemente_Enlazada_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data)
{
    Nodo_t *Nuevo_Nodo = NULL;
    int PosNodoIzq;
    int PosNodoDer;

    //Verifico si la lista esta vacia y en tal caso creo, cargo y agrego el 1er nodo de la lista
    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");

        //Llamo a funcion que crea dinamicamente un nuevo nodo
        Allocalizar_Nuevo_Nodo(&Nuevo_Nodo);

        //Cargar nodo
        Nuevo_Nodo->data = data;
        //Enlazamiento
        Nuevo_Nodo->sig = NULL;

        //Retorno, por referencia, del puntero al nuevo nodo creado
        *Nodo_Actual = Nuevo_Nodo;
        *ptr1erElemento = Nuevo_Nodo;
    }
    else
    {
        do
        {
            //Si la lista no esta vacia, entonces creo un nuevo nodo, lo cargo y lo enlazo a la lista actual. Elijo ademas un metodo de enlazamiento
            printf("Ingrese una de las siguientes opciones de enlazamiento de nodo\n-1)Enlazar al final\n-2)Enlazar al principio\n-3)Enlazar en el medio\n");
            scanf("%d", &decision);
            __fpurge(stdin);

            if( decision < 1 || decision > 3)
                printf("Ha ingresado mal una opcion. Intentelo nuevamente\n");
        }while( decision < 1 || decision > 3);

        switch(decision)
        {
            case 1:
                Enlazar_Al_Final_Y_Cargar(ptr1erElemento,Nodo_Actual,data,&Nuevo_Nodo);
                break;
            case 2:
                Enlazar_Al_Principio_Y_Cargar(ptr1erElemento,Nodo_Actual,data,&Nuevo_Nodo);
                break;
            case 3:

                //Pedido de ingreso de nro de nodos entre los cuales se quiere enlazar al nuevo.
                //Faltaria agregar proteccion contra posicion de nodos mal ingresados
                printf("Usted va a ingresar un nro de posicion de nodos consecutivos entre los cuales quiere enlazar el nuevo nodo\nConsidere como posicion inicial 0\n");
                printf("Ingrese solamente la posicion del nodo lateral izquierdo: ");
                scanf("%d", &PosNodoIzq);
                __fpurge(stdin);
                PosNodoDer = PosNodoIzq + 1;
                printf("La posicion del nodo lateral derecho consecutivo es: %d\n",PosNodoDer);
                /*
                printf("Ingrese la posicion del nodo lateral derecho: ");
                scanf("%d", &PosNodoDer);
                __fpurge(stdin);
                */
                Enlazar_En_El_Medio_Y_Cargar(ptr1erElemento,Nodo_Actual,data,&Nuevo_Nodo,PosNodoIzq,PosNodoDer);
                break;
            default:
                break;
        }
    }

    return;
}

void Allocalizar_Nuevo_Nodo(Nodo_t **Nuevo_Nodo)
{
    //Allocacion de memoria dinamica para un nuevo nodo y verificacion de error de malloc
    *Nuevo_Nodo = (Nodo_t *)malloc(sizeof(Nodo_t));
    if(*Nuevo_Nodo == NULL)
    {
        printf("Hubo un error con la creacion y asignacion de memoria dinamica para un nuevo nodo\n");
        exit(-1);
    }
    else
        printf("Se creo exitosamente y dinamicamente un nuevo nodo\n");

    return;
}

void Enlazar_Al_Final_Y_Cargar_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data,Nodo_t **Nuevo_Nodo)
{
    //Asignacion tal que el *Nodo_Actual apunta al 1er nodo de la lista
    *Nodo_Actual = *ptr1erElemento;

    printf("Se creara, cargara y agregara un nuevo nodo al final de la lista\n");

    //Llamo a funcion que crea dinamicamente un nuevo nodo
    Allocalizar_Nuevo_Nodo(Nuevo_Nodo);

    //Busqueda del ultimo nodo en la lista
    while( (*Nodo_Actual)->sig != NULL  )
        (*Nodo_Actual) = (*Nodo_Actual)->sig;

    //Enlazo nodo al final de la lista
    (*Nodo_Actual)->sig = *Nuevo_Nodo;
    //Cargo el nuevo nodo
    (*Nuevo_Nodo)->data = data;
    (*Nuevo_Nodo)->sig = NULL;
    //Retorno, por referencia, del puntero al nuevo nodo creado
    *Nodo_Actual = *Nuevo_Nodo;

    return;
}

void Enlazar_Al_Principio_Y_Cargar_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data,Nodo_t **Nuevo_Nodo)
{
    //Asignacion tal que el *Nodo_Actual apunta al 1er nodo de la lista
    *Nodo_Actual = *ptr1erElemento;

    printf("Se creara, cargara y agregara un nuevo nodo al principio de la lista\n");

    //Llamo a funcion que crea dinamicamente un nuevo nodo
    Allocalizar_Nuevo_Nodo(Nuevo_Nodo);

    //No busco ultimo nodo del final de lista ya que solo necesito el nodo inicial de la lista

    //Enlazo nodo al princpio de la lista
    (*Nuevo_Nodo)->sig = *Nodo_Actual;
    //Cargo el nuevo nodo
    (*Nuevo_Nodo)->data = data;
    //Retorno, por referencia, del puntero al nuevo nodo creado
    *Nodo_Actual = *Nuevo_Nodo;

    return;
}

void Enlazar_En_El_Medio_Y_Cargar_V1(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,Producto_t data,Nodo_t **Nuevo_Nodo,int PosNodoIzq, int PosNodoDer)
{
    //Asignacion tal que el *Nodo_Actual apunta al 1er nodo de la lista
    *Nodo_Actual = *ptr1erElemento;

    //Declaracion de 2 punteros auxiliares para apuntar a los nodos laterales que se enlazaran con el nodo intermedio creado
    Nodo_t *Nodo_Aux1 = *ptr1erElemento;
    Nodo_t *Nodo_Aux2 = *ptr1erElemento;

    //Declaracion de variable de iteracion
    int i;

    printf("Se creara, cargara y agregara un nuevo nodo en el medio de la lista siendo que se ubique entre el nodo: %d y el nodo:  %d\n", PosNodoIzq, PosNodoDer);

    //Llamo a funcion que crea dinamicamente un nuevo nodo
    Allocalizar_Nuevo_Nodo(Nuevo_Nodo);

    if(PosNodoIzq != 0)
    {
        //Recorro la lista en busqueda del nodo lateral izquierdo
        for( i = 1; i < PosNodoIzq; i++ )
            Nodo_Aux1 = Nodo_Aux1->sig;
    }
    //Recorro la lista en busqueda del nodo lateral derecho
    for( i = 0; i < PosNodoDer; i++ )
        Nodo_Aux2 = Nodo_Aux2->sig;

    //Enlazo el nuevo nodo creado entre medio de los nodos laterales izquierdo y derecho respectivamente
    Nodo_Aux1->sig = *Nuevo_Nodo;
    (*Nuevo_Nodo)->sig = Nodo_Aux2;

    //Cargo el nuevo nodo
    (*Nuevo_Nodo)->data = data;
    //Retorno, por referencia, del puntero al nuevo nodo creado
    *Nodo_Actual = *Nuevo_Nodo;

    return;
}

void BorrarNodo(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,//parametros de filtrado para borrar)
{
    //*Nodo_Actual seria equivalente a Nodo_t *Puntero_Nodo_aux
    *Nodo_Actual = *ptr1erElemento;
    Nodo_t *Nodo_Anterior = NULL;

    if(*Nodo_Actual == NULL)
    {
        printf("Lista vacia, usted saldra del programa\n");
        exit(-1);
    }
    else
    {
        while(*Nodo_Actual != NULL)
        {
            //Pregunto si el dato del campo elegido del nodo actual coincide con el parametro de borrado ingresado
            if(*Nodo_Actual->/*parametro*/ == /*parametro*/)
            {
                //Pregunto si el nodo a borrar es el 1er nodo de la lista y en caso de V o F actuo en consecuncia
                if(*Nodo_Actual == *ptr1erElemento)
                {
                    //Sabiendo que el nodo a borrar es el 1er nodo de la lista entonces, pregunto si es el nodo a borrar es ademas el UNICO nodo de la lista
                    if(*Nodo_Actual->sig == NULL)
                    {
                        //Apunto el puntero inicial a NULL tal que la lista esta vacua
                        *ptr1erElemento = NULL;
                        //Libero la memoria dinamica consumida por el nodo
                        free(*Nodo_Actual);
                    }
                    //Sabiendo que el nodo a borrar es el 1er nodo de la lista PERO que NO ES EL UNICO en la lista, actuo en consecuencia.
                    else
                    {
                        //Apunto el puntero inicial al siguiente nodo consecutivo de la lista
                        *ptr1erElemento = *Nodo_Actual->sig;
                        //Libero la memoria dinamica consumida por el nodo
                        free(*Nodo_Actual);
                    }
                }
                //Sabiendo que el nodo a borrar NO ES EL 1ER NODO, entonces actuo en consecuencia
                else
                {
                    //El nodo anterior respecto al que se va a borrar, "Salta el enlace" tal que se enlaza al nodo siguinete consecutivo al que se va a borrar
                    Nodo_Anterior->sig = *Nodo_Actual->sig;
                    //Libero la memoria dinamica consumida por el nodo
                    free(*Nodo_Actual);
                }
            }
                 Nodo_Anterior = *Nodo_Actual;
                *Nodo_Actual = *Nodo_Actual->sig;


        }
    }

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


//Funcion generica que crea un nodo donde alguno de los campos internos es un puntero a otra estructura
//Esta funcion esta pensada para poder utilizar un nodo cuya "struct" es presentada de la siguiente manera
/*
    typedef struct nodo
    {
        void *data;
        Nodo_t *sig;
    }Nodo_t;
 */
void Lista_Simplemente_Enlazada_V2(Nodo_t **ptr1erElemento,Nodo_t **Nodo_Actual,void *nueva_data, size_t tam_data)
{
    Nodo_t *Nuevo_Nodo = NULL;
    int i;
    //Verifico si la lista esta vacia y en tal caso creo, cargo y agrego el 1er nodo de la lista
    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");

        //Llamo a funcion que crea dinamicamente un nuevo nodo
        Allocalizar_Nuevo_Nodo(&Nuevo_Nodo);
        //Llamo a funcion que crea dinamicamente una nueva estructura
        Allocalizar_Nueva_Estructura(&Nuevo_Nodo, tam_data);

        // Copiado del contenido de lo apuntado por "void *nueva_data" hacia el bloque de memoria dinamico creado para la estructura interna del nodo.
        // Assunmo que char pesa 1 byte y que copia de a 1 byte a la vez
        for( i = 0; i < tam_data; i++ )
            *(char *)(Nuevo_Nodo->data + i) = *(char *)(nueva_data + i);

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

void Allocalizar_Nueva_Estructura(Nodo_t **Nuevo_Nodo, size_t tam_data)
{
    //Alocalizar memoria dinamica para una estructura interna del nodo y Cargar nodo
    (*Nuevo_Nodo)->data = (void *)malloc(tam_data);
    if((*Nuevo_Nodo)->data == NULL)
    {
        printf("Hubo un problema con la asignacion de memoria dinamica para la estructura interna del nuevo nodo\n");
        exit(-1);
    }
    else
        printf("Se ha creado exitosamente una estructura interna dinamicamente\n");

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
