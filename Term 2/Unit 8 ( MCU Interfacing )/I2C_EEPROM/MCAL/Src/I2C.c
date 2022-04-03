/*
 * I2C.c
 *
 *  Created on: Apr 1, 2022
 *      Author: Aya Sayed
 *
 *******************************************************************************
                                     Includes
*******************************************************************************/
#include "I2C.h"


/*******************************************************************************
                                Global Variables
*******************************************************************************/
static I2C_Config_t Global_I2C_Config[2];
#define I2C1_Index              0
#define I2C2_Index              1

/*
 * I2C_GPIO_Pins[x][0] >> I2Cx_SCL
 * I2C_GPIO_Pins[x][1] >> I2Cx_SDA
 */
const uint16_t I2C_GPIO_Pins[2][2] = {{GPIO_PIN_6 , GPIO_PIN_7 } ,
		                              {GPIO_PIN_10, GPIO_PIN_11}};

#define I2Cx_SCL_Index          0
#define I2Cx_SDA_Index          1


/*******************************************************************************
                                  Generic APIs
*******************************************************************************/
uint8_t I2C_Get_EventFlag(I2C_t* I2Cx, Status_t Flag)
{
	switch(Flag){
	case BUS_BUSY: return  I2Cx->SR2.BUSY ;
	case EV5  :    return  I2Cx->SR1.SB   ;
	case EV6  :    return  I2Cx->SR1.ADDR ;
	case EV9  :    return  I2Cx->SR1.ADD10;
	case EV8  :    return  I2Cx->SR1.TxE  ;
	case EV8_1:    return (I2Cx->SR1.TxE  && I2Cx->SR2.MSL   &&
						   I2Cx->SR2.BUSY && I2Cx->SR2.TRA   );
	case EV8_2:	   return (I2Cx->SR1.TxE  && I2Cx->SR1.STOPF &&
			               I2Cx->SR1.BTF  );
	case EV7  :    return  I2Cx->SR1.RxNE  ;
	case EV7_1:    return (I2Cx->SR1.RxNE && I2Cx->SR1.STOPF &&
			               I2Cx->CR1.ACK  );
	}
	return DONE;
}

void I2C_Generate_StartCondition(I2C_t* I2Cx, START_Condition_t Start)
{
	// Check the type of start (Start enable or disable or Repeated Start)
	if (Start == START_DISABLE) { I2Cx->CR1.START = FALSE; }
	if (Start == START_ENABLE ) { while (I2C_Get_EventFlag(I2Cx, BUS_BUSY)); }
	if (Start != START_DISABLE) { I2Cx->CR1.START = TRUE; }
}

void I2C_Send_Address(I2C_t* I2Cx, uint16_t Device_Address,I2C_Direction_t Direction)
{
	I2C_Config_t* I2CxConfig = NULL;
	*I2CxConfig = (I2C_Config_t)((I2Cx == I2C1)? Global_I2C_Config[I2C1_Index] : Global_I2C_Config[I2C2_Index]);

	if (I2CxConfig->Slave_Address.Slave_Address_Mode == I2C_SLAVE_ADDRESS_MODE_7_BIT)
	{
		if      (Direction == READ ) { I2Cx->DR.DR = ((Device_Address << 1) | 0X1); }
		else if (Direction == WRITE) { I2Cx->DR.DR =  (Device_Address << 1); }
		else                         { /*  Misra  */ }
	}
	else { /* Fast Mode not supported */ }
}

void I2C_Generate_StopCondition(I2C_t* I2Cx, STOP_Condition_t Stop)
{
	if      (Stop == STOP_DISABLE) { I2Cx->CR1.STOP = FALSE; }
	else if (Stop == STOP_ENABLE)  { I2Cx->CR1.STOP = TRUE ; }
	else                           { /*  Misra  */ }
}

void I2C_Generate_ACK(I2C_t* I2Cx, ACK_t ACK)
{
	if      (ACK == ACK_DISABLE) { I2Cx->CR1.ACK = FALSE; }
	else if (ACK == ACK_ENABLE)  { I2Cx->CR1.ACK = TRUE ; }
	else                         { /*  Misra  */ }
}

