/*
 * LIFO.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Aya Sayed
 */


#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"

//define typedef of LIFO and LIFO status
typedef unsigned int  LIFO_t ;

typedef struct{
	LIFO_t* Base ;
	LIFO_t* head ;
	unsigned int count ;
	unsigned int length ;
}LIFO_Buffer_t;

typedef enum {
		LIFO_EMPTY,
		LIFO_FULL,
		LIFO_NULL,
		LIFO_NO_ERROR
}LIFO_Status;

//APIS
LIFO_Status LIFO_INIT( LIFO_Buffer_t* LIFO_buf , LIFO_t* buf , unsigned int length);
LIFO_Status LIFO_PUSH( LIFO_Buffer_t* LIFO_buf , LIFO_t item );
LIFO_Status LIFO_POP ( LIFO_Buffer_t* LIFO_buf , LIFO_t* item );

#endif /* LIFO_H_ */
