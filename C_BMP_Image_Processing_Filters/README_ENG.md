# BMP Image Processing - Integrated Project

**Brief Description:**  
This project performs BMP image processing, allowing reading, writing, and manipulation of BMP files. It uses a modular approach to facilitate the implementation of various image processing functions.  
- [YouTube Presentation BMP Image Processing](.........)

---

## Table of Contents

1. [Detailed Description](#detailed-description)
2. [Installation](#installation)
3. [Usage](#usage)
4. [Common Issues](#common-issues)
5. [Implemented Algorithms](#implemented-algorithms)
6. [Additional Considerations](#additional-considerations)
7. [Documentation & Reference Sources](#documentation--reference-sources)
8. [Contribution](#contribution)
9. [License](#license)
10. [Authors](#authors)
11. [Acknowledgments And Collaborations](#acknowledgments-and-collaborations)

---

## Detailed Description
* This program uses a `main.c` file as the main source, where various functions are called and utilized.  
* This source file also contains pointer declarations used in the various functions.  
* Additionally, the source file includes usage instructions for:
  - Command-line arguments for `main`.
  - Executing the executable file.
  - The BMP image to be processed.
These instructions are displayed on the screen during program execution. Users must carefully read the messages presented.

* In more detail, the program performs mandatory reading of the input BMP file through a function that reads the header, color table (if any), and image data. It also prints the header and color table (if any) on the screen through another function. Most importantly, it features a recursive menu with different image processing options, all performed through various function calls.  
The input `.bmp` file can be of the following types:
- 1) Black and white,
- 2) Grayscale (GrayshadeScale),
- 3) RGB color.

* Specifically, the different processing options available are:
- A) Copy_Image  
     Applicable for image types 1), 2), 3) and pixel sizes of 2, 4, 8, 16, 24, and 32 bits.

- B) RGB_to_Grayscale Conversion  
     Applicable for image type 3). For types 2) and 1), it is also possible but not recommended as it produces an unintended result. It is applicable for pixel sizes of 2, 4, 8, 16, 24, and 32 bits. It uses a single color-to-grayscale conversion algorithm called "The Weighted Method." This method, also known as the "Luminosity Method," "weights" the red, green, and blue colors according to their wavelength.  
     The formula is:  
     `Grayscale = 0.299R + 0.587G + 0.114B`

- C) Grayscale_to_BlackAndWhite Conversion  
     Applicable for image type 2). For types 3) and 1), it is also possible but not recommended as it produces an unintended result. It is applicable for pixel sizes of 2, 4, 8, 16, 24, and 32 bits. It uses a single grayscale-to-black-and-white conversion algorithm called "binarization," which converts the integer value of each byte to 0 or 1. Each byte of image data is evaluated such that its integer value is either 0 (black) or 1 (white). A "Threshold" value is used, defined by the programmer (e.g., 150). Changing this value alters how dark the black and how light the white appears in the output black-and-white image.

- D) Image_Rotation  
     Applicable for image types 1), 2), and 3). It is applicable for pixel sizes of 2, 4, 8, 16, 24, and 32 bits. It uses a single rotation algorithm. The rotation is not performed using linear transformation but by assigning each pixel from the 2D array `BufferCopiaLocalIn` to the 2D array `BufferCopiaLocalOut`, placing each pixel at coordinates "x and y" associated with the indexes "i and j," which are modified through mathematical operations during the assignment process. This assignment process is executed through two loops for each rotation case, as the pixels are located in 2D arrays.

- E) Linear_Edge_Detection  
    Applicable for image types 1), 2), and 3). It is applicable for pixel sizes of 2, 4, 8, 16, 24, and 32 bits. It performs edge detection using a mask, i.e., a 3x3 2D array with preloaded values. This algorithm uses four loops:
    - The 1st loop iterates through all rows.
    - The 2nd loop iterates through all columns.
    - The 3rd and 4th loops modify the value of one pixel to another and load the new pixel value into a specific position in the output image data buffer. This algorithm uses the "gradient" operator, which computes the first derivatives in the processed digital image.

