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
//#include <limits>  //   //?
#include <stdio_ext.h>
#include <iostream>
#include <fstream>
#include <string>
// faire menage dans les includes a la fin
#include <prussdrv.h>
#include <pruss_intc_mapping.h>



#define PRU_NUM 0 	// Using PRU 0

#define         DEVICE_PORT             "/dev/ttyO2"  


int adress = 0;
int adress1 = 0;
unsigned int wAdress = 0; // working adresss
unsigned int aAdress = 1;
int aAdr = 1;
int aAdr1 = 1;

int setAdress;
/////////////////////PAS BON IL Y A DEUX OVERIDE!!!!!!!!!!///////
/////////// MODIFIER LE RESTE DU PROGRAMME /////////////// DEMAIN
// Set dev adress ////// Verrified
//char
char bigul1[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x03, 0x02, 0x01, 0x03, 0xff, 0x4c, 0x55, 0x4d};
// Set DMX adress  ///// ?
char bigul2[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x11, 0x02, 0x01, 0x03, 0xff, 0x4c, 0x55, 0x4d};
// Set DMX Enable /////// ????
char bigul3[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x10, 0x02, 0x01, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set Light Overide  //////Verrified
char bigul4[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x04, 0x02, 0x01, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set Identify  ////// Verrified
char bigul5[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x0e, 0x02, 0x01, 0x01, 0xff, 0x4c, 0x55, 0x4d};
// Set Random  // commande 13 Verrified
char bigul6[]={0x4c, 0x49, 0x44, 0x00, 0x00, 0x4e, 0x13, 0x00, 0xff, 0x4c, 0x55, 0x4d};
int onbigul1 = 0;
int onbigul2 = 0; 
int onbigul3 = 0;
int onbigul4 = 0;
int onbigul5 = 0;
int onbigul6 = 0;
int working = 1;
char name[14];
char command[14];
int stringLength;

int bank();
int assign();
 

int kbin(){ // Keyboard Input

	std::cin.get(name, 14);
	std::cin.clear();
	__fpurge(stdin);
	return 1;
}
int subMain(){

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

    if (onbigul1 == 1){
    Ret=LS.Write (bigul1, 14);
    }
    if (onbigul2 == 1){
    Ret=LS.Write (bigul2, 14);
    }
    if (onbigul3 == 1){
    Ret=LS.Write (bigul3, 14);
    }
    if (onbigul4 == 1){
    Ret=LS.Write (bigul4, 14);
    }
    if (onbigul5 == 1){
    Ret=LS.Write (bigul5, 14);
    }
    if (onbigul6 == 1){
    Ret=LS.Write (bigul6, 14);
    }            
    if (Ret!=1) {                             
        printf ("Error while writing data\n");
        return Ret;                           
    }
    printf ("Write operation is successful \n");

    // Close the connection with the device
    LS.Close();
}
//int sendident(){}
int rand(){
//printf("Poulet Rand\n");
bigul6[3] = adress;
bigul6[4] = adress1;
onbigul6 = 1;
write();
onbigul6 = 0;
}

char buffer[2];

int set(){
//char buffer[2];	
//printf ("wadresss = %d\a", wAdress);
	for (int i = 0; i < 2; i++){
	buffer[i] = ((wAdress >> (8 * i)) & 0xFF);
	}
	adress = buffer[0];
	adress1 = buffer[1];
//	printf("adress1 = %d \n", adress);
//	printf("adress = %d \n", adress1);
}

int aSet(){
//char buffer[2];
//printf ("aAdress = %d \n", aAdress);
	for (int i = 0; i < 2; i++){
	buffer[i] = ((aAdress >> (8 * i)) & 0xFF);
	}
	aAdr = buffer[0];
	aAdr1 = buffer[1];
//	printf("aAdr = %d\n", aAdr);
//	printf("aAdr1 = %d\n", aAdr1);
}


int identify(){
//printf("Poulet Identify\n");
bigul5[3] = adress1;
bigul5[4] = adress;
onbigul5 = 1;
write();
onbigul5 = 0;
}

int num;
int side(){
	identify();
	printf("\nIs the light at unique adress?\n");
	kbin();
	std::string no = ("n");
		if (name == no){
		bank();
		}
	else {
	printf("\nInput new DMX adress\n");
	kbin();
	aAdress = atoi(name);
	aSet(); //Splittte la nouvelle adress( celle a ecrire) 
	assign();	
     	}
}



int bank(){ 
//	set();
	bigul1[3] = adress1; 
	bigul1[4] = adress;
	//wAdress = 600;
	bigul1[8] = 2;
	bigul1[9] = 88 ;
 
	onbigul1 = 1;
	write();
	onbigul1 = 0;
	}

int assign(){
	bigul1[3] = adress1;
	bigul1[4] = adress;
	bigul1[8] = aAdr1;
	bigul1[9] = aAdr;
	bigul2[8] = aAdr1;
	bigul2[9] = aAdr;
	onbigul1 = 1;	
	onbigul2 = 1;
	write();
	onbigul1 = 0;
	onbigul2 = 0;
}

int rbank(){
printf("Poulet Rbank\n");
wAdress = 600;
set();
//Fucking patch
int fuck = adress;
int fuck1 = adress1;
adress = fuck1;
adress1 = fuck;
rand();
// perofir rand at dress 600
// bigul 3 4
//bigul1[3
//adress = 2;
//adress1 = 88;
}

int cycle(){
	for (int i = 500; i <= 515; i++) {
	printf("Now testing Adress %d\n\n", i);
	wAdress = i;
	set(); // divise l'adresse
	side(); //probleme dans side ?
	}
}
int dmx(){
onbigul3 = 1;
write();
onbigul3 = 0;
}
int overide(){
onbigul4 = 1;
write();
onbigul4 = 0;
}
int mSet(){
printf("Input New Lamp Adress: \n");
kbin();
wAdress = atoi(name);
set();
}

/////////////////////////////MAIN///////////////////////
int main(){

if(getuid()!=0){
printf("You must run this program as root. EXITING.\n");
exit(EXIT_FAILURE);
}
wAdress = 1;
printf("\n\n\n \\\\\\\\\\\\\\Wlecome\\\\\\\\\\\\\ \n\n\n");
for (;;){
//set();
printf("\n");
printf("Lamp adress is: %d\n", wAdress);;

subMain();  // Options

std::string random = ("Rand");
std::string Sset = ("Set");
std::string Iidentify = ("Ident");
std::string Sside = ("Sident");
std::string Bbank = ("Bank");
std::string Rrbank = ("Rbank");
std::string Ccycle = ("Cycle");
std::string dDMX("DMX");
std::string Ooveride = ("Overide");
printf("\nInput Command :\n");
kbin();
stringLength = strlen(name);
for (int i = 0; i < stringLength; i++) {
command[i] = name[i];
//command = name;
}
//i = 0;
if(command == random){
rand(); 
}
else if(command == Sset){
mSet();
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
else {printf("Invalid Command\n");}

int stringLenght = strlen(command);
for (int i = 0; i< stringLenght; i++) {
command[i] = 0;
}

   

//printf("This is where we mess with the pruss \n");
// Initialize structure used by prussdrv_pruintc_intc
// PRUSS_INTC_INITDATA is found in the pruss_intc_mapping.h
//tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
// Allocate and initialyze Memory
//prussdrv_init ();
//prussdrv_open (PRU_EVTOUT_0);
// Maps PRU Interrupts
//prussdrv_pruintc_init(&pruss_intc_initdata); 

// Maintenant ecrire une valeur dans la memoire du PRUSS
// Motherfucker
// safe pour le debut mais modify
//unsigned int percent = 50;
//prussdrv_pru_write_memory(PRUSS0_PRU0_DATARAM, 0, &percent, 4);
//unsigned int sample = 10;
//prussdrv_pru_write_memory(PRUSS0_PRU0_DATARAM, 1, &sample, 4);
// quand devmem2 ces adresse 0x4a300000
// ca donne 0x32 qui est 50 dec et 0x4a300004 donne BB


//but I should realy split the program ?  francois?


// Load and Execute the PRU Programm on the PRU
//prussdrv_exec_program (PRU_NUM, "./toBeDmx.bin");
// Wwait for the event Completion from PRU, returns PRU_EVTOUT_0 number
//int n = prussdrv_pru_wait_event (PRU_EVTOUT_0);
//printf("PRU program completed, event number %d. \n", n);
// Disable PRU and close memory mappings

//prussdrv_pru_disable(PRU_NUM);
//prussdrv_exit ();


//    return 0;
}

}
