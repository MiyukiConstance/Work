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
/////////////////////PAS BON IL Y A DEUX OVERIDE!!!!!!!!!!///////
/////////// MODIFIER LE RESTE DU PROGRAMME /////////////// DEMAIN
// Set dev adress ////// Verrified
char bigul1[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x03, 0x02, 0x01, 0x03, 0xff, 0x4c, 0x55, 0x4d};
// Set DMX adress  ///// ?
char bigul2[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x11, 0x02, 0x01, 0x03, 0xff, 0x4c, 0x55, 0x4d};
// Set DMX Enable /////// ????
char bigul3[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x10, 0x02, 0x01, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set Light Overide  //////Verrified
char bigul4[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x04, 0x02, 0x01, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set Identify  ////// Verrified
char bigul5[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x0e, 0x02, 0x01, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set Random  // pas bon encore
char bigul6[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x03, 0x02, 0x01, 0x03, 0xff, 0x4c, 0x55, 0x4d};


char name[14];
char command[14];
int stringLength;

int kbin(){ // Keyboard Input

	std::cin.get(name, 14);
	std::cin.clear();
	__fpurge(stdin);
	return 1;
}
int subMain(){

printf("Working Adress = %d \n", adress);
printf("\nList of available commands:\n\n");
printf("Rand	: Perform Random on working adress\n");
printf("Set	: Set the new Working Adress\n");
printf("Ident	: Identify the lamp at Working Adress\n");
printf("Sident	: Identyfy and prompt if single\n");
printf("Bank	: Bank Working Adress\n");
printf("Rbank	: Perform Rand on Bank\n");
printf("Cycle	: Perform Ident Cycle of Rand\n");
printf("DMX 	: Enable DMX on ALL Channels\n");
printf("Overide	: Set light overide on ALL channels\n");
}
int write(){
	 serialib LS;  // Object of the serialib class
    int Ret;      // Used for return values

    char Buffer[256];
    int Buffed[128];

    // Open serial port

    Ret=LS.Open(DEVICE_PORT,115200); // Open serial link at 115200 bauds
    if (Ret!=1) {                    // If an error occured...
        printf ("Error while opening port. Permission problem ?\n"); 
        return Ret;                  // ... quit the application
    }
    printf ("Serial port opened successfully !\n");
    // Write Lidlum command on the serial port

    Ret=LS.Write (bigul1, 14);
    Ret=LS.Write (bigul2, 14);
    Ret=LS.Write (bigul3, 14);
    Ret=LS.Write (bigul4, 14);
    Ret=LS.Write (bigul5, 14);                
    if (Ret!=1) {                             
        printf ("Error while writing data\n");
        return Ret;                           
    }
    printf ("Write operation is successful \n");

    // Close the connection with the device
    LS.Close();
}
int rand(){
printf("Poulet Rand\n");
}
int set(){
printf("Poulet Set\n");
bigul1[9] = adress;
bigul2[9] = adress;
bigulX[9] = adress;
bigul6[9] = adress;
//no write yet

printf("The New working adress is %d \n", bigul1[9]);

}
int identify(){
printf("Poulet Identify\n");
sendident(); //existe pas encore
}
int side(){
printf("Poulet Side\n"); // Side Ident
//sendident();
printf("Is the light at unique adress?\n");
kbin();
if (name == 'n'){
sendsix(); // existe pas encore, met le working a 600
}}

int bank(){
printf("Poulet Bank\n");
sendsix();// send working adress to 600
}
int rbank(){
printf("Poulet Rbank\n");
// set working adress to 600
// perform random
// remet working a ce quelle etait
}
int cycle(){
printf("Poulet Cycle\n");
for (i = 0, i<15, i++) {
	//set working adress to 500
	setident();//identify
	side();
	printf("Input new DMX adress);
	kbin();
	bigulX[x] = //name
	//write  to working new address
	}
}
int dmx(){
printf("Poulet DMX\n");
bigul5[9] = 0;
// no write yet
}
int overide(){
printf("Poulet Overide\n");
bigul4[9] = 0;
// no write yet
}

/////////////////////////////MAIN///////////////////////
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
subMain();  // Options

set();	


std::string random = ("Rand");
std::string Sset = ("Set");
std::string Iidentify = ("Ident");
std::string Sside = ("Sident");
std::string Bbank = ("Bank");
std::string Rrbank = ("Rbank");
std::string Ccycle = ("Cycle");
std::string dDMX("DMX");
std::string Ooveride = ("Overide");
// passer a une variable

kbin();
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
else if(command == dDMX){
dmx();
}
else if(command == Ooveride){
overide();
}
else printf("Invalid Command\n");

   

printf("This is where we mess with the pruss \n");
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

