/*
 * UART.h
 *
 * Created: 3/26/2022 5:20:32 AM
 *  Author: Aya Sayed
 */ 


#ifndef UART_H_
#define UART_H_

/*******************************************************************************
                                  Includes                                   
 *******************************************************************************/
#include "micro_config.h"


/*******************************************************************************
                             APIs Prototypes                                   
 *******************************************************************************/
void   UART_INIT(void);
void   UART_Send(uint8 data );
uint8  UART_Receive(void);

void   UART_SendNumberU32(uint32 num);
uint32 UART_ReceiveNumberU32(void);

void   UART_Send_String(char* str);
char* UART_Receive_String(void);


#endif /* UART_H_ */