* All these image processing operations were successfully tested for a "pixel size or bit depth" of 24 bits, i.e., each pixel composed of 3 bytes. The pixel size is referred to in the code as `Tampunto`.

**Note:**  
In the `Lectura_Imagen` and `Copia_Imagen` functions, file descriptors are used, and therefore POSIX System Calls (`open`, `read`, `write`, `close`, etc.) are employed. In the other functions, "Streams" are used, and therefore FILE pointers and the respective functions for FILE pointers (`fopen`, `fread`, `fwrite`, `fclose`, etc.) are employed. These are part of Standard C. The purpose of this mix was to use different syntax and resources to solve various problems associated with file handling.

---

## Installation
To install the software and set up the environment, follow these steps:

1. Ensure you have a C compiler installed.
2. Download the `mainV1.c` file and place it in your working directory.
3. Compile the file using the command:
   ```
   gcc mainV1.c -o bmp_processor
   ```
4. Run the program with the BMP file as an argument:
   ```
   ./bmp_processor image.bmp
   ```

---

## Usage
Once the program is compiled, you can use it to process BMP images. Simply provide the BMP file you want to process as an argument when running the program and follow the on-screen instructions. You can watch the following video playlist to see how to use the program and the results for each case.  
[YouTube Playlist BMP Image Processing](.........)

---

## Common Issues
1. **File Not Found Error**: Ensure the BMP file path is correct.
2. **Permission Issues**: Verify that you have read and write permissions in the directory where the program is being executed.
3. **Usage Issues**: Follow the steps indicated on the screen. If you make a mistake in any option or data input via the keyboard, please close the program and start again.
4. **Filter Issues**: Applying filters to BMP images in the wrong color scale or format may result in unexpected effects.

---

## Implemented Algorithms

### Image Copying Algorithm

**Detailed Explanation:**
- This algorithm copies an input image so that the output is another image with the same qualities and characteristics. To achieve this, an output file named `copy.bmp` is opened with read and write permissions using the `open` function. If the file does not already exist, it is created, and user permissions for reading and writing are set.

- After reading all the image information into memory and storing it in a dynamic local buffer, the information is copied to the already created output file.

- The copying process begins with the BMP file header, which is written from the `DatosBMP` structure to the output file using the `write` function. The header contains essential information about the BMP file, such as the file type, size, and the offset where the image data begins.

- Next, the color table (if it exists) is copied. Specifically, if the color depth given by `TamPunto` is less than or equal to 8 bits, the color table is copied from the `Paleta_de_colores` structure to the output file using the `write` function. The color table is necessary for images with low color depth, as it defines the colors used in the image.

- Finally, the image data is copied from the temporary buffer `BufferDataImagen` to the output file using the `write` function. The amount of data copied must equal the total file size minus the header size.

**Summary:**
- This algorithm copies an image so that the copy is identical to the original. To achieve this, an output file is opened or created, indicating that it is a copy. Then, after reading the information into a local buffer, the relevant information is copied.

- The copying process involves taking the header, the color table (if it exists), and the image data itself, ensuring that all this information is written to the output file in the specified order.

- Below is the relevant function and the code section associated with the algorithm used.
```c
void Copia_Imagen( DatosBMP **p, Paleta_de_colores **p1, unsigned char **BufferDataImagen, int *fd_out )
{
   //....No prior code.
   *fd_out = open("copia.bmp", O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);

   write(*fd_out,*p,TamCabezera);
    
   if( (*p)->TamPunto <= 8 )
      write(*fd_out,*p1,TamTotalColores);
    
   write(*fd_out,*BufferDataImagen,( (*p)->TamARchivo ) - TamCabezera);

   //....Code for printing successful execution messages for the function.
}
```

### RGB To Grayscale Conversion Algorithm

**Detailed Explanation:**
- This algorithm transforms each mixed RGB color pixel into a Grayscale pixel and performs a "padding" process, i.e., filling bytes associated with the black color at the end of each row of bytes completed with Grayscale information.

