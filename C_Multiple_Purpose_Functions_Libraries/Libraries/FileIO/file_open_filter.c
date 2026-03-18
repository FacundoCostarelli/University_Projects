/**
 * ==========================================================================
 * file_open_filter.c — File I/O, Struct Filtering & Linked List Patterns
 * ==========================================================================
 * [ESP] Colección de algoritmos/plantillas reutilizables para:
 *       - Manejo de señales para salir de loops (SIGINT)
 *       - Apertura de archivos binarios + lectura de estructuras en memoria
 *       - Filtrado de estructuras por campo con listas simplemente enlazadas
 *       - Implementación de PILA y COLA con listas simplemente enlazadas
 *       - Funciones de alocación, enlazamiento, impresión y liberación
 *
 * [ENG] Collection of reusable algorithm/template patterns for:
 *       - Signal handling to exit loops (SIGINT)
 *       - Binary file opening + reading structs into memory
 *       - Struct field filtering with singly linked lists
 *       - Stack and Queue implementation with singly linked lists
 *       - Allocation, linking, printing, and freeing functions
 *
 * Materia / Subject: Informática 1 — UTNBA (2022)
 * Autor / Author:    Facundo Costarelli
 * ==========================================================================
 */

/*ALGORITMO PARA TERMINAR EXITOSAMENE UN PROGRAMA EN LOOP CON SIGNAL DEL SHELL*/
    volatile sig_atomic_t stop;
    
    void
    inthand(int signum)
    {
        stop = 1;
    }
    signal(SIGINT, inthand);
        
        while (!stop)
            pause();
        printf("exiting safely\n");
/**********************FIN************************/
    


   /* ALGORITMO DE APERTURA ARCHIVO DE ENTRADA + ALOCACION DE MEMORIA DINAMICA
  + GUARDADO O LECUTRA EN MEMORIA DE ESTRUCTURAS DE FILE IN*/

    /*#include<stdio.h>*/
    /*#include<stdlib.h>*/
    /*#define ERROR <CTE_DE_ERROR>*/
    /*#define EXITO <CTE_DE_EXITO>*/
    FILE *File_in = NULL;
    int CantidadEstructuras_FileIn = 0;
    long tamanio_archivo = 0;
    int i = 0;
    /*<NOMBRE_DE_ESTRUCTURA>*/ *Buffer_Read_in = NULL;

    //Abro el archivo de entrada
    File_in = fopen(/*<PUNTERO_FILE_A_ARCHIVO_IN>*/,"r");
    if( File_in == NULL )
    {
        printf("Ocurrio un erorr en la apertura del archivo de entrada\n");
        return ERROR;
    }

    //Posiciono el "file position indicator" al final del archivo de entrada
    fseek(File_in,0,SEEK_END);
    //Averiguo el tamanio del archivo
    tamanio_archivo = ftell(File_in);
    //Averiguo la cantidad de estructuras del archivo de entrada
    CantidadEstructuras_FileIn =  ( (int)tamanio_archivo ) / ( (int)sizeof(/*<NOMBRE_DE_ESTRUCTURA>*/) );
    printf("La cantidad de estructuras tipo <NOMBRE_DE_ESTRUCTURA> son: %d\n", CantidadEstructuras_FileIn);
    //Posiciono el "file position indicator" al comienzo del arhcivo de entrada
    fseek(File_in,0,SEEK_SET);

    //Pido memoria dinamica para almacenar la info del archivo in en memoria
    Buffer_Read_in = (/*<NOMBRE_DE_ESTRUCTURA>*/ *)malloc( CantidadEstructuras_FileIn * sizeof(/*<NOMBRE_DE_ESTRUCTURA>*/));
    //Proteccion contra NULL de malloc
    if( Buffer_Read_in == NULL )
    {
        printf("Erropr en la asignacion de memoria dinamica para buffer de informacion read in\n");
        return ERROR;
    }

    //Leo del arhcivo de entrada las estructuras y las guardo en memoria
    if ( fread(Buffer_Read_in, CantidadEstructuras_FileIn * sizeof(/*<NOMBRE_DE_ESTRUCTURA>*/), 1, File_in) < 1 )
    {
        printf("Hubo un error con la lectura en memoria de las estructuras de entrada\n");
        return ERROR;
    }

    //Libero los recursos del buffer dinamico de estructuras provenientes del archivo de entrada
    free(Buffer_Read_in);
    //Cierro el archivo de entrada
    fclose(File_in);
