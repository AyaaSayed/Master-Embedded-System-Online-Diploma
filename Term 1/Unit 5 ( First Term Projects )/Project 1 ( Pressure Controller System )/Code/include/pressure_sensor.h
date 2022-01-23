/*
 * pressure_sensor.h
 *
 *  Created on: Jan 20, 2022
 *      Author: Aya Sayed
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"

//Register addresses
#define RCC_BASE       0x40021000
#define GPIOA_BASE     0x40010800
#define APB2ENR        *( vuint32_t* )( RCC_BASE    + 0x18 )
#define GPIOA_CRL      *( vuint32_t* )( GPIOA_BASE  + 0x00 )
#define GPIOA_IDR      *( vuint32_t* )( GPIOA_BASE  + 0x08 )

//define bits name
#define RCC_IOPAEN     2       //RCC_IOPAEN is name of bit3

//States ID
enum{
	PS_INIT,
	Reading_Pressure,
	PS_WAITING
}PS_STATE_ID;

//protoypes
STATE_DECL(PS_INIT);
STATE_DECL(Reading_Pressure);
STATE_DECL(PS_WAITING);

//global pointer to function
void (*PS_STATE)();

//read pressure sensor from GPIOA 
uint32_t read_pressure_values();

#endif /* PRESSURE_SENSOR_H_ */
