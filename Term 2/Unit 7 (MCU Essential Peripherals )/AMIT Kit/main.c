/*
 * ATmega32 Drivers.c
 *
 * Created: 3/19/2022 1:22:27 AM
 * Author : diesel
 */ 

#include "LCD.h"
#include "Keypad.h"

int main(void)
{
	LCD_INIT();
	LCD_display_String("learn in depth");
}

