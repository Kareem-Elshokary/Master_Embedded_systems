/*
 * Ex1.c
 *
 *  Created on: Mar 14, 2023
 *      Author: KARIM
 *  Check whether a number is even or odd
 */

#include<stdio.h>

int main(){
	int x;
	printf("Enter an integer: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	if(x%2 == 0){
		printf("%d is even",x);
	}
	else{
		printf("%d is odd",x);
	}

	return 0;
}

