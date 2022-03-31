/*
 * SPI.h
 *
 *  Created on: Mar 28, 2022
 *      Author: Aya Sayed
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "RCC.h"

/*******************************************************************************
                           User Configuration structures
*******************************************************************************/
typedef struct
{
	// specifies SPI MODE Master/Slave
	// This parameter must be set based on @ref SPI_MODE_DEFINE
	uint8_t SPI_Mode;

	// specifies SPI Communication mode
	// This parameter must be set based on @ref COMMUNICATION_MODE_DEFINE
	uint8_t Communication_Mode;

	// specifies Data MSB transmit first or LSB transmit first
	// This parameter must be set based on @ref FRAME_FORMAT_DEFINE
	uint8_t Frame_Format;

	// specifies Data frame size 8-bit or 16_bit
	// This parameter must be set based on @ref FRABaudRate_PrescalerME_SIZE_DEFINE
	uint8_t Frame_Size;

	// specifies SPI clock Polarity idle on low or idle on high
	// This parameter must be set based on @ref CLK_POLARITY_DEFINE
	uint8_t CLK_Polarity;

	// specifies SPI clock Phase,first clock capture or second clock capture
	// This parameter must be set based on @ref CLK_PHASE_DEFINE
	uint8_t CLK_Phase;

	// specifies slave select management by hardware or by software
	// This parameter must be set based on @ref NSS_DEFINE
	uint8_t NSS;

	// specifies SPI clock BaudRate Prescaler
	// This parameter must be set based on @ref BAUDERATE_PRESCALER_DEFINE
	uint8_t BaudRate_Prescaler;

	// specifies SPI Interrupt Requests
	// This parameter must be set based on @ref IRQ_ENABLE_DEFINE
	uint8_t IRQ_Enable;

	//set the C Function which will be called once IRQ Happens
	void (* P_IRQ_CallBack)(void);


}SPI_Config_t;

/******************************************************************************
                           User Define References Macros
*******************************************************************************/
/**************************** @ref SPI_MODE_DEFINE ****************************/
#define SPI_MODE_MASTER						                         1U
#define SPI_MODE_SLAVE						                         0U

/*********************** @ref COMMUNICATION_MODE_DEFINE ***********************/
#define SPI_COMMUNICATION_MODE_2LINE_FULL_DUPLEX	                 0U
#define SPI_COMMUNICATION_MODE_1LINE_RX_ONLY		                 1U
#define SPI_COMMUNICATION_MODE_1LINE_TX_ONLY		                 2U
#define SPI_COMMUNICATION_MODE_2LINE_RXE_ONLY		                 3U

/************************** @ref FRAME_FORMAT_DEFINE **************************/
#define SPI_FRAME_FORMAT_MSB_FIRST					                 0U
#define SPI_FRAME_FORMAT_LSB_FIRST					                 1U

/********************** @ref BaudRate_Prescaler_DEFINE ************************/
#define SPI_FRAME_SIZE_8BIT							                 0U
#define SPI_FRAME_SIZE_16BIT						                 1U

/************************** @ref CLK_POLARITY_DEFINE **************************/
#define SPI_CLK_POLARITY_IDLE_LOW					                 0U
#define SPI_CLK_POLARITY_IDLE_HIGH                                   1U

/**************************** @ref CLK_PHASE_DEFINE ***************************/
#define SPI_CLK_PHASE_FIRST                                          0U
#define SPI_CLK_PHASE_SECOND                                         1U

/******************************* @ref NSS_DEFINE ******************************/
// Hardware (SPI_CR2 Register)
#define SPI_NSS_HW_SLAVE							                 0U
#define SPI_NSS_HW_MASTER_SS_OUTPUT_ENABLED			                 1U
#define SPI_NSS_HW_MASTER_SS_OUTPUT_DISABLED		                 2U

// Software (NSS is driven by Software for "Master or Slave" )
#define SPI_NSS_SW_SSI_SET							                 3U
#define SPI_NSS_SW_SSI_RESET						                 4U

/************************ @ref BAUDERATE_PRESCALER_DEFINE *********************/
// CR1.Bit1 CPOL: Clock polarity
#define SPI_BAUDERATE_PRESCALER_2					                 0U
#define SPI_BAUDERATE_PRESCALER_4					                 1U
#define SPI_BAUDERATE_PRESCALER_8					                 2U
#define SPI_BAUDERATE_PRESCALER_16					                 3U
#define SPI_BAUDERATE_PRESCALER_32					                 4U
#define SPI_BAUDERATE_PRESCALER_64					                 5U
#define SPI_BAUDERATE_PRESCALER_128					                 6U
#define SPI_BAUDERATE_PRESCALER_256					                 7U

/**************************** @ref IRQ_ENABLE_DEFINE **************************/
#define SPI_IRQ_ENABLE_NONE					                         0U
#define SPI_IRQ_ENABLE_TXEIE					                     1U
#define SPI_IRQ_ENABLE_RXNEIE					                     2U
#define SPI_IRQ_ENABLE_ERRIE					                     3U

/***************************** @Ref Mechanism_define ***************************/
#define Polling_Mechanism           1U
#define Interrupt_Mechanism         0U


/*******************************************************************************
                     APIs Supported by "MCAL SPI DRIVER"
*******************************************************************************/
void MCAL_SPI_Init  (SPI_t *SPIx, SPI_Config_t *SPI_Config);
void MCAL_SPI_DeInit(SPI_t *SPIx);

void MCAL_SPI_GPIO_Set_Pins(SPI_t *SPIx);

void MCAL_SPI_Send_Data    (SPI_t *SPIx, uint16_t *P_TxBuffer, uint8_t Mechanism);
void MCAL_SPI_Recieve_Data (SPI_t *SPIx, uint16_t *P_RxBuffer, uint8_t Mechanism);
void MCAL_SPI_TX_RX        (SPI_t *SPIx, uint16_t *P_TxBuffer, uint8_t Mechanism);






































#endif /* INC_SPI_H_ */
