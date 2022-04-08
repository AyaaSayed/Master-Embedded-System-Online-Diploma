/******************************************************************************
 *
 * LCD.c
 *
 * Created: 3/4/2022 7:20:16 AM
 *  Author: Aya Sayed
 *
 ********************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
#include "LCD.h"

void _delay_ms(uint32 time)
{
	for (volatile uint32 i=0 ; i<time ; i++)
		for (volatile uint8 j=0 ; j<255 ; j++);
		
	return;
}

void LCD_Clear_Screen()
{
	LCD_Send_Command(CLEAR_COMMAND);
}

void LCD_INIT()
{
	_delay_ms(20);
	// Configure the control pins(E,RS,RW) as output pins
	//LCD_CTRL_DDR  |= (1<<E) | (1<<RS) | (1<<RW);
	vINTIAL_PIN_OUTPUT(LCD_CTRL_PORT,  E, OUT_ON);
	vINTIAL_PIN_OUTPUT(LCD_CTRL_PORT, RS, OUT_ON);
	vINTIAL_PIN_OUTPUT(LCD_CTRL_PORT, RW, OUT_ON);
	
    #if (DATA_BITS_MODE == 4)    // if LCD Data bits configuration mode is 4 bits
		#ifdef UPPER_PORT_PINS
		//LCD_DATA_DDR |= 0xF0;    // Configure the highest 4 bits of the data port as output pins
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_4, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_5, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_6, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_7, OUT_ON);
		#else
		//LCD_DATA_DDR |= 0x0F;    // Configure the lowest 4 bits of the data port as output pins
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_0, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_1, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_2, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_3, OUT_ON);
		#endif
		
		// initialize LCD in 4-bit mode
		LCD_Send_Command(FOUR_BITS_DATA_MODE);
		
		// use 2 line lcd + 4 bit Data Mode + 5*7 dot display Mode
		LCD_Send_Command(LCD_2LINE_4BIT_MODE);
		
	#elif (DATA_BITS_MODE == 8)  // if LCD Data bits configuration mode is 8 bits
		//LCD_DATA_DDR = 0xFF;     // Configure the data port as output pins
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_0, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_1, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_2, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_3, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_4, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_5, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_6, OUT_ON);
		vINTIAL_PIN_OUTPUT(LCD_DATA_PORT, PIN_7, OUT_ON);
		
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
	//LCD_CTRL_PORT &=~ (1<<RS) | (1<<RW);  // Configure the control pin RS command mode, RW write mode
	vWRITE_PIN(LCD_CTRL_PORT, RS, FALSE);
	vWRITE_PIN(LCD_CTRL_PORT, RW, FALSE);
	_delay_ms(1);                         // delay for processing Tas = 50ns
	//LCD_CTRL_PORT |= (1<<E);              // Enable LCD
	vWRITE_PIN(LCD_CTRL_PORT, E, TRUE);
	_delay_ms(1);                         // delay for processing Tpw - Tdws = 190ns
	
	#if (DATA_BITS_MODE == 4)             // if LCD Data bits configuration mode is 4 bits
	    // out the highest 4 bits of the required command to the data bus D4 --> D7
		#ifdef UPPER_PORT_PINS
		//LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command & 0xF0);
		vWRITE_PORT(LCD_DATA_PORT, ((uREAD_PORT(LCD_DATA_PORT) & 0x0F) | (command & 0xF0)));
		#else
		//LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((command & 0xF0) >> 4));
		vWRITE_PORT(LCD_DATA_PORT, ((uREAD_PORT(LCD_DATA_PORT) & 0xF0) | ((command & 0xF0) >> 4)));
		#endif
		
		_delay_ms(1);                     // delay for processing Tdsw = 100ns
		//LCD_CTRL_PORT &=~ (1<<E);         // disable LCD
		vWRITE_PIN(LCD_CTRL_PORT, E, FALSE);
		_delay_ms(1);                     // delay for processing Th = 13ns
		//LCD_CTRL_PORT |= (1<<E);          // Enable LCD
		vWRITE_PIN(LCD_CTRL_PORT, E, TRUE); 
		_delay_ms(1);                     // delay for processing Tpw - Tdws = 190ns 
		
		// out the lowest 4 bits of the required command to the data bus D4 --> D7
		#ifdef UPPER_PORT_PINS
		//LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((command & 0x0F) << 4);
		vWRITE_PORT(LCD_DATA_PORT, ((uREAD_PORT(LCD_DATA_PORT) & 0x0F) | ((command & 0x0F) << 4)));
		#else
		//LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (command & 0x0F);
		vWRITE_PORT(LCD_DATA_PORT, ((uREAD_PORT(LCD_DATA_PORT) & 0xF0) | (command & 0x0F)));
		#endif
		
	#elif (DATA_BITS_MODE == 8)           // if LCD Data bits configuration mode is 8 bits
		// out the required command to the data bus D0 --> D7
		//LCD_DATA_PORT = command;
		vWRITE_PORT(LCD_DATA_PORT, command);
		
	#endif
	_delay_ms(1);                     // delay for processing Tdsw = 100ns
	//LCD_CTRL_PORT &=~ (1<<E);         // disable LCD E=0
	vWRITE_PIN(LCD_CTRL_PORT, E, FALSE);
	_delay_ms(1);                     // delay for processing Th = 13ns	
}

void LCD_Display_Character( char data )
{
	//LCD_CTRL_PORT |= (1<<RS);             // Configure the control pin RS data mode
	//LCD_CTRL_PORT &=~(1<<RW);             // Configure the control pin RW write mode
	vWRITE_PIN(LCD_CTRL_PORT, RS, TRUE);
	vWRITE_PIN(LCD_CTRL_PORT, RW, FALSE);
	_delay_ms(1);                         // delay for processing Tas = 50ns
	//LCD_CTRL_PORT |= (1<<E);              // Enable LCD
	vWRITE_PIN(LCD_CTRL_PORT, E, TRUE); 
	_delay_ms(1);                         // delay for processing Tpw - Tdws = 190ns
	
	#if (DATA_BITS_MODE == 4)             // if LCD Data bits configuration mode is 4 bits
	// out the highest 4 bits of the required data to the data bus D4 --> D7
	#ifdef UPPER_PORT_PINS
	//LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (data & 0xF0);
	vWRITE_PORT(LCD_DATA_PORT, ((uREAD_PORT(LCD_DATA_PORT) & 0x0F) | (data & 0xF0)));
	#else
	//LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | ((data & 0xF0) >> 4));
	vWRITE_PORT(LCD_DATA_PORT, ((uREAD_PORT(LCD_DATA_PORT) & 0xF0) | ((data & 0xF0) >> 4)));
	#endif
	
	_delay_ms(1);                     // delay for processing Tdsw = 100ns
	//LCD_CTRL_PORT &=~ (1<<E);         // disable LCD
	vWRITE_PIN(LCD_CTRL_PORT, E, FALSE);
	_delay_ms(1);                     // delay for processing Th = 13ns
	//LCD_CTRL_PORT |= (1<<E);          // Enable LCD
	vWRITE_PIN(LCD_CTRL_PORT, E, TRUE);
	_delay_ms(1);                     // delay for processing Tpw - Tdws = 190ns
	
	// out the lowest 4 bits of the required data to the data bus D4 --> D7
	#ifdef UPPER_PORT_PINS
	//LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | ((data & 0x0F) << 4);
	vWRITE_PORT(LCD_DATA_PORT, ((uREAD_PORT(LCD_DATA_PORT) & 0x0F) | ((data & 0x0F) << 4)));
	#else
	//LCD_DATA_PORT = (LCD_DATA_PORT & 0xF0) | (data & 0x0F);
	vWRITE_PORT(LCD_DATA_PORT, ((uREAD_PORT(LCD_DATA_PORT) & 0xF0) | (data & 0x0F)));
	#endif
	
	#elif (DATA_BITS_MODE == 8)           // if LCD Data bits configuration mode is 8 bits
	// out the required data to the data bus D0 --> D7
	//LCD_DATA_PORT = data;
	vWRITE_PORT(LCD_DATA_PORT, data);
	
	#endif
	_delay_ms(1);                     // delay for processing Tdsw = 100ns
	//LCD_CTRL_PORT &=~ (1<<E);         // disable LCD E=0
	vWRITE_PIN(LCD_CTRL_PORT, E, FALSE);
	_delay_ms(1);                     // delay for processing Th = 13ns
}

void LCD_display_String( char* Str )
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

void LCD_Intger_Number( uint32 Intger_Number )
{
	char str[7];
	
	sprintf(str,"%ld",Intger_Number);     // Adjust the formatting to your liking
	LCD_display_String((uint8*)str);
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
	
	LCD_display_String((uint8*)str);
}

void LCD_goto_xy(int line, int position)
{
	if(line == 1)
	if(position >= 0 && position < 16)
	LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW + position);
	
	else if (line == 2)
	if(position >= 0 && position < 16)
	LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW + position);
}