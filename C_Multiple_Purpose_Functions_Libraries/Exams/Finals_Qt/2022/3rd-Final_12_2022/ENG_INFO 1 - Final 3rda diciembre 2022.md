# Translated Text - INFO 1 - Final 3rda diciembre 2022.pdf

F I N A L I N F O R M A T I C A I December 2022 
 
Name and Surname File No. Teacher Qualification Evaluator 
   Name Signature 
  
 
Theoretical section  
 It is not allowed to do it with a PC 
Point 1.-  
Based on the following statements, indicate which of the analogies present in the table are valid when 
moment of accessing a position in the Array, either the address (location) or its content (the data itself). 
#define NN 20 
short intvec[NN]; 
shortint *p=vec; 
 T/F 
A p[10] ≡ *(&Arr[10])  
B &p [10] ≡ *(p+10)  
C &p [10] ≡ (p+8+2)  
D *Arr[10] ≡ *(p+10)  
E p+40 ≡ Arr+40  
F Arr[10] ≡ *Arr+10  
G &Arr[10] ≡ (Arr+10)  
H *(&Arr[10]) ≡ *p+10  
 
Point 2.-  
There is a function for processing one-dimensional arrays, compatible with what we want. 
process. But we only need to process the elements that go from position 3 to 2 before the end of the 
array. 
For example, in the following array of 18 elements the gray area would be sorted: 
                  
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 
 
Knowing that: 
 the number of elements in our array is size (in the example it is 18).  
 The array of which only a part should be processed is vec. 
 That the function first receives the number of elements and then the address of the array 
Which of the following invocations are valid? 
 (there may be 0, 1 or more than one correct answer – check all that you consider correct). 
 
 T/F 
A func_pz ( size-5, vec+5);  
B func_pz ( size-5, vec+=3 );  
C func_pz ( size+5 ,&vec[3]);  
D func_pz ( size-5,&(*vec+3) );  
E func_pz ( size-5, vec[3]);  
F func_pz ( size-5, vec+3);  
 
 
F I N A L I N F O R M A T I C A I December 2022 
 
Name and Surname File No. Teacher Qualification Evaluator 
   Name Signature 
  
 
Practical Section 
 
As part of a development team, you must perform a number of functions to manage a message queue 
(data) multi destination. 
Like any message (or data) queue, the first element inserted is the first to be removed always and 
when it meets the recipient's condition. 
The memory model to use to manage the message queue is at your discretion, and may be a list 
simply linked, a block of compact memory or another. If it is mandatory that it be in the 
HEAP (dynamic memory)  
Under no circumstances is the use of global variables allowed. 
 
Functions to be developed: The following are the minimum functions to be developed. If according to the model of 
selected memory requires other functions, indicate it and develop them.  
 
Function: int init ( ___other_parameters___);  
The init function or macro must implement everything that is necessary to leave the message queue ready 
to be used. 
If your design does not require this function, do not develop it and indicate the conditions that must be met. 
comply so that the message queue is available for use.  
 
Function: int pushMulti ( ___other_parameters___ , const data_t * pdat , uint32_t dest );  
The pushMulti function must insert the data into the message queue, indicating through a bit field 
(bitwise) the destinations of the message. 
 
 pdat: data to be inserted into the message queue. 
 dest: value composed of a wise bit that indicates the destinations to which the message is directed.  
 __other_parameters__: everything you consider necessary for the operation of the function. 
The function should return 1 if the data is inserted correctly. Otherwise it should return 0. 
 
Example of use: 
#define DEST_01 0x0001 
#define DEST_02 0x0002 
……… 
#define DEST_06 0x0020 
……… 
data_t data; 
……… 
    ret=pushMulti ( ___other parameters___ , &data , DEST_01|DEST_03|DEST_04|DEST_06);  
 
Function: int popDest ( ___other_parameters___ , data_t * pdat , uint32_t dest );  
The popDest function must extract the data from the message queue corresponding to the indicated destination (dest).  
 pdat: buffer where to leave the data. 
 dest: value composed of a wise bit that indicates the destinations to which the message is directed.  
The function must return 1 if there is a message for the requesting destination and 0 if the list is empty or not. 
there are messages for the applicant. 
 
Example of use: 
……… 
data_t data; 
……… 
    ret= popDest ( ___other parameters___ , &data , DEST_03);  
 
 
Function: voidrelease(___parameters___);  
The release function must empty the message queue, release all resources, and restoreeer the variables 
corresponding messages indicating that the message queue is empty. 
 
 
General notes:  
 
a.-  
uint32_t is a type definition 
typedef unsigned int uint32_t; 
 
b.- it is not necessary to perform main(), you must only perform the functions requested here and those that 
deem necessary or convenient.  
 
c.- If you do not know how to operate with bit-level arithmetic, you can consider that the destinations are defined 
by a decimal digit, as follows.  
    ret= pushMulti ( ___other parameters___ , &data , 1346);  
indicating that the destinations for this data are 1, 3, 4 and 6. 
Same consideration for the popDest function.