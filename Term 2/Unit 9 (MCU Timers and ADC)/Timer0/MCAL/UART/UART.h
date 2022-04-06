/*
 * UART.h
 *
 * Created: 3/26/2022 5:20:32 AM
 *  Author: Aya Sayed
 */ 


#ifndef UART_H_
#define UART_H_

/*******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "GPIO.h"


/*******************************************************************************
                           User Configuration structures
*******************************************************************************/
typedef struct
{
	// Specifies TX/RX Enable/Disable
	// This parameters must be set based on @Ref UART_Mode_define
	uint8 USART_Mode;

	// This member to configure the Baud Rate
	// This parameters must be set based on @Ref UART_BaudRate_define
	uint8 BaudRate;

    //specifies the no. of data bits (5,6,7,8 or 9 bits)
    //must be a value of @ref USART_DATA_BITS_define
	uint8 Databits;
	
	// Specifies the parity mode
	// This parameters must be set based on @Ref UART_Parity_define
	uint8 Parity;

	// Specifies the number of stop bits
	// This parameters must be set based on @Ref UART_StopBits_define
	uint8 StopBits;

	// enable or disable the interrupt
	// This parameters must be set based on @Ref UART_IRQ_define
	uint8 IRQ_Enable;

	// Set the C Function() which will be called once the IRQ Happen
	void (* P_IRQ_CallBack)(void);
}USART_Config_t;


/******************************************************************************
                           User Define References Macros
*******************************************************************************/
/**************************** @Ref UART_Mode_define ***************************/
#define USART_MODE_ASYNC				0
#define USART_MODE_SYNC					1

/************************* @Ref UART_BaudRate_define **************************/
/*
 * @ref USART_BAUD_RATE_define
 * Baud rate (bps) @ f_osc = 8.0000MHz
 * @ U2X = 0 , Asynchronous Normal mode
 */
#define USART_BAUD_RATE_2400			207
#define USART_BAUD_RATE_4800			103
#define USART_BAUD_RATE_9600			51
#define USART_BAUD_RATE_14400			34
#define USART_BAUD_RATE_19200			25
#define USART_BAUD_RATE_28800			16
#define USART_BAUD_RATE_38400			12
#define USART_BAUD_RATE_57600			8
#define USART_BAUD_RATE_76800			6
#define USART_BAUD_RATE_115200			3
#define USART_BAUD_RATE_230400			1
#define USART_BAUD_RATE_250000			1

/************************* @ref USART_DATA_BITS_define ************************/
#define USART_5_DATA_BITS				0
#define USART_6_DATA_BITS				1
#define USART_7_DATA_BITS				2
#define USART_8_DATA_BITS				3
#define USART_9_DATA_BITS				4

/*************************** @Ref UART_Parity_define **************************/
#define USART_NO_PARITY					0
#define USART_ODD_PARITY				1
#define USART_EVEN_PARITY				2

/************************* @Ref UART_StopBits_define **************************/
#define USART_1_STOP_BIT				0
#define USART_2_STOP_BIT				1

/***************************** @Ref UART_IRQ_define ***************************/
#define USART_IRQ_DISABLE				0
#define USART_IRQ_TXCIE					1
#define USART_IRQ_RXCIE					2
#define USART_IRQ_TXCIE_RXCIE			3



/*******************************************************************************
                     APIs Supported by "MCAL UART DRIVER"
*******************************************************************************/
void   MCAL_USART_Init(USART_Config_t * PinConfig);
void   MCAL_USART_DeInit(void);

void   MCAL_UART_SendData(uint8 *TxBuffer, enum Mechanism Enable);
uint16 MCAL_UART_ReceiveData(enum Mechanism Enable);

void   MCAL_USART_SendString(uint8 *pTxBuffer);
void   MCAL_USART_ReceiveString(uint8 *pRxBuffer);

void   MCAL_UART_SendNumberU32(uint32 num, enum Mechanism Enable);
uint32 MCAL_UART_ReceiveNumberU32(enum Mechanism Enable);


#endif /* UART_H_ */