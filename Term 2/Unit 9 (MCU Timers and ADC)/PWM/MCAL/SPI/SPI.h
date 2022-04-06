/*
 * SPI.h
 *
 * Created: 3/29/2022 8:49:23 AM
 *  Author: Aya Sayed
 */ 


#ifndef SPI_H_
#define SPI_H_

/*******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "GPIO.h"

/*******************************************************************************
                             Generic Macros                                   
 *******************************************************************************/
#define MCU_Act_As_MASTER
//#define MCU_Act_As_SLAVE


/*******************************************************************************
                           User Configuration structures
*******************************************************************************/
typedef struct
{
	// specifies SPI MODE Master/Slave
	// This parameter must be set based on @ref SPI_MODE_DEFINE
	uint8 SPI_Mode;

	// specifies Data MSB transmit first or LSB transmit first
	// This parameter must be set based on @ref FRAME_FORMAT_DEFINE
	uint8 Frame_Format;

	// specifies SPI clock speed Low or high
	// This parameter must be set based on @ref CLK_SPEED_DEFINE
	uint8 CLK_Speed;

	// specifies SPI clock Polarity idle on low or idle on high
	// This parameter must be set based on @ref CLK_POLARITY_DEFINE
	uint8 CLK_Polarity;

	// specifies SPI clock Phase,first clock capture or second clock capture
	// This parameter must be set based on @ref CLK_PHASE_DEFINE
	uint8 CLK_Phase;

	// specifies SPI clock BaudRate Prescaler
	// This parameter must be set based on @ref BAUDERATE_PRESCALER_DEFINE
	uint8 BaudRate_Prescaler;

	// specifies SPI Interrupt Requests
	// This parameter must be set based on @ref IRQ_ENABLE_DEFINE
	uint8 IRQ_Enable;

	//set the C Function which will be called once IRQ Happens
	void (* P_IRQ_CallBack)(void);


}SPI_Config_t;

/******************************************************************************
                           User Define References Macros
*******************************************************************************/
/**************************** @ref SPI_MODE_DEFINE ****************************/
#define SPI_MODE_MASTER							(uint8)(1<<MSTR)
#define SPI_MODE_SLAVE							(uint8)(0<<MSTR) 

/*********************** @ref COMMUNICATION_MODE_DEFINE ***********************/
// #define COMMUNICATION_MODE_FULL_DUPLEX			(uint8)(0)
// #define COMMUNICATION_MODE_3_WIRE				(uint8)(0)

/************************** @ref FRAME_FORMAT_DEFINE **************************/
#define FRAME_FORMAT_MSB_FIRST					(uint8)(0<<DORD)		
#define FRAME_FORMAT_LSB_FIRST					(uint8)(1<<DORD)

/************************ @ref BAUDERATE_PRESCALER_DEFINE *********************/
/* SPCR.Bits 1:0 – SPRn:?SPI Clock Rate Select */
#define BAUDERATE_PRESCALER_4					(uint8)(0<<SPR0)
#define BAUDERATE_PRESCALER_16					(uint8)(1<<SPR0)
#define BAUDERATE_PRESCALER_64					(uint8)(2<<SPR0)
#define BAUDERATE_PRESCALER_128					(uint8)(3<<SPR0)

/* SPSR.Bit 0 – SPI2X:?Double SPI Speed Bit */
#define BAUDERATE_PRESCALER_DOUBLE_SPEED_2		(uint8)(0<<SPR0)
#define BAUDERATE_PRESCALER_DOUBLE_SPEED_8		(uint8)(1<<SPR0)
#define BAUDERATE_PRESCALER_DOUBLE_SPEED_32		(uint8)(2<<SPR0)
#define BAUDERATE_PRESCALER_DOUBLE_SPEED_64		(uint8)(3<<SPR0)

/************************** @ref CLK_POLARITY_DEFINE **************************/
#define CLK_POLARITY_RISING_FALLING				(uint8)(0<<CPOL)
#define CLK_POLARITY_FALLING_RISING				(uint8)(1<<CPOL)

/**************************** @ref CLK_PHASE_DEFINE ***************************/
#define CLK_PHASE_SAMPLE_SETUP					(uint8)(0<<CPHA)
#define CLK_PHASE_SETUP_SAMPLE					(uint8)(1<<CPHA)

/**************************** @ref CLK_SPEED_DEFINE ***************************/
#define CLK_SPEED_LOW							(uint8)(0)
#define CLK_SPEED_HIGH							(uint8)(1)

/**************************** @ref IRQ_ENABLE_DEFINE **************************/
#define IRQ_ENABLE_NONE							(uint8)(0<<SPIE)
#define IRQ_ENABLE								(uint8)(1<<SPIE)


/*******************************************************************************
                     APIs Supported by "MCAL SPI DRIVER"
*******************************************************************************/
void  MCAL_SPI_Init  (SPI_Config_t *SPI_Config);
void  MCAL_SPI_DeInit(void);

void  MCAL_SPI_GPIO_Set_Pins(void);

uint8 MCAL_SPI_Send_Data    (uint8 *P_TxBuffer, enum Mechanism Enable);
uint8 MCAL_SPI_Recieve_Data (uint8* P_RxBuffer, enum Mechanism Enable);
uint8 MCAL_SPI_TX_RX        (uint8 *P_TxBuffer, enum Mechanism Enable);

void  MCAL_SPI_Send_STRING    (uint8* str);
//uint8 MCAL_SPI_Recieve_STRING (uint8* str);

#endif /* SPI_H_ */