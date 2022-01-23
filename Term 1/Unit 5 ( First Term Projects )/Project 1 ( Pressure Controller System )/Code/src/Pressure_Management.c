/*
 * Pressure_Management.c
 *
 *  Created on: Jan 20, 2022
 *      Author: Aya Sayed
 */

#include "Pressure_Management.h"

extern void (*PM_STATE)();

STATE_DECL(RESET_ALARM)
{
	//state action
	//state ID
	PM_STATE_ID = RESET_ALARM;

    //set action
    Stop_Alarm();

	//update state
	PM_STATE = STATE(SETTING);
}

STATE_DECL(SETTING)
{
	//state action
	//state ID
	PM_STATE_ID = SETTING;

	//check state and update state
	( get_pressure_values() >= 20 )? ( PM_STATE = STATE(SET_ALARM) ):( PM_STATE = STATE(RESET_ALARM) );
}

STATE_DECL(SET_ALARM)
{
	//state action
	//state ID
	PM_STATE_ID = SET_ALARM;

    //set action
    Start_Alarm();

	//update state
	PM_STATE = STATE(WAITING);
}

STATE_DECL(WAITING)
{
	//state action
	//state ID
	PM_STATE_ID = WAITING;

    //delay 60 sec
    Delay(600);

	//update state
	PM_STATE = STATE(RESET_ALARM);
}
