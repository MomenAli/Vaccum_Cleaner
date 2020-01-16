/*
 * File:   Motor.c
 * Author: Momen Ali
 *
 * Created on January 16, 2020, 1:20 AM
 */

#include "Vacuum.h"


/* static variable speed target*/

/* static variable actual firing angle*/

/* static variable for motor state*/

void Motor_Init(MOTOR_SPEET_t m)
{
    // initialize motor pin 
    
    // initialize motor initial actual firing angle
    
    // initialize initial target angle
    
    //initialize current state
    
}
void Motor_SetSpeed(MOTOR_SPEET_t m)
{
    // set speed in target speed
    
    // if speed  
    // change mode to switching
    
}
void Motor_Update(void)
{
    // normal mode
    
    //Kruz algorithm
    // if actual speed > target speed
    
    //true 
    //actual speed - 10
    
    //false
    //actual speed + 10
    
    
    //switching mode
    
    //if actual angle = target angle
    /* true
     * actual speed +=5
     * current mode = normal mode 
     */ 
    
    //false
    // increment soft switch counter
    
    // if soft switch counter = soft switching time
    
    /* true
     * if target > actual 
     * true increment actual
     * false decrement actual
     */
    
    // invoke firing function 
    
}
