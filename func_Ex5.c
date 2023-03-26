/*
 * func_Ex5.c
 *
 *  Created on: Mar 26, 2023
 *      Author: KARIM
 *  C function to reverse an array
 */

#include<stdio.h>
void reverse (int arr1[], int arr2[], int n);

int main(){
	int arr1[20],arr2[20],n;

	printf("Enter the number of elements(<20): \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("Enter array numbers: \n");
	fflush(stdin); fflush(stdout);
	for(int i=0; i<n; i++){
		scanf("%d",&arr1[i]);
	}

	printf("Before swapping \n");
	for(int i=0; i<n; i++){
		printf("%d \n",arr1[i]);
	}

	reverse(arr1,arr2,n);

	return 0;
}

void reverse (int arr1[], int arr2[], int n){
	int i,j;

	for(i=n-1, j=0; i>=0; i--,j++){
		arr2[j] = arr1[i];
	}

	printf("After swapping \n");
	for(i=0; i<n; i++){
		printf("%d \n",arr2[i]);
	}

}
