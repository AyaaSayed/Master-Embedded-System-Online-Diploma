/*
 * Thermistor.h
 *
 * Created: 4/8/2022 8:09:45 PM
 *  Author: Aya Sayed
 */ 


#ifndef THERMISTOR_H_
#define THERMISTOR_H_

/*******************************************************************************
                                      Includes                                   
 *******************************************************************************/
#include "ADC.h"

#define USING_POLLING
//#define USING_INTERRUPT

/*******************************************************************************
                                  Application APIs                                 
 *******************************************************************************/
void ADC_PERCENTAGE_WITH_PROGRESS_BAR(void);

void ADC_Interrupt_CallBack(void);



#endif /* THERMISTOR_H_ */