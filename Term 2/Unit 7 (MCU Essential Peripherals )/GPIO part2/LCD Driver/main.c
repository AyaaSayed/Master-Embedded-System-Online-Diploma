/******************************************************************************
 *
 * LCD Driver.c
 *
 * Created: 3/4/2022 7:19:09 AM
 * Author : Aya Sayed
 *
 *******************************************************************************/

#include "LCD.h"


int main(void)
{
    LCD_INIT();
	
	LCD_display_String("Hello in Embedded System Diploma by Eng.Keroles Shenouda :)");
	_delay_ms(1000);
	LCD_Clear_Screen();
	
	LCD_display_String("Numbers Examples :");
	LCD_Real_Number(30.17);
	LCD_display_String("   ");
	
	LCD_Intger_Number(12);
	_delay_ms(1000);
	LCD_Clear_Screen();
	
    while (1);
}

