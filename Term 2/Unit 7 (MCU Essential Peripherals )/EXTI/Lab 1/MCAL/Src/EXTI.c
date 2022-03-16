/*
 * EXTI.c
 *
 *  Created on: Mar 13, 2022
 *      Author: Aya Sayed
 */

/*******************************************************************************
                                    Includes
*******************************************************************************/
#include <EXTI.h>


/*******************************************************************************
                                Generic Variables
*******************************************************************************/
void (*GP_IRQCallBack[15])(void);


/*******************************************************************************
                                  IRQ Handlers
*******************************************************************************/
void EXTI0_IRQHandler()
{
	//This bit is cleared by writing a ‘1’ into the bit
	EXTI->PR._PR |= (1<<EXTI0);

	//Call Back C function() which will be called once IRQ happen
	GP_IRQCallBack[EXTI0]();
}

void EXTI1_IRQHandler()
{
	//This bit is cleared by writing a ‘1’ into the bit
	EXTI->PR._PR |= (1<<EXTI1);

	//Call Back C function() which will be called once IRQ happen
	GP_IRQCallBack[EXTI2]();
}

void EXTI2_IRQHandler()
{
	//This bit is cleared by writing a ‘1’ into the bit
	EXTI->PR._PR |= (1<<EXTI2);

	//Call Back C function() which will be called once IRQ happen
	GP_IRQCallBack[EXTI2]();
}

void EXTI3_IRQHandler()
{
	//This bit is cleared by writing a ‘1’ into the bit
	EXTI->PR._PR |= (1<<EXTI3);

	//Call Back C function() which will be called once IRQ happen
	GP_IRQCallBack[EXTI3]();
}

void EXTI4_IRQHandler()
{
	//This bit is cleared by writing a ‘1’ into the bit
	EXTI->PR._PR |= (1<<EXTI4);

	//Call Back C function() which will be called once IRQ happen
	GP_IRQCallBack[EXTI4]();
}

void EXTI9_5_IRQHandler()
{
	//Call Back C function() which will be called once IRQ happen
	if      (EXTI->PR._PR & (1 << EXTI5)) {EXTI->PR._PR |= (1<<EXTI5);  GP_IRQCallBack[EXTI5]();}
	else if (EXTI->PR._PR & (1 << EXTI6)) {EXTI->PR._PR |= (1<<EXTI6);  GP_IRQCallBack[EXTI6]();}
	else if (EXTI->PR._PR & (1 << EXTI7)) {EXTI->PR._PR |= (1<<EXTI7);  GP_IRQCallBack[EXTI7]();}
	else if (EXTI->PR._PR & (1 << EXTI8)) {EXTI->PR._PR |= (1<<EXTI8);  GP_IRQCallBack[EXTI8]();}
	else if (EXTI->PR._PR & (1 << EXTI9)) {EXTI->PR._PR |= (1<<EXTI9);  GP_IRQCallBack[EXTI9]();}
}

void EXTI15_10_IRQHandler()
{
	//Call Back C function() which will be called once IRQ happen
	if      (EXTI->PR._PR & (1 << EXTI10)) {EXTI->PR._PR |= (1<<EXTI10);  GP_IRQCallBack[EXTI10]();}
	else if (EXTI->PR._PR & (1 << EXTI11)) {EXTI->PR._PR |= (1<<EXTI11);  GP_IRQCallBack[EXTI11]();}
	else if (EXTI->PR._PR & (1 << EXTI12)) {EXTI->PR._PR |= (1<<EXTI12);  GP_IRQCallBack[EXTI12]();}
	else if (EXTI->PR._PR & (1 << EXTI13)) {EXTI->PR._PR |= (1<<EXTI13);  GP_IRQCallBack[EXTI13]();}
	else if (EXTI->PR._PR & (1 << EXTI14)) {EXTI->PR._PR |= (1<<EXTI14);  GP_IRQCallBack[EXTI14]();}
	else if (EXTI->PR._PR & (1 << EXTI15)) {EXTI->PR._PR |= (1<<EXTI15);  GP_IRQCallBack[EXTI15]();}
}


