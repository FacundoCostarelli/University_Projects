# Análisis de Señales y Sistemas en MATLAB

**Descripción Breve:** Este repositorio contiene una colección integral de scripts y funciones en MATLAB desarrollados para la asignatura de Análisis de Señales y Sistemas. El proyecto aborda desde los fundamentos matemáticos (números complejos y matrices) hasta el modelado avanzado de sistemas físicos (circuitos RLC), pasando por el análisis temporal de señales (convolución).

- [Youtube Presentación Parte A](LINK_A_TU_VIDEO_AQUI)
- [Youtube Presentación Parte B](LINK_A_TU_VIDEO_AQUI)
- [Youtube Presentación Parte C](LINK_A_TU_VIDEO_AQUI)

---

## Tabla de Contenidos

1. [Instalación](#instalación)
2. [Estructura del Proyecto](#estructura-del-proyecto)
   - [Parte A: Fundamentos](#parte-a-fundamentos-matemáticos-y-algoritmos-básicos)
   - [Parte B: Análisis Temporal](#parte-b-análisis-temporal-de-señales-y-sistemas)
   - [Parte C: Modelado de Circuitos](#parte-c-modelado-y-simulación-de-sistemas-físicos)
3. [Problemas Comunes](#problemas-comunes)
4. [Documentación](#documentación)
5. [Fuentes De Consulta](#fuentes-de-consulta)
6. [Contribución](#contribución)
7. [Licencia](#licencia)
8. [Autores](#autores)
9. [Reconocimientos](#reconocimientos-y-colaboraciones)

---

## Instalación
Guía para preparar el entorno de MATLAB y ejecutar las simulaciones.

**Requisitos Previos:**
- PC con Windows, Linux o MacOS.
- **MATLAB** (Versión R2016a o superior recomendada).
- **Signal Processing Toolbox** (Recomendado para funciones avanzadas de filtrado).

**Pasos De Instalación:**
1. Clonar el repositorio o descargar los archivos:
   ```bash
   git clone [https://github.com/TU_USUARIO/TU_REPO_SENALES.git](https://github.com/TU_USUARIO/TU_REPO_SENALES.git)

2. Configurar el entorno en MATLAB:
    - Abrir MATLAB.
    - Navegar hasta la carpeta del proyecto.
    - Hacer clic derecho en la carpeta en el navegador de archivos y seleccionar "Add to Path" > "Selected Folders and Subfolders". Esto es crucial para que MATLAB encuentre las funciones auxiliares (ramp.m, esc.m, etc.) desde cualquier script.

---

## Estructura del Proyecto

El desarrollo se divide en tres módulos principales. A continuación se detalla la función de cada script y archivo auxiliar.

### Parte A: Fundamentos Matemáticos y Algoritmos Básicos

Esta sección establece las bases del cálculo numérico, abarcando números complejos, álgebra matricial y aproximaciones por series.

**Scripts Principales:**
* **`script_a1.m`**: Operaciones fundamentales con números complejos (suma, producto, módulo, fase, conjugado) y su visualización fasorial.
* **`script_a2.m`**: Álgebra matricial avanzada; incluye multiplicación, cálculo de determinantes, inversas y operaciones elemento a elemento.
* **`script_a3.m`**: Generación de polinomios con coeficientes aleatorios y cálculo de sus raíces mediante la función nativa `roots`.
* **`script_a4.m`**: Script de prueba para visualizar las raíces n-ésimas de un número complejo en el plano Z (círculo unitario).
* **`script_a5.m`**: Implementación lógica de la aproximación del número de Euler ($e$) mediante series de Taylor sin bucles explícitos (vectorizado).
* **`script_a6.m`**: Validación y comparación del error entre el valor aproximado calculado y el valor real de MATLAB (`exp(1)`).

**Funciones Principales:**
* **`f_get_roots.m`**: Resuelve el polinomio $z^n - z = 0$ devolviendo resultados cartesianos y polares.
* **`f_calc_e.m`**: Encapsula el algoritmo de la serie de Taylor para aproximar $e$ según la precisión deseada.

**Resultados de Simulación (Publish):**

| Validación de Euler (`script_a6`) | Visualización de Raíces (`script_a4`) |
| :---: | :---: |
| **Aproximación Numérica** | **Plano Complejo y Fasores** |
| [Ver Reporte Completo](html/script_a6.html) | [Ver Reporte Completo](html/script_a4.html) |
| *(Consola: e_aprox vs e_real)* | [![Gráfico Raíces](html/script_a4_01.png)](html/script_a4.html) |

---

### Parte B: Análisis Temporal de Señales y Sistemas

Profundiza en la generación de señales, propiedades de simetría y la respuesta de sistemas LTI mediante convolución.

**Scripts Principales:**
* **`script_b1.m`**: Síntesis de señales complejas combinando rampas y senoidales. Incluye reproducción de audio (`audioplayer`) y búsqueda de picos.
* **`script_b2.m`**: Demostración manual de la descomposición de una señal lineal en sus componentes par e impar.
* **`script_b3.m`**: Validación de la descomposición par/impar utilizando la función automatizada sobre una señal de prueba.
* **`script_b4.m`**: Implementación manual de la convolución continua, demostrando el escalado temporal y la operación matemática paso a paso.
* **`script_b5.m`**: Simulación de la respuesta de un sistema (carga exponencial) ante una entrada escalón mediante convolución continua automática.
* **`script_b6.m`**: Ejecución de convolución discreta (sumatoria) y verificación de la propiedad conmutativa ($x*h = h*x$).

**Funciones Principales:**
* **Generadores de Señal**: `esc.m` (Escalón), `ramp.m` (Rampa), `delta.m` (Impulso).
* **`f_get_even_odd.m`**: Separa cualquier señal discreta en sus partes simétrica y antisimétrica.
* **`f_plot_conv.m`**: Realiza y grafica la convolución continua aproximada, gestionando automáticamente los vectores de tiempo resultantes.
* **`f_stem_conv.m`**: Realiza y grafica la convolución discreta utilizando diagramas de tallos (`stem`).

**Resultados de Simulación (Publish):**

| Respuesta al Impulso y Convolución (`script_b5`) |
| :---: |
| **Entrada, Respuesta al Impulso h(t) y Salida y(t)** |
| [Ver Reporte Completo](html/script_b5.html) |
| [![Gráfico Convolución](html/script_b5_01.png)](html/script_b5.html) |
| *La gráfica muestra la dinámica de salida calculada mediante la integral de convolución.* |

---

### Parte C: Modelado y Simulación de Sistemas Físicos

Resolución de Ecuaciones Diferenciales Ordinarias (EDO) para modelar circuitos eléctricos utilizando solvers numéricos (`ode23`) y Espacio de Estados.

**Scripts Principales:**
* **`script_c1.m`**: Planteo y resolución básica de la EDO de un circuito RL serie. Calcula $v_L(t)$ derivando numéricamente la corriente.
* **`script_c2.m`**: Simulación avanzada del circuito RL ante diferentes estímulos (pulsos simples y combinados) visualizando $v_{in}, i_L, v_L$.
* **`script_c3.m`**: Modelado de un circuito RLC serie mediante Espacio de Estados (Matrices A y B). Resuelve la dinámica del voltaje en el capacitor.
* **`script_c4.m`**: Estudio completo de los regímenes transitorios en RLC. Simula y compara los casos: Amortiguamiento Crítico, Sobreamortiguado y Subamortiguado.

**Funciones Principales:**
* **`f_resRL.m`**: Función que encapsula la dinámica del circuito RL, permitiendo variar parámetros $R, L$ y la función de excitación.
* **`f_resRLC.m`**: Función generalizada para resolver circuitos RLC serie ante cualquier entrada arbitraria utilizando `ode23`.

**Resultados de Simulación y Fundamentación:**

| Circuito RL (1er Orden) | Circuito RLC (2do Orden) |
| :---: | :---: |
| **Deducción del Modelo** | **Deducción del Modelo** |
| ![Derivación RL](Obtención%20EDO%20script_c2.jpeg) | ![Derivación RLC](Obtención%20EDO%20script_c4.jpeg) |
| **Respuesta al Pulso** | **Respuesta Subamortiguada** |
| [Ver Reporte Completo](html/script_c2.html) | [Ver Reporte Completo](html/script_c4.html) |
| [![Gráfico RL](html/script_c2_01.png)](html/script_c2.html) | [![Gráfico RLC](html/script_c4_03.png)](html/script_c4.html) |

---

## Problemas Comunes
1. Error "Undefined function or variable":
    - Causa: MATLAB no encuentra las funciones auxiliares (esc, ramp, f_plot_conv).
    - Solución: Asegúrate de haber añadido la carpeta del proyecto al Path (ver sección Instalación) o ejecuta los scripts desde el directorio raíz.

2. Gráficos de Convolución vacíos o erróneos:
    - Solución: Verifica que el paso de tiempo dt sea lo suficientemente pequeño (ej. 0.01) y consistente entre los vectores de entrada y la respuesta al impulso.

---

## Documentación
Referencias técnicas utilizadas para el desarrollo de los algoritmos:

- [Documentación de ode23 (MathWorks) - Solver de ecuaciones diferenciales.](https://www.mathworks.com/help/matlab/ref/ode23.html)
- [Convolución en MATLAB (conv).](https://www.mathworks.com/help/matlab/ref/conv.html)
- Apuntes de Cátedra: Modelado de Sistemas Físicos y Análisis de Señales.

---

## Fuentes De Consulta
- Documentación oficial de MathWorks (MATLAB).
- Libros de texto: Oppenheim, A. V., & Willsky, A. S. - Signals and Systems.

---

## Contribución
Toda colaboración es bienvenida. Sigue estos pasos para contribuir:

  1. Realiza un fork del repositorio.
  2. Crea una rama para tu mejora (git checkout -b feature/nueva-funcionalidad).
  3. Haz commit de tus cambios.
  4. Haz push a la rama y abre un Pull Request.

---

## Licencia
Este proyecto está bajo la Licencia Pública General GNU v3.0.

---

## Autores
- Facundo Costarelli

---

## Reconocimientos Y Colaboraciones
- Cátedra de Análisis de Señales y Sistemas - Universidad Tecnológica Nacional (UTN).