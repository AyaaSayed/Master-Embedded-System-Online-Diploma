/*
 * Calculator.c
 *
 * Created: 3/5/2022 8:01:25 AM
 * Author : diesel
 */ 

#include "LCD.h"
#include "APP.h"
#include "keypad.h"

#define NO_VALID_INPUT  0xFF

#define string_parser_input_index   16
FIFO_t string_parser_input[string_parser_input_index];
FIFO_Buffer_t Input_FIFO;


int main(void)
{
	unsigned char key = NO_VALID_INPUT;
	uint8_t Length = 0;                                 //calculate length of the input buffer
	string_parser_output_t *parser_output = NULL;       //Pointer to take the return of the string parser as a struct
	
    //Initialization LCD and Keypad
	LCD_INIT();
	Keypad_INIT();
	
	//Initialization string parser output FIFO
	FIFO_INIT(&Input_FIFO, string_parser_input, string_parser_input_index);
	
    while (1)
    {
	    //Scan Character from Keypad
	    key = Keypad_Get_Character();
		
		//If I pressed any buttom
		if (key != NO_VALID_INPUT)
		{
			//check if key is number or character
			if (key == 'C')
			{
				LCD_Clear_Screen();
				FIFO_INIT(&Input_FIFO, string_parser_input, string_parser_input_index);
				continue;
			}
			else
			{
				LCD_Display_Character(key);
				FIFO_Enqueue(&Input_FIFO, key);
				
				if (key == '=')
				{
					if (FIFO_IS_EMPTY(&Input_FIFO) == FIFO_EMPTY)
					{
						LCD_display_String("NO VALID INPUT");
						_delay_ms(1000);
						LCD_Clear_Screen();
						FIFO_INIT(&Input_FIFO, string_parser_input, string_parser_input_index);
					}
					else
					{
						//Parse the input data and get the operands, operation, and errors in a struct
						String_parser(string_parser_input, Length);
					}
				}
				Length++;
			}
		}
	}
}

