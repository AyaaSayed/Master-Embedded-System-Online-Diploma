/*
 * Alarm.h
 *
 *  Created on: Jan 20, 2022
 *      Author: Aya Sayed
 */

#ifndef ALARM_H_
#define ALARM_H_

#include "state.h"

//Register addresses
#define RCC_BASE       0x40021000
#define GPIOA_BASE     0x40010800
#define APB2ENR        *( vuint32_t* )( RCC_BASE    + 0x18 )
#define GPIOA_CRH      *( vuint32_t* )( GPIOA_BASE  + 0x04 )
#define GPIOA_ODR      *( vuint32_t* )( GPIOA_BASE  + 0x0C )

//define bits name
#define RCC_IOPAEN     2       //RCC_IOPAEN is name of bit3

//States ID
enum{
	ALARM_INIT,
	ALARM_WAITING,
	ALARM_ON,
	ALARM_OFF
}ALARM_STATE_ID;

//protoypes
STATE_DECL(ALARM_INIT);
STATE_DECL(ALARM_WAITING);
STATE_DECL(ALARM_ON);
STATE_DECL(ALARM_OFF);

//global pointer to function
void (*ALARM_STATE)();

void Set_Alarm(uint32_t i);

#endif /* ALARM_H_ */
