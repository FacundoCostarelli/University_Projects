# Sistema de Codificación y Decodificación DTMF en MATLAB

**Descripción Breve:** Desarrollo de un sistema de software en MATLAB para la generación y detección de señales DTMF (Dual-Tone Multi-Frequency).
Este proyecto implementa un codificador que genera señales de audio correspondientes a los dígitos telefónicos (0-9) y un decodificador basado en un banco de filtros FIR de ventana Kaiser para identificar las frecuencias presentes y reconstruir el número marcado.
- [Youtube Presentación DTMF PT1](LINK_A_TU_VIDEO_AQUI)
- [Youtube Presentación DTMF PT2](LINK_A_TU_VIDEO_AQUI)

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
Se presenta una guía escrita de cómo preparar el entorno de MATLAB para la ejecución de los scripts de simulación y procesamiento digital de señales.

**Requisitos Previos:**
- PC con Windows, Linux o MacOS.
- Software necesario:
  - [MATLAB](https://www.mathworks.com/products/matlab.html) (Versión R2016a o superior recomendada).
  - [Signal Processing Toolbox](https://www.mathworks.com/products/signal.html) (Esencial para las funciones `fir1` y `kaiserord`).

**Pasos De Instalación:**
1. Clonar el repositorio o descargar los archivos:
   ```bash
   git clone [https://github.com/FacundoCostarelli/TU_REPO_DTMF](https://github.com/FacundoCostarelli/TU_REPO_DTMF)

2. Configurar el entorno en MATLAB:
    - Abrir MATLAB.
    - Navegar hasta la carpeta donde se descargaron los archivos .m (deben estar todos en el mismo directorio: tp2.m, rowX.m, colX.m, make_signal_dtmf.m, etc.).
    - Hacer clic derecho en la carpeta en el navegador de archivos de MATLAB y seleccionar "Add to Path" > "Selected Folders". Esto asegura que MATLAB encuentre las funciones de los filtros y scripts auxiliares.

---

## Uso
Una vez descargados los archivos y configurado el path, se puede probar el sistema completo utilizando el script de prueba principal.

**Pasos De Uso:**
- Abrir el archivo tp2.m en el editor de MATLAB.
- Dar click en botón de play o run para correr el proyecto o presionar F5. Solo debe hacerlo desde el archivo "tp2.m" .

**Características del Script tp2.m**
- Este script realiza automáticamente lo siguiente:
- Define una frecuencia de muestreo (fs = 8000 Hz).
- Itera sobre los dígitos del 0 al 9.
- Codificación: Llama a make_signal_dtmf para generar el audio sumando los cosenos de las frecuencias correspondientes.
- Reproducción: Reproduce el sonido generado (asegúrate de tener el volumen activado).
- Decodificación: Llama a get_number_from_dtmf. Esta función pasa la señal por un banco de 7 filtros pasa-banda (diseñados con ventana Kaiser) y determina qué tecla fue presionada basándose en la relación de energía de entrada/salida.
- Muestra el resultado detectado en la ventana de comandos (Command Window).

**Funciones Principales**
* **`make_signal_dtmf(n, fs, d)`**: Genera la señal temporal DTMF.
* **`get_number_from_dtmf(x, fs)`**: Detecta el dígito analizando la energía tras filtrar la señal.
* **`rowX(fs) y colX(fs)`**: Funciones que generan los objetos de filtro FIR específicos para cada frecuencia estándar DTMF.

## Problemas Comunes
1. Error en el diseño de filtros (NaNs):
    - Descripción: Al ejecutar, aparece el error "NaN's cannot be converted to logicals" en kaiserord.
    - Solución: Esto suele ocurrir por un error de tipeo en los vectores de frecuencia. Verificar el archivo row4.m. Asegurarse de que el vector de frecuencias sea [Fstop1 Fpass1 Fpass2 Fstop2] y no se repita Fpass2 al final.

2. El dígito detectado no coincide:
    - Descripción: El sistema detecta un número erróneo o devuelve 0.
    - Solución: Revisar el umbral de energía en get_number_from_dtmf.m. Actualmente está configurado en Ey/Ex >= 0.45. Si la señal tiene mucho ruido, este umbral debe ajustarse.

3. Audio no se escucha o se escucha cortado:
    - Descripción: La función playblocking falla o el audio es muy breve.
    - Solución: Verificar que la variable d (duración) en tp2.m sea suficiente (ej. 2 segundos) y que la frecuencia de muestreo fs sea compatible con la tarjeta de audio (8000 Hz es estándar).

---

## Documentación
Para mayor información y detalles sobre los estándares y métodos utilizados:
- [ITU-T Recommendation Q.23 - Especificaciones técnicas de las frecuencias DTMF](https://www.itu.int/rec/T-REC-Q.23/en).
- [Diseño de Filtros FIR en MATLAB - Documentación sobre fir1](https://www.mathworks.com/help/signal/ug/fir-filter-design.html).
- [Ventana Kaiser - Detalles sobre la estimación de parámetros para filtros con ventana Kaiser](https://www.mathworks.com/help/signal/ref/kaiserord.html).

---

## Fuentes De Consulta
- Documentación oficial de MathWorks (MATLAB).
- Apuntes de la Cátedra de Análisis de Señales y Sistemas de Procesamiento de Señales.
- [Foros De StackOverflow - Consultas sobre errores de sintaxis en MATLAB](https://stackoverflow.com/questions).

---

## Contribución
Toda colaboración es bienvenida. Sigue estos pasos para contribuir:

  1. Realiza un fork del repositorio.
  2. Crea una nueva rama para tu mejora (ej. optimización de filtros o interfaz gráfica):
     - git checkout -b feature/nueva-mejora
  3. Realiza tus cambios y haz commit:
     - git commit -m "Mejora en la detección de energía"
  4. Haz push a tu rama:
     - git push origin feature/nueva-mejora
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
- Cátedra de Procesamiento Digital de Señales - Universidad Tecnológica Nacional (UTN BA).

---

## Abreviaciones:
- DTMF --> Dual-Tone Multi-Frequency.
- FIR --> Finite Impulse Response (Filtro de Respuesta al Impulso Finita).
- FS --> Frecuencia de Muestreo (Sampling Frequency).