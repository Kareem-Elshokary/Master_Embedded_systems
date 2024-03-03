/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : STM32F103C8_Drivers  	                             			  	*/
/* File          : GPIO.h		     		                       				      	*/
/* Date          : 19/2/2024                                        				  	*/
/* Version       : V2                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/Master_Embedded_systems          */
/*************************************************************************/


#ifndef INC_GPIO_H_
#define INC_GPIO_H_

/*****************************
 * Includes
 ****************************/
#include "STM32F103x8.h"


//=====================================================================

/*****************************
 * User Configuration
 ****************************/

/*
 * To use a pin as input/output pin you should configure the following:
 * 1- Port
 * 2- Pin Number
 * 3- Pin Mode
 * 4- Pin Speed if it output
 */

//Pin Number
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15
#define GPIO_PINS	0xFFFF


//Pin Mode
/*
	CNFy[1:0]: Port x configuration bits (y= 0 .. 7)
 	In input mode (MODE[1:0]=00):
	00: Analog mode
	01: Floating input (reset state)
	10: Input with pull-up / pull-down
	11: Reserved
*/
#define INPUT_ANALOG			0b0000
#define INPUT_FLOATING			0b0100
#define INPUT_PU				0b11000
#define INPUT_PD				0b01000
#define INPUT_AF				0b0100

/*
	CNFy[1:0]: Port x configuration bits (y= 0 .. 7)
	In output mode (MODE[1:0] > 00):
	00: General purpose output push-pull
	01: General purpose output Open-drain
	10: Alternate function output Push-pull
	11: Alternate function output Open-drain
 */
#define OUTPUT_PP				0b00
#define OUTPUT_OD				0b01
#define OUTPUT_AF_PP			0b10
#define OUTPUT_AF_OD			0b11


//Pin Speed
/*
	CNFy[1:0]: Port x configuration bits (y= 0 .. 7)
	00: Input mode (reset state)
	01: Output mode, max speed 10 MHz.
	10: Output mode, max speed 2 MHz.
	11: Output mode, max speed 50 MHz.
 */
#define SPEED_10MHz				0b01
#define SPEED_2MHz				0b10
#define SPEED_50MHz				0b11


//Pin Status
#define SET						1
#define RESET					0


//Pin Lock
#define LOCK					1
#define UNLOCK					0


//=====================================================================

/**************************************
 * APIs Supported by MCAL GPIO Drive
 **************************************/

//GPIO Pin Initialization
void MCAL_GPIO_INIT(GPIO_REG_t* GPIOx, uint16_t pin_num, uint32_t mode, uint32_t speed);

//GPIO Pin Deinitialization
void MCAL_GPIO_DEINIT(GPIO_REG_t* GPIOx);

//Write APIS
void MCAL_GPIO_WRITEPIN(GPIO_REG_t* GPIOx, uint16_t pin_num, uint8_t status);
void MCAL_GPIO_WRITEPORT(GPIO_REG_t* GPIOx, uint32_t status);

//Read APIs
uint32_t MCAL_GPIO_READPIN(GPIO_REG_t* GPIOx, uint16_t pin_num);
uint32_t MCAL_GPIO_READPORT(GPIO_REG_t* GPIOx);

//Toggle Pin
void MCAL_GPIO_TOGGLE(GPIO_REG_t* GPIOx, uint16_t pin_num);

//Lock Pin
uint8_t MCAL_GPIO_LOCKPIN(GPIO_REG_t* GPIOx, uint16_t pin_num);




#endif /* INC_GPIO_H_ */
