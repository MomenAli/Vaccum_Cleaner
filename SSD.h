

/* 
 * File:        ssd.h
 * Author:      Momen Ali
 * Comments:    header file of ssd driver
 * Revision history: 5/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __SSD_H
#define	__SSD_H


#include <xc.h> // include processor files - each processor file is guarded.  

/*
 * NUMBER OF SSDs IN THIS APPLICATION 
 * please edit this number if you want to increase 
 * or decrease the number of SSDs
 */
#define NUMBER_SSD (4)

/* 
 * SSD symbols
 * please add your symbol here in the opposite 
 * of it's index in LOT 
 */
typedef enum
{
    SSD_L_1 = 0,
    SSD_L_2,
    SSD_L_3,
    SSD_NULL
}SSD_Symbol_t;

/* 
 * SSD type
 * please add your type here in the opposite 
 * of it's index in Buffer 
 */
typedef enum
{
    SSD_FIRST,
    SSD_SECOND,
    SSD_THIRD,
}SSD_t;

/* SSD states */
typedef enum
{
    SSD_OFF = 0,
    SSD_ON = 1
}tSSD_State;

void SSD_Init(void);
void SSD_Set_Symbol(SSD_Symbol_t symbol,SSD_t index);
void SSD_Update(void);
#endif	/* XC_HEADER_TEMPLATE_H */

