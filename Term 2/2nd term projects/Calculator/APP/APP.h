/*
 * APP.h
 *
 * Created: 3/17/2022 1:46:11 PM
 *  Author: Aya Sayed
 */ 


#ifndef APP_H_
#define APP_H_

#include "LCD.h"
#include "FIFO.h"

//string parser
typedef enum{
	CALC_NO_ERR,
	CALC_SYNTAX_ERR,
	CALC_MATH_ERR,
	CALC_OUT_OF_RANGE_ERR
}calc_error;

#define CALC_MAX_NUM_DIGITS 3

typedef struct
{
	int16_t Number1;
	int16_t Number2;
	uint16_t Result;
	uint8_t operation;
	calc_error error;
}string_parser_output_t;

void String_parser(FIFO_t *string, uint8_t length);



#endif /* APP_H_ */