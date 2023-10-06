/*
 * Sec_Assignment2
 *
 * Created: 10/5/2023 7:50:00 PM
 * Author : KARIM
 */ 

#include "Drive.h"
#include <util/delay.h>


int main(void)
{
	//Port A is output
    DDRA  = 0xff;
	PORTA = 0x00;
	//Port C pin0 is input
	DDRC  = 0x00;
	PORTC = 0b00000001;
	
    while (1) 
    {
		if ( Read_bit(PINC,0) == 1 )
		{
			Set_Bit(PORTA,LED1);
			Delay(10000);
		}
		if ( Read_bit(PINC,0) == 1 )
		{
			Set_Bit(PORTA,LED2);
			Delay(10000);
		}
		if ( Read_bit(PINC,0) == 1 )
		{
			Set_Bit(PORTA,LED3);
			Delay(10000);
		}
		if ( Read_bit(PINC,0) == 1 )
		{
			Set_Bit(PORTA,LED4);
			Delay(10000);
		}
		if ( Read_bit(PINC,0) == 1 )
		{
			Set_Bit(PORTA,LED5);
			Delay(10000);
		}
		if ( Read_bit(PINC,0) == 1 )
		{
			Set_Bit(PORTA,LED6);
			Delay(10000);
		}
		if ( Read_bit(PINC,0) == 1 )
		{
			Set_Bit(PORTA,LED7);
			Delay(10000);
		}
		if ( Read_bit(PINC,0) == 1 )
		{
			Set_Bit(PORTA,LED8);
			Delay(10000);
		}
    }
	
}

