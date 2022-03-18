/*
 * APP.c
 *
 * Created: 3/17/2022 1:46:29 PM
 *  Author: Aya Sayed
 */ 

#include "APP.h"

FIFO_t Num1[3], Num2[3], str[16];
uint8_t Output[5];
FIFO_Buffer_t Number1_FIFO;
FIFO_Buffer_t Number2_FIFO;
string_parser_output_t* output = NULL;

uint8_t Is_Operator(char c)
{
	return (c=='+' || c=='-' || c=='*'|| c=='/' );
}

void String_parser(FIFO_t *Buffer, uint8_t length)
{
	FIFO_INIT(&Number1_FIFO, Num1, 3);
	FIFO_INIT(&Number2_FIFO, Num2, 3);
	
	//Initialize
	output->Result = 0;
	output->Number1 = 0;
	output->Number2 = 0;	
	output->operation = 0;
	output->error = CALC_NO_ERR;
	
	//Checking for syntax errors..
	for(uint8_t i=0 ; i<length ; i++)
	{
		//If there are 3 consecutive operators
		//If the text begins with * or / or ends with an operator
		if((Buffer[0] == '*' || Buffer[0] == '/' || Is_Operator(Buffer[length])) || (Is_Operator(Buffer[i]) && Is_Operator(Buffer[i+1]) && Is_Operator(Buffer[i+2])))
		{
			output->error = CALC_SYNTAX_ERR;
			LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
			LCD_display_String("CALC SYNTAX ERR ");
			break;
		}
	}
	
	uint8_t op_count = 0, i = 0;
	
	//If there are no syntax errors, start parsing
	while(i < length)
	{
		if((Buffer[i] == '+') || (Buffer[i] == '-') || (Buffer[i] == '*') || (Buffer[i] == '/'))   //If found operator
		{
			output->operation = Buffer[i];
			op_count++;
		}
		else                                                                  //If found digit
		{
			if(op_count == 0)                                                 //Before operator
			{
				FIFO_Enqueue(&Number1_FIFO, Buffer[i]);                       //store digit in operand 1
			}
			else if(op_count == 1)                                            //After operator
			{
				FIFO_Enqueue(&Number2_FIFO, Buffer[i]);                       //store digit in operand 2
			}
			else
			{
				output->error = CALC_OUT_OF_RANGE_ERR;                        //Return out of range error
				LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
				LCD_display_String("CALC OUT OF RANGE ERR");
				break;
			}
		}
		i++;
	}
	//output->Number1 = (int16_t)atoi(Num1);
	output->Number2 = (int16_t)atoi(Num2);
	output->Number1 = (int16_t)atoi(Num1);
	
	
	switch(output->operation)
	{
		case '+':
			output->Result = output->Number1 + output->Number2;
			break;
		case '-':
			output->Result = output->Number1 - output->Number2;
			break;
		case '*':
			output->Result = output->Number1 * output->Number2;
			break;
		case '/':
			output->Result = output->Number1 / output->Number2;
			break;
	}
	LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
	itoa(output->Result, Output, 10);
	LCD_display_String(Output);
}

