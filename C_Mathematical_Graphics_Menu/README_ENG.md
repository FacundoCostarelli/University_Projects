# Mathematical Graphs Menu - Integrated Project

**Brief Description:**  
This project allows the user to plot different mathematical functions, including lines, quadratics, polynomials, hyperbolas, modules, natural logarithms with Taylor series, sine, cosine, and tangent with Maclaurin series. It is possible to calculate multiple points, define coefficients, and the number of terms via main command inputs. The program generates output files with the necessary data and commands to plot in Octave. We can plot various functions in the same window partitioned as a matrix of up to 9 sub-windows.

---

## Table of Contents

1. [Installation](#installation)
2. [Usage](#usage)
3. [Common Issues](#common-issues)
4. [Documentation](#documentation)
5. [References](#references)
6. [Contribution](#contribution)
7. [License](#license)
8. [Authors](#authors)
9. [Acknowledgments and Collaborations](#acknowledgments-and-collaborations)

---

## Installation
To install and run this project, follow these steps:

**Prerequisites:**
- Linux operating system or WSL (Windows Subsystem for Linux) as the project uses the Linux-specific `stdio_ext.h` library.
- Octave installed to visualize the generated graphs.

**Installation Steps:**
1. Clone the repository:
    git clone
2. Navigate to the project directory:
    cd 
3. Compile the `GraphicsMenu.c` file:
    Method 1:
     - gcc GraphicsMenu.c -o GraphicsMenu -lm
    Method 2:
     - gcc -c GraphicsMenu.c -o GraphicsMenu.o
     - gcc GraphicsMenu.o -o GraphicsMenu -lm

---

## Usage
Once the installation is complete, follow these steps to use the program:

1. Run the program:
    ./GraphicsMenu
2. Follow the on-screen instructions to enter the necessary data for the graphs.
3. The program will generate `.m` files that can be executed in Octave to visualize the graphs.

---

## Common Issues
1. **Compilation Issues On Non-Linux Systems:**
   - Description: The `stdio_ext.h` file is specific to Linux.
   - Solution: Use a Linux operating system or WSL to compile and run the program.

2. **Errors When Entering The Output File Name:**
   - Description: If the file name exceeds 50 characters, it may cause errors.
   - Solution: Ensure that the file name does not exceed 50 characters.

3. **Issues Plotting In Octave:**
   - Description: Octave may not immediately plot the quadratic with its tangent line.
   - Solution: Click on the Octave window or minimize and maximize the window to force the graph to update.

4. **Issues With The Tangent Graph:**
   - Description: The shape of the tangent graph depends on several factors:
     - If the graph starts from -89 to 89 degrees.
     - The number of terms where a very large number beyond 30 results in "nan" in some values of the points vector.
     - The number of points, generally with 10<=n<=20 should work without problems and with a number of points between 10 to 20.
   - Solution: Adjust the graph parameters as necessary.

---

## Documentation
For more details about the project, refer to the following documents:

---

## References
- [StackOverflow Forums](https://stackoverflow.com/)
- [Octave Documentation](https://www.gnu.org/software/octave/doc/interpreter/)

---

## Contribution

All contributions are welcome. Follow these steps to contribute:

1. Fork the repository.
2. Create a new branch for your feature or fix:
    - git checkout -b feature/new-feature
3. Make your changes and commit:
    - git commit -m "Description of the changes made"
4. Push to your branch:
    - git push origin feature/new-feature
5. Create a Pull Request describing your changes.

---

## License
This project is licensed under the GNU General Public License v3.0. 
You can use, modify, and distribute this project respecting the terms of the license.

---

## Authors
- Facundo Costarelli

---

## Acknowledgments and Collaborations
- Prof Ing Mariano Gonzalez (Electronics at UTN BA)
- Engineering Student Francisco Germaniez (Electronics at UTN BA)

**Abbreviations:**
- UTN BA --> National Technological University of Buenos Aires.