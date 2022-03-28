/*
 * USART.c
 *
 *  Created on: Mar 27, 2022
 *      Author: Aya Sayed
 *
 *******************************************************************************
                                     Includes
*******************************************************************************/
#include "USART.h"

/*******************************************************************************
                                Global Variables
*******************************************************************************/
USART_Config_t* Global_USART_Config[3] = {NULL};


/*******************************************************************************
                     APIs Supported by "MCAL USART DRIVER"
*******************************************************************************/
/*******************************************************************************
* Fn                -MCAL_UART_Init.
*
* Brief             -Initialize UART Asynchronous  only.
*
* Param [in]        -USARTx: where x can be (1..3 depending on device used).
*
* Param [in]        -UART_Config: All UART configuration.
*
* Retval            -None.
*
* Note              -support for now Asynchronous mode & clock 8 MHz.
*/
void MCAL_UART_Init(USART_t* USARTx, USART_Config_t* UART_Config)
{
	// 1. Enable the clock for given USART peripheral
	if      (USARTx == USART1){ RCC->APB2ENR.USART1EN = TRUE; Global_USART_Config[0] = UART_Config; }
	else if (USARTx == USART2){ RCC->APB1ENR.USART2EN = TRUE; Global_USART_Config[1] = UART_Config; }
	else if (USARTx == USART3){ RCC->APB1ENR.USART3EN = TRUE; Global_USART_Config[2] = UART_Config; }
	else                      { /*  Misra  */ }

	// 2. Enable USART Module
	USARTx->CR1.UE = TRUE;

	// 3. Enable USART TX/RX engines according to the USART_Mode configuration item
	switch(UART_Config->USART_Mode){
		case UART_Mode_RX:USARTx->CR1.RE = TRUE;break;
		case UART_Mode_TX:USARTx->CR1.TE = TRUE;break;
		case UART_Mode_TX_RX:
			USARTx->CR1.RE = TRUE;
			USARTx->CR1.TE = TRUE;
			break;
		}

	//  4. Pay-load width
	USARTx->CR1.M = UART_Config->Payload_Length;

	// 5. configuration of parity control bit field
	if (!UART_Config->Parity)
	{
		switch(UART_Config->Parity){
			case UART_Parity_ODD : USARTx->CR1.PCE = TRUE; USARTx->CR1.PS = TRUE; break;
			case UART_Parity_EVEN: USARTx->CR1.PCE = TRUE; USARTx->CR1.PS = FALSE;break;
			}
	}else
	{
		USARTx->CR1.PCE = FALSE;
	}

	// 6. configuration the no. of stop bits
	USARTx->CR2.STOP = UART_Config->StopBits;

	// 7. USART HW Flow Control
	switch(UART_Config->HW_FlowControl){
		case UART_HW_FlowControl_CTS: USARTx->CR3.CTSE = TRUE;break;
		case UART_HW_FlowControl_RTS: USARTx->CR3.RTSE = TRUE;break;
		case UART_HW_FlowControl_RTS_CTS:
			USARTx->CR3.CTSE = TRUE;
			USARTx->CR3.RTSE = TRUE;break;
		}

	// 8. configuration baud-rate
	uint32_t pclk = (USARTx == USART1)? MCAL_RCC_GetPCLK2Freq() : MCAL_RCC_GetPCLK1Freq();
	USARTx->BRR.DIV_Fraction = DIV_Fraction(pclk, UART_Config->BaudRate);
	USARTx->BRR.DIV_Mantissa = DIV_Mantissa(pclk, UART_Config->BaudRate);

	// 9. Enable or Disable Interrupt
	if (UART_Config->IRQ_Enable != UART_IRQ_Enable_NONE)
	{
		if      (USARTx == USART1){ NVIC_ISER->NVIC_ISER1 |= (1 << (USART1_IRQ - 32)); }
	    else if (USARTx == USART2){ NVIC_ISER->NVIC_ISER1 |= (1 << (USART2_IRQ - 32)); }
	    else if (USARTx == USART3){ NVIC_ISER->NVIC_ISER1 |= (1 << (USART3_IRQ - 32)); }
	    else                      { /*  Misra  */ }

		if      (UART_Config->IRQ_Enable == UART_IRQ_Enable_TXE)    { USARTx->CR1.TXEIE  = TRUE; }
		else if (UART_Config->IRQ_Enable == UART_IRQ_Enable_TC)     { USARTx->CR1.TCIE   = TRUE; }
		else if (UART_Config->IRQ_Enable == UART_IRQ_Enable_RXNEIE) { USARTx->CR1.RXNEIE = TRUE; }
		else if (UART_Config->IRQ_Enable == UART_IRQ_Enable_PE)     { USARTx->CR1.PEIE   = TRUE; }
		else                                                        { /*  Misra  */ }
	}
}

