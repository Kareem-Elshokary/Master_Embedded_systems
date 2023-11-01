/*
 *  STM32_F103c6_GPIO_Driver.c
 *
 *  Eng. Kareem Abelkader
 *
 */


/***********************************
 * Includes
 ***********************************/
#include"STM32_F103c6_GPIO_Driver.h"
#include"STM32_F103x6.h"


//===========================================================================================

/**================================================================
* @Fn			- Get_CRLH_Position
* @brief 		- Access the bits of the selected pin
* @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
* @retval 		- The pin position
* Note			- none
*/
uint8_t Get_CRLH_Position(uint16_t PinNum)
{
	switch(PinNum)
	{
	//CRL
	case GPIO_PIN_0:
		return 0 ;
		break;

	case GPIO_PIN_1:
		return 4;
		break;

	case GPIO_PIN_2:
		return 8;
		break;

	case GPIO_PIN_3:
		return 12;
		break;

	case GPIO_PIN_4:
		return 16;
		break;

	case GPIO_PIN_5:
		return 20;
		break;

	case GPIO_PIN_6:
		return 24;
		break;

	case GPIO_PIN_7:
		return 28;
		break;

	//CRH
	case GPIO_PIN_8:
		return 0;
		break;

	case GPIO_PIN_9:
		return 4;
		break;

	case GPIO_PIN_10:
		return 8;
		break;

	case GPIO_PIN_11:
		return 12;
		break;

	case GPIO_PIN_12:
		return 16;
		break;

	case GPIO_PIN_13:
		return 20;
		break;

	case GPIO_PIN_14:
		return 24;
		break;

	case GPIO_PIN_15:
		return 28;
		break;


	}
	return 0;
}



/**================================================================
* @Fn			- MCAL_GPIO_INIT
* @brief 		- Initializes the GPIOx PINy according to a specific parameter in the Pin Configuration
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinConfig: points to GPIO_PinConfig_t that contain the configuration of the pin
* @retval 		- none
* Note			- none
*/
void MCAL_GPIO_INIT(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig){
	//Port configuration register low (GPOIx_CRL) configure pins from 0:7
	//Port configuration register high (GPOIx_CRH) configure pins from 8:15
	uint8_t Pinconfig = 0;
	volatile uint32_t* configregister = NULL;
	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH;

	//Clear CNF8[1:0] MODE8[1:0]
	(*configregister) &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//If pin is output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_ALT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_ALT_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP)){
		//Set CNF8[1:0] MODE8[1:0]
		Pinconfig = ((((PinConfig->GPIO_MODE - 4) << 2) | PinConfig->GPIO_Output_Speed) & 0x0f);
		(*configregister) |= (Pinconfig << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
	}
	//If pin is input
	else{
		if((PinConfig->GPIO_MODE == GPIO_MODE_ANALOG) || (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO)){
			//Set CNF8[1:0] MODE8[0:0]
			Pinconfig = ((((PinConfig->GPIO_MODE) << 2) | 0x00) & 0x0f);
		}
		else if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_ALT){
			//Set CNF8[1:0] MODE8[0:0]
			Pinconfig = ((((GPIO_MODE_INPUT_FLO) << 2) | 0x00) & 0x0f);
		}
		else{
			Pinconfig = ((((GPIO_MODE_INPUT_PU) << 2) | 0x00) & 0x0f);
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU){
				//PxODR = 1 pull-up
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber);
			}
			else{
				//PxODR = 0 pull-down
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}

	(*configregister) |= (Pinconfig << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
}


/**================================================================
* @Fn			- MCAL_GPIO_DEINIT
* @brief 		- Reset the GPIOx PINy according to a specific parameter in the Pin Configuration
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @retval 		- none
* Note			- none
*/
void MCAL_GPIO_DEINIT(GPIO_TypeDef* GPIOx){
	if (GPIOx == GPIOA){

		RCC->APB2RSTR |=  (1 << 2) ;  //Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1 << 2) ;

	}
	else if (GPIOx == GPIOB){

		RCC->APB2RSTR |=  (1 << 3) ;  //Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR &= ~(1 << 3) ;

	}
	else if (GPIOx == GPIOC){

		RCC->APB2RSTR |=  (1 << 4) ;  //Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR &= ~(1 << 4) ;

	}
	else if (GPIOx == GPIOD){

		RCC->APB2RSTR |=  (1 << 5) ;  //Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR &= ~(1 << 5) ;

	}
	else if (GPIOx == GPIOE){

		RCC->APB2RSTR |=  (1 << 6) ;  //Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR &= ~(1 << 6) ;

	}
	else if (GPIOx == GPIOF){

		RCC->APB2RSTR |=  (1 << 7) ;  //Bit 7 IOPERST: IO port F reset
		RCC->APB2RSTR &= ~(1 << 7) ;

	}
	else{
		RCC->APB2RSTR |=  (1 << 8) ;  //Bit 8 IOPERST: IO port G reset
		RCC->APB2RSTR &= ~(1 << 8) ;
	}

}


