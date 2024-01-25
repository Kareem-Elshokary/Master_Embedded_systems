/*
 * GPIO.h
 *
 * Master Embedded System Diploma
 * Eng. Kareem Abelkader
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

/******************************
 * Includes
 *******************************/
#include "STM32F103x8.h"

//==========================================================================

/***********************************
 * User Type Definitions
 ***********************************/
/*To configure a pin, determine the following consideration:
 * 1- Pin number
 * 2- Pin mode (input / output / AF)
 * 3- Pin speed if it output pin
 */
typedef struct {
	uint16_t Pin_Num; 		//Specific the GPIO pin to be configured. This parameter is value of @ref PINS_DEF
	uint8_t Pin_Mode;		//Specific the operation mode for the selected pin. This parameter is value of @ref MODE_DEF
	uint8_t Pin_Speed;		//Specific the GPIO speed for the selected pin. This parameter is value of @ref SPEED_DEF
}GPIO_PinConfig_t;


/***********************************
 *  Configuration References
 ***********************************/

/*PINS_DEF ref*/
#define PIN_0				((uint16_t)0x0001) //Pin 0 Selected
#define PIN_1				((uint16_t)0x0002) //Pin 1 Selected
#define PIN_2				((uint16_t)0x0004) //Pin 2 Selected
#define PIN_3				((uint16_t)0x0008) //Pin 3 Selected
#define PIN_4				((uint16_t)0x0010) //Pin 4 Selected
#define PIN_5				((uint16_t)0x0020) //Pin 5 Selected
#define PIN_6				((uint16_t)0x0040) //Pin 6 Selected
#define PIN_7				((uint16_t)0x0080) //Pin 7 Selected
#define PIN_8				((uint16_t)0x0100) //Pin 8 Selected
#define PIN_9				((uint16_t)0x0200) //Pin 9 Selected
#define PIN_10				((uint16_t)0x0400) //Pin 10 Selected
#define PIN_11				((uint16_t)0x0800) //Pin 11 Selected
#define PIN_12				((uint16_t)0x1000) //Pin 12 Selected
#define PIN_13				((uint16_t)0x2000) //Pin 13 Selected
#define PIN_14				((uint16_t)0x4000) //Pin 14 Selected
#define PIN_15				((uint16_t)0x8000) //Pin 15 Selected
#define GPIO_PORT			((uint16_t)0xFFFF) //Port Selected



/*MODE_DEF ref */
/*
		0: Analog mode
		1: Floating input (reset state)
		2: Input with pull-up
		3:  Input with  pull-down
		4: General purpose output push-pull
		5: General purpose output Open-drain
		6: Alternate function output Push-pull
		7: Alternate function output Open-drain
		8: Alternate function INPUT
 */
//Input mode
#define ANALOG_MODE				0x000000000u //Analog mode
#define INPUT_FLO_MODE			0x000000001u //Floating input mode
#define INPUT_PU_MODE			0x000000002u //Input with pull-up
#define INPUT_PD_MODE			0x000000003u //Input with pull-down
//Output mode
#define OUTPUT_PP_MODE			0x000000004u //Output push-pull
#define OUTPUT_OD_MODE			0x000000005u //Output open-drain
//AF mode
#define OUTPUT_ALT_PP_MODE		0x000000006u //Alternate function output Push-pull
#define OUTPUT_ALT_OD_MODE		0x000000007u //Alternate function output open-drain
#define INPUT_ALT_MODE	 		0x000000008u //Alternate function input mode



/*SPEED DEF ref */
#define SPEED_10MHz				0x00000001u //01: Output mode, max speed 10 MHz.
#define SPEED_2MHz				0x00000002u //10: Output mode, max speed 2 MHz
#define SPEED_50MHz			0x00000003u //11: Output mode, max speed 50 MHz

/*Pin Status */
#define Pin_SET					1
#define Pin_RESET				0
#define Pin_LOCKED				0
#define Pin_UNLOCKED			1

//=====================================================================

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

//Initialization of GPIOx PINy according to a specific configuration
void MCAL_GPIO_INIT(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig);
//De-initialization of GPIOx PINy
void MCAL_GPIO_DEINIT(GPIO_TypeDef* GPIOx);
//Write on pin
void MCAL_GPIO_WRITEPIN(GPIO_TypeDef* GPIOx, uint16_t PinNumber, uint8_t value);
//Write on port
void MCAL_GPIO_WRITEPORT(GPIO_TypeDef* GPIOx, uint16_t value);
//Read from pin
uint8_t MCAL_GPIO_READPIN(GPIO_TypeDef* GPIOx, uint16_t PinNumber);
//Read from port
uint16_t MCAL_GPIO_READPORT(GPIO_TypeDef* GPIOx);
//Toggle pin
void MCAL_GPIO_TOGGLEPIN(GPIO_TypeDef* GPIOx, uint16_t PinNumber);
//Toggle port
void MCAL_GPIO_TOGGLEPORT(GPIO_TypeDef* GPIOx);
//Lock pin
uint8_t MCAL_GPIO_LOCKPIN(GPIO_TypeDef* GPIOx, uint16_t PinNumber);


#endif /* GPIO_GPIO_H_ */
