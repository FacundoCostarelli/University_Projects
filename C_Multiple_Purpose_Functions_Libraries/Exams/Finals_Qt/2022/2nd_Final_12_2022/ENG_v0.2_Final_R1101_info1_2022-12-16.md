# Translated Text - v0.2_Final_R1101_info1_2022-12-16.pdf

National Technological University December 16, 2022 Final  
Buenos Aires Regional Faculty  
Department of Electronic Engineering  
Computer Science I  
 
 
Surname and First Name File # of Sheets  
   
 
You pass if you add 60% and at least have: 30% practice and 20% theory simultaneously  
T1(20%) T2(20%) P1 (20%) P2 (20%) P3(20%) TOTAL  
      
 
General Rules   
Number the sheets delivered. Read each question carefully, the interpretation of the statement is part of the evaluation.  
Complete on the first sheet the total number of sheets delivered. Do this partial with blue or black ink. Do not use red or 
green please. Each exercise must be done on separate and numbered sheets. Each sheet must be identified with: Name, 
Surname, File. Please hand in this sheet and the rest of the topic along with the exam.  
 
 
Theoretical section TIME 15m [Correct +1, Incorrect -1, Incorrect Justified 0]  
 
1. On Thread check the correct ones:  
● pthread_join() blocks the thread on which it is invoked waiting for the one put in the argument 
finish.  
● pthread_join() does NOT block the thread on which it is invoked waiting for the one it is put into. 
finalize argument.  
● A thread shares heap and stack with the other threads of the same process.  
● A thread does NOT share heap and stack with the other threads of the same process.  
2. About socket tilde the correct ones:  
● The only sockets that exist are tcp/ipv4.  
● TCP/IPv4 sockets determine a connection using 2 IPs, and 2 ports.  
● TCP/IPv4 sockets determine a connection using 1 IP, and 1 ports.  
● TCP/IPv4 sockets determine a connection using 2 IPs and 4 ports.  
● accept() is a blocking function, until a client connects, it is not unblocked.  
● connect() is the function that is called by the client code to connect to a server.  
● A TCP connection is completely closed, if a close() is done on the connection on each side 
established.  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
Practical Section  
National Technological University December 16, 2022 Final  
Buenos Aires Regional Faculty  
Department of Electronic Engineering  
Computer Science I  
 
 
Surname and First Name File # of Sheets  
   
 
You pass if you add 60% and at least have: 30% practice and 20% theory simultaneously  
T1(20%) T2(20%) P1 (20%) P2 (20%) P3(20%) TOTAL  
      
 
General Rules   
Number the sheets delivered. Read each question carefully, the interpretation of the statement is part of the 
evaluation.  
Complete on the first sheet the total number of sheets delivered. Do this partial with blue or black ink. Do not use red or 
green please. Each exercise must be done on separate and numbered sheets. Each sheet must be identified with: Name, 
Surname, File. Please hand in this sheet and the rest of the topic along with the exam.  
A switch is a communications device in packet data networks. It has 
physical interconnect connectors (ports), where a cable with a connector in its 
end (the other end can be connected to a computer). Every device you ship 
messages on the network have an identifying tag called the mac address, which is a number of 6 
bytes.  
  By analyzing the received packet, a switch must be able to identify which port a packet entered. 
packet, and after processing you know which port it has to leave.  
This exam asks you to perform only some parts of the operation of a switch, in order to 
achieve a simulation of its operation.  
 
As part of network simulation software, the following are requested:  
 Build a main that calls the point functions (1,2,3), and adds any 
function that you consider necessary:  
 
1. Make a function that dynamically fills a static array of pointers to struct 
pack of 10 positions. The internal structure of struct package is detailed below, 
Note that each struct package contains 2 struct ports that are used as the port field. 
bits.(the array must be created in the main). With this function we simulate the existence of 
10 packages.  
2. Make a function that randomly fills the char array called MACori and 
MACdes that are part of the structure, and fill in the struct port input and output. 
(In the latter only 1 bit of each struct port input and struct per output can be valid 
'1'). with this itemThe aim is to have a source mac address and a 
random destination mac, along with a random source port (where the 
simulated packet came in), and a random output port (where the packet 
simulated should come out)  
3. Perform a function that prints to the terminal according to the following title.  
a) MAC_Destination MAC_Source Output_Port Input_Port.  
 
 
 
 
 
 
 
 
National Technological University December 16, 2022 Final  
Buenos Aires Regional Faculty  
Department of Electronic Engineering  
Computer Science I  
 
 
Surname and First Name File # of Sheets  
   
 
You pass if you add 60% and at least have: 30% practice and 20% theory simultaneously  
T1(20%) T2(20%) P1 (20%) P2 (20%) P3(20%) TOTAL  
      
 
General Rules   
Number the sheets delivered. Read each question carefully, the interpretation of the statement is part of the 
evaluation.  
Complete on the first sheet the total number of sheets delivered. Do this partial with blue or black ink. Do not use red or 
green please. Each exercise must be done on separate and numbered sheets. Each sheet must be identified with: Name, 
Surname, File. Please hand in this sheet and the rest of the topic along with the exam.  
 
    struct port  
    { 
unsigned char p0:1;  
unsigned char p1:1;  
unsigned char p2:1;  
unsigned char p3:1;  
unsigned char p4:1;  
unsigned char p5:1;  
unsigned char p6:1;  
unsigned char p7:1;  
    }; struct package  
{ 
 unsigned char MACori[6];  
 unsigned char MACdes[6];  
struct port input;  
struct port output;  
};