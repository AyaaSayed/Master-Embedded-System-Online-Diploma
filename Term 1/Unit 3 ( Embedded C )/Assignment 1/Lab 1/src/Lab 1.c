/*
 =================================================================================================
 Name        : Lab.c
 Author      : Aya Sayed
 Version     :
 Copyright   : Your copyright notice
 Description :
 =================================================================================================
 */

//You can use 1 or 2
//1.Standard library stdint.h
//#include "stdint.h"
//typedef volatile uint32_t   vuint32_t;

//2.Your Platform_Types.h file
#include "Platform_Types.h"

/************************************************************************************************/
#define Set(bit)       |=bit                               //to set bit
#define AND(value)     &=value                             //to AND content of register with value
#define OR(value)      |=value                             //to OR content of register with value

#define ON             1                                   //LED IS ON
#define OFF            0                                   //LED IS OFF

#define Delay          for( int i=0 ; i<5000 ; i++ );      //Delay Macro
/************************************************************************************************/

//Register addresses
#define RCC_BASE       0x40021000
#define GPIOA_BASE     0x40010800
#define RCC_APB2ENR    *( vuint32_t* )( RCC_BASE    + 0x18 )
#define GPIOA_CRH      *( vuint32_t* )( GPIOA_BASE  + 0x04 )
#define GPIOA_ODR      *( vuint32_t* )( GPIOA_BASE  + 0x0C )

//Bit fields
#define RCC_IOPAEN     ( 1<<2 )
#define GPIOA13        ( 1UL<<13 )


typedef union
{
	vuint32_t          all_fields;
	struct
	{
		vuint32_t     reversed:13;
		vuint32_t     pin_13:1;
	}Spin;
}R_ODR_t;

volatile R_ODR_t*  R_ODR =  ( volatile R_ODR_t* )( GPIOA_BASE + 0x0C );

int main(void)
{
	RCC_APB2ENR  Set(RCC_IOPAEN);
	GPIOA_CRH    AND(0xFF0FFFFF);
	GPIOA_CRH    OR(0x00200000);
	while(1)
	{
		R_ODR->Spin.pin_13 = ON ;   Delay
		R_ODR->Spin.pin_13 = OFF;   Delay
	}
}
