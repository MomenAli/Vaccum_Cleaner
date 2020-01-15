
/* 
 * File:        Vacuum.h
 * Author:      Momen Ali
 * Comments:    Drive the vacuum cleaner machine (pure software module) 
 * Revision history: 15/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __VACUUM_H
#define	__VACUUM_H

#include <xc.h> // include processor files - each processor file is guarded.  

/*
 * enum represent the speed and the Target firing angle of this speed
 * 
 * please edit this enum only if you need to 
 * modify the speed levels or firing angles 
 */
typedef enum
{
    LOW_SPEED = 140,
    MID_SPEED = 90,
    HIGH_SPEED = 10
}MOTOR_SPEET_t;

void VC_Init(void);
MOTOR_SPEET_t VC_GetSpeed(void);
void VC_Update();

#endif	/* XC_HEADER_TEMPLATE_H */

