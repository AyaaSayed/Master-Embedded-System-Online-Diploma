/*
 * Timer0.c
 *
 * Created: 4/5/2022 7:54:14 PM
 *  Author: Aya Sayed
 *
 *******************************************************************************
                                        Includes
 *******************************************************************************/
  #include "Timer0.h"
  
/*******************************************************************************
                                Global Variables
*******************************************************************************/
void (*GP_IRQ_CallBack)(void) = NULL;

TIMER0Config_t Global_TIMER0_Config;

/*******************************************************************************
                     APIs Supported by "MCAL SPI DRIVER"
*******************************************************************************/
/*******************************************************************************
* Fn                -MCAL_TIMER0_Init.
*
* Brief             -Initializes TIMER0 according to the specified parameters
*					 in Timer_Cfg.
*
* Param [in]        -TIMER0_Config : a pointer to TIMERCONFIG_t structure
*	     			 that contains the configuration information for the
*					 specified TIMER Module.
*
* Retval            -None.
*
* Note              -Supported for TIMER0 only.
*/
void MCAL_TIMER0_Init(TIMER0Config_t* TIMER0_Config)
{
	Global_TIMER0_Config = *TIMER0_Config;
	
	// 1. Select Timer Mode
	TCCR0 |= TIMER0_Config->Timer_Mode;
	if (TIMER0_Config->Timer_Mode != TIMER0_MODE_CTC &&
	    TIMER0_Config->Timer_Mode != TIMER0_MODE_NORMAL)
		vINTIAL_PIN_OUTPUT(B, PIN_3, OUT_OFF);    //Configure OC0 (PINB3) as Output
		
	// 2. Select Clock Source
	TCCR0 |= TIMER0_Config->Clock_Source;
	if (TIMER0_Config->Clock_Source == TIMER0_CLOCK_SOURCE_EXTERNAL_RISING_EDGE &&
	    TIMER0_Config->Clock_Source == TIMER0_CLOCK_SOURCE_EXTERNAL_FALLING_EDGE)
		vINTIAL_PIN_INPUT(B, PIN_0, Pullup_OFF);  //Configure T0 (PINB0) as Input
	
	// 3. Enable Or Disable IRQ
	TIMSK |= TIMER0_Config->IRQ_Enable;
	if (TIMER0_Config->IRQ_Enable != TIMER0_IRQ_ENABLE_NONE)
		sei();
	
	// 4. Call back ISR function
	GP_IRQ_CallBack = TIMER0_Config->P_IRQ_CallBack;
}

/*******************************************************************************
* Fn                -MCAL_TIMER0_DeInit.
*
* Brief             -DeInitialze Timer0 Operation By Disable Timer Clock.
*
* Retval            -None.
*
* Note              -Supported for TIMER0 only.
*/
void MCAL_TIMER0_DeInit(void)
{
	TCCR0 &= ~((1<<CS00) | (1<<CS01) | (1<<CS02));
}

/*******************************************************************************
* Fn                -MCAL_TIMER0_SetCompareValue.
*
* Brief             -Set OCR Register compare Value in Compare Match Mode(CTC).
*
* Param [in]        -TicksNumber: Value to Set in OCR(compare value must not
*                    exceed 255).
*
* Retval            -None.
*
* Note              -Supported for Compare Match Mode(CTC) only & compare value
*                    must not exceed 255.
*/
void MCAL_TIMER0_SetCompareValue(uint8 TicksNumber)
{
	OCR0 = TicksNumber;
}

/*******************************************************************************
* Fn                -MCAL_TIMER0_GetCounterValue.
*
* Brief             -Get Timer counter value.
*
* Param [in]        -TicksNumber: Value to Set in OCR(compare value must not
*                    exceed 255).
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_TIMER0_GetCounterValue(uint8* TicksNumber)
{
	*TicksNumber = TCNT0;
}

/*******************************************************************************
* Fn                -MCAL_PWM_DutyCycle.
*
* Brief             -Set PWM duty cycle in Fast PWM Mode.
*
* Param [in]        -Duty_Cycle : Value of PWM duty cycle (from 0 to 255).
*
* Retval            -None.
*
* Note              -Supported for Fast PWM Mode only & count value must not
*					 exceed 255.
*/
void MCAL_PWM_DutyCycle(uint8 Duty_Cycle)
{
	if(Global_TIMER0_Config.Timer_Mode == TIMER0_MODE_Fast_PWM_Noninverting)
	{
		OCR0 = Duty_Cycle;
	}
	else if(Global_TIMER0_Config.Timer_Mode == TIMER0_MODE_Fast_PWM_Inverting)
	{
		OCR0 = (uint8)(255 - Duty_Cycle);
	}
}

/*******************************************************************************
                                  IRQ Handlers
*******************************************************************************/
ISR(TIMER0_OVF_vect)
{
	GP_IRQ_CallBack();
}

ISR(TIMER0_COMP_vect)
{
	GP_IRQ_CallBack();
}