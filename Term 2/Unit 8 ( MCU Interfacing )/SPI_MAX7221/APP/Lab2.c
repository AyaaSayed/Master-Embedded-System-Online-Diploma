/*
 * Lab2.c
 *
 * Created: 3/30/2022 7:47:59 AM
 *  Author: Aya Sayed
 */ 
#include "Lab2.h"

void delay(uint32 time)
{
	for (volatile uint32 i=0 ; i<time ; i++)
	for (volatile uint8 j=0 ; j<255 ; j++);
	
	return;
}

void execute(uint8 cmd, uint8 data)
{
	vWRITE_PIN(B, SS, FALSE);
	
	MCAL_SPI_Send_Data(&cmd, Polling_Mechanism_EN);
	MCAL_SPI_Send_Data(&data, Polling_Mechanism_EN);
	
	vWRITE_PIN(B, SS, TRUE);
}

void SPI_lab2(void)
{
	/* Replace with your application code */
	unsigned char counter = 0;
	unsigned char index_display;
	
	/* Configuration of SPI1 */
	SPI_Config_t SPI_Config;
	SPI_Config.BaudRate_Prescaler = BAUDERATE_PRESCALER_16;
	SPI_Config.CLK_Phase          = CLK_PHASE_SAMPLE_SETUP;
	SPI_Config.CLK_Polarity       = CLK_POLARITY_RISING_FALLING;
	SPI_Config.Frame_Format       = FRAME_FORMAT_MSB_FIRST;
	SPI_Config.CLK_Speed          = CLK_SPEED_LOW;
	SPI_Config.IRQ_Enable         = IRQ_ENABLE_NONE;
	SPI_Config.P_IRQ_CallBack     = NULL;
	SPI_Config.SPI_Mode           = SPI_MODE_MASTER;
	MCAL_SPI_Init(&SPI_Config);

	 execute(0x09, 0xFF);
	 execute(0x0A, 0xFF);
	 execute(0x0B, 0xF7);
	 execute(0x0C, 0x01);
	 
	 while (1)
	 {
		 for (index_display = 1; index_display < 9; index_display++)
		 execute(index_display, counter++);
		 delay(1000);
	 }
}