- For example, consider that each color pixel is 24 bits, meaning it has 3 bytes, where each byte corresponds to a small pixel of a different RGB color: the 1st byte represents the "red pixel," the 2nd byte represents the "green pixel," and the 3rd byte represents the "blue pixel." Thus, 3 small 8-bit pixels form a complete 24-bit mixed RGB color pixel.

- Each byte of a single image data pixel is taken from the input file and initially stored in an array called "pixel," where each element represents a byte associated with a different RGB color. Then, each element of the array, i.e., each byte of each RGB color, is multiplied by a constant: 0.3 for red, 0.59 for green, and 0.11 for blue. The results of these multiplications are summed, producing a value stored in an unsigned char variable called "gray."

- Next, using `memset`, the "pixel" array is completely filled with bytes (3 in total) whose values are set to the "gray" byte value obtained in the previous step. As the next step, these bytes from the "pixel" array are written to the output file.

- These steps are repeated for each pixel in each column of the current row being processed from the input file. At the end of writing each row to the output file and just before starting the next row, a padding process is performed. This process fills new pixels with the same constant value.

- The padding process involves reading one item of image data from the input file, with a size equal to the integer value of the padding. This data item is stored in the "pixel" array, and then the contents of this array are written to the output file immediately after the completed row.

- This procedure is performed once for each row to avoid image cropping and ensure that when applying filters with masks, the mask values "overlap" entirely with the various pixels, producing the necessary modifications. This prevents areas of the image where the mask values overlap with nothing, which would cause issues.

**Summary:**
- This algorithm converts an RGB image to Grayscale using the "Luminosity" method. The formula used is:
   ```
   Grayscale = 0.299R + 0.587G + 0.114B
   ```
- This formula weights the red, green, and blue color components according to their contribution to perceived brightness. The result is a value representing the brightness of each pixel in the grayscale image.

- Below is the relevant function and the code section associated with the algorithm used.
```c
void Conversion_RGB_a_Grayscale(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision) 
{
      //....Variable declarations and function call for writing the color table and header to the output file.
      
      unsigned char pixel[3];
      for ( y = 0; y < (*p)->Altura; ++y)
      {
            for ( x = 0; x < (*p)->Ancho; ++x)
            {
                  fread(pixel, 3, 1, *ptr_in);
                  unsigned char gray = pixel[0] * 0.3 + pixel[1] * 0.58 + pixel[2] * 0.11;
                  memset(pixel, gray, sizeof(pixel));
                  fwrite(pixel, 3, 1, *ptr_out);
            }
            fread(pixel, padding, 1, *ptr_in);
            fwrite(pixel, padding, 1, *ptr_out);
      }

      //....File closing code and successful execution messages for the function.
}
```

### Grayscale To Black And White Conversion Algorithm

**Detailed Explanation:**
- This algorithm converts a grayscale image to black and white using a process called "binarization," which involves converting the integer value of each byte to either 0 or 1. Each byte represents part of a pixel, and its integer value is evaluated in a `for` loop.

- Specifically, each byte of image data is processed such that its integer value is either 0 (black) or 1 (white). Each pixel's value is modified in the memory block pointed to by `BufferCopiaLocal`.

- Additionally, an integer value called "Threshold" is used, which determines the cutoff point for assigning a value of 1 or 0 to a pixel. Bytes with integer values greater than the threshold are assigned a value of 1, while those below or equal to the threshold are assigned a value of 0.

- The code uses three macros: `BLANCO` (White) for 1, `NEGRO` (Black) for 0, and `UMBRAL` (Threshold) for a programmer-defined integer value (e.g., 150). Changing the threshold value alters how dark the black and how light the white appear in the output black-and-white image.

**Summary:**
- This algorithm converts a grayscale image to black and white using the "Binarization" method. It evaluates the integer value of each byte that makes up a pixel and assigns it a value of 0 (black) or 1 (white) based on a "Threshold" value.

- Once the local dynamic memory block is modified, all this information is written to the output file using the `fwrite` function.

