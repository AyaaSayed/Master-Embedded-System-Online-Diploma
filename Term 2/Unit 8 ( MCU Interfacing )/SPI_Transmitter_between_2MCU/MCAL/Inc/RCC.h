/*
 * RCC.h
 *
 *  Created on: Mar 27, 2022
 *      Author: Aya Sayed
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "GPIO.h"


/*******************************************************************************
                                 Clock Macros
*******************************************************************************/
#define HSE_CLK 		(uint32_t)16000000
#define HSI_RC_CLK 		(uint32_t)8000000


/*******************************************************************************
                     APIs Supported by "MCAL RCC DRIVER"
*******************************************************************************/
void MCAL_RCC_AFIO_EN();
void MCAL_RCC_GPIO_EN(GPIO_t* GPIOx);

uint32_t MCAL_RCC_GetSYS_CLKFreq(void);

uint32_t MCAL_RCC_GetHCLKFreq(void);

uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);


#endif /* INC_RCC_H_ */
