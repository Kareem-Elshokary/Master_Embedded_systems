/*
 * Mastering Embedded System Diploma 
 * Eng. Kareem Abdelkader
 *
 * KEYPAD_Driver.h
 *
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>

//Keypad roes and columns
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

//The connected ports (A/B/...) to the keypad
#define KEYPAD_PORT PORTC
#define KEYPAD_DDR  DDRC
#define KEYPAD_PIN  PINC

//APIs
void KEYPAD_INIT();
char KEYPAD_GetKey();


#endif /* KEYPAD_H_ */