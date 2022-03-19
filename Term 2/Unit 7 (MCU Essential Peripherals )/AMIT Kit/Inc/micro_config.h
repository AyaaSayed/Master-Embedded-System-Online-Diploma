/*
 * micro_config.h
 *
 * Created: 3/19/2022 1:28:29 AM
 *  Author: Aya Sayed
 */ 


#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

/*Clock*/
#ifndef F_CPU 
#define F_CPU 16000000UL  //frequency is 16MHz
#endif

/*AVR headers*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#endif /* MICRO_CONFIG_H_ */