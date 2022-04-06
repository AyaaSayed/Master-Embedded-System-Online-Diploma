/*
 * SPI_Slave.c
 *
 * Created: 3/30/2022 6:02:05 AM
 *  Author: Aya Sayed
 */
 
 #include "SPI_Slave.h"
 
 //#define MCU_Act_As_Master
 #define MCU_Act_As_Slave

 
void SPI_Slave(void)
{	
	LCD_INIT();
	
	/* Configuration of SPI1 */
	SPI_Config_t SPI_Config;

	/* Common Configuration */
	SPI_Config.BaudRate_Prescaler = BAUDERATE_PRESCALER_4;
	SPI_Config.CLK_Phase = CLK_PHASE_SAMPLE_SETUP;
	SPI_Config.CLK_Polarity = CLK_POLARITY_RISING_FALLING;
	SPI_Config.Frame_Format = FRAME_FORMAT_MSB_FIRST;

	#ifdef MCU_Act_As_Slave
	SPI_Config.SPI_Mode = SPI_MODE_SLAVE;
	SPI_Config.IRQ_Enable = IRQ_ENABLE_NONE;
	SPI_Config.P_IRQ_CallBack = NULL;
	#endif

	MCAL_SPI_Init(&SPI_Config);
	MCAL_SPI_GPIO_Set_Pins();

	/* Set Idle High (Active High) */
	vWRITE_PIN(PORTB, PIN_4, TRUE);
	
	#ifdef MCU_Act_As_Slave
	LCD_display_String("Slave:");
	LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
	#endif

	/* Loop For Ever */
	while(1);
}

 
