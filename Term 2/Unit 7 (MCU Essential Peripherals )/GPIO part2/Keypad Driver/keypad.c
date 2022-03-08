/******************************************************************************
 *
 * keypad.c
 *
 * Created: 3/4/2022 6:28:35 PM
 *  Author: Aya Sayed
 *
 *******************************************************************************/

#include "Keypad.h"

static const unsigned char g_Keypad_Mapping[4][4] = {{'1','2','3','A'},
													 {'4','5','6','B'},
													 {'7','8','9','C'},
													 {'#','0','*','D'}};
	
	
void Keypad_INIT(void)
{
	//Set rows as output
	KEYPAD_DDR |= (1U<<ROW0) | (1U<<ROW1) | (1U<<ROW2) | (1U<<ROW3);
	
	//Set colums as input
	KEYPAD_DDR &= ~(1U<<COLUM0) | (1U<<COLUM1) | (1U<<COLUM2) | (1U<<COLUM3);
	
	//Input is connected to pull up so it reads (1) by default
	//Initialize rows to no output state (1)
	KEYPAD_PORT = NO_VALID_INPUT;
}

unsigned char Keypad_Get_Character(void)
{
	uint8_t row;
	uint8_t	colum = NO_VALID_INPUT;
	unsigned char result = NO_VALID_INPUT;
	
	//loop on rows
	for (row=0;row<4;row++)
	{
		//set rows to no output state (1)
		KEYPAD_PORT |= (NO_OUTPUT_STATE<<ROW0);
		KEYPAD_PORT |= (NO_OUTPUT_STATE<<ROW1);
		KEYPAD_PORT |= (NO_OUTPUT_STATE<<ROW2);
		KEYPAD_PORT |= (NO_OUTPUT_STATE<<ROW3);
		
		//set the numbered row to output state (0)
		switch (row)
		{
			case 0:KEYPAD_PORT &= ~(OUTPUT_STATE<<ROW0);break;
			case 1:KEYPAD_PORT &= ~(OUTPUT_STATE<<ROW1);break;
			case 2:KEYPAD_PORT &= ~(OUTPUT_STATE<<ROW2);break;
			case 3:KEYPAD_PORT &= ~(OUTPUT_STATE<<ROW3);break;
			default:break;
		}
		
		//check inputs
		if ((KEYPAD_PIN & (1U<<COLUM0)) == INPUT_STATE)		    {colum = 0;}
		else if ((KEYPAD_PIN & (1U<<COLUM1)) == INPUT_STATE)	{colum = 1;}
		else if ((KEYPAD_PIN & (1U<<COLUM2)) == INPUT_STATE)	{colum = 2;}
		else if ((KEYPAD_PIN & (1U<<COLUM3)) == INPUT_STATE)	{colum = 3;}
		else { ; /* MISRA */}
			
		//if there was a valid input
		if (colum != NO_VALID_INPUT)
		{
			//wait until the input is gone
			while (INPUT_IS_STILL_VALID == INPUT_STATE);
			
			//return the mapped key to this input
			result = g_Keypad_Mapping[row][colum];
			break;
		}
		
	}
	return result;
}
