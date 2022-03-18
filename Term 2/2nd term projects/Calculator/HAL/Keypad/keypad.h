/******************************************************************************
 *
 * keypad.h
 *
 * Created: 3/4/2022 6:28:18 PM
 *  Author: Aya Sayed
 *
 *******************************************************************************/


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_types.h"
#include "micro_config.h"
#include "keypad_config.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define INPUT_STATE		0U
#define OUTPUT_STATE	1U
#define NO_OUTPUT_STATE	1U
#define NO_VALID_INPUT	0xFF

#define INPUT_IS_STILL_VALID	     ((KEYPAD_PIN&(1U<<COLUM0))\
									&&(KEYPAD_PIN&(1U<<COLUM1))\
									&&(KEYPAD_PIN&(1U<<COLUM2))\
									&&(KEYPAD_PIN&(1U<<COLUM3)))

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Keypad_INIT(void);
unsigned char Keypad_Get_Character(void);



#endif /* KEYPAD_H_ */