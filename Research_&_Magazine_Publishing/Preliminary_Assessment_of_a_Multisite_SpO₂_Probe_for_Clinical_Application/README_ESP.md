# Evaluación Preliminar de una Sonda SpO₂ Multisitio para Aplicación Clínica (nFISIO)

[![DOI](https://doi.org/10.1007/978-3-032-06401-1_33)](https://doi.org/10.1007/978-3-032-06401-1_33)
[![Print ISBN](978-3-032-06400-4)](#)
[![Online ISBN](978-3-032-06401-1)](#)
[![Congreso](https://sabi.org.ar/congresos/)](#)

🎥 **[Mirá el video de la presentación en el SABI 2025 en YouTube](https://www.youtube.com/watch?v=1K4XcBGGPJE)**

## 📌 Resumen del Proyecto
La saturación periférica de oxígeno (SpO₂) es un parámetro no invasivo clave para evaluar la oxigenación sistémica. Aunque la oximetría de pulso en el dedo es el estándar clínico, su fiabilidad suele verse comprometida por artefactos de movimiento, mala perfusión periférica y factores anatómicos.

Este repositorio documenta la arquitectura, metodología y resultados preliminares del proyecto **nFISIO**: una sonda de diseño propio en forma de lápiz que permite la adquisición de datos de SpO₂ desde territorios arteriales alternativos (cuello, lóbulo de la oreja y muñeca), ofreciendo una alternativa robusta para entornos clínicos de alta exigencia.

## 🛠️ Arquitectura de Hardware y Software
El dispositivo nFISIO es inalámbrico y autónomo, e integra:
* **Microcontrolador:** STM32F103 (STMicroelectronics) para la adquisición y procesamiento de datos en tiempo real.
* **Sensor:** MAX30102 (Analog Devices) con LEDs Rojo (650-670 nm) e Infrarrojo (870-900 nm).
* **Conectividad:** Módulo Bluetooth HC-05 para transmisión inalámbrica.
* **Visualización:** Pantalla OLED monocromática de 0.96 pulgadas (128x64 px) vía I2C.
* **Carcasa:** Diseño ergonómico impreso en 3D (ABS mediante FDM para la estructura principal y resina para la cápsula del sensor, garantizando un buen acople óptico).
* **Interfaz de Software:** Interfaz gráfica de usuario multiplataforma desarrollada en **Qt (v5.13)** con la biblioteca QCustomPlot para visualización en tiempo real y almacenamiento en formato .csv.

## 📊 Resultados Preliminares
El dispositivo fue evaluado en 16 sujetos, comparando las mediciones del cuello, lóbulo de la oreja, brazo, muñeca y dedo con un oxímetro de pulso comercial.
* **Métricas de Error:** Error Absoluto Medio (MAE): 1.51%, Error Cuadrático Medio (MSE): 2.98%, Raíz del Error Cuadrático Medio (RMSE): 1.73%.
* **Conclusión:** Los hallazgos demuestran la viabilidad de obtener señales consistentes de SpO₂ desde ubicaciones alternativas bajo diversas condiciones fisiológicas, mitigando artefactos mediante la redundancia multisitio.

## 👥 Autores
* Nahuel Contreras¹, Facundo Costarelli¹, Maximiliano Montenegro¹, Martín De Luca¹, Diego E. Nuñez², Ricardo L. Armentano¹, Leandro J. Cymberknop¹
* *¹ Universidad Tecnológica Nacional, Facultad Regional Buenos Aires, Grupo de Investigación y Desarrollo en Bioingeniería (GIBIO).*
* *² Servicio de Kinesiología, Hospital Municipal San José, Buenos Aires, Argentina.*

---
*Publicado en Springer Nature Switzerland (Oct 2025).*