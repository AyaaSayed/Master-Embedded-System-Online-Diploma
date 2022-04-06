/*
 * Timer_test.h
 *
 * Created: 4/6/2022 10:56:32 AM
 *  Author: Aya Sayed
 */ 


#ifndef TIMER_TEST_H_
#define TIMER_TEST_H_

/*******************************************************************************
                                      Includes                                   
 *******************************************************************************/
#include "Timer0.h"

/*******************************************************************************
                                  Application APIs                                 
 *******************************************************************************/
void Timer_test(void);

void Timer_OverFlow_Interrupt_Handler(void);
void Timer_CompareMatch_Interrupt_Handler(void);

#endif /* TIMER_TEST_H_ */