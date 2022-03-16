/*****************************************************************************
 *
 * CFile1.c
 *
 * Created: 3/4/2022 7:20:16 AM
 *  Author: Aya Sayed
 *
 *****************************************************************************
                                 Includes
*******************************************************************************/
#include "LCD.h"


 /****************************************************************************
                         Functions Definitions
 ****************************************************************************/
void _delay_ms(uint32_t t)
{
	uint32_t i,j;
	for(i=0 ; i<t ; i++)
		for(j=0 ; j<256 ; j++);
}


void HAL_LCD_Clear_Screen()
{
	HAL_LCD_Send_Command(CLEAR_COMMAND);
}

void HAL_LCD_GOTO_XY(uint8_t line, uint8_t position)
{
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW + position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			HAL_LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW + position);
		}
	}
}

void HAL_LCD_INIT()
{
	_delay_ms(20);

	// Configure the control pins(E,RS,RW) as output pins
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_PinNumber = RS;     // RS
	PinConfig.GPIO_MODE = LCD_MODE;
    PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
    MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinConfig);

    PinConfig.GPIO_PinNumber = RW;     // RW
	PinConfig.GPIO_MODE = LCD_MODE;
	PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = E;     // E
	PinConfig.GPIO_MODE = LCD_MODE;
	PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinConfig);

    #if (DATA_BITS_MODE == 4)    // if LCD Data bits configuration mode is 4 bits
		// Configure the 4 bits of the data port as output pins
		PinConfig.GPIO_PinNumber = LCD_DATA_4;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_5;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_6;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_7;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		delay_ms(15);

		// initialize LCD in 4-bit mode
		HAL_LCD_Send_Command(FOUR_BITS_DATA_MODE);

		// use 2 line lcd + 4 bit Data Mode + 5*7 dot display Mode
		HAL_LCD_Send_Command(LCD_2LINE_4BIT_MODE);

	#elif (DATA_BITS_MODE == 8)  // if LCD Data bits configuration mode is 8 bits
		// Configure the data port as output pins
		PinConfig.GPIO_PinNumber = LCD_DATA_0;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_1;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_2;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_3;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_4;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_5;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_6;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		PinConfig.GPIO_PinNumber = LCD_DATA_7;
		PinConfig.GPIO_MODE = LCD_MODE;
		PinConfig.GPIO_OUTPUT_SPEED = LCD_SPEED;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinConfig);

		_delay_ms(15);

		HAL_LCD_Send_Command(CLEAR_COMMAND);

		// use 2 line lcd + 8 bit Data Mode + 5*7 dot display Mode
		HAL_LCD_Send_Command(LCD_2LINE_8BIT_MODE);

	#endif

	HAL_LCD_Send_Command(LCD_ENTRY_MODE);
	HAL_LCD_Send_Command(LCD_DISP_ON_CURSOR_BLINK);
	HAL_LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW);
}

void HAL_LCD_Send_Command( uint8_t command )
{
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS, FALSE);    // Configure the control pin RS command mode
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW, FALSE);    // Configure the control pin RW write mode

	_delay_ms(1);                                   // delay for processing Tdsw = 100ns
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, E, TRUE); // Disable LCD
	_delay_ms(50);                                   // delay for processing Tpw - Tdws = 190ns


	#if (DATA_BITS_MODE == 4)                           // if LCD Data bits configuration mode is 4 bits
	    // out the highest 4 bits of the required command to the data bus D4 --> D7
		MCAL_GPIO_WritePort(LCD_DATA_PORT, (uint8_t)(command & 0xF0));

		_delay_ms(1);                                   // delay for processing Tdsw = 100ns
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, E, FALSE); // Disable LCD
		_delay_ms(1);                                   // delay for processing Tpw - Tdws = 190ns
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, E, TRUE);  // Enable LCD
		_delay_ms(1);                                   // delay for processing Tdsw = 100ns

		// out the lowest 4 bits of the required command to the data bus D4 --> D7
		MCAL_GPIO_WritePort(LCD_DATA_PORT, (uint8_t)((command & 0x0F) << 4));

	#elif (DATA_BITS_MODE == 8)                         // if LCD Data bits configuration mode is 8 bits
		// out the required command to the data bus D0 --> D7

		MCAL_GPIO_WritePort(LCD_DATA_PORT, command);
	#endif

	_delay_ms(1);                                       // delay for processing Tas = 50ns
	/*MCAL_GPIO_WritePin(LCD_CONTROL_PORT, E, TRUE);      // Enable LCD
	_delay_ms(50);     */                                 // delay for processing Tpw - Tdws = 190ns
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, E, FALSE);     // Enable LCD
	_delay_ms(50);                                       // delay for processing Tdsw = 100ns
}

