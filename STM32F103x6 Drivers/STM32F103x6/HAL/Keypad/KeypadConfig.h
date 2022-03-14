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

#define KEYPAD_PORT  	GPIOB

#define ROW0			GPIO_PIN_0
#define ROW1			GPIO_PIN_1
#define ROW2			GPIO_PIN_3
#define ROW3			GPIO_PIN_4
#define COLUM0			GPIO_PIN_5
#define COLUM1			GPIO_PIN_6
#define COLUM2			GPIO_PIN_7
#define COLUM3			GPIO_PIN_8


#endif /* KEYPAD_CONFIG_H_ */
