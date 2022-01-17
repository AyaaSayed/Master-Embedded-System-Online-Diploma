/*
 * Ultrasonic_Sensor.c
 *
 *  Created on: Jan 17, 2022
 *      Author: Aya Sayed
 */

#include <stdint.h>
#include "Ultrasonic_Sensor.h"

extern void (*US_state)();

//Module Variables
uint32_t Distance;

//generate random value
int generate_random( int min , int max , int count )
{
	//generate random value between min and max
	for ( int i=0 ; i<count ; i++ )
	{
		int rand_num = (rand() % ( max - min + 1 )) + min ;
		return rand_num ;
	}
}

STATE_DECL( US_Init )
{
	//init US Sensor
	//call the US driver or function
	printf ("US_Init\n");
}

STATE_DECL( US_Busy )
{
	//state action
	US_STATE_ID = US_Busy;
	//read from the ultrasonic
	Distance = generate_random(45,55,1);

	printf ("US_Busy state: Distance = %d \n",Distance);

	US_state = STATE(US_Busy);
}
