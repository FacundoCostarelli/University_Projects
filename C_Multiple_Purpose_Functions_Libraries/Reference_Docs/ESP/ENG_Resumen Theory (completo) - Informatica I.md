# Translated Text - Resumen Theory (completo) - Informatica I.pdf

What is an operating system?: An operating system is a collection of programs 
that are responsible for managing the computer's resources, providing 
different users who may be logged into the system the possibility of using the  
hardware and software resources without the need to know details about 
themselves and in a safe way for themselves and others.
API (Application Programming Interface): series of services or functions that the 
Operating System offers the programmer and through these to access the resources of 
system hardware. The implementation of the APIs within the Operating System is 
known as System Calls.
Kernel: The set of programs that constitute the Operating System itself
said and the implementation of System Calls is called kernel. (NOTE 
wiki: It is the main one responsible for providing the different programs with secure access to the 
computer hardware or in basic form, it is responsible for managing resources. 
It is also responsible for deciding which program can make use of a device. 
hardware and for how long).
Shell: It is a user interface. The Shell is a command interpreter that 
in charge of translating the user's requests and invoking the appropriate System Calls 
It takes them forward. This interface is known as console mode.  EXTRA: Every time 
When we type a command, the shell assumes it as a binary executable or as a
script. A binary executable is the result of editing and compiling and linking.
of a specific program. A script is a text file that contains commands 
binaries or other scripts to execute, and which may also include control statements  
of flow.
Device Drivers: To access the hardware, the 
operating system has a very low-level interface called Device Drivers. These 
software components are part of the kernel and their mission is to access the hardware 
system directly. Applications CANNOT perform this access on 
modern operating systems since these are
multi-user where the stability of the system and the applications being run  
within it it must be guaranteed.

