

/* 
 * File:        Port
 * Author:      Momen Ali
 * Comments:    this file contain all the definitions related to schematic 
 * Revision history: 1/2/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __PORT_H
#define	__PORT_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "HW.h"
#include"GPIO.h"

/************************************port***********************************
 *                               description                               *
 * this header included all the configuration depend on your schematic     *
 * please change the configuration if you change board 3                   *                             *
 ***************************************************************************/

//sw NUMBER 1 PLUS SPEED
#define  SW_P_PORT GPIO_PORTB_DATA
#define  SW_P_DIR  GPIO_PORTB_DIR
#define  SW_P_PIN  PIN_0
//sw NUMBER 2 MINUS SPEED
#define  SW_M_PORT GPIO_PORTB_DATA
#define  SW_M_DIR  GPIO_PORTB_DIR
#define  SW_M_PIN  PIN_1
//sw NUMBER 3 PRESSURE SWITCH
#define  SW_PRESSURE_PORT GPIO_PORTB_DATA
#define  SW_PRESSURE_DIR  GPIO_PORTB_DIR
#define  SW_PRESSURE_PIN  PIN_2
//LED FOR PRESSURE ALARM  
#define  LED_PRESSURE_ALARM_PORT GPIO_PORTB_DATA
#define  LED_PRESSURE_ALARM_DIR  GPIO_PORTB_DIR
#define  LED_PRESSURE_ALARM_PIN  PIN_3


// SSD
#define SSD_DATA_PORT   GPIO_PORTD_DATA
#define SSD_DATA_DIR    GPIO_PORTD_DIR
// SSD FIRST
#define SSD_FIRST_PORT  GPIO_PORTB_DATA
#define SSD_FIRST_DIR   GPIO_PORTB_DIR
#define SSD_FIRST_PIN   PIN_7
// SSD TWO
#define SSD_SECOND_PORT GPIO_PORTB_DATA
#define SSD_SECOND_DIR  GPIO_PORTB_DIR
#define SSD_SECOND_PIN  PIN_6
// SSD THREE
#define SSD_THIRD_PORT  GPIO_PORTB_DATA
#define SSD_THIRD_DIR   GPIO_PORTB_DIR
#define SSD_THIRD_PIN   PIN_5


#endif	/* XC_HEADER_TEMPLATE_H */

