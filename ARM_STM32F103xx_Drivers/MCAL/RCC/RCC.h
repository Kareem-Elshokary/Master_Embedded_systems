/*
 * RCC.h
 *
 * Master Embedded System Diploma
 * Eng. Kareem Abelkader
 */

#ifndef RCC_RCC_H_
#define RCC_RCC_H_

/******************************
 * Includes
 *******************************/
#include "STM32F103x8.h"

//==========================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

/*1st: AHB peripherals Enable*/

//DMA1 clock Enable
#define RCC_DMA1_CLK_EN()	( RCC->AHBENR |= (1<<0) )
//DMA2 clock Enable
#define RCC_DMA2_CLK_EN()	( RCC->AHBENR |= (1<<1) )
//SRAM clock Enable
#define RCC_SRAM_CLK_EN()	( RCC->AHBENR |= (1<<2) )
//FLITFEN clock Enable
#define RCC_FLITF_CLK_EN()	( RCC->AHBENR |= (1<<4) )
//FLITFEN clock Enable
#define RCC_CRC_CLK_EN()	( RCC->AHBENR |= (1<<6) )
//FLITFEN clock Enable
#define RCC_OTGFS_CLK_EN()	( RCC->AHBENR |= (1<<12) )
//FLITFEN clock Enable
#define RCC_ETHMAC_CLK_EN()	( RCC->AHBENR |= (1<<14) )
//FLITFEN clock Enable
#define RCC_ ETHMACTX_CLK_EN()	( RCC->AHBENR |= (1<<15) )
//FLITFEN clock Enable
#define RCC_ETHMACRX_CLK_EN()	( RCC->AHBENR |= (1<<16) )
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

/*2nd: APB1 peripherals Enable*/

//TIMER2 clock Enable
#define RCC_TIM2_CLK_EN()	( RCC->APB1ENR |= (1<<0) )
//TIMER3 clock Enable
#define RCC_TIM3_CLK_EN()	( RCC->APB1ENR |= (1<<1) )
//TIMER4 clock Enable
#define RCC_TIM4_CLK_EN()	( RCC->APB1ENR |= (1<<2) )
//TIMER4 clock Enable
#define RCC_TIM4_CLK_EN()	( RCC->APB1ENR |= (1<<2) )
//WWDG clock Enable
#define RCC_WWDG_CLK_EN()	( RCC->APB1ENR |= (1<<11) )
//SPI1 clock Enable
#define RCC_SPI2_CLK_EN()	( RCC->APB1ENR |= (1<<14) )
//USART2 clock Enable
#define RCC_USART2_CLK_EN()	( RCC->APB1ENR |= (1<<17) )
//USART3 clock Enable
#define RCC_USART3_CLK_EN()	( RCC->APB1ENR |= (1<<18) )
//I2C1 clock Enable
#define RCC_I2C1_CLK_EN()	( RCC->APB1ENR |= (1<<21) )
//I2C2 clock Enable
#define RCC_I2C2_CLK_EN()	( RCC->APB1ENR |= (1<<22) )
//CAN1 clock Enable
#define RCC_CAN1_CLK_EN()	( RCC->APB1ENR |= (1<<25) )
//CAN2 clock Enable
#define RCC_CAN12_CLK_EN()	( RCC->APB1ENR |= (1<<26) )
//BKP clock Enable
#define RCC_BKP_CLK_EN()	( RCC->APB1ENR |= (1<<27) )
//PWR clock Enable
#define RCC_PWR_CLK_EN()	( RCC->APB1ENR |= (1<<28) )
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

/*3rd: APB2 peripherals Enable*/

