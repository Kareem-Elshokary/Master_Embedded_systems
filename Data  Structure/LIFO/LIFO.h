/*
 * LIFO.h
 *
 *  Created on: May 7, 2023
 *      Author: KARIM
 */

#ifndef LIFO_H_
#define LIFO_H_

#define NULL 0
//Type Definitions
typedef struct {
	unsigned int length ;    //Total size of buffer
	unsigned int count ;     //Total number of added items
	unsigned int* base ;     //Starting point
	unsigned int* head ;     //Ending point
}LIFO_buf_t;

typedef enum {
	NO_Error, FULL, Empty, lifo_NULL
}LIFO_Stutas;

//APIs
LIFO_Stutas LIFO_Add_Item (LIFO_buf_t* lifo_buff, unsigned int item);                         //PUSH
LIFO_Stutas LIFO_Get_Item (LIFO_buf_t* lifo_buff, unsigned int* item);                        //POP
LIFO_Stutas LIFO_init (LIFO_buf_t* lifo_buff, unsigned int* buf, unsigned int length);        //Initialization of the buffer

#endif /* LIFO_H_ */
