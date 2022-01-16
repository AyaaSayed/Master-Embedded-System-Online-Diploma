
#include "UART.h"

unsigned char string_buffer[50] = "Learn_in_depth < Aya Sayed >";
unsigned char sting;

int main()
{
	UART_SEND_DATA(string_buffer);
}