/***********************FIN_DE_ALGORITMO*********************************************/


    /*ALGORITMO_DE_FILTRADO_DE_ALGUN_CAMPO_DE_ESTRCUTURAS*/

    //Evaluo cada estructura con su informacion la cual se encuentra en el buffer en memoria heap
    for( i = 0; i < CantidadEstructuras_FileIn; i++ )
    {
        printf("El campo de la estructura a comparar es: %TIPO_DE_DATO\n", Buffer_Read_in[i]./*<CAMPO_INTERNO_ESTRUCTURA>*/);

        //Habiendo logrado obtener exitosamente el campo de la estructura a comparar, entonces comparo con el campo o informacion propuesta de filtro

        if( /*<CAMPO_INTERNO_ESTRUCTURA>*/ == /*<CAMPO_A_FILTRAR>*/ )
        {
            //En caso de coincidir los campos internos de la estructura vs el campo de filtro, entonces creo y armo una
            //Lista simplemente enlazada que puede ser tipo:
            // - COLA, es decir, con formato FIFO
            // - PILA, es decir, con formato LIFO
            //Esto depende del algoritmo de enlazamiento
            if( Lista_Simplemente_Enlazada(/*<NOMBRE_DE_PUNTERO_DOBLE_A_INICIO_DE_LISTA>*/,Buffer_Read_in[i]/*(ESTRUCTURA_A_PASAR_POR_COPIA)*/) == EXITO )
                printf("Se creo crrectamente un nuevo nodo\n");
            else
            {
                printf("NO se creo correctamente un nodo;\n");
                return ERROR;
            }
        }
        
    }

/***********************FIN_DE_ALGORITMO*********************************************/


    /*LISTA SIMPLEMENTE ENLAZADA, ALLOCALIZAR NODO,
     *ENLAZAMIENTO AL PRINCIPIO(PILA), ENLAZAMIENTO AL FINAL(COLA)
     *IMPRIMIR LISTA, LIBERAR LISTA
    */

    //Funcion generica que crea,cargar y enlaza un nodo donde alguno de los campos internos es una variable asociada a una estructura
    //y NO un puntero a estructura. Esta funcion esta pensada para poder utilizar
    //un nodo cuya "struct" es presentada de la siguiente manera

    typedef struct nodo
    {
        /*<NOMBRE_ESTRUCTURA_DATO>*/ data;
        /*<NOMBRE_NODO>*/ *sig;
    }/*<NOMBRE_NODO>*/;

    typedef struct dato
    {
        /*CAMPOS_INTERNOS*/
        /********/

    }/*<NOMBRE_ESTRUCTURA_DATO>*/:


    int Lista_Simplemente_Enlazada_PILA(/*<NOMBRE_NODO>*/ **ptr1erElemento,/*<NOMBRE_ESTRUCTURA_DATO>*/ data)
    {
        /*<NOMBRE_NODO>*/ *Nuevo_Nodo = NULL;

        //Verifico si la lista esta vacia y en tal caso creo, cargo y agrego el 1er nodo de la lista
        if(*ptr1erElemento == NULL)
        {
            printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");

            //Llamo a funcion que crea dinamicamente un nuevo nodo
            if ( Allocalizar_Nuevo_Nodo(&Nuevo_Nodo) == ERROR )
                return ERROR;

            //Cargar 1er nodo
            Nuevo_Nodo->data = data;
            //Enlazamiento del 1er nodo
            Nuevo_Nodo->sig = NULL;

            //Retorno, por referencia, del puntero al nuevo nodo creado
            *ptr1erElemento = Nuevo_Nodo;
        }
        else
        {
            //Si la lista no esta vacia, entonces creo un nuevo nodo, lo cargo y lo enlazo a la lista actual
            //Por ser pila es con enlazamiento al principio

            /*ENLAZAMIENTO AL PRINCIPIO(PILA)*/
            if( Enlazar_Al_Principio_Y_Cargar(ptr1erElemento,data,&Nuevo_Nodo) == ERROR )
                return ERROR;
        }

        return EXITO;
    }
    
    int Lista_Simplemente_Enlazada_COLA(/*<NOMBRE_NODO>*/ **ptr1erElemento,/*<NOMBRE_NODO>*/ **ptrAux,/*<NOMBRE_ESTRUCTURA_DATO>*/ data){	
    /*<NOMBRE_NODO>*/ *Nuevo_Nodo = NULL;

    //Verifico si la lista esta vacia y en tal caso creo, cargo y agrego el 1er nodo de la lista
    if(*ptr1erElemento == NULL)
    {
        printf("La lista se encuentra vacia\nSe creara el 1er nodo\n");

        //Llamo a funcion que crea dinamicamente un nuevo nodo
        if ( Allocalizar_Nuevo_Nodo(&Nuevo_Nodo) == ERROR )
            return ERROR;

        //Cargar 1er nodo
        Nuevo_Nodo->data = data;
        //Enlazamiento del 1er nodo
        Nuevo_Nodo->sig = NULL;

        //Retorno, por referencia, del puntero al nuevo nodo creado
        *ptr1erElemento = Nuevo_Nodo;
        //Hago que un puntero auxiliar comienze apuntando al nodo nuevo creado por 1era vez
        *ptrAux = Nuevo_Nodo;

    }
    else
    {
        if ( Enlazar_Al_Final_Y_Cargar(ptr1erElemento,ptrAux,data,&Nuevo_Nodo) == ERROR )
            return ERROR;
    }

    return EXITO;
}

    //Funcion que allocaliza dinamicamente un nuevo nodo.
    //Retorna ERROR en caso de error y EXITO en caso de exito
    int Allocalizar_Nuevo_Nodo( /*<NOMBRE_NODO>*/ **Nuevo_Nodo)
    {
        //Allocacion de memoria dinamica para un nuevo nodo y verificacion de error de malloc
        *Nuevo_Nodo = (/*<NOMBRE_NODO>*/ *)malloc(sizeof(/*<NOMBRE_NODO>*/));
        if(*Nuevo_Nodo == NULL)
        {
            printf("Hubo un error con la creacion y asignacion de memoria dinamica para un nuevo nodo\n");
            return ERROR;
        }
        else
            printf("Se creo exitosamente y dinamicamente un nuevo nodo\n");

        return EXITO;
    }

    //Funcion que elaza al principio y carga el nodo.
    //ESTO ES FORMATO PILA para una LISTA_SL
    int Enlazar_Al_Principio_Y_Cargar(/*<NOMBRE_NODO>*/ **ptr1erElemento,/*<NOMBRE_ESTRUCTURA_DATO>*/ data,/*<NOMBRE_NODO>*/ **Nuevo_Nodo)
    {
        printf("Se creara, cargara y agregara un nuevo nodo al principio de la lista\n");

        //Llamo a funcion que crea dinamicamente un nuevo nodo
        if( Allocalizar_Nuevo_Nodo(Nuevo_Nodo) == ERROR )
            return ERROR;

        //No busco ultimo nodo del final de lista ya que solo necesito el nodo inicial de la lista

        //Enlazo nodo al princpio de la lista
        (*Nuevo_Nodo)->sig = *ptr1erElemento;
        //Cargo el nuevo nodo
        (*Nuevo_Nodo)->data = data;
        //Retorno, por referencia, del puntero al nuevo nodo creado
        *ptr1erElemento= *Nuevo_Nodo;

        return EXITO;
    }

