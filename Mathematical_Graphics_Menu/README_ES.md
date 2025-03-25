# Menú de Gráficas Matemáticas - Proyecto Integrado

**Descripción Breve:**  
Este proyecto permite al usuario graficar diferentes funciones matemáticas, incluyendo rectas, cuadráticas, polinomios, hipérbolas, módulos, logaritmos naturales con series de Taylor, seno, coseno y tangente con series de Maclaurin. Es posible calcular múltiples puntos, definir los coeficientes y cantidad de términos por entrada de comandos de main. El programa genera archivos de salida con los datos y comandos necesarios para graficar en Octave. Podremos graficar diversas funciones en una misma ventana particionada como matriz de hasta 9 subventanas. 

En la siguiente playlist encontrarás todo lo necesario para poder ejecutar este proyecto y una demostración del funcionamiento del mismo.
[Youtube GraphicsMenu Playlist](.....)

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

---

## Instalación
Para instalar y ejecutar este proyecto, siga los siguientes pasos:

**Requisitos Previos:**
- Sistema operativo Linux o WSL(Windows Subsystem for Linux) ya que el proyecto utiliza la biblioteca `stdio_ext.h` específica de Linux.
- Octave instalado para visualizar las gráficas generadas.

**Pasos De Instalación:**
1. Clonar el repositorio:
    git clone
2. Navegar al directorio del proyecto:
    cd 
3. Compilar el archivo `GraphicsMenu.c`:
    Forma 1:
     - gcc GraphicsMenu.c -o GraphicsMenu -lm
    Forma 2:
     - gcc -c GraphicsMenu.c -o GraphicsMenu.o
     - gcc    GraphicsMenu.o -o GraphicsMenu -lm

---

## Uso
Una vez completada la instalación, siga estos pasos para usar el programa:

1. Ejecutar el programa:
    ./GraphicsMenu
2. Seguir las instrucciones en pantalla para ingresar los datos necesarios para las gráficas.
3. El programa generará archivos `.m` que pueden ser ejecutados en Octave para visualizar las gráficas.

---

## Problemas Comunes
1. **Problemas De Compilación En Sistemas No Linux:**
   - Descripción: El archivo `stdio_ext.h` es específico de Linux.
   - Solución: Utilizar un sistema operativo Linux o WSL para compilar y ejecutar el programa.

2. **Errores Al Ingresar El Nombre Del Archivo De Salida:**
   - Descripción: Si el nombre del archivo excede los 50 caracteres, puede causar errores.
   - Solución: Asegurarse de que el nombre del archivo no exceda los 50 caracteres.

3. **Problemas Al Graficar En Octave:**
   - Descripción: Octave puede no graficar inmediatamente la cuadrática con su recta tangente.
   - Solución: Hacer clic en la ventana de Octave o minimizar y maximizar la ventana para forzar la actualización de la gráfica.

4. **Problemas Con La Gráfica De La Tangente:**
   - Descripción: La forma de la gráfica de la tangente depende de varios factores:
     - Si comienza la gráfica en -89 a 89 grados.
     - La cantidad de términos donde una cantidad muy grande pasados de los 30, arroja "nan" en algunos valores del vector de puntos.
     - La cantidad de puntos que en general con un 10<=n<=20 debería funcionar sin problema y con una cantidad de puntos de entre 10 a 20.
   - Solución: Ajustar los parámetros de la gráfica según sea necesario.
   
---

## Documentación
Para más detalles sobre el proyecto, consulte los siguientes documentos:

---

## Fuentes De Consulta
- [Foros de StackOverflow](https://stackoverflow.com/)
- [Documentación de Octave](https://www.gnu.org/software/octave/doc/interpreter/)

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
Este proyecto está licenciado bajo la Licencia Pública General GNU v3.0. 
Puedes usar, modificar y distribuir este proyecto respetando los términos de la licencia.

---

## Autores
- Facundo Costarelli

---

## Reconocimientos Y Colaboraciones
- Prof Ing Mariano Gonzalez                     (Electrónica en UTN BA)
- Estudiante de Ing Francisco Germaniez			(Electrónica en UTN BA)

**Abreviaciones:**
- UTN BA --> Universidad Tecnológica Nacional de Buenos Aires.