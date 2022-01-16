/*
 * LIFO.c
 *
 *  Created on: Jan 7, 2022
 *      Author: Aya Sayed
 */

#include "LIFO.h"

LIFO_Status LIFO_INIT( LIFO_Buffer_t* LIFO_buf , LIFO_t* buf , unsigned int length)
{
	//check if LIFO buffer is exist
	if ( buf == NULL)
		return LIFO_NULL ;

	LIFO_buf->Base = buf ;
	LIFO_buf->head = buf ;
	LIFO_buf->length = length ;
	LIFO_buf->count = 0 ;
	return LIFO_NO_ERROR ;
}

LIFO_Status LIFO_PUSH( LIFO_Buffer_t* LIFO_buf , LIFO_t item )
{
	//check if LIFO buffer is exist
	if ( !LIFO_buf->head || !LIFO_buf->Base )
		return LIFO_NULL ;

	//check if LIFO buffer is full
	if ( LIFO_buf->count == LIFO_buf->length )
		return LIFO_FULL ;

	*(LIFO_buf->head) = item ;
	LIFO_buf->head++ ;
	LIFO_buf->count++;
	return LIFO_NO_ERROR ;
}

LIFO_Status LIFO_POP ( LIFO_Buffer_t* LIFO_buf , LIFO_t* item )
{
	//check if LIFO buffer is exist
	if ( !LIFO_buf->head || !LIFO_buf->Base )
		return LIFO_NULL ;

	//check if LIFO buffer is empty
	if ( LIFO_buf->count == 0 )
			return LIFO_EMPTY ;

	LIFO_buf->head-- ;
	*item = *(LIFO_buf->head) ;
	LIFO_buf->count--;
	return LIFO_NO_ERROR ;
}
