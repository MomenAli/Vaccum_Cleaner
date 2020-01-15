

/* 
 * File:        Disp.h 
 * Author:      Momen Ali   
 * Comments:    this is the layer connect between SSD and Vacuum brain 
 *              it knows how to show different levels of speed 
 * Revision history: 15/1/2020
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __DISP_H
#define	__DISP_H

#include <xc.h> // include processor files - each processor file is guarded.  

void Disp_Init(void);
void Disp_Update(void);

#endif	/* XC_HEADER_TEMPLATE_H */

