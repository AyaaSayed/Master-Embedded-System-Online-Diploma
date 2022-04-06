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
	
uint8 INPUT_IS_STILL_VALID()
{
	return ((uREAD_PIN(KEYPAD_PORT, COLUM0))&&
	(uREAD_PIN(KEYPAD_PORT, COLUM1))&&
	(uREAD_PIN(KEYPAD_PORT, COLUM2))&&
	(uREAD_PIN(KEYPAD_PORT, COLUM3)));
}
	
void Keypad_INIT(void)
{
	//Set rows as output
	//set rows to no output state (1)
	vINTIAL_PIN_OUTPUT(KEYPAD_PORT, ROW0, OUT_ON);
	vINTIAL_PIN_OUTPUT(KEYPAD_PORT, ROW1, OUT_ON);
	vINTIAL_PIN_OUTPUT(KEYPAD_PORT, ROW2, OUT_ON);
	vINTIAL_PIN_OUTPUT(KEYPAD_PORT, ROW3, OUT_ON);
	
	//Set colum as input
	vINTIAL_PIN_INPUT(KEYPAD_PORT, COLUM0, Pullup_ON);
	vINTIAL_PIN_INPUT(KEYPAD_PORT, COLUM1, Pullup_ON);
	vINTIAL_PIN_INPUT(KEYPAD_PORT, COLUM2, Pullup_ON);
	vINTIAL_PIN_INPUT(KEYPAD_PORT, COLUM3, Pullup_ON);
	
	//Input is connected to pull up so it reads (1) by default
	//Initialize rows to no output state (1)
	//KEYPAD_PORT = NO_VALID_INPUT;
	vWRITE_PORT(KEYPAD_PORT, NO_VALID_INPUT);
}

unsigned char Keypad_Get_Character(void)
{
	uint8 row;
	uint8	colum = NO_VALID_INPUT;
	unsigned char result = NO_VALID_INPUT;
	
	//loop on rows
	for (row=0;row<4;row++)
	{		
		//set the numbered row to output state (0)
		switch (row)
		{
			case 0:vWRITE_PIN(KEYPAD_PORT, ROW0, FALSE);
			case 1:vWRITE_PIN(KEYPAD_PORT, ROW1, FALSE);
			case 2:vWRITE_PIN(KEYPAD_PORT, ROW2, FALSE);
			case 3:vWRITE_PIN(KEYPAD_PORT, ROW3, FALSE);
			default:break;
		}
		
		//check inputs
		if (uREAD_PIN(KEYPAD_PORT, COLUM0)== INPUT_STATE)		    {colum = 0;}
		else if (uREAD_PIN(KEYPAD_PORT, COLUM1) == INPUT_STATE)	    {colum = 1;}
		else if (uREAD_PIN(KEYPAD_PORT, COLUM2) == INPUT_STATE)	    {colum = 2;}
		else if (uREAD_PIN(KEYPAD_PORT, COLUM3) == INPUT_STATE)	    {colum = 3;}
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

