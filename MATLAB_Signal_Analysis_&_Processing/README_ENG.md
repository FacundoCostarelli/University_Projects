# Signals and Systems Analysis in MATLAB

**Brief Description:** This repository contains a comprehensive collection of MATLAB scripts and functions developed for the Signals and Systems course. The project covers everything from mathematical fundamentals (complex numbers and matrices) to advanced physical system modeling (RLC circuits), including temporal signal analysis (convolution).

- [Youtube Presentation Part A](LINK_TO_YOUR_VIDEO_HERE)
- [Youtube Presentation Part B](LINK_TO_YOUR_VIDEO_HERE)
- [Youtube Presentation Part C](LINK_TO_YOUR_VIDEO_HERE)

---

## Table of Contents

1. [Installation](#installation)
2. [Project Structure](#project-structure)
   - [Part A: Fundamentals](#part-a-mathematical-fundamentals-and-basic-algorithms)
   - [Part B: Time Analysis](#part-b-temporal-analysis-of-signals-and-systems)
   - [Part C: Circuit Modeling](#part-c-modeling-and-simulation-of-physical-systems)
3. [Common Issues](#common-issues)
4. [Documentation](#documentation)
5. [References](#references)
6. [Contribution](#contribution)
7. [License](#license)
8. [Authors](#authors)
9. [Acknowledgments](#acknowledgments)

---

## Installation
Guide to set up the MATLAB environment and execute the simulations.

**Prerequisites:**
- PC with Windows, Linux, or MacOS.
- **MATLAB** (Version R2016a or higher recommended).
- **Signal Processing Toolbox** (Recommended for advanced filtering functions).

**Installation Steps:**
1. Clone the repository or download the files:
   ```bash
   git clone [https://github.com/YOUR_USER/YOUR_REPO_SIGNALS.git](https://github.com/YOUR_USER/YOUR_REPO_SIGNALS.git)
2. Configure the MATLAB environment:
    - Open MATLAB.
    - Navigate to the project folder.
    - Right-click on the folder in the file browser and select "Add to Path" > "Selected Folders and Subfolders". This is crucial for MATLAB to find the auxiliary functions (ramp.m, esc.m, etc.) from any script.

----

## Project Structure

The development is divided into three main modules. Below is the function of each script and auxiliary file.

### Part A: Mathematical Fundamentals and Basic Algorithms

This section establishes the basis for numerical calculus, covering complex numbers, matrix algebra, and series approximations.

**Main Scripts:**
* **`script_a1.m`**: Fundamental operations with complex numbers (sum, product, modulus, phase, conjugate) and their phasor visualization.
* **`script_a2.m`**: Advanced matrix algebra; includes multiplication, determinant calculation, inverses, and element-wise operations.
* **`script_a3.m`**: Generation of polynomials with random coefficients and calculation of their roots using the native `roots` function.
* **`script_a4.m`**: Test script to visualize the n-th roots of a complex number on the Z-plane (unit circle).
* **`script_a5.m`**: Logical implementation of the approximation of Euler's number ($e$) using Taylor series without explicit loops (vectorized).
* **`script_a6.m`**: Validation and error comparison between the calculated approximate value and MATLAB's real value (`exp(1)`).

**Main Functions:**
* **`f_get_roots.m`**: Solves the polynomial $z^n - z = 0$ returning Cartesian and polar results.
* **`f_calc_e.m`**: Encapsulates the Taylor series algorithm to approximate $e$ according to the desired precision.

**Simulation Results (Publish):**

| Euler Validation (`script_a6`) | Roots Visualization (`script_a4`) |
| :---: | :---: |
| **Numerical Approximation** | **Complex Plane and Phasors** |
| [View Full Report](html/script_a6.html) | [View Full Report](html/script_a4.html) |
| *(Console: e_aprox vs e_real)* | [![Roots Graph](html/script_a4_01.png)](html/script_a4.html) |

---

### Part B: Temporal Analysis of Signals and Systems

Delves into signal generation, symmetry properties, and the response of LTI systems via convolution.

**Main Scripts:**
* **`script_b1.m`**: Synthesis of complex signals combining ramps and sinusoids. Includes audio playback (`audioplayer`) and peak finding.
* **`script_b2.m`**: Manual demonstration of the decomposition of a linear signal into its even and odd components.
* **`script_b3.m`**: Validation of even/odd decomposition using the automated function on a test signal.
* **`script_b4.m`**: Manual implementation of continuous convolution, demonstrating time scaling and the mathematical operation step-by-step.
* **`script_b5.m`**: Simulation of a system's response (exponential charge) to a step input using automatic continuous convolution.
* **`script_b6.m`**: Execution of discrete convolution (summation) and verification of the commutative property ($x*h = h*x$).

**Main Functions:**
* **Signal Generators**: `esc.m` (Step), `ramp.m` (Ramp), `delta.m` (Impulse).
* **`f_get_even_odd.m`**: Separates any discrete signal into its symmetric and antisymmetric parts.
* **`f_plot_conv.m`**: Performs and plots the approximate continuous convolution, automatically managing the resulting time vectors.
* **`f_stem_conv.m`**: Performs and plots the discrete convolution using stem diagrams.

**Simulation Results (Publish):**

| Impulse Response and Convolution (`script_b5`) |
| :---: |
| **Input, Impulse Response h(t), and Output y(t)** |
| [View Full Report](html/script_b5.html) |
| [![Convolution Graph](html/script_b5_01.png)](html/script_b5.html) |
| *The graph shows the output dynamics calculated via the convolution integral.* |

---

### Part C: Modeling and Simulation of Physical Systems

Resolution of Ordinary Differential Equations (ODE) to model electrical circuits using numerical solvers (`ode23`) and State Space.

**Main Scripts:**
* **`script_c1.m`**: Setup and basic resolution of the ODE for a series RL circuit. Calculates $v_L(t)$ by numerically differentiating the current.
* **`script_c2.m`**: Advanced simulation of the RL circuit under different stimuli (simple and combined pulses) visualizing $v_{in}, i_L, v_L$.
* **`script_c3.m`**: Modeling of a series RLC circuit using State Space (Matrices A and B). Solves the voltage dynamics across the capacitor.
* **`script_c4.m`**: Complete study of transient regimes in RLC. Simulates and compares the cases: Critically Damped, Overdamped, and Underdamped.

**Main Functions:**
* **`f_resRL.m`**: Function that encapsulates the dynamics of the RL circuit, allowing variation of parameters $R, L$ and the excitation function.
* **`f_resRLC.m`**: Generalized function to solve series RLC circuits for any arbitrary input using `ode23`.

**Simulation Results and Fundamentals:**

| RL Circuit (1st Order) | RLC Circuit (2nd Order) |
| :---: | :---: |
| **Model Derivation** | **Model Derivation** |
| ![RL Derivation](Obtención%20EDO%20script_c2.jpeg) | ![RLC Derivation](Obtención%20EDO%20script_c4.jpeg) |
| **Pulse Response** | **Underdamped Response** |
| [View Full Report](html/script_c2.html) | [View Full Report](html/script_c4.html) |
| [![RL Graph](html/script_c2_01.png)](html/script_c2.html) | [![RLC Graph](html/script_c4_03.png)](html/script_c4.html) |

---

## Common Issues
1. Error "Undefined function or variable":
    - Cause: MATLAB cannot find the auxiliary functions (esc, ramp, f_plot_conv).
    - Solution: Ensure you have added the project folder to the Path (see Installation section) or execute the scripts from the root directory.

2. Empty or erroneous Convolution Plots:
    - Solution: Verify that the time step dt is small enough (e.g., 0.01) and consistent between the input vectors and the impulse response.

---

## Documentation
Technical references used for algorithm development:

- [ode23 Documentation (MathWorks) - Differential equation solver.](https://www.mathworks.com/help/matlab/ref/ode23.html)
- [Convolution in MATLAB (conv).](https://www.mathworks.com/help/matlab/ref/conv.html)
- Lecture Notes: Modeling of Physical Systems and Signal Analysis.

---

## References
- Official MathWorks Documentation (MATLAB).
- Textbooks: Oppenheim, A. V., & Willsky, A. S. - Signals and Systems.

---

## Contribution
Contributions are welcome. Follow these steps to collaborate:

  1. Fork the repository.

  2. Create a branch for your feature (git checkout -b feature/new-feature).

  3. Commit your changes.

  4. Push to the branch and open a Pull Request.

---

## License
This project is licensed under the GNU General Public License v3.0.

---

## Authors
- Facundo Costarelli

---

## Acknowledgments
- Signals and Systems Analysis Department - National Technological University (UTN).
