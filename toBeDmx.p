// BIT BAGNING DMX Signal
// Written By Marcel Bergeron 2018
// Output is r30.5 (P9_27) and Input is r31.3 (P9_28)

.origin 0               // offset of start of program in PRU memory
.entrypoint START       // program entry point used by the debugger

#define PRU0_R31_VEC_VALID 32
#define EVENTOUT0 3

.macro SLEEPUS
.mparam us,inst,lab
    MOV r7, (us*100)-1-inst
lab:
    SUB r7, r7, 1
    QBNE lab, r7, 0
.endm
//us inst are defined later in the program genre SLEEPUS 12, 1
//en passant ca marche parfaitement  BITBANG MOTHERFUCKER

.macro BRING_HIGH
    SET r30.t5
.endm

.macro BRING_LOW
    CLR r30.t5
.endm

//.macro STOP_BIT
//	BRING_HIGH
//	SLEEPUS 8, 1, CSTOP_BIT
//	SET r30.t5
	
//.endm

START:
        // Reading the memory that was set by the C program into registers
	// r1 - Read the PWM percent high (0-100)
	MOV	r0, 0x00000000	   //load the memory location
	LBBO	r6, r0, 0, 1	   //load the percent value into r1
	// r2 - Load the sample time delay
	MOV	r0, 0x00000004	   //load the memory location
	LBBO	r2, r0, 0, 4	   //load the step delay value into r2
	// r3 - The PWM precent that the signal is low (100-r1)
	MOV	r3, 100		   //load 100 into r3
	SUB	r3, r3, r1	   //subtract r1 (high) away from 100 

MAINLOOP:	
// (init)
	MOV R14, 0  // will be use to determine if 0 ou 1
	BRING_HIGH   // this will be modified
	SLEEPUS 75, 1, MARK_BEFORE  // juste pour sassurer que c'est high
	BRING_LOW
	SLEEPUS 92, 1, BREAK
	BRING_HIGH
	SLEEPUS 12, 1,  MARK_AFTER_BREAK
	BRING_LOW
	SLEEPUS 32, 1, START_CODE
//	STOP_BIT
	BRING_HIGH
	SLEEPUS 8, 1, STOP_BIT
BIT_BANG:
	MOV r11, 8
	MOV R15, 512

EVALUATE:
// load dans r10 la valeur a 0x00000000
// evaluate 0 ou 1 bit
// if 0 bring low    r14 = 0 
//  pAS bon de lete MOV r6.t0, r2.t0 // on vas voir
//LBBO r6, r1, r11, 1
//LBBO r6, r1.b0, 0, 1
// fait planter    LBCO r6, c1, 0, 1
//MOV r6, r1.b0.t1
QBEQ DELAY_BIT, r6, 1  // vas direc a delay si un parceque high apres stop bit
//mais pas bon encore
BRING_LOW  // On devrait etre apres les 2 stop bits
DELAY_BIT:
	SLEEPUS 4, 1, DUREE_BIT
	SUB r11, r11, 1  // r 11 pour 8 bits (repeat 8x)
	QBNE EVALUATE, R11, 0
STOPEND:
	BRING_HIGH
	SLEEPUS 8, 1, STOP
//STOP_BIT


SUB r15, r15, 1
//QBNE EVALUATE, R15, 0


// la logiqur devrait etre correct maintenant evaluer....	


//	MOV	r4, r1		   // start counter at number of steps high
//	SET	r30.t5	           // set the output P9_27 high
//SIGNAL_HIGH:
//	MOV	r0, r2		   // the delay step length - load r2 above
//DELAY_HIGH:
//	SUB	r0, r0, 1          // decrement delay loop counter
//	QBNE	DELAY_HIGH, r0, 0  // repeat until step delay is done
//	SUB	r4, r4, 1          // the signal was high for a step
//	QBNE	SIGNAL_HIGH, r4, 0 // repeat until signal high steps are done

	// Now the signal is going to go low for 100%-r1% - i.e. r3
//	MOV	r4, r3		   // number of steps low loaded
//	CLR	r30.t5	           // set the output P9_27 low
//SIGNAL_LOW:
//	MOV	r0, r2		   // the delay step lenght - load r2 above
//DELAY_LOW:
//	SUB	r0, r0, 1          // decrement loop counter
//	QBNE	DELAY_LOW, r0, 0   // repeat until step delay is done
//	SUB	r4, r4, 1          // the signal was low for a step
//	QBNE	SIGNAL_LOW, r4, 0  // repeat until signal low % is done

	QBBS	END, r31.t3        // quit if button on P9_28 is pressed
	QBA	MAINLOOP           // otherwise loop forever
END:                               // end of program, send back interrupt
	MOV	R31.b0, PRU0_R31_VEC_VALID | EVENTOUT0
	HALT
