/*
 * Collision_Avoidance.c
 *
 *  Created on: Jan 17, 2022
 *      Author: Aya Sayed
 */

#include <stdio.h>
#include "Collision_Avoidance.h"

//global variables
int Speed = 0 ;
int Distance = 0 ;
int Threshold = 50 ;

//STATE pointer to function
extern void (*CA_state)();
int US_get_distance_random( int min , int max , int count );

//define each block
void ST_CA_Waiting()
 {
    //state name
	CA_STATE_ID = CA_Waiting;

	//state action
	DC_Motor(0);

	//event check
	Distance = US_get_distance_random(45,55,1);
	(Distance <= Threshold) ? (CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
	printf ("CA_Waiting State: Distance = %d  Speed = %d \n", Distance, Speed);
}

void ST_CA_Driving()
 {
	//state name
	CA_STATE_ID = CA_Driving;

	//state action
	DC_Motor(30);

	//event check
	Distance = US_get_distance_random(45,55,1);
	(Distance <= Threshold) ? (CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
	printf ("CA_Waiting State: Distance = %d  Speed = %d \n", Distance, Speed);
}

int US_get_distance_random( int min , int max , int count )
{
	//generate random value between min and max
	for ( int i=0 ; i<count ; i++ )
	{
		int rand_num = (rand() % ( max - min + 1 )) + min ;
		return rand_num ;
	}
}