- Below is the relevant function and the code section associated with the algorithm used.
```c
void Conversion_Grayscale_to_BlackAndWhite(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
   //....Code for variable declarations, function call for writing the color table and header to the output file, malloc null protection, and reading image data into memory.

   for( i = 0; i < (*p)->TamImg; i++ )
   {
      BufferCopiaLocal[i] = (BufferCopiaLocal[i]>THRESHOLD)?WHITE : BLACK;
   }

   //....Code for writing modified image data to the output file, closing files, freeing dynamic memory, and printing successful execution messages for the function.
}
```

### Rotation Algorithm

**Detailed Explanation:**
- The algorithm is based on a non-recursive menu of image rotation options. The actual rotation algorithm is not performed using linear transformation but by assigning each pixel from the 2D array `BufferCopiaLocalIn` to the 2D array `BufferCopiaLocalOut`. Each pixel is placed at coordinates "x and y" associated with the indexes "i and j," which are modified through mathematical operations during the assignment process in the `BufferCopiaLocalOut` 2D array.

- This assignment process is executed through two loops for each rotation case because the pixels are located in 2D arrays. It is important to note that the rotation only works for images where the height and width dimensions are the same, such as the "Lena" image of 512 x 512. However, for the "Goldhill" image of 720 x 576, it does not work, and even if it were 576 x 720, it still would not work. The rotation only functions for square images (same height and width).

- __*90° Left Rotation:*__ If we create a 2D matrix, we can see that the rows of pixels actually rotate to the right, but in the output image, the visual effect is a rotation to the left. This is due to the reference margin taken from the original image. In this case, the reference margin to consider is the left margin of the original image. Following the left rotation at the image level, we see that the left margin becomes the bottom margin in the output image, indicating a 90-degree left rotation relative to this reference. However, at the matrix level, the left margin of the matrix rotates 90 degrees to the right, becoming the top margin in the matrix.

- __*90° Right Rotation & Mirroring Effect:*__ If we create a 2D matrix, we can see that the rows of pixels actually rotate to the left, but in the output image, the visual effect is a rotation to the right. This is due to the reference margin taken from the original image. In this case, the reference margin to consider is the right margin of the original image. Following the rotation with mirroring at the image level, we see that the right margin first mirrors, becoming the left margin, and then rotates to the right. Thus, it becomes the top margin of the output image, indicating a 90-degree right rotation with mirroring relative to this reference. However, at the matrix level, the right margin of the matrix rotates 90 degrees to the left and mirrors, becoming the bottom margin in the matrix.

- __*180° Rotation & Inversion:*__ If we create a 2D matrix, we can see that the top rows occupy the positions of the bottom rows and vice versa, without modifying the positions of the intermediate rows. In the output image, a 180-degree inversion effect occurs. In this case, at both the image and matrix levels, the same logic is respected regarding the reference margin. For example, the top margin of the image and matrix becomes the bottom margin and vice versa. However, the center of the image, in terms of pixels and the matrix, remains unchanged.

**Summary:**
- This algorithm performs a rotation of a square image. A non-recursive menu is used to select the types of rotation. To rotate the image, each pixel from the `BufferCopiaLocalIn` 2D array is assigned to the `BufferCopiaLocalOut` 2D array based on a pair of coordinates "x and y."

- Mathematical operations are applied to the pair of coordinates during the pixel assignment process to the `BufferCopiaLocalOut` 2D array.

- The rotations can be of three types: 90° Left, 90° Right, and 180° & Inversion. During the right rotation, a mirroring effect also occurs. Additionally, the matrix-level rotations in the code follow an inverted logic compared to the visual effect obtained. This is better understood by observing the reference margin taken from the input image relative to the output.

