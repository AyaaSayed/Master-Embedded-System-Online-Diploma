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


/*******************************************************************************
                                    APIs                                  
 *******************************************************************************/
void UART_INIT(void)
{
	// transmission speed
	CLEAR_BIT(UCSRA,U2X);   // Normal Speed

	//B- 8-Bit data
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	CLEAR_BIT(UCSRB,UCSZ2);

	//Async
	CLEAR_BIT(UCSRC,UMSEL);
	
	//NO parity
	CLEAR_BIT(UCSRC,UPM0);
	CLEAR_BIT(UCSRC,UPM1);
	
	// One stop bit
	CLEAR_BIT(UCSRC,USBS);
	
	// BaudRate 9600 F_cpu = 8MHZ
	UBRRH = 0;
	UBRRL = 51;
	
	//enable UART  receiver.
	SET_BIT(UCSRB,RXEN);

	//enable UART  transmitter .
	SET_BIT(UCSRB,TXEN);
}

void UART_Send(uint8 data)
{
	while(!(READ_BIT(UCSRA,UDRE)));
	UDR = data;
}

uint8 UART_Receive(void)
{
	while(!(READ_BIT(UCSRA,RXC)));
	return UDR;
}

void UART_SendNumberU32(uint32 num)
{
	// UART_Send(num);
	// UART_Send(num>>8);
	// UART_Send(num>>16);
	// UART_Send(num>>24);

	uint8  *ptr = (uint8*)&num;
	UART_Send(ptr[0]);
	UART_Send(ptr[1]);
	UART_Send(ptr[2]);
	UART_Send(ptr[3]);
}

uint32 UART_ReceiveNumberU32(void)
{
	//u8 b1= UART_Receive();
	//u8 b2= UART_Receive();
	//u8 b3= UART_Receive();
	//u8 b4= UART_Receive();

	//u32 num1=0;
	//num = b1| (u32)b2<<8 | (u32)b3<<16 | (u32)b4<<24;

	uint32 num;
	uint8 *p = (uint8*)&num;
	p[0] = UART_Receive();
	p[1] = UART_Receive();
	p[2] = UART_Receive();
	p[3] = UART_Receive();
	return num;
}

void UART_Send_String(char* str)
{
	while (*str != '\0')
	{
		UART_Send(*str);
		str++;
	}
}

char* UART_Receive_String(void)
{
	char data = UART_Receive();
	char str[50];
	char counter = 0 ;

	while (data != '#')
	{
		str[counter] = data;
		data = UART_Receive();
		counter ++ ;
	}
	str[counter] = '\0';
	counter = 0;
	return str;
}