/*
 * func_Ex12.c
 *
 *  Created on: Apr 2, 2023
 *      Author: KARIM
 *  C function to sum numbers from 1 to 100(without loop)
 */

#include<stdio.h>

int Sum (int n);

int main(){

	printf("Sum = %d",Sum(1));
	return 0;
}

int Sum (int n){
	static int sum = 0;
	if( n <= 100 ){
		Sum(n+1);
		sum = sum + n;
	}
	return sum;
}