File system: A file system is a set of policies defined for the organization 
of the information in files within a storage medium, so that 
allow you to define your location within that medium and enable access to the data 
contained by these in a simple way. The file system manager is a piece of 
software of an operating system that implements the policies defined for the file 
system. EXAMPLES of file system: hard drives, CDs, DVDs. The file system 
manager is responsible for organizing the sectors and tracks of "records, cd's..." in 
files, directories, links, etc., and keep the database updated. 
sectors that correspond to each file, directory, link, etc.
Processes: A process is (trying to try a simplified definition) a 
execution instance of a program, EXTRA: Processes are programs that are executed  
at a given moment. as an example the ls command.  Several 
people running ls simultaneously. Each execution instance of ls is a 
different process. (with the ps command you see the Processes). Every time we run a  
ls to view a directory the system creates a process.
".h" files: These files contain definitions of functions, macros, and variables.
The Compilation: The compilation process involves four successive stages: 
preprocessing, compilation, assembly and linking. To move between programs 
source written by a human to an executable file it is necessary to perform these 
four stages in succession.
1.Pre-processing: In this stage, the directives are interpreted 
preprocessor. Among other things, variables initialized with #define are 
replaced items in the code with their value everywhere their value appears 
name. The preprocessing can be requested by doing: gcc E circle.c > circle.pp and 
examine it by doing: more circle.pp
2. Compilation:      Compilation transforms the C code into the language 
own assembler of our machine's processor.
gcc S circulo.c performs the first two stages by creating the file circulo.s; 
By examining it with more circles, you can see the program in language. 
assemblyadore
3.Assembly:   Assembly transforms the written program into language 
assembler to object code, a binary machine language file 
executable by the processor.  gcc c circle.c gcc c o circle c circle gcc c 
circulo.c or circulo.o Either of these code lines creates the file in 
object code circle.o from circle.c (Perform the 2 steps first 
above). The file type can be checked using the $file command. 
circle.o NOTE: In large programs, where many files are written  
source in C code, it is very common to compile each source file separately,  
and then link all created object modules. These operations are 
they automate by placing them in a file called makefile, interpretable by the 
make command, which is responsible for performing the minimum updates 
necessary whenever any portion of the code is modified in any of the 
the source files.
4. Linker: The C/C++ functions included in our code, such as 
like printf() in the example, they are already compiled and assembled in 
existing libraries in the system. It is necessary to somehow incorporate the 
binary code from these functions to our executable (combine or link them). In  
This is the linking stage, where one or more modules are brought together in code. 
object with the existing code in the libraries.  $ gcc o circle circle.o creates the 
executable circle from the object.
Library: A program library is nothing other than a file that contains 
compiled and functional code and data, which will be incorporated into other programs
when they require them. Code libraries facilitate code reuse 
avoiding having to rewrite them every time we need them and at the same time allowing 
teamwork. A bookstore is made up of:
• Function prototypes (header file(s).h)
• Function definition (source file(s).c)
Types of library:
1. Statics: They are simple collections of object programs grouped into a single 
file whose name typically ends in '.a'. When compiling a program that 
makes use of code contained in a static library, at the time of 
the link phase, the object code of the 
library, that is, it is not necessary to distribute our program with the library 
since it is embedded in our new program. To generate 
a static library we use the utility ar. Before obviously 
we must have generated the object program, compiling with option c. EJ:    
$ gcc c holalib.c We create object in that step..... $ ar rcs libhola.a holalib.o 
We created the library.  Bookstores generally have the prefix in their name. 
“lib”. Therefore, the name for the purposes of the linker is what follows “lib” and 
precedes “.a”.
2. Shared: These libraries are not linked to the program that calls 
functions packaged in them, but rather the references are resolved in the 
start time of the program in question. Yes at the time of loading 
of our program, the necessary libraries are not already loaded in memory, 
The dynamic loader will simultaneously load the program itself into memory. 
that will compose the process triggered by the user, together with the libraries 
that you need.
3.Dynamic Loaded (DL, for Dynamic Loaded): These libraries are loaded into 
different moments of program loading and execution. Its main utility 
is the implementation of modules, or plugins, since these software elements  
They are loaded when they are invoked during the execution of a program. Since the 
From the point of view of their format, they have no differences in Linux with respect to how 
Shared libraries or object programs are built. However, there are 
differences in the code that needs to be written in the application to work 
with these libraries. That is, the application programmer must include 
specific functions that are not required until now in the analyzed models. 
Basically we need to invoke four functions:
•dlopen(): Loads a library and prepares it for use.
•Dlerror():   Returns a string that describes the error generated by the 
other dynamic library management functions.
•Dlsym():   Looks up the value of a symbol present in a library already 
open with dlopen ().
•dlclose():   Close the open library with dlopen().
Development of a program:
Make: make is a tool that allows you to execute a sequence of processes. 
It uses a script, commonly called a makefile. It is able to determine 
automatically which steps of a sequence should be repeated due to the change in 
some of the files involved in the construction of an object, or in a 
operation, and which have not recorded changes since the last time so that it is not 
necessary to repeat them.
Make logic (according to the development of a program): Each object program 
It depends on its corresponding source program, and headers if any. A 
executable will depend on the object programs involved in your project, plus the 
libraries of use in it.

We have three groups clearly differentiated by the colors of the arrows. At the time 
Before putting together a makefile we need to have a clear dependency map.
Once the makefile is set up and running, if we modify the b.c file, we will not
No matter the reason, make it detect the update but instead of repeating all the 
compilations and linking, just recompile to the b.c file, which modifies the b.o object, 
and therefore you must relink the application to reach the executable version that 
contain the changes made in b.c. The interesting thing is that he didn't touch the rest. That is to say 
that does not change is left as it is. Make example above:
What we see at the beginning of the line as a name ending with ':' is called a rule.
If we don't specify anything and just type make simply, make us assume that the rule a 
execute is only the first line with this feature. In our first 
executable example.
If the rule following the character ':' has dependencies, these should 
correspond within the makefile to other rules that are written following the 
dependent rule. In our case excecutable is dependent on a.o and b.o.
Therefore, there must necessarily be one rule for a.o and another for written b.o. 
after the dependent rule. These lines are below with their respective lines. 
dependencies.
Finally, we have written a rule that allows us to clean all the generated files 
from the sources. This can be useful for doing a general rebuild. 
It is executed by doing: “$ make clean” Bypassing the other rules and executing 

just the clean rule. The general format of each rule is:
dependent: dependence
command to generate the dependent from the dependency.
Lines containing commands begin with a tab. Otherwise 
it works.
Variables in 
make: They are placed 
at the beginning of 
code, matching the  
variable constant  
to the command 
replace, and 
access the value 
putting $
(VARIABLE). 
Units 
basics:  
•BIT[b]: Smallest unit of information, it can be worth 0 or 1.
•BYTE[B]: Set of 8 bits.

