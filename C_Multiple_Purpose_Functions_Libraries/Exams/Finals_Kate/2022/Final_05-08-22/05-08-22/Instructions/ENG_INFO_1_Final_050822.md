# Translated Text - INFO_1_Final_050822.pdf

Computer Science I  
August 5, 2022  
Final  
Surname and First Name File # of Sheets Teacher  
    
 
Page 1 of 4 
General Rules  
Read each question carefully and ask any questions that may arise.  The correct interpretation of 
statement is part of the evaluation. 
If you take the exam on paper, number the sheets provided. Complete on the first sheet the total amount of 
sheets delivered. Each sheet must be identified with: First name, Last name, File.  
Please hand in this sheet along with the rest of the sheets made.  
 
Theoretical section (Time 15 minutes)  
1) Briefly define what a library is and how it relates to header files. 
 
2)  
a) Justify the differences of the following declarations and initializations: 
 
char *str = "Hello World"; 
char str[100] = "Hello World"; 
 
b) Is it correct? Justify. 
 
#include <string.h> 
 
int main(void) 
{ 
    char *str = "Hello World"; 
    strcpy(str, "Hello"); 
    return 0; 
} 
 
c) Given the following arrays, complete the attached table: 
 
int x[5] 1 2 10 11 12 
 20     
     
int y[5] 0 22 1 15 8 
 40     
     
int z[5] 3 6 -1 14 198 
 60      
 
 
 
 
  Computer Science I  
August 5, 2022  
Final  
Surname and First Name File # of Sheets Teacher  
    
 
Page 2 of 4 
Knowing that array x starts at memory location 20, y at 40 and z at 60. 
 
 
Reference address Value 
and[3]     
and[6]     
and[-2]     
x[12]     
 
 
Practical Section (Time 90 minutes)  
You work in the cryptography department at UTN-FRBA. Due to an attack, he was 
requests to regenerate the “text” encryption algorithms using the following 
functions that must be developed: 
 
1) Function to encrypt characters A-Z 
 
int encrypt_leras ( const char *src , char * dst); 
 
The encryption algorithm is based on "shifting" each of the letters of the source string (src) 
received as the first argument of the function, an integer value. 
This integer value, the value of the "alphabetical offset" must be defined by the function itself 
(encrypt_letters) randomly for each call to it. 
This random displacement can take values between 1 and 25. 
In the event that the new "encrypted" (shifted) value exceeds 'Z', you must continue with the 
'A'. 
Numbers and spaces must remain unchanged (they are not modified) 
The function should return the number of positions the characters have been moved.  
Assume that in dst a pointer to a string of sufficient size to store the text was received 
encrypted. 
Assume that the input string is completely uppercase. 
 
Example:  
“HELLO 54.” If the random number was 3, it should be “KROD 54”. 
 
To generate random numbers you can use the srand and random functions: 
#include <stdio.h> 
 
void srand (unsigned int seed ); 
int rand(void); 
 
  Computer Science I  
August 5, 2022  
Final  
Surname and First Name File # of Sheets Teacher  
    
 
Page 3 of 4 
/* 
Remember that the rand function returns numbers from a pseudo-random sequence between 0 and 
RAND_MAX, and you must call srand appropriately at the beginning of the program to change 
said sequence every time the program is executed 
*/ 
 
2)  
void encrypt_numbers ( const char *src , char *dst); 
 
To encrypt the string numbers, the procedure will be as follows: you must convert the 
number in octal, and then replace each of its digits with the following characters. 
Additionally, the # character must be added to both the beginning and the end of the number 
encrypted.  
 
EX: “305” (461 in octal) “#@+%#” 
 
$0 
1% 
2 & 
3* 
4@ 
5! 
6 + 
7 = 
 
3) In order to use the functions previously implemented, develop a program that 
do the following: 
 
a) Receive the following arguments from the command line: 
 first argument: name of a file (“path” to a file) 
 second argument: text to be encrypted 
The two arguments are mandatory, if you do not receive any of them, end the program and 
indicate what happened with an error message. 
 
b) Encrypt the text received from the command line and store it in a structure. 
 
struct st_encrypted_text  
{ 
 char txt[TXT_MAX_LEN]; 
int offset; 
}; 
  Computer Science I  
August 5, 2022  
Final  
Surname and First Name File # of Sheets Teacher  
    
 
Page 4 of 4 
 
Where the “txt” field is the encrypted textand “displacement” is precisely the one generated 
automatically by the “encrypt_letters” function  
 
c) Finally save the structure to the file received from the command line as 
first argument. Each time the program is run, the structure must be stored in the 
end of file. 
 
 
Note: if you cannot solve a function or module, prototype a function that will help you. 
Allow us to move forward, describe its use and assume that it is a library function in order to continue.