/******************************************************************************
 *
 * CFile1.c
 *
 * Created: 3/4/2022 7:20:16 AM
 *  Author: Aya Sayed
 *
 ********************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
#include "LCD.h"

void LCD_Clear_Screen()
{
	LCD_Send_Command(CLEAR_COMMAND);
}

void LCD_INIT()
{
	_delay_ms(20);
	// Configure the control pins(E,RS,RW) as output pins
	LCD_CTRL_DDR  |= (1<<E) | (1<<RS) | (1<<RW);
	
    #if (DATA_BITS_MODE == 4)    // if LCD Data bits configuration mode is 4 bits
		#ifdef UPPER_PORT_PINS
		LCD_DATA_DDR |= 0xF0;    // Configure the highest 4 bits of the data port as output pins
		#else
		LCD_DATA_DDR |= 0x0F;    // Configure the lowest 4 bits of the data port as output pins
		#endif
		
		// initialize LCD in 4-bit mode
		LCD_Send_Command(FOUR_BITS_DATA_MODE);
		
		// use 2 line lcd + 4 bit Data Mode + 5*7 dot display Mode
		LCD_Send_Command(LCD_2LINE_4BIT_MODE);
		
	#elif (DATA_BITS_MODE == 8)  // if LCD Data bits configuration mode is 8 bits
		LCD_DATA_DDR = 0xFF;     // Configure the data port as output pins
		
		// use 2 line lcd + 8 bit Data Mode + 5*7 dot display Mode
		LCD_Send_Command(LCD_2LINE_8BIT_MODE);
		
	#endif
	
	LCD_Send_Command(LCD_ENTRY_MODE);
	LCD_Send_Command(CLEAR_COMMAND);
	LCD_Send_Command(LCD_DISP_ON_CURSOR_BLINK);
	LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW);
}

void LCD_Send_Command( uint8 command )
{
	LCD_CTRL_PORT &=~ (1<<RS) | (1<<RW);  // Configure the control pin RS command mode, RW write mode
	_delay_ms(1);                         // delay for processing Tas = 50ns
	LCD_CTRL_PORT |= (1<<E);              // Enable LCD
	_delay_ms(1);                         // delay for processing Tpw - Tdws = 190ns
	
	#if (DATA_BITS_MODE == 4)             // if LCD Data bits configuration mode is 4 bits
	    // out the highest 4 bits of the required command to the data bus D4 --> D7
		#ifdef UPPER_PORT_PINS
		LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command & 0xF0);
		#else
		LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((command & 0xF0) >> 4));
		#endif
		
		_delay_ms(1);                     // delay for processing Tdsw = 100ns
		LCD_CTRL_PORT &=~ (1<<E);         // disable LCD
		_delay_ms(1);                     // delay for processing Th = 13ns
		LCD_CTRL_PORT |= (1<<E);          // Enable LCD 
		_delay_ms(1);                     // delay for processing Tpw - Tdws = 190ns 
		
		// out the lowest 4 bits of the required command to the data bus D4 --> D7
		#ifdef UPPER_PORT_PINS
		LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((command & 0x0F) << 4);
		#else
		LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (command & 0x0F);
		#endif

		_delay_ms(1);                     // delay for processing Tdsw = 100ns
		LCD_CTRL_PORT &=~ (1<<E);         // disable LCD E=0
		_delay_ms(1);                     // delay for processing Th = 13ns
		
	#elif (DATA_BITS_MODE == 8)           // if LCD Data bits configuration mode is 8 bits
		// out the required command to the data bus D0 --> D7
		LCD_DATA_PORT = command;
		_delay_ms(1);                     // delay for processing Tdsw = 100ns
		LCD_CTRL_PORT &=~ (1<<E);         // disable LCD
		_delay_ms(1);                     //delay for processing Th = 13ns
		
	#endif	
}

void LCD_Display_Character( uint8 data )
{
	LCD_CTRL_PORT |= (1<<RS);             // Configure the control pin RS data mode
	LCD_CTRL_PORT &=~(1<<RW);             // Configure the control pin RW write mode
	_delay_ms(1);                         // delay for processing Tas = 50ns
	LCD_CTRL_PORT |= (1<<E);              // Enable LCD
	_delay_ms(1);                         // delay for processing Tpw - Tdws = 190ns
	
	#if (DATA_BITS_MODE == 4)             // if LCD Data bits configuration mode is 4 bits
	// out the highest 4 bits of the required data to the data bus D4 --> D7
	#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (data & 0xF0);
	#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((data & 0xF0) >> 4));
	#endif
	
	_delay_ms(1);                     // delay for processing Tdsw = 100ns
	LCD_CTRL_PORT &=~ (1<<E);         // disable LCD
	_delay_ms(1);                     // delay for processing Th = 13ns
	LCD_CTRL_PORT |= (1<<E);          // Enable LCD
	_delay_ms(1);                     // delay for processing Tpw - Tdws = 190ns
	
	// out the lowest 4 bits of the required data to the data bus D4 --> D7
	#ifdef UPPER_PORT_PINS
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((data & 0x0F) << 4);
	#else
	LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (data & 0x0F);
	#endif

	_delay_ms(1);                     // delay for processing Tdsw = 100ns
	LCD_CTRL_PORT &=~ (1<<E);         // disable LCD E=0
	_delay_ms(1);                     // delay for processing Th = 13ns
	
	#elif (DATA_BITS_MODE == 8)           // if LCD Data bits configuration mode is 8 bits
	// out the required data to the data bus D0 --> D7
	LCD_DATA_PORT = data;
	_delay_ms(1);                     // delay for processing Tdsw = 100ns
	LCD_CTRL_PORT &=~ (1<<E);         // disable LCD
	_delay_ms(1);                     //delay for processing Th = 13ns
	
	#endif
}

void LCD_display_String( const char *Str )
{
	uint16_t count = 0;
	
	//Display character by character utill end the string
	while( *Str != '\0' )
	{
		LCD_Display_Character( *Str++ );
		count++;
		if( count == 16 )
		{
			LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
		}
		else if (count == 32)
		{
			_delay_ms(1000);
			LCD_Send_Command(CLEAR_COMMAND);
			LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW);
			count = 0;
		}
	}
}

void LCD_Intger_Number( int32 Intger_Number )
{
	char str[7];
	
	sprintf(str,"%ld",Intger_Number);     // Adjust the formatting to your liking
	LCD_display_String( str );
}

void LCD_Real_Number( double Real_Number )
{
	char str[16];
	
	char *temp_sign = ( Real_Number<0 )? "-" : "";
	float temp_val  = ( Real_Number<0 )? -Real_Number : Real_Number;
	
	int   temp_Integer1 = temp_val;                   // Get the integer value
	float temp_fraction = temp_val - temp_Integer1;   // Get the fraction value
	int   temp_Integer2 = temp_fraction * 100;      // Turn into integer value
	
	// Print as parts
	// note that you need 0 padding for fractional bit
	sprintf(str,"%s%d.%02d",temp_sign,temp_Integer1,temp_Integer2);
	
	LCD_display_String(str);
}