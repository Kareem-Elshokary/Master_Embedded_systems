/*
 * arr_Ex3.c
 *
 *  Created on: Mar 18, 2023
 *      Author: KARIM
 *  Find the transpose of matrix
 */

#include<stdio.h>

int main(){
	int r,c,i,j; // r is no. of rows, c is no. of columns.
	int mat[50][50], trans [50][50];

	printf("Enter the number of rows: \n"); // get no. of rows from user
	fflush(stdin); fflush(stdout);
	scanf("%d",&r);
	printf("Enter the number of columns: \n"); // get no. of columns from user
	fflush(stdin); fflush(stdout);
	scanf("%d",&c);

	if( r<=50  && c<=50  ){ // not to exceed the range of the array

		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				printf("Enter m%d%d: \n",i+1,j+1);
				fflush(stdin); fflush(stdout);
				scanf("%d",&mat[i][j]);
			}
		}
		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				trans[i][j] = mat[j][i];
			}
		}
		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				printf("%d \t",trans[i][j]);
			}
			printf("\n");
		}
	}

	else{
		printf("Sorry, Enter number between 0:50 ");
	}


	return 0;
}
