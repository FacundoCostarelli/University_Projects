#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct info
{
    int dni;
    char sexo;
    char *nombre;
};

struct nodo
{
    struct nodo *psig;
    struct nodo *pant;
    struct info *Info;
};

void InsertarNodo (struct nodo **Pini, struct info *dato);
void MostrarLista (struct nodo *ini);
struct info *GenerarNodo(int gdni, char gsexo, char * gnombre);
void LiberarRecursos(struct nodo *ini);

int main()
{
    srandom(time(NULL));
    struct nodo *pinicio = NULL;
    struct info *aux = NULL;
    struct nodo *pfree = NULL;
    int i;

    for( i = 0; i < 5; i ++)
    {
        printf("Se llego a la linea 34\n");

        printf("Se generara un nuevo nodo #%d\n",i);
        aux = GenerarNodo(random()%100,'M',NULL);
        InsertarNodo(&pinicio,aux);
    }
    printf("La lista doblemente enlazada se ha creado exitosamente\n");
    pfree = pinicio;
    MostrarLista(pinicio);
    LiberarRecursos(pfree);

    return 0;
}

void InsertarNodo(struct nodo **Pini, struct info *dato)
{
    struct nodo *aux = *Pini;
    struct nodo *aux2 = *Pini;

    if(*Pini == NULL)
    {
        printf("Lista vacia\n");
        //Si entro a este if es porque la lista esta vacia. Entonces, se crea un nuevo nodo y el puntero inicial apunta a dicho nodo
        (*Pini) = (struct nodo *)malloc(sizeof(struct nodo));
        //Luego se rellenan los campos del nodo
        (*Pini)->psig = NULL;
        (*Pini)->pant = NULL;
        (*Pini)->Info = dato;

    }
    else
    {
        //Si entro aca es porque la lista no esta vacia. Entonces ya tengo al menos 1 o mas nodos.
        printf("La lista NO esta vacia. Se insertara un nuevo nodo\n");
        //Recorro la lista en busqueda del ultimo nodo tal que el nuevo nodo lo enlaze al final. Ademas se contempla un enlazamiento tal que los DNI quedan ordenados de mayor a menor. En caso del que el nuevo DNI del nuevo nodo sea mayor al DNI del nodo de comparacion actual, entonces se finaliza la busqueda y se hace un enlazamiento en el medio.

        while( (aux!=NULL)&& ( (aux->Info->dni) > (dato->dni) ) )
        {
            aux2 = aux;//Aux2 apunta al anteultimo nodo independientemente de en que lugar termina la iteracion del while
            aux = aux->psig;//Aux queda apuntando al ultimo nodo independientemente de en que lugar termina la iteracion del while
        }

        //Pregunto si el ultimo nodo de la lista es en realidad el 1er nodo de la lista. De ser cierto, esto indicaria que la Lista solo tenia 1 nodo y que el nodo a insertar seria el 2do nodo.
        //Enlazamiento al principio
        if( aux == *Pini)
        {
            printf("aux == *Pini\n");
            (*Pini)->pant = (struct nodo *)malloc(sizeof(struct nodo));//El nodo inicial de la lista, con su pant apunta a un nuevo nodo
            ((*Pini)->pant)->psig = (*Pini);//Accedo al nuevo nodo creado y hago que su psig apunte al nodo inicial de la lista
            ((*Pini)->pant)->pant = NULL;//Accedo al nuevo nodo creado y hago que su pant apunte a NULL
            (*Pini) = (*Pini)->pant;//Pini apunta ahora al nuevo nodo creado siendo este ahora el nodo inicial de la lista
            ((*Pini)->Info) = dato;//En el nuevo nodo creado cargao el dato
        }
        //En caso de que la lista tenga mas de 1 nodo, entonces entro en este else
        //Enlazamiento al final o en el medio segun convenga
        else
        {

            //Pregunto si aux apunta un nodo NULL. De ser cierto... esto indicaria que llegamos al final de la lista donde aux2 apunta al anteultimo nodo y aux apunta al ultimo nodo que es un nodo del tipo NULL. Esto implica que el nuevo nodo lo vamos a enlazar al final
            if(aux == NULL)//De cumplirse el if, entonces tenemos un enlazamiento al final
            {
                aux2->psig = (struct nodo *)malloc(sizeof(struct nodo));//El anteultimo nodo(que no es NULL) hago que apunte a un nuevo nodo creado con malloc a traves de que su psig apunte al nuevo nodo
                (aux2->psig)->psig = NULL;//Accedo al nuevo nodo creado y hago que su psig apunte a un nodo NULL
                (aux2->psig)->pant = aux2;//Accedo al nuevo nodo creado y hago que su pant apunte al anteultimo nodo apuntado por aux2
                (aux2->psig)->Info = dato;//Accedo al nuevo nodo creado y cargo el dato
                //Luego de todo esto, entonces el nuevo nodo creado es el anteultimo de la lista mientras que el ultimo nodo es NULL
                aux2 = aux2->psig;
                aux = NULL;
            }
            //En caso de no cumplirse el if, entonces se enlaza un nodo entre medio del nodo apuntado por aux(ultimo nodo en algun punto de la lista) y el nodo apuntado por aux2(nodo anterior al apuntado por aux en algun punto de la lista)
            else
            {
                aux2->psig = (struct nodo *)malloc(sizeof(struct nodo));//El anteultimo nodo respecto del apuntado por aux, hago que apunte a un nuevo nodo creado con malloc a traves de que su psig apunte al nuevo nodo
                aux->pant = aux2->psig;//El nodo apuntado por aux, ubicado en algun punto de la lista que no es al princpio ni al final, apunta con su pant al nuevo nodo creado
                (aux2->psig)->psig = aux;//Accedo al nuevo nodo creado y hago que su psig apunte al nodo apuntado por aux
                (aux2->psig)->pant = aux2;//Accedo al nuevo nodo creado y hago que su pant apunte al nodo apuntado por aux2
                (aux2->psig)->Info = dato;//Accedo al nuevo nodo creado y cargo el dato
                //Luego de todo esto, entonces el nuevo nodo creado es algun nodo intermedio de la lista ubicado entre 2 nodos cualesquiera
            }

        }
    }


    return;
}

