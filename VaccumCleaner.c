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

void main(void) 
{
    SSD_Init();
    VC_Init(MID_SPEED);
    SW_Init();
    while(1)
    {
        __delay_ms(5);
        SW_Update();
        VC_Update();
        switch(VC_GetSpeed())
        {
            case HIGH_SPEED:
                SSD_Set_Symbol(SSD_L_3,SSD_THIRD);
                SSD_Set_Symbol(SSD_L_2,SSD_SECOND);
                SSD_Set_Symbol(SSD_L_1,SSD_FIRST);
                break;
            case MID_SPEED:
                SSD_Set_Symbol(SSD_L_1,SSD_FIRST);
                SSD_Set_Symbol(SSD_L_2,SSD_SECOND);
                SSD_Set_Symbol(SSD_NULL,SSD_THIRD);
                break;
            case LOW_SPEED:
                SSD_Set_Symbol(SSD_L_1,SSD_FIRST);
                SSD_Set_Symbol(SSD_NULL,SSD_SECOND);
                SSD_Set_Symbol(SSD_NULL,SSD_THIRD);
                break;
        }
        SSD_Update();
    }
}
