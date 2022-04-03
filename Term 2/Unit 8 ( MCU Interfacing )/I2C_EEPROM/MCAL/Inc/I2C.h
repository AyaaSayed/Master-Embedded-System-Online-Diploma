/*
 * I2C.h
 *
 *  Created on: Apr 1, 2022
 *      Author: Aya Sayed
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

/*******************************************************************************
                                     Includes
*******************************************************************************/
#include "RCC.h"

/*******************************************************************************
                           User Configuration structures
*******************************************************************************/
typedef struct
{
	// This parameter must be set based on @ref Dual_Address_Mode_DEFINE
	uint32_t Dual_Address_Mode;

	uint8_t  Slave_First_Address;
	uint8_t	 Slave_Second_Address;

	// This parameter must be set based on @ref I2C_SLAVE_ADDRESS_MODE_DEFINE
	uint32_t Slave_Address_Mode;
}I2C_slave_address_t;

typedef enum
{
	I2C_EV_STOP,
	I2C_EV_ADD_MATCHED,
	I2C_EV_DATA_REQ,	// APP_Layer should send data (I2C slave send data)
	I2C_EV_DATA_RCV		// APP_Layer should receive data (I2C slave receive data)
}Slave_State;

typedef struct
{
	uint32_t Clock_Speed;						// Specifies I2C clock speed
												// This parameter must be set based on @ref I2C_CLOCK_SPEED_DEFINE

	uint32_t Stretch_Mode;						// specifies Enable or Disable clock stretching in slave mode only
												// This parameter must be set based on @ref I2C_STRETCH_MODE_DEFINE

	uint32_t General_Call;						// specifies Enable or Disable General_Call
												// This parameter must be set based on @ref I2C_GENERAL_CALL_DEFINE

	uint32_t Master_Mode;			 			// specifies I2C Master mode SM mode or FM mode
												// This parameter must be set based on @ref I2C_MASTER_MODE_DEFINE

	uint32_t Mode;								// specifies I2C SMBUS mode or I2C mode
												// This parameter must be set based on @ref I2C_MODE_DEFINE

	uint32_t ACK_Control;						// Enable ACK by Hardware or Disable ACK
												// This parameter must be set based on @ref I2C_ACK_CONTROL_DEFINE

	I2C_slave_address_t	Slave_Address;			// Slave address information from user

	uint8_t IRQ_Enable;                         // specifies I2C Interrupt Requests
	                                            // This parameter must be set based on @ref IRQ_ENABLE_DEFINE

	void(*P_Slave_CallBack)(Slave_State state); // Set the C Function which will be called once IRQ Happens

}I2C_Config_t;

/******************************************************************************
                           User Define References Macros
*******************************************************************************/
/*********************** @ref Dual_Address_Mode_DEFINE ************************/
#define Dual_Address_Mode_Enable                       1U
#define Dual_Address_Mode_Disable                      0U

/********************* @ref I2C_SLAVE_ADDRESS_MODE_DEFINE *********************/
#define I2C_SLAVE_ADDRESS_MODE_7_BIT			       0U
#define I2C_SLAVE_ADDRESS_MODE_10_BIT			       1U

/************************* @ref I2C_CLOCK_SPEED_DEFINE *************************/
#define I2C_CLOCK_SPEED_50KHZ					       50000U
#define I2C_CLOCK_SPEED_100KHZ					       100000U

/************************ @ref I2C_STRETCH_MODE_DEFINE *************************/
#define I2C_STRETCH_MODE_ENABLE					       0U
#define I2C_STRETCH_MODE_DISABLE		    		   1U

/************************ @ref I2C_GENERAL_CALL_DEFINE *************************/
#define I2C_GENERAL_CALL_ENABLE					       1U
#define I2C_GENERAL_CALL_DISABLE					   0U

/************************* @ref I2C_MASTER_MODE_DEFINE *************************/
#define I2C_MASTER_MODE_SM							   0U
#define I2C_MASTER_MODE_FM							   1U

/**************************** @ref I2C_MODE_DEFINE *****************************/
#define I2C_MODE_I2C_MODE							   0U
#define I2C_MODE_SMBUS_MODE							   1U

/************************* @ref I2C_ACK_CONTROL_DEFINE *************************/
#define I2C_ACK_CONTROL_ENABLE					       1U
#define I2C_ACK_CONTROL_DISABLE	 			           0U

/**************************** @ref IRQ_ENABLE_DEFINE **************************/
#define I2C_IRQ_DISABLE	 		        	           0U
#define I2C_IRQ_ENABLE        					       1U

/******************************************************************************
                           User Define Enum
*******************************************************************************/
typedef enum
{
	START_DISABLE,
	START_ENABLE,
	START_Repeated
}START_Condition_t;

typedef enum
{
	STOP_DISABLE,
	STOP_ENABLE
}STOP_Condition_t;

typedef enum
{
	ACK_DISABLE,
	ACK_ENABLE
}ACK_t;

typedef enum
{
	WRITE,
	READ
}I2C_Direction_t;

typedef enum
{
	BUS_BUSY,	/* BUSY: Bus busy 1: Communication ongoing on the bus */
	EV5,		/* SB=1, cleared by reading SR1 register followed by writing DR register with Address */
	EV6,		/* ADDR=1, cleared by reading SR1 register followed by reading SR2 */
	EV8,		/* TxE=1, shift register not empty, data register empty, cleared by writing DR register */
	EV8_1,		/* TxE=1, shift register empty, data register empty, write Data1 in DR */
	EV8_2,      /* TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition */
	EV9,        /* ADD10=1, cleared by reading SR1 register followed by writing DR register */
	EV7,        /* RxNE=1, Cleared by reading DR register */
	EV7_1       /* RxNE=1, Cleared by reading DR register and program ACK=0 and STOP request */
}Status_t;

/*******************************************************************************
                     APIs Supported by "MCAL SPI DRIVER"
*******************************************************************************/
void    MCAL_I2C_Init  (I2C_t* I2Cx, I2C_Config_t *I2C_Config);
void    MCAL_I2C_DeInit(I2C_t* I2Cx);

void    MCAL_I2C_GPIO_Set_Pins(I2C_t* I2Cx);

void    MCAL_I2C_MASTER_TX(I2C_t* I2Cx, uint16_t Device_Address, uint8_t *pTxData, uint8_t Data_Length, STOP_Condition_t Stop, START_Condition_t Start);
void    MCAL_I2C_MASTER_RX(I2C_t* I2Cx, uint16_t Device_Address, uint8_t *pRxData, uint8_t Data_Length, STOP_Condition_t Stop, START_Condition_t Start);

void    MCAL_I2C_Slave_TX(I2C_t* I2Cx, uint8_t TxData);
uint8_t MCAL_I2C_Slave_RX(I2C_t* I2Cx);

/*******************************************************************************
                                  Generic APIs
*******************************************************************************/



/*******************************************************************************
                                  Generic Macros
*******************************************************************************/
#define GET_I2CFrequancy(PCLK1)                   (PCLK1 / 1000000)
#define GET_CCR(PCLK1, I2C_ClockFrequency)        (PCLK1 / (I2C_ClockFrequency << 1))












#endif /* INC_I2C_H_ */
