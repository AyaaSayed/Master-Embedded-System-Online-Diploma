
#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
void uart_init();
void send_byte(unsigned char data);
void send_str(char *str);
char arr[]={'0','1','2','3','4','5','6','7','8','9'};
unsigned int i=0;
int main(void)
{
	uart_init();
	send_byte(arr[i]);
	while(1);
}
void uart_init()
{     UBRRL=12;
	//UBRRH= UBRR_VALUE >> 8;
	UCSRA=1<<U2X; //double speed
	UCSRB=(1<<RXEN) | (1<<TXEN) | (1<<TXCIE); enable receiver and transmitter and enable transmitter interrup
	UCSRC=(1<<UCSZ0) | (1<<UCSZ1) | (1<<URSEL);
	sei();
}
void send_byte(unsigned char data)
{
	while(!(UCSRA &(1<<UDRE)));
	UDR=data;
}
ISR(USART_TXC_vect)
{
	i++;
	if(i<10)
	send_byte(arr[i]);
}