//Enable clock AFIO
#define RCC_AFIO_CLK_EN()	( RCC->APB2ENR |= (1<<0) )
//Enable clock GPIOA
#define RCC_GPIOA_CLK_EN()	( RCC->APB2ENR |= (1<<2) )
//Enable clock GPIOB
#define RCC_GPIOB_CLK_EN()	( RCC->APB2ENR |= (1<<3) )
//Enable clock GPIOC
#define RCC_GPIOC_CLK_EN()	( RCC->APB2ENR |= (1<<4) )
//Enable clock ADC1
#define RCC_ADC1_CLK_EN()	( RCC->APB2ENR |= (1<<9) )
//Enable clock ADC2
#define RCC_ADC2_CLK_EN()	( RCC->APB2ENR |= (1<<10) )
//Enable clock TIM1
#define RCC_TIM1_CLK_EN()	( RCC->APB2ENR |= (1<<11) )
//Enable clock SPI1
#define RCC_SPI1_CLK_EN()	( RCC->APB2ENR |= (1<<12) )
//Enable clock USART1
#define RCC_USART1_CLK_EN()	( RCC->APB2ENR |= (1<<14) )

//==========================================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Clock Reset Macros:
//-*-*-*-*-*-*-*-*-*-*-*

/*APB1 peripherals reset*/

//TIMER2 clock reset
#define RCC_TIM2_CLK_Reset()	( RCC->APB1RSTR |= (1<<0) )
//TIMER3 clock reset
#define RCC_TIM3_CLK_Reset()	( RCC->APB1RSTR |= (1<<1) )
//TIMER4 clock reset
#define RCC_TIM4_CLK_Reset()	( RCC->APB1RSTR |= (1<<2) )
//TIMER4 clock reset
#define RCC_TIM4_CLK_Reset()	( RCC->APB1RSTR |= (1<<2) )
//WWDG clock reset
#define RCC_WWDG_CLK_Reset()	( RCC->APB1RSTR |= (1<<11) )
//SPI1 clock reset
#define RCC_SPI2_CLK_Reset()	( RCC->APB1RSTR |= (1<<14) )
//USART2 clock reset
#define RCC_USART2_CLK_Reset()	( RCC->APB1RSTR |= (1<<17) )
//USART3 clock reset
#define RCC_USART3_CLK_Reset()	( RCC->APB1RSTR |= (1<<18) )
//I2C1 clock reset
#define RCC_I2C1_CLK_Reset()	( RCC->APB1RSTR |= (1<<21) )
//I2C2 clock reset
#define RCC_I2C2_CLK_Reset()	( RCC->APB1RSTR |= (1<<22) )
//CAN1 clock reset
#define RCC_CAN1_CLK_Reset()	( RCC->APB1RSTR |= (1<<25) )
//CAN2 clock reset
#define RCC_CAN2_CLK_Reset()	( RCC->APB1RSTR |= (1<<26) )
//BKP clock reset
#define RCC_BKP_CLK_Reset()	( RCC->APB1RSTR |= (1<<27) )
//PWR clock reset
#define RCC_PWR_CLK_Reset()	( RCC->APB1RSTR |= (1<<28) )
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

/*APB2 peripherals reset*/

//reset clock AFIO
#define RCC_AFIO_CLK_Reset()	( RCC->APB2RSTR |= (1<<0) )
//reset clock GPIOA
#define RCC_GPIOA_CLK_Reset()	( RCC->APB2RSTR |= (1<<2) )
//reset clock GPIOB
#define RCC_GPIOB_CLK_Reset()	( RCC->APB2RSTR |= (1<<3) )
//reset clock GPIOC
#define RCC_GPIOC_CLK_Reset()	( RCC->APB2RSTR |= (1<<4) )
//reset clock ADC1
#define RCC_ADC1_CLK_Reset()	( RCC->APB2RSTR |= (1<<9) )
//reset clock ADC2
#define RCC_ADC2_CLK_Reset()	( RCC->APB2RSTR |= (1<<10) )
//reset clock TIM1
#define RCC_TIM1_CLK_Reset()	( RCC->APB2RSTR |= (1<<11) )
//reset clock SPI1
#define RCC_SPI1_CLK_Reset()	( RCC->APB2RSTR |= (1<<12) )
//reset clock USART1
#define RCC_USART1_CLK_Reset()	( RCC->APB2RSTR |= (1<<14) )

//==========================================================================

/*
 * ===============================================
 * APIs Supported by "MCAL RCC DRIVER"
 * ===============================================
 */

uint32_t MCAL_RCC_GetSYS_CLCKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);
uint32_t MCAL_RCC_GetPCLK2_ADCFreq(void);


#endif /* RCC_RCC_H_ */
