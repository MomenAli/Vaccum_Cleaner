
/* 
 * File:   Hardware 
 * Author: Momen Ali
 * Comments: this file contain all the definitions related to the hardware
 * Revision history:  1/2/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __HW_H
#define	__HW_H
 
#include<xc.h>
#define _XTAL_FREQ 8000000

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
/************************************HW*************************************
 *                               description                               *
 * this header included all the configuration of micro controller directly *
 * if you change the micro controller please change these configuration    *
 * pic16f877a                                                              *
 ***************************************************************************/

/*TEST CODE*/
#define OS_TICK   (5)
/*END TEST CODE*/


/* GPIO Port Data Registers redefinition */
#define GPIO_PORTA_DATA      (PORTA)
#define GPIO_PORTB_DATA      (PORTB)
#define GPIO_PORTC_DATA      (PORTC)
#define GPIO_PORTD_DATA      (PORTD)
#define GPIO_PORTE_DATA      (PORTE)

/* GPIO Port Direction Registers redefinition */
#define GPIO_PORTA_DIR       (TRISA)
#define GPIO_PORTB_DIR       (TRISB)
#define GPIO_PORTC_DIR       (TRISC)
#define GPIO_PORTD_DIR       (TRISD)
#define GPIO_PORTE_DIR       (TRISE)

/* number of pins in ports */

#define PORTA_PINS              (8)
#define PORTB_PINS              (8)
#define PORTC_PINS              (8)
#define PORTD_PINS              (8)
#define PORTE_PINS              (3)

/* GPIO direction setting */
#define GPIO_OUT                (0)
#define GPIO_IN                 (1)



/*
 * Redefine register and configuration bits of TIMER 0
 * if you use another timer please edit this section 
 */
/*
 * PSA = 0  Pre scaler is assign to TIMERO
 * PSA = 1  Pre scaler is assign to WDT 
 */
#define TIMER_PRESCALER_ACTIVE   (PSA = 0)


/*
 * 
 *  define the pre scaler as below table 
 *    _____________________
 *  | TMR0 RATE | PS2:PS0 |
 *  |___________|_________|
 *  |     2     |   000   |
 *  |___________|_________|
 *  |     4     |   001   |
 *  |___________|_________|
 *  |     .     |    .    |
 *  |___________|_________|
 *  |     .     |    .    |
 *  |___________|_________|
 *  |    128    |   110   |
 *  |___________|_________|
 *  |    256    |   111   |
 *  |___________|_________|
 *  
 */
/* 
 * we will use pre scaler 256
 * edit this if you need to change pre scaler 
 */
#define TMR_PRESCALER_256 PS2 = 1;\
                            PS1 = 1;\
                            PS0 = 1

/*
 * timer 0 register
 */
#define TMR0_REG    (TMR0)
/*this flag will be 1 if overflow happened to the timer*/
#define TMR0_I_FLAG (TMR0IF)


/*enable interrupts flag*/
#define TMR0_ENABLE_INTERRUPT	(TMR0IE = 1)
/*enable global interrupt flag*/
#define GLOBAL_INTERRUPT_ENABLE	(GIE = 1)

/* CLOCK CONTROL BIT
 * TOCS = 0  enable internal instruction cycle clock(CLKO)
 * T0CS = 1  enable external clock from TOCKI pin
 */
#define TMR0_ENABLE_CLOCK		(T0CS = 0)
/* 
 * we don't have any input in RA4
 * be sure you don't use this pin if you need to stop the timer0
 */
#define TMR0_DISABLE_CLOCK		(T0CS = 1)  


/*
 * timer 1 register
 */
#define TMR1_REG    (TMR1)
/*this flag will be 1 if overflow happened to the timer*/
#define TMR1_I_FLAG (TMR1IF)


/*enable interrupts flag*/
#define TMR1_ENABLE_INTERRUPT	(TMR1IE = 1)

/* START timer BIT
 * TMR1ON = 0  stop timer 1
 * TMR1ON = 1  start timer 1
 */
#define TMR1_START_FLAG	(TMR1ON)

/*ENABLE INTERNAL CLOCK*/
#define TMR1_ENABLE_INTERNAL_CLOCK  (TMR1CS = 0)

/*OSCILLATOR SHUT OFF*/
#define TMR1_OSCILLATOR_SHUT_OFF     (T1OSCEN = 0)

/* PRESCALER
 * we will use 2 as pre scaler
 */
#define TMR1_PRESCALER      T1CKPS0 = 1;\
                            T1CKPS1 = 0

/*TIMER 1 END*/

/* define some standard types does not depend on the machine */
typedef unsigned char uint8;
typedef unsigned int  uint16;


#endif	/* XC_HEADER_TEMPLATE_H */

