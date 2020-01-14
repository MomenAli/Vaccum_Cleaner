
/* 
 * File:        Led.h
 * Author:      Momen Ali
 * Comments:    this file is driver for leds 
 * Revision history:    3/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __LED_H
#define	__LED_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "HW.h"

typedef enum
{
    LED_ALARM
}LED_t;

typedef enum{
    /*modify this enum depend on your connection (cathode or anode)*/
    LED_OFF = 0,
    LED_ON  = 1
}LEDState_t;

uint8 LED_Init(LED_t led, LEDState_t state);
uint8 LED_GetState(LED_t led);
void LED_SetState(LED_t led, LEDState_t state);
void LED_update(void);
void LED_Toggle(LED_t led);

#endif	/* XC_HEADER_TEMPLATE_H */

