/*************************************************************************/
/* Author        : Kareem Abdelkader                                   			  	  	*/
/* Project       : STM32F103C8_Drivers  	                             			  	*/
/* File          : GPIO.h		     		                       				      	*/
/* Date          : 19/2/2024                                        				  	*/
/* Version       : V2                                                				    */
/* GitHub        : https://github.com/Kareem-Elshokary/Master_Embedded_systems          */
/*************************************************************************/


/*****************************
 * Includes
 ****************************/
#include "GPIO.h"

//=====================================================================

/*****************************
 * Generic Function
 ****************************/




//=====================================================================

/**================================================================
 * @Fn			- MCAL_GPIO_INIT
 * @brief 		- Initializes the GPIOx PINy according to a specific parameter in the Pin Configuration
 * @param [in] 	- GPIOx: x can be (A:D depend on the device used) to select the GPIO peripheral
 * @param [in] 	- pin_num: pin number
 * @param [in] 	- mode: pin is output / input
 * @param [in] 	- speed: pin speed
 * @retval 		- none
 * Note			- none
 */
void MCAL_GPIO_INIT(GPIO_REG_t* GPIOx, uint16_t pin_num, uint32_t mode, uint32_t speed)
{
	if( pin_num < 8 )
	{
		if( mode == INPUT_ANALOG || mode == INPUT_FLOATING || mode == INPUT_PU || mode == INPUT_PD || mode == INPUT_AF){
			//			GPIOx->GPIOx_CRL &= ~( (0b1111) << (pin_num * 4)) ;
			//			GPIOx->GPIOx_CRL |= ( (mode) << (pin_num * 4)) ;

			if (mode == INPUT_ANALOG) {
				GPIOx->GPIOx_CRL &= ~(0xF << (pin_num * 4));
				GPIOx->GPIOx_CRL |= ( (INPUT_ANALOG) << (pin_num * 4));
			}
			else if(mode == INPUT_FLOATING || mode == INPUT_AF ) {
				GPIOx->GPIOx_CRL &= ~(0xF << (pin_num * 4));
				GPIOx->GPIOx_CRL |= ( (INPUT_FLOATING) << (pin_num * 4));
			}
			else {
				if(mode == INPUT_PU) {
					GPIOx->GPIOx_CRL &= ~(0xF << (pin_num * 4));
					GPIOx->GPIOx_CRL |= ( (INPUT_PU) << (pin_num * 4));
					GPIOx->GPIOx_ODR |= (1 << pin_num);
				}
				else {
					GPIOx->GPIOx_CRL &= ~(0xF << (pin_num * 4));
					GPIOx->GPIOx_CRL |= ( (INPUT_PD) << (pin_num * 4));
					GPIOx->GPIOx_ODR &= ~(1 << pin_num);
				}
			}
		}
		else
		{
			GPIOx->GPIOx_CRL &= ~(0xF << (pin_num * 4));
			switch(speed)
			{
			case SPEED_2MHz:
			{
				if(mode == OUTPUT_PP){
					GPIOx->GPIOx_CRL |= (0b0010 << (pin_num * 4)); }
				else if(mode == OUTPUT_OD){
					GPIOx->GPIOx_CRL |= (0b0110 << (pin_num * 4)); }
				else if(mode == OUTPUT_AF_OD){
					GPIOx->GPIOx_CRL |= (0b1110 << (pin_num * 4)); }
				else{
					GPIOx->GPIOx_CRL |= (0b1010 << (pin_num * 4)); }
			}
			break;
			case SPEED_10MHz:
			{
				if(mode == OUTPUT_PP){
					GPIOx->GPIOx_CRL |= (0b0001 << (pin_num * 4)); }
				else if(mode == OUTPUT_OD){
					GPIOx->GPIOx_CRL |= (0b0101 << (pin_num * 4)); }
				else if(mode == OUTPUT_AF_OD){
					GPIOx->GPIOx_CRL |= (0b1101 << (pin_num * 4)); }
				else{
					GPIOx->GPIOx_CRL |= (0b1001 << (pin_num * 4)); }
			}
			break;
			case SPEED_50MHz:
			{
				if(mode == OUTPUT_PP){
					GPIOx->GPIOx_CRL |= (0b0011 << (pin_num * 4)); }
				else if(mode == OUTPUT_OD){
					GPIOx->GPIOx_CRL |= (0b0111 << (pin_num * 4)); }
				else if(mode == OUTPUT_AF_OD){
					GPIOx->GPIOx_CRL |= (0b1111 << (pin_num * 4)); }
				else{
					GPIOx->GPIOx_CRL |= (0b1011 << (pin_num * 4)); }
			}
			break;
			}
		}

	}



	if( pin_num > 7 )
	{
		if( mode == INPUT_ANALOG || mode == INPUT_FLOATING || mode == INPUT_PU || mode == INPUT_PD || mode == INPUT_AF ){
			if (mode == INPUT_ANALOG) {
				GPIOx->GPIOx_CRH &= ~(0xF << ((pin_num - 8) * 4));
				GPIOx->GPIOx_CRH |= ( (INPUT_ANALOG) << ((pin_num - 8) * 4));
			}
			else if(mode == INPUT_FLOATING || mode == INPUT_AF ) {
				GPIOx->GPIOx_CRH &= ~(0xF << ((pin_num - 8) * 4));
				GPIOx->GPIOx_CRH |= ( (INPUT_FLOATING) << ((pin_num - 8) * 4));
			}
			else {
				if(mode == INPUT_PU) {
					GPIOx->GPIOx_CRH &= ~(0xF << ((pin_num - 8) * 4));
					GPIOx->GPIOx_CRH |= ( (INPUT_PU) << ((pin_num - 8) * 4));
					GPIOx->GPIOx_ODR |= (1 << pin_num);
				}
				else {
					GPIOx->GPIOx_CRH &= ~(0xF << ((pin_num - 8) * 4));
					GPIOx->GPIOx_CRH |= ( (INPUT_PD) << ((pin_num - 8) * 4));
					GPIOx->GPIOx_ODR &= ~(1 << pin_num);
				}
			}
		}
		else
		{
			GPIOx->GPIOx_CRH &= ~( (0b1111) << ( (pin_num - 8) * 4)) ;

			switch(speed)
			{
			case SPEED_2MHz:
			{
				if(mode == OUTPUT_PP){
					GPIOx->GPIOx_CRH |= (0b0010 << ((pin_num - 8) * 4)); }
				else if(mode == OUTPUT_OD){
					GPIOx->GPIOx_CRH |= (0b0110 << ((pin_num - 8) * 4)); }
				else if(mode == OUTPUT_AF_OD){
					GPIOx->GPIOx_CRH |= (0b1110 << ((pin_num - 8) * 4)); }
				else{
					GPIOx->GPIOx_CRH |= (0b1010 << ((pin_num - 8) * 4)); }
			}
			break;
			case SPEED_10MHz:
			{
				if(mode == OUTPUT_PP){
					GPIOx->GPIOx_CRH |= (0b0001 << ((pin_num - 8) * 4)); }
				else if(mode == OUTPUT_OD){
					GPIOx->GPIOx_CRH |= (0b0101 << ((pin_num - 8) * 4)); }
				else if(mode == OUTPUT_AF_OD){
					GPIOx->GPIOx_CRH |= (0b1101 << ((pin_num - 8) * 4)); }
				else{
					GPIOx->GPIOx_CRH |= (0b1001 << ((pin_num - 8) * 4)); }
			}
			break;
			case SPEED_50MHz:
			{
				if(mode == OUTPUT_PP){
					GPIOx->GPIOx_CRH |= (0b0011 << ((pin_num - 8) * 4)); }
				else if(mode == OUTPUT_OD){
					GPIOx->GPIOx_CRH |= (0b0111 << ((pin_num - 8) * 4)); }
				else if(mode == OUTPUT_AF_OD){
					GPIOx->GPIOx_CRH |= (0b1111 << ((pin_num - 8) * 4)); }
				else{
					GPIOx->GPIOx_CRH |= (0b1011 << ((pin_num - 8) * 4)); }
			}
			break;
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
void MCAL_GPIO_DEINIT(GPIO_REG_t* GPIOx)
{
	GPIOx->GPIOx_CRL = 0x44444444;
	GPIOx->GPIOx_CRH = 0x44444444;
	GPIOx->GPIOx_IDR = 0x00000000;
	GPIOx->GPIOx_ODR = 0x00000000;
	GPIOx->GPIOx_LCKR = 0x00000000;
}


/**================================================================
 * @Fn			- MCAL_GPIO_WRITEPIN
 * @brief 		- Write on a specific pin
 * @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
 * @param [in] 	- pin_num: the selected pin according to GPIO_PINS_DEF
 * @param [in] 	- status: pin value
 * @retval 		- none
 * Note			- The value that passing to the function, it defined at Pin_Statuse reference (Pin_SET/Pin_RESET)
 */
void MCAL_GPIO_WRITEPIN(GPIO_REG_t* GPIOx, uint16_t pin_num, uint8_t status)
{
	switch(status)
	{
	case SET:
	{
		GPIOx->GPIOx_ODR |= (1 << pin_num);
	}
	break;
	case RESET:
	{
		GPIOx->GPIOx_ODR &= ~(1 << pin_num);
	}
	break;
	}
}


/**================================================================
 * @Fn			- MCAL_GPIO_WRITEPORT
 * @brief 		- Write on a specific pin
 * @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
 * @param [in] 	- status: port value
 * @retval 		- none
 * Note			- none
 */
void MCAL_GPIO_WRITEPORT(GPIO_REG_t* GPIOx, uint32_t status)
{
	GPIOx->GPIOx_ODR = status;
}


/**================================================================
 * @Fn			- MCAL_GPIO_READPIN
 * @brief 		- Read from a specific pin
 * @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
 * @param [in] 	- pin_num: the selected pin according to GPIO_PINS_DEF
 * @retval 		- Pin status (two values according to PIN_STATUS)
 * Note			- none
 */
uint32_t MCAL_GPIO_READPIN(GPIO_REG_t* GPIOx, uint16_t pin_num)
{
	return (GPIOx->GPIOx_IDR >>  pin_num)&1 ;
}


/**================================================================
 * @Fn			- MCAL_GPIO_READPORT
 * @brief 		- Read the port
 * @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
 * @retval 		- The input port value
 * Note			- none
 */
uint32_t MCAL_GPIO_READPORT(GPIO_REG_t* GPIOx)
{
	return GPIOx->GPIOx_IDR ;
}


/**================================================================
 * @Fn			- MCAL_GPIO_TOGGLEPIN
 * @brief 		- Toggle a specific pin
 * @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
 * @param [in] 	- pin_num: the selected pin according to GPIO_PINS_DEF
 * @retval 		- none
 * Note			- none
 */
void MCAL_GPIO_TOGGLE(GPIO_REG_t* GPIOx, uint16_t pin_num)
{
	GPIOx->GPIOx_ODR ^= (1 << pin_num);
}


/**================================================================
 * @Fn			- MCAL_GPIO_LOCKPIN
 * @brief 		- Lock a specific pin
 * @param [in] 	- GPIOx: x can be (A:G depend on the device used) to select the GPIO peripheral
 * @param [in] 	- PinNumber: the selected pin according to GPIO_PINS_DEF
 * @retval 		- Pin_LOCKED if the pin locked, Pin_UNLOCKED if the pin not locked according to GPIO PIN LOCK DEF
 * Note			- none
 */
uint8_t MCAL_GPIO_LOCKPIN(GPIO_REG_t* GPIOx, uint16_t pin_num)
{
	volatile uint32_t temp = 1<<16;

	/*
	  	   LCKK[16]: Lock key
		   This bit can be read any time. It can only be modified using the Lock Key Writing Sequence.
		   0: Port configuration lock key not active
		   1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset
		   LCKy: Port x Lock bit y (y= 0 .. 15)
		   These bits are read write but can only be written when the LCKK bit is 0.
			0: Port configuration not locked
			1: Port configuration locked
	 */
	GPIOx->GPIOx_LCKR |= pin_num;

	/*
	LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	 */
	GPIOx->GPIOx_LCKR = temp;
	GPIOx->GPIOx_LCKR = (uint32_t) pin_num;
	GPIOx->GPIOx_LCKR = temp;
	temp = GPIOx->GPIOx_LCKR;
	if( (uint32_t)(GPIOx->GPIOx_LCKR & (1<<16)) )
	{
		return LOCK;
	}
	else
	{
		return UNLOCK;
	}
}
