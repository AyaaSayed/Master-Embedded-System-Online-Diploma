/*
 * ATmega32 Drivers.c
 *
 * Created: 3/19/2022 1:22:27 AM
 * Author : diesel
 */ 

#include "LCD.h"
#include "UART.h"

int main(void)
{
	//Initializte LCD
	LCD_INIT();
	LCD_display_String("learn in depth");
	
	//Initializte UART
	UART_INIT();
	UART_Send_String("UART INIT");
	//LCD_display_String(UART_Receive_String());

	while (1)
	{
		uint8* str;
		str = UART_Receive_String();
		LCD_display_String(str);
	
	}
}

