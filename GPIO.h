
/* 
 * File:        GPIO.h
 * Author:      Momen Ali
 * Comments:    this file contain definitions and functions of GPIO
 * Revision history: 3/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __GPIO_H
#define	__GPIO_H

#include <xc.h> // include processor files - each processor file is guarded.  


#include "HW.h"

#define PIN_0 (0)
#define PIN_1 (1)
#define PIN_2 (2)
#define PIN_3 (3)
#define PIN_4 (4)
#define PIN_5 (5)
#define PIN_6 (6)
#define PIN_7 (7)

/* GPIO port operations */
#define GPIO_Set_Dir_Port(DIRECTION_REG , DIRECTION)    ((DIRECTION_REG)=(DIRECTION)?(~0):(0))
#define GPIO_Write_Port(DATA_REG , DATA)                ((DATA_REG)=(DATA))
#define GPIO_Read_Port(DATA_REG)                        (DATA_REG)


/* GPIO pin operations */
#define GPIO_Set_Dir_Pin(DIRECTION_REG ,PIN, DIRECTION)     ((DIRECTION_REG)=(DIRECTION_REG & ~(1<<PIN))|(DIRECTION<<PIN))
#define GPIO_Write_Pin(DATA_REG ,PIN, DATA)                 ((DATA_REG)=(DATA_REG & ~(1<<PIN))|(DATA<<PIN))
#define GPIO_Toggle_Pin(DATA_REG ,PIN)                      ((DATA_REG)=(DATA_REG ^(1<<PIN)))
#define GPIO_Read_Pin(DATA_REG ,PIN)                        ((DATA_REG >> PIN)& 1)



uint8 GPIO_Init_Port(uint8 * DirRegAddress/*direction register address*/,uint8 dir/* DIRECTION*/);
uint8 GPIO_Init_Pin(uint8 * DirRegAddress/*direction register address*/,uint8 pin_number,uint8 dir/* I/O*/);



#endif	/* XC_HEADER_TEMPLATE_H */

