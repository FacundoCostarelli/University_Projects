# Translated Text - final2023_02_17_ConSolucion.pdf

Computer Science I 
 Electronic engineering Final exam 
 02/17/2023 
 Student:______________________________________________________File:___________ Note___________ 
 Delivery conditions: 
 a.  The start time is 7:00 p.m. and the end time is 8:30 p.m. 
 b.  All deliveries made after the deadline will not be taken into account for correction. 
 c.  Approval condition 6 or more points 
 Theoretical part: 
 1. Given the string defined as char v[]="Hello" indicate the option true 
 a.  The strlen(v) is 5 
 b.  The strlen(v) is 4 
 c.  The strlen(v) is 3 
 d.  None of the above 
 2. Indicate which of the following statements is correct 
 a.  int r = 10% 2; 
 b.  float r = 2.7 % 2; 
 c.  float r = 10 % 2.0 
 d.  All of the above are correct 
 3. Given the following variable int var = 0x1234; which prints the following printf("0x%x\r\n", ~(var ^ 0xFFFF)) 
 a.  0xFFFF 
 b.  0x1234 
 c.  0xEDCB 
 d.  None of the above 
 4. Given the following code, indicate which statement is true char v[10]; int n = strlen(v); 
 to.  n is equal to 1 
 b.  n is worth 10 
 c.  Generates a segfault 
 d.  There is a syntax error. 
 Practical part: 
 1. Implement a function that receives a vector of integers and performs two operations on it. 
 to.  Insert at end: Delete the first element of the vector, move the entire place one place to leave the last place free 
 and insert the new value at the end. Example: Insert the number 33 into a 4-position vector. 
 Original vector. 
 11 12 13 14 
 Vector after inserting the value. 
 12 13 14 33 
 b.  Insert at start: Delete the last element of the vector, move everything one place to leave the first place 
 free and insert the new value at the beginning. Example: Insert the number 33 into a 4-position vector. 
 Original vector. 
 11 12 13 14 
 Vector after inserting the value. 
 Computer Science Final 1 - 02/17/2023 1 

 Computer Science I 
 Electronic engineering Final exam 
 02/17/2023 
 33 11 12 13 
 The function prototype is as follows: 
 int insertInt(int *dataPtr, int dataQty, int n, int op)  
 Where: 
 ● dataPtr: Pointer to the vector with integers. 
 ● dataCant: Number of elements in the integer vector. 
 ● n: Number to insert 
 ● op: Operation to be performed. 
 ○ 0: Insert the beginning. 
 ○ 1: Insert at the end. 
 Returns the value removed from the vector. 
 2. Implement a function that splits a file into multiple files of the given size. The prototype of the 
 function is the following 
 int splitFiles(char *name, int size)  
 Where: 
 ● name: Name of the file to be divided. 
 ● size: Size of each file resulting from the division. 
 Returns: The number of files into which the original was divided or a negative number indicating the 
 error. 
 ● -1: If you could not open the source file 
 ● -2: If the number of resulting files is greater than 999 
 ● -3: If the number of resulting files is zero 
 The name of the resulting files will be numbered after the extension, for example if the name 
 The original file is test.txt and this will be divided into 4 parts, the names of the resulting files 
 They will be the following test.txt.000; test.txt.001; test.txt.002; test.txt.003; 
 Computer Science Final 1 - 02/17/2023 2 

 Computer Science I 
 Electronic engineering Final exam 
 02/17/2023 
 Theoretical part solution: 
 1. Option B 
 2. Option A 
 3. Option B 
 4. Option C 
 Practical part solution: 
 int insertInt(int *dataPtr, int dataQty, int n, int op) { 
 int i, value; 
 if (op == 0) { 
 value = *(dataPtr + dataQty - 1); 
 for (i = dataCant - 1; i > 0; i--) { 
 *(dataPtr + i) = *(dataPtr + i - 1); 
 } 
 *(dataPtr + 0) = n; 
 } else { 
 value = *(dataPtr + 0); 
 for (i = 0; i < dataQty - 1; i++) { 
 *(dataPtr + i) = *(dataPtr + i + 1); 
 } 
 *(dataPtr + dataQty - 1) = n; 
 } 
 return (value); 
 } 
 Computer Science Final 1 - 02/17/2023 3 

 Computer Science I 
 Electronic engineering Final exam 
 02/17/2023 
 int splitFiles(char *name, int size) 
 { 
 FILE *fr, *fw; 
 int rVal, totalSize; 
 struct statdata; 
 char partName[64]; 
 char *p; 
 int readSize, i, j; 
 fr = fopen(name, "r"); 
 if (fr == NULL) { 
 return (-1); 
 } 
 rVal = stat(name, &data); 
 if (rVal < 0) { 
 return (-1); 
 } 
 totalSize = data.st_size; 
 p = (char *) malloc (sizeof (int) * size); 
 if (p == NULL) { 
 return (-4); 
 } 
 j = 0; 
 do { 
 readsize = fread (p, 1, sizechild, fr); 
 if (readsize > 0) { 
 sprintf (partName, "%s.%03d", name, j); 
 fw = fopen(partName, "w"); 
 if (fw == NULL) { 
 free(p); 
 fclose(fr); 
 return (-2); 
 } 
 fwrite (p, 1, readSize, fw); 
 fclose (fw); 
 printf ("%s. %d. %d\r\n", partName, readSize, j); 
 j++; 
 } 
 } while (readSize > 0); 
 Computer Science Final 1 - 02/17/2023 4 

 Computer Science I 
 Electronic engineering Final exam 
 02/17/2023 
 free(p); 
 fclose(fr); 
 return (0); 
 } 
 Computer Science Final 1 - 02/17/2023 5