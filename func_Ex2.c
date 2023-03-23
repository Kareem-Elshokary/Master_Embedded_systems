/*
 * func_Ex2.c
 *
 *  Created on: Mar 23, 2023
 *      Author: KARIM
 *  Find the factorial by recursion
 */

#include<stdio.h>
int factorial (int x);

int main(){
	int number;
	printf("Enter a number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&number);
	int result = factorial (number);
	printf("factorial of %d is %d",number,result);

	return 0;
}

int factorial (int x){
	if (x != 1)
		return x*factorial(x-1);
}
