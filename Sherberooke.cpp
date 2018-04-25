#include <prussdrv.h>
#include <pruss_intc_mapping.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "serialib.h"
#include <ctype.h>
#include <limits>  //   //?
#include <stdio_ext.h>
#include <iostream>
#include <fstream>
#include <string>
// faire menage dans les includes a la fin
#include <prussdrv.h>
#include <pruss_intc_mapping.h>
#define PRU_NUM 0 	// Using PRU 0

#define         DEVICE_PORT             "/dev/ttyO2"  

// Experimental Stuff ///








i

char usrPass[14];
int passAuth(){ 
std::string root = "root";
std::string password = "password";
if (usrPass == root){
// vas remplacer par case NON PEUT PAS single expression multiple  cases
god =1;
//usrPass = root;
printf("je suis une huiter man!");
}
// marcheras pas switch(1){
else if (usrPass == password){
printf("Good!");
}

else {
printf("You are not qualified to run this station Motherfucker\n");
exit(EXIT_FAILURE);
}
}

char buffer[256];
char bar_value;


   
   
   /*!
 \file      Example1.cpp

 \brief     Super COOL Stuff,  also Richard was fired today!
 \	    Good Drift Wood Riddance!
 \author    Marcel Bergeron   Based on some work from a french guy
 \version   0.1
 \date      05/01/2011
 */

                

