/*
 * arr_Ex4.c
 *
 *  Created on: Mar 18, 2023
 *      Author: KARIM
 *  Insert an element in an array
 */

#include<stdio.h>

int main(){
	int loc,val,i;
	int a[6];

	for(i=0; i<6; i++){
		printf("Enter array element%d: \n",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",&a[i]);
	}

	printf("Enter the value to insert: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&val);
	printf("Enter the location: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&loc);

	a[loc] = val;
	for(i=0; i<6; i++){
		printf("%d \t",a[i]);
	}

	return 0;
}
