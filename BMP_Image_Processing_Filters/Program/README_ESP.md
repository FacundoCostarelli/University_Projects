# Procesamiento de Imágenes BMP - Proyecto Integrado

**Descripción breve:**  
Este proyecto realiza el procesamiento de imágenes BMP, permitiendo la lectura, escritura y manipulación de archivos BMP. Utiliza un enfoque modular para facilitar la implementación de diversas funciones de procesamiento de imágenes.

**Descripción detallada:**
* Este programa utiliza un codigo main.c como fuente principal donde se llama a las diversas funciones y se las utiliza. 
* Este fuente a su vez, posee declaraciones de punteros que se utilizan en las diversas funciones. 
* También dicho archivo fuente contiene las instrucciones de uso de:
  - Comandos por argumento de main.
  - De la ejecución del archivo ejectuable.
  - De la imagen .bmp a procesar.
Dichas instrucciones, se presentan en pantalla durante la ejecución del programa. Debe leer atentamente los mensajes presentados al usuario.
* En términos mas detallados, el programa realiza la lectura obligatoria del archivo de entrada bmp a traves de una funcion que lee el header, tabla de colores(si existiese) y la data imagen. Ademas printea dicho header y tabla de colores(si existiese) en pantalla a traves de otra funcion y finalmente y más importante es que posee un menu recursivo con diferentes opciones de procesamiento de imagenes donde todos estos procesamientos son realizados a traves del llamado de diversas funciones.
El archivo .bmp de entrada puede ser del tipo:
- 1) Blanco y negro,
- 2) En escala de grises, osea en GrayshadeScale 
- 3) Color RGB
 
* En particular las diferentes opciones de procesamiento en funcionamiento son:
- A) Copiar_imagen 
     Aplicable para los tipos de imagenes 1),2),3) y para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits.
- B) Conversion_RGB_a_Grayscale 
     Aplicable para los tipos de imagenes 3) mientras que para 2) y 1) tambien es posible pero es no recomendable porque se adquiere un resultado distinto al buscado. Es aplicable para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits. Posee un unico algoritmo de conversion de colores a grises llamado "The Weighted Method". Este metodo tambien llamado "Metodo de luminosidad" consiste en "pesar" el color rojo, verde y azul de acuerdo a sus longitudes de onda "landa". 
     La formula es:
     Grayscale = 0.299R + 0.587G + 0.114B
  
- C) Conversion_Grayscale_a_BlancoyNegro 
     Aplicable para los tipos de imagenes 2) mientras que para 3) y 1) tambien es posile pero es no recomendable porque se adquiere un resultado distinto al buscado. Es aplicable para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits. Posee un solo algoritmo de conversion de grises a blanco y negro llamado "binarizacion" que consiste en convertir el valor entero de cada byte a 0 o 1. Se toma byte a byte de data de imagen tal que el valor entero propiamente dicho de ese byte valga 0 o 1 donde 0 equivale al negro binario y donde 1 equivale al blanco binario. Se usa ademas un valor entero de "Threshold" o tambien llamado "Umbral" tal que los valores enteros de bytes que superen dicho umbral se les asigne el valor de 1 y los valores que no superen el umbral se les asigne el valor de 0. En el codigo se usan 3 macros, BLANCO para 1, NEGRO para 0 y UMBRAL para un valor entero definido por el programador ej: 150. Al cambiar este valor, cambia que tan oscuro se ve el negro y que tan claro se ve el blanco en la imagen blanco y negro de salida.

- D) Rotacion_Imagen
     Aplicable para los tipos de imagenes 1),2) y 3). Es aplicable para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits. Posee un solo algoritmo de rotacion. La rotacion en un sentido u otro no es realizado en este programa a traves de la transformacion lineal sino a partir de asignar cada pixel del array "BufferCopiaLocalIn" de 2 dimensiones, en el array "BufferCopiaLocalOut" de 2 dimensiobes pero ubicando cada uno de ellos en las coordenadas "x e y" asociadas a los indexes "i e j" modificados matematicamente en los [] en el array BufferCopiaLocalOut de 2 dimensiones durante la asignacion. Dicho proceso de asignacion se ejecuta a traves de 2 ciclos for por cada case de rotacion debido a que los pixeles se encuentran ubicados en arreglos de 2 dimensiones.