/*******************************************************************************
* Fn                -MCAL_UART_DeInit.
*
* Brief             -DEInit UART Asynchronous only.
*
* Param [in]        -USARTx: where x can be (1..3 depending on device used).
*
* Retval            -None.
*
* Note              -Initialize UART first.
*/
void MCAL_UART_DeInit(USART_t* USARTx)
{
	if (USARTx == USART1){
			RCC->APB2RSTR.USART1RST = TRUE;
			NVIC_ICER->NVIC_ICER1 |= (1 << (USART1_IRQ - 32));
	}else if (USARTx == USART2){
			RCC->APB1RSTR.USART2RST = TRUE;
			NVIC_ICER->NVIC_ICER1 |= (1 << (USART2_IRQ - 32));
	}else if (USARTx == USART3){
			RCC->APB1RSTR.USART3RST = TRUE;
			NVIC_ICER->NVIC_ICER1 |= (1 << (USART3_IRQ - 32));
	}else { /*  Misra  */ }
}

/*******************************************************************************
* Fn                -MCAL_UART_GPIO_Set_Pins.
*
* Brief             -Initializes GPIO Pins.
*
* Param [in]        -USARTx: where x can be (1..3 depending on device used).
*
* Retval            -None.
*
* Note              -Should enable the corresponding ALT & GPIO in RCC clock.
* 					-Also called after MCAL_UART_Init().
*/
void MCAL_UART_GPIO_Set_Pins(USART_t* USARTx)
{
	GPIO_PinConfig_t PinConfig;

    if (USARTx == USART1)
	{
    	//Enable GPIOA and AFIO
    	MCAL_RCC_AFIO_EN();
    	MCAL_RCC_GPIO_EN(GPIOA);

    	// PA9 TX and PA10 RX
    	if (Global_USART_Config[0]->USART_Mode != UART_Mode_TX)
    	{
			// Initialize GPIOA Pin 10 as a AFIO UART RX
			PinConfig.GPIO_PinNumber = GPIO_PIN_10;
			PinConfig.GPIO_MODE = GPIO_MODE_Iuput_AF;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
    	}
    	if (Global_USART_Config[0]->USART_Mode != UART_Mode_RX)
    	{
			// Initialize GPIOA Pin 9 as a AFIO UART TX
			PinConfig.GPIO_PinNumber = GPIO_PIN_9;
			PinConfig.GPIO_MODE = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
    	}
    	else { /*  Misra  */ }

    	// PA11 CTS and PA12 RTS
		if (Global_USART_Config[0]->HW_FlowControl != UART_HW_FlowControl_RTS)
		{
			// Initialize GPIOA Pin 10 as a AFIO UART CTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_11;
			PinConfig.GPIO_MODE = GPIO_MODE_Iuput_AF;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (Global_USART_Config[0]->HW_FlowControl != UART_HW_FlowControl_CTS)
		{
			// Initialize GPIOA Pin 9 as a AFIO UART RTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_12;
			PinConfig.GPIO_MODE = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		else { /*  Misra  */ }
	}
    else if (USARTx == USART2)
	{
    	//Enable GPIOA and AFIO
		MCAL_RCC_AFIO_EN();
		MCAL_RCC_GPIO_EN(GPIOA);

		// PA2 TX and PA3 RX
		if (Global_USART_Config[1]->USART_Mode != UART_Mode_TX)
		{
			// Initialize GPIOA Pin 3 as a AFIO UART RX
			PinConfig.GPIO_PinNumber = GPIO_PIN_3;
			PinConfig.GPIO_MODE = GPIO_MODE_Iuput_AF;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (Global_USART_Config[1]->USART_Mode != UART_Mode_RX)
		{
			// Initialize GPIOA Pin 2 as a AFIO UART TX
			PinConfig.GPIO_PinNumber = GPIO_PIN_2;
			PinConfig.GPIO_MODE = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		else { /*  Misra  */ }

		// PA0 CTS and PA1 RTS
		if (Global_USART_Config[1]->HW_FlowControl != UART_HW_FlowControl_RTS)
		{
			// Initialize GPIOA Pin 0 as a AFIO UART CTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_0;
			PinConfig.GPIO_MODE = GPIO_MODE_Iuput_AF;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		if (Global_USART_Config[1]->HW_FlowControl != UART_HW_FlowControl_CTS)
		{
			// Initialize GPIOA Pin 1 as a AFIO UART RTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_1;
			PinConfig.GPIO_MODE = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOA, &PinConfig);
		}
		else { /*  Misra  */ }
	}
    else if (USARTx == USART3)
	{
    	//Enable GPIOA and AFIO
		MCAL_RCC_AFIO_EN();
		MCAL_RCC_GPIO_EN(GPIOB);

		// PB10 TX and PB11 RX
		if (Global_USART_Config[2]->USART_Mode != UART_Mode_TX)
		{
			// Initialize GPIOB Pin 11 as a AFIO UART RX
			PinConfig.GPIO_PinNumber = GPIO_PIN_11;
			PinConfig.GPIO_MODE = GPIO_MODE_Iuput_AF;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		if (Global_USART_Config[2]->USART_Mode != UART_Mode_RX)
		{
			// Initialize GPIOB Pin 10 as a AFIO UART TX
			PinConfig.GPIO_PinNumber = GPIO_PIN_10;
			PinConfig.GPIO_MODE = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		else { /*  Misra  */ }

		// PA13 CTS and PA14 RTS
		if (Global_USART_Config[2]->HW_FlowControl != UART_HW_FlowControl_RTS)
		{
			// Initialize GPIOB Pin 13 as a AFIO UART CTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_MODE = GPIO_MODE_Iuput_AF;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		if (Global_USART_Config[2]->HW_FlowControl != UART_HW_FlowControl_CTS)
		{
			// Initialize GPIOB Pin 14 as a AFIO UART RTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_MODE = GPIO_MODE_Output_AF_PP;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOB, &PinConfig);
		}
		else { /*  Misra  */ }
	}
    else { /*  Misra  */ }

}

/*******************************************************************************
* Fn                -MCAL_UART_SendData.
*
* Brief             -Send buffer on UART.
*
* Param [in]        -USARTx: where x can be (1..3 depending on device used).
*
* param [in] 		-P_TxBuffer buffer.
*
* Param [in]        -Mechanism is defined at  @Ref Mechanism_define.
*
* Retval            -None.
*
* Note              -Initialize UART first.
*                   -When transmitting with the parity enabled (PCE bit set to 1
*                    in the USART_CR1 register).
*                   -The value written in the MSB ( bit 7 or bit 8 depending on
*                    the data length ) has no effect.
*                   -Because it is replaced by the parity.
*                   -When receiving with the parity enabled the value read in
*                    the MSB bit is the received parity bit.
*/
void MCAL_UART_SendData(USART_t* USARTx, uint16_t* P_TxBuffer, uint8_t Mechanism)
{
	// 1. Wait until TXE (Transmit data register empty)
	if (Mechanism == Polling_Mechanism) { while(!(USARTx->SR.TXE)); }
	else                                { /*  Misra  */ }

	// 2. Check the USART_WordLength item for 9-bit or 8-bit in a frame
	USART_Config_t* USARTxConfig = NULL;
	USARTxConfig = (USART_Config_t*)((USARTx == USART1)?  Global_USART_Config       :
			                            ((USARTx == USART2)? (Global_USART_Config + 1)  :
			                		                             (Global_USART_Config + 2)));

	switch(USARTxConfig->Payload_Length){
	case UART_Payload_Length_8B: USARTx->DR.DR = ((*P_TxBuffer) & (uint8_t)0xFF); break;
	case UART_Payload_Length_9B: USARTx->DR.DR = ((*P_TxBuffer) & (uint8_t)0x1FF);break;
	}
}

/*******************************************************************************
* Fn                -MCAL_UART_ReceiveData.
*
* Brief             -Receive buffer on UART.
*
* Param [in]        -USARTx: where x can be (1..3 depending on device used).
*
* param [in] 		-P_RxBuffer buffer.
*
* Param [in]        -Mechanism.
*
* Retval            -None.
*
* Note              -Initialize UART first.
*                   -When transmitting with the parity enabled (PCE bit set to 1
*                    in the USART_CR1 register).
*                   -The value written in the MSB ( bit 7 or bit 8 depending on
*                    the data length ) has no effect.
*                   -Because it is replaced by the parity.
*                   -When receiving with the parity enabled the value read in
*                    the MSB bit is the received parity bit.
*/
void MCAL_UART_ReceiveData(USART_t* USARTx, uint16_t* P_RxBuffer, uint8_t Mechanism)
{
	// 1. Wait until RXNE (Read data register not empty)
	if (Mechanism == Polling_Mechanism) { while(!(USARTx->SR.RXNE)); }
	else                                { /*  Misra  */ }

	// 2. Check the USART_WordLength item for 9-bit or 8-bit in a frame
	USART_Config_t* USARTxConfig = NULL;
	USARTxConfig = (USART_Config_t*)((USARTx == USART1)?  Global_USART_Config       :
			                        ((USARTx == USART2)? (Global_USART_Config + 1)  :
			                		                     (Global_USART_Config + 2)));

	switch(USARTxConfig->Payload_Length){
	case UART_Payload_Length_8B:
		if (USARTxConfig->Parity == UART_Parity_Disable)
			*P_RxBuffer = (USARTx->DR.DR & (uint8_t)0xFF);
		else
			*P_RxBuffer = (USARTx->DR.DR & (uint8_t)0x7F);
		break;
	case UART_Payload_Length_9B:
		if (USARTxConfig->Parity == UART_Parity_Disable)
			*P_RxBuffer =  USARTx->DR.DR;
		else
			*P_RxBuffer = (USARTx->DR.DR & (uint8_t)0xFF);
		break;
	}
}

/*******************************************************************************
* Fn                -MCAL_UART_WAIT_TC.
*
* Brief             -Wait Transmission complete on UART.
*
* Param [in]        -USARTx: where x can be (1..3 depending on device used).
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_UART_WAIT_TC(USART_t* USARTx)
{
	while(!USARTx->SR.TC);
}


/*******************************************************************************
                                  IRQ Handlers
*******************************************************************************/
void USART2_IRQHandler(void)
{
	Global_USART_Config[1]->P_IRQ_CallBack();
}

void USART1_IRQHandler(void)
{
	Global_USART_Config[0]->P_IRQ_CallBack();
}

void USART3_IRQHandler(void)
{
	Global_USART_Config[2]->P_IRQ_CallBack();
}











