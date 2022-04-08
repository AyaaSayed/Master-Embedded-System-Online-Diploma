/*
 * GPIO.h
 *
 * Created: 3/19/2022 1:28:29 AM
 *  Author: Aya Sayed
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "micro_config.h"


 /*PIN Num*/
#define PIN_0 0b00000001
#define PIN_1 0b00000010
#define PIN_2 0b00000100
#define PIN_3 0b00001000
#define PIN_4 0b00010000
#define PIN_5 0b00100000
#define PIN_6 0b01000000
#define PIN_7 0b10000000


/*Types*/
typedef enum PortName {A=0, B, C, D} PORT_NAME_t;
typedef enum PullupStatus{Pullup_OFF=0, Pullup_ON}PULLUP_STATUS_t;
typedef enum PinOutIntialState{OUT_OFF=0, OUT_ON}PIN_INTIAL_OUTPUT_STATE_t; 
	
	
/*PORT Functions Deceleration*/
void vINTIAL_PORT_INPUT(PORT_NAME_t,PULLUP_STATUS_t);
void vINTIAL_PORT_OUTPUT(PORT_NAME_t,uint8 Intial_Value);
void vWRITE_PORT(PORT_NAME_t, uint8 DATA);                /*Write>>--PORT*/
uint8 uREAD_PORT(PORT_NAME_t);                            /*Read>>-- PIN*/
void vTOGGLE_PORT(PORT_NAME_t);

/*PIN Functions Deceleration*/
void vINTIAL_PIN_INPUT(PORT_NAME_t,uint8 PIN_NUM,PULLUP_STATUS_t);
void vINTIAL_PIN_OUTPUT(PORT_NAME_t,uint8 PIN_NUM,PIN_INTIAL_OUTPUT_STATE_t Intial_val);
void vWRITE_PIN(PORT_NAME_t,uint8 PIN_NUM,uint8 DATA);
uint8 uREAD_PIN(PORT_NAME_t,uint8 PIN_NUM);
void vTOGGLE_PIN(PORT_NAME_t, uint8 PIN_NUM);



#endif /* GPIO_H_ */