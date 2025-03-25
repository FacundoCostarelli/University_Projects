# BMP Image Processing Project

**Brief Description:**  
This project performs BMP image processing, allowing for reading, writing, and manipulating BMP files. It uses a modular approach to facilitate the implementation of various image processing functions.

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
10. [Filtering Algorithms and Others](#filtering-algorithms-and-others)

---

## Installation
To install the software and set up the environment, follow these steps:

1. Ensure you have a C compiler installed.
2. Download the `mainV1.c` file and place it in your working directory.
3. Compile the file using the command:

## Usage
Steps to use the software.

## Common Issues
Description of common issues and their solutions.

## Algorithm Explanations

### Grayscale Conversion Algorithm
This algorithm converts an RGB image to grayscale using the luminosity method. The formula used is:
```
Grayscale = 0.299R + 0.587G + 0.114B
```
This formula weights the red, green, and blue components of the pixel to produce a single grayscale value. The weights are based on human perception, where green is perceived as brighter than red, and red is perceived as brighter than blue. This method ensures that the resulting grayscale image maintains the luminance of the original RGB image.

```c
void Conversion_RGB_a_Grayscale(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision) {
    // Code to convert RGB to grayscale
}
```

### Edge Detection Algorithm
This algorithm detects edges in an image using a linear filter. It applies a 3x3 convolution mask to each pixel in the image to identify areas of high intensity change, which correspond to edges. The process involves iterating over each pixel, applying the mask, and calculating the gradient to determine if an edge is present.

```c
void Deteccion_de_Bordes_lineal(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision, int Mascara[][3]) {
    // Code for edge detection
    // Each pixel of the image is traversed and the convolution mask is applied.
    // Pixels that meet the edge criteria are marked in the output buffer.
}
```

By following this approach, you can effectively document your project while providing clear explanations for complex algorithms.