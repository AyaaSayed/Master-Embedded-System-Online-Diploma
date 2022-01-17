/*
 * main.c
 *
 *  Created on: Jan 17, 2022
 *      Author: diesel
 */

#include <stdio.h>
#include "Collision_Avoidance.h"
#include "DC_Motor.h"
#include "Ultrasonic_Sensor.h"
#include "state.h"

void Setup();

int main()
{
	Setup();

	while (1)
	{
		//call CA_state for each block
		CA_state();
		//delay time
		for( volatile int i=0 ; i<1000 ; i++ );
	}
}

void Setup()
{
	//Init all the drivers
	//Init IRQ....
	//Init HAL drivers: Ultrasonic driver & DC Motor driver
	//Init Collision Avoidance Block
	//set state pointer for each block
    CA_state = STATE(CA_Waiting);
}
