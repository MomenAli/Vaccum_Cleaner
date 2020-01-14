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

void main(void) 
{
    SW_Init();
    LED_Init(LED_ALARM,LED_ON);
    while(1)
    {
        __delay_ms(5);
        SW_Update();
        if(SW_GetState(SW_PLUS) == SW_PRESSED)
        {
            LED_SetState(LED_ALARM,LED_OFF);
        }
        else
        {
            
            LED_SetState(LED_ALARM,LED_ON);
        }
    }
}
