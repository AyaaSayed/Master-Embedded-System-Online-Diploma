/*
 * SPI_Transmitter_between_2MCU.c
 *
 *  Created on: Mar 29, 2022
 *      Author: Aya Sayed
 *
 *******************************************************************************
                                   Includes
*******************************************************************************/
#include "SPI_Transmitter_between_2MCU.h"

//#define MCU_Act_As_Master
#define MCU_Act_As_Slave

/*******************************************************************************
                                Global Variables
*******************************************************************************/
extern const uint16_t SPI_GPIO_Pins[2][4];
uint16_t data;


/*******************************************************************************
                                  APP Function
*******************************************************************************/
void USART1_CallBack(void)
{
#ifdef MCU_Act_As_Master
	MCAL_UART_ReceiveData(USART1, &data, Interrupt_Mechanism);
	MCAL_UART_SendData   (USART1, &data, Polling_Mechanism);

	//Send to SPI1
	MCAL_GPIO_WritePin(GPIOA, SPI_GPIO_Pins[SPI1_Index][SPIx_NSS_Index], FALSE);
	MCAL_SPI_TX_RX(SPI1, &data, Polling_Mechanism);
	MCAL_GPIO_WritePin(GPIOA, SPI_GPIO_Pins[SPI1_Index][SPIx_NSS_Index], TRUE );
#endif
}

void SPI1_CallBack(void)
{
#ifdef MCU_Act_As_Slave
	/* If RX Buffer Not Empty Interrupt */
	if(SPI1->SR.RXNE)
	{
		/* Receive data */
		MCAL_SPI_Recieve_Data(SPI1, &data, Polling_Mechanism);

		/* Send the Received data to the terminal to see it */
		MCAL_UART_SendData(USART1, &data, Polling_Mechanism);
	}
#endif
}

void SPI_Transmitter_between_2MCU(void)
{
	/************************************************************/
	// Configuration of USART1
	USART_Config_t UART1_Config;
	UART1_Config.BaudRate       = UART_BaudRate_115200;
	UART1_Config.HW_FlowControl = UART_HW_FlowControl_NONE;
	UART1_Config.IRQ_Enable     = UART_IRQ_Enable_RXNEIE;
	UART1_Config.P_IRQ_CallBack = USART1_CallBack;
	UART1_Config.Parity         = UART_Parity_Disable;
	UART1_Config.Payload_Length = UART_Payload_Length_8B;
	UART1_Config.StopBits       = UART_StopBits_1;
	UART1_Config.USART_Mode     = UART_Mode_TX_RX;

	MCAL_UART_Init(USART1, &UART1_Config);
	MCAL_UART_GPIO_Set_Pins(USART1);

    /************************************************************/
	// Configuration of SPI1
	SPI_Config_t SPI1_Config;
	SPI1_Config.CLK_Phase          = SPI_CLK_PHASE_SECOND;
	SPI1_Config.CLK_Polarity       = SPI_CLK_POLARITY_IDLE_HIGH;
	SPI1_Config.Frame_Size         = SPI_FRAME_SIZE_8BIT;
	SPI1_Config.Frame_Format       = SPI_FRAME_FORMAT_MSB_FIRST;
	SPI1_Config.BaudRate_Prescaler = SPI_BAUDERATE_PRESCALER_8;    //Assume by default PCLK2 is 8MHZ
	SPI1_Config.Communication_Mode = SPI_COMMUNICATION_MODE_2LINE_FULL_DUPLEX;

#ifdef MCU_Act_As_Master
	SPI1_Config.SPI_Mode       = SPI_MODE_MASTER;
	SPI1_Config.NSS            = SPI_NSS_SW_SSI_SET;
	SPI1_Config.IRQ_Enable     = SPI_IRQ_ENABLE_NONE;
	SPI1_Config.P_IRQ_CallBack = NULL;

	//Configure SS on PA4 by GPIO
	GPIO_PinConfig_t Pin_Config;
	Pin_Config.GPIO_PinNumber    = SPI_GPIO_Pins[SPI1_Index][SPIx_NSS_Index];
	Pin_Config.GPIO_MODE         = GPIO_MODE_Output_pp;
	Pin_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOA, &Pin_Config);

	//Force the slave select (High) Idle Mode
	MCAL_GPIO_WritePin(GPIOA, SPI_GPIO_Pins[SPI1_Index][SPIx_NSS_Index], TRUE);
#endif

#ifdef MCU_Act_As_Slave
	SPI1_Config.SPI_Mode       = SPI_MODE_SLAVE;
	SPI1_Config.IRQ_Enable     = SPI_IRQ_ENABLE_RXNEIE;
	SPI1_Config.NSS            = SPI_NSS_HW_SLAVE;
	SPI1_Config.P_IRQ_CallBack = SPI1_CallBack;
#endif

	MCAL_SPI_Init(SPI1, &SPI1_Config);
	MCAL_SPI_GPIO_Set_Pins(SPI1);

	while(1);
}



