/*
 * arr_Ex2.c
 *
 *  Created on: Mar 18, 2023
 *      Author: KARIM
 *  Calculate the average of numbers
 */

#include<stdio.h>

int main(){
	int n,i;
	float arr[20], sum=0, ave;

	printf("Enter the numbers of data: \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	for(i=0; i<n; i++){
		printf("%d. Enter number: \n",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&arr[i]);
		sum += arr[i];
	}

	ave = sum / n;
	printf("Average = %f \n",ave);

	return 0;
}
