/******************************************************************************
 *
 * LCD_Config.h
 *
 * Created: 3/4/2022 7:22:22 AM
 *  Author: Aya Sayed
 *
 *******************************************************************************/ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "GPIO.h"
#include <stdio.h>


//LCD HW Pins
#define RS								PIN_1
#define RW								PIN_2
#define E								PIN_3
#define LCD_CTRL_PORT					B		 //PORTB
#define LCD_DATA_PORT					A		 //PORTA

//LCD Commands
#define FOUR_BITS_DATA_MODE             0x02
#define LCD_2LINE_4BIT_MODE             0x28
#define LCD_2LINE_8BIT_MODE             0x38
#define LCD_BEGIN_AT_FIRST_RAW          0x80
#define LCD_BEGIN_AT_SECOND_RAW         0xC0
#define LCD_DISP_ON_CURSOR_ON		    0x0E
#define LCD_DISP_ON_CURSOR_BLINK	    0x0F
#define LCD_DISP_ON_BLINK	            0x0D
#define LCD_DISP_ON_CURSOR_OFF          0x0C
#define LCD_DISP_OFF_CURSOR_OFF         0x08
#define LCD_MOVE_DISP_RIGHT             0x1C
#define LCD_MOVE_DISP_LEFT              0x18
#define LCD_MOVE_CURSOR_RIGHT           0x14
#define LCD_MOVE_CURSOR_LEFT            0x10
#define LCD_ENTRY_MODE      		    0x06
#define CLEAR_COMMAND			    	0x01



#endif /* LCD_CONFIG_H_ */