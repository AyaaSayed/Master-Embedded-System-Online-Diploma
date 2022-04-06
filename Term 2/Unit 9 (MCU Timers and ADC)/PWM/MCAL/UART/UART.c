/*
 * UART.c
 *
 * Created: 3/26/2022 5:20:18 AM
 *  Author: Aya Sayed
 *
 *******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "UART.h"

void (*GP_IRQ_CallBack)(void);

/*******************************************************************************
                     APIs Supported by "MCAL UART DRIVER"
*******************************************************************************/
/*******************************************************************************
* Fn                -MCAL_USART_Init.
*
* Brief             -initialize the USART according to config instance PinConfig.
*
* Param [in]        -PinConfig: pointer to USART_config that contains USART
*                               configuration.
*
* Retval            -None.
*
* Note              -None.
*
*/
void MCAL_USART_Init(USART_Config_t * PinConfig)
{
	/* 1. Set Boud rate */
	UBRRL = PinConfig->BaudRate;
	
	/* 2. Set Asynchronous Normal mode */
	CLEAR_BIT(UCSRA, U2X);

	/* 3. Set data bits mode */
	SET_BIT(UCSRC, URSEL);    
	switch(PinConfig->Databits){
		case USART_5_DATA_BITS:
			CLEAR_BIT(UCSRC, UCSZ0);
			CLEAR_BIT(UCSRC, UCSZ1);
			CLEAR_BIT(UCSRB, UCSZ2);
			break;
		case USART_6_DATA_BITS:
			SET_BIT(UCSRC, UCSZ0);
			CLEAR_BIT(UCSRC, UCSZ1);
			CLEAR_BIT(UCSRB, UCSZ2);
			break;
		case USART_7_DATA_BITS:
			CLEAR_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			CLEAR_BIT(UCSRB, UCSZ2);
			break;
		case USART_8_DATA_BITS:
			SET_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			CLEAR_BIT(UCSRB, UCSZ2);
			break;
		case USART_9_DATA_BITS:
			SET_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			SET_BIT(UCSRB, UCSZ2);
			break;
	}
	
	/* 4. Set Parity bit type */
	SET_BIT(UCSRC, URSEL);
	switch(PinConfig->Parity){
		case USART_NO_PARITY:  CLEAR_BIT(UCSRC, UPM0); CLEAR_BIT(UCSRC, UPM1); break;
		case USART_ODD_PARITY: CLEAR_BIT(UCSRC, UPM0); SET_BIT(UCSRC, UPM1); break;
		case USART_EVEN_PARITY:  SET_BIT(UCSRC, UPM0); SET_BIT(UCSRC, UPM1); break;
	}
	
	/* 5. Set Stop bit type */
	SET_BIT(UCSRC, URSEL);
	switch (PinConfig->StopBits){
		case USART_1_STOP_BIT: CLEAR_BIT(UCSRC ,USBS);break;
		case USART_2_STOP_BIT:   SET_BIT(UCSRC ,USBS);break;	
	}
	
	/* 6. Set USART Mode */
	SET_BIT(UCSRC, URSEL);
	switch(PinConfig->USART_Mode){
		case USART_MODE_ASYNC: CLEAR_BIT(UCSRC ,UMSEL);break;
		case USART_MODE_SYNC:    SET_BIT(UCSRC ,UMSEL);break;
	}
	
	/* 7. Enable/Disable interrupt */
	switch(PinConfig->IRQ_Enable){
		case USART_IRQ_DISABLE:
			CLEAR_BIT(UCSRB, RXCIE);
			CLEAR_BIT(UCSRB, TXCIE);
			GP_IRQ_CallBack = NULL;
			CLEAR_BIT(SREG, I);
			break;
		case USART_IRQ_TXCIE:
			CLEAR_BIT(UCSRB, RXCIE);
			SET_BIT(UCSRB, TXCIE);
			GP_IRQ_CallBack = PinConfig->P_IRQ_CallBack;
			SET_BIT(SREG, I);
			break;
		case USART_IRQ_RXCIE:
			SET_BIT(UCSRB, RXCIE);
			CLEAR_BIT(UCSRB, TXCIE);
			GP_IRQ_CallBack = PinConfig->P_IRQ_CallBack;
			SET_BIT(SREG, I);
			break;
		case USART_IRQ_TXCIE_RXCIE:
			SET_BIT(UCSRB, RXCIE);
			SET_BIT(UCSRB, TXCIE);
			GP_IRQ_CallBack = PinConfig->P_IRQ_CallBack;
			SET_BIT(SREG, I);
			break;
	}

	/* 8. Enable Sending/Receiving */
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);
}

/*******************************************************************************
* Fn                -MCAL_USART_DeInit.
*
* Brief             -Deinitialize the USART.
*
* Retval            -None.
*
* Note              -None.
*
*/
void MCAL_USART_DeInit(void)
{
	while (!READ_BIT(UCSRA, UDRE));
	
	UBRRL = 0x00;
	CLEAR_BIT(UCSRA, MPCM);
	CLEAR_BIT(UCSRA, U2X);
	CLEAR_BIT(UCSRA, TXC);
	UCSRB &= ~(0x02);
	UCSRC = 0x86;
	UBRRL = 0x00;
	UBRRH = 0x00;
}

