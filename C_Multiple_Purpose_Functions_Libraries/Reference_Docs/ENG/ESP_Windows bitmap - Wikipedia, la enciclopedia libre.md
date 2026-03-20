# Original Text - Windows bitmap - Wikipedia, la enciclopedia libre.pdf

Windows bitmap
DesarrolladorMicrosoft en 1986
Información generalExtensión dearchivo.bmp o .dibTipo de MIMEimage/x-ms-bmp (no
oficial)Uniform TypeIdentifiercom.microsoft.bmpNúmero mágicoBMTipo deformatoGráfico rasterizadoFormatoabierto?Windows bitmapWindows bitmap (.BMP) es un formato
del ITSL imagen de mapa de bits,  propio
del sistema operativo Microsoft Windows.
Puede guardar imágenes de 24 bits (16,7
millones de colores), 8 bits (256 tonos de
gris) y menos. Puede darse a estos archivos
una compresión sin pérdida de calidad: la
compresión RLE (Run-length encoding).
Los  archivos  de  mapas  de  bits  se
componen  de  direcciones  asociadas  a
códigos de color, uno para cada cuadro en
una  matriz  de  píxeles  tal  como  se
esquematizaría un dibujo  de "colorea los
cuadros"  para  niños  pequeños.
Normalmente, se caracterizan por ser muy
poco  eficientes  en  su  uso  de  espacio  en
disco, pero pueden mostrar un buen nivel
de  calidad.  A  diferencia  de  los  gráficos
vectoriales al ser rescalados a un tamaño
mayor, pierden calidad. Los archivos BMP
no  son  utilizados  en  páginas  web  debido  a  su  gran  tamaño  en  relación  a  su
resolución.
Dependiendo de la profundidad de color que tenga la imagen cada píxel puede
ocupar 1 o varios bytes. Generalmente se suelen transformar en otros formatos,
como JPEG (fotografías), GIF (animaciones) o PNG (dibujos y esquemas), los cuales
utilizan otros algoritmos para conseguir una mayor compresión (menor tamaño delarchivo).
Los archivos comienzan (cabecera o header) con las letras BM (0x42 0x4D), que lo
identifica con el programa de visualización o edición. En la cabecera también se
indica el tamaño de la imagen y con cuántos bytes se representa el color de cada
píxel.
Los bytes están organizados usando el sistema little-endian.
A continuación se detalla la estructura de la cabecera de un fichero .BMPWindows bitmap - Wikipedia, la enciclopedia libre https://es.wikipedia.org/wiki/Windows_bitmap
1 of 2 8/14/22, 23:26
Bytes Información
0, 1 Tipo de fichero "BM"
2, 3, 4, 5 T amaño del archivo
6, 7 Reservado
8, 9 Reservado
10,  11,  12,
13Inicio  de  los  datos  de  la
imagen
14,  15,  16,
17T amaño  de  la  cabecera  del
bitmap
18,  19,  20,
21Anchura (píxels)
22,  23,  24,
25Altura (píxels)
26, 27 Número de planos
28, 29 T amaño de cada punto
30,  31,  32,
33Compresión  (0=no
comprimido)
34,  35,  36,
37T amaño de la imagen
38,  39,  40,
41Resolución horizontal
42,  43,  44,
45Resolución vertical
46,  47,  48,
49T amaño de la tabla de color
50,  51,  52,
53Contador  de  colores
importantes
El mapa de bits de una imagen .BMP comienza a leerse de abajo arriba, es decir: en
una imagen en 24 bits los primeros 3 bytes corresponden al primer píxel inferior
izquierdo.
Obtenido de «https://es.wikipedia.org/w/index.php?title=Windows_bitmap&oldid=141594917»
Esta página se editó por última vez el 10 feb 2022 a las 23:52.
El texto está disponible bajo la Licencia Creative Commons Atribución Compartir Igual 3.0; pueden
aplicarse cláusulas adicionales. Al usar este sitio, usted acepta nuestros términos de uso y nuestra
política de privacidad.
Wikipedia® es una marca registrada de la Fundación Wikimedia, Inc., una organización sin ánimo de
lucro.Windows bitmap - Wikipedia, la enciclopedia libre https://es.wikipedia.org/wiki/Windows_bitmap
2 of 2 8/14/22, 23:26
