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


int adress =1;
int setAdress;

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
char bigul6[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x03, 0x02, 0x00, 0x03, 0xff, 0x4c, 0x55, 0x4d};


char name[14];
//char usrName[14];
//char supName[14];
//char supPass[14];
//char usrPass[14];
char command[14];
int stringLength;

int kbin(){ // Keyboard Input

	std::cin.get(name, 14);
	std::cin.clear();
	__fpurge(stdin);
	return 1;
}
int rand(){
printf("Poulet Rand\n");
}
int set(){
printf("Poulet Set\n");
}
int identify(){
printf("Poulet Identify\n");
}
int side(){
printf("Poulet Side\n");
}
int bank(){
printf("Poulet Bank\n");
}
int rbank(){
printf("Poulet Rbank\n");
}
int cycle(){
printf("Poulet Cycle\n");
}

int main()
{

if(getuid()!=0){
printf("You must run this program as root. EXITING.\n");
exit(EXIT_FAILURE);
}


printf("\n");
printf("Set workig adress, 0 = all\n");
kbin();
adress = atoi(name);
//int stringLength = strlen(name);
//for (int i = 0; i < stringLength; i++) {
//usrName[i] = name[i];
//testOut[1] = usrName;  // teporaire log genre ostie de chien sale
printf("Working Adress = %d \n", adress);
printf("\nList of available commands:\n\n");
printf("Rand	: Perform Random on working adress\n");
printf("Set	: Set the new Working Adress\n");
printf("Ident	: Identify the lamp at Working Adress\n");
printf("Sident	: Identyfy and prompt if single\n");
printf("Bank	: Bank Working Adress\n");
printf("Rbank	: Perform Rand on Bank\n");
printf("Cycle	: Perform Ident Cycle of Rand\n");

kbin();
std::string random = ("Rand");
std::string Sset = ("Set");
std::string Iidentify = ("Ident");
std::string Sside = ("Sident");
std::string Bbank = ("Bank");
std::string Rrbank = ("Rbank");
std::string Ccycle = ("Cycle");
// passer a une variable
stringLength = strlen(name);
for (int i = 0; i < stringLength; i++) {
command[i] = name[i];
}

if(command == random){
rand(); 
}
else if(command == Sset){
set();
}
else if(command == Iidentify){
identify();
}
else if(command == Sside){
side();
}
else if(command == Bbank){
bank();
}
else if(command == Rrbank){
rbank();
}
else if(command == Ccycle){
cycle();
}

else printf("Invalid Command\n");
//if (god == 0){// le return de kbin c'est toujours name
//printf("\n\nMake your Supervivsor approve these settings: \n\n");
//}
// faut rajouter les includes
//readfile();


//printf("The Program will read from a file and display the content \n");
//printf("The file will have all the information about the unit \n\n");
// non ca je lai mis apres la logique.



//if(god == 0){
//printf("Enter Supervisor Name:\a");
//kbin();
//stringLength = strlen(name);
//for (int i = 0; i < stringLength; i++){
//supName[i] = name[i];
//}
//printf("stringLength = %d \n", stringLength);
//printf("sup name = %s \n", name);
//printf("Enter Supervisor Password:\a");
// metre la le usr root pass
//if(god = 0) {
//kbin();
//}
//else printf("fuck");
//stringLength = strlen(name);
//for (int i = 0; i < stringLength; i++) {
//supPass[i] = name[i];
//} // end of god 0
//}
//else printf("Fuck");
//}
//}

//if (god = 0){
//printf("supPass = %s \n", supPass);



// /old  stuff  New Stuff
//int input = 66;
//char input2 = 28;
//char line [3];
//printf("Enter Primary(starting) Adress: \n");
//std::cin.get( line, 3);
//std::cout << line << "\n";
//input2 = input;
//input = atoi (line);
//printf("the value of input is %d \n" ,input);
//printf("Scan DUT (Device Under Test) Bar Code to Beiging Test \n");
	
//    bzero(buffer,256);
//    printf("reading barcode:");

//writeCsv();

 //   scan_keyascii();
//printf("\n\n\nThe Test is Executing\n");
// Now pour Modifier la valeur de ce que je desire configurer

//bigul1[9]={input};
//bigul2[9]={input};
//bigul5

//
//printf(" The value of bigul1 9 is %d \n", bigul1[9]);

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
    printf ("Write operation is successful \n");
//    printf ("Why Stall \n ca a lair quil faut le backslas n abs \n");




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


