/******************************************************************************
 Master Embedded System Diploma <Learn in depth>
 file           : main.c
 Author         : Aya Sayed
 brief          : main program body
 ******************************************************************************/
//#include <stdint.h>
//#define typdef volatile uint32_t vuint32_t

#define Set(Register_name,bit_no)     Register_name|=(1<<bit_no)    //to set bit
#define Clear(Register_name,bit_no)   Register_name&=~(1<<bit_no)   //to clear bit

#define Delay            for(_delay=0 ; _delay < 2000 ; _delay++)   //delay time

//enable GPIOF
#define SYSCTL_BASE       0X400FE000
#define SYSCTL_RCGC2_R    *((volatile unsigned long *)(SYSCTL_BASE+0x108)) 

//define port f Register
#define GPIO_PORTF_BASE   0X40025000
#define GPIO_PORTF_DIR_R  *((volatile unsigned long *)(GPIO_PORTF_BASE+0X400)) 
#define GPIO_PORTF_DATA_R *((volatile unsigned long *)(GPIO_PORTF_BASE+0X3FC)) 
#define GPIO_PORTF_DEN_R  *((volatile unsigned long *)(GPIO_PORTF_BASE+0X51C)) 

int main()
{
	volatile unsigned long _delay; 
	
	SYSCTL_RCGC2_R = 0x20;       //Enable GPIO port
	Delay;

	Set(GPIO_PORTF_DIR_R,3);     //Set pf3 direction as output
    Set(GPIO_PORTF_DEN_R,3);     //Enable pf3 pin
    
	while(1)
	{
		Set(GPIO_PORTF_DATA_R,3);    //led is ON
		Delay;
		Clear(GPIO_PORTF_DATA_R,3);  //led is ON
		Delay;

	}
	return 0;
}