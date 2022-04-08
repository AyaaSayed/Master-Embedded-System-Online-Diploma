/******************************************************************************
 *
 * LCD.h
 *
 * Created: 3/4/2022 7:20:41 AM
 *  Author: Aya Sayed
 *
 *******************************************************************************/
 

#ifndef LCD_H_
#define LCD_H_

#include "LCDConfig.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
// LCD Data bits mode configuration
#define DATA_BITS_MODE 4

// Use higher 4 bits in the data port
#if (DATA_BITS_MODE == 4)
#define  UPPER_PORT_PINS
#endif

/*******************************************************************************
                           Functions Prototypes                                   
 *******************************************************************************/
void LCD_INIT();
void LCD_Clear_Screen();
void LCD_Send_Command( uint8 command );  
void LCD_Display_Character( char data );
void LCD_display_String( char* Str );
void LCD_Intger_Number( uint32 Intger_Number );
void LCD_Real_Number( double Intger_Number );
void LCD_goto_xy(int line, int position);

#endif /* LCD_H_ */