
#include "UART.h"

#define UARTDR *((volatile unsigned int* const)((unsigned int)0x101f1000))

void UART_SEND_DATA(unsigned char* p_tx_string)
{
	while ( *p_tx_string  != '\0' )
	{
		UARTDR = *p_tx_string;
		p_tx_string++;
	}
}
