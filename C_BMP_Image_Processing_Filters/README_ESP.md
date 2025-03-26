# Procesamiento de Imágenes BMP - Proyecto Integrado

**Descripción Breve:**  
Este proyecto realiza el procesamiento de imágenes BMP, permitiendo la lectura, escritura y manipulación de archivos BMP. Utiliza un enfoque modular para facilitar la implementación de diversas funciones de procesamiento de imágenes.
- [Youtube Presentación Procesamiento de Imágenes BMP ](.........)

---

## Tabla de Contenidos

1. [Descripción Detallada](#descripción-detallada)
2. [Instalación](#instalación)
3. [Uso](#uso)
4. [Problemas Comunes](#problemas-comunes)
5. [Algoritmos Implementados](#algoritmos-implementados)
6. [Consideraciones Adicionales](#consideraciones-adicionales)
7. [Documentación & Fuentes De Consulta](#documentación--fuentes-de-consulta)
8. [Contribución](#contribución)
9. [Licencia](#licencia)
10. [Autores](#autores)
11. [Reconocimientos Y Colaboraciones](#reconocimientos-y-colaboraciones)

---

## Descripción Detallada
* Este programa utiliza un código `main.c` como fuente principal, donde se llama a las diversas funciones y se las utiliza. 
* Este fuente a su vez, posee declaraciones de punteros que se utilizan en las diversas funciones. 
* También dicho archivo fuente contiene las instrucciones de uso de:
  - Comandos por argumento de `main`.
  - De la ejecución del archivo ejecutable.
  - De la imagen.bmp a procesar.
Dichas instrucciones, se presentan en pantalla durante la ejecución del programa. Debe leer atentamente los mensajes presentados al usuario.
* En términos mas detallados, el programa realiza la lectura obligatoria del archivo de entrada BMP a través de una función que lee el header, tabla de colores (si existiese) y la data imagen. Además, imprime dicho header y tabla de colores (si existiese) en pantalla a través de otra función y finalmente y más importante es que posee un menú recursivo con diferentes opciones de procesamiento de imágenes donde todos estos procesamientos son realizados a través del llamado de diversas funciones.
El archivo `.bmp` de entrada puede ser del tipo:
- 1) Blanco y negro,
- 2) En escala de grises, o sea en GrayshadeScale 
- 3) Color RGB
 
* En particular, las diferentes opciones de procesamiento en funcionamiento son:
- A) Copiar_imagen 
     Aplicable para los tipos de imágenes 1), 2), 3) y para tamaño de píxel de 2, 4, 8, 16, 24 y 32 bits.

- B) Conversión_RGB_a_Grayscale 
     Aplicable para los tipos de imágenes 3), mientras que para 2) y 1) también es posible, pero es no recomendable porque se adquiere un resultado distinto al buscado. Es aplicable para tamaño de pixel de 2, 4, 8, 16, 24 y 32 bits. Posee un único algoritmo de conversión de colores a grises llamado "The Weighted Method". Este método, también llamado "Metodo de luminosidad", consiste en "pesar" el color rojo, verde y azul de acuerdo a sus longitudes de onda "landa". 
     La fórmula es:
     `Grayscale = 0.299R + 0.587G + 0.114B`
  
- C) Conversión_Grayscale_a_BlancoyNegro 
     Aplicable para los tipos de imágenes 2), mientras que para 3) y 1) también es posible, pero no es recomendable porque se adquiere un resultado distinto al buscado. Es aplicable para tamaño de píxel de 2, 4, 8, 16, 24 y 32 bits. Posee un solo algoritmo de conversión de grises a blanco y negro llamado "binarización", que consiste en convertir el valor entero de cada byte a 0 o 1. Se toma byte a byte de data de imagen tal que el valor entero propiamente dicho de ese byte valga 0 o 1, donde 0 equivale al negro binario y donde 1 equivale al blanco binario. Se usa además un valor entero de "Threshold" o también llamado "umbral", tal que los valores enteros de bytes que superen dicho umbral se les asigne el valor de 1 y los valores que no superen el umbral se les asigne el valor de 0. En el código se usan 3 macros, BLANCO para 1, NEGRO para 0 y UMBRAL para un valor entero definido por el programador ej: 150. Al cambiar este valor, cambia qué tan oscuro se ve el negro y qué tan claro se ve el blanco en la imagen blanco y negro de salida.

