/*
 * main.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Aya Sayed
 */

#include "LIFO.h"
#include "stdio.h"
#include "stdlib.h"

LIFO_Buffer_t LIFO_UART;                          //define a static LIFO UART
#define LIFO_buffer_length 5
LIFO_t buf[LIFO_buffer_length] , temp ;

int main()
{
	LIFO_INIT( &LIFO_UART , buf , LIFO_buffer_length );

	//padding LIFO UART Buffer by its values
	for( int i=0 ; i<5 ; i++ )
	{
		LIFO_PUSH( &LIFO_UART , i );
	}

	printf ("LIFO UART Buffer: \n");
	for( int i=0 ; i<5 ; i++ )
	{
		LIFO_POP( &LIFO_UART , &temp );
		printf ("%d\n", temp ) ;
	}
}

