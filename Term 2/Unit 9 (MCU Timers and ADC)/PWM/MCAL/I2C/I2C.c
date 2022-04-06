/*
 * I2C.c
 *
 * Created: 4/4/2022 8:12:14 AM
 *  Author: Aya Sayed
 *
 *******************************************************************************
                                     Includes
*******************************************************************************/
#include "I2C.h"

/*******************************************************************************
                     APIs Supported by "MCAL SPI DRIVER"
*******************************************************************************/
/*******************************************************************************
* Fn                -MCAL_I2C_Init.
*
* Brief             -Initializes I2Cx according to the specified parameters in
* 					 I2C_Config.
*
* Param [in]        -I2C_Config: All I2C configuration.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_I2C_Init  (I2C_Config_t *I2C_Config)
{
	/***************** 1. Initialize Bit Rate *****************/
	// 1. Set Peripheral clock frequency
	TWBR  = 0x00;  //Clear frequencys' bits
	TWSR |= I2C_Config->Prescaler << TWPS0;
	
	switch(I2C_Config->Prescaler){
	case I2C_Prescaler_1:
		TWBR  = GET_I2CFrequancy(I2C_Config->SCL_Clock, 1);
		break;
	case I2C_Prescaler_4:
		TWBR  = GET_I2CFrequancy(I2C_Config->SCL_Clock, 4);
		break;
	case I2C_Prescaler_16:
		TWBR  = GET_I2CFrequancy(I2C_Config->SCL_Clock, 16);
		break;
	case I2C_Prescaler_64:
		TWBR  = GET_I2CFrequancy(I2C_Config->SCL_Clock, 64);
		break;	
	}
	
	/************* 2. Configure Control register  ************/
	// 1. Enable TWI Interrupt
	SET_BIT(TWCR, TWINT);

	// 2. Disable General call
	CLEAR_BIT(TWAR, TWGCE);
	
	// 3. Enable the global Interrupt for each peripheral *****/
	SET_BIT(TWCR, TWIE);

	// 4. Enable The I2C peripheral
	SET_BIT(TWCR, TWEN);
	
	// 5. Enable ACK
	if (I2C_Config->ACK_Control == I2C_ACK_CONTROL_ENABLE)
		SET_BIT(TWCR, TWEA);
	else
		CLEAR_BIT(TWCR, TWEA);
		
	/****************** 3. Set Slave address  *****************/
	TWAR = I2C_Config->Slave_Address;
	while(!READ_BIT(TWCR, TWINT));
}

/*******************************************************************************
* Fn                -MCAL_I2C_GPIO_Set_Pins.
*
* Brief             -Initializes GPIO Pins to be connected with the selected I2C.
*
* Retval            -None.
*
* Note              -None.
*/
void  MCAL_I2C_GPIO_Set_Pins(void)
{
}

/*******************************************************************************
* Fn                -MCAL_I2C_TX.
*
* Brief             -Send data with I2C.
*
* Param [in]        -pTxData : a pointer to the data which will be send.
*
* Retval            -None.
*
* Note              -None.
*/
void  MCAL_I2C_TX(uint8 *pTxData)
{
	SET_BIT(TWCR, TWINT);
	TWDR = *pTxData;
	while(!READ_BIT(TWCR, TWINT));
}

/*******************************************************************************
* Fn                -MCAL_I2C_RX.
*
* Brief             -Receive  data with I2C.
*
* Param [in]        -pTxData : a pointer to the data which will be Receive.
*
* Retval            -None.
*
* Note              -None.
*/
void  MCAL_I2C_RX(uint8* pRxData)
{
	SET_BIT(TWCR, TWINT);
	*pRxData = TWDR;
	while(!READ_BIT(TWCR, TWINT));
}

/*******************************************************************************
* Fn                -MCAL_I2C_StartCondition.
*
* Brief             -Generate Start Contion.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_I2C_StartCondition(void)
{
	SET_BIT(TWCR, TWINT);
	SET_BIT(TWCR, TWSTA);
	while(!READ_BIT(TWCR, TWINT));
}

/*******************************************************************************
* Fn                -MCAL_I2C_StopCondition.
*
* Brief             -Generate Stop Contion.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_I2C_StopCondition(void)
{
	SET_BIT(TWCR, TWINT);
	SET_BIT(TWCR, TWSTO);
	while(!READ_BIT(TWCR, TWINT));
}
