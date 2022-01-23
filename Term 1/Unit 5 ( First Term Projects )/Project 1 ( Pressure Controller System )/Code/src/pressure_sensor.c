/*
 * pressure_sensor.c
 *
 *  Created on: Jan 20, 2022
 *      Author: Aya Sayed
 */

#include "pressure_sensor.h"

extern void (*PS_STATE)();

//Module Variable
uint32_t pressure_val;


uint32_t get_pressure_values()
{
	//get pressure values
	return pressure_val;
}

uint32_t read_pressure_values()
{
	//get pressure values
	return ( GPIOA_IDR & 0xFF );
}

STATE_DECL(PS_INIT)
{
	//state action
	//state ID
	PS_STATE_ID = PS_INIT;

	//init pressure sensor
	Set(APB2ENR,RCC_IOPAEN);
	AND(GPIOA_CRL,0xFF0FFFFF);
	OR(GPIOA_CRL,0X00000000);

	//update state
	PS_STATE = STATE(Reading_Pressure);
}

STATE_DECL(Reading_Pressure)
{
	//state action
	//state ID
	PS_STATE_ID = Reading_Pressure;

	//get pressure value from GPIOA_IDR register
	pressure_val = read_pressure_values();

	//update state
	PS_STATE = STATE(PS_WAITING);
}

STATE_DECL(PS_WAITING)
{
	//state action
	//state ID
	PS_STATE_ID = PS_WAITING;

	//delay 100 sec
	Delay(10000);

	//update state
	PS_STATE = STATE(Reading_Pressure);
}

