/*
 * ADC.c
 *
 * Created: 4/8/2022 12:00:32 PM
 *  Author: Aya Sayed
 *
 *******************************************************************************
                                     Includes
 *******************************************************************************/ 
#include "ADC.h"

/*******************************************************************************
                                Global Variables
*******************************************************************************/
ADCConfig_t Global_ADC_Config;

/*******************************************************************************
                       APIs Supported by "MCAL ADC DRIVER"
*******************************************************************************/
/*******************************************************************************
* Fn                -MCAL_ADC_Init.
*
* Brief             -Initializes ADC according to the specified parameters in
					 ADC_Config.
*
* Param [in]        -ADC_Config: a pointer to ADC_CONFIG_t structure that contains
* 					 the configuration information for the specified ADC Module.
*
* Retval            -None.
*
* Note              -Supported for Single conversion mode or Free running mode only.
					-ADC requires Clock Between 50khz and 200khz.
*/
void MCAL_ADC_Init  (ADCConfig_t* ADC_Config)
{
	Global_ADC_Config = *ADC_Config;
	
	// 1. Select ADC Mode
	ADCSRA |= ADC_Config->ADC_MODE;
	
	// 2. Select VREF Source
	ADMUX |= ADC_Config->ADC_Voltage_REF;
	
	// 3. Select Result Presentation
	ADMUX |= ADC_Config->ADC_Result_Presentation;
	
	// 4. Select ADC Clock PreScaler
	ADMUX |= ADC_Config->ADC_PRESCALER;
	
	// 5. Configure Enable or Disable IRQ
	ADCSRA |= ADC_Config->IRQ_Enable;
	
	if (ADC_Config->IRQ_Enable == ADC_IRQ_ENABLE_ADIE)
		sei();
	
	// 6. Enable ADC Module
	SET_BIT(ADCSRA, ADEN);
	
	// 7. start Conversion With ADC FREE Running mode
	if(ADC_Config->ADC_MODE == ADC_MODE_FREE_RUNNING)
		SET_BIT(ADCSRA, 6);
}

/*******************************************************************************
* Fn                -MCAL_ADC_DeInit.
*
* Brief             -Reset ADC Registers.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_ADC_DeInit(void)
{
	ADMUX  = 0X00;
	ADCSRA = 0X00;
	SFIOR &= ~((1<<ADTS0) | (1<<ADTS1) | (1<<ADTS2));
}

/*******************************************************************************
* Fn                -MCAL_ADC_Start_Conversion.
*
* Brief             -Start ADC conversion in Single conversion mode.
*
* Retval            -None.
*
* Note              -only use for Single conversion mode.
*/
void MCAL_ADC_Start_Conversion(void)
{
	if(Global_ADC_Config.ADC_MODE == ADC_MODE_SINGLE_CONVERSION)
		SET_BIT(ADCSRA, ADSC);
}

/*******************************************************************************
* Fn                -MCAL_ADC_Get_Result_Data.
*
* Brief             -Get ADC conversion Result.
*
* Param [in]        -data: pointer to variable that holds ADC converted data.
*
* Param [in]        -Polling: Enable Polling or Disable it.
*
* Retval            -None.
*
* Note              -None.
*/
void MCAL_ADC_Get_Result_Data(Channel_Select_t channel, uint16* data, Polling_Mechanism_t Polling)
{
	ADMUX &= ~(0x1F);
	
	//select ADC Channel and Configure it To be Input
	ADMUX |= (uint8)channel;
	CLEAR_BIT(DDRA, channel);
	
	//Start conversion
	MCAL_ADC_Start_Conversion();
	
	//Check for using Polling Mechanism
	if(Polling == Polling_ENABLE)
		while(!READ_BIT(ADCSRA, 4));     //polling for ADIF flag
	
	//Read Converted Data
	if(Global_ADC_Config.ADC_Result_Presentation == ADC_Result_Presentation_RIGHT_ADJUSTED)
		*data = (ADCL | ((ADCH & (0x03)) << 8));
	else
		*data = ((ADCL & (0xC0)) >> 6) | (ADCH << 2);
	
	//Clear ADIF flag
	CLEAR_BIT(ADCSRA, 4);
}

ISR(ADC_vect)
{
	Global_ADC_Config.P_CallBack();
}