/*******************************************************************************
                     APIs Supported by "MCAL SPI DRIVER"
*******************************************************************************/
/*******************************************************************************
* Fn                -MCAL_I2C_Init.
*
* Brief             -Initializes I2Cx according to the specified parameters in
* 					 I2C_Config.
*
* Param [in]        -I2Cx : where x can be (1..2 depending on device used) to
* 					 select I2C peripheral.
*
* Param [in]        -I2C_Config: All I2C configuration.
*
* Retval            -None.
*
* Note              -Supported for I2C SM mode only.
* 					-Support only 7-bit address mode.
*/
void MCAL_I2C_Init  (I2C_t *I2Cx, I2C_Config_t *I2C_Config)
{
	uint32_t PCLK = MCAL_RCC_GetPCLK1Freq();

	// 1. Enable the RCC Clock
	if      (I2Cx == I2C1){ RCC->APB1ENR.I2C1EN = TRUE; Global_I2C_Config[I2C1_Index] = *I2C_Config; }
	else if (I2Cx == I2C2){ RCC->APB1ENR.I2C2EN = TRUE; Global_I2C_Config[I2C2_Index] = *I2C_Config; }
	else                  { /*  Misra  */ }

	// 2. Set I2C Mode
	if (I2C_Config->Mode == I2C_MODE_I2C_MODE)
	{
		/****************** 1. Initialize Timing ******************/
		// 1. Set Peripheral clock frequency
		I2Cx->CR2.FREQ = 0b00000;  //Clear frequencys' bits
		I2Cx->CR2.FREQ = GET_I2CFrequancy(PCLK);

		/*********** Configure Clock control register *************/
		// 2. Disable I2C peripheral to configure time
		I2Cx->CR1.PE = FALSE;

		// 3. Configure the speed in the standard mode / Fast Mode
		if ((I2C_Config->Clock_Speed == I2C_CLOCK_SPEED_50KHZ)  ||
			(I2C_Config->Clock_Speed == I2C_CLOCK_SPEED_100KHZ))
		{
			// 4. Enable standard mode
			I2Cx->CR1.SMBUS = FALSE;

			// 5. Put the standard mode calculation
			I2Cx->CCR.CCR = GET_CCR(PCLK, I2C_Config->Clock_Speed);

			/*********** Configure Rise time register *************/
			I2Cx->TRISE.TRISE = GET_I2CFrequancy(PCLK) + 1;
		}
		else { /* Fast Mode not supported */ }

		/************* 2. Configure Control register 1 ************/
		// 1. Enable Acknowledge
		I2Cx->CR1.ACK = I2C_Config->ACK_Control;

		// 2. Enable Clock stretching
		I2Cx->CR1.NOSTRETCH = I2C_Config->Stretch_Mode;

		// 3. Enable General call
		I2Cx->CR1.ENGC = I2C_Config->General_Call;

		// 4. Set I2C Mode
		I2Cx->CR1.SMBUS = I2C_Config->Mode;

		/************* 3. Configure Own address register ***********/
		if (I2C_Config->Slave_Address.Dual_Address_Mode == Dual_Address_Mode_Enable)
		{
			// 1. Enable the Dual addressing mode
			I2Cx->OAR2.ENDUAL = TRUE;

			// 2. Put the input Second address from the user to the register
			I2Cx->OAR2.ADD2 = I2C_Config->Slave_Address.Slave_Second_Address;
		}
		// 3. Put the input First address form the user to the register
		I2Cx->OAR1.ADD1_7 = I2C_Config->Slave_Address.Slave_First_Address;

		// 4. Configure Addressing mode (slave mode)
		I2Cx->OAR1.ADDMODE = I2C_Config->Slave_Address.Slave_Address_Mode;
	}
	else { /* Fast Mode not supported */}

	// 3. Set Interrupt
	if (I2C_Config->IRQ_Enable != I2C_IRQ_DISABLE)
	{
		/********************** 1. Enable IRQ **********************/
		I2Cx->CR2.ITBUFEN = TRUE;
		I2Cx->CR2.ITERREN = TRUE;
		I2Cx->CR2.ITEVTEN = TRUE;

		/**** 2. Open the global Interrupt for each peripheral *****/
		if      (I2Cx == I2C1){ NVIC_ISER->NVIC_ISER0 |= (1 <<  I2C1_EV_IRQ);
		                        NVIC_ISER->NVIC_ISER1 |= (1 << (I2C1_ER_IRQ - 32));}
		else if (I2Cx == I2C2){ NVIC_ISER->NVIC_ISER1 |= (1 << (I2C2_EV_IRQ - 32));
		                        NVIC_ISER->NVIC_ISER1 |= (1 << (I2C2_ER_IRQ - 32));}
		else                  { /*  Misra  */ }

	}

	// 4. Enable The I2C peripheral
	I2Cx->CR1.PE = TRUE;
}

