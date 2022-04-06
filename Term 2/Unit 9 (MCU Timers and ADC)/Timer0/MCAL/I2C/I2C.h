/*
 * I2C.h
 *
 * Created: 4/4/2022 8:12:25 AM
 *  Author: Aya Sayed
 */ 


#ifndef I2C_H_
#define I2C_H_

/*******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "GPIO.h"

/*******************************************************************************
                             Generic Macros                                   
 *******************************************************************************/
#define MCU_Act_As_MASTER
//#define MCU_Act_As_SLAVE

/*******************************************************************************
                           User Configuration structures
*******************************************************************************/
typedef struct
{
	uint8 SCL_Clock;						// Specifies I2C SCL clock
											// This parameter should be set by the user

	uint8 Prescaler;						// specifies Set the Pre-scaler
											// This parameter must be set based on @ref I2C_PRESCALER_DEFINE

	uint8 Mode;								// specifies I2C SMBUS mode or I2C mode
											// This parameter must be set based on @ref I2C_MODE_DEFINE

	uint8 ACK_Control;						// Enable ACK by Hardware or Disable ACK
											// This parameter must be set based on @ref I2C_ACK_CONTROL_DEFINE
   
    uint8 General_Call;						// specifies Enable or Disable General_Call
											// This parameter must be set based on @ref I2C_GENERAL_CALL_DEFINE

	uint8 Slave_Address;					// Slave address information from user

	uint8 IRQ_Enable;                       // specifies I2C Interrupt Requests
											// This parameter must be set based on @ref IRQ_ENABLE_DEFINE

	void(*P_Slave_CallBack)(void);	        // Set the C Function which will be called once IRQ Happens

}I2C_Config_t;

/******************************************************************************
                           User Define References Macros
*******************************************************************************/
/************************** @ref I2C_PRESCALER_DEFINE *************************/
#define I2C_Prescaler_1                                0U
#define I2C_Prescaler_4                                1U
#define I2C_Prescaler_16                               2U
#define I2C_Prescaler_64                               3U

/************************* @ref I2C_ACK_CONTROL_DEFINE *************************/
#define I2C_ACK_CONTROL_ENABLE					       1U
#define I2C_ACK_CONTROL_DISABLE	 			           0U

/************************* @ref I2C_MASTER_MODE_DEFINE *************************/
#define I2C_MODE_MASTER								   0U
#define I2C_MODE_SLAVE								   1U

/**************************** @ref IRQ_ENABLE_DEFINE **************************/
#define I2C_IRQ_DISABLE	 		        	           0U
#define I2C_IRQ_ENABLE        					       1U

/************************ @ref I2C_GENERAL_CALL_DEFINE *************************/
#define I2C_GENERAL_CALL_ENABLE					       1U
#define I2C_GENERAL_CALL_DISABLE					   0U


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

/*******************************************************************************
                     APIs Supported by "MCAL SPI DRIVER"
*******************************************************************************/
void  MCAL_I2C_Init  (I2C_Config_t *I2C_Config);

void MCAL_I2C_StartCondition(void);
void MCAL_I2C_StopCondition (void);

void  MCAL_I2C_TX(uint8* pTxData);
void  MCAL_I2C_RX(uint8* pRxData);




/*******************************************************************************
                                  Generic Macros
*******************************************************************************/
#define GET_I2CFrequancy(SCL_FREQ, Pre_scaler)                   (uint8)(((F_CPU / SCL_FREQ) - 16) / (2 * Pre_scaler))

#define SCL  PC0
#define SDA  PC1

#endif /* I2C_H_ */