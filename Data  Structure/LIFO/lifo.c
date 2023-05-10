/*
 * lifo.c
 *
 *  Created on: May 7, 2023
 *      Author: KARIM
 */

#include"LIFO.h"

LIFO_Stutas LIFO_Add_Item (LIFO_buf_t* lifo_buff, unsigned int item){
	//Check lifo if valid
	if( !lifo_buff->base || !lifo_buff->head)
		return lifo_NULL ;
	//Check lifo if full
	if( lifo_buff->count == lifo_buff->length )
		return FULL ;
	//Add
	*lifo_buff->head = item;
	lifo_buff->head++;
	lifo_buff->count++;
	return NO_Error ;
}

LIFO_Stutas LIFO_Get_Item (LIFO_buf_t* lifo_buff, unsigned int* item){
	//Check lifo if valid
	if( !lifo_buff->base || !lifo_buff->head)
		return lifo_NULL ;
	//Check if lifo is empty
	if( lifo_buff->count == 0)
		return Empty;

	lifo_buff->head--;
	*item = *(lifo_buff->head);
	lifo_buff->count--;
	return NO_Error ;
}

LIFO_Stutas LIFO_init (LIFO_buf_t* lifo_buff, unsigned int* buf, unsigned int length){
	if( buf == NULL )
		return lifo_NULL ;

	lifo_buff->base = buf;
	lifo_buff->head = buf;
	lifo_buff->length = length;
	lifo_buff->count = 0;
	return NO_Error ;
}

