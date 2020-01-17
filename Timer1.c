/*
 * File:   Timer1.c
 * Author: Momen Ali
 *
 * Created on January 16, 2020, 8:02 PM
 */
#include "Timer1.h"
#include "Motor.h"

void TMR1_Init(void)
{
   // initialize timer 1
   // set up timer prescaler
    TMR1_PRESCALER;
   // enable internal clock
    TMR1_ENABLE_INTERNAL_CLOCK;
   // shut off oscillator mode
    TMR1_OSCILLATOR_SHUT_OFF;
   //STOP TIMER 
    TMR1_STOP;
}
void TMR1_Start(uint16 degree)
{
     // update the clock flag to start
    TMR1_CLEAR_FLAG;
    // load the timer register with the tick
    TMR1_LOAD_REGISTER(degree);
    // enable the ISR
    TMR1_ENABLE_INTERRUPT;
    TMR1_PERIPHERAL_I_ENABLE;
    // start the timer
    TMR1_START;
}
void TMR1_Stop(void)
{
    // STOP TIMER 1
    TMR1_STOP;
}
uint8 TMR1_CheckOverflow(void)
{
    // CHECK IF OVERFLOW FLAG 
    return TMR1_GET_FLAG;
}
void TMR1_ISR(void)
{
    // Generate firing pulse
    Mo_generate_firing_pulse();
    //STOP TIMER 1
    TMR1_Stop();
    //clear flag
    TMR1_CLEAR_FLAG;
}
