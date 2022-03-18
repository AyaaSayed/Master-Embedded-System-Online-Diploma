/******************************************************************************
 *
 * Module: Micro - Configuration
 *
 * File Name: Micro_Config.h
 *
 * Description: File include all Microcontroller libraries
 *
 *  Author: Aya Sayed
 *
 *******************************************************************************/  


#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 8000000UL    // 8 MHz Clock frequency
#endif

#include <avr/io.h>
#include <avr/interrupt.h> // Must be included First
#include <util/delay.h>
#include <stdio.h>



#endif /* MICRO_CONFIG_H_ */