- E) Deteccion de bordes lineal
    Aplicable para los tipos de imagenes 1),2) y 3). Es aplicable para tamanio de pixel de 2, 4, 8, 16, 24 y 32 bits. Realiza la deteccion de bordes a partir de una mascara, es decir, un array de 2 dimensiones de 3x3 con valores pre-cargados. Dicho algoritmo utiliza 4 ciclos for: 
    - El 1ero es para recorrer todas las filas.
    - El 2do para recorrer todas las columnas. 
    - El 3ero y el 4to que realizan cambio de valor en un pixel a otro valor y ademas se carga el nuevo valor del pixel en determinada posicion del buffer de salida de data imagen. Este algoritmo utiliza el operador de "gradientes" el cual computa las derivadas primeras en la imagen digital procesada.

* Todos estas operaciones de procesamiento de imagenes fueron testeadas con exito de forma exhaustiva para "tamanio de pixel o profundidad de bit" de 24 bits osea cada pixel compuesto por 3bytes. El tamanio de pixel lo llamo en el codigo "Tampunto". 

**Atención** 
En las funciones Lectura_Imagen y Copia_Imagen se usan files descriptors y por ende POSIX system calls (open, read, write, close, etc). En el resto de funciones se usan "streams" y por ende FILE pointers y las respectivas funciones para punteros a FILE(fopen, fread, fwrite, fclose, etc.). Estas son del standard C. La finalidad de esta mezcla fue usar distintas sintaxis y recursos para resolver diversos problemas asociados al manejo de archivos.

---

## Tabla de Contenidos

