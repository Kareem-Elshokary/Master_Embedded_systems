/*
 * 7.c
 *
 *  Created on: Mar 16, 2023
 *      Author: KARIM
 *  Swap two numbers without temp
 */

#include<stdio.h>

int main(){
	float a,b;

	printf("Enter value of a: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);

	a = a + b;
	b = a - b;
	a = a - b;

	printf("After swapping, value of a = %f \n",a);
	printf("After swapping, value of b = %f \n",b);

	return 0;
}
