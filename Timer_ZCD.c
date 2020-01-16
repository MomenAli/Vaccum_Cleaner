/*
 * File:   Timer.c
 * Author: Momen Ali
 *
 * Created on January 16, 2020, 6:12 PM
 */


#include <xc.h>

#include "HW.h"
#include "GPIO.h"
#include "Port.h"
#include "SW.h"
#include "Disp.h"
#include "SSD.h"
#include"Timer_ZCD.h"

static uint16 tempCounter = 0;

void TMR_Init(void)
{
    // initialize the timer
    // set up the timer pre scaler
    TMR_PRESCALER_256;
    // stop timer
    TMR_DISABLE_CLOCK;
   
}



void TMR0_ISR() 
{
    // start firing timer
    
    // reset the overflow flag
    TMR_CLEAR_FLAG;
    // load the timer register with the tick
    TMR_LOAD_REGISTER(OS_TICK);
    // call tasks
    
    SSD_Update();
    SW_Update();
    Disp_Update();
}
void TMR_Start(void)
{
    // update the clock flag to start
    TMR_CLEAR_FLAG;
    // load the timer register with the tick
    TMR_LOAD_REGISTER(ZCD_PERIOD_TICK_NUM);
    // enable the ISR
    TMR_ENABLE_INTERRUPT;
    GLOBAL_INTERRUPT_ENABLE;
    // enable the clock
    TMR_ENABLE_CLOCK;
}
void TMR_Stop(void)
{
    // update the clock flag to stop
    TMR_DISABLE_CLOCK;
}
uint8 TMR_CheckOverflow(void)
{
    // return the overflow flag
    return TMR_GET_FLAG;
}

void __interrupt() Generic_ISR()
{
    /* if timer1
    */
    
    /*if timer0 
    */
}


