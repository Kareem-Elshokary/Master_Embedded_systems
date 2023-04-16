/*
 * Ptr_Ex4.c
 *
 *  Created on: Apr 14, 2023
 *      Author: KARIM
 *  a program in C to print the elements of an array in reverse
 */

#include<stdio.h>

int main(){
	int arr[20], rev[20];
	int n, i=0, j;
	int* ptr1 = arr;
	int* ptr2 = rev;

	printf("Enter the number of elements: \n");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&n);

	for(; i<n; i++){
		printf("Enter Element%d: \n",i+1);
		fflush(stdin);  fflush(stdout);
		scanf("%d",ptr1);
		ptr1++;
	}

	for(i=n; i>=0; i--){
		for(j=0; j<n; j++){
			*ptr2 = *ptr1;
			ptr1--;
			ptr2++;
		}
	}

	ptr2 = rev;
	for(; i<n; i++){
		printf("Element%d : %d \n",i+1,*ptr2);
		ptr2++;
	}

	return 0;
}
