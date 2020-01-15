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

void main(void) 
{
    VC_Init(MID_SPEED);
    Disp_Init();
    SW_Init();
    while(1)
    {
        __delay_ms(5);
        SW_Update();
        VC_Update();
        Disp_Update();
        SSD_Update();
    }
}
