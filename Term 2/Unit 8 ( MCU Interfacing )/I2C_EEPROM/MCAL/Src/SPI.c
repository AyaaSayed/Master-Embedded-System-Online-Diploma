/*
 * SPI.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Aya Sayed
 *
 *******************************************************************************
                                     Includes
*******************************************************************************/
#include "SPI.h"

/*******************************************************************************
                                Global Variables
*******************************************************************************/
static SPI_Config_t* Global_SPI_Config[2]= {NULL};
#define SPI1_Index              0
#define SPI2_Index              1

/*
 * SPI_GPIO_Pins[x][0] >> SPIx_NSS
 * SPI_GPIO_Pins[x][1] >> SPIx_SCK
 * SPI_GPIO_Pins[x][2] >> SPIx_MISO
 * SPI_GPIO_Pins[x][3] >> SPIx_MOSI
 */
const uint16_t SPI_GPIO_Pins[2][4] = {{GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6 , GPIO_PIN_7 },
		                              {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15}};
#define SPIx_NSS_Index          0
#define SPIx_SCK_Index          1
#define SPIx_MISO_Index         2
#define SPIx_MOSI_Index         3

/*******************************************************************************
                     APIs Supported by "MCAL SPI DRIVER"
*******************************************************************************/
/*******************************************************************************
* Fn                -MCAL_SPI_Init.
*
* Brief             -Initializes SPIx according to the specified parameters in
*                    SPI_Config_t.
*
* Param [in]        -SPIx: where x can be (1..2 depending on device used) to
*                    select SPI peripheral.
*
* Param [in]        -SPI_Config: All SPI configuration.
*
* Retval            -None.
*
* Note              -Supported for SPI FULL DUPLEX Master/Slave only and
* 					 NSS Hardware/Software.
* 					-You have to configure RCC to select clock for the
* 					 selected SPI Module.
*/
void MCAL_SPI_Init(SPI_t *SPIx, SPI_Config_t *SPI_Config)
{
	// 1. Enable the clock for given USART peripheral
	if      (SPIx == SPI1){ RCC->APB2ENR.SPI1EN = TRUE; Global_SPI_Config[SPI1_Index] = SPI_Config; }
	else if (SPIx == SPI2){ RCC->APB1ENR.SPI2EN = TRUE; Global_SPI_Config[SPI2_Index] = SPI_Config; }
	else                  { /*  Misra  */ }

	/*// 2. Enable SPI
	SPIx->CR1.SPE = TRUE;*/

	// 3. Set Master or Slave
	SPIx->CR1.MSTR = SPI_Config->SPI_Mode;

	// 4. Set Communication Mode
	switch (SPI_Config->Communication_Mode){
	case SPI_COMMUNICATION_MODE_2LINE_FULL_DUPLEX: SPIx->CR1.BIDIMODE = FALSE; break;
	case SPI_COMMUNICATION_MODE_2LINE_RXE_ONLY:    SPIx->CR1.RXONLY   = FALSE; break;
	case SPI_COMMUNICATION_MODE_1LINE_RX_ONLY:
		SPIx->CR1.BIDIMODE = TRUE ;
		SPIx->CR1.BIDIOE   = FALSE;
		break;
	case SPI_COMMUNICATION_MODE_1LINE_TX_ONLY:
		SPIx->CR1.BIDIMODE = TRUE;
		SPIx->CR1.BIDIOE   = TRUE;
		break;
	}

	// 5. Set Frame Format
	SPIx->CR1.LSBFIRST = SPI_Config->Frame_Format;

	// 6. Set Data size
	SPIx->CR1.DFF = SPI_Config->Frame_Size;

	// 7. Set Clock Polarity
	SPIx->CR1.CPOL = SPI_Config->CLK_Polarity;

	// 8. Set Clock Phase
	SPIx->CR1.CPHA = SPI_Config->CLK_Phase;

	// 9. Set Slave Select Management
	if      (SPI_Config->NSS == SPI_NSS_HW_SLAVE)                       {SPIx->CR2.SSOE = FALSE;}
	else if (SPI_Config->NSS == SPI_NSS_HW_MASTER_SS_OUTPUT_ENABLED)    {SPIx->CR2.SSOE = TRUE; }
	else if (SPI_Config->NSS == SPI_NSS_HW_MASTER_SS_OUTPUT_DISABLED)   {SPIx->CR2.SSOE = FALSE;}
	else if (SPI_Config->NSS == SPI_NSS_SW_SSI_RESET)                   {SPIx->CR1.SSM  = TRUE; }
	else if (SPI_Config->NSS == SPI_NSS_SW_SSI_SET){SPIx->CR1.SSM  = TRUE; SPIx->CR1.SSI = TRUE;}
	else                                                                        { /*  Misra  */ }

	// 10. Set BoudRate Pre-scaler
	SPIx->CR1.BR = SPI_Config->BaudRate_Prescaler;

	// 11. Set Interrupt
	if (SPI_Config->IRQ_Enable != SPI_IRQ_ENABLE_NONE)
	{
		if      (SPI_Config->IRQ_Enable == SPI_IRQ_ENABLE_TXEIE)  { SPIx->CR2.TXEIE  = TRUE; }
		else if (SPI_Config->IRQ_Enable == SPI_IRQ_ENABLE_ERRIE)  { SPIx->CR2.ERRIE  = TRUE; }
		else if (SPI_Config->IRQ_Enable == SPI_IRQ_ENABLE_RXNEIE) { SPIx->CR2.RXNEIE = TRUE; }
		else                                                      { /*  Misra  */ }

		// 12. Open the global Interrupt for each peripheral
		if      (SPIx == SPI1){ NVIC_ISER->NVIC_ISER1 |= (1 << (SPI1_IRQ - 32)); }
		else if (SPIx == SPI2){ NVIC_ISER->NVIC_ISER1 |= (1 << (SPI2_IRQ - 32)); }
		else                  { /*  Misra  */ }

	}
	else { /*  Misra  */ }
	// 2. Enable SPI
	SPIx->CR1.SPE = TRUE;
}

