#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

struct info
{
    char nombre[10];
    int edad;
};

struct nodo
{
    struct info *pdato;
    struct nodo *psig;
};

void PushNodo(struct nodo **pinicial);
void PopNodo(struct nodo **pinicial);
void MostrarLista(struct nodo *pinicial);
void LiberarLista(struct nodo **pinicial);



//Una PILA consiste en un "apilamiento de datos" tal que el primero en entrar, es el ultimo en salir. Esto se conoce como FILO(First in Last Out). El equivalente a esto es pensar en LIFO(Last In First OUT) ya que en una pila, ademas, el ultimo en entrar, es el 1er dato en salir. Se suele usar esto con listas simplemente enlazadas ya que solo necesitamos un puntero al comienzo de la lista. Aunque tambien se puede usar con arrays.
//Si trabajamos con una lista simplemente enlazada para trabajar con PILAS, entonces,se dice que cada nuevo nodo se agrega AL PRINCIPIO de la lista y cada extraccion tambien se hace AL PRINCIPIO de la lista hasta llegar al nodo deseado

int main()
{
    struct nodo *pINI = NULL;//Lista inicialmente vacia
    int i, CantNodos;

    printf("Ingrese la cantidad de nodos a crear: ");
    scanf("%d", &CantNodos);
    __fpurge(stdin);

    //Creo nodos y los enlazo tal que tengo una lista simplemente enlazada trabajando como una PILA
    for( i = 0; i < CantNodos; i++ )
        PushNodo(&pINI);
    //Imprimo la lista creada
    MostrarLista(pINI);
    //Extraigo un nodo
    PopNodo(&pINI);
    //Imprimo la lista creada
    MostrarLista(pINI);
    //Extraigo un nodo
    PopNodo(&pINI);
    //Extraigo un nodo
    PopNodo(&pINI);
    //Libero los recursos
    LiberarLista(&pINI);

    printf("El programa se ha ejecutado correctamente y se ham liberado todos los recursos\n");


    return 0;
}

void PushNodo(struct nodo **pinicial)
{
     struct nodo *paux = *pinicial;

    //Pregunto si la lista esta vacia. En caso de estarlo creo el 1er nodo y lo inserto
    if((*pinicial) == NULL)
    {
         printf("La lista esta vacia. Se creara e insertara el 1er nodo de la PILA\n");
        *pinicial = (struct nodo *)malloc(sizeof(struct nodo));//Creo dinamicamente el 1er nodo de la PILA
        //Aca iria proteccion contra NULL de malloc

        (*pinicial)->psig = NULL;//El puntero psig lo apunto a NULL
        (*pinicial)->pdato = (struct info *)malloc(sizeof(struct info));//Creo la estructura dato de forma dinamica. Este dato estara ubicado dentro del nodo
        //Aca iria proteccion contra NULL de malloc


        //Cargo con informacion, proveniente del teclado, la estructura dato creada dinamicamente
        printf("Ingrese un nombre\n");
        scanf("%s",( (*pinicial)->pdato )->nombre);
        __fpurge(stdin);

        printf("Ingrese la edad\n");
        scanf("%d", &( ( (*pinicial)->pdato )->edad ) );
        __fpurge(stdin);


    }
    //Si la lista no esta vacia. Entonces creo el nuevo nodo y lo enlazo AL PRINCIPIO ya que en una PILA, simepre se hace de esta forma
    else
    {
        printf("La lista NO esta vacia. Se creara e insertara un nuevo nodo AL PRINCIPIO de la PILA\n");
        paux = (struct nodo *)malloc(sizeof(struct nodo));//Creo dinamicamente un nuevo nodo de la PILA
        //Aca iria proteccion contra NULL de malloc

         paux->psig = *pinicial;//Accedo al psig del nuevo nodo y hago que apunte al nodo inicial viejo de la lista
         *pinicial = paux;//El puntero al nodo inicial viejo de la lista apunta ahora al nuevo nodo de la lista el cual sera a su vez el inicial de la lista

         (*pinicial)->pdato = (struct info *)malloc(sizeof(struct info));//Creo dinamicamente la estructura dato. Esta se encuentra en el interior del nuevo nodo
        //Aca iria proteccion contra NULL de malloc
        //Cargo con informacion proveniente del teclado, la estructura dato creada dinamicamente
        printf("Ingrese un nombre\n");
        scanf("%s",( (*pinicial)->pdato )->nombre);
        __fpurge(stdin);

        printf("Ingrese la edad\n");
        scanf("%d", &( ( (*pinicial)->pdato )->edad ) );
        __fpurge(stdin);


    }



    return;
}

void PopNodo(struct nodo **pinicial)
{
    struct nodo *paux = NULL;

    //Pregunto si la lista esta vacia.De ser cierto, actuo en consecuencia
    if((*pinicial)==NULL)
    {
        printf("PILA vacia. No hay nada para extraer\n");
    }
    //Si la lista no esta vacia, entonces extraigo un nodo AL PRINCIPIO de la lista
    else
    {
        paux = *pinicial;//Guardo en paux la direccion del 1er nodo de la PILA
        printf("Extrayendo nombre: %s edad: %d\n", ((*pinicial)->pdato)->nombre, ((*pinicial)->pdato)->edad);//Extraigo dato
        *pinicial = (*pinicial)->psig;//Accedo al psig del nodo actual a extraer y hago que el *pinicial apunte al siguiente nodo siendo que este ahora se convierta en el nodo inicial de la lista

        free(paux->pdato);//Libero la memoria del dato del nodo a extraer
        free(paux);//Libero la memoria del nodo


    }
    return;
}

void MostrarLista(struct nodo *pinicial)
{
    struct nodo *paux = pinicial;

    if(pinicial == NULL)
    {
        printf("Lista Vacia\n");
    }
    else
    {
        while(paux != NULL)
        {
            printf("Nombre: %s, edad: %d\n", (paux->pdato)->nombre, (paux->pdato)->edad);
            paux = paux->psig;
        }
    }

    return;
}

void LiberarLista(struct nodo **pinicial)
{
    struct nodo *pactual = *pinicial;
    struct nodo *psiguiente = NULL;

    while(pactual != NULL)
    {
        psiguiente = pactual->psig;
        free(pactual->pdato);
        free(pactual);
        pactual = psiguiente;
    }

    *pinicial = NULL;

    return;
}
