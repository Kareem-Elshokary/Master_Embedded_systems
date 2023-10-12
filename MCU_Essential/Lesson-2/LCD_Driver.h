/*
 * Mastering Embedded System Diploma 
 * Eng. Kareem Abdelkader
 *
 * LCD_Driver.h
 *
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#define F_CPU 8000000U

//The connected ports (A/B/C...) to the lcd 
#define LCD_DATA_PORT PORTA
#define LCD_DATA_DDR  DDRA
#define LCD_CTRL_PORT PORTB
#define LCD_CTRL_DDR  DDRB

//Control pins
#define RS 1
#define RW 2
#define EN 3

//LCD modes
//When a mode selected, put the other as a comment
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

//LCD configuration
#define DATA_Shift                                  0
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)  //Shift entire display right
#define LCD_MOVE_DISP_LEFT   						(0x18)  //Shift entire display left
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)  //Move cursor right by one character
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)  //Move cursor left by one character
#define LCD_DISP_OFF   								(0x08)  //Display off Cursor off
#define LCD_DISP_ON_CURSOR   						(0x0E)  //Display on Cursor on
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)  //Display on Cursor blinking
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)  //Display on Cursor off
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)  //Force cursor to beginning of the first line
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)  //Force cursor to beginning of second line
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)


//APIs
void LCD_INIT();
void Check_lcd_isbusy(void);
void LCD_kick(void);
void LCD_clear_screen();
void LCD_GOTO_XY(unsigned char line, unsigned char position);
void LCD_SEND_COMMAND(unsigned char command);
void LCD_SEND_CHAR(unsigned char character);
void LCD_SEND_STRING(char* string);
void LCD_SEND_NUMBER(int number);
void LCD_SEND_RealNumber(double number);

#endif /* LCD_DRIVER_H_ */