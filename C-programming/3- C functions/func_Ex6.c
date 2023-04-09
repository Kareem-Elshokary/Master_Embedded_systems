/*
 * func_Ex6.c
 *
 *  Created on: Mar 26, 2023
 *      Author: KARIM
 *  C functions to clear or set or toggle a bit
 */

#include<stdio.h>

int clear_bit (int num, int pos);
int Set_bit (int num, int pos);
int Toggle_bit (int num, int pos);

int main(){
	int num, pos;
	char c;

	printf("Enter number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	printf("Enter bit position: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&pos);
	printf("Choose operation [C for clear, S for set, T for toggle]: \n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);

	switch(c){
	case 'C': {
		printf("Result = %d",clear_bit(num,pos));}
	break;
	case 'S': {
		printf("Result = %d",Set_bit(num,pos));}
	break;
	case 'T': {
		printf("Result = %d",Toggle_bit(num,pos));}
	break;
	default :{
		printf("Wrong choose");}
	break;
	}


	return 0;
}

int clear_bit (int num, int pos){
	return num &= ~(1<<pos);
}

int Set_bit (int num, int pos){
	return num |= (1<<pos);
}

int Toggle_bit (int num, int pos){
	return num ^= (1<<pos);
}