void MostrarLista(struct nodo *ini)
{

    struct nodo *aux;

    printf("Se recorrera la lista en sentido directo\n");
    while(ini != NULL)//Se recorre la lista en sentido directo, es decir, desde el inicio hacia el final
    {
        printf("%d %c %s\n",ini->Info->dni, ini->Info->sexo, ini->Info->nombre);
        aux = ini;
        printf("ant: %p\nini: %p\n", ini->pant, ini);
        ini = ini->psig;
    }
    //Una vez finalizado el recorrido en sentido directo sucedera que ini apunta un ultimo nodo NULL y que aux apunta a un anteultimo nodo NO NULL respecto del nodo apuntado por ini
    printf("Se recorrera la lista en sentido inverso\n");
    while(aux != NULL)//Se recorre la lista en sentido inverso, es decir, desde el final hacia el inicio
    {
        printf("%d %c %s\n",aux->Info->dni, aux->Info->sexo, aux->Info->nombre);
        aux = aux->pant;
        printf("aux: %p\n", aux);
    }

    return;
}

struct info *GenerarNodo(int gdni, char gsexo, char * gnombre)
{
    struct info *datoaux = NULL;
    datoaux = (struct info *)malloc(sizeof(struct info));
    //Aca iria proteccion contra NULL de malloc
    datoaux->dni = gdni;
    datoaux->sexo = gsexo;
    datoaux->nombre = "No definido";
    return datoaux;
}

void LiberarRecursos(struct nodo *ini)
{
     struct nodo *aux;
     while(ini != NULL)
     {
         aux = ini;
         ini = ini->psig;
         free(aux->Info);
         free(aux);
     }

     printf("Se liberaron los recursos correctamente\n");
     return;

}
