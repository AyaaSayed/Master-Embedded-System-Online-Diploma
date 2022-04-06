/*
 * GPIO.c
 *
 * Created: 3/19/2022 1:28:29 AM
 *  Author: AL_FAJR
 */ 

#include "GPIO.h"

/*PORT Functions Definition*/

void vINTIAL_PORT_INPUT(PORT_NAME_t Name,PULLUP_STATUS_t Pullup_status)
{
	switch (Pullup_status)
	{
		case Pullup_OFF:
		switch (Name)
		{
			case 0: DDRA  =0x00;
			        PORTA =0x00;
					break;
					
			case 1: DDRB  =0x00;
					PORTB =0x00;
					break;
					
			case 2: DDRC  =0x00;
			    	PORTC =0x00;
				    break;
					
			case 3: DDRD  =0x00;
					PORTD =0x00;
					break;
		}
		   break;
		   
		
		case Pullup_ON:
		switch (Name)
		{
			case 0: DDRA  =0x00;
			        PORTA =0xFF;
			        break;
					
			case 1: DDRB  =0x00;
			        PORTB =0xFF;
			        break;
					
			case 2: DDRC  =0x00;
			        PORTC =0xFF;
			        break;
					
			case 3: DDRD  =0x00;
			        PORTD =0xFF;
		        	break;
		}
		   break;
	}
}

void vINTIAL_PORT_OUTPUT(PORT_NAME_t Name,uint8 Intial_Value)
{
	switch (Name)
	{
		case 0: DDRA  = 0xFF;
		        PORTA = Intial_Value;
				break;
				
		case 1: DDRB  = 0xFF;
				PORTB = Intial_Value;
				break;
				
		case 2: DDRC  = 0xFF;
				PORTC = Intial_Value;
				break;
				
		case 3: DDRD  = 0xFF;
				PORTD = Intial_Value;
				break;
	}
	
}

void vWRITE_PORT(PORT_NAME_t Name, uint8 DATA)
{
	switch (Name)
	{
		case 0: PORTA = DATA;
		        break;
		
		case 1: PORTB = DATA;
		        break;
		
		case 2: PORTC = DATA;
		        break;
		
		case 3: PORTD = DATA;
		        break;
	}
	
}

uint8 uREAD_PORT(PORT_NAME_t Name)
{
	uint8 DATA_READ;
	
	switch (Name)
	{
		case 0: DATA_READ = PINA;
		        break;
		
		case 1: DATA_READ = PINB;
		        break;
		
		case 2: DATA_READ = PINC;
		        break;
		
		case 3: DATA_READ = PIND;
		        break;
	}
	return DATA_READ;
	
}

void vTOGGLE_PORT(PORT_NAME_t Name)
{
	switch (Name)
	{
		case 0: PORTA ^=PORTA;
		        break;
		
		case 1: PORTB ^=PORTB ;
		        break;
		
		case 2: PORTC ^=PORTC;
		        break;
		
		case 3: PORTD ^=PORTD;
		        break;
	}
	
}


/*PIN Functions Definition*/
void vINTIAL_PIN_INPUT (PORT_NAME_t Name ,uint8 PIN_NUM,PULLUP_STATUS_t Pullup_status)
{
	switch (Pullup_status) 
	{
		case Pullup_OFF: 
		switch (Name)
		{
			case 0: DDRA  &=~ (PIN_NUM);
			        PORTA &=~ (PIN_NUM);
			        break;
			
			case 1: DDRB  &=~ (PIN_NUM);
			        PORTB &=~ (PIN_NUM);
			        break;
			
			case 2: DDRC  &=~ (PIN_NUM);
			        PORTC &=~ (PIN_NUM);
			        break;
			
			case 3: DDRD  &=~ (PIN_NUM);
			        PORTD &=~ (PIN_NUM);
			        break;
		}
	    break;
		
		
		case Pullup_ON:
		switch (Name)
		{
			case 0: DDRA  &=~ (PIN_NUM);
			        PORTA |=  (PIN_NUM);
			        break;
			
			case 1: DDRB  &=~ (PIN_NUM);
			        PORTB |=  (PIN_NUM);
			        break;
			
			case 2: DDRC  &=~ (PIN_NUM);
			        PORTC |=  (PIN_NUM);
			        break;
			
			case 3: DDRD  &=~ (PIN_NUM);
			        PORTD |=  (PIN_NUM);
			        break;
		}
	    break;
	}
	
}

void vINTIAL_PIN_OUTPUT(PORT_NAME_t Name,uint8 PIN_NUM,PIN_INTIAL_OUTPUT_STATE_t Intial_Val)
{
	switch (Intial_Val)
	{
	case OUT_OFF : switch (Name)
	       {
			   case 0: DDRA  |= (PIN_NUM);
			           PORTA &=~(PIN_NUM);
			   break;
			   
			   case 1: DDRB  |= (PIN_NUM);
			           PORTB &=~(PIN_NUM);
			   break; 
			   
			   case 2: DDRC  |= (PIN_NUM);
			           PORTC &=~(PIN_NUM);
			   break;
			   
			   case 3: DDRD  |= (PIN_NUM);
			           PORTD &=~(PIN_NUM);
			   break;
	       }
		break;
		
		case OUT_ON : switch (Name)
		{
			case 0: DDRA  |= (PIN_NUM);
			        PORTA |= (PIN_NUM);
			break;
			
			case 1: DDRB  |= (PIN_NUM);
			        PORTB |= (PIN_NUM);
			break;
			
			case 2: DDRC  |= (PIN_NUM);
			        PORTC |= (PIN_NUM);
			break;
			
			case 3: DDRD  |= (PIN_NUM);
			        PORTD |= (PIN_NUM);
			break;
		}
		break;
	}	
}

void vWRITE_PIN(PORT_NAME_t Name,uint8 PIN_NUM,uint8 Val)
{
	switch (Val)
	{
	case LOW:  switch (Name)
	           {
		       case 0: PORTA  &=~(PIN_NUM);
		       break;
		
		       case 1: PORTB &=~(PIN_NUM);
		       break;
		
		       case 2: PORTC &=~(PIN_NUM);
		       break;
		
		       case 3: PORTD &=~(PIN_NUM);
		        break;
	           }
	
		break;
		
		case HIGH:  switch (Name)
		{
			case 0: PORTA |= (PIN_NUM);
			break;
			
			case 1: PORTB |= (PIN_NUM);
			break;
			
			case 2: PORTC |= (PIN_NUM);
			break;
			
			case 3: PORTD |= (PIN_NUM);
			break;
		}
	}
}

uint8 uREAD_PIN(PORT_NAME_t Name,uint8 PIN_NUM)
{
	switch (Name)
	{
		case 0: return ((PINA&=(PIN_NUM))?HIGH:LOW);
		break;
		
		case 1: return ((PINB&=(PIN_NUM))?HIGH:LOW);
		break;
		
		case 2: return ((PINC&=(PIN_NUM))?HIGH:LOW);
		break;
		
		case 3: return ((PIND&=(PIN_NUM))?HIGH:LOW);
		break;
	}	
}
