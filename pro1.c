/*
 * pro1.c
 *
 *  Created on: Apr 2, 2023
 *      Author: KARIM
 *  C function to take a number and sum all digits
 */

#include<stdio.h>

int Sum (int num);

int main(){

	int num;
	printf("Enter a number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("%d", Sum(num));

	return 0;
}

int Sum (int num){
	int sum=0, i;

	while(num > 0){
		if(num != 0){
			i = num%10;
			sum += i;
			num /= 10;
		}
		else{
			return 0;
		}
	}

	return sum;
}
