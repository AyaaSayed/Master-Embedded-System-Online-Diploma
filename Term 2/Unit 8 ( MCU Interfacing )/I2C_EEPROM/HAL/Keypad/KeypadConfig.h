/******************************************************************************
 *
 * keypad_config.h
 *
 * Created: 3/4/2022 6:28:04 PM
 *  Author: Aya Sayed
 *
 *******************************************************************************/


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "GPIO.h"

#define KEYPAD_PORT  	GPIOA

#define ROW0			GPIO_PIN_8
#define ROW1			GPIO_PIN_9
#define ROW2			GPIO_PIN_10
#define ROW3			GPIO_PIN_11
#define COLUM0			GPIO_PIN_12
#define COLUM1			GPIO_PIN_13
#define COLUM2			GPIO_PIN_14
#define COLUM3			GPIO_PIN_15


#endif /* KEYPAD_CONFIG_H_ */
