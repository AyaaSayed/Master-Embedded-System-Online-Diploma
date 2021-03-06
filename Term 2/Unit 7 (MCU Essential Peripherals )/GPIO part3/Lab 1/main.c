/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "GPIO.h"


typedef volatile unsigned int vuint32_t ;
#define _delay         for( vuint32_t i = 0 ; i<5000 ; i++ )


void MCAL_Clock_INIT(GPIO_t* GPIOx)
{
	if (GPIOx == GPIOA)
		RCC.APB2ENR.IOPAEN = TRUE;
	else if (GPIOx == GPIOB)
		RCC.APB2ENR.IOPBEN = TRUE;
	else if (GPIOx == GPIOC)
		RCC.APB2ENR.IOPCEN = TRUE;
	else if (GPIOx == GPIOD)
		RCC.APB2ENR.IOPDEN = TRUE;
	else
		RCC.APB2ENR.IOPEEN = TRUE;
}


int main()
{
	MCAL_Clock_INIT(GPIOA);
	MCAL_Clock_INIT(GPIOB);

	GPIO_PinConfig_t* PinConfig = NULL;

	//Port configuration register
	//Set Port B pin1 as output mode at 10 MHZ
	//set push-pull mode
	PinConfig->GPIO_PinNumber = GPIO_PIN_1;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB, PinConfig);

	//Set Port B pin13 as output mode at 10 MHZ
	//set push-pull mode
	PinConfig->GPIO_PinNumber = GPIO_PIN_13;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB, PinConfig);

	//Set Port A pin1 as input mode
	//set Floating input mode
	PinConfig->GPIO_PinNumber = GPIO_PIN_1;
	PinConfig->GPIO_MODE = GPIO_MODE_Input_FLO;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
	MCAL_GPIO_Init(GPIOA, PinConfig);

	//Set Port A pin1 as input mode
	//set Floating input mode
	PinConfig->GPIO_PinNumber = GPIO_PIN_13;
	PinConfig->GPIO_MODE = GPIO_MODE_Input_FLO;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
	MCAL_GPIO_Init(GPIOA, PinConfig);

	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1 , TRUE);
	MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, FALSE);

	while(1)
	{
		if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) != TRUE )
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			_delay;
			while( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) != TRUE );   //Single Pressing
		}
		if( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == TRUE )        //multi pressing
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		_delay;
	}
}
