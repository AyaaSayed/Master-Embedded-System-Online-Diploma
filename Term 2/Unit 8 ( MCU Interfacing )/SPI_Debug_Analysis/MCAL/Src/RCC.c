/*
 * RCC.c
 *
 *  Created on: Mar 27, 2022
 *      Author: Aya Sayed
 *
 *******************************************************************************
                                     Includes
*******************************************************************************/
#include "RCC.h"


/*******************************************************************************
                     APIs Supported by "MCAL RCC DRIVER"
*******************************************************************************/
void MCAL_RCC_GPIO_EN(GPIO_t* GPIOx)
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

void MCAL_RCC_AFIO_EN()
{
	RCC->APB2ENR.AFIOEN = TRUE;
}

uint32_t MCAL_RCC_GetSYS_CLKFreq(void)
{
	// Get System clock switch status (SWS)
	switch(RCC->CFGR.SWS){
		case 0:return HSI_RC_CLK;   //HSI oscillator used as system clock
		case 1:return HSE_CLK;      //HSE oscillator used as system clock
			                        //HSE user should specify it
		case 2:return 16000000;     //PLL used as system clock
			                        //PLLCLK and PLLMULL and PLL Source MUX
	}
	return ERROR;
}

uint32_t MCAL_RCC_GetHCLKFreq(void)
{
	// Get AHB pre-scaler
	return (MCAL_RCC_GetSYS_CLKFreq() >> RCC->CFGR.HPRE);
}

uint32_t MCAL_RCC_GetPCLK1Freq(void)
{
	// Get APB1 pre-scaler
	return (MCAL_RCC_GetHCLKFreq() >> RCC->CFGR.PPRE1);
}

uint32_t MCAL_RCC_GetPCLK2Freq(void)
{
	// Get APB2 pre-scaler
	return (MCAL_RCC_GetHCLKFreq() >> RCC->CFGR.PPRE2);
}
