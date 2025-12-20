# Sistema Microprocesador de 16-bits con UART y I/O - Proyecto Integrado

![Estado del Proyecto](https://img.shields.io/badge/Estado-Completado-success) ![VHDL](https://img.shields.io/badge/Lenguaje-VHDL-blue) ![Vivado](https://img.shields.io/badge/IDE-Vivado-orange)

> **Diseño de Microprocesador** > **Institución:** Universidad Tecnológica Nacional (UTN BA)  
> **Ingeniero:** Facundo Costarelli

---

## Sobre el Proyecto

Este repositorio contiene el diseño e implementación completa de un **Sistema Microprocesador de 16 bits**. El objetivo principal fue diseñar una **Unidad de Control (UC)** robusta capaz de orquestar un Datapath completo que incluye una Unidad Aritmético-Lógica (ALU), Contador de Programa (PC), memorias RAM/ROM, periféricos de comunicación UART Tx-Rx y puertos IO.

El sistema fue diseñado utilizando **VHDL** y sintetizado/simulado en **AMD Vivado 2024.2**. El diseño cuenta con una Arquitectura de Set de Instrucciones (ISA) de 32 bits que procesa datos de 16 bits, capaz de realizar cálculos aritméticos, operaciones lógicas, gestión de memoria y comunicación serie vía RS-232 (UART).

**Especificaciones:** [Descargar Especificaciones Oficiales (18.microIO.pdf)](./docs/18.microIO.pdf)

### Video Demostración
Mira la explicación completa y el análisis de la simulación en el siguiente video/playlist:
[![Video Demo](https://img.youtube.com/vi/ID_DE_TU_VIDEO/0.jpg)](LINK_A_TU_PLAYLIST_YOUTUBE)

---

## Arquitectura del Sistema

El proyecto está estructurado jerárquicamente, con `microIO.vhd` actuando como la **Entidad Top Level**. Este módulo interconecta la Unidad de Control con el camino de datos y las interfaces de E/S.

![Diagrama de Bloques](./images/block_diagram_placeholder.png)
*(Diagrama de bloques detallado mostrando las conexiones entre UC, ALU, PC y UART)*

### 1. Unidad de Control (UC) - El "Cerebro"
La **UC** es el módulo más complejo. Implementa una **Máquina de Estados Finitos (FSM)** que decodifica las instrucciones de 32 bits recibidas del PC.
* **¿Por qué?** Para coordinar los tiempos entre la búsqueda de una instrucción (Fetch), la decodificación del código de operación (Decode) y la ejecución (Execute), habilitando la ALU o la escritura en RAM/UART según corresponda.
* **Función:** Lee los bits `[22:21]` de la instrucción para determinar el tipo de operación (ALU, JMP, MOV) y controla las señales específicas (`aluEna`, `portWrEna`, `pcPl`, etc.).

### 2. Unidad Aritmético-Lógica (ALU)
Unidad de procesamiento de 16 bits diseñada para tareas de señales complejas.
* **Características Clave:**
    * **Lógica de Saturación:** Previene el desbordamiento aritmético (wrap-around). Si una suma excede el valor máximo de 16 bits, se fija en `0x7FFF` en lugar de pasar a negativo. Analogamente ocurre lo mismo con la resta, si esta excede, el valor mínimo de 16 bits, se fija en `0x8000`. 
    * **Lógica de Compuertas:** Realiza las operaciones `and`, `or`, `xor`. 
    * **Barrel Shifter:** Implementa lógica de rotación de bits mediante el módulo `rot.vhd`.
    * **Flags:** Actualiza banderas de estado (`Zero`, `Negative`, `Overflow`, `Carry`) que retroalimentan a la UC para los saltos condicionales.

### 3. Contador de Programa (PC)
Gestiona el flujo de instrucciones.
* **Secuencial vs. Salto:** Normalmente incrementa la dirección en 1. Sin embargo, cuando ocurre una instrucción `JMP`, la UC activa la señal de **Carga Paralela (PL)**, forzando al PC a saltar a una dirección específica definida en la instrucción.

### 4. UART (Transmisor-Receptor Asíncrono Universal)
Módulo de comunicación serie full-duplex que cumple con el estándar RS-232.
* **Módulo RX:** Implementa una técnica de muestreo en la **mitad del periodo de bit** (M/2) para asegurar la integridad de los datos e inmunidad al ruido.
* **Módulo TX:** Utiliza un registro de desplazamiento configurable para serializar los datos paralelos.

### 5. Puerto E/S (`portIO.vhd`)
Registros de datos de entrada y salida del microprocesador.
* Las entradas y salidas pasan a través de Flip-Flops tipo D quedando registrados los datos. **¿Por qué Registrado?** Esta sincronización es vital para prevenir problemas de **metaestabilidad** al interconectar el mundo externo asíncrono con el reloj interno síncrono del procesador.

---

## Set de Instrucciones (ISA)

El procesador utiliza un ancho de instrucción fijo de 32 bits para manipular datos de 16 bits. La decodificación es manejada por la UC basada en la siguiente estructura:

| Rango de Bits | Función | Descripción |
| :--- | :--- | :--- |
| **[22:21]** | **Tipo de Opcode** | `00`: NOP, `01`: Op ALU, `10`: Saltos (Flujo de Control), `11`: Memoria/IO MOV |
| **[20:17]** | **Sub-Opcode** | Especifica la operación exacta (ej. ADD, SUB, AND, JMP_Z, MOV_UART) |
| **[16]** | **Sel. Fuente** | Selecciona entre Valor Literal o contenido de RAM |
| **[15:0]** | **Operando** | Valor Literal o Dirección |

**Documentación:** [Descargar PDF del Set de Instrucciones](./docs/microIO_2023setDeInstruccion.pdf)

---

## Simulación y Pruebas

El sistema fue validado utilizando un **Testbench** (`microIO_tb.vhd`). Se utilizaron dos archivos COE principales para cargar la ROM de Instrucciones:

1.  **`test00.coe`**: Prueba de sanidad inicial (toggling básico de puertos).
2.  **`test01.coe`**: Suite de validación completa incluyendo aritmética, saturación y saltos condicionales.
3.  **`test02.coe`**: Suite de validación específico para caso especial donde en la suma, uno de los operandos vale 1 literal.

### Cómo correr la simulación
Para reproducir las vistas de señales exactas mostradas abajo, carga el archivo de configuración de ondas personalizado provisto en el repositorio:
* Archivo: `sim/microIO_tb_behaveFacundo.wcfg`

### Análisis del Caso de Prueba: `test01.coe`
Este programa valida la tabla de verdad `test01.pdf`. Ejecuta:
1.  **Movimiento de Datos:** Carga de valores en el acumulador.
2.  **Aritmética:** Realización de sumas que disparan la saturación.
3.  **Saltos:** Prueba de Saltos Condicionales (`JMP Z`, `JMP N`) basados en los flags de la ALU.

#### Análisis de Waveforms
A continuación se muestran los resultados de la simulación del ciclo de ejecución:

![Waveform 1](./images/waveform_overview.png)
*Figura 1: Vista general del ciclo Fetch-Decode-Execute usando `test01.coe`.*

![Waveform 2](./images/waveform_zoom_alu.png)
*Figura 2: Zoom en la ejecución de la ALU mostrando la activación del flag de Saturación.*

**Verificación:** [Descargar Tabla de Verdad Test01 (PDF)](./docs/test01.pdf)

---

## Estructura del Proyecto y Submódulos

```bash
├── src/
│   ├── microIO.vhd              # Entidad Top Level (Conecta todo el sistema)
│   │
│   ├── uc.vhd                   # Unidad de Control (Máquina de Estados)
│   │   └── ramMem.xci           # IP Core: Memoria RAM de Datos
│   │
│   ├── alu.vhd                  # Unidad Aritmético-Lógica
│   │   └── rot.vhd              # Rotador combinacional (Barrel Shifter)
│   │
│   ├── pc.vhd                   # Program Counter (Top)
│   │   ├── pcMem.xci            # IP Core: Memoria ROM de Instrucciones
│   │   └── myCntBinarioPl.vhd   # Contador con Carga Paralela
│   │       # ¿Por qué? Permite incrementar (PC+1) o cargar dirección de salto (JMP)
│   │
│   ├── uart/
│   │   ├── uart.vhd             # Top Level de Comunicación
│   │   │   ├── uartTx.vhd       # Módulo Transmisor
│   │   │   │   ├── myCnt.vhd    # Generador de Baud Rate (Temporización)
│   │   │   │   ├── mySingleModuleCnt.vhd # Contador de bits enviados (0 a 9)
│   │   │   │   └── myShiftReg_dir.vhd    # Serializador (Piso)
│   │   │   │       # ¿Por qué? Permite elegir orden de bits (LSB/MSB first)
│   │   │   │
│   │   │   └── uartRx.vhd       # Módulo Receptor
│   │   │       ├── SckRisingAndFallingEdgeDetector.vhd # Detector de Start Bit
│   │   │       │   # ¿Por qué? Sincroniza el inicio de recepción asíncrona
│   │   │       ├── myCnt.vhd    # Temporizador de Muestreo (Sampling a M/2)
│   │   │       ├── mySingleModuleCnt.vhd # Contador de bits recibidos
│   │   │       └── myShiftReg.vhd        # Deserializador (Sipo)
│   │
│   └── portIO.vhd               # Controlador de E/S Registrado
│
├── sim/
│   ├── microIO_tb.vhd           # Testbench Principal
│   ├── test00.coe               # Archivo de inicialización ROM (Básico)
│   ├── test01.coe               # Archivo de inicialización ROM (Completo)
│   ├── microIO_tb_behaveFacundo.wcfg  # Waveform Config (Señales personalizadas)
│   └── microIO_tb_behav.wcfg          # Waveform Config (Default)
│
├── docs/
│   ├── 18.microIO.pdf           # Especificaciones del Proyecto
│   ├── microIO_2023setDeInstruccion.pdf
│   └── test01.pdf               # Tabla de Verdad de Resultados
└── README.md

---

## Herramientas y Tecnologías
- Lenguaje: VHDL (Estándar IEEE 1076)
- Síntesis y Simulación: AMD Xilinx Vivado 2023
- Plataforma FPGA: Digilent Zybo / Arty Z7 (Zynq-7000)
- Control de Versiones: Git & GitHub

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

## Autor
- Facundo Costarelli Estudiante de Ingeniería Electrónica en UTN BA

---

## Reconocimientos Y Colaboraciones
- Prof Ing Jerónimo Atencio           (Electrónica en UTN BA)
- Prof Ing Nicolas Ríos Taurási       (Electrónica en UTN BA)

**Abreviaciones:**
- UTN BA --> Universidad Tecnológica Nacional de Buenos Aires.
