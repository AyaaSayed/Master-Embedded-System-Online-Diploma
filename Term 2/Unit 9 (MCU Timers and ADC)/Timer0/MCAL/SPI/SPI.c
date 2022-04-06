/*
 * SPI.c
 *
 * Created: 3/29/2022 8:49:39 AM
 *  Author: Aya Sayed
 *
 *******************************************************************************
                                   Includes
 *******************************************************************************/
#include "SPI.h"

/*******************************************************************************
                                Global Variables
*******************************************************************************/
SPI_Config_t *G_SPI_Config = NULL;

/*******************************************************************************
                     APIs Supported by "MCAL SPI DRIVER"
*******************************************************************************/
/*******************************************************************************
* Fn                -MCAL_SPI_Init.
*
* Brief             -Initializes SPIx according to the specified parameters in
*                    SPI_Config_t.
*
* Param [in]        -SPI_Config: All SPI configuration.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_SPI_Init(SPI_Config_t *SPI_Config)
{	
   /* Add all configuration to the global config to use it with all driver */
	G_SPI_Config = SPI_Config;
	
	/* 1. Set Master or Slave Pins */
	MCAL_SPI_GPIO_Set_Pins();
	
	/* 2. Set Master or Slave */
	SPCR |= SPI_Config->SPI_Mode;
	
	/* 3. Set Frame format */
	SPCR |= SPI_Config->Frame_Format;

	/* 4. Set Clock Polarity */
	SPCR |= SPI_Config->CLK_Polarity;

	/* 5. Set Clock Phase */
	SPCR |= SPI_Config->CLK_Phase;
	
	/* Check If Double Speed Selected to set the BaudRate Pre-scaler */
	if (SPI_Config->CLK_Speed == CLK_SPEED_HIGH)
	{
		/* 6. Set BoudRate Pre-scaler */
		SPCR |= SPI_Config->BaudRate_Prescaler;
		SET_BIT(SPSR, SPI2X);
	}
	else
	{
		/* 6. Set BoudRate Pre-scaler */
		SPCR |= SPI_Config->BaudRate_Prescaler;
	}
	
	/* Check If IRQ Enabled */
	if (SPI_Config->IRQ_Enable != IRQ_ENABLE_NONE)
	{
		/* Open Global Interrupt */
		SET_BIT(SREG, I);
		
		/* 7. Open Interrupt */
		SPCR |= SPI_Config->IRQ_Enable;
	}
	else
	{
		/* 7. Disable Interrupt */
		SPCR |= SPI_Config->IRQ_Enable;
	}
	/* 8. Enable the SPI */
	SPCR |= (1<<SPE);
}


/*******************************************************************************
* Fn                -MCAL_SPI_DeInit.
*
* Brief             -Resets Selected SPI Module.
*
* Retval            -None.
*
* Note              -Reset The Module By RCC & Disable NVIC.
*/
void MCAL_SPI_DeInit(void)
{
	SPCR = 0x00;
	CLEAR_BIT(SPSR, SPI2X);
}

/*******************************************************************************
* Fn                -MCAL_SPI_Send_Data.
*
* Brief             -Send Buffer With SPI.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_SPI_GPIO_Set_Pins(void)
{
	/*
	 * Port Pin Alternate Functions
	 *   PB7      SCK  (SPI Bus Serial Clock)
	 *   PB6      MISO (SPI Bus Master Input/Slave Output)
	 *   PB5      MOSI (SPI Bus Master Output/Slave Input)
	 *   PB4      SS   (SPI Slave Select Input) 
	 */
	
	/* Master */
	if (G_SPI_Config->SPI_Mode == SPI_MODE_MASTER)
	{
		/* PB7      SCK: Master Clock output */
		vINTIAL_PIN_OUTPUT(B, PIN_7, OUT_OFF);
		
		/* PB6      MISO: Master Data input */
		vINTIAL_PIN_INPUT(B, PIN_6, Pullup_ON);
		
		/* PB5      MOSI: SPI Master Data output */
		vINTIAL_PIN_OUTPUT(B, PIN_5, OUT_OFF);
		
		/* PB4      SS: SPI Master Data Output */
		vINTIAL_PIN_OUTPUT(B, PIN_4, OUT_OFF);
	}
	/* Slave */
	else 
	{
		/* PB7      SCK:  Slave Clock input pin */
		vINTIAL_PIN_INPUT(B, PIN_7, Pullup_ON);
		
		/* PB6      MISO: Slave Data output pin */
		vINTIAL_PIN_OUTPUT(B, PIN_6, OUT_OFF);
		
		/* PB5      MOSI: Slave Data input */
		vINTIAL_PIN_INPUT(B, PIN_5, Pullup_OFF);
		
		/* PB4      SS: SPI Slave Select input */
		vINTIAL_PIN_INPUT(B, PIN_4, Pullup_OFF);
	}
}


