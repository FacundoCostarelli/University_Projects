# Preliminary Assessment of a Multisite SpO₂ Probe for Clinical Application (nFISIO)

[![DOI](https://img.shields.io/badge/DOI-Insert_DOI_Here-blue.svg)](https://doi.org/10.1007/978-3-032-06401-1_33)
[![Print ISBN](https://img.shields.io/badge/ISBN-Insert_ISBN_Here-lightgrey.svg)](#978-3-032-06400-4)
[![Online ISBN](https://img.shields.io/badge/ISBN-Insert_ISBN_Here-lightgrey.svg)](#978-3-032-06401-1)
[![Conference](https://img.shields.io/badge/Congress-SABI_2025-success.svg)]([#978-3-032-06401-1](https://sabi.org.ar/congresos/))

🎥 **[Watch the SABI 2025 Presentation Video on YouTube](https://www.youtube.com/watch?v=1K4XcBGGPJE)**

## 📌 Overview
Peripheral oxygen saturation (SpO₂) is a key non-invasive parameter for assessing systemic oxygenation. While fingertip pulse oximetry remains the clinical standard, its reliability is often compromised by motion artifacts, poor peripheral perfusion, and anatomical factors. 

This repository contains the hardware overview, methodology, and preliminary results of the **nFISIO** project: a custom-designed, pen-like probe that enables SpO₂ data acquisition from alternative arterial territories such as the neck, earlobe, and wrist, offering a robust alternative for high-demand clinical environments.

## 🛠️ Hardware & Software Architecture
The nFISIO device is fully wireless and autonomous, integrating:
* **Microcontroller:** STM32F103 (STMicroelectronics) for real-time data acquisition and processing.
* **Sensor:** MAX30102 (Analog Devices) with Red (650-670 nm) and IR (870-900 nm) LEDs.
* **Connectivity:** HC-05 Bluetooth module for wireless UART transmission.
* **Display:** 0.96-inch monochrome OLED (128x64 px) via I2C for real-time visual feedback.
* **Housing:** Custom ergonomic 3D-printed enclosure (FDM ABS for the main structure, Resin for the sensor housing to ensure optical coupling).
* **Software Interface:** A multi-platform GUI developed with the **Qt framework (v5.13)** and QCustomPlot library for real-time visualization and .csv data storage.

## 📊 Preliminary Results
The device was tested on 16 subjects comparing measurements from the neck, earlobe, upper arm, wrist, and fingertip against a commercial pulse oximeter. 
* **Error Metrics:** Mean Absolute Error (MAE): 1.51%, Mean Square Error (MSE): 2.98%, Root Mean Square Error (RMSE): 1.73%.
* **Conclusion:** The findings demonstrate the feasibility of obtaining consistent SpO₂ signals from alternative locations under varied physiological conditions, mitigating artifacts through multi-site redundancy.

## 👥 Authors
* Nahuel Contreras¹, Facundo Costarelli¹, Maximiliano Montenegro¹, Martín De Luca¹, Diego E. Nuñez², Ricardo L. Armentano¹, Leandro J. Cymberknop¹
* *¹ Universidad Tecnológica Nacional, Facultad Regional Buenos Aires, Grupo de Investigación y Desarrollo en Bioingeniería (GIBIO).*
* *² Servicio de Kinesiología, Hospital Municipal San José, Buenos Aires, Argentina.*

---
*Published in Springer Nature Switzerland (Oct 2025).*