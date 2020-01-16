/*
 * File:   Timer1.c
 * Author: Momen Ali
 *
 * Created on January 16, 2020, 8:02 PM
 */
#include "Timer1.h"

void TMR1_Init(void)
{
   // initialize timer 1
   // set up timer prescaler
    
   // enable internal clock
    
   // shut off oscillator mode
    
   //STOP TIMER 
    
}
void TMR1_Start(uint8 degree)
{
     // update the clock flag to start
    TMR1_CLEAR_FLAG;
    // load the timer register with the tick
    TMR1_LOAD_REGISTER(degree);
    // enable the ISR
    TMR1_ENABLE_INTERRUPT;
    GLOBAL_INTERRUPT_ENABLE;
    // start the timer
    
}
void TMR1_Stop(void)
{
    // STOP TIMER 1
}
uint8 TMR1_CheckOverflow(void)
{
    // CHECK IF OVERFLOW FLAG 
    return TMR1_GET_FLAG;
}
void TMR1_ISR(void)
{
    // Generate firing pulse
    
    //STOP TIMER 1
}
