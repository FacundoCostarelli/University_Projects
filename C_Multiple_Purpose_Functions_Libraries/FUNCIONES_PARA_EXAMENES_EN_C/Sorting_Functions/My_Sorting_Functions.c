#include"Mis_OrdenamientoFunciones.h"

void Int_Ordenamiento_Burbuja_May_A_Men(int *Array, int largo)
{
    int i = 0;
    int j = 0;
    int aux = 0;
    //Supongo inicialmente que el array esta completamente ordenado
    bool Ocurrencia_De_Intercambio = false;
    /*El primer for esta asociado a la cantidad de veces que se recorre todo el vector para realizar un
    "swap o intercambio"*/
    do
    {   /*Asumo que todos los elementos del array estan totalmente ordenados luego de ejutar un intercambio en el bloque for e if
          Luego con los ciclos for evaluo si es cierto
          En caso de que haya algo que intercambiarse, se asgina "true" en el bloque if
          Esta tecnica evita tener que recorrer el array "n = largo,  veces" cuando ya se encuentra completamente ordenado
          tanto por pirmera vez como luego de algun intercambio o swap*/
        Ocurrencia_De_Intercambio = false;

        /*El segundo for esta asociado con la iteracion de valores para buscar 2 valores
          para intercambiar o "swapear". Cada vez que un elemento queda completamente ordenado
          en su lugar, ya no es necesario compararlo con los elementos consecutivos ya que estos tambien
          estan ordenados y por lo tanto no es necesario recorrer todo el vector. Es por esto que
          el segundo for se ejecuta siempre que j < (largo-1-i).
          Si fuese (largo-1) entonces seguiria recorriendo elementos que ya estan ordenados y esto no es eficiente
           */
        for(j = 0; j < (largo-1-i); j++)
        {
            /*Pregunto si el valor en posicion actual j es mayor que el de la posicion siguiente j+1
                en tal caso, realizo un swap*/
            if(Array[j] < Array[j+1])//Como uso el "<" el ordenamiento es de mayor a menor
            {
                /*Guardo el valor de la pos actual j en una variable aux*/
                aux = Array[j];
                /*Cpio el valor de la pos siguiente j+1 en el elemento de la pos actual j*/
                Array[j] = Array[j+1];
                /*Copio el valor de lo almacenado por aux en el elemento de la pos siguiente j+1*/
                Array[j+1] = aux;
                /*Al ejecutarse un intercambio, entonces seteo la variable indicada en true. Esto significa que
                 ocurrio un intercambio y que no es posible saber en esta instancia que el siguiente elemento
                 tambien este ordenado */
                 Ocurrencia_De_Intercambio = true;
            }
        }
        i++;
    }while(Ocurrencia_De_Intercambio == true);

    for( i = 0; i < largo; i ++ )
    {
        printf("Array [%d] = %d ",i,Array[i]);
    }
    printf("\n");
    return;
}

void Int_Ordenamiento_Burbuja_Men_A_May(int *Array, int largo)
{
    int i = 0;
    int j = 0;
    int aux = 0;
    //Supongo inicialmente que el array esta completamente ordenado
    bool Ocurrencia_De_Intercambio = false;
    /*El primer for esta asociado a la cantidad de veces que se recorre todo el vector para realizar un
    "swap o intercambio"*/
    do
    {   /*Asumo que todos los elementos del array estan totalmente ordenados luego de ejutar un intercambio en el bloque for e if
          Luego con los ciclos for evaluo si es cierto
          En caso de que haya algo que intercambiarse, se asgina "true" en el bloque if
          Esta tecnica evita tener que recorrer el array "n = largo,  veces" cuando ya se encuentra completamente ordenado
          tanto por pirmera vez como luego de algun intercambio o swap*/
        Ocurrencia_De_Intercambio = false;

        /*El segundo for esta asociado con la iteracion de valores para buscar 2 valores
          para intercambiar o "swapear". Cada vez que un elemento queda completamente ordenado
          en su lugar, ya no es necesario compararlo con los elementos consecutivos ya que estos tambien
          estan ordenados y por lo tanto no es necesario recorrer todo el vector. Es por esto que
          el segundo for se ejecuta siempre que j < (largo-1-i).
          Si fuese (largo-1) entonces seguiria recorriendo elementos que ya estan ordenados y esto no es eficiente
           */
        for(j = 0; j < (largo-1-i); j++)
        {
            /*Pregunto si el valor en posicion actual j es mayor que el de la posicion siguiente j+1
                en tal caso, realizo un swap*/
            if(Array[j] > Array[j+1])//Como uso el ">" el ordenamiento es de menor a mayor
            {
                 /*Guardo el valor de la pos actual j en una variable aux*/
                 aux = Array[j];
                 /*Cpio el valor de la pos siguiente j+1 en el elemento de la pos actual j*/
                 Array[j] = Array[j+1];
                 /*Copio el valor de lo almacenado por aux en el elemento de la pos siguiente j+1*/
                 Array[j+1] = aux;
                 /*Al ejecutarse un intercambio, entonces seteo la variable indicada en true. Esto significa que
                 ocurrio un intercambio y que no es posible saber en esta instancia que el siguiente elemento
                 tambien este ordenado */
                 Ocurrencia_De_Intercambio = true;
            }
        }
        i++;
    }while(Ocurrencia_De_Intercambio == true);

    for( i = 0; i < largo; i ++ )
    {
        printf("Array [%d] = %d ",i,Array[i]);
    }
    printf("\n");

    return;
}
