/*
 * Ptr_Ex1.c
 *
 *  Created on: Apr 14, 2023
 *      Author: KARIM
 *  a program in C to demonstrate how to handle the pointers in the program.
 */

#include<stdio.h>

int main(){
	int m = 29 ;
	printf("Address of m = %x \n Value of m = %d \n",&m,m);

	int* ab = &m ;
	printf("Address of ab is %x \n Content of ab is %d \n",ab,*ab);

	*ab = 34;
	printf("Address of ab is %x \n Content of ab is %d \n",ab,*ab);

	*ab = 7;
	printf("Address of ab is %x \n Content of ab is %d",ab,*ab);

	return 0;
}
