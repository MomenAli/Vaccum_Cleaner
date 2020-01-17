/*
 * File:   Motor.c
 * Author: Momen Ali
 *
 * Created on January 16, 2020, 1:20 AM
 */

#include "Vacuum.h"
#include "Motor.h"
#include "GPIO.h"
#include "Port.h"
#include "Timer_ZCD.h"

/* */
#define FIRING_PULSE_WIDTH (100)
/* TIME BETWEEN TWO INVOKATION TO UPDATE FUNCTION*/
#define MOTOR_UPDATE_TICK (20)

/* initial value of the angle */
#define INITIAL_ANGLE (170)

/* kruz number to reduce the harmonics*/
#define KRUZ_CONST (10)

/* Time between adding 1 degree to the actual speed
 * on switching mode to achieve soft starting  
 */
#define SWITCHING_TIME (40)
/* count the number of ms elapsed between two addition process 
 * to actual angle in soft switching mode*/
static uint8 soft_switching_counter;


/* static variable speed target*/
static MOTOR_SPEED_t target_angle; 
/* static variable actual firing angle*/
static uint8 actual_angle;
/* static variable for motor state*/
static MOTOR_STATE_t motor_state;

void Mo_Init(MOTOR_SPEED_t m)
{
    // initialize motor pin 
    GPIO_Init_Pin(&MOTOR_DIR,MOTOR_PIN,GPIO_OUT);
    GPIO_Write_Pin(MOTOR_PORT,MOTOR_PIN,0);
    // initialize motor initial actual firing angle
    actual_angle = INITIAL_ANGLE;
    // initialize initial target angle
    target_angle = m;
    //initialize current state
    motor_state = MO_SWITCHING;
    // reset the switching counter
    soft_switching_counter = 0;
}
void Mo_SetSpeed(MOTOR_SPEED_t m)
{
    // if speed == target speed
    if(target_angle == m)return;
    /* true return*/   
    
    /*false
     * change mode to switching
     * set speed in target speed 
     */
    motor_state = MO_SWITCHING;
    target_angle = m;
    
}
void Mo_Update(void)
{
    /* create static variable to count time*/
    static uint8 motor_tick_counter = 10;   
    // increment motor tick counter
    motor_tick_counter += OS_TICK;
    // check if it's my tick
    if(motor_tick_counter != MOTOR_UPDATE_TICK) return;
    //reset counter
    motor_tick_counter = 0;
    // motor state machine
    switch(motor_state)
    {
        case MO_NORMAL:
            // normal mode
            //Kruz algorithm
            // if actual speed > target speed
            if(actual_angle > target_angle)
            {
                //true 
                //actual speed - 10
                actual_angle -= KRUZ_CONST;
            }
            else
            {
                //false
                //actual speed + 10
                actual_angle += KRUZ_CONST;
            }
            break;
    
        case MO_SWITCHING: 
            //switching mode
            //if actual angle = target angle
            if(actual_angle == target_angle){
                /* true
                 * actual speed +=5
                 * current mode = normal mode 
                 */ 
                actual_angle += 5;
                motor_state = MO_NORMAL;
            }
            else
            {
                //false
                // increment soft switch counter
                soft_switching_counter += MOTOR_UPDATE_TICK;
                // if soft switch counter = soft switching time
                if(soft_switching_counter == SWITCHING_TIME)
                {
                    /* true
                     * if target > actual 
                     * true increment actual
                     * false decrement actual
                     */
                    if(target_angle > actual_angle)
                    {
                        //increment angle
                        actual_angle++;
                    }
                    else
                    {
                        //decrement angle
                        actual_angle--;
                    }
                    // RESET COUNTER 
                    soft_switching_counter = 0;
                }
            }
            break;
        default:
            /*not supposed to come here*/
            break;
    }
    
}


uint8 Mo_Get_Actual_Angle(void)
{
    return actual_angle;
}
void Mo_generate_firing_pulse(void)
{
    // set motor pin high
    GPIO_Write_Pin(MOTOR_PORT,MOTOR_PIN,1);
    // delay for 100 us
    __delay_us(FIRING_PULSE_WIDTH);
    // reset motor pin
    GPIO_Write_Pin(MOTOR_PORT,MOTOR_PIN,0);
}