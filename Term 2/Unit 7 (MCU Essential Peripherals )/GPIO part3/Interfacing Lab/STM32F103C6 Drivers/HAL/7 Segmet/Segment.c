/*
 * 7_Segment.c
 *
 *  Created on: Mar 9, 2022
 *      Author: diesel
 */

#include "Segment.h"

unsigned char Segment[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};


/*******************************************************************************
                  APIs Supported by "HAL 7 SEGMENT DRIVER"
*******************************************************************************/
void HAL_7_Segment_INIT()
{
	// Configure the 7 Layers pins as output pins
	GPIO_PinConfig_t* PinConfig = NULL;
	PinConfig->GPIO_PinNumber = SEGMENT_PIN1;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(SEGMENT_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = SEGMENT_PIN2;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(SEGMENT_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = SEGMENT_PIN3;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(SEGMENT_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = SEGMENT_PIN4;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(SEGMENT_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = SEGMENT_PIN5;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(SEGMENT_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = SEGMENT_PIN6;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(SEGMENT_PORT, PinConfig);

	PinConfig->GPIO_PinNumber = SEGMENT_PIN7;
	PinConfig->GPIO_MODE = GPIO_MODE_Output_pp;
	PinConfig->GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(SEGMENT_PORT, PinConfig);
	}