The Von Newmann model: Proposes:
•Memory: Data and programs are stored in the same memory. 
readingwriting.
◦The contents of this memory are addressed indicating their position without 
import its type.
•Execution:   Sequential  processing  of  instructions (unless  indicated) 
contrary).
•Information:   All of this using Binary Data.
In the current version of software computer architectures 
stored minimally comply with the following characteristics:
•Three hardware systems (interconnected by buses):
◦Central Processing Unit (CPU).
◦A main memory system.
◦An input and output (I/O) system.
•Ability to perform processing sequentially.
•A single path (physical or logical) between memory and CPU (bottleneck of the 
Von Newmann architecture).
 Central Processing Unit (CPU): Its mission is to coordinate and 
control or perform all system operations. Its main parts are 
following:
•Control unit: implements the state machine.
•Arithm Ethical L ogic Unit (ALU).
•Central Memory (MC) or Registers (small memory area and counter 

program).
Main memory system: Stores data and programs.
Entry and exit system: Communication with the outside world.
The central processing unit, the main memory system, and the 
input and output are connected to each other by a system of interconnections (buses).
A typical complete cycle would be:
1)The control unitretrieves the “next” program instruction from the 
main memory (using program counter: IP)
2)The instruction is decoded.
3) The operands following the instruction are taken from memory and 
placed in the records.
4)The ALU performs the requested operation and the result is placed in the registers or 
memory.
SEE IMAGE BELOW.
 A processor is a sequential machine that is in an infinite cycle like that of the computer. 
figure:
Decimal system:  
•You need 10 symbols: (0 1 2 3 4 5 6 7 8 9).

• The value of the number is given by the sum of each digit multiplied by its 
“weight”.
◦For example: 123.4=1⋅102+2⋅101+3⋅100+4⋅10−1
Binary system:   
•I need 2 symbols: (0 1).
•The value of the number is given by the sum of each digit multiplied by its 
“weight”.
◦For example: 101102=1⋅24+0⋅23+1⋅22+1⋅21+0⋅20=16+0+4+2+0=2210
Octal system:  
•I need 8 symbols (0 1 2 3 4 5 6 7).
•The value of the number is given by the sum of each digit multiplied by its 
“weight”.
◦For example: 3778=3⋅82+7⋅81+7⋅80=192+56+7=255-->(255=4⋅82−1)
Hexadecimal system:   
•I need 8 symbols (0 1 2 3 4 5 6 7 8 9 A B C D E F).
•The value of the number is given by the sum of each digit multiplied by its 
“weight”.
◦For example: ABC8=10⋅162+11⋅161+12⋅160=2560+176+12=274810
TICKETS:
4410=1001002:
Divide the number to be converted by the base to convert, until the quotient of a 
number smaller than said base. The result is composed of the last quotient and the remainders  
taken in the reverse sense of the sequence of quotients.
In the case of decimals, it is multiplied by the base and the whole part is the digit. 
searched.
0.375x2=0.75 => 0.0
0.75x2=1.5 => 0.01
0.5x2=1 => 0.011                 2.37510=10.0112
Binary to octal:  
Binary to Hexa:  

If I exceed the maximum number of digits that I manage when adding, I will have problems, for this 
It is called “carry”: 
•Carry    Flag (CF) (Bit 0) Carry. Indicates with 1 an unsigned overflow. Ex: bytes  
255 + 1 (the result is not in the range 0...255).
•Overflow    Flag (OF) (Bit 11) Overflow. Indicates a signed overflow with 1. Ex: 
bytes 100 + 50 (result is not in range of 128...127).
Adding and subtracting within the set of INTEGERS brings us a new problem to the
time to do it on a PC: How to represent negative numbers? For this 
We analyze 4 points:
•Sign and Magnitude

