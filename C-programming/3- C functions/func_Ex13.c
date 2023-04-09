/*
 * func_Ex14.c
 *
 *  Created on: Apr 2, 2023
 *      Author: KARIM
 *  C function to reverse digits in number
 */

#include<stdio.h>

int Reverse (int n);

int main(){

	int number;
	printf("Enter a number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&number);

	printf("Reverse is %d", Reverse(number));

	return 0;
}

int Reverse (int n){
	int rev = 0;
	while ( n!=0 ){
		rev = rev*10 + n%10 ;
		n = n/10 ;
	}
	return rev;
}
