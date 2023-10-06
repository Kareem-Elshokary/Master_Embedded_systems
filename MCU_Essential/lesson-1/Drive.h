/*
 * Master Embedded System Diploma
 * Eng: Kareem Abdelkader
 * 
 * Drive.h
 */ 


#ifndef DRIVE_H_
#define DRIVE_H_

#include <stdio.h>

//CPU frequency 
#define F_CPU 8000000U

//PORTA 
#define DDRA   *((volatile unsigned int *) 0x3A)
#define PORTA  *((volatile unsigned int *) 0x3B)
#define PINA   *((volatile unsigned int *) 0x39)

//PORTB
#define DDRB   *((volatile unsigned int *) 0x37)
#define PORTB  *((volatile unsigned int *) 0x38)
#define PINB   *((volatile unsigned int *) 0x36)

//PORTC
#define DDRC   *((volatile unsigned int *) 0x34)
#define PORTC  *((volatile unsigned int *) 0x35)
#define PINC   *((volatile unsigned int *) 0x33)

//PORTD
#define DDRD   *((volatile unsigned int *) 0x31)
#define PORTD  *((volatile unsigned int *) 0x32)
#define PIND   *((volatile unsigned int *) 0x30)


//Modify a specific bit
#define Set_Bit(reg,bit)   (reg |= (1<<bit))
#define Clr_Bit(reg,bit)   (reg &= ~(1<<bit))
#define Tog_Bit(reg,bit)   (reg ^= (1<<bit))
#define Read_bit(reg,bit)  ((reg>>bit)&1)

//Delay
void Delay(int x){
	for(int i=0; i<x; i++);
}

//LEDs
#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4
#define LED6 5
#define LED7 6
#define LED8 7

//Push Buttons
#define PB1 0
#define PB2 1
#define PB3 2
#define PB4 3
#define PB5 4
#define PB6 5
#define PB7 6
#define PB8 7

//7_Segment
static unsigned char Segment[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

#endif /* DRIVE_H_ */