- D) Rotación_Imagen
     Aplicable para los tipos de imágenes 1), 2) y 3). Es aplicable para tamaño de píxel de 2, 4, 8, 16, 24 y 32 bits. Posee un solo algoritmo de rotación. La rotación en un sentido u otro no es realizado en este programa a través de la transformación lineal, sino a partir de asignar cada píxel del array `BufferCopiaLocalIn` de 2 dimensiones, en el array `BufferCopiaLocalOut` de 2 dimensiones, pero ubicando cada uno de ellos en las coordenadas "x e y" asociadas a los indexes "i e j" que se van modificando según unas operaciones matemáticas durante la asignación de cada píxel en el array `BufferCopiaLocalOut` de 2D. Dicho proceso de asignación se ejecuta a través de 2 ciclos por por cada case de rotación debido a que los píxeles se encuentran ubicados en arreglos de 2 dimensiones.

- E) Detección_De_Bordes_Lineal
    Aplicable para los tipos de imágenes 1), 2) y 3). Es aplicable para tamaño de píxel de 2, 4, 8, 16, 24 y 32 bits. Realiza la detección de bordes a partir de una máscara, es decir, un array de 2 dimensiones de 3x3 con valores pre-cargados. Dicho algoritmo utiliza 4 ciclos por: 
    - El 1.º es para recorrer todas las filas.
    - El 2.º para recorrer todas las columnas. 
    - El 3.º y el 4.º que realizan cambio de valor en un píxel a otro valor, y además se carga el nuevo valor del píxel en determinada posición del buffer de salida de data imagen. Este algoritmo utiliza el operador de "gradientes", el cual computa las derivadas primeras en la imagen digital procesada.

* Todos estas operaciones de procesamiento de imagenes fueron testeadas con exito de forma exhaustiva para "tamanio de pixel o profundidad de bit" de 24 bits osea cada pixel compuesto por 3bytes. El tamanio de pixel lo llamo en el codigo `Tampunto`. 

**Atención:** 
En las funciones `Lectura_Imagen` y `Copia_Imagen` se usan files descriptors y por ende POSIX System Calls (`open`, `read`, `write`, `close`, etc). En el resto de funciones se usan "Streams" y por ende FILE pointers y las respectivas funciones para punteros a FILE(`fopen`, `fread`, `fwrite`, `fclose`, etc.). Estas son del Standard C. La finalidad de esta mezcla fue usar distintas sintaxis y recursos para resolver diversos problemas asociados al manejo de archivos.

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

---

## Uso
Una vez que el programa esté compilado, puede utilizarlo para procesar imágenes BMP. Simplemente, proporcione el archivo BMP que desea procesar como argumento al ejecutar el programa y siga las instrucciones dadas en pantalla. Puede observar la siguiente playlist de vídeos donde se muestra cómo utilizar el programa y cuál es el resultado para cada caso.
[Youtube Playlist Procesamiento de Imágenes BMP](.........)

---

## Problemas Comunes
1. **Error De Archivo No Encontrado**: Asegúrese de que la ruta del archivo BMP sea correcta.
2. **Problemas De Permisos**: Verifique que tenga permisos de lectura y escritura en el directorio donde está ejecutando el programa.
3. **Problemas De Uso**: Siga los pasos indicados en pantalla, en caso de equivocarse en alguna opción o carga de datos por teclado, por favor cierre el programa y vuelva a comenzar.
4. **Problemas De Filtros**: La aplicación de filtros a imágenes BMP en escala de colores incorrecta o en formato incorrecto puede resultar en efectos inesperados.

---

## Algoritmos Implementados

### Algoritmo De Copiado De Imagen

**Explicación Detallada:**
- Algoritmo que copia una imagen de entrada de forma tal que a la salida se tiene otra imagen con las mismas cualidades y características. Para esto, se abre un archivo de salida `copia.bmp` con permisos de lectura y escritura utilizando la función `open`. Si no existe previamente, se crea ese archivo de salida y se establecen los permisos de usuario para lectura y escritura.

- Previamente habiendo realizado una lectura en memoria de toda la información de la imagen tal que quede almacenada en un buffer local dinámico, se realiza ahora un copiado de toda la información en el archivo de salida ya creado.

- La copia comienza con la cabecera del archivo BMP desde la estructura `DatosBMP` hacia el archivo de salida utilizando la función `write`. La cabecera contiene información esencial sobre el archivo BMP, como el tipo de archivo, tamaño, y offset de inicio de la imagen.

