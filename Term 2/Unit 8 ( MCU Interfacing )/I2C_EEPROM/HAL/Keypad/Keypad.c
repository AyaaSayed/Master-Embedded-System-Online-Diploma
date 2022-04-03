/******************************************************************************
 *
 * keypad.c
 *
 * Created: 3/4/2022 6:28:35 PM
 *  Author: Aya Sayed
 *
 *******************************************************************************/

#include "Keypad.h"

static const unsigned char g_Keypad_Mapping[4][4] = {{'1','2','3','/'},
													 {'4','5','6','*'},
													 {'7','8','9','-'},
													 {'C','0','=','+'}};


/*******************************************************************************
                           Generic Functions
*******************************************************************************/
uint8_t INPUT_IS_STILL_VALID()
{
	return (MCAL_GPIO_ReadPin(KEYPAD_PORT, COLUM0)&&
			MCAL_GPIO_ReadPin(KEYPAD_PORT, COLUM1)&&
			MCAL_GPIO_ReadPin(KEYPAD_PORT, COLUM2)&&
			MCAL_GPIO_ReadPin(KEYPAD_PORT, COLUM3));
}

/*******************************************************************************
                   APIs Supported by "HAL KEYPAD DRIVER"
*******************************************************************************/
void HAL_Keypad_INIT(void)
{
	//Set rows and colums as output
	GPIO_PinConfig_t* PinConfig = NULL;
	PinConfig->GPIO_PinNumber = ROW0;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = ROW1;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = ROW2;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = ROW3;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = COLUM0;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = COLUM1;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = COLUM2;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = COLUM3;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, PinConfig);

	//Input is connected to pull up so it reads (1) by default
	//Initialize rows to no output state (1)
	MCAL_GPIO_WritePort(KEYPAD_PORT, ((KEYPAD_PORT->ODR._ODR & 0xFF) | (NO_VALID_INPUT << 8 )));
}

unsigned char HAL_Keypad_Get_Character(void)
{
	uint8_t row;
	uint8_t	colum = NO_VALID_INPUT;
	unsigned char result = NO_VALID_INPUT;

	//loop on rows
	for (row=0;row<4;row++)
	{
		//set rows to no output state (1)
		MCAL_GPIO_WritePin(KEYPAD_PORT, ROW0, TRUE);
		MCAL_GPIO_WritePin(KEYPAD_PORT, ROW1, TRUE);
		MCAL_GPIO_WritePin(KEYPAD_PORT, ROW2, TRUE);
		MCAL_GPIO_WritePin(KEYPAD_PORT, ROW3, TRUE);

		//set the numbered row to output state (0)
		switch (row)
		{
			case 0:MCAL_GPIO_WritePin(KEYPAD_PORT, ROW0, FALSE);break;
			case 1:MCAL_GPIO_WritePin(KEYPAD_PORT, ROW1, FALSE);break;
			case 2:MCAL_GPIO_WritePin(KEYPAD_PORT, ROW2, FALSE);break;
			case 3:MCAL_GPIO_WritePin(KEYPAD_PORT, ROW3, FALSE);break;
			default:break;
		}

		//check inputs
		if (MCAL_GPIO_ReadPin(KEYPAD_PORT, COLUM0) == INPUT_STATE)		    {colum = 0;}
		else if (MCAL_GPIO_ReadPin(KEYPAD_PORT, COLUM1) == INPUT_STATE)	    {colum = 1;}
		else if (MCAL_GPIO_ReadPin(KEYPAD_PORT, COLUM2) == INPUT_STATE)	    {colum = 2;}
		else if (MCAL_GPIO_ReadPin(KEYPAD_PORT, COLUM3) == INPUT_STATE)	    {colum = 3;}
		else { ; /* MISRA */}

		//if there was a valid input
		if (colum != NO_VALID_INPUT)
		{
			//wait until the input is gone
			while (INPUT_IS_STILL_VALID() == INPUT_STATE);

			//return the mapped key to this input
			result = g_Keypad_Mapping[row][colum];
			break;
		}

	}
	return result;
}
