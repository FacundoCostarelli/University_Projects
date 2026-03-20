# Translated Text - InformaticaI_guiaDeClaseCompleta_2022.pdf

Class guide 
 Computer Science I 
 Ing. Jerónimo F. Atencio 
 Version 14 

 Index 
 Index 1 
 About this guide 6 
 Evaluation mode 7 
 Conditions for signing the matter.  7 
 Conditions for the promotion of the subject.  7 
 Carrying out the partial and recovery tests 7 
 Delivery of practical work 8 
 1.Operating systems 9 
 Installing Lubuntu on a virtual machine 9 
 2. Basic commands of terminal 20 
 a. date: Date and time 20 
 b. cal: Calendar 20 
 c. man: Manuals 21 
 d. pwd: Current directory 21 
 e. ls: List 22 
 f. mkdir 22 
 g. cd 22 
 h. touch 22 
 i. rm 22 
 j. rmdir 22 
 k. clear 23 
 3. Installing packages 24 
 4. Installing development tools and man pages 25 
 Installing guest addition in virtualbox 25 
 5. My first program in C 28 
 6. Accessing repository 30 
 Verifying the repositories from the browser.  30 
 Setting up Git for the first time 31 
 Cloning the material repository.  32 
 Updating the local version of the material repository from a remote one (pull) 32 
 Cloning your personal repository.  33 
 Adding or modifying a file to your repository. (commit, push) 34 
 Summary 34 
 7. Numbering systems 35 
 Classiﬁcation of numbering systems 35 
 ● Non-positional 35 
 ● Positional 35 
 Decimal number system 36 
 Binary number system 36 
 1 

 Octal numbering system 36 
 Hexadecimal number system 36 
 Symbols for base numbering systems 2, 8, 10 and 16 37 
 Changing decimal base to binary, octal or hexadecimal 37 
 Base change from octal to binary and binary to octal 39 
 Base change from hexadecimal to binary or from binary to hexadecimal 39 
 Base change octal to hexadecimal or hexadecimal to octal 39 
 Information unit 40 
 Exercises 40 
 8. Data entry and screen printing 41 
 Data types 41 
 Escape sequences 41 
 Format specifiers 41 
 ASCII Table 42 
 Functions used 42 
 How to get the manual for a library function 42 
 Examples 42 
 Exercises 43 
 9. Arithmetic operations - casting.  45 
 Arithmetic operators 45 
 Functions used 45 
 Examples 45 
 Exercises 46 
 10. Conditional if and switch-case statements 48 
 Relational operators 48 
 Logical operators 48 
 Sentences used 48 
 Examples 48 
 Exercises 53 
 11. Repetition for statements; while; do-while 55 
 Assignment, increment and decrement operators 55 
 Sentences used 55 
 Examples 55 
 Exercises 57 
 12. Precompiler directive deﬁnes 59 
 Precompile Directives 59 
 Examples 59 
 Exercises 60 
 13. Functions 61 
 Symbolic constants 61 
 Examples 61 
 Exercises 64 
 2 

 14. Vectors and strings 65 
 Examples 65 
 Exercises 68 
 15. Pointers 70 
 Basic way to use pointers 70 
 Examples 71 
 Exercises 74 
 16. Dynamic memory allocation 76 
 Used functions of stdlib.h 76 
 Examples 76 
 Exercises 78 
 17. Integrative algorithms 79 
 Used functions of string.h 79 
 Used functions of stdlib.h 79 
 Examples 79 
 Exercises 83 
 18. Memory model 88 
 Data types (for 64 bits) 88 
 Scope of use of a variable. (scope of a variable) 88 
 Memory map 90 
 Variable modifiers 90 
 Memory addresses 91 
 Standard streams 94 
 19. Structures 96 
 Operator 96 
 Examples 96 
 Exercises 107 
 20. Archives I 110 
 Used functions of stdio.h 110 
 Ways to open a file 110 
 Required programs 110 
 Commands 111 
 Example of command use.  111 
 Examples 114 
 Exercises 121 
 21. Archives II 122 
 Functions used from stdio.h 122 
 Functions used from sys/stat.h 122 
 Commands 122 
 Example of command use.  122 
 Each column returned by ls -l is: 123 
 3 

 Example of using chmod, we give the file read, write and execute permissions to 
 the owner, the group and others.  123 
 Examples 124 
 Exercises 129 
 22. Pointers, the return!  131 
 Examples 132 
 Exercises 139 
 23. Matrices.  141 
 Examples 141 
 Exercises 143 
 24. Bit-level operations, bit fields. Unions. Enum 145 
 Bit level operators 145 
 Examples 145 
 Exercises 152 
 25. Recursion.  153 
 Exercises 154 
 26. Use of makefile: compilation and linking.  155 
 Required programs 155 
 Build Steps 155 
 Compiletion of various .c and .h 156 
 Makefile 158 
 How to install debugger on Atom 159 
 How to debug a program in C 160 
 Library 162 
 Static library 162 
 Dynamic library 163 
 27. Code Documentation: Doxygen and Indentation 165 
 Required programs 165 
 Doxygen 165 
 Documenting with doxygen 165 
 Example of file documentation with main function.  166 
 Example of file documentation with various functions.  167 
 Example of .h file documentation 168 
 28. Simple linked list I 169 
 Insert a node at the start (stack) 169 
 Print all 170 nodes 
 Release all 170 nodes 
 Counts the number of nodes in the simple linked list 171 
 Insert a node at the end 171 
 Search for a node 171 
 Remove a node 172 
 Insert a node in an orderly manner 173 
 4 

 Main function that demonstrates the use of the functions described above.  174 
 Exercises 175 
 29. Signals 177 
 Functions used 177 
 Commands 177 
 Program, process 177 
 Examples 178 
 Exercises 184 
 30.Threads 185 
 Functions used 185 
 Examples 185 
 31. Sockets 189 
 Functions used 189 
 Examples 189 
 Exercises 190 
 32. Visual interfaces: Qt 191 
 Required programs 191 
 Execution 191 
 5 

 About this guide 
 This document attempts to guide you in learning the C language on the Linux platform, covering the 
 installation of the operating system and the development tools, and then begin to carry out the 
 first programs in C. 
 Each programming section begins by showing relevant information to carry out the 
 section, and then continue with some examples and finish with proposed exercises to perform. 
 It is advisable to follow the order of the guide and the exercises since their difficulty varies 
 increase. The examples are very basic, but they serve to show some aspect of the language and/or how 
 basis for solving the exercises, which is why it is advisable to transcribe and test them. 
 It is recommended that you transcribe the example programs avoiding copying and pasting to take 
 practice in the syntax of the language. Try to read the manuals (use the man command) of the functions, 
 sentences and commands used to understand their use beyond the particular application that is 
 do in this guide. 
 6 

 Evaluation mode 
 The evaluation of the subject will be carried out with two midterms and each one will have two instances of 
 recovery. 
 Conditions for signing the matter. 
 1. Obtain 6 or more points in the first partial. It can be recovered in December and/or February. 
 2. Obtain 6 or more points in the second quarter. It can be recovered in December and/or February. 
 3. Have 75% of the practical work approved. 
 Conditions for the promotion of the subject. 
 1. Obtain 7 or more points in the first quarter. 
 2. Obtain 8 or more points in the first quarter. 
 3. Have 75% of the practical work approved. 
 In this case, if any of the partials do not reach the condition for promotion, they can only be recovered 
 one on the date of December. The grade that remains is that of the last evaluation carried out. 
 Examples: 
 Recovery Partials 
 December Recovery 
 February Work 
 practical 
 approved Result 
 First 
 partial Second 
 partial primer 
 partial Second 
 partial primer 
 partial Second 
 partial 
 7 8 - - - - Yes Promotes 
 6 8 7 - - - Yes Promotes 
 6 8 6 - - - Yes Signature 
 7 7 - 5 - 6 Yes Signature 
 10 7 - - - - Yes Signature 
 10 7 - 7 - 8 Yes Signature 
 7 7 - 4 - 2 Yes Appeal 
 10 10 - - - - Does not appeal 
 Carrying out partial and recovery exams 
 The dates of the midterms and retakes can be found in the planning. In each partial 
 All topics seen up to the previous class, said partial, are included. Both partials will be in person like this 
 as well as recoveries. 
 7 

 Delivery of practical work 
 In the planning you will find the deadlines for the delivery of the exercises of each chapter and which 
 They are deliverable. 
 All exercises must be uploaded to the repository in a folder with the following convention: 
 names exercises_AA where 
 ● AA: It is the chapter number 
 For example: for chapter 8 the folder will be called exercises_08 
 When performing the examples, unless otherwise indicated, we will use lto following naming convention 
 example_AA_BB.c where 
 ● AA: It is the chapter number 
 ● BB: It is the example number 
 For example: example 1 from chapter 8 will be called example08_01.c 
 When performing the examples, unless otherwise indicated, we will use the following naming convention 
 exercise_AA_BB.c where 
 ● AA: It is the chapter number 
 ● BB: It is the exercise number 
 For example: exercise 10 of chapter 9 will be called exercises 09_10.c 
 8 

 1.Operating systems 
 The operating system is the software that manages hardware and software resources in addition to providing 
 an interface for the programs that will run on it.  There are numerous operating systems among 
 which we can mention: 
 ●Linux 
 ●Windows 
 ● MacOS 
 ●Unix 
 In this guide we will use Linux as the operating system, which has several distributions (distros), such as 
 for example: 
 ● Debian (https://www.debian.org) 
 ● Ubuntu (https://ubuntu.com) 
 ● Lubuntu (https://lubuntu.net) 
 ● Mint (https://linuxmint.com) 
 ● Fedora (https://getfedora.org) 
 ● Arch (https://archlinux.org/) 
 A distribution uses the Linux Kernel (https://www.kernel.org/) and is composed of software 
 such as a text editor, software to play music or video, browser, a 
 file manager, etc. In addition to documentation, GNU tools, a package manager and 
 its libraries along with some user interface that can be a window manager or a 
 terminal. The choice of distribution usually depends on the use that will be given and the tastes of the user, in 
 In the case of this guide we will use Lubuntu. 
 Installing Lubuntu on a virtual machine 
 If you don't have experience installing operating systems, installing it in a virtual machine is a 
 a simple and safe way to learn how to do it, given that any mistake could delete the image and 
 try again without affecting your native operating system. When you gain some experience in Linux 
 It is advisable that you install it natively on your computer. The following steps assume that your 
 native system is Windows. 
 to.  Download an LTS (Long Term Support) version of the Lubuntu distribution (https://lubuntu.net) 
 b.  Download the VirtualBox software (https://www.virtualbox.org/) which is what we will use to make 
 the virtual machine. You must download the one that says Windows Host. 
 c.  Install VirtualBox, it is advisable to restart the computer when the installation is complete. 
 9 

 d.  Once VirtualBox is opened, 
 create a new virtual machine 
 clicking on the New button 
 e.  In the next window you 
 configure the following 
 ● The machine name 
 virtual 
 ● The folder where the 
 virtual disk (We leave the 
 that is configured) 
 ● The type of system 
 operational, we select 
 linux 
 ● The version (distribution) of the 
 operating system 
 10 

 f.  The memory that 
 is reserved for our 
 virtual machine, initially 
 you can leave the proposed value 
 for installation, in the case 
 If it works slowly, you can 
 then assign more. It must be 
 keep in mind that memory 
 that we reserve for the 
 virtual machine is memory that 
 the physical machine will not use. 
 g.  The option is sectioned for 
 use a virtual hard drive 
 new 
 11 

 h.  Disc type selection 
 virtual rigid. 
 Yo.  The option is selected to 
 create the virtual hard drive 
 of fixed size. 
 12 

 j.  Select the size of the 
 virtual hard disk, with at 
 less 12GB should be enough 
 for a basic installation. 
 k.  When disk creation is complete 
 rigid virtual you reach a 
 screen like this. If 
 select the virtual machine 
 created and given start. 
 13 

 l.  The image is selected 
 Linux that you want to install. The 
 image to install usually has 
 .iso extension 
 14 

 From this point the installation of the operating system is carried out 
 m.  Once I start the installer, 
 option is selected 
 Install Lubuntu  
 n.  The language is selected for the 
 installation. 
 15 

 or.  The first option selected 
 it is for updates 
 are downloaded during 
 installation. The second option 
 is to allow it to be installed 
 third party software. 
 p.  Since the virtual hard disk 
 You don't have anything installed, 
 select the delete option 
 the entire album and iinstall 
 Lubuntu 
 16 

 q.  Request confirmation about 
 the changes to be made in the 
 virtual hard disk. 
 r.  It indicates the place where 
 we are for 
 regional configurations. 
 17 

 s.  The layout of the 
 keyboard. 
 t.  Set the name of 
 username, name 
 computer, passwords (Try 
 not to forget passwords) 
 18 

 u.  We wait for the 
 installation. 
 v.  Once the 
 installation, we restart the 
 computer. 
 Warning: 
 Remember the configured password and username. 
 . 
 19 

 2. Basic terminal commands 
 This section explores some useful terminal commands. To open the terminal you can use the 
 shortcut CTRL+ALT+T or the menu seen in the following image. 
 to.  date: Date and time 
 With the -a option Show all manuals that contain intro 
 jerome@linuxVm:~$ date 
 Sun Mar 21 21:45:40 -03 2021  
 b.  cal: Calendar 
 Shows the calendar of the month. 
 jerome@linuxVm:~$ cal 
 March 2021  
 sun lu tu mi thu fri sat  
 1 2 3 4 5 6  
 7 8 9 10 11 12 13  
 14 15 16 17 18 19 20  
 21 22 23 24 25 26 27  
 28 29 30 31  
 20 

 Shows the calendar of a particular month and year. 
 jerome@linuxVm:~$ cal -m 12 2001  
 December 2001  
 sun lu tu mi thu fri sat  
 1 
 2 3 4 5 6 7 8  
 9 10 11 12 13 14 15  
 16 17 18 19 20 21 22  
 23 24 25 26 27 28 29  
 30 31 
 c.  man: Manuals 
 Shows the manual for a command or function that is passed as a parameter. The manual has 
 of seven sections described below. 
 1. Executable programs or shell commands 
 2. System calls (Functions provided by the kernel) 
 3. Calls to the library. 
 4. Special files. (Those found in /dev) 
 5. File formats and conventions. 
 6. Games 
 7. Miscellaneous 
 8. System administration commands 
 9. Kernel routines 
 To obtain the manual of the manual, once inside the manual if you want to exit you must press the 
 letter q 
 jerome@linuxVm:~$ man man 
 To obtain the manual date 
 jerome@linuxVm:~$ man date  
 To search the manual 1 date 
 jerome@linuxVm:~$ man 1 date  
 With the -a option Show all manuals that contain intro 
 jerome@linuxVm:~$ man -a intro  
 d.  pwd: Current directory 
 Print the name of the current directory 
 jerome@linuxVm:~$ pwd 
 /home/jerome  
 21 

 e.  ls: List 
 List the contents of a directory 
 jerome@linuxVm:~$ ls 
 Desktop Documents Music Pictures Public Templates Videos  
 Lists the contents of a directory including the date and time of last modification, among others. 
 data. 
 jerome@linuxVm:~$ ls -l 
 total 32  
 drwxr-xr-x 2 info1 info1 4096 Apr 6 2020 Desktop  
 drwxr-xr-x 4 info1 info1 4096 Mar 24 00:18 Documents  
 drwxr-xr-x 2 info1 info1 4096 Apr 6 2020 Music  
 drwxr-xr-x 2 info1 info1 4096 Apr 6 2020 Pictures  
 drwxr-xr-x 2 info1 info1 4096 Apr 6 2020 Public  
 drwxr-xr-x 2 info1 info1 4096 Apr 6 2020 Templates  
 drwxr-xr-x 2 info1 info1 4096 Apr 6 2020 Videos  
 f.  mkdir 
 Create a new directory. Create a directory called testDir 
 jerome@linuxVm:~$ mkdir testDir  
 jerome@linuxVm:~$ ls 
 Desktop Documents Music Pictures testDir Public Templates  
 Videos 
 g.  cd 
 It allows me to move between directories. 
 I move to the directory with the name testDir 
 jerome@linuxVm:~$ cd testDir  
 jerome@linuxVm:~/testDir$  
 h.  touch 
 Create an empty file or update the last access or last modification date. 
 jerome@linuxVm:~/testDir$ touch testFile.txt  
 jerome@linuxVm:~/testDir$ ls 
 testFile.txt  
 i.  rm 
 Delete a file 
 jerome@linuxVm:~/testDir$ rm testFile.txt  
 j.  rmdir 
 Delete a directory. 
 Before deleting a directory I must exit it, to do this I use the cd command 
 22 

 jerome@linuxVm:~/testDir$ cd .. 
 jerome@linuxVm:~$ rmdir testDir  
 k.  clear 
 Clean the screen 
 jerome@linuxVm:~/testDir$ clear 
 23 

 3. Installing packages 
 Each Linux distribution has a package manager, in the case of Lubuntu it is apt or apt-get.  
 A package manager is software that automates the process of installing, updating, configuring, and 
 uninstalling software on your computer. 
 As an example we are going to install VLC, which is an audio and video player. 
 jerome@linuxVm:~$ apt install vlc  
 E: Could not open lock file /var/lib/dpkg/lock-frontend - open (13:  
 Permissionn denied)  
 E: Unable to acquire the dpkg frontend lock  
 (/var/lib/dpkg/lock-frontend), are you root?  
 After executing the apt install vlc command, it returns an error indicating that it does not 
 We have sufficient permissions, so we must use sudo before the command. After writing 
 sudo apt install vlc and running it will ask us for our password. Finally it will tell us the 
 necessary space for the installation, then it will ask us and we want to continue so we press 
 And starting with the installation 
 jerome@linuxVm:~$ sudo apt install vlc  
 Reading package lists... Done  
 Building dependency tree  
 Reading state information... Done  
 The following additional packages will be installed:  
 fonts-freefont-ttf vlc-bin vlc-l10n vlc-plugin-notify vlc-plugin-qt  
 vlc-plugin-samba  
 vlc-plugin-skins2 vlc-plugin-video-splitter vlc-plugin-visualization  
 The following NEW packages will be installed:  
 fonts-freefont-ttf vlc vlc-bin vlc-l10n vlc-plugin-notify  
 vlc-plugin-qt vlc-plugin-samba  
 vlc-plugin-skins2 vlc-plugin-video-splitter vlc-plugin-visualization  
 0 upgraded, 10 newly installed, 0 to remove and 410 not upgraded.  
 Need to get 11.7 MB of files.  
 After this operation, 57.0 MB of additional disk space will be used.  
 Do you want to continue? [Y/n]  
 To verify that the installation was completed correctly 
 jerome@linuxVm:~$ vlc 
 24 

 4. Installing development tools and man pages 
 To begin we will install the basic development tools. 
 ● The gcc compiler 
 ● Git version control software 
 ● The atom text editor (https://ﬂight-manual.atom.io/getting-started/sections/installing-atom/) 
 To carry out the installation we will execute the following command, in which we include all the packages to 
 install and the -Y option so that it does not ask us if we agree with the installation. 
 jerome@linuxVm:~$ sudo apt install gcc git -y  
 In the case of installing the text editor we must follow the following commands, which 
 They appear on two lines because they do not enter this document on the same line. 
 jerome@linuxVm:~$ wget -qO - https://packagecloud.io/AtomEditor/atom/gpgkey 
 | sudo apt-key add - 
 jerome@linuxVm:~$ sudo sh -c 'echo "deb [arch=amd64] 
 https://packagecloud.io/AtomEditor/atom/any/ any main" > 
 /etc/apt/sources.list.d/atom.list' 
 jerome@linuxVm:~$ sudo apt-get update  
 Finally we execute 
 jerome@linuxVm:~$ sudo apt install atom -y  
 To install the development manuals you must execute the following command 
 jerome@linuxVm:~$ sudo apt install manpages-dev manpages-posix-dev -y 
 If we also need the manuals in Spanish, you can execute the following command 
 jerome@linuxVm:~$ sudo apt install manpages-es manpages-es-extra -y 
 Installing guest addition in virtualbox 
 Guest additions is a software package to add some features to the virtual machine, such as 
 for example being able to use it in full screen or sharing the clipboard. 
 To install them we have to carry out the following procedure 
 a.  Start the virtual machine and log into the operating system. 
 b.  Go to the next menu and select Insert Guest Additions CD image...  
 25 

 c.  The following should appear on the operating system desktop inside the virtual machine: 
 icon. 
 d.  Select the icon and press right button. In the context menu select Open In terminal 
 (This will open a new terminal) 
 26 

 e.  In the terminal run the following commands 
 jerome@linuxVm:/media/jerome/VBox_Gas_6.0.4$ sudo apt install  
 build-essential  
 jerome@linuxVm:/media/jerome/VBox_Gas_6.0.4$  
 sudo ./VBoxLinuxAdditions.run  
 f.  Restart the virtual machine. 
 27 

 5. My first C program 
 1. Once I start Linux open a terminal (press CTRL+ALT+T to open it) 
 2. From the terminal, create a directory called firstProgram using the mkdir command. 
 jerome@linuxVm:~$ mkdir firstProgram  
 3. Move to the created directory using the cd command. 
 jerome@linuxVm:~$ cd firstProgram  
 4. Open the atom text editor by typing the following command in the atom & console (the ampersand 
 it is so that the command is executed in the background) 
 jerome@linuxVm:~/firstProgram$ atom & 
 Another option to open the atom is using the menu 
 5. Create a new file, select the menu File->New File. 
 28 

 6. Go to menu File->Save as.. (File->Save As) and save the file with the following name 
 hello.c (respect the case of the name) in the directory 
 ~/firstProgram/  
 7. In the created file copy the following program and save it. 
 #include <stdio.h>  
 int main(void)  
 { 
 printf ("Hello!!!\r\n");  
 return (0);  
 } 
 Warning: 
 Verify that you saved the code. 
 8. Go back to the console, compile the program with the following command. 
 jerome@linuxVm:~/firstProgram$ gcc hello.c -Wall -ohello.out  
 This will generate an output file named helloWorld.out. Verify your creation by listing the 
 directory files with the command ls -las 
 jerome@linuxVm:~/firstProgram$ ls 
 hello.c hello.out  
 9. Run the compiled program, typing ./hello.out in the console  
 jerome@linuxVm:~/firstProgram$ ./hello.out  
 Hello!!! 
 29 

 6. Accessing the repository 
 It will be shown in simple steps how to use git to perform simple tasks, first checking the 
 repositories from a browser and then using some git functions from the console. 
 Verifying the repositories from the browser. 
 1. Open the browser window (Firefox, Chrome, chromium, etc.) and go to the address 
 https://gitlab.frba.utn.edu.ar and log in with your Sinap username 
 2. Access a page similar to this one where there are at least two repositories 
 a.  material: It is the repository to download the material of the subject 
 b.  A repository with its SinAp user: This repository will be used to upload jobs 
 practical. 
 Select the material repository 
 30 

 3. Access a page like the following 
 4. By selecting the icon indicated in red you can download the content of the repository. 
 Setting up Git for the first time 
 Before starting to use git you must execute the following commands to conﬁgure your user and 
 email. Replace what is indicated in blue with your data 
 jerome@linuxVm:~$ git config --global user.name " user " 
 jerome@linuxVm:~$ git config --global user.email " email " 
 Using the following command confirm that the data was set correctly. 
 jerome@linuxVm:~$ git config --global --list  
 31 

 Cloning the material repository. 
 1. Obtain the address of the material repository. To do this, enter the repository to clone, press the 
 Clone button and copy the address marked with the red box. 
 2. The address obtained in the previous point is placed after the git clone command. They replace 
 indicated in blue by the address obtained in the previous point. 
 jerome@linuxVm:~$ git clonerepositoryAddress  
 After executing the command to perform the cloning, you will be asked for the username and password to 
 access the repository. If the data is correct, a directory will be created with the name of the 
 repository which you can access with the cd command. 
 For example, for the material repository it would be 
 j erome@linuxVm:~/jatencio$ git clone  
 https://gitlab.frba.utn.edu.ar/info1-r1053/material.git  
 Cloning into 'material'...  
 Username for 'https://gitlab.frba.utn.edu.ar':  
 Password for 'https://jatencio@gitlab.frba.utn.edu.ar':  
 remote: Enumerating objects: 3, done.  
 remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 3  
 Unpacking objects: 100% (3/3), done.  
 Checking connectivity... done.  
 Updating the local version of the material repository from a remote one (pull) 
 1. Enter the material repository folder using the cd command. 
 jerome@linuxVm:~$ cd material  
 jerome@linuxVm:~/material$  
 2. We pull the remote repository. (What is in blue you should replace it with your user name. 
 user) 
 32 

 jerome@linuxVm:~/material$ git pull  
 Username for 'https://gitlab.frba.utn.edu.ar': user 
 Password for 'https://usuario@gitlab.frba.utn.edu.ar':  
 remote: Enumerating objects: 5, done.  
 remote: Counting objects: 100% (5/5), done.  
 remote: Compressing objects: 100% (3/3), done.  
 remote: Total 3 (delta 1), reused 0 (delta 0), pack-reused 0  
 Unpacking objects: 100% (3/3), done.  
 From https://gitlab.frba.utn.edu.ar/info1-r1053/material  
 c6d8a8a..97a0a6a master -> origin/master  
 Updating c6d8a8a..97a0a6a  
 Fast-forward  
 README.md | 5++---  
 1 file changed, 2 insertions(+), 3 deletions(-)  
 Cloning your personal repository. 
 3. Get the repository address of your personal repository. for himor enter the repository at 
 clone, press the Clone button and copy the address marked with the red box. 
 4. The address obtained in the previous point is placed after the git clone command. They replace 
 what is indicated in blue by the address obtained in the previous point. 
 jerome@linuxVm:~$ git clonerepositoryAddress  
 After executing the command to perform the cloning, you will be asked for the username and password to 
 access the repository. If the data is correct, a directory will be created with the name of the 
 repository which you can access with the cd command. 
 For example, for the material repository it would be 
 j erome@linuxVm:~/jatencio$ git clone  
 https://gitlab.frba.utn.edu.ar/info1-r1053/2021/usuario.git  
 Cloning into 'user'...  
 Username for 'https://gitlab.frba.utn.edu.ar':  
 33 

 Password for 'https://usuario@gitlab.frba.utn.edu.ar':  
 remote: Enumerating objects: 3, done.  
 remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 3  
 Unpacking objects: 100% (3/3), done.  
 Checking connectivity... done.  
 Adding or modifying a file to your repository. (commit, push) 
 1. We are going to add the first C program we made to our remote repository. For this 
 We copy the file hello.c from the firstProgram directory to the directory of the 
 repository. They replace what is indicated in blue with their username, which in this case coincides with 
 the name of the repository. 
 j erome@linuxVm:~$ cp ./firstProgram/hello.c ./ user 
 2. Enter the material repository folder using the cd command. (What is in blue should 
 replace it with your username) 
 j erome@linuxVm:~$ cd ./ user 
 3. To start tracking a file we have to execute the following command line, this 
 You will only need to do this once for each file you want to add to the repository. 
 j erome@linuxVm:~/user$ git add ./hello.c  
 4. To make the commit we execute the following command. After the -m we can place a legend 
 that identifies the commit. The commit stores our change in the local repository 
 j erome@linuxVm:~/user$ git commit -m "First Commit"  
 5. Finally we upload the change to the remote repository 
 j erome@linuxVm:~/user$ git push  
 6. Every time you modify a file that is already added for tracking you must perform 
 only commit and push operations to upload changes to the remote repository 
 Summary 
 ● git clone 
 ● git add 
 ● git commit 
 ● git push 
 ● git pull 
 ● git config 
 ● git status 
 34 

 7. Numbering systems 
 A number system is a set of rules that allows numbers to be represented using 
 symbols. The numbers that we construct in each number system are abstract entities that 
 They allow us to represent whole quantities or fractions of whole quantities. The system of 
 numbering that we use in everyday life is Decimal (or base 10) which consists of ten symbols 
 (numbers zero to nine) 
 Classiﬁcation of numbering systems 
 We can classify the numbering systems into two: 
 ● Non-positional 
 They are the most primitive, representing quantities by making marks on a stick or knots on a 
 rope for example. Its main characteristic is that the brands have the same value without 
 regardless of the position they occupy. This results in addition and subtraction operations consisting 
 counting, but it is more difficult to perform other operations. 
 ● Positional 
 In these number systems any number can be represented with a set 
 limited number of symbols, the number of symbols being what defines the basis of the 
 numbering. Its main characteristic is that a certain symbol takes on a different value 
 depending on the position it occupies and each position corresponds to successive powers of the 
 basis of the numbering system. Although it is possible to define any integer as a base 
 of a numbering system, we will only analyze four of the following: 
 ○ Binary, base two 
 ○ Octal, base eight 
 ○ Decimal, base ten 
 ○ Hexadecimal, base sixteen 
 Generically we can construct a number from any base like 
 Where: 
 ○ b: Basis of the numbering system 
 ○ A: Valid number of the numbering system 
 ○ a j : Valid symbols (b-1 symbols) 
 35 

 ○ n + 1: Number of symbols in the integer part 
 ○ k: Quantity de digits of the fractional part 
 Decimal number system 
 Its base is ten and valid symbols are: 0; 1; 23; 4; 5; 6; 7; 8; 9 
 Example: 
 Binary number system 
 Its base is two and valid symbols are: 0; 1 
 Example: 
 Octal numbering system 
 Its base is eight and the valid symbols are: 0; 1; 23; 4; 5; 6; 7 
 Example: 
 Hexadecimal number system 
 Its base is sixteen and valid symbols are: 0; 1; 23; 4; 5; 6; 7; 8; 9; TO; B; C; D; AND; f 
 Example: 
 36 

 Symbols for base numbering systems 2, 8, 10 and 16 
 Decimal Binary Octal Hexadecimal 
 0 0000 0 0 
 1 0001 1 1 
 2 0010 2 2 
 3 0011 3 3 
 4 0100 4 4 
 5 0101 5 5 
 6 0110 6 6 
 7 0111 7 7 
 8 1000 10 8 
 9 1001 11 9 
 10 1010 12 A 
 11 1011 13 B 
 12 1100 14 C 
 13 1101 15 D 
 14 1110 16 E 
 15 1111 17 F 
 Changing decimal base to binary, octal or hexadecimal 
 The procedure to convert a decimal number into binary, octal or hexadecimal is 
 ● In taking the decimal number A and dividing it by the base you want to convert. 
 ● Then the operation is repeated, dividing the quotient obtained by the destination base, until the 
 quotient is less than the destination base. 
 ● The result is obtained by concatenating the remains obtained from the successive divisions taking the 
 first remainder as the least significant digit (LSB) of the number in the base 
 destination and the last quotient corresponds to the most significant digit (MSB: Most Significant Bit) of the 
 number in the destination base. 
 37 

 Example: Convert the number 89 in decimal base to binary 
 89 2 
 (LSB) 1 44 2 
 0 22 2 
 0 11 2 
 1 5 2 
 1 2 2 
 0 1 (MSB) 
 89 10 = 1011001 2 
 Example: Convert the number 89 in decimal base to octal 
 89 8 
 (LSB) 1 11 8 
 3 1 (MSB) 
 89 10 = 131 8 
 Example: Convert the number 89 in decimal base to hexadecimal 
 89 16 
 (LSB) 9 5 
 89 10 = 59 16 
 Example: Convert the number 2639 in decimal base to hexadecimal 
 2639 16 
 (LSB) 15 (F) 164 16 
 4 10 (A) (MSB) 
 2639 10 = A4F 16 
 38 

 Base change from octal to binary and binary to octal 
 ● Octal to binary 
 The method to convert an octal number to binary is to take each octal digit and 
 convert it to binary independently. For example to convert the number 4126 10 to 
 binary 
 Octal 4 1 2 6 
 Binary 100 001 011 110 
 4126 8 = 100001011110 2 
 ● Binary to octal 
 The method is similar to the previous one, but in this case three binary digits are grouped 
 starting from the least significant bit and then converting each group individually. By 
 example to convert the number 11101111000 2 
 Binary 11 101 111 000 
 Octal 3 5 7 0 
 11101111000 2 = 3570 8 
 Base change from hexadecimal to binary or from binary to hexadecimal 
 The method to perform these conversions is the same as that explained in the previous section with the exception 
 that binary digits are grouped into 4 digits. Examples 
 ● Hexadecimal to binary 
 Hexadecimal F 1 C 5 
 Binary 1111 0001 1100 0101 
 F1C5 16 = 1111000111000101 2 
 ● Binary to hexadecimal 
 Binary 0011 1010 1011 0000 
 Hexadecimal 3 A B 0 
 0011101010110000 2 = 3AB0 16 
 Base change octal to hexadecimal or hexadecimal to octal 
 This conversion from hexadecimal to octal is achieved by intermediately transforming the number 
 hexadecimal to binary, and then transform that binary number to octal. For the octal case a 
 hexadecimal the same process of passing intermediately to binary is carried out. 
 39 

 information unit 
 A bit (binary-digit) is the minimum unit of information available in digital systems, it can take only 
 two values. The bits can be grouped in different quantities, such as: 
 ● Nibble: It is a set of 4 bits, in which a hexadecimal digit can be represented. 
 ● Bytes: It is a set of 8 bits. 
 ● Word: Generally it is the grouping of several bytes, for example: 
 ○ Word16: Groups 2 bytes, which are 16 bits 
 ○ Word32: Groups 4 bytes, which are 32 bits 
 ○ Word64: Groups 8 bytes, which are 64 bits 
 Exercises 
 Complete the following table with the numbers in the corresponding bases 
 Binary Octal Decimal Hexadecimal 
 10100101 
 765 
 2019 
 A5A5 
 FD07ACD367E 
 291338389 
 205037 
 11101001 
 Verify the results using the Lubuntu calculator 
 40 

 8. Data entry and printing on pasize 
 Data types 
 Data type Size in bytes Representation range 
 char 1 (8 bits) [(-1) 2 7 ~ (2 7 -1)] [-128 ~ 127] 
 int 4 (32 bits) [(-1) 2 31 ~ (2 31 -1)] [−2,147,483,648 ~ 2,147,483,647] 
 float 4 (32 bits) See IEEE 754 
 double 8 (64 bits) See IEEE 754 
 Escape sequences 
 Escape Sequence Description 
 \nLine break. Advances the cursor to the next line. 
 \r Carriage return. Place the cursor at the beginning of the line. 
 \t Horizontal tab. Move the cursor one tab. 
 \\ Print the counterbar. 
 \" Print the double quotes 
 Format Specifiers 
 Specifier 
 format Data type Description 
 %d int Prints/converts the data to a decimal integer 
 %3d int Prints/converts the data into a 3-digit decimal integer, if any 
 less leave spaces in front when printing. 
 %03d int Prints/converts the data into a 3-digit decimal integer, if any 
 fewer digits places leading zeros when printing. 
 %c char Prints/converts the data to an ASCII character 
 %o int Prints/converts the data to an octal integer 
 %x int Prints/converts the data into a hexadecimal integer 
 %f ﬂoat Prints/converts the data to the following format (-) dd.dddddd 
 %lf double Prints/converts the data to the following format (-) dd.dddddd 
 %2.3f ﬂoat Prints/converts the data to the following format (-) dd.ddd 
 2 digits before the decimal point and 3 after the decimal point 
 %% ---- Print % 
 41 

 ASCII table 
 You can get ascii table from terminal 
 jerome@linuxVm:~$ man ascii  
 Functions used 
 Header File Function 
 printf stdio.h 
 scanf stdio.h 
 How to get the manual for a library function 
 If I ask for the printf man as shown below, it will give me the manual for the printf command and not the 
 printf function. You may notice that at the top next to printf a number appears between 
 parentheses indicating the manual number, in this case 1. 
 jerome@linuxVm:~$ man printf  
 PRINTF(1) User Commands PRINTF(1)  
 NAME 
 printf - format and print data  
 SYNOPSIS  
 printf FORMAT [ARGUMENT]...  
 printf OPTION  
 …. 
 In order to see the manual of the library function we can use the -a option and scroll through them until 
 find what we are looking for or search in manual 3 as shown below. 
 jerome@linuxVm:~$ man 3 printf  
 Examples 
 1. Program that prints a legend on the screen requesting an integer and then prints it 
 #include <stdio.h>  
 int main(void)  
 { 
 int var;   //-- Integer variable declaration --  
 /* I print a legend on the screen */  
 printf ("Enter a number:\r\n");  
 /* I wait for the user to enter an integer */  
 scanf("%d", &var);  
 42 

 //-- I print a legend and the value stored in the variable --  
 printf ("The number entered is: %d\r\n", var);  
 //-- I print the number in hexa --  
 printf ("The number entered is (in hexa): %x\r\n", var);  
 return (0);  
 } 
 Write and save the above code in a file called example08_00.c 
 jerome@linuxVm:~$ gcc example08_00.c -Wall -oexample08_00.out  
 jerome@linuxVm:~$ ./example08_00.out  
 Exercises 
 1. Implement a program that, using the printf function, prints the legend Hello World on the screen. 
 The on-screen legend should look like this: 
 jerome@linuxVm:~$ ./ejercicio08_01.out  
 Hello World  
 Remember to place \r\n at the end of the legend so that it goes down one line 
 2. Implement a program in which a variable of type int called varInt initialized with the 
 value 376 and then prints it on the screen using the printf function. The program output is shown 
 below. 
 jerome@linuxVm:~$ ./ejercicio08_02.out  
 The variable varInt contains the value 376  
 3. Repeat the above program with the following data types and seed values 
 a.  char: varChar = 'c'; 
 b.  int: varInt = 0x55AA; 
 c.  int: varInt = 017; 
 d.  ﬂoat: varFloat = 1.27; 
 e.  double: varDouble = 2.7172; 
 Warning: 
 The period, not the comma, is used to separate the integer part from the decimal part of a decimal number. 
 Warning: 
 Integers starting with 0x represent hexadecimal numbers. 
 Integers starting with 0 represent octal numbers. 
 43 

 4. Implement a program that, using the scanf function, asks the useruser entering a number 
 whole. Then print this number as shown below 
 jerome@linuxVm:~$ ./ejercicio08_04.out  
 Enter number: 33  
 The number entered is: 33  
 5. Repeat the above program using the following data types. 
 to.  char (for this type of data the user will enter a letter) 
 b.  float 
 6. Make a program that converts a keyboard-entered integer to hexadecimal and octal. 
 jerome@linuxVm:~$ ./ejercicio08_04.out  
 Enter number: 16  
 The number entered was: 16 (decimal); 0x10 (hexadecimal); 020 (octal)  
 7. Modify the above program to allow the user to enter a number in hexadecimal and 
 the program converts it to octal and decimal. To do this, use scanf with the specifiers 
 %o and %x format 
 8. Make a program that asks the user to enter a letter and prints its corresponding 
 ASCII code in decimal and hexadecimal 
 jerome@linuxVm:~$ ./ejercicio08_08.out  
 Enter letter: A  
 The ASCII code for the letter A is: 65; 0x41  
 9. Make a program that asks the user for a float number and prints it on the screen with only two 
 digits after the decimal point. 
 jerome@linuxVm:~$ ./ejercicio08_09.out  
 Enter number: 1.2785  
 The entered is: 1.27  
 44 

 9. Arithmetic operations - casting. 
 Arithmetic operators 
 Operator Description 
 + Sum 
 - Subtraction 
 * Multiplication 
 / Division 
 % Rest of division 
 Functions used 
 Header File Function 
 without math.h 
 cos math.h 
 so math.h 
 sqrt math.h 
 log math.h 
 exp math.h 
 pow math.h 
 Examples 
 1. Program that asks the user for 2 numbers, stores them in the variables a and b. Then calculate a b 
 print the result. 
 #include <stdio.h>  
 #include <math.h>  
 int main(void)  
 { 
 double a, b, r;  
 /* Data entry */  
 printf ("Enter a number:\r\n");  
 scanf("%lf", &a);  
 printf ("Enter a number:\r\n");  
 scanf("%lf", &b);  
 //-- I print a legend and the value stored in the variable --  
 r = pow (a, b);  
 printf ("The result is: %lf\r\n", r);  
 return (0);  
 } 
 45 

 Write and save the above code in a file named example09_01.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example09_01.c -Wall -lm -oexample09_01.out  
 jerome@linuxVm:~$ ./example09_01.out  
 The linker -l directive is added along with the name of the library to include in this case m. For this reason 
 Note -lm which must be added to link the math library functions. 
 Warning: 
 Don't forget to add the necessary libraries to link your code. Use the -l directive 
 2. Program that calculates the average of two integers entered by keyboard. 
 #include <stdio.h>  
 #include <math.h>  
 int main(void)  
 { 
 int a,b;  
 average float;  
 /* Data entry */  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 printf ("Enter a number:\r\n");  
 scanf("%d", &b);  
 //-- I print a legend and the value stored in the variable --  
 p = (float)(a + b) / (float)2.0;  
 printf ("The result is: %f\r\n", p);  
 return (0);  
 } 
 Exercises 
 1. Make a program that adds two "real" numbers (use ﬂoat as data type) and displays it 
 result on screen. 
 jerome@linuxVm:~$ ./ejercicio09_01.out  
 Enter number: 1.27  
 Enter number: 1  
 The sum of 1.27 + 1 is equal to 2.27  
 2. Implement a program that allows the entry of a real number (ﬂoat) and prints the 
 integer and decimal part 
 jerome@linuxVm:~$ ./ejercicio09_02.out  
 Enter number: 1.27  
 The whole part is: 1  
 The decimal part is: 0.27  
 46 

 3. Make a program that asks the user to enter two integers, calculate the division and 
 report the quotient (integer) and the remainder (use the %) operator 
 jerome@linuxVm:~$ ./ejercicio09_03.out  
 Enter number: 101  
 Enter number: 2  
 The quotient is: 50  
 The rest is: 1  
 4. Make a program that calculates and prints (to 4 decimal places) the square root of an entered number 
 by keyboard. What happens if the number entered is negative? Please indicate your answer in a comment. 
 in the code. 
 jerome@linuxVm:~$ ./ejercicio09_04.out  
 Enter number: 2  
 The square root of 2 is 1.4142  
 5. Make a program that calculates and prints the cosine of an angle expressed in degrees entered 
 by keyboard. 
 jerome@linuxVm:~$ ./ejercicio09_05.out  
 Enter nnumber: 45  
 The cosine of 45 is 0.707  
 6. Make a program that calculates the hypotenuse of a right triangle whose values of its legs 
 They are entered by keyboard. 
 jerome@linuxVm:~$ ./ejercicio09_06.out  
 Enter number: 1  
 Enter number: 1  
 The hypotenuse is 1.4142  
 7. Implement a program that requests a number and calculates the base 2 logarithm of it. 
 jerome@linuxVm:~$ ./ejercicio09_07.out  
 Enter number: 64  
 The base 2 logarithm of 64 is 6  
 47 

 10. If and switch-case conditional statements 
 Relational operators 
 Operator Description 
 > Greater than 
 < Less than 
 == Same 
 != Different 
 >= Greater than and equal to 
 <= Less than and equal to 
 Logical operators 
 Operator Description 
 && and logic. (And logic) 
 ||  or logic (O logic) 
 !  logical not 
 Sentences used 
 Sentences 
 if 
 switch-case 
 Examples 
 1. Program that asks the user for a number and tells us if it is zero 
 #include <stdio.h>  
 int main(void)  
 { 
 int a; 
 /* Data entry */  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 //-- I check if it is zero --  
 if (a == 0) {  
 printf ("The user entered zero\r\n");  
 } 
 return (0);  
 } 
 48 

 2. Program that asks the user for a number and tells us if it is greater than or equal to 6 or less. 
 #include <stdio.h>  
 int main(void)  
 { 
 int a; 
 /* Data entry */  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 //-- I check if it is greater than or equal to six --  
 if (a >= 6) {  
 printf ("The number entered is greater than or equal to 6\r\n");  
 } else {  
 printf ("The number entered is less than 6\r\n");  
 } 
 return (0);  
 } 
 3. Program that asks the user for a number and tells us if it is positive, negative or zero. 
 #include <stdio.h>  
 int main(void)  
 { 
 int a; 
 /* Data entry */  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 //-- Check if it is zero, positive or negative --  
 if (a == 0) {  
 printf ("The user entered zero\r\n");  
 } else {  
 if (a > 0) {  
 printf ("The user entered a positive number\r\n");  
 } else {  
 printf ("The user entered a negative number\r\n");  
 } 
 } 
 return (0);  
 } 
 49 

 4. Program that asks the user for two numbers and tells us which one is greater or if they are equal 
 #include <stdio.h>  
 int main(void)  
 { 
 int a,b;  
 /* Data entry */  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 printf ("Enter a number:\r\n");  
 scanf("%d", &b);  
 //-- Compare two entered numbers --  
 if (a == b) {  
 printf ("They are the same\r\n");  
 } else {  
 if (a > b) {  
 printf ("The first is greater than the second\r\n");  
 } else {  
 printf ("The second is greater than the first\r\n");        }  
 } 
 return (0);  
 } 
 5. Program that asks the user for a number and indicates whether it is between 1 and 10 (including 
 both) 
 #include <stdio.h>  
 int main(void)  
 { 
 int a; 
 /* Data entry */  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 //-- I check if the number is between 1 and 10 --  
 if ((a >= 1) && (a <= 10)) {  
 printf ("The number entered is between 1 and 10\r\n");  
 } 
 return (0);  
 } 
 50 

 6. Program that asks the user for a number and indicates whether it is greater than 10 or less than 1 
 #include <stdio.h>  
 int main(void)  
 { 
 int a; 
 /* Data entry */  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 //-- I check if the number is greater than 10 or less than 1 --  
 if ((a < 1) || (a > 10)) {  
 printf ("The number entered is greater than 10 or less than 1 \r\n");  
 } 
 return (0);  
 } 
 7. Program that asks the user for a character and indicates whether it is a capital letter 
 #include <stdio.h>  
 int main(void)  
 { 
 char a; 
 /* Data entry */  
 printf ("Enter a character:\r\n");  
 scanf("%c", &a);  
 //-- Check if it is a capital letter --  
 if ((a >= 'A') && (a <= 'Z')) {  
 printf ("The entered character is a capital letter\r\n");  
 } 
 return (0);  
 } 
 See the ascii man to see the order of the characters in the table. 
 51 

 8. Program that asks the user for a character and indicates if it is a lowercase vowel 
 #include <stdio.h>  
 int main(void)  
 { 
 char a; 
 /* Data entry */  
 printf ("Enter a character:\r\n");  
 scanf("%c", &a);  
 //-- I check if it is a vowel --  
 switch (a) {  
 case 'a':  
 printf ("It's a vowel\r\n");  
 break; 
 case 'e':  
 printf("It's vocal\r\n");  
 break; 
 case 'i':  
 printf ("It's a vowel\r\n");  
 break; 
 case 'o':  
 printf ("It's a vowel\r\n");  
 break; 
 case 'u':  
 printf ("It's a vowel\r\n");  
 break; 
 default:  
 printf ("Not a vowel\r\n");  
 break; 
 } 
 return (0);  
 } 
 52 

 9. Program that requests the entry of a 1-digit integer number and prints the value in letters. In case 
 If the digit entered is negative or has more than one digit, write a legend indicating it 
 #include <stdio.h>  
 int main(void)  
 { 
 int a; 
 /* Data entry */  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 //-- I check if it is a vowel --  
 switch (a) {  
 case 0: printf ("zero\r\n");   break;  
 case 1: printf ("one\r\n");    break;  
 case 2: printf ("two\r\n");    break;  
 case 3: printf ("three\r\n");   break;  
 case 4: printf ("four\r\n"); break;  
 case 5: printf ("five\r\n");  break;  
 case 6: printf ("six\r\n");   break;  
 case 7: printf ("seven\r\n");  break;  
 case 8: printf ("eight\r\n");   break;  
 case 9: printf ("nine\r\n");  break;  
 default:  
 printf ("Invalid entry\r\n");  
 break; 
 } 
 return (0);  
 } 
 Exercises 
 1. Write a program that allows the entry of an integer and indicates whether it is even or 
 odd  (use if and the % operator) 
 2. Write a program where you enter a pair of integer values by keyboard, which represent the 
 rectangular coordinates of different points in the plane. It is requested to determine and inform 
 display: 
 ○ If both values are zero. 
 ○ Which quadrant does the point belong to? 
 ○ The distance to the origin of coordinates. which is calculated as: 𝑟 = 𝑎 2 
+ 𝑏 2 
 53 

 3. Make a program that indicates whether the entered letter is uppercase, lowercase, a number or another 
 character. Verify operation with the following cases 
 stdout input values (display) 
 from 'a' to 'z' It is a lowercase letter. 
 from 'A' to 'Z' It is a capital letter. 
 from '0' to '9' It is a number 
 Another character It is another character 
 4. Create a program where two real values and the operation symbol ('+', '-', '*', '/') are entered. 
 The data entered, the operation and the result must be presented on the screen. If the symbol 
 used did not correspond to any of the four operations must present a message of 
 "Invalid operation." To read the operation symbol from the keyboard use 
 scanf ("%*c%c", &op)   .  (The program must be solved by using the structure 
 switch) 
 5. Implement a program that prompts the entry of scores from two midterms to determine if the 
 computer science student I: 
 ○ Signed the matter. 
 ○ I promote 
 ○ You must recover a partial. 
 The valid score will be in the range of 1 to 10, in case of error the program exits. 
 54 

 11. Repetition for statements; while; do-while 
 Assignment, increment and decrement operators 
 Operator Description 
 = Assignment (equal) 
 += Increase. Example x += 2;  is equivalent to x = x + 2; 
 -= Decrement. Example x -= 2;  is equivalent to x = x - 2; 
 ++ Pre or post increase. 
 -- Pre or post decrease. 
 Sentences used 
 Sentences 
 for 
 while 
 do - while 
 Examples 
 1. Example program of pre and post increment operators. 
 #include <stdio.h> 
 int main(void) 
 { 
 int w, x, y, z; 
 w = 0;  x = 0;  y = 0; z = 0; 
 //-- Print the original values -- 
 printf ("w = %d\tx = %d\ty = %d\tz = %d\r\n", w, x, y, z); 
 //-- I increment by one and print -- 
 w = w + 1;  x++;  ++y;  z+=1; 
 printf ("w = %d\tx = %d\ty = %d\tz = %d\r\n", w, x, y, z); 
 //-- I increment by one and print -- 
 printf ("w = %d\tx = %d\ty = %d\tz = %d\r\n", w = w + 1, x++, ++y, z+=1); 
 //-- I print the values -- 
 printf ("w = %d\tx = %d\ty = %d\tz = %d\r\n", w, x, y, z); 
 return (0); 
 } 
 55 

 2. Program that prints the legend Hello World 10 times. 
 #include <stdio.h>  
 int main (void) {  
 int i; 
 for (i = 0; i < 10; i++) {  
 printf ("Hello World\r\n");  
 } 
 return (0);  
 } 
 3. Program that prints integers from zero to nine 
 #include <stdio.h>  
 int main(void)  
 {int i; 
 for (i = 0; i < 10; i++) {  
 printf ("%d\r\n", i);  
 } 
 return (0);  
 } 
 4. The printing program asks the user for numbers successively until the user enters a larger one. 
 that 10 
 #include <stdio.h>  
 int main(void)  
 { 
 int a; 
 do { 
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 } while (a < 10);  
 maintf ("The number entered was greater than 10\r\n");  
 return (0);  
 } 
 56 

 5. Program that accumulates the numbers entered by keyboard as long as this accumulation does not exceed the 
 value 100. When the value of 100 is exceeded, it reports the total sum on the screen. 
 #include <stdio.h>  
 int main(void)  
 { 
 int a; 
 int sum = 0;  
 while (sum <= 100) {  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 sum += a;  
 } 
 printf ("The sum is %d\r\n", sum);  
 return (0);  
 } 
 Exercises 
 1. Implement a program that prints the even integers between zero and one hundred. 
 2. Implement a program that prompts the user for two integers and prints all the numbers 
 integers between them, including the limits. If the two numbers are the same you should print that 
 number only. Examples: 
 ● The user enters -1 and 2. The program should print: -1; 0; 1; 2 
 ● User enters 2 and -1. The program should print: 2; 1; 0; -1 
 ● The user enters 2 and 2. The program should print: 2 
 3. Implement a program using the for statement that calculates the average of 10 numbers 
 integers entered by keyboard. 
 4. Make a program using the do-while statement that prints the numbers 0 to 9 
 5. Make a program using the while statement that prints the numbers 0 to 9 
 6. Implement a program that accumulates the numbers entered by keyboard while it is 
 accumulation does not exceed the value 100. Report this number on the screen.  If user enters: 10, 80, 20 
 the program should print: 90 
 7. Make a program that calculates the average of all the notes entered by keyboard. The notes 
 valid are in the interval [1; 10] and the data entry will end when the user enters as 
 Note the value -1 which should not be taken into account for the average. If the user enters a number 
 outside the range you must report with a legend on the screen and continue entering data. 
 Finally show the average to 2 decimal places. 
 8. Make a program that calculates the average of all the notes entered by keyboard. The notes 
 valid are in the interval [1; 10] and the data entry will end when the user enters as 
 57 

 Note the value -1 which should not be taken into account for the average. If the user enters a number 
 outside the range you must report with a legend on the screen and continue entering data. Furthermore 
 You must check that the number of valid notes entered is greater than three, otherwise 
 You will need to prompt the user to continue entering data. Finally show the average 
 with 2 decimal places. Use do-while . 
 9. Write a program that allows the user to play a game of guessing a secret number between 0 and 9. To 
 It will ask you to enter a number (the secret) and then it will ask you to enter numbers up to 
 guess it  If the user enters a number outside the valid range [0; 9] must indicate it and in the case 
 of the secret number should continue prompting until you enter the value in the valid range. The 
 program will continue asking for numbers until the user guesses it by indicating "YOU WON" with which 
 which must start the game again or make a mistake 3 times indicating "YOU DID NOT WON, 
 TRY AGAIN." Use while . 
 10. Implement a program that asks the user to enter an integer and then reports the 
 number of digits of it. Use while . 
 58 

 12. Precompiler directive deﬁnes 
 Precompile directives 
 Directive Description 
 deﬁne Defines a symbolic constant 
 Examples 
 1. Program that prints the legend Hello World 10 times. Set this threshold to a deﬁne. 
 #include <stdio.h>  
 #define QTY ((int)10)  
 int main(void)  
 { 
 int i; 
 for (i = 0; i < QTY; i++) {  
 printf ("Hello World\r\n");  
 } 
 return (0);  
 } 
 2. Program that calculates the average of QTY data entered. 
 #include <stdio.h>  
 #define QTY ((int)10)  
 int main(void)  
 { 
 int i; 
 int acc = 0, n;  
 average float;  
 for (i = 0; i < QTY; i++) {  
 printf ("Enter number\r\n");  
 scanf("%d", &n);  
 acc += n;  
 } 
 average = acc / (float)QTY;  
 printf ("Average %f\r\n", average);  
 return (0);  
 } 
 59 

 Warning: 
 You cannot modify the value of a define during execution, for example you CANNOT make QTY = 0 
 Exercises 
 1. Implement a program that asks the user for a number and indicates if the number is greater than 100. 
 Place thisthreshold in a define . 
 2. Implement a program that calculates the factorial of a positive integer entered by keyboard 
 The factorial of n is the product of all positive integers up to and including n. 
 ● For n > 0 => n! = 1 x 2 x 3 x … x n 
 ● For n = 0 => n! = 1 
 Verify all the conditions that you consider relevant so that the result obtained is correct. 
 Determine the maximum number at which you can calculate the factorial. Check the operation of the 
 program with the following values. 
 x x! (stdout output) 
 -1 I cannot calculate the factorial of a negative number 
 0 1 
 1 1 
 2 2 
 3 6 
 12 479001600 
 3. Enter an integer using the keyboard and determine if it is prime. 
 4. Implement a program that asks the user to enter 10 (use define ) integers and 
 report the oldest and youngest of all those admitted. 
 5. Implement a program that prompts the user to enter 10 (use define ) integers 
 positive and count the number of even and odd numbers entered. 
 60 

 13. Functions 
 Symbolic constants 
 Constant Description 
 M_PI Number Pi, defined in math.h 
 Examples 
 1. Function that prints the legend "Hello World". 
 #include <stdio.h>  
 void print(void)  
 { 
 printf ("Hello World\r\n");  
 } 
 int main(void)  
 { 
 print();  
 return (0);  
 } 
 2. Function that prints the legend "Hello World", the number of times it was passed as a parameter. 
 #include <stdio.h>  
 void print (int qty)  
 { 
 int i; 
 for (i = 0; i < qty; i++) {  
 printf ("Hello World\r\n");  
 } 
 } 
 int main(void)  
 { 
 int c; 
 printf ("Enter quantity\r\n");  
 scanf("%d", &c);  
 print(c);  
 return (0);  
 } 
 61 

 3. Function that returns the number passed as a parameter adding 1 to it. 
 #include <stdio.h>  
 #define QTY ((int)10)  
 int sum1 (int a)  
 { 
 int r; 
 r = a + 1;  
 return (r);  
 } 
 int main(void)  
 { 
 int c, r;  
 printf ("Enter quantity\r\n");  
 scanf("%d", &c);  
 r = sum1 (c);  
 printf ("Result = %d\r\n", r);  
 return (0);  
 } 
 4. Function that converts the letter passed as a parameter from uppercase to lowercase 
 char passLowercase(char a)  
 #include <stdio.h>  
 #define QTY ((int)10)  
 char passesLowercase (char a)  
 { 
 char r; 
 if ((a >= 'A') && (a <= 'Z') {  
 r = (a - 'A') + 'a';  
 } else {  
 r = a; 
 } 
 return (r);  
 } 
 62 

 int main(void)  
 { 
 char c, r;  
 printf ("Enter letter\r\n");  
 scanf("%c", &c);  
 r = passLowercase(c);  
 printf ("Result = %c\r\n", r);  
 return (0);  
 } 
 5. Function that returns the sum of two integers passed as parameters 
 #include <stdio.h>  
 int sumTwoNumbers (int a, int b)  
 { 
 int r; 
 r = a + b;  
 return (r);  
 } 
 int main(void)  
 { 
 int x, y, r;  
 printf ("Enter number\r\n");  
 scanf("%d", &x);  
 printf ("Enter number\r\n");  
 scanf("%d", &y);  
 r = sumTwoNumbers (x, y);  
 printf ("Result = %d\r\n", r);  
 return (0);  
 } 
 Warning: 
 Remember to deﬁne the function or place the prototype before the function call. 
 63 

 Exercises 
 1. Implement a function that calculates the area of a circle. Use the pi constant from math.h. 
 The prototype is 
 float areaCircle (float radius);  
 2. Implement a function that calculates the perimeter of a circle. Use the pi constant 
 math.h.  The prototype is 
 float circleperimeter (float radius);  
 3. Implement a function to which you pass a character as a parameter and return 
 ○ 0: if the character is a capital letter. 
 ○ 1: if the character is a lowercase letter. 
 ○ 2: if the character is a number. 
 ○ 3: in case it is not any of the above. 
 Use define for constants. The prototype is int filterASCII (char character);  
 4. Implement a function that performs the four basic operations between two numbers of type float and 
 return the result. The function prototype is as follows 
 float calculation (float opA, float opB, char op)  
 Where: 
 ● opA and OpB are the numbers with which the operation must be performed 
 ● op: The operation to be performed 
 ○ '+': Performs the sum. 
 ○ ‘-’: Performs the subtraction. 
 ○ '*': Make the product 
 ○ ‘/’: Performs the division 
 ● The function returns zero if the operation is invalid. 
 5. Implement a function that passes as parameters two numbers that represent the legs of 
 a right triangle and give me back the hypotenuse.  The prototype is 
 float calcHypo (float legA, float legB)  
 6. Implement a function that calculates the factorial of a number passed as a parameter. If the factorial 
 cannot be calculated the function must return zero. 
 int factorial (int n);  
 64 

 14. Vectors and strings 
 Examples 
 1. Program in which a vector of ten integers is defined and initialized at runtime. 
 execution with the numbers 0 to 9. It then prints it in ascending and descending order. 
 #include <stdio.h>  
 #define QTY ((int)10)  
 int main(void)  
 { 
 int v[QTY];  
 //-- Initialize the vector --  
 for (i = 0; i < QTY; i++) {  
 v[i] = i;  
 } 
 //-- Print in ascending order --  
 for (i = 0; i < QTY; i++) {  
 printf ("%d\r\n", v[i]);  
 } 
 //-- Print in descending order --  
 for (i = QTY - 1; i >= 0; i--) {  
 printf ("%d\r\n", v[i]);  
 } 
 return (0);  
 } 
 2. Program in which a vector of ten integers is defined and initialized at runtime. 
 compilation with the multiplication table of 5. Ask the user to enter a number between zero and 
 nine, and then calculate the multiplication by five of said number by indexing the vector. 
 #include <stdio.h>  
 #define QTY ((int)10)  
 int main(void)  
 { 
 int m5[QTY] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45};  
 int num;  
 //-- Enter number --  
 printf ("Enter number\r\n");  
 scanf("%d", &num);  
 65 

 if ((num >= 0) && (num <= 9)) {  
 printf ("The result is: %d\r\n", m5[num]);  
 } else {  
 printf ("Unable to calculate\r\n");  
 } 
 return (0);  
 } 
 3. Program in which the user is asked to enter 10 numbers, and then print 
 separate the even and odd numbers entered. The vector is initialized to zero at time 
 compilation. 
 #include <stdio.h>  
 #define QTY ((int)10)  
 int main(void)  
 { 
 int v[QTY] = {0};  
 int i; 
 //-- Enter number --  
 for (i = 0; i < QTY; i++) {  
 printf ("Enter number\r\n");  
 scanf("%d", &v[i]);  
 } 
 printf ("The pairs are: \r\n");  
 for (i = 0; i < QTY; i++) {  
 if ((v[i] % 2) == 0) {  
 printf ("%d.%d\r\n", i, v[i]);  
 } 
 } 
 printf ("The odd ones are: \r\n");  
 for (i = 0; i < QTY; i++) {  
 if ((v[i] % 2) != 0) {  
 printf ("%d.%d\r\n", i, v[i]);  
 } 
 } 
 return (0);  
 } 
 Warning: 
 Always verify that the vector index is within the defined range. 
 66 

 4. Program that shows how to generate 10 pseudorandom numbers. 
 #include <stdio.h>  
 #include <time.h>  
 #include <stdlib.h>  
 #define QTY ((int)10)  
 int main(void)  
 { 
 int i; 
 srand(time(NULL));  
 for (i = 0; i < QTY; i++) {  
 printf ("%d\r\n", rand());  
 } 
 return (0);  
 } 
 5. Program that asks the user to enter a word and then indicates the number of vowels 
 which has the same. 
 #include <stdio.h>  
 #define QTY ((int)32)  
 #define VOWEL_COUNT ((int)10)  
 int main(void)  
 { 
 char v[QTY];  
 char vowels[VOWEL_QTY] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I',  
 'O', 'U'};  
 int vowelsCont = 0;  
 int i, j;  
 //-- Word entry --  
 printf ("Enter word\r\n");  
 scanf("%s", &v[0]);  
 //-- I count the vowels --  
 i = 0; 
 while (v[i] != '\0') {  
 for (j = 0; j < sizeof (vowels); j++) {  
 if (v[i] == vowels[j]) {  
 vowelsCont++;  
 } 
 } 
 i++; 
 } 
 printf ("The number of vowels is: %d\r\n", vowelsCont);  
 return (0);  
 } 
 67 

 6. Program that initializes a string at compile time and displays it on the screen. 
 #include <stdio.h>  
 #define QTY ((int)32)  
 #define VOWEL_COUNT ((int)10)  
 int main(void)  
 { 
 char str0[] = "Hello";  
 char str1[] = {'h', 'o', 'l', 'a', '\0'};  
 //-- Word entry --  
 printf ("Word %s\r\n", str0);  
 printf ("Word %s\r\n", str1);  
 return (0);  
 } 
 7. Program that indicates the number of characters in a string entered by keyboard. 
 #include <stdio.h>  
 #define QTY ((int)32)  
 #define VOWEL_COUNT ((int)10)  
 int main(void)  
 { 
 char str0[] = "Hello";  
 char str1[] = {'h', 'o', 'l', 'a', '\0'};  
 //-- Word entry --  
 printf ("Word %s\r\n", str0);  
 printf ("Word %s\r\n", str1);  
 return (0);  
 } 
 Exercises 
 1. Write a program in which you define a vector that stores all the letters of the alphabet, except the 
 eñe (use char as data type). Initialize it at runtime. Print it in alphabetical order 
 2. Implement code that generates a pseudo random number between [0; 99] , then the program should 
 ask user for numbersand tell you whether or not you guessed the pseudo-randomly generated number correctly.  If he 
 user repeats a number the program must indicate it, the same if the user enters one outside of 
 range. 
 3. Make a program that allows the user to enter the heights of a group of at most one hundred 
 people. The end of data entry occurs when the entered height is less than zero. Then the 
 will ask the user to enter two height values and the program should indicate the amount of 
 people with heights in that range. If the interval entered by the user is invalid, indicate it by 
 screen. 
 68 

 4. Implement a program that asks the user for integers and stores them in 4 vectors 
 different according to their types. 
 ● Positives and zero. 
 ● Negatives. 
 ● Pairs. 
 ● Odd. 
 The user will enter ten values and then the program must print on the screen the amount of 
 numbers stored in each vector and subsequently the data stored in each of them. 
 5. Implement a program that asks the user to enter a word by keyboard and prints it on 
 capital letter per screen. 
 6. Implement a program that asks the user to enter a word by keyboard and reports the 
 number of characters it has without counting the '\0'. 
 7. Implement a program that asks the user to enter two words via keyboard and indicates whether they are 
 equal or which appears first in the dictionary. 
 8. Implement a program that asks the user to enter a word and a character by keyboard. A 
 Next replace this character in the word with an asterisk. Finally you must indicate the amount 
 of times it replaced the character. 
 69 

 15. Pointers 
 Basic way to use pointers 
 In order to keep the pointers controlled, thus avoiding segment violations, 
 recommends following the following recommendations in its use 
 ● Declare pointer. 
 ● Always initialize the pointer before using it. You can initialize it to: 
 ○ To the corresponding variable 
 ○ TO NULL 
 ● Make the data type match the pointer's data type. 
 ● If the variable where you initialize the pointer is a vector, initialize it to element zero. 
 ● When the pointer was initialized with the zero element of a vector use the pointer like this 
 *(p + i) where i is the integer index 
 These recommendations avoid the use of pointers by modifying the value they point to, for example 
 doing p++; 
 Examples of using pointers 
 int variable int vector 
 int variable declaration a;  int v[3]; 
 pointer declaration int *p;  int *p; 
 Pointer initialization p = &a;  p = &v[0]; 
 I assign a value 
 variable a a = 10;  v[0] = 1; 
 v[1] = 2; 
 v[2] = 3; 
 I assign a value to the 
 variable using a 
 pointer *p = 10; // a = 10;  *(p + 0) = 1; // v[0] =1; 
 *(p + 1) = 2; // v[1] =2; 
 *(p + 2) = 3; // v[2] =3; 
 I print the value of the 
 variable printf ("%d\r\n", a);  printf ("%d\r\n", v[0]); 
 printf ("%d\r\n", v[1]); 
 printf ("%d\r\n", v[2]); 
 I print the value of the 
 variable using the 
 pointer printf ("%d\r\n", a);  printf ("%d\r\n", *(p + 0)); 
 printf ("%d\r\n", *(p + 1)); 
 printf ("%d\r\n", *(p + 2)); 
 70 

 Examples 
 1. Program in which an int type variable and a pointer of the same type are instantiated. The 
 pointer to this variable and initializes it using the pointer with the value 0x55. Then print the value 
 stored in the variable using the pointer. 
 #include <stdio.h> 
 int main(void) 
 { 
 int a; 
 int *p;        //-- I declare the pointer -- 
 p = &a;    //-- Initialize the pointer -- 
 *p = 0x55; //-- I initialize the variable a using the pointer -- 
 printf ("%d\r\n", *p); //-- Print using the pointer -- 
 return (0); 
 } 
 2. Program that defines a vector of 10 elements of type char, then initializes it with the numbers of the 
 '0' to '9' using a pointer. Finally print said vector using a pointer. 
 #include <stdio.h> 
 #define QTY ((int)QTY) 
 int main(void) 
 { 
 char c[QTY]; 
 char *p; 
 p = &c[0];  //-- Initialize the pointer -- 
 //-- Initialize the vector using the pointer -- 
 for (i = 0; i < QTY; i++) { 
 *(p + i) = '0' + i; 
 } 
 //-- Print the vector using the pointer -- 
 for (i = 0; i < QTY; i++) { 
 printf ("%d\r\n", *(p + i)); 
 } 
 return (0); 
 } 
 71 

 3. A function is made that adds two integers that are passed as a parameter and returns the 
 result using the return of the function. 
 #include <stdio.h> 
 int sum (int *a, int *b) 
 { 
 int r; 
 r = *a + *b; 
 return (r); 
 } 
 int main(void) 
 { 
 int x, y, r; 
 //-- Enter the two numbers to add -- 
 printf ("Enter number\r\n"); 
 scanf("%d", &x); 
 printf ("Enter number\r\n"); 
 scanf("%d", &y); 
 r = sum (&x, &y); 
 printf ("The result %d\r\n", r); 
 return (0); 
 } 
 4. A function is made that adds two integers that are passed as a parameter and returns the 
 result using a pointer. 
 #include <stdio.h>  
 void sum (int *a, int *b, int *r)  
 { 
 *r = *a + *b;  
 return; 
 } 
 int main(void)  
 { 
 int x, y, r;  
 //-- Enter the two numbers to add --  
 printf ("Enter number\r\n");  
 scanf("%d", &x);  
 printf ("Enter number\r\n");  
 scanf("%d", &y);  
 72 

 sum (&x, &y, &r);  
 printf ("The result %d\r\n", *r);  
 return (0);  
 } 
 5. A function is performed that returns a pointer to the center element of a vector of integers. 
 Finally, the central element of the vector is printed using the pointer obtained with the 
 #include <stdio.h> 
 #define QTY ((int)3) 
 int* middle (int *dataPtr, int dataCant) 
 { 
 int *p; 
 p = dataPtr + (dataCant / 2); 
 return (p); 
 } 
 int main(void) 
 { 
 int v[QTY] = {1, 2, 3}; 
 int *q; 
 q = medium (&v[0], QTY); 
 //-- I print the central element -- 
 printf ("Central element is %d\r\n", *q); 
 return (0); 
 } 
 Warning: 
 Don't forget to initialize the pointer before using it. 
 Warning: 
 Avoid performing increment or decrement operations on pointers, for example: p++ or p--; 
 73 

 Exercises 
 1. Implement a function that calculates the average of a float vector. The prototype of the function 
 is 
 float average (float *dataPtr, int dataCant);  
 Where: 
 dataPtr: It is the pointer to the data. 
 dataCant: It is the number of elements of the pointed vector. 
 2. Implement a function that inverts the content of two variables whose prototype is: 
 void swap(int *a, int *b);  
 Where: a and b are the pointers to the variables whose content should be inverted. 
 3. Implement a function that checks whether an int vector is ordered in increasing or 
 decreasing. The prototype is 
 int order (int *dataPtr, int dataCant);  
 Where: 
 dataPtr: It is the pointer to the data 
 dataCant: It is the number of elements of the pointed vector 
 Returns: 1 if the order is increasing;  0 if unsorted;  -1 if the order is descending. 
 4. Implement a function that returns a pointer to the element that contains the maximum value of a 
 vector. 
 int * myMax (int *dataPtr, int dataCant);  
 Where: 
 dataPtr: It is the pointer to the data 
 dataCant: It is the number of elements of the pointed vector 
 Returns: The pointer to the element containing the maximum 
 5. Implement a function that returns a pointer to the element that contains the minimum value of a 
 vector. 
 int * myMin (int *dataPtr, int dataCant);  
 Where: 
 dataPtr: It is the pointer to the data 
 dataCant: It is the number of elements of the pointed vector 
 Returns: The pointer to the element containing the minimum 
 6. Implement a function that prints all characters in a string in hexadecimal. The prototype 
 of the function is the following. 
 int myHexa(char *dataPtr)  
 Where: 
 dataPtr: It is the pointer to the string to convert to hexadecimal. 
 Returns the number of characters without counting the '\0' 
 74 

 7. Implement a function that is passed a pointer to a string as a parameter and indicate whether this 
 contains only the digits '0' to '9'. The function prototype is as follows. 
 int isNumber (char *dataPtr);  
 Where: 
 dataPtr: It is the pointer to the string 
 Returns: Zero if any character in the string does not correspond to a digit from '0' to '9', returns one 
 8. Implement a function that receives a pointer to a string containing a number and returns that 
 number in an int . The function prototype is as follows. 
 int convertTo_Int(char *dataPtr)  
 Where: 
 dataPtr: It is the pointer to the string to be converted. 
 Returns: The integer if you could convert it, if the string contains a character other than digits 
 from '0' to '9' and minus one in case of error. 
 75 

 16. Dynamic memory allocation 
 Used functions of stdlib.h 
 Function Description 
 malloc Dynamically allocates memory. 
 free Frees dynamically allocated memory. 
 realloc Dynamically allocates memory. 
 Examples 
 1. Program in which a 10-element vector is dynamically instantiatedof type int. These are 
 initialized with the numbers from 0 to 9. Finally this vector is printed on the screen and the 
 dynamically allocated memory. 
 #include <stdio.h>  
 #include <stdlib.h>  
 #define QTY ((int)10)  
 int main(void)  
 { 
 int *p; 
 int i; 
 //-- Request memory dynamically. --  
 p = (int *)malloc (sizeof (*p) * QTY);  
 if (p == NULL) {  
 return (-1);  
 } 
 //-- Initialize the vector --  
 for (i = 0; i < QTY ; i++) {  
 *(p + i) = i;  
 } 
 //-- I print the vector --  
 for (i = 0; i < QTY ; i++) {  
 printf ("%d\r\n", *(p + i));  
 } 
 //-- I free memory --  
 free(p);  
 return (0);  
 } 
 76 

 2. Program in which a 10-element vector of type int is dynamically instantiated. These are 
 initialized with numbers from 0 to 9. Then using realloc, 10 more elements are requested and 
 initialized with the numbers from 10 to 19. Finally this vector is printed on the screen and the 
 dynamically allocated memory. 
 #include <stdio.h>  
 #include <stdlib.h>  
 #define QTY ((int) 10)  
 int main(void)  
 { 
 int *p, *pBack;  
 int totalquant, i;  
 int used#;  
 //-- Request memory for QTY elements --  
 totalQTY = QTY;  
 qtyUsed = 0;  
 p = (int*)malloc (sizeof (*p) * totalqty);  
 if (p == NULL) {  
 return (-1);  
 } 
 //-- I initialize the allocated memory area with zero--  
 for (i = usedqty; i < totalqty; i++) {  
 *(p + i) = i;  
 qtyUsed++;  
 } 
 //-- I request memory for QTY more elements--  
 pBack = (int*)realloc (p, sizeof (*p) * (totalqty + QTY));  
 if (pBack != NULL) {  
 //-- Realloc ok --  
 //-- There areTotalQTY + QTY elements --  
 qtytotal += qty;  
 p = pBack;  
 } 
 //-- I initialize the allocated memory area with one--  
 for (i = usedqty; i < totalqty; i++) {  
 *(p + i) = i;  
 qtyUsed++;  
 } 
 //-- I print the vector used, in this case that's all --  
 for (i = 0; i < used#; i++) {  
 printf ("%d\r\n", *(p + i));  
 } 
 77 

 //-- I free memory --  
 free(p);  
 return (0);  
 } 
 Exercises 
 1. Implement a program that, using malloc, reserves memory to store the letters 
 capital letters of the alphabet (except Ñ). Then print the reserved area and release it before finishing the 
 program. 
 2. Implement a program that asks the user how many letters they want to enter, reserve using 
 malloc the necessary memory and then ask the user for characters until the reserved vector is filled 
 dynamically. Finally you must print the vector in reverse order to the one entered and free the memory 
 reserved. 
 3. Implement a program that asks the user to enter letters and stores them in memory, the end 
 Data entry occurs when the user enters the exclamation point. Then they must 
 print all letters entered by the user. (Use realloc) 
 78 

 17. Integrative algorithms 
 Used functions of string.h 
 Function Description 
 strcat Concatenate one string with another 
 strchr Searches for a character in a string 
 strcmp Compares two strings alphabetically 
 strcpy Copies one string to another. 
 strlen Gets the size of a string 
 strstr Searches a string in another string 
 memcpy Copies a number of bytes from one memory area to another 
 memset Writes a memory area with a given character. 
 memcmp Compares two memory areas. 
 Used functions of stdlib.h 
 Function Description 
 qsort  Ordena un vector. 
 Examples 
 1. Implement a function that counts the number of characters in a string without counting the '\0'. 
 function prototype is 
 int myStrLen(char *s);  
 Also implement a main that automatically verifies the basic operation of the function 
 implemented 
 #include <stdio.h>  
 #include <stdlib.h>  
 int myStrLen (char *s)  
 { 
 int c = 0;  
 if (s != NULL) {  
 while (*(s + c) != '\0') {  
 c++; 
 } 
 } 
 return (c);  
 } 
 79 

 int main(void)  
 { 
 //-- Test vectors --  
 char v0[]="Hello";  
 char v1[]="";  
 char v2[]="Hello, how are you doing?";  
 int r; 
 //-- Test functions --  
 r = myStrLen(v0);       printf ("strlen > %s: %d\r\n", v0, r);  
 r = myStrLen(v1);       printf ("strlen > %s: %d\r\n", v1, r);  
 r = myStrLen(v2);       printf ("strlen > %s: %d\r\n", v2, r);  
 r = myStrLen(NULL);     printf ("strlen > NULL: %d\r\n", r);  
 return (0);  
 } 
 Write and save the above code in a file called example01.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example01.c -Wall -oexample01.out  
 jerome@linuxVm:~$ ./example01.out  
 strlen > Hello: 4  
 strlen >  : 0  
 strlen > Hello, how are you doing? : 16  
 strlen > NULL : 0  
 2. Program in which a 10-element vector of type int is dynamically instantiated. These are 
 initialized with the numbers from 0 to 9. The qsort function is used to sort the vector from greatest to 
 minor. The vector is printed before and after calling the qsort function. Finally it is released 
 memory. 
 #include <stdio.h> 
 #include <stdlib.h> 
 #define QTY ((int) 10) 
 int compareInt (const void *a, const void *b) 
 { 
 int *a_, *b_; 
 a_ = (int *)a; 
 b_ = (int *)b; 
 return (*b_ - *a_); 
 } 
 int main(void) 
 { 
 int *p; 
 int i; 
 80 

 //-- Request memory for QTY elements -- 
 p = (int*)malloc (sizeof (*p) * QTY); 
 if (p == NULL) { 
 printf ("Error\r\n"); 
 return (-1); 
 } 
 //-- I initialize the allocated memory area with zero-- 
 for (i = 0; i < QTY; i++) { 
 *(p + i) = i; 
 } 
 //-- I print the vector -- 
 printf ("Before qsort\r\n"); 
 for (i = 0; i < QTY; i++) { 
 printf ("%d\r\n", *(p + i)); 
 } 
 //-- I order -- 
 qsort (p, QTY, sizeof (*p), compareInt); 
 //-- I print the vector -- 
 printf ("\r\nAfter qsort\r\n"); 
 for (i = 0; i < QTY; i++) { 
 printf ("%d\r\n", *(p + i)); 
 } 
 //-- I free memory -- 
 free(p); 
 return (0); 
 } 
 3. Program in which a 10-element vector of type int is dynamically instantiated. These are 
 initialized with the numbers 0 to 9. The bubbling algorithm is used to sort the vector of 
 largest to smallest. The vector is printed before and after sorting. Finally memory is freed. 
 #include <stdio.h>  
 #include <stdlib.h>  
 #define QTY ((int) 10)  
 int main(void)  
 { 
 int *p; 
 int i, j;  
 int aux;  
 81 

 //-- Request memory for QTY elements --  
 p = (int*)malloc (sizeof (*p) * QTY);  
 if (p == NULL) {  
 printf ("Error\r\n");  
 return (-1);  
 } 
 //-- I initialize the allocated memory area with zero --  
 for (i = 0; i < QTY; i++) {  
 *(p + i) = i;  
 } 
 //-- I print the vector --  
 printf ("Before sorting\r\n");  
 for (i = 0; i < QTY; i++) {  
 printf ("%d\r\n", *(p + i));  
 } 
 //-- I order --  
 for (i = 0; i < QTY - 1; i++) {  
 for (j = i + 1; j < QTY; j++) {  
 if (*(p + i) < *(p + j)) {  
 aux = *(p + i);  
 *(p + i) = *(p + j);  
 *(p + j) = aux;  
 } 
 } 
 } 
 //-- I print the vector --  
 printf ("\r\nAfter sorting\r\n");  
 for (i = 0; i < QTY; i++) {  
 printf ("%d\r\n", *(p + i));  
 } 
 //-- I free memory --  
 free(p);  
 return (0);  
 } 
 82 

 Exercises 
 In the exercises that request implementing a function, it also generates a main that clearly demonstrates 
 Automatic function operation. 
 1. Implement a program that asks the user to enter letters and stores them in memory, the end 
 Data entry occurs when the user enters the exclamation point. Then they must 
 print all letters entered by the user in alphabetical order. Use the qsort function. 
 2. Implement a program that asks the user to enter letters and stores them in memory, the end 
 Data entry occurs when the user enters the exclamation point. Then they must 
 print all letters entered by the user in alphabetical order. Para ordenar coloque el 
 Bubbling algorithm into a function and use it to sort. 
 3. Implement a function that tells me if the entered string contains only letters or only numbers. The 
 function prototype is as follows: 
 int validString (char *dataPtr);  
 Returns 
 ● 1 if the string contains only letters. 
 ● 2 if the string contains only numbers. 
 ● 0 If none of the above. 
 4. Implement a function that counts the occurrence of each character (histogram) of a passed string 
 as a parameter. 
 void countCharacters (char *dataPtr, int *dataCntPtr);  
 Where: 
 dataPtr: It is the pointer to the string in which the occurrence of each character must be counted. 
 dataCntPtr: The pointer is a vector of 256 integers in which the count of characters is kept. 
 of the string 
 Example: 
 The string pointed to by dataPtr is "11AB1B1ZZZZ1" 
 ● Position 65 (65 is the ASCII of 'A') of the vector pointed to by dataCntPtr must have the number 1 
 (Number of 'A' in the string) 
 ● Position 66 (66 is the ASCII of 'B') of the vector pointed to by dataCntPtr must have the number 
 2 (Amount of 'B' in the string) 
 ● The 90 position (90 is the ASCII of the 'Z') of the vector pointed to by dataCntPtr must have the number 
 4 (Amount of 'Z' in the string) 
 ● Position 49 (49 is the ASCII of '1') of the vector pointed to by dataCntPtr must have the number 5 
 (Number of '1' in the string) 
 ● The rest of the elements of the vector must be zero. 
 5. Implement a function that counts the occurrence of each character (histogram) of a passed string 
 as a parameter. 
 int* countCharacters (char *dataPtr);  
 Where: 
 dataPtr: It is the pointer to the string in which the occurrence of each character must be counted. 
 83 

 Returns a vector pointer of 256 integers in which the count of the characters in the string is kept, the 
 which is dynamically generated within the function. 
 Example: 
 The string pointed to by dataPtr is "11AB1B1ZZZZ1" 
 ● Position 65 (65 is the ASCII of 'A') of the vector pointed to by dataCntPtr must have the number 1 
 (Number of 'A' in the string) 
 ● Position 66 (66 is the ASCII of 'B') of the vector pointed to by dataCntPtr must have the number 
 2 (Amount of 'B' in the string) 
 ● Position 90 (90 is the ASCII of 'Z') of the vector pointed to by dataCntPtr must have the number 
 4 (Amount of 'Z' in the string) 
 ● Position 49 (49 is the ASCII of '1') of the vector pointed to by dataCntPtr must have the number 5 
 (Number of '1' in the string) 
 ●  El resto de los elementos del vector deberán estar en cero. 
 6. Implement a function that parses a paragraph of text and returns the number of characters and 
 words it contains. The function prototype is as follows: 
 int parseString (char *dataPtr, int *wordsQty,  
 int *charsQty);  
 Where: 
 ● dataPtr is the pointer to the string to analyze 
 ● wordsQty is a pointer to a variable where the number of words of the 
 text 
 ● charactersQty is a pointer to a variable where the number of characters of the character will be stored. 
 text 
 Returns 
 ● 0 if the string contains only letters and punctuation marks. 
 ● -1 otherwise. 
 Implementation notes: 
 ● The characters to count are all the letters of the alphabet, numbers, punctuation marks and 
 spaces. 
 ● A word is separated from another by a space or punctuation mark. 
 ● Do not count spaces to get the number of words, since the text can contain two 
 spaces in a row and this will give an incorrect count. 
 7. Implement a function that determines whether a word passed as a parameter is a palindrome 
 Function prototype 
 int detectorPalindrome(char *wordPtr)  
 Where: 
 ● wordPtr: it is the pointer to the word to analyze 
 Returns: 
 ● 0 if the word is palindrome 
 ● -1 if the word is not palindrome 
 ● -2 if the word is less than 2 characters 
 84 

 8. Implement a function that removes the character passed as a parameter from a string. Please note 
 that when deleting characters you must adjust the position of '\0' The prototype of the function is the following. 
 int removeCharacter (char *dataPtr, char c);  
 Where: 
 dataPtr: It is the pointer to the string to be modified. 
 c: Character to delete. 
 Returns: 
 ● The number of characters removed. 
 9. Implement a function that validates credit card numbers using Luhn's algorithm. The 
 function prototype is as follows: 
 int luhnAlg (char *card);  
 Parameters 
 ● card: pointer to the vector containing the credit card number ending in '\0' 
 Devuelve: 
 ● Zero or a positive number indicating that the card is valid. 
 ● -1: When the number of digits on the card is other than 16. 
 ● -2: Indicates that the card number is invalid. 
 Luhn's algorithm 
 a.  Multiply the digits that are in the even position of the vector by two, if the result is 
 greater than or equal to ten, each of the digits are added. 
 b.  Multiply the digits that are in the odd position of the vector by one. 
 c.  Add all the results obtained in points a and b, obtaining the sum called S. If the 
 module 10 of the sum obtained S is equal to zero, the card number is valid. 
 Example: 
 Digits Card 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 7 
 Value to 
 multiply by 
 digit X2 X1 X2 X1 X2 X1 X2 X1 
 Result of the 
 multiplication 0 1 4 3 8 5 12 7 16 9 0 1 4 3 8 7 
 Digits to add 0 1 4 3 8 5 1+2 7 1+6 9 0 1 4 3 8 7 = 70 
 70%10 = 0 => The card is validone way 
 10. Implement a function that converts a 4-digit hexadecimal positive number stored into a 
 string and return the corresponding decimal number. The letters of the hexadecimal number are in 
 capital letter. 
 The prototype of the function is: 
 int hexaToDec (char *dataPtr);  
 Returns: 
 ● The hexadecimal value in decimal 
 ● -1 If there is a symbol that does not correspond to a hexadecimal number. 
 ● -2 If the number of digits is different than 4 
 Examples 
 85 

 hexaToDec("0001");  // Returns 1 
 hexaToDec("COFFEE");  // Returns 51966 
 hexaToDec("JJJJ");  // Returns -1 
 hexaToDec("1");  // Returns -2 
 11. Implement a function that converts a positive integer passed as a parameter to binary. 
 The prototype of the function is 
 char* printBinary (int n);  
 Where: 
 n number to print in binary. 
 Returns NULL if the number is less than zero, otherwise returns the pointer to a string with 
 the binary number. 
 12. Implement a function that calculates the average of the notes passed by a string separated by 
 spaces. The last note has a space too. The function prototype is as follows 
 float calculateAverage (char *dataPtr)  
 If the string passed as a parameter is malformed, return NAN 
 Examples: 
 calculateAverage("Hello");  // Return NAN 
 calculateAverage("");  // Return NAN 
 calculateAverage("1 2 3 12");  // Return NAN 
 calculateAverage("0 1 2 3 4 5 6 7 8 9 ");  // Returns 4.5 
 Implementation notes: 
 ● This function only calculates the average of single-digit numbers separated by spaces. 
 13. Implement a function that searches within a string for all occurrences of a passed word 
 as a parameter and replace them with another word. The function prototype is as follows: 
 int replaceWord (char *dataPtr, char *searchword,  
 char *newword);  
 Where: 
 dataPtr: It is a pointer to the string where the replacements are made 
 searchword: It is a pointer to the word to search. 
 newword: It is a pointer to the word to replace 
 Returns 
 ● a positive number indicating the number of words replaced. 
 ● -1 in case Searchword and Newword have different sizes. 
 ● -2 in case Searchword and Newword are '\0'. 
 86 

 14. Implement a function that determines whether a password meets all the recommendations of 
 security described below: 
 a.  It must be at least 8 characters. 
 b.  It should not have spaces. 
 c.  It must contain upper and lower case letters. 
 d.  It must contain one of these symbols ~! @ # $% ^& * _-+ = ' | \ \ (){}\ []:; "' <>,.? / 
 e.  Must contain a base 10 digit. (0 - 9) 
 The function prototype is as follows 
 int validatePassword(char *dataPtr)  
 Where: 
 ● dataPtr: It is the pointer to the password to validate. 
 ● Returns: 
 ○ 1: The password meets the four security recommendations. 
 ○ -1: If you do not comply with the recommendation 
 ○ -2: If you do not comply with recommendation b 
 ○ -3: If you do not comply with recommendation c 
 ○ -4: If you do not comply with the recommendation d 
 ○ -5: If you do not comply with the recommendation and 
 15. Implement a function that obtains the check digit of a CUIT number passed as 
 parameter, the calculation is performed using the modulo11 algorithm. The prototype of the function is 
 next: 
 int cuitValid (char *cuit);  
 Parameters 
 ● cuit: pointer to the vector containing the CUIT number ending in '\0' 
 Returns: 
 ● A positive number indicating the check digit. 
 ● -1: When the number of digits is different from 10 
 ● -2: Indicates that the CUIT number is invalid (contains something other than numbers) 
 Module 11 algorithm 
 a.  Multiply the digits from the least significant by the series 2,3,4,5,6,7. 
 b.  Add the result of the previous multiplications. 
 c.  Calculate the modulo 11 of the previous sum. 
 d.  Calculate 11 minus the previous result, if the result is less than 10 the result is the digit 
 verifier. On the other hand, if it is 10, the check digit is 9. If it is 11, the check digit is 0. 
 Example: 
 CUIT 2 0 1 2 3 4 5 6 7 8 Sum %11 Digit 
 Value to 
 multiply by 
 digit X5 X4 X3 X2 X7 X6 X5 X4 X3 
 Result of the 
 multiplication 10 0 3 4 21 24 25 24 21 16 =148 =5 6 
 87 

 18. Memory model 
 Data types (for 64 bits) 
 Data type Description Number of bytes 
 (sizeof)Range 
 char Character 1 -128 a127 
 unsigned char Character 1 0 to 255 
 short Integer 2 -32768 to 32767 
 unsigned short Integer 2 0 to 65535 
 int Integer 4 -2147483648 to 2147483647  
 unsigned int Integer 4 0 to 4294967295  
 ﬂoat Actual number 4 3.4E-38 to 3.4E+38  
 double Real number 8 1.7E-308 to 1.7E+308  
 void*; int*; ﬂoat*; 
 char* Pointers 8 --- 
 Scope of use of a variable. (scope of a variable) 
 The scope of a variable is the area or part of the program where it can be accessed. 
 1. For example in the following code fragment the variable 
 a.  The sum variable and the param parameter are only accessible within the function funcSuma1 
 b.  The aux and res variables are only accessible within the main function. 
 #include <stdio.h> 
 int funcSum1 (int param) 
 { 
 int sum; 
 sum = param + 1; 
 return (sum); 
 } 
 int main(void) 
 { 
 int num, res; 
 printf ("Enter number\r\n"); 
 scanf("%d", &num); 
 88 

 res = funcSum1(num); 
 printf ("Enter number\r\n"); 
 return (0); 
 } 
 Warning: 
 Never return the address of a local variable or parameter of a function 
 int * funcMal(void) { 
 int WRONG = 10; 
 return (&MAL); 
 } 
 2. For example in the following code fragment the variable 
 a.  The param parameter is only accessible within the function funcSuma1 
 b.  The aux and res variables are only accessible within the main function. 
 c.  The variable sum is global and is accessible in all functions of the .c file in this 
 case is accessible by funcSuma1 and by the main function 
 #include <stdio.h> 
 int sum; 
 int funcSum1 (int param) 
 { 
 sum = param + 1; 
 return (sum); 
 } 
 int main(void) 
 { 
 int num, res; 
 printf ("Enter number\r\n"); 
 scanf("%d", &num); 
 res = funcSum1 (num); 
 printf ("res = %d\r\n", res); 
 printf ("sum = %d\r\n", sum); 
 return (0); 
 } 
 Warning: 
 Avoid using global variables as much as possible. 
 89 

 memory map 
 Variable modifiers 
 ● auto : All variables are auto unless otherwise indicated. These variables are hosted 
 on the stack. Variables of this type cease to exist once we exit the function where 
 were defined. 
 ● extern: Used in global variables, so that they can be accessed outside of the .c in the 
 which are deﬁned. 
 ● static: Its operation depends on whether it is used in a local or global variable. 
 ○ If it is used in a variable local to a function, its value persists no matter how many times it is 
 has left the function. It is like a local variable, but can only be used within 
 90 

 the function that was defined. When defining a local variable as static it must be 
 initialized at the time it is deﬁned. 
 ○ If used in a global variable, it cannot be accessed from another .c Even if 
 makes an extern the variable unable to be accessed from another .c 
 ● volatile : A variable declared like this tells the compiler not to optimize the variable because it does not 
 finds it being used in that context. 
 ● const: Declaring it this way prevents the variable from being modiﬁed after initializing it. 
 ● register: It is a suggestion to place the variable in a processor register. 
 The following shows examples of 
 #include <stdio.h> 
 int funcSum1 (int param) 
 { 
 static int sum = 0;  //-- I declare a static variable -- 
 sum = param + 1; 
 return (sum); 
 } 
 int main(void) 
 { 
 int num, res;  //-- Auto variables -- 
 const int CONSTANT = 10;  //-- I declare a constant variable -- 
 printf ("Enter number\r\n"); 
 scanf("%d", &num); 
 res = funcSum1 (num); 
 printf ("res = %d\r\n", res); 
 return (0); 
 } 
 Memory addresses 
 Memory is the place where variables and the program are stored, it is usually organized in bytes and each 
 One of these is assigned a number that identifies it called an address. These addresses are written in 
 hexadecimal since it makes it easier to read. The following diagram shows 4 memory locations of 1 
 byte that stores the numbers 0, 1, 2, 3 and to its left the addresses of each of them 
 1 Byte 
 0x7ﬀebdeb2f60 0 
 0x7ﬀebdeb2f61 1 
 91 

 0x7ﬀebdeb2f62 2 
 0x7ﬀebdeb2f63 3 
 In the code we never place fixed memory positions (except for NULL) since every time we 
 We execute the code again, the operating system will assign us a different memory area. The 
 variables are the abstractionwhich we use to refer to memory areas. 
 To make it easier to see the examples, we are going to simplify the address numbers and above we are going to 
 To indicate the width in bytes of the memory, in the following examples we place 4 bytes to match 
 with the size of an int variable and is easier to read. Furthermore we are not going to take into account the byte 
 order of data stored in memory. 
 Below is a small code and the line where the execution was stopped is indicated in green 
 (the green line was not executed at the time of printing the memory map) on the right you can see 
 a memory map with the two variables involved in the code. 
 #include <stdio.h> 
 int main(void) 
 { 
 int num = 0, res = 0; 
 printf ("Enter number\r\n"); 
 scanf("%d", &num); 
 res = num + 1 
 printf ("res = %d\r\n", num); 
 return (0); 
 } 
 We continue the code execution of the code by entering the decimal number 4660 which in hexadecimal 
 is 0x1234, this number is stored in the variable num which is in memory location 0x7F00 
 #include <stdio.h> 
 int main(void) 
 { 
 int num = 0, res = 0; 
 printf ("Enter number\r\n"); 
 scanf("%d", &num); 
 res = num + 1 
 printf ("res = %d\r\n", num); 
 return (0); 
 } 
 92 

 The following example shows the memory map with a pointer in the code, you must remember that a 
 pointer is a variable that stores a memory address. 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 int num = 0x55AA; 
 int *p = NULL; 
 p = &num; 
 *p = 0x1234; 
 num = 0x2233; 
 return (0); 
 } 
 After assigning the pointer. The pointer p points to the variable num. 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 int num = 0x55AA; 
 int *p = NULL; 
 p = &num; 
 *p = 0x1234; 
 num = 0x2233; 
 return (0); 
 } 
 93 

 We change the value stored in the variable num using the pointer. 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 int num = 0x55AA; 
 int *p = NULL; 
 p = &num; 
 *p = 0x1234; 
 num = 0x2233; 
 return (0); 
 } 
 Finally I change the value of the variable 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 int num = 0x55AA; 
 int *p = NULL; 
 p = &num; 
 *p = 0x1234; 
 num = 0x2233; 
 return (0); 
 } 
 Standard streams 
 When the main function is executed, it has 3 predeﬁned streams open: 
 ● stdin : Standard input stream of the program, usually redirected to the keyboard 
 ● stdout: Standard output stream of the program, usually redirected to the terminal 
 text. 
 ● stderr: Program error output stream, usually redirected to the terminal 
 text. 
 All three are deﬁned in stdio.h as FILE *stdin; FILE *stdout; FILE *stderr; 
 94 

 95 

 19. Structures 
 Operator 
 Operator Description 
 sizeof() Returns the size of the operand 
 Examples 
 1. Program that creates a structure that contains the data name, age and sex. It is then initialized 
 at run time and prints it on the screen. 
 #include <stdio.h>  
 #include <string.h>  
 #define NAME_QTY ((int)16) //!< Number of elements in the vector  
 name 
 struct person {  
 char name[NAME_QTY];  
 int age;  
 char sex;  
 }; 
 int main(void)  
 { 
 struct person student;  
 //-- I initialize the structure --  
 strcpy (&student.name[0], "John");  
 student.age = 18;  
 student.sex = 'M';  
 //-- I print the structure --  
 printf("Name: %s\r\n", student.name);  
 printf("Age: %d\r\n", student.age);  
 printf("Sex: %c\r\n", student.sex);  
 return (0);  
 } 
 96 

 2. Program that creates a structure that contains the name, age and sex data. It is then initialized 
 by the user and prints it on the screen. 
 #include <stdio.h>  
 #define NAME_QTY ((int)16) //!< Number of elements in the vector  
 name 
 struct person {  
 char name[NAME_QTY];  
 int age;  
 char sex;  
 }; 
 int main(void)  
 { 
 struct person student;  
 //-- I initialize the structure --  
 printf ("Enter name:\r\n"); scanf ("%s", &student.name[0]);  
 printf ("Enter age:\r\n");   scanf ("%d", &student.age);  
 printf ("Enter gender:\r\n"); scanf ("%c", &student.sex);  
 //-- I print the structure --  
 printf("Name: %s\r\n", student.name);  
 printf("Age: %d\r\n", student.age);  
 printf("Sex: %c\r\n", student.sex);  
 return (0);  
 } 
 97 

 3. Program that creates a vector of structures of the type struct persona. Then the vector is initialized by 
 the user and prints it on the screen. 
 #include <stdio.h> 
 #define NAME_QTY ((int)16) //!< Number of elements in the name vector 
 #define QTY ((int)3) //!< Number of element of the student vector 
 struct person { 
 char name[NAME_QTY]; 
 int age; 
 char sex; 
 }; 
 int main(void) 
 { 
 struct person student[QTY]; 
 int i; 
 //-- I initialize the structure -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Enter name:\r\n"); 
 scanf ("%s", &(student[i].name[0])); 
 printf ("Enter age:\r\n"); 
 scanf ("%d", &(student[i].age)); 
 printf ("Enter gender:\r\n"); 
 scanf ("%*c%c", &(student[i].sex)); 
 } 
 //-- I print the vector of structures -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Name: %s\r\n", student[i].name); 
 printf ("Age: %d\r\n", student[i].age); 
 printf ("Sex: %c\r\n", student[i].sex); 
 } 
 return (0); 
 } 
 98 

 4. Program that creates a vector of structures of the struct persona type. Then the vector is initialized 
 using a pointer and prints it on the screen using the same pointer. 
 #include <stdio.h> 
 #define NAME_QTY ((int)16) //!< Number of elements in the name vector 
 #define QTY ((int)3) //!< Number of elements in the student vector 
 struct person { 
 char name[NAME_QTY]; 
 int age; 
 char sex; 
 }; 
 int main(void) 
 { 
 struct person student[QTY]; 
 struct person *p; 
 int i; 
 p = &student[0];  //-- Initialize the pointer -- 
 //-- I initialize the structure -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Enter name:\r\n"); 
 scanf ("%s", &((p + i)->name[0])); 
 printf ("Enter age:\r\n"); 
 scanf ("%d", &((p + i)->age)); 
 printf ("Enter gender:\r\n"); 
 scanf ("%*c%c", &((p + i)->sex)); 
 } 
 //-- I print the vector of structures -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Name: %s\r\n", (p + i)->name); 
 printf ("Age: %d\r\n", (p + i)->age); 
 printf ("Sex: %c\r\n", (p + i)->sex); 
 } 
 return (0); 
 } 
 99 

 5. Program that creates a structure of the type struct persona and an element of this is another structure of the 
 type struct data. Then both are initialized by the user and printed on the screen. 
 #include <stdio.h> 
 #define NAME_QTY ((int)16) //!< Number of elements in the name vector 
 #define QTY ((int)3) //!< Number of elements in the student vector 
 struct data { 
 int age; 
 char sex; 
 }; 
 struct person { 
 char name[NAME_QTY]; 
 struct data eg; 
 }; 
 int main(void) 
 { 
 struct person student[QTY]; 
 int i; 
 //-- I initialize the structure -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Enter name:\r\n"); 
 scanf ("%s", &(student[i].name[0])); 
 printf ("Enter age:\r\n"); 
 scanf ("%d", &(student[i].eg.age)); 
 printf ("Enter gender:\r\n"); 
 scanf ("%*c%c", &(student[i].eg.sex)); 
 } 
 //-- I print the vector of structures -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Name: %s\r\n", student[i].name); 
 printf ("Age: %d\r\n", student[i].eg.age); 
 printf ("Sex: %c\r\n", student[i].eg.sex); 
 } 
 return (0); 
 } 
 100 

 6. Program that creates a vector of structures of the type struct persona and an element of this is another 
 structure of type struct data. Then the vector is initialized using a pointer and printed by 
 screen using the same pointer. 
 #include <stdio.h> 
 #define NAME_QTY ((int)16) //!< Number of elements in the name vector 
 #define QTY ((int)3) //!< Number of elements in the student vector 
 struct data { 
 int age; 
 char sex; 
 }; 
 struct person { 
 char name[NAME_QTY]; 
 struct data eg; 
 }; 
 int main(void) 
 { 
 struct person student[QTY]; 
 struct person *p; 
 int i; 
 p = &student[0];  //-- Initialize the pointer -- 
 //-- I initialize the structure -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Enter name:\r\n"); 
 scanf ("%s", &((p + i)->name[0])); 
 printf ("Enter age:\r\n"); 
 scanf ("%d", &((p + i)->eg.age)); 
 printf ("Enter gender:\r\n"); 
 scanf ("%*c%c", &((p + i)->eg.sex)); 
 } 
 //-- I print the vector of structures -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Name: %s\r\n", (p + i)->name); 
 printf ("Age: %d\r\n", (p + i)->eg.age); 
 printf ("Sex: %c\r\n", (p + i)->eg.sex); 
 } 
 return (0); 
 } 
 101 

 7. Program that creates a vector of structures of the type struct persona whose elements are a vector 
 for thestore the name and a vector of final struct structures. 
 #include <stdio.h> 
 #define NAME_QTY ((int)16) //!< Number of elements in the name vector 
 #define QTY ((int)3) //!< Number of elements in the student vector 
 #define FINALS_QTY ((int)16) //!< Number of elements of the matter vector 
 final struct { 
 char matter[MATTER_QTY]; 
 int note; 
 }; 
 struct person { 
 char name[NAME_QTY]; 
 final struct final[ENDS_QTY]; 
 }; 
 int main(void) 
 { 
 struct person student[QTY]; 
 int i, j; 
 p = &student[0];  //-- Initialize the pointer -- 
 //-- I initialize the structure -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Enter name:\r\n"); 
 scanf ("%s", &(student[i].name[0])); 
 for (j = 0; j < QTY; j++) { 
 printf ("Enter subjects:\r\n"); 
 scanf ("%s", &((p + i)->end[j].matter[0])); 
 printf ("Enter note:\r\n"); 
 scanf ("%d", &((p + i)->end[j].note)); 
 } 
 } 
 //-- I print the vector of structures -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Name: %s\r\n", (p + i)->name); 
 for (j = 0; j < FINAL_QTY; j++) { 
 printf ("Matter: %s\r\n", (p + i)->end[j].matter)); 
 printf ("Note: %d\r\n", (p + i)->end[j].note); 
 } 
 } 
 return (0); 
 } 
 102 

 8. Program that creates a vector of structures of the type struct persona whose elements are a vector 
 to store the name and a vector of final struct structures. Using a pointer. 
 #include <stdio.h> 
 #define NAME_QTY ((int)16) //!< Number of elements in the name vector 
 #define QTY ((int)3) //!< Number of elements in the student vector 
 #define FINALS_QTY ((int)16) //!< Number of elements of the matter vector 
 final struct { 
 char matter[MATTER_QTY]; 
 int note; 
 }; 
 struct person { 
 char name[NAME_QTY]; 
 final struct final[ENDS_QTY]; 
 }; 
 int main(void) 
 { 
 struct person student[CANT], *p; 
 int i, j; 
 //-- I initialize the structure -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Enter name:\r\n"); 
 scanf ("%s", &(student[i].name[0])); 
 for (j = 0; j < QTY; j++) { 
 printf ("Enter subjects:\r\n"); 
 scanf ("%s", &(student[i].final[j].subject[0])); 
 printf ("Enter note:\r\n"); 
 scanf ("%d", &(student[i].end[j].note)); 
 } 
 } 
 //-- I print the vector of structures -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Name: %s\r\n", student[i].name); 
 for (j = 0; j < FINAL_QTY; j++) { 
 printf ("Subject: %s\r\n", student[i].final[j].subject)); 
 printf ("Note: %d\r\n", student[i].final[j].grade); 
 } 
 } 
 return (0); 
 } 
 103 

 9. Program that creates a structure that stores age, sex and a pointer to a created vector 
 dynamically to store the name. 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <string.h> 
 #define NAME_QTY ((int)16) //!< Maximum number of elements of the name. 
 struct person { 
 char *name; 
 int age; 
 char sex; 
 }; 
 int main(void) 
 { 
 struct person student; 
 char name[NAME_QTY]; 
 //-- I initialize the structure -- 
 printf ("Enter name:\r\n"); scanf ("%s", &name[0]); 
 student.name = (char *)malloc(strlen(name) + 1); 
 if (student.name == NULL) { 
 return (-1); 
 } else { 
 strcpy(student.name, name); 
 } 
 printf ("Enter age:\r\n");   scanf ("%d", &student.age); 
 printf ("Enter gender:\r\n"); scanf ("%c", &student.sex); 
 //-- I print the structure -- 
 printf("Name: %s\r\n", student.name); 
 printf("Age: %d\r\n", student.age); 
 printf("Sex: %c\r\n", student.sex); 
 return (0); 
 } 
 104 

 10. Program demonstrating the use of sizeof 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <string.h> 
 #define QTY ((int)10) //!< Quantity. 
 struct data{ 
 char *ptr; 
 int varInt; 
 int vectInt[QTY]; 
 }; 
 int main(void) 
 { 
 int varInt, vectInt[CANT], *ptrInt; 
 char varChar, vectChar[CANT], *ptrChar; 
 struct data varStruct, vectStruct[CANT], *ptrStruct; 
 printf ("sizeof(varInt): %d\r\n", sizeof(varInt)); 
 printf ("sizeof(vectInt): %d\r\n", sizeof(vectInt)); 
 printf ("sizeof(vectInt[0]): %d\r\n", sizeof(vectInt[0])); 
 printf ("sizeof(ptrInt): %d\r\n", sizeof(ptrInt)); 
 printf ("sizeof(*ptrInt): %d\r\n", sizeof(*ptrInt)); 
 printf ("sizeof(varChar): %d\r\n", sizeof(varChar)); 
 printf ("sizeof(vectChar): %d\r\n", sizeof(vectChar)); 
 printf ("sizeof(vectChar[0]): %d\r\n", sizeof(vectChar[0])); 
 printf ("sizeof(ptrChar): %d\r\n", sizeof(ptrChar)); 
 printf("sizeof(*ptrChar): %d\r\n", sizeof(*ptrChar)); 
 printf ("sizeof(varStruct): %d\r\n", sizeof(varStruct)); 
 printf ("sizeof(vectStruct): %d\r\n", sizeof(vectStruct)); 
 printf ("sizeof(vectStruct[0]): %d\r\n", sizeof(vectStruct[0])); 
 printf ("sizeof(ptrStruct): %d\r\n", sizeof(ptrStruct)); 
 printf ("sizeof(*ptrStruct): %d\r\n", sizeof(*ptrStruct)); 
 printf ("sizeof(varStruct.ptr): %d\r\n", sizeof(varStruct.ptr)); 
 printf ("sizeof(varStruct.varInt): %d\r\n", sizeof(varStruct.varInt)); 
 printf ("sizeof(varStruct.vectInt): %d\r\n", sizeof(varStruct.vectInt)); 
 return (0); 
 } 
 105 

 When you run the code you see 
 jerome@linuxVm:~$ ./example18_10.out  
 sizeof(varInt): 4  
 sizeof(vectInt): 40  
 sizeof(vectInt[0]): 4  
 sizeof(ptrInt): 8  
 sizeof(*ptrInt): 4  
 sizeof(varChar): 1  
 sizeof(vectChar): 10  
 sizeof(vectChar[0]): 1  
 sizeof(ptrChar): 8  
 sizeof(*ptrChar): 1  
 sizeof(varStruct): 56  
 sizeof(vectStruct): 560  
 sizeof(vectStruct[0]): 56  
 sizeof(ptrStruct): 8  
 sizeof(*ptrStruct): 56  
 sizeof(varStruct.ptr): 8  
 sizeof(varStruct.varInt): 4  
 sizeof(varStruct.vectInt): 40  
 11. Demonstrating program 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <string.h> 
 struct data{ 
 int varInt0; 
 char varChar0; 
 int varInt1; 
 char varChar1; 
 }; 
 struct dataAlign { 
 int varInt0; 
 int varInt1; 
 char varChar0; 
 char varChar1; 
 }; 
 int main(void) 
 { 
 struct data varStruct; 
 struct dataAlign varStructAlign; 
 printf ("sizeof(varStruct): %ld\r\n", sizeof(varStruct)); 
 printf ("sizeof(varStructAlign): %ld\r\n", sizeof(varStructAlign)); 
 return (0); 
 } 
 106 

 When you run the code you see 
 jerome@linuxVm:~/jatencio$ ./example18_11.out  
 sizeof(varStruct): 16  
 sizeof(varStructAlign): 12  
 Warning: 
 The sizeof of a structure does not always coincide with the sum of the sizeof of each field, this is 
 due to the alignment of the structure fields. 
 Exercises 
 1. Implement a program that asks the user for data to fill a vector of 10 structures of the type 
 struct person. This vector of structures must be created dynamically using malloc. It is known 
 that the name entered by the user does not have more than 16 characters including '\0' To 
 store the name entered by the user must use malloc reserving exactly the 
 number of characters of the name entered plus the space for '\0'. At the end of the entry 
 print the entire vector and free the reserved memory before ending the program. 
 struct person {  
 char *name;  
 int age;  
 char sex;  
 }; 
 2. Implement a function with the following prototype that performs data entry like the exercise 
 previous. 
 struct person* income (int dataCant);  
 Where: 
 dataCant: It is the number of structures to reserve. 
 The function returns a pointer to the dynamically created vector of structures. 
 3. Implement a function that prints the data stored in the passed structures vector as 
 parameter. 
 void print (struct person *p, int dataCant);  
 Where: 
 p: Pointer to the vector of structures. 
 dataCant: It is the number of structures pointed to by p. 
 4. Implement a function that frees the reserved memory. 
 void release (struct person *p, int dataCant);  
 Where: 
 p: Pointer to the vector of structures to release. 
 dataCant: It is the number of structures pointed to by p. 
 107 

 5. Implement a function that performs the sorting of a vector of structures of type struct 
 person by name. The function prototype is as follows. 
 void sort(struct person *p, int dataQty);  
 Where: 
 p: Pointer to the vector of structures. 
 dataCant: It is the number of structures pointed to by p. 
 6. Implement a function with the following prototype that performs data entry for the structures 
 of the following types. 
 final struct {  
 char matter[16];  
 int note;  
 }; 
 struct student {  
 char name[16]  
 int finalQuant;  
 struct final *final;  
 }; 
 struct student* income (int dataCant);  
 Where: 
 dataCant: It is the number of structures to reserve. 
 The user will enter the name of the student and then for each one they will enter the name of the subject 
 and the final note. The loading of the finals ends when a subject is entered with a grade equal to -1. 
 The elementFinalCount indicates the number of elements of the vector pointed to by the final pointer. 
 Use realloc to perform thisexercise. 
 7. Implement a function that prints the data stored in the passed structures vector as 
 parameter. 
 void print (struct student *p, int dataQty);  
 Where: 
 p: Pointer to the vector of structures. 
 dataCant: It is the number of structures pointed to by p. 
 8. Implement a function that frees the reserved memory. 
 void release (struct student *p, int dataQty);  
 Where: 
 p: Pointer to the vector of structures to release. 
 dataCant: It is the number of structures pointed to by p. 
 9. Implement a function that performs the sorting of a vector of structures of type struct 
 student by number of finals. The function prototype is as follows. 
 void sort(struct student *p, int dataQty);  
 Where: 
 p: Pointer to the vector of structures. 
 dataCant: It is the number of structures pointed to by p 
 108 

 10. Implement a function that performs a search by name and subject in a vector of structures 
 of type struct student. The function prototype is as follows. 
 int search(struct student *p, int dataQty, char *name,  
 char *matter);  
 Where: 
 p: Pointer to the vector of structures. 
 dataCant: It is the number of structures pointed to by p 
 name: Pointer of the name to search 
 matter: Pointer of the matter to search for. 
 Returns: 
 -1: If you didn't find the name 
 -2: If the matter was not found 
 The note if you found the name and subject. 
 109 

 20. Files I 
 Used functions of stdio.h 
 Function Description 
 fopen Open a file. 
 fprintf Write text to a file. 
 fgets Read a string from a file. 
 fscanf Reads from a file according to the indicated format. 
 feof Indicates if we have reached the end of the file 
 fclose Closes a file. 
 Ways to open a file 
 Mode Description Starting position 
 r Open the file for reading At the beginning of the file 
 r+ Open the file for reading and writing At the beginning of the file 
 w Open the file for writing 
 Truncate the file to zero size or 
 Create the file if it does not exist At the beginning of the file 
 w+ Open the file for writing 
 Truncate the file to zero size or 
 Create the file if it does not exist At the beginning of the file 
 a Open the file to add. 
 Create the file if it does not exist.  At the end of the file 
 a+ Open the file to read and append. 
 Create the file if it does not exist.  At the end of the file 
 Required programs 
 Use apt to install them 
 Package Description 
 okteta Raw file editor. Allows you to view them in hexa, octal, ascii, etc. 
 hexdump Displays the contents of a file in hexa, octal, ascii, etc. 
 110 

 Commands 
 Command Description 
 cat Print a file to stdout (screen) 
 head Print the first lines of a file to stdout (screen) 
 tail Print the last lines of a file to stdout (screen) 
 Example of command use. 
 We perform an ls of / and store it in the file list.txt. 
 jerome@linuxVm:~$ ls / -las > list.txt  
 We can verify the content of the list.txt file using a text editor (for example atom) 
 We execute the cat command on list.txt, to see all the content on the screen. 
 jerome@linuxVm:~$ cat list.txt  
 total 104  
 4 drwxr-xr-x 23 root root 4096 Apr 2 21:22 .  
 4 drwxr-xr-x 23 root root 4096 Apr 2 21:22 ..  
 4 drwxr-xr-x 2 root root 4096 Apr 2 21:23 bin  
 4 drwxr-xr-x 3 root root 4096 Apr 5 11:01 boot  
 4 drwxrwxr-x 2 root root 4096 Apr 2 21:15 cdrom  
 0 drwxr-xr-x 18 root root 3920 May 10 15:33 dev  
 12 drwxr-xr-x 122 root root 12288 May 10 15:33 etc  
 4 drwxr-xr-x 3 root root 4096 Apr 2 21:21 home  
 0 lrwxrwxrwx 1 root root Apr 33 2 21:22 initrd.img ->  
 boot/initrd.img-4.10.0-28-generic  
 4 drwxr-xr-x 20 root root 4096 Apr 2 21:23 lib  
 4 drwxr-xr-x 2 root root 4096 Apr 3 04:07 lib64  
 16 drwx------ 2 root root 16384 Apr 2 21:07 lost+found  
 4 drwxr-xr-x 3 root root 4096 Apr 2 22:22 media  
 4 drwxr-xr-x 2 root root 4096 Aug 1 2017 mnt  
 4 drwxr-xr-x 3 root root 4096 Apr 5 10:59 opt  
 0 dr-xr-xr-x 137 root root 0 May 10 15:32 proc  
 4 drwx------ 3 root root 4096 May 10 15:33 root  
 0 drwxr-xr-x 22 root root 680 May 10 15:38 run  
 12 drwxr-xr-x 2 root root 12288 Apr 5 11:01 sbin  
 4 drwxr-xr-x 2 root root 4096 Aug 1 2017 srv  
 0 dr-xr-xr-x 13 root root 0 May 10 15:38 sys  
 4 drwxrwxrwt 9 root root 4096 May 10 15:38 tmp  
 4 drwxr-xr-x 10 root root 4096 Aug 1 2017 usr  
 4 drwxr-xr-x 13 root root 4096 Aug 1 2017 var  
 0 lrwxrwxrwx 1 root root Apr 30 2 21:22 vmlinuz ->  
 boot/vmlinuz-4.10.0-28-generic  
 Displays the last 5 lines of the list.txt file 
 111 

 jerome@linuxVm:~$ tail -n5 list.txt  
 0 dr-xr-xr-x 13 root root 0 May 10 15:38 sys  
 4 drwxrwxrwt 9 root root 4096 May 10 15:38 tmp  
 4 drwxr-xr-x 10 root root 4096 Aug 1 2017 usr  
 4 drwxr-xr-x 13 root root 4096 Aug 1 2017 var  
 0 lrwxrwxrwx 1 root root Apr 30 2 21:22 vmlinuz ->  
 boot/vmlinuz-4.10.0-28-generic  
 Displays the first 5 lines of the list.txt file 
 jerome@linuxVm:~$ head -n5 list.txt  
 total 104  
 4 drwxr-xr-x 23 root root 4096 Apr 2 21:22 .  
 4 drwxr-xr-x 23 root root 4096 Apr 2 21:22 ..  
 4 drwxr-xr-x 2 root root 4096 Apr 2 21:23 bin  
 4 drwxr-xr-x 3 root root 4096 Apr 5 11:01 boot  
 Display list.txt file in hexa and ASCII 
 jerome@linuxVm:~$ hexdump ./list.txt -C  
 00000000 74 6f 74 61 6c 20 31 30 34 0a 20 34 20 64 72 77 |total 104. 4 drw| 
 00000010 78 72 2d 78 72 2d 78 20 20 32 33 20 72 6f 6f 74 |xr-xr-x 23 root| 
 00000020 20 72 6f 6f 74 20 20 34 30 39 36 20 61 62 72 20 | root Apr 4096 | 
 00000030 20 32 20 32 31 3a 32 32 20 2e 0a 20 34 20 64 72 | 2 21:22 .. 4 dr| 
 00000040 77 78 72 2d 78 72 2d 78 20 20 32 33 20 72 6f 6f |wxr-xr-x 23 roo| 
 00000050 74 20 72 6f 6f 74 20 20 34 30 39 36 20 61 62 72 |t root 4096 Apr| 
 00000060 20 20 32 20 32 31 3a 32 32 20 2e 2e 0a 20 34 20 |  2 21:22 ... 4 | 
 00000070 64 72 77 78 72 2d 78 72 2d 78 20 20 20 32 20 72 |drwxr-xr-x 2 r| 
 00000080 6f 6f 74 20 72 6f 6f 74 20 20 34 30 39 36 20 61 |oot root 4096 a| 
 00000090 62 72 20 20 32 20 32 31 3a 32 33 20 62 69 6e 0a |br 2 21:23 bin.| 
 000000a0 20 34 20 64 72 77 78 72 2d 78 72 2d 78 20 20 20 | 4 drwxr-xr-x | 
 000000b0 33 20 72 6f 6f 74 20 72 6f 6f 74 20 20 34 30 39 |3 root root 409| 
 000000c0 36 20 61 62 72 20 20 35 20 31 31 3a 30 31 20 62 |6 Apr 5 11:01 b| 
 000000d0 6f 6f 74 0a 20 34 20 64 72 77 78 72 77 78 72 2d |oot. 4 drwxrwxr-| 
 000000e0 78 20 20 20 32 20 72 6f 6f 74 20 72 6f 6f 74 20 |x 2 root root | 
 000000f0 20 34 30 39 36 20 61 62 72 20 20 32 20 32 31 3a | 4096 Apr 2 21:| 
 00000100 31 35 20 63 64 72 6f 6d 0a 20 30 20 64 72 77 78 |15 cdrom. 0 drwx| 
 00000110 72 2d 78 72 2d 78 20 20 31 38 20 72 6f 6f 74 20 |r-xr-x 18 root | 
 00000120 72 6f 6f 74 20 20 33 39 32 30 20 6d 61 79 20 31 |root 3920 May 1| 
 00000130 30 20 31 35 3a 33 33 20 64 65 76 0a 31 32 20 64 |0 15:33 dev.12 d| 
 00000140 72 77 78 72 2d 78 72 2d 78 20 31 32 32 20 72 6f |rwxr-xr-x 122 ro| 
 00000150 6f 74 20 72 6f 6f 74 20 31 32 32 38 38 20 6d 61 |ot root 12288 ma| 
 00000160 79 20 31 30 20 31 35 3a 33 33 20 65 74 63 0a 20 |and 10 15:33 etc. | 
 00000170 34 20 64 72 77 78 72 2d 78 72 2d 78 20 20 20 33 |4 drwxr-xr-x 3| 
 00000180 20 72 6f 6f 74 20 72 6f 6f 74 20 20 34 30 39 36 | root root 4096| 
 00000190 20 61 62 72 20 20 32 20 32 31 3a 32 31 20 68 6f | Apr 2 21:21 today 
 000001a0 6d 65 0a 20 30 20 6c 72 77 78 72 77 78 72 77 78 |me. 0 lrwxrwxrwx| 
 000001b0 20 20 20 31 20 72 6f 6f 74 20 72 6f 6f 74 20 20 |   1 root root | 
 000001c0 20 20 33 33 20 61 62 72 20 20 32 20 32 31 3a 32 |  Apr 33 2 21:2| 
 000001d0 32 20 69 6e 69 74 72 64 2e 69 6d 67 20 2d 3e 20 |2 initrd.img -> | 
 000001e0 62 6f 6f 74 2f 69 6e 69 74 72 64 2e 69 6d 67 2d |boot/initrd.img-| 
 000001f0 34 2e 31 30 2e 30 2d 32 38 2d 67 65 6e 65 72 69 |4.10.0-28-generi| 
 112 

 00000200 63 0a 20 34 20 64 72 77 78 72 2d 78 72 2d 78 20 |c. 4 drwxr-xr-x | 
 00000210 20 32 30 20 72 6f 6f 74 20 72 6f 6f 74 20 20 34 | 20 root root 4| 
 00000220 30 39 36 20 61 62 72 20 20 32 20 32 31 3a 32 33 |096 Apr 2 21:23| 
 00000230 20 6c 69 62 0a 20 34 20 64 72 77 78 72 2d 78 72 | lib. 4 drwxr-xr| 
 00000240 2d 78 20 20 20 32 20 72 6f 6f 74 20 72 6f 6f 74 |-x 2 root root| 
 00000250 20 20 34 30 39 36 20 61 62 72 20 20 33 20 30 34 |  4096 Apr 3 04| 
 00000260 3a 30 37 20 6c 69 62 36 34 0a 31 36 20 64 72 77 |:07 lib64.16 drw| 
 00000270 78 2d 2d 2d 2d 2d 2d 20 20 20 32 20 72 6f 6f 74 |x------ 2 root| 
 00000280 20 72 6f 6f 74 20 31 36 33 38 34 20 61 62 72 20 | root Apr 16384 | 
 00000290 20 32 20 32 31 3a 30 37 20 6c 6f 73 74 2b 66 6f | 2 21:07 lost+fo| 
 000002a0 75 6e 64 0a 20 34 20 64 72 77 78 72 2d 78 72 2d |und. 4 drwxr-xr-| 
 000002b0 78 20 2020 33 20 72 6f 6f 74 20 72 6f 6f 74 20 |x 3 root root | 
 000002c0 20 34 30 39 36 20 61 62 72 20 20 32 20 32 32 3a | 4096 Apr 2 22:| 
 000002d0 32 32 20 6d 65 64 69 61 0a 20 34 20 64 72 77 78 |22 average. 4 drwx| 
 000002e0 72 2d 78 72 2d 78 20 20 20 32 20 72 6f 6f 74 20 |r-xr-x 2 root | 
 000002f0 72 6f 6f 74 20 20 34 30 39 36 20 61 67 6f 20 20 |root 4096 Aug | 
 00000300 31 20 20 32 30 31 37 20 6d 6e 74 0a 20 34 20 64 |1 2017 mnt. 4 d| 
 00000310 72 77 78 72 2d 78 72 2d 78 20 20 20 33 20 72 6f |rwxr-xr-x 3 ro| 
 00000320 6f 74 20 72 6f 6f 74 20 20 34 30 39 36 20 61 62 |ot root 4096 ab| 
 00000330 72 20 20 35 20 31 30 3a 35 39 20 6f 70 74 0a 20 |r 5 10:59 opt. | 
 00000340 30 20 64 72 2d 78 72 2d 78 72 2d 78 20 31 33 37 |0 dr-xr-xr-x 137| 
 00000350 20 72 6f 6f 74 20 72 6f 6f 74 20 20 20 20 20 30 | root root 0| 
 00000360 20 6d 61 79 20 31 30 20 31 35 3a 33 32 20 70 72 | May 10 15:32 pr| 
 00000370 6f 63 0a 20 34 20 64 72 77 78 2d 2d 2d 2d 2d 2d |oc. 4 drwx------| 
 00000380 20 20 20 33 20 72 6f 6f 74 20 72 6f 6f 74 20 20 |   3 root root | 
 00000390 34 30 39 36 20 6d 61 79 20 31 30 20 31 35 3a 33 |4096 May 10 15:3| 
 000003a0 33 20 72 6f 6f 74 0a 20 30 20 64 72 77 78 72 2d |3 root. 0 drwxr-| 
 000003b0 78 72 2d 78 20 20 32 32 20 72 6f 6f 74 20 72 6f |xr-x 22 root ro| 
 000003c0 6f 74 20 20 20 36 38 30 20 6d 61 79 20 31 30 20 |ot 680 May 10 | 
 000003d0 31 35 3a 33 38 20 72 75 6e 0a 31 32 20 64 72 77 |15:38 run.12 drw| 
 000003e0 78 72 2d 78 72 2d 78 20 20 20 32 20 72 6f 6f 74 |xr-xr-x 2 root| 
 000003f0 20 72 6f 6f 74 20 31 32 32 38 38 20 61 62 72 20 | root Apr 12288 | 
 00000400 20 35 20 31 31 3a 30 31 20 73 62 69 6e 0a 20 34 | 5 11:01 sbin. 4| 
 00000410 20 64 72 77 78 72 2d 78 72 2d 78 20 20 20 32 20 | drwxr-xr-x 2 | 
 00000420 72 6f 6f 74 20 72 6f 6f 74 20 20 34 30 39 36 20 |root root 4096 | 
 00000430 61 67 6f 20 20 31 20 20 32 30 31 37 20 73 72 76 |Aug 1 2017 srv| 
 00000440 0a 20 30 20 64 72 2d 78 72 2d 78 72 2d 78 20 20 |. 0 dr-xr-xr-x | 
 00000450 31 33 20 72 6f 6f 74 20 72 6f 6f 74 20 20 20 20 |13 root root | 
 00000460 20 30 20 6d 61 79 20 31 30 20 31 35 3a 33 38 20 | 0 May 10 15:38 | 
 00000470 73 79 73 0a 20 34 20 64 72 77 78 72 77 78 72 77 |sys. 4 drwxrwxrw| 
 00000480 74 20 20 20 39 20 72 6f 6f 74 20 72 6f 6f 74 20 |t 9 root root | 
 00000490 20 34 30 39 36 20 6d 61 79 20 31 30 20 31 35 3a | 4096 May 10 15:| 
 000004a0 33 38 20 74 6d 70 0a 20 34 20 64 72 77 78 72 2d |38 tmp. 4 drwxr-| 
 000004b0 78 72 2d 78 20 20 31 30 20 72 6f 6f 74 20 72 6f |xr-x 10 root ro| 
 000004c0 6f 74 20 20 34 30 39 36 20 61 67 6f 20 20 31 20 |ot 4096 Aug 1 | 
 000004d0 20 32 30 31 37 20 75 73 72 0a 20 34 20 64 72 77 | 2017 usr. 4 drw| 
 000004e0 78 72 2d 78 72 2d 78 20 20 31 33 20 72 6f 6f 74 |xr-xr-x 13 root| 
 000004f0 20 72 6f 6f 74 20 20 34 30 39 36 20 61 67 6f 20 | root Aug 4096 | 
 00000500 20 31 20 20 32 30 31 37 20 76 61 72 0a 20 30 20 | 1 2017 var. 0 | 
 00000510 6c 72 77 78 72 77 78 72 77 78 20 20 20 31 20 72 |lrwxrwxrwx 1 r| 
 00000520 6f 6f 74 20 72 6f 6f 74 20 20 20 20 33 30 20 61 |oot root 30 a| 
 00000530 62 72 20 20 32 20 32 31 3a 32 32 20 76 6d 6c 69 |br 2 21:22 vmli| 
 00000540 6e 75 7a 20 2d 3e 20 62 6f 6f 74 2f 76 6d 6c 69 |nuz -> boot/vmli| 
 113 

 00000550 6e 75 7a 2d 34 2e 31 30 2e 30 2d 32 38 2d 67 65 |nuz-4.10.0-28-ge| 
 00000560 6e 65 72 69 63 0a |neric.| 
 00000566 
 Examples 
 1. Program that creates a file with the name test.txt, writes in it the legend "Hello world!!!" and 
 close the file. 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 FILE *f; 
 int aux; 
 //-- I open the file -- 
 f = fopen("./test.txt", "w"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- I write -- 
 aux = fprintf(f, "Hello world!!!"); 
 if (aux < 0) { 
 printf ("Error writing to file\r\n"); 
 return (-1); 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Write and save the above code in a file named example20_01.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example20_01.c -Wall -oexample20_01.out  
 jerome@linuxVm:~$ ./example20_01.out  
 jerome@linuxVm:~$ cat ./test.txt  
 jerome@linuxVm:~$ hexdump ./test.txt -C  
 Finish meOpen the test.txt file with a text editor or with the cat command and confirm your 
 content. Also verify the contents with okteta or the hexdump command 
 114 

 2. Program reads a file containing a line of text and prints it on the screen. 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 FILE *f; 
 int aux; 
 char buffer[32], *p; 
 //-- I open the file -- 
 f = fopen("./test.txt", "r"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- Leo -- 
 p = fgets(buffer, sizeof(buffer), f); 
 if (p == NULL) { 
 printf ("Error reading file\r\n"); 
 return (-2); 
 } 
 printf ("The string read is: %s\r\n", buffer); 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 return (-3); 
 } 
 return (0); 
 } 
 115 

 3. Program that adds a line of text to the end of the file. 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 FILE *f; 
 int aux; 
 //-- I open the file -- 
 f = fopen("./test.txt", "a"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- I write -- 
 aux = fprintf (f, "New line!!\r\n"); 
 if (aux < 0) { 
 printf ("Error writing to file\r\n"); 
 return (-1); 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Write and save the above code in a file named example20_03.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example20_03.c -Wall -oexample20_03.out  
 jerome@linuxVm:~$ ./example20_03.out  
 jerome@linuxVm:~$ cat ./test.txt  
 jerome@linuxVm:~$ hexdump ./test.txt -C  
 Finally open the file test.txt with a text editor or with the cat command and confirm your 
 content. Also verify the contents with okteta or the hexdump command 
 116 

 4. Program that writes an integer entered by the user to a file called 
 testNum.txt 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 FILE *f; 
 int aux; 
 int a; 
 //-- Entering an integer -- 
 printf ("Enter number\r\n"); 
 scanf("%d", &a); 
 //-- I open the file -- 
 f = fopen("./testNum.txt", "w"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- I write -- 
 aux = fprintf (f, "%d\r\n", a); 
 if (aux < 0) { 
 printf ("Error writing to file\r\n"); 
 return (-1); 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Write and save the above code in a file named example20_04.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example20_04.c -Wall -oexample20_04.out  
 jerome@linuxVm:~$ ./example20_04.out  
 jerome@linuxVm:~$ cat ./testNum.txt  
 jerome@linuxVm:~$ hexdump ./testNum.txt -C  
 Finally open the file testNum.txt with a text editor or with the cat command and confirm your 
 content. Also verify the contents with okteta or the hexdump command 
 117 

 5. Program that reads an integer that is stored in a file. 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 FILE *f; 
 int aux; 
 int a; 
 //-- I open the file -- 
 f = fopen("./testNum.txt", "r"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- I read a number from the file -- 
 aux = fscanf (f, "%d\r\n", &a); 
 if (aux <= 0) { 
 printf ("Error reading file\r\n"); 
 return (-1); 
 } else { 
 printf ("The number read is: %d\r\n", a); 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Write and save the above code in a file named example20_05.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example20_05.c -Wall -oexample20_05.out  
 jerome@linuxVm:~$ ./example20_05.out  
 Finally verify that the number read from the file matches the one stored by the example 
 previous. 
 118 

 6. Program that writes ten integers to a file called testNum.txt 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 FILE *f; 
 int aux; 
 int i; 
 //-- I open the file -- 
 f = fopen("./testNum.txt", "w"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- I write -- 
 for (i = 0; i < QTY; i++) { 
 aux = fprintf (f, "%d\r\n", i);if (aux < 0) { 
 printf ("Error writing to file\r\n"); 
 return (-1); 
 } 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Write and save the above code in a file named example20_06.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example20_06.c -Wall -oexample20_06.out  
 jerome@linuxVm:~$ ./example20_06.ou t 
 jerome@linuxVm:~$ cat ./testNum.txt  
 jerome@linuxVm:~$ hexdump ./testNum.txt -C  
 Finally open the file testNum.txt with a text editor or with the cat command and confirm your 
 content. Also verify the contents with okteta or the hexdump command 
 119 

 7. Program that reads all integers in a file called testNum.txt and prints them in 
 screen. 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 FILE *f; 
 int aux; 
 int a; 
 //-- I open the file -- 
 f = fopen("./testNum.txt", "r"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- Leo -- 
 while (!feof(f)) { 
 aux = fscanf (f, "%d\r\n", &a); 
 if (aux < 0) { 
 printf ("Error reading from file\r\n"); 
 return (-1); 
 } else { 
 printf ("The number read is: %d\r\n", a); 
 } 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Write and save the above code in a file named example20_07.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example20_07.c -Wall -oexample20_07.out  
 jerome@linuxVm:~$ ./example20_07.out  
 120 

 Exercises 
 1. Implement a program that prints the entire contents of the file exercise20_01.c per screen. 
 2. Implement a program that asks the user to enter the full path and name of a 
 file (everything is entered together) and then print the entire contents of the file. Please note that if 
 use the fgets function, it adds the character \x0A to the end of what is entered and it must be eliminated, 
 To do this you can use the strchr function that looks for a character in a string and replaces it with '\0' 
 3. Develop a program that creates a file called test.txt and using the fprintf function (check 
 the value returned by it) write all odd numbers between zero and 100. If the file existed it would 
 will need to be overwritten. 
 4. Implement a program that asks the user for ten names along with ten ages and stores them in 
 a file with the following format. Use the fprintf function. 
 Name, age\r\n 
 Jose,33\r\n 
 View the contents of the file with a hexadecimal viewer and a text editor. Get 
 conclusions. The file name is "bDatos.txt" put it in a deﬁne. 
 5. Develop a program that reads the contents of a file called "bData.txt" that contains data 
 with the format described in the previous point and place them in a vector of the following structures. 
 (use fscanf(f, "%[^,],%d\r\n", name, &age); where name is a string and age is an int.) 
 #define NAME_SIZE (32) 
 struct data_S {  
 char name[NAME_SIZE];  
 unsigned int age;  
 }; 
 The maximum number of records is ten. Finally print the vector of structures on the screen. 
 121 

 21. Archives II 
 Used functions of stdio.h 
 Function Description 
 ftell Returns the current position within the file. 
 fseek Moves to the indicated position in the file. 
 rewind Returns to the beginning of the file. 
 fstat Returns information about the file. 
 fwrite Write to file 
 fread Read a file 
 Functions used from sys/stat.h 
 Function Description 
 fstat Returns information about the file. You need the following includes: 
 #include <sys/types.h> 
 #include <sys/stat.h> 
 #include <unistd.h> 
 Commands 
 Command Description 
 chmod Change permissions on a file or directory. 
 chown Changes the owner of a file or directory. 
 chgrp Change the owner of a file or directory 
 Example of command use. 
 We create a text file. 
 jerome@linuxVm:~$ ls / -las > list.txt  
 We list the file using ls -l 
 jerome@linuxVm:~$ ls ./list.txt -l  
 -rw-rw-r-- 1 jerome jerome 1382 May 10 15:39 ./list.txt  
 122 

 Each column returned by ls -l is: 
 Hard Permissions 
 links Owner Group 
 owner Size Date Name 
 -rw-rw-r-- 1 jerome jerome 1382 May 10 
 15:39 list.txt  
 ● Permissions: This campo is divided into four 
 Type of 
 Permissions file 
 owner Group permissions 
 owner Permissions from the rest of 
 system users 
 - rw- rw- r-- 
 ○ File type: 
 ■ - (hyphen): File 
 ■ d: Directory 
 ■ l: Link 
 ○ Permissions: 
 ■ r : Read 
 ■ w: Write 
 ■ x: Execute 
 Number Representation Permit 
 0 --- No permissions  
 1 --x Execution  
 2 -w- Writing  
 3 -wx Write and execute  
 4 r-- Reading 
 5 r-x Reading and execution  
 6 rw- Reading and writing  
 7 rwx Reading, writing and  
 execution.  
 ● Hard link: Number of hard links 
 ● Owner: The owner of the file. 
 ● Owner group: This is the group to which the file belongs. 
 ● Size: Size in bytes of the file. 
 ● Date: Date of the last modification of the file. 
 ● Name: File name 
 Example of using chmod, we give the file read, write and execute permissions for the 
 owner, the group and others. 
 jerome@linuxVm:~$ chmod 777 list.txt  
 jerome@linuxVm:~$ ls ./list.txt -l  
 -rwxrwxrwx 1 jerome jerome 1382 May 10 15:39 ./list.txt  
 123 

 Examples 
 1. Program that asks the user for the name of a file and prints on the screen the size in bytes of the file. 
 same. 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <sys/types.h> 
 #include <sys/stat.h> 
 #include <unistd.h> 
 int main(void) 
 { 
 int aux; 
 struct stat st; 
 //-- read the stat structure of the file -- 
 aux = stat("./example01.c", &st); 
 if (aux < 0) { 
 printf ("Error in fstat\r\n"); 
 return (-1); 
 } 
 printf ("File has %ld bytes\r\n", st.st_size); 
 return (0); 
 } 
 Write and save the above code in a file named example20_01.c 
 Compiling and running the program. Check the file size with the command ls -l 
 jerome@linuxVm:~$ gcc example20_01.c -Wall -oexample20_01.out  
 jerome@linuxVm:~$ ./example20_01.out  
 jerome@linuxVm:~$ ls -l 
 2. Program that writes an integer entered by keyboard to a file called test.bin 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 FILE *f; 
 int aux, a; 
 //-- I open the file -- 
 f = fopen("./test.bin", "w"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- Enter an integer -- 
 printf ("Enter a number\r\n"); 
 124 

 scanf("%d", &a); 
 //-- I write -- 
 aux = fwrite (&a, sizeof (a), 1, f); 
 if (aux < 0) { 
 printf ("Error writing to file\r\n"); 
 return (-1); 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Write and save the above code in a file named example21_02.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example21_02.c -Wall -oexample21_02.out  
 jerome@linuxVm:~$ .   /example21_02.out  
 jerome@linuxVm:~$ hexdump ./test.bin -C  
 Finally open the file test.txt with a text editor or with the cat command and confirm your 
 content. Also verify the contents with okteta or the hexdump command 
 3. Program that writes the integers from 0 to 9 to a file called test.bin 
 #include <stdio.h> 
 #include <stdlib.h> 
 #define QTY ((int)10) 
 int main(void) 
 { 
 FILE *f; 
 int aux, i; 
 int v[QTY]; 
 //-- I open the file -- 
 f = fopen("./test.bin", "w"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- I create a vector with the numbers from 0 to 9 -- 
 for (i = 0 ;i < QTY; i++) { 
 v[i] = i; 
 } 
 //-- I write -- 
 aux = fwrite (&v[0], sizeof (v[0]), QTY, f); 
 125 

 if (aux < 0) { 
 printf ("Error writing to file\r\n"); 
 return (-1); 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Write and save the above code in a file called example21_03.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example21_03.c -Wall -oexample21_03.out  
 jerome@linuxVm:~$ ./example21_03.out  
 jerome@linuxVm:~$ hexdump ./test.bin -C  
 Finally open the file test.bin with a hexa editor or the hexdump command and confirm your 
 content. 
 4. Program that reads a file called test.bin and prints its contents on the screen. 
 #include <stdio.h> 
 #include <stdlib.h> 
 #define QTY ((int)20) 
 int main(void) 
 { 
 FILE *f; 
 int aux, i; 
 int v[QTY], cantRead; 
 //-- I open the file-- 
 f = fopen("./test.bin", "r"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- Leo -- 
 cantRead = fread (&v[0], sizeof (v[0]), QTY, f); 
 if (cantRead < 0) { 
 printf ("Error writing to file\r\n"); 
 return (-1); 
 } else { 
 printf ("Number of integers read: %d\r\n", cantRead); 
 for (i = 0; i < cantRead; i++) { 
 printf ("%d\r\n", v[i]); 
 } 
 126 

 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 5. Program that writes a vector of structures of type struct to a file called test.bin 
 person 
 #include <stdio.h> 
 #include <stdlib.h> 
 #define QTY ((int)3) 
 struct person { 
 char name[16]; 
 int age; 
 }; 
 int main(void) 
 { 
 FILE *f; 
 int aux, i, cantWrite; 
 struct person v[QTY]; 
 //-- I open the file -- 
 f = fopen("./test.bin", "w"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- Data entry -- 
 for (i = 0; i < QTY; i++) { 
 printf ("Enter name\r\n"); 
 scanf ("%s", v[i].name); 
 printf ("Enter age\r\n"); 
 scanf ("%d", &v[i].age); 
 } 
 //-- I write -- 
 cantWrite = fwrite (&v[0], sizeof (v[0]), QTY, f); 
 if (cantWrite < 0) { 
 printf ("Error writing to file\r\n"); 
 return (-1); 
 } else { 
 127 

 printf ("Number of structures written: %d\r\n", cantWrite); 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Write and save the above code in a file called example21_05.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example21_05.c -Wall -oexample21_05.out  
 jerome@linuxVm:~$ ./example21_05.out  
 jerome@linuxVm:~$ cat ./test.bin  
 jerome@linuxVm:~$ hexdump ./test.bin -C  
 Finally open the test.bin file with a hexa editor or the hexdump command and confirm its contents. 
 6. Program that reads from a file called test.bin the vector of structures struct persona 
 stored. 
 #include <stdio.h> 
 #include <stdlib.h> 
 #define QTY ((int)3) 
 struct person { 
 char name[16]; 
 int age; 
 }; 
 int main(void) 
 { 
 FILE *f; 
 int aux, i, cantRead; 
 struct person v[QTY]; 
 //-- I open the file -- 
 f = fopen("./test.bin", "r"); 
 if (f == NULL) { 
 printf ("Error opening file\r\n"); 
 return (-1); 
 } 
 //-- I read the file -- 
 cantRead = fread (&v[0], sizeof (v[0]), QTY, f); 
 if (cantRead < 0) { 
 printf ("Error writing to file\r\n"); 
 return (-1); 
 } else { 
 printf ("Number of structures read: %d\r\n", cantRead); 
 128 

 for (i = 0; i < QTY; i++) { 
 printf ("%d.%s,%d\r\n", i, v[i].name, v[i].age); 
 } 
 } 
 //-- Close -- 
 aux = fclose(f); 
 if (aux != 0) { 
 printf ("Error closing file\r\n"); 
 } 
 return (0); 
 } 
 Exercises 
 1. Implement a function that prints the data pointed to by a pointer in hexadecimal on the screen 
 The function prototype is as follows 
 void printHex (void *dataPtr, int dataSize) 
 Where: 
 ○ dataPtr: Pointer to the data to print in hexadecimal. 
 ○ dataSize: Amount of data to write. 
 2. Using a text editor, create a file named test.txt. Write the legend on it: Hello 
 world!!! save and close the file. Implement a program that reads the contents of the file 
 test.txt using the fread function and print the content to the screen using printf (Note 
 Note that the file is not stored on '\0') also print it using the printHex function (No 
 copy the function in your code, use the .c file generated above). Try reading the file byte a 
 byte or 32 bytes. Check the value returned by the fread and feof functions in each case. 
 3. Develop a program that creates a file called test.txt and using the fwrite function writes the 
 legend Hello info1!!! If the file exists, it must be overwritten. Note that the character '\0' 
 It should not be written to the file. Verify the contents of the file using a hexa editor and a 
 text editor. Draw conclusions. 
 4. Implement a program that adds the legend Goodbye!! to the test.txt file created in point 
 above, without destroying the previous content of the file. 
 5. Develop a program that asks the user to enter 10 integers and stores them 
 in a file with the name entero.bin using the fwrite function.  Check the contents of the file 
 using a hexa editor and a text editor. Draw conclusions. 
 6. Develop a program that reads the file created in the previous point using the fread function and 
 put the data into a dynamically generated integer vector. Finally print in decimal and 
 hexadecimal by display the vector of integers read. Compare what is printed on the screen with what is observed 
 into the file using a hex editor. 
 129 

 7. Develop a program that copies a file indicated by the user through the line 
 command example copy source destination 
 Where: 
 ○ copy: is the name of our program. 
 ○ origin: path and name of the source file. 
 ○ destination: path and name of the destination file. 
 Observe and compare the content using the okteta. 
 8. Develop a program that prints the second half of a file in hexadecimal on the screen 
 indicated by the user. To do this you must use the fseek function to position yourself in the middle of the 
 file and then with the fread function read it. 
 9. Implement a program that asks the user to enter names along with ages and stores them 
 into a file (Use the structure below to store the data). The end of income 
 data occurs when the user enters as age -1. 
 #define NAME_SIZE (32) 
 struct data_S {  
 char name[NAME_SIZE];  
 int age;  
 }; 
 The file name is "bData.bin" place it in a deﬁne. 
 10. Develop a program that prints the content of the file created in the previous point on the screen. 
 Please note that you do not know the number of structures stored. 
 130 

 22. Pointers, the return! 
 In this chapter you will see examples of the following uses of pointers 
 ● Array of pointers. 
 ● Array of pointers to string. 
 ● Main arguments. 
 ● Pointer to function. 
 ● Array of function pointers 
 Examples of using pointers 
 int variable int vector 
 int variable declaration a;  int v[3]; 
 pointer declaration int *p;  int *p; 
 Pointer initialization p = &a;  p = &v[0]; 
 I assign a value 
 variable a a = 10;  v[0] = 1; 
 v[1] = 2; 
 v[2] = 3; 
 I assign a value to the 
 variable using a 
 pointer *p = 10; // a = 10;  *(p + 0) = 1; // v[0] =1; 
 *(p + 1) = 2; // v[1] =2; 
 *(p + 2) = 3; // v[2] =3; 
 I print the value of the 
 variable printf ("%d\r\n", a);  printf ("%d\r\n", v[0]); 
 printf ("%d\r\n", v[1]); 
 printf ("%d\r\n", v[2]); 
 I print the value of the 
 variable using the 
 pointer printf ("%d\r\n", *p);  printf ("%d\r\n", *(p + 0)); 
 printf ("%d\r\n", *(p + 1)); 
 printf ("%d\r\n", *(p + 2)); 
 131 

 Examples 
 1. Program that creates a vector of 3 pointers to integers, points them to three integers and then operates 
 on variables using pointers. 
 #include <stdio.h> 
 int main(void) 
 { 
 int *p[3]; 
 int a = 11, b = 22, c = 33; 
 p[0] = &a; 
 p[1] = &b; 
 p[2] = &c; 
 //-- I access the variables a,b and c using the vector of pointers -- 
 printf ("a = %d\tb = %d\tc = %d\r\n", a, b, c); 
 printf ("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1], *p[2]); 
 //-- Show the address of the variables a, b and c and the pointers -- 
 printf ("&a = %p\t&b = %p\t&c = %p\r\n", &a, &b, &c); 
 printf ("p[0] = %p\tp[1] = %p\tp[2] = %p\r\n", p[0], p[1], p[2]); 
 //-- I modify the value of the variables a. b, c using pointers -- 
 *p[0] = 100; *p[1] = 200; *p[2] = 300; 
 printf ("a = %d\tb = %d\tc = %d\r\n", a, b, c); 
 printf ("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1], *p[2]); 
 return (0); 
 } 
 jerome@linuxVm:~$ gcc example22_01.c -Wall -oexample22_01.out  
 jerome@linuxVm:~$ ./example22_01.out  
 a = 11 b = 22 c = 33 
 *p[0] = 11 *p[1] = 22 *p[2] = 33  
 &a = 0x7ffeb47cd5a4 &b = 0x7ffeb47cd5a8 &c = 0x7ffeb47cd5ac  
 p[0] = 0x7ffeb47cd5a4 p[1] = 0x7ffeb47cd5a8 p[2] = 0x7ffeb47cd5ac  
 a = 100 b = 200 c = 300 
 *p[0] = 100 *p[1] = 200 *p[2] = 300  
 132 

 2. Program that creates a vector of pointers and passes it to a function as a parameter. 
 #include <stdio.h> 
 void func (int **p) 
 { 
 *p[0] = 100; *p[1] = 200; *p[2] = 300; 
 } 
 int main(void) 
 { 
 int *p[3]; 
 int a = 11, b = 22, c = 33; 
 p[0] = &a; 
 p[1] = &b; 
 p[2] = &c; 
 printf ("Variable values\r\n"); 
 printf ("a = %d\tb = %d\tc = %d\r\n", a, b, c); 
 printf ("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1],*p[2]); 
 printf ("Addresses\r\n"); 
 printf ("&a = %p\t&b = %p\t&c = %p\r\n", &a, &b, &c); 
 printf ("p[0] = %p\tp[1] = %p\tp[2] = %p\r\n", p[0], p[1], p[2]); 
 printf ("I modify the values ​​in the function\r\n"); 
 func(&p[0]); 
 printf ("a = %d\tb = %d\tc = %d\r\n", a, b, c); 
 printf ("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1], *p[2]); 
 return (0); 
 } 
 jerome@linuxVm:~$ gcc example22_02.c -Wall -oexample22_02.out  
 jerome@linuxVm:~$ ./example22_02.out  
 Variable values  
 a = 11 b = 22 c = 33 
 *p[0] = 11 *p[1] = 22 *p[2] = 33  
 Directions  
 &a = 0x7fffac887434 &b = 0x7fffac887438 &c = 0x7fffac88743c  
 p[0] = 0x7fffac887434 p[1] = 0x7fffac887438 p[2] = 0x7fffac88743c  
 I modify the values in the function  
 a = 100 b = 200 c = 300 
 *p[0] = 100 *p[1] = 200 *p[2] = 300  
 133 

 3. Program that dynamically generates an array of integer pointers 
 #include <stdio.h> 
 #include <stdlib.h> 
 int main(void) 
 { 
 int **p; 
 int a = 11, b = 22, c = 33; 
 p = (int **)malloc (sizeof (*p) * 3); 
 if (p == NULL) { 
 printf ("Error malloc \r\n"); 
 return (-1); 
 } 
 *(p + 0) = &a; 
 *(p + 1) = &b; 
 *(p + 2) = &c; 
 printf ("Variable values\r\n"); 
 printf ("a = %d\tb = %d\tc = %d\r\n", a, b, c); 
 printf ("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1], *p[2]); 
 printf ("Addresses\r\n"); 
 printf ("&a = %p\t&b = %p\t&c = %p\r\n", &a, &b, &c); 
 printf ("*p[0] = %p\t*p[1] = %p\t*p[2] = %p\r\n", p[0], p[1], p[2]); 
 return (0); 
 } 
 jerome@linuxVm:~$ gcc example22_03.c -Wall -oexample22_03.out  
 jerome@linuxVm:~$ ./example22_03.out  
 Variable values  
 a = 11 b = 22 c = 33 
 *p[0] = 11 *p[1] = 22 *p[2] = 33  
 Directions  
 &a = 0x7fffac887434 &b = 0x7fffac887438 &c = 0x7fffac88743c  
 p[0] = 0x7fffac887434 p[1] = 0x7fffac887438 p[2] = 0x7fffac88743c  
 134 

 4. Program that generates two vectors of pointers to char 
 ○ The first one initializes it with the address of 3 string at compile time. 
 ○ The second initializes it with the address of 3 string at run time. 
 #include <stdio.h> 
 int main(void) 
 { 
 char *p[3]; 
 char *q[] = { 
 "Hello", 
 "Goodbye", 
 "Info1" 
 }; 
 char a[] = "Hello"; 
 char b[] = "Bye"; 
 char c[] = "Info1"; 
 p[0] = &a[0]; 
 p[1] = &b[0]; 
 p[2] = &c[0]; 
 printf ("I print the strings\r\n"); 
 printf ("a = %s\tb = %s\tc = %s\r\n", a, b, c); 
 printf ("p[0] = %s\tp[1] = %s\tp[2] = %s\r\n", p[0], p[1], p[2]); 
 printf ("q[0] = %s\tq[1] = %s\tq[2] = %s\r\n", q[0], q[1], q[2]); 
 printf ("I print the addresses of the strings\r\n"); 
 printf ("a = %p\tb = %p\tc = %p\r\n", &a[0], &b[0], &c[0]); 
 printf ("p[0] = %p\tp[1] = %p\tp[2] = %p\r\n", p[0], p[1], p[2]); 
 printf ("q[0] = %p\tq[1] = %p\tq[2] = %p\r\n", q[0], q[1], q[2]); 
 return (0); 
 } 
 jerome@linuxVm:~$ gcc example22_04.c -Wall -oexample22_04.out  
 jerome@linuxVm:~$ ./example22_04.out  
 I print the strings  
 a = Hello b = Goodbye c = Info1  
 p[0] = Hello p[1] = Goodbye p[2] = Info1  
 q[0] = Hello q[1] = Goodbye q[2] = Info1  
 I print the addresses of the strings  
 a = 0x7ffe54ac0290 b = 0x7ffe54ac02a0 c = 0x7ffe54ac02b0  
 p[0] = 0x7ffe54ac0290 p[1] = 0x7ffe54ac02a0 p[2] = 0x7ffe54ac02b0  
 q[0] = 0x4007b8 q[1] = 0x4007bd q[2] = 0x4007c3  
 135 

 5. Program that prints all arguments passed through the command line 
 #include <stdio.h> 
 int main (int argc, char *argv[]) 
 { 
 int i; 
 for (i = 0; i < argc ; i++) { 
 printf ("%d.%s\r\n", i, argv[i]); 
 } 
 return (0); 
 } 
 jerome@linuxVm:~$ gcc example22_05.c -Wall -oexample22_05.out  
 jerome@linuxVm:~$ ./ejemplo22_05.out Hello, how are you doing? 
 0. ./example22_05.out  
 1.hello 
 2.how 
 3.te 
 4.va 
 6. Program demonstrates the use of a function pointer 
 #include <stdio.h> 
 int sum (int a, int b) 
 { 
 return(a + b); 
 } 
 int main(void) 
 { 
 int a, b, r;  
 int (*func) (int, int); 
 //-- Assignment of the pointer to a function --  
 func = sum; 
 //-- Data entry --  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 printf ("Enter a number:\r\n");  
 scanf("%d", &b);  
 //-- Use of the function pointer --  
 r = func (a, b);  
 printf ("The result is: %d\r\n", r);  
 return (0); 
 } 
 136 

 7. Program that shows the use of an array of function pointers 
 #include <stdio.h> 
 #define SUM ((int)0) 
 #define SUBTRACTION ((int)1) 
 #define DIVISION ((int)2) 
 #define MULTIPLICATIONON ((int)3) 
 int sum (int a, int b) 
 { 
 return(a + b); 
 } 
 int subtraction (int a, int b) 
 { 
 return(a - b); 
 } 
 int division (int a, int b) 
 { 
 return(a / b); 
 } 
 int multiplication (int a, int b) 
 { 
 return(a * b); 
 } 
 int main(void) 
 { 
 int a, b, r;  
 int (*func[4]) (int, int); 
 int opIndex; 
 //-- Assignment of the pointer to a function --  
 func[SUM] = sum; 
 func[SUBTRACTION] = subtraction; 
 func[DIVISION] = division; 
 func[MULTIPLICATION] = multiplication; 
 //-- Data entry --  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 printf ("Enter a number:\r\n");  
 scanf("%d", &b);  
 printf ("Enter operation:\r\n");  
 printf ("0. Sum\r\n");  
 printf ("1. Subtraction\r\n");  
 printf ("2. Division\r\n");  
 printf ("3. Multiplication\r\n");  
 scanf("%d", &opIndex);  
 137 

 if (opIndex < SUM || opIndex > MULTIPLICATION ) {  
 printf ("Invalid operation\r\n");  
 return (-1);  
 } 
 //-- Use of the function pointer --  
 r = func[opIndex] (a, b);  
 printf ("The result is: %d\r\n", r);  
 return (0); 
 } 
 8. Program that shows the use of an array of function pointers. 
 #include <stdio.h> 
 #include <string.h> 
 #define SUM ((int)0) 
 #define SUBTRACTION ((int)1) 
 #define DIVISION ((int)2) 
 #define MULTIPLICATION ((int)3) 
 int sum (int a, int b) 
 { 
 return(a + b); 
 } 
 int subtraction (int a, int b) 
 { 
 return(a - b); 
 } 
 int division (int a, int b) 
 { 
 return(a / b); 
 } 
 int multiplication (int a, int b) 
 { 
 return(a * b); 
 } 
 int main(void) 
 { 
 int a, b, r;  
 char op, *p;  
 int (*func[4]) (int, int); 
 char listOp[] = "+-/*"; 
 int opIndex; 
 //-- Assignment of the pointer to a function --  
 func[SUM] = sum; 
 func[SUBTRACTION] = subtraction; 
 138 

 func[DIVISION] = division; 
 func[MULTIPLICATION] = multiplication; 
 //-- Data entry --  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 printf ("Enter operation\r\n");  
 scanf("%*c%c", &op);  
 printf ("Enter a number:\r\n");  
 scanf("%d", &b);  
 p = strchr(listOp, op);  
 if (p == NULL) {  
 printf ("Invalid operation\r\n");  
 return (0);  
 } 
 opIndex = (int)(p - listOp);  
 //-- Use of the function pointer --  
 r = func[opIndex] (a, b);  
 printf ("The result is: %d\r\n", r);  
 return (0); 
 } 
 Exercises 
 1. Implement a program that receives the name of a file via the command line and prints it. 
 display its size in bytes. 
 jerome@linuxVm:~$ ./ejercicio22_01.out filename  
 2. Implement a program that copies a file. The name of the source and destination file 
 receive via command line. (Similar to cp command) 
 jerome@linuxVm:~$ ./ejercicio22_02.out origin destination  
 3. Create a program that uses the command line to pass two real values and the symbol of the 
 operation ('+', '-', '*', '/'). The data entered, the operation and the procedure must be presented on the screen. 
 result. If the symbol used does not correspond to any of the four operations, it must 
 display an "Invalid operation" message. 
 jerome@linuxVm:~$ ./ejercicio22_03.out 2 + 3  
 2 + 3 = 5  
 jerome@linuxVm:~$ ./ejercicio22_03.out 2 * 3  
 2 * 3 = 6  
 jerome@linuxVm:~$ ./ejercicio22_03.out 2 ! 3  
 Invalid operation  
 4. Modify the above program to use an array of function pointers. 
 139 

 5. Implement a function that reads four texts separated by "\r\n" from a file and places them in 
 four dynamically generated strings. Then assign these four pointers to the vector of pointers 
 passed as a parameter in the function. 
 int readText (char *name, char **textPtr);  
 Where: 
 name: It is the pointer to the file name 
 textoPtr: It is the number of elements of the pointed vector 
 Returns: The number of lines of text read or a negative number indicating the error. 
 140 

 23. Matrices. 
 Examples 
 1. Program that statically creates a two-dimensional 3 x 3 array of integers and fills it with the 
 numbers from 0 to 9 
 #include <stdio.h> 
 #define ROWS ((int)3) 
 #define COLUMNS ((int)3) 
 int main(void) 
 { 
 int m[ROWS][COLUMNS]; 
 int i, j; 
 int c = 0; 
 //-- Initialize the array -- 
 for (i = 0; i < ROWS; i++) { 
 for (j = 0; j < COLUMNS ; j++) { 
 m[i][j] = c; 
 c++; 
 } 
 } 
 //-- I print the matrix -- 
 for (i = 0; i < ROWS; i++) { 
 for (j = 0; j < COLUMNS ; j++) { 
 printf ("%d\t",m[i][j]); 
 } 
 printf ("\r\n"); 
 } 
 return (0); 
 } 
 2. Program that creates this waycreates a 3 x 3 two-dimensional array of integers and fills it with the 
 numbers from 0 to 9 using pointers to address as an array. 
 #include <stdio.h> 
 #define ROWS ((int)3) 
 #define COLUMNS ((int)3) 
 int main(void) 
 { 
 int m[ROWS][COLUMNS]; 
 int i, j; 
 int c = 0; 
 int *p; 
 p = &m[0][0]; 
 //-- Initialize the array -- 
 141 

 for (i = 0; i < ROWS; i++) { 
 for (j = 0; j < COLUMNS ; j++) { 
 *(p + (i * COLUMNS) + j) = c; 
 c++; 
 } 
 } 
 //-- I print the matrix -- 
 for (i = 0; i < ROWS; i++) { 
 for (j = 0; j < COLUMNS ; j++) { 
 printf ("%d\t", *(p + (i * COLUMNS) + j)); 
 } 
 printf ("\r\n"); 
 } 
 return (0); 
 } 
 3. Program that statically creates a two-dimensional 3 x 3 array of integers and fills it with the 
 numbers from 0 to 9 using pointers. 
 #include <stdio.h> 
 #define ROWS ((int)3) 
 #define COLUMNS ((int)3) 
 int main(void) 
 { 
 int m[ROWS][COLUMNS]; 
 int i, j; 
 int *p; 
 p = &m[0][0]; 
 //-- Initialize the array -- 
 for (i = 0; i < ROWS * COLUMNS; i++) { 
 *(p + i) = i; 
 } 
 //-- I print the matrix -- 
 for (i = 0; i < ROWS; i++) { 
 for (j = 0; j < COLUMNS ; j++) { 
 printf ("%d\t", *(p + (i * COLUMNS) + j)); 
 } 
 printf ("\r\n"); 
 } 
 return (0); 
 } 
 142 

 4. Program that dynamically creates a two-dimensional 3 x 3 array of integers and fills it with the 
 numbers from 0 to 9 using pointers. 
 #include <stdio.h> 
 #include <stdlib.h> 
 #define ROWS ((int)3) 
 #define COLUMNS ((int)3) 
 int main(void) 
 { 
 int *m; 
 int i, j; 
 int c = 0; 
 m = (int *)malloc (ROWS * COLUMNS * sizeof (*m)); 
 if (m == NULL) { 
 printf ("Error malloc \r\n"); 
 return (-1); 
 } 
 //-- Initialize the array -- 
 for (i = 0; i < ROWS; i++) { 
 for (j = 0; j < COLUMNS ; j++) { 
 *(m + (i * COLUMNS) + j) = c; 
 c++; 
 } 
 } 
 //-- I print the matrix -- 
 for (i = 0; i < ROWS; i++) { 
 for (j = 0; j < COLUMNS ; j++) { 
 printf ("%d\t", *(m + (i * COLUMNS) + j)); 
 } 
 printf ("\r\n"); 
 } 
 free (m) 
 return (0); 
 } 
 Exercises 
 1. Implement a function that prints on the screen a matrix of rows by columns, the prototype of the 
 function is 
 void printMatrix(int *p, int rows, int columns);  
 2. Implement a function that creates a row-by-column array and initializes it to zero, the prototype 
 of the function is: 
 int * arrayCreate(int rows, int columns);  
 3. Implement a function that stores an array passed as a parameter to a file, the prototype 
 of the function is the following 
 143 

 int arrayWrite(char *name, int *p, int rows, int columns);  
 4. Implement a function that reads the file generated by the write array function and returns 
 store the array in memory. 
 int arrayRead (char *name, int *p, int rows, int columns);  
 5. Implement a program that allows two users to play ta-te-ti. Selecting the box 
 Playing is done using the locker number. 
 0 1 2 
 3 4 5 
 6 7 8 
 For example, if the user wants to place an X in the center, they must enter 4. 
 The program must do the following: 
 ● The program must indicate if the user can play in the position indicated or if that position is already 
 was played. You will need to keep asking the user to play until a valid play is entered 
 ● The program must indicate if any player wins the game or if it is a tie. 
 6. Modify the previous program to store the last game in a file. It is stored every 
 change in the game matrix. 
 144 

 24. Bit-level operations, bit fields. Unions. Enum 
 Bit-level operators 
 Operator Description 
 & Bitwise operation 
 |  bitwise or operation 
 ~ Bitwise not operation 
 ^ Bitwise xor operation 
 <<Shift right 
 >> Shift left 
 Examples 
 All the examples of bit-level operators are applied to a char type variable so that it is 
 easier to understand, but they can be applied to any type of data. On the other hand, it is defined 
 a function called chartoBin that prints in binary the char value passed as a parameter. 
 1. Program demonstrating the use of the toBin function 
 #include <stdio.h> 
 #include <string.h> 
 void chartoBin (unsigned char data, char *binPtr) 
 { 
 int i; 
 int sizeBit = sizeof (data) * 8; 
 memset (binPtr, '\0', sizeof(*binPtr)); 
 for (i = 0; i < sizeBit; i++) { 
 if ((data % 2) == 0) { 
 *(binPtr + sizeBit - 1 - i) = '0'; 
 } else { 
 *(binPtr + sizeBit - 1 - i) = '1'; 
 } 
 data = data >> 1; 
 } 
 *(binPtr + i) = '\0'; 
 } 
 int main(void) 
 { 
 char vect[33]; 
 chartoBin ((unsigned char)0x01, &vect[0]); 
 printf ("%s\r\n", &vect[0]); 
 chartoBin ((unsigned char)0x80, &vect[0]); 
 printf ("%s\r\n", &vect[0]); 
 145 

 chartoBin ((unsigned char)0xA5, &vect[0]); 
 printf ("%s\r\n", &vect[0]); 
 return (0); 
 } 
 2. Program that demonstrates shifting left and right. Print the operation 
 made with the values in binary. 
 #include <stdio.h> 
 #include <string.h> 
 //-- Add the chartoBin function -- 
 int main(void) 
 { 
 unsigned char entry; 
 unsigned char output; 
 char inputV[9]; 
 char outputV[9]; 
 input = 0x01;    output = input << 1; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s << 1 : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0x01;    output = input << 2; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s << 2 : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0x01;    output = input << 4; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s << 4 : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0x01;    output = input << 7; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s << 7 : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0x80;    output = input >> 1; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s >> 1 : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0x80;    output = input >> 2; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s >> 2 : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0x80;    output = input >> 4; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s >> 4 : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0xA0;    output = input >> 7; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s >> 7 : %s\r\n", &inputV[0], &outputV[0]); 
 146 

 return (0); 
 } 
 3. Program that demonstrates use of the not operator 
 #include <stdio.h> 
 #include <string.h> 
 //-- Add the chartoBin function -- 
 int main(void) 
 { 
 unsigned char entry; 
 unsigned char output; 
 char inputV[9]; 
 char outputV[9]; 
 input = 0x00;    output = ~input; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("~%s : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0xFF;    output = input << 2; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("~%s : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0x01;    output = input << 4; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("~%s : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0xAA;    output = input << 7; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("~%s : %s\r\n", &inputV[0], &outputV[0]); 
 return (0); 
 } 
 147 

 4. Program demonstrating use of the operator and 
 #include <stdio.h> 
 #include <string.h> 
 //-- Add the chartoBin function -- 
 int main(void) 
 { 
 unsigned char entry; 
 unsigned char output; 
 char inputV[9]; 
 char outputV[9]; 
 input = 0xFF;    output = input & 0x01; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s & 0x01 : %s\r\n", &Vinput[0], &Voutput[0]); 
 input = 0xFF;    output = input & 0x02; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s & 0x02 : %s\r\n", &inputV[0], &outputV[0]); 
 input = 0x02;    output = input & 0x01; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s & 0x01 : %s\r\n", &Vinput[0], &Voutput[0]); 
 input = 0x02;    output = input & 0x01; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s & 0x01 : %s\r\n", &Vinput[0], &Voutput[0]); 
 input = 0x56;    output = input & 0x0F; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s & 0x0F : %s\r\n", &inputV[0], &outputV[0]); 
 return (0); 
 } 
 148 

 5. Program demonstrating use of the or operator 
 #include <stdio.h> 
 #include <string.h> 
 //-- Add the chartoBin function -- 
 int main(void) 
 { 
 unsigned char entry; 
 unsigned char output; 
 char inputV[9]; 
 char outputV[9]; 
 input = 0x00;    output = input | 0x01; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s | 0x01 : %s\r\n", &Vinput[0], &Voutput[0]); 
 input = 0xF0;    yesoutput = input | 0x02; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s | 0x02 : %s\r\n", &Vinput[0], &Voutput[0]); 
 input = 0x02;    output = input | 0x01; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s | 0x01 : %s\r\n", &Vinput[0], &Voutput[0]); 
 input = 0x50;    output = input | 0x0F; 
 chartoBin (input, inputV); chartoBin(output, outputV); 
 printf ("%s | 0x0F : %s\r\n", &Vinput[0], &Voutput[0]); 
 return (0); 
 } 
 149 

 6. Program that demonstrates use of a union 
 #include <stdio.h> 
 union intCharVect { 
 int varInt; 
 char vectChar[4]; 
 }; 
 int main(void) 
 { 
 union intCharVect data; 
 data.varInt = 0x12345678; 
 printf("data.varInt = 0x%x\r\n", data.varInt); 
 printf("data.vectChar[0] = 0x%x\r\n", data.vectChar[0]); 
 printf("data.vectChar[1] = 0x%x\r\n", data.vectChar[1]); 
 printf("data.vectChar[2] = 0x%x\r\n", data.vectChar[2]); 
 printf("data.vectChar[3] = 0x%x\r\n", data.vectChar[3]); 
 printf("sizeof (data) = %ld\r\n", sizeof (data)); 
 printf("sizeof (data.varInt) = %ld\r\n", sizeof (data.varInt)); 
 printf("sizeof (data.vectChar) = %ld\r\n", sizeof (data.vectChar)); 
 return (0); 
 } 
 150 

 7. Program that demonstrates use of an enum 
 #include <stdio.h> 
 enum days_E { 
 SUNDAY = 0, 
 MONDAY, 
 TUESDAY, 
 WEDNESDAY, 
 THURSDAY, 
 FRIDAY, 
 SATURDAY, 
 }; 
 int main(void) 
 { 
 int day; 
 printf("Enter number indicating the day of the week (0 - 6)\r\n") 
 scanf("%d", &day); 
 switch (day) {  
 case 0: printf ("Sunday\r\n");   break;  
 case 1: printf ("Monday\r\n");    break;  
 case 2: printf ("Tuesday\r\n");    break;  
 case 3: printf ("Wednesday\r\n");   break;  
 case 4: printf ("Thursday\r\n"); break;  
 case 5: printf ("Friday\r\n");  break;  
 case 6: printf ("Saturday\r\n");   break;  
 default:  
 printf ("Invalid entry\r\n");  
 break; 
 } 
 return (0); 
 } 
 151 

 Exercises 
 1. Implement a function that returns the value of a bit indicated as a parameter 
 int readBit(int word, int bit); 
 Where: 
 ● word: It is the value at which it should be processed. 
 ● bit: is the bit number to read from the word 
 The function returns a zero if the bit read is zero or a one otherwise. 
 2. Implement a function that negates the value of a bit indicated as a parameter 
 int negateBit(int word, int bit); 
 Where: 
 ● word: It is the value at which it should be processed. 
 ● bit: is the bit number to negate the word. 
 The function returns the value of the negated bit. 
 3. Implement the following functions that write a bit, nibble or byte of a word. 
 int writeBit (int word, int bit, int dataBit); 
 int writeNibble (int word, int nibble, int dataNibble); 
 int writeByte(int word, int byte, int dataByte); 
 Where: 
 ● word: It is the value at which it should be processed. 
 ● bit: is the bit number to be set in the word 
 ● dataBit: It is the value to be placed in the indicated bit. It can take the value zero or one. 
 ● dataNibble: It is the value to place in the indicated nibble. It can take values from 0x0 to 
 0xF 
 ● datoByte: It is the value to be placed in the indicated byte. It can take values from 0x00 to 
 0xFF 
 The function returns the modified word. 
 4. Implement a function that returns the value of the nibble indicated as a parameter 
 int readNibble(int word, int nibble); 
 Where: 
 ● word: It is the value at which it should be processed. 
 ● nibble: is the nibble number to read from the word. 
 5. Implement a function that returns the value of the byte indicated as a parameter 
 int readByte(int word, int byte); 
 Where: 
 ● word: It is the value at which it should be processed. 
 ● byte: is the byte number to be set for the word. 
 152 

 25. Recursion. 
 Recursion consists of constructing functions that call themselves. 
 1. Program that counts recursively. 
 #include <stdio.h> 
 void count(int n) { 
 printf ("Number %d\r\n", n); 
 if (n > 0) { 
 count (n - 1); 
 } 
 } 
 int main(void) 
 { 
 int n; 
 printf ("Enter a number:\r\n");  
 scanf("%d", &n);  
 count (n); 
 return (0); 
 } 
 2. Program that recursively calculates the factorial. 
 #include <stdio.h> 
 int factorial(int n) 
 { 
 if (n == 0) { 
 return (1); 
 } else { 
 return (n * factorial(n - 1)); 
 } 
 } 
 int main(void) 
 { 
 int n, r; 
 printf ("Enter number\r\n"); 
 scanf("%d", &n); 
 r = factorial (n); 
 printf ("The factorial of %d is %d\r\n", n, r); 
 return (0); 
 } 
 153 

 Exercises 
 1.Implemind a function that recursively calculates the power x y The prototype of the function is the 
 next: 
 int power(int x, int y) 
 2. Implement a function that calculates the Fibonacci series recursively. 
 3. Implement a function that converts an int data passed as a parameter to binary in a vector. 
 154 

 26. Use of makefile: compilation and linking. 
 Required programs 
 Use apt to install them 
 Package Description 
 make Tool to assist in the automatic compilation of source code. 
 gdb Debugger 
 Compilation steps 
 1. Precompiler: In this step the following operations are performed. 
 ● Resolves directives that start with # such as includes, ifdef and macros. 
 ● Comments are deleted. 
 When compiled with the -save-temps or -E option the output is generated after this step. 
 It is usually a file with an .i extension 
 2. Compilation: Takes the output from the previous step and produces an output with the code level 
 assembly. When compiled with the -save-temps or -S option the output is generated after this 
 step. It is usually a file with an .s extension 
 3. Assembly: Takes the output of the compilation step and translates it into machine language. When 
 It is compiled with the -save-temps or -c option and the output is generated after this step. It is usually 
 a file with .o extension 
 4. Linking: This is the last step to form the executable file, in this phase code is added 
 for the start and end of the program. In addition, function calls are joined with their code 
 and the. 
 The gcc is a wrapper that performs these steps to compile everything. 
 We save the following code in a file called example.c 
 #include <stdio.h> 
 #define QTY ((int)10) 
 int main(void) 
 { 
 int i; 
 for (i = 0; i < QTY; i++) { 
 printf ("%d.Hello\r\n", i); 
 } 
 return (0); 
 } 
 155 

 We execute the following command that generates all the intermediate files of the compilation process 
 jerome@linuxVm:~$ gcc example.c -Wall -save-temps -oexample.out 
 jerome@linuxVm:~$ ls 
 example.c example.i example.o example.out example.s 
 Compilation of various .c and .h 
 Transcribe the following code into a file called functions.c 
 #include <stdio.h> 
 #include <string.h> 
 int sum (int a, int b) 
 { 
 return(a + b); 
 } 
 int subtraction (int a, int b) 
 { 
 return(a - b); 
 } 
 int division (int a, int b) 
 { 
 return(a / b); 
 } 
 int multiplication (int a, int b) 
 { 
 return(a * b); 
 } 
 Transcribe the following code into a file called functions.h 
 #ifndef FUNCTIONS_H 
 #define FUNCTIONS_H 
 enum op_E { 
 SUM = 0, 
 SUBTRACTION, 
 DIVISION, 
 MULTIPLICATION 
 }; 
 int sum(int a, int b); 
 int subtraction (int a, int b); 
 int division (int a, int b); 
 int multiplication (int a, int b); 
 #endif 
 Transcribe the following code into a file called main.c 
 156 

 #include <stdio.h> 
 #include <string.h> 
 #include "functions.h" 
 int main(void) 
 { 
 int a, b, r;  
 char op, *p;  
 int (*func[4]) (int, int); 
 char listOp[] = "+-/*"; 
 int opIndex; 
 //-- Assignment of the pointer to a function --  
 func[SUM] = sum; 
 func[SUBTRACTION] = subtraction; 
 func[DIVISION] = division; 
 func[MULTIPLICATION] = multiplication; 
 //-- Data entry --  
 printf ("Enter a number:\r\n");  
 scanf("%d", &a);  
 printf ("Enter operation\r\n");  
 scanf("%*c%c", &op);  
 printf ("Enter a number:\r\n");  
 scanf("%d", &b);  
 p = strchr(listOp, op);  
 if (p == NULL) {  
 printf ("Invalid operation\r\n");  
 return (0);  
 } 
 opIndex = (int)(p - listOp);  
 //-- Use of the function pointer --  
 r = func[opIndex] (a, b);  
 printf ("The result is: %d\r\n", r);  
 return (0); 
 } 
 Compile the code as follows 
 jerome@linuxVm:~$ gcc main.c functions.c -Wall -oexample.out  
 157 

 Makefile 
 Write the following code into a file called Makefile and place it with the files in the 
 previous example. 
 CC=gcc 
 EXECUTABLE=main.out 
 HEADERS=./include 
 CFLAGS=-c -I$(HEADERS) -Wall 
 LFLAGS= 
 LIBS= -lm 
 all: main.o functions.o 
 $(CC) $(LFLAGS) main.o functions.o $(LIBS) -o$(EXECUTABLE) 
 main.o: main.c 
 $(CC) $(CFLAGS) main.c -omain.o 
 functions.o: functions.c 
 $(CC) $(CFLAGS) functions.c -ofunctions.o 
 doxy: 
 doxygen Doxyfile 
 firefox ./doxy/html/index.html & 
 clean: 
 rm -f ./*.o 
 rm -f ./*.out 
 rm ./doxy -rf 
 run: 
 ./example.out 
 Compile the code as follows 
 jerome@linuxVm:~$Makefile  
 158 

 As urgedlar debugger in Atom 
 Install the dbg-gdb Atom package 
 1. Enter the Atom Edit->Preferences preferences 
 159 

 2. Select the Install menu and find the dbg-gdb package, then install it. 
 3. Install all the dependencies that the installation requires. 
 How to debug a C program 
 1. Copy the following code to a file named example.c 
 #include <stdio.h>  
 #define QTY ((int)10)  
 int main(void)  
 { 
 int i; 
 for (i = 0; i < QTY; i++) {  
 printf ("%d.Hello\r\n", i);  
 } 
 return (0);  
 } 
 160 

 2. Compile the code using the -g option 
 jerome@linuxVm:~$ gcc example.c -Wall -g -oexample.out  
 3. You can place breakpoints by clicking to the left of the line number 
 A red circle will appear indicating that the breakpoint could be placed. 
 4. Press the F5 key to configure the debugger. In the panel that appears, select the file 
 example.out that I generate in point 2 
 5. Press the Debug button to start code execution 
 6. To continue the execution you can press the F5 key 
 161 

 library 
 It is a set of functions compiled together intended to be reused. 
 In Linux we have 3 types 
 ● Static library: The library is copied to the program to which it is linked. 
 ● Dynamic library: Only a reference to the library is included, so the Library can be modified 
 without recompiling the entire program. 
 Static libraries 
 Write the following code into a file called Makefile and place it with the files in the 
 previous example. 
 CC=gcc 
 EXECUTABLE=main.out 
 HEADERS=./include 
 CFLAGS=-c -I$(HEADERS) -Wall 
 LFLAGS= 
 ARFLAGS=rcs 
 LIBS= -lm 
 all: main.o functions.o 
 $(CC) $(LFLAGS) main.o functions.o $(LIBS) -o$(EXECUTABLE) 
 main.o: main.c 
 $(CC) $(CFLAGS) main.c -omain.o 
 functions.o: functions.c 
 $(CC) $(CFLAGS) functions.c -ofunctions.o 
 #-- Create the static lib -- 
 libStatic: functions.o 
 $(AR) $(ARFLAGS) libfunctions.a functions.o 
 #-- Compile with the static lib -- 
 compileLibStatic: main.o 
 $(CC) -o$(EXECUTABLE) main.o -L. -lfunctions 
 doxy: 
 doxygen Doxyfile 
 firefox ./doxy/html/index.html & 
 clean: 
 rm -f ./*.o 
 rm -f ./*.out 
 rm -f ./*.a 
 rm ./doxy -rf 
 run: 
 ./main.out 
 Compile the code as follows 
 162 

 jerome@linuxVm:~$Makefile  
 dynamic libraries 
 CC=gcc 
 EXECUTABLE=main.out 
 HEADERS=./include 
 CFLAGS=-c -I$(HEADERS) -Wall 
 LFLAGS= 
 ARFLAGS= 
 LIBS= -lm 
 all: main.o functions.o 
 $(CC) $(LFLAGS) main.o functions.o $(LIBS) -o$(EXECUTABLE) 
 main.o: main.c 
 $(CC) $(CFLAGS) main.c -omain.o 
 functions.o: functions.c 
 $(CC) $(CFLAGS) functions.c -ofunctions.o 
 #-- I create the shared lib -- 
 libShared: functions.o 
 $(CC) $(CFLAGS) -Werror -fPIC functions.c 
 $(CC) -shared -o libfunctions.so functions.o 
 #-- I compile with the shared lib -- 
 compileLibShared: main.o 
 $(CC) -L./ -Wall main.o -o$(EXECUTABLE) -lfunctions 
 #export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH 
 doxy: 
 doxygen Doxyfile 
 firefox ./doxy/html/index.html & 
 clean: 
 rm -f ./*.o 
 rm -f ./*.out 
 rm -f ./*.so 
 rm ./doxy -rf 
 #unset LD_LIBRARY_PATH 
 run: 
 ./main.out 
 Compile the code as follows 
 jerome@linuxVm:~$Makefile  
 Add the path where the library is in the LD_LIBRARY_PATH environment variable 
 163 

 jerome@linuxVm:~$ export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH  
 Using this command you can delete the previous configuration. 
 jerome@linuxVm:~$ unset LD_LIBRARY_PATH  
 164 

 27. Code Documentation: Doxygen and Indentation 
 Required programs 
 Use apt to install them 
 Package Description 
 doxygen Program to document source code in c, c++m etc. 
 doxygen-gui doxygen graphical interface 
 graphviz Tools to generate graphs. 
 Doxygen 
 It is a documentation generator for C, C++, Python, VHDL, etc. which allows us to contain within 
 from the same source code files the documentation making it easier to maintain the documentation 
 updated. 
 Documenting with doxygen 
 The documentation in doxygen is done directly on the source files as comments 
 using block and/or inline comments specially identiﬁed to be taken as art of 
 documentation and not as a code comment. 
 ● Block comment 
 /** 
 Block comment 
 */ 
 ● Online comment 
 //! online comment 
 ● Online comment to document in detail a deﬁne or a catype of a structure. 
 //!< Inline comment 
 Within these comments tags are placed to carry out documentation, among them we can 
 mention 
 ● \ﬁle To document a file 
 ● \fn To document a function 
 ● \struct To document a structure 
 ● \enum To document an enum 
 ● \brief Brief description of the documented element. 
 ● \detail Detailed description of the documented element. 
 ● \author Author of the documented item. 
 ● \date Date of the documented item. 
 ● \version Version of the documented element. 
 ● \param Parameter of the documented function 
 ● \return Return value of the 
 165 

 ● \all Adds the text to the all list of the documentation 
 Example of file documentation with main function. 
 /** 
 \file main.c 
 \brief Example program that calls a function hosted in another .c file 
 \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com) 
 \date 2021.05.05 
 \version 1 
 */ 
 //-------------- 
 //-- Includes -- 
 //-------------- 
 #include <stdio.h> 
 #include "oper.h" 
 /** 
 \fn int main (void) 
 \brief Requests the entry of two integers and performs their sum using 
 the operSuma function, if the two operands are zero it exits the program. 
 \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com) 
 \date 2021.05.05 
 \return Always returns zero. 
 \bug Does not check the range of the numbers entered. 
 */ 
 int main(void) 
 { 
 int a,b; 
 int resultS; 
 int resultM; 
 do { 
 //-- Data entry -- 
 printf ("Enter number:\r\n"); 
 scanf("%d", &a); 
 printf ("Enter number:\r\n"); 
 scanf("%d", &b); 
 //-- call the function --- 
 resultS = operSum (a, b); 
 resultM = operMult(a,b); 
 //-- Print the result of the operation -- 
 printf ("\r\n%d + %d = %d\r\n", a,b, resultS); 
 printf ("\r\n%d * %d = %d\r\n", a,b, resultM); 
 } while ((a != 0) || (b != 0)); 
 return (0); 
 } 
 Save this code in a file called main.c 
 166 

 Example of file documentation with various functions. 
 /** 
 \file oper.c 
 \brief Contains functions that perform mathematical operations 
 \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com) 
 \date 2021.05.05 
 \version 1 
 \all Add more operations. 
 */ 
 //-------------- 
 //-- Includes -- 
 //-------------- 
 #include "oper.h" 
 /** 
 \fn int operSum (int a, int b) 
 \brief Add two integers and return the result 
 \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com) 
 \date 2021.05.05 
 \param a First operand to add 
 \param b Second operand to add 
 \return Returns the sum of the operands passed as parameters 
 \all Modify so that it checks overflow. 
 */ 
 int operSum (int a, int b) 
 { 
 return (a + b); 
 } 
 /** 
 \fn int operMult (int a, int b) 
 \brief Multiply two integers and return the result 
 \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com) 
 \date 2021.05.05 
 \param a First operand to add 
 \param b Second operand to add 
 \return Returns the sum of the operands passed as parameters 
 */ 
 int operMult (int a, int b) 
 { 
 return (a * b); 
 } 
 Save this code in a file called oper.c 
 167 

 .h file documentation example 
 /** 
 \file oper.h 
 \brief Prototypes of oper.c functions 
 \author Ing. Jerónimo F. Atencio (jerome5416@gmail.com) 
 \date 2021.05.05 
 \version 1.0.0 
 */ 
 #ifndef OPER_H 
 #define OPER_H 
 //---------------- 
 //-- Prototypes -- 
 //---------------- 
 int operSum (int a, int b); 
 int operMult (int a, int b); 
 #endif 
 We compile the code 
 jerome@linuxVm:~$ gcc -Wall main.c oper.c -osuma.out  
 We generate the doxygen configuration file. 
 jerome@linuxVm:~$ doxygen -g  
 Configuration file `Doxyfile' created.  
 Now edit the configuration file and enter  
 doxygen Doxyfile  
 to generate the documentation for your project  
 jerome@linuxVm:~$  
 We generate the documentation 
 jerome@linuxVm:~$ doxygen 
 We open the documentation using Firefox or any browser you use. 
 jerome@linuxVm:~$ firefox ./html/index.html  
 168 

 28. Simple linked list I 
 The functions below are those needed to operate a simple linked list of 
 a node like the following. 
 struct node_S { 
 int data; 
 struct node_S *sig; 
 }; 
 Insert a node at the beginning (stack) 
 Inserts a new node at the beginning of the simple linked list, the first parameter of the function is a 
 pointer to the head of the lista, in case the list is empty this pointer must be NULL. The 
 second parameter is the data to be inserted into the list. The function returns a pointer to the head of the list. 
 struct node_S * lseInsertStart (struct node_S *h, int data) 
 { 
 struct node_S *p; 
 *err = 0; 
 //-- Request memory -- 
 p = (struct node_S*)malloc (sizeof (struct node_S)); 
 if (p == NULL) { 
 //-- No memory -- 
 return (NULL); 
 } else { 
 //-- Fill the structure -- 
 p->data = data; 
 //-- I put the node at the beginning -- 
 p->sig = h;//-- If it is the first node in the list h is NULL -- 
 //-- Point the pointer at the head of the list to the new node 
 h = p; 
 return (h); 
 } 
 } 
 169 

 Print all nodes 
 Prints the data of the simple linked list, including the address of the node and the address of the next 
 node. The parameter of the function is the pointer to the head of the list. 
 void lsePrint (struct node_S *h) 
 { 
 struct node_S *p; 
 int i = 0; 
 //-- I go through the list and print nodes -- 
 puts(""); 
 printf("Index\tData\t\tNodeDir\t\tNextNodeDir\r\n"); 
 for (p = h; p != NULL; p = p->sig) { 
 printf("%02d\t%08d\t%p\t%p\r\n", i++, p->data, p, p->sig); 
 } 
 puts(""); 
 } 
 Release all nodes 
 Frees the memory that was dynamically allocated from all nodes in the list. The parameter of the 
 function is the pointer to the head of the list. 
 struct node_S * lseRelease (struct node_S *h) 
 { 
 struct node_S *p, *aux; 
 if (h == NULL) { 
 //-- Empty list -- 
 return (h); 
 } else { 
 //-- I go through the list and eliminate nodes -- 
 for (p = h; p != NULL;) { 
 //** Debug ** 
 //printf ("%p\r\n", p); 
 //** Debug ** 
 aux = p;  //-- Except the pointer to the node to delete -- 
 p = p->sig;  //-- I move to the next node -- 
 free (aux);  //-- release the current node -- 
 } 
 h = p;//-- I set the pointer to the head of the list to NULL -- 
 } 
 return (h); 
 } 
 170 

 Counts the number of nodes in the simple linked list 
 The parameter of the function is the pointer to the head of the list and it returns the number of nodes 
 who has the list. 
 int lseCount (struct node_S *h) 
 { 
 struct node_S *p; 
 int i; 
 for (p = h, i = 0; p != NULL; p = p->sig, i++); 
 return (i); 
 } 
 Insert a node at the end 
 Inserts a new node at the end of the simple linked list, the first parameter of the function is a pointer 
 at the head of the list, in case the list is empty this pointer must be NULL. The second 
 parameter is the data to be inserted into the list. The function returns a pointer to the head of the list. 
 struct node_S * lseInsertEnd (struct node_S *h, int data) 
 { 
 struct node_S *p, *aux; 
 //-- Request memory -- 
 p = (struct node_S*)malloc (sizeof (struct node_S)); 
 if (p == NULL) { 
 //-- No memory -- 
 return (NULL); 
 } else { 
 //-- Fill the structure -- 
 p->data = data; 
 p->sig = NULL;//-- Since it is the last node, I point the sig to NULL 
 //-- I'm wondering where to insert it -- 
 if (h == NULL) { 
 //-- The list is empty -- 
 h = p; 
 } else { 
 //-- Search for the last node -- 
 for (aux = h; aux->sig != NULL; aux = aux->sig); 
 //-- Insert the node at the end -- 
 aux->sig = p; 
 } 
 return (h); 
 } 
 } 
 Find a node 
 The first parameter of the function is a pointer to the head of the list where the data to be searched will be searched. 
 found in the second parameter of the function. The function returns a pointer to the node that contains the 
 searched data or NULL in case the searched data is not found. 
 171 

 struct node_S * lseSearch (struct node_S *h, int data) 
 { 
 struct node_S *p; 
 //-- I go through the list -- 
 for (p = h; p != NULL; p = p->sig) { 
 if (p->data == data) { 
 //-- Found the data -- 
 return (p); 
 } 
 } 
 //-- If I left the for, I didn't find anything -- 
 return (NULL); 
 } 
 Remove a node 
 The first parameter of the function is a pointer to the head of the list where the data to be searched will be searched. 
 found in the second parameter of the function, to later eliminate the node. The function 
 returns a pointer to the head of the list or NULL if the list is empty. 
 struct node_S * lseRemover (struct node_S *h, int data) 
 { 
 struct node_S *p, *aux; 
 //-- I check if there is something on the list -- 
 if (h != NULL) { 
 //-- I look for the node to delete -- 
 for (p = h, aux = NULL; p != NULL; aux = p, p = p->sig){ 
 if (p->data == data) { 
 //-- Found the data -- 
 if (aux == NULL) { 
 //-- It is the first node -- 
 h = p->sig; 
 } else { 
 aux->sig =p->sig; 
 } 
 free(p); 
 return (h); 
 } 
 } 
 } else { 
 //-- Empty list -- 
 return (h); 
 } 
 return (h); 
 } 
 172 

 Insert a node in an orderly manner 
 The function inserts the data passed as a parameter into a simple linked list ordered in such a way 
 ascending. If the list is previously created and is unordered, this function will not sort it, the only thing 
 What it does is insert new nodes in an orderly manner. 
 struct node_S * lseInsertOrdered (struct node_S *h, int data) 
 { 
 struct node_S *p, *q, *r; 
 //-- I notice where it goes -- 
 for (p = h, q = NULL; p != NULL && (data < p->data); q = p, p = p->sig); 
 r = (struct node_S*)malloc (sizeof (struct node_S)); 
 if (r == NULL) { 
 //-- No memory -- 
 return (NULL); 
 } else { 
 //-- Fill the structure -- 
 r->data = data; 
 r->sig = NULL; 
 //-- Insert the node where it goes -- 
 if (q == NULL) { 
 //-- It is the first node in the list -- 
 r->sig = h; 
 h = r; 
 } else { 
 //-- Goes before the first node -- 
 r->sig = p; 
 q->sig = r; 
 } 
 } 
 return (h); 
 } 
 173 

 Main function that demonstrates the use of the functions described above. 
 int main(void) 
 { 
 int data[] = {1, 2, 3, 4};  //-- Data to insert into the list -- 
 struct node_S *h = NULL;  //-- Pointer to the head of the list -- 
 struct node_S *aux;  //-- Auxiliary pointer -- 
 int i; 
 //-- I print the sizeof so I can understand the printed addresses -- 
 printf ("sizeof (struct node_S) = %ld\r\n", sizeof (struct node_S) 
 printf ("sizeof (struct node_S*) = %ld\r\n\r\n",sizeof (struct node_S*)); 
 //-- Insert into the list -- 
 for (i = 0; i < 4; i++) { 
 aux = lseInsertStart (h, data[i]); 
 if (aux != NULL) { 
 h = aux; 
 } else { 
 printf ("Error inserting node\r\n"); 
 } 
 } 
 //-- Print the data -- 
 lsePrint (h); 
 //-- Count the number of nodes -- 
 printf ("Nodes qty: %d\r\n", lseCount (h)); 
 //-- Insert into the list -- 
 for (i = 0; i < 4; i++) { 
 aux = lseEndInsert (h, data[i] + 10); 
 if (aux != NULL) { 
 h = aux; 
 } else { 
 printf ("Error inserting node\r\n"); 
 } 
 } 
 //-- Print the data -- 
 lsePrint (h); 
 //-- Count the number of nodes -- 
 printf ("Nodes qty: %d\r\n", lseCount (h)); 
 //-- I'm looking for something that's on the list -- 
 puts ("\r\nI am looking for number 12 in the list:"); 
 aux = lseSearch(h, 12); 
 if (aux != NULL) { 
 printf ("I found it\r\n"); 
 } else { 
 printf ("I didn't find it\r\n"); 
 } 
 174 

 //-- I'm looking for something that is not on the list -- 
 puts ("\r\nI look for number 2 in the list:"); 
 aux = lseSearch(h, 2); 
 if (aux != NULL) { 
 printf ("I found it\r\n"); 
 } else { 
 printf ("I didn't find it\r\n"); 
 } 
 //-- Remove a node from the list -- 
 puts ("\r\n"); 
 puts ("I remove a node from the list that has the number 3 as data:"); 
 h = lseRemover(h, 3); 
 lsePrint (h); 
 //-- Release the data -- 
 puts ("\r\nI release the requested memory"); 
 h = lseRelease(h); 
 //-- Count the number of nodes -- 
 printf ("Nodes qty: %d\r\n", lseCount (h)); 
 return (0); 
 } 
 Exercises 
 1. Take all the functions to operate on a simple linked list and put them in a file 
 called lsd.c and create its corresponding header file lse.h Then create a makefile that compiles 
 lse.c as a static library. Finally add a rule in the makefile to compile a function 
 main that demonstrates the use of simple linked list functions by linking the library before 
 created. 
 2. Implement a function that reads a text file and inserts it sorted by name into a 
 simple linked list. 
 The file format is as follows: 
 Name, age\r\n 
 Jose,33\r\n 
 The prototype of the function is: 
 struct node_S * readFile (struct node_S *h, char *filename) 
 Where: 
 ● h: It is the pointer to the head of the list. 
 ● filename: Name of the source file. 
 The function returns a negative number indicating error or the number of nodes in the list that were 
 they could create. 
 175 

 The node of the simple linked list is: 
 #define NAME_SIZE (32) 
 struct node_S { 
 char name[NAME_SIZE]; 
 int age; 
 struct node_S *sig; 
 }; 
 3. Implement a function with the following prototype that stores the data of a simple list 
 linked in a file made up of structures like the following. 
 #define NAME_SIZE (32) 
 struct data_S { 
 char name[NAME_SIZE]; 
 int age; 
 }; 
 The prototype of the function is: 
 int readFile (struct S_node *h, char *filename) 
 Where: 
 ● h: It isthe pointer to the head of the list. 
 ● filename: Name of the destination file 
 The function returns a negative number indicating error or the number of nodes in the list that were 
 They were able to write to the file. 
 176 

 29. Signals 
 Functions used 
 Function Description Include 
 getpid Returns the PID of the process that executes it sys/types.h 
 unistd.h 
 getppid Returns the PID of the parent of the process that executes it sys/types.h 
 unistd.h 
 Sigaction is a system call that changes the action taken by a process to the 
 receive a certain signal.  signal.h 
 sleep Puts the thread to sleep for a specified number of seconds unistd.h 
 kill is a system call that sends a signal to any process or 
 process group.  sys/types.h 
 signal.h 
 alarm Configures SIGALRM to be sent in a quantity 
 determined by seconds.  unistd.h 
 exit Terminates a process normally stdlib.h 
 pause Stops a process until a unistd.h signal arrives 
 Commands 
 Command Description 
 ps Process Status. Allows you to view the status of the processes. 
 kill Used to send signals to a running process 
 grep Takes a regular expression from the command line, reads standard input or a list of 
 file 
 time Gives us information about the system resources used. 
 Program, process 
 ● Program: Sequence of instructions that the processor executes to perform some operation or 
 data processing. 
 ● Process: It is an instance of a running program.  Each process is identified by the system 
 operational by a number called PID (Process ID) 
 177 

 Examples 
 1. Program prints on the screen its own PID (Process ID) and the PID of the parent process (PPID, Parent 
 Process ID) 
 #include <stdio.h>  
 #include <unistd.h>  
 #include <sys/types.h>  
 int main(void)  
 { 
 pid_t pid, ppid;  
 //-- I get my pid and the parent's pid --  
 pid = getpid();  
 printf ("PID: %d\r\n", pid);  
 ppid = getppid();  
 printf ("PPID: %d\r\n", ppid);  
 return (0);  
 } 
 2. Program in which the legend "Hello signal" is printed when receiving the SIGUSR1 signal. 
 #include <stdio.h>  
 #include <string.h>  
 #include <errno.h>  
 #include <unistd.h>  
 #include <sys/types.h>  
 #include <sys/wait.h>  
 #include <signal.h>  
 void handler_SIGUSR1 (int mySignal)  
 { 
 printf ("Hello signal %d\r\n", mySignal);  
 } 
 int main(void)  
 { 
 int r; 
 struct seguiraction s;  
 //-- Fill the seguiraction structure --  
 s.sa_handler = handler_SIGUSR1;  
 s.sa_flags = 0;  
 sigemptyset(&s.sa_mask);  
 r = seguiraction (SIGUSR1, &s, NULL);  
 if (r < 0) {  
 178 

 //-- Error --  
 printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));  
 return (-1);  
 } else {  
 printf ("I wait for SIGUSR1\r\n");  
 while (1) {  
 sleep(1);  
 } 
 } 
 return (0);  
 } 
 Write and save the above code in a file named example27_02.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example27_02.c -Wall -oexample27_02.out  
 jerome@linuxVm:~$ ./example27_02.out  
 Use another terminal to send SIGUSR1 to the program. 
 jerome@linuxVm:~$ ps -e | grep example27_02.out  
 PPPP pts/0 00:00:00 a.out  
 jerome@linuxVm:~$ kill -SIGUSR1 PPPP 
 In this example the PID is represented by PPPP.  To send the SIGUSR1 signal the pid returned by the 
 ps command is the one used with the kill command 
 179 

 3. Program that generates a segment violation and the SIGSEGV signal is captured. 
 #include <stdio.h>  
 #include <string.h>  
 #include <errno.h>  
 #include <unistd.h>  
 #include <sys/types.h>  
 #include <sys/wait.h>  
 #include <signal.h>  
 #include <stdlib.h>  
 void handler_SIGSEGV (int mySignal)  
 { 
 printf ("Segment violation %d\r\n", mySignal);  
 exit(0);  
 } 
 int main(void)  
 { 
 int r; 
 struct seguiraction s;  
 int *p = NULL;  
 //-- Fill the seguiraction structure --  
 s.sa_handler = handler_SIGSEGV;  
 s.sa_flags = 0;  
 sigemptyset(&s.sa_mask);  
 r = seguiraction (SIGSEGV, &s, NULL);  
 if (r < 0) {  
 //-- Error --  
 printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));  
 return (-1);  
 } else {  
 printf ("About to generate a segfault\r\n");  
 *p = 0; 
 } 
 return (0);  
 } 
 180 

 4. Program that generates a division by zero exception and the SIGFPE signal is captured. 
 #include <stdio.h>  
 #include <string.h>  
 #include <errno.h>  
 #include <unistd.h>  
 #include <sys/types.h>  
 #include <sys/wait.h>  
 #include <signal.h>  
 #include <stdlib.h>  
 void handler_SIGFPE (int mySignal)  
 { 
 printf ("Floating point exception %d\r\n", mySignal);  
 exit(0);  
 } 
 int main(void)  
 { 
 int r; 
 struct seguiraction s;  
 //-- Fill the seguiraction structure --  
 s.sa_handler = handler_SIGFPE;  
 s.sa_flags = 0;  
 sigemptyset(&s.sa_mask);  
 r = seguiraction(SIGFPE, &s, NULL);  
 if (r < 0) {  
 //-- Error --  
 printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));  
 return (-1);  
 } else {  
 printf ("Calculation 1 / 0\r\n");  
 //-- Division by zero in integers generates floating point exception --  
 r = 1 / 0;  
 printf ("%d\r\n", r);  
 } 
 return (0);  
 } 
 181 

 5. Program that configures the alarm function so that the SIGALRM handler is executed every 5 
 seconds 
 #include <stdio.h>  
 #include <string.h>  
 #include <errno.h>  
 #include <unistd.h>  
 #include <sys/types.h>  
 #include <sys/wait.h>  
 #include <signal.h>  
 #include <stdlib.h>  
 void handler_SIGALRM (int mySignal)  
 { 
 printf ("Alarm %d\r\n", mySignal);  
 alarm(5);   //-- I set the alarm for 5 seconds -- 
 } 
 int main(void)  
 { 
 int r; 
 struct seguiraction s;  
 //-- Fill the seguiraction structure --  
 s.sa_handler = handler_SIGALRM;  
 s.sa_flags = 0;  
 sigemptyset(&s.sa_mask);  
 r = seguiraction (SIGALRM, &s, NULL);  
 if (r < 0) {  
 //-- Error --  
 printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));  
 return (-1);  
 } else {  
 //-- I set the alarm for 5 seconds --  
 alarm(5);  
 do { 
 pause();  
 } while (1);  
 } 
 return (0);  
 } 
 Write and save the above code in a file called example27_05.c 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example27_05.c -Wall -oexample27_05.out  
 jerome@linuxVm:~$ ./example27_05.out  
 You can run the program using the time command previously and see the system resources 
 used 
 jerome@linuxVm:~$ time ./example27_05.out  
 182 

 6. Program that captures the pressure of the CTRL-C keys on the keyboard 
 #include <stdio.h>  
 #include <string.h>  
 #include <errno.h>  
 #include <unistd.h>  
 #include <sys/types.h>  
 #include <sys/wait.h>  
 #include <signal.h>  
 #include <stdlib.h>  
 void handler_SIGINT (int mySignal)  
 { 
 printf ("They pressed CTRL-C %d\r\n", mySignal);  
 } 
 int main(void)  
 { 
 int r; 
 struct seguiraction s;  
 //-- Fill the seguiraction structure --  
 s.sa_handler = handler_SIGINT;  
 s.sa_flags = 0;  
 sigemptyset(&s.sa_mask);  
 r = seguiraction (SIGINT, &s, NULL);  
 if (r < 0) {  
 //-- Error --  
 printf ("sigaction error: %d> %s\r\n", errno, strerror(errno));  
 return (-1);  
 } else {  
 //-- I set the alarm for 5 seconds --  
 do { 
 sleep(1);  
 } while (1);  
 } 
 return (0);  
 } 
 183 

 7. Program that exemplifies the use of kill to send SIGUSR1 
 #include <stdio.h>  
 #include <stdlib.h>  
 #include <sys/types.h>  
 #include <signal.h>  
 int main (int argc, char *argv[])  
 { 
 int r; 
 //-- I check the arguments --  
 if (argc < 2) {  
 printf ("Use ./sendSignal PID\r\n");  
 return (-1);  
 } 
 r = kill(atoi(argv[1]), SIGUSR1);  
 if (r != 0) {  
 printf ("Error kill\r\n");  
 return (-2);  
 } 
 printf ("SIGUSR1 could be sent\r\n");  
 return (0);  
 } 
 Write and save the above code in a file named example28_11.c 
 In a terminal run example28_11.out 
 jerome@linuxVm:~$ ./example28_11.out  
 Use another terminal compile the program 
 jerome@linuxVm:~$ gcc -Wall example28_11.c -oexample28_11.out  
 jerome@linuxVm:~$ ps -e | grep example28_11.out  
 PPPP pts/0 00:00:00 a.out  
 jerome@linuxVm:~$ ./example28_12.out PPPP 
 In this example the PID is represented by PPPP. 
 Exercises 
 1. Implement a program that prints the legend "Hello World" five seconds after it is 
 press CTRL-C. (use alarm) 
 2. Implement a program to print a legend every so often. The number of seconds that 
 The time between each print is entered via the command line in seconds. 
 184 

 30.Threads 
 Functions used 
 Function Description Include 
 pthread_create Create a thread pthread.h 
 pthread_join Waits for a speciﬁc thread to terminate pthread.h 
 pthread_exit End a thread pthread.h 
 pthread_cancel Cancels a thread pthread.h 
 pthread_mutex_lock pthread.h 
 pthread_mutex_unlock pthread.h 
 Examples 
 1. Create a new thread 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <pthread.h> 
 #include <unistd.h> 
 void * threadFunc1 (void *p) 
 { 
 int i; 
 for (i = 0; i < 6; i++) { 
 sleep(1); 
 printf ("Th1: Step 1 second\r\n"); 
 } 
 return (NULL); 
 } 
 void * threadFunc2 (void *p) 
 { 
 int i; 
 for (i = 0; i < 2; i++) { 
 sleep(1); 
 printf ("Th2: Step 1 second\r\n"); 
 } 
 return (NULL); 
 } 
 int main(void) 
 { 
 pthread_t t1; 
 void *t1sRet; 
 int rVal; 
 185 

 rVal = pthread_create(&t1, NULL, threadFunc1, NULL); 
 if (rVal != 0) { 
 printf ("Error pthread_create\r\n"); 
 return (-1); 
 } 
 threadFunc2 (NULL); 
 rVal = pthread_join (t1, &t1sRet); 
 if (rVal != 0) { 
 printf ("Error pthread_create\r\n"); 
 return (-1); 
 } 
 return (0); 
 } 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example29_01.c -Wall -lpthread -oexample29_01.out  
 jerome@linuxVm:~$ ./example29_01.out  
 The linker -l directive is added along with the name of the library to include in this case pthread .  By 
 This is observed -lpthread which must be added to link the thread library functions. 
 Warning: 
 Don't forget to add the necessary libraries to link your code. Use the -l directive 
 2. Shows how to pass and receive data from a thread 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <pthread.h> 
 #include <unistd.h> 
 void * threadFunc (void *p) 
 { 
 int i; 
 int *val; 
 int *q; 
 val = (int*)p; 
 printf ("Th: val = %d\r\n", *val); 
 (*val)++; 
 q = (int*)malloc (1 * sizeof(int)); 
 if (q != NULL) { 
 *q = 27; 
 } 
 pthread_exit(q); 
 } 
 int main(void) 
 186 

 { 
 pthread_t t; 
 void *tRet; 
 int rVal; 
 int paramVal; 
 paramVal = 100; 
 printf ("main: paramVal = %d\r\n", paramVal); 
 rVal = pthread_create(&t, NULL, threadFunc, &paramVal); 
 if (rVal != 0) { 
 printf ("Error pthread_create\r\n"); 
 return (-1); 
 } 
 rVal = pthread_join (t, &tRet); 
 if (rVal != 0) { 
 printf ("Error pthread_create\r\n"); 
 return (-1); 
 } 
 printf ("main: *tRet = %d\r\n", *((int*)tRet)); 
 printf ("main: paramVal = %d\r\n", paramVal); 
 return (0); 
 } 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example29_02.c -Wall -lpthread -oexample29_02.out  
 jerome@linuxVm:~$ ./example29_02.out  
 3. Show the use of mutex 
 #include <stdio.h> 
 #include <stdlib.h> 
 #include <pthread.h> 
 #include <unistd.h> 
 int c = 0; 
 pthread_mutex_t lock; 
 void * threadFunc (void *p) 
 { 
 int i; 
 pthread_mutex_lock(&lock); 
 for (i = 0; i < 1e8; i++) { 
 c++; 
 } 
 pthread_mutex_unlock(&lock); 
 } 
 187 

 int main(void) 
 { 
 pthread_t t0, t1; 
 void *tRet; 
 int rVal; 
 rVal = pthread_create(&t0, NULL, threadFunc, NULL); 
 if (rVal != 0) { 
 printf ("Error pthread_create\r\n"); 
 return (-1); 
 } 
 rVal = pthread_create(&t1, NULL, threadFunc, NULL); 
 if (rVal != 0) { 
 printf ("Error pthread_create\r\n"); 
 return (-1); 
 } 
 rVal = pthread_join (t0, &tRet); 
 if (rVal != 0) { 
 printf ("Error pthread_create\r\n"); 
 return (-1); 
 } 
 rVal = pthread_join (t1, &tRet); 
 if (rVal != 0) { 
 printf ("Error pthread_create\r\n"); 
 return (-1); 
 } 
 printf ("c: %d\r\n", c); 
 return (0); 
 } 
 Compiling and running the program. 
 jerome@linuxVm:~$ gcc example29_03.c -Wall -lpthread -oexample29_03.out  
 jerome@linuxVm:~$ ./example29_03.out  
 188 

 31. Sockets 
 Functions used 
 Function Description Include 
 gethostbyname Dynamically allocates memory.  #include <netdb.h> 
 #include <sys/socket.h> 
 inet_ntoa Function for manipulating network addresses 
 internet #include <sys/socket.h> 
 #include <netinet/in.h> 
 #include <harp/inet.h> 
 inet_ntop Converts an IPv4 or IPv6 address from binary to 
 text.  #include <harp/inet.h> 
 getaddrinfo Translation of network addresses and services #include <sys/types.h> 
 #include <sys/socket.h> 
 #include <netdb.h> 
 socket Creates an endpoint of a communication #include <sys/types.h> 
 #include <sys/socket.h> 
 setsockopt Gets and sets options on sockets #include <sys/types.h> 
 #include <sys/socket.h> 
 bind Bind name to u socket #include <sys/types.h> 
 #include <sys/socket.h> 
 listen Wait for connections from a socket #include <sys/types.h> 
 #include <sys/socket.h> 
 accept Accepts a connection to a socket #include <sys/types.h> 
 #include <sys/socket.h> 
 connect Start a connection to a socket #include <sys/types.h> 
 #include <sys/socket.h> 
 send Send a message over a socket #include <sys/types.h> 
 #include <sys/socket.h> 
 recv Receive a message on a socket #include <sys/types.h> 
 #include <sys/socket.h> 
 Examples 
 1. Along with this guide you will find a folder with the following files 
 ● Makefile: Makefile of the example 
 ● TCP_clientMain.c : Example of client usage. 
 ● TCP_serverMain.c: Example of server usage. 
 ● TCP_clientServer.c: TCP client-server code 
 ● TCP_clientServer.h: Necessary deﬁnitions for the TCP client-server 
 In this example, once the server is running, a client can be started which will be left behind. 
 waits for the user to enter a word.  The entered word will be sent to the server which 
 189 

 It will be capitalized and returned to the client. Finally, the client prints it on the screen and waits for the 
 entering a new word. 
 The entire project is configured to connect through the loopback interface on port 5000 so 
 Two computers are not necessary for the test, it is enough to have two terminals open. The server 
 can accept more than one simultaneous connection. 
 Compiling the client and server 
 jerome@linuxVm:~$ make 
 In a terminal we run the server 
 jerome@linuxVm:~$ ./server.out  
 In a terminal we run the client 
 jerome@linuxVm:~$ ./client.out  
 Exercises 
 1. Implement two programs, one TCP client and the other TCP server 
 a.  The client will connect to the server and receive an integer that it will print on the screen before 
 finish its execution. 
 b.  The server, each time a client connects, must return a random number and 
 It will be waiting for a new connection. 
 2. Implement two programs, one TCP client and the other TCP server 
 a.  The client will wait for text to be entered via keyboard, which it will send to the server. Then it 
 It will wait for its response to print what is returned on the screen. 
 b.  The server will receive a text which it must convert to Morse and send it back to the client. 
 3. Implement two programs, one TCP client and the other TCP server 
 a.  The client will read a text file which will be sent to the server and then remain 
 waiting for the data to be returned by main and will store it in another file. 
 b.  The server will wait for client connections and convert all characters to uppercase and 
 will return them to the customer. 
 190 

 32. Visual interfaces: Qt 
 Required programs 
 Use apt to install them 
 Package Description 
 qt5-default QT 5 
 qtcreator qt creator installation package 
 qtbase5-examples QT Examples 
 qt5-doc Documentation 
 qt5-doc-html 
 qtbase5-doc-html Documentation in html 
 Execution 
 qtcreator 
 191