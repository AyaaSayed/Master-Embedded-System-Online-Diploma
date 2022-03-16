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
#include  "EXTI.h"


 uint8_t IRQ_Flag = 0;

void EXTI9_CALLBACK(void)
{
	IRQ_Flag = 1;
	HAL_LCD_display_String("EXTI9 is Done:) ");
}


void GPIO_Clock_EN(GPIO_t* GPIOx)
{
	if (GPIOx == GPIOA)
		RCC->APB2ENR.IOPAEN = TRUE;
	else if (GPIOx == GPIOB)
		RCC->APB2ENR.IOPBEN = TRUE;
	else if (GPIOx == GPIOC)
		RCC->APB2ENR.IOPCEN = TRUE;
	else if (GPIOx == GPIOD)
		RCC->APB2ENR.IOPDEN = TRUE;
	else  { /* Misra */ }
}

void AFIO_Clock_EN()
{
	RCC->APB2ENR.AFIOEN = TRUE;
}


int main(void)
{
	//Enable GPIO (A and D) and AFIO
	AFIO_Clock_EN();
	GPIO_Clock_EN(GPIOA);
	GPIO_Clock_EN(GPIOB);

	//Initialization LCD
	HAL_LCD_INIT();
	HAL_LCD_Clear_Screen();

	//Set EXTI Connfiguration
	EXTI_PinConfig_t EXTIConfig;
	EXTIConfig.EXTI_Pin = EXTI9PB9;
	EXTIConfig.Trigger_case = EXTI_Trigger_RISING;
	EXTIConfig.P_IRQ_CallBack = EXTI9_CALLBACK;
	EXTIConfig.IRQ_EN = EXTI_IRQ_ENABLE;
	MCAL_EXTI_Init(&EXTIConfig);

	IRQ_Flag = 1;

	while (1)
	{
		if(IRQ_Flag)
		{
			IRQ_Flag = 0;
		}
		else { /* Misra */ }
	}

}

