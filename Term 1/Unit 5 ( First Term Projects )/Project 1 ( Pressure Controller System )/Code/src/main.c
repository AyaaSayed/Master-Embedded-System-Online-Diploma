/*
 * main.c
 *
 *  Created on: Jan 21, 2022
 *      Author: Aya Sayed
 */

#include "Alarm.h"
#include "pressure_sensor.h"
#include "Pressure_Management.h"

void (*PS_STATE)() = STATE(PS_INIT);
void (*PM_STATE)() = STATE(SETTING);
void (*ALARM_STATE)() = STATE(ALARM_INIT);


int main(void)
{
	while (1)
	{
		PS_STATE();
		PM_STATE();
		ALARM_STATE();
	}

}
