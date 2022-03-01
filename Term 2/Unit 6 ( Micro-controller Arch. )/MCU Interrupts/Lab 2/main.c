/*
 * Lab 2.c
 *
 * Created: 2/25/2022 10:08:06 AM
 * Author : Aya Sayed
 */ 

#ifndef F_CPU 
#define F_CPU 16000000UL  //frequency is 16MHz
#endif

#include <avr/io.h>
#include <avr/common.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define Set(Register_name,bit_no)     Register_name|=(1<<bit_no)    //to set bit
#define Reset(Register_name,bit_no)   Register_name&=~(1<<bit_no)   //to reset bit
#define Toggle(Register_name,bit_no)  Register_name^=(1<<bit_no)    //to set bit

typedef volatile unsigned int vuint32_t ;



void Init_GPIOD(void)
{
	Set(DDRD,PD7);    //Set Pin 7 as output
	Set(DDRD,PD6);    //Set Pin 6 as output
	Set(DDRD,PD5);    //Set Pin 5 as output
}

void Init_INT(void)
{
	//Enable Global Interrupt
	//sei();
	Set(SREG,SREG_I);
	
	//Set MCU Control Register
	Set(MCUCR,ISC00);    //Set any Logical Change INT0 mode
	Set(MCUCR,ISC10);    //Set Rising edge INT1 mode
	Set(MCUCR,ISC11);    //Set Rising edge INT1 mode
	
	//Enable General Interrupt Control Register
	Set(GICR,INT1);    //Enable Interrupt 1
	Set(GICR,INT0);    //Enable Interrupt 0
	Set(GICR,INT2);    //Enable Interrupt 2
}

int main(void)
{
    //Initialize GPIO PORTD
	Init_GPIOD();
	
	//Initiatlize INT
	Init_INT();
	
	while(1)
	{
		Reset(PORTD,PD5);
		Reset(PORTD,PD6);
		Reset(PORTD,PD7);
	}
}

ISR(INT0_vect)
{
	Set(PORTD,PD5);
	_delay_ms(1000);
	Reset(PORTD,PD5);
}

ISR(INT1_vect)
{
	Set(PORTD,PD6);
	_delay_ms(1000);
	Reset(PORTD,PD6);
}

ISR(INT2_vect)
{
	Set(PORTD,PD7);
	_delay_ms(1000);
	Reset(PORTD,PD7);
}