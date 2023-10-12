/*
 * Mastering Embedded System Diploma 
 * Eng. Kareem Abdelkader
 *
 *LCD_Keypad.c
 *
 */ 


#include "LCD_Driver/LCD_Driver.h"
#include "KEYPAD_Driver/KEYPAD.h"

int main(void)
{
    LCD_INIT();
	KEYPAD_INIT();
	
	char Key;
	
    while (1) 
    {
		Key = KEYPAD_GetKey();
		switch(Key){
			case ('A'): 
			break;
			case ('?'): 
				LCD_clear_screen(); 
			break;
			default: 
				LCD_SEND_CHAR(Key); 
		}
    }
}