- A continuación, se copia la tabla de colores (si existe). En concreto, si la profundidad de color dado por `TamPunto` es menor o igual a 8 bits, se copia la tabla de colores desde la estructura `Paleta_de_colores` hacia el archivo de salida utilizando la función `write`. La tabla de colores es necesaria para imágenes con una profundidad de color baja, ya que define los colores utilizados en la imagen.

- Después, se copia la data de la imagen desde el buffer temporal `BufferDataImagen` hacia el archivo de salida utilizando la función `write`. La cantidad de datos copiados debe ser igual al tamaño total del archivo menos el tamaño de la cabecera.

**En Resumen:**
- Este algoritmo copia una imagen tal que la copia es idéntica a la original. Para lograrlo, se abre o crea un archivo de salida indicando que es una copia. Luego, con una previa lectura de la información en un buffer local, se copia la información pertinente.

- El proceso del copiado consta en tomar el header, la tabla de colores (si existiese) y la data imagen en sí misma tal que toda esta información se escribe en el archivo de salida respetando el orden mencionado. 

- Vemos a continuación la función pertinente y la sección de código relacionada con el algoritmo utilizado.
```c
void Copia_Imagen( DatosBMP **p, Paleta_de_colores **p1, unsigned char **BufferDataImagen, int *fd_out )
{
     //....No código previo.
     *fd_out = open("copia.bmp", O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);

     write(*fd_out,*p,TamCabezera);
    
     if( (*p)->TamPunto <= 8 )
          write(*fd_out,*p1,TamTotalColores);
    
     write(*fd_out,*BufferDataImagen,( (*p)->TamARchivo ) - TamCabezera);

     //....Código de impresión de mensajes de ejecución exitosa de la función.
}
```
### Algoritmo De Conversión RGB A Escala de Grises

**Explicación Detallada:**
- Algoritmo que transforma cada píxel de color mezclado de RGB a un píxel de color de GrayshadeScale y que realiza proceso de "padding", es decir, relleno de bytes asociados al color negro al final de cada fila de bytes completada con información asociada a GrayshadeScale. 

- Para esto, se considera como ejemplo que cada píxel de color es de 24 bit, entonces, tiene 3 bytes y donde cada byte está asociado a un pequeño píxel de un color distinto RGB siendo 1.º byte equivalente a "píxel rojo", 2.º byte equivalente a "píxel verde", 3.º byte equivalente a "píxel azul". Por lo que 3 píxeles pequeños de 8 bits cada uno, forman un píxel de color completo mezclado RGB de 24 bits.

- Cada byte de 1 píxel de data de imagen, es tomado del archivo de entrada y almacenado en principio en un array "píxel" donde cada elemento entonces será un byte asociado a un color RGB diferente. Luego a cada elemento del vector, es decir, a cada byte de cada color RGB lo multiplico por una constante siendo para el rojo el 0.3, para el verde el 0.59 y para el azul el 0.11. Luego sumo los resultados de dicha multiplicación, lo que devuelve un valor que se almacena en una variable del tipo unsigned char llamada "gris".

- Después, a través de `memset`, se rellena el array "pixel" por completo con todos bytes (3 en total) asociados sus valores al valor del byte "gris", el cual fue obtenido en la línea anterior. Como siguiente paso, se cargan esos bytes del array "pixel" ahora en el archivo de salida.

- Todos estos pasos se repiten para cada píxel de cada columna de la fila de estudio del archivo de entrada. Al finalizar la carga de cada fila en el archivo de salida y justo antes de comenzar la carga de la siguiente fila, se realiza entonces, un proceso de padding, es decir, un proceso de rellenado de nuevos píxeles todos con mismo valor constante. 

- Dicho proceso se realiza a través de leer del archivo de entrada, 1 ítem de data de imagen de tamaño igual al valor entero de padding y a partir de esto almacenar dicho ítem de data, en el array "pixel" para luego tomar lo que hay en ese array y almacenarlo en el archivo de salida justo a continuación de la fila cargada. 

- Todo este procedimiento se hace 1 vez por cada fila cargada para poder evitar recortes en la imagen y que al momento de aplicar filtros con máscaras se asegure que los valores de la máscara se "superpongan" todos en contacto con los distintos píxeles, produciendo las modificaciones pertinentes y que, por ende, evitar así que haya zonas de imagen donde los valores de las máscaras se superponen con la nada, lo cual genera problemas.

