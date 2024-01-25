/*
 * GPIO.c
 *
 * Master Embedded System Diploma
 * Eng. Kareem Abelkader
 */


/******************************
 * Includes
 *******************************/
#include "GPIO.h"

//==========================================================================
/**================================================================
* @Fn			- Get_CRLH_Position
* @brief 		- Access the bits of the selected pin
* @param [in] 	- PinNum: the selected pin according to GPIO_PINS_DEF
* @retval 		- The pin position
* Note			- none
*/
uint8_t Get_CRLH_Position(uint16_t PinNum){
	switch(PinNum){
	//CRL
	case PIN_0:
		return 0 ;
		break;

	case PIN_1:
		return 4;
		break;

	case PIN_2:
		return 8;
		break;

	case PIN_3:
		return 12;
		break;

	case PIN_4:
		return 16;
		break;

	case PIN_5:
		return 20;
		break;

	case PIN_6:
		return 24;
		break;

	case PIN_7:
		return 28;
		break;

	//CRH
	case PIN_8:
		return 0;
		break;

	case PIN_9:
		return 4;
		break;

	case PIN_10:
		return 8;
		break;

	case PIN_11:
		return 12;
		break;

	case PIN_12:
		return 16;
		break;

	case PIN_13:
		return 20;
		break;

	case PIN_14:
		return 24;
		break;

	case PIN_15:
		return 28;
		break;
	}

	return 0;
}


/**================================================================
* @Fn			- MCAL_GPIO_INIT
* @brief 		- Initializes the GPIOx PINy according to a specific parameter in the Pin Configuration
* @param [in] 	- GPIOx: x can be (A:D depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinConfig: points to GPIO_PinConfig_t that contain the configuration of the pin
* @retval 		- none
* Note			- none
*/
void MCAL_GPIO_INIT(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig){
	// GPIOx_CRL register configure bits from 0 to 7
	// GPIOx_CRH register configure bits from 8 to 15
	// Check the pin number to determine the suitable register (CRL/CRH)
	volatile uint32_t* Config_Reg = NULL;
	Config_Reg = (PinConfig->Pin_Num < PIN_8)? &GPIOx->CRL : &GPIOx->CRH;
	//To configure the pin, clear CNF[1:0] MODE[1:0]
	(*Config_Reg) &= ~(0xf << Get_CRLH_Position(PinConfig->Pin_Num));


	uint8_t PIN_Config = 0;

	//In output mode
	if((PinConfig->Pin_Mode == OUTPUT_PP_MODE) || (PinConfig->Pin_Mode == OUTPUT_OD_MODE) || (PinConfig->Pin_Mode == OUTPUT_ALT_PP_MODE) || (PinConfig->Pin_Mode == OUTPUT_ALT_OD_MODE)){
		//Set CNF[1:0] MODE[1:0]
		//the (-4) is because we specified in the .h that the four output confider start from 0x4 till 0x7
		PIN_Config = ( (((PinConfig->Pin_Mode - 4) << 2) | (PinConfig->Pin_Speed)) & 0x0F);
		(*Config_Reg) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->Pin_Num) );
	}
	else{
		//In input mode
		//Check if the pin mode equal to one of input modes
		if((PinConfig->Pin_Mode == ANALOG_MODE) || (PinConfig->Pin_Mode == INPUT_FLO_MODE)){
			//Set CNF[0:0] MODE[0:0]
			PIN_Config = ( ( ((PinConfig->Pin_Mode) << 2) | 0x00) & 0x0F);
			(*Config_Reg) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->Pin_Num) );
		}
		else if((PinConfig->Pin_Mode == INPUT_ALT_MODE)){
			//Set CNF[0:1] MODE[0:0]
			PIN_Config = ( ( ((INPUT_FLO_MODE) << 2) | 0x00) & 0x0F);
			(*Config_Reg) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->Pin_Num) );
		}
		else{
			//Set CNF[1:0] MODE[0:0]
			PIN_Config = ( ( ((INPUT_PU_MODE) << 2) | 0x00) & 0x0F);
			(*Config_Reg) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->Pin_Num) );
			//From TRM
			if(PinConfig->Pin_Mode == INPUT_PU_MODE){
				//PxODR = 1 pull-up
				GPIOx->ODR |= (PinConfig->Pin_Num);
			}
			else{
				//PxODR = 0 pull-down
				GPIOx->ODR &= ~(PinConfig->Pin_Num);
			}
		}

	}


}


/**================================================================
* @Fn			- MCAL_GPIO_DEINIT
* @brief 		- Reset the GPIOx PINy according to a specific parameter in the Pin Configuration
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @retval 		- none
* Note			- Can be reset by reset controller
*/
void MCAL_GPIO_DEINIT(GPIO_TypeDef* GPIOx){
	GPIOx->CRL  = 0x44444444;
	GPIOx->CRH  = 0x44444444;
	GPIOx->ODR  = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->BRR  = 0x00000000;
	GPIOx->LCKR = 0x00000000;
}


