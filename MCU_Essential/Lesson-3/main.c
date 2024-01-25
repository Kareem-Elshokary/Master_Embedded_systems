/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include"STM32_F103x6.h"
#include"STM32_F103c6_GPIO_Driver.h"

void Clock_INIT(){
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void GPIO_INIT(){
	GPIO_PinConfig_t PinCfg;

	//Pin A1 is input
	//High impedance (Floating mode) mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PinCfg);

	//Pin A13 is input
	//High impedance (Floating mode) mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(GPIOA, &PinCfg);

	//Pin B1 is output
	//Push-Pull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(GPIOB, &PinCfg);

	//Pin B13 is output
	//Push-Pull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_INIT(GPIOB, &PinCfg);
}

void Delay(int x){
	for(int i=0; i<x; i++);
}

int main(void)
{
	Clock_INIT();
	GPIO_INIT();

	while(1){
		if( MCAL_GPIO_READPIN(GPIOA, GPIO_PIN_1) == 0 ){
			MCAL_GPIO_TOGGLEPIN(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_READPIN(GPIOA, GPIO_PIN_1) == 0);
		}
		if( MCAL_GPIO_READPIN(GPIOA, GPIO_PIN_13) == 0 ){
			MCAL_GPIO_TOGGLEPIN(GPIOB, GPIO_PIN_13);
		}
		Delay(20000);
	}
}







