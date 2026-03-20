# Translated Text - Theoretical.pdf

Theorists 
 1) printf("%li\n",sizeof(string));  // 10 
 printf("%li\n",strlen(string));  // 6 
 printf("%li\n",sizeof(p));  // 8 
 printf("%li\n",strlen(p));  // 6 
 printf("%li\n",sizeof(*p));  // 1 
 2) A union occupies what the largest of its elements occupies, a structure occupies the sum 
 of what its elements occupy. Furthermore, in a union the same data can be accessed 
 calling it differently. 
 ➢ Declaration: 
 ○ union A{ 
 char U_letter; 
 char U_string[10]; 
 } ; 
 ○ struct Is{ 
 char E_letter; 
 char E_string[10]; 
 } ; 
 ➢ Sizes 
 ○ union Un: 10Bytes 
 ○ structure Is: 11Bytes 
 ➢ Example with names 
 ○ Definition. 
 union A U1; 
 struct Is E1; 
 ○ Access 
 U1.U_letter 
 U1.Ustring 
 E1.E_letter 
 E1.E_string 
 ➢ Example with pointers 
 ○ Definition. 
 union A *PU; 
 struct Is *PE; 
 ○ Assignment 
 PU=&U1; 
 PE=&E1; 
 ○ Access 
 PU->U_letter 
 PU->Ucadena 
 PE->E_letter 
 PE->E_string 
 3) A75Dh-F363h 
 a) In the case of simply having numbers in hexadecimal base, the A75Dh is 
 the decimal 42845 and the F363h is 62307 and as 42845-62307 it is -19462 
 we have that in hexadecimal it is -4C06h. 
 b) In the case of working in 16, the two data are negative numbers because they have 
 its most significant bit therefore we have that, applying 2's complement, 
 the A75Dh is the -58A3h which in decimal is -22691 and the F363h is -0C9Dh 
 corresponding to -3229 in decimal leaving -22691-(-3229)=-19462 in 
 decimal which turns out to be -4C06h then, because it is a negative number, we must 
 use 2's complement in 16 bit for the final result in hexadecimal: the 
 62307 and since 42845-62307 is -19462 we have B3FAh in hexadecimal. 
 c) In the case of working in 32 bit what we really have is 0000A75Dh and 
 0000F363h, which are two positive numbers, in this way we have, equally 
 that in the case where the A75Dh is the decimal 42845 and the F363h is the 62307 and 
 since 42845-62307 is -19462 we have that in hexadecimal it is -4C06h, 
 Since it is negative, you have to apply two's complement to obtain its 
 32-bit representation: FFFFB3FAh.