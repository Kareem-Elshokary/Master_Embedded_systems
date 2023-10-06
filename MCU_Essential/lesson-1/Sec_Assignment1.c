/*
 * Sec_Assignment1
 *
 * Created: 10/5/2023 6:57:41 PM
 * Author : KARIM
 */ 

#include "Drive.h"

int main(void)
{
    //Pins of port A is output
	DDRA  = 0xff;
	PORTA = 0x00;
	
    while (1) 
    {
		Set_Bit(PORTA,LED1);
		Set_Bit(PORTA,LED2);
		Set_Bit(PORTA,LED3);
		Set_Bit(PORTA,LED4);
		Set_Bit(PORTA,LED5);
		Set_Bit(PORTA,LED6);
		Set_Bit(PORTA,LED7);
		Set_Bit(PORTA,LED8);
		Delay(10000);
		
		Clr_Bit(PORTA,LED8);
		Clr_Bit(PORTA,LED7);
		Clr_Bit(PORTA,LED6);
		Clr_Bit(PORTA,LED5);
		Clr_Bit(PORTA,LED4);
		Clr_Bit(PORTA,LED3);
		Clr_Bit(PORTA,LED2);
		Clr_Bit(PORTA,LED1);
		Delay(10000);
    }
}

