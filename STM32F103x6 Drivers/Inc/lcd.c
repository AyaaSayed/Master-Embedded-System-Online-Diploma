/*
 * lcd.c
 *
 * Created: 4/22/2021 3:01:11 PM
 *  Author: Marco
 */

#include "lcd.h"

void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void LCD_clear_screen() {
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void LCD_INIT() {

	delay_ms(20);

	// SET THE FIRST 3 PINS AS OUPUT
	PinCfg.GPIO_PinNumber = RS_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = RW_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = EN_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	// SET THE NEXT 8 PINS AS INPUT
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_Output_pp;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_DATA, &PinCfg);

	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, FALSE);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, FALSE);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, FALSE);

	delay_ms(15);

	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}


void LCD_WRITE_COMMAND(unsigned char command) {
	MCAL_GPIO_WritePort(LCD_DATA, command);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, FALSE);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, FALSE);

	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, TRUE);
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, FALSE);
}

void LCD_WRITE_CHAR(unsigned char character) {
	MCAL_GPIO_WritePort(LCD_DATA, character);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, FALSE);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, TRUE);

	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, TRUE);
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, FALSE);
}

void LCD_WRITE_STRING(char *string) {
	int count = 0;
	while (*string > 0) {
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) {
			LCD_GOTO_XY(2, 0);
		} else if (count == 32) {
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}