/*******************************************************************************
* Fn                -MCAL_SPI_Recieve_Data.
*
* Brief             -Receive Buffer With SPI.
*
* param [in] 		-P_TxBuffer: Pointer to buffer Which holds the RX data.
*
* Param [in]        -Mechanism is defined at  @Ref Mechanism_define.
*
* Retval            -None.
*
* Note              -None.
*/
uint8 MCAL_SPI_Send_Data(uint8 *P_TxBuffer, enum Mechanism Enable)
{
	/* Start transmission, Write data to SPI data register */
	SPDR = (uint8)(*P_TxBuffer);
	
	/* Wait for transmission complete */
	if (Enable == Polling_Mechanism_EN)
	{
		while(!READ_BIT(SPSR, SPIF));
	}
	return SPDR;
}


/*******************************************************************************
* Fn                -MCAL_SPI_TX_RX.
*
* Brief             -Transmit and Receive Data.
*
* param [in] 		-P_TxBuffer: Pointer to buffer Which holds the RX data.
*
* Param [in]        -Mechanism is defined at  @Ref Mechanism_define.
*
* Retval            -None.
*
* Note              -None.
*/
uint8 MCAL_SPI_Recieve_Data (uint8* P_RxBuffer, enum Mechanism Enable)
{
	/* Start Receive */
	SPDR = (uint8)(*P_RxBuffer);
	
	/* Wait for Reception  complete */
	if (Enable == Polling_Mechanism_EN)
	{
		while(!READ_BIT(SPSR, SPIF));
	}
	
	return SPDR;
}
/*******************************************************************************
* Fn                -MCAL_SPI_GPIO_Set_Pins.
*
* Brief             -Initializes GPIO Pins to be connected with the selected SPI.
*
* Retval            -None.
*
* Note              -Must open clock for AFIO & GPIO After GPIO Initialization.
*                   -Supported for SPI FULL DUPLEX Master/Slave only & NSS Hardware/Software.
*/
uint8 MCAL_SPI_TX_RX(uint8 *P_TxBuffer, enum Mechanism Enable)
{
	/* Start transmission, Write data to SPI data register */
	SPDR = (uint8)(*P_TxBuffer);
	
	/* Wait for transmission complete */
	if (Enable == Polling_Mechanism_EN)
	{
		while(!READ_BIT(SPSR, SPIF));
	}
	
	/* Start Receive */
	SPDR = (uint8)(*P_TxBuffer);
	
	/* Wait for Reception  complete */
	if (Enable == Polling_Mechanism_EN)
	{
		while(!READ_BIT(SPSR, SPIF));
	}
	
	return SPDR;
}


 void MCAL_SPI_Send_STRING(uint8* str)
 {
	 while(*str != '\0')
	 {
		 MCAL_SPI_Send_Data(str++, Polling_Mechanism_EN);
	 }
 }
 
/*******************************************************************************
                                  IRQ Handlers
*******************************************************************************/
ISR(SPI_STC_vect)
{
	G_SPI_Config->P_IRQ_CallBack();
}
