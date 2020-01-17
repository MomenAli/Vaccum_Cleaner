/*
 * File:   SSD.c
 * Author: Momen Ali
 *
 * Created on January 5, 2020, 11:21 AM
 */
#include"Port.h"
#include"SSD.h"
#include"Timer_ZCD.h"

/*
 * define number of ticks need to update
 * MIN FREQ TO UPDATE SSD = 20 HZ    =>  MAX TIME = 1/20 = 50 ms 
 * MAX FREQ TO UPDATE SSD = 50 HZ    =>  MIN TIME = 1/50 = 20 ms
 * we have 3 SSD in this application
 * MAX TIME = MAX TIME PER SSD / NUMBER OF SSD = 50/3 = 16.7 ms
 * MIN TIME = MIN TIME PER SSD / NUMBER OF SSD = 20/3 = 6.7 ms
 * 10 ms 
 */
#define SSD_UPDATE_TICK (10)
/*
 * Buffer for the current displayed values
 */

void SSD_Disable(SSD_t s);
void SSD_Enable(SSD_t s);
void SSD_Data_write(void);




static SSD_Symbol_t Buffer[NUMBER_SSD];
/*
 * Buffer for the current displayed values
 */
static uint8 currentSSD = 0;


/*
 * LOOK UP TABLE
 * edit this table to add new symbols
 */ 
static uint8 SSD_LOT_ARR[] = 
{ 
    0b00001000,
    0b01001000,
    0b01001001,
    0b00000000
};


void SSD_Init(SSD_Symbol_t  sym,SSD_t ssd)
{
    //initialize to data port
    GPIO_Init_Port(&SSD_DATA_DIR,GPIO_OUT);
    
    switch(ssd)
    {
        case SSD_FIRST:
            //initialize First enable pin
            GPIO_Init_Pin(&SSD_FIRST_DIR,SSD_FIRST_PIN,GPIO_OUT);
            GPIO_Write_Pin(SSD_FIRST_PORT,SSD_FIRST_PIN,SSD_OFF);
            SSD_Set_Symbol(sym,SSD_FIRST);
            break;
        case SSD_SECOND:
            //initialize Second enable pin
            GPIO_Init_Pin(&SSD_SECOND_DIR,SSD_SECOND_PIN,GPIO_OUT);
            GPIO_Write_Pin(SSD_SECOND_PORT,SSD_SECOND_PIN,SSD_OFF);
            SSD_Set_Symbol(sym,SSD_SECOND);
            break;
        case SSD_THIRD: 
            //initialize Third enable pin
            GPIO_Init_Pin(&SSD_THIRD_DIR,SSD_THIRD_PIN,GPIO_OUT);
            GPIO_Write_Pin(SSD_THIRD_PORT,SSD_THIRD_PIN,SSD_OFF);
            SSD_Set_Symbol(sym,SSD_THIRD);
            break;
    }
}
void SSD_Set_Symbol(SSD_Symbol_t symbol,SSD_t index)
{
    // set the passed symbol in the passed index
    Buffer[index] = symbol;
}
void SSD_Update(void)
{
    /*
     * create static variable to hold time
     */
    static uint8 SSD_Time_Counter = 0; 
    SSD_Time_Counter += OS_TICK;
    //check if it's my tick 
    if(SSD_Time_Counter != SSD_UPDATE_TICK)
    {
        return;
    }
    SSD_Time_Counter = 0;
    
    // disable previous SSD
    SSD_Disable(currentSSD);
    //increment the current index
    currentSSD++;
    if(currentSSD > SSD_THIRD)currentSSD = 0;  
    // write data on port
    SSD_Data_write();
    //enable the current SSD
    SSD_Enable(currentSSD);
}

void SSD_Disable(SSD_t s)
{
    switch(s)
    {
        case SSD_FIRST:
            GPIO_Write_Pin(SSD_FIRST_PORT,SSD_FIRST_PIN,SSD_OFF);
            break;
        case SSD_SECOND:
            GPIO_Write_Pin(SSD_SECOND_PORT,SSD_SECOND_PIN,SSD_OFF);
            break;
        case SSD_THIRD:
            GPIO_Write_Pin(SSD_THIRD_PORT,SSD_THIRD_PIN,SSD_OFF);
            break;
        default:
            /*never go here*/;
    }
}

void SSD_Enable(SSD_t s)
{
    switch(s)
    {
        case SSD_FIRST:
            GPIO_Write_Pin(SSD_FIRST_PORT,SSD_FIRST_PIN,SSD_ON);
            break;
        case SSD_SECOND:
            GPIO_Write_Pin(SSD_SECOND_PORT,SSD_SECOND_PIN,SSD_ON);
            break;
        case SSD_THIRD:
            GPIO_Write_Pin(SSD_THIRD_PORT,SSD_THIRD_PIN,SSD_ON);
            break;
        default:
            /*never go here*/;
    }
}



void SSD_Data_write(void)
{
    // output the symbol in the data port
    GPIO_Write_Port(SSD_DATA_PORT,SSD_LOT_ARR[Buffer[currentSSD]]);
    
}
