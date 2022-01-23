/*
 * Pressure_Management.h
 *
 *  Created on: Jan 21, 2022
 *      Author: Aya Sayed
 */

#ifndef PRESSURE_MANAGEMENT_H_
#define PRESSURE_MANAGEMENT_H_

#include "state.h"

//States ID
enum{
    WAITING,
    SETTING,
    SET_ALARM,
	RESET_ALARM
}PM_STATE_ID;

//protoypes
STATE_DECL(WAITING);
STATE_DECL(SETTING);
STATE_DECL(SET_ALARM);
STATE_DECL(RESET_ALARM);

//global pointer to function
void (*PM_STATE)();

#endif /* PRESSURE_MANAGEMENT_H_ */