/*******************************************************************************
                                Generic Functions
*******************************************************************************/
void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	//Configure GPIO to be AF Input
	GPIO_PinConfig_t PinConfig;
	PinConfig.GPIO_PinNumber = EXTI_Config->EXTI_Pin.GPIO_Pin;
	PinConfig.GPIO_MODE = GPIO_MODE_Iuput_AF;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
	MCAL_GPIO_Init(EXTI_Config->EXTI_Pin.GPIO_Port, &PinConfig);


	//Set AFIO to route between EXTI line with Port A,B,C and D
	uint8_t AFIO_EXTICR_Index    = EXTI_Config->EXTI_Pin.EXTI_InputLineNumber / 4;
	uint8_t AFIO_EXTICR_Position = EXTI_Config->EXTI_Pin.EXTI_InputLineNumber % 4;
	uint8_t GPIO_PORT_Mask = (EXTI_Config->EXTI_Pin.GPIO_Port == GPIOA)? PA_Mask :
			                 (EXTI_Config->EXTI_Pin.GPIO_Port == GPIOB)? PB_Mask :
			                 (EXTI_Config->EXTI_Pin.GPIO_Port == GPIOC)? PC_Mask : PD_Mask;

	switch(AFIO_EXTICR_Position){
	case 0:AFIO->AFIO_EXTICR[AFIO_EXTICR_Index].EXTI_0 = GPIO_PORT_Mask;break;
	case 1:AFIO->AFIO_EXTICR[AFIO_EXTICR_Index].EXTI_1 = GPIO_PORT_Mask;break;
	case 2:AFIO->AFIO_EXTICR[AFIO_EXTICR_Index].EXTI_2 = GPIO_PORT_Mask;break;
	case 3:AFIO->AFIO_EXTICR[AFIO_EXTICR_Index].EXTI_3 = GPIO_PORT_Mask;break;
	}


	//Set Rising or Falling EXTI Trigger
	if (EXTI_Config->Trigger_case == EXTI_Trigger_RISING)
	{
		EXTI->RTSR.TR |= (1<<EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
	else if (EXTI_Config->Trigger_case == EXTI_Trigger_FALLING)
	{
		EXTI->FTSR.TR |= (1<<EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
	else if (EXTI_Config->Trigger_case == EXTI_Trigger_RISINGAndFALLING)
	{
		EXTI->RTSR.TR |= (1<<EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
		EXTI->FTSR.TR |= (1<<EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
	}
	else{ /* Misra */ }


	//IRQ CALLBACK Handler
    GP_IRQCallBack[EXTI_Config->EXTI_Pin.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack;

    //Enable/Disable IRQ and NVIC
    if (EXTI_Config->IRQ_EN == EXTI_IRQ_ENABLE)
    {
    	EXTI->IMR.MR |=  (1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
    	Enable_NVIC(EXTI_Config->EXTI_Pin.IVT_IRQ_Number);
    }
    else if  (EXTI_Config->IRQ_EN == EXTI_IRQ_DISABLE)
	{
    	EXTI->IMR.MR &= ~(1 << EXTI_Config->EXTI_Pin.EXTI_InputLineNumber);
    	Disable_NVIC(EXTI_Config->EXTI_Pin.IVT_IRQ_Number);
	}
    else{ /* Misra */ }
}


void Enable_NVIC(uint8_t IRQ_Number)
{
	if   ((IRQ_Number >= 0) && (IRQ_Number < 32))
	{
		NVIC_ISER->NVIC_ISER0 |= (1 << IRQ_Number);
	}
	else if ((IRQ_Number >= 32) && (IRQ_Number < 64))
	{
		NVIC_ISER->NVIC_ISER1 |= (1 << IRQ_Number);
	}
	else{ /* Misra */ }
}

void Disable_NVIC(uint8_t IRQ_Number)
{
	if   ((IRQ_Number >= 0) && (IRQ_Number < 32))
	{
		NVIC_ICER->NVIC_ICER0 |= (1 << IRQ_Number);
	}
	else if ((IRQ_Number >= 32) && (IRQ_Number < 64))
	{
		NVIC_ICER->NVIC_ICER1 |= (1 << IRQ_Number);
	}
	else{ /* Misra */ }
}


/*******************************************************************************
                     APIs Supported by "MCAL EXTI DRIVER"
*******************************************************************************/
/*******************************************************************************
* Fn                -MCAL_EXTI_Init.
*
* Brief             -This is used to initialize EXTI from specific GPIO Pin and
*                    specify the mask/trigger condition and IRQ call back.
*
* Param [in]        -EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define,
*                    and EXTI_IRQ_define.
*
* Retval            -None.
*
* Note              -STM32 MCU has GPIO A, B, C, D and E Modules but LQFP4
*                    package has only GPIO A,B and part of C AND D exported as
*                    external PINs from the MCU.
*                   -Also Mandatory to enable RCC Clock for AFLO and the
*                    corresponding GPIO.
*/
void MCAL_EXTI_Init   (EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}

/*******************************************************************************
* Fn                -MCAL_EXTI_DeInit.
*
* Brief             -Reset all the EXTI registers and NVIC corresponding IRQ mask.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_EXTI_DeInit (void)
{
	//Reset all the EXTI registers
	EXTI->IMR.MR  = 0x0000;        //Reset Interrupt mask register.
	EXTI->EMR.MR  = 0x0000;        //Reset Event mask register.
	EXTI->RTSR.TR = 0x0000;        //Reset Rising trigger selection register.
	EXTI->FTSR.TR = 0x0000;        //Reset Falling trigger selection register.
	EXTI->SWIER._SWIER = 0x0000;   //Reset Software interrupt event register.
	EXTI->PR._PR = 0xFFFF;         //Reset Pending register.

	//Disable all the NVIC corresponding IRQ mask
	NVIC_ICER->NVIC_ICER0 |= (1U << EXTI0_IRQ);              //Disable EXTI0 IRQ6.
	NVIC_ICER->NVIC_ICER0 |= (1U << EXTI1_IRQ);              //Disable EXTI1 IRQ7.
	NVIC_ICER->NVIC_ICER0 |= (1U << EXTI2_IRQ);              //Disable EXTI2 IRQ8.
	NVIC_ICER->NVIC_ICER0 |= (1U << EXTI3_IRQ);              //Disable EXTI3 IRQ9.
	NVIC_ICER->NVIC_ICER0 |= (1U << EXTI4_IRQ);              //Disable EXTI4 IRQ10.
	NVIC_ICER->NVIC_ICER0 |= (1U << EXTI9_5_IRQ);            //Disable EXTI9_5 IRQ23.
	NVIC_ICER->NVIC_ICER1 |= (1U << (EXTI15_10_IRQ - 32));   //Disable EXTI15_10 IRQ40.
}

/*******************************************************************************
* Fn                -MCAL_EXTI_Update.
*
* Brief             -This is used to initialize EXTI from specific GPIO Pin and
*                    specify the mask/trigger condition and IRQ call back.
*
* Param [in]        -EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define,
*                    and EXTI_IRQ_define.
*
* Retval            -None.
*
* Note              -STM32 MCU has GPIO A, B, C, D and E Modules but LQFP4
*                    package has only GPIO A,B and part of C AND D exported as
*                    external PINs from the MCU.
*                   -Also Mandatory to enable RCC Clock for AFLO and the
*                    corresponding GPIO.
*/
void MCAL_EXTI_Update (EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}
