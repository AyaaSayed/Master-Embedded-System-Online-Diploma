/******************************************************************************
 *
 * LCD_Config.h
 *
 * Created: 3/4/2022 7:22:22 AM
 *  Author: Aya Sayed
 *
 ******************************************************************************/


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include <GPIO.h>


/*******************************************************************************
                             LCD PINs Configuration
*******************************************************************************/
#define RS								GPIO_PIN_10
#define RW								GPIO_PIN_11
#define E								GPIO_PIN_12
#define LCD_CONTROL_PORT                GPIOA
#define LCD_DATA_0					    GPIO_PIN_0
#define LCD_DATA_1			         	GPIO_PIN_1
#define LCD_DATA_2				    	GPIO_PIN_2
#define LCD_DATA_3				        GPIO_PIN_3
#define LCD_DATA_4					    GPIO_PIN_4
#define LCD_DATA_5			         	GPIO_PIN_5
#define LCD_DATA_6				    	GPIO_PIN_6
#define LCD_DATA_7				        GPIO_PIN_7
#define LCD_DATA_PORT                   GPIOA
#define LCD_MODE                        GPIO_MODE_Output_pp
#define LCD_SPEED                       GPIO_SPEED_10MHZ



#endif /* LCD_CONFIG_H_ */
