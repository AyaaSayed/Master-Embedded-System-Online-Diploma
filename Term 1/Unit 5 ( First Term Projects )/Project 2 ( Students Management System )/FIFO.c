/*
 * FIFO.c
 *
 *  Created on: Jan 23, 2022
 *      Author: diesel
 */

#include "FIFO.h"
#include "Features.h"

FIFO_Status FIFO_STATUS( FIFO_Buffer_t* FIFO_buf )
{
	//check if FIFO buffer is empty
	if ( FIFO_buf->count == 0 )
		return FIFO_EMPTY;

	//check if FIFO buffer is exist
	if ( !FIFO_buf->head || !FIFO_buf->Base || !FIFO_buf->tail )
		return FIFO_NULL;

	//check if FIFO buffer is full
	if ( FIFO_buf->count == FIFO_buf->length )
		return FIFO_FULL;

	return FIFO_NO_ERROR;
}

FIFO_Status FIFO_INIT( FIFO_Buffer_t* FIFO_buf , Student_t* buf , uint32_t length )
{
	//check if FIFO buffer is exist
	if ( buf == NULL )
		return FIFO_NULL;

	FIFO_buf->Base = buf;
	FIFO_buf->head = FIFO_buf->Base;
	FIFO_buf->tail = FIFO_buf->Base;
	FIFO_buf->length = length;
	FIFO_buf->count = 0;
	return FIFO_NO_ERROR;
}

FIFO_Status FIFO_Enqueue( FIFO_Buffer_t* FIFO_buf , Student_t Item )
{
	//check if FIFO buffer is still Empty or Full Empty
	if ( ( FIFO_STATUS(FIFO_buf) != FIFO_NULL ) || ( FIFO_STATUS(FIFO_buf) != FIFO_EMPTY ) )
	{
		//Circular FIFO
		if( FIFO_buf->tail != FIFO_buf->Base )
			FIFO_buf->head = FIFO_buf->Base;

		*(FIFO_buf->head) = Item ;
		FIFO_buf->head++;
		FIFO_buf->count++;

		return FIFO_NO_ERROR;
	}
	else
	{
		printf("FIFO Student is Full\n");

		return FIFO_FULL;
	}
}

FIFO_Status FIFO_Dequeue( FIFO_Buffer_t* FIFO_buf , Student_t* Item )
{
	//check if FIFO buffer is exist
	if ( ( FIFO_STATUS(FIFO_buf) != FIFO_EMPTY ) || ( FIFO_STATUS(FIFO_buf) != 	FIFO_NULL ) )
	{
		//Circular FIFO
		if( FIFO_buf->tail == FIFO_buf->Base + (FIFO_buf->length) * sizeof(Status_t) )
			FIFO_buf->tail = FIFO_buf->Base;

		*Item = *(FIFO_buf->tail);
		FIFO_buf->tail++;
		FIFO_buf->count--;

		return FIFO_NO_ERROR;
	}
	else
	{
		printf("FIFO Dequeue is failed\n");
		return FIFO_ERROR;
	}
}