- Below is the relevant function and the code section associated with the algorithm used.
```c
void Rotacion_Imagen(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
{
   //....Code for variable declarations, function call for writing the color table and header to the output file, reading image data into memory, and requesting menu option input via keyboard.

   switch(decisionrotacion)
   {
      case 1:  
         
         for( i = 0; i < (*p)->Ancho; i++)
         {
            for( j = 0; j < (*p)->Altura; j++)
            {
               BufferCopiaLocalOut[j][(*p)->Altura-1-i] = BufferCopiaLocalIn[i][j];
            }
         }
         
         break;

      case 2:  
         
         for( i = 0; i < (*p)->Ancho; i++)
         {
            for( j = 0; j < (*p)->Altura; j++)
            {
               BufferCopiaLocalOut[j][i] = BufferCopiaLocalIn[i][j];
            }
         }
         
         break;
      
      case 3: 
      
         for( i = 0; i < (*p)->Ancho; i++)
         {
            for( j = 0; j < (*p)->Altura; j++)
            {
               BufferCopiaLocalOut[(*p)->Ancho-1-i][j] = BufferCopiaLocalIn[i][j];
            }
         }
         
         break;

      case '\n' : case ' ': 
            
         break;
         
      default: 
            
            printf("An incorrect rotation option was entered\n");
            printf("Please enter one of the options again: ");
               
         break;
   }

   //....Code for writing modified image data to the output file, closing files, and printing successful execution messages for the function.
}
```

### Linear Edge Detection Algorithm

**Detailed Explanation:**
- This algorithm performs edge detection using a mask and multiplication operations, where the mask is a 3x3 2D array with preloaded values. The goal is to evaluate what happens with a 3x3 "neighborhood" of pixels relative to a central pixel.

- The algorithm uses 4 loops:  
   * The 1st and 2nd loops traverse all rows and columns in search of a central pixel such that the position of this central pixel in a neighborhood is given by "BufferCopiaLocalOut+x+(long)y * ((*p)->width)".  
   * Then, the 3rd and 4th loops perform a summation of results from the operations on line 1128, obtaining a resulting value from all operations on all pixels in a "neighborhood" relative to the studied central pixel.

- This resulting value of the neighborhood is evaluated at the end of the 3rd and 4th loops. During the evaluation, it is determined whether the central pixel will assume the value of "on or white (255)" or the value of "off or black (0)".

- Repeating this process successively for all pixels in an image will result in the "edges" or outlines being clearly marked in the output image.

- It is important to note that the image under study must necessarily be in grayscale.

**Summary:**
- This algorithm uses a 3x3 convolution mask to detect edges in a grayscale image. It acts as a filter that highlights areas where there are abrupt changes in pixel intensity.

- It evaluates a 3x3 "neighborhood" of pixels relative to a central pixel. The process is repetitive and consists of 4 for-loops. The 1st and 2nd loops traverse the matrix in search of a central pixel to create the "neighborhood" under study. The 3rd and 4th loops perform mathematical summations of pixel intensity values in the "neighborhood." Based on the resulting value, the central pixel assumes 255 (white) or 0 (black).

- Below is the relevant function and the code section associated with the algorithm used.
```c
void Linear_Edge_Detection(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *ImageName, int *decision, int Mask[][3]) 
{
   //....Code for variable declarations, function call for writing the color table and header to the output file, reading image data into memory.

   for(y = 1; y < (*p)->Height-1; y++)
   {
      for(x = 1; x < (*p)->Width-1; x++)
      {
         sum = 0;
         for(i = -1; i <= 1; i++)
         {
            for(j = -1; j <= 1; j++)
            {
               sum = sum + *(BufferCopiaLocalIn+x+i+(long)(y+j) * ((*p)->Width) ) * Mask[i+1][j+1];
            }
         }
         if(sum > 255) sum = 255;
         if(sum < 0) sum = 0;
         *(BufferCopiaLocalOut+x+(long)y * ((*p)->Width)) = sum;
      }
    }

    //....Code for writing modified image data to the output file, closing files, and printing successful execution messages for the function.

}
```

---

## Additional Considerations

### Repositioning The Input File Offset
In the following function, the offset for the beginning of the input file reading is repositioned:
```c
void Escritura_Imagen_HeaderYTablaColores(DatosBMP **p, Paleta_de_colores **p1, FILE **ptr_in, FILE **ptr_out, char *NombreDeImagen, int *decision)
```
Initially, when the file is opened, the offset is located at byte 0. Using `fseek`, it is repositioned to the byte number associated with the "InicioImagen" value stored in the `DatosBMP` struct. This is necessary because some functions, such as `Conversion_RGB_a_Grayscale`, require working with the input file's FILE pointer to manipulate image data bytes and padding bytes. Therefore, it is essential to position the stream's offset correctly within the input file's information block.
```c
fseek(*ptr_in, (*p)->InicioImagen, SEEK_CUR); // Line 603
```

