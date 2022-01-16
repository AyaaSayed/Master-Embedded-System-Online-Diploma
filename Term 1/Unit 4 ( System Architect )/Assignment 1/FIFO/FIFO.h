/*
 * FIFO.h
 *
 *  Created on: Jan 8, 2022
 *      Author: Aya Sayed
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

//define typedef of FIFO and FIFO status
typedef uint8_t  FIFO_t ;

typedef struct{
	FIFO_t* Base ;
	FIFO_t* head ;
	FIFO_t* tail ;
	uint32_t count ;
	uint32_t length ;
}FIFO_Buffer_t;

typedef enum {
		FIFO_EMPTY,
		FIFO_FULL,
		FIFO_NULL,
		FIFO_NO_ERROR,
		FIFO_ERROR
}FIFO_Status;

//APIS
FIFO_Status FIFO_INIT ( FIFO_Buffer_t* FIFO_buf , FIFO_t* buf , uint32_t length);
FIFO_Status FIFO_Enqueue ( FIFO_Buffer_t* FIFO_buf , FIFO_t item );
FIFO_Status FIFO_Dequeue ( FIFO_Buffer_t* FIFO_buf , FIFO_t* item );
FIFO_Status FIFO_IS_FULL ( FIFO_Buffer_t* FIFO_buf );
FIFO_Status FIFO_IS_EMPTY( FIFO_Buffer_t* FIFO_buf );

#endif /* FIFO_H_ */
