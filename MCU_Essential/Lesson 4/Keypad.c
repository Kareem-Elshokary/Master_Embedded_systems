/*
 *  Keypad.h
 *
 *  Eng. Kareem Abdelkader
 *
 */

/***********************************
 * Includes
 ***********************************/
#include"Keypad.h"

//====================================================================================


int Keypad_Row[] = {R0, R1, R2, R3}; //Rows of the keypad
int Keypad_Col[] = {C0, C1, C2, C3}; //Columns of the keypad



void KEYPAD_INIT(){
	pincof.GPIO_PinNumber = R0;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &pincof);

	pincof.GPIO_PinNumber = R1;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &pincof);

	pincof.GPIO_PinNumber = R2;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &pincof);

	pincof.GPIO_PinNumber = R3;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &pincof);

	pincof.GPIO_PinNumber = C0;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &pincof);

	pincof.GPIO_PinNumber = C1;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &pincof);

	pincof.GPIO_PinNumber = C2;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &pincof);

	pincof.GPIO_PinNumber = C3;
	pincof.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pincof.GPIO_Output_Speed = GPIO_SPEED_10MHz;
	MCAL_GPIO_Init(KEYPAD_PORT, &pincof);

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);
}

char KEYPAD_GetKey(){
	int i,j;
	for (i = 0; i < 4; i++){
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[0], GPIO_PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[1], GPIO_PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[2], GPIO_PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[3], GPIO_PIN_SET);
		MCAL_GPIO_WRITEPIN(KEYPAD_PORT, Keypad_Col[i], GPIO_PIN_RESET);
		for (j = 0; j < 4; j++) {
			if (MCAL_GPIO_READPIN(KEYPAD_PORT, Keypad_Row[j]) == 0) {
				while (MCAL_GPIO_READPIN(KEYPAD_PORT, Keypad_Row[j]) == 0);
				switch(i){
					case (0):
					if (j == 0) return '7';
					else if (j == 1) return '4';
					else if (j == 2) return '1';
					else if (j == 3) return '?';
					break;
					case (1):
					if (j == 0) return '8';
					else if (j == 1) return '5';
					else if (j == 2) return '2';
					else if (j == 3) return '0';
					break;
					case (2):
					if (j == 0) return '9';
					else if (j == 1) return '6';
					else if (j == 2) return '3';
					else if (j == 3) return '=';
					break;
					case (3):
					if (j == 0) return '/';
					else if (j == 1) return '*';
					else if (j == 2) return '-';
					else if (j == 3) return '+';
					break;
				}
			}
		}
	}
	return 'A';
}