---

## Documentation & Reference Sources
For more information and details, refer to the following links. You can also check the "Documents_And_Datasheets" folder inside the "BMP_Image_Processing_Filters" directory in the "University_Proyects" repository.

- Videos and Notes from the Informatics I Course by Mariano Gonzalez.
- [C_Language_PDFs - ENG](https://github.com/FacundoCostarelli/University_Proyects/tree/master/BMP_Image_Processing_Filters/Documents_And_Reference_Sources/C_Language_PDFs/ENG)
- [Image_Processing_PDFs - ENG](https://github.com/FacundoCostarelli/University_Proyects/tree/master/BMP_Image_Processing_Filters/Documents_And_Reference_Sources/Image_Processing_PDFs/ENG)
- [Processing Images in C - Second Edition - Dwayne Phillips](https://homepages.inf.ed.ac.uk/rbf/BOOKS/PHILLIPS/cips2ed.pdf)
- [BMP File Format](https://gibberlings3.github.io/iesdp/file_formats/ie_formats/bmp.htm)
- [RGB To Grayscale Image Using C - Explanation and Example Code](https://abhijitnathwani.github.io/blog/2018/01/08/rgbtogray-Image-using-C)
- [RGB to Grayscale Conversion Formula](https://www.tutorialspoint.com/dip/grayscale_to_rgb_conversion)
- [RGB to Grayscale Conversion Formula](https://www.dynamsoft.com/blog/insights/image-processing/image-processing-101-color-space-conversion/)
- [Padding Solution - RGB to Grayscale Conversion](https://stackoverflow.com/questions/54173733/convert-rgb-to-grayscale-in-bare-c)
- [Grayscale to Black and White Image Using C - Explanation and Example Code](https://abhijitnathwani.github.io/blog/2018/01/07/Black-and-White-Image-using-C)
- [Rotate Image Using C](https://abhijitnathwani.github.io/blog/2018/01/08/rotate-Image-using-C)
- [Rotate a Rectangular Image by 90 Degrees Clockwise](https://www.geeksforgeeks.org/turn-an-image-by-90-degree/)
- [Image Edge Detection Operators in Digital Image Processing](https://www.geeksforgeeks.org/image-edge-detection-operators-in-digital-image-processing/)
- [{ C } Digital Image Processing From Ground Up™](https://www.udemy.com/course/image-processing-from-ground-uptm-in-c/)
- [Casting to a File Pointer](https://stackoverflow.com/questions/16094936/casting-to-a-file-pointer)
- [How to Dynamically Allocate a 2D Array in C](https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/)

**Note:**  
In this project, I primarily used Stack Overflow forums, GeeksForGeeks, blogs, YouTube videos, PDFs with theoretical and practical explanations of similar example codes, and a Udemy course called [{C} Digital Image Processing From Ground Up™](https://www.udemy.com/course/image-processing-from-ground-uptm-in-c/). It is important to mention that the use of any AI assistance was not allowed, and the entire project had to be developed in a single `.c` source file along with a single `.h` file.

---

## Contribution

All contributions are welcome. Follow these steps to contribute:

  1. Fork the repository.

  2. Create a new branch for your feature or fix:
     - `git checkout -b feature/new-feature`
  3. Make your changes and commit them:
     - `git commit -m "Description of the changes made"`
  4. Push to your branch:
     - `git push origin feature/new-feature`
  5. Create a Pull Request describing your changes.

---

## License
This project is licensed under the GNU General Public License v3.0. You may use, modify and distribute this project under the terms of the license.

---

## Authors
- Facundo Costarelli

---

## Acknowledgments And Collaborations
- Prof Ing Mariano Gonzalez               (Electronics at UTN BA)
- Ing Student Francisco Germaniez         (Electronics at UTN BA)

**Abbreviations:**
- UTN BA --> Universidad Tecnológica Nacional de Buenos Aires.
