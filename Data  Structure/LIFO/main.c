/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: KARIM
 */

#include<stdio.h>
#include<stdlib.h>
#include"LIFO.h"

unsigned int Buffer1 [5];

int main() {
	unsigned int i, temp = 0;
	LIFO_buf_t UART_lifo, I2C_lifo;
	//Static allocation
	LIFO_init(&UART_lifo, Buffer1, 5);
	//Dynamic allocation
	unsigned int* Buffer2 = (unsigned int*) malloc (5 * sizeof(unsigned int));
	LIFO_init(&I2C_lifo, Buffer2, 5);

	for(i=0; i<6; i++){
		if( LIFO_Add_Item(&UART_lifo , i) == NO_Error){
			printf("UART_LIFO Add : %d \n",i);
		}
		else if(LIFO_Add_Item(&UART_lifo, i) == FULL){
			printf("UART_LIFO is Full \n");
		}
		else{
			printf("UART_LIFO not exist");
		}
	}

	printf("\n");

	for(i=0; i<6; i++){
		if( LIFO_Get_Item(&UART_lifo, &temp) == NO_Error){
			printf("UART_LIFO : %d \n",i);
		}
		else if(LIFO_Get_Item(&UART_lifo, &temp) == Empty){
			printf("UART_LIFO is Empty \n");
		}
	}

	return 0;
}
