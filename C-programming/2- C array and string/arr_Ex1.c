/*
 * arr_Ex1.c
 *
 *  Created on: Mar 18, 2023
 *      Author: KARIM
 *  Sum of multidimensional array
 */

#include<stdio.h>

int main(){

	float a [2][2];
	float b [2][2];
	int i,j;
	float sum [2][2];

	printf("Enter the elements of 1st matrix: \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("Enter a%d%d: \n",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&a[i][j]);
		}
	}

	printf("Enter the elements of 2nd matrix: \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("Enter b%d%d: \n",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&b[i][j]);
		}
	}

    printf("Sum of matrix: \n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			sum [i][j] = a[i][j] + b[i][j];
			printf("%f \t",sum[i][j]);
		}
		printf("\n\r");
	}

	return 0;
}
