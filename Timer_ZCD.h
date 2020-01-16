

/* 
 * File:        Timer.h
 * Author:      Momen Ali
 * Comments:    OS module use timer ISR to simulate ZCD  
 * Revision history: 16/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __TIMER_ZCD_H
#define __TIMER_ZCD_H

#include <xc.h>

#include "HW.h" // include processor files - each processor file is guarded.  


/*TIMER INTERUPT FLAG OPERATIONS*/
#define TMR_GET_FLAG			(TMR_I_FLAG)
#define TMR_CLEAR_FLAG			(TMR_I_FLAG = 0)

/* 
 * Time calculation
 * timer0 is 8bit => max count is 256
 * CLKO input in the timer0 is (FOSC/4)
 * XTEL_FREQ = 8000000     => CLKO = 2000000 
 * we are using pre scaler so CLK =  ( CLKO / PRE SCALER )
 * PRE SCALER = 256  => CLK = 7812.5
 * TICK TIME = 1 / CLK   => TICK TIME = 128 us
 * OVERFLOW TIME = TICK TIME * 256  => 128 us * 256 = 32.768 ms
 * TICK TIME = 128 us
 * we need tick every 10 ms to simulate ZCD
 * 10 ms / 128 us = 78.125
 * TMR0 = 256 - (TICKS)
 */
#define ZCD_PERIOD_TICK_NUM (78)
#define TMR_LOAD_REGISTER(TICKS)		(TMR_REG = 256 - (TICKS))

/* assume it's 5 ms till we make dynamic design*/
#define OS_TICK (10)


void TMR_Init(void);
void TMR_Start(void);
void TMR_Stop(void);
uint8 TMR_CheckOverflow(void);

#endif	/* XC_HEADER_TEMPLATE_H */

