/*
 * func_Ex13.c
 *
 *  Created on: Apr 2, 2023
 *      Author: KARIM
 *  C function to count the max number of ones between two zeros
 */

#include<stdio.h>

int Ones (int n);

int main(){
	int x;
	printf("Enter a number: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x);

	printf("%d", Ones(x));

	return 0;
}

int Ones (int n){
	int count = 0;
	while( n!=0 ){
		n = n & (n<<1) ;
		count++;
	}
	return count;
}