/**================================================================
* @Fn			- MCAL_GPIO_READPIN
* @brief 		- Read from a specific pin
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
* @retval 		- Pin status (two values according to PIN_STATUS)
* Note			- none
*/
uint8_t MCAL_GPIO_READPIN(GPIO_TypeDef* GPIOx, uint8_t PinNumber){
	if((GPIOx->IDR & PinNumber) != (uint32_t)GPIO_PIN_RESET )
	{

		return GPIO_PIN_SET;
	}
	else
	{

		return GPIO_PIN_RESET ;
	}
}


/**================================================================
* @Fn			- MCAL_GPIO_READPORT
* @brief 		- Read the port
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @retval 		- The input port value
* Note			- none
*/
uint16_t MCAL_GPIO_READPORT(GPIO_TypeDef* GPIOx){
	return (uint16_t)GPIOx->IDR;
}


/**================================================================
* @Fn			- MCAL_GPIO_WRITEPIN
* @brief 		- Write on a specific pin
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
* @param [in] 	- value: pin value
* @retval 		- none
* Note			- none
*/
void MCAL_GPIO_WRITEPIN(GPIO_TypeDef* GPIOx, uint8_t PinNumber, uint8_t value){
	//We can use ODR and Also we can use BSRR to reset and BRR to set pin value
	//i'm using BSRR to reset and BRR to set pin values

	if(value == (uint8_t)GPIO_PIN_SET)
	{
		/*  Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Set the corresponding ODRx bit              */

		GPIOx->BSSR = (uint32_t)PinNumber;
	}

	else
	{

		/*	Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Reset the corresponding ODRx bit				*/

		GPIOx->BRR = (uint32_t)PinNumber;
	}
}


/**================================================================
* @Fn			- MCAL_GPIO_WRITEPORT
* @brief 		- Write on a specific pin
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- value: port value
* @retval 		- none
* Note			- none
*/
void MCAL_GPIO_WRITEPORT(GPIO_TypeDef* GPIOx, uint16_t value){
	GPIOx->ODR = (uint32_t)value;
}


/**================================================================
* @Fn			- MCAL_GPIO_TOGGLEPIN
* @brief 		- Toggle a specific pin
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
* @retval 		- none
* Note			- none
*/
void MCAL_GPIO_TOGGLEPIN(GPIO_TypeDef* GPIOx, uint8_t PinNumber){
	GPIOx->ODR ^= (uint32_t)PinNumber;
}


/**================================================================
* @Fn			- MCAL_GPIO_LOCKPIN
* @brief 		- Lock a specific pin
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
* @retval 		- OK if the pin locked, ERROR if the pin not locked according to GPIO PIN LOCK DEF
* Note			- none
*/
uint8_t MCAL_GPIO_LOCKPIN(GPIO_TypeDef* GPIOx, uint8_t PinNumber){
	// Bit 16 LCKK[16]: Lock key
	// This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	// 0: Port configuration lock key not active
	// 1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	// LOCK key writing sequence:
	// Write 1
	// Write 0
	// Write 1
	// Read 0
	// Read 1 (this read is optional but confirms that the lock is active)
	// Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	// Any error in the lock sequence will abort the lock.

	// Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	// These bits are read write but can only be written when the LCKK bit is 0.
	// 0: Port configuration not locked
	// 1: Port configuration locked.

	//Set LCCK[16]
	volatile uint32_t temp= 1<<16;


	//write 1 in the selected pin
	GPIOx->LCKR |= (uint32_t)PinNumber;

	//Bit 16 LCKK[16]: Lock key Lock sequence:

	temp |= (uint32_t)PinNumber;
	// Write 1
	GPIOx->LCKR = temp;

	// Write 0
	GPIOx->LCKR = (uint32_t)PinNumber;

	// Write 1
	GPIOx->LCKR = temp;

	// Read 0
	temp = GPIOx->LCKR;

	// Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)(GPIOx->LCKR & (1<<16)))
	{
		return GPIO_PIN_LOCKED;
	}
	else
	{
		return GPIO_PIN_UNLOCKED;
	}
}











