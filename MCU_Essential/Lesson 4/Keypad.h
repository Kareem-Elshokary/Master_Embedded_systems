/*
 *  Keypad.h
 *
 *  Eng. Kareem Abdelkader
 *
 */

#ifndef KEYPAD_DRIVER_KEYPAD_H_
#define KEYPAD_DRIVER_KEYPAD_H_

#include"STM32_F103x6.h"
#include"STM32_F103c6_GPIO_Driver.h"

GPIO_PinConfig_t pincof;

//Keypad rows and columns
#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_2
#define R3 GPIO_PIN_3
#define C0 GPIO_PIN_4
#define C1 GPIO_PIN_5
#define C2 GPIO_PIN_6
#define C3 GPIO_PIN_7

//The connected ports (A/B/...) to the keypad
#define KEYPAD_PORT GPIOB


//APIs
void KEYPAD_INIT();
char KEYPAD_GetKey();


#endif /* KEYPAD_DRIVER_KEYPAD_H_ */
