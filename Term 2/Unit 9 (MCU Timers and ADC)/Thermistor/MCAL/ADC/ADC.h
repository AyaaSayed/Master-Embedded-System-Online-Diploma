/*
 * ADC.h
 *
 * Created: 4/8/2022 12:00:18 PM
 *  Author: Aya Sayed
 */ 


#ifndef ADC_H_
#define ADC_H_


/*******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "GPIO.h"

/*******************************************************************************
                             Generic Macros                                   
 *******************************************************************************/


/*******************************************************************************
                           User Configuration structures
*******************************************************************************/
typedef struct
{
	uint8 ADC_MODE;				       // specifies ADC Mode (Single conversion mode or Free running mode)
	                                   // This parameter must be set based on @ref ADC_MODE_DEFINE
	
	uint8 ADC_Voltage_REF;			   // Selects ADC VREF source
	                           	       // This parameter must be set based on @ref ADC_Voltage_REF_DEFINE
	
	uint8 ADC_Result_Presentation;	   // specifies ADC Output result presentation(right adjusted or left adjusted)
	                           	       // This parameter must be set based on @ref ADC_Result_Presentation_DEFINE
	
	uint8 ADC_PRESCALER;			   // Selects the division factor between the XTAL frequency and the input clock to ADC
	                            	   // This parameter must be set based on @ref ADC_PRESCALER_DEFINE
	
	uint8 IRQ_Enable;				   // Enable interrupt or Disable it and use polling mechanism
	                            	   // This parameter must be set based on @ref IRQ_ENABLE_DEFINE
	
	void (*P_CallBack)(void);		   //set the C Function which will be called once IRQ Happens when Conversion completed
	
}ADCConfig_t;

/******************************************************************************
                           User Define References Macros
*******************************************************************************/
/*************************** @ref ADC_MODE_DEFINE *****************************/
#define ADC_MODE_SINGLE_CONVERSION							  (uint8)(0)
#define ADC_MODE_FREE_RUNNING								  (uint8)(1<<ADCSRA)

/*********************** @ref ADC_Voltage_REF_DEFINE **************************/
#define ADC_Voltage_REF_AVCC							       (uint8)(1<<REFS0)
#define ADC_Voltage_REF_INTERNAL						       (uint8)(3<<REFS0)
#define ADC_Voltage_REF_EXTERNAL_AREF				           (uint8)(0)

/******************** @ref ADC_Result_Presentation_DEFINE *********************/
#define ADC_Result_Presentation_RIGHT_ADJUSTED			       (uint8)(0)
#define ADC_Result_Presentation_LEFT_ADJUSTED			       (uint8)(1<<ADLAR)

/************************* @ref ADC_PRESCALER_DEFINE **************************/
#define ADC_PRESCALER_DIVUDED_BY_2							   (uint8)(1<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_4							   (uint8)(2<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_8							   (uint8)(3<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_16						       (uint8)(4<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_32							   (uint8)(5<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_64							   (uint8)(6<<ADPS0)
#define ADC_PRESCALER_DIVUDED_BY_128						   (uint8)(7<<ADPS0)

/************************** @ref IRQ_ENABLE_DEFINE ****************************/
#define ADC_IRQ_ENABLE_NONE									    (uint8)(0)
#define ADC_IRQ_ENABLE_ADIE										(uint8)(1<<ADIE)


typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
}Channel_Select_t;


typedef enum
{
	Polling_ENABLE,
	Polling_DISABLE
}Polling_Mechanism_t;

/*******************************************************************************
                       APIs Supported by "MCAL ADC DRIVER"
*******************************************************************************/
void MCAL_ADC_Init  (ADCConfig_t* ADC_Config);
void MCAL_ADC_DeInit(void);

void MCAL_ADC_Start_Conversion(void);
void MCAL_ADC_Get_Result_Data(Channel_Select_t channel, uint16* data, Polling_Mechanism_t Polling);



#endif /* ADC_H_ */