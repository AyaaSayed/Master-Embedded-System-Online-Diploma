/******************************************************************************
 * @file           : main.c
 * @author         : Aya Sayed
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  4#warning "FPU is n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ot initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*******************************************************************************
                                     Includes
*******************************************************************************/

#include "LCD.h"
#include "Keypad.h"
#include  "Segment.h"

#define NO_VALID_INPUT  0xFF

void Clock_INIT(GPIO_t* GPIOx)
{
	if (GPIOx == GPIOA)
		RCC->APB2ENR.IOPAEN = TRUE;
	else if (GPIOx == GPIOB)
		RCC->APB2ENR.IOPBEN = TRUE;
	else if (GPIOx == GPIOC)
		RCC->APB2ENR.IOPCEN = TRUE;
	else if (GPIOx == GPIOD)
		RCC->APB2ENR.IOPDEN = TRUE;
	else
		RCC->APB2ENR.IOPEEN = TRUE;
}

int main(void)
{
	unsigned char key = NO_VALID_INPUT;
	unsigned char LCD[] = {'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9'};
	unsigned char Segment[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

	//Enable GPIOA and GPIOB
	Clock_INIT(GPIOA);
	Clock_INIT(GPIOB);

	//Initialization LCD, Keypad and 7 Segment
	HAL_LCD_INIT();
	HAL_Keypad_INIT();
	HAL_7_Segment_INIT();

	_delay_ms(1000);
	//LCD display startup message
	HAL_LCD_display_String("Hey ");
	_delay_ms(1000);
	HAL_LCD_Clear_Screen();

	//Displaying count from 0 to 9 untill keypad is ready
	for (unsigned char i=0 ; i<11 ; i++)
	{
		HAL_LCD_Display_Character(LCD[i]);
		MCAL_GPIO_WritePort(SEGMENT_PORT , Segment[i] << 3);
		_delay_ms(500);
	}
	HAL_LCD_Clear_Screen();
	HAL_LCD_display_String("Keypad is ready ");

	while (1)
	{
		//Scan Character from Keypad
		key = HAL_Keypad_Get_Character();

		//If I pressed any buttom
		if (key != NO_VALID_INPUT)
		{
			HAL_LCD_Clear_Screen();
			//check if key is number or character
			if (key == 'C')
			{
				HAL_LCD_Clear_Screen();
				continue;
			}
			else
			{
				HAL_LCD_Display_Character(key);
			}

		}
	}

}