/**================================================================
* @Fn			- MCAL_GPIO_WRITEPIN
* @brief 		- Write on a specific pin
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
* @param [in] 	- value: pin value
* @retval 		- none
* Note			- The value that passing to the function, it defined at Pin_Statuse reference (Pin_SET/Pin_RESET)
*/
void MCAL_GPIO_WRITEPIN(GPIO_TypeDef* GPIOx, uint16_t PinNumber, uint8_t value){
	//Set the pin
	if( value != Pin_RESET ){
		GPIOx->ODR |= PinNumber;

		/*
		 *  For atomic bit set/reset,
		 *  the ODR bits can be individually set and cleared by writing to the GPIOx_BSRR register (x = A .. G).
		 *  BSy: Port x Set bit y (y= 0 .. 15)
			These bits are write-only and can be accessed in Word mode only.
			0: No action on the corresponding ODRx bit
			1: Set the corresponding ODRx bit
		 */
		//GPIOx->BSRR = value;
	}
	//Reset the pin
	else{
		GPIOx->ODR &= ~(PinNumber);

		/*
		 * BRy: Port x Reset bit y (y= 0 .. 15)
		   These bits are write-only and can be accessed in Word mode only.
		   0: No action on the corresponding ODRx bit
		   1: Reset the corresponding ODRx bit
		 */
		//GPIOx->BRR = PinNumber;
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
	GPIOx->ODR = (uint32_t)(value);
}


/**================================================================
* @Fn			- MCAL_GPIO_READPIN
* @brief 		- Read from a specific pin
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
* @retval 		- Pin status (two values according to PIN_STATUS)
* Note			- none
*/
uint8_t MCAL_GPIO_READPIN(GPIO_TypeDef* GPIOx, uint16_t PinNumber){
	//IDRy: Port input data (y= 0 .. 15)
	//These bits are read only and can be accessed in Word mode only. They contain the input value of the corresponding I/O port.
	uint8_t Pin_Value;
	if( (GPIOx->IDR & PinNumber) != (uint32_t)Pin_RESET){
		Pin_Value = Pin_SET;
	}
	else{
		Pin_Value = Pin_RESET;
	}

	return Pin_Value;
}


/**================================================================
* @Fn			- MCAL_GPIO_READPORT
* @brief 		- Read the port
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @retval 		- The input port value
* Note			- none
*/
uint16_t MCAL_GPIO_READPORT(GPIO_TypeDef* GPIOx){
	uint16_t Port_Value;
	Port_Value = (uint16_t)(GPIOx->IDR);
	return Port_Value;
}


/**================================================================
* @Fn			- MCAL_GPIO_TOGGLEPIN
* @brief 		- Toggle a specific pin
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
* @retval 		- none
* Note			- none
*/
void MCAL_GPIO_TOGGLEPIN(GPIO_TypeDef* GPIOx, uint16_t PinNumber){
	GPIOx->ODR ^= (PinNumber);
}


/**================================================================
* @Fn			- MCAL_GPIO_TOGGLEPORT
* @brief 		- Toggle the port
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @retval 		- none
* Note			- none
*/
void MCAL_GPIO_TOGGLEPORT(GPIO_TypeDef* GPIOx){
	GPIOx->ODR ^= 0xFFFF;
}


/**================================================================
* @Fn			- MCAL_GPIO_LOCKPIN
* @brief 		- Lock a specific pin
* @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
* @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
* @retval 		- Pin_LOCKED if the pin locked, Pin_UNLOCKED if the pin not locked according to GPIO PIN LOCK DEF
* Note			- none
*/
uint8_t MCAL_GPIO_LOCKPIN(GPIO_TypeDef* GPIOx, uint16_t PinNumber){
	volatile uint32_t temp = 1<<16;

	/*
	 * LCKK[16]: Lock key
	   This bit can be read any time. It can only be modified using the Lock Key Writing Sequence.
	   0: Port configuration lock key not active
	   1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset
	   LCKy: Port x Lock bit y (y= 0 .. 15)
	   These bits are read write but can only be written when the LCKK bit is 0.
		0: Port configuration not locked
		1: Port configuration locked
	 */

	GPIOx->LCKR |= PinNumber;

	//Writing Sequence.
	//Write 1
	GPIOx->LCKR = temp;
	//Write 0
	GPIOx->LCKR = (uint32_t)PinNumber;
	//Write 1
	GPIOx->LCKR = temp;
	//Read 0
	temp = GPIOx->LCKR;
	//Read 1
	if( (uint32_t)(GPIOx->LCKR & (1<<16)) ){
		return Pin_LOCKED;
	}
	else{
		return Pin_UNLOCKED;
	}
}


