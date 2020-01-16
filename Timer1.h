
/* 
 * File:        Timer1.h
 * Author:      Momen Ali   
 * Comments:    Designed to make the firing angle 
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __TIMER_1_H
#define	__TIMER_1_H

#include <xc.h>

#include "HW.h" // include processor files - each processor file is guarded.  


/* 
 * Time calculation
 * timer1 is 16bit => max count is 65,536
 * CLKO input in the timer1 is (FOSC/4)
 * XTEL_FREQ = 8000000     => CLKO = 2000000 
 * we are using pre scaler so CLK =  ( CLKO / PRE SCALER )
 * PRE SCALER = 2  => CLK = 1000000 
 * TICK TIME = 1 / CLK   => TICK TIME = 1 us
 * OVERFLOW TIME = TICK TIME * max count  => 1 us * 65536 = 65.536 ms
 * TICK TIME = 1 us
 * we need to change the timer with accuracy of 1 degree
 * 1 degree = 10 ms / 180 = 55us
 * TMR1 = 65536 - ((DEGREE)* 55)
 */
#define TMR1_LOAD_REGISTER(DEGREE)		(TMR1_REG = 65536 - ((DEGREE) * 55))

/*TIMER 1 START AND STOP*/
#define TMR1_START  (TMR1_START_FLAG = 1) 
#define TMR1_STOP   (TMR1_START_FLAG = 0)


/*TIMER INTERRUPT FLAG OPERATIONS*/
#define TMR1_GET_FLAG			(TMR1_I_FLAG)
#define TMR1_CLEAR_FLAG			(TMR1_I_FLAG = 0)

void TMR1_Init(void);
void TMR1_Start(uint8 degree);
void TMR1_Stop(void);
uint8 TMR1_CheckOverflow(void);
void TMR1_ISR(void);

#endif	/* __TIMER_1_H */

