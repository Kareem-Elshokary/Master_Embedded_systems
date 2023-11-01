/*
 *  STM32_F103c6_EXTI_Driver.c
 *
 *  Eng. Kareem Abelkader
 *
 */

/***********************************
 * Includes
 ***********************************/
#include"STM32_F103c6_EXTI_Driver.h"
#include"STM32_F103c6_GPIO_Driver.h"


//===========================================================================================

/*************************************
 * Generic Variables
 ************************************/
//Array of 16 ptr to a function
void (* GP_CallBack[16])(void);



/*************************************
 * Generic Macros
 ************************************/
//Select the source input for EXTIx
#define AFIO_GPIO_EXTI_Mapping(x) ((x==GPIOA) ? 0:\
									(x==GPIOB) ? 1:\
									(x==GPIOC) ? 2:\
									(x==GPIOD) ? 3:0)



//===========================================================================================

/*************************************
 * Generic Functions
 ************************************/
void Enable_NVIC(uint16_t IRQ){
	switch(IRQ){
	case 0 :
		NVIC_IRQ6_EXTI0_Enable();
		break;
	case 1 :
		NVIC_IRQ7_EXTI1_Enable();
		break;
	case 2 :
		NVIC_IRQ8_EXTI2_Enable();
		break;
	case 3 :
		NVIC_IRQ9_EXTI3_Enable();
		break;
	case 4 :
		NVIC_IRQ10_EXTI4_Enable();
		break;
	case 5 :
	case 6 :
	case 7 :
	case 8 :
	case 9 :
		NVIC_IRQ23_EXTI5_9_Enable();
		break;
	case 10 :
	case 11 :
	case 12 :
	case 13 :
	case 14 :
	case 15 :
		NVIC_IRQ40_EXTI10_15_Enable();
		break;
	}
}

void Disable_NVIC(uint16_t IRQ){
	switch(IRQ){
		case 0 :
			NVIC_IRQ6_EXTI0_Disable();
			break;
		case 1 :
			NVIC_IRQ7_EXTI1_Disable();
			break;
		case 2 :
			NVIC_IRQ8_EXTI2_Disable();
			break;
		case 3 :
			NVIC_IRQ9_EXTI3_Disable();
			break;
		case 4 :
			NVIC_IRQ10_EXTI4_Disable();
			break;
		case 5 :
		case 6 :
		case 7 :
		case 8 :
		case 9 :
			NVIC_IRQ23_EXTI5_9_Disable();
			break;
		case 10 :
		case 11 :
		case 12 :
		case 13 :
		case 14 :
		case 15 :
			NVIC_IRQ40_EXTI10_15_Disable();
			break;
		}
}

void Update_EXTI(EXTI_Pinconfig_t* PinCFG){
	// 1- Configure the pin to be an AF (Floating Input)
	GPIO_PinConfig_t PinCfg;
	PinCfg.GPIO_PinNumber = PinCFG->EXTI_Pin.GPIO_Pin;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_ALT;
	MCAL_GPIO_INIT(PinCFG->EXTI_Pin.GPIO_Port, &PinCfg);

	// 2- Update AFIO to route EXTI line between GPIO_Port A,B,C,D
	uint8_t AFIO_EXTICR_Index = PinCFG->EXTI_Pin.EXTI_InputLineNum / 4;
	uint8_t AFIO_EXTICR_Position = (PinCFG->EXTI_Pin.EXTI_InputLineNum % 4) * 4;
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xf << AFIO_EXTICR_Position);            //Clear the 4bits first
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ( (AFIO_GPIO_EXTI_Mapping(PinCFG->EXTI_Pin.GPIO_Port) & 0x0f) << AFIO_EXTICR_Position);

	// 3- Choose trigger case for EXTI Pin
	EXTI->RTSR &= ~(1 << PinCFG->EXTI_Pin.EXTI_InputLineNum);
	EXTI->FTSR &= ~(1 << PinCFG->EXTI_Pin.EXTI_InputLineNum);

	//Then we choose Trigger_Case
	if(PinCFG->Trigger_Case == RISING)
	{
		EXTI->RTSR |= (1 << PinCFG->EXTI_Pin.EXTI_InputLineNum);

	}else if(PinCFG->Trigger_Case == FALLING)
	{
		EXTI->FTSR |= (1 << PinCFG->EXTI_Pin.EXTI_InputLineNum);

	}else if(PinCFG->Trigger_Case == RISINGandFALLING)
	{
		EXTI->RTSR |= (1 << PinCFG->EXTI_Pin.EXTI_InputLineNum);
		EXTI->FTSR |= (1 << PinCFG->EXTI_Pin.EXTI_InputLineNum);
	}

	// 4- Locate Interrupt handle Function called in main if IRQ is done
	GP_CallBack[PinCFG->EXTI_Pin.EXTI_InputLineNum] = PinCFG->P_CallBack;

	// 5- Enable/Disable IRQ for EXTI Pin
	if(PinCFG->IRQ_EN == EXTI_IRQ_EN){
		EXTI->IMR |= (1 << PinCFG->EXTI_Pin.EXTI_InputLineNum);
		Enable_NVIC(PinCFG->EXTI_Pin.EXTI_InputLineNum);
	}
	else{
		EXTI->IMR &= ~(1 << PinCFG->EXTI_Pin.EXTI_InputLineNum);
		Disable_NVIC(PinCFG->EXTI_Pin.EXTI_InputLineNum);
	}

}

