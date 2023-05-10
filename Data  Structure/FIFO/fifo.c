/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: KARIM
 */

#include "fifo.h"
#include <stdlib.h>


int main() {
	FIFO_buf_t fifo_UART ;
	unsigned int i, temp=0;

	if( FIFO_init(&fifo_UART, &buff, width) == FIFO_no_error)
		printf("FIFO UART is Done");

	for(i=0; i<7; i++){
		if( FIFO_Enqueue_Item( &fifo_UART, i) == FIFO_no_error){
			printf("FIFO UART : %d \n",i);
		}
		else if( FIFO_Enqueue_Item( &fifo_UART, i) == FIFO_Full){
			printf("FIFO UART is Full");
		}
		else if( FIFO_Enqueue_Item( &fifo_UART, i) == FIFO_null){
			printf(" FIFO UART not Exist");
		}
	}

	printf("\n");

	for(i=0; i<7; i++){
		if( FIFO_Dequeue_Item(&fifo_UART, *temp) == FIFO_no_error){
			printf("FIFO UART : %d \n",temp);
		}
		else if( FIFO_Dequeue_Item(&fifo_UART, *temp) == FIFO_empty){
			printf("FIFO UART is Empty");
		}
	}

	return 0;
}
