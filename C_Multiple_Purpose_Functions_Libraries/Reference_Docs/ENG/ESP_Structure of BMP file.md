# Original Text - Structure of BMP file.pdf

Lab Home pageDepartment of Microelectronic Systems, Faculty of
Electronics, Telecommunications and Informatics,
Gdansk University of Technology
 Polska wersja
Structure of BMP file
Bitmap file in RAM or ROM contains a header, which should be omitted (we do not check it,
assuming that the bitmap already has the required format). After the header there is data section,
containing information on pixels' colours. Single byte (8 bits) contains colour information on two
pixels, 4 MSB concerns pixel on the left side, 4 LSB - pixel on the right side. Colour is encoded as a
4-bit address in colour table (which can be found in BMP header). The colour table used in the file
from this exercise has the following structure (parameter Bits per pixel=4, NumColors=16):
Fig. 1 Colour table
The order of the pixels in BMP file is as follows: from left to right, from bottom to top (first pixel is
from lower left corner of the picture). In the first approach, the picture can be displayed upside
down, just to test the reading data from memory.
Each line is filled with zeros at the end, so each line has a length of multiple of 32 bits. In this
example filling is not used, since each line has 256 pixels, i.e. exactly 32 groups of 32 bits.Structure of BMP ﬁle http://www.ue.eti.pg.gda.pl/fpgalab/zadania.spartan3/z...
1 of 2 8/14/22, 23:19
Fig. 2 Structure of BMP fileStructure of BMP ﬁle http://www.ue.eti.pg.gda.pl/fpgalab/zadania.spartan3/z...
2 of 2 8/14/22, 23:19
