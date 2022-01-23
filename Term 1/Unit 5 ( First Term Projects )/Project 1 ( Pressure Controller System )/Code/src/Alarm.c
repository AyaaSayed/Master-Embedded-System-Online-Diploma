/*
 * Alarm.c
 *
 *  Created on: Jan 20, 2022
 *      Author: Aya Sayed
 */

#include "Alarm.h"

extern void (*ALARM_STATE)();

STATE_DECL(ALARM_INIT)
{
	//state action
	//state ID
	ALARM_STATE_ID = ALARM_INIT;

	//Init Alarm(GPIOA)
	Set(APB2ENR,RCC_IOPAEN);
	AND(GPIOA_CRH,0xFF0FFFFF);
	OR(GPIOA_CRH,0x00200000);

	//update state
	ALARM_STATE = STATE(ALARM_WAITING);
}

STATE_DECL(ALARM_WAITING)
{
	//state action
	//state ID
	ALARM_STATE_ID = ALARM_WAITING;

	//update state
	ALARM_STATE = STATE(ALARM_WAITING);
}

STATE_DECL(ALARM_ON)
{
	//state action
	//state ID
	ALARM_STATE_ID = ALARM_ON;

	//Alarm on
	Set_Alarm(1);

	//update state
	ALARM_STATE = STATE(ALARM_WAITING);
}

STATE_DECL(ALARM_OFF)
{
	//state action
	//state ID
	ALARM_STATE_ID = ALARM_OFF;

	//Alarm off
	Set_Alarm(0);

	//update state
	ALARM_STATE = STATE(ALARM_WAITING);
}

void Set_Alarm(uint32_t i)
{
	//update state
	if ( i == 0 )
    {
        Set(GPIOA_ODR,13);
    }
	else
	{
		Clear(GPIOA_ODR,13);
	}
}

int Start_Alarm()
{
	//update state
	ALARM_STATE = STATE(ALARM_ON);
}

int Stop_Alarm()
{
	//update state
	ALARM_STATE = STATE(ALARM_OFF);
}
