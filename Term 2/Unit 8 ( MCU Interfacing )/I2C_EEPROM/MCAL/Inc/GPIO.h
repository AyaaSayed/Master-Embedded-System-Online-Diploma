/*
 * GPIO.h
 *
 *  Created on: Mar 7, 2022
 *      Author: Aya Sayed
 */

#ifndef GPIO_H_
#define GPIO_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "STM32F103x6.h"


/*******************************************************************************
                      User type definitions (structures)
*******************************************************************************/
typedef struct{
	// Specifies the GPIO pins to be configured
	// This parameter must be a value of @ref GPIO_PINS_define
	uint16_t GPIO_PinNumber;

	// Specifies the operating mode for the selected pins
	// This parameter must be a value of @ref GPIO_MODE_define
	uint8_t GPIO_MODE;

	// Specifies the speed for the selected pins
	// This parameter must be a value of @ref GPIO_SPEED_define
	uint8_t GPIO_OUTPUT_SPEED;
}GPIO_PinConfig_t;

/******************************************************************************
                       Macros Configuration References
*******************************************************************************/

/*************************** @ref GPIO_PINS_define ****************************/
#define GPIO_PIN_0                     ((uint16_t)0x0001) // Pin 0 Selected
#define GPIO_PIN_1                     ((uint16_t)0x0002) // Pin 1 Selected
#define GPIO_PIN_2                     ((uint16_t)0x0004) // Pin 2 Selected
#define GPIO_PIN_3                     ((uint16_t)0x0008) // Pin 3 Selected
#define GPIO_PIN_4                     ((uint16_t)0x0010) // Pin 4 Selected
#define GPIO_PIN_5                     ((uint16_t)0x0020) // Pin 5 Selected
#define GPIO_PIN_6                     ((uint16_t)0x0040) // Pin 6 Selected
#define GPIO_PIN_7                     ((uint16_t)0x0080) // Pin 7 Selected
#define GPIO_PIN_8                     ((uint16_t)0x0100) // Pin 8 Selected
#define GPIO_PIN_9                     ((uint16_t)0x0200) // Pin 9 Selected
#define GPIO_PIN_10                    ((uint16_t)0x0400) // Pin 10 Selected
#define GPIO_PIN_11                    ((uint16_t)0x0800) // Pin 11 Selected
#define GPIO_PIN_12                    ((uint16_t)0x1000) // Pin 12 Selected
#define GPIO_PIN_13                    ((uint16_t)0x2000) // Pin 13 Selected
#define GPIO_PIN_14                    ((uint16_t)0x4000) // Pin 14 Selected
#define GPIO_PIN_15                    ((uint16_t)0x8000) // Pin 15 Selected
#define GPIO_PIN_ALL                   ((uint16_t)0xFFFF) // ALL PinS Selected


/*************************** @ref GPIO_MODE_define ****************************/
#define GPIO_MODE_ANALOG               0x00000000U  //0x00: Analog Mode
#define GPIO_MODE_Input_FLO            0x00000001U  //0x01: Floating Input (reset state)
#define GPIO_MODE_Input_PU             0x00000002U  //0x10: Input with Pull-Up
#define GPIO_MODE_Input_PD             0x00000003U  //0x10: Input with Pull-Down
#define GPIO_MODE_Output_pp            0x00000004U  //0x00: General Purpose Output Push-Pull
#define GPIO_MODE_Output_OD            0x00000005U  //0x01: General Purpose Output Open-Drain
#define GPIO_MODE_Output_AF_PP         0x00000006U  //0x10: Alternate Function Output Push-Pull
#define GPIO_MODE_Output_AF_OD         0x00000007U  //0x11: Alternate Function Output Open-Drain
#define GPIO_MODE_Iuput_AF             0x00000008U  //0x01: Alternate Function Input


/****************************** GPIO_MODE_MASK *******************************/
#define GPIO_MODE_ANALOG_MASK          0b00U  //0x00: Analog Mode
#define GPIO_MODE_Input_FLO_MASK       0b01U  //0x01: Floating Input (reset state)
#define GPIO_MODE_Input_PU_MASK        0b10U  //0x10: Input with Pull-Up
#define GPIO_MODE_Input_PD_MASK        0b10U  //0x10: Input with Pull-Down
#define GPIO_MODE_Output_pp_MASK       0b00U  //0x00: General Purpose Output Push-Pull
#define GPIO_MODE_Output_OD_MASK       0b01U  //0x01: General Purpose Output Open-Drain
#define GPIO_MODE_Output_AF_PP_MASK    0b10U  //0x10: Alternate Function Output Push-Pull
#define GPIO_MODE_Output_AF_OD_MASK    0b11U  //0x11: Alternate Function Output Open-Drain
#define GPIO_MODE_Iuput_AF_MASK        0b01U  //0x01: Alternate Function Input


/*************************** @ref GPIO_SPEED_define ***************************/
#define GPIO_SPEED_Input               0b00U  //Input State
#define GPIO_SPEED_10MHZ               0b01U  //Output mode, max speed 10 MHZ
#define GPIO_SPEED_2MHZ                0b10U  //Output mode, max speed 2  MHZ
#define GPIO_SPEED_50MHZ               0b11U  //Output mode, max speed 50 MHZ


/*********************************@ref GPIO_PIN********************************/
#define HIGH                           1U
#define LOW                            0U
#define OUTPUT                         1U
#define INPUT                          0U


/******************************************************************************
                      APIs Supported by "MCAL GPIO DRIVER"
*******************************************************************************/
void MCAL_GPIO_Init          (GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit        (GPIO_t* GPIOx);

// Read APIs
uint8_t   MCAL_GPIO_ReadPin  (GPIO_t* GPIOx , uint16_t PinNumber);
uint16_t  MCAL_GPIO_ReadPort (GPIO_t* GPIOx);

// Write APIs
void MCAL_GPIO_WritePin      (GPIO_t* GPIOx , uint16_t PinNumber , uint8_t Value);
void MCAL_GPIO_WritePort     (GPIO_t* GPIOx , uint16_t Value);

void MCAL_GPIO_TogglePin     (GPIO_t* GPIOx , uint16_t PinNumber);

Return_t MCAL_GPIO_LockPin   (GPIO_t* GPIOx , uint16_t PinNumber);

#endif /* GPIO_H_ */