/*******************************************************************************
* Fn                -MCAL_I2C_DeInit.
*
* Brief             -Resets Selected I2C Module and disable NVIC IRQs.
*
* Param [in]        -I2Cx : where x can be (1..2 depending on device used) to
*                    select I2C peripheral.
*
* Retval            -None.
*
* Note              -Reset The Module By RCC & Disable NVIC.
*/
void MCAL_I2C_DeInit(I2C_t *I2Cx)
{
	if      (I2Cx == I2C1)
	{
		RCC->APB1RSTR.I2C1RST = TRUE;
		NVIC_ICER->NVIC_ICER0 |= (1 <<  I2C1_EV_IRQ);
		NVIC_ICER->NVIC_ICER1 |= (1 << (I2C1_ER_IRQ - 32));
	}
	else if (I2Cx == I2C2)
	{
		RCC->APB1RSTR.I2C2RST = TRUE;
		NVIC_ICER->NVIC_ICER1 |= (1 << (I2C2_EV_IRQ - 32));
		NVIC_ICER->NVIC_ICER1 |= (1 << (I2C2_ER_IRQ - 32));
	}
	else                  { /*  Misra  */ }

}

/*******************************************************************************
* Fn                -MCAL_I2C_GPIO_Set_Pins.
*
* Brief             -Initializes GPIO Pins to be connected with the selected I2C.
*
* Param [in]        -I2Cx : where x can be (1..2 depending on device used) to
*                    select I2C peripheral.
*
* Retval            -None.
*
* Note              -Must open clock for AFIO & GPIO After GPIO Initialization.
*                   -Supported for I2C SM MODE only.
*/
void MCAL_I2C_GPIO_Set_Pins(I2C_t *I2Cx)
{
	GPIO_PinConfig_t I2C_GPIO_Config;
	uint16_t* GPIOPins = NULL;
	I2C_Config_t* I2CxConfig = NULL;

	*I2CxConfig = (I2C_Config_t)((I2Cx == I2C1)? Global_I2C_Config[I2C1_Index] : Global_I2C_Config[I2C2_Index]);
	GPIOPins   =     (uint16_t*)((I2Cx == I2C1)? (I2C_GPIO_Pins) : (I2C_GPIO_Pins + I2Cx_SDA_Index));

	MCAL_RCC_AFIO_EN();
	MCAL_RCC_GPIO_EN(GPIOB);

	//I2C_GPIO_Pins[x][0] >> I2Cx_SCL
	I2C_GPIO_Config.GPIO_PinNumber    = GPIOPins[I2Cx_SCL_Index];
	I2C_GPIO_Config.GPIO_MODE         = GPIO_MODE_Output_AF_OD;
	I2C_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB, &I2C_GPIO_Config);

	//I2C_GPIO_Pins[x][1] >> I2Cx_SDA
	I2C_GPIO_Config.GPIO_PinNumber    = GPIOPins[I2Cx_SDA_Index];
	I2C_GPIO_Config.GPIO_MODE         = GPIO_MODE_Output_AF_OD;
	I2C_GPIO_Config.GPIO_OUTPUT_SPEED = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB, &I2C_GPIO_Config);
}

