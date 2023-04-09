/*
 * Ex6.c
 *
 *  Created on: Apr 6, 2023
 *      Author: KARIM
 */

#include<stdio.h>
#define Pi 3.14

int main(){
	int r, a;

	printf("Enter radius: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&r);

	a = 2 * Pi * r;
	printf("Area = %d",a);

	return 0;
}
