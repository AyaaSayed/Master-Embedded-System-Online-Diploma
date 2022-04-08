/*
 * LM35.c
 *
 * Created: 4/8/2022 8:06:12 PM
 *  Author: Aya Sayed
 *
 *******************************************************************************
                                     Includes
 *******************************************************************************/
 #include "LM35.h"
 #include "LCD.h"

uint32 ADC_Data, Temp;
/*******************************************************************************
                                  Application APIs                                 
 *******************************************************************************/
void LM35_TEMPERATURE_SENSOR(void)
{
	ADCConfig_t ADC_config;
	
	ADC_config.ADC_MODE = ADC_MODE_SINGLE_CONVERSION;
	ADC_config.ADC_PRESCALER = ADC_PRESCALER_DIVUDED_BY_64;
	ADC_config.ADC_Result_Presentation = ADC_Result_Presentation_LEFT_ADJUSTED;
	ADC_config.ADC_Voltage_REF = ADC_Voltage_REF_AVCC;
	ADC_config.IRQ_Enable = ADC_IRQ_ENABLE_NONE;
	ADC_config.P_CallBack = NULL;
	MCAL_ADC_Init(&ADC_config);
	LCD_INIT();
	
	//ADC_CONFIG_Using_Polling_Mechanism();
	MCAL_ADC_Get_Result_Data(ADC1, &ADC_Data, Polling_ENABLE);
	Temp = (((ADC_Data * 5600) / 1023) / 10);
	LCD_display_String("TEMP :  ");
	LCD_Intger_Number(Temp);
	LCD_display_String(" C");
	_delay_ms(2000);
	LCD_Clear_Screen();
}