/*******************************************************************************
* Fn                -MCAL_I2C_MASTER_TX.
*
* Brief             -Master Send data with I2C.
*
* Param [in]        -I2Cx : where x can be (1..2 depending on device used) to
*                    select I2C peripheral.
*
* Param [in]        -Device_Address : slave address.
*
* Param [in]        -pTxData : a pointer to the data which will be send.
*
* Param [in]        -Stop : select send stop bit or not.
*
* Param [in]        -Start : select send start or repeated start
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_I2C_MASTER_TX(I2C_t* I2Cx, uint16_t Device_Address, uint8_t *pTxData, uint8_t Data_Length, STOP_Condition_t Stop, START_Condition_t Start)
{
	// 1. Generate Start Condition
	I2C_Generate_StartCondition(I2Cx, Start);

	// 2. Wait for EV5 then writing DR register with Address
	while (!I2C_Get_EventFlag(I2Cx, EV5));
	I2C_Send_Address(I2Cx, Device_Address, WRITE);

	// 3. Wait for EV6 and EV_1 then writting Data1 in DR
	while (!I2C_Get_EventFlag(I2Cx, EV6));
	while (!I2C_Get_EventFlag(I2Cx, EV8_1));

	//Until EV8_2 doesn't happen (Program Stop request)
/*	while (!I2C_Get_EventFlag(I2Cx, EV8_2))
	{
		I2Cx->DR.DR = *pTxData;
		pTxData++;

		// 4. Wait for EV8
		while (!I2C_Get_EventFlag(I2Cx, EV8));
	}*/
	for (uint8_t i = 0 ; i < Data_Length ; ++i)
	{
		I2Cx->DR.DR = *pTxData;
		pTxData++;

		// 4. Wait for EV8
		while (!I2C_Get_EventFlag(I2Cx, EV8));
	}

	// 5. Generate Stop Condition
	I2C_Generate_StopCondition(I2Cx, Stop);
}

/*******************************************************************************
* Fn                -MCAL_I2C_MASTER_RX.
*
* Brief             -Master Receive  data with I2C.
*
* Param [in]        -I2Cx : where x can be (1..2 depending on device used) to
*                    select I2C peripheral.
*
* Param [in]        -Device_Address : slave address.
*
* Param [in]        -pTxData : a pointer to the data which will be send.
*
* Param [in]        -Stop : select send stop bit or not.
*
* Param [in]        -Start : select send start or repeated start
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_I2C_MASTER_RX(I2C_t* I2Cx, uint16_t Device_Address, uint8_t *pRxData, uint8_t Data_Length, STOP_Condition_t Stop, START_Condition_t Start)
{
	// 1. Generate Start Condition
	I2C_Generate_StartCondition(I2Cx, Start);

	// 2. Wait for EV5 then writing DR register with Address
	while (!I2C_Get_EventFlag(I2Cx, EV5));
	I2C_Send_Address(I2Cx, Device_Address, READ);

	// 3. Wait for EV6 and EV_1 then writing Data1 in DR
	while (!I2C_Get_EventFlag(I2Cx, EV6));

	// 4. Enable Automatic ACK
	I2C_Generate_ACK(I2Cx, ACK_ENABLE);

/*	//Until EV7_1 doesn't happen (Program Stop request)
	while (!I2C_Get_EventFlag(I2Cx, EV7_1))
	{
		// 5. Wait for EV8
		while (!I2C_Get_EventFlag(I2Cx, EV7));

		*pRxData = I2Cx->DR.DR;
		pRxData++;
	}*/
	// Loop inside the data to read it till length become zero
	for (uint8_t i=Data_Length; i>1 ; i--)
	{
		// 5. Wait for EV8
		while (!I2C_Get_EventFlag(I2Cx, EV7));

		*pRxData = I2Cx->DR.DR;
		pRxData++;
	}

	// 6. Generate NACK
	I2C_Generate_ACK(I2Cx, ACK_DISABLE);

	// 5. Generate Stop Condition
	I2C_Generate_StopCondition(I2Cx, Stop);

	// 6. Re-Enable the automatic ACK
	I2C_Config_t* I2CxConfig = NULL;
	*I2CxConfig = (I2C_Config_t)((I2Cx == I2C1)? Global_I2C_Config[I2C1_Index] : Global_I2C_Config[I2C2_Index]);
	I2C_Generate_ACK(I2Cx, I2CxConfig->ACK_Control);
}

