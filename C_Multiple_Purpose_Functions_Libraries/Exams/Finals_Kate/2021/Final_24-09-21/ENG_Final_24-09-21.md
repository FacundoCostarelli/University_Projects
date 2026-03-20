# Translated Text - Final_24-09-21.pdf

National Technological University
Buenos Aires Regional Faculty
Department of Electronic EngineeringComputer Science I
September 24, 20 21
Final
Surname and First Names FileTeacher# Sheets
General Rules
Read each question carefully and ask any interpretation questions that may arise.
Theoretical section (estimated time 30 minutes)
1. What size does it take up in memory?
union info1{
float vector[3];
char str[10];
int *p;
};
On a machine with 32-bit integers and 64-bit pointers.
2. What are the 3 ways you can handle closing a child process
from the parent how to avoid zombie processes?
3. The fork() function, what is it for? What does it return as a return value?
4. What is the difference between using struct or union? In what cases would you use union?
5. In what situations can the use of a function pointer help us? From an example
practical use of function pointers.
Notes for the theoretical part:
A text file must be submitted indicating the point and the letter(s) of the answers that 
consider correct.
You must have at least 6 points to pass. Each question is worth 2 points if the answer is correct. 
and 1 point if the answer is not completely satisfactory.
Page 1 of 3

National Technological University
Buenos Aires Regional Faculty
Department of Electronic EngineeringComputer Science I
September 24, 20 21
Final
Surname and First Names FileTeacher# Sheets
Practical section (estimated time 1 hour and 30 minutes)
1. Create a program that captures system loading information (loadavg) 
using the information provided by the /proc/loadavg file:
0.57 0.49 0.39 1/1106 6472
From this string of characters (separated by spaces) you must take:
• The first value (average of 1 minute of processor usage): 0.57
• And divide the fourth value into two parts:
◦ The number of concurrent processes: 1
◦ The number of processes in the system: 1106
The program must:
a. Read this file once per minute until completing 15 readings. In every reading 
you will need to open and close the file (for the information to be updated). Each of 
These elements (the structure with the 3 aforementioned data: float, int, int) are 
must be saved in a vector (compact list) and once its capacity has been exceeded, it must
write those at the beginning.
b. Every 5 minutes the average of these 15 data should be taken. With mytime() 
should get the time (returns a text string of type YYYYMMDDHHMM, 
for example 202109241245) and send it along with the average to a FIFO. Resulting in a 
semicolon (;) separated string starting with the date and the 3 values 
collected (for example 202109241245;0.18;2.5;1348) .
The named FIFO output will be called stats_loadavg
2. You will need to create another "collector" program that takes the data left by the first program, 
Organize them by date by saving them in one file by day. The result will be a file 
save to disk with the name: stats_system_YYYYMMDD.txt
3. You will need to create a third program that will send the created files (system_stats_*) to 
the IPs described in the “systems_ips.txt” file (one IP per line), this program 
can handle as many children as the supporting machine (maximum one child per core of the 
processor). In the cpuinfo.txt file you will have a number (in ASCII) that represents the 
number of processor cores the system has.
The program will act as a client connecting to the server IPs in the list in 
“systems_ips.txt” using port 3000 via TCP:
1. It will first send a long with the file size.
2. It will then send the full content of the file.
3. Upon completion, the execution of the child will be terminated (in an orderly manner).
This will happen for each IP in the file until the list ends and without exceeding the number of 
simultaneous system processes. To solve this exercise you can use the library 
sockets of the chair presented on the next page.
Page 2 of 3

National Technological University
Buenos Aires Regional Faculty
Department of Electronic EngineeringComputer Science I
September 24, 20 21
Final
Surname and First Names FileTeacher# Sheets
Chair TCP/IP Library Function:
#define PORT 3490 /* The port where it will connect, server */
#define BACKLOG 10 /* Size of the received connection queue */
/*
  Client function connecting to a remote server using TCP
   - Take: Parameters passed by command line
           For example: myclient 127.0.0.1 3490
   - Returns: The created socket ready to be used (if it is !=0)
*/
interconnect (int argc, char **argv);
/* Creates a server socket and returns it
    - Take: The structure with the socket data to be configured already assembled
    - Returns: The socket created to accept connections (if != 0)
*/
intOpen_connection (struct sockaddr_in *);
/* Function that accepts an incoming connection (blocking)
    - Socket: The socket created by connect()
    - Returns: A socket already connected to a client.
*/
intAccept_orders (int socket);
Page 3 of 3