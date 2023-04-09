/*
 * func_ex9.c
 *
 *  Created on: Apr 2, 2023
 *      Author: KARIM
 *  C function to take an integer number and calculate it's square root
 */

#include<stdio.h>
#include<math.h>

float Squ_Root (int a);

int main(){

	int num;
	printf("Enter a number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("Result = %f",Squ_Root(num));

	return 0;
}

float Squ_Root (int a){
	float res;
	res = sqrt(a);
	return res;
}