**En Resumen:**
- Este algoritmo convierte una imagen RGB a Escala De Grises utilizando el método de "Luminosidad. La fórmula utilizada es:
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

    //....Código de cierre de archivos e impresión de mensajes de ejecución exitosa de la función.
}
```

### Agoritmo De Conversión Escala De Grises A Blanco y Negro

**Explicación Detallada:**
- Algoritmo que convierte una imagen en Escala de Grises a Blanco y Negro, este es llamado "binarización" y consiste en convertir el valor entero de cada byte a 0 o 1. Dicho byte es el que forma parte de un píxel donde a través de un ciclo `for`, se evalúa el valor entero de cada píxel. 

- En particular, se toma byte a byte de data de imagen tal que el valor entero propiamente dicho de ese byte valga 0 o 1 donde 0 equivale al negro binario y donde 1 equivale al blanco binario. Cada modificación de valor de píxel se hace sobre píxeles almacenados en el bloque de memoria apuntado por `BufferCopiaLocal`

- Se usa además un valor entero de "Threshold" o también llamado "Umbral", tal que los valores enteros de bytes que superen dicho umbral se les asigne el valor de 1 y los valores que no superen el umbral se les asigne el valor de 0.

- En el código se usan 3 macros, `BLANCO` para 1, `NEGRO` para 0 y `UMBRAL` para un valor entero definido por el programador ej: 150. Al cambiar este valor, cambia qué tan oscuro se ve el negro y qué tan claro se ve el blanco en la imagen blanco y negro de salida.

**En Resumen:**
- Este algoritmo convierte una imagen en Escala de Grises a Blanco y Negro utilizando el método de "Binarizacion". Esto consiste en convertir el valor entero de cada byte que conforma un píxel, a 0 (negro) o 1 (blanco). Se utiliza un valor de "Threshold" como referencia para saber cuándo asignar a un píxel el valor de 0 o 1.

- Luego, una vez modificado este bloque de memoria dinámico local, se escribe toda esta información en el archivo de salida con la función `frwite`.

- Vemos a continuación la función pertinente y la sección de código relacionada con el algoritmo utilizado.
```c
void Conversion_Grayscale_a_BlancoyNegro(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
     //....Codigo de declaración de variables, llamado a función para escritura de tabla de colores y header en archivo de salida, protección contra null de malloc y lectura en memoria de la data imagen.

     for( i = 0; i < (*p)->TamImg; i++ )
     {
          BufferCopiaLocal[i] = (BufferCopiaLocal[i]>UMBRAL)?BLANCO : NEGRO;
     }

     //....Código de escrritura de data imagen modificada en archivo de salida, cierre de archivos, liberación de memoria dinámica e impresión de mensajes de ejecución exitosa de la función.
}
```

### Algoritmo de Rotación

**Explicación Detallada:**
- El algoritmo se basa en un menú no recursivo de opciones de rotación de imagen. El algoritmo propiamente dicho de la rotación en un sentido u otro no lo hago a través de transformación lineal, sino a partir de asignar cada píxel del array `BufferCopiaLocalIn` de 2D en el array `BufferCopiaLocalOut` de 2D, pero ubicando cada uno de ellos en las coordenadas "x e y" asociadas a los indexes "y e j" que se van modificando según unas operaciones matemáticas durante la asignación de cada píxel en el array `BufferCopiaLocalOut` de 2D.

- Dicho proceso de asignación se ejecuta a través de 2 ciclos por por cada case de rotación debido a que los píxeles se encuentran ubicados en arreglos de 2D. Es importante destacar que la rotación solo funciona para imágenes cuya dimensión en alto y ancho es la misma que para la imagen de "Lena" de 512 x 512. Pero para la imagen de "Goldhill" de 720x576, entonces no funciona y así fuese de 576x720, tampoco funcionará. Resulta que la rotación solo funciona para imágenes cuadradas (mismo, alto y ancho).

- __*Rotación 90° a Izquierda:*__ Si armo una matriz de 2D, se puede ver que las filas de píxeles rotan en realidad hacia la derecha, pero en la imagen de salida el efecto visual es de rotación a la izquierda. Esto tiene que ver con el margen de referencia que se tome de la imagen original. En este caso, el margen de referencia a tomar sería el margen izquierdo de la imagen original, siguiendo la rotación a izquierda a nivel imagen, vemos que el margen izquierdo pasa a ser el margen inferior en la imagen de salida indicando que hubo una rotación de 90 grados a izquierda respecto de esta referencia. Sin embargo, a nivel matricial, el margen izquierdo de la matriz rota a derecha 90 pasando a ser margen superior en la matriz en términos matriciales.

- __*Rotación 90° a Derecha & Efecto Espejo:*__ Si armo una matriz de 2D, se puede ver que las filas de píxeles rotan en realidad hacia la izquierda, pero en la imagen de salida el efecto visual es de rotación a la derecha. Esto tiene que ver con el margen de referencia que se tome de la imagen original. En este caso, el margen de referencia a tomar sería el margen derecho de la imagen original, siguiendo la rotación con espejado a nivel imagen, vemos que el margen derecho primero se espera quedando en el lugar del margen izquierdo y luego rota hacia la derecha. Así, pasa a ser el margen superior de la imagen de salida, indicando que hubo una rotación de 90 grados a derecha con espejado respecto de esta referencia. Sin embargo, a nivel matricial, el margen derecho de la matriz rota a izquierda 90 y se espera pasando a ser margen inferior en la matriz.

- __*Rotación 180° & Inversión*__ Si armo una matriz de 2D, se puede ver que las filas superiores pasan a ocupar los lugares de las filas inferiores y viceversa, pero sin modificar las ubicaciones de las filas intermedias. En la imagen de salida se produce un efecto de inversión a 180 grados. Se puede pensar que en este caso a nivel imagen y a nivel 
matricial, se respeta la misma lógica en cuanto a la referencia a tomar, siendo dicha referencia por ejemplo en este caso el margen superior de la imagen y a nivel matricial también. Vemos que este margen superior pasa a ser el margen inferior y viceversa. Pero el centro de la imagen en términos de píxeles y de la matriz se mantiene sin modificaciones.

**En Resumen:**
- Este algoritmo realiza una rotación de una imagen cuadrada. Se utiliza un menú no recursivo para elegir los tipos de rotación. Mientras que para rotar la imagen, se asigna cada píxel del array `BufferCopiaLocalIn` de 2D en el array `BufferCopiaLocalOut` de 2D de acuerdo a un par de coordenadas "x e y".

- Al par de coordenadas se les va aplicando unas operaciones matemáticas durante el proceso de asignación de píxeles al array `BufferCopiaLocalOut` de 2D. 

- Las rotaciones pueden ser de 3 tipos: 90° a Izquierda, 90° a Derecha y 180° & Inversión. Durante la rotación a derecha surge además un efecto espejo. Además, las rotaciones a nivel matricial en código siguen una lógica invertida con respecto al efecto visual obtenido. Esto se entiende mejor al observar el margen de referencia tomado de la imagen de entrada respecto de la salida.

- Vemos a continuación la función pertinente y la sección de código relacionada con el algoritmo utilizado.
```c
void Rotacion_Imagen(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
     //....Codigo de declaración de variables, llamado a función para escritura de tabla de colores y header en archivo de salida, lectura en memoria de la data imagen y solicitud de opción de menú por teclado.

     switch(decisionrotacion)
     {
          case 1:  
               
               for( i = 0; i < (*p)->Ancho; i++)
               {
                    for( j = 0; j < (*p)->Altura; j++)
                    {
                         BufferCopiaLocalOut[j][(*p)->Altura-1-i] = BufferCopiaLocalIn[i][j];
                    }
               }
               
               break;

          case 2:  
               
               for( i = 0; i < (*p)->Ancho; i++)
               {
                    for( j = 0; j < (*p)->Altura; j++)
                    {
                         BufferCopiaLocalOut[j][i] = BufferCopiaLocalIn[i][j];
                    }
               }
               
               break;
          
          case 3: 
          
               for( i = 0; i < (*p)->Ancho; i++)
               {
                    for( j = 0; j < (*p)->Altura; j++)
                    {
                         BufferCopiaLocalOut[(*p)->Ancho-1-i][j] = BufferCopiaLocalIn[i][j];
                    }
               }
               
               break;

          case '\n' : case ' ': 
                    
               break;
               
          default: 
                    
                    printf("Se ingreso incorrectamente una opcion de rotacion\n");
                    printf("Ingrese devuelta una de las opciones: ");
                         
               break;
     }

     //....Código de escrritura de data imagen modificada en archivo de salida, cierre de archivos e impresión de mensajes de ejecución exitosa de la función.
}
```

### Algoritmo de Detección de Bordes Lineal

**Explicación Detallada:**
- Algoritmo que realiza la detección de bordes a partir de una máscara y operaciones de multiplicación, donde esta máscara es un array de 2D de 3x3 con valores pre-cargados. Se busca evaluar qué sucede con un "vecindario" de píxeles de 3x3 respecto a un píxel central.

- Dicho algoritmo utiliza 4 ciclos por:  
     * El 1.º y el 2.º es para recorrer todas las filas y las columnas en búsqueda de un píxel central tal que la posición de dicho píxel central de un vecindario esté dado por "BufferCopiaLocalOut+x+(long)y * ((*p)-> ancho)". 
     * Luego, el 3.º y el 4.º realizan una sumatoria de resultados dados por las operaciones de la línea 1128 
     tal que se obtiene un valor resultante de todas las operaciones de todos los píxeles de un "neighborhood" respecto al píxel central estudiado. 

- Dicho valor resultante del vecindario se evalúa al finalizar el 3.º y 4.º for. En la evaluación, se determina si el píxel central asumirá el valor de "encendido o blanco (255)" o el valor de "apagado o negro (0)". 

- Repitiendo esto sucesivamente para todos los píxeles de una imagen, se podrá tener entonces los "bordes" o delineados bien marcados en la imagen de salida. 

- Cabe aclarar que la imagen de estudio debe estar en escala de grises obligatoriamente.

**En Resumen:**
- Este algoritmo utiliza una máscara de convolución de 3x3 para detectar bordes en una imagen en escala de grises. Resulta entonces un filtro que resalta las áreas donde hay cambios bruscos en la intensidad de los píxeles.

- Se busca evaluar un "vecindario" de píxeles de 3x3 respecto de un píxel central. El procedimiento es repetitivo y consta de 4 ciclos for. El 1.º y 2.º recorren la matriz en búsqueda de un píxel central para crear el "vecindario" de estudio. El  3.º y 4.º realizan unas sumas matemáticas de valores de intensidad de píxeles del "vecindario". Según el resultado obtenido, el píxel central asume 255 (blanco) o 0 (negro).

- Vemos a continuación la función pertinente y la sección de código relacionada con el algoritmo utilizado.
```c
void Deteccion_de_Bordes_lineal(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision, int Mascara[][3]) 
{
     //....Codigo de declaración de variables, llamado a función para escritura de tabla de colores y header en archivo de salida, lectura en memoria de la data imagen.

     for(y = 1; y < (*p)->Altura-1; y++)
     {
          for(x = 1; x < (*p)->Ancho-1; x++)
          {
               sum = 0;
               for(i = -1; i <= 1; i++)
               {
                    for(j = -1; j <= 1; j++)
                    {
                         sum = sum + *(BufferCopiaLocalIn+x+i+(long)(y+j) * ((*p)->Ancho) ) * Mascara[i+1][j+1];
                    }
               }
               if(sum > 255) sum = 255;
               if(sum < 0) sum = 0;
               *(BufferCopiaLocalOut+x+(long)y * ((*p)->Ancho)) = sum;
          }
    }

    //....Código de escrritura de data imagen modificada en archivo de salida, cierre de archivos e impresión de mensajes de ejecución exitosa de la función.

}
```

---

## Consideraciones Adicionales

### Reposicionamiento del offset del archivo de entrada
En la siguiente función, se realiza un reposicionamiento del offset del comienzo de lectura del archivo de entrada.
```c 
void Escritura_Imagen_HeaderYTablaColores(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
```
En principio al abrir el archivo, dicho offset está ubicado en el byte 0 y a través de `fseek` lo re-ubico en el nro de byte asociado al valor de "InicioImagen" almacenado dicho byte en la struct `DatosBMP`. Esto lo hago porque en algunas funciones, como `Conversion_RGB_a_Grayscale`, se requiere trabajar con puntero a FILE de archivo de entrada para manipular bytes de data de imagen y bytes de "padding". Por lo que es necesario posicionar el offset del "stream" en la posición adecuado dentro del bloque de información del archivo de entrada.
```c 
fseek(*ptr_in,(*p)->InicioImagen, SEEK_CUR );//Line 603 
```

---

## Documentación & Fuentes De Consulta
Para mayor información y detalles se sugiere consultar los siguientes enlaces. También puede consultar la carpeta "Documents_And_Datasheets" dentro de la carpeta "BMP_Image_Processing_Filters" en el repositorio de "University_Proyects".

- Videos Y Apuntes De La Cátedra Informática I De Mariano Gonzalez.
- [C_Language_PDFs - ESP](https://github.com/FacundoCostarelli/University_Proyects/tree/master/BMP_Image_Processing_Filters/Documents_And_Reference_Sources/C_Language_PDFs/ESP)
- [Image_Processing_PDFs - ESP](https://github.com/FacundoCostarelli/University_Proyects/tree/master/BMP_Image_Processing_Filters/Documents_And_Reference_Sources/Image_Processing_PDFs/ESP)
- [Procesamiento De Imágenes En C - Segunda Edición - Dwayne Phillips](https://homepages.inf.ed.ac.uk/rbf/BOOKS/PHILLIPS/cips2ed.pdf)
- [BMP File Format](https://gibberlings3.github.io/iesdp/file_formats/ie_formats/bmp.htm)
- [RGB To Grayscale Image Using C - Explicación Y Código De Ejemplo](https://abhijitnathwani.github.io/blog/2018/01/08/rgbtogray-Image-using-C)
- [Fórmula De Conversión RGB A Grayscale](https://www.tutorialspoint.com/dip/grayscale_to_rgb_conversion)
- [Fórmula De Conversión RGB A Grayscale](https://www.dynamsoft.com/blog/insights/image-processing/image-processing-101-color-space-conversion/)
- [Solución Al Problema De Padding - Conversión RBG A Grayscale](https://stackoverflow.com/questions/54173733/convert-rgb-to-grayscale-in-bare-c)
- [Grayscale To Black And white Image Using C - Explicación Y Código De Ejemplo](https://abhijitnathwani.github.io/blog/2018/01/07/Black-and-White-Image-using-C)
- [Rotate Image Using C](https://abhijitnathwani.github.io/blog/2018/01/08/rotate-Image-using-C)
- [Rotate A Rectangular Image By 90 Degrees Clockwise](https://www.geeksforgeeks.org/turn-an-image-by-90-degree/)
- [Image Edge Detection Operators In Digital Image Processing](https://www.geeksforgeeks.org/image-edge-detection-operators-in-digital-image-processing/)
- [{ C } Digital Image Processing From Ground Up™](https://www.udemy.com/course/image-processing-from-ground-uptm-in-c/)
- [Casting to a File Pointer](https://stackoverflow.com/questions/16094936/casting-to-a-file-pointer)
- [How to dynamically allocate a 2D array in C](https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/)

**Atención:** 
En este proyectó utilizé principalmente los foros de Stack Overflow, GeeksForGeeks, blogs, videos en Youtube, archivos PDF con explicaciones teóricas y prácticas de códigos ejemplos similares y un curso en Udemy llamado [{C} Digital Image Processing From Ground Up™](https://www.udemy.com/course/image-processing-from-ground-uptm-in-c/). Es necesario mencionar que no fue permitido el uso de ninguna IA de ayuda y que todo el proyecto debía ser desarrollado en único archivo fuente `.c` junto a un único archivo `.h`. 

---

## Contribución

Toda colaboración es bienvenida. Sigue estos pasos para contribuir:

  1. Realiza un fork del repositorio.

  2. Crea una nueva rama para tu funcionalidad o corrección:
     - git checkout -b feature/nueva-caracteristica
  3. Realiza tus cambios y haz commit:
     - git commit -m "Descripción de los cambios realizados"
  4. Haz push a tu rama:
     - git push origin feature/nueva-caracteristica
  5. Crea un Pull Request describiendo tus cambios.

---

## Licencia
Este proyecto está licenciado bajo la Licencia Pública General GNU v3.0. Puedes usar, modificar y distribuir este proyecto respetando los términos de la licencia.

---

## Autores
- Facundo Costarelli

---

## Reconocimientos Y Colaboraciones
- Prof Ing Mariano Gonzalez               (Electrónica en UTN BA)
- Estudiante de Ing Francisco Germaniez   (Electrónica en UTN BA)

**Abreviaciones:**
- UTN BA --> Universidad Tecnológica Nacional de Buenos Aires.