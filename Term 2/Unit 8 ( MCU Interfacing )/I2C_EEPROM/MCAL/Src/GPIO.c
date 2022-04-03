/*
 * GPIO.c
 *
 *  Created on: Mar 8, 2022
 *      Author: Aya Sayed
 */

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include <GPIO.h>


/*******************************************************************************
                      APIs Supported by "MCAL GPIO DRIVER"
*******************************************************************************/
void ConfigurationPin(GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig , uint8_t Configuration , uint8_t PinModeMask)
{
	if (Configuration == LOW)
	{
		switch(PinConfig->GPIO_PinNumber){
			case GPIO_PIN_0:
				GPIOx->CRL.CNF0  = PinModeMask;
				GPIOx->CRL.MODE0 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_1:
				GPIOx->CRL.CNF1  = PinModeMask;
				GPIOx->CRL.MODE1 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_2:
				GPIOx->CRL.CNF2  = PinModeMask;
				GPIOx->CRL.MODE2 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_3:
				GPIOx->CRL.CNF3  = PinModeMask;
				GPIOx->CRL.MODE3 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_4:
				GPIOx->CRL.CNF4  = PinModeMask;
				GPIOx->CRL.MODE4 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_5:
				GPIOx->CRL.CNF5  = PinModeMask;
				GPIOx->CRL.MODE5 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_6:
				GPIOx->CRL.CNF6  = PinModeMask;
				GPIOx->CRL.MODE6 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_7:
				GPIOx->CRL.CNF7  = PinModeMask;
				GPIOx->CRL.MODE7 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			default:break;
		}
	}
	else
	{
		switch(PinConfig->GPIO_PinNumber) {
			case GPIO_PIN_8:
				GPIOx->CRH.CNF8  = PinModeMask;
				GPIOx->CRH.MODE8 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_9:
				GPIOx->CRH.CNF9  = PinModeMask;
				GPIOx->CRH.MODE9 = PinConfig->GPIO_OUTPUT_SPEED;;
				break;
			case GPIO_PIN_10:
				GPIOx->CRH.CNF10  = PinModeMask;
				GPIOx->CRH.MODE10 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_11:
				GPIOx->CRH.CNF11  = PinModeMask;
				GPIOx->CRH.MODE11 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_12:
				GPIOx->CRH.CNF12  = PinModeMask;
				GPIOx->CRH.MODE12 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_13:
				GPIOx->CRH.CNF13  = PinModeMask;
				GPIOx->CRH.MODE13 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_14:
				GPIOx->CRH.CNF14  = PinModeMask;
				GPIOx->CRH.MODE14 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			case GPIO_PIN_15:
				GPIOx->CRH.CNF15  = PinModeMask;
				GPIOx->CRH.MODE15 = PinConfig->GPIO_OUTPUT_SPEED;
				break;
			default:break;
		}
	}
}


/*******************************************************************************
* Fn                -MCAL_GPIO_Init
* Brief             -Initializes the GPIOx PINy according to the specified
*                    parameters in the PinConfig.
*
* Param [in]        -GPIOx: where x can be (A..E depending on device used) to
*                    select the GPIO Peripheral.
*
* Param [in]        -PinConfig: is a pointer to GPIO_PinConfig_t structure that
*                    contains the configuration information for the specified
*                    GPIO PIN.
*
* Retval            -None.
*
* Note              -STM32F103C6 MCU has GPIO A,B,C,D and E Modules but LQFP4
*                    package has only GPIO A,B and part of C AND D exported as
*                    external PINs from the MCU.
*/
void MCAL_GPIO_Init(GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig)
{
	// Port configuration register low  (GPIOx_CRL) (x=A..G) configure pin 0..7
	// Port configuration register high (GPIOx_CRH) (x=A..G) configure pin 8..15
	volatile uint8_t Configuration = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? LOW : HIGH;

	switch(PinConfig->GPIO_MODE){
	case GPIO_MODE_ANALOG:
		ConfigurationPin(GPIOx, PinConfig, Configuration, GPIO_MODE_ANALOG_MASK);break;
	case GPIO_MODE_Input_FLO:
		ConfigurationPin(GPIOx, PinConfig, Configuration, GPIO_MODE_Input_FLO_MASK);break;
	case GPIO_MODE_Input_PU:
		ConfigurationPin(GPIOx, PinConfig, Configuration, GPIO_MODE_Input_PU_MASK);
		//Input pull-up Table 20. Port bit configuration table
		GPIOx->ODR._ODR |= PinConfig->GPIO_PinNumber;break;
	case GPIO_MODE_Input_PD:
		ConfigurationPin(GPIOx, PinConfig, Configuration, GPIO_MODE_Input_PD_MASK);break;
	case GPIO_MODE_Output_pp:
		ConfigurationPin(GPIOx, PinConfig, Configuration, GPIO_MODE_Output_pp_MASK);break;
	case GPIO_MODE_Output_OD:
		ConfigurationPin(GPIOx, PinConfig, Configuration, GPIO_MODE_Output_OD_MASK);break;
	case GPIO_MODE_Output_AF_PP:
		ConfigurationPin(GPIOx, PinConfig, Configuration, GPIO_MODE_Output_AF_PP_MASK);break;
	case GPIO_MODE_Output_AF_OD:
		ConfigurationPin(GPIOx, PinConfig, Configuration, GPIO_MODE_Output_AF_OD_MASK);break;
	case GPIO_MODE_Iuput_AF:
		ConfigurationPin(GPIOx, PinConfig, Configuration, GPIO_MODE_Iuput_AF_MASK);break;
	}
}


