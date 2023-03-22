/*
 * Ex3.c
 *
 *  Created on: Mar 14, 2023
 *      Author: KARIM
 *  Check whether a number is +ve or -ve
 */

#include<stdio.h>

int main(){
	int x;
	printf("Enter an integer: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	if( x>0){
		printf("%d is positive",x);
	}
	else if( x<0 ){
		printf("%d is negative",x);
	}
	else{
		printf("%d is neither positive or negative",x);
	}


	return 0;
}

