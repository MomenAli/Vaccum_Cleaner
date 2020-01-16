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
#include "Timer1.h"
#include "Motor.h"

static uint16 tempCounter = 0;

void TMR_Init(void)
{
    // initialize the timer
    // set up the timer pre scaler
    TMR_PRESCALER_256;
    // stop timer
    TMR0_DISABLE_CLOCK;
   
}



void TMR0_ISR(void) 
{
    // start firing timer (TIMER1)
    TMR1_Start(Mo_Get_Actual_Angle());
    // reset the overflow flag
    TMR0_CLEAR_FLAG;
    // load the timer register with the tick
    TMR_LOAD_REGISTER(ZCD_PERIOD_TICK_NUM);
    // set flag to process tasks
    ISR_FLAG = 1;
}
void TMR_Start(void)
{
    // update the clock flag to start
    TMR0_CLEAR_FLAG;
    // load the timer register with the tick
    TMR_LOAD_REGISTER(ZCD_PERIOD_TICK_NUM);
    // enable the ISR
    TMR0_ENABLE_INTERRUPT;
    GLOBAL_INTERRUPT_ENABLE;
    // enable the clock
    TMR0_ENABLE_CLOCK;
}
void TMR_Stop(void)
{
    // update the clock flag to stop
    TMR0_DISABLE_CLOCK;
}
uint8 TMR_CheckOverflow(void)
{
    // return the overflow flag
    return TMR0_GET_FLAG;
}