/*******************************************************************************
* Fn                -MCAL_SPI_DeInit.
*
* Brief             -Resets Selected SPI Module.
*
* Param [in]        -SPIx: where x can be (1..2 depending on device used) to
*                    select SPI peripheral.
*
* Retval            -None.
*
* Note              -Reset The Module By RCC & Disable NVIC.
*/
void MCAL_SPI_DeInit(SPI_t *SPIx)
{
	if      (SPIx == SPI1){ RCC->APB2RSTR.SPI1RST = TRUE; NVIC_ICER->NVIC_ICER1 |= (1 << (SPI1_IRQ - 32)); }
	else if (SPIx == SPI2){ RCC->APB1RSTR.SPI2RST = TRUE; NVIC_ICER->NVIC_ICER1 |= (1 << (SPI2_IRQ - 32)); }
	else                  { /*  Misra  */ }

}

/*******************************************************************************
* Fn                -MCAL_SPI_Send_Data.
*
* Brief             -Send Buffer With SPI.
*
* Param [in]        -SPIx: where x can be (1..2 depending on device used) to
*                    select SPI peripheral.
*
* param [in] 		-P_TxBuffer: Pointer to buffer Which holds the TX data.
*
* Param [in]        -Mechanism is defined at  @Ref Mechanism_define.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_SPI_Send_Data(SPI_t *SPIx, uint16_t *P_TxBuffer, uint8_t Mechanism)
{
	// 1. Wait until TXE (Transmit data register empty)
	if (Mechanism == Polling_Mechanism) { while(!(SPIx->SR.TXE)); }
	else                                { /*  Misra  */ }

	// 2. Start transmission, Write data to SPI data register
	SPIx->DR.DR = *(P_TxBuffer);
}

/*******************************************************************************
* Fn                -MCAL_SPI_Recieve_Data.
*
* Brief             -Receive Buffer With SPI.
*
* Param [in]        -SPIx: where x can be (1..2 depending on device used) to
*                    select SPI peripheral.
*
* param [in] 		-P_TxBuffer: Pointer to buffer Which holds the RX data.
*
* Param [in]        -Mechanism is defined at  @Ref Mechanism_define.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_SPI_Recieve_Data(SPI_t *SPIx, uint16_t *P_RxBuffer, uint8_t Mechanism)
{
	// 1. Wait until RXNE (Read data register not empty)
	if (Mechanism == Polling_Mechanism) { while(!(SPIx->SR.RXNE)); }
	else                                { /*  Misra  */ }

	// 2. Start reception, Write data to SPI data register
	*(P_RxBuffer) = (uint16_t)SPIx->DR.DR;
}

