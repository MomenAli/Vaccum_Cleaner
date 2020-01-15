/*
 * File:   Vacuum.c
 * Author: Momen Ali
 *
 * Created on January 15, 2020, 1:34 PM
 */

#include "Vacuum.h"
#include "SW.h"
#include "HW.h"
#include "Led.h"


/* periodic tick for update */
#define VC_UPDATE_TICK (20) 

/* create static variable of speed type */
static MOTOR_SPEET_t motor_speed;

/*  function to handle switches state change prototype*/
static void Switch_Event_Handler(void);

/* Number of m seconds to triger the event of pressure switch*/
#define PRESSURE_MSECONDS_TRIGER (30000) 

/* 
 * create static variable to count 30 seconds
 * 
 */
static uint16 pressure_sw_counter;

void VC_Init(MOTOR_SPEET_t speed)
{
    //initialize speed type (enum)  variable
    motor_speed = speed;
    //set initial speed of the motor (MOTOR Module)
    /* NOT DONE */
    
    /* initialize alarm led*/
    LED_Init(LED_ALARM,LED_OFF);
    //initialize the counter of pressure switch
    pressure_sw_counter = 0;
}
MOTOR_SPEET_t VC_GetSpeed(void)
{  
    // return the current speed of the vacuum cleaner
    return motor_speed;
}
void VC_Update(void)
{
    static uint8 VC_TICK_COUNTER = 0;
    VC_TICK_COUNTER += OS_TICK;
    //return if not my tick
    if(VC_TICK_COUNTER != VC_UPDATE_TICK)
        return;
    VC_TICK_COUNTER = 0;
    
    //handle the switch state change
    /*
     * update the speed depend on the state machine
     * 
     * If (+) is pre=pressed & speed is not max, speed increases by 1 step
     * If (-) is pre=pressed & speed is not min, speed decreases by 1 step
     * If(P) is pressed & press time == 30 seconds & speed is not min, speed decreases by 1 step. 
     * 
     */
    Switch_Event_Handler();
    
    // set the motor speed at motor module
    /* NOT DONE */
    
}

static void Switch_Event_Handler(void)
{
    //plus switch
    /*
     * If (+) is pre=pressed & speed is not max, speed increases by 1 step
     */
    if(SW_GetState(SW_PLUS) == SW_PRE_PRESSED && motor_speed != HIGH_SPEED)
    {
        // change the speed (+)
        switch(motor_speed)
        {
            case LOW_SPEED:
                motor_speed = MID_SPEED;
                break;
            case MID_SPEED:
                motor_speed = HIGH_SPEED;
                break;
            default:
                /*not suppose to reach this point*/
                break;
        }
    }
    
    //minus switch
    /*
     * If (-) is pre=pressed & speed is not min, speed decreases by 1 step
     */
    if((SW_GetState(SW_MINUS) == SW_PRE_PRESSED) && (motor_speed != LOW_SPEED))
    {
        // change the speed (-)
        
        switch(motor_speed)
        {
            case MID_SPEED:
                motor_speed = LOW_SPEED; 
                break;
            case HIGH_SPEED:
                motor_speed = MID_SPEED;
                break;
            default:
                /*not suppose to reach this point*/
                break;
        }
    }
    //pressure switch
    /*
     * If(P) is pressed & press time == 30 seconds & speed is not min, speed decreases by 1 step. 
     */
    if(SW_GetState(SW_PRESSURE) == SW_PRESSED && (motor_speed != LOW_SPEED))
    {
        // increment counter 
        pressure_sw_counter += VC_UPDATE_TICK;
        /* 
         * check if 30 seconds passed
         */
        if( pressure_sw_counter == PRESSURE_MSECONDS_TRIGER )
        {
            //if true speed change (-)

            switch(motor_speed)
            {
                case MID_SPEED:
                    motor_speed = LOW_SPEED; 
                    break;
                case HIGH_SPEED:
                    motor_speed = MID_SPEED;
                    break;
                default:
                    /*not suppose to reach this point*/
                    break;
            }
            // reset counter
            pressure_sw_counter = 0;
        }
        // turn on Alarm led
        LED_SetState(LED_ALARM,LED_ON);
    }
    else
    {
        pressure_sw_counter = 0;
        // turn off Alarm led 
        LED_SetState(LED_ALARM,LED_OFF);   
    }
}