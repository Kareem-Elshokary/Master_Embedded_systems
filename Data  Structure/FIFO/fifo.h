/*
 * fifo.h
 *
 *  Created on: May 7, 2023
 *      Author: KARIM
 */

#ifndef FIFO_H_
#define FIFO_H_


#include "stdint.h"
#include "stdio.h"

//User Configuration
#define element_type uint8_t
#define width 5
element_type buff[width];

//FIFO data types
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type base;
	element_type head;
	element_type tail;
}FIFO_buf_t;

typedef enum {
	FIFO_no_error,
	FIFO_Full,
	FIFO_empty,
	FIFO_null
}FIFO_Stutas;

//APIs
FIFO_Stutas FIFO_Enqueue_Item (FIFO_buf_t* fifo_buff, unsigned int item);
FIFO_Stutas FIFO_Dequeue_Item (FIFO_buf_t* fifo_buff, unsigned int* item);
FIFO_Stutas FIFO_init (FIFO_buf_t* fifo_buff, unsigned int* buf, unsigned int length);        //Initialization of the buffer


#endif /* FIFO_H_ */