//===========================================================================================

/**================================================================
* @Fn			- MCAL_EXTI_GPIO_DEINIT
* @brief 		- Uninitialization of EXTI
* @param [in] 	- none
* @retval 		- none
* Note			- none
*/
void MCAL_EXTI_GPIO_DEINIT(void){
	//EXTI
	EXTI->IMR   = 0x00000000;
	EXTI->EMR   = 0x00000000;
	EXTI->FTSR  = 0x00000000;
	EXTI->RTSR  = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR    = 0xffffffff; //Clear by write 1

	//NVIC
	NVIC_IRQ6_EXTI0_Disable();
	NVIC_IRQ7_EXTI1_Disable();
	NVIC_IRQ8_EXTI2_Disable();
	NVIC_IRQ9_EXTI3_Disable();
	NVIC_IRQ10_EXTI4_Disable();
	NVIC_IRQ23_EXTI5_9_Disable();
	NVIC_IRQ40_EXTI10_15_Disable();
}


/**===============================================================================================
 * @FName			- MCAL_EXTI_GPIO_Init
 * @Brief 			- Used to initialize EXTI from specific GPIO pin and specify the mask/trigger options and callback function
 * @Parameter [in] 	- PinConfig: Pointer takes the address of EXTI_PinConfig_t structure that contains
 * 								 Configuration data for a single EXTI pin
 * @Return Value	- NONE
 * Note				- PinConfig is only set by @ref EXTI_define & @ref EXTI_Trigger_define & @ref EXTI_IRQ_define
 * 					  it is also mandatory to enable RCC clock for AFIO and corresponding GPIO
 */
void MCAL_EXTI_GPIO_INIT(EXTI_Pinconfig_t* pin){
	Update_EXTI(pin);
}



/*
 * =============================================================================
 * 								ISR Functions
 * =============================================================================
 */
void EXTI0_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<0);

	//Call the IRQ callback Function
	GP_CallBack[0]();

}

void EXTI1_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<1);

	//Call the IRQ callback Function
	GP_CallBack[1]();

}

void EXTI2_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<2);

	//Call the IRQ callback Function
	GP_CallBack[2]();

}

void EXTI3_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<3);

	//Call the IRQ callback Function
	GP_CallBack[3]();

}

void EXTI4_IRQHandler(void)
{
	//Clear IRQ bit in Pending Register (EXTI_PR)
	EXTI->PR |= (1 <<4);

	//Call the IRQ callback Function
	GP_CallBack[4]();

}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & (1 << 5)) { EXTI->PR |= (1 << 5); GP_CallBack[5](); }
	if(EXTI->PR & (1 << 6)) { EXTI->PR |= (1 << 6); GP_CallBack[6](); }
	if(EXTI->PR & (1 << 7)) { EXTI->PR |= (1 << 7); GP_CallBack[7](); }
	if(EXTI->PR & (1 << 8)) { EXTI->PR |= (1 << 8); GP_CallBack[8](); }
	if(EXTI->PR & (1 << 9)) { EXTI->PR |= (1 << 9); GP_CallBack[9](); }
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & (1 << 10)) { EXTI->PR |= (1 << 10); GP_CallBack[10](); }
	if(EXTI->PR & (1 << 11)) { EXTI->PR |= (1 << 11); GP_CallBack[11](); }
	if(EXTI->PR & (1 << 12)) { EXTI->PR |= (1 << 12); GP_CallBack[12](); }
	if(EXTI->PR & (1 << 13)) { EXTI->PR |= (1 << 13); GP_CallBack[13](); }
	if(EXTI->PR & (1 << 14)) { EXTI->PR |= (1 << 14); GP_CallBack[14](); }
	if(EXTI->PR & (1 << 15)) { EXTI->PR |= (1 << 15); GP_CallBack[15](); }
}




