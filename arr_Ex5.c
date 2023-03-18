/*
 * arr_Ex5.c
 *
 *  Created on: Mar 18, 2023
 *      Author: KARIM
 *  Search an element in an array
 */

#include<stdio.h>

int main(){
	int i,n,search;
	int arr[10];

	printf("Enter the number of elements: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	for(i=0; i<n; i++){
		printf("Enter the number of element%d: \n",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&arr[i]);
	}

	printf("Enter number to search: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&search);

	// loop for searching
	for(i=0; i<n; i++){
		if( arr[i]==search ){
			printf("%d is found at location %d",search,i+1);
			break;
		}
		else{
			printf("%d is not found",search);
			break;
		}
	}

	return 0;
}

