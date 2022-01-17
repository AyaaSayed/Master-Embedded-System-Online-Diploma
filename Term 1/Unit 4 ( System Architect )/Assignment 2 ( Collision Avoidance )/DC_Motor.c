/*
 * DC_Motor.c
 *
 *  Created on: Jan 17, 2022
 *      Author: Aya Sayed
 */

#include <stdio.h>
#include <stdint.h>
#include "DC_Motor.h"

//Module Variables
uint32_t Speed;

extern void (*DC_state)();

DC_Motor( int s )
{
	Speed = s;
	//state action
	DC_STATE_ID = DC_Busy;

	printf ("CA ----> DC          DC_Motor()\n");
}

STATE_DECL( DC_Init )
{
	//init DC motor
	//call the DC motor driver or function
	printf ("DC_Init\n");
}

STATE_DECL( DC_Idle )
{
	//state action
	DC_STATE_ID = DC_Idle;

	DC_state = STATE(DC_Idle);

	printf ("DC_Idle state: Speed = %d \n\n",Speed);
}

STATE_DECL( DC_Busy )
{
	//state action
	DC_STATE_ID = DC_Busy;

	DC_state = STATE(DC_Busy);

	printf ("DC_Busy state: Speed = %d  \n\n",Speed);

}