/*******************************************************************************
* Fn                -MCAL_UART_Send.
*
* Brief             -transmits the data through USART.
*
* Param [in]        -pTxBuffer: data to be transmitted.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_UART_SendData(uint8* TxBuffer, enum Mechanism Enable)
{
	if(Enable)
		while (!READ_BIT(UCSRA, UDRE));

	if(READ_BIT(UCSRB, UCSZ2))
	{
		/* TXB8 is the ninth data bit of the received character */
		/* Must be read before reading the low bits from UDR. */
		UCSRB |= (uint8)((*TxBuffer) & (1<<8));
		UDR = ((uint8)(*TxBuffer));
	}
	else
	{
		UDR = (uint8)(*TxBuffer);
	}
}


/*******************************************************************************
* Fn                -MCAL_UART_ReceiveData.
*
* Brief             -reads the data received by USART.
*
* Retval            -RxBuffer: data received by USART.
*
* Note              -None.
*/
uint16 MCAL_UART_ReceiveData(enum Mechanism Enable)
{
	uint16 RxBuffer = 0;
	
	if(Enable)
		while (!READ_BIT(UCSRA, RXC));
	
	if(READ_BIT(UCSRB, UCSZ2))
	{
		/* RXB8 is the ninth data bit of the received character */
		/* Must be read before reading the low bits from UDR. */
		RxBuffer = READ_BIT(UCSRB, RXB8);
		RxBuffer = UDR;
	}
	else
	{
		RxBuffer = UDR;
	}
	return RxBuffer;
}

/*******************************************************************************
* Fn                -MCAL_USART_ReceiveString.
*
* Brief             -reads the received string by USART char by char.
*
* Param [in]        -pRxBuffer: pointer to array of char to store received string.
*
* Retval            -None.
*
* Note              -to work properly it is preferred to use 8bit data in frame.
*/
void MCAL_USART_ReceiveString(uint8 *pRxBuffer)
{
	while(1)
	{
		while(!READ_BIT(UCSRA, RXC));
		
		*pRxBuffer = UDR;
		
		if(*pRxBuffer == '\0')
		{
			break;
		}
		else
		{
			pRxBuffer++;
		}
	}
}

/*******************************************************************************
* Fn                -MCAL_USART_Init.
*
* Brief             -initialize the USART according to config instance PinConfig.
*
* Param [in]        -PinConfig: pointer to USART_config that contains USART
*                               configuration.
*
* Retval            -None.
*
* Note              -None.
*
*/
void MCAL_USART_SendString(uint8 *pTxBuffer)
{
	while(*pTxBuffer !='\0')
	{
		while(!READ_BIT(UCSRA, UDRE));
		
		if(READ_BIT(UCSRB, UCSZ2))
		{
			CLEAR_BIT(UCSRB, TXB8);
			UDR = (uint8)(*pTxBuffer);
		}
		else
		{
			UDR = (*pTxBuffer);
			pTxBuffer++;
		}
	}
	
	while(!READ_BIT(UCSRA, UDRE));
	
	UDR = '\0';
}

/*******************************************************************************
* Fn                -MCAL_USART_Init.
*
* Brief             -Receive number which represent 4 bytes.
*
* Retval            -None.
*
* Note              -None.
*
*/
uint32 MCAL_UART_ReceiveNumberU32(enum Mechanism Enable)
{
	//u8 b1= MCAL_UART_ReceiveData(Enable);
	//u8 b2= MCAL_UART_ReceiveData(Enable);
	//u8 b3= MCAL_UART_ReceiveData(Enable);
	//u8 b4= MCAL_UART_ReceiveData(Enable);

	//u32 num1=0;
	//num = b1| (u32)b2<<8 | (u32)b3<<16 | (u32)b4<<24;

	uint32 num;
	uint8 *p = (uint8*)&num;
	p[0] = (uint8)MCAL_UART_ReceiveData(Enable);
	p[1] = (uint8)MCAL_UART_ReceiveData(Enable);
	p[2] = (uint8)MCAL_UART_ReceiveData(Enable);
	p[3] = (uint8)MCAL_UART_ReceiveData(Enable);
	return num;
}

/*******************************************************************************
* Fn                -MCAL_UART_SendNumberU32.
*
* Brief             -Send number which represent 4 bytes .
*
* Param [in]        -a 4 bytes of data.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_UART_SendNumberU32(uint32 num, enum Mechanism Enable)
{
	// MCAL_UART_SendData(num, Enable);
	// MCAL_UART_SendData(num>>8, Enable);
	// MCAL_UART_SendData(num>>16, Enable);
	// MCAL_UART_SendData(num>>24, Enable);

	uint8  *ptr = (uint8*)&num;
	MCAL_UART_SendData((uint8*)&ptr[0], Enable);
	MCAL_UART_SendData((uint8*)&ptr[1], Enable);
	MCAL_UART_SendData((uint8*)&ptr[2], Enable);
	MCAL_UART_SendData((uint8*)&ptr[3], Enable);
}