/*******************************************************************************
* Fn                -MCAL_I2C_Slave_TX.
*
* Brief             -Slave Send data with I2C.
*
* Param [in]        -I2Cx : where x can be (1..2 depending on device used) to
*                    select I2C peripheral.
*
* Param [in]        -pTxData : a pointer to the data which will be send.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_I2C_Slave_TX(I2C_t* I2Cx, uint8_t TxData)
{
	I2Cx->DR.DR = TxData;
}

/*******************************************************************************
* Fn                -MCAL_I2C_Slave_RX.
*
* Brief             -Slave Receive  data with I2C.
*
* Param [in]        -I2Cx : where x can be (1..2 depending on device used) to
*                    select I2C peripheral.
*
* Retval            -None.
*
* Note              -None.
*/
uint8_t MCAL_I2C_Slave_RX(I2C_t* I2Cx)
{
	return I2Cx->DR.DR;
}


/*******************************************************************************
                                  IRQ Handlers
*******************************************************************************/
void I2C1_EV_IRQHandler(void)
{
	/* Interrupt handling for both master and slave mode of the device */
	uint32_t Temp_1, Temp_2, Temp_3;

	Temp_1 = I2C1->CR2.ITEVTEN;	    // Event interrupt enable
	Temp_2 = I2C1->CR2.ITBUFEN;	    // Buffer interrupt enable
	Temp_3 = I2C1->SR1.STOPF;		// Stop detection (slave mode)

	/* Handle Stop Condition Event */
	if(Temp_1 && Temp_3)
	{
		/* STOPF Cleared by software reading the SR1 register followed by a write in the CR1 register,
		 * i have already read SR1 in Temp_3
		 * then next statement i write to CR1
		 */
		I2C1->CR1.CR1 = 0x0000;
		Global_I2C_Config[I2C1_Index].P_Slave_CallBack(I2C_EV_STOP);
	}

	/********************************************************************/
	Temp_3 = I2C1->SR1.ADDR;		//ADDR

	if(Temp_1 && Temp_3)
	{
		/* clear ADDR flag
		 * In slave mode, it is recommended to perform the complete clearing sequence (READ SR1 then READ SR2) after ADDR is set.
		 */

		/* Check master mode or slave mode */
		if(I2C1->SR2.MSL)
		{ /* Master mode (Using polling mechanism not interrupt) */ }
		else
		{
			/* Slave mode */
			Global_I2C_Config[I2C1_Index].P_Slave_CallBack(I2C_EV_ADD_MATCHED);
		}
	}

	/********************************************************************/
	/* Handle TxE: Data register empty (Master request data from slave)--> slave_transmitter */
	Temp_3 = I2C1->SR1.TxE;		// TXE

	if(Temp_1 && Temp_2 && Temp_3)				// In case TXE=1, ITEVTEN=1, ITBUFEN=1
	{
		/* Check master mode or slave mode */
		if(I2C1->SR2.MSL)
		{ /* Master mode (Using polling mechanism not interrupt) */ }
		else
		{
			/* Slave mode */
			/* Check if slave in transmit mode */
			if(I2C1->SR2.TRA)		//TRA: Transmitter/receiver: 1: Data bytes transmitted
			{
				Global_I2C_Config[I2C1_Index].P_Slave_CallBack(I2C_EV_DATA_REQ);
			}
		}
	}

	/********************************************************************/
	/* Handle RxNE: Data register not empty (slave receive data)-->slave_Receiver */
	Temp_3 = I2C1->SR1.RxNE;		// RXNE

	if(Temp_1 && Temp_2 && Temp_3)				// In case RXNE=1, ITEVTEN=1, ITBUFEN=1
	{
		/* Check master mode or slave mode */
		if(I2C1->SR2.MSL)
		{ /* Master mode (Using polling mechanism not interrupt) */ }
		else
		{
			/* Slave mode */
			if(!(I2C1->SR2.TRA))		//TRA: Transmitter/receiver: 0: Data bytes received
			{
				Global_I2C_Config[I2C1_Index].P_Slave_CallBack(I2C_EV_DATA_RCV);
			}
		}
	}
}

void I2C1_ER_IRQHandler(void)
{

}

void I2C2_EV_IRQHandler(void)
{

}

void I2C2_ER_IRQHandler(void)
{

}





