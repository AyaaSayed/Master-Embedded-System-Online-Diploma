/*
 * DC_Motor.h
 *
 *  Created on: Jan 17, 2022
 *      Author: Aya Sayed
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "State.h"

//define state
enum{
	DC_Init,
	DC_Idle,
	DC_Busy
}DC_STATE_ID;

//declare states functions CA
STATE_DECL(DC_Init);
STATE_DECL(DC_Idle);
STATE_DECL(DC_Busy);

//global pointer to function
void (*DC_state)();


#endif /* DC_MOTOR_H_ */
