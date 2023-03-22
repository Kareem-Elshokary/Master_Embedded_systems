/*
 * ex6.c
 *
 *  Created on: Mar 13, 2023
 *      Author: KARIM
 *  Swap Two Numbers
 */

#include<stdio.h>

int main(){
	float a,b;
	float temp;

	printf("Enter value of a: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: \n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);

	temp = a;
	a = b;
	b = temp;

	printf("After swapping, value of a = %f \n",a);
	printf("After swapping, value of b = %f \n",b);

	return 0;
}

