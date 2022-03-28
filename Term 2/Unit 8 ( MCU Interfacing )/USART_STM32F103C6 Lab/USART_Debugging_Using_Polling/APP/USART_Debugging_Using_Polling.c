/*
 * USART_Debugging_Using_Polling.c
 *
 *  Created on: Mar 27, 2022
 *      Author: Aya Sayed
 *
 *******************************************************************************
                                   Includes
*******************************************************************************/
#include "USART_Debugging_Using_Polling.h"

/*******************************************************************************
                                Global Variables
*******************************************************************************/
uint16_t data;

/*******************************************************************************
                                  APP Function
*******************************************************************************/
void USART_Debugging_Using_Polling(void)
{
	// Configuration of USART1
	USART_Config_t UART1_Config;
	UART1_Config.BaudRate       = UART_BaudRate_115200;
	UART1_Config.HW_FlowControl = UART_HW_FlowControl_NONE;
	UART1_Config.IRQ_Enable     = UART_IRQ_Enable_NONE;
	UART1_Config.P_IRQ_CallBack = NULL;
	UART1_Config.Parity         = UART_Parity_Disable;
	UART1_Config.Payload_Length = UART_Payload_Length_8B;
	UART1_Config.StopBits       = UART_StopBits_1;
	UART1_Config.USART_Mode     = UART_Mode_TX_RX;

	MCAL_UART_Init(USART1, &UART1_Config);
	MCAL_UART_GPIO_Set_Pins(USART1);


	while(1)
	{
		MCAL_UART_ReceiveData(USART1, &data, Polling_Mechanism);
		MCAL_UART_SendData   (USART1, &data, Polling_Mechanism);
	}
}