/*******************************************************************************
* Fn                -MCAL_SPI_TX_RX.
*
* Brief             -Transmit and Receive Data.
*
* Param [in]        -SPIx: where x can be (1..2 depending on device used) to
*                    select SPI peripheral.
*
* param [in] 		-P_TxBuffer: Pointer to buffer Which holds the RX data.
*
* Param [in]        -Mechanism is defined at  @Ref Mechanism_define.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_SPI_TX_RX(SPI_t *SPIx, uint16_t *P_TxBuffer, uint8_t Mechanism)
{
	// 1. Wait until TXE (Transmit data register empty)
	if (Mechanism == Polling_Mechanism) { while(!(SPIx->SR.TXE)); }
	else                                { /*  Misra  */ }

	// 2. Start transmission, Write data to SPI data register
	SPIx->DR.DR = *(P_TxBuffer);

	// 3. Wait until RXNE (Read data register not empty)
	if (Mechanism == Polling_Mechanism) { while(!(SPIx->SR.RXNE)); }
	else                                { /*  Misra  */ }

	// 4. Start reception, Write data to SPI data register
	*(P_TxBuffer) = (uint16_t)SPIx->DR.DR;
}

/*******************************************************************************
* Fn                -MCAL_SPI_GPIO_Set_Pins.
*
* Brief             -Initializes GPIO Pins to be connected with the selected SPI.
*
* Param [in]        -SPIx: where x can be (1..2 depending on device used) to
*                    select SPI peripheral.
*
* Retval            -None.
*
* Note              -Must open clock for AFIO & GPIO After GPIO Initialization.
*                   -Supported for SPI FULL DUPLEX Master/Slave only & NSS Hardware/Software.
*/
void MCAL_SPI_GPIO_Set_Pins(SPI_t *SPIx)
{
	GPIO_PinConfig_t SPI_GPIO_Config;
	GPIO_t* GPIOx = NULL;
	uint16_t* GPIOPins = NULL;
	SPI_Config_t* SPIxConfig = NULL;

	SPIxConfig = (SPI_Config_t*)((SPIx == SPI1)? Global_SPI_Config[SPI1_Index] : Global_SPI_Config[SPI2_Index]);
	GPIOPins   =     (uint16_t*)((SPIx == SPI1)? (SPI_GPIO_Pins) : (SPI_GPIO_Pins + 1));
	GPIOx      =       (GPIO_t*)((SPIx == SPI1)? GPIOA : GPIOB);

	//Enable GPIOA and AFIO
	MCAL_RCC_AFIO_EN();
	MCAL_RCC_GPIO_EN(GPIOx);

	if (SPIxConfig->SPI_Mode == SPI_MODE_MASTER)
	{
		// SPI_GPIO_Pins[x][0] >> SPIx_NSS
		if (SPIxConfig->NSS == SPI_NSS_HW_MASTER_SS_OUTPUT_DISABLED)
		{
			SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_NSS_Index];
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_Iuput_AF;
			SPI_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
		}
		else if (SPIxConfig->NSS == SPI_NSS_HW_MASTER_SS_OUTPUT_ENABLED)
		{
			SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_NSS_Index];
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_Output_AF_PP;
			SPI_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
		}
		else { /* Misra */ }

		// SPI_GPIO_Pins[x][1] >> SPIx_SCK
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_SCK_Index];
		SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_Output_AF_PP;
		SPI_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);

		// SPI_GPIO_Pins[x][2] >> SPIx_MISO
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_MISO_Index];
		SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_Input_FLO;
		SPI_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);

		// SPI_GPIO_Pins[x][3] >> SPIx_MOSI
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_MOSI_Index];
		SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_Output_AF_PP;
		SPI_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
	}
	else if (SPIxConfig->SPI_Mode == SPI_MODE_SLAVE)
	{
		if (SPIxConfig->NSS == SPI_NSS_HW_SLAVE)
		{
			// SPI_GPIO_Pins[x][0] >> SPIx_NSS
			SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_NSS_Index];
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_Iuput_AF;
			SPI_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
			MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
		}
		// SPI_GPIO_Pins[x][1] >> SPIx_SCK
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_SCK_Index];
		SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_Iuput_AF;
		SPI_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);

		// SPI_GPIO_Pins[x][2] >> SPIx_MISO
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_MISO_Index];
		SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_Output_AF_PP;
		SPI_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);

		// SPI_GPIO_Pins[x][3] >> SPIx_MOSI
		SPI_GPIO_Config.GPIO_PinNumber = GPIOPins[SPIx_MOSI_Index];
		SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_Iuput_AF;
		SPI_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_Input;
		MCAL_GPIO_Init(GPIOx, &SPI_GPIO_Config);
	}
	else { /* Misra */ }
}


/*******************************************************************************
                                  IRQ Handlers
*******************************************************************************/
void SPI1_IRQHandler(void)
{
	Global_SPI_Config[SPI1_Index]->P_IRQ_CallBack();
}

void SPI2_IRQHandler(void)
{
	Global_SPI_Config[SPI2_Index]->P_IRQ_CallBack();
}

