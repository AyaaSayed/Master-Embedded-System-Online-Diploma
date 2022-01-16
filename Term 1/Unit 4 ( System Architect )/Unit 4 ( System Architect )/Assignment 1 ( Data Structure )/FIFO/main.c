/*
 * main.c
 *
 *  Created on: Jan 8, 2022
 *      Author: Aya Sayed
 */

#include "FIFO.h"
#include "stdio.h"
#include "stdlib.h"

FIFO_Buffer_t FIFO_UART;                          //define a static FIFO UART
#define FIFO_buffer_length 5
FIFO_t buf[FIFO_buffer_length] , temp ;

int main()
{
	if ( FIFO_INIT( &FIFO_UART , buf , FIFO_buffer_length ) == FIFO_NO_ERROR )
		printf ("FIFO Initialization is Done\n");

	//padding FIFO UART Buffer by its values
	for( int i=0 ; i<5 ; i++ )
	{
		if ( FIFO_Enqueue( &FIFO_UART , i ) == FIFO_NO_ERROR )
		    printf (" %d\tFIFO NO ERROR in Enqueue \n", i );
		else
			printf (" %d\tFIFO ERROR in Eequeue\n", i );
	}

	printf ("FIFO UART Buffer: \n");
	for( int i=0 ; i<5 ; i++ )
	{
		if ( FIFO_Dequeue( &FIFO_UART , &temp ) == FIFO_NO_ERROR )
			printf (" %d\tFIFO NO ERROR \n" , temp );
		else
			printf ("%d\tFIFO ERROR in Dequeue\n" , temp );
	}
}
