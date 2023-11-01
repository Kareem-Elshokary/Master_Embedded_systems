/*
 *  STM32_F103x6.h
 *
 *  Eng. Kareem Abelkader
 *
 */

#ifndef INCLUDE_STM32_F103X6_H_
#define INCLUDE_STM32_F103X6_H_

/***********************************
 * Includes
 ***********************************/
#include<stdlib.h>
#include<stdint.h>



/***********************************
 * Base Addresses for Memories
 ***********************************/
#define FLASH_MEM_BASE                        0x08000000UL
#define SYSTEM_MEM_BASE                       0x1FFFF000UL
#define SRAM_MEM_BASE                         0x20000000UL
#define PERIPHERAL_MEM_BASE                   0x40000000UL
#define CPU_Internal_Peripheral_BASE          0xE0000000UL



/*************************************
 * Base Addresses for Bus Peripheral
 ************************************/

/*Base Addresses for AHB Peripheral*/
// Reset and clock control RCC
#define RCC_BASE                               0x40021000


/*Base Addresses for AHB Peripheral*/
//GPIO
#define GPIOA_BASE                             0x40010800
#define GPIOB_BASE                             0x40010C00
#define GPIOC_BASE                             0x40011000
#define GPIOD_BASE                             0x40011400
#define GPIOE_BASE                             0x40011800
#define GPIOF_BASE                             0x40011C00
#define GPIOG_BASE                             0x40012000

//EXTI
#define EXTI_BASE							   0x40010400

//AFIO
#define AFIO_BASE                              0x40010000

//NVIC
#define NVIC_BASE							   0xE000E100
#define NVIC_ISER0				*(volatile uint16_t*)(NVIC_BASE + 0x00)
#define NVIC_ISER1				*(volatile uint16_t*)(NVIC_BASE + 0x04)
#define NVIC_ISER2				*(volatile uint16_t*)(NVIC_BASE + 0x08)
#define NVIC_ICER0				*(volatile uint16_t*)(NVIC_BASE + 0x80)
#define NVIC_ICER1				*(volatile uint16_t*)(NVIC_BASE + 0x84)
#define NVIC_ICER2				*(volatile uint16_t*)(NVIC_BASE + 0x88)


//=====================================================================

/*************************************
 * Peripheral registers
 ************************************/

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSSR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	volatile uint32_t RESERVED0;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;


//=====================================================================

/*************************************
 * Peripheral instant
 ************************************/
#define GPIOA					((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB					((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC					((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD					((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE					((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF					((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG					((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOA					((GPIO_TypeDef *)GPIOA_BASE)
#define RCC						((RCC_TypeDef  *)RCC_BASE)
#define EXTI					((EXTI_TypeDef *)EXTI_BASE)
#define AFIO					((AFIO_TypeDef *)AFIO_BASE)




//======================================================================

/*************************************
 * Clock Enable Macros
 ************************************/
#define RCC_GPIOA_CLK_EN()			(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()			(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()			(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()			(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()			(RCC->APB2ENR |= 1<<6)
#define RCC_GPIOF_CLK_EN()			(RCC->APB2ENR |= 1<<7)
#define RCC_GPIOG_CLK_EN()			(RCC->APB2ENR |= 1<<8)
#define RCC_AFIO_CLK_EN()			(RCC->APB2ENR |= 1<<0)


//======================================================================

/*************************************
 * EXTI Macros
 ************************************/

//EXTI
#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10
#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23
#define EXTI10_IRQ			40
#define EXTI11_IRQ			40
#define EXTI12_IRQ			40
#define EXTI13_IRQ			40
#define EXTI14_IRQ			40
#define EXTI15_IRQ			40


//NVIC
#define NVIC_IRQ6_EXTI0_Enable()			(NVIC_ISER0 |= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable()			(NVIC_ISER0 |= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable()			(NVIC_ISER0 |= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable()			(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable()			(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable()			(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable()		(NVIC_ISER1 |= 1<<8)  //40 - 32 = 8

#define NVIC_IRQ6_EXTI0_Disable()			(NVIC_ISER0 |= (1<<6) )
#define NVIC_IRQ7_EXTI1_Disable()			(NVIC_ISER0 |= (1<<7) )
#define NVIC_IRQ8_EXTI2_Disable()			(NVIC_ISER0 |= (1<<8) )
#define NVIC_IRQ9_EXTI3_Disable()			(NVIC_ISER0 |= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable()			(NVIC_ISER0 |= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable()		(NVIC_ISER0 |= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable()		(NVIC_ISER1 |= 1<<8)  //40 - 32 = 8



#endif /* INCLUDE_STM32_F103X6_H_ */
