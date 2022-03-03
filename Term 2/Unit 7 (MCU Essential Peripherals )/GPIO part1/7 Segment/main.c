/*
 * 7 Segment.c
 *
 * Created: 3/3/2022 8:09:23 AM
 * Author : diesel
 */ 

#define Set(Register_name,bit_no)     Register_name|=(1<<bit_no)    //to set bit
#define Reset(Register_name,bit_no)   Register_name&=~(1<<bit_no)   //to reset bit
#define Toggle(Register_name,bit_no)  Register_name^=(1<<bit_no)    //to set bit

typedef volatile unsigned int vuint32_t ;

#define DDRC      *( vuint32_t *)(0x34)
#define PORTC     *( vuint32_t *)(0x35)


#define PC2       2
#define PC3       3
#define PC4       4
#define PC5       5
#define PC6       6
#define PC7       7

void _delay(vuint32_t t)
{
	for( vuint32_t i = 0 ; i<t ; i++ )
	{
		for( vuint32_t j=0 ; j<256 ; j++ );
	}
}


void Init_GPIOC()
{
	//Initialize PORTC
	Set(DDRC,PC2);   //Set PC2 as output 
	Set(DDRC,PC3);   //Set PC3 as output
	Set(DDRC,PC4);   //Set PC4 as output
	Set(DDRC,PC5);   //Set PC5 as output
	Set(DDRC,PC6);   //Set PC6 as output
	Set(DDRC,PC7);   //Set PC7 as output
}

int main(void)
{
    Init_GPIOC();
    while (1) 
    {
		vuint32_t i,j;
		for( i=0 ; i<10 ;i++ )
		{
			for( j=0 ; j<10 ; j++ )
			{
				PORTC = 0b1011 | (i<<4);
				_delay(500);
				PORTC = 0b0111 | (j<<4);
				_delay(1500);
			}
		}
    }
}

