/*
 * func_Ex10.c
 *
 *  Created on: Apr 2, 2023
 *      Author: KARIM
 *  C function to count number of ones in binary number
 */

#include<stdio.h>

int Count (int a);

int main(){
	int num;
	printf("Enter a number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	printf("Number of 1's = %d", Count(num));

	return 0;
}

int Count (int a){
	int i, sum=0;
	for(i=32; i>0; i--){
		if(a & (1>>1)){
			sum += sum;
		}
	}
	return sum;
}