•1's complement
•2's complement
•Shifted Binary
Sign and magnitude: Uses the most significant bit (MSB) to represent the sign and 
the rest for the module. Thus, working with 4 bits we have to:
•00102 is equivalent to 2.
•10102 is equal to 2.
Disadvantages of this method: 
•2 values are consumed to represent zero 0000b=1000b (0=0)
•The same HARDWARE that adds n positive numbers cannot be used to 
add negative numbers. 2+(1)=1       0010b+1001b=1011b (3)
•To perform an addition, first determine if the two numbers have the same 
sign.
◦ Same sign: add significant part
◦ Different sign: subtract the largest from the smallest and assign the sign of the largest.
1's complement: To represent a negative number, each bit is inverted by its 
complement (1 in 0 and vice versa).
01112=7101's Complement: 1000b=0111b=7d (Same problem with 0).
If a carry occurs at the end of the addition/subtraction, add it to the result obtained (end
around carry) 
ex:
The result is in one's complement, so if the answer was negative, 
they reverse the bits. When I added the same signs, it gave me an opposite sign as an answer 
then I went off scale (the last 2 cases).
Two's complement: To represent a negative number, each bit is inverted by its  
complement and 1 is added to it (C2=C1+1).
0111b=7d
 0000b=0d
Now, being negative, the complement is made (taking into account C2 = C1 + 1)
1111b=0000b+1=1d
1000b=0111b+1=8d
It does not require adjustment when adding 2 numbers of different signs. (carry is not added, have 

into account again the sum of signs that corresponds as in case 
above).
Shifted Binary: The absolute value of half the range is added to the signed value.  
minus 1. (The value that I want to represent I add: half of the signed absolute value,  
This absolute value is 2 (for binary) raised to the number of bits to be represented, and 
this value subtracts 1). The result of the account is the value that I have to pass to 
binary) that represents the shifted binary number. Ex:
Floating point: Represents any real number.

Examples
•AxisExample Wikipedia:   
Let's encode the decimal number -118,625 using the IEEE 754 system.
We need to get the sign, the exponent and the fraction.
Since it is a negative number, the sign bit is "1".
First, we write the number (without sign) using binary notation. Look at the binary number system  
to see how to do this. The result is 1110110.101.
Now, let's move the decimal point to the left, leaving only a 1 to its left.
1110110.101=1.110110101·26 This is a normalized floating point number.
The signifier is the part to the right of the decimal point, padded with zeros to the right until 
let's get all 23 bits. That is, 11011010100000000000000.
The exponent is 6, but we need to convert it to binary and shift it (so that the longest exponent 
negative is 0, and all exponents are only non-negative binary numbers). For IEEE format 

754 32-bit, the offset is 127, so 6 + 127 = 133. In binary, this is written as 
10000101.
Putting it all together:
  1 8 23 <-- size in bits
 +-+--------+-----------------------+
 |S|  Exp |     Significant |
 |1|10000101|11011010100000000000000|
 +-+--------+-----------------------+
 31 30 23 22 0 <-- bit index (0 to the right)
    displaced +127
•Utenian example:   
Express in Base 10 the following given numbers in Simple Precision Floating Point form.
And it gives you the following number: 35C1F.
Simple Precision floating point, it is 4 bytes.
So the number is actually 35C1F000.
35C1F000 converted to binary:
00110101110000011111000000000000
And now we divide into: 1 sign bit, 8 exponent, 23 mantissa
0|01101011|10000011111000000000000
Sign: 0 -> +1
Exponent: 01101011 -> 107 -> we subtract the excess -> 107 - 127 = -20 -> as they are powers  
of 2 we are left with -> 2^-20
Mantissa: 10000011111000000000000 -> 2^-1+2^-7+2^-8+2^-9+2^-10+2^-11 = 
0.515136719 -> 1 is added -> 1.515136719
We multiply everything:
+1 * 2^-20 * 1.515136719 = 1.44494697 E -6
Express the following numbers expressed in base 10 in single precision floating point.
And it gives us this number: 165,625.
We have 165,625
We look for its sign: +1 -> 0
We transform the number without the sign to binary
165,625 -> 10100101,101
Exponent:
We move the comma until leaving only a 1 on the left
1.0100101101 -> 7 places -> Mantisa: 0100101101
Exponent: 7 -> Shifted by 127 -> 127+7 = 134 -> In binary: 10000110
We put together the number
0|10000110|0100101101 -> we complete with zeros up to 4 bytes
01000011001001011010000000000000 -> In hexa: 4325A000 -> 4325A
#define NAME value
enum: data type or variable similar to #define. This is done by counting.
enum boolean {NO, YES }; // NO=0, YES =1.
enum months {January =1, February, March, April, May, June, July, August, September, 
October, November, December }; // February =2, March= 3, . . .
enum escapes {BELL = '\a' , TAB = '\t' , NVLIN = '\n'};
if inline: a = (i<0) ? 0 : 100;