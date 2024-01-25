/*
 * RCC.c
 *
 * Master Embedded System Diploma
 * Eng. Kareem Abelkader
 */


/******************************
 * Includes
 *******************************/
#include "RCC.h"

//==========================================================================

/*
// bit control Func.
set_bit -->(reg = reg| (1<<bit))
clear_bit-->(reg = reg &~ (1<<bit))
read_bit-->((reg >> bit) & 1)
toggle_bit-->(reg = reg ^ (1<<bit))
*/

uint32_t MCAL_RCC_GetSYS_CLCKFreq(void)
{
	// PLL enable
	//---------------------------------
	 RCC->CR |  (1 << 24) ;
	//---------------------------------
	//PREDIV1 0000: PREDIV1 input clock not divided
	//---------------------------------
	RCC->CFGR2 |  (0b0000 << 0) ;
	//---------------------------------
	//PREDIV1 entry clock source : 0: HSE oscillator clock selected as PREDIV1 clock entry
	//---------------------------------
	RCC->CFGR2 &~ (1 << 16)  ;
	//---------------------------------
	//PLL entry clock source : 1: Clock from PREDIV1 selected as PLL input clock
	//---------------------------------
	RCC->CFGR |  (1 << 16)   ;
	//---------------------------------
	//PLL multiplication factor : 0101: PLL input clock x 7
	//---------------------------------
	RCC->CFGR |  (0b0101 << 18)   ;
	//---------------------------------
	// System clock Switch : 10: PLL selected as system clock
	//---------------------------------
	RCC->CFGR |  (0b01 << 0)   ;
	//---------------------------------
}

uint32_t MCAL_RCC_GetHCLKFreq(void)
{
	MCAL_RCC_GetSYS_CLCKFreq();
	return RCC->CFGR &~  (0b1111 << 4)   ;
}

//APB Low speed clock (PCLK1).
//Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
uint32_t MCAL_RCC_GetPCLK1Freq(void)
{
	 MCAL_RCC_GetHCLKFreq();
	return RCC->CFGR  | (0b100 << 8)   ;
}

uint32_t MCAL_RCC_GetPCLK2Freq(void)
{
	 MCAL_RCC_GetHCLKFreq();
	return RCC->CFGR &~  (0b1111 << 11)   ;

}

uint32_t MCAL_RCC_GetPCLK2_ADCFreq(void)
{
	 MCAL_RCC_GetHCLKFreq();
	return RCC->CFGR |  (0b10 << 14)   ;
}
