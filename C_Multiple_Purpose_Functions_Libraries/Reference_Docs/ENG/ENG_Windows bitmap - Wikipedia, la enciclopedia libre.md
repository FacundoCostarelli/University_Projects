# Translated Text - Windows bitmap - Wikipedia, la enciclopedia libre.pdf

windows bitmap
DeveloperMicrosoft in 1986
General informationFile extension.bmp or .dibMIME typeimage/x-ms-bmp (not
official)Uniform TypeIdentifiercom.microsoft.bmpMagic numberBMType of formatRaster graphicOpen format?Windows bitmapWindows bitmap (.BMP) is a format
ITSL's own bitmap image
of the Microsoft Windows operating system.
You can save 24-bit images (16.7
million colors), 8 bits (256 shades of
gray) and less. Can be given to these files
compression without loss of quality:
RLE compression (Run-length encoding).
Bitmap files are
consist of addresses associated with
color codes, one for each box in
a matrix of pixels as shown
I would outline a "color the
paintings" for young children.
Normally, they are characterized by being very
inefficient in their use of space
disc, but they can show a good level
of quality.  Unlike the graphics
vectors when rescaled to a size
older, they lose quality. BMP files
They are not used in web pages due to their large size in relation to their
resolution.
Depending on the color depth of the image, each pixel can
occupy 1 or several bytes. They are generally transformed into other formats,
such as JPEG (photographs), GIF (animations) or PNG (drawings and diagrams), which
They use other algorithms to achieve greater compression (smaller file size).
The files begin (header) with the letters BM (0x42 0x4D), which
identifies with the viewing or editing program. In the header it is also
indicates the size of the image and with how many bytes the color of each is represented.
pixel.
The bytes are organized using the little-endian system.
The structure of the header of a .BMPWindows bitmap file is detailed below - Wikipedia, the free encyclopedia https://es.wikipedia.org/wiki/Windows_bitmap
1 of 2 8/14/22, 23:26
Bytes Information
0, 1 File type "BM"
2, 3, 4, 5 File size
6, 7 Reserved
8, 9 Reserved
10, 11, 12,
13Start of the data of the
image
14, 15, 16,
17T header size
bitmap
18, 19, 20,
21Width (pixels)
22, 23, 24,
25Height (pixels)
26, 27 Number of planes
28, 29 Size of each point
30, 31, 32,
33Compression (0=no
compressed)
34, 35, 36,
37T image size
38, 39, 40,
41Horizontal resolution
42, 43, 44,
45Vertical resolution
46, 47, 48,
49T size color chart
50, 51, 52,
53Color counter
important
The bitmap of a .BMP image begins to be read from the bottom up, that is: in
a 24-bit image, the first 3 bytes correspond to the first lower pixel
left.
Obtained from «https://es.wikipedia.org/w/index.php?title=Windows_bitmap&oldid=141594917»
This page was last edited on 10 Feb 2022 at 23:52.
The text is available under the Creative Commons Attribution Share Alike 3.0 License; can
additional clauses apply. By using this site, you agree to our terms of use and our
privacy policy.
Wikipedia® is a registered trademark of the Wikimedia Foundation, Inc., a non-profit organization.
profit.Windows bitmap - Wikipedia, the free encyclopedia https://es.wikipedia.org/wiki/Windows_bitmap
2 of 2 8/14/22, 23:26