//Funcion que elaza al final y carga el nodo.
//ESTO ES FORMATO COLA para una LISTA_SL
int Enlazar_Al_Final_Y_Cargar(/*<NOMBRE_NODO>*/ **ptr1erElemento,/*<NOMBRE_NODO>*/ **ptrAux,/*<NOMBRE_ESTRUCTURA_DATO>*/ data,/*<NOMBRE_NODO>*/**Nuevo_Nodo)
{

    printf("Se creara, cargara y agregara un nuevo nodo al final de la lista\n");

    //Llamo a funcion que crea dinamicamente un nuevo nodo
    if( Allocalizar_Nuevo_Nodo(Nuevo_Nodo) == ERROR )
        return ERROR;

    //No busco ultimo nodo del final de lista ya que solo necesito el nodo inicial de la lista
    //Enlazo nodo al final de la lista

    //Pregunto si el puntero sig del 1er nodo apunta a NULL. En tal caso enlazo al final respecto del 1er nodo y cargo el nuevo nodo
    if ( (*ptr1erElemento)->sig == NULL )
    {
        (*ptr1erElemento)->sig = *Nuevo_Nodo;
        *ptrAux = *Nuevo_Nodo;
        (*Nuevo_Nodo)->sig = NULL;
        //Cargo el nuevo nodo
        (*Nuevo_Nodo)->data = data;
    }
    //Si el puntero sig del 1er nodo NO apunta a NULL, significa que ya tenemos al menos 2 nodos. En tal caso enlazo al final desde el ultimo nodo
    else
    {
        (*ptrAux)->sig = *Nuevo_Nodo;
        *ptrAux = *Nuevo_Nodo;
        (*Nuevo_Nodo)->sig = NULL;
        //Cargo el nuevo nodo
        (*Nuevo_Nodo)->data = data;
    }
    return EXITO;
}
    

    void Liberar_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(/*<NOMBRE_NODO>*/ **ptr1erElemento)
    {
        /*<NOMBRE_NODO>*/ *Nodo_Actual = *ptr1erElemento;

        while(*ptr1erElemento != NULL)
        {
            *ptr1erElemento = Nodo_Actual->sig;
            free(Nodo_Actual);
            Nodo_Actual = *ptr1erElemento;
        }

        return;
    }

    //Funcion que imprime la informacion de cada nodo de una lista simplemente enlazada siempre y cuando cada nodo tenga una variable del tipo "struct" con sus respectivos campos
    void Imprimir_Lista_Simplemente_Enlazada_TIPO_PILA_O_COLA(/*<NOMBRE_NODO>*/ **ptr1erElemento)
    {
        /*<NOMBRE_NODO>*/ *Nodo_Actual = *ptr1erElemento;
        //Se imprime comenzando por el PRINCIPIO de la COLA hasta el FINAL de la misma.
        //Deberia ser al reves pero se necesita una COLA DOBLEMENTE ENLAZADA
        while(Nodo_Actual != NULL)
        {
            printf("CAMPO 1: %TIPO_DE_DATO\n", Nodo_Actual->data.campo1);
            printf("CAMPO 2: %TIPO_DE_DATO\n", Nodo_Actual->data.campo2);
            printf("CAMPO 3: %TIPO_DE_DATO\n", Nodo_Actual->data.campo3);
            Nodo_Actual = Nodo_Actual->sig;
        }

        return;
    }


