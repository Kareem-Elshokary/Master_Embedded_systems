/*
 * func_Ex11.c
 *
 *  Created on: Apr 2, 2023
 *      Author: KARIM
 *  C function to return unique number in array with one loop
 */

#include<stdio.h>

int Unique (int a[], int size);

int main(){

	int a[] = {1,1,2,2,3};
	int size = sizeof(a)/sizeof(a[0]);

	printf("Unique num is: %d", Unique(a,size));

	return 0;
}

int Unique (int a[], int size){
	int i, U=0;
	for(i=0; i<size; i++){
		U ^= a[i];
	}
	return U;
}
