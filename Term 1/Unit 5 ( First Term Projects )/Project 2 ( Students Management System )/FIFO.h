/*
 * FIFO.h
 *
 *  Created on: Jan 23, 2022
 *      Author: Aya Sayed
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

//create a new record
typedef struct {
	float GPA;
	uint8_t F_name[20];
	uint8_t L_name[20];
	uint32_t Roll_Num;
	uint32_t Course_ID[4];
} Student_t;

//FIFO
typedef struct {
	Student_t* Base;
	Student_t* head;
	Student_t* tail;
	uint32_t count;
	uint32_t length;
} FIFO_Buffer_t;

//FIFO Status
typedef enum {
	FIFO_EMPTY,
	FIFO_FULL,
	FIFO_NULL,
	FIFO_NO_ERROR,
	FIFO_ERROR
} FIFO_Status;

//APIS
FIFO_Status FIFO_INIT   ( FIFO_Buffer_t* FIFO_buf , Student_t* buf , uint32_t length );
FIFO_Status FIFO_Enqueue( FIFO_Buffer_t* FIFO_buf , Student_t Item );
FIFO_Status FIFO_Dequeue( FIFO_Buffer_t* FIFO_buf , Student_t* Item );
FIFO_Status FIFO_STATUS ( FIFO_Buffer_t* FIFO_buf );

#endif /* FIFO_H_ */
