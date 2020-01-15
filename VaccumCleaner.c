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

void main(void) 
{
    SSD_Init();
    while(1)
    {
        __delay_ms(1000);
        SSD_Set_Symbol(SSD_L_1,SSD_FIRST);
        SSD_Update();
        __delay_ms(1000);
        SSD_Set_Symbol(SSD_L_2,SSD_SECOND);
        SSD_Update();
        __delay_ms(1000);
        SSD_Set_Symbol(SSD_L_3,SSD_THIRD);
        SSD_Update();
        
    }
}
