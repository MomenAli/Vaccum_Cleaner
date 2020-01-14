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

void main(void) 
{
    SW_Init();
    GPIO_Init_Pin(&LED_PRESSURE_ALARM_DIR,LED_PRESSURE_ALARM_PIN,GPIO_OUT);
    while(1)
    {
        __delay_ms(1000);
        SW_Update();
        if(SW_GetState(SW_PLUS) == SW_PRESSED)
        {
            GPIO_Write_Pin(LED_PRESSURE_ALARM_PORT,LED_PRESSURE_ALARM_PIN,0);
        }
        else
        {
            GPIO_Write_Pin(LED_PRESSURE_ALARM_PORT,LED_PRESSURE_ALARM_PIN,1);
        }
        
    }
}
