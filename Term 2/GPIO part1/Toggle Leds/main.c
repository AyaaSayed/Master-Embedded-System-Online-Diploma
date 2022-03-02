/*
 * Toggle Leds.c
 *
 * Created: 3/2/2022 9:12:09 AM
 * Author : Aya Sayed
 */ 



#define Set(Register_name,bit_no)     Register_name|=(1<<bit_no)    //to set bit
#define Reset(Register_name,bit_no)   Register_name&=~(1<<bit_no)   //to reset bit
#define Toggle(Register_name,bit_no)  Register_name^=(1<<bit_no)    //to set bit

typedef volatile unsigned int vuint32_t ;

#define _delay    for( vuint32_t i = 0 ; i<10000 ; i++ )

#define DDRD      *( vuint32_t *)(0x31)
#define PORTD     *( vuint32_t *)(0x32)

#define PD4       4
#define PD5       5
#define PD6       6
#define PD7       7

int main(void)
{
	//Initialize PORTA
	Set(DDRD,PD4);   //Set PA1 as output 
	Set(DDRD,PD5);   //Set PA2 as output
	Set(DDRD,PD6);   //Set PA3 as output
	Set(DDRD,PD7);   //Set PA4 as output
	
    while(1)
	{
		//Led 1 is ON
		Toggle(PORTD,PD5);
		_delay;
		Toggle(PORTD,PD5);
		
		//Led 2 is ON
		Toggle(PORTD,PD6);
		_delay;
		Toggle(PORTD,PD6);
		
		//Led 3 is ON
		Toggle(PORTD,PD7);
		_delay;
		Toggle(PORTD,PD7);
		
		//BUZZER is ON
		Toggle(PORTD,PD4);
		_delay;
		Toggle(PORTD,PD4);
	}
}