void HAL_LCD_Display_Character( uint8_t data )
{
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS, TRUE);     // Configure the control pin RS data mode
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW, FALSE);    // Configure the control pin RW write mode

	#if (DATA_BITS_MODE == 4)                           // if LCD Data bits configuration mode is 4 bits
		// out the highest 4 bits of the required data to the data bus D4 --> D7
		MCAL_GPIO_WritePort(LCD_DATA_PORT, (uint8_t)(data & 0xF0));

		_delay_ms(1);                                   // delay for processing Tdsw = 100ns
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, E, FALSE); // Enable LCD
		_delay_ms(1);                                   // delay for processing Tpw - Tdws = 190ns
		MCAL_GPIO_WritePin(LCD_CONTROL_PORT, E, TRUE);  // disable LCD
		_delay_ms(1);                                   // delay for processing Tdsw = 100ns

		// out the lowest 4 bits of the required data to the data bus D4 --> D7
		MCAL_GPIO_WritePort(LCD_DATA_PORT, (uint8_t)((data & 0x0F) << 4));

	#elif (DATA_BITS_MODE == 8)                         // if LCD Data bits configuration mode is 8 bits
		// out the required data to the data bus D0 --> D7
		MCAL_GPIO_WritePort(LCD_DATA_PORT, data);
	#endif

	_delay_ms(1);                                       // delay for processing Tas = 50ns
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, E, TRUE);      // Enable LCD
	_delay_ms(50);                                      // delay for processing Tpw - Tdws = 190ns
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, E, FALSE);     // Enable LCD
	_delay_ms(1);                                       // delay for processing Tdsw = 100ns
}

void HAL_LCD_display_String(char *Str)
{
	uint16_t count = 0;

	//Display character by character utill end the string
	while( *Str != '\0' )
	{
		HAL_LCD_Display_Character(*Str++);
		count++;
		if( count == 16 )
		{
			HAL_LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
		}
		else if (count == 32)
		{
			_delay_ms(1000);
			HAL_LCD_Send_Command(CLEAR_COMMAND);
			HAL_LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW);
			count = 0;
		}
	}
}

void HAL_LCD_Intger_Number( uint32_t Intger_Number )
{
	char str[7];

	sprintf(str,"%ld",Intger_Number);     // Adjust the formatting to your liking
	HAL_LCD_display_String( str );
}

void LCD_Real_Number( double Real_Number )
{
	char str[16];

	char *temp_sign = ( Real_Number<0 )? "-" : "";
	float temp_val  = ( Real_Number<0 )? -Real_Number : Real_Number;

	int   temp_Integer1 = temp_val;                   // Get the integer value
	float temp_fraction = temp_val - temp_Integer1;   // Get the fraction value
	int   temp_Integer2 = temp_fraction * 100;        // Turn into integer value

	// Print as parts
	// note that you need 0 padding for fractional bit
	sprintf(str,"%s%d.%02d",temp_sign,temp_Integer1,temp_Integer2);

	HAL_LCD_display_String(str);
}