// Set dev adress
char bigul1[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x03, 0x02, 0x00, 0x03, 0xff, 0x4c, 0x55, 0x4d};
// Set DMX adress
char bigul2[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x11, 0x02, 0x00, 0x03, 0xff, 0x4c, 0x55, 0x4d};
// Set Overide
char bigul3[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x10, 0x02, 0x00, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set Light Overide
char bigul4[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x04, 0x02, 0x00, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set DMX Enable
char bigul5[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x0e, 0x02, 0x00, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set Random
char bigul[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x03, 0x02, 0x00, 0x03, 0xff, 0x4c, 0x55, 0x4d};


char name[14];
char usrName[14];
char supName[14];
char supPass[14];
//char usrPass[14];

int kbin() //keyboard Input

{

std::cin.get( name, 14);
std::cin.clear();
__fpurge(stdin);


return 1;
}

char string;

int main()
{

if(getuid()!=0){
printf("You must run this program as root. EXITING.\n");
exit(EXIT_FAILURE);
}


printf("\n\n\n\n\n");
printf("Welcome to the LIDLUM Linear Serie Automated Test \n \n");
printf("Enter your Operator Name: \n\n");
kbin();
int stringLength = strlen(name);
for (int i = 0; i < stringLength; i++) {
usrName[i] = name[i];
testOut[1] = usrName;  // teporaire log genre ostie de chien sale
printf("Operator name = %s \n", usrName);
}
printf("stringLength = %d \n", stringLength);
printf("Welcomme %s \nInput Operator Password:", usrName);
kbin();
// passer a une variable
stringLength = strlen(name);
for (int i = 0; i < stringLength; i++) {
usrPass[i] = name[i];
}
passAuth();  // Password Autentification

if (god == 0){// le return de kbin c'est toujours name
printf("\n\nMake your Supervivsor approve these settings: \n\n");
}
// faut rajouter les includes
readfile();


//printf("The Program will read from a file and display the content \n");
//printf("The file will have all the information about the unit \n\n");
// non ca je lai mis apres la logique.

//printf ("fuck richard");

if(god == 0){
printf("Enter Supervisor Name:\a");
kbin();
stringLength = strlen(name);
for (int i = 0; i < stringLength; i++){
supName[i] = name[i];
}
printf("stringLength = %d \n", stringLength);
printf("sup name = %s \n", name);
printf("Enter Supervisor Password:\a");
// metre la le usr root pass
//if(god = 0) {
kbin();
//}
//else printf("fuck");
stringLength = strlen(name);
for (int i = 0; i < stringLength; i++) {
supPass[i] = name[i];
} // end of god 0
//}
//else printf("Fuck");
//}
}

//if (god = 0){
printf("supPass = %s \n", supPass);



// /old  stuff  New Stuff
int input = 66;
char input2 = 28;
char line [3];
printf("Enter Primary(starting) Adress: \n");
std::cin.get( line, 3);
std::cout << line << "\n";
input2 = input;
input = atoi (line);
printf("the value of input is %d \n" ,input);
printf("Scan DUT (Device Under Test) Bar Code to Beiging Test \n");
	
//    bzero(buffer,256);
//    printf("reading barcode:");

writeCsv();

    scan_keyascii();
printf("\n\n\nThe Test is Executing\n");
// Now pour Modifier la valeur de ce que je desire configurer

bigul1[9]={input};
bigul2[9]={input};
//bigul5

printf(" The value of bigul1 9 is %d \n", bigul1[9]);

// End of New Stuff


    serialib LS;                                                            // Object of the serialib class
    int Ret;                                                                // Used for return values
//    char Buffer[128];
//    char Buffer[128];
    char Buffer[256];
    int Buffed[128];

    // Open serial port

    Ret=LS.Open(DEVICE_PORT,115200);                                        // Open serial link at 115200 bauds
    if (Ret!=1) {                                                           // If an error occured...
        printf ("Error while opening port. Permission problem ?\n");        // ... display a message ...
        return Ret;                                                         // ... quit the application
    }
    printf ("Serial port opened successfully !\n");
    // Write Lidlum command on the serial port

    Ret=LS.Write (bigul1, 14);
    Ret=LS.Write (bigul2, 14);
    Ret=LS.Write (bigul3, 14);
    Ret=LS.Write (bigul4, 14);
    Ret=LS.Write (bigul5, 14);                                          // Send the command on the serial port
    if (Ret!=1) {                                                           // If the writting operation failed ...
        printf ("Error while writing data\n");                              // ... display a message ...
        return Ret;                                                         // ... quit the application.
    }
    printf ("POulet Write operation is successful \n");
    printf ("Why Stall \n ca a lair quil faut le backslas n abs \n");




    // Read a string from the serial device
//    Ret=LS.ReadString(Buffer,'\n',128,5000);  // Read a maximum of 128 characters with a timeout of 5 seconds
//    Ret=LS.ReadString(Buffer, 0xff,128,5000);   // The final character of the string must be a line feed ('\n')
//    if (Ret>0) {
	//Buffed = atoi (Buffer);                                                              // If a string has been read from, print the string
//	printf ("Miyuki : %d \n",Buffer);
       // printf ("String read from serial port : %s",Buffer);}
//}
//    else
//        printf ("TimeOut reached. No data received !\n");                   // If not, print a message.



    // Close the connection with the device
    LS.Close();

printf("This is where we mess with the pruss \n");

// Second part of the test, Pruss Stuff for the DMX


// Initialize structure used by prussdrv_pruintc_intc
// PRUSS_INTC_INITDATA is found in the pruss_intc_mapping.h
tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
// Allocate and initialyze Memory
prussdrv_init ();
prussdrv_open (PRU_EVTOUT_0);
// Maps PRU Interrupts
prussdrv_pruintc_init(&pruss_intc_initdata); 

// Maintenant ecrire une valeur dans la memoire du PRUSS
// Motherfucker
// safe pour le debut mais modify
unsigned int percent = 50;
prussdrv_pru_write_memory(PRUSS0_PRU0_DATARAM, 0, &percent, 4);
unsigned int sample = 10;
prussdrv_pru_write_memory(PRUSS0_PRU0_DATARAM, 1, &sample, 4);
// quand devmem2 ces adresse 0x4a300000
// ca donne 0x32 qui est 50 dec et 0x4a300004 donne BB

// up to this point it fucking works!!!!!
//but I should realy split the program ?  francois?


// Load and Execute the PRU Programm on the PRU
prussdrv_exec_program (PRU_NUM, "./toBeDmx.bin");
// Wwait for the event Completion from PRU, returns PRU_EVTOUT_0 number
int n = prussdrv_pru_wait_event (PRU_EVTOUT_0);
printf("PRU program completed, event number %d. \n", n);
// Disable PRU and close memory mappings

prussdrv_pru_disable(PRU_NUM);
prussdrv_exit ();


    return 0;
}


