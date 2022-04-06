/*
 * SPI_test.c
 *
 * Created: 3/29/2022 1:55:37 PM
 *  Author: Aya Sayed
 */
#include "SPI_Master.h"

 #define MCU_Act_As_Master
 //#define MCU_Act_As_Slave

 void delay(uint32 time)
 {
	 for (volatile uint32 i=0 ; i<time ; i++)
	 for (volatile uint8 j=0 ; j<255 ; j++);
	 
	 return;
 }
 

 
void SPI_Master(void)
{
	LCD_INIT();
	
	/* Configuration of SPI1 */
	SPI_Config_t SPI_Config;

	/* Common Configuration */
	SPI_Config.BaudRate_Prescaler = BAUDERATE_PRESCALER_4;
	SPI_Config.CLK_Phase = CLK_PHASE_SAMPLE_SETUP;
	SPI_Config.CLK_Polarity = CLK_POLARITY_RISING_FALLING;
	SPI_Config.Frame_Format = FRAME_FORMAT_MSB_FIRST;

	#ifdef MCU_Act_As_Master
	SPI_Config.SPI_Mode = SPI_MODE_MASTER;
	SPI_Config.IRQ_Enable = IRQ_ENABLE_NONE;
	SPI_Config.P_IRQ_CallBack = NULL;
	#endif

	MCAL_SPI_Init(&SPI_Config);
	MCAL_SPI_GPIO_Set_Pins();

	/* Set Idle High (Active High) */
	vWRITE_PIN(PORTB, PIN_4, TRUE);
	
	#ifdef MCU_Act_As_Master
	LCD_display_String("Master:");
	LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
	#endif

	uint8 arr[] = "Hello Slave";
	MCAL_SPI_Send_STRING(arr);
	
	/* Loop For Ever */
	while(1);
}