1. [Instalación](#instalación)
2. [Uso](#uso)
3. [Problemas Comunes](#problemas-comunes)
4. [Documentación](#documentación)
5. [Fuentes De Consulta](#fuentes-de-consulta)
6. [Contribución](#contribución)
7. [Licencia](#licencia)
8. [Autores](#autores)
9. [Reconocimientos Y Colaboraciones](#reconocimientos-y-colaboraciones)
10. [Algoritmos De Filtrado y otros](#algoritmos-de-filtrado-y-otros)

---

## Instalación
Para instalar el software y configurar el entorno, siga estos pasos:

1. Asegúrese de tener un compilador de C instalado.
2. Descargue el archivo `mainV1.c` y colóquelo en su directorio de trabajo.
3. Compile el archivo utilizando el comando:
   ```
   gcc mainV1.c -o procesador_bmp
   ```
4. Ejecute el programa con el archivo BMP como argumento:
   ```
   ./procesador_bmp imagen.bmp
   ```

## Uso
Una vez que el programa esté compilado, puede utilizarlo para procesar imágenes BMP. Simplemente proporcione el archivo BMP que desea procesar como argumento al ejecutar el programa y siga las instrucciones dadas en pantalla.
Puede observar el siguiente video donde se muestra como utilizar el programa y cual es el resultado. 

---

## Problemas Comunes
1. **Error de archivo no encontrado**: Asegúrese de que la ruta del archivo BMP sea correcta.
2. **Problemas de permisos**: Verifique que tenga permisos de lectura y escritura en el directorio donde está ejecutando el programa.
3. **Problemas de uso**: Siga los pasos indicados en pantalla, en caso de equivocarse en alguna opción o carga de datos por teclado, por favor cierre el programa y vuelva a comenzar.
4. **Problemas de filtros**: La aplicacipon de filtros a imagenes BMP en escala de colores incorrecta o en formato incorrecto puede resultar en efectos inesperados.

---

## Consideraciones Adicionales

### Reposicionamiento del offset del archivo de entrada
En la siguiente funcion, se realiza un reposicionamiento del offset del comienzo de lectura del archivo de entrada.
```c 
void Escritura_Imagen_HeaderYTablaColores(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
```
En principio al abrir el archivo, dicho offset esta ubicado en el byte 0 y a traves de "fseek" lo re-ubico en el nro de byte asociado al valor de "InicioImagen" almacenado dicho byte en la struct DatosBMP. Esto lo hago porque en algunas funciones como "Conversion_RGB_a_Grayscale" se requiere trabajar con puntero a FILE de archivo de entrada para manipular bytes de data de imagen y bytes de padding. Por lo que es necesario posicionar el offset del "stream" en la posicion adecuado dentro del bloque de informacion del archivo de entrada.
```c 
fseek(*ptr_in,(*p)->InicioImagen, SEEK_CUR );//Line 602 
```

## Algoritmos Implementados

### Algoritmo de Conversión RGB a Escala de Grises

**Explicación detallada:**
- Algoritmo que transforma cada pixel de color mezclado de RGB a un pixel de color de GrayshadeScale y que realiza proceso de "padding", es decir, relleno de bytes asociados al color negro al final de cada fila de bytes completada con informacion asociada a GrayshadeScale. 

- Para esto, se considera como ejemplo que cada pixel de color es de 24 bit, entonces, tiene 3 bytes y donde cada byte está asociado a un pequeño pixel de un color distinto RGB siendo 1er byte equivalente a "pixel rojo", 2do byte equivalente a "pixel verde", 3er byte equivalente a "pixel azul". Por lo que 3 pixeles pequeños de 8 bits cada uno, forman un pixel de color completo mezclado RGB de 24 bits. 

- Cada byte de 1 pixel de data de imagen, es tomado del archivo de entrada y almacenado en principio en un array "pixel" donde cada elemento entonces sera un byte asociado a un color RGB diferente. Luego a cada elemento del vector, es decir, a cada byte de cada color RGB lo multiplico por una constante siendo para el rojo el 0.3, para el verde el 0.59 y para el azul el 0.11. Luego sumo los resultados de dicha multiplicacion, lo que devuelve un valor que se almacena en una variable del tipo unsigned char llamada "gris".

- Despues, a traves de memset, se re-llena el array "pixel" por completo con todos bytes(3 en total) asociados sus valores al valor del byte "gris" el cual fue obtenido en la linea anterior. Como siguiente paso, se cargan esos bytes del array "pixel" ahora en el archivo de salida. 

- Todos estos pasos se repiten para cada pixel de cada columna de la fila de estudio del archivo de entrada. Al finalizar la carga de cada fila en el archivo de salida y justo antes de comenzar la carga de la siguiente fila, se realiza entonces, un proceso de padding, es decir, un proceso de rellenado de nuevos pixeles todos con mismo valor constante. 

- Dicho proceso se realiza a traves de leer del archivo de entrada, 1 item de data de imagen de tamanio igual al valor entero de padding y a partir de esto almacenar dicho item de data, en el array "pixel" para luego tomar lo que hay en ese array y almacenarlo en el archivo de salida justo a continuacion de la fila cargada. 

- Todo este procesidimiento se hace 1 vez por cada fila cargada para poder evitar recortes en la imagen y que al momento de aplicar filtros con mascaras se asegure que los valores de la mascara se "superpongan" todos en contacto con los distintos pixeles produciendo las modificaciones pertinentes y que por ende evitar asi que haya zonas de imagen donde los valores de las mascaras se superponen con la nada lo cual genera problemas.

**En resumen:**
- Este algoritmo convierte una imagen RGB a escala de grises utilizando el método de luminosidad. La fórmula utilizada es:
  ```
  Grayscale = 0.299R + 0.587G + 0.114B
  ```
- Esta fórmula pondera los componentes de color rojo, verde y azul de acuerdo con su contribución a la percepción de la luminosidad. El resultado es un valor que representa el brillo de cada píxel en la imagen en escala de grises.

- Vemos a continuación la función pertinente y la sección de código relacionada con el algoritmo utilizado.
```c
void Conversion_RGB_a_Grayscale(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision) 
{
    //....Codigo de declaración de variables y llamado a función para escritura de tabla de colores y header en archivo de salida.
    
    unsigned char pixel[3];
    for ( y = 0; y < (*p)->Altura; ++y)
    {
        for ( x = 0; x < (*p)->Ancho; ++x)
        {
            fread(pixel, 3, 1, *ptr_in);
            unsigned char gris = pixel[0] * 0.3 + pixel[1] * 0.58 + pixel[2] * 0.11;
            memset(pixel, gris, sizeof(pixel));
            fwrite(pixel, 3, 1, *ptr_out);
        }
        fread(pixel, padding, 1, *ptr_in);
        fwrite(pixel, padding, 1, *ptr_out);
    }

    //....Código de cierre de archivos.
}

```

### Agoritmo de Conversion Escala de Grises a Blanco y Negro

**Explicación detallada:**
- El algoritmo es llamado "binarizacion" y consiste en convertir el valor entero de cada byte a 0 o 1. Dicho byte es el que forma parte de un pixel. 

- Se toma byte a byte de data de imagen tal que el valor entero propiamente dicho de ese byte valga 0 o 1 donde 0 equivale al negro binario y donde 1 equivale al blanco binario. 

- Se usa ademas un valor entero de "Threshold" o tambien llamado "Umbral" tal que los valores enteros de bytes que superen dicho umbral se les asigne el valor de 1 y los valores que no superen el umbral se les asigne el valor de 0.

- En el codigo se usan 3 macros, BLANCO para 1, NEGRO para 0 y UMBRAL para un valor entero definido por el programador ej: 150. Al cambiar este valor, cambia que tan oscuro se ve el negro y que tan claro se ve el blanco en la imagen blanco y negro de salida.

**En resumen:**
- Algoritmo de "binarizacion" de pixeles en Grayshadescale. A traves de ciclo for, se evalua el valor entero de cada pixel, si el valor supera el valor de umbral entonces se le asigna el valor entero de 1 asociado al blanco. Caso contrario se le asigna el valor de entero 0, asociado al negro. Cada modificacion de valor de pixel se hace sobre pixeles almacenados en el bloque de memoria apuntado por "BufferCopiaLocal". 

- Luego, una vez modificado este bloque de memoria dinamico local, se escribe toda esta informacion en el archivo de salida con la funcion "frwite".

- Vemos a continuación la función pertinente y la sección de código relacionada con el algoritmo utilizado.
```c
void Conversion_Grayscale_a_BlancoyNegro(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
     //....Codigo de declaración de variables, llamado a función para escritura de tabla de colores y header en archivo de salida, protección contra null de malloc y lectura en memoria de la data imagen.

     for( i = 0; i < (*p)->TamImg; i++ )
     {
          BufferCopiaLocal[i] = (BufferCopiaLocal[i]>UMBRAL)?BLANCO : NEGRO;
     }

     //....Código de escrritura de data imagen modificada en archivo de salida, cierre de archivos y liberación de memoria dinámica.
}
```

### Algoritmo de Rotación

```c
```

### Algoritmo de Detección de Bordes
Este algoritmo utiliza una máscara de convolución para detectar bordes en la imagen. Se aplica un filtro que resalta las áreas donde hay cambios bruscos en la intensidad de los píxeles.

```c
void Deteccion_de_Bordes_lineal(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision, int Mascara[][3]) {
    // Código para la detección de bordes
    // Se recorre cada píxel de la imagen y se aplica la máscara de convolución.
    // Los píxeles que cumplen con el criterio de borde se marcan en el buffer de salida.
}
```
