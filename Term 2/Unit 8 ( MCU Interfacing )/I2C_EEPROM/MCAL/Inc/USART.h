/*
 * USART.h
 *
 *  Created on: Mar 27, 2022
 *      Author: Aya Sayed
 */

#ifndef INC_USART_H_
#define INC_USART_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "RCC.h"


/*******************************************************************************
                           User Configuration structures
*******************************************************************************/
typedef struct
{
	// Specifies TX/RX Enable/Disable
	// This parameters must be set based on @Ref UART_Mode_define
	uint8_t	 USART_Mode;

	// This member to configure the Baud Rate
	// This parameters must be set based on @Ref UART_BaudRate_define
	uint32_t BaudRate;

	// Specifies the number of data bits transmitted or received in a frame
	// This parameters must be set based on @Ref UART_Payload_Length_define
	uint8_t	 Payload_Length;

	// Specifies the parity mode
	// This parameters must be set based on @Ref UART_Parity_define
	uint8_t	 Parity;

	// Specifies the number of stop bits
	// This parameters must be set based on @Ref UART_StopBits_define
	uint8_t	 StopBits;

	// Specifies whether the hardware flow control mode is enabled or disabled
	// This parameters must be set based on @Ref UART_HW_FlowControl_define
	uint8_t	 HW_FlowControl;

	// enable or disable the interrupt
	// This parameters must be set based on @Ref UART_IRQ_define
	uint8_t	 IRQ_Enable;

	// Set the C Function() which will be called once the IRQ Happen
	void (* P_IRQ_CallBack)(void);
}USART_Config_t;


/******************************************************************************
                           User Define References Macros
*******************************************************************************/
/**************************** @Ref UART_Mode_define ***************************/
#define UART_Mode_RX				1U
#define UART_Mode_TX				2U
#define UART_Mode_TX_RX				3U

/************************* @Ref UART_BaudRate_define **************************/
#define UART_BaudRate_2400			2400
#define UART_BaudRate_9600			9600
#define UART_BaudRate_19200			19200
#define UART_BaudRate_57600			57600
#define UART_BaudRate_115200		115200
#define UART_BaudRate_230400		230400
#define UART_BaudRate_460800		460800
#define UART_BaudRate_921600		921600
#define UART_BaudRate_225000		2250000
#define UART_BaudRate_4500000		4500000

/*********************** @Ref UART_Payload_Length_define **********************/
#define UART_Payload_Length_8B		0U
#define UART_Payload_Length_9B		1U

/*************************** @Ref UART_Parity_define **************************/
#define UART_Parity_Disable			1U
#define UART_Parity_EVEN			2U
#define UART_Parity_ODD				3U

/************************* @Ref UART_StopBits_define **************************/
#define UART_StopBits_1				0U
#define UART_StopBits_half			1U
#define UART_StopBits_2				2U
#define UART_StopBits_1_half		3U

/********************** @Ref UART_HW_FlowControl_define ***********************/
#define UART_HW_FlowControl_NONE	0U
#define UART_HW_FlowControl_RTS		1U
#define UART_HW_FlowControl_CTS		2U
#define UART_HW_FlowControl_RTS_CTS	3U

/***************************** @Ref UART_IRQ_define ***************************/
#define UART_IRQ_Enable_NONE		0U
#define UART_IRQ_Enable_TXE			1U
#define UART_IRQ_Enable_TC			2U
#define UART_IRQ_Enable_RXNEIE		3U
#define UART_IRQ_Enable_PE			4U

/***************************** @Ref Mechanism_define ***************************/
#define Polling_Mechanism           1U
#define Interrupt_Mechanism         0U


/*******************************************************************************
                          Baud Rate Calculation Macros
*******************************************************************************/
/*
 * USARTDIV = fclk / (16 * Baudrate)
 * USARTDIV_MUL100 = uint32((100 * fclk ) / ( 16 * Baudrate) == (25 * fclk) / (4 * Baudrate))
 * DIV_Mantissa_MUL100 = Integer Part (USARTDIV) * 100
 * DIV_Mantissa = Integer Part (USARTDIV)
 * DIV_Fraction = (( USARTDIV_MUL100 - DIV_Mantissa_MUL100 ) *16) / 100
 */

#define USARTDIV(_PCLK_, _BAUD_)				(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)			(uint32_t) ((25 * _PCLK_ ) / (4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_, _BAUD_)			(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)				(uint32_t) (USARTDIV(_PCLK_, _BAUD_ ))
#define DIV_Fraction(_PCLK_, _BAUD_)			(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_) )*16) / 100)
#define UART_BRR_Register(_PCLK_, _BAUD_)		(( Mantissa (_PCLK_, _BAUD_ ) ) << 4 )|((DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )


/*******************************************************************************
                     APIs Supported by "MCAL USART DRIVER"
*******************************************************************************/
void MCAL_UART_Init  (USART_t* USARTx, USART_Config_t* UART_Config);
void MCAL_UART_DeInit(USART_t* USARTx);

void MCAL_UART_GPIO_Set_Pins(USART_t* USARTx);

void MCAL_UART_SendData   (USART_t* USARTx, uint16_t* P_TxBuffer, uint8_t Mechanism);
void MCAL_UART_ReceiveData(USART_t* USARTx, uint16_t* P_RxBuffer, uint8_t Mechanism);

void MCAL_UART_WAIT_TC(USART_t* USARTx);


#endif /* INC_USART_H_ */
