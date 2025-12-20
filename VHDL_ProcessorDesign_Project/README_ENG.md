# 16-bit Microprocessor System with UART & I/O - Integrated Project

![Project Status](https://img.shields.io/badge/Status-Completed-success) ![VHDL](https://img.shields.io/badge/Language-VHDL-blue) ![Vivado](https://img.shields.io/badge/IDE-Vivado-orange)

> **Microprocessor Design** > **Institution:** National Technological University (UTN BA)  
> **Engineer:** Facundo Costarelli

---

## 📖 About the Project

This repository contains the complete design and implementation of a **16-bit Microprocessor System**. The core objective was to design a robust **Control Unit (UC)** capable of orchestrating a full Datapath comprising an Arithmetic Logic Unit (ALU), Program Counter (PC), RAM/ROM memories, UART Tx-Rx communication peripherals, and IO ports.

The system was designed using **VHDL** and synthesized/simulated in **AMD Vivado 2024.2**. It features a 32-bit Instruction Set Architecture (ISA) processing 16-bit data, capable of performing arithmetic calculations, logical operations, memory management, and serial communication via RS-232 (UART).

📄 **Specifications:** [Download Official Specifications (18.microIO.pdf)](./docs/18.microIO.pdf)

### 📺 Video Demo
Watch the full explanation and simulation analysis in the following video/playlist:
[![Video Demo](https://img.youtube.com/vi/YOUR_VIDEO_ID_HERE/0.jpg)](LINK_TO_YOUR_YOUTUBE_PLAYLIST)

---

## 📋 Table of Contents

1. [About the Project](#-about-the-project)
2. [System Architecture](#️-system-architecture)
3. [Instruction Set (ISA)](#-instruction-set-isa)
4. [Simulation & Testing](#-simulation--testing)
5. [Project Structure](#-project-structure-and-submodules)
6. [Tools & Technologies](#️-tools--technologies)
7. [Contribution](#-contribution)
8. [License](#-license)
9. [Author](#-author)
10. [Acknowledgments](#-acknowledgments)

---

## 🏗️ System Architecture

The project is structured hierarchically, with `microIO.vhd` acting as the **Top Level Entity**. This module interconnects the Control Unit with the data path and I/O interfaces.

![Block Diagram](./images/block_diagram_placeholder.png)
*(Detailed Block Diagram showing connections between UC, ALU, PC, and UART)*

### 1. Control Unit (UC) - The "Brain"
The **UC** is the most complex module. It implements a **Finite State Machine (FSM)** that decodes 32-bit instructions received from the PC.
* **Why?** To coordinate timing between instruction Fetch, Opcode Decode, and Execution, enabling the ALU or writing to RAM/UART as required.
* **Function:** Reads bits `[22:21]` of the instruction to determine operation type (ALU, JMP, MOV) and controls specific signals (`aluEna`, `portWrEna`, `pcPl`, etc.).

### 2. Arithmetic Logic Unit (ALU)
A 16-bit processing unit designed for complex signal tasks.
* **Key Features:**
    * **Saturation Logic:** Prevents arithmetic overflow wrap-around. If a sum exceeds the 16-bit maximum, it clamps to `0x7FFF` instead of rolling over to negative.
    * **Barrel Shifter:** Implements bit rotation logic via the `rot.vhd` module.
    * **Flags:** Updates status flags (`Zero`, `Negative`, `Overflow`, `Carry`) which feed back to the UC for conditional jumps.

### 3. Program Counter (PC)
Manages instruction flow using a binary counter with parallel load (`myCntBinarioPl.vhd`).
* **Sequential vs. Jump:** Normally increments the address by 1. However, when a `JMP` instruction occurs, the UC activates the **Parallel Load (PL)** signal, forcing the PC to jump to a specific address defined in the instruction.

### 4. UART (Universal Asynchronous Receiver-Transmitter)
Full-duplex serial communication module complying with the RS-232 standard.
* **RX Module (`uartRx.vhd`):** Implements a sampling technique at the **middle of the bit period** (M/2) using `myCnt.vhd` to ensure data integrity and noise immunity.
* **TX Module (`uartTx.vhd`):** Uses a configurable shift register (`myShiftReg_dir.vhd`) to serialize parallel data.

### 5. Port I/O (`portIO.vhd`)
* **Why Registered?** Inputs and outputs pass through D-Type Flip-Flops. This synchronization is vital to prevent **metastability** issues when interfacing the asynchronous external world with the synchronous internal processor clock.

---

## 🕹️ Instruction Set (ISA)

The processor uses a fixed 32-bit instruction width to manipulate 16-bit data. Decoding is handled by the UC based on the following structure:

| Bit Range | Function | Description |
| :--- | :--- | :--- |
| **[22:21]** | **Opcode Type** | `00`: NOP, `01`: ALU Op, `10`: Jumps (Control Flow), `11`: Memory/IO MOV |
| **[20:17]** | **Sub-Opcode** | Specifies exact operation (e.g., ADD, SUB, AND, JMP_Z, MOV_UART) |
| **[16]** | **Source Sel.** | Selects between Immediate Value or RAM content |
| **[15:0]** | **Operand** | Immediate value or Address |

📄 **Documentation:** [Download Instruction Set PDF](./docs/microIO_2023setDeInstruccion.pdf)

---

## 📊 Simulation & Testing

The system was validated using a **Testbench** (`microIO_tb.vhd`). Two main COE files were used to load the Instruction ROM:

1.  **`test00.coe`**: Initial sanity check (basic port toggling).
2.  **`test01.coe`**: Full validation suite including arithmetic, saturation, and conditional jumps.

### How to Run the Simulation
To reproduce the exact signal views shown below, load the custom waveform configuration file provided in the repository:
* File: `sim/microIO_tb_behaveFacundo.wcfg`

### Test Case: `test01.coe` Analysis
This program validates the `test01.pdf` truth table. It executes:
1.  **Data Movement:** Loading values into the accumulator.
2.  **Arithmetic:** Performing additions that trigger saturation.
3.  **Jumps:** Testing Conditional Jumps (`JMP Z`, `JMP N`) based on ALU flags.

#### Waveform Analysis
Below are the simulation results showing the execution cycle:

![Waveform 1](./images/waveform_overview.png)
*Figure 1: Overview of the Fetch-Decode-Execute cycle using `test01.coe`.*

![Waveform 2](./images/waveform_zoom_alu.png)
*Figure 2: Zoom in on ALU execution showing Saturation flag activation.*

📄 **Verification:** [Download Test01 Truth Table (PDF)](./docs/test01.pdf)

---

## 📂 Project Structure and Submodules

```bash
├── src/
│   ├── microIO.vhd              # Top Level Entity (Connects the entire system)
│   │
│   ├── uc.vhd                   # Control Unit (Finite State Machine)
│   │   └── ramMem.xci           # IP Core: Data RAM Memory
│   │
│   ├── alu.vhd                  # Arithmetic Logic Unit
│   │   └── rot.vhd              # Combinational Rotator (Barrel Shifter)
│   │
│   ├── pc.vhd                   # Program Counter (Top)
│   │   ├── pcMem.xci            # IP Core: Instruction ROM Memory
│   │   └── myCntBinarioPl.vhd   # Counter with Parallel Load
│   │       # Why? Allows incrementing (PC+1) or loading jump address (JMP)
│   │
│   ├── uart/
│   │   ├── uart.vhd             # Communication Top Level
│   │   │   ├── uartTx.vhd       # Transmitter Module
│   │   │   │   ├── myCnt.vhd    # Baud Rate Generator (Timing)
│   │   │   │   ├── mySingleModuleCnt.vhd # Sent bits counter (0 to 9)
│   │   │   │   └── myShiftReg_dir.vhd    # Serializer (Piso)
│   │   │   │       # Why? Allows choosing bit order (LSB/MSB first)
│   │   │   │
│   │   │   └── uartRx.vhd       # Receiver Module
│   │   │       ├── SckRisingAndFallingEdgeDetector.vhd # Start Bit Detector
│   │   │       │   # Why? Synchronizes asynchronous reception start
│   │   │       ├── myCnt.vhd    # Sampling Timer (Sampling at M/2)
│   │   │       ├── mySingleModuleCnt.vhd # Received bits counter
│   │   │       └── myShiftReg.vhd        # Deserializer (Sipo)
│   │
│   └── portIO.vhd               # Registered I/O Controller
│
├── sim/
│   ├── microIO_tb.vhd           # Main Testbench
│   ├── test00.coe               # Basic initialization test
│   ├── test01.coe               # Main validation test
│   ├── microIO_tb_behaveFacundo.wcfg  # Custom Waveform Config
│   └── microIO_tb_behav.wcfg          # Default Waveform Config
│
├── docs/
│   ├── 18.microIO.pdf           # Project Specifications
│   ├── microIO_2023setDeInstruccion.pdf
│   └── test01.pdf               # Expected Results Truth Table
└── README.md

---

## Tools and Technologies
- Language: VHDL (IEEE 1076 Standard)
- Synthesis and Simulation: AMD Xilinx Vivado 2023
- FPGA Platform: Digilent Zybo / Arty Z7 (Zynq-7000)
- Version Control: Git & GitHub

## Contribution

All collaboration is welcome. Follow these steps to contribute:

1. Fork the repository.
2. Create a new branch for your feature or fix:
    - `git checkout -b feature/new-feature`
3. Make your changes and commit:
    - `git commit -m "Description of changes made"`
4. Push to your branch:
    - `git push origin feature/new-feature`
5. Create a pull request describing your changes.

---

## License
This project is licensed under the GNU General Public License v3.0. You may use, modify, and distribute this project respecting the license terms.

---

## Author
- Facundo Costarelli, Electronic Engineering Student at UTN BA

---

## Acknowledgments and Collaborations
- Professor Jerónimo Atencio (Electronics at UTN BA)
- Professor Nicolás Ríos Taurási (Electronics at UTN BA)

**Abbreviations:**
- UTN BA --> National Technological University of Buenos Aires.