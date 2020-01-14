/*
 * File:   Led.c
 * Author: Momen Ali
 *
 * Created on January 3, 2020, 1:20 AM
 */


#include"HW.h"
#include"Port.h"
#include"GPIO.h"
#include"Led.h"

uint8 LED_Init(LED_t led, LEDState_t state)
{
    /* initialize the led
     * set initial state
     * return true if success
     */
    uint8 ret = 1;   // return value if 1 success if 0 Failed
    switch(led)
    {
        case LED_ALARM:
            ret = GPIO_Init_Pin(&LED_PRESSURE_ALARM_DIR,LED_PRESSURE_ALARM_PIN,GPIO_OUT);
            break;
        default: ret = 0;
    }
    if(ret != 0)
    {
        LED_SetState(led,state);
    }

    return ret;
}
uint8 LED_GetState(LED_t led)
{
    /* return the led state */
    uint8 ret = 1;
    switch(led)
    {
        case LED_ALARM:
            ret = GPIO_Read_Pin(LED_PRESSURE_ALARM_DIR,LED_PRESSURE_ALARM_PIN);
            break;
        default:
            break;
    }

    return ret;
}
void LED_SetState(LED_t led, LEDState_t state)
{
    /* set the new state */
    switch(led)
    {
        case LED_ALARM:
            GPIO_Write_Pin(LED_PRESSURE_ALARM_PORT,LED_PRESSURE_ALARM_PIN,state);
            break;
        default:
            break;
    }
}
void LED_update(void)
{
    /* do nothing in this application */
}
void LED_Toggle(LED_t led)
{
    if(LED_GetState(led))
    {
        LED_SetState(led,LED_OFF);
    }
    else
    {
        LED_SetState(led,LED_ON);
    }
}
