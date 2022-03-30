/*
 * Lab1.c
 *
 * Created: 3/30/2022 7:47:44 AM
 *  Author: diesel
 */ 

#include "Lab1.h"
void delay(uint32 time)
{
	for (volatile uint32 i=0 ; i<time ; i++)
	for (volatile uint8 j=0 ; j<255 ; j++);
	
	return;
}
void SPI_lab1(void)
{
	uint8 ch = 0;
	
	DDRA = 0xFF;
	
	/* Configuration of SPI1 */
	SPI_Config_t SPI_Config;
	SPI_Config.BaudRate_Prescaler = BAUDERATE_PRESCALER_16;
	SPI_Config.CLK_Phase          = CLK_PHASE_SAMPLE_SETUP;
	SPI_Config.CLK_Polarity       = CLK_POLARITY_RISING_FALLING;
	SPI_Config.Frame_Format       = FRAME_FORMAT_MSB_FIRST;
	SPI_Config.CLK_Speed          = CLK_SPEED_LOW;
	SPI_Config.IRQ_Enable         = IRQ_ENABLE_NONE;
	SPI_Config.P_IRQ_CallBack     = NULL;
	
	#if (MCU == Master)
	SPI_Config.SPI_Mode = SPI_MODE_MASTER;
	MCAL_SPI_Init(&SPI_Config);
	
	for (ch = 0; ch <=100; ch++)
	{
		delay(100);
		PORTA = MCAL_SPI_Send_Data(&ch, Polling_Mechanism_EN);
	}
	#elif (MCU == Slave)
	SPI_Config.SPI_Mode = SPI_MODE_SLAVE;
	MCAL_SPI_Init(&SPI_Config);
	
	for (ch = 0; ch <=100; ch++)
	{
		PORTA = MCAL_SPI_Recieve_Data(&ch, Polling_Mechanism_EN);
	}
    #endif
	
	
	
}