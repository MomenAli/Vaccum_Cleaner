
/* 
 * File:        Motor.h
 * Author:      Momen Ali
 * Comments:    motor driver module 
 *              change speed of motor depend on speed selected
 *              soft switching between speed to protect the motor  
 * Revision history: 15/1/2020 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>

#include "Vacuum.h" // include processor files - each processor file is guarded.  

typedef enum
{
    MO_NORMAL,
    MO_SWITCHING        
}MOTOR_STATE_t;


void Motor_Init(MOTOR_SPEED_t);
void Motor_SetSpeed(MOTOR_SPEED_t);
void Motor_Update(void);


#endif	/* XC_HEADER_TEMPLATE_H */

