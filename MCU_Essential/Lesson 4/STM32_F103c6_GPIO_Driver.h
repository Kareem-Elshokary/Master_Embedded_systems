/*
 *  STM32_F103c6_GPIO_Driver.h
 *
 *  Eng. Kareem Abelkader
 *
 */

#ifndef INCLUDE_STM32_F103C6_GPIO_DRIVER_H_
#define INCLUDE_STM32_F103C6_GPIO_DRIVER_H_


/***********************************
 * Includes
 ***********************************/
#include"STM32_F103x6.h"


//===========================================================================================

/***********************************
 * User Type Definitions
 ***********************************/
typedef struct{
	uint8_t GPIO_PinNumber;    //Specific the GPIO pin to be configured. This parameter is value of @ref GPIO_PINS_DEF
	uint8_t GPIO_MODE;         //Specific the operation mode for the selected pin. This parameter is value of @ref GPIO_MODE_DEF
	uint8_t GPIO_Output_Speed; //Specific the GPIO speed for the selected pin. This parameter is value of @ref GPIO_SPEED_DEF
}GPIO_PinConfig_t;


//===========================================================================================

/***********************************
 *  Configuration References
 ***********************************/

/* GPIO PINS DEF ref */
#define GPIO_PIN_0				((uint16_t)0x0001) //Pin 0 Selected
#define GPIO_PIN_1				((uint16_t)0x0002) //Pin 1 Selected
#define GPIO_PIN_2				((uint16_t)0x0004) //Pin 2 Selected
#define GPIO_PIN_3				((uint16_t)0x0008) //Pin 3 Selected
#define GPIO_PIN_4				((uint16_t)0x0010) //Pin 4 Selected
#define GPIO_PIN_5				((uint16_t)0x0020) //Pin 5 Selected
#define GPIO_PIN_6				((uint16_t)0x0040) //Pin 6 Selected
#define GPIO_PIN_7				((uint16_t)0x0080) //Pin 7 Selected
#define GPIO_PIN_8				((uint16_t)0x0100) //Pin 8 Selected
#define GPIO_PIN_9				((uint16_t)0x0200) //Pin 9 Selected
#define GPIO_PIN_10				((uint16_t)0x0400) //Pin 10 Selected
#define GPIO_PIN_11				((uint16_t)0x0800) //Pin 11 Selected
#define GPIO_PIN_12				((uint16_t)0x1000) //Pin 12 Selected
#define GPIO_PIN_13				((uint16_t)0x2000) //Pin 13 Selected
#define GPIO_PIN_14				((uint16_t)0x4000) //Pin 14 Selected
#define GPIO_PIN_15				((uint16_t)0x8000) //Pin 15 Selected
#define GPIO_PORT				((uint16_t)0xffff) //Port Selected


/* GPIO MODE DEF ref */
#define GPIO_MODE_ANALOG			0x000000000UL //Analog mode
#define GPIO_MODE_INPUT_FLO			0x000000001UL //Floating input mode
#define GPIO_MODE_INPUT_PU			0x000000002UL //Input with pull-up
#define GPIO_MODE_INPUT_PD			0x000000003UL //Input with pull-down
#define GPIO_MODE_OUTPUT_PP			0x000000004UL //Output push-pull
#define GPIO_MODE_OUTPUT_OD			0x000000005UL //Output open-drain
#define GPIO_MODE_OUTPUT_ALT_PP		0x000000006UL //Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_ALT_OD		0x000000007UL //Alternate function output open-drain
#define GPIO_MODE_INPUT_ALT 		0x000000008UL //Alternate function input mode


/* GPIO SPEED DEF ref */
#define GPIO_SPEED_10MHz			0x00000001UL //01: Output mode, max speed 10 MHz.
#define GPIO_SPEED_2MHz				0x00000002UL //10: Output mode, max speed 2 MHz
#define GPIO_SPEED_500MHz			0x00000003UL //11: Output mode, max speed 50 MHz


/* GPIO PIN STATUS DEF */
#define GPIO_PIN_SET			1
#define GPIO_PIN_RESET			0


/* GPIO PIN LOCK DEF */
#define GPIO_PIN_LOCKED			1
#define GPIO_PIN_UNLOCKED		0

//===========================================================================================

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_INIT(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DEINIT(GPIO_TypeDef* GPIOx);
uint8_t MCAL_GPIO_READPIN(GPIO_TypeDef* GPIOx, uint8_t PinNumber);					//Read API
uint16_t MCAL_GPIO_READPORT(GPIO_TypeDef* GPIOx);									//Read API
void MCAL_GPIO_WRITEPIN(GPIO_TypeDef* GPIOx, uint8_t PinNumber, uint8_t value);		//Write API
void MCAL_GPIO_WRITEPORT(GPIO_TypeDef* GPIOx, uint16_t value);						//Write API
void MCAL_GPIO_TOGGLEPIN(GPIO_TypeDef* GPIOx, uint8_t PinNumber);
uint8_t MCAL_GPIO_LOCKPIN(GPIO_TypeDef* GPIOx, uint8_t PinNumber);




#endif /* INCLUDE_STM32_F103C6_GPIO_DRIVER_H_ */
