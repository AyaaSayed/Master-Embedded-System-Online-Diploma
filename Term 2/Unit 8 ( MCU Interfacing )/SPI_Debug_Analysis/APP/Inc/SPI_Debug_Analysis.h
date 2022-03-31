/*
 * SPI_Debug_Analysis.h
 *
 *  Created on: Mar 29, 2022
 *      Author: Aya Sayed
 */

#ifndef INC_SPI_DEBUG_ANALYSIS_H_
#define INC_SPI_DEBUG_ANALYSIS_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "USART.h"
#include "SPI.h"

/*******************************************************************************
                                    Macros
*******************************************************************************/
#define SPI1_Index              0
#define SPI2_Index              1
#define SPIx_NSS_Index          0
#define SPIx_SCK_Index          1
#define SPIx_MISO_Index         2
#define SPIx_MOSI_Index         3

/*******************************************************************************
                                  APP Function
*******************************************************************************/
void SPI1_CallBack(void);
void USART1_CallBack(void);

void SPI_Debug_Analysis_Using_UART1_Interrupt(void);



#endif /* INC_SPI_DEBUG_ANALYSIS_H_ */
