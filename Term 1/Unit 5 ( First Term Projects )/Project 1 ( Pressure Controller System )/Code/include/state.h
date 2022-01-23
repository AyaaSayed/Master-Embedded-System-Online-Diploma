/*
 * state.h
 *
 *  Created on: Jan 20, 2022
 *      Author: Aya Sayed
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdint.h>

typedef volatile uint32_t   vuint32_t;

//Delay Macro
#define Delay(time)          for( int i=0 ; i<time ; i++ );

//define macros
#define Set(Register_name,bit_no)     Register_name|=(1<<bit_no)    //to set bit
#define Clear(Register_name,bit_no)   Register_name&=~(1<<bit_no)   //to clear bit

//logical operation
#define AND(Register_name,value)      Register_name&=value          //to AND content of register with value
#define OR(Register_name,value)       Register_name|=value          //to OR content of register with value



#define STATE_DECL(_stateFUNC_)  void ST_##_stateFUNC_()
#define STATE(_stateFUNC_)       ST_##_stateFUNC_

//prototype functions
uint32_t get_pressure_values(void);
int Start_Alarm();
int Stop_Alarm();

#endif /* STATE_H_ */
