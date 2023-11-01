/*
 *  LCD.h
 *
 *  Eng. Kareem Abdelkader
 *
 */


/***********************************
 * Includes
 ***********************************/
#include"LCD.h"
#include"stdio.h"

//====================================================================================

void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}


void LCD_INIT(){
	//LCD Power ON delay always >15ms
	delay_ms(20);

	//Control pins
	//LCD_CTRL_PORT &= ~(1<<EN | 1<<RW | 1<<RS) ;
	pincof.GPIO_PinNumber = EN;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);

	pincof.GPIO_PinNumber = RW;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);

	pincof.GPIO_PinNumber = RS;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);

	delay_ms(15);
	LCD_clear_screen();

	//Set the 8pins of data
	pincof.GPIO_PinNumber = GPIO_PIN_0;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_1;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_2;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_3;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_4;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_5;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_6;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_7;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);

	LCD_SEND_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_SEND_COMMAND(0x02);
	LCD_SEND_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	LCD_SEND_COMMAND(LCD_ENTRY_MODE);
	LCD_SEND_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_SEND_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_kick(){
	MCAL_GPIO_WRITEPIN(LCD_PORT, EN, GPIO_PIN_SET);
	delay_ms(50);
	MCAL_GPIO_WRITEPIN(LCD_PORT, EN, GPIO_PIN_RESET);
}

void Check_lcd_isbusy(){
	pincof.GPIO_PinNumber = GPIO_PIN_0;
	pincof.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_1;
	pincof.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_2;
	pincof.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_3;
	pincof.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_4;
	pincof.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_5;
	pincof.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_6;
	pincof.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);
	pincof.GPIO_PinNumber = GPIO_PIN_7;
	pincof.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_PORT, &pincof);

	MCAL_GPIO_WRITEPIN(LCD_PORT, RW, GPIO_PIN_SET);
	MCAL_GPIO_WRITEPIN(LCD_PORT, RS, GPIO_PIN_RESET);

	LCD_kick();

	MCAL_GPIO_WRITEPIN(LCD_PORT, RW, GPIO_PIN_RESET);
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
	Check_lcd_isbusy();

	MCAL_GPIO_WRITEPORT(LCD_PORT, command);
	MCAL_GPIO_WRITEPIN(LCD_PORT, RW, GPIO_PIN_RESET);
	MCAL_GPIO_WRITEPIN(LCD_PORT, RS, GPIO_PIN_RESET);

	delay_ms(1);
	LCD_kick();
}

void LCD_SEND_CHAR(unsigned char character){

	MCAL_GPIO_WRITEPORT(LCD_PORT, character);

	MCAL_GPIO_WRITEPIN(LCD_PORT, RW, GPIO_PIN_RESET);
	MCAL_GPIO_WRITEPIN(LCD_PORT, RS, GPIO_PIN_SET);

	delay_ms(1);
	LCD_kick();
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

