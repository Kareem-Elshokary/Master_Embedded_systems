/*
 * Mastering Embedded System Diploma 
 * Eng. Kareem Abdelkader
 *
 * LCD_Driver.c
 *
 */ 

#include "LCD_Driver.h"

void LCD_INIT(){
	//LCD Power ON delay always >15ms
	_delay_ms(20);
	
	//Control pins
	LCD_CTRL_DDR  |= (1<<EN | 1<<RW | 1<<RS) ;
	LCD_CTRL_PORT &= ~(1<<EN | 1<<RW | 1<<RS) ;
	LCD_DATA_DDR  = 0xff;
	_delay_ms(15);
	
	LCD_clear_screen();
	
	#ifdef EIGHT_BIT_MODE
	LCD_SEND_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_SEND_COMMAND(0x02);
	LCD_SEND_COMMAND(LCD_FUNCTION_4BIT_2LINES); 
	#endif
	
	LCD_SEND_COMMAND(LCD_ENTRY_MODE);
	LCD_SEND_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_SEND_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_kick(){
	LCD_CTRL_PORT &= ~(1<<EN);
	_delay_ms(50);
	LCD_CTRL_PORT |= (1<<EN);
}

void Check_lcd_isbusy(){
	LCD_DATA_DDR  = 0x00;
	LCD_CTRL_PORT |= (1<<RW); //Read
	LCD_CTRL_PORT &= ~(1<<RS);
	LCD_kick();
	LCD_DATA_DDR  = 0xff;
	LCD_CTRL_PORT &= ~(1<<RW);
}

void LCD_clear_screen(){
	LCD_SEND_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 0)
	{
		if(position<16 && position>=0)
			LCD_SEND_COMMAND(0x80 + position);
	}
	else if (line == 1)
	{
		if(position<16 && position>=0)
			LCD_SEND_COMMAND(0xc0 + position);
	}
}

void LCD_SEND_COMMAND(unsigned char command){
	#ifdef EIGHT_BIT_MODE
	Check_lcd_isbusy();
	LCD_DATA_PORT = command;
	LCD_CTRL_PORT &= ~((1<<RW) | (1<<RS));
	LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	Check_lcd_isbusy();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (command & 0xf0);
	LCD_CTRL_PORT &= ~((1<<RW) | (1<<RS));
	_delay_us(1);
	LCD_kick();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (command << 4);
	LCD_CTRL_PORT &= ~ ((1<<RW)|(1<<RS));
	LCD_kick();
	#endif
}

void LCD_SEND_CHAR(unsigned char character){
	#ifdef EIGHT_BIT_MODE
	Check_lcd_isbusy();
	LCD_CTRL_PORT |= (1<<RS); //Data mode
	LCD_DATA_PORT = ( ((character) << DATA_Shift) );
	LCD_CTRL_PORT |= (1<<RS); //Data mode
	LCD_CTRL_PORT &= ~(1<<RW); //Turn RW off so you can write
	LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (LCD_DATA_PORT & 0xf0);
	LCD_CTRL_PORT |= (1<<RS); //Data mode
	LCD_CTRL_PORT &= ~(1<<RW); //Turn RW off so you can write
	LCD_kick();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (character << 4);
	LCD_CTRL_PORT |= (1<<RS); //Data mode
	LCD_CTRL_PORT &= ~(1<<RW); //Turn RW off so you can write
	LCD_kick();
	#endif
}

void LCD_SEND_STRING(char* string){
	int count; //To count how much char on the line
	while (*string > 0)
	{
		count++;
		LCD_SEND_CHAR(*string++);
		if (count == 16) //Go to the second line
		{
			LCD_GOTO_XY(1,0); //Line 1 position 0
		}
		else if (count == 32 || count == 33) //Clear screen and show again
		{
			LCD_clear_screen();
			LCD_GOTO_XY(0,0); //Line 0 position 0
			count = 0;
		}
	}
}

void LCD_SEND_NUMBER(int number){
	char str[7];
	sprintf(str,"%d",number); //Adjust the formatting to your liking
	LCD_SEND_STRING(str);
}

void LCD_SEND_RealNumber(double number){
	char str[16];
	char* tmpSign = (number < 0) ? "-" : "";
	float tmpVal  = (number < 0) ? -number : number;
	int Int1 = tmpVal; //Get the integer
	float Frac = tmpVal - Int1; //Get the fraction
	int Int2 = Frac * 10000; //Turn into integer
	sprintf(str,"%s%d.%04d",tmpSign,Int1,Int2);
	LCD_SEND_STRING(str);
}
