/*
 * File:   SW.c
 * Author: Momen Ali
 *
 * Created on January 6, 2020, 11:18 AM
 */

#include "GPIO.h"
#include "Port.h"
#include "SW.h"
#include"Timer_ZCD.h"


/* SW voltage level */
#define SW_PRESSED_LEVEL        (0)
#define SW_RELEASED_LEVEL       (1)

/*
 * update the state depend on the previous state the state transition table
 */
void SW_UpdateState(SW_t sw);

/*
 * State Struct to hold data 
 * the state of the switch
 * 2 samples of the last situation of the switch
 *   _________________________________________________________________
 *  | state   | last sample (n-1) | present sample (n) |  next state  |
 *  |_________|___________________|____________________|______________|
 *  | pre rel |         1         |        1           |   release    |
 *  |_________|___________________|____________________|______________|
 *  | release |         0         |        0           |   pre pre    |
 *  |_________|___________________|____________________|______________|
 *  | pre pre |         0         |        0           |   pressed    |
 *  |_________|___________________|____________________|______________|
 *  | pressed |         1         |        1           |   pre rel    |
 *  |_________|___________________|____________________|______________|
 * 
 */

typedef struct 
{
    uint8 samples[2];
    uint8 state;
}SW_DATA_t;

/*
 * Create array of structs to hold data
 */
 static SW_DATA_t SW_DATA[SW_NUM];
 


void SW_Init(void)
{
     
    // initialize the the plus switch
    GPIO_Init_Pin(&SW_P_DIR,SW_P_PIN,GPIO_IN);
    SW_DATA[SW_PLUS].state = SW_RELEASED;
    SW_DATA[SW_PLUS].samples[0] = SW_RELEASED_LEVEL;
    SW_DATA[SW_PLUS].samples[1] = SW_RELEASED_LEVEL;
    // initialize the the Minus switch
    GPIO_Init_Pin(&SW_M_DIR,SW_M_PIN,GPIO_IN);
    SW_DATA[SW_MINUS].state = SW_RELEASED;
    SW_DATA[SW_MINUS].samples[0] = SW_RELEASED_LEVEL;
    SW_DATA[SW_MINUS].samples[1] = SW_RELEASED_LEVEL;
    // initialize the the SET switch
    GPIO_Init_Pin(&SW_PRESSURE_DIR,SW_PRESSURE_PIN,GPIO_IN);
    SW_DATA[SW_PRESSURE].state = SW_RELEASED;
    SW_DATA[SW_PRESSURE].samples[0] = SW_RELEASED_LEVEL;
    SW_DATA[SW_PRESSURE].samples[1] = SW_RELEASED_LEVEL;
    
}
uint8 SW_GetState(SW_t sw)
{
    uint8 ret =0;
    
    // return the state of the passed switch
    ret = SW_DATA[sw].state;
    
    return ret;
}
void SW_Update(void)
{
    /*
     * create static variable to hold time
     */
    static uint8 SW_Time_Counter = 0; 
    SW_Time_Counter += OS_TICK;
    //check if it's my tick 
    if(SW_Time_Counter != SW_UPDATE_TICK)
    {
        return;
    }
    SW_Time_Counter = 0;
    // update samples of plus switch
    SW_DATA[SW_PLUS].samples[0] = SW_DATA[SW_PLUS].samples[1];
    SW_DATA[SW_PLUS].samples[1] = GPIO_Read_Pin(SW_P_PORT,SW_P_PIN);
    // update state of plus switch
    SW_UpdateState(SW_PLUS);
    // update samples of minus switch
    SW_DATA[SW_MINUS].samples[0] = SW_DATA[SW_MINUS].samples[1];
    SW_DATA[SW_MINUS].samples[1] = GPIO_Read_Pin(SW_M_PORT,SW_M_PIN);
    // update state of MINUS switch
    SW_UpdateState(SW_MINUS);
    
    // update samples of set switch
    SW_DATA[SW_PRESSURE].samples[0] = SW_DATA[SW_PRESSURE].samples[1];
    SW_DATA[SW_PRESSURE].samples[1] = GPIO_Read_Pin(SW_PRESSURE_PORT,SW_PRESSURE_PIN);
    // update state of SET switch
    SW_UpdateState(SW_PRESSURE);
}

void SW_UpdateState(SW_t sw)
{
    /*
     *   _________________________________________________________________
     *  | state   | last sample (n-1) | present sample (n) |  next state  |
     *  |_________|___________________|____________________|______________|
     *  | pre rel |         1         |        1           |   release    |
     *  |_________|___________________|____________________|______________|
     *  | release |         0         |        0           |   pre pre    |
     *  |_________|___________________|____________________|______________|
     *  | pre pre |         0         |        0           |   pressed    |
     *  |_________|___________________|____________________|______________|
     *  | pressed |         1         |        1           |   pre rel    |
     *  |_________|___________________|____________________|______________|
     */
    
    // update the state of the passed switch
    switch(SW_DATA[sw].state)
    {
        
        case SW_PRE_RELEASED:
            if(SW_DATA[sw].samples[0] == SW_RELEASED_LEVEL && SW_DATA[sw].samples[1] == SW_RELEASED_LEVEL)
                SW_DATA[sw].state = SW_RELEASED;
            break;
        case SW_RELEASED:
            if(SW_DATA[sw].samples[0] == SW_PRESSED_LEVEL && SW_DATA[sw].samples[1] == SW_PRESSED_LEVEL)
                SW_DATA[sw].state = SW_PRE_PRESSED;
            break;
        case SW_PRE_PRESSED:
            if(SW_DATA[sw].samples[0] == SW_PRESSED_LEVEL && SW_DATA[sw].samples[1] == SW_PRESSED_LEVEL)
                SW_DATA[sw].state = SW_PRESSED;
            break;
        case SW_PRESSED:
            if(SW_DATA[sw].samples[0] == SW_RELEASED_LEVEL && SW_DATA[sw].samples[1] == SW_RELEASED_LEVEL)
                SW_DATA[sw].state = SW_PRE_RELEASED;
            break;
        default:
            
            break;
    }
}