/*******************************************************************************
* Fn                -MCAL_GPIO_DeInit
*
* Brief             -Reset all the GPIO Registers.
*
* Param [in]        -GPIOx: where x can be (A..E depending on device used) to
*                    select the GPIO Peripheral.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_GPIO_DeInit (GPIO_t* GPIOx)
{
	// APB2 peripheral reset register (RCC_APB2RSTR)
	// Set and cleared by software.
	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR.IOPARST = TRUE;
		RCC->APB2RSTR.IOPARST = FALSE;
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR.IOPBRST = TRUE;
		RCC->APB2RSTR.IOPBRST = FALSE;
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR.IOPCRST = TRUE;
		RCC->APB2RSTR.IOPCRST = FALSE;
	}
	else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR.IOPDRST = TRUE;
		RCC->APB2RSTR.IOPDRST = FALSE;
	}
	else
	{
		RCC->APB2RSTR.IOPERST = TRUE;
		RCC->APB2RSTR.IOPERST = FALSE;
	}
}


/*******************************************************************************
* Fn                -MCAL_GPIO_ReadPin
*
* Brief             -Read specific PIN.
*
* Param [in]        -GPIOx: where x can be (A..E depending on device used) to
*                    select the GPIO Peripheral.
*
* Param [in]        -PinNumber: set pin number according @ref GPIO_PINS_define.
*
* Retval            -The input pin value.
*
* Note              -None.
*/
uint8_t  MCAL_GPIO_ReadPin (GPIO_t* GPIOx , uint16_t PinNumber)
{
	return ((((GPIOx->IDR._IDR) & PinNumber) == PinNumber)? TRUE : FALSE);
}

/*******************************************************************************
* Fn                -MCAL_GPIO_ReadPort
*
* Brief             -Read specific PORT.
*
* Param [in]        -GPIOx: where x can be (A..E depending on device used) to
*                    select the GPIO Peripheral.
*
* Retval            -The input port value.
*
* Note              -None.
*/
uint16_t  MCAL_GPIO_ReadPort (GPIO_t* GPIOx)
{
	return ((uint16_t)GPIOx->IDR._IDR);
}


/*******************************************************************************
* Fn                -MCAL_GPIO_WritePort
*
* Brief             -Write on specific PIN.
*
* Param [in]        -GPIOx: where x can be (A..E depending on device used) to
*                    select the GPIO Peripheral.
*
* Param [in]        -PinNumber: specifies the port pin to write on it, set pin
*                    number according @ref GPIO_PINS_define
*
* Param [in]        -Value: Pin value.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_GPIO_WritePin (GPIO_t* GPIOx , uint16_t PinNumber , uint8_t Value)
{
/*	// Using GPIOx->ODR to write on it
	if (Value == TRUE)
		GPIOx->ODR._ODR |= PinNumber;
	else
		GPIOx->ODR._ODR &= ~(PinNumber);*/


	// Using GPIOx->BSRR to write on it
	if (Value == TRUE)
		GPIOx->BSRR.BS = PinNumber;
	else
		GPIOx->BRR.BR = PinNumber;
}


/*******************************************************************************
* Fn                -MCAL_GPIO_WritePort
*
* Brief             -Write on specific PORT.
*
* Param [in]        -GPIOx: where x can be (A..E depending on device used) to
*                    select the GPIO Peripheral.
*
* Param [in]        -Value: Port value.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_GPIO_WritePort    (GPIO_t* GPIOx , uint16_t Value)
{
	GPIOx->ODR._ODR = Value;
}

/*******************************************************************************
* Fn                -MCAL_GPIO_TogglePin
*
* Brief             -Toggle a specific pin in GPIOx.
*
* Param [in]        -GPIOx: where x can be (A..E depending on device used) to
*                    select the GPIO Peripheral.
*
* Param [in]        -PinNumber: specifies the port pin to toggle it, set pin
*                    number according @ref GPIO_PINS_define.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_GPIO_TogglePin    (GPIO_t* GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR._ODR ^= PinNumber;
}


/*******************************************************************************
* Fn                -MCAL_GPIO_LockPin
*
* Brief             -The locking mechanism allows the IO configuration to be
*                    frozen.
*
* Param [in]        -GPIOx: where x can be (A..E depending on device used) to
*                    select the GPIO Peripheral.
*
* Param [in]        -PinNumber: specifies the port pin to lock it, set pin
*                    number according @ref GPIO_PINS_define.
*
* Retval            -DONE if PinConfig is locked or ERROR if pin not locked
*                    Return_t is defined at @ref GLOBAL_ENUM.
*
* Note              -During the LOCK Key Writing sequence, the value of
*                    LCK[15:0] must not change. Any error in the lock
*                    sequence will abort the lock.
*/
Return_t MCAL_GPIO_LockPin      (GPIO_t* GPIOx , uint16_t PinNumber)
{
	// These bits are read write but can only be written when the LCKK bit is 0.
	GPIOx->LCKR.LCK |= PinNumber;

	/* This bit can be read anytime. It can only be modified using the Lock Key
	   Writing Sequence.
	   LOCK key writing sequence:
	   Write 1
	   Write 0
       Write 1
	   Read 0
	   Read 1 (this read is optional but confirms that the lock is active)*/
	GPIOx->LCKR.LCKK = TRUE;
	GPIOx->LCKR.LCKK = FALSE;
	GPIOx->LCKR.LCKK = TRUE;
	return ((GPIOx->LCKR.LCKK == TRUE)? DONE : ERROR);
}

