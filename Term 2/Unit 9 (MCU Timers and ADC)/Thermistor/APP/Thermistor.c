/*
 * Thermistor.c
 *
 * Created: 4/8/2022 8:09:55 PM
 *  Author: Aya Sayed
 *
  *******************************************************************************
                                    Includes
  *******************************************************************************/ 
#include "Thermistor.h"
#include "LCD.h"

uint32 vinput_mv, Temp;
uint32 ADC_Data, i = 0, bar_size;
/*******************************************************************************
                                  Application APIs                                 
 *******************************************************************************/
void ADC_Interrupt_CallBack(void)
{
	ADC_Data = ((ADC_Data * 100) / 1023);
	LCD_display_String("PERC :    ");
	LCD_Intger_Number((uint32)ADC_Data);
	LCD_Display_Character('%');
	LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
	bar_size = (160 / (1000 / ADC_Data));
	for(i=0; i<bar_size; i++)
	LCD_Display_Character(0xff);
	_delay_ms(1000);
	LCD_Clear_Screen();
}


void ADC_PERCENTAGE_WITH_PROGRESS_BAR(void)
{
	ADCConfig_t ADC_config;
	
	ADC_config.ADC_MODE = ADC_MODE_SINGLE_CONVERSION;
	ADC_config.ADC_PRESCALER = ADC_PRESCALER_DIVUDED_BY_64;
	ADC_config.ADC_Result_Presentation = ADC_Result_Presentation_RIGHT_ADJUSTED;
	ADC_config.ADC_Voltage_REF = ADC_Voltage_REF_AVCC;
	
#ifdef USING_POLLING
	ADC_config.IRQ_Enable = ADC_IRQ_ENABLE_NONE;
	ADC_config.P_CallBack = NULL;
#endif
#ifdef USING_INTERRUPT
	ADC_config.IRQ_Enable = ADC_IRQ_ENABLE_ADIE;
	ADC_config.P_CallBack = ADC_Interrupt_CallBack;
#endif

	MCAL_ADC_Init(&ADC_config);
	LCD_INIT();
	
#ifdef USING_POLLING
	MCAL_ADC_Get_Result_Data(ADC1, &ADC_Data, Polling_ENABLE);
	ADC_Data = ((ADC_Data * 100) / 1023);
	LCD_display_String("PERC :    ");
	LCD_Intger_Number((uint32)ADC_Data);
	LCD_Display_Character('%');
	LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW);
	bar_size = (160 / (1000 / ADC_Data));
	for(i=0; i<bar_size; i++)
	LCD_Display_Character(0xff);
	_delay_ms(1000);
	LCD_Clear_Screen();
#endif
#ifdef USING_INTERRUPT
	MCAL_ADC_Get_Result_Data(ADC1, &ADC_Data, Polling_DISABLE);
#endif
}