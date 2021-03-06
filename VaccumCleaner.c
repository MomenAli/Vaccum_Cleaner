/*
 * File:   VaccumCleaner.c
 * Author: Momen Ali
 *
 * Created on January 14, 2020, 4:37 PM
 */

#include <xc.h>

#include "HW.h"
#include "SW.h"
#include "GPIO.h"
#include "Port.h"
#include "Led.h"
#include "SSD.h"
#include "Vacuum.h"
#include "Disp.h"
#include "Timer_ZCD.h"
#include "Timer1.h"
#include "Motor.h"

volatile uint8 ISR_FLAG;

void main(void) 
{
    ISR_FLAG = 0;
    VC_Init(MID_SPEED);
    TMR_Init();
    TMR_Start();
    TMR1_Init();
    Disp_Init();
    SW_Init();
    
    /*TEST CODE*/
    GPIO_Init_Pin(&GPIO_PORTC_DIR,PIN_4,GPIO_OUT);
    /*END TEST CODE*/
    while(1)
    {
        if(ISR_FLAG)
        {
            /*TEST CODE*/
            GPIO_Toggle_Pin(GPIO_PORTC_DATA,PIN_4);
            /*END TEST CODE*/
            //tasks 
            SSD_Update();
            SW_Update();
            Disp_Update();
            VC_Update();
            Mo_Update();
            ISR_FLAG = 0;
        }
    }
}

void __interrupt() Generic_ISR()
{
    /* if timer1 ISR
    */
    if(TMR1_CheckOverflow()){
        TMR1_ISR();
    }
    /*if timer0 ISR
    */
    if(TMR_CheckOverflow())
    {
        TMR0_ISR();
    }
}