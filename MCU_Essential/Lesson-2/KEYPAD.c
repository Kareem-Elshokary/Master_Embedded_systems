/*
 * Mastering Embedded System Diploma 
 * Eng. Kareem Abdelkader
 *
 * KEYPAD_Driver.c
 *
 */ 

#include "KEYPAD.h"

int Keypad_Row[] = {R0, R1, R2, R3}; //Rows of the keypad
int Keypad_Col[] = {C0, C1, C2, C3}; //Columns of the keypad

void KEYPAD_INIT(){
	KEYPAD_DDR  &= ~( (1<<R0) | (1<<R1) | (1<<R2) | (1<<R3) );
	KEYPAD_DDR  |= ( (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3) );
	KEYPAD_PORT = 0xff;
}

char KEYPAD_GetKey(){
	int i,j;
	for (i = 0; i < 4; i++){
		KEYPAD_PORT |= ((1<<Keypad_Col[0]) | (1<<Keypad_Col[1]) | (1<<Keypad_Col[2]) | (1<<Keypad_Col[3]));
		KEYPAD_PORT &= ~(1<<Keypad_Col[i]);
		for(j = 0; j < 4; j++){
			if (!(KEYPAD_PIN & (1 << Keypad_Row[j])))
			{
				while(!(KEYPAD_PIN & (1 << Keypad_Row[j])));
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
