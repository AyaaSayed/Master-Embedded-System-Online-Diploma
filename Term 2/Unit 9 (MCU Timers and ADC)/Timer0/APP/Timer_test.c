/*
 * Timer_test.c
 *
 * Created: 4/6/2022 10:56:00 AM
 *  Author: Aya Sayed
 *
 *******************************************************************************
                                      Includes                                   
 *******************************************************************************/
#include "Timer_test.h"

/*******************************************************************************
                                  Global variables                                  
 *******************************************************************************/
uint32 Timer_Counter = 0;

/*******************************************************************************
                                  Application APIs                                 
 *******************************************************************************/
void Timer_test(void)
{
	/* Configure PIND0 as Output */
	SET_BIT(DDRB, 0);
	
	/* Set compare value */
	MCAL_TIMER0_SetCompareValue(100);
	
	/* Set timer configuration */
	TIMER0Config_t TIMER0_Config;
	
	TIMER0_Config.Timer_Mode = TIMER0_MODE_CTC;
	TIMER0_Config.Clock_Source = TIMER0_CLOCK_SOURCE_INTERNAL_PRESCALER_8;
	TIMER0_Config.IRQ_Enable = TIMER0_IRQ_ENABLE_TOIE0;
	TIMER0_Config.P_IRQ_CallBack = Timer_OverFlow_Interrupt_Handler;
	
	MCAL_TIMER0_Init(&TIMER0_Config);
	
	while (1);
}

void Timer_OverFlow_Interrupt_Handler(void)
{
	Timer_Counter++;
	if(Timer_Counter == 3921) /* 3921 ---> 1 sec*/
	{
		/* Toggle Led every one second */
		TOGGLE_BIT(PORTB, 0);
		
		/* Clear Counter */
		Timer_Counter = 0;
	}
}

void Timer_CompareMatch_Interrupt_Handler(void)
{

}