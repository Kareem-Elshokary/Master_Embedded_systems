/*
 * func_Ex7.c
 *
 *  Created on: Mar 26, 2023
 *      Author: KARIM
 *  Check if given number is power of 3
 */

#include<stdio.h>

void Check (int n);

int main(){
	int number;
	printf("Enter the number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&number);

	Check (number);

	return 0;
}

void Check (int n){
	if( n%3 == 0)
		printf("%d is power of 3",n);
	else
		printf("%d is not power of 3",n);
}
