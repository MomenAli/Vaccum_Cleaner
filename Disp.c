/*
 * File:   Disp.c
 * Author: Momen Ali
 *
 * Created on January 7, 2020, 9:10 AM
 */


#include <xc.h>

#include "HW.h"
#include "SSD.h"
#include "Vacuum.h"
/*
 * WE CAN MAKE TICK OF THE DISP = TICK CYCLE OF SSD 
 */
#define DISP_UPDATE_TICK  (20)




void Disp_Init(void)
{
    //initialize the SSDs
    SSD_Init(SSD_NULL,SSD_FIRST);
    SSD_Init(SSD_NULL,SSD_SECOND);
    SSD_Init(SSD_NULL,SSD_THIRD);
}
void Disp_Update(void)
{
     /*
     * create static variable to hold time
     */
    static uint8 DISP_Time_Counter = 10; 
    DISP_Time_Counter += OS_TICK;
    //check if it's my tick 
    if(DISP_Time_Counter != DISP_UPDATE_TICK)
    {
        return;
    }
    DISP_Time_Counter = 0;
    
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
    
}



